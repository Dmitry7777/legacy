#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>

#include "cann.h"
#include "debug.h"

// Atmel ; LAP includes
#include "config.h"

#include "uart-host.h"
#include "can-uart.h"

#ifndef max
 #define max(a,b) (((a) > (b)) ? (a) : (b))
#endif


char *progname;
char *serial; 
char *logfile=NULL;
char *scriptfile=NULL;

static char *optstring = "hdv::S:p:l:s:";
struct option longopts[] =
{
  { "help", no_argument, NULL, 'h' },
  { "daemon", no_argument, NULL, 'd' },
  { "verbose", optional_argument, NULL, 'v' },
  { "serial", required_argument, NULL, 'S' },
  { "port", required_argument, NULL, 'p' },
  { "logfile", required_argument, NULL, 'l'},
  { "scriptfile", required_argument, NULL, 's'},
  { NULL, 0, NULL, 0 }
};

void help()
{
	printf("\nUsage: %s [OPTIONS]\n", progname);
	printf("\
   -h, --help              display this help and exit\n\
   -v, --verbose           be more verbose and display a CAN packet dump\n\
   -d, --daemon            become daemon\n\
   -S, --serial PORT       use specified serial port\n\
   -s, --scriptfile FILE   use a scripte file to execute cmds on package\n\
   -l, --logfile FILE      log every package to a logfile\n\    
   -p, --port PORT         use specified TCP/IP port (default: 2342)\n\n" );
}


void hexdump(unsigned char * addr, int size){
	unsigned char x=0, sbuf[3];
	
	printf( "Size: %d\n", size);
	while(size--){
	  printf("%02x ", *addr++);
		if(++x == 16){
		  printf("\n");
			x = 0;
		}
	}
	printf("\n");
}

void customscripts(rs232can_msg *msg)
{
  FILE *fp;
  FILE *scriptFP;
  char tmpstr[80];
  char tmpstr2[80];
  time_t mytime;

  int result;

  uint8_t i;

  mytime = time(NULL);
  char line[300];
  can_message_match *in_msg = (can_message*)(msg->data);
  can_message_match match_msg = {0x00,0x00,0x00,0x00,0x00,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}};

  strftime(tmpstr2,79,"%r",localtime(&mytime));

  if( (fp=fopen(logfile,"a")) != NULL)
    {
      result = snprintf(tmpstr,80,"%s : src: 0x%.2x:0x%.2x dst:0x%.2x:0x%.2x data: ", 
			tmpstr2, 
			in_msg->addr_src,in_msg->port_src,
			in_msg->addr_dst,in_msg->port_dst );
      if(result<=80 && result>=0) 
	{
	  fwrite(tmpstr,result,1,fp);
	  for(i=0;i<in_msg->dlc;i++)
	    {
	      result = snprintf(tmpstr,80,"0x%.2x ",in_msg->data[i]);
	      if(result == 5)
		{
		  fwrite(tmpstr,result,1,fp);
		}
	    }
	  fwrite("\n",8,1,fp);
	}
      else 
	{
	  fwrite("logfail\n",8,1,fp);
	}
      fflush(fp);
      fclose(fp);
    }

  if( (scriptFP=fopen(scriptfile,"r")) != NULL)
    {  
      // we only support full match - on src/dst and dlc
      // example:
      // 0x00:0x00 0x00:0x00 0x04 data -> command
      // src:srcport dst:dstport len data... -> executable
      while (fgets(line, 300, scriptFP) != NULL) 
	{
	  result = sscanf(line,"0x%hhx:0x%hhx 0x%hhx:0x%hhx 0x%hhx %s -> %s",
			  &(match_msg.addr_src),&(match_msg.port_src),
			  &(match_msg.addr_dst),&(match_msg.port_dst),
			  &(match_msg.dlc),
			  tmpstr,
			  tmpstr2);
	  if(result !=7)
	    {
	      return;
	    }
    
	  if( (match_msg.addr_dst == in_msg->addr_dst) && 
	      (match_msg.addr_src == in_msg->addr_src) && 
	      (match_msg.port_dst == in_msg->port_dst) && 
	      (match_msg.port_src == in_msg->port_src) && 
	      (match_msg.dlc == in_msg->dlc))
	    {
	      snprintf(line,300,"%s %s",tmpstr2,tmpstr);
	      system(line);
	    }

	}
      fclose(scriptFP);
    }


}

void process_uart_msg()
{
	cann_conn_t *ac;
	debug( 10, "Activity on uart_fd" );

	rs232can_msg *msg = canu_get_nb();
	if(!msg) return;
	
	debug(3, "Processing message from uart..." );
	
	if(msg->cmd != RS232CAN_PKT){
		debug(0, "Whats going on? Received other than PKT type on Uart");
		canu_free(msg);
		return;
	}

	customscripts(msg);

	// foreach client
	ac = cann_conns_head;
	while(ac) {
//XXX		if ( cann_match_filter(ac, msg) ) 
		cann_transmit(ac, msg);
		
		ac = ac->next;
	}
	
	canu_free(msg);
	debug(3, "...processing done.");
}

void process_client_msg( cann_conn_t *client )
{
	cann_conn_t *ac;
	int x;

	debug( 10, "Activity on client %d", client->fd );

	rs232can_msg *msg = cann_get_nb(client);
	if(!msg) return;
	
	debug(3, "Processing message from network..." );
	if (debug_level >= 3) hexdump((void *)msg, msg->len + 2);

	customscripts(msg);

	switch(msg->cmd) {
		case RS232CAN_SETFILTER:
			/* XXX */
			break;
		case RS232CAN_SETMODE:
			/* XXX */
			break;
		case RS232CAN_PKT:
		default:
			// to UART
			if (serial) canu_transmit(msg);

			// foreach client
			ac = cann_conns_head;
			while(ac) {
//XXX				if ( cann_match_filter(ac, msg) ) 
				if ( ac != client )
					cann_transmit(ac, msg);

				ac = ac->next;
			}
	}
//	cann_free(msg);
	debug(3, "...processing done.");
}

void new_client( cann_conn_t *client )
{
	// XXX
}

void event_loop()
{
	for(;;) {
		int num;
		int highfd = 0;;
		fd_set rset;
		cann_conn_t *client;

		FD_ZERO(&rset);

		if (serial) {
			highfd = uart_fd;
			FD_SET(uart_fd, &rset);
		};
		highfd = max(highfd, cann_fdset(&rset));


		debug( 9, "VOR SELECT" );
		cann_dumpconn();

		num = select(highfd+1, &rset, (fd_set *)NULL, (fd_set *)NULL, NULL);
		debug_assert( num >= 0, "select failed" );
		debug( 10, "Select returned %d", num);
		cann_dumpconn();

		// check activity on uart_fd
		if (serial && FD_ISSET(uart_fd, &rset))
			process_uart_msg();

		debug( 9, "AFTER UART" );
		cann_dumpconn();

		// check client activity 
		//
		while( client = cann_activity(&rset) ) {
			debug(5, "CANN actiity found" );
			process_client_msg(client);
		}

		debug( 9, "AFTER CANN ACTIVITY" );
		cann_dumpconn();

		// new connections
		if( client = cann_accept(&rset) ) {
			debug( 2, "===> New connection (fd=%d)", client->fd );
		}

		debug( 9, "AFTER CANN NEWCONN" );
		cann_dumpconn();


		// close errorous connections
		cann_close_errors();

		debug( 9, "AFTER CANN CLOSE" );
		cann_dumpconn();
	}
}


int main(int argc, char *argv[])
{
	int d = 0;                   // daemon
	int tcpport  = 2342;         // TCP Port
	int optc;

	progname = argv[0];

	while ((optc=getopt_long(argc, argv, optstring, longopts, (int *)0))
		!= EOF) {
		switch (optc) {
			case 'v':
				if (optarg)
					debug_level = atoi(optarg);
				else 
					debug_level = 3;
				break;
			case 'd':
				d = 1;
				break;
			case 'S':
				serial = optarg;
				break;
			case 'p':
				tcpport = atoi(optarg);
				break;
			case 'h':
				help();
				exit(0);
		case 'l':
		  logfile = optarg;
		  break;
		case 's':
		  scriptfile = optarg;
		  break;
			default:
				help();
				exit(1);
		}
	} // while

	// setup serial communication
	if (serial) {
		canu_init(serial);
		debug(1, "Serial CAN communication established" );
	};

	// setup network socket
	cann_listen(tcpport);
	debug(1, "Listenig for network connections on port %d", tcpport );

	event_loop();  // does not return

	return 1;  
}

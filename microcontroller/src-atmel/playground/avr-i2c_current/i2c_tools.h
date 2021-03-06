#ifndef I2C_TOOLS_H_
#define I2C_TOOLS_H_

#include <stdint.h>
#include "i2c.h"


/* MACROS */
#define SET_N_BITS(s) ((1<<(s))-1)

/* types */
typedef uint8_t i2c_reg_t;

#ifndef __BOOL__
#ifndef BOOL
	typedef enum{false=0, true=1} bool;
	#define BOOL
	#define __BOOL__
#endif
#endif


/* low level functions */
uint8_t		i2c_get_8bit_reg(i2c_addr_t, i2c_reg_t);
uint16_t		i2c_get_16bit_reg(i2c_addr_t, i2c_reg_t);
void			i2c_set_8bit_reg(i2c_addr_t, i2c_reg_t, uint8_t);
void			i2c_set_16bit_reg(i2c_addr_t, i2c_reg_t, uint16_t);

/* advanced functions */
void			i2c_set_bit_in_8bit_reg(i2c_addr_t, i2c_reg_t, uint8_t, bool);
bool			i2c_get_bit_in_8bit_reg(i2c_addr_t, i2c_reg_t, uint8_t);
void			i2c_set_bits_in_8bit_reg(i2c_addr_t, i2c_reg_t, uint8_t, uint8_t, uint8_t);
uint8_t		i2c_get_bits_in_8bit_reg(i2c_addr_t, i2c_reg_t, uint8_t, uint8_t);

void			i2c_ack_poll(i2c_addr_t);

#endif /*I2C_TOOLS_H_*/

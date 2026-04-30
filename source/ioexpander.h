/*
 * ioexpander.h
 *
 *  Created on: 02-Sep-2025
 *      Author: BM_R&D
 */

#ifndef IOEXPANDER_H_
#define IOEXPANDER_H_
#include <stdint.h>
#include "fsl_lpspi.h"
#include "fsl_gpio.h"

typedef enum MCP23S08_REGISTER{
	IODIR,
	IPOL,
	GPINTEN,
	DEFVAL,
	INTCON,
	IOCON,
	GPPU,
	INTF,
	INTCAP,
	GPIO,
	OLAT,
}mcp23s08_register;

#define A0	0
#define A1	0
#define mcp23s08_hardware_addr_def	(0b01000000 | A0 << 1 | A1 << 2)

#define HAEN_SHIFT	3
#define HAEN	(1 << HAEN_SHIFT)

enum {
	LOW,
	HIGH,
};

enum{
	WRITE,
	READ,
};

typedef enum MODE{
	B_ON,
	R_ON,
	G_ON,
	B_R_ON,
	R_G_ON,
	B_G_ON,
	B_R_G_ON,
	B_R_G_OFF,
}mode;

typedef enum GUNNO{
	GUN1 = 1,
	GUN2,
}gunno;

extern void GPIO_ON_OFF(mode, gunno);
extern void lpspi_transfer_function(lpspi_transfer_t*, bool, uint8_t*, uint8_t, uint32_t);
extern void modes_setup(uint8_t*, mode, gunno);
extern lpspi_transfer_t lpspi_master_transfer;
extern uint8_t transmitdata[13];

#endif /* IOEXPANDER_H_ */

/*
 * ioexpander.c
 *
 *  Created on: 04-Sep-2025
 *      Author: BM_R&D
 */

#include "ioexpander.h"

void GPIO_ON_OFF(mode, gunno);
void lpspi_transfer_function(lpspi_transfer_t*, bool, uint8_t*, uint8_t, uint32_t);
void modes_setup(uint8_t*, mode, gunno);
lpspi_transfer_t lpspi_master_transfer;
uint8_t transmitdata[13] = {mcp23s08_hardware_addr_def,IODIR,0,0,0,0,0,HAEN,0,0,0,0,0};

void GPIO_ON_OFF(mode mode, gunno gun_no)
{
	transmitdata[1] = GPIO;
	if(transmitdata[1] == IOCON)
	{
		transmitdata[2] = HAEN;
		transmitdata[3] = 0;
		transmitdata[4] = 0;
		transmitdata[5] = 0;
		modes_setup(&transmitdata[6], mode, gun_no);
		lpspi_transfer_function(&lpspi_master_transfer, WRITE, &transmitdata[0], 7, 10);
	}
	else if(transmitdata[1] == GPIO)
	{
		modes_setup(&transmitdata[2], mode, gun_no);
		lpspi_transfer_function(&lpspi_master_transfer, WRITE, &transmitdata[0], 3, 10);
	}
}

void lpspi_transfer_function(lpspi_transfer_t *lpspi_transfer_t, bool read_write, uint8_t *txData, uint8_t datasize, uint32_t delay)
{
	*(txData + 0) = mcp23s08_hardware_addr_def | read_write;
	(*lpspi_transfer_t).txData = txData;
	(*lpspi_transfer_t).rxData = NULL;
	(*lpspi_transfer_t).dataSize = datasize;
	(*lpspi_transfer_t).configFlags = kLPSPI_MasterPcsContinuous | kLPSPI_MasterByteSwap;
	GPIO_PinWrite(GPIO2, 28U, 0U);
	SDK_DelayAtLeastUs(1, CLOCK_GetFreq(kCLOCK_CpuClk));
	LPSPI_MasterTransferBlocking(LPSPI2, &lpspi_master_transfer);
	SDK_DelayAtLeastUs(1, CLOCK_GetFreq(kCLOCK_CpuClk));
	GPIO_PinWrite(GPIO2, 28U, 1U);
	SDK_DelayAtLeastUs(delay, CLOCK_GetFreq(kCLOCK_CpuClk));
}


void modes_setup(uint8_t *txData, mode mode, gunno gun_no)
{
	if(gun_no == 1)
	{
		*txData &= 0b11111000;
		switch(mode)
		{
		case B_ON:
			*txData |= (1 << 0);
			break;
		case R_ON:
			*txData |= (1 << 1);
			break;
		case G_ON:
			*txData |= (1 << 2);
			break;
		case B_R_ON:
			*txData |= ((1 << 0) | (1 << 1));
			break;
		case R_G_ON:
			*txData |= ((1 << 1) | (1 << 2));
			break;
		case B_G_ON:
			*txData |= ((1 << 0) | (1 << 2));
			break;
		case B_R_G_ON:
			*txData |= ((1 << 0) | (1 << 1) | (1 << 2));
			break;
		case B_R_G_OFF:
			*txData &= (uint8_t)(~((uint8_t)((1 << 0) | (1 << 1) | (1 << 2))));
			break;
		}
	}
	else if(gun_no == 2)
	{
		*txData &= 0b11000111;
		switch(mode)
		{
		case B_ON:
			*txData |= (1 << 3);
			break;
		case R_ON:
			*txData |= (1 << 4);
			break;
		case G_ON:
			*txData |= (1 << 5);
			break;
		case B_R_ON:
			*txData |= ((1 << 3) | (1 << 4));
			break;
		case R_G_ON:
			*txData |= ((1 << 4) | (1 << 5));
			break;
		case B_G_ON:
			*txData |= ((1 << 3) | (1 << 5));
			break;
		case B_R_G_ON:
			*txData |= ((1 << 3) | (1 << 4) | (1 << 5));
			break;
		case B_R_G_OFF:
			*txData &= (uint8_t)(~((uint8_t)((1 << 3) | (1 << 4) | (1 << 5))));
			break;
		}
	}
}

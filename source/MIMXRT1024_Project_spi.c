/*
 * Copyright 2016-2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file    MIMXRT1024_Project_spi.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MIMXRT1024.h"
#include "fsl_debug_console.h"
#include "ioexpander.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */
int main(void) {

    /* Init board hardware. */
    BOARD_ConfigMPU();
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    lpspi_transfer_function(&lpspi_master_transfer, WRITE, &transmitdata[0], 13, 30);

//    GPIO_ON_OFF(G_ON, GUN2);

    while(1) {

    	GPIO_PinWrite(GPIO1, 26, 1);
    	GPIO_PinWrite(GPIO1, 27, 1);
    	GPIO_PinWrite(GPIO1, 28, 1);

    	GPIO_PinWrite(GPIO1, 29, 1);
    	GPIO_PinWrite(GPIO1, 30, 1);
    	GPIO_PinWrite(GPIO1, 31, 1);
    	SDK_DelayAtLeastUs(5000000, CLOCK_GetFreq(kCLOCK_CpuClk));
//
    	GPIO_PinWrite(GPIO1, 26, 0);
    	GPIO_PinWrite(GPIO1, 27, 1);
    	GPIO_PinWrite(GPIO1, 28, 0);
//
//    	GPIO_PinWrite(GPIO1, 29, 1);
//    	GPIO_PinWrite(GPIO1, 30, 0);
//    	GPIO_PinWrite(GPIO1, 31, 0);
////    	GPIO_ON_OFF(G_ON, GUN2);
////    	GPIO_ON_OFF(G_ON, GUN1);
//        SDK_DelayAtLeastUs(5000000, CLOCK_GetFreq(kCLOCK_CpuClk));
//
//    	GPIO_PinWrite(GPIO1, 26, 0);
//    	GPIO_PinWrite(GPIO1, 27, 0);
//    	GPIO_PinWrite(GPIO1, 28, 1);
//
//    	GPIO_PinWrite(GPIO1, 29, 0);
//    	GPIO_PinWrite(GPIO1, 30, 0);
//    	GPIO_PinWrite(GPIO1, 31, 1);
////        GPIO_ON_OFF(B_ON, GUN2);
////        GPIO_ON_OFF(B_ON, GUN1);
//        SDK_DelayAtLeastUs(5000000, CLOCK_GetFreq(kCLOCK_CpuClk));
    }
    return 0 ;
}

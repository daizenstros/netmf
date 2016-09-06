////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// 
// This file is part of the Microsoft .NET Micro Framerwork Porting Kit Code Samples and is unsupported. 
// Copyright (C) Microsoft Corporation. All rights reserved. Use of this sample source code is subject to 
// the terms of the Microsoft license agreement under which you licensed this sample source code. 
// 
// THIS SAMPLE CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, 
// INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
// 
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _AT91SAM9X35_H_1
#define _AT91SAM9X35_H_1 1
    
//
//  PERIPHERAL ID DEFINITIONS FOR AT91SAM9X35
//
#define AT91C_ID_FIQ    ((unsigned int)  0) // Advanced Interrupt Controller (FIQ)
#define AT91C_ID_SYS    ((unsigned int)  1) // System Interrupt
#define AT91C_ID_PIOAB  ((unsigned int)  2) // Parallel IO Controller A and B
#define AT91C_ID_PIOCD  ((unsigned int)  3) // Parallel IO Controller C and D
#define AT91C_ID_SMD    ((unsigned int)  4) // Soft Modem Device
#define AT91C_ID_US0    ((unsigned int)  5) // USART 0
#define AT91C_ID_US1    ((unsigned int)  6) // USART 1
#define AT91C_ID_US2    ((unsigned int)  7) // USART 2
#define AT91C_ID_TWI0   ((unsigned int)  9) // Two-Wire Interface 0 
#define AT91C_ID_TWI1   ((unsigned int) 10) // Two-Wire Interface 1
#define AT91C_ID_TWI2   ((unsigned int) 11) // Two-Wire Interface 2
#define AT91C_ID_TWI    AT91C_ID_TWI0       // only support one I2C
#define AT91C_ID_HSMCI0 ((unsigned int) 12) // High Speed Multimedia Card Interface 0
#define AT91C_ID_SPI0   ((unsigned int) 13) // Serial Peripheral Interface 0
#define AT91C_ID_SPI1   ((unsigned int) 14) // Serial Peripheral Interface 1
#define AT91C_ID_UART0  ((unsigned int) 15) // UART 0
#define AT91C_ID_UART1  ((unsigned int) 16) // UART 1
#define AT91C_ID_TC0    ((unsigned int) 17) // Timer Counter 0-5
#define AT91C_ID_PWMC   ((unsigned int) 18) // Pulse Width Modulation Controller
#define AT91C_ID_TSADCC ((unsigned int) 19) // Touch Panel ADC
#define AT91C_ID_DMAC0  ((unsigned int) 20) // DMA Controller 0
#define AT91C_ID_DMAC1  ((unsigned int) 21) // DMA Controller 1
#define AT91C_ID_UDP    ((unsigned int) 23) // USB High speed Device Port
#define AT91C_ID_EMAC   ((unsigned int) 24) // Ethernet MAC
#define AT91C_ID_LCDC   ((unsigned int) 25) // LCD Controller
#define AT91C_ID_HSMCI1 ((unsigned int) 26) // High Speed Multimedia Card Interface 1
#define AT91C_ID_SSC    ((unsigned int) 28) // Serial Synchronous Controller
#define AT91C_ID_CAN0   ((unsigned int) 29) // Controller Area Network Controller 0
#define AT91C_ID_CAN1   ((unsigned int) 30) // Controller Area Network Controller 1
#define AT91C_ID_IRQ0   ((unsigned int) 31) // Advanced Interrupt Controller (IRQ0)

//
// BASE ADDRESS DEFINITIONS FOR AT91SAM9X35
//
#define AT91C_BASE_SYS          0xFFFFDE00 // (SYS) Base Address
#define AT91C_BASE_MATRIX       0xFFFFDE00 // (MATRIX) Base Address
#define AT91C_BASE_ECC          0xFFFFE000 // (ECC) Address
#define AT91C_BASE_SDRAMC       0xFFFFE800 // (SDRAMC) Base Address
#define AT91C_BASE_SMC          0xFFFFEA00 // (SMC) Base Address
#define AT91C_BASE_DMAC0        0xFFFFEC00 // (DMAC0)Address
#define AT91C_BASE_DMAC1        0xFFFFEE00 // (DMAC1)Address
#define AT91C_BASE_AIC          0xFFFFF000 // (AIC) Base Address
#define AT91C_BASE_PDC_DBGU     0xFFFFF300 // (PDC_DBGU) Base Address
#define AT91C_BASE_DBGU         0xFFFFF200 // (DBGU) Base Address
#define AT91C_BASE_PIOA         0xFFFFF400 // (PIOA) Base Address
#define AT91C_BASE_PIOB         0xFFFFF600 // (PIOB) Base Address
#define AT91C_BASE_PIOC         0xFFFFF800 // (PIOC) Base Address
#define AT91C_BASE_PIOD         0xFFFFFA00 // (PIOD) Base Address
#define AT91C_BASE_CKGR         0xFFFFFC20 // (CKGR) Base Address
#define AT91C_BASE_PMC          0xFFFFFC00 // (PMC) Base Address
#define AT91C_BASE_RSTC         0xFFFFFE00 // (RSTC) Base Address
    #define AT91C_RTSC__PROCRST     0x01         // processor reset bit
    #define AT91C_RTSC__PERRST      0x04         // Peripheral reset bit
    #define AT91C_RTSC__EXTRST      0x08         // asserts NRST pin
    #define AT91C_RSTC__RESET_KEY   0xA5000000   // reset key
#define AT91C_BASE_RSTC_SR      0xFFFFFD04
    #define AT91C_RTSC_SR__SRCMP    (1ul << 17)   // Software Reset Command in progress
    #define AT91C_RTSC_SR__NRSTL    (1ul << 16)   // Registers the NRST Pin Level at Master Clock (MCK)
    #define AT91C_RTSC_SR__RSTTYP   (7ul <<  8)   // Reset Type mask
    #define AT91C_RTSC_SR__BODSTS   (1ul <<  1)   // Brownout Detection Status
    #define AT91C_RTSC_SR__URSTS    (1ul <<  0)   // User Reset Status
#define AT91C_BASE_RSTC_MR      0xFFFFFD08

#define AT91C_BASE_SHDWC        0xFFFFFE10 // (SHDWC) Base Address
#define AT91C_SHDWC__SHUTDOWN_KEY   0xA5000000   // reset key
#define AT91C_SHDWC__SHDW           0x01         // processor reset bit

#define AT91C_BASE_PITC         0xFFFFFE30 // (PITC) Base Address
#define AT91C_BASE_WDTC         0xFFFFFE40 // (WDTC) Base Address
#define AT91C_BASE_SCKCR        0xFFFFFE50 // (SCKCR) Base Address
#define AT91C_BASE_GPBR         0xFFFFFE60 // (GPBR) Base Address
#define AT91C_BASE_RTCC         0xFFFFFEB0 // (RTCC) Base Address

#define AT91C_BASE_PDC_SPI0     0xF0000100 // (PDC_SPI0) Base Address
#define AT91C_BASE_SPI0         0xF0000000 // (SPI0) Base Address
#define AT91C_BASE_PDC_SPI1     0xF0004100 // (PDC_SPI1) Base Address
#define AT91C_BASE_SPI1         0xF0004000 // (SPI1) Base Address
#define AT91C_BASE_PDC_MCI0     0xF0008100 // (PDC_HSMCI0) Base Address
#define AT91C_BASE_MCI0         0xF0008000 // (HSMCI0) Base Address
#define AT91C_BASE_PDC_MCI1     0xF000C100 // (PDC_HSMCI1) Base Address
#define AT91C_BASE_MCI1         0xF000C000 // (HSMCI1) Base Address
#define AT91C_BASE_PDC_SSC      0xF0010100 // (PDC_SSC) Base Address
#define AT91C_BASE_SSC          0xF0010000 // (SSC) Base Address
#define AT91C_BASE_TC0          0xF8008000 // (TC0) Base Address
#define AT91C_BASE_TC1          0xF8008040 // (TC1) Base Address
#define AT91C_BASE_TC2          0xF8008080 // (TC2) Base Address
#define AT91C_BASE_TC3          0xF800C000 // (TC3) Base Address
#define AT91C_BASE_TC4          0xF800C040 // (TC4) Base Address
#define AT91C_BASE_TC5          0xF800C080 // (TC5) Base Address
#define AT91C_BASE_TWI0         0xF8010000 // (TWI0) Base Address
#define AT91C_BASE_TWI1         0xF8014000 // (TWI1) Base Address
#define AT91C_BASE_TWI2         0xF8018000 // (TWI2) Base Address
#define AT91C_BASE_TWI          AT91C_BASE_TWI0 // Support one I2C controller only
#define AT91C_BASE_PDC_US0      0xF801C100 // (PDC_US0) Base Address
#define AT91C_BASE_US0          0xF801C000 // (US0) Base Address
#define AT91C_BASE_PDC_US1      0xF8020100 // (PDC_US1) Base Address
#define AT91C_BASE_US1          0xF8020000 // (US1) Base Address
#define AT91C_BASE_PDC_US2      0xF8024100 // (PDC_US2) Base Address
#define AT91C_BASE_US2          0xF8024000 // (US2) Base Address
#define AT91C_BASE_PWMC         0xF8034000 // (PWMC) Base Address
#define AT91C_BASE_UDP          0xF803C000 // (UDP) Base Address
#define AT91C_BASE_PDC_UART0    0xF8040100 // (PDC_UART0) Base Address
#define AT91C_BASE_UART0        0xF8040000 // (UART0) Base Address
#define AT91C_BASE_PDC_UART1    0xF8044100 // (PDC_UART1) Base Address
#define AT91C_BASE_UART1        0xF8044000 // (UART1) Base Address
#define AT91C_BASE_TSADCC       0xF804C000 // (ADC touch screen) Base Address

#define AT91C_BASE_ITCM         0x00100000 // (ITCM) Base Address
#define AT91C_BASE_DTCM         0x00200000 // (DTCM) Base Address
#define AT91C_BASE_LCDC         0xF8038000 // (LCDC) Base Address
#define AT91C_BASE_LCDC_16B_TFT 0xF8038000 // (LCDC_16B_TFT) Base Address
#define AT91C_BASE_UDP_DMA      0x00500000 // (UDP DMA) Base Address


#define     AT91C_MATRIX_CS3A_SM            (0x1 <<  3) // (MATRIX) Chip Select 3 is assigned to the Static Memory Controller and the SmartMedia Logic is activated.
// Timer number - See AT91_TIMER.H
#define AT91_MAX_TIMER      1 // Hardware has 6 but the interrupt code / peripheral IDs is not setup for a single ID

// Max GPIO number
#define AT91_MAX_GPIO       128

// Max USART Number
#define AT91_MAX_USART      4 // 1 Debug and 3 USART

// Define the multiplexing pins USART
#define AT91_DRXD   AT91_GPIO_Driver::PA9
#define AT91_DTXD   AT91_GPIO_Driver::PA10
#define AT91_TXD0   AT91_GPIO_Driver::PA0
#define AT91_RXD0   AT91_GPIO_Driver::PA1
#define AT91_RTS0   AT91_GPIO_Driver::PA2
#define AT91_CTS0   AT91_GPIO_Driver::PA3
#define AT91_TXD1   AT91_GPIO_Driver::PA5
#define AT91_RXD1   AT91_GPIO_Driver::PA6
#define AT91_RTS1   AT91_GPIO_Driver::PC27
#define AT91_CTS1   AT91_GPIO_Driver::PC28
#define AT91_TXD2   AT91_GPIO_Driver::PA7
#define AT91_RXD2   AT91_GPIO_Driver::PA8
#define AT91_RTS2   AT91_GPIO_Driver::PB0
#define AT91_CTS2   AT91_GPIO_Driver::PB1

// Define the multiplexing pins LCD
//#define AT91_LCDVSYNC  AT91_GPIO_Driver::PC4
#define AT91_LCDHSYNC  AT91_GPIO_Driver::PC5
#define AT91_LCDDOTCK  AT91_GPIO_Driver::PC6
#define AT91_LCDDEN    AT91_GPIO_Driver::PC7
#define AT91_LCDCC     AT91_GPIO_Driver::PC3
#define AT91_LCDPWR    AT91_GPIO_Driver::PC1

//#define AT91_LCDD2     AT91_GPIO_Driver::PC8
#define AT91_LCDD3     AT91_GPIO_Driver::PC9
#define AT91_LCDD4     AT91_GPIO_Driver::PC10
#define AT91_LCDD5     AT91_GPIO_Driver::PC11
#define AT91_LCDD6     AT91_GPIO_Driver::PC12
#define AT91_LCDD7     AT91_GPIO_Driver::PC13

//#define AT91_LCDD10    AT91_GPIO_Driver::PC14
#define AT91_LCDD11    AT91_GPIO_Driver::PC15
#define AT91_LCDD12    AT91_GPIO_Driver::PC16
#define AT91_LCDD13    AT91_GPIO_Driver::PC17
#define AT91_LCDD14    AT91_GPIO_Driver::PC18
#define AT91_LCDD15    AT91_GPIO_Driver::PC19

#define AT91_LCDD18    AT91_GPIO_Driver::PC20
#define AT91_LCDD19    AT91_GPIO_Driver::PC21
#define AT91_LCDD20    AT91_GPIO_Driver::PC22
#define AT91_LCDD21    AT91_GPIO_Driver::PC23
#define AT91_LCDD22    AT91_GPIO_Driver::PC24
#define AT91_LCDD23    AT91_GPIO_Driver::PC25

//PMC
#define AT91C_PMC_PCK         (0x1 << 0 ) /**< (PMC) Processor Clock */
#define AT91C_PMC_PCK0        (0x1 << 8 ) /**< (PMC) Programmable Clock Output */
#define AT91C_PMC_PCK1        (0x1 << 9 ) /**< (PMC) Programmable Clock Output */



#include "../AT91_GPIO/AT91_GPIO.h"
#include "../AT91_SAM/AT91_SAM.h"

#include "../AT91_TIME/AT91_TIME.h"

#include "../AT91_USART/AT91_USART.h"
#include "../AT91_USB/AT91_USB.h"


#define LCD_PMC_ENABLE()    AT91_PMC_EnablePeriphClock(AT91C_ID_LCDC)//to do, enable clock for LCD
#define LCD_PMC_DISABLE()   AT91_PMC_DisablePeriphClock(AT91C_ID_LCDC)//to do, disable clock for LCD

static const UINT8 c_LCD_1[] =
{
    AT91_LCDHSYNC,
    AT91_LCDDOTCK,
    AT91_LCDDEN,
    AT91_LCDCC,
    
};

static const UINT8 c_LCD_2[] =
{  
    AT91_LCDD3,
    AT91_LCDD4,
    AT91_LCDD5,
    AT91_LCDD6,
    AT91_LCDD7,
    AT91_LCDD11,
    AT91_LCDD12,
    AT91_LCDD13,
    AT91_LCDD14,
    AT91_LCDD15,
    AT91_LCDD18,
    AT91_LCDD19,
    AT91_LCDD20,
    AT91_LCDD21,
    AT91_LCDD22,
    AT91_LCDD23,
    AT91_LCDPWR,
};

#define AT91C_MAX_SPI       2
#define AT91C_SPI_CS        4

// Define the multiplexing pins SPI0
#define AT91_SPI0_MISO      AT91_GPIO_Driver::PA11
#define AT91_SPI0_MOSI      AT91_GPIO_Driver::PA12
#define AT91_SPI0_SCLK      AT91_GPIO_Driver::PA13
#define AT91_SPI0_NSS       AT91_GPIO_Driver::PA14

#define AT91_SPI0_NPCS0     AT91_GPIO_Driver::PA14
#define AT91_SPI0_NPCS1     AT91_GPIO_Driver::PA7
#define AT91_SPI0_NPCS2     AT91_GPIO_Driver::PA1
#define AT91_SPI0_NPCS3     AT91_GPIO_Driver::PB3

// Define the multiplexing pins SPI1
#define AT91_SPI1_MISO      AT91_GPIO_Driver::PA21
#define AT91_SPI1_MOSI      AT91_GPIO_Driver::PA22
#define AT91_SPI1_SCLK      AT91_GPIO_Driver::PA23
#define AT91_SPI1_NSS       AT91_GPIO_Driver::PA8

#define AT91_SPI1_NPCS0     AT91_GPIO_Driver::PA8
#define AT91_SPI1_NPCS1     AT91_GPIO_Driver::PA0
#define AT91_SPI1_NPCS2     AT91_GPIO_Driver::PA31
#define AT91_SPI1_NPCS3     AT91_GPIO_Driver::PA30

// define the TWI (i2C) pins
#define AT91_TWI_SDA        AT91_GPIO_Driver::PA30
#define AT91_TWI_SCL        AT91_GPIO_Driver::PA31

#endif // _AT91SAM9X35_H_1


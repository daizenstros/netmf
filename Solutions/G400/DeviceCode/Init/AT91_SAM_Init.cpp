////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) Microsoft Corporation.  All rights reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <tinyhal.h>

#define BOARD_OSCOUNT           (AT91_PMC::CKGR_OSCOUNT & (64 << 8))

#define BOARD_CKGR_PLLA         ((0x1 << 29) | AT91_PMC::CKGR_OUT_0)
#define BOARD_PLLACOUNT         (63 << 8)
#define BOARD_MULA              (AT91_PMC::CKGR_MUL & ((200-1) << 16))
#define BOARD_DIVA              (AT91_PMC::CKGR_DIV & 3)

#define BOARD_PRESCALER         (AT91_PMC::PMC_MDIV_3 | AT91_PMC::PMC_PLLADIV2_DIV2)

#define BOARD_USBEN             (1 << 16)
#define BOARD_USBPLLCOUNT       (0x0F << 20)
#define BOARD_BIASEN            (1 << 24)
#define BOARD_BIASCOUNT         (0x0F << 28)

#define READ(peripheral, register)          (peripheral.register)
#define WRITE(peripheral, register, value)  (peripheral.register = value)

void DebugPrintFlush(void)
{
    AT91_USART &usart = AT91::USART(0);

    while (0 == (usart.US_CSR & AT91_USART::US_TXEMPTY))
        ;
}

void DebugPrintChar(const char c)
{
    AT91_USART &usart = AT91::USART(0);

    while (0 == (usart.US_CSR & AT91_USART::US_TXRDY))
        ;

    usart.US_THR = c;
}

char DebugGetChar(void)
{
    AT91_USART &usart = AT91::USART(0);

    while (0 == (usart.US_CSR & AT91_USART::US_RXRDY))
        ;

    return usart.US_RHR;
}

static void DebugPuts(const char *str)
{
    while ('\0' != *str)
        DebugPrintChar(*str++);
}

int Debug_Write(const char *buffer, size_t size)
{
    for (int i=0; i<size; i++)
        DebugPrintChar(buffer[i]);
    return size;
}

int Debug_Read(char *buffer, size_t size)
{
    for (int i=0; i<size; i++)
        buffer[i] = DebugGetChar();
    return size;
}

void DebugPrintString(const char *str)
{
    DebugPuts(str);
    DebugPrintChar('\r');
    DebugPrintChar('\n');
    DebugPrintFlush();
}

static char getHexChar(unsigned char val)
{
    if (val > 15) {
        return '?';
    } else if (val > 9) {
        return val - 10 + 'A';
    } else {
        return val + '0';
    }
}

void DebugPrintHex8(const char *str, unsigned char hex)
{
    DebugPuts(str);
    DebugPuts(" 0x");
    DebugPrintChar(getHexChar(hex >> 4));
    DebugPrintChar(getHexChar(hex & 0xF));
    DebugPrintChar('\r');
    DebugPrintChar('\n');
    DebugPrintFlush();
}

void DebugPrintHex16(const char *str, unsigned short hex)
{
    DebugPuts(str);
    DebugPuts(" 0x");
    DebugPrintChar(getHexChar(hex >> 12));
    DebugPrintChar(getHexChar((hex >> 8) & 0xF));
    DebugPrintChar(getHexChar((hex >> 4) & 0xF));
    DebugPrintChar(getHexChar(hex & 0xF));
    DebugPrintChar('\r');
    DebugPrintChar('\n');
    DebugPrintFlush();
}

void DebugPrintHex32(const char *str, unsigned int hex)
{
    DebugPuts(str);
    DebugPuts(" 0x");
    DebugPrintChar(getHexChar(hex >> 28));
    DebugPrintChar(getHexChar((hex >> 24) & 0xF));
    DebugPrintChar(getHexChar((hex >> 20) & 0xF));
    DebugPrintChar(getHexChar((hex >> 16) & 0xF));
    DebugPrintChar(getHexChar((hex >> 12) & 0xF));
    DebugPrintChar(getHexChar((hex >> 8) & 0xF));
    DebugPrintChar(getHexChar((hex >> 4) & 0xF));
    DebugPrintChar(getHexChar(hex & 0xF));
    DebugPrintChar('\r');
    DebugPrintChar('\n');
    DebugPrintFlush();
}

void DebugPrintAIC(void)
{
    AT91_AIC &aic = AT91::AIC();

#if 0
    for (int i=0; i<32; i++) {
        UINT32 reg;

        reg = aic.AIC_SMR[i];
        hal_printf("AIC_SMR%2d = 0x%08x    ", i, reg);
        reg = aic.AIC_SVR[i];
        hal_printf("AIC_SVR%2d = 0x%08x\r\n", i, reg);
    }
#endif

//    hal_printf("AIC_IVR  = 0x%08x\r\n", aic.AIC_IVR);
//    DebugPrintHex32("AIC_IVR  =", aic.AIC_IVR);
//    hal_printf("AIC_FVR  = 0x%08x\r\n", aic.AIC_FVR);
//    DebugPrintHex32("AIC_FVR  =", aic.AIC_FVR);
//    hal_printf("AIC_ISR  = 0x%08x\r\n", aic.AIC_ISR);
//    DebugPrintHex32("AIC_ISR  =", aic.AIC_ISR);
//    hal_printf("AIC_IPR  = 0x%08x\r\n", aic.AIC_IPR);
    DebugPrintHex32("AIC_IPR  =", aic.AIC_IPR);
//    hal_printf("AIC_IMR  = 0x%08x\r\n", aic.AIC_IMR);
    DebugPrintHex32("AIC_IMR  =", aic.AIC_IMR);
//    hal_printf("AIC_CISR = 0x%08x\r\n", aic.AIC_CISR);
//    DebugPrintHex32("AIC_CISR =", aic.AIC_CISR);
//    hal_printf("AIC_SPU  = 0x%08x\r\n", aic.AIC_SPU);
//    DebugPrintHex32("AIC_SPU  =", aic.AIC_SPU);
}

/*
* Setup PLL & SDRAM
*/
void AT91_SAM_ClockInit(void)
{
    // Power Management Controller
    AT91_PMC &pmc = AT91::PMC();
    DebugPrintString("");
    DebugPrintString("AT91_SAM_ClockInit: Enter");

    // Initialize main oscillator
    pmc.PMC_CKGR_MOR = BOARD_OSCOUNT | AT91_PMC::CKGR_MOSCEN | AT91_PMC::CKGR_KEY | AT91_PMC::CKGR_MOSCRCEN | AT91_PMC::CKGR_MOSCSEL;
    while (!(pmc.PMC_SR & AT91_PMC::PMC_MOSCS));

#if defined(CAPTURE_MAIN_CLOCK_SPEED)
    while(!(pmc.PMC_CKGR_MCFR & (1 << 16)));

    UINT32 mainClock = (UINT32)(pmc.PMC_CKGR_MCFR & 0xFFFF) * SLOW_CLOCKS_PER_SECOND / 16;
#endif

    // per spec, the before configuring PLLA/B the corresponding bits must be set in the PLLICPR register
    pmc.PMC_PLLICPR = AT91_PMC::PMC_PLLICPR__PLLA | AT91_PMC::PMC_PLLICPR__PLLB;

    // Initialize PLLA
    pmc.PMC_CKGR_PLLAR = BOARD_CKGR_PLLA
                                | BOARD_PLLACOUNT
                                | BOARD_MULA
                                | BOARD_DIVA;
    while (!(pmc.PMC_SR & AT91_PMC::PMC_LOCKA));

    // Initialize UTMI for USB usage
    pmc.PMC_CKGR_UCKR = BOARD_USBEN | BOARD_USBPLLCOUNT | BOARD_BIASEN | BOARD_BIASCOUNT;
    while (!(pmc.PMC_SR & AT91_PMC::PMC_LOCKU));

    // Wait for the master clock if it was already initialized
    while (!(pmc.PMC_SR & AT91_PMC::PMC_MCKRDY));

    // Switch to fast clock
    // Switch to main oscillator + prescaler
    pmc.PMC_MCKR = BOARD_PRESCALER;
    while (!(pmc.PMC_SR & AT91_PMC::PMC_MCKRDY));

    // Switch to PLL + prescaler
    pmc.PMC_MCKR |= AT91_PMC::PMC_CSS_PLLA_CLK;
    while (!(pmc.PMC_SR & AT91_PMC::PMC_MCKRDY));

    DebugPrintString("AT91_SAM_ClockInit: Leave");
}


#if 0
#define GPIO_PIN_TO_PORT(x) (x / AT91_GPIO_Driver::c_PinsPerPort)
#define GPIO_PIN_TO_BIT(x)  (x % AT91_GPIO_Driver::c_PinsPerPort)

/*
* Localize the SDRAM GPIO pin disable code because we are not fully initialized
* In particular, the SmartPtr (GLOBAL_LOCK) code is mapped to the 0 address space 
* which isn't valid until MMU is initialized.
*/
void AT91_SAM_Sdram_DisablePin(UINT32 gpioPin)
{
    AT91_PIO &pioX = AT91::PIO (GPIO_PIN_TO_PORT(gpioPin));

    UINT32 bit = GPIO_PIN_TO_BIT(gpioPin);

    pioX.PIO_PPUDR = bit;
    pioX.PIO_PDR   = bit;
    pioX.PIO_ASR   = bit;
    pioX.PIO_IDR   = bit;
}
#endif

void AT91_SAM_SdramInit(void)
{
#if 0
    ///
    /// Only run SDRAM init if we are not running from SDRAM
    ///
    if((UINT32)&AT91_SAM_SdramInit > SDRAM_MEMORY_Base && 
       (UINT32)&AT91_SAM_SdramInit < (SDRAM_MEMORY_Base + SDRAM_MEMORY_Size))
    {
        return;
    }

    volatile UINT32 *pSdram = (volatile UINT32*) SDRAM_MEMORY_Base;
    int i;

    // Affect PIO lines to SDRAM controller
    AT91_SAM_Sdram_DisablePin( AT91_GPIO_Driver::PC16 );
    AT91_SAM_Sdram_DisablePin( AT91_GPIO_Driver::PC17 );
    AT91_SAM_Sdram_DisablePin( AT91_GPIO_Driver::PC18 );
    AT91_SAM_Sdram_DisablePin( AT91_GPIO_Driver::PC19 );
    AT91_SAM_Sdram_DisablePin( AT91_GPIO_Driver::PC20 );
    AT91_SAM_Sdram_DisablePin( AT91_GPIO_Driver::PC21 );
    AT91_SAM_Sdram_DisablePin( AT91_GPIO_Driver::PC22 );
    AT91_SAM_Sdram_DisablePin( AT91_GPIO_Driver::PC23 );
    AT91_SAM_Sdram_DisablePin( AT91_GPIO_Driver::PC24 );
    AT91_SAM_Sdram_DisablePin( AT91_GPIO_Driver::PC25 );
    AT91_SAM_Sdram_DisablePin( AT91_GPIO_Driver::PC26 );
    AT91_SAM_Sdram_DisablePin( AT91_GPIO_Driver::PC27 );
    AT91_SAM_Sdram_DisablePin( AT91_GPIO_Driver::PC28 );
    AT91_SAM_Sdram_DisablePin( AT91_GPIO_Driver::PC29 );
    AT91_SAM_Sdram_DisablePin( AT91_GPIO_Driver::PC30 );
    AT91_SAM_Sdram_DisablePin( AT91_GPIO_Driver::PC31 );

    // AT91 Bus Matrix controller
    AT91_MATRIX &matrix = AT91::MATRIX();

    // Enable EBI chip select for the SDRAM
    WRITE(matrix, MATRIX_EBICSA, AT91_MATRIX::MATRIX_CS1A_SDRAMC);

    // Sdramc Controller
    AT91_SDRAMC &sdramc = AT91::SDRAMC();

    // CFG Control Register
    sdramc.SDRAMC_CR = (   AT91_SDRAMC::SDRAMC_NC_9  
                                | AT91_SDRAMC::SDRAMC_NR_13 
                                | AT91_SDRAMC::SDRAMC_CAS_2
                                | AT91_SDRAMC::SDRAMC_NB_4_BANKS
                                | AT91_SDRAMC::SDRAMC_DBW_16_BITS
                                | AT91_SDRAMC::SDRAMC_TWR_2
                                | AT91_SDRAMC::SDRAMC_TRC_7
                                | AT91_SDRAMC::SDRAMC_TRP_2
                                | AT91_SDRAMC::SDRAMC_TRCD_2 
                                | AT91_SDRAMC::SDRAMC_TRAS_5
                                | AT91_SDRAMC::SDRAMC_TXSR_8);

        WRITE(sdramc, SDRAMC_MDR, AT91_SDRAMC::SDRAMC_MD_SDRAM);

        AT91_TIME_Driver::Sleep_uSec_Loop(100);

        WRITE(sdramc, SDRAMC_MR, AT91_SDRAMC::SDRAMC_MODE_NOP_CMD);         // Perform NOP
        pSdram[0] = 0x00000000;

        WRITE(sdramc, SDRAMC_MR, AT91_SDRAMC::SDRAMC_MODE_PRCGALL_CMD);     // Set PRCHG AL
        pSdram[0] = 0x00000000;                                             // Perform PRCHG

        AT91_TIME_Driver::Sleep_uSec_Loop(5);

        WRITE(sdramc, SDRAMC_MR, AT91_SDRAMC::SDRAMC_MODE_RFSH_CMD);        // Set 1st CBR for (i=0; i<8; i++)
        for (i=0; i<8; i++)
        {
            pSdram[0] = 0x00000000;                                         // Perform CBR
        }

        WRITE(sdramc, SDRAMC_MR, AT91_SDRAMC::SDRAMC_MODE_RFSH_CMD);        // Set 1st CBR for (i=0; i<8; i++)
        AT91_TIME_Driver::Sleep_uSec_Loop(5);

        WRITE(sdramc, SDRAMC_MR, AT91_SDRAMC::SDRAMC_MODE_LMR_CMD);         // Set LMR operation
        pSdram[0] = 0;                                                      // Perform LMR burst=1, lat=2

        AT91_TIME_Driver::Sleep_uSec_Loop(5);

        WRITE(sdramc, SDRAMC_TR, ((SYSTEM_PERIPHERAL_CLOCK_HZ / ONE_MHZ) * 781) / 100); // Set Refresh Timer

        AT91_TIME_Driver::Sleep_uSec_Loop(5);

        WRITE(sdramc, SDRAMC_MR, AT91_SDRAMC::SDRAMC_MODE_NORMAL_CMD);      // Set Normal mode
        pSdram[0] = 0x00000000;

        AT91_TIME_Driver::Sleep_uSec_Loop(5);
#endif
}


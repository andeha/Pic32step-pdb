/*  regs-mm.c | the structure of MM and no double. */

import litenbeam;

/* CP0, register 16, 0 */ BITMASK (uint32_t) { /* MIPS Config */
  MIPS_Config_K23 = 0b111<<28, /* Cacheability kseg2 and kseg3 */
  MIPS_Config_KU = 0b111<<25,  /* Cacheability kuseg and useg */
// MIPS_Config_ISP = 0b1<<24,   /* Instruction scratch pad RAM */
// MIPS_Config_DSP = 0b1<<23,   /* Data scratch pad RAM */
  MIPS_Config_UDI = 0b1<<22,   /* User-defined */
  MIPS_Config_SB = 0b1<<21,    /* Simple BE */
  MIPS_Config_MDU = 0b1<<20,   /* Multiply/divide unit */
// MIPS_Config_MM = 0b11<<17,   /* Merge mode */
  MIPS_Config_DS = 0b1<<16,    /* Dual SRAM Interface */
// MIPS_Config_DSBM = 0b1<<16,  /* Dual SRAM/burst mode */
// MIPS_Config_BM = 0b1<<16,    /* Burst mode */
  MIPS_Config_BE = 0b1<<15,    /* Endian mode */
  MIPS_Config_AT = 0b11<<13,   /* Architecture type */
  MIPS_Config_AR = 0b111<<10,  /* Architecture revision level */
  MIPS_Config_MT = 0b111<<7,   /* MMU Type */
  MIPS_Config_K0 = 0b111<<0    /* Kseg0 Coherency Algorithm */
};

Bitfield MipsMM_Config[] = {
  { Ū("MIPS_Config_K23"), MIPS_Config_K23, Ū("Cacheability kseg2 and kseg3") },
  { Ū("MIPS_Config_KU"), MIPS_Config_KU, Ū("Cacheability kuseg and useg") },
  { Ū("MIPS_Config_UDI"), MIPS_Config_UDI, Ū("User-defined") },
  { Ū("MIPS_Config_SB"), MIPS_Config_SB, Ū("Simple BE") },
  { Ū("MIPS_Config_MDU"), MIPS_Config_MDU, Ū("Multiply/Divide Unit") },
  { Ū("MIPS_Config_DS"), MIPS_Config_DS, Ū("Dual SRAM Interface") },
  { Ū("MIPS_Config_BE"), MIPS_Config_BE, Ū("Endian Mode") },
  { Ū("MIPS_Config_AT"), MIPS_Config_AT, Ū("Architecture Type") },
  { Ū("MIPS_Config_AR"), MIPS_Config_AR, Ū("Architecture Revision Level") },
  { Ū("MIPS_Config_MT"), MIPS_Config_MT, Ū("MMU Type") },
  { Ū("MIPS_Config_K0"), MIPS_Config_K0, Ū("Kseg0 Coherency Algorithm") },
};

AnnotatedRegister AR_MipsMM_Config = {
  Ū("Config: Configuration Register (CP0 Register 16, Select 0)"),
  11, MipsMM_Config, 0x80000000,
  Ū("")
};

/* CP0, register 23, 0 */ BITMASK(uint32_t) { /* Debug Register */
  MIPS_Debug_DBD        = 0b10000000000000000000000000000000, /* Branch ͞ Debug Exception */
  MIPS_Debug_DM         = 0b01000000000000000000000000000000, /* Debug Mode */
  MIPS_Debug_NODCR      = 0b00100000000000000000000000000000, /* Debug Control Register */
  MIPS_Debug_LSNM       = 0b00010000000000000000000000000000, /* Load Store Access Control */
  MIPS_Debug_DOZE       = 0b00001000000000000000000000000000, /* Low-Power Mode Debug Exception */
  MIPS_Debug_HALT       = 0b00000100000000000000000000000000, /* System Bus Clock Stop */
  MIPS_Debug_COUNTDM    = 0b00000010000000000000000000000000, /* Count Register Behavior */
  MIPS_Debug_IBUSEP     = 0b00000001000000000000000000000000, /* Instruction Fetch Bus Error Exception Pending */
  MIPS_Debug_MCHECKP    = 0b00000000100000000000000000000000, /* Machine Check Exception Pending */
  MIPS_Debug_CACHEEP    = 0b00000000010000000000000000000000, /* Cache Error Pending */
  MIPS_Debug_DBUSEP     = 0b00000000001000000000000000000000, /* Data Access Bus Error Exception Pending */
  MIPS_Debug_IEXI       = 0b00000000000100000000000000000000, /* Imprecise Error Exception Inhibit Control */
  MIPS_Debug_DDBSIMPR   = 0b00000000000010000000000000000000, /* Debug Data Break Store Exception */
  MIPS_Debug_DDBLIMPR   = 0b00000000000001000000000000000000, /* Debug Data Break Load Exception */
  MIPS_Debug_VER_3͞      = 0b00000000000000111000000000000000, /* EJTAG Version */
  MIPS_Debug_DEXCCODE_5͞ = 0b00000000000000000111110000000000, /* Latest Exception in Debug Mode */
  MIPS_Debug_NOSST      = 0b00000000000000000000001000000000, /* Singe-step Feature Control */
  MIPS_Debug_SST        = 0b00000000000000000000000100000000, /* Debug Single-step Control */
  MIPS_Debug_DIBIMPR    = 0b00000000000000000000000001000000, /* Imprecise Debug Instruction Break Exception */
  MIPS_Debug_DINT       = 0b00000000000000000000000000100000, /* Debug Interrupt Exception */
  MIPS_Debug_DIB        = 0b00000000000000000000000000010000, /* Debug Instruction Break Exception */
  MIPS_Debug_DDBS       = 0b00000000000000000000000000001000, /* Debug Data Break Exception on Store */
  MIPS_Debug_DDBL       = 0b00000000000000000000000000000100, /* Debug Data Break Exception on Load */
  MIPS_Debug_DBP        = 0b00000000000000000000000000000010, /* Debug Software Breakpoint Exception */
  MIPS_Debug_DSS        = 0b00000000000000000000000000000001  /* Debug Single-step Exception */
};

Bitfield MipsMM_Debug[] = {
  { Ū("MIPS_Debug_DBD"), MIPS_Debug_DBD, Ū("Branch Delay Debug Exception") },
  { Ū("MIPS_Debug_DM"), MIPS_Debug_DM, Ū("Debug Mode") },
  { Ū("MIPS_Debug_NODCR"), MIPS_Debug_NODCR, Ū("Debug Control Register") },
  { Ū("MIPS_Debug_LSNM"), MIPS_Debug_LSNM, Ū("Load Store Access Control") },
  { Ū("MIPS_Debug_DOZE"), MIPS_Debug_DOZE, Ū("Low-Power Mode Debug Exception") },
  { Ū("MIPS_Debug_HALT"), MIPS_Debug_HALT, Ū("System Bus Clock Stop") },
  { Ū("MIPS_Debug_COUNTDM"), MIPS_Debug_COUNTDM, Ū("Count Register Behavior") },
  { Ū("MIPS_Debug_IBUSEP"), MIPS_Debug_IBUSEP, Ū("Instruction Fetch Bus Error Exception Pending") },
  { Ū("MIPS_Debug_MCHECKP"), MIPS_Debug_MCHECKP, Ū("Machine Check Exception Pending") },
  { Ū("MIPS_Debug_CACHEEP"), MIPS_Debug_CACHEEP, Ū("Cache Error Pending") },
  { Ū("MIPS_Debug_DBUSEP"), MIPS_Debug_DBUSEP, Ū("Data Access Bus Error Exception Pending") },
  { Ū("MIPS_Debug_IEXI"), MIPS_Debug_IEXI, Ū("Imprecise Error Exception Inhibit Control") },
  { Ū("MIPS_Debug_DDBSIMPR"), MIPS_Debug_DDBSIMPR, Ū("Debug Data Break Store Exception") },
  { Ū("MIPS_Debug_DDBLIMPR"), MIPS_Debug_DDBLIMPR, Ū("Debug Data Break Load Exception") },
  { Ū("MIPS_Debug_VER_3"), MIPS_Debug_VER_3͞, Ū("EJTAG Version") },
  { Ū("MIPS_Debug_DEXCCODE_5"), MIPS_Debug_DEXCCODE_5͞, Ū("Latest Exception in Debug Mode") },
  { Ū("MIPS_Debug_NOSST"), MIPS_Debug_NOSST, Ū("Single-step Feature Control") },
  { Ū("MIPS_Debug_SST"), MIPS_Debug_SST, Ū("Debug Single-step Control") },
  { Ū("MIPS_Debug_DIBIMPR"), MIPS_Debug_DIBIMPR, Ū("Imprecise Debug Instruction Break Exception") },
  { Ū("MIPS_Debug_DINT"), MIPS_Debug_DINT, Ū("Debug Interrupt Exception") },
  { Ū("MIPS_Debug_DIB"), MIPS_Debug_DIB, Ū("Debug Instruction Break Exception") },
  { Ū("MIPS_Debug_DDBS"), MIPS_Debug_DDBS, Ū("Debug Data Break Exception on Store") },
  { Ū("MIPS_Debug_DDBL"), MIPS_Debug_DDBL, Ū("Debug Data Break Exception on Load") },
  { Ū("MIPS_Debug_DBP"), MIPS_Debug_DBP, Ū("Debug Software Breakpoint Exception") },
  { Ū("MIPS_Debug_DSS"), MIPS_Debug_DSS, Ū("Debug Single-step Exception") }
};

AnnotatedRegister AR_MipsMM_Debug = {
  Ū("Debug Register (CP0 Register 23, Select 0)"),
  25, MipsMM_Debug, 0x00000000,
  Ū("")
};

BITMASK (uint32_t) { /* INTCON */
  PIC32MM_INTCON_VS = 0b1111111<<16, /* Vector Spacing */
  PIC32MM_INTCON_MVEC = 0b1<<12, /* Multivector Configuration */
  PIC32MM_INTCON_TPC = 0b111<<8, /* Interrupt Proximity Timer Control */
  PIC32MM_INTCON_INT4EP = 0b1<<4, /* Ext. Irq 4 Edge Polarity Ctrl */
  PIC32MM_INTCON_INT3EP = 0b1<<3, /* Ext. Irq 3 Edge Polarity Ctrl */
  PIC32MM_INTCON_INT2EP = 0b1<<2, /* Ext. Irq 2 Edge Polarity Ctrl */
  PIC32MM_INTCON_INT1EP = 0b1<<1, /* Ext. Irq 1 Edge Polarity Ctrl */
  PIC32MM_INTCON_INT0EP = 0b1<<0 /*  Ext. Irq 0 Edge Polarity Ctrl */
};

Bitfield MicrochipMM_INTCON[] = {
  { Ū("PIC32MM_INTCON_VS"), PIC32MM_INTCON_VS, Ū("Vector Spacing") },
  { Ū("PIC32MM_INTCON_MVEC"), PIC32MM_INTCON_MVEC, Ū("Multi Vector Configuration") },
  { Ū("PIC32MM_INTCON_TPC"), PIC32MM_INTCON_TPC, Ū("Interrupt Proximity Timer Control") },
  { Ū("PIC32MM_INTCON_INT4EP"), PIC32MM_INTCON_INT4EP, Ū("Ext. Irq 4 Edge Polarity Ctrl") },
  { Ū("PIC32MM_INTCON_INT3EP"), PIC32MM_INTCON_INT3EP, Ū("Ext. Irq 3 Edge Polarity Ctrl") },
  { Ū("PIC32MM_INTCON_INT2EP"), PIC32MM_INTCON_INT2EP, Ū("Ext. Irq 2 Edge Polarity Ctrl") },
  { Ū("PIC32MM_INTCON_INT1EP"), PIC32MM_INTCON_INT1EP, Ū("Ext. Irq 1 Edge Polarity Ctrl") },
  { Ū("PIC32MM_INTCON_INT0EP"), PIC32MM_INTCON_INT0EP, Ū("Ext. Irq 0 Edge Polarity Ctrl") }
};

AnnotatedRegister AR_MicrochipMM_INTCON = {
  Ū("INTCON: INTERRUPT CONTROL REGISTER"),
  8, MicrochipMM_INTCON, 0x00000000,
  Ū("")
};

BITMASK (uint32_t) { /* PRISS */
  PIC32MM_PRISS_PRI7SS = 0xf0000000, /* Irq with Prio Level 7 Shadow Set */
  PIC32MM_PRISS_PRI6SS = 0x0f000000, /* Irq with Prio Level 6 Shadow Set */
  PIC32MM_PRISS_PRI5SS = 0x00f00000, /* Irq with Prio Level 5 Shadow Set */
  PIC32MM_PRISS_PRI4SS = 0x000f0000, /* Irq with Prio Level 4 Shadow Set */
  PIC32MM_PRISS_PRI3SS = 0x0000f000, /* Irq with Prio Level 3 Shadow Set */
  PIC32MM_PRISS_PRI2SS = 0x00000f00, /* Irq with Prio Level 2 Shadow Set */
  PIC32MM_PRISS_PRI1SS = 0x000000f0, /* Irq with Prio Level 1 Shadow Set */
  PIC32MM_PRISS_SS0 = 0b1<<0 /* Single Vector Shadow Register Set */
};

Bitfield MicrochipMM_PRISS[] = {
  { Ū("PIC32MM_PRISS_PRI7SS"), PIC32MM_PRISS_PRI7SS, Ū("Interrupt with Priority Level 7 Shadow Set") },
  { Ū("PIC32MM_PRISS_PRI6SS"), PIC32MM_PRISS_PRI6SS, Ū("Interrupt with Priority Level 6 Shadow Set") },
  { Ū("PIC32MM_PRISS_PRI5SS"), PIC32MM_PRISS_PRI5SS, Ū("Interrupt with Priority Level 5 Shadow Set") },
  { Ū("PIC32MM_PRISS_PRI4SS"), PIC32MM_PRISS_PRI4SS, Ū("Interrupt with Priority Level 4 Shadow Set") },
  { Ū("PIC32MM_PRISS_PRI3SS"), PIC32MM_PRISS_PRI3SS, Ū("Interrupt with Priority Level 3 Shadow Set") },
  { Ū("PIC32MM_PRISS_PRI2SS"), PIC32MM_PRISS_PRI2SS, Ū("Interrupt with Priority Level 2 Shadow Set") },
  { Ū("PIC32MM_PRISS_PRI1SS"), PIC32MM_PRISS_PRI1SS, Ū("Interrupt with Priority Level 1 Shadow Set") },
  { Ū("PIC32MM_PRISS_SS0"),    PIC32MM_PRISS_SS0, Ū("Single Vector Shadow Register Set") }
};

AnnotatedRegister AR_MicrochipMM_PRISS = {
  Ū("PRISS: PRIORITY SHADOW SELECT REGISTER"),
  8, MicrochipMM_PRISS, 0x00000000,
  Ū("")
};

BITMASK (uint32_t) { /* INTSTAT */
  PIC32MM_INTSTAT_SRIPL = 0b111<<8, /* Requested Priority Level bits for Single Vector Mode */
  PIC32MM_INTSTAT_SIRQ = 0xff /* Last Interrupt Request Serviced Status */
};

Bitfield MicrochipMM_INTSTAT[] = {
  { Ū("PIC32MM_INTSTAT_SRIPL"), PIC32MM_INTSTAT_SRIPL, Ū("Requested Priority Level bits for Single Vector Mode") },
  { Ū("PIC32MM_INTSTAT_SIRQ"),  PIC32MM_INTSTAT_SIRQ, Ū("Last Interrupt Request Serviced Status") }
};

AnnotatedRegister AR_MicrochipMM_INTSTAT = {
  Ū("INTSTAT: INTERRUPT STATUS REGISTER"),
  2, MicrochipMM_INTSTAT, 0x00000000,
  Ū("")
};

BITMASK (uint32_t) { /* IPTMR */
  PIC32MM_IPTMR_IPTMR = 0xffffffff /* Interrupt Proximity Timer Reload */
};

Bitfield MicrochipMM_IPTMR[] = {
  { Ū("PIC32MM_IPTMR_IPTMR"), PIC32MM_IPTMR_IPTMR, Ū("Interrupt Proximity Timer Reload") }
};

AnnotatedRegister AR_MicrochipMM_IPTMR = {
  Ū("IPTMR: INTERRUPT PROXIMITY TIMER REGISTER"),
  1, MicrochipMM_IPTMR, 0x00000000,
  Ū("")
};

BITMASK (uint32_t) { /* IFS0 */
  PIC32MM_IFS0_CCP2IF = 0x80000000, /* Capture/Compare/PWM/Timer P2 Interrupt */
  PIC32MM_IFS0_CCT1IF = 0b1<<30, /* Capture/Compare/PWM/Timer T1 Interrupt */
  PIC32MM_IFS0_CCP1IF = 0b1<<29, /* Capture/Compare/PWM/Timer P1 Interrupt */
  PIC32MM_IFS0_U1EIF = 0b1<<25, /* Uart 1 Generic Interrupt */
  PIC32MM_IFS0_U1TXIF = 0b1<<24, /* Uart 1 Tx Interrupt */
  PIC32MM_IFS0_U1RXIF = 0b1<<23, /* Uart 1 Rx Interrupt */
  PIC32MM_IFS0_SPI1RXIF = 0b1<<22, /* Spi1 Rx Interrupt */
  PIC32MM_IFS0_SPI1TXIF = 0b1<<21, /* Spi1 Tx Interrupt */
  PIC32MM_IFS0_SPI1EIF = 0b1<<20, /* Spi1 Generic Interrupt */
  PIC32MM_IFS0_CLC2IF = 0b1<<19, /* Logic 2 Interrupt */
  PIC32MM_IFS0_CLC1IF = 0b1<<18, /* Logic 1 Interrupt */
  PIC32MM_IFS0_LVDIF = 0b1<<17, /* High/Low-Voltage Detect Interrupt */
  PIC32MM_IFS0_CRCIF = 0b1<<16, /* CRC Interrupt */
  PIC32MM_IFS0_AD1IF = 0b1<<15, /* ADC 1 Interrupt */
  PIC32MM_IFS0_RTCCIF = 0b1<<14, /* RTCC Interrupt */
  PIC32MM_IFS0_CMP2IF = 0b1<<13, /* Comparator 2 Interrupt */
  PIC32MM_IFS0_CMP1IF = 0b1<<12, /* Comparator 1 Interrupt */
  PIC32MM_IFS0_T1IF = 0b1<<11, /* Timer 1 Interrupt */
  PIC32MM_IFS0_CNCIF = 0b1<<10, /* Change Notification C */
  PIC32MM_IFS0_CNBIF = 0b1<<9, /* Change Notification B */
  PIC32MM_IFS0_CNAIF = 0b1<<8, /* Change Notification A */
  PIC32MM_IFS0_INT4IF = 0b1<<7, /* External Interrupt 4 */
  PIC32MM_IFS0_INT3IF = 0b1<<6, /* External Interrupt 3 */
  PIC32MM_IFS0_INT2IF = 0b1<<5, /* External Interrupt 2 */
  PIC32MM_IFS0_INT1IF = 0b1<<4, /* External Interrupt 1 */
  PIC32MM_IFS0_INT0IF = 0b1<<3, /* External Interrupt 0 */
  PIC32MM_IFS0_CS1IF = 0b1<<2, /* Core Software Interrupt 1 */
  PIC32MM_IFS0_CS0IF = 0b1<<1, /* Core Software Interrupt 0 */
  PIC32MM_IFS0_CTIF = 0b1<<0 /* Core Timer Interrupt */
};

Bitfield MicrochipMM_IFS0[] = {
  { Ū("PIC32MM_IFS0_CCP2IF"), PIC32MM_IFS0_CCP2IF, Ū("Capture/Compare/PWM/Timer P2 Interrupt") },
  { Ū("PIC32MM_IFS0_CCT1IF"), PIC32MM_IFS0_CCT1IF, Ū("Capture/Compare/PWM/Timer T1 Interrupt") },
  { Ū("PIC32MM_IFS0_CCP1IF"), PIC32MM_IFS0_CCP1IF, Ū("Capture/Compare/PWM/Timer P1 Interrupt") },
  { Ū("PIC32MM_IFS0_U1EIF"), PIC32MM_IFS0_U1EIF, Ū("Uart 1 Generic Interrupt") },
  { Ū("PIC32MM_IFS0_U1TXIF"), PIC32MM_IFS0_U1TXIF, Ū("Uart 1 Tx Interrupt") },
  { Ū("PIC32MM_IFS0_U1RXIF"), PIC32MM_IFS0_U1RXIF, Ū("Uart 1 Rx Interrupt") },
  { Ū("PIC32MM_IFS0_SPI1RXIF"), PIC32MM_IFS0_SPI1RXIF, Ū("Spi1 Rx Interrupt") },
  { Ū("PIC32MM_IFS0_SPI1TXIF"), PIC32MM_IFS0_SPI1TXIF, Ū("Spi1 Tx Interrupt") },
  { Ū("PIC32MM_IFS0_SPI1EIF"), PIC32MM_IFS0_SPI1EIF, Ū("Spi1 Generic Interrupt") },
  { Ū("PIC32MM_IFS0_CLC2IF"), PIC32MM_IFS0_CLC2IF, Ū("Logic 2 Interrupt") },
  { Ū("PIC32MM_IFS0_CLC1IF"), PIC32MM_IFS0_CLC1IF, Ū("Logic 1 Interrupt") },
  { Ū("PIC32MM_IFS0_LVDIF"), PIC32MM_IFS0_LVDIF, Ū("High/Low-Voltage Detect Interrupt") },
  { Ū("PIC32MM_IFS0_CRCIF"), PIC32MM_IFS0_CRCIF, Ū("CRC Interrupt") },
  { Ū("PIC32MM_IFS0_AD1IF"), PIC32MM_IFS0_AD1IF, Ū("ADC 1 Interrupt") },
  { Ū("PIC32MM_IFS0_RTCCIF"), PIC32MM_IFS0_RTCCIF, Ū("RTCC Interrupt") },
  { Ū("PIC32MM_IFS0_CMP2IF"), PIC32MM_IFS0_CMP2IF, Ū("Comparator 2 Interrupt") },
  { Ū("PIC32MM_IFS0_CMP1IF"), PIC32MM_IFS0_CMP1IF, Ū("Comparator 1 Interrupt") },
  { Ū("PIC32MM_IFS0_T1IF"), PIC32MM_IFS0_T1IF, Ū("Timer 1 Interrupt") },
  { Ū("PIC32MM_IFS0_CNCIF"), PIC32MM_IFS0_CNCIF, Ū("Change Notification C") },
  { Ū("PIC32MM_IFS0_CNBIF"), PIC32MM_IFS0_CNBIF, Ū("Change Notification B") },
  { Ū("PIC32MM_IFS0_CNAIF"), PIC32MM_IFS0_CNAIF, Ū("Change Notification A") },
  { Ū("PIC32MM_IFS0_INT4IF"), PIC32MM_IFS0_INT4IF, Ū("External Interrupt 4") },
  { Ū("PIC32MM_IFS0_INT3IF"), PIC32MM_IFS0_INT3IF, Ū("External Interrupt 3") },
  { Ū("PIC32MM_IFS0_INT2IF"), PIC32MM_IFS0_INT2IF, Ū("External Interrupt 2") },
  { Ū("PIC32MM_IFS0_INT1IF"), PIC32MM_IFS0_INT1IF, Ū("External Interrupt 1") },
  { Ū("PIC32MM_IFS0_INT0IF"), PIC32MM_IFS0_INT0IF, Ū("External Interrupt 0") },
  { Ū("PIC32MM_IFS0_CS1IF"), PIC32MM_IFS0_CS1IF, Ū("Core Software Interrupt 1") },
  { Ū("PIC32MM_IFS0_CS0IF"), PIC32MM_IFS0_CS0IF, Ū("Core Software Interrupt 0") },
  { Ū("PIC32MM_IFS0_CTIF"), PIC32MM_IFS0_CTIF, Ū("Core Timer Interrupt") }
};

AnnotatedRegister AR_MicrochipMM_IFS0 = {
  Ū("IFS0: INTERRUPT FLAG REGISTER 0"),
  29, MicrochipMM_IFS0, 0x00000000,
  Ū("")
};

BITMASK (uint32_t) { /* IFS1 */
  PIC32MM_IFS1_CPCIF = 0b1<<15, /* */
  PIC32MM_IFS1_NVMIF = 0b1<<14, /* Non-volatile Interrupt */
  PIC32MM_IFS1_U2EIF = 0b1<<10, /* Uart 2 Generic Interrupt */
  PIC32MM_IFS1_U2TXIF = 0b1<<9, /* Uart 2 Tx Interrupt */
  PIC32MM_IFS1_U2RXIF = 0b1<<8, /* Uart 2 Rx Interrupt */
  PIC32MM_IFS1_SPI2RXIF = 0b1<<7, /* Spi2 Rx Interrupt */
  PIC32MM_IFS1_SPI2TXIF = 0b1<<6, /* Spi2 Tx Interrupt */
  PIC32MM_IFS1_SPI2EIF = 0b1<<5, /* Spi2 Generic Interrupt */
  PIC32MM_IFS1_CCT3IF = 0b1<<2, /* Capture/Compare/PWM/Timer T3 Interrupt */
  PIC32MM_IFS1_CCP3IF = 0b1<<1, /* Capture/Compare/PWM/Timer P3 Interrupt */
  PIC32MM_IFS1_CCT2IF = 0b1<<0, /* Capture/Compare/PWM/Timer T2 Interrupt */
};

Bitfield MicrochipMM_IFS1[] = {
  { Ū("PIC32MM_IFS1_CPCIF"), PIC32MM_IFS1_CPCIF, Ū("") },
  { Ū("PIC32MM_IFS1_NVMIF"), PIC32MM_IFS1_NVMIF, Ū("Non-volatile Interrupt") },
  { Ū("PIC32MM_IFS1_U2EIF"), PIC32MM_IFS1_U2EIF, Ū("Uart 2 Generic Interrupt") },
  { Ū("PIC32MM_IFS1_U2TXIF"), PIC32MM_IFS1_U2TXIF, Ū("Uart 2 Tx Interrupt") },
  { Ū("PIC32MM_IFS1_U2RXIF"), PIC32MM_IFS1_U2RXIF, Ū("Uart 2 Rx Interrupt") },
  { Ū("PIC32MM_IFS1_SPI2RXIF"), PIC32MM_IFS1_SPI2RXIF, Ū("Spi2 Rx Interrupt") },
  { Ū("PIC32MM_IFS1_SPI2TXIF"), PIC32MM_IFS1_SPI2TXIF, Ū("Spi2 Tx Interrupt") },
  { Ū("PIC32MM_IFS1_SPI2EIF"), PIC32MM_IFS1_SPI2EIF, Ū("Spi2 Generic Interrupt") },
  { Ū("PIC32MM_IFS1_CCT3IF"), PIC32MM_IFS1_CCT3IF, Ū("Capture/Compare/PWM/Timer T3 Interrupt") },
  { Ū("PIC32MM_IFS1_CCP3IF"), PIC32MM_IFS1_CCP3IF, Ū("Capture/Compare/PWM/Timer P3 Interrupt") },
  { Ū("PIC32MM_IFS1_CCT2IF"), PIC32MM_IFS1_CCT2IF, Ū("Capture/Compare/PWM/Timer T2 Interrupt") }
};

AnnotatedRegister AR_MicrochipMM_IFS1 = {
  Ū("IFS1: INTERRUPT FLAG REGISTER 1"),
  11, MicrochipMM_IFS0, 0x00000000,
  Ū("")
};



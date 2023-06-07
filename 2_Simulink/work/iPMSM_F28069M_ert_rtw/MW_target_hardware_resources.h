#ifndef PORTABLE_WORDSIZES
#ifdef __MW_TARGET_USE_HARDWARE_RESOURCES_H__
#ifndef __MW_TARGET_HARDWARE_RESOURCES_H__
#define __MW_TARGET_HARDWARE_RESOURCES_H__

#define MW_MULTI_TASKING_MODE 1
#include "c2000BoardSupport.h"
#include "F2806x_Device.h"
#include "F2806x_Examples.h"
#include "F2806x_GlobalPrototypes.h"
#include "F2806x_CpuTimers.h"
#include "c2000SchedulerTimer.h"

#define MW_USECODERTARGET 1
#define MW_TARGETHARDWARE TI Piccolo F28069M LaunchPad
#define MW_CONNECTIONINFO_SERIAL_IPADDRESS codertarget.registry.getLoopbackIP;
#define MW_CONNECTIONINFO_SERIAL_PORT 17725
#define MW_CONNECTIONINFO_SERIAL_VERBOSE 0
#define MW_CONNECTIONINFO_SERIALUSINGXCP_BAUDRATE codertarget.registry.getExtModeHostBaud(hCS);
#define MW_CONNECTIONINFO_SERIALUSINGXCP_COMPORT COM1
#define MW_CONNECTIONINFO_SERIALUSINGXCP_VERBOSE 1
#define MW_CONNECTIONINFO_CAN_MEXARGS  
#define MW_CONNECTIONINFO_XCPONCAN_MEXARGS  
#define MW_CONNECTIONINFO_XCPONCAN_BUSSPEED codertarget.registry.getExtModeCANBusSpeed(hCS)
#define MW_CONNECTIONINFO_XCPONCAN_CANCHANNEL 
#define MW_CONNECTIONINFO_XCPONCAN_CANDEVICE 
#define MW_CONNECTIONINFO_XCPONCAN_CANIDCOMMAND 2
#define MW_CONNECTIONINFO_XCPONCAN_CANIDRESPONSE 3
#define MW_CONNECTIONINFO_XCPONCAN_CANVENDOR 
#define MW_CONNECTIONINFO_XCPONCAN_ISCANIDEXTENDED 0
#define MW_CONNECTIONINFO_XCPONCAN_VERBOSE 1
#define MW_CONNECTIONINFO_XCPONSERIAL_BAUDRATE codertarget.registry.getExtModeHostBaud(hCS);
#define MW_CONNECTIONINFO_XCPONSERIAL_COMPORT codertarget.registry.serialPortValueCallback(hCS, 'ExtModeCOMPort');
#define MW_CONNECTIONINFO_XCPONSERIAL_VERBOSE 1
#define MW_EXTMODE_CONFIGURATION XCP on Serial
#define MW_EXTMODE_SIGNALBUFFERSIZE 2000.000000
#define MW_EXTMODE_SCIMODULE 0
#define MW_EXTMODE_HOSTINTERFACE 3P Tools
#define MW_EXTMODE_CANMODULE 0
#define MW_EXTMODE_CANIDTYPE Standard (11-bit)
#define MW_EXTMODE_CANMASTERID 0x02
#define MW_EXTMODE_CANSLAVEID 0x03
#define MW_EXTMODE_CANRXMAILBOXNUMBER 0
#define MW_EXTMODE_CANTXMAILBOXNUMBER 1
#define MW_EXTMODE_USEREALTIMESTAMPLOGGING 0
#define MW_RTOS Baremetal
#define MW_SCHEDULER_INTERRUPT_SOURCE 0
#define MW_RUNTIME_BUILDACTION 1
#define MW_RUNTIME_DEVICEID 0
#define MW_RUNTIME_FLASHLOAD 1
#define MW_RUNTIME_BOOTLOADERPROGRAMMINGSUPPORT 0
#define MW_RUNTIME_BOOTLOADERCHOICE 0
#define MW_RUNTIME_BOOTLOADERCOMPORT COM1
#define MW_RUNTIME_LOADCOMMANDARG $(TARGET_ROOT)/CCS_Config/f28069.ccxml
#define MW_RUNTIME_DMAACCESS 0
#define MW_RUNTIME_BOOTLOADERCOMPATIBLEOS 1
#define MW_RUNTIME_ENABLEFASTRTS 1
#define MW_RUNTIME_DISABLEPARALLELBUILD 0
#define MW_TARGETLINKOBJ_USECUSTOMLINKER 0
#define MW_TARGETLINKOBJ_NAME $(TARGET_ROOT)/src/c28069M.cmd
#define MW_CLOCKING_CPUCLOCKRATEMHZ 90
#define MW_CLOCKING_USEINTERNALOSC 1
#define MW_CLOCKING_OSCCLK 10
#define MW_CLOCKING_AUTOSETPLLSETTINGS 1
#define MW_CLOCKING_PLLCR 7
#define MW_CLOCKING_DIVSEL 2
#define MW_CLOCKING_CLOSESTCPUCLOCK 90
#define MW_CLOCKING_LSPCLKDIV 0
#define MW_CLOCKING_LSPCLK 90
#define MW_ADC_CLOCKDIV 1
#define MW_ADC_CLOCKFREQUENCY 45.000000
#define MW_ADC_NONOVERLAP 0
#define MW_ADC_OFFSETCORRECTIONVALUE AdcRegs.ADCOFFTRIM.bit.OFFTRIM
#define MW_ADC_EXTERNALREFERENCESELECTOR 0
#define MW_ADC_EXTERNALREFERENCEVREFHI 3.3
#define MW_ADC_EXTERNALREFERENCEVREFLO 0
#define MW_ADC_INTPULSEGENERATION 0
#define MW_ADC_SOCPRIORITY 0
#define MW_ADC_XINT2GPIO 0
#define MW_COMP_PINASSIGNMENT_COMP1 1
#define MW_COMP_PINASSIGNMENT_COMP2 1
#define MW_COMP_PINASSIGNMENT_COMP3 1
#define MW_ECAN_A_MODULECLOCKFREQUENCY 45
#define MW_ECAN_A_BAUDRATEPRESCALER 5.000000
#define MW_ECAN_A_TSEG1 3
#define MW_ECAN_A_TSEG2 1
#define MW_ECAN_A_BAUDRATE 1000000
#define MW_ECAN_A_SBG 0
#define MW_ECAN_A_SJW 1
#define MW_ECAN_A_SAM 0
#define MW_ECAN_A_ENHANCEDCANMODE 1
#define MW_ECAN_A_SELFTESTMODE 0
#define MW_ECAP_PINASSIGNMENT_ECAP1 2
#define MW_ECAP_PINASSIGNMENT_ECAP2 1
#define MW_ECAP_PINASSIGNMENT_ECAP3 1
#define MW_EPWM_PINASSIGNMENT_TZ1 0
#define MW_EPWM_PINASSIGNMENT_TZ2 0
#define MW_EPWM_PINASSIGNMENT_TZ3 0
#define MW_EPWM_PINASSIGNMENT_SYNCI 0
#define MW_EPWM_PINASSIGNMENT_SYNCO 0
#define MW_EPWM_PINASSIGNMENT_PWM7A 2
#define MW_EPWM_PINASSIGNMENT_PWM7B 1
#define MW_EPWM_PINASSIGNMENT_PWM8A 2
#define MW_I2C_MODE 0
#define MW_I2C_ADDRDATAFORMAT 0
#define MW_I2C_OWNADDRESS 1
#define MW_I2C_BITCOUNT 0
#define MW_I2C_MODULECLOCKPRESCALER 9
#define MW_I2C_MODULECLOCKFREQUENCY 9000000.000000
#define MW_I2C_MASTERCLKLOWTIME 5
#define MW_I2C_MASTERCLKHIGHTIME 5
#define MW_I2C_MASTERCLOCKFREQUENCY 450000.000000
#define MW_I2C_MASTERCLOCKFREQUENCY_1 450000.000000
#define MW_I2C_MASTERCLOCKFREQUENCY_2 450000.000000
#define MW_I2C_ENABLELOOPBACK 0
#define MW_I2C_PINASSIGNMENT_SDAA 0
#define MW_I2C_PINASSIGNMENT_SCLA 0
#define MW_I2C_ENABLETXINT 0
#define MW_I2C_TXFIFOLEVEL 4
#define MW_I2C_ENABLERXINT 0
#define MW_I2C_RXFIFOLEVEL 4
#define MW_I2C_ENABLESYSINT 0
#define MW_I2C_AAS 0
#define MW_I2C_SCD 0
#define MW_I2C_ARDY 0
#define MW_I2C_NACK 0
#define MW_I2C_AL 0
#define MW_I2C_PINVALUE_SDA 32
#define MW_I2C_PINVALUE_SCL 33
#define MW_I2C_PINMUX_SDA 1
#define MW_I2C_PINMUX_SCL 1
#define MW_SCI_A_ENABLELOOPBACK 0
#define MW_SCI_A_SUSPENSIONMODE 2
#define MW_SCI_A_NUMBEROFSTOPBITS 0
#define MW_SCI_A_PARITYMODE 0
#define MW_SCI_A_CHARACTERLENGTHBITS 0
#define MW_SCI_A_USERBAUDRATE 5.625e6
#define MW_SCI_A_BAUDRATEPRESCALER 1.000000
#define MW_SCI_A_BAUDRATE 5625000.000000
#define MW_SCI_A_COMMUNICATIONMODE 0
#define MW_SCI_A_BLOCKINGMODE 0
#define MW_SCI_A_DATABYTEORDER 0
#define MW_SCI_A_DATASWAPWIDTH 0
#define MW_SCI_A_PINASSIGNMENT_TX 2
#define MW_SCI_A_PINASSIGNMENT_RX 2
#define MW_SCI_A_ENABLEINTERRUPTTX 0
#define MW_SCI_A_FIFOINTERRUPTLEVELTX 1
#define MW_SCI_A_ENABLEINTERRUPTRX 1
#define MW_SCI_A_FIFOINTERRUPTLEVELRX 4
#define MW_SCI_B_ENABLELOOPBACK 0
#define MW_SCI_B_SUSPENSIONMODE 2
#define MW_SCI_B_NUMBEROFSTOPBITS 0
#define MW_SCI_B_PARITYMODE 0
#define MW_SCI_B_CHARACTERLENGTHBITS 0
#define MW_SCI_B_USERBAUDRATE 115200
#define MW_SCI_B_BAUDRATEPRESCALER 97.000000
#define MW_SCI_B_BAUDRATE 114796.000000
#define MW_SCI_B_COMMUNICATIONMODE 0
#define MW_SCI_B_BLOCKINGMODE 0
#define MW_SCI_B_DATABYTEORDER 0
#define MW_SCI_B_DATASWAPWIDTH 0
#define MW_SCI_B_PINASSIGNMENT_TX 6
#define MW_SCI_B_PINASSIGNMENT_RX 2
#define MW_SCI_B_ENABLEINTERRUPTTX 0
#define MW_SCI_B_FIFOINTERRUPTLEVELTX 1
#define MW_SCI_B_ENABLEINTERRUPTRX 0
#define MW_SCI_B_FIFOINTERRUPTLEVELRX 1
#define MW_SPI_A_MODE 0
#define MW_SPI_A_USERBAUDRATE 921600
#define MW_SPI_A_BAUDRATEFACTOR 97.000000
#define MW_SPI_A_BAUDRATE 918367.000000
#define MW_SPI_A_DATABITS 15
#define MW_SPI_A_CLOCKPOLARITY 0
#define MW_SPI_A_CLOCKPHASE 0
#define MW_SPI_A_SUSPENSIONMODE 2
#define MW_SPI_A_ENABLELOOPBACK 0
#define MW_SPI_A_ENABLETHREEWIRE 0
#define MW_SPI_A_TXINTERRUPTENABLE 0
#define MW_SPI_A_FIFOINTERRUPTLEVEL_TX 0
#define MW_SPI_A_RXINTERRUPTENABLE 0
#define MW_SPI_A_FIFOINTERRUPTLEVEL_RX 4
#define MW_SPI_A_FIFOENABLE 1
#define MW_SPI_A_FIFOTRANSMITDELAY 0
#define MW_SPI_A_PINASSIGNMENT_SIMO 2
#define MW_SPI_A_PINASSIGNMENT_SOMI 2
#define MW_SPI_A_PINASSIGNMENT_CLK 1
#define MW_SPI_A_PINASSIGNMENT_STE 1
#define MW_SPI_A_PINVALUE_SIMO 16
#define MW_SPI_A_PINVALUE_SOMI 17
#define MW_SPI_A_PINVALUE_CLK 18
#define MW_SPI_A_PINVALUE_STE 19
#define MW_SPI_A_PINMUX_SIMO 1
#define MW_SPI_A_PINMUX_SOMI 1
#define MW_SPI_A_PINMUX_CLK 1
#define MW_SPI_A_PINMUX_STE 1
#define MW_SPI_A_FIFO_LEVEL 4.000000
#define MW_SPI_B_MODE 0
#define MW_SPI_B_USERBAUDRATE 921600
#define MW_SPI_B_BAUDRATEFACTOR 97.000000
#define MW_SPI_B_BAUDRATE 918367.000000
#define MW_SPI_B_DATABITS 15
#define MW_SPI_B_CLOCKPOLARITY 0
#define MW_SPI_B_CLOCKPHASE 0
#define MW_SPI_B_SUSPENSIONMODE 2
#define MW_SPI_B_ENABLELOOPBACK 0
#define MW_SPI_B_ENABLETHREEWIRE 0
#define MW_SPI_B_TXINTERRUPTENABLE 0
#define MW_SPI_B_FIFOINTERRUPTLEVEL_TX 0
#define MW_SPI_B_RXINTERRUPTENABLE 0
#define MW_SPI_B_FIFOINTERRUPTLEVEL_RX 4
#define MW_SPI_B_FIFOENABLE 1
#define MW_SPI_B_FIFOTRANSMITDELAY 0
#define MW_SPI_B_PINASSIGNMENT_SIMO 2
#define MW_SPI_B_PINASSIGNMENT_SOMI 2
#define MW_SPI_B_PINASSIGNMENT_CLK 1
#define MW_SPI_B_PINASSIGNMENT_STE 2
#define MW_SPI_B_PINVALUE_SIMO 24
#define MW_SPI_B_PINVALUE_SOMI 25
#define MW_SPI_B_PINVALUE_CLK 14
#define MW_SPI_B_PINVALUE_STE 27
#define MW_SPI_B_PINMUX_SIMO 3
#define MW_SPI_B_PINMUX_SOMI 3
#define MW_SPI_B_PINMUX_CLK 3
#define MW_SPI_B_PINMUX_STE 3
#define MW_SPI_B_FIFO_LEVEL 4.000000
#define MW_EQEP_PINASSIGNMENT_EQEP1A 1
#define MW_EQEP_PINASSIGNMENT_EQEP1B 1
#define MW_EQEP_PINASSIGNMENT_EQEP1S 0
#define MW_EQEP_PINASSIGNMENT_EQEP1I 1
#define MW_EQEP_PINASSIGNMENT_EQEP2A 2
#define MW_EQEP_PINASSIGNMENT_EQEP2B 2
#define MW_EQEP_PINASSIGNMENT_EQEP2S 0
#define MW_EQEP_PINASSIGNMENT_EQEP2I 3
#define MW_WATCHDOG_ENABLE_WATCHDOG 0
#define MW_WATCHDOG_WATCHDOGCLOCK 0
#define MW_WATCHDOG_TIME_PERIOD 0.013107
#define MW_WATCHDOG_WATCHDOGEVENT 0
#define MW_GPIO0_7_GPIOQUALSEL0 0
#define MW_GPIO0_7_GPIOQUALSEL1 0
#define MW_GPIO0_7_GPIOQUALSEL2 0
#define MW_GPIO0_7_GPIOQUALSEL3 0
#define MW_GPIO0_7_GPIOQUALSEL4 0
#define MW_GPIO0_7_GPIOQUALSEL5 0
#define MW_GPIO0_7_GPIOQUALSEL6 0
#define MW_GPIO0_7_GPIOQUALSEL7 0
#define MW_GPIO0_7_QUALPRD 0
#define MW_GPIO8_15_GPIOQUALSEL8 0
#define MW_GPIO8_15_GPIOQUALSEL9 0
#define MW_GPIO8_15_GPIOQUALSEL10 0
#define MW_GPIO8_15_GPIOQUALSEL11 0
#define MW_GPIO8_15_GPIOQUALSEL12 0
#define MW_GPIO8_15_GPIOQUALSEL13 0
#define MW_GPIO8_15_GPIOQUALSEL14 0
#define MW_GPIO8_15_GPIOQUALSEL15 0
#define MW_GPIO8_15_QUALPRD 0
#define MW_GPIO16_23_GPIOQUALSEL16 0
#define MW_GPIO16_23_GPIOQUALSEL17 0
#define MW_GPIO16_23_GPIOQUALSEL18 0
#define MW_GPIO16_23_GPIOQUALSEL19 0
#define MW_GPIO16_23_GPIOQUALSEL20 0
#define MW_GPIO16_23_GPIOQUALSEL21 0
#define MW_GPIO16_23_GPIOQUALSEL22 0
#define MW_GPIO16_23_GPIOQUALSEL23 0
#define MW_GPIO16_23_QUALPRD 0
#define MW_GPIO24_31_GPIOQUALSEL24 0
#define MW_GPIO24_31_GPIOQUALSEL25 0
#define MW_GPIO24_31_GPIOQUALSEL26 0
#define MW_GPIO24_31_GPIOQUALSEL27 0
#define MW_GPIO24_31_GPIOQUALSEL28 0
#define MW_GPIO24_31_GPIOQUALSEL29 0
#define MW_GPIO24_31_GPIOQUALSEL30 0
#define MW_GPIO24_31_GPIOQUALSEL31 0
#define MW_GPIO24_31_QUALPRD 0
#define MW_GPIO32_39_GPIOQUALSEL32 0
#define MW_GPIO32_39_GPIOQUALSEL33 0
#define MW_GPIO32_39_GPIOQUALSEL34 0
#define MW_GPIO32_39_GPIOQUALSEL39 0
#define MW_GPIO32_39_QUALPRD 0
#define MW_GPIO40_44_GPIOQUALSEL40 0
#define MW_GPIO40_44_GPIOQUALSEL41 0
#define MW_GPIO40_44_GPIOQUALSEL42 0
#define MW_GPIO40_44_GPIOQUALSEL43 0
#define MW_GPIO40_44_GPIOQUALSEL44 0
#define MW_GPIO40_44_QUALPRD 0
#define MW_GPIO50_55_GPIOQUALSEL50 0
#define MW_GPIO50_55_GPIOQUALSEL51 0
#define MW_GPIO50_55_GPIOQUALSEL52 0
#define MW_GPIO50_55_GPIOQUALSEL53 0
#define MW_GPIO50_55_GPIOQUALSEL54 0
#define MW_GPIO50_55_GPIOQUALSEL55 0
#define MW_GPIO50_55_QUALPRD 0
#define MW_GPIO56_58_GPIOQUALSEL56 0
#define MW_GPIO56_58_GPIOQUALSEL57 0
#define MW_GPIO56_58_GPIOQUALSEL58 0
#define MW_GPIO56_58_QUALPRD 0
#define MW_DMA_CH1_ENABLEDMACHANNEL 0
#define MW_DMA_CH1_DATASIZE 0
#define MW_DMA_CH1_INTERRUPTSRC 0
#define MW_DMA_CH1_EXTERNALPIN 0
#define MW_DMA_CH1_BURSTSIZE 0
#define MW_DMA_CH1_TRANSFERSIZE 1
#define MW_DMA_CH1_SRCBEGINADD 0xC000
#define MW_DMA_CH1_DSTBEGINADD 0xD000
#define MW_DMA_CH1_SRCBURSTSTEP 0
#define MW_DMA_CH1_DSTBURSTSTEP 0
#define MW_DMA_CH1_SRCTRANSSTEP 0
#define MW_DMA_CH1_DSTTRANSSTEP 0
#define MW_DMA_CH1_WRAPSRCSIZE 65536
#define MW_DMA_CH1_WRAPDSTSIZE 65536
#define MW_DMA_CH1_SRCWRAPSTEP 0
#define MW_DMA_CH1_DSTWRAPSTEP 0
#define MW_DMA_CH1_SETCH1TOHIGH 0
#define MW_DMA_CH1_ENABLEONESHOT 0
#define MW_DMA_CH1_ENABLECONTINUOUS 1
#define MW_DMA_CH1_SYNCENABLE 0
#define MW_DMA_CH1_ENABLEDSTSYNC 0
#define MW_DMA_CH1_GENINTERRUPT 0
#define MW_DMA_CH1_ENABLEOVERFLOW 0
#define MW_DMA_CH2_ENABLEDMACHANNEL 0
#define MW_DMA_CH2_DATASIZE 0
#define MW_DMA_CH2_INTERRUPTSRC 0
#define MW_DMA_CH2_EXTERNALPIN 0
#define MW_DMA_CH2_BURSTSIZE 0
#define MW_DMA_CH2_TRANSFERSIZE 1
#define MW_DMA_CH2_SRCBEGINADD 0xC000
#define MW_DMA_CH2_DSTBEGINADD 0xD000
#define MW_DMA_CH2_SRCBURSTSTEP 0
#define MW_DMA_CH2_DSTBURSTSTEP 0
#define MW_DMA_CH2_SRCTRANSSTEP 0
#define MW_DMA_CH2_DSTTRANSSTEP 0
#define MW_DMA_CH2_WRAPSRCSIZE 65536
#define MW_DMA_CH2_WRAPDSTSIZE 65536
#define MW_DMA_CH2_SRCWRAPSTEP 0
#define MW_DMA_CH2_DSTWRAPSTEP 0
#define MW_DMA_CH2_ENABLEONESHOT 0
#define MW_DMA_CH2_ENABLECONTINUOUS 1
#define MW_DMA_CH2_SYNCENABLE 0
#define MW_DMA_CH2_ENABLEDSTSYNC 0
#define MW_DMA_CH2_GENINTERRUPT 0
#define MW_DMA_CH2_ENABLEOVERFLOW 0
#define MW_DMA_CH3_ENABLEDMACHANNEL 0
#define MW_DMA_CH3_DATASIZE 0
#define MW_DMA_CH3_INTERRUPTSRC 0
#define MW_DMA_CH3_EXTERNALPIN 0
#define MW_DMA_CH3_BURSTSIZE 0
#define MW_DMA_CH3_TRANSFERSIZE 1
#define MW_DMA_CH3_SRCBEGINADD 0xC000
#define MW_DMA_CH3_DSTBEGINADD 0xD000
#define MW_DMA_CH3_SRCBURSTSTEP 0
#define MW_DMA_CH3_DSTBURSTSTEP 0
#define MW_DMA_CH3_SRCTRANSSTEP 0
#define MW_DMA_CH3_DSTTRANSSTEP 0
#define MW_DMA_CH3_WRAPSRCSIZE 65536
#define MW_DMA_CH3_WRAPDSTSIZE 65536
#define MW_DMA_CH3_SRCWRAPSTEP 0
#define MW_DMA_CH3_DSTWRAPSTEP 0
#define MW_DMA_CH3_ENABLEONESHOT 0
#define MW_DMA_CH3_ENABLECONTINUOUS 1
#define MW_DMA_CH3_SYNCENABLE 0
#define MW_DMA_CH3_ENABLEDSTSYNC 0
#define MW_DMA_CH3_GENINTERRUPT 0
#define MW_DMA_CH3_ENABLEOVERFLOW 0
#define MW_DMA_CH4_ENABLEDMACHANNEL 0
#define MW_DMA_CH4_DATASIZE 0
#define MW_DMA_CH4_INTERRUPTSRC 0
#define MW_DMA_CH4_EXTERNALPIN 0
#define MW_DMA_CH4_BURSTSIZE 0
#define MW_DMA_CH4_TRANSFERSIZE 1
#define MW_DMA_CH4_SRCBEGINADD 0xC000
#define MW_DMA_CH4_DSTBEGINADD 0xD000
#define MW_DMA_CH4_SRCBURSTSTEP 0
#define MW_DMA_CH4_DSTBURSTSTEP 0
#define MW_DMA_CH4_SRCTRANSSTEP 0
#define MW_DMA_CH4_DSTTRANSSTEP 0
#define MW_DMA_CH4_WRAPSRCSIZE 65536
#define MW_DMA_CH4_WRAPDSTSIZE 65536
#define MW_DMA_CH4_SRCWRAPSTEP 0
#define MW_DMA_CH4_DSTWRAPSTEP 0
#define MW_DMA_CH4_ENABLEONESHOT 0
#define MW_DMA_CH4_ENABLECONTINUOUS 1
#define MW_DMA_CH4_SYNCENABLE 0
#define MW_DMA_CH4_ENABLEDSTSYNC 0
#define MW_DMA_CH4_GENINTERRUPT 0
#define MW_DMA_CH4_ENABLEOVERFLOW 0
#define MW_DMA_CH5_ENABLEDMACHANNEL 0
#define MW_DMA_CH5_DATASIZE 0
#define MW_DMA_CH5_INTERRUPTSRC 0
#define MW_DMA_CH5_EXTERNALPIN 0
#define MW_DMA_CH5_BURSTSIZE 0
#define MW_DMA_CH5_TRANSFERSIZE 1
#define MW_DMA_CH5_SRCBEGINADD 0xC000
#define MW_DMA_CH5_DSTBEGINADD 0xD000
#define MW_DMA_CH5_SRCBURSTSTEP 0
#define MW_DMA_CH5_DSTBURSTSTEP 0
#define MW_DMA_CH5_SRCTRANSSTEP 0
#define MW_DMA_CH5_DSTTRANSSTEP 0
#define MW_DMA_CH5_WRAPSRCSIZE 65536
#define MW_DMA_CH5_WRAPDSTSIZE 65536
#define MW_DMA_CH5_SRCWRAPSTEP 0
#define MW_DMA_CH5_DSTWRAPSTEP 0
#define MW_DMA_CH5_ENABLEONESHOT 0
#define MW_DMA_CH5_ENABLECONTINUOUS 1
#define MW_DMA_CH5_SYNCENABLE 0
#define MW_DMA_CH5_ENABLEDSTSYNC 0
#define MW_DMA_CH5_GENINTERRUPT 0
#define MW_DMA_CH5_ENABLEOVERFLOW 0
#define MW_DMA_CH6_ENABLEDMACHANNEL 0
#define MW_DMA_CH6_DATASIZE 0
#define MW_DMA_CH6_INTERRUPTSRC 0
#define MW_DMA_CH6_EXTERNALPIN 0
#define MW_DMA_CH6_BURSTSIZE 0
#define MW_DMA_CH6_TRANSFERSIZE 1
#define MW_DMA_CH6_SRCBEGINADD 0xC000
#define MW_DMA_CH6_DSTBEGINADD 0xD000
#define MW_DMA_CH6_SRCBURSTSTEP 0
#define MW_DMA_CH6_DSTBURSTSTEP 0
#define MW_DMA_CH6_SRCTRANSSTEP 0
#define MW_DMA_CH6_DSTTRANSSTEP 0
#define MW_DMA_CH6_WRAPSRCSIZE 65536
#define MW_DMA_CH6_WRAPDSTSIZE 65536
#define MW_DMA_CH6_SRCWRAPSTEP 0
#define MW_DMA_CH6_DSTWRAPSTEP 0
#define MW_DMA_CH6_ENABLEONESHOT 0
#define MW_DMA_CH6_ENABLECONTINUOUS 1
#define MW_DMA_CH6_SYNCENABLE 0
#define MW_DMA_CH6_ENABLEDSTSYNC 0
#define MW_DMA_CH6_GENINTERRUPT 0
#define MW_DMA_CH6_ENABLEOVERFLOW 0
#define MW_XINT_GPIOXINT1SEL 0
#define MW_XINT_GPIOXINT2SEL 0
#define MW_XINT_GPIOXINT3SEL 0
#define MW_XINT_POLARITY1 0
#define MW_XINT_POLARITY2 0
#define MW_XINT_POLARITY3 0
#define MW_EXTMODECOMPORT -1
#define MW_EXECUTIONPROFILEBUFFERLEN 50.000000
#define MW_SDCARD_ENABLE 0
#define MW_SDCARD_SPIMODULE 0
#define MW_SDCARD_SPIBAUDRATE 1
#define MW_DATAVERSION 2016.02
#define MW_PIL_COMMUNICATIONINTERFACE 0
#define MW_PIL_SCIMODULE 0
#define MW_PIL_COMPORT COM3
#define MW_OVERRUNDETECTION_ENABLE_OVERRUN_DETECTION 0
#define MW_OVERRUNDETECTION_CHECK_GPIO_STATUS 1
#define MW_OVERRUNDETECTION_DIGITAL_OUTPUT_TO_SET_ON_OVERRUN 6
#define MW_OVERRUNDETECTION_GPIOMODE 0
#define MW_OVERRUNDETECTION_CUSTOM_LOGIC 0
#define MW_OVERRUNDETECTION_PIE_NUMBER 0
#define MW_OVERRUNDETECTION_CPU_NUMBER 0
#define MW_OVERRUNDETECTION_CUSTOM_FUNCTION c2000_OverrunFunction
#define MW_I2C_A_PINVALUE_SDA 32
#define MW_I2C_A_PINVALUE_SCL 33
#define MW_I2C_A_PINMUX_SDA 1
#define MW_I2C_A_PINMUX_SCL 1
#define MW_IOBLOCKSMODE deployed
#define MW_EXTMODEPROTOCOLINFO_XCPONSERIAL_HOSTINTERFACE Simulink
#define MW_EXTMODEPROTOCOLINFO_XCPONSERIAL_LOGGINGBUFFERAUTO 1
#define MW_EXTMODEPROTOCOLINFO_XCPONSERIAL_LOGGINGBUFFERSIZE 1000
#define MW_EXTMODEPROTOCOLINFO_XCPONSERIAL_LOGGINGBUFFERNUM 3
#define MW_EXTMODEPROTOCOLINFO_XCPONSERIAL_MAXCONTIGSAMPLES 8
#define MW_EXTMODEPROTOCOLINFO_XCPONCAN_HOSTINTERFACE Simulink
#define MW_EXTMODEPROTOCOLINFO_XCPONCAN_LOGGINGBUFFERAUTO 1
#define MW_EXTMODEPROTOCOLINFO_XCPONCAN_LOGGINGBUFFERSIZE 1000
#define MW_EXTMODEPROTOCOLINFO_XCPONCAN_LOGGINGBUFFERNUM 3
#define MW_EXTMODEPROTOCOLINFO_XCPONCAN_MAXCONTIGSAMPLES 10
#define MW_ESB_SIMDIAGSHOWINSDI 1
#define MW_ESB_SIMDIAGSAVETOFILE 1
#define MW_ESB_SIMDIAGOVERWRITEFILE 0
#define MW_ESB_HWDIAGSHOWINSDI 0
#define MW_ESB_HWDIAGSAVETOFILE 0
#define MW_ESB_HWDIAGOVERWRITEFILE 0
#define MW_ESB_HWDIAGINSTRUMENTATION Code
#define MW_ESB_HWDIAGRECORDING Continuous
#define MW_ESB_HWDIAGSTREAMINGMODETYPE Unlimited
#define MW_ESB_HWDIAGBUFFERSIZE 1024.000000
#define MW_ESB_HWDIAGNUMBUFFERS 1.000000
#define MW_ESB_HWDIAGVIEWLEVEL Task manager tasks
#define MW_ESB_SETRNG 0
#define MW_ESB_RNGSEED default
#define MW_ESB_CACHEDATA 0
#define MW_ESB_SCHEDULEEDITORSCHEDULERESET 0
#define MW_ESB_PROCESSINGUNIT c28xCPU1
#define MW_SIMULINKIO_COMMUNICATIONINTERFACE 0
#define MW_SIMULINKIO_SCIMODULE 0
#define MW_SIMULINKIO_MODELTRANSPORTDATAFCN codertarget.simulinkIO.tic2000.getModelTransportInfo
#define MW_SIMULINKIO_SERVERDEPLOYFCN codertarget.simulinkIO.tic2000.updateServer
#define MW_SIMULINKIO_COMPORT COM3
#define MW_TASKMAP_TASKS_HWI_SCIRXINTA_TASKPRIORITY 25
#define MW_TASKMAP_TASKS_HWI_SCIRXINTA_MAPPEDGROUP SCI - Serial Communications Interface
#define MW_TASKMAP_TASKS_HWI_SCIRXINTA_MAPPEDINTERRUPT SCIRXINTA
#define MW_TASKMAP_TASKS_HWI_SCIRXINTA_MAPPEDSOURCE Default event
#define MW_TASKMAP_TASKS_HWI_SCIRXINTA_EVENTORDER 1.000000
#define MW_TASKMAP_TASKS_HWI_SCIRXINTA_DISABLEPREMPTION off
#define MW_TASKMAP_TASKS_HWI_SCIRXINTA_CLEARINTERRUPTFLAGSATENDOFEVENT on
#define MW_TASKMAP_TASKS_HWI_ADCINT1_TASKPRIORITY 30
#define MW_TASKMAP_TASKS_HWI_ADCINT1_MAPPEDGROUP ADC - Analog to Digital Converter
#define MW_TASKMAP_TASKS_HWI_ADCINT1_MAPPEDINTERRUPT ADCINT1
#define MW_TASKMAP_TASKS_HWI_ADCINT1_MAPPEDSOURCE Default event
#define MW_TASKMAP_TASKS_HWI_ADCINT1_EVENTORDER 1.000000
#define MW_TASKMAP_TASKS_HWI_ADCINT1_DISABLEPREMPTION on
#define MW_TASKMAP_TASKS_HWI_ADCINT1_CLEARINTERRUPTFLAGSATENDOFEVENT on

#endif /* __MW_TARGET_HARDWARE_RESOURCES_H__ */

#endif

#endif

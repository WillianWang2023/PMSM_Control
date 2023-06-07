//###########################################################################
//
// FILE:   main.c
//
// TITLE:  
//
//! \addtogroup f2806x_Config_list
//! <h1> (c)</h1>
//! 
//!
//! 
//!
//###########################################################################

//
// Included Files
//
#include "DSP28x_Project.h"     // Device Headerfile and Configs Include File
//
// Function Prototypes
//

void InitEPwm1Config(void);
void InitEPwm2Config(void);
void InitEPwm3Config(void);
__interrupt void cpu_timer0_isr(void);
__interrupt void cpu_timer1_isr(void);
__interrupt void cpu_timer2_isr(void);
__interrupt void adc_isr(void);

//
// Globals
//
Uint16 LoopCount;
Uint16 ConversionCount;
Uint16 TempSensorVoltage[10];

//
// Globals
//
Uint32  EPwm1TimerIntCount;
Uint32  EPwm2TimerIntCount;
Uint32  EPwm3TimerIntCount;
Uint16  EPwm1_DB_Direction;
Uint16  EPwm2_DB_Direction;
Uint16  EPwm3_DB_Direction;

//
// Defines that Maximum Dead Band values
//
#define EPWM1_MAX_DB   0x03FF
#define EPWM2_MAX_DB   0x03FF
#define EPWM3_MAX_DB   0x03FF

#define EPWM1_MIN_DB   0
#define EPWM2_MIN_DB   0
#define EPWM3_MIN_DB   0

//
// Defines to keep track of which way the Dead Band is moving
//
#define DB_UP   1
#define DB_DOWN 0

/**
 * main.c
 */
void main(void)
{
	//
    // Step 1. Initialize System Control:
    // PLL, WatchDog, enable Peripheral Clocks
    // This Config function is found in the F2806x_SysCtrl.c file.
    //
    InitSysCtrl();																	//浣跨敤鍐呴儴鏃堕挓锛屾椂閽熼鐜囦负90MHz
	//
    // Step 2. Initalize GPIO:
    // This Config function is found in the F2806x_Gpio.c file and
    // illustrates how to set the GPIO to it's default state.
    //
    // InitGpio();  // Skipped for this Config
    InitEPwm();
    //
    // Step 3. Clear all interrupts and initialize PIE vector table:
    // Disable CPU interrupts
    //
    DINT;
	//
    // Initialize the PIE control registers to their default state.
    // The default state is all PIE interrupts disabled and flags are cleared.
    // This function is found in the F2806x_PieCtrl.c file.
    //
    InitPieCtrl();

    //
    // Disable CPU interrupts and clear all CPU interrupt flags:
    //
    IER = 0x0000;
    IFR = 0x0000;

    //
    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    // This will populate the entire table, even if the interrupt
    // is not used in this Config.  This is useful for debug purposes.
    // The shell ISR routines are found in F2806x_DefaultIsr.c.
    // This function is found in F2806x_PieVect.c.
    //
    InitPieVectTable();
	//
    // Interrupts that are used in this Config are re-mapped to
    // ISR functions found within this file.
    //
    EALLOW;  // This is needed to write to EALLOW protected registers
    PieVectTable.TINT0 = &cpu_timer0_isr;										//涓柇鍝嶅簲鍑芥暟鏄犲皠
    PieVectTable.TINT1 = &cpu_timer1_isr;
    PieVectTable.TINT2 = &cpu_timer2_isr;
    PieVectTable.ADCINT1 = &adc_isr;
    EDIS;    // This is needed to disable write to EALLOW protected registers
	//
    // Step 4. Initialize the Device Peripheral. This function can be
    //         found in F2806x_CpuTimers.c
    //
    InitCpuTimers();   // For this Config, only initialize the Cpu Timers

    // This function is found in F2806x_Adc.c
    //
    InitAdc();  // For this Config, init the ADC
    AdcOffsetSelfCal();

    InitEPwm1Config();
    InitEPwm2Config();
    InitEPwm3Config();

    //
    // Configure CPU-Timer 0, 1, and 2 to interrupt every second:
    // 80MHz CPU Freq, 1 second Period (in uSeconds)
    //
    ConfigCpuTimer(&CpuTimer0, 80, 1000);                                   //  1000 = 1ms
    ConfigCpuTimer(&CpuTimer1, 80, 10000);
    ConfigCpuTimer(&CpuTimer2, 80, 100000);
	//
    // To ensure precise timing, use write-only instructions to write to the 
    // entire register. Therefore, if any of the configuration bits are changed
    // in ConfigCpuTimer and InitCpuTimers (in F2806x_CpuTimers.h), the below 
    // settings must also be updated.
    //
    
    //
    // Use write-only instruction to set TSS bit = 0
    //
    CpuTimer0Regs.TCR.all = 0x4000;										//浣胯兘ISR 锛屼负0鏃惰Е鍙戜腑鏂�
    
    //
    // Use write-only instruction to set TSS bit = 0
    //
    CpuTimer1Regs.TCR.all = 0x4000;

    //
    // Use write-only instruction to set TSS bit = 0
    //
    CpuTimer2Regs.TCR.all = 0x4000;
    
    //
    // Step 5. User specific code, enable interrupts
    //
    // ADC Configuration for Temp Sensor
    //
    //
    // Step 6. Configure ADC to sample the temperature sensor on ADCIN5:
    // The output of Piccolo temperature sensor can be internally connected to 
    // the ADC through ADCINA5 via the TEMPCONV bit in the ADCCTL1 register. 
    // When this bit is set, any voltage applied to the external ADCIN5 pin 
    // is ignored.
    //
    EALLOW;
    
    //
    // Connect internal temp sensor to channel ADCINA5.
    //
    // AdcRegs.ADCCTL1.bit.TEMPCONV 	= 1;
    
    EDIS;
    EALLOW;
    AdcRegs.ADCCTL2.bit.ADCNONOVERLAP = 1;	// Enable non-overlap mode
    //
    // ADCINT1 trips after AdcResults latch
    //
    AdcRegs.ADCCTL1.bit.INTPULSEPOS	= 1;    
    AdcRegs.INTSEL1N2.bit.INT1E     = 1;	// Enabled ADCINT1
    AdcRegs.INTSEL1N2.bit.INT1CONT  = 0;	// Disable ADCINT1 Continuous mode
    
    //
    // setup EOC0 to trigger ADCINT1 to fire
    //
    AdcRegs.INTSEL1N2.bit.INT1SEL	= 0;
    
    //
    // set SOC0 channel select to ADCINA5 
    // (which is internally connected to the temperature sensor)
    //
    AdcRegs.ADCSOC0CTL.bit.CHSEL 	= 5;
    
    AdcRegs.ADCSOC0CTL.bit.TRIGSEL 	= 5;	// set SOC0 start trigger on EPWM1A
    
    //
    // set SOC0 S/H Window to 26 ADC Clock Cycles, (25 ACQPS plus 1)
    //
    AdcRegs.ADCSOC0CTL.bit.ACQPS 	= 25;
    EDIS;

	//
    // Enable CPU int1 which is connected to CPU-Timer 0, CPU int13
    // which is connected to CPU-Timer 1, and CPU int 14, which is connected
    // to CPU-Timer 2
    //
    IER |= M_INT1;
    IER |= M_INT13;
    IER |= M_INT14;

    //
    // Enable TINT0 in the PIE: Group 1 interrupt 7
    //
    PieCtrlRegs.PIEIER1.bit.INTx7 = 1;
    //
    // Enable ADCINT1 in PIE
    //
    PieCtrlRegs.PIEIER1.bit.INTx1 = 1; // Enable INT 1.1 in the PIE

    //
    // Enable global Interrupts and higher priority real-time debug events:
    //
    EINT;   // Enable Global interrupt INTM
    ERTM;   // Enable Global realtime interrupt DBGM

    LoopCount = 0;
    ConversionCount = 0;

//    //
//    // Assumes ePWM1 clock is already enabled in InitSysCtrl();
//    //
//    EPwm1Regs.ETSEL.bit.SOCAEN	= 1;		// Enable SOC on A group
//
//    //
//    // Select SOC from from CPMA on upcount
//    //
//    EPwm1Regs.ETSEL.bit.SOCASEL	= 4;
//
//    EPwm1Regs.ETPS.bit.SOCAPRD 	= 1;		// Generate pulse on 1st event
//    EPwm1Regs.CMPA.half.CMPA 	= 0x0080;	// Set compare A value
//    EPwm1Regs.TBPRD				= 0xFFFF;	// Set period for ePWM1
//    EPwm1Regs.TBCTL.bit.CTRMODE	= 0;		// count up and start

    //
    // Wait for ADC interrupt
    //
    //
    // Step 7. IDLE loop. Just sit and loop forever (optional)
    //
    for(;;);
    {
        
    }	
}
//
// cpu_timer0_isr - 
//
__interrupt void
cpu_timer0_isr(void)
{
    CpuTimer0.InterruptCount++;

    //
    // Acknowledge this interrupt to receive more interrupts from group 1
    //
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}

//
// cpu_timer1_isr - 
//
__interrupt void
cpu_timer1_isr(void)
{
    CpuTimer1.InterruptCount++;
   
    //
    // The CPU acknowledges the interrupt
    //
    EDIS;
}

//
// cpu_timer2_isr - 
//
__interrupt void
cpu_timer2_isr(void)
{
    EALLOW;
    CpuTimer2.InterruptCount++;
    
    //
    // The CPU acknowledges the interrupt.
    //
    EDIS;
}
//
// adc_isr - 
//
__interrupt void
adc_isr(void)
{
    TempSensorVoltage[ConversionCount] = AdcResult.ADCRESULT0;

    //
    // If 10 conversions have been logged, start over
    //
    if(ConversionCount == 9)
    {
        ConversionCount = 0;
    }
    else
    {
        ConversionCount++;
    }

    //
    // Clear ADCINT1 flag reinitialize for next SOC
    //
    AdcRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;
    
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;   // Acknowledge interrupt to PIE

    return;
}

//
// InitEPwm1Config -
//
void
InitEPwm1Config()
{
    EPwm1Regs.TBPRD = 6000;                        // Set timer period
    EPwm1Regs.TBPHS.half.TBPHS = 0x0000;           // Phase is 0
    EPwm1Regs.TBCTR = 0x0000;                      // Clear counter

    //
    // Setup TBCLK
    //
    EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up
    EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE;        // Disable phase loading
    EPwm1Regs.TBCTL.bit.HSPCLKDIV = TB_DIV4;       // Clock ratio to SYSCLKOUT
    EPwm1Regs.TBCTL.bit.CLKDIV = TB_DIV4;

    EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;    // Load registers every ZERO
    EPwm1Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
    EPwm1Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    //
    // Setup compare
    //
    EPwm1Regs.CMPA.half.CMPA = 3000;

    //
    // Set actions
    //
    EPwm1Regs.AQCTLA.bit.CAU = AQ_SET;           // Set PWM1A on CAU
    EPwm1Regs.AQCTLA.bit.CAD = AQ_CLEAR;         // Clear PWM1A on CAD

    EPwm1Regs.AQCTLB.bit.CAU = AQ_CLEAR;         // Clear PWM1B on CAU
    EPwm1Regs.AQCTLB.bit.CAD = AQ_SET;           // Set PWM1B on CAD

    //
    // Active Low PWMs - Setup Deadband
    //
    EPwm1Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
    EPwm1Regs.DBCTL.bit.POLSEL = DB_ACTV_LO;
    EPwm1Regs.DBCTL.bit.IN_MODE = DBA_ALL;
    EPwm1Regs.DBRED = EPWM1_MIN_DB;
    EPwm1Regs.DBFED = EPWM1_MIN_DB;
    EPwm1_DB_Direction = DB_UP;

    //
    // Interrupt where we will change the Deadband
    //
     //
    // Select SOC from from CPMA on upcount
    //
    //
    // Assumes ePWM1 clock is already enabled in InitSysCtrl();
    //
    EPwm1Regs.ETSEL.bit.SOCAEN	= 1;		// Enable SOC on A group
    EPwm1Regs.ETSEL.bit.SOCASEL	= 4;    
    EPwm1Regs.ETPS.bit.SOCAPRD 	= 1;		// Generate pulse on 1st event
    // EPwm1Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;     // Select INT on Zero event
    // EPwm1Regs.ETSEL.bit.INTEN = 1;                // Enable INT
    // EPwm1Regs.ETPS.bit.INTPRD = ET_3RD;           // Generate INT on 3rd event
}

//
// InitEPwm2Config -
//
void
InitEPwm2Config()
{
    EPwm2Regs.TBPRD = 6000;                        // Set timer period
    EPwm2Regs.TBPHS.half.TBPHS = 0x0000;           // Phase is 0
    EPwm2Regs.TBCTR = 0x0000;                      // Clear counter

    //
    // Setup TBCLK
    //
    EPwm2Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up
    EPwm2Regs.TBCTL.bit.PHSEN = TB_DISABLE;        // Disable phase loading
    EPwm2Regs.TBCTL.bit.HSPCLKDIV = TB_DIV4;       // Clock ratio to SYSCLKOUT

    //
    // Slow just to observe on the scope
    //
    EPwm2Regs.TBCTL.bit.CLKDIV = TB_DIV4;

    //
    // Setup compare
    //
    EPwm2Regs.CMPA.half.CMPA = 3000;

    //
    // Set actions
    //
    EPwm2Regs.AQCTLA.bit.CAU = AQ_SET;             // Set PWM2A on CAU
    EPwm2Regs.AQCTLA.bit.CAD = AQ_CLEAR;           // Clear PWM2A on CAD

    EPwm2Regs.AQCTLB.bit.CAU = AQ_CLEAR;           // Clear PWM2B on CAU
    EPwm2Regs.AQCTLB.bit.CAD = AQ_SET;             // Set PWM2B on CAD

    //
    // Active Low complementary PWMs - setup the deadband
    //
    EPwm2Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
    EPwm2Regs.DBCTL.bit.POLSEL = DB_ACTV_LOC;
    EPwm2Regs.DBCTL.bit.IN_MODE = DBA_ALL;
    EPwm2Regs.DBRED = EPWM2_MIN_DB;
    EPwm2Regs.DBFED = EPWM2_MIN_DB;
    EPwm2_DB_Direction = DB_UP;

    //
    // Interrupt where we will modify the deadband
    //
    // EPwm2Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;      // Select INT on Zero event
    // EPwm2Regs.ETSEL.bit.INTEN = 1;                 // Enable INT
    // EPwm2Regs.ETPS.bit.INTPRD = ET_3RD;            // Generate INT on 3rd event
}

//
// InitEPwm3Config -
//
void
InitEPwm3Config()
{
    EPwm3Regs.TBPRD = 6000;                         // Set timer period
    EPwm3Regs.TBPHS.half.TBPHS = 0x0000;            // Phase is 0
    EPwm3Regs.TBCTR = 0x0000;                       // Clear counter

    //
    // Setup TBCLK
    //
    EPwm3Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up
    EPwm3Regs.TBCTL.bit.PHSEN = TB_DISABLE;        // Disable phase loading
    EPwm3Regs.TBCTL.bit.HSPCLKDIV = TB_DIV4;       // Clock ratio to SYSCLKOUT

    //
    // Slow so we can observe on the scope
    //
    EPwm3Regs.TBCTL.bit.CLKDIV = TB_DIV4;

    //
    // Setup compare
    //
    EPwm3Regs.CMPA.half.CMPA = 3000;

    //
    // Set actions
    //
    EPwm3Regs.AQCTLA.bit.CAU = AQ_SET;              // Set PWM3A on CAU
    EPwm3Regs.AQCTLA.bit.CAD = AQ_CLEAR;            // Clear PWM3A on CAD

    EPwm3Regs.AQCTLB.bit.CAU = AQ_CLEAR;            // Clear PWM3B on CAU
    EPwm3Regs.AQCTLB.bit.CAD = AQ_SET;              // Set PWM3B on CAD

    //
    // Active high complementary PWMs - Setup the deadband
    //
    EPwm3Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
    EPwm3Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
    EPwm3Regs.DBCTL.bit.IN_MODE = DBA_ALL;
    EPwm3Regs.DBRED = EPWM3_MIN_DB;
    EPwm3Regs.DBFED = EPWM3_MIN_DB;
    EPwm3_DB_Direction = DB_UP;

    //
    // Interrupt where we will change the deadband
    //
    // EPwm3Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;     // Select INT on Zero event
    // EPwm3Regs.ETSEL.bit.INTEN = 1;                // Enable INT
    // EPwm3Regs.ETPS.bit.INTPRD = ET_3RD;           // Generate INT on 3rd event
}

//
// End of File
//

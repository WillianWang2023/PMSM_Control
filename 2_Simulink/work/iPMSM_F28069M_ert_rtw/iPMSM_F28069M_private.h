/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: iPMSM_F28069M_private.h
 *
 * Code generated for Simulink model 'iPMSM_F28069M'.
 *
 * Model version                  : 6.14
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Wed Jun  7 10:02:56 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_iPMSM_F28069M_private_h_
#define RTW_HEADER_iPMSM_F28069M_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "iPMSM_F28069M.h"
#include "iPMSM_F28069M_types.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFFFU) ) || ( SCHAR_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFU) ) || ( INT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFUL) ) || ( LONG_MAX != (0x7FFFFFFFL) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */
void InitAdc (void);
void config_ADC_SOC0_SOC1 (void);
void config_ADC_SOC2_SOC3 (void);
extern uint16_T MW_adcInitFlag;
extern void iPMSM_F28069M_Accumulate(boolean_T rtu_Enable, real32_T rtu_Theta,
  real32_T rtu_Theta_e_prev, rtB_Accumulate_iPMSM_F28069M *localB,
  rtDW_Accumulate_iPMSM_F28069M *localDW);
extern void iPMSM_F28_IfActionSubsystem(real32_T rtu_In1, real32_T *rty_Out1,
  rtB_IfActionSubsystem_iPMSM_F28 *localB);
extern void iPMSM_F2_IfActionSubsystem1(real32_T rtu_In1, real32_T *rty_Out1,
  rtB_IfActionSubsystem1_iPMSM_F2 *localB);
extern void iPMSM_F28069M_Dir_Sense(boolean_T rtu_A, boolean_T rtu_B,
  rtB_Dir_Sense_iPMSM_F28069M *localB, rtZCE_Dir_Sense_iPMSM_F28069M *localZCE);
extern void iPMSM_F28069M_Subsystem2(real32_T rtu_SigmaAlpha, real32_T
  rtu_SigmaBeta, real32_T *rty_Out1, real32_T *rty_Out2);
extern void iPMS_SPIMasterTransfer_Init(rtDW_SPIMasterTransfer_iPMSM_F2 *localDW);
extern void iPMSM_F28_SPIMasterTransfer(uint16_T rtu_0,
  rtB_SPIMasterTransfer_iPMSM_F28 *localB, rtDW_SPIMasterTransfer_iPMSM_F2
  *localDW);
extern void iPMSM_F28_SpeedControl_Init(rtB_SpeedControl_iPMSM_F28069M *localB,
  rtDW_SpeedControl_iPMSM_F28069M *localDW);
extern void iPMSM_F28069M_SpeedControl(real32_T rtu_Speed_Ref_PU, real32_T
  rtu_Speed_Meas_PU, const boolean_T *rtd_EnClosedLoop, const boolean_T
  *rtd_Enable, const real32_T *rtd_Speed_ref, rtB_SpeedControl_iPMSM_F28069M
  *localB, rtDW_SpeedControl_iPMSM_F28069M *localDW);
extern void SVC_Calc_Init(void);
extern void SVC_Calc(void);
extern void iPMSM_F_CurrentControl_Init(void);
extern void iPMSM__CurrentControl_Reset(void);

#pragma CODE_SECTION (iPMSM_F28069_CurrentControl, "ramfuncs")

extern void iPMSM_F28069_CurrentControl(void);
extern void iPMS_SPIMasterTransfer_Term(rtDW_SPIMasterTransfer_iPMSM_F2 *localDW);

#endif                                 /* RTW_HEADER_iPMSM_F28069M_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

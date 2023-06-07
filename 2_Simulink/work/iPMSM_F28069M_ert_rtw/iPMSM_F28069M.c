/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: iPMSM_F28069M.c
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

#include "iPMSM_F28069M.h"
#include "rtwtypes.h"
#include "iPMSM_F28069M_private.h"
#include <math.h>
#include "iPMSM_F28069M_types.h"
#include "rt_nonfinite.h"
#include "zero_crossing_types.h"
#include <string.h>

/* Exported block signals */
real32_T Iab_fb_PU[2];                 /* '<S165>/Data Type Conversion1' */
uint16_T Iab_ADC_u16[2];               /* '<S164>/IA//IB Measurement' */

/* Block signals (default storage) */
BlockIO_iPMSM_F28069M iPMSM_F28069M_B;

/* Block states (default storage) */
D_Work_iPMSM_F28069M iPMSM_F28069M_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_iPMSM_F28069M iPMSM_F28069M_PrevZCSigState;

/* Real-time model */
static RT_MODEL_iPMSM_F28069M iPMSM_F28069M_M_;
RT_MODEL_iPMSM_F28069M *const iPMSM_F28069M_M = &iPMSM_F28069M_M_;
static void rate_monotonic_scheduler(void);

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcInitFlag = 0;

#endif

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void iPMSM_F28069M_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(iPMSM_F28069M_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (iPMSM_F28069M_M->Timing.TaskCounters.TID[1])++;
  if ((iPMSM_F28069M_M->Timing.TaskCounters.TID[1]) > 499) {/* Sample time: [0.5s, 0.0s] */
    iPMSM_F28069M_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Output and update for enable system:
 *    '<S142>/Accumulate'
 *    '<S196>/Accumulate'
 */
void iPMSM_F28069M_Accumulate(boolean_T rtu_Enable, real32_T rtu_Theta, real32_T
  rtu_Theta_e_prev, rtB_Accumulate_iPMSM_F28069M *localB,
  rtDW_Accumulate_iPMSM_F28069M *localDW)
{
  /* Outputs for Enabled SubSystem: '<S142>/Accumulate' incorporates:
   *  EnablePort: '<S143>/Enable'
   */
  if (rtu_Enable) {
    /* Delay: '<S143>/Delay' */
    localB->Delay = localDW->Delay_DSTATE;

    /* Outputs for Enabled SubSystem: '<S143>/Subsystem' incorporates:
     *  EnablePort: '<S144>/Enable'
     */
    if (localB->Delay) {
      /* SignalConversion generated from: '<S144>/Input' */
      localB->Input = rtu_Theta;
    }

    /* End of Outputs for SubSystem: '<S143>/Subsystem' */

    /* Sum: '<S143>/Add' */
    localB->Add = localB->Input + rtu_Theta_e_prev;

    /* DataTypeConversion: '<S143>/Data Type Conversion' */
    localB->DataTypeConversion = (int16_T)(real32_T)floor(localB->Add);

    /* DataTypeConversion: '<S143>/Data Type Conversion1' */
    localB->DataTypeConversion1 = localB->DataTypeConversion;

    /* Sum: '<S143>/Add1' */
    localB->Add1 = localB->Add - localB->DataTypeConversion1;

    /* Update for Delay: '<S143>/Delay' incorporates:
     *  Constant: '<S143>/Constant'
     */
    localDW->Delay_DSTATE = true;
  }

  /* End of Outputs for SubSystem: '<S142>/Accumulate' */
}

/*
 * Output and update for action system:
 *    '<S147>/If Action Subsystem'
 *    '<S253>/If Action Subsystem'
 */
void iPMSM_F28_IfActionSubsystem(real32_T rtu_In1, real32_T *rty_Out1,
  rtB_IfActionSubsystem_iPMSM_F28 *localB)
{
  /* DataTypeConversion: '<S149>/Convert_uint16' */
  localB->Convert_uint16 = (int16_T)(real32_T)floor(rtu_In1);

  /* DataTypeConversion: '<S149>/Convert_back' */
  localB->Convert_back = localB->Convert_uint16;

  /* Sum: '<S149>/Sum' */
  *rty_Out1 = rtu_In1 - localB->Convert_back;
}

/*
 * Output and update for action system:
 *    '<S147>/If Action Subsystem1'
 *    '<S253>/If Action Subsystem1'
 */
void iPMSM_F2_IfActionSubsystem1(real32_T rtu_In1, real32_T *rty_Out1,
  rtB_IfActionSubsystem1_iPMSM_F2 *localB)
{
  /* DataTypeConversion: '<S150>/Convert_uint16' */
  localB->Convert_uint16 = (int16_T)rtu_In1;

  /* DataTypeConversion: '<S150>/Convert_back' */
  localB->Convert_back = localB->Convert_uint16;

  /* Sum: '<S150>/Sum' */
  *rty_Out1 = rtu_In1 - localB->Convert_back;
}

/*
 * Output and update for trigger system:
 *    '<S338>/Dir_Sense'
 *    '<S188>/Dir_Sense'
 */
void iPMSM_F28069M_Dir_Sense(boolean_T rtu_A, boolean_T rtu_B,
  rtB_Dir_Sense_iPMSM_F28069M *localB, rtZCE_Dir_Sense_iPMSM_F28069M *localZCE)
{
  boolean_T zcEvent;

  /* Outputs for Triggered SubSystem: '<S338>/Dir_Sense' incorporates:
   *  TriggerPort: '<S346>/Trigger'
   */
  zcEvent = (rtu_A && (localZCE->Dir_Sense_Trig_ZCE != POS_ZCSIG));
  if (zcEvent) {
    /* Logic: '<S346>/Logical Operator' */
    localB->LogicalOperator = (rtu_A && rtu_B);

    /* Switch: '<S346>/Switch' */
    if (localB->LogicalOperator) {
      /* Switch: '<S346>/Switch' incorporates:
       *  Constant: '<S346>/Constant'
       */
      localB->Switch = -1;
    } else {
      /* Switch: '<S346>/Switch' incorporates:
       *  Constant: '<S346>/Constant1'
       */
      localB->Switch = 1;
    }

    /* End of Switch: '<S346>/Switch' */
  }

  localZCE->Dir_Sense_Trig_ZCE = rtu_A;

  /* End of Outputs for SubSystem: '<S338>/Dir_Sense' */
}

/*
 * Output and update for action system:
 *    '<S338>/Subsystem2'
 *    '<S188>/Subsystem2'
 */
void iPMSM_F28069M_Subsystem2(real32_T rtu_SigmaAlpha, real32_T rtu_SigmaBeta,
  real32_T *rty_Out1, real32_T *rty_Out2)
{
  /* UnaryMinus: '<S347>/Unary Minus' */
  *rty_Out1 = -rtu_SigmaAlpha;

  /* SignalConversion generated from: '<S347>/SigmaBeta' */
  *rty_Out2 = rtu_SigmaBeta;
}

/* System initialize for atomic system: '<S11>/Calculate position and speed' */
void SVC_Calc_Init(void)
{
  /* SystemInitialize for IfAction SubSystem: '<S166>/Extended EMF Observer' */
  /* InitializeConditions for Delay: '<S170>/Delay1' */
  iPMSM_F28069M_DWork.Delay1_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S189>/Delay' */
  iPMSM_F28069M_DWork.Delay_DSTATE_i = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S233>/Integrator' */
  iPMSM_F28069M_DWork.Integrator_PrevResetState_e = 0;

  /* SystemInitialize for IfAction SubSystem: '<S198>/DifferentiationMethod' */
  /* InitializeConditions for Delay: '<S261>/Delay2' */
  iPMSM_F28069M_DWork.Delay2_DSTATE_o = 0.0F;

  /* InitializeConditions for Delay: '<S261>/Delay3' */
  iPMSM_F28069M_DWork.Delay3_DSTATE_f = 0.0F;

  /* InitializeConditions for Delay: '<S262>/Delay2' */
  iPMSM_F28069M_DWork.Delay2_DSTATE_p = 0.0F;

  /* InitializeConditions for Delay: '<S262>/Delay3' */
  iPMSM_F28069M_DWork.Delay3_DSTATE_n = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S198>/DifferentiationMethod' */

  /* SystemInitialize for IfAction SubSystem: '<S198>/IntegralMethod' */
  /* InitializeConditions for Delay: '<S286>/Delay1' */
  iPMSM_F28069M_DWork.Delay1_DSTATE_j = 0.0F;

  /* InitializeConditions for Delay: '<S286>/Delay' */
  iPMSM_F28069M_DWork.Delay_DSTATE_a = 0.0F;

  /* InitializeConditions for Delay: '<S287>/Delay1' */
  iPMSM_F28069M_DWork.Delay1_DSTATE_a = 0.0F;

  /* InitializeConditions for Delay: '<S287>/Delay' */
  iPMSM_F28069M_DWork.Delay_DSTATE_o = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S198>/IntegralMethod' */

  /* SystemInitialize for IfAction SubSystem: '<S198>/OptimizedDifferentiationMethod' */
  /* InitializeConditions for Delay: '<S294>/Delay2' */
  iPMSM_F28069M_DWork.Delay2_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S294>/Delay3' */
  iPMSM_F28069M_DWork.Delay3_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S295>/Delay2' */
  iPMSM_F28069M_DWork.Delay2_DSTATE_i = 0.0F;

  /* InitializeConditions for Delay: '<S295>/Delay3' */
  iPMSM_F28069M_DWork.Delay3_DSTATE_a = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S198>/OptimizedDifferentiationMethod' */

  /* SystemInitialize for Merge: '<S198>/Merge' */
  iPMSM_F28069M_B.Merge_g = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S166>/Extended EMF Observer' */

  /* SystemInitialize for IfAction SubSystem: '<S166>/Flux Observer' */
  /* InitializeConditions for Delay: '<S327>/Delay1' */
  iPMSM_F28069M_DWork.Delay1_DSTATE_n = 0.0F;

  /* InitializeConditions for Delay: '<S327>/Delay' */
  iPMSM_F28069M_DWork.Delay_DSTATE_om = 0.0F;

  /* InitializeConditions for Delay: '<S320>/Delay1' */
  iPMSM_F28069M_DWork.Delay1_DSTATE_n2 = 0.0F;

  /* InitializeConditions for Delay: '<S320>/Delay' */
  iPMSM_F28069M_DWork.Delay_DSTATE_hc = 0.0F;

  /* InitializeConditions for Delay: '<S307>/Delay' */
  iPMSM_F28069M_DWork.CircBufIdx = 0U;

  /* End of SystemInitialize for SubSystem: '<S166>/Flux Observer' */

  /* SystemInitialize for IfAction SubSystem: '<S166>/Sliding Mode Observer' */
  /* InitializeConditions for Delay: '<S339>/Delay' */
  iPMSM_F28069M_DWork.Delay_DSTATE_n = 0.0F;

  /* InitializeConditions for Delay: '<S349>/Delay1' */
  iPMSM_F28069M_DWork.Delay1_DSTATE_l = 0.0F;

  /* InitializeConditions for Delay: '<S340>/Delay' */
  iPMSM_F28069M_DWork.Delay_DSTATE_e = 0.0F;

  /* InitializeConditions for Delay: '<S350>/Delay1' */
  iPMSM_F28069M_DWork.Delay1_DSTATE_jt = 0.0F;

  /* InitializeConditions for Delay: '<S337>/Delay' */
  iPMSM_F28069M_DWork.Delay_DSTATE_nm = 0.0F;

  /* InitializeConditions for Delay: '<S344>/Delay' */
  iPMSM_F28069M_DWork.CircBufIdx_n = 0U;

  /* End of SystemInitialize for SubSystem: '<S166>/Sliding Mode Observer' */

  /* SystemInitialize for IfAction SubSystem: '<S166>/Extended EMF Observer' */
  /* InitializeConditions for Delay: '<S171>/Delay' */
  iPMSM_F28069M_DWork.Delay_DSTATE[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S166>/Extended EMF Observer' */

  /* SystemInitialize for Merge: '<S166>/Merge' */
  iPMSM_F28069M_B.Merge_k[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S166>/Extended EMF Observer' */
  /* InitializeConditions for Delay: '<S171>/Delay' */
  iPMSM_F28069M_DWork.Delay_DSTATE[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S166>/Extended EMF Observer' */

  /* SystemInitialize for Merge: '<S166>/Merge' */
  iPMSM_F28069M_B.Merge_k[1] = 0.0F;
}

/* Output and update for atomic system: '<S11>/Calculate position and speed' */
void SVC_Calc(void)
{
  real32_T Delay5;
  real32_T Product_ds;
  real32_T UnitDelay_g;
  ZCSigState Delay1_Reset_ZCE_p_tmp;
  boolean_T zcEvent;

  /* Outputs for IfAction SubSystem: '<S166>/Flux Observer' incorporates:
   *  ActionPort: '<S168>/Action Port'
   */
  /* SwitchCase: '<S166>/Switch Case' incorporates:
   *  Constant: '<S311>/Filter_Constant'
   *  Product: '<S311>/Product'
   */
  Delay5 = iPMSM_F28069M_B.Delay5[0];
  Product_ds = Delay5 * 0.005F;

  /* End of Outputs for SubSystem: '<S166>/Flux Observer' */

  /* Product: '<S311>/Product' */
  iPMSM_F28069M_B.Product_ds[0] = Product_ds;

  /* Outputs for IfAction SubSystem: '<S166>/Flux Observer' incorporates:
   *  ActionPort: '<S168>/Action Port'
   */
  /* SwitchCase: '<S166>/Switch Case' incorporates:
   *  UnitDelay: '<S311>/Unit Delay'
   */
  UnitDelay_g = iPMSM_F28069M_DWork.UnitDelay_DSTATE_n3[0];

  /* End of Outputs for SubSystem: '<S166>/Flux Observer' */

  /* UnitDelay: '<S311>/Unit Delay' */
  iPMSM_F28069M_B.UnitDelay_g[0] = UnitDelay_g;

  /* Outputs for IfAction SubSystem: '<S166>/Flux Observer' incorporates:
   *  ActionPort: '<S168>/Action Port'
   */
  /* SwitchCase: '<S166>/Switch Case' incorporates:
   *  Constant: '<S311>/One'
   *  Product: '<S311>/Product1'
   */
  UnitDelay_g *= 0.995F;

  /* End of Outputs for SubSystem: '<S166>/Flux Observer' */

  /* Product: '<S311>/Product1' */
  iPMSM_F28069M_B.Product1_fg[0] = UnitDelay_g;

  /* Outputs for IfAction SubSystem: '<S166>/Flux Observer' incorporates:
   *  ActionPort: '<S168>/Action Port'
   */
  /* SwitchCase: '<S166>/Switch Case' incorporates:
   *  Sum: '<S311>/Add1'
   */
  Product_ds += UnitDelay_g;

  /* End of Outputs for SubSystem: '<S166>/Flux Observer' */

  /* Sum: '<S311>/Add1' */
  iPMSM_F28069M_B.Add1_iq[0] = Product_ds;

  /* Outputs for IfAction SubSystem: '<S166>/Flux Observer' incorporates:
   *  ActionPort: '<S168>/Action Port'
   */
  /* SwitchCase: '<S166>/Switch Case' incorporates:
   *  Constant: '<S311>/Filter_Constant'
   *  Product: '<S311>/Product'
   *  Sum: '<S304>/Sum6'
   */
  iPMSM_F28069M_B.Sum6_ap[0] = Delay5 - Product_ds;
  Delay5 = iPMSM_F28069M_B.Delay5[1];
  Product_ds = Delay5 * 0.005F;

  /* End of Outputs for SubSystem: '<S166>/Flux Observer' */

  /* Product: '<S311>/Product' */
  iPMSM_F28069M_B.Product_ds[1] = Product_ds;

  /* Outputs for IfAction SubSystem: '<S166>/Flux Observer' incorporates:
   *  ActionPort: '<S168>/Action Port'
   */
  /* SwitchCase: '<S166>/Switch Case' incorporates:
   *  UnitDelay: '<S311>/Unit Delay'
   */
  UnitDelay_g = iPMSM_F28069M_DWork.UnitDelay_DSTATE_n3[1];

  /* End of Outputs for SubSystem: '<S166>/Flux Observer' */

  /* UnitDelay: '<S311>/Unit Delay' */
  iPMSM_F28069M_B.UnitDelay_g[1] = UnitDelay_g;

  /* Outputs for IfAction SubSystem: '<S166>/Flux Observer' incorporates:
   *  ActionPort: '<S168>/Action Port'
   */
  /* SwitchCase: '<S166>/Switch Case' incorporates:
   *  Constant: '<S311>/One'
   *  Product: '<S311>/Product1'
   */
  UnitDelay_g *= 0.995F;

  /* End of Outputs for SubSystem: '<S166>/Flux Observer' */

  /* Product: '<S311>/Product1' */
  iPMSM_F28069M_B.Product1_fg[1] = UnitDelay_g;

  /* Outputs for IfAction SubSystem: '<S166>/Flux Observer' incorporates:
   *  ActionPort: '<S168>/Action Port'
   */
  /* SwitchCase: '<S166>/Switch Case' incorporates:
   *  Sum: '<S311>/Add1'
   */
  Product_ds += UnitDelay_g;

  /* End of Outputs for SubSystem: '<S166>/Flux Observer' */

  /* Sum: '<S311>/Add1' */
  iPMSM_F28069M_B.Add1_iq[1] = Product_ds;

  /* Outputs for IfAction SubSystem: '<S166>/Flux Observer' incorporates:
   *  ActionPort: '<S168>/Action Port'
   */
  /* SwitchCase: '<S166>/Switch Case' incorporates:
   *  Constant: '<S311>/Filter_Constant'
   *  Product: '<S311>/Product'
   *  Sum: '<S304>/Sum6'
   */
  iPMSM_F28069M_B.Sum6_ap[1] = Delay5 - Product_ds;
  Delay5 = iPMSM_F28069M_B.Delay5[2];
  Product_ds = Delay5 * 0.005F;

  /* End of Outputs for SubSystem: '<S166>/Flux Observer' */

  /* Product: '<S311>/Product' */
  iPMSM_F28069M_B.Product_ds[2] = Product_ds;

  /* Outputs for IfAction SubSystem: '<S166>/Flux Observer' incorporates:
   *  ActionPort: '<S168>/Action Port'
   */
  /* SwitchCase: '<S166>/Switch Case' incorporates:
   *  UnitDelay: '<S311>/Unit Delay'
   */
  UnitDelay_g = iPMSM_F28069M_DWork.UnitDelay_DSTATE_n3[2];

  /* End of Outputs for SubSystem: '<S166>/Flux Observer' */

  /* UnitDelay: '<S311>/Unit Delay' */
  iPMSM_F28069M_B.UnitDelay_g[2] = UnitDelay_g;

  /* Outputs for IfAction SubSystem: '<S166>/Flux Observer' incorporates:
   *  ActionPort: '<S168>/Action Port'
   */
  /* SwitchCase: '<S166>/Switch Case' incorporates:
   *  Constant: '<S311>/One'
   *  Product: '<S311>/Product1'
   */
  UnitDelay_g *= 0.995F;

  /* End of Outputs for SubSystem: '<S166>/Flux Observer' */

  /* Product: '<S311>/Product1' */
  iPMSM_F28069M_B.Product1_fg[2] = UnitDelay_g;

  /* Outputs for IfAction SubSystem: '<S166>/Flux Observer' incorporates:
   *  ActionPort: '<S168>/Action Port'
   */
  /* SwitchCase: '<S166>/Switch Case' incorporates:
   *  Sum: '<S311>/Add1'
   */
  Product_ds += UnitDelay_g;

  /* End of Outputs for SubSystem: '<S166>/Flux Observer' */

  /* Sum: '<S311>/Add1' */
  iPMSM_F28069M_B.Add1_iq[2] = Product_ds;

  /* Outputs for IfAction SubSystem: '<S166>/Flux Observer' incorporates:
   *  ActionPort: '<S168>/Action Port'
   */
  /* SwitchCase: '<S166>/Switch Case' incorporates:
   *  Constant: '<S311>/Filter_Constant'
   *  Product: '<S311>/Product'
   *  Sum: '<S304>/Sum6'
   */
  iPMSM_F28069M_B.Sum6_ap[2] = Delay5 - Product_ds;
  Delay5 = iPMSM_F28069M_B.Delay5[3];
  Product_ds = Delay5 * 0.005F;

  /* End of Outputs for SubSystem: '<S166>/Flux Observer' */

  /* Product: '<S311>/Product' */
  iPMSM_F28069M_B.Product_ds[3] = Product_ds;

  /* Outputs for IfAction SubSystem: '<S166>/Flux Observer' incorporates:
   *  ActionPort: '<S168>/Action Port'
   */
  /* SwitchCase: '<S166>/Switch Case' incorporates:
   *  UnitDelay: '<S311>/Unit Delay'
   */
  UnitDelay_g = iPMSM_F28069M_DWork.UnitDelay_DSTATE_n3[3];

  /* End of Outputs for SubSystem: '<S166>/Flux Observer' */

  /* UnitDelay: '<S311>/Unit Delay' */
  iPMSM_F28069M_B.UnitDelay_g[3] = UnitDelay_g;

  /* Outputs for IfAction SubSystem: '<S166>/Flux Observer' incorporates:
   *  ActionPort: '<S168>/Action Port'
   */
  /* SwitchCase: '<S166>/Switch Case' incorporates:
   *  Constant: '<S311>/One'
   *  Product: '<S311>/Product1'
   */
  UnitDelay_g *= 0.995F;

  /* End of Outputs for SubSystem: '<S166>/Flux Observer' */

  /* Product: '<S311>/Product1' */
  iPMSM_F28069M_B.Product1_fg[3] = UnitDelay_g;

  /* Outputs for IfAction SubSystem: '<S166>/Flux Observer' incorporates:
   *  ActionPort: '<S168>/Action Port'
   */
  /* SwitchCase: '<S166>/Switch Case' incorporates:
   *  Sum: '<S311>/Add1'
   */
  Product_ds += UnitDelay_g;

  /* End of Outputs for SubSystem: '<S166>/Flux Observer' */

  /* Sum: '<S311>/Add1' */
  iPMSM_F28069M_B.Add1_iq[3] = Product_ds;

  /* Outputs for IfAction SubSystem: '<S166>/Flux Observer' incorporates:
   *  ActionPort: '<S168>/Action Port'
   */
  /* SwitchCase: '<S166>/Switch Case' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S316>/a16'
   *  Constant: '<S324>/Filter_Constant'
   *  Constant: '<S324>/One'
   *  Constant: '<S331>/Filter_Constant'
   *  Constant: '<S331>/One'
   *  Constant: '<S334>/Filter_Constant'
   *  Constant: '<S334>/One'
   *  DataStoreRead: '<S168>/Data Store Read1'
   *  DataTypeConversion: '<S336>/DTC'
   *  Delay: '<S307>/Delay'
   *  Delay: '<S320>/Delay'
   *  Delay: '<S320>/Delay1'
   *  Delay: '<S327>/Delay'
   *  Delay: '<S327>/Delay1'
   *  Gain: '<S168>/elect2mech'
   *  Gain: '<S307>/PositionToCount'
   *  Gain: '<S307>/SpeedGain'
   *  Gain: '<S317>/Gain'
   *  Gain: '<S320>/Gain1'
   *  Gain: '<S320>/Gain2'
   *  Gain: '<S321>/ScalingL'
   *  Gain: '<S321>/ScalingR'
   *  Gain: '<S327>/Gain1'
   *  Gain: '<S327>/Gain2'
   *  Gain: '<S328>/ScalingL'
   *  Gain: '<S328>/ScalingR'
   *  Logic: '<S168>/Logical Operator'
   *  Merge: '<S166>/Merge'
   *  Product: '<S324>/Product'
   *  Product: '<S324>/Product1'
   *  Product: '<S331>/Product'
   *  Product: '<S331>/Product1'
   *  Product: '<S334>/Product'
   *  Product: '<S334>/Product1'
   *  SignalConversion generated from: '<S168>/Position//Speed'
   *  Sum: '<S304>/Sum6'
   *  Sum: '<S307>/SpeedCount'
   *  Sum: '<S318>/Sum1'
   *  Sum: '<S318>/Sum3'
   *  Sum: '<S320>/Sum'
   *  Sum: '<S320>/Sum1'
   *  Sum: '<S324>/Add1'
   *  Sum: '<S325>/Sum1'
   *  Sum: '<S325>/Sum3'
   *  Sum: '<S327>/Sum'
   *  Sum: '<S327>/Sum1'
   *  Sum: '<S331>/Add1'
   *  Sum: '<S334>/Add1'
   *  Switch: '<S316>/Switch'
   *  Switch: '<S317>/Switch'
   *  Switch: '<S318>/Switch'
   *  Switch: '<S325>/Switch'
   *  Trigonometry: '<S316>/Atan2'
   *  UnitDelay: '<S311>/Unit Delay'
   *  UnitDelay: '<S324>/Unit Delay'
   *  UnitDelay: '<S331>/Unit Delay'
   *  UnitDelay: '<S334>/Unit Delay'
   * */
  iPMSM_F28069M_B.Sum6_ap[3] = Delay5 - Product_ds;
  iPMSM_F28069M_B.DataStoreRead1_c = iPMSM_F28069M_DWork.Enable;
  iPMSM_F28069M_B.LogicalOperator_ed = !iPMSM_F28069M_B.DataStoreRead1_c;
  iPMSM_F28069M_B.ScalingR = 0.612403691F * iPMSM_F28069M_B.Sum6_ap[3];
  iPMSM_F28069M_B.Sum3_d = iPMSM_F28069M_B.Sum6_ap[1] - iPMSM_F28069M_B.ScalingR;
  zcEvent = (((iPMSM_F28069M_PrevZCSigState.Delay1_Reset_ZCE_p == POS_ZCSIG) !=
              (int16_T)iPMSM_F28069M_B.LogicalOperator_ed) &&
             (iPMSM_F28069M_PrevZCSigState.Delay1_Reset_ZCE_p !=
              UNINITIALIZED_ZCSIG));
  if (zcEvent || iPMSM_F28069M_B.LogicalOperator_ed) {
    iPMSM_F28069M_DWork.Delay1_DSTATE_n = 0.0F;
  }

  Delay1_Reset_ZCE_p_tmp = iPMSM_F28069M_B.LogicalOperator_ed;
  iPMSM_F28069M_PrevZCSigState.Delay1_Reset_ZCE_p = Delay1_Reset_ZCE_p_tmp;
  iPMSM_F28069M_B.Delay1_c = iPMSM_F28069M_DWork.Delay1_DSTATE_n;
  iPMSM_F28069M_B.Sum_nc = iPMSM_F28069M_B.Sum3_d + iPMSM_F28069M_B.Delay1_c;
  iPMSM_F28069M_B.Gain1_m = 2.49998757E-5F * iPMSM_F28069M_B.Sum_nc;
  zcEvent = (((iPMSM_F28069M_PrevZCSigState.Delay_Reset_ZCE_a == POS_ZCSIG) !=
              (int16_T)iPMSM_F28069M_B.LogicalOperator_ed) &&
             (iPMSM_F28069M_PrevZCSigState.Delay_Reset_ZCE_a !=
              UNINITIALIZED_ZCSIG));
  if (zcEvent || iPMSM_F28069M_B.LogicalOperator_ed) {
    iPMSM_F28069M_DWork.Delay_DSTATE_om = 0.0F;
  }

  iPMSM_F28069M_PrevZCSigState.Delay_Reset_ZCE_a = Delay1_Reset_ZCE_p_tmp;
  iPMSM_F28069M_B.Delay_ld = iPMSM_F28069M_DWork.Delay_DSTATE_om;
  iPMSM_F28069M_B.Gain2_j = 0.99999F * iPMSM_F28069M_B.Delay_ld;
  iPMSM_F28069M_B.Sum1_n = iPMSM_F28069M_B.Gain1_m + iPMSM_F28069M_B.Gain2_j;
  iPMSM_F28069M_B.ScalingL = 0.000340224273F * iPMSM_F28069M_B.Sum6_ap[3];
  iPMSM_F28069M_B.Sum1_b = iPMSM_F28069M_B.Sum1_n - iPMSM_F28069M_B.ScalingL;
  iPMSM_F28069M_B.Product_iy = iPMSM_F28069M_B.Sum1_b * 0.0010000047F;
  iPMSM_F28069M_B.UnitDelay_ii = iPMSM_F28069M_DWork.UnitDelay_DSTATE_p;
  iPMSM_F28069M_B.Product1_b3 = 0.999F * iPMSM_F28069M_B.UnitDelay_ii;
  iPMSM_F28069M_B.Add1_o0 = iPMSM_F28069M_B.Product_iy +
    iPMSM_F28069M_B.Product1_b3;
  if (iPMSM_F28069M_B.LogicalOperator_ed) {
    /* Switch: '<S325>/Switch' incorporates:
     *  Constant: '<S325>/Constant'
     */
    iPMSM_F28069M_B.Switch_g = 0.0F;
  } else {
    /* Sum: '<S330>/Sum' */
    iPMSM_F28069M_B.Sum_f = iPMSM_F28069M_B.Sum1_b - iPMSM_F28069M_B.Add1_o0;

    /* Switch: '<S325>/Switch' */
    iPMSM_F28069M_B.Switch_g = iPMSM_F28069M_B.Sum_f;
  }

  iPMSM_F28069M_B.ScalingR_k = 0.612403691F * iPMSM_F28069M_B.Sum6_ap[2];
  iPMSM_F28069M_B.Sum3_n = iPMSM_F28069M_B.Sum6_ap[0] -
    iPMSM_F28069M_B.ScalingR_k;
  zcEvent = (((iPMSM_F28069M_PrevZCSigState.Delay1_Reset_ZCE_a == POS_ZCSIG) !=
              (int16_T)iPMSM_F28069M_B.LogicalOperator_ed) &&
             (iPMSM_F28069M_PrevZCSigState.Delay1_Reset_ZCE_a !=
              UNINITIALIZED_ZCSIG));
  if (zcEvent || iPMSM_F28069M_B.LogicalOperator_ed) {
    iPMSM_F28069M_DWork.Delay1_DSTATE_n2 = 0.0F;
  }

  iPMSM_F28069M_PrevZCSigState.Delay1_Reset_ZCE_a = Delay1_Reset_ZCE_p_tmp;
  iPMSM_F28069M_B.Delay1_o = iPMSM_F28069M_DWork.Delay1_DSTATE_n2;
  iPMSM_F28069M_B.Sum_lg = iPMSM_F28069M_B.Sum3_n + iPMSM_F28069M_B.Delay1_o;
  iPMSM_F28069M_B.Gain1_ox = 2.49998757E-5F * iPMSM_F28069M_B.Sum_lg;
  zcEvent = (((iPMSM_F28069M_PrevZCSigState.Delay_Reset_ZCE_o == POS_ZCSIG) !=
              (int16_T)iPMSM_F28069M_B.LogicalOperator_ed) &&
             (iPMSM_F28069M_PrevZCSigState.Delay_Reset_ZCE_o !=
              UNINITIALIZED_ZCSIG));
  if (zcEvent || iPMSM_F28069M_B.LogicalOperator_ed) {
    iPMSM_F28069M_DWork.Delay_DSTATE_hc = 0.0F;
  }

  iPMSM_F28069M_PrevZCSigState.Delay_Reset_ZCE_o = Delay1_Reset_ZCE_p_tmp;
  iPMSM_F28069M_B.Delay_h = iPMSM_F28069M_DWork.Delay_DSTATE_hc;
  iPMSM_F28069M_B.Gain2_f1 = 0.99999F * iPMSM_F28069M_B.Delay_h;
  iPMSM_F28069M_B.Sum1_ni = iPMSM_F28069M_B.Gain1_ox + iPMSM_F28069M_B.Gain2_f1;
  iPMSM_F28069M_B.ScalingL_c = 0.000340224273F * iPMSM_F28069M_B.Sum6_ap[2];
  iPMSM_F28069M_B.Sum1_g = iPMSM_F28069M_B.Sum1_ni - iPMSM_F28069M_B.ScalingL_c;
  iPMSM_F28069M_B.Product_m5 = iPMSM_F28069M_B.Sum1_g * 0.0010000047F;
  iPMSM_F28069M_B.UnitDelay_f = iPMSM_F28069M_DWork.UnitDelay_DSTATE_nr;
  iPMSM_F28069M_B.Product1_hg = 0.999F * iPMSM_F28069M_B.UnitDelay_f;
  iPMSM_F28069M_B.Add1_az = iPMSM_F28069M_B.Product_m5 +
    iPMSM_F28069M_B.Product1_hg;
  if (iPMSM_F28069M_B.LogicalOperator_ed) {
    /* Switch: '<S318>/Switch' incorporates:
     *  Constant: '<S318>/Constant'
     */
    iPMSM_F28069M_B.Switch_h = 1.0E-6F;
  } else {
    /* Sum: '<S323>/Sum' */
    iPMSM_F28069M_B.Sum_bp = iPMSM_F28069M_B.Sum1_g - iPMSM_F28069M_B.Add1_az;

    /* Switch: '<S318>/Switch' */
    iPMSM_F28069M_B.Switch_h = iPMSM_F28069M_B.Sum_bp;
  }

  /* Outputs for Atomic SubSystem: '<S315>/atan2' */
  iPMSM_F28069M_B.Atan2 = atan2f(iPMSM_F28069M_B.Switch_g,
    iPMSM_F28069M_B.Switch_h);

  /* Outputs for Atomic SubSystem: '<S316>/Per Unit' */
  iPMSM_F28069M_B.Gain_f = 0.159154937F * iPMSM_F28069M_B.Atan2;
  if (iPMSM_F28069M_B.Gain_f >= 0.0F) {
    /* Switch: '<S317>/Switch' */
    iPMSM_F28069M_B.Switch_c = iPMSM_F28069M_B.Gain_f;
  } else {
    /* Bias: '<S317>/Bias' */
    iPMSM_F28069M_B.Bias = iPMSM_F28069M_B.Gain_f + 1.0F;

    /* Switch: '<S317>/Switch' */
    iPMSM_F28069M_B.Switch_c = iPMSM_F28069M_B.Bias;
  }

  /* End of Outputs for SubSystem: '<S316>/Per Unit' */
  iPMSM_F28069M_B.Switch_ds = iPMSM_F28069M_B.Switch_c;
  iPMSM_F28069M_B.algDD = iPMSM_F28069M_B.Switch_ds;

  /* End of Outputs for SubSystem: '<S315>/atan2' */
  iPMSM_F28069M_B.PositionToCount = (uint32_T)(4.2949673E+9F *
    iPMSM_F28069M_B.algDD);
  iPMSM_F28069M_B.Delay =
    iPMSM_F28069M_DWork.Delay_DSTATE_ad[iPMSM_F28069M_DWork.CircBufIdx];
  iPMSM_F28069M_B.SpeedCount = (int32_T)iPMSM_F28069M_B.PositionToCount -
    (int32_T)iPMSM_F28069M_B.Delay;
  iPMSM_F28069M_B.DTC = (real32_T)iPMSM_F28069M_B.SpeedCount;
  iPMSM_F28069M_B.SpeedGain = 6.80294043E-9F * iPMSM_F28069M_B.DTC;
  iPMSM_F28069M_B.Product_pk = iPMSM_F28069M_B.SpeedGain * 0.01F;
  iPMSM_F28069M_B.UnitDelay_d = iPMSM_F28069M_DWork.UnitDelay_DSTATE_a1;
  iPMSM_F28069M_B.Product1_al = 0.99F * iPMSM_F28069M_B.UnitDelay_d;
  iPMSM_F28069M_B.Add1_pz = iPMSM_F28069M_B.Product_pk +
    iPMSM_F28069M_B.Product1_al;
  iPMSM_F28069M_B.elect2mech = 0.25F * iPMSM_F28069M_B.Add1_pz;
  iPMSM_F28069M_B.Merge_k[0] = iPMSM_F28069M_B.algDD;
  iPMSM_F28069M_B.Merge_k[1] = iPMSM_F28069M_B.elect2mech;
  iPMSM_F28069M_DWork.UnitDelay_DSTATE_n3[0] = iPMSM_F28069M_B.Add1_iq[0];
  iPMSM_F28069M_DWork.UnitDelay_DSTATE_n3[1] = iPMSM_F28069M_B.Add1_iq[1];
  iPMSM_F28069M_DWork.UnitDelay_DSTATE_n3[2] = iPMSM_F28069M_B.Add1_iq[2];
  iPMSM_F28069M_DWork.UnitDelay_DSTATE_n3[3] = iPMSM_F28069M_B.Add1_iq[3];
  iPMSM_F28069M_DWork.Delay1_DSTATE_n = iPMSM_F28069M_B.Sum3_d;
  iPMSM_F28069M_DWork.Delay_DSTATE_om = iPMSM_F28069M_B.Sum1_n;
  iPMSM_F28069M_DWork.UnitDelay_DSTATE_p = iPMSM_F28069M_B.Add1_o0;
  iPMSM_F28069M_DWork.Delay1_DSTATE_n2 = iPMSM_F28069M_B.Sum3_n;
  iPMSM_F28069M_DWork.Delay_DSTATE_hc = iPMSM_F28069M_B.Sum1_ni;
  iPMSM_F28069M_DWork.UnitDelay_DSTATE_nr = iPMSM_F28069M_B.Add1_az;
  iPMSM_F28069M_DWork.Delay_DSTATE_ad[iPMSM_F28069M_DWork.CircBufIdx] =
    iPMSM_F28069M_B.PositionToCount;
  if (iPMSM_F28069M_DWork.CircBufIdx < 9U) {
    iPMSM_F28069M_DWork.CircBufIdx++;
  } else {
    iPMSM_F28069M_DWork.CircBufIdx = 0U;
  }

  iPMSM_F28069M_DWork.UnitDelay_DSTATE_a1 = iPMSM_F28069M_B.Add1_pz;

  /* End of Outputs for SubSystem: '<S166>/Flux Observer' */
}

/* System initialize for function-call system: '<Root>/Current Control' */
void iPMSM_F_CurrentControl_Init(void)
{
  /* Start for S-Function (c2802xadc): '<S164>/IA//IB Measurement' */
  if (MW_adcInitFlag == 0U) {
    InitAdc();
    MW_adcInitFlag = 1U;
  }

  config_ADC_SOC0_SOC1 ();

  /* Start for S-Function (c280xgpio_do): '<S364>/Digital Output' */
  EALLOW;
  GpioCtrlRegs.GPBMUX2.all &= 0xFFFFFFCFU;
  GpioCtrlRegs.GPBDIR.all |= 0x40000U;
  EDIS;

  /* Start for S-Function (c2802xpwm): '<S364>/ePWM1' */

  /*** Initialize ePWM1 modules ***/
  {
    /*  // Time Base Control Register
       EPwm1Regs.TBCTL.bit.CTRMODE              = 2U;          // Counter Mode
       EPwm1Regs.TBCTL.bit.SYNCOSEL             = 1U;          // Sync Output Select

       EPwm1Regs.TBCTL.bit.PRDLD                = 0U;          // Shadow select

       EPwm1Regs.TBCTL.bit.PHSEN                = 0U;          // Phase Load Enable
       EPwm1Regs.TBCTL.bit.PHSDIR               = 0U;          // Phase Direction Bit
       EPwm1Regs.TBCTL.bit.HSPCLKDIV            = 0U;          // High Speed TBCLK Pre-scaler
       EPwm1Regs.TBCTL.bit.CLKDIV               = 0U;          // Time Base Clock Pre-scaler
     */
    EPwm1Regs.TBCTL.all = (EPwm1Regs.TBCTL.all & ~0x3FFFU) | 0x12U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm1Regs.TBPRD = 2250U;           // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm1Regs.TBPHS.half.TBPHS               = 0U;         // Phase offset register
     */
    EPwm1Regs.TBPHS.all = (EPwm1Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm1Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm1Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm1Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm1Regs.CMPCTL.bit.SHDWAMODE           = 0U;          // Compare A Register Block Operating Mode
       EPwm1Regs.CMPCTL.bit.SHDWBMODE           = 0U;          // Compare B Register Block Operating Mode
     */
    EPwm1Regs.CMPCTL.all = (EPwm1Regs.CMPCTL.all & ~0x5FU) | 0x0U;
    EPwm1Regs.CMPA.half.CMPA = 1126U;  // Counter Compare A Register
    EPwm1Regs.CMPB = 1126U;            // Counter Compare B Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm1Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm1Regs.AQCTLB.all = 264U;
                               // Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm1Regs.AQSFRC.bit.RLDCSF              = 0U;          // Reload from Shadow Options
     */
    EPwm1Regs.AQSFRC.all = (EPwm1Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm1Regs.AQCSFRC.bit.CSFA               = 0U;          // Continuous Software Force on output A
       EPwm1Regs.AQCSFRC.bit.CSFB               = 0U;          // Continuous Software Force on output B
     */
    EPwm1Regs.AQCSFRC.all = (EPwm1Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm1Regs.DBCTL.bit.OUT_MODE             = 3U;          // Dead Band Output Mode Control
       EPwm1Regs.DBCTL.bit.IN_MODE              = 0U;          // Dead Band Input Select Mode Control
       EPwm1Regs.DBCTL.bit.POLSEL               = 2U;          // Polarity Select Control
       EPwm1Regs.DBCTL.bit.HALFCYCLE            = 0U;          // Half Cycle Clocking Enable
     */
    EPwm1Regs.DBCTL.all = (EPwm1Regs.DBCTL.all & ~0x803FU) | 0xBU;
    EPwm1Regs.DBRED = 15U;
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm1Regs.DBFED = 15U;
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm1Regs.ETSEL.bit.SOCAEN               = 1U;          // Start of Conversion A Enable
       EPwm1Regs.ETSEL.bit.SOCASEL              = 2U;          // Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCAPRD               = 1U;          // EPWM1SOCA Period Select
       EPwm1Regs.ETSEL.bit.SOCBEN               = 0U;          // Start of Conversion B Enable
       EPwm1Regs.ETSEL.bit.SOCBSEL              = 1U;          // Start of Conversion B Select
       EPwm1Regs.ETPS.bit.SOCBPRD               = 1U;          // EPWM1SOCB Period Select
       EPwm1Regs.ETSEL.bit.INTEN                = 0U;          // EPWM1INTn Enable
       EPwm1Regs.ETSEL.bit.INTSEL               = 1U;          // EPWM1INTn Select
       EPwm1Regs.ETPS.bit.INTPRD                = 1U;          // EPWM1INTn Period Select
     */
    EPwm1Regs.ETSEL.all = (EPwm1Regs.ETSEL.all & ~0xFF0FU) | 0x1A01U;
    EPwm1Regs.ETPS.all = (EPwm1Regs.ETPS.all & ~0x3303U) | 0x1101U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm1Regs.PCCTL.bit.CHPEN                = 0U;          // PWM chopping enable
       EPwm1Regs.PCCTL.bit.CHPFREQ              = 0U;          // Chopping clock frequency
       EPwm1Regs.PCCTL.bit.OSHTWTH              = 0U;          // One-shot pulse width
       EPwm1Regs.PCCTL.bit.CHPDUTY              = 0U;          // Chopping clock Duty cycle
     */
    EPwm1Regs.PCCTL.all = (EPwm1Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm1Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm1Regs.TZCTL.bit.TZA                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM1A
       EPwm1Regs.TZCTL.bit.TZB                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM1B
       EPwm1Regs.TZCTL.bit.DCAEVT1              = 3U;          // EPWM1A action on DCAEVT1
       EPwm1Regs.TZCTL.bit.DCAEVT2              = 3U;          // EPWM1A action on DCAEVT2
       EPwm1Regs.TZCTL.bit.DCBEVT1              = 3U;          // EPWM1B action on DCBEVT1
       EPwm1Regs.TZCTL.bit.DCBEVT2              = 3U;          // EPWM1B action on DCBEVT2
     */
    EPwm1Regs.TZCTL.all = (EPwm1Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	// Trip Zone Enable Interrupt Register
       EPwm1Regs.TZEINT.bit.OST                 = 0U;          // Trip Zones One Shot Int Enable
       EPwm1Regs.TZEINT.bit.CBC                 = 0U;          // Trip Zones Cycle By Cycle Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT1             = 0U;          // Digital Compare A Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT2             = 0U;          // Digital Compare A Event 2 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT1             = 0U;          // Digital Compare B Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT2             = 0U;          // Digital Compare B Event 2 Int Enable
     */
    EPwm1Regs.TZEINT.all = (EPwm1Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	// Digital Compare A Control Register
       EPwm1Regs.DCACTL.bit.EVT1SYNCE           = 0U;          // DCAEVT1 SYNC Enable
       EPwm1Regs.DCACTL.bit.EVT1SOCE            = 0U;          // DCAEVT1 SOC Enable
       EPwm1Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCAEVT1 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          // DCAEVT1 Source Signal
       EPwm1Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCAEVT2 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          // DCAEVT2 Source Signal
     */
    EPwm1Regs.DCACTL.all = (EPwm1Regs.DCACTL.all & ~0x30FU) | 0x0U;

    /*	// Digital Compare B Control Register
       EPwm1Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          // DCBEVT1 SYNC Enable
       EPwm1Regs.DCBCTL.bit.EVT1SOCE            = 0U;          // DCBEVT1 SOC Enable
       EPwm1Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCBEVT1 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          // DCBEVT1 Source Signal
       EPwm1Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCBEVT2 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          // DCBEVT2 Source Signal
     */
    EPwm1Regs.DCBCTL.all = (EPwm1Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	// Digital Compare Trip Select Register
       EPwm1Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          // Digital Compare A High COMP Input Select

       EPwm1Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          // Digital Compare A Low COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          // Digital Compare B High COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          // Digital Compare B Low COMP Input Select
     */
    EPwm1Regs.DCTRIPSEL.all = (EPwm1Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm1Regs.TZDCSEL.bit.DCAEVT1            = 0U;          // Digital Compare Output A Event 1
       EPwm1Regs.TZDCSEL.bit.DCAEVT2            = 0U;          // Digital Compare Output A Event 2
       EPwm1Regs.TZDCSEL.bit.DCBEVT1            = 0U;          // Digital Compare Output B Event 1
       EPwm1Regs.TZDCSEL.bit.DCBEVT2            = 0U;          // Digital Compare Output B Event 2
     */
    EPwm1Regs.TZDCSEL.all = (EPwm1Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	// Digital Compare Filter Control Register
       EPwm1Regs.DCFCTL.bit.BLANKE              = 0U;          // Blanking Enable/Disable
       EPwm1Regs.DCFCTL.bit.PULSESEL            = 1U;          // Pulse Select for Blanking & Capture Alignment
       EPwm1Regs.DCFCTL.bit.BLANKINV            = 0U;          // Blanking Window Inversion
       EPwm1Regs.DCFCTL.bit.SRCSEL              = 0U;          // Filter Block Signal Source Select
     */
    EPwm1Regs.DCFCTL.all = (EPwm1Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm1Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm1Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm1Regs.DCCAPCTL.bit.CAPE              = 0U;          // Counter Capture Enable
     */
    EPwm1Regs.DCCAPCTL.all = (EPwm1Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	// HRPWM Configuration Register
       EPwm1Regs.HRCNFG.bit.SWAPAB              = 0U;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm1Regs.HRCNFG.bit.SELOUTB             = 0U;          // EPWMB Output Selection Bit
     */
    EPwm1Regs.HRCNFG.all = (EPwm1Regs.HRCNFG.all & ~0xA0U) | 0x0U;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S364>/ePWM2' */

  /*** Initialize ePWM2 modules ***/
  {
    /*  // Time Base Control Register
       EPwm2Regs.TBCTL.bit.CTRMODE              = 2U;          // Counter Mode
       EPwm2Regs.TBCTL.bit.SYNCOSEL             = 0U;          // Sync Output Select

       EPwm2Regs.TBCTL.bit.PRDLD                = 0U;          // Shadow select

       EPwm2Regs.TBCTL.bit.PHSEN                = 1U;          // Phase Load Enable
       EPwm2Regs.TBCTL.bit.PHSDIR               = 1U;          // Phase Direction Bit
       EPwm2Regs.TBCTL.bit.HSPCLKDIV            = 0U;          // High Speed TBCLK Pre-scaler
       EPwm2Regs.TBCTL.bit.CLKDIV               = 0U;          // Time Base Clock Pre-scaler
     */
    EPwm2Regs.TBCTL.all = (EPwm2Regs.TBCTL.all & ~0x3FFFU) | 0x2006U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm2Regs.TBPRD = 2250U;           // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm2Regs.TBPHS.half.TBPHS               = 0U;         // Phase offset register
     */
    EPwm2Regs.TBPHS.all = (EPwm2Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm2Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm2Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm2Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm2Regs.CMPCTL.bit.SHDWAMODE           = 0U;          // Compare A Register Block Operating Mode
       EPwm2Regs.CMPCTL.bit.SHDWBMODE           = 0U;          // Compare B Register Block Operating Mode
     */
    EPwm2Regs.CMPCTL.all = (EPwm2Regs.CMPCTL.all & ~0x5FU) | 0x0U;
    EPwm2Regs.CMPA.half.CMPA = 1126U;  // Counter Compare A Register
    EPwm2Regs.CMPB = 1126U;            // Counter Compare B Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm2Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm2Regs.AQCTLB.all = 264U;
                               // Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm2Regs.AQSFRC.bit.RLDCSF              = 0U;          // Reload from Shadow Options
     */
    EPwm2Regs.AQSFRC.all = (EPwm2Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm2Regs.AQCSFRC.bit.CSFA               = 0U;          // Continuous Software Force on output A
       EPwm2Regs.AQCSFRC.bit.CSFB               = 0U;          // Continuous Software Force on output B
     */
    EPwm2Regs.AQCSFRC.all = (EPwm2Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm2Regs.DBCTL.bit.OUT_MODE             = 3U;          // Dead Band Output Mode Control
       EPwm2Regs.DBCTL.bit.IN_MODE              = 0U;          // Dead Band Input Select Mode Control
       EPwm2Regs.DBCTL.bit.POLSEL               = 2U;          // Polarity Select Control
       EPwm2Regs.DBCTL.bit.HALFCYCLE            = 0U;          // Half Cycle Clocking Enable
     */
    EPwm2Regs.DBCTL.all = (EPwm2Regs.DBCTL.all & ~0x803FU) | 0xBU;
    EPwm2Regs.DBRED = 15U;
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm2Regs.DBFED = 15U;
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm2Regs.ETSEL.bit.SOCAEN               = 0U;          // Start of Conversion A Enable
       EPwm2Regs.ETSEL.bit.SOCASEL              = 0U;          // Start of Conversion A Select
       EPwm2Regs.ETPS.bit.SOCAPRD               = 1U;          // EPWM2SOCA Period Select
       EPwm2Regs.ETSEL.bit.SOCBEN               = 0U;          // Start of Conversion B Enable
       EPwm2Regs.ETSEL.bit.SOCBSEL              = 1U;          // Start of Conversion B Select
       EPwm2Regs.ETPS.bit.SOCBPRD               = 1U;          // EPWM2SOCB Period Select
       EPwm2Regs.ETSEL.bit.INTEN                = 0U;          // EPWM2INTn Enable
       EPwm2Regs.ETSEL.bit.INTSEL               = 1U;          // EPWM2INTn Select
       EPwm2Regs.ETPS.bit.INTPRD                = 1U;          // EPWM2INTn Period Select
     */
    EPwm2Regs.ETSEL.all = (EPwm2Regs.ETSEL.all & ~0xFF0FU) | 0x1001U;
    EPwm2Regs.ETPS.all = (EPwm2Regs.ETPS.all & ~0x3303U) | 0x1101U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm2Regs.PCCTL.bit.CHPEN                = 0U;          // PWM chopping enable
       EPwm2Regs.PCCTL.bit.CHPFREQ              = 0U;          // Chopping clock frequency
       EPwm2Regs.PCCTL.bit.OSHTWTH              = 0U;          // One-shot pulse width
       EPwm2Regs.PCCTL.bit.CHPDUTY              = 0U;          // Chopping clock Duty cycle
     */
    EPwm2Regs.PCCTL.all = (EPwm2Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm2Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm2Regs.TZCTL.bit.TZA                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM2A
       EPwm2Regs.TZCTL.bit.TZB                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM2B
       EPwm2Regs.TZCTL.bit.DCAEVT1              = 3U;          // EPWM2A action on DCAEVT1
       EPwm2Regs.TZCTL.bit.DCAEVT2              = 3U;          // EPWM2A action on DCAEVT2
       EPwm2Regs.TZCTL.bit.DCBEVT1              = 3U;          // EPWM2B action on DCBEVT1
       EPwm2Regs.TZCTL.bit.DCBEVT2              = 3U;          // EPWM2B action on DCBEVT2
     */
    EPwm2Regs.TZCTL.all = (EPwm2Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	// Trip Zone Enable Interrupt Register
       EPwm2Regs.TZEINT.bit.OST                 = 0U;          // Trip Zones One Shot Int Enable
       EPwm2Regs.TZEINT.bit.CBC                 = 0U;          // Trip Zones Cycle By Cycle Int Enable
       EPwm2Regs.TZEINT.bit.DCAEVT1             = 0U;          // Digital Compare A Event 1 Int Enable
       EPwm2Regs.TZEINT.bit.DCAEVT2             = 0U;          // Digital Compare A Event 2 Int Enable
       EPwm2Regs.TZEINT.bit.DCBEVT1             = 0U;          // Digital Compare B Event 1 Int Enable
       EPwm2Regs.TZEINT.bit.DCBEVT2             = 0U;          // Digital Compare B Event 2 Int Enable
     */
    EPwm2Regs.TZEINT.all = (EPwm2Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	// Digital Compare A Control Register
       EPwm2Regs.DCACTL.bit.EVT1SYNCE           = 0U;          // DCAEVT1 SYNC Enable
       EPwm2Regs.DCACTL.bit.EVT1SOCE            = 1U;          // DCAEVT1 SOC Enable
       EPwm2Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCAEVT1 Force Sync Signal
       EPwm2Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          // DCAEVT1 Source Signal
       EPwm2Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCAEVT2 Force Sync Signal
       EPwm2Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          // DCAEVT2 Source Signal
     */
    EPwm2Regs.DCACTL.all = (EPwm2Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	// Digital Compare B Control Register
       EPwm2Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          // DCBEVT1 SYNC Enable
       EPwm2Regs.DCBCTL.bit.EVT1SOCE            = 0U;          // DCBEVT1 SOC Enable
       EPwm2Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCBEVT1 Force Sync Signal
       EPwm2Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          // DCBEVT1 Source Signal
       EPwm2Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCBEVT2 Force Sync Signal
       EPwm2Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          // DCBEVT2 Source Signal
     */
    EPwm2Regs.DCBCTL.all = (EPwm2Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	// Digital Compare Trip Select Register
       EPwm2Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          // Digital Compare A High COMP Input Select

       EPwm2Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          // Digital Compare A Low COMP Input Select
       EPwm2Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          // Digital Compare B High COMP Input Select
       EPwm2Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          // Digital Compare B Low COMP Input Select
     */
    EPwm2Regs.DCTRIPSEL.all = (EPwm2Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm2Regs.TZDCSEL.bit.DCAEVT1            = 0U;          // Digital Compare Output A Event 1
       EPwm2Regs.TZDCSEL.bit.DCAEVT2            = 0U;          // Digital Compare Output A Event 2
       EPwm2Regs.TZDCSEL.bit.DCBEVT1            = 0U;          // Digital Compare Output B Event 1
       EPwm2Regs.TZDCSEL.bit.DCBEVT2            = 0U;          // Digital Compare Output B Event 2
     */
    EPwm2Regs.TZDCSEL.all = (EPwm2Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	// Digital Compare Filter Control Register
       EPwm2Regs.DCFCTL.bit.BLANKE              = 0U;          // Blanking Enable/Disable
       EPwm2Regs.DCFCTL.bit.PULSESEL            = 1U;          // Pulse Select for Blanking & Capture Alignment
       EPwm2Regs.DCFCTL.bit.BLANKINV            = 0U;          // Blanking Window Inversion
       EPwm2Regs.DCFCTL.bit.SRCSEL              = 0U;          // Filter Block Signal Source Select
     */
    EPwm2Regs.DCFCTL.all = (EPwm2Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm2Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm2Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm2Regs.DCCAPCTL.bit.CAPE              = 0U;          // Counter Capture Enable
     */
    EPwm2Regs.DCCAPCTL.all = (EPwm2Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	// HRPWM Configuration Register
       EPwm2Regs.HRCNFG.bit.SWAPAB              = 0U;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm2Regs.HRCNFG.bit.SELOUTB             = 0U;          // EPWMB Output Selection Bit
     */
    EPwm2Regs.HRCNFG.all = (EPwm2Regs.HRCNFG.all & ~0xA0U) | 0x0U;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S364>/ePWM3' */

  /*** Initialize ePWM3 modules ***/
  {
    /*  // Time Base Control Register
       EPwm3Regs.TBCTL.bit.CTRMODE              = 2U;          // Counter Mode
       EPwm3Regs.TBCTL.bit.SYNCOSEL             = 3U;          // Sync Output Select

       EPwm3Regs.TBCTL.bit.PRDLD                = 0U;          // Shadow select

       EPwm3Regs.TBCTL.bit.PHSEN                = 1U;          // Phase Load Enable
       EPwm3Regs.TBCTL.bit.PHSDIR               = 1U;          // Phase Direction Bit
       EPwm3Regs.TBCTL.bit.HSPCLKDIV            = 0U;          // High Speed TBCLK Pre-scaler
       EPwm3Regs.TBCTL.bit.CLKDIV               = 0U;          // Time Base Clock Pre-scaler
     */
    EPwm3Regs.TBCTL.all = (EPwm3Regs.TBCTL.all & ~0x3FFFU) | 0x2036U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm3Regs.TBPRD = 2250U;           // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm3Regs.TBPHS.half.TBPHS               = 0U;         // Phase offset register
     */
    EPwm3Regs.TBPHS.all = (EPwm3Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm3Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm3Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm3Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm3Regs.CMPCTL.bit.SHDWAMODE           = 0U;          // Compare A Register Block Operating Mode
       EPwm3Regs.CMPCTL.bit.SHDWBMODE           = 0U;          // Compare B Register Block Operating Mode
     */
    EPwm3Regs.CMPCTL.all = (EPwm3Regs.CMPCTL.all & ~0x5FU) | 0x0U;
    EPwm3Regs.CMPA.half.CMPA = 1126U;  // Counter Compare A Register
    EPwm3Regs.CMPB = 1126U;            // Counter Compare B Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm3Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm3Regs.AQCTLB.all = 264U;
                               // Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm3Regs.AQSFRC.bit.RLDCSF              = 0U;          // Reload from Shadow Options
     */
    EPwm3Regs.AQSFRC.all = (EPwm3Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm3Regs.AQCSFRC.bit.CSFA               = 0U;          // Continuous Software Force on output A
       EPwm3Regs.AQCSFRC.bit.CSFB               = 0U;          // Continuous Software Force on output B
     */
    EPwm3Regs.AQCSFRC.all = (EPwm3Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm3Regs.DBCTL.bit.OUT_MODE             = 3U;          // Dead Band Output Mode Control
       EPwm3Regs.DBCTL.bit.IN_MODE              = 0U;          // Dead Band Input Select Mode Control
       EPwm3Regs.DBCTL.bit.POLSEL               = 2U;          // Polarity Select Control
       EPwm3Regs.DBCTL.bit.HALFCYCLE            = 0U;          // Half Cycle Clocking Enable
     */
    EPwm3Regs.DBCTL.all = (EPwm3Regs.DBCTL.all & ~0x803FU) | 0xBU;
    EPwm3Regs.DBRED = 15U;
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm3Regs.DBFED = 15U;
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm3Regs.ETSEL.bit.SOCAEN               = 0U;          // Start of Conversion A Enable
       EPwm3Regs.ETSEL.bit.SOCASEL              = 0U;          // Start of Conversion A Select
       EPwm3Regs.ETPS.bit.SOCAPRD               = 1U;          // EPWM3SOCA Period Select
       EPwm3Regs.ETSEL.bit.SOCBEN               = 0U;          // Start of Conversion B Enable
       EPwm3Regs.ETSEL.bit.SOCBSEL              = 1U;          // Start of Conversion B Select
       EPwm3Regs.ETPS.bit.SOCBPRD               = 1U;          // EPWM3SOCB Period Select
       EPwm3Regs.ETSEL.bit.INTEN                = 0U;          // EPWM3INTn Enable
       EPwm3Regs.ETSEL.bit.INTSEL               = 1U;          // EPWM3INTn Select
       EPwm3Regs.ETPS.bit.INTPRD                = 1U;          // EPWM3INTn Period Select
     */
    EPwm3Regs.ETSEL.all = (EPwm3Regs.ETSEL.all & ~0xFF0FU) | 0x1001U;
    EPwm3Regs.ETPS.all = (EPwm3Regs.ETPS.all & ~0x3303U) | 0x1101U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm3Regs.PCCTL.bit.CHPEN                = 0U;          // PWM chopping enable
       EPwm3Regs.PCCTL.bit.CHPFREQ              = 0U;          // Chopping clock frequency
       EPwm3Regs.PCCTL.bit.OSHTWTH              = 0U;          // One-shot pulse width
       EPwm3Regs.PCCTL.bit.CHPDUTY              = 0U;          // Chopping clock Duty cycle
     */
    EPwm3Regs.PCCTL.all = (EPwm3Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm3Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm3Regs.TZCTL.bit.TZA                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM3A
       EPwm3Regs.TZCTL.bit.TZB                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM3B
       EPwm3Regs.TZCTL.bit.DCAEVT1              = 3U;          // EPWM3A action on DCAEVT1
       EPwm3Regs.TZCTL.bit.DCAEVT2              = 3U;          // EPWM3A action on DCAEVT2
       EPwm3Regs.TZCTL.bit.DCBEVT1              = 3U;          // EPWM3B action on DCBEVT1
       EPwm3Regs.TZCTL.bit.DCBEVT2              = 3U;          // EPWM3B action on DCBEVT2
     */
    EPwm3Regs.TZCTL.all = (EPwm3Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	// Trip Zone Enable Interrupt Register
       EPwm3Regs.TZEINT.bit.OST                 = 0U;          // Trip Zones One Shot Int Enable
       EPwm3Regs.TZEINT.bit.CBC                 = 0U;          // Trip Zones Cycle By Cycle Int Enable
       EPwm3Regs.TZEINT.bit.DCAEVT1             = 0U;          // Digital Compare A Event 1 Int Enable
       EPwm3Regs.TZEINT.bit.DCAEVT2             = 0U;          // Digital Compare A Event 2 Int Enable
       EPwm3Regs.TZEINT.bit.DCBEVT1             = 0U;          // Digital Compare B Event 1 Int Enable
       EPwm3Regs.TZEINT.bit.DCBEVT2             = 0U;          // Digital Compare B Event 2 Int Enable
     */
    EPwm3Regs.TZEINT.all = (EPwm3Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	// Digital Compare A Control Register
       EPwm3Regs.DCACTL.bit.EVT1SYNCE           = 0U;          // DCAEVT1 SYNC Enable
       EPwm3Regs.DCACTL.bit.EVT1SOCE            = 1U;          // DCAEVT1 SOC Enable
       EPwm3Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCAEVT1 Force Sync Signal
       EPwm3Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          // DCAEVT1 Source Signal
       EPwm3Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCAEVT2 Force Sync Signal
       EPwm3Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          // DCAEVT2 Source Signal
     */
    EPwm3Regs.DCACTL.all = (EPwm3Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	// Digital Compare B Control Register
       EPwm3Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          // DCBEVT1 SYNC Enable
       EPwm3Regs.DCBCTL.bit.EVT1SOCE            = 0U;          // DCBEVT1 SOC Enable
       EPwm3Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCBEVT1 Force Sync Signal
       EPwm3Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          // DCBEVT1 Source Signal
       EPwm3Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCBEVT2 Force Sync Signal
       EPwm3Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          // DCBEVT2 Source Signal
     */
    EPwm3Regs.DCBCTL.all = (EPwm3Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	// Digital Compare Trip Select Register
       EPwm3Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          // Digital Compare A High COMP Input Select

       EPwm3Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          // Digital Compare A Low COMP Input Select
       EPwm3Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          // Digital Compare B High COMP Input Select
       EPwm3Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          // Digital Compare B Low COMP Input Select
     */
    EPwm3Regs.DCTRIPSEL.all = (EPwm3Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm3Regs.TZDCSEL.bit.DCAEVT1            = 0U;          // Digital Compare Output A Event 1
       EPwm3Regs.TZDCSEL.bit.DCAEVT2            = 0U;          // Digital Compare Output A Event 2
       EPwm3Regs.TZDCSEL.bit.DCBEVT1            = 0U;          // Digital Compare Output B Event 1
       EPwm3Regs.TZDCSEL.bit.DCBEVT2            = 0U;          // Digital Compare Output B Event 2
     */
    EPwm3Regs.TZDCSEL.all = (EPwm3Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	// Digital Compare Filter Control Register
       EPwm3Regs.DCFCTL.bit.BLANKE              = 0U;          // Blanking Enable/Disable
       EPwm3Regs.DCFCTL.bit.PULSESEL            = 1U;          // Pulse Select for Blanking & Capture Alignment
       EPwm3Regs.DCFCTL.bit.BLANKINV            = 0U;          // Blanking Window Inversion
       EPwm3Regs.DCFCTL.bit.SRCSEL              = 0U;          // Filter Block Signal Source Select
     */
    EPwm3Regs.DCFCTL.all = (EPwm3Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm3Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm3Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm3Regs.DCCAPCTL.bit.CAPE              = 0U;          // Counter Capture Enable
     */
    EPwm3Regs.DCCAPCTL.all = (EPwm3Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	// HRPWM Configuration Register
       EPwm3Regs.HRCNFG.bit.SWAPAB              = 0U;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm3Regs.HRCNFG.bit.SELOUTB             = 0U;          // EPWMB Output Selection Bit
     */
    EPwm3Regs.HRCNFG.all = (EPwm3Regs.HRCNFG.all & ~0xA0U) | 0x0U;
    EDIS;
  }

  /* InitializeConditions for DiscreteIntegrator: '<S124>/Integrator' */
  iPMSM_F28069M_DWork.Integrator_PrevResetState = 0;
  iPMSM_F28069M_DWork.Integrator_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S73>/Integrator' */
  iPMSM_F28069M_DWork.Integrator_PrevResetState_f = 0;
  iPMSM_F28069M_DWork.Integrator_IC_LOADING_p = 1U;

  /* SystemInitialize for Atomic SubSystem: '<S11>/Calculate position and speed' */
  SVC_Calc_Init();

  /* End of SystemInitialize for SubSystem: '<S11>/Calculate position and speed' */
}

/* System reset for function-call system: '<Root>/Current Control' */
void iPMSM__CurrentControl_Reset(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<S124>/Integrator' */
  iPMSM_F28069M_DWork.Integrator_PrevResetState = 0;
  iPMSM_F28069M_DWork.Integrator_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S73>/Integrator' */
  iPMSM_F28069M_DWork.Integrator_PrevResetState_f = 0;
  iPMSM_F28069M_DWork.Integrator_IC_LOADING_p = 1U;
}

/* Output and update for function-call system: '<Root>/Current Control' */
#pragma CODE_SECTION (iPMSM_F28069_CurrentControl, "ramfuncs")

void iPMSM_F28069_CurrentControl(void)
{
  int32_T Q17perunitconversion;
  real32_T Bias;
  real32_T u0;
  uint32_T Sum;
  int16_T s366_iter;
  uint16_T Data;

  /* DataStoreRead: '<S18>/Data Store Read' */
  iPMSM_F28069M_B.DataStoreRead = iPMSM_F28069M_DWork.Speed_ref;

  /* Abs: '<S18>/Abs' */
  iPMSM_F28069M_B.Abs = fabsf(iPMSM_F28069M_B.DataStoreRead);

  /* Switch: '<S18>/Switch2' */
  iPMSM_F28069M_B.Switch2_m = (uint16_T)(iPMSM_F28069M_B.Abs > 0.1F);

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  iPMSM_F28069M_B.DataTypeConversion_j = (iPMSM_F28069M_B.Switch2_m != 0U);

  /* DataStoreWrite: '<S18>/Data Store Write' */
  iPMSM_F28069M_DWork.EnClosedLoop = iPMSM_F28069M_B.DataTypeConversion_j;

  /* Gain: '<S18>/Gain' */
  iPMSM_F28069M_B.Gain = 0.01369F * iPMSM_F28069M_B.DataStoreRead;

  /* UnitDelay: '<S142>/Unit Delay' */
  iPMSM_F28069M_B.UnitDelay = iPMSM_F28069M_DWork.UnitDelay_DSTATE;

  /* Logic: '<S142>/NOT' */
  iPMSM_F28069M_B.NOT_a = true;

  /* Outputs for Enabled SubSystem: '<S142>/Accumulate' */
  iPMSM_F28069M_Accumulate(true, iPMSM_F28069M_B.Gain, iPMSM_F28069M_B.UnitDelay,
    &iPMSM_F28069M_B.Accumulate, &iPMSM_F28069M_DWork.Accumulate);

  /* End of Outputs for SubSystem: '<S142>/Accumulate' */

  /* Delay: '<S1>/Delay5' */
  iPMSM_F28069M_B.Delay5[0] = iPMSM_F28069M_DWork.Delay5_DSTATE[0];
  iPMSM_F28069M_B.Delay5[1] = iPMSM_F28069M_DWork.Delay5_DSTATE[1];
  iPMSM_F28069M_B.Delay5[2] = iPMSM_F28069M_DWork.Delay5_DSTATE[2];
  iPMSM_F28069M_B.Delay5[3] = iPMSM_F28069M_DWork.Delay5_DSTATE[3];

  /* Outputs for Atomic SubSystem: '<S11>/Calculate position and speed' */
  SVC_Calc();

  /* End of Outputs for SubSystem: '<S11>/Calculate position and speed' */

  /* Switch: '<S18>/Switch' */
  if (iPMSM_F28069M_B.Switch2_m != 0U) {
    /* Switch: '<S18>/Switch' */
    iPMSM_F28069M_B.Switch = iPMSM_F28069M_B.Merge_k[0];
  } else {
    /* Switch: '<S18>/Switch' */
    iPMSM_F28069M_B.Switch = iPMSM_F28069M_B.Accumulate.Add1;
  }

  /* End of Switch: '<S18>/Switch' */

  /* DataStoreRead: '<S165>/Data Store Read' */
  iPMSM_F28069M_B.DataStoreRead_m = iPMSM_F28069M_DWork.IaOffset;

  /* DataStoreRead: '<S165>/Data Store Read1' */
  iPMSM_F28069M_B.DataStoreRead1 = iPMSM_F28069M_DWork.IbOffset;

  /* S-Function (c2802xadc): '<S164>/IA//IB Measurement' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    Iab_ADC_u16[0] = (AdcResult.ADCRESULT0);
    Iab_ADC_u16[1] = (AdcResult.ADCRESULT1);
  }

  /* DataTypeConversion: '<S165>/Data Type Conversion' */
  iPMSM_F28069M_B.DataTypeConversion_c[0] = Iab_ADC_u16[0];
  iPMSM_F28069M_B.DataTypeConversion_c[1] = Iab_ADC_u16[1];

  /* Sum: '<S165>/Add' */
  iPMSM_F28069M_B.Add_k[0] = iPMSM_F28069M_B.DataTypeConversion_c[0] -
    iPMSM_F28069M_B.DataStoreRead_m;
  iPMSM_F28069M_B.Add_k[1] = iPMSM_F28069M_B.DataTypeConversion_c[1] -
    iPMSM_F28069M_B.DataStoreRead1;

  /* ArithShift: '<S165>/Q17 per unit conversion' incorporates:
   *  Sum: '<S165>/Add'
   */
  Q17perunitconversion = iPMSM_F28069M_B.Add_k[0] << 6U;
  iPMSM_F28069M_B.Q17perunitconversion[0] = Q17perunitconversion;

  /* DataTypeConversion: '<S165>/Data Type Conversion1' incorporates:
   *  ArithShift: '<S165>/Q17 per unit conversion'
   */
  Iab_fb_PU[0] = (real32_T)Q17perunitconversion * 7.62939453E-6F;

  /* ArithShift: '<S165>/Q17 per unit conversion' incorporates:
   *  Sum: '<S165>/Add'
   */
  Q17perunitconversion = iPMSM_F28069M_B.Add_k[1] << 6U;
  iPMSM_F28069M_B.Q17perunitconversion[1] = Q17perunitconversion;

  /* DataTypeConversion: '<S165>/Data Type Conversion1' incorporates:
   *  ArithShift: '<S165>/Q17 per unit conversion'
   */
  Iab_fb_PU[1] = (real32_T)Q17perunitconversion * 7.62939453E-6F;

  /* Outputs for Atomic SubSystem: '<S8>/Clarke Transform' */
  /* Sum: '<S15>/a_plus_2b' */
  iPMSM_F28069M_B.a_plus_2b = (Iab_fb_PU[0] + Iab_fb_PU[1]) + Iab_fb_PU[1];

  /* Gain: '<S15>/one_by_sqrt3' */
  iPMSM_F28069M_B.one_by_sqrt3 = 0.577350259F * iPMSM_F28069M_B.a_plus_2b;

  /* AlgorithmDescriptorDelegate generated from: '<S15>/a16' */
  iPMSM_F28069M_B.algDD_o1_g = Iab_fb_PU[0];

  /* AlgorithmDescriptorDelegate generated from: '<S15>/a16' */
  iPMSM_F28069M_B.algDD_o2_cx = iPMSM_F28069M_B.one_by_sqrt3;

  /* End of Outputs for SubSystem: '<S8>/Clarke Transform' */

  /* Switch: '<S27>/Switch1' incorporates:
   *  Constant: '<S27>/ChosenMethod'
   */
  iPMSM_F28069M_B.Switch1_f = 3U;

  /* RelationalOperator: '<S148>/Compare' incorporates:
   *  Constant: '<S148>/Constant'
   */
  iPMSM_F28069M_B.Compare = (iPMSM_F28069M_B.Switch < 0.0F);

  /* DataTypeConversion: '<S147>/Data Type Conversion' */
  iPMSM_F28069M_B.DataTypeConversion_a = iPMSM_F28069M_B.Compare;

  /* If: '<S147>/If' */
  if (iPMSM_F28069M_B.DataTypeConversion_a > 0U) {
    /* Outputs for IfAction SubSystem: '<S147>/If Action Subsystem' incorporates:
     *  ActionPort: '<S149>/Action Port'
     */
    iPMSM_F28_IfActionSubsystem(iPMSM_F28069M_B.Switch, &iPMSM_F28069M_B.Merge,
      &iPMSM_F28069M_B.IfActionSubsystem);

    /* End of Outputs for SubSystem: '<S147>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S147>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S150>/Action Port'
     */
    iPMSM_F2_IfActionSubsystem1(iPMSM_F28069M_B.Switch, &iPMSM_F28069M_B.Merge,
      &iPMSM_F28069M_B.IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S147>/If Action Subsystem1' */
  }

  /* End of If: '<S147>/If' */

  /* Gain: '<S20>/indexing' */
  iPMSM_F28069M_B.indexing = 800.0F * iPMSM_F28069M_B.Merge;

  /* DataTypeConversion: '<S20>/Get_Integer' */
  iPMSM_F28069M_B.Get_Integer = (uint16_T)iPMSM_F28069M_B.indexing;

  /* Sum: '<S20>/Sum' incorporates:
   *  Constant: '<S20>/offset'
   */
  Sum = iPMSM_F28069M_B.Get_Integer + 1UL;
  iPMSM_F28069M_B.Sum[0] = Sum;

  /* Selector: '<S20>/Lookup' incorporates:
   *  Constant: '<S20>/sine_table_values'
   */
  iPMSM_F28069M_B.Lookup[0] = iPMSM_F28069M_ConstP.pooled32[(int16_T)Sum];

  /* Sum: '<S20>/Sum' */
  Sum = iPMSM_F28069M_B.Get_Integer;
  iPMSM_F28069M_B.Sum[1] = Sum;

  /* Selector: '<S20>/Lookup' incorporates:
   *  Constant: '<S20>/sine_table_values'
   */
  iPMSM_F28069M_B.Lookup[1] = iPMSM_F28069M_ConstP.pooled32[(int16_T)Sum];

  /* Sum: '<S20>/Sum' incorporates:
   *  Constant: '<S20>/offset'
   */
  Sum = iPMSM_F28069M_B.Get_Integer + 201UL;
  iPMSM_F28069M_B.Sum[2] = Sum;

  /* Selector: '<S20>/Lookup' incorporates:
   *  Constant: '<S20>/sine_table_values'
   */
  iPMSM_F28069M_B.Lookup[2] = iPMSM_F28069M_ConstP.pooled32[(int16_T)Sum];

  /* Sum: '<S20>/Sum' incorporates:
   *  Constant: '<S20>/offset'
   */
  Sum = iPMSM_F28069M_B.Get_Integer + 200UL;
  iPMSM_F28069M_B.Sum[3] = Sum;

  /* Selector: '<S20>/Lookup' incorporates:
   *  Constant: '<S20>/sine_table_values'
   */
  iPMSM_F28069M_B.Lookup[3] = iPMSM_F28069M_ConstP.pooled32[(int16_T)Sum];

  /* Sum: '<S146>/Sum3' */
  iPMSM_F28069M_B.Sum3 = iPMSM_F28069M_B.Lookup[0] - iPMSM_F28069M_B.Lookup[1];

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  iPMSM_F28069M_B.DataTypeConversion1_m = iPMSM_F28069M_B.Get_Integer;

  /* Sum: '<S20>/Sum2' */
  iPMSM_F28069M_B.Sum2 = iPMSM_F28069M_B.indexing -
    iPMSM_F28069M_B.DataTypeConversion1_m;

  /* Product: '<S146>/Product' */
  iPMSM_F28069M_B.Product = iPMSM_F28069M_B.Sum3 * iPMSM_F28069M_B.Sum2;

  /* Sum: '<S146>/Sum4' */
  iPMSM_F28069M_B.Sum4 = iPMSM_F28069M_B.Product + iPMSM_F28069M_B.Lookup[1];

  /* Sum: '<S146>/Sum5' */
  iPMSM_F28069M_B.Sum5 = iPMSM_F28069M_B.Lookup[2] - iPMSM_F28069M_B.Lookup[3];

  /* Product: '<S146>/Product1' */
  iPMSM_F28069M_B.Product1 = iPMSM_F28069M_B.Sum5 * iPMSM_F28069M_B.Sum2;

  /* Sum: '<S146>/Sum6' */
  iPMSM_F28069M_B.Sum6 = iPMSM_F28069M_B.Product1 + iPMSM_F28069M_B.Lookup[3];

  /* Outputs for Atomic SubSystem: '<S8>/Park Transform' */
  /* Product: '<S19>/acos' */
  iPMSM_F28069M_B.acos_c = iPMSM_F28069M_B.algDD_o1_g * iPMSM_F28069M_B.Sum6;

  /* Product: '<S19>/bsin' */
  iPMSM_F28069M_B.bsin = iPMSM_F28069M_B.algDD_o2_cx * iPMSM_F28069M_B.Sum4;

  /* Sum: '<S19>/sum_Ds' */
  iPMSM_F28069M_B.sum_Ds = iPMSM_F28069M_B.acos_c + iPMSM_F28069M_B.bsin;

  /* Product: '<S19>/bcos' */
  iPMSM_F28069M_B.bcos = iPMSM_F28069M_B.algDD_o2_cx * iPMSM_F28069M_B.Sum6;

  /* Product: '<S19>/asin' */
  iPMSM_F28069M_B.asin_f = iPMSM_F28069M_B.algDD_o1_g * iPMSM_F28069M_B.Sum4;

  /* Sum: '<S19>/sum_Qs' */
  iPMSM_F28069M_B.sum_Qs = iPMSM_F28069M_B.bcos - iPMSM_F28069M_B.asin_f;

  /* Switch: '<S145>/Switch' */
  iPMSM_F28069M_B.Switch_bi[0] = iPMSM_F28069M_B.sum_Ds;
  iPMSM_F28069M_B.Switch_bi[1] = iPMSM_F28069M_B.sum_Qs;

  /* AlgorithmDescriptorDelegate generated from: '<S19>/a16' */
  iPMSM_F28069M_B.algDD_o1 = iPMSM_F28069M_B.Switch_bi[0];

  /* AlgorithmDescriptorDelegate generated from: '<S19>/a16' */
  iPMSM_F28069M_B.algDD_o2 = iPMSM_F28069M_B.Switch_bi[1];

  /* End of Outputs for SubSystem: '<S8>/Park Transform' */

  /* Sum: '<S24>/Sum' */
  iPMSM_F28069M_B.Sum_m = iPMSM_F28069M_B.RT2[1] - iPMSM_F28069M_B.algDD_o2;

  /* Product: '<S129>/PProd Out' incorporates:
   *  Constant: '<S24>/Kp'
   */
  iPMSM_F28069M_B.PProdOut = iPMSM_F28069M_B.Sum_m * 1.70112133F;

  /* DataStoreRead: '<S24>/Data Store Read1' */
  iPMSM_F28069M_B.DataStoreRead1_b = iPMSM_F28069M_DWork.EnClosedLoop;

  /* Logic: '<S24>/Logical Operator' */
  iPMSM_F28069M_B.LogicalOperator = !iPMSM_F28069M_B.DataStoreRead1_b;

  /* UnitDelay: '<S24>/Unit Delay' */
  iPMSM_F28069M_B.UnitDelay_p = iPMSM_F28069M_DWork.UnitDelay_DSTATE_l;

  /* DiscreteIntegrator: '<S124>/Integrator' */
  if (iPMSM_F28069M_DWork.Integrator_IC_LOADING != 0U) {
    iPMSM_F28069M_DWork.Integrator_DSTATE = iPMSM_F28069M_B.UnitDelay_p;
  }

  if (iPMSM_F28069M_B.LogicalOperator ||
      (iPMSM_F28069M_DWork.Integrator_PrevResetState != 0)) {
    iPMSM_F28069M_DWork.Integrator_DSTATE = iPMSM_F28069M_B.UnitDelay_p;
  }

  /* DiscreteIntegrator: '<S124>/Integrator' */
  iPMSM_F28069M_B.Integrator = iPMSM_F28069M_DWork.Integrator_DSTATE;

  /* Sum: '<S133>/Sum' */
  iPMSM_F28069M_B.Sum_a = iPMSM_F28069M_B.PProdOut + iPMSM_F28069M_B.Integrator;

  /* Switch: '<S24>/Switch' */
  if (iPMSM_F28069M_B.DataStoreRead1_b) {
    /* Saturate: '<S131>/Saturation' */
    u0 = iPMSM_F28069M_B.Sum_a;
    if (u0 > 1.0F) {
      /* Saturate: '<S131>/Saturation' */
      iPMSM_F28069M_B.Saturation = 1.0F;
    } else if (u0 < -1.0F) {
      /* Saturate: '<S131>/Saturation' */
      iPMSM_F28069M_B.Saturation = -1.0F;
    } else {
      /* Saturate: '<S131>/Saturation' */
      iPMSM_F28069M_B.Saturation = u0;
    }

    /* End of Saturate: '<S131>/Saturation' */

    /* Switch: '<S24>/Switch' */
    iPMSM_F28069M_B.Switch_j = iPMSM_F28069M_B.Saturation;
  } else {
    /* Switch: '<S24>/Switch' incorporates:
     *  Constant: '<S24>/Vq_OpenLoop'
     */
    iPMSM_F28069M_B.Switch_j = 0.0F;
  }

  /* End of Switch: '<S24>/Switch' */

  /* Sum: '<S23>/Sum' */
  iPMSM_F28069M_B.Sum_g = iPMSM_F28069M_B.RT2[0] - iPMSM_F28069M_B.algDD_o1;

  /* Product: '<S78>/PProd Out' incorporates:
   *  Constant: '<S23>/Kp'
   */
  iPMSM_F28069M_B.PProdOut_c = iPMSM_F28069M_B.Sum_g * 1.70112133F;

  /* DataStoreRead: '<S23>/Data Store Read1' */
  iPMSM_F28069M_B.DataStoreRead1_f = iPMSM_F28069M_DWork.EnClosedLoop;

  /* Logic: '<S23>/Logical Operator' */
  iPMSM_F28069M_B.LogicalOperator_e = !iPMSM_F28069M_B.DataStoreRead1_f;

  /* UnitDelay: '<S23>/Unit Delay' */
  iPMSM_F28069M_B.UnitDelay_i = iPMSM_F28069M_DWork.UnitDelay_DSTATE_l0;

  /* DiscreteIntegrator: '<S73>/Integrator' */
  if (iPMSM_F28069M_DWork.Integrator_IC_LOADING_p != 0U) {
    iPMSM_F28069M_DWork.Integrator_DSTATE_j = iPMSM_F28069M_B.UnitDelay_i;
  }

  if (iPMSM_F28069M_B.LogicalOperator_e ||
      (iPMSM_F28069M_DWork.Integrator_PrevResetState_f != 0)) {
    iPMSM_F28069M_DWork.Integrator_DSTATE_j = iPMSM_F28069M_B.UnitDelay_i;
  }

  /* DiscreteIntegrator: '<S73>/Integrator' */
  iPMSM_F28069M_B.Integrator_i = iPMSM_F28069M_DWork.Integrator_DSTATE_j;

  /* Sum: '<S82>/Sum' */
  iPMSM_F28069M_B.Sum_n = iPMSM_F28069M_B.PProdOut_c +
    iPMSM_F28069M_B.Integrator_i;

  /* Switch: '<S23>/Switch' */
  if (iPMSM_F28069M_B.DataStoreRead1_f) {
    /* Saturate: '<S80>/Saturation' */
    u0 = iPMSM_F28069M_B.Sum_n;
    if (u0 > 1.0F) {
      /* Saturate: '<S80>/Saturation' */
      iPMSM_F28069M_B.Saturation_f = 1.0F;
    } else if (u0 < -1.0F) {
      /* Saturate: '<S80>/Saturation' */
      iPMSM_F28069M_B.Saturation_f = -1.0F;
    } else {
      /* Saturate: '<S80>/Saturation' */
      iPMSM_F28069M_B.Saturation_f = u0;
    }

    /* End of Saturate: '<S80>/Saturation' */

    /* Switch: '<S23>/Switch' */
    iPMSM_F28069M_B.Switch_d = iPMSM_F28069M_B.Saturation_f;
  } else {
    /* DataStoreRead: '<S23>/Vd_OpenLoop' */
    iPMSM_F28069M_B.Vd_OpenLoop = iPMSM_F28069M_DWork.Speed_ref;

    /* Abs: '<S23>/Abs' */
    iPMSM_F28069M_B.Abs_i = fabsf(iPMSM_F28069M_B.Vd_OpenLoop);

    /* Saturate: '<S23>/Saturation' */
    u0 = iPMSM_F28069M_B.Abs_i;
    if (u0 > 0.5F) {
      /* Saturate: '<S23>/Saturation' */
      iPMSM_F28069M_B.Saturation_a = 0.5F;
    } else if (u0 < 0.15F) {
      /* Saturate: '<S23>/Saturation' */
      iPMSM_F28069M_B.Saturation_a = 0.15F;
    } else {
      /* Saturate: '<S23>/Saturation' */
      iPMSM_F28069M_B.Saturation_a = u0;
    }

    /* End of Saturate: '<S23>/Saturation' */

    /* Switch: '<S23>/Switch' */
    iPMSM_F28069M_B.Switch_d = iPMSM_F28069M_B.Saturation_a;
  }

  /* End of Switch: '<S23>/Switch' */

  /* Switch: '<S27>/Switch' incorporates:
   *  Constant: '<S27>/Constant3'
   */
  iPMSM_F28069M_B.Switch_jv = 1.0F;

  /* Product: '<S27>/Product' */
  iPMSM_F28069M_B.Product_l = 1.0F;

  /* Product: '<S28>/Product' */
  iPMSM_F28069M_B.Product_o = iPMSM_F28069M_B.Switch_d *
    iPMSM_F28069M_B.Switch_d;

  /* Product: '<S28>/Product1' */
  iPMSM_F28069M_B.Product1_a = iPMSM_F28069M_B.Switch_j *
    iPMSM_F28069M_B.Switch_j;

  /* Sum: '<S28>/Sum1' */
  iPMSM_F28069M_B.Sum1 = iPMSM_F28069M_B.Product_o + iPMSM_F28069M_B.Product1_a;

  /* Outputs for IfAction SubSystem: '<S22>/D-Q Equivalence' incorporates:
   *  ActionPort: '<S25>/Action Port'
   */
  /* If: '<S22>/If' incorporates:
   *  DataTypeConversion: '<S25>/Data Type Conversion'
   *  RelationalOperator: '<S25>/Relational Operator'
   */
  iPMSM_F28069M_B.RelationalOperator_l = (iPMSM_F28069M_B.Sum1 > 1.0F);
  iPMSM_F28069M_B.DataTypeConversion_k = iPMSM_F28069M_B.RelationalOperator_l;

  /* If: '<S25>/If' incorporates:
   *  If: '<S22>/If'
   */
  if (iPMSM_F28069M_B.DataTypeConversion_k != 0U) {
    /* Outputs for IfAction SubSystem: '<S25>/Limiter' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */
    /* Product: '<S29>/Product' */
    iPMSM_F28069M_B.Product_ch[0] = iPMSM_F28069M_B.Switch_d;
    iPMSM_F28069M_B.Product_ch[1] = iPMSM_F28069M_B.Switch_j;

    /* Sqrt: '<S29>/Square Root' */
    iPMSM_F28069M_B.SquareRoot = (real32_T)sqrt(iPMSM_F28069M_B.Sum1);

    /* Switch: '<S29>/Switch' */
    if (iPMSM_F28069M_B.SquareRoot != 0.0F) {
      /* Switch: '<S29>/Switch' */
      iPMSM_F28069M_B.Switch_os = iPMSM_F28069M_B.SquareRoot;
    } else {
      /* Switch: '<S29>/Switch' incorporates:
       *  Constant: '<S29>/Constant'
       */
      iPMSM_F28069M_B.Switch_os = 1.0F;
    }

    /* End of Switch: '<S29>/Switch' */

    /* Product: '<S29>/Reciprocal' */
    iPMSM_F28069M_B.Reciprocal = 1.0F / iPMSM_F28069M_B.Switch_os;

    /* Merge: '<S22>/Merge' incorporates:
     *  Product: '<S29>/Product1'
     */
    iPMSM_F28069M_B.Merge_m[0] = iPMSM_F28069M_B.Product_ch[0] *
      iPMSM_F28069M_B.Reciprocal;
    iPMSM_F28069M_B.Merge_m[1] = iPMSM_F28069M_B.Product_ch[1] *
      iPMSM_F28069M_B.Reciprocal;

    /* End of Outputs for SubSystem: '<S25>/Limiter' */
  } else {
    /* Outputs for IfAction SubSystem: '<S25>/Passthrough' incorporates:
     *  ActionPort: '<S30>/Action Port'
     */
    /* Merge: '<S22>/Merge' incorporates:
     *  SignalConversion generated from: '<S30>/dqRef'
     */
    iPMSM_F28069M_B.Merge_m[0] = iPMSM_F28069M_B.Switch_d;
    iPMSM_F28069M_B.Merge_m[1] = iPMSM_F28069M_B.Switch_j;

    /* End of Outputs for SubSystem: '<S25>/Passthrough' */
  }

  /* End of If: '<S25>/If' */
  /* End of Outputs for SubSystem: '<S22>/D-Q Equivalence' */

  /* DeadZone: '<S66>/DeadZone' */
  if (iPMSM_F28069M_B.Sum_n > 1.0F) {
    /* DeadZone: '<S66>/DeadZone' */
    iPMSM_F28069M_B.DeadZone = iPMSM_F28069M_B.Sum_n - 1.0F;
  } else if (iPMSM_F28069M_B.Sum_n >= -1.0F) {
    /* DeadZone: '<S66>/DeadZone' */
    iPMSM_F28069M_B.DeadZone = 0.0F;
  } else {
    /* DeadZone: '<S66>/DeadZone' */
    iPMSM_F28069M_B.DeadZone = iPMSM_F28069M_B.Sum_n - -1.0F;
  }

  /* End of DeadZone: '<S66>/DeadZone' */

  /* RelationalOperator: '<S64>/Relational Operator' incorporates:
   *  Constant: '<S64>/Clamping_zero'
   */
  iPMSM_F28069M_B.RelationalOperator = (iPMSM_F28069M_B.DeadZone != 0.0F);

  /* RelationalOperator: '<S64>/fix for DT propagation issue' incorporates:
   *  Constant: '<S64>/Clamping_zero'
   */
  iPMSM_F28069M_B.fixforDTpropagationissue = (iPMSM_F28069M_B.DeadZone > 0.0F);

  /* Switch: '<S64>/Switch1' */
  if (iPMSM_F28069M_B.fixforDTpropagationissue) {
    /* Switch: '<S64>/Switch1' incorporates:
     *  Constant: '<S64>/Constant'
     */
    iPMSM_F28069M_B.Switch1_l = 1;
  } else {
    /* Switch: '<S64>/Switch1' incorporates:
     *  Constant: '<S64>/Constant2'
     */
    iPMSM_F28069M_B.Switch1_l = -1;
  }

  /* End of Switch: '<S64>/Switch1' */

  /* Product: '<S70>/IProd Out' incorporates:
   *  Constant: '<S23>/Ki'
   */
  iPMSM_F28069M_B.IProdOut = iPMSM_F28069M_B.Sum_g * 0.154943794F;

  /* RelationalOperator: '<S64>/fix for DT propagation issue1' incorporates:
   *  Constant: '<S64>/Clamping_zero'
   */
  iPMSM_F28069M_B.fixforDTpropagationissue1 = (iPMSM_F28069M_B.IProdOut > 0.0F);

  /* Switch: '<S64>/Switch2' */
  if (iPMSM_F28069M_B.fixforDTpropagationissue1) {
    /* Switch: '<S64>/Switch2' incorporates:
     *  Constant: '<S64>/Constant3'
     */
    iPMSM_F28069M_B.Switch2_i = 1;
  } else {
    /* Switch: '<S64>/Switch2' incorporates:
     *  Constant: '<S64>/Constant4'
     */
    iPMSM_F28069M_B.Switch2_i = -1;
  }

  /* End of Switch: '<S64>/Switch2' */

  /* RelationalOperator: '<S64>/Equal1' incorporates:
   *  Switch: '<S64>/Switch1'
   *  Switch: '<S64>/Switch2'
   */
  iPMSM_F28069M_B.Equal1 = (iPMSM_F28069M_B.Switch1_l ==
    iPMSM_F28069M_B.Switch2_i);

  /* Logic: '<S64>/AND3' */
  iPMSM_F28069M_B.AND3 = (iPMSM_F28069M_B.RelationalOperator &&
    iPMSM_F28069M_B.Equal1);

  /* Switch: '<S64>/Switch' */
  if (iPMSM_F28069M_B.AND3) {
    /* Switch: '<S64>/Switch' incorporates:
     *  Constant: '<S64>/Constant1'
     */
    iPMSM_F28069M_B.Switch_o = 0.0F;
  } else {
    /* Switch: '<S64>/Switch' */
    iPMSM_F28069M_B.Switch_o = iPMSM_F28069M_B.IProdOut;
  }

  /* End of Switch: '<S64>/Switch' */

  /* DeadZone: '<S117>/DeadZone' */
  if (iPMSM_F28069M_B.Sum_a > 1.0F) {
    /* DeadZone: '<S117>/DeadZone' */
    iPMSM_F28069M_B.DeadZone_n = iPMSM_F28069M_B.Sum_a - 1.0F;
  } else if (iPMSM_F28069M_B.Sum_a >= -1.0F) {
    /* DeadZone: '<S117>/DeadZone' */
    iPMSM_F28069M_B.DeadZone_n = 0.0F;
  } else {
    /* DeadZone: '<S117>/DeadZone' */
    iPMSM_F28069M_B.DeadZone_n = iPMSM_F28069M_B.Sum_a - -1.0F;
  }

  /* End of DeadZone: '<S117>/DeadZone' */

  /* RelationalOperator: '<S115>/Relational Operator' incorporates:
   *  Constant: '<S115>/Clamping_zero'
   */
  iPMSM_F28069M_B.RelationalOperator_i = (iPMSM_F28069M_B.DeadZone_n != 0.0F);

  /* RelationalOperator: '<S115>/fix for DT propagation issue' incorporates:
   *  Constant: '<S115>/Clamping_zero'
   */
  iPMSM_F28069M_B.fixforDTpropagationissue_f = (iPMSM_F28069M_B.DeadZone_n >
    0.0F);

  /* Switch: '<S115>/Switch1' */
  if (iPMSM_F28069M_B.fixforDTpropagationissue_f) {
    /* Switch: '<S115>/Switch1' incorporates:
     *  Constant: '<S115>/Constant'
     */
    iPMSM_F28069M_B.Switch1_cm = 1;
  } else {
    /* Switch: '<S115>/Switch1' incorporates:
     *  Constant: '<S115>/Constant2'
     */
    iPMSM_F28069M_B.Switch1_cm = -1;
  }

  /* End of Switch: '<S115>/Switch1' */

  /* Product: '<S121>/IProd Out' incorporates:
   *  Constant: '<S24>/Ki'
   */
  iPMSM_F28069M_B.IProdOut_n = iPMSM_F28069M_B.Sum_m * 0.154943794F;

  /* RelationalOperator: '<S115>/fix for DT propagation issue1' incorporates:
   *  Constant: '<S115>/Clamping_zero'
   */
  iPMSM_F28069M_B.fixforDTpropagationissue1_g = (iPMSM_F28069M_B.IProdOut_n >
    0.0F);

  /* Switch: '<S115>/Switch2' */
  if (iPMSM_F28069M_B.fixforDTpropagationissue1_g) {
    /* Switch: '<S115>/Switch2' incorporates:
     *  Constant: '<S115>/Constant3'
     */
    iPMSM_F28069M_B.Switch2_c = 1;
  } else {
    /* Switch: '<S115>/Switch2' incorporates:
     *  Constant: '<S115>/Constant4'
     */
    iPMSM_F28069M_B.Switch2_c = -1;
  }

  /* End of Switch: '<S115>/Switch2' */

  /* RelationalOperator: '<S115>/Equal1' incorporates:
   *  Switch: '<S115>/Switch1'
   *  Switch: '<S115>/Switch2'
   */
  iPMSM_F28069M_B.Equal1_m = (iPMSM_F28069M_B.Switch1_cm ==
    iPMSM_F28069M_B.Switch2_c);

  /* Logic: '<S115>/AND3' */
  iPMSM_F28069M_B.AND3_d = (iPMSM_F28069M_B.RelationalOperator_i &&
    iPMSM_F28069M_B.Equal1_m);

  /* Switch: '<S115>/Switch' */
  if (iPMSM_F28069M_B.AND3_d) {
    /* Switch: '<S115>/Switch' incorporates:
     *  Constant: '<S115>/Constant1'
     */
    iPMSM_F28069M_B.Switch_l = 0.0F;
  } else {
    /* Switch: '<S115>/Switch' */
    iPMSM_F28069M_B.Switch_l = iPMSM_F28069M_B.IProdOut_n;
  }

  /* End of Switch: '<S115>/Switch' */

  /* Outputs for Atomic SubSystem: '<S8>/Inverse Park Transform' */
  /* Product: '<S17>/qcos' */
  iPMSM_F28069M_B.qcos = iPMSM_F28069M_B.Merge_m[1] * iPMSM_F28069M_B.Sum6;

  /* Product: '<S17>/dsin' */
  iPMSM_F28069M_B.dsin = iPMSM_F28069M_B.Merge_m[0] * iPMSM_F28069M_B.Sum4;

  /* Sum: '<S17>/sum_beta' */
  iPMSM_F28069M_B.sum_beta = iPMSM_F28069M_B.qcos + iPMSM_F28069M_B.dsin;

  /* Product: '<S17>/dcos' */
  iPMSM_F28069M_B.dcos = iPMSM_F28069M_B.Merge_m[0] * iPMSM_F28069M_B.Sum6;

  /* Product: '<S17>/qsin' */
  iPMSM_F28069M_B.qsin = iPMSM_F28069M_B.Merge_m[1] * iPMSM_F28069M_B.Sum4;

  /* Sum: '<S17>/sum_alpha' */
  iPMSM_F28069M_B.sum_alpha = iPMSM_F28069M_B.dcos - iPMSM_F28069M_B.qsin;

  /* Switch: '<S141>/Switch' */
  iPMSM_F28069M_B.Switch_df[0] = iPMSM_F28069M_B.sum_alpha;
  iPMSM_F28069M_B.Switch_df[1] = iPMSM_F28069M_B.sum_beta;

  /* AlgorithmDescriptorDelegate generated from: '<S17>/a16' */
  iPMSM_F28069M_B.algDD_o1_o = iPMSM_F28069M_B.Switch_df[0];

  /* AlgorithmDescriptorDelegate generated from: '<S17>/a16' */
  iPMSM_F28069M_B.algDD_o2_c = iPMSM_F28069M_B.Switch_df[1];

  /* End of Outputs for SubSystem: '<S8>/Inverse Park Transform' */

  /* UnitDelay: '<S157>/Output' */
  iPMSM_F28069M_B.Output = iPMSM_F28069M_DWork.Output_DSTATE;

  /* DataTypeConversion: '<S159>/Data Type Conversion' */
  iPMSM_F28069M_B.DataTypeConversion_l[0] = (int16_T)(iPMSM_F28069M_B.Merge_k[1]
    * 4096.0F);
  iPMSM_F28069M_B.DataTypeConversion_l[1] = (int16_T)(Iab_fb_PU[0] * 4096.0F);

  /* DataTypeConversion: '<S159>/Data Type Conversion3' incorporates:
   *  DataTypeConversion: '<S159>/Data Type Conversion'
   */
  iPMSM_F28069M_B.DataTypeConversion3[0] = (uint16_T)
    iPMSM_F28069M_B.DataTypeConversion_l[0];
  iPMSM_F28069M_B.DataTypeConversion3[1] = (uint16_T)
    iPMSM_F28069M_B.DataTypeConversion_l[1];

  /* If: '<S9>/If' */
  if (iPMSM_F28069M_B.Output == 0U) {
    /* Outputs for IfAction SubSystem: '<S9>/Start' incorporates:
     *  ActionPort: '<S161>/Action Port'
     */
    /* Merge: '<S9>/Merge' incorporates:
     *  Constant: '<S161>/End'
     *  SignalConversion generated from: '<S161>/Data_out'
     */
    iPMSM_F28069M_B.SCI_Tx_Data[0] = 21331U;

    /* SignalConversion generated from: '<S161>/Data' */
    Data = iPMSM_F28069M_B.DataTypeConversion3[0];

    /* End of Outputs for SubSystem: '<S9>/Start' */
    iPMSM_F28069M_B.Data_fw[0] = Data;

    /* Outputs for IfAction SubSystem: '<S9>/Start' incorporates:
     *  ActionPort: '<S161>/Action Port'
     */
    /* Merge: '<S9>/Merge' incorporates:
     *  SignalConversion generated from: '<S161>/Data_out'
     */
    iPMSM_F28069M_B.SCI_Tx_Data[1] = Data;

    /* SignalConversion generated from: '<S161>/Data' */
    Data = iPMSM_F28069M_B.DataTypeConversion3[1];

    /* End of Outputs for SubSystem: '<S9>/Start' */
    iPMSM_F28069M_B.Data_fw[1] = Data;

    /* Outputs for IfAction SubSystem: '<S9>/Start' incorporates:
     *  ActionPort: '<S161>/Action Port'
     */
    /* Merge: '<S9>/Merge' incorporates:
     *  SignalConversion generated from: '<S161>/Data_out'
     */
    iPMSM_F28069M_B.SCI_Tx_Data[2] = Data;

    /* Merge: '<S9>/Merge1' incorporates:
     *  Bias: '<S161>/Bias'
     */
    iPMSM_F28069M_B.SCI_Tx_Iteration = iPMSM_F28069M_ConstB.Width + 1U;

    /* End of Outputs for SubSystem: '<S9>/Start' */
  } else if (iPMSM_F28069M_B.Output == 599U) {
    /* Outputs for IfAction SubSystem: '<S9>/End' incorporates:
     *  ActionPort: '<S160>/Action Port'
     */
    /* SignalConversion generated from: '<S160>/Data' */
    Data = iPMSM_F28069M_B.DataTypeConversion3[0];

    /* End of Outputs for SubSystem: '<S9>/End' */
    iPMSM_F28069M_B.Data_f[0] = Data;

    /* Outputs for IfAction SubSystem: '<S9>/End' incorporates:
     *  ActionPort: '<S160>/Action Port'
     */
    /* Merge: '<S9>/Merge' incorporates:
     *  SignalConversion generated from: '<S160>/Data_out'
     */
    iPMSM_F28069M_B.SCI_Tx_Data[0] = Data;

    /* SignalConversion generated from: '<S160>/Data' */
    Data = iPMSM_F28069M_B.DataTypeConversion3[1];

    /* End of Outputs for SubSystem: '<S9>/End' */
    iPMSM_F28069M_B.Data_f[1] = Data;

    /* Outputs for IfAction SubSystem: '<S9>/End' incorporates:
     *  ActionPort: '<S160>/Action Port'
     */
    /* Merge: '<S9>/Merge' incorporates:
     *  Constant: '<S160>/Start'
     *  SignalConversion generated from: '<S160>/Data_out'
     */
    iPMSM_F28069M_B.SCI_Tx_Data[1] = Data;
    iPMSM_F28069M_B.SCI_Tx_Data[2] = 17733U;

    /* Merge: '<S9>/Merge1' incorporates:
     *  Bias: '<S160>/Bias'
     */
    iPMSM_F28069M_B.SCI_Tx_Iteration = iPMSM_F28069M_ConstB.Width + 1U;

    /* End of Outputs for SubSystem: '<S9>/End' */
  } else {
    /* Outputs for IfAction SubSystem: '<S9>/Data' incorporates:
     *  ActionPort: '<S158>/Action Port'
     */
    /* SignalConversion generated from: '<S158>/Data' */
    Data = iPMSM_F28069M_B.DataTypeConversion3[0];

    /* End of Outputs for SubSystem: '<S9>/Data' */
    iPMSM_F28069M_B.Data[0] = Data;

    /* Outputs for IfAction SubSystem: '<S9>/Data' incorporates:
     *  ActionPort: '<S158>/Action Port'
     */
    /* Merge: '<S9>/Merge' incorporates:
     *  SignalConversion generated from: '<S158>/Data_out'
     */
    iPMSM_F28069M_B.SCI_Tx_Data[0] = Data;

    /* SignalConversion generated from: '<S158>/Data' */
    Data = iPMSM_F28069M_B.DataTypeConversion3[1];

    /* End of Outputs for SubSystem: '<S9>/Data' */
    iPMSM_F28069M_B.Data[1] = Data;

    /* Outputs for IfAction SubSystem: '<S9>/Data' incorporates:
     *  ActionPort: '<S158>/Action Port'
     */
    /* Merge: '<S9>/Merge' incorporates:
     *  Constant: '<S158>/Start'
     *  SignalConversion generated from: '<S158>/Data_out'
     */
    iPMSM_F28069M_B.SCI_Tx_Data[1] = Data;
    iPMSM_F28069M_B.SCI_Tx_Data[2] = 0U;

    /* Merge: '<S9>/Merge1' incorporates:
     *  SignalConversion generated from: '<S158>/Data_width'
     */
    iPMSM_F28069M_B.SCI_Tx_Iteration = iPMSM_F28069M_ConstB.Width;

    /* End of Outputs for SubSystem: '<S9>/Data' */
  }

  /* End of If: '<S9>/If' */

  /* Outputs for Iterator SubSystem: '<S365>/CodeGeneration' incorporates:
   *  WhileIterator: '<S366>/While Iterator'
   */
  s366_iter = 1;
  do {
    iPMSM_F28069M_B.WhileIterator = s366_iter;
    iPMSM_F28069M_B.IndexVector =
      iPMSM_F28069M_B.SCI_Tx_Data[iPMSM_F28069M_B.WhileIterator - 1];

    {
      if (checkSCITransmitInProgressA != 1U) {
        checkSCITransmitInProgressA = 1U;
        int16_T errFlgHeader = NOERROR;
        int16_T errFlgData = NOERROR;
        int16_T errFlgTail = NOERROR;
        errFlgData = scia_xmit((unsigned char*)&iPMSM_F28069M_B.IndexVector, 2,
          2);
        checkSCITransmitInProgressA = 0U;
      }
    }

    iPMSM_F28069M_B.Add_m = iPMSM_F28069M_B.SCI_Tx_Iteration - (uint16_T)
      iPMSM_F28069M_B.WhileIterator;
    s366_iter++;
  } while (iPMSM_F28069M_B.Add_m != 0U);

  /* End of Outputs for SubSystem: '<S365>/CodeGeneration' */

  /* Sum: '<S162>/FixPt Sum1' incorporates:
   *  Constant: '<S162>/FixPt Constant'
   */
  iPMSM_F28069M_B.FixPtSum1 = iPMSM_F28069M_B.Output + 1U;

  /* Switch: '<S163>/FixPt Switch' */
  if (iPMSM_F28069M_B.FixPtSum1 > 599U) {
    /* Switch: '<S163>/FixPt Switch' incorporates:
     *  Constant: '<S163>/Constant'
     */
    iPMSM_F28069M_B.FixPtSwitch = 0U;
  } else {
    /* Switch: '<S163>/FixPt Switch' */
    iPMSM_F28069M_B.FixPtSwitch = iPMSM_F28069M_B.FixPtSum1;
  }

  /* End of Switch: '<S163>/FixPt Switch' */

  /* DataStoreRead: '<S13>/Enable' */
  iPMSM_F28069M_B.Enable = iPMSM_F28069M_DWork.Enable;

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  iPMSM_F28069M_B.DataTypeConversion = iPMSM_F28069M_B.Enable;

  /* S-Function (c280xgpio_do): '<S364>/Digital Output' */
  {
    if (iPMSM_F28069M_B.DataTypeConversion) {
      GpioDataRegs.GPBSET.bit.GPIO50 = 1U;
    } else {
      GpioDataRegs.GPBCLEAR.bit.GPIO50 = 1U;
    }
  }

  /* Switch: '<S364>/Switch1' */
  if (iPMSM_F28069M_B.DataTypeConversion >= 0.5F) {
    /* Gain: '<S156>/sqrt3_by_two' */
    iPMSM_F28069M_B.sqrt3_by_two = 0.866025388F * iPMSM_F28069M_B.algDD_o2_c;

    /* Gain: '<S156>/one_by_two' */
    iPMSM_F28069M_B.one_by_two = 0.5F * iPMSM_F28069M_B.algDD_o1_o;

    /* Sum: '<S156>/add_c' */
    iPMSM_F28069M_B.add_c = (0.0F - iPMSM_F28069M_B.one_by_two) -
      iPMSM_F28069M_B.sqrt3_by_two;

    /* Sum: '<S156>/add_b' */
    iPMSM_F28069M_B.add_b = iPMSM_F28069M_B.sqrt3_by_two -
      iPMSM_F28069M_B.one_by_two;

    /* MinMax: '<S154>/Min' */
    u0 = iPMSM_F28069M_B.algDD_o1_o;
    Bias = iPMSM_F28069M_B.add_b;
    if ((u0 <= Bias) || rtIsNaNF(Bias)) {
      Bias = u0;
    }

    u0 = iPMSM_F28069M_B.add_c;
    if ((!(Bias <= u0)) && (!rtIsNaNF(u0))) {
      Bias = u0;
    }

    /* MinMax: '<S154>/Min' */
    iPMSM_F28069M_B.Min = Bias;

    /* MinMax: '<S154>/Max' */
    u0 = iPMSM_F28069M_B.algDD_o1_o;
    Bias = iPMSM_F28069M_B.add_b;
    if ((u0 >= Bias) || rtIsNaNF(Bias)) {
      Bias = u0;
    }

    u0 = iPMSM_F28069M_B.add_c;
    if ((!(Bias >= u0)) && (!rtIsNaNF(u0))) {
      Bias = u0;
    }

    /* MinMax: '<S154>/Max' */
    iPMSM_F28069M_B.Max = Bias;

    /* Sum: '<S154>/Add' */
    iPMSM_F28069M_B.Add = iPMSM_F28069M_B.Max + iPMSM_F28069M_B.Min;

    /* Gain: '<S154>/one_by_two' */
    iPMSM_F28069M_B.one_by_two_d = -0.5F * iPMSM_F28069M_B.Add;

    /* Sum: '<S153>/Add3' */
    iPMSM_F28069M_B.Add3 = iPMSM_F28069M_B.algDD_o1_o +
      iPMSM_F28069M_B.one_by_two_d;

    /* Sum: '<S153>/Add2' */
    iPMSM_F28069M_B.Add2 = iPMSM_F28069M_B.one_by_two_d + iPMSM_F28069M_B.add_c;

    /* Sum: '<S153>/Add1' */
    iPMSM_F28069M_B.Add1 = iPMSM_F28069M_B.add_b + iPMSM_F28069M_B.one_by_two_d;

    /* Gain: '<S153>/Gain' */
    iPMSM_F28069M_B.Gain_c[0] = 1.15470052F * iPMSM_F28069M_B.Add3;
    iPMSM_F28069M_B.Gain_c[1] = 1.15470052F * iPMSM_F28069M_B.Add1;
    iPMSM_F28069M_B.Gain_c[2] = 1.15470052F * iPMSM_F28069M_B.Add2;

    /* Gain: '<S13>/Gain' */
    Bias = 0.5F * iPMSM_F28069M_B.Gain_c[0];
    iPMSM_F28069M_B.Gain_c1[0] = Bias;

    /* Sum: '<S13>/Sum' incorporates:
     *  Constant: '<S13>/Constant'
     */
    Bias += 0.5F;
    iPMSM_F28069M_B.PWM_Duty_Cycles[0] = Bias;

    /* Gain: '<S364>/Scale_to_PWM_Counter_PRD' */
    Data = (uint16_T)(2250.0F * Bias);
    iPMSM_F28069M_B.Scale_to_PWM_Counter_PRD[0] = Data;

    /* Switch: '<S364>/Switch1' */
    iPMSM_F28069M_B.Switch1_c[0] = Data;

    /* Gain: '<S13>/Gain' */
    Bias = 0.5F * iPMSM_F28069M_B.Gain_c[1];
    iPMSM_F28069M_B.Gain_c1[1] = Bias;

    /* Sum: '<S13>/Sum' incorporates:
     *  Constant: '<S13>/Constant'
     */
    Bias += 0.5F;
    iPMSM_F28069M_B.PWM_Duty_Cycles[1] = Bias;

    /* Gain: '<S364>/Scale_to_PWM_Counter_PRD' */
    Data = (uint16_T)(2250.0F * Bias);
    iPMSM_F28069M_B.Scale_to_PWM_Counter_PRD[1] = Data;

    /* Switch: '<S364>/Switch1' */
    iPMSM_F28069M_B.Switch1_c[1] = Data;

    /* Gain: '<S13>/Gain' */
    Bias = 0.5F * iPMSM_F28069M_B.Gain_c[2];
    iPMSM_F28069M_B.Gain_c1[2] = Bias;

    /* Sum: '<S13>/Sum' incorporates:
     *  Constant: '<S13>/Constant'
     */
    Bias += 0.5F;
    iPMSM_F28069M_B.PWM_Duty_Cycles[2] = Bias;

    /* Gain: '<S364>/Scale_to_PWM_Counter_PRD' */
    Data = (uint16_T)(2250.0F * Bias);
    iPMSM_F28069M_B.Scale_to_PWM_Counter_PRD[2] = Data;

    /* Switch: '<S364>/Switch1' */
    iPMSM_F28069M_B.Switch1_c[2] = Data;
  } else {
    /* Switch: '<S364>/Switch1' incorporates:
     *  Constant: '<S364>/stop'
     */
    iPMSM_F28069M_B.Switch1_c[0] = 0U;
    iPMSM_F28069M_B.Switch1_c[1] = 0U;
    iPMSM_F28069M_B.Switch1_c[2] = 0U;
  }

  /* End of Switch: '<S364>/Switch1' */

  /* S-Function (c2802xpwm): '<S364>/ePWM1' */

  /*-- Update CMPA value for ePWM1 --*/
  {
    EPwm1Regs.CMPA.half.CMPA = (uint16_T)(iPMSM_F28069M_B.Switch1_c[0]);
  }

  /* S-Function (c2802xpwm): '<S364>/ePWM2' */

  /*-- Update CMPA value for ePWM2 --*/
  {
    EPwm2Regs.CMPA.half.CMPA = (uint16_T)(iPMSM_F28069M_B.Switch1_c[1]);
  }

  /* S-Function (c2802xpwm): '<S364>/ePWM3' */

  /*-- Update CMPA value for ePWM3 --*/
  {
    EPwm3Regs.CMPA.half.CMPA = (uint16_T)(iPMSM_F28069M_B.Switch1_c[2]);
  }

  /* SignalConversion generated from: '<S1>/Speed_meas_PU' */
  iPMSM_F28069M_B.Speed_fb_PU = iPMSM_F28069M_B.Merge_k[1];

  /* SignalConversion generated from: '<S1>/Delay5' */
  iPMSM_F28069M_B.TmpSignalConversionAtDelay5Inpo[0] =
    iPMSM_F28069M_B.algDD_o1_o;
  iPMSM_F28069M_B.TmpSignalConversionAtDelay5Inpo[1] =
    iPMSM_F28069M_B.algDD_o2_c;
  iPMSM_F28069M_B.TmpSignalConversionAtDelay5Inpo[2] =
    iPMSM_F28069M_B.algDD_o1_g;
  iPMSM_F28069M_B.TmpSignalConversionAtDelay5Inpo[3] =
    iPMSM_F28069M_B.algDD_o2_cx;

  /* Update for UnitDelay: '<S142>/Unit Delay' */
  iPMSM_F28069M_DWork.UnitDelay_DSTATE = iPMSM_F28069M_B.Accumulate.Add1;

  /* Update for Delay: '<S1>/Delay5' */
  iPMSM_F28069M_DWork.Delay5_DSTATE[0] =
    iPMSM_F28069M_B.TmpSignalConversionAtDelay5Inpo[0];
  iPMSM_F28069M_DWork.Delay5_DSTATE[1] =
    iPMSM_F28069M_B.TmpSignalConversionAtDelay5Inpo[1];
  iPMSM_F28069M_DWork.Delay5_DSTATE[2] =
    iPMSM_F28069M_B.TmpSignalConversionAtDelay5Inpo[2];
  iPMSM_F28069M_DWork.Delay5_DSTATE[3] =
    iPMSM_F28069M_B.TmpSignalConversionAtDelay5Inpo[3];

  /* Update for UnitDelay: '<S24>/Unit Delay' */
  iPMSM_F28069M_DWork.UnitDelay_DSTATE_l = iPMSM_F28069M_B.Switch_j;

  /* Update for DiscreteIntegrator: '<S124>/Integrator' */
  iPMSM_F28069M_DWork.Integrator_IC_LOADING = 0U;
  iPMSM_F28069M_DWork.Integrator_DSTATE += iPMSM_F28069M_B.Switch_l;
  iPMSM_F28069M_DWork.Integrator_PrevResetState = (int16_T)
    iPMSM_F28069M_B.LogicalOperator;

  /* Update for UnitDelay: '<S23>/Unit Delay' */
  iPMSM_F28069M_DWork.UnitDelay_DSTATE_l0 = iPMSM_F28069M_B.Switch_d;

  /* Update for DiscreteIntegrator: '<S73>/Integrator' */
  iPMSM_F28069M_DWork.Integrator_IC_LOADING_p = 0U;
  iPMSM_F28069M_DWork.Integrator_DSTATE_j += iPMSM_F28069M_B.Switch_o;
  iPMSM_F28069M_DWork.Integrator_PrevResetState_f = (int16_T)
    iPMSM_F28069M_B.LogicalOperator_e;

  /* Update for UnitDelay: '<S157>/Output' */
  iPMSM_F28069M_DWork.Output_DSTATE = iPMSM_F28069M_B.FixPtSwitch;
}

/* System initialize for atomic system: */
void iPMS_SPIMasterTransfer_Init(rtDW_SPIMasterTransfer_iPMSM_F2 *localDW)
{
  MW_SPI_FirstBitTransfer_Type MsbFirstTransferLoc;
  MW_SPI_Mode_type ClockModeValue;
  uint32_T SPIPinsLoc;
  uint32_T SSPinNameLoc;
  codertarget_tic2000_blocks_SPIM *b_obj;
  codertarget_tic2000_blocks_SPIM *obj;
  codertarget_tic2000_blocks_SPIM *obj_0;

  /* Start for MATLABSystem: '<S377>/SPI Master Transfer' */
  localDW->obj.matlabCodegenIsDeleted = true;
  b_obj = &localDW->obj;
  b_obj->isInitialized = 0L;
  b_obj->matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  b_obj = &localDW->obj;
  b_obj->isSetupComplete = false;
  b_obj->isInitialized = 1L;
  obj = b_obj;
  obj_0 = obj;
  SSPinNameLoc = MW_UNDEFINED_VALUE;
  SPIPinsLoc = MW_UNDEFINED_VALUE;
  obj_0->MW_SPI_HANDLE = MW_SPI_Open(0UL, SPIPinsLoc, SPIPinsLoc, SPIPinsLoc,
    SSPinNameLoc, true, 0U);
  ClockModeValue = MW_SPI_MODE_0;
  MsbFirstTransferLoc = MW_SPI_MOST_SIGNIFICANT_BIT_FIRST;
  MW_SPI_SetFormat(obj->MW_SPI_HANDLE, 16U, ClockModeValue, MsbFirstTransferLoc);
  b_obj->isSetupComplete = true;
}

/* Output and update for atomic system: */
void iPMSM_F28_SPIMasterTransfer(uint16_T rtu_0, rtB_SPIMasterTransfer_iPMSM_F28
  *localB, rtDW_SPIMasterTransfer_iPMSM_F2 *localDW)
{
  MW_SPI_FirstBitTransfer_Type MsbFirstTransferLoc;
  MW_SPI_Mode_type ClockModeValue;
  codertarget_tic2000_blocks_SPIM *obj;
  codertarget_tic2000_blocks_SPIM *obj_0;
  uint16_T PinNameLoc;
  uint16_T rdDataRaw;

  /* MATLABSystem: '<S377>/SPI Master Transfer' */
  obj = &localDW->obj;
  obj_0 = obj;
  MW_SPI_SetSlaveSelect(obj_0->MW_SPI_HANDLE, 0U, true);
  obj_0 = obj;
  ClockModeValue = MW_SPI_MODE_0;
  MsbFirstTransferLoc = MW_SPI_MOST_SIGNIFICANT_BIT_FIRST;
  PinNameLoc = MW_SPI_SetFormat(obj_0->MW_SPI_HANDLE, 16U, ClockModeValue,
    MsbFirstTransferLoc);
  if (PinNameLoc == 0U) {
    MW_SPI_MasterWriteRead_8bits(obj->MW_SPI_HANDLE, &rtu_0, &rdDataRaw, 1UL);
  }

  /* MATLABSystem: '<S377>/SPI Master Transfer' */
  localB->SPIMasterTransfer = rdDataRaw;
}

/* Termination for atomic system: */
void iPMS_SPIMasterTransfer_Term(rtDW_SPIMasterTransfer_iPMSM_F2 *localDW)
{
  uint32_T PinNameLoc;
  uint32_T SPIPinsLoc;
  codertarget_tic2000_blocks_SPIM *obj;

  /* Terminate for MATLABSystem: '<S377>/SPI Master Transfer' */
  obj = &localDW->obj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if ((obj->isInitialized == 1L) && obj->isSetupComplete) {
      PinNameLoc = MW_UNDEFINED_VALUE;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(obj->MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc, SPIPinsLoc,
                   PinNameLoc);
    }
  }

  /* End of Terminate for MATLABSystem: '<S377>/SPI Master Transfer' */
}

/* System initialize for atomic system: '<Root>/Speed Control' */
void iPMSM_F28_SpeedControl_Init(rtB_SpeedControl_iPMSM_F28069M *localB,
  rtDW_SpeedControl_iPMSM_F28069M *localDW)
{
  /* Start for Constant: '<S391>/Ki2' */
  localB->Ki2 = 0.0F;

  /* InitializeConditions for RateLimiter: '<S392>/Rate Limiter' */
  localDW->PrevY = 0.1F;

  /* InitializeConditions for RateLimiter: '<S392>/Rate Limiter1' */
  localDW->PrevY_f = -0.1F;

  /* InitializeConditions for DiscreteIntegrator: '<S429>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
  localDW->Integrator_PrevResetState = 0;
}

/* Output and update for atomic system: '<Root>/Speed Control' */
void iPMSM_F28069M_SpeedControl(real32_T rtu_Speed_Ref_PU, real32_T
  rtu_Speed_Meas_PU, const boolean_T *rtd_EnClosedLoop, const boolean_T
  *rtd_Enable, const real32_T *rtd_Speed_ref, rtB_SpeedControl_iPMSM_F28069M
  *localB, rtDW_SpeedControl_iPMSM_F28069M *localDW)
{
  real32_T rateLimiterRate;

  /* Constant: '<S7>/Id_Ref' */
  localB->Id_Ref = 0.0F;

  /* DataStoreRead: '<S391>/Data Store Read1' */
  localB->DataStoreRead1 = *rtd_Enable;

  /* DataStoreRead: '<S391>/Data Store Read2' */
  localB->DataStoreRead2 = *rtd_EnClosedLoop;

  /* Logic: '<S391>/AND' */
  localB->AND = (localB->DataStoreRead1 && localB->DataStoreRead2);

  /* RateLimiter: '<S392>/Rate Limiter' */
  rateLimiterRate = rtu_Speed_Ref_PU - localDW->PrevY;
  if (rateLimiterRate > 0.0048697344F) {
    /* RateLimiter: '<S392>/Rate Limiter' */
    localB->RateLimiter = localDW->PrevY + 0.0048697344F;
  } else if (rateLimiterRate < -0.0048697344F) {
    /* RateLimiter: '<S392>/Rate Limiter' */
    localB->RateLimiter = localDW->PrevY - 0.0048697344F;
  } else {
    /* RateLimiter: '<S392>/Rate Limiter' */
    localB->RateLimiter = rtu_Speed_Ref_PU;
  }

  localDW->PrevY = localB->RateLimiter;

  /* End of RateLimiter: '<S392>/Rate Limiter' */

  /* RateLimiter: '<S392>/Rate Limiter1' */
  rateLimiterRate = rtu_Speed_Ref_PU - localDW->PrevY_f;
  if (rateLimiterRate > 0.0048697344F) {
    /* RateLimiter: '<S392>/Rate Limiter1' */
    localB->RateLimiter1 = localDW->PrevY_f + 0.0048697344F;
  } else if (rateLimiterRate < -0.0048697344F) {
    /* RateLimiter: '<S392>/Rate Limiter1' */
    localB->RateLimiter1 = localDW->PrevY_f - 0.0048697344F;
  } else {
    /* RateLimiter: '<S392>/Rate Limiter1' */
    localB->RateLimiter1 = rtu_Speed_Ref_PU;
  }

  localDW->PrevY_f = localB->RateLimiter1;

  /* End of RateLimiter: '<S392>/Rate Limiter1' */

  /* DataStoreRead: '<S393>/Data Store Read1' */
  localB->DataStoreRead1_p = *rtd_EnClosedLoop;

  /* Switch: '<S393>/Switch' */
  if (localB->DataStoreRead1_p) {
    /* Switch: '<S392>/Switch' */
    if (rtu_Speed_Ref_PU >= 0.0F) {
      /* Switch: '<S392>/Switch' */
      localB->Switch_a = localB->RateLimiter;
    } else {
      /* Switch: '<S392>/Switch' */
      localB->Switch_a = localB->RateLimiter1;
    }

    /* End of Switch: '<S392>/Switch' */

    /* Switch: '<S393>/Switch' */
    localB->Speed_Ref = localB->Switch_a;
  } else {
    /* DataStoreRead: '<S393>/Data Store Read' */
    localB->DataStoreRead = *rtd_Speed_ref;

    /* Switch: '<S393>/Switch1' */
    if (localB->DataStoreRead > 0.0F) {
      /* Switch: '<S393>/Switch1' incorporates:
       *  Constant: '<S393>/Constant'
       */
      localB->Switch1 = 0.1F;
    } else {
      /* Switch: '<S393>/Switch1' incorporates:
       *  Constant: '<S393>/Constant1'
       */
      localB->Switch1 = -0.1F;
    }

    /* End of Switch: '<S393>/Switch1' */

    /* Switch: '<S393>/Switch' */
    localB->Speed_Ref = localB->Switch1;
  }

  /* End of Switch: '<S393>/Switch' */

  /* Product: '<S448>/Product' incorporates:
   *  Constant: '<S448>/Filter_Constant'
   */
  localB->Product = localB->Speed_Ref * 0.2F;

  /* UnitDelay: '<S448>/Unit Delay' */
  localB->UnitDelay = localDW->UnitDelay_DSTATE;

  /* Product: '<S448>/Product1' incorporates:
   *  Constant: '<S448>/One'
   */
  localB->Product1 = 0.8F * localB->UnitDelay;

  /* Sum: '<S448>/Add1' */
  localB->Add1 = localB->Product + localB->Product1;

  /* Sum: '<S391>/Sum' */
  localB->Sum = localB->Add1 - rtu_Speed_Meas_PU;

  /* Product: '<S434>/PProd Out' incorporates:
   *  Constant: '<S391>/Kp1'
   */
  localB->PProdOut = localB->Sum * 0.459470749F;

  /* Logic: '<S391>/Logical Operator' */
  localB->LogicalOperator = !localB->AND;

  /* Constant: '<S391>/Ki2' */
  localB->Ki2 = 0.0F;

  /* DiscreteIntegrator: '<S429>/Integrator' */
  if (localB->LogicalOperator || (localDW->Integrator_PrevResetState != 0)) {
    localDW->Integrator_DSTATE = 0.0F;
  }

  /* DiscreteIntegrator: '<S429>/Integrator' */
  localB->Integrator = localDW->Integrator_DSTATE;

  /* Sum: '<S438>/Sum' */
  localB->Sum_g = localB->PProdOut + localB->Integrator;

  /* DeadZone: '<S422>/DeadZone' */
  if (localB->Sum_g > 1.0F) {
    /* DeadZone: '<S422>/DeadZone' */
    localB->DeadZone = localB->Sum_g - 1.0F;
  } else if (localB->Sum_g >= -1.0F) {
    /* DeadZone: '<S422>/DeadZone' */
    localB->DeadZone = 0.0F;
  } else {
    /* DeadZone: '<S422>/DeadZone' */
    localB->DeadZone = localB->Sum_g - -1.0F;
  }

  /* End of DeadZone: '<S422>/DeadZone' */

  /* RelationalOperator: '<S420>/Relational Operator' incorporates:
   *  Constant: '<S420>/Clamping_zero'
   */
  localB->RelationalOperator = (localB->DeadZone != 0.0F);

  /* RelationalOperator: '<S420>/fix for DT propagation issue' incorporates:
   *  Constant: '<S420>/Clamping_zero'
   */
  localB->fixforDTpropagationissue = (localB->DeadZone > 0.0F);

  /* Switch: '<S420>/Switch1' */
  if (localB->fixforDTpropagationissue) {
    /* Switch: '<S420>/Switch1' incorporates:
     *  Constant: '<S420>/Constant'
     */
    localB->Switch1_c = 1;
  } else {
    /* Switch: '<S420>/Switch1' incorporates:
     *  Constant: '<S420>/Constant2'
     */
    localB->Switch1_c = -1;
  }

  /* End of Switch: '<S420>/Switch1' */

  /* Product: '<S426>/IProd Out' incorporates:
   *  Constant: '<S391>/Ki1'
   */
  localB->IProdOut = localB->Sum * 0.00606610067F;

  /* RelationalOperator: '<S420>/fix for DT propagation issue1' incorporates:
   *  Constant: '<S420>/Clamping_zero'
   */
  localB->fixforDTpropagationissue1 = (localB->IProdOut > 0.0F);

  /* Switch: '<S420>/Switch2' */
  if (localB->fixforDTpropagationissue1) {
    /* Switch: '<S420>/Switch2' incorporates:
     *  Constant: '<S420>/Constant3'
     */
    localB->Switch2 = 1;
  } else {
    /* Switch: '<S420>/Switch2' incorporates:
     *  Constant: '<S420>/Constant4'
     */
    localB->Switch2 = -1;
  }

  /* End of Switch: '<S420>/Switch2' */

  /* RelationalOperator: '<S420>/Equal1' incorporates:
   *  Switch: '<S420>/Switch1'
   *  Switch: '<S420>/Switch2'
   */
  localB->Equal1 = (localB->Switch1_c == localB->Switch2);

  /* Logic: '<S420>/AND3' */
  localB->AND3 = (localB->RelationalOperator && localB->Equal1);

  /* Switch: '<S420>/Switch' */
  if (localB->AND3) {
    /* Switch: '<S420>/Switch' incorporates:
     *  Constant: '<S420>/Constant1'
     */
    localB->Switch = 0.0F;
  } else {
    /* Switch: '<S420>/Switch' */
    localB->Switch = localB->IProdOut;
  }

  /* End of Switch: '<S420>/Switch' */

  /* Saturate: '<S436>/Saturation' */
  rateLimiterRate = localB->Sum_g;
  if (rateLimiterRate > 1.0F) {
    /* Saturate: '<S436>/Saturation' */
    localB->Saturation = 1.0F;
  } else if (rateLimiterRate < -1.0F) {
    /* Saturate: '<S436>/Saturation' */
    localB->Saturation = -1.0F;
  } else {
    /* Saturate: '<S436>/Saturation' */
    localB->Saturation = rateLimiterRate;
  }

  /* End of Saturate: '<S436>/Saturation' */

  /* Update for UnitDelay: '<S448>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localB->Add1;

  /* Update for DiscreteIntegrator: '<S429>/Integrator' */
  localDW->Integrator_DSTATE += localB->Switch;
  localDW->Integrator_PrevResetState = (int16_T)localB->LogicalOperator;
}

/* Model step function for TID0 */
void iPMSM_F28069M_step0(void)         /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition: '<Root>/RT6' */
  iPMSM_F28069M_DWork.RT6_semaphoreTaken = iPMSM_F28069M_DWork.RT6_ActiveBufIdx;

  /* RateTransition: '<Root>/RT6' */
  iPMSM_F28069M_B.RT6 =
    iPMSM_F28069M_DWork.RT6_Buffer[iPMSM_F28069M_DWork.RT6_semaphoreTaken];

  /* RateTransition: '<Root>/RT4' */
  iPMSM_F28069M_DWork.RT4_semaphoreTaken = iPMSM_F28069M_DWork.RT4_ActiveBufIdx;

  /* RateTransition: '<Root>/RT4' */
  iPMSM_F28069M_B.RT4 =
    iPMSM_F28069M_DWork.RT4_Buffer[iPMSM_F28069M_DWork.RT4_semaphoreTaken];

  /* Outputs for Atomic SubSystem: '<Root>/Speed Control' */
  iPMSM_F28069M_SpeedControl(iPMSM_F28069M_B.RT6, iPMSM_F28069M_B.RT4,
    &iPMSM_F28069M_DWork.EnClosedLoop, &iPMSM_F28069M_DWork.Enable,
    &iPMSM_F28069M_DWork.Speed_ref, &iPMSM_F28069M_B.SpeedControl,
    &iPMSM_F28069M_DWork.SpeedControl);

  /* End of Outputs for SubSystem: '<Root>/Speed Control' */

  /* RateTransition: '<Root>/RT2' */
  iPMSM_F28069M_DWork.RT2_Buffer[(iPMSM_F28069M_DWork.RT2_ActiveBufIdx == 0) <<
    1U] = iPMSM_F28069M_B.SpeedControl.Id_Ref;
  iPMSM_F28069M_DWork.RT2_Buffer[1 + ((iPMSM_F28069M_DWork.RT2_ActiveBufIdx == 0)
    << 1U)] = iPMSM_F28069M_B.SpeedControl.Saturation;
  iPMSM_F28069M_DWork.RT2_ActiveBufIdx = (iPMSM_F28069M_DWork.RT2_ActiveBufIdx ==
    0);
}

/* Model step function for TID1 */
void iPMSM_F28069M_step1(void)         /* Sample time: [0.5s, 0.0s] */
{
  /* Outputs for Atomic SubSystem: '<Root>/Heartbeat LED' */
  /* S-Function (c280xgpio_do): '<S386>/Digital Output1' incorporates:
   *  Constant: '<S4>/RED_LED'
   */
  {
    GpioDataRegs.GPBTOGGLE.bit.GPIO34 = (uint16_T)((1U) != 0);
  }

  /* End of Outputs for SubSystem: '<Root>/Heartbeat LED' */
}

/* Model initialize function */
void iPMSM_F28069M_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)iPMSM_F28069M_M, 0,
                sizeof(RT_MODEL_iPMSM_F28069M));

  /* block I/O */
  (void) memset(((void *) &iPMSM_F28069M_B), 0,
                sizeof(BlockIO_iPMSM_F28069M));

  {
    iPMSM_F28069M_B.RT6 = 0.0F;
    iPMSM_F28069M_B.RT4 = 0.0F;
    iPMSM_F28069M_B.RT2[0] = 0.0F;
    iPMSM_F28069M_B.RT2[1] = 0.0F;
    iPMSM_F28069M_B.DataTypeConversion1[0] = 0.0F;
    iPMSM_F28069M_B.DataTypeConversion1[1] = 0.0F;
    iPMSM_F28069M_B.Speed_Ref = 0.0F;
    iPMSM_F28069M_B.DataStoreRead = 0.0F;
    iPMSM_F28069M_B.Abs = 0.0F;
    iPMSM_F28069M_B.Gain = 0.0F;
    iPMSM_F28069M_B.UnitDelay = 0.0F;
    iPMSM_F28069M_B.Delay5[0] = 0.0F;
    iPMSM_F28069M_B.Delay5[1] = 0.0F;
    iPMSM_F28069M_B.Delay5[2] = 0.0F;
    iPMSM_F28069M_B.Delay5[3] = 0.0F;
    iPMSM_F28069M_B.Switch = 0.0F;
    iPMSM_F28069M_B.Merge = 0.0F;
    iPMSM_F28069M_B.indexing = 0.0F;
    iPMSM_F28069M_B.Lookup[0] = 0.0F;
    iPMSM_F28069M_B.Lookup[1] = 0.0F;
    iPMSM_F28069M_B.Lookup[2] = 0.0F;
    iPMSM_F28069M_B.Lookup[3] = 0.0F;
    iPMSM_F28069M_B.Sum3 = 0.0F;
    iPMSM_F28069M_B.DataTypeConversion1_m = 0.0F;
    iPMSM_F28069M_B.Sum2 = 0.0F;
    iPMSM_F28069M_B.Product = 0.0F;
    iPMSM_F28069M_B.Sum4 = 0.0F;
    iPMSM_F28069M_B.Sum5 = 0.0F;
    iPMSM_F28069M_B.Product1 = 0.0F;
    iPMSM_F28069M_B.Sum6 = 0.0F;
    iPMSM_F28069M_B.Sum_m = 0.0F;
    iPMSM_F28069M_B.PProdOut = 0.0F;
    iPMSM_F28069M_B.UnitDelay_p = 0.0F;
    iPMSM_F28069M_B.Integrator = 0.0F;
    iPMSM_F28069M_B.Sum_a = 0.0F;
    iPMSM_F28069M_B.Switch_j = 0.0F;
    iPMSM_F28069M_B.Sum_g = 0.0F;
    iPMSM_F28069M_B.PProdOut_c = 0.0F;
    iPMSM_F28069M_B.UnitDelay_i = 0.0F;
    iPMSM_F28069M_B.Integrator_i = 0.0F;
    iPMSM_F28069M_B.Sum_n = 0.0F;
    iPMSM_F28069M_B.Switch_d = 0.0F;
    iPMSM_F28069M_B.Switch_jv = 0.0F;
    iPMSM_F28069M_B.Product_l = 0.0F;
    iPMSM_F28069M_B.Product_o = 0.0F;
    iPMSM_F28069M_B.Product1_a = 0.0F;
    iPMSM_F28069M_B.Sum1 = 0.0F;
    iPMSM_F28069M_B.Merge_m[0] = 0.0F;
    iPMSM_F28069M_B.Merge_m[1] = 0.0F;
    iPMSM_F28069M_B.DeadZone = 0.0F;
    iPMSM_F28069M_B.IProdOut = 0.0F;
    iPMSM_F28069M_B.Switch_o = 0.0F;
    iPMSM_F28069M_B.DeadZone_n = 0.0F;
    iPMSM_F28069M_B.IProdOut_n = 0.0F;
    iPMSM_F28069M_B.Switch_l = 0.0F;
    iPMSM_F28069M_B.DataTypeConversion = 0.0F;
    iPMSM_F28069M_B.Speed_fb_PU = 0.0F;
    iPMSM_F28069M_B.TmpSignalConversionAtDelay5Inpo[0] = 0.0F;
    iPMSM_F28069M_B.TmpSignalConversionAtDelay5Inpo[1] = 0.0F;
    iPMSM_F28069M_B.TmpSignalConversionAtDelay5Inpo[2] = 0.0F;
    iPMSM_F28069M_B.TmpSignalConversionAtDelay5Inpo[3] = 0.0F;
    iPMSM_F28069M_B.sqrt3_by_two = 0.0F;
    iPMSM_F28069M_B.one_by_two = 0.0F;
    iPMSM_F28069M_B.add_c = 0.0F;
    iPMSM_F28069M_B.add_b = 0.0F;
    iPMSM_F28069M_B.Min = 0.0F;
    iPMSM_F28069M_B.Max = 0.0F;
    iPMSM_F28069M_B.Add = 0.0F;
    iPMSM_F28069M_B.one_by_two_d = 0.0F;
    iPMSM_F28069M_B.Add3 = 0.0F;
    iPMSM_F28069M_B.Add2 = 0.0F;
    iPMSM_F28069M_B.Add1 = 0.0F;
    iPMSM_F28069M_B.Gain_c[0] = 0.0F;
    iPMSM_F28069M_B.Gain_c[1] = 0.0F;
    iPMSM_F28069M_B.Gain_c[2] = 0.0F;
    iPMSM_F28069M_B.Gain_c1[0] = 0.0F;
    iPMSM_F28069M_B.Gain_c1[1] = 0.0F;
    iPMSM_F28069M_B.Gain_c1[2] = 0.0F;
    iPMSM_F28069M_B.PWM_Duty_Cycles[0] = 0.0F;
    iPMSM_F28069M_B.PWM_Duty_Cycles[1] = 0.0F;
    iPMSM_F28069M_B.PWM_Duty_Cycles[2] = 0.0F;
    iPMSM_F28069M_B.Merge_k[0] = 0.0F;
    iPMSM_F28069M_B.Merge_k[1] = 0.0F;
    iPMSM_F28069M_B.Delay1 = 0.0F;
    iPMSM_F28069M_B.Delay_f[0] = 0.0F;
    iPMSM_F28069M_B.Delay_f[1] = 0.0F;
    iPMSM_F28069M_B.Gain_m = 0.0F;
    iPMSM_F28069M_B.UnaryMinus = 0.0F;
    iPMSM_F28069M_B.Product1_f = 0.0F;
    iPMSM_F28069M_B.Gain1 = 0.0F;
    iPMSM_F28069M_B.Product2 = 0.0F;
    iPMSM_F28069M_B.Product_k = 0.0F;
    iPMSM_F28069M_B.Gain_n = 0.0F;
    iPMSM_F28069M_B.Product_i = 0.0F;
    iPMSM_F28069M_B.Sum_mr = 0.0F;
    iPMSM_F28069M_B.Product1_ao = 0.0F;
    iPMSM_F28069M_B.Product3 = 0.0F;
    iPMSM_F28069M_B.Sum1_m = 0.0F;
    iPMSM_F28069M_B.Product3_n = 0.0F;
    iPMSM_F28069M_B.Product1_o = 0.0F;
    iPMSM_F28069M_B.Product2_c = 0.0F;
    iPMSM_F28069M_B.Gain_g = 0.0F;
    iPMSM_F28069M_B.Product3_n0 = 0.0F;
    iPMSM_F28069M_B.Sum1_c = 0.0F;
    iPMSM_F28069M_B.Product1_h = 0.0F;
    iPMSM_F28069M_B.UnaryMinus_k = 0.0F;
    iPMSM_F28069M_B.UnaryMinus_f = 0.0F;
    iPMSM_F28069M_B.Product2_a = 0.0F;
    iPMSM_F28069M_B.Product_g = 0.0F;
    iPMSM_F28069M_B.Sum_i = 0.0F;
    iPMSM_F28069M_B.Product_kc = 0.0F;
    iPMSM_F28069M_B.UnaryMinus_fm = 0.0F;
    iPMSM_F28069M_B.Gain1_o = 0.0F;
    iPMSM_F28069M_B.UnaryMinus1 = 0.0F;
    iPMSM_F28069M_B.Product2_d = 0.0F;
    iPMSM_F28069M_B.Gain_j = 0.0F;
    iPMSM_F28069M_B.UnaryMinus_i = 0.0F;
    iPMSM_F28069M_B.Product_f = 0.0F;
    iPMSM_F28069M_B.Sum_e = 0.0F;
    iPMSM_F28069M_B.Product1_oz = 0.0F;
    iPMSM_F28069M_B.Product3_nb = 0.0F;
    iPMSM_F28069M_B.Sum1_k = 0.0F;
    iPMSM_F28069M_B.UnaryMinus_j = 0.0F;
    iPMSM_F28069M_B.Product_n = 0.0F;
    iPMSM_F28069M_B.Product3_c = 0.0F;
    iPMSM_F28069M_B.UnaryMinus1_b = 0.0F;
    iPMSM_F28069M_B.Product5 = 0.0F;
    iPMSM_F28069M_B.Sum1_i = 0.0F;
    iPMSM_F28069M_B.Product2_o = 0.0F;
    iPMSM_F28069M_B.Product4 = 0.0F;
    iPMSM_F28069M_B.Product1_b = 0.0F;
    iPMSM_F28069M_B.UnaryMinus_g = 0.0F;
    iPMSM_F28069M_B.Product2_f = 0.0F;
    iPMSM_F28069M_B.Sum_k = 0.0F;
    iPMSM_F28069M_B.Product_gf = 0.0F;
    iPMSM_F28069M_B.Sum_h = 0.0F;
    iPMSM_F28069M_B.Product1_d = 0.0F;
    iPMSM_F28069M_B.Product3_g = 0.0F;
    iPMSM_F28069M_B.Sum1_j = 0.0F;
    iPMSM_F28069M_B.Sum_l[0] = 0.0F;
    iPMSM_F28069M_B.Sum_l[1] = 0.0F;
    iPMSM_F28069M_B.Sum_n2[0] = 0.0F;
    iPMSM_F28069M_B.Sum_n2[1] = 0.0F;
    iPMSM_F28069M_B.Gain1_c[0] = 0.0F;
    iPMSM_F28069M_B.Gain1_c[1] = 0.0F;
    iPMSM_F28069M_B.Sum2_o[0] = 0.0F;
    iPMSM_F28069M_B.Sum2_o[1] = 0.0F;
    iPMSM_F28069M_B.Gain2[0] = 0.0F;
    iPMSM_F28069M_B.Gain2[1] = 0.0F;
    iPMSM_F28069M_B.Sum1_j4[0] = 0.0F;
    iPMSM_F28069M_B.Sum1_j4[1] = 0.0F;
    iPMSM_F28069M_B.Product_m[0] = 0.0F;
    iPMSM_F28069M_B.Product_m[1] = 0.0F;
    iPMSM_F28069M_B.Product_j[0] = 0.0F;
    iPMSM_F28069M_B.Product_j[1] = 0.0F;
    iPMSM_F28069M_B.UnitDelay_j[0] = 0.0F;
    iPMSM_F28069M_B.UnitDelay_j[1] = 0.0F;
    iPMSM_F28069M_B.Product1_e[0] = 0.0F;
    iPMSM_F28069M_B.Product1_e[1] = 0.0F;
    iPMSM_F28069M_B.Add1_j[0] = 0.0F;
    iPMSM_F28069M_B.Add1_j[1] = 0.0F;
    iPMSM_F28069M_B.Delay_e = 0.0F;
    iPMSM_F28069M_B.Merge_h = 0.0F;
    iPMSM_F28069M_B.indexing_j = 0.0F;
    iPMSM_F28069M_B.Lookup_i[0] = 0.0F;
    iPMSM_F28069M_B.Lookup_i[1] = 0.0F;
    iPMSM_F28069M_B.Lookup_i[2] = 0.0F;
    iPMSM_F28069M_B.Lookup_i[3] = 0.0F;
    iPMSM_F28069M_B.Sum5_o = 0.0F;
    iPMSM_F28069M_B.DataTypeConversion1_ma = 0.0F;
    iPMSM_F28069M_B.Sum2_c = 0.0F;
    iPMSM_F28069M_B.Product1_k = 0.0F;
    iPMSM_F28069M_B.Sum6_a = 0.0F;
    iPMSM_F28069M_B.Merge_k4 = 0.0F;
    iPMSM_F28069M_B.Square = 0.0F;
    iPMSM_F28069M_B.Merge1 = 0.0F;
    iPMSM_F28069M_B.Square1 = 0.0F;
    iPMSM_F28069M_B.Sum_e2 = 0.0F;
    iPMSM_F28069M_B.Sqrt = 0.0F;
    iPMSM_F28069M_B.Switch_b = 0.0F;
    iPMSM_F28069M_B.Divide1 = 0.0F;
    iPMSM_F28069M_B.Product_la = 0.0F;
    iPMSM_F28069M_B.Divide = 0.0F;
    iPMSM_F28069M_B.Sum3_m = 0.0F;
    iPMSM_F28069M_B.Product_ig = 0.0F;
    iPMSM_F28069M_B.Sum4_j = 0.0F;
    iPMSM_F28069M_B.Product1_dd = 0.0F;
    iPMSM_F28069M_B.Sum_b = 0.0F;
    iPMSM_F28069M_B.ProportionalGain = 0.0F;
    iPMSM_F28069M_B.IntegralGain = 0.0F;
    iPMSM_F28069M_B.Integrator_c = 0.0F;
    iPMSM_F28069M_B.Sum_dd = 0.0F;
    iPMSM_F28069M_B.Merge_g = 0.0F;
    iPMSM_F28069M_B.Product_kr = 0.0F;
    iPMSM_F28069M_B.UnitDelay_l = 0.0F;
    iPMSM_F28069M_B.Product1_ff = 0.0F;
    iPMSM_F28069M_B.Add1_d = 0.0F;
    iPMSM_F28069M_B.speed = 0.0F;
    iPMSM_F28069M_B.Gain_i = 0.0F;
    iPMSM_F28069M_B.UnitDelay_b = 0.0F;
    iPMSM_F28069M_B.Product_iq = 0.0F;
    iPMSM_F28069M_B.UnitDelay_im = 0.0F;
    iPMSM_F28069M_B.Product1_ok = 0.0F;
    iPMSM_F28069M_B.Add1_h = 0.0F;
    iPMSM_F28069M_B.Delay2 = 0.0F;
    iPMSM_F28069M_B.Delay3 = 0.0F;
    iPMSM_F28069M_B.Product_oq = 0.0F;
    iPMSM_F28069M_B.UnitDelay_n = 0.0F;
    iPMSM_F28069M_B.Product1_n = 0.0F;
    iPMSM_F28069M_B.Add1_a = 0.0F;
    iPMSM_F28069M_B.Gain_h = 0.0F;
    iPMSM_F28069M_B.Sum1_cg = 0.0F;
    iPMSM_F28069M_B.Gain1_a = 0.0F;
    iPMSM_F28069M_B.Delay2_i = 0.0F;
    iPMSM_F28069M_B.Delay3_n = 0.0F;
    iPMSM_F28069M_B.Product_n1 = 0.0F;
    iPMSM_F28069M_B.UnitDelay_bs = 0.0F;
    iPMSM_F28069M_B.Product1_o1 = 0.0F;
    iPMSM_F28069M_B.Add1_p = 0.0F;
    iPMSM_F28069M_B.Gain_is = 0.0F;
    iPMSM_F28069M_B.Sum1_a = 0.0F;
    iPMSM_F28069M_B.Gain1_j = 0.0F;
    iPMSM_F28069M_B.Product_e = 0.0F;
    iPMSM_F28069M_B.Product1_fq = 0.0F;
    iPMSM_F28069M_B.Product_ky = 0.0F;
    iPMSM_F28069M_B.UnitDelay_l2 = 0.0F;
    iPMSM_F28069M_B.Product1_dp = 0.0F;
    iPMSM_F28069M_B.Add1_au = 0.0F;
    iPMSM_F28069M_B.Delay1_f = 0.0F;
    iPMSM_F28069M_B.Sum_ad = 0.0F;
    iPMSM_F28069M_B.Gain1_f = 0.0F;
    iPMSM_F28069M_B.Delay_a = 0.0F;
    iPMSM_F28069M_B.Gain2_f = 0.0F;
    iPMSM_F28069M_B.Sum1_p = 0.0F;
    iPMSM_F28069M_B.Product_d = 0.0F;
    iPMSM_F28069M_B.Product_a = 0.0F;
    iPMSM_F28069M_B.UnitDelay_o = 0.0F;
    iPMSM_F28069M_B.Product1_m = 0.0F;
    iPMSM_F28069M_B.Add1_jc = 0.0F;
    iPMSM_F28069M_B.Delay1_g = 0.0F;
    iPMSM_F28069M_B.Sum_ia = 0.0F;
    iPMSM_F28069M_B.Gain1_ok = 0.0F;
    iPMSM_F28069M_B.Delay_b = 0.0F;
    iPMSM_F28069M_B.Gain2_c = 0.0F;
    iPMSM_F28069M_B.Sum1_il = 0.0F;
    iPMSM_F28069M_B.Product1_j = 0.0F;
    iPMSM_F28069M_B.Sum_ie = 0.0F;
    iPMSM_F28069M_B.MathFunction = 0.0F;
    iPMSM_F28069M_B.Abs_p = 0.0F;
    iPMSM_F28069M_B.Delay2_n = 0.0F;
    iPMSM_F28069M_B.Delay3_ni = 0.0F;
    iPMSM_F28069M_B.Product_p = 0.0F;
    iPMSM_F28069M_B.UnitDelay_c = 0.0F;
    iPMSM_F28069M_B.Product1_c = 0.0F;
    iPMSM_F28069M_B.Add1_f = 0.0F;
    iPMSM_F28069M_B.Gain_d = 0.0F;
    iPMSM_F28069M_B.Sum1_jp = 0.0F;
    iPMSM_F28069M_B.Gain1_i = 0.0F;
    iPMSM_F28069M_B.Delay2_d = 0.0F;
    iPMSM_F28069M_B.Delay3_h = 0.0F;
    iPMSM_F28069M_B.Product_pv = 0.0F;
    iPMSM_F28069M_B.UnitDelay_i1 = 0.0F;
    iPMSM_F28069M_B.Product1_o5 = 0.0F;
    iPMSM_F28069M_B.Add1_o = 0.0F;
    iPMSM_F28069M_B.Gain_jy = 0.0F;
    iPMSM_F28069M_B.Sum1_l = 0.0F;
    iPMSM_F28069M_B.Gain1_e = 0.0F;
    iPMSM_F28069M_B.Delay_e4 = 0.0F;
    iPMSM_F28069M_B.Delay1_h = 0.0F;
    iPMSM_F28069M_B.Switch1 = 0.0F;
    iPMSM_F28069M_B.Product_c = 0.0F;
    iPMSM_F28069M_B.UnitDelay_jq = 0.0F;
    iPMSM_F28069M_B.Product1_dx = 0.0F;
    iPMSM_F28069M_B.Add1_i = 0.0F;
    iPMSM_F28069M_B.Square_f = 0.0F;
    iPMSM_F28069M_B.Square1_i = 0.0F;
    iPMSM_F28069M_B.Sum2_oo = 0.0F;
    iPMSM_F28069M_B.Sqrt_n = 0.0F;
    iPMSM_F28069M_B.UnaryMinus_h = 0.0F;
    iPMSM_F28069M_B.Sum_j = 0.0F;
    iPMSM_F28069M_B.Product_ds[0] = 0.0F;
    iPMSM_F28069M_B.Product_ds[1] = 0.0F;
    iPMSM_F28069M_B.Product_ds[2] = 0.0F;
    iPMSM_F28069M_B.Product_ds[3] = 0.0F;
    iPMSM_F28069M_B.UnitDelay_g[0] = 0.0F;
    iPMSM_F28069M_B.UnitDelay_g[1] = 0.0F;
    iPMSM_F28069M_B.UnitDelay_g[2] = 0.0F;
    iPMSM_F28069M_B.UnitDelay_g[3] = 0.0F;
    iPMSM_F28069M_B.Product1_fg[0] = 0.0F;
    iPMSM_F28069M_B.Product1_fg[1] = 0.0F;
    iPMSM_F28069M_B.Product1_fg[2] = 0.0F;
    iPMSM_F28069M_B.Product1_fg[3] = 0.0F;
    iPMSM_F28069M_B.Add1_iq[0] = 0.0F;
    iPMSM_F28069M_B.Add1_iq[1] = 0.0F;
    iPMSM_F28069M_B.Add1_iq[2] = 0.0F;
    iPMSM_F28069M_B.Add1_iq[3] = 0.0F;
    iPMSM_F28069M_B.Sum6_ap[0] = 0.0F;
    iPMSM_F28069M_B.Sum6_ap[1] = 0.0F;
    iPMSM_F28069M_B.Sum6_ap[2] = 0.0F;
    iPMSM_F28069M_B.Sum6_ap[3] = 0.0F;
    iPMSM_F28069M_B.ScalingR = 0.0F;
    iPMSM_F28069M_B.Sum3_d = 0.0F;
    iPMSM_F28069M_B.Delay1_c = 0.0F;
    iPMSM_F28069M_B.Sum_nc = 0.0F;
    iPMSM_F28069M_B.Gain1_m = 0.0F;
    iPMSM_F28069M_B.Delay_ld = 0.0F;
    iPMSM_F28069M_B.Gain2_j = 0.0F;
    iPMSM_F28069M_B.Sum1_n = 0.0F;
    iPMSM_F28069M_B.ScalingL = 0.0F;
    iPMSM_F28069M_B.Sum1_b = 0.0F;
    iPMSM_F28069M_B.Product_iy = 0.0F;
    iPMSM_F28069M_B.UnitDelay_ii = 0.0F;
    iPMSM_F28069M_B.Product1_b3 = 0.0F;
    iPMSM_F28069M_B.Add1_o0 = 0.0F;
    iPMSM_F28069M_B.Switch_g = 0.0F;
    iPMSM_F28069M_B.ScalingR_k = 0.0F;
    iPMSM_F28069M_B.Sum3_n = 0.0F;
    iPMSM_F28069M_B.Delay1_o = 0.0F;
    iPMSM_F28069M_B.Sum_lg = 0.0F;
    iPMSM_F28069M_B.Gain1_ox = 0.0F;
    iPMSM_F28069M_B.Delay_h = 0.0F;
    iPMSM_F28069M_B.Gain2_f1 = 0.0F;
    iPMSM_F28069M_B.Sum1_ni = 0.0F;
    iPMSM_F28069M_B.ScalingL_c = 0.0F;
    iPMSM_F28069M_B.Sum1_g = 0.0F;
    iPMSM_F28069M_B.Product_m5 = 0.0F;
    iPMSM_F28069M_B.UnitDelay_f = 0.0F;
    iPMSM_F28069M_B.Product1_hg = 0.0F;
    iPMSM_F28069M_B.Add1_az = 0.0F;
    iPMSM_F28069M_B.Switch_h = 0.0F;
    iPMSM_F28069M_B.DTC = 0.0F;
    iPMSM_F28069M_B.SpeedGain = 0.0F;
    iPMSM_F28069M_B.Product_pk = 0.0F;
    iPMSM_F28069M_B.UnitDelay_d = 0.0F;
    iPMSM_F28069M_B.Product1_al = 0.0F;
    iPMSM_F28069M_B.Add1_pz = 0.0F;
    iPMSM_F28069M_B.elect2mech = 0.0F;
    iPMSM_F28069M_B.Sum_f = 0.0F;
    iPMSM_F28069M_B.Sum_bp = 0.0F;
    iPMSM_F28069M_B.Atan2 = 0.0F;
    iPMSM_F28069M_B.Switch_ds = 0.0F;
    iPMSM_F28069M_B.algDD = 0.0F;
    iPMSM_F28069M_B.Gain_f = 0.0F;
    iPMSM_F28069M_B.Switch_c = 0.0F;
    iPMSM_F28069M_B.Bias = 0.0F;
    iPMSM_F28069M_B.UnitDelay1 = 0.0F;
    iPMSM_F28069M_B.UnitDelay_g4 = 0.0F;
    iPMSM_F28069M_B.a = 0.0F;
    iPMSM_F28069M_B.Delay_k = 0.0F;
    iPMSM_F28069M_B.Sum2_g = 0.0F;
    iPMSM_F28069M_B.Sum3_md = 0.0F;
    iPMSM_F28069M_B.b_invg = 0.0F;
    iPMSM_F28069M_B.Delay1_e = 0.0F;
    iPMSM_F28069M_B.Sum4_b = 0.0F;
    iPMSM_F28069M_B.Product_c0 = 0.0F;
    iPMSM_F28069M_B.UnitDelay_a = 0.0F;
    iPMSM_F28069M_B.Product1_en = 0.0F;
    iPMSM_F28069M_B.Add1_dd = 0.0F;
    iPMSM_F28069M_B.UnitDelay1_k = 0.0F;
    iPMSM_F28069M_B.UnitDelay_k = 0.0F;
    iPMSM_F28069M_B.a_e = 0.0F;
    iPMSM_F28069M_B.Delay_i = 0.0F;
    iPMSM_F28069M_B.Sum2_g2 = 0.0F;
    iPMSM_F28069M_B.Sum3_l = 0.0F;
    iPMSM_F28069M_B.b_invg_o = 0.0F;
    iPMSM_F28069M_B.Delay1_fr = 0.0F;
    iPMSM_F28069M_B.Sum4_m = 0.0F;
    iPMSM_F28069M_B.Product_p3 = 0.0F;
    iPMSM_F28069M_B.UnitDelay_gx = 0.0F;
    iPMSM_F28069M_B.Product1_k4 = 0.0F;
    iPMSM_F28069M_B.Add1_g = 0.0F;
    iPMSM_F28069M_B.Merge_ku = 0.0F;
    iPMSM_F28069M_B.Merge1_i = 0.0F;
    iPMSM_F28069M_B.Delay_ep = 0.0F;
    iPMSM_F28069M_B.Sign = 0.0F;
    iPMSM_F28069M_B.Eta = 0.0F;
    iPMSM_F28069M_B.Sum_gf = 0.0F;
    iPMSM_F28069M_B.b = 0.0F;
    iPMSM_F28069M_B.a_a = 0.0F;
    iPMSM_F28069M_B.Sum1_d = 0.0F;
    iPMSM_F28069M_B.Sign_m = 0.0F;
    iPMSM_F28069M_B.Eta_n = 0.0F;
    iPMSM_F28069M_B.Sum_bl = 0.0F;
    iPMSM_F28069M_B.b_i = 0.0F;
    iPMSM_F28069M_B.a_p = 0.0F;
    iPMSM_F28069M_B.Sum1_gj = 0.0F;
    iPMSM_F28069M_B.DTC_e = 0.0F;
    iPMSM_F28069M_B.SpeedGain_k = 0.0F;
    iPMSM_F28069M_B.Product_i2 = 0.0F;
    iPMSM_F28069M_B.UnitDelay_ci = 0.0F;
    iPMSM_F28069M_B.Product1_ey = 0.0F;
    iPMSM_F28069M_B.Add1_c = 0.0F;
    iPMSM_F28069M_B.Product_jt = 0.0F;
    iPMSM_F28069M_B.Product2_i = 0.0F;
    iPMSM_F28069M_B.Sum1_mc = 0.0F;
    iPMSM_F28069M_B.Product1_mw = 0.0F;
    iPMSM_F28069M_B.Product3_b = 0.0F;
    iPMSM_F28069M_B.Sum2_p = 0.0F;
    iPMSM_F28069M_B.Switch_cx = 0.0F;
    iPMSM_F28069M_B.Atan2_n = 0.0F;
    iPMSM_F28069M_B.Switch_gb = 0.0F;
    iPMSM_F28069M_B.algDD_a = 0.0F;
    iPMSM_F28069M_B.Gain_o = 0.0F;
    iPMSM_F28069M_B.Switch_m = 0.0F;
    iPMSM_F28069M_B.Bias_f = 0.0F;
    iPMSM_F28069M_B.Bias_j = 0.0F;
    iPMSM_F28069M_B.acos_c = 0.0F;
    iPMSM_F28069M_B.bsin = 0.0F;
    iPMSM_F28069M_B.sum_Ds = 0.0F;
    iPMSM_F28069M_B.bcos = 0.0F;
    iPMSM_F28069M_B.asin_f = 0.0F;
    iPMSM_F28069M_B.sum_Qs = 0.0F;
    iPMSM_F28069M_B.Switch_bi[0] = 0.0F;
    iPMSM_F28069M_B.Switch_bi[1] = 0.0F;
    iPMSM_F28069M_B.algDD_o1 = 0.0F;
    iPMSM_F28069M_B.algDD_o2 = 0.0F;
    iPMSM_F28069M_B.qcos = 0.0F;
    iPMSM_F28069M_B.dsin = 0.0F;
    iPMSM_F28069M_B.sum_beta = 0.0F;
    iPMSM_F28069M_B.dcos = 0.0F;
    iPMSM_F28069M_B.qsin = 0.0F;
    iPMSM_F28069M_B.sum_alpha = 0.0F;
    iPMSM_F28069M_B.Switch_df[0] = 0.0F;
    iPMSM_F28069M_B.Switch_df[1] = 0.0F;
    iPMSM_F28069M_B.algDD_o1_o = 0.0F;
    iPMSM_F28069M_B.algDD_o2_c = 0.0F;
    iPMSM_F28069M_B.Saturation = 0.0F;
    iPMSM_F28069M_B.Vd_OpenLoop = 0.0F;
    iPMSM_F28069M_B.Abs_i = 0.0F;
    iPMSM_F28069M_B.Saturation_a = 0.0F;
    iPMSM_F28069M_B.Saturation_f = 0.0F;
    iPMSM_F28069M_B.Product_ch[0] = 0.0F;
    iPMSM_F28069M_B.Product_ch[1] = 0.0F;
    iPMSM_F28069M_B.SquareRoot = 0.0F;
    iPMSM_F28069M_B.Switch_os = 0.0F;
    iPMSM_F28069M_B.Reciprocal = 0.0F;
    iPMSM_F28069M_B.Switch_i[0] = 0.0F;
    iPMSM_F28069M_B.Switch_i[1] = 0.0F;
    iPMSM_F28069M_B.Switch2 = 0.0F;
    iPMSM_F28069M_B.Product_b = 0.0F;
    iPMSM_F28069M_B.Sum_a3 = 0.0F;
    iPMSM_F28069M_B.Product2_ao = 0.0F;
    iPMSM_F28069M_B.Merge_e = 0.0F;
    iPMSM_F28069M_B.Gain_l = 0.0F;
    iPMSM_F28069M_B.Switch_k = 0.0F;
    iPMSM_F28069M_B.Switch1_h = 0.0F;
    iPMSM_F28069M_B.Sqrt_np = 0.0F;
    iPMSM_F28069M_B.Gain_e = 0.0F;
    iPMSM_F28069M_B.a_plus_2b = 0.0F;
    iPMSM_F28069M_B.one_by_sqrt3 = 0.0F;
    iPMSM_F28069M_B.algDD_o1_g = 0.0F;
    iPMSM_F28069M_B.algDD_o2_cx = 0.0F;
    iPMSM_F28069M_B.SpeedControl.Id_Ref = 0.0F;
    iPMSM_F28069M_B.SpeedControl.RateLimiter = 0.0F;
    iPMSM_F28069M_B.SpeedControl.RateLimiter1 = 0.0F;
    iPMSM_F28069M_B.SpeedControl.Speed_Ref = 0.0F;
    iPMSM_F28069M_B.SpeedControl.Product = 0.0F;
    iPMSM_F28069M_B.SpeedControl.UnitDelay = 0.0F;
    iPMSM_F28069M_B.SpeedControl.Product1 = 0.0F;
    iPMSM_F28069M_B.SpeedControl.Add1 = 0.0F;
    iPMSM_F28069M_B.SpeedControl.Sum = 0.0F;
    iPMSM_F28069M_B.SpeedControl.PProdOut = 0.0F;
    iPMSM_F28069M_B.SpeedControl.Ki2 = 0.0F;
    iPMSM_F28069M_B.SpeedControl.Integrator = 0.0F;
    iPMSM_F28069M_B.SpeedControl.Sum_g = 0.0F;
    iPMSM_F28069M_B.SpeedControl.DeadZone = 0.0F;
    iPMSM_F28069M_B.SpeedControl.IProdOut = 0.0F;
    iPMSM_F28069M_B.SpeedControl.Switch = 0.0F;
    iPMSM_F28069M_B.SpeedControl.Saturation = 0.0F;
    iPMSM_F28069M_B.SpeedControl.DataStoreRead = 0.0F;
    iPMSM_F28069M_B.SpeedControl.Switch1 = 0.0F;
    iPMSM_F28069M_B.SpeedControl.Switch_a = 0.0F;
    iPMSM_F28069M_B.IfActionSubsystem1_j.Convert_back = 0.0F;
    iPMSM_F28069M_B.IfActionSubsystem_e.Convert_back = 0.0F;
    iPMSM_F28069M_B.Accumulate_j.Add = 0.0F;
    iPMSM_F28069M_B.Accumulate_j.DataTypeConversion1 = 0.0F;
    iPMSM_F28069M_B.Accumulate_j.Add1 = 0.0F;
    iPMSM_F28069M_B.Accumulate_j.Input = 0.0F;
    iPMSM_F28069M_B.IfActionSubsystem1.Convert_back = 0.0F;
    iPMSM_F28069M_B.IfActionSubsystem.Convert_back = 0.0F;
    iPMSM_F28069M_B.Accumulate.Add = 0.0F;
    iPMSM_F28069M_B.Accumulate.DataTypeConversion1 = 0.0F;
    iPMSM_F28069M_B.Accumulate.Add1 = 0.0F;
    iPMSM_F28069M_B.Accumulate.Input = 0.0F;
  }

  /* exported global signals */
  Iab_fb_PU[0] = 0.0F;
  Iab_fb_PU[1] = 0.0F;
  Iab_ADC_u16[0] = 0U;
  Iab_ADC_u16[1] = 0U;

  /* states (dwork) */
  (void) memset((void *)&iPMSM_F28069M_DWork, 0,
                sizeof(D_Work_iPMSM_F28069M));
  iPMSM_F28069M_DWork.UnitDelay_DSTATE = 0.0F;
  iPMSM_F28069M_DWork.Delay5_DSTATE[0] = 0.0F;
  iPMSM_F28069M_DWork.Delay5_DSTATE[1] = 0.0F;
  iPMSM_F28069M_DWork.Delay5_DSTATE[2] = 0.0F;
  iPMSM_F28069M_DWork.Delay5_DSTATE[3] = 0.0F;
  iPMSM_F28069M_DWork.UnitDelay_DSTATE_l = 0.0F;
  iPMSM_F28069M_DWork.Integrator_DSTATE = 0.0F;
  iPMSM_F28069M_DWork.UnitDelay_DSTATE_l0 = 0.0F;
  iPMSM_F28069M_DWork.Integrator_DSTATE_j = 0.0F;
  iPMSM_F28069M_DWork.Delay1_DSTATE = 0.0F;
  iPMSM_F28069M_DWork.Delay_DSTATE[0] = 0.0F;
  iPMSM_F28069M_DWork.Delay_DSTATE[1] = 0.0F;
  iPMSM_F28069M_DWork.Delay_DSTATE_i = 0.0F;
  iPMSM_F28069M_DWork.Integrator_DSTATE_o = 0.0F;
  iPMSM_F28069M_DWork.Delay2_DSTATE = 0.0F;
  iPMSM_F28069M_DWork.Delay3_DSTATE = 0.0F;
  iPMSM_F28069M_DWork.Delay2_DSTATE_i = 0.0F;
  iPMSM_F28069M_DWork.Delay3_DSTATE_a = 0.0F;
  iPMSM_F28069M_DWork.Delay1_DSTATE_j = 0.0F;
  iPMSM_F28069M_DWork.Delay_DSTATE_a = 0.0F;
  iPMSM_F28069M_DWork.Delay1_DSTATE_a = 0.0F;
  iPMSM_F28069M_DWork.Delay_DSTATE_o = 0.0F;
  iPMSM_F28069M_DWork.Delay2_DSTATE_o = 0.0F;
  iPMSM_F28069M_DWork.Delay3_DSTATE_f = 0.0F;
  iPMSM_F28069M_DWork.Delay2_DSTATE_p = 0.0F;
  iPMSM_F28069M_DWork.Delay3_DSTATE_n = 0.0F;
  iPMSM_F28069M_DWork.UnitDelay_DSTATE_n3[0] = 0.0F;
  iPMSM_F28069M_DWork.UnitDelay_DSTATE_n3[1] = 0.0F;
  iPMSM_F28069M_DWork.UnitDelay_DSTATE_n3[2] = 0.0F;
  iPMSM_F28069M_DWork.UnitDelay_DSTATE_n3[3] = 0.0F;
  iPMSM_F28069M_DWork.Delay1_DSTATE_n = 0.0F;
  iPMSM_F28069M_DWork.Delay_DSTATE_om = 0.0F;
  iPMSM_F28069M_DWork.UnitDelay_DSTATE_p = 0.0F;
  iPMSM_F28069M_DWork.Delay1_DSTATE_n2 = 0.0F;
  iPMSM_F28069M_DWork.Delay_DSTATE_hc = 0.0F;
  iPMSM_F28069M_DWork.UnitDelay_DSTATE_nr = 0.0F;
  iPMSM_F28069M_DWork.UnitDelay_DSTATE_a1 = 0.0F;
  iPMSM_F28069M_DWork.Delay_DSTATE_n = 0.0F;
  iPMSM_F28069M_DWork.Delay1_DSTATE_l = 0.0F;
  iPMSM_F28069M_DWork.Delay_DSTATE_e = 0.0F;
  iPMSM_F28069M_DWork.Delay1_DSTATE_jt = 0.0F;
  iPMSM_F28069M_DWork.Delay_DSTATE_nm = 0.0F;
  iPMSM_F28069M_DWork.RT6_Buffer[0] = 0.0F;
  iPMSM_F28069M_DWork.RT6_Buffer[1] = 0.0F;
  iPMSM_F28069M_DWork.RT4_Buffer[0] = 0.0F;
  iPMSM_F28069M_DWork.RT4_Buffer[1] = 0.0F;
  iPMSM_F28069M_DWork.RT2_Buffer[0] = 0.0F;
  iPMSM_F28069M_DWork.RT2_Buffer[1] = 0.0F;
  iPMSM_F28069M_DWork.RT2_Buffer[2] = 0.0F;
  iPMSM_F28069M_DWork.RT2_Buffer[3] = 0.0F;
  iPMSM_F28069M_DWork.Speed_ref = 0.0F;
  iPMSM_F28069M_DWork.SpeedControl.UnitDelay_DSTATE = 0.0F;
  iPMSM_F28069M_DWork.SpeedControl.Integrator_DSTATE = 0.0F;
  iPMSM_F28069M_DWork.SpeedControl.PrevY = 0.0F;
  iPMSM_F28069M_DWork.SpeedControl.PrevY_f = 0.0F;

  {
    uint16_T s379_iter;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory3' */
    iPMSM_F28069M_DWork.Speed_ref = 0.1F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
    iPMSM_F28069M_DWork.IaOffset = 2087U;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
    iPMSM_F28069M_DWork.IbOffset = 2082U;
    iPMSM_F28069M_PrevZCSigState.Delay_Reset_ZCE_n = UNINITIALIZED_ZCSIG;
    iPMSM_F28069M_PrevZCSigState.Delay1_Reset_ZCE_b = UNINITIALIZED_ZCSIG;
    iPMSM_F28069M_PrevZCSigState.Delay_Reset_ZCE_l = UNINITIALIZED_ZCSIG;
    iPMSM_F28069M_PrevZCSigState.Delay1_Reset_ZCE_bl = UNINITIALIZED_ZCSIG;
    iPMSM_F28069M_PrevZCSigState.Delay_Reset_ZCE_n0 = UNINITIALIZED_ZCSIG;
    iPMSM_F28069M_PrevZCSigState.Delay1_Reset_ZCE_p = UNINITIALIZED_ZCSIG;
    iPMSM_F28069M_PrevZCSigState.Delay_Reset_ZCE_a = UNINITIALIZED_ZCSIG;
    iPMSM_F28069M_PrevZCSigState.Delay1_Reset_ZCE_a = UNINITIALIZED_ZCSIG;
    iPMSM_F28069M_PrevZCSigState.Delay_Reset_ZCE_o = UNINITIALIZED_ZCSIG;
    iPMSM_F28069M_PrevZCSigState.Delay2_Reset_ZCE_e = UNINITIALIZED_ZCSIG;
    iPMSM_F28069M_PrevZCSigState.Delay3_Reset_ZCE_d = UNINITIALIZED_ZCSIG;
    iPMSM_F28069M_PrevZCSigState.Delay2_Reset_ZCE_c = UNINITIALIZED_ZCSIG;
    iPMSM_F28069M_PrevZCSigState.Delay3_Reset_ZCE_p = UNINITIALIZED_ZCSIG;
    iPMSM_F28069M_PrevZCSigState.Delay1_Reset_ZCE_h = UNINITIALIZED_ZCSIG;
    iPMSM_F28069M_PrevZCSigState.Delay_Reset_ZCE_d = UNINITIALIZED_ZCSIG;
    iPMSM_F28069M_PrevZCSigState.Delay1_Reset_ZCE_j = UNINITIALIZED_ZCSIG;
    iPMSM_F28069M_PrevZCSigState.Delay_Reset_ZCE_bz = UNINITIALIZED_ZCSIG;
    iPMSM_F28069M_PrevZCSigState.Delay2_Reset_ZCE = UNINITIALIZED_ZCSIG;
    iPMSM_F28069M_PrevZCSigState.Delay3_Reset_ZCE = UNINITIALIZED_ZCSIG;
    iPMSM_F28069M_PrevZCSigState.Delay2_Reset_ZCE_a = UNINITIALIZED_ZCSIG;
    iPMSM_F28069M_PrevZCSigState.Delay3_Reset_ZCE_e = UNINITIALIZED_ZCSIG;
    iPMSM_F28069M_PrevZCSigState.Delay1_Reset_ZCE = UNINITIALIZED_ZCSIG;
    iPMSM_F28069M_PrevZCSigState.Delay_Reset_ZCE = UNINITIALIZED_ZCSIG;
    iPMSM_F28069M_PrevZCSigState.Delay_Reset_ZCE_b = UNINITIALIZED_ZCSIG;
    iPMSM_F28069M_PrevZCSigState.Dir_Sense_m.Dir_Sense_Trig_ZCE = POS_ZCSIG;
    iPMSM_F28069M_PrevZCSigState.Dir_Sense.Dir_Sense_Trig_ZCE = POS_ZCSIG;

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S371>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Current Control'
     */
    iPMSM_F_CurrentControl_Init();

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S373>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Serial Receive'
     */
    /* System initialize for function-call system: '<Root>/Serial Receive' */

    /* Start for S-Function (c28xsci_rx): '<S390>/SCI Receive' */

    /* Initialize out port */
    {
      iPMSM_F28069M_B.SCIReceive[0] = (uint16_T)0.0;
      iPMSM_F28069M_B.SCIReceive[1] = (uint16_T)0.0;
    }

    /*Configure Timer2 when blocking mode is enabled and Timeout is not inf*/
    {
      /* InitCpuTimers() - CPU Timers are also initialized in
       * MW_c28xx_board.c in the generated code.
       */
      CpuTimer2Regs.PRD.all = 0xFFFFFFFFU;/* max Period*/
      CpuTimer2Regs.TIM.all = 0xFFFFFFFFU;/* set Ctr*/
      CpuTimer2Regs.TPR.all = 0x00U;   /* no prescaler    */
      StartCpuTimer2();
    }

    /* SystemInitialize for Atomic SubSystem: '<Root>/Speed Control' */
    iPMSM_F28_SpeedControl_Init(&iPMSM_F28069M_B.SpeedControl,
      &iPMSM_F28069M_DWork.SpeedControl);

    /* End of SystemInitialize for SubSystem: '<Root>/Speed Control' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Heartbeat LED' */
    /* Start for S-Function (c280xgpio_do): '<S386>/Digital Output1' */
    EALLOW;
    GpioCtrlRegs.GPBMUX1.all &= 0xFFFFFFCFU;
    GpioCtrlRegs.GPBDIR.all |= 0x4U;
    EDIS;

    /* End of SystemInitialize for SubSystem: '<Root>/Heartbeat LED' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Hardware Init' */
    /* Start for S-Function (c280xgpio_do): '<S377>/Digital Output' */
    EALLOW;
    GpioCtrlRegs.GPBMUX2.all &= 0xFFFFFFCFU;
    GpioCtrlRegs.GPBDIR.all |= 0x40000U;
    EDIS;

    /* SystemInitialize for Enabled SubSystem: '<S375>/Calculate ADC Offset ' */
    /* SystemInitialize for Iterator SubSystem: '<S376>/For Iterator Subsystem' */
    /* Start for S-Function (c2802xadc): '<S379>/IA//IB Measurement' */
    if (MW_adcInitFlag == 0U) {
      InitAdc();
      MW_adcInitFlag = 1U;
    }

    config_ADC_SOC2_SOC3 ();

    /* End of SystemInitialize for SubSystem: '<S376>/For Iterator Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S375>/Calculate ADC Offset ' */

    /* Constant: '<S3>/6PWM_Mode' */
    iPMS_SPIMasterTransfer_Init(&iPMSM_F28069M_DWork.SPIMasterTransfer);

    /* Constant: '<S3>/ADC_Gain_Setting' */
    iPMS_SPIMasterTransfer_Init(&iPMSM_F28069M_DWork.SPIMasterTransfer1);

    /* End of SystemInitialize for SubSystem: '<Root>/Hardware Init' */

    /* Outputs for Atomic SubSystem: '<Root>/Hardware Init' */
    /* Constant: '<S3>/6PWM_Mode' */
    iPMSM_F28_SPIMasterTransfer(14870U, &iPMSM_F28069M_B.SPIMasterTransfer,
      &iPMSM_F28069M_DWork.SPIMasterTransfer);

    /* Constant: '<S3>/ADC_Gain_Setting' */
    iPMSM_F28_SPIMasterTransfer(20480U, &iPMSM_F28069M_B.SPIMasterTransfer1,
      &iPMSM_F28069M_DWork.SPIMasterTransfer1);

    /* S-Function (c280xgpio_do): '<S377>/Digital Output' incorporates:
     *  Constant: '<S377>/DRV830x_Enable'
     */
    {
      if ((1U)) {
        GpioDataRegs.GPBSET.bit.GPIO50 = 1U;
      } else {
        GpioDataRegs.GPBCLEAR.bit.GPIO50 = 1U;
      }
    }

    /* Outputs for Enabled SubSystem: '<S375>/Calculate ADC Offset ' incorporates:
     *  EnablePort: '<S376>/Enable'
     */
    /* Outputs for Iterator SubSystem: '<S376>/For Iterator Subsystem' incorporates:
     *  ForIterator: '<S379>/For Iterator'
     */
    for (s379_iter = 1U; s379_iter < 17U; s379_iter++) {
      /* Outputs for Iterator SubSystem: '<S376>/For Iterator Subsystem' incorporates:
       *  ForIterator: '<S379>/For Iterator'
       */
      iPMSM_F28069M_B.ForIterator = s379_iter;

      /* S-Function (c2802xadc): '<S379>/IA//IB Measurement' */
      {
        /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
        /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
        AdcRegs.ADCSOCFRC1.bit.SOC2 = 1U;

        /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

        asm(" RPT #70|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

        float wait_index;
        for (wait_index= 11; wait_index > 0; wait_index--)
          __mnop();

#endif

        iPMSM_F28069M_B.IAIBMeasurement[0] = (AdcResult.ADCRESULT2);
        iPMSM_F28069M_B.IAIBMeasurement[1] = (AdcResult.ADCRESULT3);
      }

      /* If: '<S379>/If' */
      if (iPMSM_F28069M_B.ForIterator > 8U) {
        /* Outputs for IfAction SubSystem: '<S379>/If Action Subsystem' incorporates:
         *  ActionPort: '<S384>/Action Port'
         */
        /* Memory: '<S384>/Memory' */
        iPMSM_F28069M_B.Memory = iPMSM_F28069M_DWork.Memory_PreviousInput;

        /* Sum: '<S384>/Sum' */
        iPMSM_F28069M_B.Sum_dn = iPMSM_F28069M_B.IAIBMeasurement[0] +
          iPMSM_F28069M_B.Memory;

        /* Memory: '<S384>/Memory1' */
        iPMSM_F28069M_B.Memory1 = iPMSM_F28069M_DWork.Memory1_PreviousInput;

        /* Sum: '<S384>/Sum1' */
        iPMSM_F28069M_B.Sum1_dq = iPMSM_F28069M_B.IAIBMeasurement[1] +
          iPMSM_F28069M_B.Memory1;

        /* Update for Memory: '<S384>/Memory' */
        iPMSM_F28069M_DWork.Memory_PreviousInput = iPMSM_F28069M_B.Sum_dn;

        /* Update for Memory: '<S384>/Memory1' */
        iPMSM_F28069M_DWork.Memory1_PreviousInput = iPMSM_F28069M_B.Sum1_dq;

        /* End of Outputs for SubSystem: '<S379>/If Action Subsystem' */
      }

      /* End of If: '<S379>/If' */
    }

    /* End of Outputs for SubSystem: '<S376>/For Iterator Subsystem' */

    /* Product: '<S376>/Divide' incorporates:
     *  Constant: '<S376>/Constant'
     */
    iPMSM_F28069M_B.Divide_h = (uint16_T)((real_T)iPMSM_F28069M_B.Sum_dn / 8.0);

    /* If: '<S376>/If' incorporates:
     *  Constant: '<S376>/Constant1'
     *  Constant: '<S376>/Constant2'
     */
    if ((iPMSM_F28069M_B.Divide_h > 1500U) && (iPMSM_F28069M_B.Divide_h < 2500U))
    {
      /* Outputs for IfAction SubSystem: '<S376>/If Action Subsystem' incorporates:
       *  ActionPort: '<S380>/Action Port'
       */
      /* DataStoreWrite: '<S380>/Data Store Write1' */
      iPMSM_F28069M_DWork.IaOffset = iPMSM_F28069M_B.Divide_h;

      /* End of Outputs for SubSystem: '<S376>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S376>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S381>/Action Port'
       */
      /* DataStoreWrite: '<S381>/Data Store Write1' incorporates:
       *  Constant: '<S381>/Constant'
       */
      iPMSM_F28069M_DWork.IaOffset = 2087U;

      /* End of Outputs for SubSystem: '<S376>/If Action Subsystem1' */
    }

    /* End of If: '<S376>/If' */

    /* Product: '<S376>/Divide1' incorporates:
     *  Constant: '<S376>/Constant'
     */
    iPMSM_F28069M_B.Divide1_e = (uint16_T)((real_T)iPMSM_F28069M_B.Sum1_dq / 8.0);

    /* If: '<S376>/If1' incorporates:
     *  Constant: '<S376>/Constant1'
     *  Constant: '<S376>/Constant2'
     */
    if ((iPMSM_F28069M_B.Divide1_e > 1500U) && (iPMSM_F28069M_B.Divide1_e <
         2500U)) {
      /* Outputs for IfAction SubSystem: '<S376>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S382>/Action Port'
       */
      /* DataStoreWrite: '<S382>/Data Store Write2' */
      iPMSM_F28069M_DWork.IbOffset = iPMSM_F28069M_B.Divide1_e;

      /* End of Outputs for SubSystem: '<S376>/If Action Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S376>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S383>/Action Port'
       */
      /* DataStoreWrite: '<S383>/Data Store Write2' incorporates:
       *  Constant: '<S383>/Constant1'
       */
      iPMSM_F28069M_DWork.IbOffset = 2082U;

      /* End of Outputs for SubSystem: '<S376>/If Action Subsystem3' */
    }

    /* End of If: '<S376>/If1' */
    /* End of Outputs for SubSystem: '<S375>/Calculate ADC Offset ' */

    /* Logic: '<S375>/NOT' */
    iPMSM_F28069M_B.NOT = false;

    /* Outputs for Enabled SubSystem: '<S375>/Default ADC Offset' incorporates:
     *  EnablePort: '<S378>/Enable'
     */
    if (iPMSM_F28069M_B.NOT) {
      /* DataStoreWrite: '<S378>/Data Store Write1' incorporates:
       *  Constant: '<S378>/Constant'
       */
      iPMSM_F28069M_DWork.IaOffset = 2087U;

      /* DataStoreWrite: '<S378>/Data Store Write2' incorporates:
       *  Constant: '<S378>/Constant1'
       */
      iPMSM_F28069M_DWork.IbOffset = 2082U;
    }

    /* End of Outputs for SubSystem: '<S375>/Default ADC Offset' */
    /* End of Outputs for SubSystem: '<Root>/Hardware Init' */
  }
}

/* Model terminate function */
void iPMSM_F28069M_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/Hardware Init' */
  iPMS_SPIMasterTransfer_Term(&iPMSM_F28069M_DWork.SPIMasterTransfer);
  iPMS_SPIMasterTransfer_Term(&iPMSM_F28069M_DWork.SPIMasterTransfer1);

  /* End of Terminate for SubSystem: '<Root>/Hardware Init' */
}

void iPMSM_F28069M_configure_interrupts(void)
{
  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(32,&ADCINT1,1);
  HWI_TIC28x_EnableIRQ(32);

  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(96,&SCIRXINTA,0);
  HWI_TIC28x_EnableIRQ(96);
}

/* Hardware Interrupt Block: '<S371>/Hardware Interrupt' */
interrupt void ADCINT1(void)
{
  /* Event: Default Event */
  if (1 == runModel) {
    {
      int16_T tmp;

      /* RateTransition: '<Root>/RT2' */
      tmp = iPMSM_F28069M_DWork.RT2_ActiveBufIdx << 1U;
      iPMSM_F28069M_B.RT2[0] = iPMSM_F28069M_DWork.RT2_Buffer[tmp];
      iPMSM_F28069M_B.RT2[1] = iPMSM_F28069M_DWork.RT2_Buffer[tmp + 1];

      /* S-Function (HardwareInterrupt_sfun): '<S371>/Hardware Interrupt' */
      iPMSM_F28069_CurrentControl();

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S371>/Hardware Interrupt' */

      /* RateTransition: '<Root>/RT4' */
      iPMSM_F28069M_DWork.RT4_Buffer[iPMSM_F28069M_DWork.RT4_semaphoreTaken == 0]
        = iPMSM_F28069M_B.Speed_fb_PU;
      iPMSM_F28069M_DWork.RT4_ActiveBufIdx =
        (iPMSM_F28069M_DWork.RT4_semaphoreTaken == 0);
    }
  }

  /* Clear occurred EOC event event */
  AdcRegs.ADCINTFLGCLR.bit.ADCINT1= 1;

  /* Clear occurred Overflow event event */
  AdcRegs.ADCINTOVFCLR.bit.ADCINT1= 1;
  HWI_TIC28x_AcknowledgeIrq(32);
}

/* Hardware Interrupt Block: '<S373>/Hardware Interrupt' */
interrupt void SCIRXINTA(void)
{
  volatile unsigned int PIEIER1_stack_save = PieCtrlRegs.PIEIER1.all;
  volatile unsigned int PIEIER9_stack_save = PieCtrlRegs.PIEIER9.all;
  PieCtrlRegs.PIEIER1.all &= ~65;
                              /*disable group1 lower/equal priority interrupts*/
  PieCtrlRegs.PIEIER9.all &= ~1;
                              /*disable group9 lower/equal priority interrupts*/
  asm(" RPT #5 || NOP");               /*wait 5 cycles        */
  IFR &= ~257;    /*eventually disable lower/equal priority pending interrupts*/
  PieCtrlRegs.PIEACK.all = 257;
                   /*ACK to allow other interrupts from the same group to fire*/
  IER |= 256;
  EINT;

  /* Event: Default Event */
  if (1 == runModel) {
    {
      /* S-Function (HardwareInterrupt_sfun): '<S373>/Hardware Interrupt' */

      /* Output and update for function-call system: '<Root>/Serial Receive' */
      {
        int16_T DataTypeConversion2;

        /* S-Function (c28xsci_rx): '<S390>/SCI Receive' */
        {
          int16_T i;
          int16_T errFlg = NOERROR;
          uint16_T isHeadReceived = 1U;

          //get data as uint16 in recBuff
          uint16_T recbuff[2];
          for (i = 0; i < 2; i++) {
            recbuff[i] = 0U;
          }

          errFlg = NOERROR;

          /* Receiving data: For uint32 and uint16, rcvBuff will contain uint16 data */
          if (isHeadReceived) {
            errFlg = scia_rcv(recbuff, 4, 2);
            asm(" NOP");
            if ((errFlg == NOERROR) || (errFlg == PARTIALDATA)) {
              memcpy( &iPMSM_F28069M_B.SCIReceive[0], recbuff,2);
            }
          }
        }

        /* DataTypeConversion: '<S388>/Data Type Conversion2' */
        DataTypeConversion2 = (int16_T)iPMSM_F28069M_B.SCIReceive[0];
        iPMSM_F28069M_B.DataTypeConversion2[0] = DataTypeConversion2;

        /* DataTypeConversion: '<S388>/Data Type Conversion1' incorporates:
         *  DataTypeConversion: '<S388>/Data Type Conversion2'
         */
        iPMSM_F28069M_B.DataTypeConversion1[0] = (real32_T)DataTypeConversion2 *
          0.000244140625F;

        /* DataTypeConversion: '<S388>/Data Type Conversion2' */
        DataTypeConversion2 = (int16_T)iPMSM_F28069M_B.SCIReceive[1];
        iPMSM_F28069M_B.DataTypeConversion2[1] = DataTypeConversion2;

        /* DataTypeConversion: '<S388>/Data Type Conversion1' incorporates:
         *  DataTypeConversion: '<S388>/Data Type Conversion2'
         */
        iPMSM_F28069M_B.DataTypeConversion1[1] = (real32_T)DataTypeConversion2 *
          0.000244140625F;

        /* DataTypeConversion: '<S6>/Data Type Conversion3' */
        iPMSM_F28069M_B.DataTypeConversion3_b =
          (iPMSM_F28069M_B.DataTypeConversion1[1] != 0.0F);

        /* DataStoreWrite: '<S6>/Data Store Write' */
        iPMSM_F28069M_DWork.Enable = iPMSM_F28069M_B.DataTypeConversion3_b;

        /* DataTypeConversion: '<S6>/Data Type Conversion1' */
        iPMSM_F28069M_B.Speed_Ref = iPMSM_F28069M_B.DataTypeConversion1[0];

        /* DataStoreWrite: '<S6>/Data Store Write1' */
        iPMSM_F28069M_DWork.Speed_ref = iPMSM_F28069M_B.Speed_Ref;
      }

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S373>/Hardware Interrupt' */

      /* RateTransition: '<Root>/RT6' */
      iPMSM_F28069M_DWork.RT6_Buffer[iPMSM_F28069M_DWork.RT6_semaphoreTaken == 0]
        = iPMSM_F28069M_B.Speed_Ref;
      iPMSM_F28069M_DWork.RT6_ActiveBufIdx =
        (iPMSM_F28069M_DWork.RT6_semaphoreTaken == 0);
    }
  }

  /* Clear occurred Rx event event */
  EALLOW;
  SciaRegs.SCIFFRX.bit.RXFFINTCLR= 1;
  EDIS;

  /* Clear occurred Rx FIFO overflow event */
  EALLOW;
  SciaRegs.SCIFFRX.bit.RXFFOVRCLR= 1;
  EDIS;
  DINT;
  /* disable global interrupts during context switch, CPU will enable global interrupts after exiting ISR */
  PieCtrlRegs.PIEIER1.all = PIEIER1_stack_save;
                                   /*restore PIEIER register that was modified*/
  PieCtrlRegs.PIEIER9.all = PIEIER9_stack_save;
                                   /*restore PIEIER register that was modified*/
  HWI_TIC28x_AcknowledgeIrq(96);
}

void iPMSM_F28069M_unconfigure_interrupts (void)
{
  HWI_TIC28x_DisableIRQ(32);
  HWI_TIC28x_DisableIRQ(96);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Motor_Control_01.c
 *
 * Code generated for Simulink model 'Motor_Control_01'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Wed Jun  7 14:55:12 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. Traceability
 * Validation result: Not run
 */

#include "Motor_Control_01.h"
#include "rtwtypes.h"

/* Exported block signals */
uint16_T Task_1ms_Cnt;                 /* '<S2>/Add' */
uint16_T Task_10ms_Cnt;                /* '<S1>/Add' */

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Motor_Control_01_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(rtM, 1));
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
  (rtM->Timing.TaskCounters.TID[1])++;
  if ((rtM->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.01s, 0.0s] */
    rtM->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void Task_1ms(void)                    /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Sum: '<S2>/Add' incorporates:
   *  Constant: '<S2>/Constant'
   */
  Task_1ms_Cnt += rtP.Constant_Value;
}

/* Model step function for TID1 */
void Task_10ms(void)                   /* Sample time: [0.01s, 0.0s] */
{
  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant'
   */
  Task_10ms_Cnt += rtP.Constant_Value_c;
}

/* Model initialize function */
void Motor_Control_01_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)rtM, 0,
                sizeof(RT_MODEL));

  /* block I/O */

  /* exported global signals */
  Task_1ms_Cnt = 0U;
  Task_10ms_Cnt = 0U;

  /* InitializeConditions for Sum: '<S2>/Add' incorporates:
   *  Delay: '<S2>/Delay'
   */
  Task_1ms_Cnt = rtP.Delay_InitialCondition;

  /* InitializeConditions for Sum: '<S1>/Add' incorporates:
   *  Delay: '<S1>/Delay'
   */
  Task_10ms_Cnt = rtP.Delay_InitialCondition_j;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

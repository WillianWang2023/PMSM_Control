/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Motor_Control_01.h
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

#ifndef RTW_HEADER_Motor_Control_01_h_
#define RTW_HEADER_Motor_Control_01_h_
#ifndef Motor_Control_01_COMMON_INCLUDES_
#define Motor_Control_01_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Motor_Control_01_COMMON_INCLUDES_ */

#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#define Motor_Control_01_M             (rtM)

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Parameters (default storage) */
struct P_ {
  uint16_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S2>/Constant'
                                        */
  uint16_T Delay_InitialCondition; /* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<S2>/Delay'
                                    */
  uint16_T Constant_Value_c;           /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S1>/Constant'
                                        */
  uint16_T Delay_InitialCondition_j;
                                 /* Computed Parameter: Delay_InitialCondition_j
                                  * Referenced by: '<S1>/Delay'
                                  */
};

/* Parameters (default storage) */
typedef struct P_ P;

/* Real-time Model Data Structure */
struct tag_RTM {
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P rtP;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern uint16_T Task_1ms_Cnt;          /* '<S2>/Add' */
extern uint16_T Task_10ms_Cnt;         /* '<S1>/Add' */

/* External function called from main */
extern void Motor_Control_01_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Motor_Control_01_initialize(void);
extern void Task_1ms(void);
extern void Task_10ms(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Motor_Control_01'
 * '<S1>'   : 'Motor_Control_01/Task_10ms'
 * '<S2>'   : 'Motor_Control_01/Task_1ms'
 */

/*-
 * Requirements for '<Root>': Motor_Control_01

 */
#endif                                 /* RTW_HEADER_Motor_Control_01_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

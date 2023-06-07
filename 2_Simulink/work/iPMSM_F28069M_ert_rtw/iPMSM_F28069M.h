/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: iPMSM_F28069M.h
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

#ifndef RTW_HEADER_iPMSM_F28069M_h_
#define RTW_HEADER_iPMSM_F28069M_h_
#ifndef iPMSM_F28069M_COMMON_INCLUDES_
#define iPMSM_F28069M_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "F2806x_Device.h"
#include "F2806x_Gpio.h"
#include "DSP28xx_SciUtil.h"
#include "F2806x_Examples.h"
#include "IQmathLib.h"
#include "MW_SPI.h"
#endif                                 /* iPMSM_F28069M_COMMON_INCLUDES_ */

#include "MW_c2000ISR.h"
#include "iPMSM_F28069M_types.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <stddef.h>
#include "zero_crossing_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

extern void init_SCI(void);
extern void init_SCI_GPIO(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);

/* Block signals for system '<S142>/Accumulate' */
typedef struct {
  real32_T Add;                        /* '<S143>/Add' */
  real32_T DataTypeConversion1;        /* '<S143>/Data Type Conversion1' */
  real32_T Add1;                       /* '<S143>/Add1' */
  real32_T Input;                      /* '<S144>/Input' */
  int16_T DataTypeConversion;          /* '<S143>/Data Type Conversion' */
  boolean_T Delay;                     /* '<S143>/Delay' */
} rtB_Accumulate_iPMSM_F28069M;

/* Block states (default storage) for system '<S142>/Accumulate' */
typedef struct {
  boolean_T Delay_DSTATE;              /* '<S143>/Delay' */
} rtDW_Accumulate_iPMSM_F28069M;

/* Block signals for system '<S147>/If Action Subsystem' */
typedef struct {
  real32_T Convert_back;               /* '<S149>/Convert_back' */
  int16_T Convert_uint16;              /* '<S149>/Convert_uint16' */
} rtB_IfActionSubsystem_iPMSM_F28;

/* Block signals for system '<S147>/If Action Subsystem1' */
typedef struct {
  real32_T Convert_back;               /* '<S150>/Convert_back' */
  int16_T Convert_uint16;              /* '<S150>/Convert_uint16' */
} rtB_IfActionSubsystem1_iPMSM_F2;

/* Block signals for system '<S338>/Dir_Sense' */
typedef struct {
  int16_T Switch;                      /* '<S346>/Switch' */
  boolean_T LogicalOperator;           /* '<S346>/Logical Operator' */
} rtB_Dir_Sense_iPMSM_F28069M;

/* Zero-crossing (trigger) state for system '<S338>/Dir_Sense' */
typedef struct {
  ZCSigState Dir_Sense_Trig_ZCE;       /* '<S338>/Dir_Sense' */
} rtZCE_Dir_Sense_iPMSM_F28069M;

/* Block signals for system '<S377>/SPI Master Transfer' */
typedef struct {
  uint16_T SPIMasterTransfer;          /* '<S377>/SPI Master Transfer' */
} rtB_SPIMasterTransfer_iPMSM_F28;

/* Block states (default storage) for system '<S377>/SPI Master Transfer' */
typedef struct {
  codertarget_tic2000_blocks_SPIM obj; /* '<S377>/SPI Master Transfer' */
  boolean_T objisempty;                /* '<S377>/SPI Master Transfer' */
} rtDW_SPIMasterTransfer_iPMSM_F2;

/* Block signals for system '<Root>/Speed Control' */
typedef struct {
  real32_T Id_Ref;                     /* '<S7>/Id_Ref' */
  real32_T RateLimiter;                /* '<S392>/Rate Limiter' */
  real32_T RateLimiter1;               /* '<S392>/Rate Limiter1' */
  real32_T Speed_Ref;                  /* '<S393>/Switch' */
  real32_T Product;                    /* '<S448>/Product' */
  real32_T UnitDelay;                  /* '<S448>/Unit Delay' */
  real32_T Product1;                   /* '<S448>/Product1' */
  real32_T Add1;                       /* '<S448>/Add1' */
  real32_T Sum;                        /* '<S391>/Sum' */
  real32_T PProdOut;                   /* '<S434>/PProd Out' */
  real32_T Ki2;                        /* '<S391>/Ki2' */
  real32_T Integrator;                 /* '<S429>/Integrator' */
  real32_T Sum_g;                      /* '<S438>/Sum' */
  real32_T DeadZone;                   /* '<S422>/DeadZone' */
  real32_T IProdOut;                   /* '<S426>/IProd Out' */
  real32_T Switch;                     /* '<S420>/Switch' */
  real32_T Saturation;                 /* '<S436>/Saturation' */
  real32_T DataStoreRead;              /* '<S393>/Data Store Read' */
  real32_T Switch1;                    /* '<S393>/Switch1' */
  real32_T Switch_a;                   /* '<S392>/Switch' */
  int16_T Switch1_c;                   /* '<S420>/Switch1' */
  int16_T Switch2;                     /* '<S420>/Switch2' */
  boolean_T DataStoreRead1;            /* '<S391>/Data Store Read1' */
  boolean_T DataStoreRead2;            /* '<S391>/Data Store Read2' */
  boolean_T AND;                       /* '<S391>/AND' */
  boolean_T DataStoreRead1_p;          /* '<S393>/Data Store Read1' */
  boolean_T LogicalOperator;           /* '<S391>/Logical Operator' */
  boolean_T RelationalOperator;        /* '<S420>/Relational Operator' */
  boolean_T fixforDTpropagationissue;/* '<S420>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1;
                                    /* '<S420>/fix for DT propagation issue1' */
  boolean_T Equal1;                    /* '<S420>/Equal1' */
  boolean_T AND3;                      /* '<S420>/AND3' */
} rtB_SpeedControl_iPMSM_F28069M;

/* Block states (default storage) for system '<Root>/Speed Control' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S448>/Unit Delay' */
  real32_T Integrator_DSTATE;          /* '<S429>/Integrator' */
  real32_T PrevY;                      /* '<S392>/Rate Limiter' */
  real32_T PrevY_f;                    /* '<S392>/Rate Limiter1' */
  int16_T Integrator_PrevResetState;   /* '<S429>/Integrator' */
} rtDW_SpeedControl_iPMSM_F28069M;

/* Block signals (default storage) */
typedef struct {
  uint32_T Sum[4];                     /* '<S20>/Sum' */
  uint32_T Sum_d[4];                   /* '<S197>/Sum' */
  uint32_T PositionToCount;            /* '<S307>/PositionToCount' */
  uint32_T Delay;                      /* '<S307>/Delay' */
  uint32_T PositionToCount_i;          /* '<S344>/PositionToCount' */
  uint32_T Delay_l;                    /* '<S344>/Delay' */
  real32_T RT6;                        /* '<Root>/RT6' */
  real32_T RT4;                        /* '<Root>/RT4' */
  real32_T RT2[2];                     /* '<Root>/RT2' */
  real32_T DataTypeConversion1[2];     /* '<S388>/Data Type Conversion1' */
  real32_T Speed_Ref;                  /* '<S6>/Data Type Conversion1' */
  real32_T DataStoreRead;              /* '<S18>/Data Store Read' */
  real32_T Abs;                        /* '<S18>/Abs' */
  real32_T Gain;                       /* '<S18>/Gain' */
  real32_T UnitDelay;                  /* '<S142>/Unit Delay' */
  real32_T Delay5[4];                  /* '<S1>/Delay5' */
  real32_T Switch;                     /* '<S18>/Switch' */
  real32_T Merge;                      /* '<S147>/Merge' */
  real32_T indexing;                   /* '<S20>/indexing' */
  real32_T Lookup[4];                  /* '<S20>/Lookup' */
  real32_T Sum3;                       /* '<S146>/Sum3' */
  real32_T DataTypeConversion1_m;      /* '<S20>/Data Type Conversion1' */
  real32_T Sum2;                       /* '<S20>/Sum2' */
  real32_T Product;                    /* '<S146>/Product' */
  real32_T Sum4;                       /* '<S146>/Sum4' */
  real32_T Sum5;                       /* '<S146>/Sum5' */
  real32_T Product1;                   /* '<S146>/Product1' */
  real32_T Sum6;                       /* '<S146>/Sum6' */
  real32_T Sum_m;                      /* '<S24>/Sum' */
  real32_T PProdOut;                   /* '<S129>/PProd Out' */
  real32_T UnitDelay_p;                /* '<S24>/Unit Delay' */
  real32_T Integrator;                 /* '<S124>/Integrator' */
  real32_T Sum_a;                      /* '<S133>/Sum' */
  real32_T Switch_j;                   /* '<S24>/Switch' */
  real32_T Sum_g;                      /* '<S23>/Sum' */
  real32_T PProdOut_c;                 /* '<S78>/PProd Out' */
  real32_T UnitDelay_i;                /* '<S23>/Unit Delay' */
  real32_T Integrator_i;               /* '<S73>/Integrator' */
  real32_T Sum_n;                      /* '<S82>/Sum' */
  real32_T Switch_d;                   /* '<S23>/Switch' */
  real32_T Switch_jv;                  /* '<S27>/Switch' */
  real32_T Product_l;                  /* '<S27>/Product' */
  real32_T Product_o;                  /* '<S28>/Product' */
  real32_T Product1_a;                 /* '<S28>/Product1' */
  real32_T Sum1;                       /* '<S28>/Sum1' */
  real32_T Merge_m[2];                 /* '<S22>/Merge' */
  real32_T DeadZone;                   /* '<S66>/DeadZone' */
  real32_T IProdOut;                   /* '<S70>/IProd Out' */
  real32_T Switch_o;                   /* '<S64>/Switch' */
  real32_T DeadZone_n;                 /* '<S117>/DeadZone' */
  real32_T IProdOut_n;                 /* '<S121>/IProd Out' */
  real32_T Switch_l;                   /* '<S115>/Switch' */
  real32_T DataTypeConversion;         /* '<S13>/Data Type Conversion' */
  real32_T Speed_fb_PU;                /* '<S1>/Input Scaling' */
  real32_T TmpSignalConversionAtDelay5Inpo[4];
  real32_T sqrt3_by_two;               /* '<S156>/sqrt3_by_two' */
  real32_T one_by_two;                 /* '<S156>/one_by_two' */
  real32_T add_c;                      /* '<S156>/add_c' */
  real32_T add_b;                      /* '<S156>/add_b' */
  real32_T Min;                        /* '<S154>/Min' */
  real32_T Max;                        /* '<S154>/Max' */
  real32_T Add;                        /* '<S154>/Add' */
  real32_T one_by_two_d;               /* '<S154>/one_by_two' */
  real32_T Add3;                       /* '<S153>/Add3' */
  real32_T Add2;                       /* '<S153>/Add2' */
  real32_T Add1;                       /* '<S153>/Add1' */
  real32_T Gain_c[3];                  /* '<S153>/Gain' */
  real32_T Gain_c1[3];                 /* '<S13>/Gain' */
  real32_T PWM_Duty_Cycles[3];         /* '<S13>/Sum' */
  real32_T Merge_k[2];                 /* '<S166>/Merge' */
  real32_T Delay1;                     /* '<S170>/Delay1' */
  real32_T Delay_f[2];                 /* '<S171>/Delay' */
  real32_T Gain_m;                     /* '<S176>/Gain' */
  real32_T UnaryMinus;                 /* '<S184>/Unary Minus' */
  real32_T Product1_f;                 /* '<S173>/Product1' */
  real32_T Gain1;                      /* '<S183>/Gain1' */
  real32_T Product2;                   /* '<S184>/Product2' */
  real32_T Product_k;                  /* '<S173>/Product' */
  real32_T Gain_n;                     /* '<S183>/Gain' */
  real32_T Product_i;                  /* '<S184>/Product' */
  real32_T Sum_mr;                     /* '<S184>/Sum' */
  real32_T Product1_ao;                /* '<S184>/Product1' */
  real32_T Product3;                   /* '<S184>/Product3' */
  real32_T Sum1_m;                     /* '<S184>/Sum1' */
  real32_T Product3_n;                 /* '<S173>/Product3' */
  real32_T Product1_o;                 /* '<S180>/Product1' */
  real32_T Product2_c;                 /* '<S173>/Product2' */
  real32_T Gain_g;                     /* '<S175>/Gain' */
  real32_T Product3_n0;                /* '<S180>/Product3' */
  real32_T Sum1_c;                     /* '<S180>/Sum1' */
  real32_T Product1_h;                 /* '<S179>/Product1' */
  real32_T UnaryMinus_k;               /* '<S179>/Unary Minus' */
  real32_T UnaryMinus_f;               /* '<S180>/Unary Minus' */
  real32_T Product2_a;                 /* '<S180>/Product2' */
  real32_T Product_g;                  /* '<S180>/Product' */
  real32_T Sum_i;                      /* '<S180>/Sum' */
  real32_T Product_kc;                 /* '<S179>/Product' */
  real32_T UnaryMinus_fm;              /* '<S181>/Unary Minus' */
  real32_T Gain1_o;                    /* '<S178>/Gain1' */
  real32_T UnaryMinus1;                /* '<S178>/Unary Minus1' */
  real32_T Product2_d;                 /* '<S181>/Product2' */
  real32_T Gain_j;                     /* '<S178>/Gain' */
  real32_T UnaryMinus_i;               /* '<S178>/Unary Minus' */
  real32_T Product_f;                  /* '<S181>/Product' */
  real32_T Sum_e;                      /* '<S181>/Sum' */
  real32_T Product1_oz;                /* '<S181>/Product1' */
  real32_T Product3_nb;                /* '<S181>/Product3' */
  real32_T Sum1_k;                     /* '<S181>/Sum1' */
  real32_T UnaryMinus_j;               /* '<S182>/Unary Minus' */
  real32_T Product_n;                  /* '<S177>/Product' */
  real32_T Product3_c;                 /* '<S177>/Product3' */
  real32_T UnaryMinus1_b;              /* '<S177>/Unary Minus1' */
  real32_T Product5;                   /* '<S177>/Product5' */
  real32_T Sum1_i;                     /* '<S177>/Sum1' */
  real32_T Product2_o;                 /* '<S182>/Product2' */
  real32_T Product4;                   /* '<S177>/Product4' */
  real32_T Product1_b;                 /* '<S177>/Product1' */
  real32_T UnaryMinus_g;               /* '<S177>/Unary Minus' */
  real32_T Product2_f;                 /* '<S177>/Product2' */
  real32_T Sum_k;                      /* '<S177>/Sum' */
  real32_T Product_gf;                 /* '<S182>/Product' */
  real32_T Sum_h;                      /* '<S182>/Sum' */
  real32_T Product1_d;                 /* '<S182>/Product1' */
  real32_T Product3_g;                 /* '<S182>/Product3' */
  real32_T Sum1_j;                     /* '<S182>/Sum1' */
  real32_T Sum_l[2];                   /* '<S175>/Sum' */
  real32_T Sum_n2[2];                  /* '<S171>/Sum' */
  real32_T Gain1_c[2];                 /* '<S171>/Gain1' */
  real32_T Sum2_o[2];                  /* '<S171>/Sum2' */
  real32_T Gain2[2];                   /* '<S171>/Gain2' */
  real32_T Sum1_j4[2];                 /* '<S171>/Sum1' */
  real32_T Product_m[2];               /* '<S170>/Product' */
  real32_T Product_j[2];               /* '<S187>/Product' */
  real32_T UnitDelay_j[2];             /* '<S187>/Unit Delay' */
  real32_T Product1_e[2];              /* '<S187>/Product1' */
  real32_T Add1_j[2];                  /* '<S187>/Add1' */
  real32_T Delay_e;                    /* '<S189>/Delay' */
  real32_T Merge_h;                    /* '<S253>/Merge' */
  real32_T indexing_j;                 /* '<S197>/indexing' */
  real32_T Lookup_i[4];                /* '<S197>/Lookup' */
  real32_T Sum5_o;                     /* '<S252>/Sum5' */
  real32_T DataTypeConversion1_ma;     /* '<S197>/Data Type Conversion1' */
  real32_T Sum2_c;                     /* '<S197>/Sum2' */
  real32_T Product1_k;                 /* '<S252>/Product1' */
  real32_T Sum6_a;                     /* '<S252>/Sum6' */
  real32_T Merge_k4;                   /* '<S188>/Merge' */
  real32_T Square;                     /* '<S194>/Square' */
  real32_T Merge1;                     /* '<S188>/Merge1' */
  real32_T Square1;                    /* '<S194>/Square1' */
  real32_T Sum_e2;                     /* '<S194>/Sum' */
  real32_T Sqrt;                       /* '<S194>/Sqrt' */
  real32_T Switch_b;                   /* '<S194>/Switch' */
  real32_T Divide1;                    /* '<S194>/Divide1' */
  real32_T Product_la;                 /* '<S189>/Product' */
  real32_T Divide;                     /* '<S194>/Divide' */
  real32_T Sum3_m;                     /* '<S252>/Sum3' */
  real32_T Product_ig;                 /* '<S252>/Product' */
  real32_T Sum4_j;                     /* '<S252>/Sum4' */
  real32_T Product1_dd;                /* '<S189>/Product1' */
  real32_T Sum_b;                      /* '<S189>/Sum' */
  real32_T ProportionalGain;           /* '<S238>/Proportional Gain' */
  real32_T IntegralGain;               /* '<S230>/Integral Gain' */
  real32_T Integrator_c;               /* '<S233>/Integrator' */
  real32_T Sum_dd;                     /* '<S242>/Sum' */
  real32_T Merge_g;                    /* '<S198>/Merge' */
  real32_T Product_kr;                 /* '<S283>/Product' */
  real32_T UnitDelay_l;                /* '<S283>/Unit Delay' */
  real32_T Product1_ff;                /* '<S283>/Product1' */
  real32_T Add1_d;                     /* '<S283>/Add1' */
  real32_T speed;                      /* '<S189>/Sum1' */
  real32_T Gain_i;                     /* '<S189>/Gain' */
  real32_T UnitDelay_b;                /* '<S196>/Unit Delay' */
  real32_T Product_iq;                 /* '<S201>/Product' */
  real32_T UnitDelay_im;               /* '<S201>/Unit Delay' */
  real32_T Product1_ok;                /* '<S201>/Product1' */
  real32_T Add1_h;                     /* '<S201>/Add1' */
  real32_T Delay2;                     /* '<S294>/Delay2' */
  real32_T Delay3;                     /* '<S294>/Delay3' */
  real32_T Product_oq;                 /* '<S303>/Product' */
  real32_T UnitDelay_n;                /* '<S303>/Unit Delay' */
  real32_T Product1_n;                 /* '<S303>/Product1' */
  real32_T Add1_a;                     /* '<S303>/Add1' */
  real32_T Gain_h;                     /* '<S294>/Gain' */
  real32_T Sum1_cg;                    /* '<S294>/Sum1' */
  real32_T Gain1_a;                    /* '<S294>/Gain1' */
  real32_T Delay2_i;                   /* '<S295>/Delay2' */
  real32_T Delay3_n;                   /* '<S295>/Delay3' */
  real32_T Product_n1;                 /* '<S300>/Product' */
  real32_T UnitDelay_bs;               /* '<S300>/Unit Delay' */
  real32_T Product1_o1;                /* '<S300>/Product1' */
  real32_T Add1_p;                     /* '<S300>/Add1' */
  real32_T Gain_is;                    /* '<S295>/Gain' */
  real32_T Sum1_a;                     /* '<S295>/Sum1' */
  real32_T Gain1_j;                    /* '<S295>/Gain1' */
  real32_T Product_e;                  /* '<S260>/Product' */
  real32_T Product1_fq;                /* '<S260>/Product1' */
  real32_T Product_ky;                 /* '<S293>/Product' */
  real32_T UnitDelay_l2;               /* '<S293>/Unit Delay' */
  real32_T Product1_dp;                /* '<S293>/Product1' */
  real32_T Add1_au;                    /* '<S293>/Add1' */
  real32_T Delay1_f;                   /* '<S286>/Delay1' */
  real32_T Sum_ad;                     /* '<S286>/Sum' */
  real32_T Gain1_f;                    /* '<S286>/Gain1' */
  real32_T Delay_a;                    /* '<S286>/Delay' */
  real32_T Gain2_f;                    /* '<S286>/Gain2' */
  real32_T Sum1_p;                     /* '<S286>/Sum1' */
  real32_T Product_d;                  /* '<S259>/Product' */
  real32_T Product_a;                  /* '<S290>/Product' */
  real32_T UnitDelay_o;                /* '<S290>/Unit Delay' */
  real32_T Product1_m;                 /* '<S290>/Product1' */
  real32_T Add1_jc;                    /* '<S290>/Add1' */
  real32_T Delay1_g;                   /* '<S287>/Delay1' */
  real32_T Sum_ia;                     /* '<S287>/Sum' */
  real32_T Gain1_ok;                   /* '<S287>/Gain1' */
  real32_T Delay_b;                    /* '<S287>/Delay' */
  real32_T Gain2_c;                    /* '<S287>/Gain2' */
  real32_T Sum1_il;                    /* '<S287>/Sum1' */
  real32_T Product1_j;                 /* '<S259>/Product1' */
  real32_T Sum_ie;                     /* '<S259>/Sum' */
  real32_T MathFunction;               /* '<S259>/Math Function' */
  real32_T Abs_p;                      /* '<S259>/Abs' */
  real32_T Delay2_n;                   /* '<S261>/Delay2' */
  real32_T Delay3_ni;                  /* '<S261>/Delay3' */
  real32_T Product_p;                  /* '<S275>/Product' */
  real32_T UnitDelay_c;                /* '<S275>/Unit Delay' */
  real32_T Product1_c;                 /* '<S275>/Product1' */
  real32_T Add1_f;                     /* '<S275>/Add1' */
  real32_T Gain_d;                     /* '<S261>/Gain' */
  real32_T Sum1_jp;                    /* '<S261>/Sum1' */
  real32_T Gain1_i;                    /* '<S261>/Gain1' */
  real32_T Delay2_d;                   /* '<S262>/Delay2' */
  real32_T Delay3_h;                   /* '<S262>/Delay3' */
  real32_T Product_pv;                 /* '<S269>/Product' */
  real32_T UnitDelay_i1;               /* '<S269>/Unit Delay' */
  real32_T Product1_o5;                /* '<S269>/Product1' */
  real32_T Add1_o;                     /* '<S269>/Add1' */
  real32_T Gain_jy;                    /* '<S262>/Gain' */
  real32_T Sum1_l;                     /* '<S262>/Sum1' */
  real32_T Gain1_e;                    /* '<S262>/Gain1' */
  real32_T Delay_e4;                   /* '<S266>/Delay' */
  real32_T Delay1_h;                   /* '<S266>/Delay1' */
  real32_T Switch1;                    /* '<S266>/Switch1' */
  real32_T Product_c;                  /* '<S272>/Product' */
  real32_T UnitDelay_jq;               /* '<S272>/Unit Delay' */
  real32_T Product1_dx;                /* '<S272>/Product1' */
  real32_T Add1_i;                     /* '<S272>/Add1' */
  real32_T Square_f;                   /* '<S257>/Square' */
  real32_T Square1_i;                  /* '<S257>/Square1' */
  real32_T Sum2_oo;                    /* '<S257>/Sum2' */
  real32_T Sqrt_n;                     /* '<S257>/Sqrt' */
  real32_T UnaryMinus_h;               /* '<S257>/Unary Minus' */
  real32_T Sum_j;                      /* '<S266>/Sum' */
  real32_T Product_ds[4];              /* '<S311>/Product' */
  real32_T UnitDelay_g[4];             /* '<S311>/Unit Delay' */
  real32_T Product1_fg[4];             /* '<S311>/Product1' */
  real32_T Add1_iq[4];                 /* '<S311>/Add1' */
  real32_T Sum6_ap[4];                 /* '<S304>/Sum6' */
  real32_T ScalingR;                   /* '<S328>/ScalingR' */
  real32_T Sum3_d;                     /* '<S325>/Sum3' */
  real32_T Delay1_c;                   /* '<S327>/Delay1' */
  real32_T Sum_nc;                     /* '<S327>/Sum' */
  real32_T Gain1_m;                    /* '<S327>/Gain1' */
  real32_T Delay_ld;                   /* '<S327>/Delay' */
  real32_T Gain2_j;                    /* '<S327>/Gain2' */
  real32_T Sum1_n;                     /* '<S327>/Sum1' */
  real32_T ScalingL;                   /* '<S328>/ScalingL' */
  real32_T Sum1_b;                     /* '<S325>/Sum1' */
  real32_T Product_iy;                 /* '<S331>/Product' */
  real32_T UnitDelay_ii;               /* '<S331>/Unit Delay' */
  real32_T Product1_b3;                /* '<S331>/Product1' */
  real32_T Add1_o0;                    /* '<S331>/Add1' */
  real32_T Switch_g;                   /* '<S325>/Switch' */
  real32_T ScalingR_k;                 /* '<S321>/ScalingR' */
  real32_T Sum3_n;                     /* '<S318>/Sum3' */
  real32_T Delay1_o;                   /* '<S320>/Delay1' */
  real32_T Sum_lg;                     /* '<S320>/Sum' */
  real32_T Gain1_ox;                   /* '<S320>/Gain1' */
  real32_T Delay_h;                    /* '<S320>/Delay' */
  real32_T Gain2_f1;                   /* '<S320>/Gain2' */
  real32_T Sum1_ni;                    /* '<S320>/Sum1' */
  real32_T ScalingL_c;                 /* '<S321>/ScalingL' */
  real32_T Sum1_g;                     /* '<S318>/Sum1' */
  real32_T Product_m5;                 /* '<S324>/Product' */
  real32_T UnitDelay_f;                /* '<S324>/Unit Delay' */
  real32_T Product1_hg;                /* '<S324>/Product1' */
  real32_T Add1_az;                    /* '<S324>/Add1' */
  real32_T Switch_h;                   /* '<S318>/Switch' */
  real32_T DTC;                        /* '<S336>/DTC' */
  real32_T SpeedGain;                  /* '<S307>/SpeedGain' */
  real32_T Product_pk;                 /* '<S334>/Product' */
  real32_T UnitDelay_d;                /* '<S334>/Unit Delay' */
  real32_T Product1_al;                /* '<S334>/Product1' */
  real32_T Add1_pz;                    /* '<S334>/Add1' */
  real32_T elect2mech;                 /* '<S168>/elect2mech' */
  real32_T Sum_f;                      /* '<S330>/Sum' */
  real32_T Sum_bp;                     /* '<S323>/Sum' */
  real32_T Atan2;                      /* '<S316>/Atan2' */
  real32_T Switch_ds;                  /* '<S316>/Switch' */
  real32_T algDD;
  real32_T Gain_f;                     /* '<S317>/Gain' */
  real32_T Switch_c;                   /* '<S317>/Switch' */
  real32_T Bias;                       /* '<S317>/Bias' */
  real32_T UnitDelay1;                 /* '<S349>/Unit Delay1' */
  real32_T UnitDelay_g4;               /* '<S349>/Unit Delay' */
  real32_T a;                          /* '<S349>/a' */
  real32_T Delay_k;                    /* '<S339>/Delay' */
  real32_T Sum2_g;                     /* '<S339>/Sum2' */
  real32_T Sum3_md;                    /* '<S349>/Sum3' */
  real32_T b_invg;                     /* '<S349>/b_inv*g' */
  real32_T Delay1_e;                   /* '<S349>/Delay1' */
  real32_T Sum4_b;                     /* '<S349>/Sum4' */
  real32_T Product_c0;                 /* '<S353>/Product' */
  real32_T UnitDelay_a;                /* '<S353>/Unit Delay' */
  real32_T Product1_en;                /* '<S353>/Product1' */
  real32_T Add1_dd;                    /* '<S353>/Add1' */
  real32_T UnitDelay1_k;               /* '<S350>/Unit Delay1' */
  real32_T UnitDelay_k;                /* '<S350>/Unit Delay' */
  real32_T a_e;                        /* '<S350>/a' */
  real32_T Delay_i;                    /* '<S340>/Delay' */
  real32_T Sum2_g2;                    /* '<S340>/Sum2' */
  real32_T Sum3_l;                     /* '<S350>/Sum3' */
  real32_T b_invg_o;                   /* '<S350>/b_inv*g' */
  real32_T Delay1_fr;                  /* '<S350>/Delay1' */
  real32_T Sum4_m;                     /* '<S350>/Sum4' */
  real32_T Product_p3;                 /* '<S356>/Product' */
  real32_T UnitDelay_gx;               /* '<S356>/Unit Delay' */
  real32_T Product1_k4;                /* '<S356>/Product1' */
  real32_T Add1_g;                     /* '<S356>/Add1' */
  real32_T Merge_ku;                   /* '<S338>/Merge' */
  real32_T Merge1_i;                   /* '<S338>/Merge1' */
  real32_T Delay_ep;                   /* '<S337>/Delay' */
  real32_T Sign;                       /* '<S339>/Sign' */
  real32_T Eta;                        /* '<S339>/Eta' */
  real32_T Sum_gf;                     /* '<S339>/Sum' */
  real32_T b;                          /* '<S339>/b' */
  real32_T a_a;                        /* '<S339>/a' */
  real32_T Sum1_d;                     /* '<S339>/Sum1' */
  real32_T Sign_m;                     /* '<S340>/Sign' */
  real32_T Eta_n;                      /* '<S340>/Eta' */
  real32_T Sum_bl;                     /* '<S340>/Sum' */
  real32_T b_i;                        /* '<S340>/b' */
  real32_T a_p;                        /* '<S340>/a' */
  real32_T Sum1_gj;                    /* '<S340>/Sum1' */
  real32_T DTC_e;                      /* '<S361>/DTC' */
  real32_T SpeedGain_k;                /* '<S344>/SpeedGain' */
  real32_T Product_i2;                 /* '<S359>/Product' */
  real32_T UnitDelay_ci;               /* '<S359>/Unit Delay' */
  real32_T Product1_ey;                /* '<S359>/Product1' */
  real32_T Add1_c;                     /* '<S359>/Add1' */
  real32_T Product_jt;                 /* '<S345>/Product' */
  real32_T Product2_i;                 /* '<S345>/Product2' */
  real32_T Sum1_mc;                    /* '<S345>/Sum1' */
  real32_T Product1_mw;                /* '<S345>/Product1' */
  real32_T Product3_b;                 /* '<S345>/Product3' */
  real32_T Sum2_p;                     /* '<S345>/Sum2' */
  real32_T Switch_cx;                  /* '<S345>/Switch' */
  real32_T Atan2_n;                    /* '<S362>/Atan2' */
  real32_T Switch_gb;                  /* '<S362>/Switch' */
  real32_T algDD_a;
  real32_T Gain_o;                     /* '<S363>/Gain' */
  real32_T Switch_m;                   /* '<S363>/Switch' */
  real32_T Bias_f;                     /* '<S363>/Bias' */
  real32_T Bias_j;                     /* '<S345>/Bias' */
  real32_T acos_c;                     /* '<S19>/acos' */
  real32_T bsin;                       /* '<S19>/bsin' */
  real32_T sum_Ds;                     /* '<S19>/sum_Ds' */
  real32_T bcos;                       /* '<S19>/bcos' */
  real32_T asin_f;                     /* '<S19>/asin' */
  real32_T sum_Qs;                     /* '<S19>/sum_Qs' */
  real32_T Switch_bi[2];               /* '<S145>/Switch' */
  real32_T algDD_o1;
  real32_T algDD_o2;
  real32_T qcos;                       /* '<S17>/qcos' */
  real32_T dsin;                       /* '<S17>/dsin' */
  real32_T sum_beta;                   /* '<S17>/sum_beta' */
  real32_T dcos;                       /* '<S17>/dcos' */
  real32_T qsin;                       /* '<S17>/qsin' */
  real32_T sum_alpha;                  /* '<S17>/sum_alpha' */
  real32_T Switch_df[2];               /* '<S141>/Switch' */
  real32_T algDD_o1_o;
  real32_T algDD_o2_c;
  real32_T Saturation;                 /* '<S131>/Saturation' */
  real32_T Vd_OpenLoop;                /* '<S23>/Vd_OpenLoop' */
  real32_T Abs_i;                      /* '<S23>/Abs' */
  real32_T Saturation_a;               /* '<S23>/Saturation' */
  real32_T Saturation_f;               /* '<S80>/Saturation' */
  real32_T Product_ch[2];              /* '<S29>/Product' */
  real32_T SquareRoot;                 /* '<S29>/Square Root' */
  real32_T Switch_os;                  /* '<S29>/Switch' */
  real32_T Reciprocal;                 /* '<S29>/Reciprocal' */
  real32_T Switch_i[2];                /* '<S26>/Switch' */
  real32_T Switch2;                    /* '<S36>/Switch2' */
  real32_T Product_b;                  /* '<S35>/Product' */
  real32_T Sum_a3;                     /* '<S35>/Sum' */
  real32_T Product2_ao;                /* '<S35>/Product2' */
  real32_T Merge_e;                    /* '<S35>/Merge' */
  real32_T Gain_l;                     /* '<S35>/Gain' */
  real32_T Switch_k;                   /* '<S36>/Switch' */
  real32_T Switch1_h;                  /* '<S37>/Switch1' */
  real32_T Sqrt_np;                    /* '<S37>/Sqrt' */
  real32_T Gain_e;                     /* '<S37>/Gain' */
  real32_T a_plus_2b;                  /* '<S15>/a_plus_2b' */
  real32_T one_by_sqrt3;               /* '<S15>/one_by_sqrt3' */
  real32_T algDD_o1_g;
  real32_T algDD_o2_cx;
  int32_T DataTypeConversion_c[2];     /* '<S165>/Data Type Conversion' */
  int32_T Add_k[2];                    /* '<S165>/Add' */
  int32_T Q17perunitconversion[2];     /* '<S165>/Q17 per unit conversion' */
  int32_T SpeedCount;                  /* '<S307>/SpeedCount' */
  int32_T SpeedCount_c;                /* '<S344>/SpeedCount' */
  uint16_T Divide_h;                   /* '<S376>/Divide' */
  uint16_T Divide1_e;                  /* '<S376>/Divide1' */
  uint16_T ForIterator;                /* '<S379>/For Iterator' */
  uint16_T IAIBMeasurement[2];         /* '<S379>/IA//IB Measurement' */
  uint16_T Memory;                     /* '<S384>/Memory' */
  uint16_T Sum_dn;                     /* '<S384>/Sum' */
  uint16_T Memory1;                    /* '<S384>/Memory1' */
  uint16_T Sum1_dq;                    /* '<S384>/Sum1' */
  uint16_T SCIReceive[2];              /* '<S390>/SCI Receive' */
  uint16_T Switch2_m;                  /* '<S18>/Switch2' */
  uint16_T DataStoreRead_m;            /* '<S165>/Data Store Read' */
  uint16_T DataStoreRead1;             /* '<S165>/Data Store Read1' */
  uint16_T Switch1_f;                  /* '<S27>/Switch1' */
  uint16_T DataTypeConversion_a;       /* '<S147>/Data Type Conversion' */
  uint16_T Get_Integer;                /* '<S20>/Get_Integer' */
  uint16_T Output;                     /* '<S157>/Output' */
  uint16_T DataTypeConversion3[2];     /* '<S159>/Data Type Conversion3' */
  uint16_T SCI_Tx_Data[3];             /* '<S9>/Merge' */
  uint16_T SCI_Tx_Iteration;           /* '<S9>/Merge1' */
  uint16_T FixPtSum1;                  /* '<S162>/FixPt Sum1' */
  uint16_T FixPtSwitch;                /* '<S163>/FixPt Switch' */
  uint16_T Switch1_c[3];               /* '<S364>/Switch1' */
  uint16_T IndexVector;                /* '<S366>/Index Vector' */
  uint16_T Add_m;                      /* '<S366>/Add' */
  uint16_T Scale_to_PWM_Counter_PRD[3];/* '<S364>/Scale_to_PWM_Counter_PRD' */
  uint16_T DataTypeConversion_m;       /* '<S253>/Data Type Conversion' */
  uint16_T Get_Integer_c;              /* '<S197>/Get_Integer' */
  uint16_T Data[2];                    /* '<S158>/Data' */
  uint16_T Data_f[2];                  /* '<S160>/Data' */
  uint16_T Data_fw[2];                 /* '<S161>/Data' */
  uint16_T DataTypeConversion_k;       /* '<S25>/Data Type Conversion' */
  uint16_T DataTypeConversion_a4;      /* '<S35>/Data Type Conversion' */
  int16_T DataTypeConversion2[2];      /* '<S388>/Data Type Conversion2' */
  int16_T DataTypeConversion_l[2];     /* '<S159>/Data Type Conversion' */
  int16_T WhileIterator;               /* '<S366>/While Iterator' */
  int16_T Switch1_l;                   /* '<S64>/Switch1' */
  int16_T Switch2_i;                   /* '<S64>/Switch2' */
  int16_T Switch1_cm;                  /* '<S115>/Switch1' */
  int16_T Switch2_c;                   /* '<S115>/Switch2' */
  boolean_T NOT;                       /* '<S375>/NOT' */
  boolean_T DataTypeConversion3_b;     /* '<S6>/Data Type Conversion3' */
  boolean_T DataTypeConversion_j;      /* '<S18>/Data Type Conversion' */
  boolean_T NOT_a;                     /* '<S142>/NOT' */
  boolean_T Compare;                   /* '<S148>/Compare' */
  boolean_T DataStoreRead1_b;          /* '<S24>/Data Store Read1' */
  boolean_T LogicalOperator;           /* '<S24>/Logical Operator' */
  boolean_T DataStoreRead1_f;          /* '<S23>/Data Store Read1' */
  boolean_T LogicalOperator_e;         /* '<S23>/Logical Operator' */
  boolean_T RelationalOperator;        /* '<S64>/Relational Operator' */
  boolean_T fixforDTpropagationissue; /* '<S64>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1;
                                     /* '<S64>/fix for DT propagation issue1' */
  boolean_T Equal1;                    /* '<S64>/Equal1' */
  boolean_T AND3;                      /* '<S64>/AND3' */
  boolean_T RelationalOperator_i;      /* '<S115>/Relational Operator' */
  boolean_T fixforDTpropagationissue_f;
                                     /* '<S115>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1_g;
                                    /* '<S115>/fix for DT propagation issue1' */
  boolean_T Equal1_m;                  /* '<S115>/Equal1' */
  boolean_T AND3_d;                    /* '<S115>/AND3' */
  boolean_T Enable;                    /* '<S13>/Enable' */
  boolean_T DataStoreRead1_g;          /* '<S167>/Data Store Read1' */
  boolean_T LogicalOperator_l;         /* '<S167>/Logical Operator' */
  boolean_T Compare_l;                 /* '<S254>/Compare' */
  boolean_T AlphaRelay;                /* '<S188>/AlphaRelay' */
  boolean_T BetaRelay;                 /* '<S188>/BetaRelay' */
  boolean_T NOT_g;                     /* '<S196>/NOT' */
  boolean_T Compare_f;                 /* '<S277>/Compare' */
  boolean_T Compare_g;                 /* '<S279>/Compare' */
  boolean_T Compare_j;                 /* '<S276>/Compare' */
  boolean_T LogicalOperator1;          /* '<S266>/Logical Operator1' */
  boolean_T Compare_n;                 /* '<S280>/Compare' */
  boolean_T LogicalOperator2;          /* '<S266>/Logical Operator2' */
  boolean_T AND;                       /* '<S266>/AND' */
  boolean_T UnitDelay_h;               /* '<S266>/Unit Delay' */
  boolean_T Switch_ls;                 /* '<S266>/Switch' */
  boolean_T Compare_i;                 /* '<S278>/Compare' */
  boolean_T LogicalOperator_eh;        /* '<S266>/Logical Operator' */
  boolean_T DataStoreRead1_c;          /* '<S168>/Data Store Read1' */
  boolean_T LogicalOperator_ed;        /* '<S168>/Logical Operator' */
  boolean_T DataStoreRead1_i;          /* '<S169>/Data Store Read1' */
  boolean_T LogicalOperator_i;         /* '<S169>/Logical Operator' */
  boolean_T AlphaRelay_p;              /* '<S338>/AlphaRelay' */
  boolean_T BetaRelay_j;               /* '<S338>/BetaRelay' */
  boolean_T RelationalOperator_l;      /* '<S25>/Relational Operator' */
  boolean_T Compare_n2;                /* '<S31>/Compare' */
  boolean_T Compare_m;                 /* '<S32>/Compare' */
  boolean_T LowerRelop1;               /* '<S36>/LowerRelop1' */
  boolean_T RelationalOperator_c;      /* '<S35>/Relational Operator' */
  boolean_T UpperRelop;                /* '<S36>/UpperRelop' */
  rtB_SpeedControl_iPMSM_F28069M SpeedControl;/* '<Root>/Speed Control' */
  rtB_SPIMasterTransfer_iPMSM_F28 SPIMasterTransfer1;/* '<S377>/SPI Master Transfer' */
  rtB_SPIMasterTransfer_iPMSM_F28 SPIMasterTransfer;/* '<S377>/SPI Master Transfer' */
  rtB_IfActionSubsystem1_iPMSM_F2 IfActionSubsystem1_j;/* '<S253>/If Action Subsystem1' */
  rtB_IfActionSubsystem_iPMSM_F28 IfActionSubsystem_e;/* '<S253>/If Action Subsystem' */
  rtB_Accumulate_iPMSM_F28069M Accumulate_j;/* '<S196>/Accumulate' */
  rtB_Dir_Sense_iPMSM_F28069M Dir_Sense_m;/* '<S188>/Dir_Sense' */
  rtB_Dir_Sense_iPMSM_F28069M Dir_Sense;/* '<S338>/Dir_Sense' */
  rtB_IfActionSubsystem1_iPMSM_F2 IfActionSubsystem1;/* '<S147>/If Action Subsystem1' */
  rtB_IfActionSubsystem_iPMSM_F28 IfActionSubsystem;/* '<S147>/If Action Subsystem' */
  rtB_Accumulate_iPMSM_F28069M Accumulate;/* '<S142>/Accumulate' */
} BlockIO_iPMSM_F28069M;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S142>/Unit Delay' */
  real32_T Delay5_DSTATE[4];           /* '<S1>/Delay5' */
  real32_T UnitDelay_DSTATE_l;         /* '<S24>/Unit Delay' */
  real32_T Integrator_DSTATE;          /* '<S124>/Integrator' */
  real32_T UnitDelay_DSTATE_l0;        /* '<S23>/Unit Delay' */
  real32_T Integrator_DSTATE_j;        /* '<S73>/Integrator' */
  real32_T Delay1_DSTATE;              /* '<S170>/Delay1' */
  real32_T Delay_DSTATE[2];            /* '<S171>/Delay' */
  real32_T Delay_DSTATE_i;             /* '<S189>/Delay' */
  real32_T Integrator_DSTATE_o;        /* '<S233>/Integrator' */
  real32_T Delay2_DSTATE;              /* '<S294>/Delay2' */
  real32_T Delay3_DSTATE;              /* '<S294>/Delay3' */
  real32_T Delay2_DSTATE_i;            /* '<S295>/Delay2' */
  real32_T Delay3_DSTATE_a;            /* '<S295>/Delay3' */
  real32_T Delay1_DSTATE_j;            /* '<S286>/Delay1' */
  real32_T Delay_DSTATE_a;             /* '<S286>/Delay' */
  real32_T Delay1_DSTATE_a;            /* '<S287>/Delay1' */
  real32_T Delay_DSTATE_o;             /* '<S287>/Delay' */
  real32_T Delay2_DSTATE_o;            /* '<S261>/Delay2' */
  real32_T Delay3_DSTATE_f;            /* '<S261>/Delay3' */
  real32_T Delay2_DSTATE_p;            /* '<S262>/Delay2' */
  real32_T Delay3_DSTATE_n;            /* '<S262>/Delay3' */
  real32_T UnitDelay_DSTATE_n3[4];     /* '<S311>/Unit Delay' */
  real32_T Delay1_DSTATE_n;            /* '<S327>/Delay1' */
  real32_T Delay_DSTATE_om;            /* '<S327>/Delay' */
  real32_T UnitDelay_DSTATE_p;         /* '<S331>/Unit Delay' */
  real32_T Delay1_DSTATE_n2;           /* '<S320>/Delay1' */
  real32_T Delay_DSTATE_hc;            /* '<S320>/Delay' */
  real32_T UnitDelay_DSTATE_nr;        /* '<S324>/Unit Delay' */
  real32_T UnitDelay_DSTATE_a1;        /* '<S334>/Unit Delay' */
  real32_T Delay_DSTATE_n;             /* '<S339>/Delay' */
  real32_T Delay1_DSTATE_l;            /* '<S349>/Delay1' */
  real32_T Delay_DSTATE_e;             /* '<S340>/Delay' */
  real32_T Delay1_DSTATE_jt;           /* '<S350>/Delay1' */
  real32_T Delay_DSTATE_nm;            /* '<S337>/Delay' */
  uint32_T Delay_DSTATE_ad[10];        /* '<S307>/Delay' */
  volatile real32_T RT6_Buffer[2];     /* '<Root>/RT6' */
  volatile real32_T RT4_Buffer[2];     /* '<Root>/RT4' */
  volatile real32_T RT2_Buffer[4];     /* '<Root>/RT2' */
  real32_T Speed_ref;                  /* '<Root>/Data Store Memory3' */
  int32_T DigitalOutput1_FRAC_LEN;     /* '<S386>/Digital Output1' */
  int32_T DigitalOutput_FRAC_LEN;      /* '<S377>/Digital Output' */
  int32_T Add_DWORK1[2];               /* '<S165>/Add' */
  int32_T DigitalOutput_FRAC_LEN_h;    /* '<S364>/Digital Output' */
  int32_T SpeedCount_DWORK1;           /* '<S307>/SpeedCount' */
  uint32_T Sum_DWORK1[4];              /* '<S20>/Sum' */
  uint16_T Output_DSTATE;              /* '<S157>/Output' */
  volatile int16_T RT6_ActiveBufIdx;   /* '<Root>/RT6' */
  volatile int16_T RT6_semaphoreTaken; /* '<Root>/RT6' */
  volatile int16_T RT4_ActiveBufIdx;   /* '<Root>/RT4' */
  volatile int16_T RT4_semaphoreTaken; /* '<Root>/RT4' */
  volatile int16_T RT2_ActiveBufIdx;   /* '<Root>/RT2' */
  uint16_T IaOffset;                   /* '<Root>/Data Store Memory1' */
  uint16_T IbOffset;                   /* '<Root>/Data Store Memory2' */
  uint16_T Memory_PreviousInput;       /* '<S384>/Memory' */
  uint16_T Memory1_PreviousInput;      /* '<S384>/Memory1' */
  uint16_T Add_DWORK1_o;               /* '<S366>/Add' */
  uint16_T CircBufIdx;                 /* '<S307>/Delay' */
  uint16_T CircBufIdx_n;               /* '<S344>/Delay' */
  int16_T Integrator_PrevResetState;   /* '<S124>/Integrator' */
  int16_T Integrator_PrevResetState_f; /* '<S73>/Integrator' */
  int16_T Integrator_PrevResetState_e; /* '<S233>/Integrator' */
  uint16_T Integrator_IC_LOADING;      /* '<S124>/Integrator' */
  uint16_T Integrator_IC_LOADING_p;    /* '<S73>/Integrator' */
  boolean_T Enable;                    /* '<Root>/Data Store Memory29' */
  boolean_T EnClosedLoop;              /* '<Root>/Data Store Memory5' */
  boolean_T AlphaRelay_Mode;           /* '<S188>/AlphaRelay' */
  boolean_T BetaRelay_Mode;            /* '<S188>/BetaRelay' */
  boolean_T AlphaRelay_Mode_c;         /* '<S338>/AlphaRelay' */
  boolean_T BetaRelay_Mode_j;          /* '<S338>/BetaRelay' */
  rtDW_SpeedControl_iPMSM_F28069M SpeedControl;/* '<Root>/Speed Control' */
  rtDW_SPIMasterTransfer_iPMSM_F2 SPIMasterTransfer1;/* '<S377>/SPI Master Transfer' */
  rtDW_SPIMasterTransfer_iPMSM_F2 SPIMasterTransfer;/* '<S377>/SPI Master Transfer' */
  rtDW_Accumulate_iPMSM_F28069M Accumulate_j;/* '<S196>/Accumulate' */
  rtDW_Accumulate_iPMSM_F28069M Accumulate;/* '<S142>/Accumulate' */
} D_Work_iPMSM_F28069M;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Delay1_Reset_ZCE;         /* '<S170>/Delay1' */
  ZCSigState Delay_Reset_ZCE;          /* '<S171>/Delay' */
  ZCSigState Delay_Reset_ZCE_b;        /* '<S189>/Delay' */
  ZCSigState Delay2_Reset_ZCE;         /* '<S294>/Delay2' */
  ZCSigState Delay3_Reset_ZCE;         /* '<S294>/Delay3' */
  ZCSigState Delay2_Reset_ZCE_a;       /* '<S295>/Delay2' */
  ZCSigState Delay3_Reset_ZCE_e;       /* '<S295>/Delay3' */
  ZCSigState Delay1_Reset_ZCE_h;       /* '<S286>/Delay1' */
  ZCSigState Delay_Reset_ZCE_d;        /* '<S286>/Delay' */
  ZCSigState Delay1_Reset_ZCE_j;       /* '<S287>/Delay1' */
  ZCSigState Delay_Reset_ZCE_bz;       /* '<S287>/Delay' */
  ZCSigState Delay2_Reset_ZCE_e;       /* '<S261>/Delay2' */
  ZCSigState Delay3_Reset_ZCE_d;       /* '<S261>/Delay3' */
  ZCSigState Delay2_Reset_ZCE_c;       /* '<S262>/Delay2' */
  ZCSigState Delay3_Reset_ZCE_p;       /* '<S262>/Delay3' */
  rtZCE_Dir_Sense_iPMSM_F28069M Dir_Sense_m;/* '<S188>/Dir_Sense' */
  ZCSigState Delay1_Reset_ZCE_p;       /* '<S327>/Delay1' */
  ZCSigState Delay_Reset_ZCE_a;        /* '<S327>/Delay' */
  ZCSigState Delay1_Reset_ZCE_a;       /* '<S320>/Delay1' */
  ZCSigState Delay_Reset_ZCE_o;        /* '<S320>/Delay' */
  ZCSigState Delay_Reset_ZCE_n;        /* '<S339>/Delay' */
  ZCSigState Delay1_Reset_ZCE_b;       /* '<S349>/Delay1' */
  ZCSigState Delay_Reset_ZCE_l;        /* '<S340>/Delay' */
  ZCSigState Delay1_Reset_ZCE_bl;      /* '<S350>/Delay1' */
  ZCSigState Delay_Reset_ZCE_n0;       /* '<S337>/Delay' */
  rtZCE_Dir_Sense_iPMSM_F28069M Dir_Sense;/* '<S338>/Dir_Sense' */
} PrevZCSigStates_iPMSM_F28069M;

/* Invariant block signals (default storage) */
typedef struct {
  const uint16_T Width;                /* '<S9>/Width' */
} ConstBlockIO_iPMSM_F28069M;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S20>/sine_table_values'
   *   '<S197>/sine_table_values'
   */
  real32_T pooled32[1002];
} ConstParam_iPMSM_F28069M;

/* Real-time Model Data Structure */
struct tag_RTM_iPMSM_F28069M {
  const char_T * volatile errorStatus;

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

/* Block signals (default storage) */
extern BlockIO_iPMSM_F28069M iPMSM_F28069M_B;

/* Block states (default storage) */
extern D_Work_iPMSM_F28069M iPMSM_F28069M_DWork;

/* Zero-crossing (trigger) state */
extern PrevZCSigStates_iPMSM_F28069M iPMSM_F28069M_PrevZCSigState;
extern const ConstBlockIO_iPMSM_F28069M iPMSM_F28069M_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstParam_iPMSM_F28069M iPMSM_F28069M_ConstP;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T Iab_fb_PU[2];          /* '<S165>/Data Type Conversion1' */
extern uint16_T Iab_ADC_u16[2];        /* '<S164>/IA//IB Measurement' */

/* External function called from main */
extern void iPMSM_F28069M_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void iPMSM_F28069M_initialize(void);
extern void iPMSM_F28069M_step0(void);
extern void iPMSM_F28069M_step1(void);
extern void iPMSM_F28069M_terminate(void);

/* Real-time Model object */
extern RT_MODEL_iPMSM_F28069M *const iPMSM_F28069M_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  interrupt void ADCINT1(void);
  interrupt void SCIRXINTA(void);
  void iPMSM_F28069M_configure_interrupts (void);
  void iPMSM_F28069M_unconfigure_interrupts (void);

#ifdef __cpluscplus

}

#endif

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
 * '<Root>' : 'iPMSM_F28069M'
 * '<S1>'   : 'iPMSM_F28069M/Current Control'
 * '<S2>'   : 'iPMSM_F28069M/HW Interrrupt'
 * '<S3>'   : 'iPMSM_F28069M/Hardware Init'
 * '<S4>'   : 'iPMSM_F28069M/Heartbeat LED'
 * '<S5>'   : 'iPMSM_F28069M/Inverter and Motor - Plant Model'
 * '<S6>'   : 'iPMSM_F28069M/Serial Receive'
 * '<S7>'   : 'iPMSM_F28069M/Speed Control'
 * '<S8>'   : 'iPMSM_F28069M/Current Control/Closed Loop'
 * '<S9>'   : 'iPMSM_F28069M/Current Control/Data_Logging'
 * '<S10>'  : 'iPMSM_F28069M/Current Control/HW Inputs'
 * '<S11>'  : 'iPMSM_F28069M/Current Control/Input Scaling'
 * '<S12>'  : 'iPMSM_F28069M/Current Control/Inverter'
 * '<S13>'  : 'iPMSM_F28069M/Current Control/Output Scaling'
 * '<S14>'  : 'iPMSM_F28069M/Current Control/SCI_Tx'
 * '<S15>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Clarke Transform'
 * '<S16>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers'
 * '<S17>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Inverse Park Transform'
 * '<S18>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Open_Loop_Control'
 * '<S19>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Park Transform'
 * '<S20>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Sine-Cosine Lookup'
 * '<S21>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Space Vector Generator'
 * '<S22>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/DQ Limiter'
 * '<S23>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id'
 * '<S24>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq'
 * '<S25>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D-Q Equivalence'
 * '<S26>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority'
 * '<S27>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/DQ Limiter/Inport//Dialog Selection'
 * '<S28>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/DQ Limiter/Magnitude_calc'
 * '<S29>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D-Q Equivalence/Limiter'
 * '<S30>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D-Q Equivalence/Passthrough'
 * '<S31>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant'
 * '<S32>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant1'
 * '<S33>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs'
 * '<S34>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs1'
 * '<S35>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter'
 * '<S36>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef1'
 * '<S37>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef2'
 * '<S38>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/passThrough'
 * '<S39>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset'
 * '<S40>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S41>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S42>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S43>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S44>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S45>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S46>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S47>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S48>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S49>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S50>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S51>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S52>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S53>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S54>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S55>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S56>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S57>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S58>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S59>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S60>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S61>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S62>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S63>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S64>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S65>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S66>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S67>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S68>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S69>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S70>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S71>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S72>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S73>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S74>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S75>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S76>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S77>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S78>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S79>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S80>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S81>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S82>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S83>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S84>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S85>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S86>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S87>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S88>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S89>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S90>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset'
 * '<S91>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S92>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S93>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S94>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S95>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S96>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S97>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S98>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S99>'  : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S100>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S101>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S102>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S103>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S104>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S105>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S106>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S107>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S108>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S109>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S110>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S111>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S112>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S113>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S114>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S115>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S116>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S117>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S118>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S119>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S120>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S121>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S122>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S123>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S124>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S125>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S126>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S127>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S128>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S129>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S130>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S131>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S132>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S133>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S134>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S135>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S136>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S137>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S138>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S139>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S140>' : 'iPMSM_F28069M/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S141>' : 'iPMSM_F28069M/Current Control/Closed Loop/Inverse Park Transform/Switch_Axis'
 * '<S142>' : 'iPMSM_F28069M/Current Control/Closed Loop/Open_Loop_Control/Position Generator'
 * '<S143>' : 'iPMSM_F28069M/Current Control/Closed Loop/Open_Loop_Control/Position Generator/Accumulate'
 * '<S144>' : 'iPMSM_F28069M/Current Control/Closed Loop/Open_Loop_Control/Position Generator/Accumulate/Subsystem'
 * '<S145>' : 'iPMSM_F28069M/Current Control/Closed Loop/Park Transform/Switch_Axis'
 * '<S146>' : 'iPMSM_F28069M/Current Control/Closed Loop/Sine-Cosine Lookup/Interpolation'
 * '<S147>' : 'iPMSM_F28069M/Current Control/Closed Loop/Sine-Cosine Lookup/WrapUp'
 * '<S148>' : 'iPMSM_F28069M/Current Control/Closed Loop/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S149>' : 'iPMSM_F28069M/Current Control/Closed Loop/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S150>' : 'iPMSM_F28069M/Current Control/Closed Loop/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S151>' : 'iPMSM_F28069M/Current Control/Closed Loop/Space Vector Generator/Modulation method'
 * '<S152>' : 'iPMSM_F28069M/Current Control/Closed Loop/Space Vector Generator/Voltage Input'
 * '<S153>' : 'iPMSM_F28069M/Current Control/Closed Loop/Space Vector Generator/Modulation method/SVPWM'
 * '<S154>' : 'iPMSM_F28069M/Current Control/Closed Loop/Space Vector Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S155>' : 'iPMSM_F28069M/Current Control/Closed Loop/Space Vector Generator/Voltage Input/Valphabeta'
 * '<S156>' : 'iPMSM_F28069M/Current Control/Closed Loop/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S157>' : 'iPMSM_F28069M/Current Control/Data_Logging/Counter Limited'
 * '<S158>' : 'iPMSM_F28069M/Current Control/Data_Logging/Data'
 * '<S159>' : 'iPMSM_F28069M/Current Control/Data_Logging/Data_Conditioning'
 * '<S160>' : 'iPMSM_F28069M/Current Control/Data_Logging/End'
 * '<S161>' : 'iPMSM_F28069M/Current Control/Data_Logging/Start'
 * '<S162>' : 'iPMSM_F28069M/Current Control/Data_Logging/Counter Limited/Increment Real World'
 * '<S163>' : 'iPMSM_F28069M/Current Control/Data_Logging/Counter Limited/Wrap To Zero'
 * '<S164>' : 'iPMSM_F28069M/Current Control/HW Inputs/Sensor Driver Blocks (codegen)'
 * '<S165>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate Phase Currents'
 * '<S166>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed'
 * '<S167>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer'
 * '<S168>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer'
 * '<S169>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer'
 * '<S170>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer'
 * '<S171>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer'
 * '<S172>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/IIR Filter'
 * '<S173>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/PerUnit'
 * '<S174>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer'
 * '<S175>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem'
 * '<S176>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem2'
 * '<S177>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem/A11'
 * '<S178>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem/A12'
 * '<S179>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem/A22'
 * '<S180>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem/L'
 * '<S181>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem/L1'
 * '<S182>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem/L2'
 * '<S183>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem2/B'
 * '<S184>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/EEMF Observer/Subsystem2/L'
 * '<S185>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/IIR Filter/IIR Filter'
 * '<S186>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/IIR Filter/IIR Filter/Low-pass'
 * '<S187>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S188>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/Direction_Latch'
 * '<S189>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL'
 * '<S190>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/Direction_Latch/Dir_Sense'
 * '<S191>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/Direction_Latch/Subsystem2'
 * '<S192>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/Direction_Latch/Subsystem3'
 * '<S193>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/IIR Filter'
 * '<S194>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/Normalize'
 * '<S195>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller'
 * '<S196>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/Position Generator'
 * '<S197>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/Sine-Cosine Lookup1'
 * '<S198>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1'
 * '<S199>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/IIR Filter/IIR Filter'
 * '<S200>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/IIR Filter/IIR Filter/Low-pass'
 * '<S201>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S202>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Anti-windup'
 * '<S203>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/D Gain'
 * '<S204>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter'
 * '<S205>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter ICs'
 * '<S206>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/I Gain'
 * '<S207>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain'
 * '<S208>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain Fdbk'
 * '<S209>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator'
 * '<S210>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator ICs'
 * '<S211>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Copy'
 * '<S212>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Gain'
 * '<S213>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/P Copy'
 * '<S214>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Parallel P Gain'
 * '<S215>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Reset Signal'
 * '<S216>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation'
 * '<S217>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation Fdbk'
 * '<S218>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum'
 * '<S219>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum Fdbk'
 * '<S220>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode'
 * '<S221>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode Sum'
 * '<S222>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Integral'
 * '<S223>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Ngain'
 * '<S224>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/postSat Signal'
 * '<S225>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/preSat Signal'
 * '<S226>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Anti-windup/Passthrough'
 * '<S227>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/D Gain/Disabled'
 * '<S228>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter/Disabled'
 * '<S229>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter ICs/Disabled'
 * '<S230>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/I Gain/Internal Parameters'
 * '<S231>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain/Passthrough'
 * '<S232>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S233>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator/Discrete'
 * '<S234>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator ICs/Internal IC'
 * '<S235>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S236>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Gain/Disabled'
 * '<S237>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/P Copy/Disabled'
 * '<S238>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S239>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Reset Signal/External Reset'
 * '<S240>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation/Passthrough'
 * '<S241>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation Fdbk/Disabled'
 * '<S242>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum/Sum_PI'
 * '<S243>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum Fdbk/Disabled'
 * '<S244>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode/Disabled'
 * '<S245>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S246>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S247>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S248>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/postSat Signal/Forward_Path'
 * '<S249>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/PID Controller/preSat Signal/Forward_Path'
 * '<S250>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/Position Generator/Accumulate'
 * '<S251>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/Position Generator/Accumulate/Subsystem'
 * '<S252>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/Sine-Cosine Lookup1/Interpolation'
 * '<S253>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/Sine-Cosine Lookup1/WrapUp'
 * '<S254>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/Sine-Cosine Lookup1/WrapUp/Compare To Zero'
 * '<S255>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/Sine-Cosine Lookup1/WrapUp/If Action Subsystem'
 * '<S256>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/Sine-Cosine Lookup1/WrapUp/If Action Subsystem1'
 * '<S257>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/DifferentiationMethod'
 * '<S258>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/IIR Filter'
 * '<S259>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/IntegralMethod'
 * '<S260>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/OptimizedDifferentiationMethod'
 * '<S261>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/DifferentiationMethod/Differentiator'
 * '<S262>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/DifferentiationMethod/Differentiator1'
 * '<S263>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/DifferentiationMethod/IIR Filter1'
 * '<S264>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/DifferentiationMethod/IIR Filter2'
 * '<S265>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/DifferentiationMethod/IIR Filter3'
 * '<S266>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/DifferentiationMethod/Subsystem'
 * '<S267>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/DifferentiationMethod/IIR Filter1/IIR Filter'
 * '<S268>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/DifferentiationMethod/IIR Filter1/IIR Filter/Low-pass'
 * '<S269>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/DifferentiationMethod/IIR Filter1/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S270>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/DifferentiationMethod/IIR Filter2/IIR Filter'
 * '<S271>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/DifferentiationMethod/IIR Filter2/IIR Filter/Low-pass'
 * '<S272>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/DifferentiationMethod/IIR Filter2/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S273>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/DifferentiationMethod/IIR Filter3/IIR Filter'
 * '<S274>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/DifferentiationMethod/IIR Filter3/IIR Filter/Low-pass'
 * '<S275>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/DifferentiationMethod/IIR Filter3/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S276>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/DifferentiationMethod/Subsystem/Compare To Constant'
 * '<S277>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/DifferentiationMethod/Subsystem/Compare To Constant1'
 * '<S278>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/DifferentiationMethod/Subsystem/Compare To Constant2'
 * '<S279>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/DifferentiationMethod/Subsystem/Compare To Constant4'
 * '<S280>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/DifferentiationMethod/Subsystem/Compare To Constant5'
 * '<S281>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/IIR Filter/IIR Filter'
 * '<S282>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/IIR Filter/IIR Filter/Low-pass'
 * '<S283>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S284>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/IntegralMethod/IIR Filter1'
 * '<S285>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/IntegralMethod/IIR Filter3'
 * '<S286>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/IntegralMethod/Integrator'
 * '<S287>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/IntegralMethod/Integrator1'
 * '<S288>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/IntegralMethod/IIR Filter1/IIR Filter'
 * '<S289>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/IntegralMethod/IIR Filter1/IIR Filter/Low-pass'
 * '<S290>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/IntegralMethod/IIR Filter1/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S291>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/IntegralMethod/IIR Filter3/IIR Filter'
 * '<S292>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/IntegralMethod/IIR Filter3/IIR Filter/Low-pass'
 * '<S293>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/IntegralMethod/IIR Filter3/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S294>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/OptimizedDifferentiationMethod/Differentiator'
 * '<S295>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/OptimizedDifferentiationMethod/Differentiator1'
 * '<S296>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/OptimizedDifferentiationMethod/IIR Filter1'
 * '<S297>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/OptimizedDifferentiationMethod/IIR Filter3'
 * '<S298>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/OptimizedDifferentiationMethod/IIR Filter1/IIR Filter'
 * '<S299>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/OptimizedDifferentiationMethod/IIR Filter1/IIR Filter/Low-pass'
 * '<S300>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/OptimizedDifferentiationMethod/IIR Filter1/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S301>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/OptimizedDifferentiationMethod/IIR Filter3/IIR Filter'
 * '<S302>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/OptimizedDifferentiationMethod/IIR Filter3/IIR Filter/Low-pass'
 * '<S303>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Extended EMF Observer/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward1/OptimizedDifferentiationMethod/IIR Filter3/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S304>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/DC component removal'
 * '<S305>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer'
 * '<S306>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/IIR Filter'
 * '<S307>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Speed Measurement'
 * '<S308>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/DC component removal/IIR Filter'
 * '<S309>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/DC component removal/IIR Filter/IIR Filter'
 * '<S310>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/DC component removal/IIR Filter/IIR Filter/Low-pass'
 * '<S311>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/DC component removal/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S312>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Atan2'
 * '<S313>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha'
 * '<S314>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta'
 * '<S315>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Atan2/Default'
 * '<S316>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Atan2/Default/atan2'
 * '<S317>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/Atan2/Default/atan2/Per Unit'
 * '<S318>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default'
 * '<S319>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/IIR Filter'
 * '<S320>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/Integrator'
 * '<S321>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/Scaling'
 * '<S322>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/IIR Filter/IIR Filter'
 * '<S323>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/IIR Filter/IIR Filter/High-pass'
 * '<S324>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/IIR Filter/IIR Filter/High-pass/IIR Low Pass Filter'
 * '<S325>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default'
 * '<S326>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/IIR Filter'
 * '<S327>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/Integrator'
 * '<S328>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/Scaling'
 * '<S329>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/IIR Filter/IIR Filter'
 * '<S330>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/IIR Filter/IIR Filter/High-pass'
 * '<S331>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/IIR Filter/IIR Filter/High-pass/IIR Low Pass Filter'
 * '<S332>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/IIR Filter/IIR Filter'
 * '<S333>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/IIR Filter/IIR Filter/Low-pass'
 * '<S334>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S335>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Speed Measurement/DT_Handle'
 * '<S336>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Flux Observer/Speed Measurement/DT_Handle/floating-point'
 * '<S337>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1'
 * '<S338>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Direction_Latch'
 * '<S339>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Ealpha_est'
 * '<S340>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Ebeta_est'
 * '<S341>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ealpha'
 * '<S342>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ebeta'
 * '<S343>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/IIR Filter'
 * '<S344>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Speed Measurement'
 * '<S345>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/angleCompensation'
 * '<S346>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Direction_Latch/Dir_Sense'
 * '<S347>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Direction_Latch/Subsystem2'
 * '<S348>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Direction_Latch/Subsystem3'
 * '<S349>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Ealpha_est/DisturbanceObserver'
 * '<S350>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Ebeta_est/DisturbanceObserver'
 * '<S351>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ealpha/IIR Filter'
 * '<S352>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ealpha/IIR Filter/Low-pass'
 * '<S353>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ealpha/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S354>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ebeta/IIR Filter'
 * '<S355>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ebeta/IIR Filter/Low-pass'
 * '<S356>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Filter_Ebeta/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S357>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/IIR Filter/IIR Filter'
 * '<S358>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/IIR Filter/IIR Filter/Low-pass'
 * '<S359>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S360>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Speed Measurement/DT_Handle'
 * '<S361>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/Speed Measurement/DT_Handle/floating-point'
 * '<S362>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/angleCompensation/atan1'
 * '<S363>' : 'iPMSM_F28069M/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer1/angleCompensation/atan1/Per Unit'
 * '<S364>' : 'iPMSM_F28069M/Current Control/Inverter/Code Generation'
 * '<S365>' : 'iPMSM_F28069M/Current Control/SCI_Tx/Code Generation'
 * '<S366>' : 'iPMSM_F28069M/Current Control/SCI_Tx/Code Generation/CodeGeneration'
 * '<S367>' : 'iPMSM_F28069M/HW Interrrupt/Code generation'
 * '<S368>' : 'iPMSM_F28069M/HW Interrrupt/Code generation/HWI_ADCINT1'
 * '<S369>' : 'iPMSM_F28069M/HW Interrrupt/Code generation/HWI_SCIRXINTA'
 * '<S370>' : 'iPMSM_F28069M/HW Interrrupt/Code generation/HWI_ADCINT1/ECSoC'
 * '<S371>' : 'iPMSM_F28069M/HW Interrrupt/Code generation/HWI_ADCINT1/ECSoC/ECSimCodegen'
 * '<S372>' : 'iPMSM_F28069M/HW Interrrupt/Code generation/HWI_SCIRXINTA/ECSoC'
 * '<S373>' : 'iPMSM_F28069M/HW Interrrupt/Code generation/HWI_SCIRXINTA/ECSoC/ECSimCodegen'
 * '<S374>' : 'iPMSM_F28069M/Hardware Init/Variant Subsystem'
 * '<S375>' : 'iPMSM_F28069M/Hardware Init/Variant Subsystem/Code Generation'
 * '<S376>' : 'iPMSM_F28069M/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset '
 * '<S377>' : 'iPMSM_F28069M/Hardware Init/Variant Subsystem/Code Generation/DRV Enable'
 * '<S378>' : 'iPMSM_F28069M/Hardware Init/Variant Subsystem/Code Generation/Default ADC Offset'
 * '<S379>' : 'iPMSM_F28069M/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /For Iterator Subsystem'
 * '<S380>' : 'iPMSM_F28069M/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem'
 * '<S381>' : 'iPMSM_F28069M/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem1'
 * '<S382>' : 'iPMSM_F28069M/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem2'
 * '<S383>' : 'iPMSM_F28069M/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem3'
 * '<S384>' : 'iPMSM_F28069M/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /For Iterator Subsystem/If Action Subsystem'
 * '<S385>' : 'iPMSM_F28069M/Heartbeat LED/Heartbeat LED'
 * '<S386>' : 'iPMSM_F28069M/Heartbeat LED/Heartbeat LED/Code generation'
 * '<S387>' : 'iPMSM_F28069M/Inverter and Motor - Plant Model/Codegeneration'
 * '<S388>' : 'iPMSM_F28069M/Serial Receive/Data_Conditioning'
 * '<S389>' : 'iPMSM_F28069M/Serial Receive/SCI_Rx'
 * '<S390>' : 'iPMSM_F28069M/Serial Receive/SCI_Rx/Code Generation'
 * '<S391>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed'
 * '<S392>' : 'iPMSM_F28069M/Speed Control/SlewRate'
 * '<S393>' : 'iPMSM_F28069M/Speed Control/Speed_Ref_Selector'
 * '<S394>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset'
 * '<S395>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Zero_Cancellation'
 * '<S396>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S397>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S398>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S399>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S400>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S401>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S402>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S403>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S404>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S405>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S406>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S407>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S408>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S409>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S410>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S411>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S412>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S413>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S414>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S415>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S416>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S417>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S418>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S419>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S420>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S421>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S422>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S423>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S424>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S425>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S426>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S427>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S428>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S429>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S430>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S431>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S432>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S433>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S434>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S435>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S436>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S437>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S438>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S439>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S440>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S441>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S442>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S443>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S444>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S445>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S446>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter'
 * '<S447>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass'
 * '<S448>' : 'iPMSM_F28069M/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass/IIR Low Pass Filter'
 */
#endif                                 /* RTW_HEADER_iPMSM_F28069M_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

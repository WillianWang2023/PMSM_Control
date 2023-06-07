/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: iPMSM_F28069M_types.h
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

#ifndef RTW_HEADER_iPMSM_F28069M_types_h_
#define RTW_HEADER_iPMSM_F28069M_types_h_
#include "rtwtypes.h"
#include "MW_c2000SPI.h"

/* Custom Type definition for MATLABSystem: '<S377>/SPI Master Transfer' */
#include "MW_c2000SPI.h"
#ifndef struct_tag_RL3bf5VyBoZJTCiPpDuhAE
#define struct_tag_RL3bf5VyBoZJTCiPpDuhAE

struct tag_RL3bf5VyBoZJTCiPpDuhAE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_SPI_HANDLE;
};

#endif                                 /* struct_tag_RL3bf5VyBoZJTCiPpDuhAE */

#ifndef typedef_codertarget_tic2000_blocks_SPIM
#define typedef_codertarget_tic2000_blocks_SPIM

typedef struct tag_RL3bf5VyBoZJTCiPpDuhAE codertarget_tic2000_blocks_SPIM;

#endif                             /* typedef_codertarget_tic2000_blocks_SPIM */

/* Forward declaration for rtModel */
typedef struct tag_RTM_iPMSM_F28069M RT_MODEL_iPMSM_F28069M;

#endif                                 /* RTW_HEADER_iPMSM_F28069M_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

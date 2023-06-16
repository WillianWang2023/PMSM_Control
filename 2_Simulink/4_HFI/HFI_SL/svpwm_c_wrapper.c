
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Start function
 *
 */
void svpwm_c_Start_wrapper(void)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Custom Start code goes here.
 */
#define ONE_BY_SQRT3                0.577350269189626f
#define TWO_BY_SQRT3                1.154700538379252f
#define uint32_t                    unsigned long
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
void svpwm_c_Outputs_wrapper(const real32_T *alpha_mod,
			const real32_T *beta_mod,
			const real32_T *top,
			real32_T *tAout,
			real32_T *tBout,
			real32_T *tCout)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
 */
    double alpha = *alpha_mod;
    double beta  = *beta_mod;
    uint32_t PWMHalfPeriod = *top;
    uint32_t sector;
    if (beta >= 0.0f) {
        if (alpha >= 0.0f) {
            //quadrant I
            if (ONE_BY_SQRT3 * beta > alpha) {
                sector = 2;
            } else {
                sector = 1;
            }
        } else {
            //quadrant II
            if (-ONE_BY_SQRT3 * beta > alpha) {
                sector = 3;
            } else {
                sector = 2;
            }
        }
    } else {
        if (alpha >= 0.0f) {
            //quadrant IV5
            if (-ONE_BY_SQRT3 * beta > alpha) {
                sector = 5;
            } else {
                sector = 6;
            }
        } else {
            //quadrant III
            if (ONE_BY_SQRT3 * beta > alpha) {
                sector = 4;
            } else {
                sector = 5;
            }
        }
    }

    // PWM timings
    uint32_t tA, tB, tC;

    switch (sector) {

    // sector 1-2
    case 1: {
        // Vector on-times
        uint32_t t1 = (alpha - ONE_BY_SQRT3 * beta) * PWMHalfPeriod;
        uint32_t t2 = (TWO_BY_SQRT3 * beta) * PWMHalfPeriod;

        // PWM timings
        tA = (PWMHalfPeriod - t1 - t2) / 2;
        tB = tA + t1;
        tC = tB + t2;

        break;
    }

    // sector 2-3
    case 2: {
        // Vector on-times
        uint32_t t2 = (alpha + ONE_BY_SQRT3 * beta) * PWMHalfPeriod;
        uint32_t t3 = (-alpha + ONE_BY_SQRT3 * beta) * PWMHalfPeriod;

        // PWM timings
        tB = (PWMHalfPeriod - t2 - t3) / 2;
        tA = tB + t3;
        tC = tA + t2;

        break;
    }

    // sector 3-4
    case 3: {
        // Vector on-times
        uint32_t t3 = (TWO_BY_SQRT3 * beta) * PWMHalfPeriod;
        uint32_t t4 = (-alpha - ONE_BY_SQRT3 * beta) * PWMHalfPeriod;

        // PWM timings
        tB = (PWMHalfPeriod - t3 - t4) / 2;
        tC = tB + t3;
        tA = tC + t4;

        break;
    }

    // sector 4-5
    case 4: {
        // Vector on-times
        uint32_t t4 = (-alpha + ONE_BY_SQRT3 * beta) * PWMHalfPeriod;
        uint32_t t5 = (-TWO_BY_SQRT3 * beta) * PWMHalfPeriod;

        // PWM timings
        tC = (PWMHalfPeriod - t4 - t5) / 2;
        tB = tC + t5;
        tA = tB + t4;

        break;
    }

    // sector 5-6
    case 5: {
        // Vector on-times
        uint32_t t5 = (-alpha - ONE_BY_SQRT3 * beta) * PWMHalfPeriod;
        uint32_t t6 = (alpha - ONE_BY_SQRT3 * beta) * PWMHalfPeriod;

        // PWM timings
        tC = (PWMHalfPeriod - t5 - t6) / 2;
        tA = tC + t5;
        tB = tA + t6;

        break;
    }

    // sector 6-1
    case 6: {
        // Vector on-times
        uint32_t t6 = (-TWO_BY_SQRT3 * beta) * PWMHalfPeriod;
        uint32_t t1 = (alpha + ONE_BY_SQRT3 * beta) * PWMHalfPeriod;

        // PWM timings
        tA = (PWMHalfPeriod - t6 - t1) / 2;
        tC = tA + t1;
        tB = tC + t6;

        break;
    }
    }

    *tAout = tA;
    *tBout = tB;
    *tCout = tC;
//     *svm_sector = sector;
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}



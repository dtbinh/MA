/*
 * IPC4M_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "IPC4M".
 *
 * Model version              : 1.418
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Tue Dec  8 12:18:55 2015
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_IPC4M_private_h_
#define RTW_HEADER_IPC4M_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

extern void MWDSPCG_Pseudoinverse_D(const real_T pS[], const real_T pU[], const
  real_T pV[], real_T pX[], const int32_T M, const int32_T N);
extern void rt_mldivide_U1d18x18_U_2jkRkZaZ(const real_T u0[324], const real_T
  u1[18], real_T y[18]);
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern void IPC4M_MATLABFunction3(const real_T rtu_x[28],
  B_MATLABFunction3_IPC4M_T *localB);

/* private model entry point functions */
extern void IPC4M_derivatives(void);

#endif                                 /* RTW_HEADER_IPC4M_private_h_ */

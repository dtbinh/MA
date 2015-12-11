/*
 * IPC4M.h
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

#ifndef RTW_HEADER_IPC4M_h_
#define RTW_HEADER_IPC4M_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef IPC4M_COMMON_INCLUDES_
# define IPC4M_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "dspsvd_rt.h"
#endif                                 /* IPC4M_COMMON_INCLUDES_ */

#include "IPC4M_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->ModelData.periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->ModelData.periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->ModelData.periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->ModelData.periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals for system '<S6>/MATLAB Function3' */
typedef struct {
  real_T G[144];                       /* '<S6>/MATLAB Function3' */
} B_MATLABFunction3_IPC4M_T;

/* Block signals (auto storage) */
typedef struct {
  real_T A[900];
  real_T A_m[900];
  real_T A_c[720];                     /* '<S5>/MATLAB Function' */
  real_T Pseudoinverse_o[720];         /* '<S5>/Pseudoinverse' */
  real_T dv0[720];
  real_T A_k[576];
  real_T A_cx[576];
  real_T A_b[576];
  real_T Integrator1[3];               /* '<S10>/Integrator1' */
  real_T Integrator[4];                /* '<S80>/Integrator' */
  real_T Integrator_f[6];              /* '<S10>/Integrator' */
  real_T Gdx_o[24];                    /* '<S10>/G' dx_o' */
  real_T Gain1[5];                     /* '<Root>/Gain1' */
  real_T SineWave;                     /* '<Root>/Sine Wave' */
  real_T TmpSignalConversionAtdxGdx_odIn[6];
  real_T dxGdx_od[24];                 /* '<S7>/dx = G' dx_o,d' */
  real_T Integrator_g[4];              /* '<S89>/Integrator' */
  real_T Sum;                          /* '<S33>/Sum' */
  real_T p1p1d[3];                     /* '<S18>/p1-p1d' */
  real_T k1p1p1d2kapetaq1q1d[6];       /* '<S18>/k1(p1-p1d);2kapeta*q1//q1d' */
  real_T Product2[6];                  /* '<S18>/Product2' */
  real_T Add1[6];                      /* '<S18>/Add1' */
  real_T Add4[6];                      /* '<S19>/Add4' */
  real_T Add7[6];                      /* '<S20>/Add7' */
  real_T Add10[6];                     /* '<S21>/Add10' */
  real_T Sqrt[576];                    /* '<S9>/Sqrt' */
  real_T Add[24];                      /* '<S2>/Add' */
  real_T Negative[24];                 /* '<Root>/Negative' */
  real_T Add2[4];                      /* '<S18>/Add2' */
  real_T Sqrt_n[900];                  /* '<S5>/Sqrt' */
  real_T M[30];                        /* '<S5>/M' */
  real_T M_oddx_do[6];                 /* '<S6>/M_o*ddx_do' */
  real_T h_dGh_od[24];                 /* '<S6>/h_d = G+ *h_od' */
  real_T Add_o;                        /* '<S10>/Add' */
  real_T Sum_l;                        /* '<S84>/Sum' */
  real_T Sum_a;                        /* '<S85>/Sum' */
  real_T Sum_ak;                       /* '<S86>/Sum' */
  real_T Sum_e;                        /* '<S87>/Sum' */
  real_T Sum_j;                        /* '<S92>/Sum' */
  real_T Sum_d;                        /* '<S93>/Sum' */
  real_T Sum_lp;                       /* '<S94>/Sum' */
  real_T Sum_m;                        /* '<S95>/Sum' */
  real_T x[28];                        /* '<S10>/Manipualtor pose in world frame' */
  real_T h_int[24];                    /* '<S9>/World to Object Frame' */
  real_T x_d[28];                      /* '<S7>/Manipulator Position//Orientation in World Frame' */
  real_T hcoriolis[6];                 /* '<S6>/Coriolis Force' */
  real_T h_con[24];                    /* '<S2>/ConnectingStiffness' */
  real_T h_con_g[24];                  /* '<S2>/ConnectingDamping' */
  B_MATLABFunction3_IPC4M_T sf_GraspMatrix;/* '<S10>/Grasp Matrix' */
  B_MATLABFunction3_IPC4M_T sf_MATLABFunction3_a;/* '<S6>/MATLAB Function3' */
} B_IPC4M_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Pseudoinverse_V_e[900];       /* '<S5>/Pseudoinverse' */
  real_T Pseudoinverse_X_o[720];       /* '<S5>/Pseudoinverse' */
  real_T Pseudoinverse_V[576];         /* '<S9>/Pseudoinverse' */
  real_T Pseudoinverse_U_b[576];       /* '<S5>/Pseudoinverse' */
  real_T Pseudoinverse_V_h[576];       /* '<S6>/Pseudoinverse' */
  real_T TimeStampA;                   /* '<S13>/Derivative' */
  real_T LastUAtTimeA[6];              /* '<S13>/Derivative' */
  real_T TimeStampB;                   /* '<S13>/Derivative' */
  real_T LastUAtTimeB[6];              /* '<S13>/Derivative' */
  real_T Mult1_DWORK4[576];            /* '<S9>/Mult1' */
  real_T M2_DWORK4[900];               /* '<S5>/M2' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope10_PWORK;                     /* '<Root>/Scope10' */

  struct {
    void *LoggedData;
  } Scope11_PWORK;                     /* '<Root>/Scope11' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<Root>/Scope4' */

  struct {
    void *LoggedData;
  } Scope5_PWORK;                      /* '<Root>/Scope5' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_a;                    /* '<S2>/Scope1' */

  struct {
    void *LoggedData;
  } Scope5_PWORK_n;                    /* '<S2>/Scope5' */

  struct {
    void *LoggedData;
  } Scope_PWORK_g;                     /* '<S18>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_d;                    /* '<S18>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_c;                    /* '<S18>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK_m;                    /* '<S18>/Scope3' */

  struct {
    void *LoggedData;
  } Scope5_PWORK_h;                    /* '<S18>/Scope5' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_i;                    /* '<S7>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_p;                    /* '<S7>/Scope2' */

  struct {
    void *LoggedData;
  } Scope_PWORK_l;                     /* '<S10>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_n;                    /* '<S10>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_g;                    /* '<S10>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK_a;                    /* '<S10>/Scope3' */

  struct {
    void *LoggedData;
  } Scope_PWORK_f;                     /* '<S80>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_d;                     /* '<S89>/Scope' */
} DW_IPC4M_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator1_CSTATE[3];        /* '<S10>/Integrator1' */
  real_T Integrator_CSTATE[4];         /* '<S80>/Integrator' */
  real_T Integrator_CSTATE_f[6];       /* '<S10>/Integrator' */
  real_T PT1Filter_CSTATE;             /* '<Root>/PT1 Filter' */
  real_T Integrator_CSTATE_i[3];       /* '<S13>/Integrator' */
  real_T Integrator_CSTATE_e[4];       /* '<S89>/Integrator' */
} X_IPC4M_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator1_CSTATE[3];        /* '<S10>/Integrator1' */
  real_T Integrator_CSTATE[4];         /* '<S80>/Integrator' */
  real_T Integrator_CSTATE_f[6];       /* '<S10>/Integrator' */
  real_T PT1Filter_CSTATE;             /* '<Root>/PT1 Filter' */
  real_T Integrator_CSTATE_i[3];       /* '<S13>/Integrator' */
  real_T Integrator_CSTATE_e[4];       /* '<S89>/Integrator' */
} XDot_IPC4M_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE[3];     /* '<S10>/Integrator1' */
  boolean_T Integrator_CSTATE[4];      /* '<S80>/Integrator' */
  boolean_T Integrator_CSTATE_f[6];    /* '<S10>/Integrator' */
  boolean_T PT1Filter_CSTATE;          /* '<Root>/PT1 Filter' */
  boolean_T Integrator_CSTATE_i[3];    /* '<S13>/Integrator' */
  boolean_T Integrator_CSTATE_e[4];    /* '<S89>/Integrator' */
} XDis_IPC4M_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (auto storage) */
struct P_IPC4M_T_ {
  real_T Dc;                           /* Variable: Dc
                                        * Referenced by: '<S2>/ConnectingDamping'
                                        */
  real_T Kc;                           /* Variable: Kc
                                        * Referenced by: '<S2>/ConnectingStiffness'
                                        */
  real_T j0;                           /* Variable: j0
                                        * Referenced by:
                                        *   '<S5>/Coriolis Force'
                                        *   '<S6>/Coriolis Force'
                                        */
  real_T k1;                           /* Variable: k1
                                        * Referenced by: '<S18>/k1; 2kappa1*eta1'
                                        */
  real_T k2;                           /* Variable: k2
                                        * Referenced by: '<S19>/MATLAB Function1'
                                        */
  real_T k3;                           /* Variable: k3
                                        * Referenced by: '<S20>/MATLAB Function2'
                                        */
  real_T k4;                           /* Variable: k4
                                        * Referenced by: '<S21>/MATLAB Function3'
                                        */
  real_T kappa1;                       /* Variable: kappa1
                                        * Referenced by: '<S18>/k1; 2kappa1*eta1'
                                        */
  real_T kappa2;                       /* Variable: kappa2
                                        * Referenced by: '<S19>/MATLAB Function1'
                                        */
  real_T kappa3;                       /* Variable: kappa3
                                        * Referenced by: '<S20>/MATLAB Function2'
                                        */
  real_T kappa4;                       /* Variable: kappa4
                                        * Referenced by: '<S21>/MATLAB Function3'
                                        */
  real_T l[4];                         /* Variable: l
                                        * Referenced by: '<S2>/ConnectingStiffness'
                                        */
  real_T m0;                           /* Variable: m0
                                        * Referenced by:
                                        *   '<S5>/Coriolis Force'
                                        *   '<S6>/Coriolis Force'
                                        */
  real_T r[12];                        /* Variable: r
                                        * Referenced by:
                                        *   '<S1>/MATLAB Function'
                                        *   '<S1>/MATLAB Function1'
                                        *   '<S5>/Centripetal Force'
                                        *   '<S5>/MATLAB Function'
                                        *   '<S6>/MATLAB Function3'
                                        *   '<S7>/Grasp Matrix'
                                        *   '<S7>/Manipulator Position//Orientation in World Frame'
                                        *   '<S9>/Centripal Force'
                                        *   '<S9>/Reduced Constraint Matrix'
                                        *   '<S10>/Grasp Matrix'
                                        *   '<S10>/Manipualtor pose in world frame'
                                        *   '<S11>/Reduced Constraint Matrix'
                                        */
  real_T Integrator1_IC[3];            /* Expression: [0 0 0]'
                                        * Referenced by: '<S10>/Integrator1'
                                        */
  real_T Integrator_IC[4];             /* Expression: [1; 0; 0; 0]
                                        * Referenced by: '<S80>/Integrator'
                                        */
  real_T Integrator_IC_i[6];           /* Expression: zeros(6,1)
                                        * Referenced by: '<S10>/Integrator'
                                        */
  real_T PT1Filter_A;                  /* Computed Parameter: PT1Filter_A
                                        * Referenced by: '<Root>/PT1 Filter'
                                        */
  real_T PT1Filter_C;                  /* Computed Parameter: PT1Filter_C
                                        * Referenced by: '<Root>/PT1 Filter'
                                        */
  real_T Gain1_Gain[5];                /* Expression: [1;0;0;0;0]
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T SineWave_Amp;                 /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 1*pi
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T Integrator_IC_j[3];           /* Expression: zeros(3,1)
                                        * Referenced by: '<S13>/Integrator'
                                        */
  real_T Integrator_IC_o[4];           /* Expression: [1; 0; 0; 0]
                                        * Referenced by: '<S89>/Integrator'
                                        */
  real_T Damping_Value[36];            /* Expression: blkdiag(d1*eye(3),delta1*eye(3))
                                        * Referenced by: '<S18>/Damping'
                                        */
  real_T Inertia_Value[36];            /* Expression: blkdiag(m1d*eye(3),j1d*eye(3))
                                        * Referenced by: '<S18>/Inertia'
                                        */
  real_T Damping1_Value[36];           /* Expression: blkdiag(d2*eye(3),delta2*eye(3))
                                        * Referenced by: '<S19>/Damping1'
                                        */
  real_T Inertia1_Value[36];           /* Expression: blkdiag(m2d*eye(3),j2d*eye(3))
                                        * Referenced by: '<S19>/Inertia1'
                                        */
  real_T Damping2_Value[36];           /* Expression: blkdiag(d3*eye(3),delta3*eye(3))
                                        * Referenced by: '<S20>/Damping2'
                                        */
  real_T Inertia2_Value[36];           /* Expression: blkdiag(m3d*eye(3),j3d*eye(3))
                                        * Referenced by: '<S20>/Inertia2'
                                        */
  real_T Damping3_Value[36];           /* Expression: blkdiag(d4*eye(3),delta4*eye(3))
                                        * Referenced by: '<S21>/Damping3'
                                        */
  real_T Inertia3_Value[36];           /* Expression: blkdiag(m4d*eye(3),j4d*eye(3))
                                        * Referenced by: '<S21>/Inertia3'
                                        */
  real_T Inertia_Value_h[576];         /* Expression: blkdiag(m1*eye(3), j1*eye(3), m2*eye(3), j2*eye(3), m3*eye(3), j3*eye(3), m4*eye(3), j4*eye(3))
                                        * Referenced by: '<S9>/Inertia'
                                        */
  real_T DesiredInternalForces_Value[18];/* Expression: zeros(18,1)
                                          * Referenced by: '<Root>/Desired Internal Forces'
                                          */
  real_T Negative_Gain;                /* Expression: -1
                                        * Referenced by: '<Root>/Negative'
                                        */
  real_T Inertia_Value_l[576];         /* Expression: blkdiag(m1d*eye(3), j1d*eye(3), m2d*eye(3), j2d*eye(3), m3d*eye(3), j3d*eye(3), m4d*eye(3), j4d*eye(3))
                                        * Referenced by: '<S1>/Inertia'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Distortion_Value[6];          /* Expression: zeros(6,1)
                                        * Referenced by: '<Root>/Distortion'
                                        */
  real_T Inertia_Value_h0[900];        /* Expression: blkdiag(m0*eye(3),j0*eye(3),m1*eye(3), j1*eye(3), m2*eye(3), j2*eye(3), m3*eye(3), j3*eye(3), m4*eye(3), j4*eye(3))
                                        * Referenced by: '<S5>/Inertia'
                                        */
  real_T Gravitation_Value[6];         /* Expression: [-m0*g;zeros(3,1)]
                                        * Referenced by: '<S5>/Gravitation'
                                        */
  real_T ObjectInertia_Value[36];      /* Expression: blkdiag(m0*eye(3),j0*eye(3));
                                        * Referenced by: '<S6>/Object Inertia'
                                        */
  real_T Gravitation_Value_i[6];       /* Expression: [-m0*g;zeros(3,1)]
                                        * Referenced by: '<S6>/Gravitation'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S80>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.5
                                        * Referenced by: '<S80>/Gain'
                                        */
  real_T Constant_Value_c;             /* Expression: 0
                                        * Referenced by: '<S89>/Constant'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 0.5
                                        * Referenced by: '<S89>/Gain'
                                        */
  real_T DesiredInternalForces1_Value[18];/* Expression: [0 -10 0 0 0 0    10 0 0 0 0 0      0 10 0 0 0 0]'
                                           * Referenced by: '<Root>/Desired Internal Forces1'
                                           */
};

/* Real-time Model Data Structure */
struct tag_RTM_IPC4M_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    X_IPC4M_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[21];
    real_T odeF[3][21];
    ODE3_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_IPC4M_T IPC4M_P;

/* Block signals (auto storage) */
extern B_IPC4M_T IPC4M_B;

/* Continuous states (auto storage) */
extern X_IPC4M_T IPC4M_X;

/* Block states (auto storage) */
extern DW_IPC4M_T IPC4M_DW;

/* Model entry point functions */
extern void IPC4M_initialize(void);
extern void IPC4M_step(void);
extern void IPC4M_terminate(void);

/* Real-time Model object */
extern RT_MODEL_IPC4M_T *const IPC4M_M;

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
 * '<Root>' : 'IPC4M'
 * '<S1>'   : 'IPC4M/Allocator'
 * '<S2>'   : 'IPC4M/Connecting Spring'
 * '<S3>'   : 'IPC4M/Impedance control'
 * '<S4>'   : 'IPC4M/Interaction dynamics'
 * '<S5>'   : 'IPC4M/Interaction dynamics1'
 * '<S6>'   : 'IPC4M/Inverse Dynamics'
 * '<S7>'   : 'IPC4M/Kinematic Coordination'
 * '<S8>'   : 'IPC4M/MATLAB Function'
 * '<S9>'   : 'IPC4M/Manipulator dynamics'
 * '<S10>'  : 'IPC4M/Manipulator motion'
 * '<S11>'  : 'IPC4M/Nullspace'
 * '<S12>'  : 'IPC4M/Object to World Frame'
 * '<S13>'  : 'IPC4M/Trajectory Generation'
 * '<S14>'  : 'IPC4M/Allocator/MATLAB Function'
 * '<S15>'  : 'IPC4M/Allocator/MATLAB Function1'
 * '<S16>'  : 'IPC4M/Connecting Spring/ConnectingDamping'
 * '<S17>'  : 'IPC4M/Connecting Spring/ConnectingStiffness'
 * '<S18>'  : 'IPC4M/Impedance control/Manipulator1'
 * '<S19>'  : 'IPC4M/Impedance control/Manipulator2'
 * '<S20>'  : 'IPC4M/Impedance control/Manipulator3'
 * '<S21>'  : 'IPC4M/Impedance control/Manipulator4'
 * '<S22>'  : 'IPC4M/Impedance control/Manipulator1/Quaternion Conjugate'
 * '<S23>'  : 'IPC4M/Impedance control/Manipulator1/Quaternion Multiplication'
 * '<S24>'  : 'IPC4M/Impedance control/Manipulator1/Subsystem'
 * '<S25>'  : 'IPC4M/Impedance control/Manipulator1/k1; 2kappa1*eta1'
 * '<S26>'  : 'IPC4M/Impedance control/Manipulator1/Quaternion Multiplication/q0'
 * '<S27>'  : 'IPC4M/Impedance control/Manipulator1/Quaternion Multiplication/q1'
 * '<S28>'  : 'IPC4M/Impedance control/Manipulator1/Quaternion Multiplication/q2'
 * '<S29>'  : 'IPC4M/Impedance control/Manipulator1/Quaternion Multiplication/q3'
 * '<S30>'  : 'IPC4M/Impedance control/Manipulator1/Subsystem/Quaternion Conjugate1'
 * '<S31>'  : 'IPC4M/Impedance control/Manipulator1/Subsystem/Quaternion Multiplication1'
 * '<S32>'  : 'IPC4M/Impedance control/Manipulator1/Subsystem/Quaternion Multiplication2'
 * '<S33>'  : 'IPC4M/Impedance control/Manipulator1/Subsystem/Quaternion Multiplication1/q0'
 * '<S34>'  : 'IPC4M/Impedance control/Manipulator1/Subsystem/Quaternion Multiplication1/q1'
 * '<S35>'  : 'IPC4M/Impedance control/Manipulator1/Subsystem/Quaternion Multiplication1/q2'
 * '<S36>'  : 'IPC4M/Impedance control/Manipulator1/Subsystem/Quaternion Multiplication1/q3'
 * '<S37>'  : 'IPC4M/Impedance control/Manipulator1/Subsystem/Quaternion Multiplication2/q0'
 * '<S38>'  : 'IPC4M/Impedance control/Manipulator1/Subsystem/Quaternion Multiplication2/q1'
 * '<S39>'  : 'IPC4M/Impedance control/Manipulator1/Subsystem/Quaternion Multiplication2/q2'
 * '<S40>'  : 'IPC4M/Impedance control/Manipulator1/Subsystem/Quaternion Multiplication2/q3'
 * '<S41>'  : 'IPC4M/Impedance control/Manipulator2/MATLAB Function1'
 * '<S42>'  : 'IPC4M/Impedance control/Manipulator2/Quaternion Division1'
 * '<S43>'  : 'IPC4M/Impedance control/Manipulator2/Quaternion Division1/Quaternion Norm'
 * '<S44>'  : 'IPC4M/Impedance control/Manipulator2/Quaternion Division1/q0'
 * '<S45>'  : 'IPC4M/Impedance control/Manipulator2/Quaternion Division1/q1'
 * '<S46>'  : 'IPC4M/Impedance control/Manipulator2/Quaternion Division1/q2'
 * '<S47>'  : 'IPC4M/Impedance control/Manipulator2/Quaternion Division1/q3'
 * '<S48>'  : 'IPC4M/Impedance control/Manipulator3/MATLAB Function2'
 * '<S49>'  : 'IPC4M/Impedance control/Manipulator3/Quaternion Division2'
 * '<S50>'  : 'IPC4M/Impedance control/Manipulator3/Quaternion Division2/Quaternion Norm'
 * '<S51>'  : 'IPC4M/Impedance control/Manipulator3/Quaternion Division2/q0'
 * '<S52>'  : 'IPC4M/Impedance control/Manipulator3/Quaternion Division2/q1'
 * '<S53>'  : 'IPC4M/Impedance control/Manipulator3/Quaternion Division2/q2'
 * '<S54>'  : 'IPC4M/Impedance control/Manipulator3/Quaternion Division2/q3'
 * '<S55>'  : 'IPC4M/Impedance control/Manipulator4/MATLAB Function3'
 * '<S56>'  : 'IPC4M/Impedance control/Manipulator4/Quaternion Division3'
 * '<S57>'  : 'IPC4M/Impedance control/Manipulator4/Quaternion Division3/Quaternion Norm'
 * '<S58>'  : 'IPC4M/Impedance control/Manipulator4/Quaternion Division3/q0'
 * '<S59>'  : 'IPC4M/Impedance control/Manipulator4/Quaternion Division3/q1'
 * '<S60>'  : 'IPC4M/Impedance control/Manipulator4/Quaternion Division3/q2'
 * '<S61>'  : 'IPC4M/Impedance control/Manipulator4/Quaternion Division3/q3'
 * '<S62>'  : 'IPC4M/Interaction dynamics/Apparent Inertia'
 * '<S63>'  : 'IPC4M/Interaction dynamics/Centripetal Force'
 * '<S64>'  : 'IPC4M/Interaction dynamics/Coriolis Force'
 * '<S65>'  : 'IPC4M/Interaction dynamics/Grasp Matrix'
 * '<S66>'  : 'IPC4M/Interaction dynamics1/Centripetal Force'
 * '<S67>'  : 'IPC4M/Interaction dynamics1/Coriolis Force'
 * '<S68>'  : 'IPC4M/Interaction dynamics1/MATLAB Function'
 * '<S69>'  : 'IPC4M/Inverse Dynamics/Coriolis Force'
 * '<S70>'  : 'IPC4M/Inverse Dynamics/MATLAB Function3'
 * '<S71>'  : 'IPC4M/Inverse Dynamics/Weighted Generalized Inverse'
 * '<S72>'  : 'IPC4M/Inverse Dynamics/Weighted Generalized Inverse1'
 * '<S73>'  : 'IPC4M/Inverse Dynamics/Weighted Generalized Inverse2'
 * '<S74>'  : 'IPC4M/Kinematic Coordination/Centripetal Force'
 * '<S75>'  : 'IPC4M/Kinematic Coordination/Grasp Matrix'
 * '<S76>'  : 'IPC4M/Kinematic Coordination/Manipulator Position//Orientation in World Frame'
 * '<S77>'  : 'IPC4M/Manipulator dynamics/Centripal Force'
 * '<S78>'  : 'IPC4M/Manipulator dynamics/Reduced Constraint Matrix'
 * '<S79>'  : 'IPC4M/Manipulator dynamics/World to Object Frame'
 * '<S80>'  : 'IPC4M/Manipulator motion/Angular Velocity to Quaternion'
 * '<S81>'  : 'IPC4M/Manipulator motion/Grasp Matrix'
 * '<S82>'  : 'IPC4M/Manipulator motion/Manipualtor pose in world frame'
 * '<S83>'  : 'IPC4M/Manipulator motion/Angular Velocity to Quaternion/Quaternion Multiplication'
 * '<S84>'  : 'IPC4M/Manipulator motion/Angular Velocity to Quaternion/Quaternion Multiplication/q0'
 * '<S85>'  : 'IPC4M/Manipulator motion/Angular Velocity to Quaternion/Quaternion Multiplication/q1'
 * '<S86>'  : 'IPC4M/Manipulator motion/Angular Velocity to Quaternion/Quaternion Multiplication/q2'
 * '<S87>'  : 'IPC4M/Manipulator motion/Angular Velocity to Quaternion/Quaternion Multiplication/q3'
 * '<S88>'  : 'IPC4M/Nullspace/Reduced Constraint Matrix'
 * '<S89>'  : 'IPC4M/Trajectory Generation/Angular Velocity to Quaternion Orientation'
 * '<S90>'  : 'IPC4M/Trajectory Generation/Quaternion Normalize'
 * '<S91>'  : 'IPC4M/Trajectory Generation/Angular Velocity to Quaternion Orientation/Quaternion Multiplication'
 * '<S92>'  : 'IPC4M/Trajectory Generation/Angular Velocity to Quaternion Orientation/Quaternion Multiplication/q0'
 * '<S93>'  : 'IPC4M/Trajectory Generation/Angular Velocity to Quaternion Orientation/Quaternion Multiplication/q1'
 * '<S94>'  : 'IPC4M/Trajectory Generation/Angular Velocity to Quaternion Orientation/Quaternion Multiplication/q2'
 * '<S95>'  : 'IPC4M/Trajectory Generation/Angular Velocity to Quaternion Orientation/Quaternion Multiplication/q3'
 * '<S96>'  : 'IPC4M/Trajectory Generation/Quaternion Normalize/Quaternion Modulus'
 * '<S97>'  : 'IPC4M/Trajectory Generation/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 */
#endif                                 /* RTW_HEADER_IPC4M_h_ */

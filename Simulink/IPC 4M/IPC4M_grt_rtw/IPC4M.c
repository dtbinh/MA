/*
 * IPC4M.c
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

#include "IPC4M.h"
#include "IPC4M_private.h"

/* Block signals (auto storage) */
B_IPC4M_T IPC4M_B;

/* Continuous states */
X_IPC4M_T IPC4M_X;

/* Block states (auto storage) */
DW_IPC4M_T IPC4M_DW;

/* Real-time model */
RT_MODEL_IPC4M_T IPC4M_M_;
RT_MODEL_IPC4M_T *const IPC4M_M = &IPC4M_M_;

/* Forward declaration for local functions */
static void IPC4M_quatmultiply(const real_T q[4], const real_T b_r[4], real_T
  qout[4]);

/* Forward declaration for local functions */
static void IPC4M_quatmultiply_k(const real_T q[4], const real_T b_r[4], real_T
  qout[4]);
static void IPC4M_quatmultiply_h(const real_T q[4], const real_T b_r[4], real_T
  qout[4]);
static void IPC4M_quatmultiply_l(const real_T q[4], const real_T b_r[4], real_T
  qout[4]);
static void IPC4M_quatmultiply_ec(const real_T q[4], const real_T r[4], real_T
  qout[4]);
static void IPC4M_quatmultiply_i(const real_T q[4], const real_T b_r[4], real_T
  qout[4]);
static void rt_mrdivide_U1d18x24_U_TXABSG_n(const real_T u0[432], const real_T
  u1[576], real_T y[432]);
static real_T IPC4M_norm(const real_T x[3]);
static void IPC4M_quatmultiply_n3(const real_T q[4], const real_T b_r[4], real_T
  qout[4]);
static void rt_mldivide_U1d24x24_U_NAKP2m_n(const real_T u0[576], const real_T
  u1[24], real_T y[24]);
static void IPC4M_quatmultiply_lm(const real_T q[4], const real_T r[4], real_T
  qout[4]);
static void IPC4M_quatmultiply_f(const real_T q[4], const real_T b_r[4], real_T
  qout[4]);
static void IPC4M_quatmultiply_g(const real_T q[4], const real_T r[4], real_T
  qout[4]);
static void IPC4M_quatmultiply_b(const real_T q[4], const real_T b_r[4], real_T
  qout[4]);
static void IPC4M_quatmultiply_n(const real_T q[4], const real_T b_r[4], real_T
  qout[4]);
static void rt_mldivide_U1d24x24_U_2VUCyo_n(const real_T u0[576], const real_T
  u1[432], real_T y[432]);
static void IPC4M_quatmultiply_e(const real_T q[4], const real_T b_r[4], real_T
  qout[4]);
static void IPC4M_quatmultiply_p(const real_T q[4], const real_T b_r[4], real_T
  qout[4]);
static void rt_mldivide_U1d30x30_U_kRq1hM_n(const real_T u0[900], const real_T
  u1[30], real_T y[30]);
static void rt_mrdivide_U1d24x30_U_zeNn4d_n(const real_T u0[720], const real_T
  u1[900], real_T y[720]);

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 21;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  IPC4M_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  IPC4M_step();
  IPC4M_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  IPC4M_step();
  IPC4M_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Function for MATLAB Function: '<S6>/MATLAB Function3' */
static void IPC4M_quatmultiply(const real_T q[4], const real_T b_r[4], real_T
  qout[4])
{
  qout[0] = ((q[0] * b_r[0] - q[1] * b_r[1]) - q[2] * b_r[2]) - q[3] * b_r[3];
  qout[1] = (q[0] * b_r[1] + b_r[0] * q[1]) + (q[2] * b_r[3] - q[3] * b_r[2]);
  qout[2] = (q[0] * b_r[2] + b_r[0] * q[2]) + (q[3] * b_r[1] - q[1] * b_r[3]);
  qout[3] = (q[0] * b_r[3] + b_r[0] * q[3]) + (q[1] * b_r[2] - q[2] * b_r[1]);
}

/*
 * Output and update for atomic system:
 *    '<S6>/MATLAB Function3'
 *    '<S10>/Grasp Matrix'
 */
void IPC4M_MATLABFunction3(const real_T rtu_x[28], B_MATLABFunction3_IPC4M_T
  *localB)
{
  int8_T I[9];
  int8_T b_I[9];
  int8_T c_I[9];
  int8_T d_I[9];
  real_T q[4];
  int8_T e_I[9];
  int8_T f_I[9];
  int8_T g_I[9];
  int8_T h_I[9];
  real_T tmp[4];
  real_T tmp_0[4];
  real_T tmp_1[4];
  real_T tmp_2[4];
  real_T tmp_3[4];
  int32_T i;

  /* MATLAB Function 'Inverse Dynamics/MATLAB Function3': '<S70>:1' */
  /* '<S70>:1:2' */
  for (i = 0; i < 9; i++) {
    I[i] = 0;
    b_I[i] = 0;
    c_I[i] = 0;
    d_I[i] = 0;
    e_I[i] = 0;
    f_I[i] = 0;
    g_I[i] = 0;
    h_I[i] = 0;
  }

  I[0] = 1;
  I[4] = 1;
  I[8] = 1;
  b_I[0] = 1;
  b_I[4] = 1;
  b_I[8] = 1;
  c_I[0] = 1;
  c_I[4] = 1;
  c_I[8] = 1;
  d_I[0] = 1;
  d_I[4] = 1;
  d_I[8] = 1;

  /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
  /*  frame */
  q[0] = rtu_x[3];
  q[1] = -rtu_x[4];
  q[2] = -rtu_x[5];
  q[3] = -rtu_x[6];
  tmp_2[0] = 0.0;
  tmp_2[1] = IPC4M_P.r[0];
  tmp_2[2] = IPC4M_P.r[1];
  tmp_2[3] = IPC4M_P.r[2];
  IPC4M_quatmultiply(tmp_2, q, tmp_3);
  IPC4M_quatmultiply(*(real_T (*)[4])&rtu_x[3], tmp_3, tmp_2);

  /* generates skew- symmetric matrix from vector */
  e_I[0] = 1;
  e_I[4] = 1;
  e_I[8] = 1;

  /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
  /*  frame */
  q[0] = rtu_x[3];
  q[1] = -rtu_x[4];
  q[2] = -rtu_x[5];
  q[3] = -rtu_x[6];
  tmp_1[0] = 0.0;
  tmp_1[1] = IPC4M_P.r[3];
  tmp_1[2] = IPC4M_P.r[4];
  tmp_1[3] = IPC4M_P.r[5];
  IPC4M_quatmultiply(tmp_1, q, tmp_3);
  IPC4M_quatmultiply(*(real_T (*)[4])&rtu_x[3], tmp_3, tmp_1);

  /* generates skew- symmetric matrix from vector */
  f_I[0] = 1;
  f_I[4] = 1;
  f_I[8] = 1;

  /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
  /*  frame */
  q[0] = rtu_x[3];
  q[1] = -rtu_x[4];
  q[2] = -rtu_x[5];
  q[3] = -rtu_x[6];
  tmp_0[0] = 0.0;
  tmp_0[1] = IPC4M_P.r[6];
  tmp_0[2] = IPC4M_P.r[7];
  tmp_0[3] = IPC4M_P.r[8];
  IPC4M_quatmultiply(tmp_0, q, tmp_3);
  IPC4M_quatmultiply(*(real_T (*)[4])&rtu_x[3], tmp_3, tmp_0);

  /* generates skew- symmetric matrix from vector */
  g_I[0] = 1;
  g_I[4] = 1;
  g_I[8] = 1;

  /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
  /*  frame */
  q[0] = rtu_x[3];
  q[1] = -rtu_x[4];
  q[2] = -rtu_x[5];
  q[3] = -rtu_x[6];
  tmp[0] = 0.0;
  tmp[1] = IPC4M_P.r[9];
  tmp[2] = IPC4M_P.r[10];
  tmp[3] = IPC4M_P.r[11];
  IPC4M_quatmultiply(tmp, q, tmp_3);
  IPC4M_quatmultiply(*(real_T (*)[4])&rtu_x[3], tmp_3, q);

  /* generates skew- symmetric matrix from vector */
  h_I[0] = 1;
  h_I[4] = 1;
  h_I[8] = 1;
  for (i = 0; i < 3; i++) {
    localB->G[6 * i] = I[3 * i];
    localB->G[1 + 6 * i] = I[3 * i + 1];
    localB->G[2 + 6 * i] = I[3 * i + 2];
  }

  for (i = 0; i < 3; i++) {
    localB->G[6 * (i + 3)] = 0.0;
    localB->G[1 + 6 * (i + 3)] = 0.0;
    localB->G[2 + 6 * (i + 3)] = 0.0;
  }

  for (i = 0; i < 3; i++) {
    localB->G[6 * (i + 6)] = b_I[3 * i];
    localB->G[1 + 6 * (i + 6)] = b_I[3 * i + 1];
    localB->G[2 + 6 * (i + 6)] = b_I[3 * i + 2];
  }

  for (i = 0; i < 3; i++) {
    localB->G[6 * (i + 9)] = 0.0;
    localB->G[1 + 6 * (i + 9)] = 0.0;
    localB->G[2 + 6 * (i + 9)] = 0.0;
  }

  for (i = 0; i < 3; i++) {
    localB->G[6 * (i + 12)] = c_I[3 * i];
    localB->G[1 + 6 * (i + 12)] = c_I[3 * i + 1];
    localB->G[2 + 6 * (i + 12)] = c_I[3 * i + 2];
  }

  for (i = 0; i < 3; i++) {
    localB->G[6 * (i + 15)] = 0.0;
    localB->G[1 + 6 * (i + 15)] = 0.0;
    localB->G[2 + 6 * (i + 15)] = 0.0;
  }

  for (i = 0; i < 3; i++) {
    localB->G[6 * (i + 18)] = d_I[3 * i];
    localB->G[1 + 6 * (i + 18)] = d_I[3 * i + 1];
    localB->G[2 + 6 * (i + 18)] = d_I[3 * i + 2];
  }

  for (i = 0; i < 3; i++) {
    localB->G[6 * (i + 21)] = 0.0;
    localB->G[1 + 6 * (i + 21)] = 0.0;
    localB->G[2 + 6 * (i + 21)] = 0.0;
  }

  localB->G[3] = 0.0;
  localB->G[9] = -tmp_2[3];
  localB->G[15] = tmp_2[2];
  localB->G[4] = tmp_2[3];
  localB->G[10] = 0.0;
  localB->G[16] = -tmp_2[1];
  localB->G[5] = -tmp_2[2];
  localB->G[11] = tmp_2[1];
  localB->G[17] = 0.0;
  for (i = 0; i < 3; i++) {
    localB->G[3 + 6 * (i + 3)] = e_I[3 * i];
    localB->G[4 + 6 * (i + 3)] = e_I[3 * i + 1];
    localB->G[5 + 6 * (i + 3)] = e_I[3 * i + 2];
  }

  localB->G[39] = 0.0;
  localB->G[45] = -tmp_1[3];
  localB->G[51] = tmp_1[2];
  localB->G[40] = tmp_1[3];
  localB->G[46] = 0.0;
  localB->G[52] = -tmp_1[1];
  localB->G[41] = -tmp_1[2];
  localB->G[47] = tmp_1[1];
  localB->G[53] = 0.0;
  for (i = 0; i < 3; i++) {
    localB->G[3 + 6 * (i + 9)] = f_I[3 * i];
    localB->G[4 + 6 * (i + 9)] = f_I[3 * i + 1];
    localB->G[5 + 6 * (i + 9)] = f_I[3 * i + 2];
  }

  localB->G[75] = 0.0;
  localB->G[81] = -tmp_0[3];
  localB->G[87] = tmp_0[2];
  localB->G[76] = tmp_0[3];
  localB->G[82] = 0.0;
  localB->G[88] = -tmp_0[1];
  localB->G[77] = -tmp_0[2];
  localB->G[83] = tmp_0[1];
  localB->G[89] = 0.0;
  for (i = 0; i < 3; i++) {
    localB->G[3 + 6 * (i + 15)] = g_I[3 * i];
    localB->G[4 + 6 * (i + 15)] = g_I[3 * i + 1];
    localB->G[5 + 6 * (i + 15)] = g_I[3 * i + 2];
  }

  localB->G[111] = 0.0;
  localB->G[117] = -q[3];
  localB->G[123] = q[2];
  localB->G[112] = q[3];
  localB->G[118] = 0.0;
  localB->G[124] = -q[1];
  localB->G[113] = -q[2];
  localB->G[119] = q[1];
  localB->G[125] = 0.0;
  for (i = 0; i < 3; i++) {
    localB->G[3 + 6 * (i + 21)] = h_I[3 * i];
    localB->G[4 + 6 * (i + 21)] = h_I[3 * i + 1];
    localB->G[5 + 6 * (i + 21)] = h_I[3 * i + 2];
  }
}

/* Function for MATLAB Function: '<S10>/Manipualtor pose in world frame' */
static void IPC4M_quatmultiply_k(const real_T q[4], const real_T b_r[4], real_T
  qout[4])
{
  qout[0] = ((q[0] * b_r[0] - q[1] * b_r[1]) - q[2] * b_r[2]) - q[3] * b_r[3];
  qout[1] = (q[0] * b_r[1] + b_r[0] * q[1]) + (q[2] * b_r[3] - q[3] * b_r[2]);
  qout[2] = (q[0] * b_r[2] + b_r[0] * q[2]) + (q[3] * b_r[1] - q[1] * b_r[3]);
  qout[3] = (q[0] * b_r[3] + b_r[0] * q[3]) + (q[1] * b_r[2] - q[2] * b_r[1]);
}

/* Function for MATLAB Function: '<S7>/Grasp Matrix' */
static void IPC4M_quatmultiply_h(const real_T q[4], const real_T b_r[4], real_T
  qout[4])
{
  qout[0] = ((q[0] * b_r[0] - q[1] * b_r[1]) - q[2] * b_r[2]) - q[3] * b_r[3];
  qout[1] = (q[0] * b_r[1] + b_r[0] * q[1]) + (q[2] * b_r[3] - q[3] * b_r[2]);
  qout[2] = (q[0] * b_r[2] + b_r[0] * q[2]) + (q[3] * b_r[1] - q[1] * b_r[3]);
  qout[3] = (q[0] * b_r[3] + b_r[0] * q[3]) + (q[1] * b_r[2] - q[2] * b_r[1]);
}

/* Function for MATLAB Function: '<S7>/Manipulator Position//Orientation in World Frame' */
static void IPC4M_quatmultiply_l(const real_T q[4], const real_T b_r[4], real_T
  qout[4])
{
  qout[0] = ((q[0] * b_r[0] - q[1] * b_r[1]) - q[2] * b_r[2]) - q[3] * b_r[3];
  qout[1] = (q[0] * b_r[1] + b_r[0] * q[1]) + (q[2] * b_r[3] - q[3] * b_r[2]);
  qout[2] = (q[0] * b_r[2] + b_r[0] * q[2]) + (q[3] * b_r[1] - q[1] * b_r[3]);
  qout[3] = (q[0] * b_r[3] + b_r[0] * q[3]) + (q[1] * b_r[2] - q[2] * b_r[1]);
}

/* Function for MATLAB Function: '<S7>/Centripetal Force' */
static void IPC4M_quatmultiply_ec(const real_T q[4], const real_T r[4], real_T
  qout[4])
{
  qout[0] = ((q[0] * r[0] - q[1] * r[1]) - q[2] * r[2]) - q[3] * r[3];
  qout[1] = (q[0] * r[1] + r[0] * q[1]) + (q[2] * r[3] - q[3] * r[2]);
  qout[2] = (q[0] * r[2] + r[0] * q[2]) + (q[3] * r[1] - q[1] * r[3]);
  qout[3] = (q[0] * r[3] + r[0] * q[3]) + (q[1] * r[2] - q[2] * r[1]);
}

/* Function for MATLAB Function: '<S9>/Reduced Constraint Matrix' */
static void IPC4M_quatmultiply_i(const real_T q[4], const real_T b_r[4], real_T
  qout[4])
{
  qout[0] = ((q[0] * b_r[0] - q[1] * b_r[1]) - q[2] * b_r[2]) - q[3] * b_r[3];
  qout[1] = (q[0] * b_r[1] + b_r[0] * q[1]) + (q[2] * b_r[3] - q[3] * b_r[2]);
  qout[2] = (q[0] * b_r[2] + b_r[0] * q[2]) + (q[3] * b_r[1] - q[1] * b_r[3]);
  qout[3] = (q[0] * b_r[3] + b_r[0] * q[3]) + (q[1] * b_r[2] - q[2] * b_r[1]);
}

static void rt_mrdivide_U1d18x24_U_TXABSG_n(const real_T u0[432], const real_T
  u1[576], real_T y[432])
{
  int32_T jp;
  real_T temp;
  int8_T ipiv[24];
  int32_T j;
  int32_T c;
  int32_T ix;
  real_T s;
  int32_T jA;
  int32_T jBcol;
  int32_T kBcol;
  int32_T k;
  memcpy(&IPC4M_B.A_k[0], &u1[0], 576U * sizeof(real_T));
  for (j = 0; j < 24; j++) {
    ipiv[j] = (int8_T)(1 + j);
  }

  for (j = 0; j < 23; j++) {
    c = j * 25;
    kBcol = j * 25;
    jp = 1;
    ix = c;
    temp = fabs(IPC4M_B.A_k[kBcol]);
    for (k = 2; k <= 24 - j; k++) {
      ix++;
      s = fabs(IPC4M_B.A_k[ix]);
      if (s > temp) {
        jp = k;
        temp = s;
      }
    }

    jp--;
    if (IPC4M_B.A_k[c + jp] != 0.0) {
      if (jp != 0) {
        ipiv[j] = (int8_T)((j + jp) + 1);
        ix = j;
        jp += j;
        for (k = 0; k < 24; k++) {
          temp = IPC4M_B.A_k[ix];
          IPC4M_B.A_k[ix] = IPC4M_B.A_k[jp];
          IPC4M_B.A_k[jp] = temp;
          ix += 24;
          jp += 24;
        }
      }

      k = c - j;
      for (jA = c + 1; jA + 1 <= k + 24; jA++) {
        IPC4M_B.A_k[jA] /= IPC4M_B.A_k[c];
      }
    }

    jA = kBcol;
    jp = kBcol + 24;
    for (jBcol = 1; jBcol <= 23 - j; jBcol++) {
      if (IPC4M_B.A_k[jp] != 0.0) {
        temp = -IPC4M_B.A_k[jp];
        ix = c;
        k = jA - j;
        for (kBcol = jA + 25; kBcol + 1 <= k + 48; kBcol++) {
          IPC4M_B.A_k[kBcol] += IPC4M_B.A_k[ix + 1] * temp;
          ix++;
        }
      }

      jp += 24;
      jA += 24;
    }
  }

  memcpy(&y[0], &u0[0], 432U * sizeof(real_T));
  for (j = 0; j < 24; j++) {
    jBcol = 18 * j;
    jp = 24 * j;
    for (k = 0; k + 1 <= j; k++) {
      kBcol = 18 * k;
      if (IPC4M_B.A_k[k + jp] != 0.0) {
        for (jA = 0; jA < 18; jA++) {
          y[jA + jBcol] -= IPC4M_B.A_k[k + jp] * y[jA + kBcol];
        }
      }
    }

    temp = 1.0 / IPC4M_B.A_k[j + jp];
    for (jA = 0; jA < 18; jA++) {
      y[jA + jBcol] *= temp;
    }
  }

  for (j = 23; j >= 0; j += -1) {
    jBcol = 18 * j;
    jp = 24 * j;
    for (k = j + 1; k + 1 < 25; k++) {
      kBcol = 18 * k;
      if (IPC4M_B.A_k[k + jp] != 0.0) {
        for (jA = 0; jA < 18; jA++) {
          y[jA + jBcol] -= IPC4M_B.A_k[k + jp] * y[jA + kBcol];
        }
      }
    }
  }

  for (jBcol = 22; jBcol >= 0; jBcol += -1) {
    if (jBcol + 1 != ipiv[jBcol]) {
      jp = ipiv[jBcol] - 1;
      for (kBcol = 0; kBcol < 18; kBcol++) {
        temp = y[18 * jBcol + kBcol];
        y[kBcol + 18 * jBcol] = y[18 * jp + kBcol];
        y[kBcol + 18 * jp] = temp;
      }
    }
  }
}

void MWDSPCG_Pseudoinverse_D(const real_T pS[], const real_T pU[], const real_T
  pV[], real_T pX[], const int32_T M, const int32_T N)
{
  real_T tol;
  real_T cabsS;
  int32_T P;
  int32_T rank;
  int32_T ppXIdx;
  int32_T ppUIdx;
  int32_T ppVIdx;
  int32_T j;
  int32_T k;
  int32_T M_0;

  /* S-Function (sdsppinv): '<S9>/Pseudoinverse' */
  rank = 0;
  if (M <= N) {
    P = M;
  } else {
    P = N;
  }

  cabsS = fabs(pS[0]);
  if (0.0 < cabsS) {
    rank = 1;
    if (M >= N) {
      M_0 = M;
    } else {
      M_0 = N;
    }

    tol = (real_T)M_0 * pS[0U] * 2.2204460492503131E-16;
    M_0 = P;
    while (P > 0) {
      cabsS = fabs(pS[M_0 - 1]);
      M_0--;
      if (cabsS >= tol) {
        rank = P;
        P = 0;
      }

      P--;
    }
  }

  ppXIdx = 0;
  for (P = 0; P < N * M; P++) {
    pX[ppXIdx] = 0.0;
    ppXIdx++;
  }

  if (rank != 0) {
    ppXIdx = 0;
    for (j = 0; j < M; j++) {
      for (P = 0; P < N; P++) {
        ppVIdx = P;
        ppUIdx = j;
        M_0 = 0;
        for (k = 0; k < rank; k++) {
          cabsS = pV[ppVIdx] * pU[ppUIdx] / pS[M_0];
          pX[ppXIdx] += cabsS;
          M_0++;
          ppVIdx += N;
          ppUIdx += M;
        }

        ppXIdx++;
      }
    }
  }

  /* End of S-Function (sdsppinv): '<S9>/Pseudoinverse' */
}

/* Function for MATLAB Function: '<S2>/ConnectingStiffness' */
static real_T IPC4M_norm(const real_T x[3])
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  scale = 2.2250738585072014E-308;
  absxk = fabs(x[0]);
  if (absxk > 2.2250738585072014E-308) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 2.2250738585072014E-308;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

/* Function for MATLAB Function: '<S9>/Centripal Force' */
static void IPC4M_quatmultiply_n3(const real_T q[4], const real_T b_r[4], real_T
  qout[4])
{
  qout[0] = ((q[0] * b_r[0] - q[1] * b_r[1]) - q[2] * b_r[2]) - q[3] * b_r[3];
  qout[1] = (q[0] * b_r[1] + b_r[0] * q[1]) + (q[2] * b_r[3] - q[3] * b_r[2]);
  qout[2] = (q[0] * b_r[2] + b_r[0] * q[2]) + (q[3] * b_r[1] - q[1] * b_r[3]);
  qout[3] = (q[0] * b_r[3] + b_r[0] * q[3]) + (q[1] * b_r[2] - q[2] * b_r[1]);
}

static void rt_mldivide_U1d24x24_U_NAKP2m_n(const real_T u0[576], const real_T
  u1[24], real_T y[24])
{
  real_T y_0[24];
  real_T temp;
  int8_T ipiv[24];
  int32_T jm1;
  int32_T jj;
  int32_T j;
  int32_T c;
  int32_T ix;
  real_T s;
  int32_T k;
  int32_T kAcol;
  int32_T i;
  memcpy(&IPC4M_B.A_cx[0], &u0[0], 576U * sizeof(real_T));
  for (i = 0; i < 24; i++) {
    ipiv[i] = (int8_T)(1 + i);
  }

  for (j = 0; j < 23; j++) {
    c = j * 25;
    jj = j * 25;
    kAcol = 1;
    ix = c;
    temp = fabs(IPC4M_B.A_cx[jj]);
    for (k = 2; k <= 24 - j; k++) {
      ix++;
      s = fabs(IPC4M_B.A_cx[ix]);
      if (s > temp) {
        kAcol = k;
        temp = s;
      }
    }

    kAcol--;
    if (IPC4M_B.A_cx[c + kAcol] != 0.0) {
      if (kAcol != 0) {
        ipiv[j] = (int8_T)((j + kAcol) + 1);
        ix = j;
        kAcol += j;
        for (k = 0; k < 24; k++) {
          temp = IPC4M_B.A_cx[ix];
          IPC4M_B.A_cx[ix] = IPC4M_B.A_cx[kAcol];
          IPC4M_B.A_cx[kAcol] = temp;
          ix += 24;
          kAcol += 24;
        }
      }

      i = c - j;
      for (jm1 = c + 1; jm1 + 1 <= i + 24; jm1++) {
        IPC4M_B.A_cx[jm1] /= IPC4M_B.A_cx[c];
      }
    }

    kAcol = jj + 24;
    for (jm1 = 1; jm1 <= 23 - j; jm1++) {
      if (IPC4M_B.A_cx[kAcol] != 0.0) {
        temp = -IPC4M_B.A_cx[kAcol];
        ix = c;
        i = jj - j;
        for (k = jj + 25; k + 1 <= i + 48; k++) {
          IPC4M_B.A_cx[k] += IPC4M_B.A_cx[ix + 1] * temp;
          ix++;
        }
      }

      kAcol += 24;
      jj += 24;
    }
  }

  memcpy(&y_0[0], &u1[0], 24U * sizeof(real_T));
  for (kAcol = 0; kAcol < 23; kAcol++) {
    if (kAcol + 1 != ipiv[kAcol]) {
      temp = y_0[kAcol];
      y_0[kAcol] = y_0[ipiv[kAcol] - 1];
      y_0[ipiv[kAcol] - 1] = temp;
    }
  }

  for (k = 0; k < 24; k++) {
    kAcol = 24 * k;
    if (y_0[k] != 0.0) {
      for (jm1 = k + 1; jm1 + 1 < 25; jm1++) {
        y_0[jm1] -= IPC4M_B.A_cx[jm1 + kAcol] * y_0[k];
      }
    }
  }

  for (k = 23; k >= 0; k += -1) {
    kAcol = 24 * k;
    if (y_0[k] != 0.0) {
      y_0[k] /= IPC4M_B.A_cx[k + kAcol];
      for (jm1 = 0; jm1 + 1 <= k; jm1++) {
        y_0[jm1] -= IPC4M_B.A_cx[jm1 + kAcol] * y_0[k];
      }
    }
  }

  memcpy(&y[0], &y_0[0], 24U * sizeof(real_T));
}

/* Function for MATLAB Function: '<S9>/World to Object Frame' */
static void IPC4M_quatmultiply_lm(const real_T q[4], const real_T r[4], real_T
  qout[4])
{
  qout[0] = ((q[0] * r[0] - q[1] * r[1]) - q[2] * r[2]) - q[3] * r[3];
  qout[1] = (q[0] * r[1] + r[0] * q[1]) + (q[2] * r[3] - q[3] * r[2]);
  qout[2] = (q[0] * r[2] + r[0] * q[2]) + (q[3] * r[1] - q[1] * r[3]);
  qout[3] = (q[0] * r[3] + r[0] * q[3]) + (q[1] * r[2] - q[2] * r[1]);
}

/* Function for MATLAB Function: '<S11>/Reduced Constraint Matrix' */
static void IPC4M_quatmultiply_f(const real_T q[4], const real_T b_r[4], real_T
  qout[4])
{
  qout[0] = ((q[0] * b_r[0] - q[1] * b_r[1]) - q[2] * b_r[2]) - q[3] * b_r[3];
  qout[1] = (q[0] * b_r[1] + b_r[0] * q[1]) + (q[2] * b_r[3] - q[3] * b_r[2]);
  qout[2] = (q[0] * b_r[2] + b_r[0] * q[2]) + (q[3] * b_r[1] - q[1] * b_r[3]);
  qout[3] = (q[0] * b_r[3] + b_r[0] * q[3]) + (q[1] * b_r[2] - q[2] * b_r[1]);
}

/* Function for MATLAB Function: '<Root>/Object to World Frame' */
static void IPC4M_quatmultiply_g(const real_T q[4], const real_T r[4], real_T
  qout[4])
{
  qout[0] = ((q[0] * r[0] - q[1] * r[1]) - q[2] * r[2]) - q[3] * r[3];
  qout[1] = (q[0] * r[1] + r[0] * q[1]) + (q[2] * r[3] - q[3] * r[2]);
  qout[2] = (q[0] * r[2] + r[0] * q[2]) + (q[3] * r[1] - q[1] * r[3]);
  qout[3] = (q[0] * r[3] + r[0] * q[3]) + (q[1] * r[2] - q[2] * r[1]);
}

/* Function for MATLAB Function: '<S1>/MATLAB Function' */
static void IPC4M_quatmultiply_b(const real_T q[4], const real_T b_r[4], real_T
  qout[4])
{
  qout[0] = ((q[0] * b_r[0] - q[1] * b_r[1]) - q[2] * b_r[2]) - q[3] * b_r[3];
  qout[1] = (q[0] * b_r[1] + b_r[0] * q[1]) + (q[2] * b_r[3] - q[3] * b_r[2]);
  qout[2] = (q[0] * b_r[2] + b_r[0] * q[2]) + (q[3] * b_r[1] - q[1] * b_r[3]);
  qout[3] = (q[0] * b_r[3] + b_r[0] * q[3]) + (q[1] * b_r[2] - q[2] * b_r[1]);
}

/* Function for MATLAB Function: '<S1>/MATLAB Function1' */
static void IPC4M_quatmultiply_n(const real_T q[4], const real_T b_r[4], real_T
  qout[4])
{
  qout[0] = ((q[0] * b_r[0] - q[1] * b_r[1]) - q[2] * b_r[2]) - q[3] * b_r[3];
  qout[1] = (q[0] * b_r[1] + b_r[0] * q[1]) + (q[2] * b_r[3] - q[3] * b_r[2]);
  qout[2] = (q[0] * b_r[2] + b_r[0] * q[2]) + (q[3] * b_r[1] - q[1] * b_r[3]);
  qout[3] = (q[0] * b_r[3] + b_r[0] * q[3]) + (q[1] * b_r[2] - q[2] * b_r[1]);
}

static void rt_mldivide_U1d24x24_U_2VUCyo_n(const real_T u0[576], const real_T
  u1[432], real_T y[432])
{
  real_T temp;
  int8_T ipiv[24];
  int32_T jpiv_offset;
  int32_T j;
  int32_T c;
  int32_T ix;
  real_T s;
  int32_T jA;
  int32_T jBcol;
  int32_T kAcol;
  int32_T i;
  memcpy(&IPC4M_B.A_b[0], &u0[0], 576U * sizeof(real_T));
  for (i = 0; i < 24; i++) {
    ipiv[i] = (int8_T)(1 + i);
  }

  for (j = 0; j < 23; j++) {
    c = j * 25;
    kAcol = j * 25;
    jBcol = 1;
    ix = c;
    temp = fabs(IPC4M_B.A_b[kAcol]);
    for (jA = 2; jA <= 24 - j; jA++) {
      ix++;
      s = fabs(IPC4M_B.A_b[ix]);
      if (s > temp) {
        jBcol = jA;
        temp = s;
      }
    }

    jpiv_offset = jBcol - 1;
    if (IPC4M_B.A_b[c + jpiv_offset] != 0.0) {
      if (jpiv_offset != 0) {
        ipiv[j] = (int8_T)((j + jpiv_offset) + 1);
        ix = j;
        jBcol = j + jpiv_offset;
        for (jA = 0; jA < 24; jA++) {
          temp = IPC4M_B.A_b[ix];
          IPC4M_B.A_b[ix] = IPC4M_B.A_b[jBcol];
          IPC4M_B.A_b[jBcol] = temp;
          ix += 24;
          jBcol += 24;
        }
      }

      i = c - j;
      for (jpiv_offset = c + 1; jpiv_offset + 1 <= i + 24; jpiv_offset++) {
        IPC4M_B.A_b[jpiv_offset] /= IPC4M_B.A_b[c];
      }
    }

    jA = kAcol;
    jBcol = kAcol + 24;
    for (kAcol = 1; kAcol <= 23 - j; kAcol++) {
      if (IPC4M_B.A_b[jBcol] != 0.0) {
        temp = -IPC4M_B.A_b[jBcol];
        ix = c;
        i = jA - j;
        for (jpiv_offset = jA + 25; jpiv_offset + 1 <= i + 48; jpiv_offset++) {
          IPC4M_B.A_b[jpiv_offset] += IPC4M_B.A_b[ix + 1] * temp;
          ix++;
        }
      }

      jBcol += 24;
      jA += 24;
    }
  }

  memcpy(&y[0], &u1[0], 432U * sizeof(real_T));
  for (jBcol = 0; jBcol < 23; jBcol++) {
    if (jBcol + 1 != ipiv[jBcol]) {
      kAcol = ipiv[jBcol] - 1;
      for (jpiv_offset = 0; jpiv_offset < 18; jpiv_offset++) {
        temp = y[24 * jpiv_offset + jBcol];
        y[jBcol + 24 * jpiv_offset] = y[24 * jpiv_offset + kAcol];
        y[kAcol + 24 * jpiv_offset] = temp;
      }
    }
  }

  for (j = 0; j < 18; j++) {
    jBcol = 24 * j;
    for (jA = 0; jA < 24; jA++) {
      kAcol = 24 * jA;
      if (y[jA + jBcol] != 0.0) {
        for (jpiv_offset = jA + 1; jpiv_offset + 1 < 25; jpiv_offset++) {
          y[jpiv_offset + jBcol] -= y[jA + jBcol] * IPC4M_B.A_b[jpiv_offset +
            kAcol];
        }
      }
    }
  }

  for (j = 0; j < 18; j++) {
    jBcol = 24 * j;
    for (jA = 23; jA >= 0; jA += -1) {
      kAcol = 24 * jA;
      if (y[jA + jBcol] != 0.0) {
        y[jA + jBcol] /= IPC4M_B.A_b[jA + kAcol];
        for (jpiv_offset = 0; jpiv_offset + 1 <= jA; jpiv_offset++) {
          y[jpiv_offset + jBcol] -= y[jA + jBcol] * IPC4M_B.A_b[jpiv_offset +
            kAcol];
        }
      }
    }
  }
}

void rt_mldivide_U1d18x18_U_2jkRkZaZ(const real_T u0[324], const real_T u1[18],
  real_T y[18])
{
  real_T y_0[18];
  real_T temp;
  real_T A[324];
  int8_T ipiv[18];
  int32_T jm1;
  int32_T jj;
  int32_T j;
  int32_T c;
  int32_T ix;
  real_T s;
  int32_T k;
  int32_T kAcol;
  int32_T i;
  memcpy(&A[0], &u0[0], 324U * sizeof(real_T));
  for (i = 0; i < 18; i++) {
    ipiv[i] = (int8_T)(1 + i);
  }

  for (j = 0; j < 17; j++) {
    c = j * 19;
    jj = j * 19;
    kAcol = 1;
    ix = c;
    temp = fabs(A[jj]);
    for (k = 2; k <= 18 - j; k++) {
      ix++;
      s = fabs(A[ix]);
      if (s > temp) {
        kAcol = k;
        temp = s;
      }
    }

    kAcol--;
    if (A[c + kAcol] != 0.0) {
      if (kAcol != 0) {
        ipiv[j] = (int8_T)((j + kAcol) + 1);
        ix = j;
        kAcol += j;
        for (k = 0; k < 18; k++) {
          temp = A[ix];
          A[ix] = A[kAcol];
          A[kAcol] = temp;
          ix += 18;
          kAcol += 18;
        }
      }

      i = c - j;
      for (jm1 = c + 1; jm1 + 1 <= i + 18; jm1++) {
        A[jm1] /= A[c];
      }
    }

    kAcol = jj + 18;
    for (jm1 = 1; jm1 <= 17 - j; jm1++) {
      if (A[kAcol] != 0.0) {
        temp = -A[kAcol];
        ix = c;
        i = jj - j;
        for (k = jj + 19; k + 1 <= i + 36; k++) {
          A[k] += A[ix + 1] * temp;
          ix++;
        }
      }

      kAcol += 18;
      jj += 18;
    }
  }

  memcpy(&y_0[0], &u1[0], 18U * sizeof(real_T));
  for (kAcol = 0; kAcol < 17; kAcol++) {
    if (kAcol + 1 != ipiv[kAcol]) {
      temp = y_0[kAcol];
      y_0[kAcol] = y_0[ipiv[kAcol] - 1];
      y_0[ipiv[kAcol] - 1] = temp;
    }
  }

  for (k = 0; k < 18; k++) {
    kAcol = 18 * k;
    if (y_0[k] != 0.0) {
      for (jm1 = k + 1; jm1 + 1 < 19; jm1++) {
        y_0[jm1] -= A[jm1 + kAcol] * y_0[k];
      }
    }
  }

  for (k = 17; k >= 0; k += -1) {
    kAcol = 18 * k;
    if (y_0[k] != 0.0) {
      y_0[k] /= A[k + kAcol];
      for (jm1 = 0; jm1 + 1 <= k; jm1++) {
        y_0[jm1] -= A[jm1 + kAcol] * y_0[k];
      }
    }
  }

  memcpy(&y[0], &y_0[0], 18U * sizeof(real_T));
}

/* Function for MATLAB Function: '<S5>/MATLAB Function' */
static void IPC4M_quatmultiply_e(const real_T q[4], const real_T b_r[4], real_T
  qout[4])
{
  qout[0] = ((q[0] * b_r[0] - q[1] * b_r[1]) - q[2] * b_r[2]) - q[3] * b_r[3];
  qout[1] = (q[0] * b_r[1] + b_r[0] * q[1]) + (q[2] * b_r[3] - q[3] * b_r[2]);
  qout[2] = (q[0] * b_r[2] + b_r[0] * q[2]) + (q[3] * b_r[1] - q[1] * b_r[3]);
  qout[3] = (q[0] * b_r[3] + b_r[0] * q[3]) + (q[1] * b_r[2] - q[2] * b_r[1]);
}

/* Function for MATLAB Function: '<S5>/Centripetal Force' */
static void IPC4M_quatmultiply_p(const real_T q[4], const real_T b_r[4], real_T
  qout[4])
{
  qout[0] = ((q[0] * b_r[0] - q[1] * b_r[1]) - q[2] * b_r[2]) - q[3] * b_r[3];
  qout[1] = (q[0] * b_r[1] + b_r[0] * q[1]) + (q[2] * b_r[3] - q[3] * b_r[2]);
  qout[2] = (q[0] * b_r[2] + b_r[0] * q[2]) + (q[3] * b_r[1] - q[1] * b_r[3]);
  qout[3] = (q[0] * b_r[3] + b_r[0] * q[3]) + (q[1] * b_r[2] - q[2] * b_r[1]);
}

static void rt_mldivide_U1d30x30_U_kRq1hM_n(const real_T u0[900], const real_T
  u1[30], real_T y[30])
{
  real_T y_0[30];
  real_T temp;
  int8_T ipiv[30];
  int32_T jm1;
  int32_T jj;
  int32_T j;
  int32_T c;
  int32_T ix;
  real_T s;
  int32_T k;
  int32_T kAcol;
  int32_T i;
  memcpy(&IPC4M_B.A[0], &u0[0], 900U * sizeof(real_T));
  for (i = 0; i < 30; i++) {
    ipiv[i] = (int8_T)(1 + i);
  }

  for (j = 0; j < 29; j++) {
    c = j * 31;
    jj = j * 31;
    kAcol = 1;
    ix = c;
    temp = fabs(IPC4M_B.A[jj]);
    for (k = 2; k <= 30 - j; k++) {
      ix++;
      s = fabs(IPC4M_B.A[ix]);
      if (s > temp) {
        kAcol = k;
        temp = s;
      }
    }

    kAcol--;
    if (IPC4M_B.A[c + kAcol] != 0.0) {
      if (kAcol != 0) {
        ipiv[j] = (int8_T)((j + kAcol) + 1);
        ix = j;
        kAcol += j;
        for (k = 0; k < 30; k++) {
          temp = IPC4M_B.A[ix];
          IPC4M_B.A[ix] = IPC4M_B.A[kAcol];
          IPC4M_B.A[kAcol] = temp;
          ix += 30;
          kAcol += 30;
        }
      }

      i = c - j;
      for (jm1 = c + 1; jm1 + 1 <= i + 30; jm1++) {
        IPC4M_B.A[jm1] /= IPC4M_B.A[c];
      }
    }

    kAcol = jj + 30;
    for (jm1 = 1; jm1 <= 29 - j; jm1++) {
      if (IPC4M_B.A[kAcol] != 0.0) {
        temp = -IPC4M_B.A[kAcol];
        ix = c;
        i = jj - j;
        for (k = jj + 31; k + 1 <= i + 60; k++) {
          IPC4M_B.A[k] += IPC4M_B.A[ix + 1] * temp;
          ix++;
        }
      }

      kAcol += 30;
      jj += 30;
    }
  }

  memcpy(&y_0[0], &u1[0], 30U * sizeof(real_T));
  for (kAcol = 0; kAcol < 29; kAcol++) {
    if (kAcol + 1 != ipiv[kAcol]) {
      temp = y_0[kAcol];
      y_0[kAcol] = y_0[ipiv[kAcol] - 1];
      y_0[ipiv[kAcol] - 1] = temp;
    }
  }

  for (k = 0; k < 30; k++) {
    kAcol = 30 * k;
    if (y_0[k] != 0.0) {
      for (jm1 = k + 1; jm1 + 1 < 31; jm1++) {
        y_0[jm1] -= IPC4M_B.A[jm1 + kAcol] * y_0[k];
      }
    }
  }

  for (k = 29; k >= 0; k += -1) {
    kAcol = 30 * k;
    if (y_0[k] != 0.0) {
      y_0[k] /= IPC4M_B.A[k + kAcol];
      for (jm1 = 0; jm1 + 1 <= k; jm1++) {
        y_0[jm1] -= IPC4M_B.A[jm1 + kAcol] * y_0[k];
      }
    }
  }

  memcpy(&y[0], &y_0[0], 30U * sizeof(real_T));
}

static void rt_mrdivide_U1d24x30_U_zeNn4d_n(const real_T u0[720], const real_T
  u1[900], real_T y[720])
{
  int32_T jp;
  real_T temp;
  int8_T ipiv[30];
  int32_T j;
  int32_T c;
  int32_T ix;
  real_T s;
  int32_T jA;
  int32_T jBcol;
  int32_T kBcol;
  int32_T k;
  memcpy(&IPC4M_B.A_m[0], &u1[0], 900U * sizeof(real_T));
  for (j = 0; j < 30; j++) {
    ipiv[j] = (int8_T)(1 + j);
  }

  for (j = 0; j < 29; j++) {
    c = j * 31;
    kBcol = j * 31;
    jp = 1;
    ix = c;
    temp = fabs(IPC4M_B.A_m[kBcol]);
    for (k = 2; k <= 30 - j; k++) {
      ix++;
      s = fabs(IPC4M_B.A_m[ix]);
      if (s > temp) {
        jp = k;
        temp = s;
      }
    }

    jp--;
    if (IPC4M_B.A_m[c + jp] != 0.0) {
      if (jp != 0) {
        ipiv[j] = (int8_T)((j + jp) + 1);
        ix = j;
        jp += j;
        for (k = 0; k < 30; k++) {
          temp = IPC4M_B.A_m[ix];
          IPC4M_B.A_m[ix] = IPC4M_B.A_m[jp];
          IPC4M_B.A_m[jp] = temp;
          ix += 30;
          jp += 30;
        }
      }

      k = c - j;
      for (jA = c + 1; jA + 1 <= k + 30; jA++) {
        IPC4M_B.A_m[jA] /= IPC4M_B.A_m[c];
      }
    }

    jA = kBcol;
    jp = kBcol + 30;
    for (jBcol = 1; jBcol <= 29 - j; jBcol++) {
      if (IPC4M_B.A_m[jp] != 0.0) {
        temp = -IPC4M_B.A_m[jp];
        ix = c;
        k = jA - j;
        for (kBcol = jA + 31; kBcol + 1 <= k + 60; kBcol++) {
          IPC4M_B.A_m[kBcol] += IPC4M_B.A_m[ix + 1] * temp;
          ix++;
        }
      }

      jp += 30;
      jA += 30;
    }
  }

  memcpy(&y[0], &u0[0], 720U * sizeof(real_T));
  for (j = 0; j < 30; j++) {
    jBcol = 24 * j;
    jp = 30 * j;
    for (k = 0; k + 1 <= j; k++) {
      kBcol = 24 * k;
      if (IPC4M_B.A_m[k + jp] != 0.0) {
        for (jA = 0; jA < 24; jA++) {
          y[jA + jBcol] -= IPC4M_B.A_m[k + jp] * y[jA + kBcol];
        }
      }
    }

    temp = 1.0 / IPC4M_B.A_m[j + jp];
    for (jA = 0; jA < 24; jA++) {
      y[jA + jBcol] *= temp;
    }
  }

  for (j = 29; j >= 0; j += -1) {
    jBcol = 24 * j;
    jp = 30 * j;
    for (k = j + 1; k + 1 < 31; k++) {
      kBcol = 24 * k;
      if (IPC4M_B.A_m[k + jp] != 0.0) {
        for (jA = 0; jA < 24; jA++) {
          y[jA + jBcol] -= IPC4M_B.A_m[k + jp] * y[jA + kBcol];
        }
      }
    }
  }

  for (jBcol = 28; jBcol >= 0; jBcol += -1) {
    if (jBcol + 1 != ipiv[jBcol]) {
      jp = ipiv[jBcol] - 1;
      for (kBcol = 0; kBcol < 24; kBcol++) {
        temp = y[24 * jBcol + kBcol];
        y[kBcol + 24 * jBcol] = y[24 * jp + kBcol];
        y[kBcol + 24 * jp] = temp;
      }
    }
  }
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Model step function */
void IPC4M_step(void)
{
  /* local block i/o variables */
  real_T rtb_Divide[24];
  real_T rtb_Transpose[432];
  real_T rtb_DesiredInternalForces1[18];
  if (rtmIsMajorTimeStep(IPC4M_M)) {
    /* set solver stop time */
    if (!(IPC4M_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&IPC4M_M->solverInfo, ((IPC4M_M->Timing.clockTickH0
        + 1) * IPC4M_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&IPC4M_M->solverInfo, ((IPC4M_M->Timing.clockTick0 +
        1) * IPC4M_M->Timing.stepSize0 + IPC4M_M->Timing.clockTickH0 *
        IPC4M_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(IPC4M_M)) {
    IPC4M_M->Timing.t[0] = rtsiGetT(&IPC4M_M->solverInfo);
  }

  {
    real_T (*lastU)[6];
    real_T q[4];
    real_T b_q[4];
    real_T c_q[4];
    real_T d_q[4];
    real_T x_o[3];
    int8_T I[9];
    int8_T b_I[9];
    int8_T c_I[9];
    int8_T d_I[9];
    int8_T e_I[9];
    int8_T f_I[9];
    int8_T g_I[9];
    int8_T h_I[9];
    static const int8_T a[84] = { 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
      0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    static const int8_T a_0[84] = { 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
      0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    real_T a_1;
    static const int8_T b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

    static const int8_T a_2[84] = { 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
      0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    static const int8_T b_0[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

    static const int8_T b_1[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

    static const int8_T b_2[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

    int8_T i_I[9];
    int8_T j_I[9];
    int8_T k_I[9];
    int8_T l_I[9];
    real_T deltav[12];
    real_T f_con[12];
    static const real_T a_3[144] = { 0.75, 0.0, 0.0, -0.25, -0.0, -0.0, -0.25,
      -0.0, -0.0, -0.25, -0.0, -0.0, 0.0, 0.75, 0.0, -0.0, -0.25, -0.0, -0.0,
      -0.25, -0.0, -0.0, -0.25, -0.0, 0.0, 0.0, 0.75, -0.0, -0.0, -0.25, -0.0,
      -0.0, -0.25, -0.0, -0.0, -0.25, -0.25, -0.0, -0.0, 0.75, 0.0, 0.0, -0.25,
      -0.0, -0.0, -0.25, -0.0, -0.0, -0.0, -0.25, -0.0, 0.0, 0.75, 0.0, -0.0,
      -0.25, -0.0, -0.0, -0.25, -0.0, -0.0, -0.0, -0.25, 0.0, 0.0, 0.75, -0.0,
      -0.0, -0.25, -0.0, -0.0, -0.25, -0.25, -0.0, -0.0, -0.25, -0.0, -0.0, 0.75,
      0.0, 0.0, -0.25, -0.0, -0.0, -0.0, -0.25, -0.0, -0.0, -0.25, -0.0, 0.0,
      0.75, 0.0, -0.0, -0.25, -0.0, -0.0, -0.0, -0.25, -0.0, -0.0, -0.25, 0.0,
      0.0, 0.75, -0.0, -0.0, -0.25, -0.25, -0.0, -0.0, -0.25, -0.0, -0.0, -0.25,
      -0.0, -0.0, 0.75, 0.0, 0.0, -0.0, -0.25, -0.0, -0.0, -0.25, -0.0, -0.0,
      -0.25, -0.0, 0.0, 0.75, 0.0, -0.0, -0.0, -0.25, -0.0, -0.0, -0.25, -0.0,
      -0.0, -0.25, 0.0, 0.0, 0.75 };

    static const int8_T b_a[36] = { 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0,
      0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1 };

    static const int8_T c_a[72] = { 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
      1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0,
      0, 0, 0, 0, 0, 0, 0 };

    static const real_T a_4[144] = { 0.75, 0.0, 0.0, -0.25, -0.0, -0.0, -0.25,
      -0.0, -0.0, -0.25, -0.0, -0.0, 0.0, 0.75, 0.0, -0.0, -0.25, -0.0, -0.0,
      -0.25, -0.0, -0.0, -0.25, -0.0, 0.0, 0.0, 0.75, -0.0, -0.0, -0.25, -0.0,
      -0.0, -0.25, -0.0, -0.0, -0.25, -0.25, -0.0, -0.0, 0.75, 0.0, 0.0, -0.25,
      -0.0, -0.0, -0.25, -0.0, -0.0, -0.0, -0.25, -0.0, 0.0, 0.75, 0.0, -0.0,
      -0.25, -0.0, -0.0, -0.25, -0.0, -0.0, -0.0, -0.25, 0.0, 0.0, 0.75, -0.0,
      -0.0, -0.25, -0.0, -0.0, -0.25, -0.25, -0.0, -0.0, -0.25, -0.0, -0.0, 0.75,
      0.0, 0.0, -0.25, -0.0, -0.0, -0.0, -0.25, -0.0, -0.0, -0.25, -0.0, 0.0,
      0.75, 0.0, -0.0, -0.25, -0.0, -0.0, -0.0, -0.25, -0.0, -0.0, -0.25, 0.0,
      0.0, 0.75, -0.0, -0.0, -0.25, -0.25, -0.0, -0.0, -0.25, -0.0, -0.0, -0.25,
      -0.0, -0.0, 0.75, 0.0, 0.0, -0.0, -0.25, -0.0, -0.0, -0.25, -0.0, -0.0,
      -0.25, -0.0, 0.0, 0.75, 0.0, -0.0, -0.0, -0.25, -0.0, -0.0, -0.25, -0.0,
      -0.0, -0.25, 0.0, 0.0, 0.75 };

    static const int8_T b_a_0[36] = { 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1,
      0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1 };

    static const int8_T c_a_0[84] = { 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    real_T e_q[4];
    real_T f_q[4];
    real_T g_q[4];
    real_T h_q[4];
    int8_T m_I[9];
    int8_T n_I[9];
    int8_T o_I[9];
    int8_T p_I[9];
    real_T rtb_Product4;
    real_T rtb_Sum_m;
    real_T rtb_Sum_a5;
    real_T rtb_Sum_k;
    real_T rtb_Sum_iy;
    real_T rtb_Sum_g;
    real_T rtb_Sum_bl;
    real_T rtb_Product2_fj;
    real_T rtb_Product3_eb;
    real_T rtb_Sum_e;
    real_T rtb_Derivative[6];
    real_T rtb_Add[24];
    real_T rtb_Mult[24];
    real_T rtb_TmpSignalConversionAtM3Inpo[30];
    real_T rtb_TmpSignalConversionAtSFunct[4];
    real_T rtb_TmpSignalConversionAtSFun_e[6];
    real_T Pseudoinverse_X[432];
    real_T Pseudoinverse_U[324];
    real_T Pseudoinverse_WORK[18];
    real_T Pseudoinverse_E[24];
    real_T Pseudoinverse_S[19];
    real_T Pseudoinverse_WORK_l[24];
    real_T Pseudoinverse_E_d[30];
    real_T Pseudoinverse_S_d[25];
    real_T Pseudoinverse_X_h[144];
    real_T Pseudoinverse_U_a[36];
    real_T Pseudoinverse_WORK_lf[6];
    real_T Pseudoinverse_E_k[24];
    real_T Pseudoinverse_S_h[7];
    real_T rtb_Transpose_f[144];
    real_T rtb_Ared_b[432];
    real_T rtb_MathFunction[432];
    real_T rtb_Pseudoinverse[432];
    real_T rtb_Pseudoinverse_j[144];
    real_T rtb_K_i[36];
    int32_T i;
    real_T tmp[30];
    real_T tmp_0[4];
    real_T tmp_1[4];
    real_T tmp_2[4];
    real_T tmp_3[4];
    real_T tmp_4[30];
    real_T tmp_5[4];
    real_T tmp_6[4];
    real_T tmp_7[4];
    real_T tmp_8[4];
    real_T tmp_9[4];
    real_T tmp_a[4];
    real_T rtb_Pseudoinverse_1[324];
    real_T tmp_b[4];
    real_T tmp_c[4];
    real_T tmp_d[4];
    real_T tmp_e[4];
    real_T tmp_f[4];
    real_T tmp_g[4];
    real_T tmp_h[4];
    real_T tmp_i[4];
    real_T tmp_j[4];
    real_T tmp_k[4];
    real_T tmp_l[4];
    real_T tmp_m[4];
    real_T tmp_n[4];
    real_T tmp_o[4];
    real_T tmp_p[4];
    real_T tmp_q[4];
    real_T tmp_r[4];
    real_T tmp_s[4];
    real_T tmp_t[4];
    real_T tmp_u[4];
    real_T tmp_v[4];
    real_T tmp_w[4];
    real_T tmp_x[4];
    real_T tmp_y[4];
    real_T tmp_z[4];
    real_T tmp_10[4];
    real_T tmp_11[4];
    real_T tmp_12[4];
    real_T tmp_13[4];
    real_T tmp_14[4];
    real_T tmp_15[4];
    real_T tmp_16[4];
    real_T tmp_17[4];
    real_T tmp_18[4];
    real_T tmp_19[4];
    real_T tmp_1a[4];
    real_T tmp_1b[4];
    real_T tmp_1c[6];
    real_T tmp_1d[6];
    real_T tmp_1e[9];
    real_T tmp_1f[9];
    real_T tmp_1g[9];
    real_T tmp_1h[9];
    real_T tmp_1i[9];
    real_T tmp_1j[9];
    real_T tmp_1k[9];
    real_T tmp_1l[9];
    real_T tmp_1m[9];
    real_T tmp_1n[3];
    real_T tmp_1o[3];
    real_T tmp_1p[3];
    real_T tmp_1q[24];
    real_T rtb_Transpose_a[24];
    real_T tmp_1r[6];
    real_T rtb_K_h[6];
    real_T tmp_1s[6];
    real_T tmp_1t[6];
    real_T c_a_1[3];
    real_T tmp_1u[12];
    real_T deltav_0[12];
    real_T tmp_1v[12];
    real_T rtb_Product4_0[12];
    real_T tmp_1w[9];
    real_T tmp_1x[9];
    real_T tmp_1y[9];
    real_T tmp_1z[9];
    real_T tmp_20[9];
    real_T tmp_21[9];
    real_T rtb_Ared_f[18];
    real_T tmp_22[18];
    real_T tmp_23[18];
    real_T I_0[432];
    real_T tmp_24[18];
    int32_T i_0;
    real_T tmp_25[9];
    real_T tmp_26[9];
    real_T tmp_27[9];
    real_T tmp_28[9];
    real_T tmp_29[9];
    real_T tmp_2a[9];
    real_T tmp_2b[18];
    real_T tmp_2c[9];
    real_T tmp_2d[9];
    real_T tmp_2e[6];
    real_T tmp_2f[9];
    real_T tmp_2g[9];
    real_T tmp_2h[9];
    real_T tmp_2i[9];
    real_T tmp_2j[9];
    real_T tmp_2k[9];
    real_T tmp_2l[9];
    real_T tmp_2m[9];
    real_T tmp_2n[24];
    real_T rtb_Pseudoinverse_o_0[30];
    real_T tmp_2o[9];
    real_T tmp_2p[9];
    int32_T i_1;

    /* Integrator: '<S10>/Integrator1' */
    IPC4M_B.Integrator1[0] = IPC4M_X.Integrator1_CSTATE[0];
    IPC4M_B.Integrator1[1] = IPC4M_X.Integrator1_CSTATE[1];
    IPC4M_B.Integrator1[2] = IPC4M_X.Integrator1_CSTATE[2];

    /* Integrator: '<S80>/Integrator' */
    IPC4M_B.Integrator[0] = IPC4M_X.Integrator_CSTATE[0];
    IPC4M_B.Integrator[1] = IPC4M_X.Integrator_CSTATE[1];
    IPC4M_B.Integrator[2] = IPC4M_X.Integrator_CSTATE[2];
    IPC4M_B.Integrator[3] = IPC4M_X.Integrator_CSTATE[3];

    /* MATLAB Function: '<S10>/Manipualtor pose in world frame' */
    /* MATLAB Function 'Manipulator motion/Manipualtor pose in world frame': '<S82>:1' */
    /* '<S82>:1:3' */
    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    q[0] = IPC4M_B.Integrator[0];
    q[1] = -IPC4M_B.Integrator[1];
    q[2] = -IPC4M_B.Integrator[2];
    q[3] = -IPC4M_B.Integrator[3];

    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    b_q[0] = IPC4M_B.Integrator[0];
    b_q[1] = -IPC4M_B.Integrator[1];
    b_q[2] = -IPC4M_B.Integrator[2];
    b_q[3] = -IPC4M_B.Integrator[3];

    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    c_q[0] = IPC4M_B.Integrator[0];
    c_q[1] = -IPC4M_B.Integrator[1];
    c_q[2] = -IPC4M_B.Integrator[2];
    c_q[3] = -IPC4M_B.Integrator[3];

    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    d_q[0] = IPC4M_B.Integrator[0];
    d_q[1] = -IPC4M_B.Integrator[1];
    d_q[2] = -IPC4M_B.Integrator[2];
    d_q[3] = -IPC4M_B.Integrator[3];
    tmp_17[0] = 0.0;
    tmp_17[1] = IPC4M_P.r[0];
    tmp_17[2] = IPC4M_P.r[1];
    tmp_17[3] = IPC4M_P.r[2];
    IPC4M_quatmultiply_k(tmp_17, q, tmp_18);
    IPC4M_quatmultiply_k(IPC4M_B.Integrator, tmp_18, tmp_17);
    tmp_19[0] = 0.0;
    tmp_19[1] = IPC4M_P.r[3];
    tmp_19[2] = IPC4M_P.r[4];
    tmp_19[3] = IPC4M_P.r[5];
    IPC4M_quatmultiply_k(tmp_19, b_q, tmp_18);
    IPC4M_quatmultiply_k(IPC4M_B.Integrator, tmp_18, tmp_19);
    tmp_1a[0] = 0.0;
    tmp_1a[1] = IPC4M_P.r[6];
    tmp_1a[2] = IPC4M_P.r[7];
    tmp_1a[3] = IPC4M_P.r[8];
    IPC4M_quatmultiply_k(tmp_1a, c_q, tmp_18);
    IPC4M_quatmultiply_k(IPC4M_B.Integrator, tmp_18, tmp_1a);
    tmp_1b[0] = 0.0;
    tmp_1b[1] = IPC4M_P.r[9];
    tmp_1b[2] = IPC4M_P.r[10];
    tmp_1b[3] = IPC4M_P.r[11];
    IPC4M_quatmultiply_k(tmp_1b, d_q, tmp_18);
    IPC4M_quatmultiply_k(IPC4M_B.Integrator, tmp_18, tmp_1b);
    IPC4M_B.x[0] = IPC4M_B.Integrator1[0] + tmp_17[1];
    IPC4M_B.x[1] = IPC4M_B.Integrator1[1] + tmp_17[2];
    IPC4M_B.x[2] = IPC4M_B.Integrator1[2] + tmp_17[3];
    IPC4M_B.x[3] = IPC4M_B.Integrator[0];
    IPC4M_B.x[4] = IPC4M_B.Integrator[1];
    IPC4M_B.x[5] = IPC4M_B.Integrator[2];
    IPC4M_B.x[6] = IPC4M_B.Integrator[3];
    IPC4M_B.x[7] = IPC4M_B.Integrator1[0] + tmp_19[1];
    IPC4M_B.x[8] = IPC4M_B.Integrator1[1] + tmp_19[2];
    IPC4M_B.x[9] = IPC4M_B.Integrator1[2] + tmp_19[3];
    IPC4M_B.x[10] = IPC4M_B.Integrator[0];
    IPC4M_B.x[11] = IPC4M_B.Integrator[1];
    IPC4M_B.x[12] = IPC4M_B.Integrator[2];
    IPC4M_B.x[13] = IPC4M_B.Integrator[3];
    IPC4M_B.x[14] = IPC4M_B.Integrator1[0] + tmp_1a[1];
    IPC4M_B.x[15] = IPC4M_B.Integrator1[1] + tmp_1a[2];
    IPC4M_B.x[16] = IPC4M_B.Integrator1[2] + tmp_1a[3];
    IPC4M_B.x[17] = IPC4M_B.Integrator[0];
    IPC4M_B.x[18] = IPC4M_B.Integrator[1];
    IPC4M_B.x[19] = IPC4M_B.Integrator[2];
    IPC4M_B.x[20] = IPC4M_B.Integrator[3];
    IPC4M_B.x[21] = IPC4M_B.Integrator1[0] + tmp_1b[1];
    IPC4M_B.x[22] = IPC4M_B.Integrator1[1] + tmp_1b[2];
    IPC4M_B.x[23] = IPC4M_B.Integrator1[2] + tmp_1b[3];
    IPC4M_B.x[24] = IPC4M_B.Integrator[0];
    IPC4M_B.x[25] = IPC4M_B.Integrator[1];
    IPC4M_B.x[26] = IPC4M_B.Integrator[2];
    IPC4M_B.x[27] = IPC4M_B.Integrator[3];

    /* MATLAB Function: '<S10>/Grasp Matrix' */
    IPC4M_MATLABFunction3(IPC4M_B.x, &IPC4M_B.sf_GraspMatrix);

    /* Integrator: '<S10>/Integrator' */
    for (i = 0; i < 6; i++) {
      IPC4M_B.Integrator_f[i] = IPC4M_X.Integrator_CSTATE_f[i];
    }

    /* End of Integrator: '<S10>/Integrator' */

    /* Product: '<S10>/G' dx_o' incorporates:
     *  Math: '<S10>/Transpose'
     */
    for (i = 0; i < 24; i++) {
      IPC4M_B.Gdx_o[i] = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        IPC4M_B.Gdx_o[i] += IPC4M_B.sf_GraspMatrix.G[6 * i + i_1] *
          IPC4M_B.Integrator_f[i_1];
      }
    }

    /* End of Product: '<S10>/G' dx_o' */
    if (rtmIsMajorTimeStep(IPC4M_M)) {
    }

    /* MATLAB Function: '<S7>/Grasp Matrix' */
    /* MATLAB Function 'Kinematic Coordination/Grasp Matrix': '<S75>:1' */
    /* '<S75>:1:2' */
    for (i = 0; i < 3; i++) {
      x_o[i] = 0.0;
      for (i_1 = 0; i_1 < 28; i_1++) {
        x_o[i] += (real_T)a[3 * i_1 + i] * IPC4M_B.x[i_1];
      }
    }

    /* '<S75>:1:3' */
    for (i = 0; i < 9; i++) {
      I[i] = 0;
      b_I[i] = 0;
      c_I[i] = 0;
      d_I[i] = 0;
      e_I[i] = 0;
      f_I[i] = 0;
      g_I[i] = 0;
      h_I[i] = 0;
    }

    I[0] = 1;
    I[4] = 1;
    I[8] = 1;
    b_I[0] = 1;
    b_I[4] = 1;
    b_I[8] = 1;
    c_I[0] = 1;
    c_I[4] = 1;
    c_I[8] = 1;
    d_I[0] = 1;
    d_I[4] = 1;
    d_I[8] = 1;

    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    q[0] = IPC4M_B.x[3];
    q[1] = -IPC4M_B.x[4];
    q[2] = -IPC4M_B.x[5];
    q[3] = -IPC4M_B.x[6];
    tmp_16[0] = 0.0;
    tmp_16[1] = IPC4M_B.x[0] - x_o[0];
    tmp_16[2] = IPC4M_B.x[1] - x_o[1];
    tmp_16[3] = IPC4M_B.x[2] - x_o[2];
    IPC4M_quatmultiply_h(tmp_16, q, tmp_17);
    IPC4M_quatmultiply_h(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, tmp_18);

    /* generates skew- symmetric matrix from vector */
    e_I[0] = 1;
    e_I[4] = 1;
    e_I[8] = 1;

    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    q[0] = IPC4M_B.x[3];
    q[1] = -IPC4M_B.x[4];
    q[2] = -IPC4M_B.x[5];
    q[3] = -IPC4M_B.x[6];
    tmp_15[0] = 0.0;
    tmp_15[1] = IPC4M_B.x[7] - x_o[0];
    tmp_15[2] = IPC4M_B.x[8] - x_o[1];
    tmp_15[3] = IPC4M_B.x[9] - x_o[2];
    IPC4M_quatmultiply_h(tmp_15, q, tmp_17);
    IPC4M_quatmultiply_h(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, tmp_19);

    /* generates skew- symmetric matrix from vector */
    f_I[0] = 1;
    f_I[4] = 1;
    f_I[8] = 1;

    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    q[0] = IPC4M_B.x[3];
    q[1] = -IPC4M_B.x[4];
    q[2] = -IPC4M_B.x[5];
    q[3] = -IPC4M_B.x[6];
    tmp_14[0] = 0.0;
    tmp_14[1] = IPC4M_B.x[14] - x_o[0];
    tmp_14[2] = IPC4M_B.x[15] - x_o[1];
    tmp_14[3] = IPC4M_B.x[16] - x_o[2];
    IPC4M_quatmultiply_h(tmp_14, q, tmp_17);
    IPC4M_quatmultiply_h(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, tmp_1a);

    /* generates skew- symmetric matrix from vector */
    g_I[0] = 1;
    g_I[4] = 1;
    g_I[8] = 1;

    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    q[0] = IPC4M_B.x[3];
    q[1] = -IPC4M_B.x[4];
    q[2] = -IPC4M_B.x[5];
    q[3] = -IPC4M_B.x[6];
    tmp_13[0] = 0.0;
    tmp_13[1] = IPC4M_B.x[21] - x_o[0];
    tmp_13[2] = IPC4M_B.x[22] - x_o[1];
    tmp_13[3] = IPC4M_B.x[23] - x_o[2];
    IPC4M_quatmultiply_h(tmp_13, q, tmp_17);
    IPC4M_quatmultiply_h(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, q);

    /* generates skew- symmetric matrix from vector */
    h_I[0] = 1;
    h_I[4] = 1;
    h_I[8] = 1;

    /* Math: '<S7>/Transpose' incorporates:
     *  MATLAB Function: '<S7>/Grasp Matrix'
     */
    for (i = 0; i < 3; i++) {
      rtb_Transpose_f[24 * i] = I[i];
      rtb_Transpose_f[1 + 24 * i] = I[i + 3];
      rtb_Transpose_f[2 + 24 * i] = I[i + 6];
    }

    for (i = 0; i < 3; i++) {
      rtb_Transpose_f[3 + 24 * i] = 0.0;
      rtb_Transpose_f[4 + 24 * i] = 0.0;
      rtb_Transpose_f[5 + 24 * i] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_Transpose_f[6 + 24 * i] = b_I[i];
      rtb_Transpose_f[7 + 24 * i] = b_I[i + 3];
      rtb_Transpose_f[8 + 24 * i] = b_I[i + 6];
    }

    for (i = 0; i < 3; i++) {
      rtb_Transpose_f[9 + 24 * i] = 0.0;
      rtb_Transpose_f[10 + 24 * i] = 0.0;
      rtb_Transpose_f[11 + 24 * i] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_Transpose_f[12 + 24 * i] = c_I[i];
      rtb_Transpose_f[13 + 24 * i] = c_I[i + 3];
      rtb_Transpose_f[14 + 24 * i] = c_I[i + 6];
    }

    for (i = 0; i < 3; i++) {
      rtb_Transpose_f[15 + 24 * i] = 0.0;
      rtb_Transpose_f[16 + 24 * i] = 0.0;
      rtb_Transpose_f[17 + 24 * i] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_Transpose_f[18 + 24 * i] = d_I[i];
      rtb_Transpose_f[19 + 24 * i] = d_I[i + 3];
      rtb_Transpose_f[20 + 24 * i] = d_I[i + 6];
    }

    for (i = 0; i < 3; i++) {
      rtb_Transpose_f[21 + 24 * i] = 0.0;
      rtb_Transpose_f[22 + 24 * i] = 0.0;
      rtb_Transpose_f[23 + 24 * i] = 0.0;
    }

    rtb_Transpose_f[72] = 0.0;
    rtb_Transpose_f[73] = -tmp_18[3];
    rtb_Transpose_f[74] = tmp_18[2];
    rtb_Transpose_f[96] = tmp_18[3];
    rtb_Transpose_f[97] = 0.0;
    rtb_Transpose_f[98] = -tmp_18[1];
    rtb_Transpose_f[120] = -tmp_18[2];
    rtb_Transpose_f[121] = tmp_18[1];
    rtb_Transpose_f[122] = 0.0;
    for (i = 0; i < 3; i++) {
      rtb_Transpose_f[3 + 24 * (i + 3)] = e_I[i];
      rtb_Transpose_f[4 + 24 * (i + 3)] = e_I[i + 3];
      rtb_Transpose_f[5 + 24 * (i + 3)] = e_I[i + 6];
    }

    rtb_Transpose_f[78] = 0.0;
    rtb_Transpose_f[79] = -tmp_19[3];
    rtb_Transpose_f[80] = tmp_19[2];
    rtb_Transpose_f[102] = tmp_19[3];
    rtb_Transpose_f[103] = 0.0;
    rtb_Transpose_f[104] = -tmp_19[1];
    rtb_Transpose_f[126] = -tmp_19[2];
    rtb_Transpose_f[127] = tmp_19[1];
    rtb_Transpose_f[128] = 0.0;
    for (i = 0; i < 3; i++) {
      rtb_Transpose_f[9 + 24 * (i + 3)] = f_I[i];
      rtb_Transpose_f[10 + 24 * (i + 3)] = f_I[i + 3];
      rtb_Transpose_f[11 + 24 * (i + 3)] = f_I[i + 6];
    }

    rtb_Transpose_f[84] = 0.0;
    rtb_Transpose_f[85] = -tmp_1a[3];
    rtb_Transpose_f[86] = tmp_1a[2];
    rtb_Transpose_f[108] = tmp_1a[3];
    rtb_Transpose_f[109] = 0.0;
    rtb_Transpose_f[110] = -tmp_1a[1];
    rtb_Transpose_f[132] = -tmp_1a[2];
    rtb_Transpose_f[133] = tmp_1a[1];
    rtb_Transpose_f[134] = 0.0;
    for (i = 0; i < 3; i++) {
      rtb_Transpose_f[15 + 24 * (i + 3)] = g_I[i];
      rtb_Transpose_f[16 + 24 * (i + 3)] = g_I[i + 3];
      rtb_Transpose_f[17 + 24 * (i + 3)] = g_I[i + 6];
    }

    rtb_Transpose_f[90] = 0.0;
    rtb_Transpose_f[91] = -q[3];
    rtb_Transpose_f[92] = q[2];
    rtb_Transpose_f[114] = q[3];
    rtb_Transpose_f[115] = 0.0;
    rtb_Transpose_f[116] = -q[1];
    rtb_Transpose_f[138] = -q[2];
    rtb_Transpose_f[139] = q[1];
    rtb_Transpose_f[140] = 0.0;
    for (i = 0; i < 3; i++) {
      rtb_Transpose_f[21 + 24 * (i + 3)] = h_I[i];
      rtb_Transpose_f[22 + 24 * (i + 3)] = h_I[i + 3];
      rtb_Transpose_f[23 + 24 * (i + 3)] = h_I[i + 6];
    }

    /* End of Math: '<S7>/Transpose' */

    /* TransferFcn: '<Root>/PT1 Filter' */
    rtb_Product4 = IPC4M_P.PT1Filter_C * IPC4M_X.PT1Filter_CSTATE;

    /* Sin: '<Root>/Sine Wave' */
    IPC4M_B.SineWave = sin(IPC4M_P.SineWave_Freq * IPC4M_M->Timing.t[0] +
      IPC4M_P.SineWave_Phase) * IPC4M_P.SineWave_Amp + IPC4M_P.SineWave_Bias;
    for (i = 0; i < 5; i++) {
      /* Gain: '<Root>/Gain1' */
      IPC4M_B.Gain1[i] = IPC4M_P.Gain1_Gain[i] * rtb_Product4;

      /* SignalConversion: '<S7>/TmpSignal ConversionAtdx = G' dx_o,dInport2' */
      IPC4M_B.TmpSignalConversionAtdxGdx_odIn[i] = IPC4M_B.Gain1[i];
    }

    /* SignalConversion: '<S7>/TmpSignal ConversionAtdx = G' dx_o,dInport2' */
    IPC4M_B.TmpSignalConversionAtdxGdx_odIn[5] = IPC4M_B.SineWave;

    /* Product: '<S7>/dx = G' dx_o,d' */
    for (i = 0; i < 24; i++) {
      IPC4M_B.dxGdx_od[i] = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        IPC4M_B.dxGdx_od[i] += rtb_Transpose_f[24 * i_1 + i] *
          IPC4M_B.TmpSignalConversionAtdxGdx_odIn[i_1];
      }
    }

    /* End of Product: '<S7>/dx = G' dx_o,d' */
    if (rtmIsMajorTimeStep(IPC4M_M)) {
    }

    /* Integrator: '<S89>/Integrator' */
    IPC4M_B.Integrator_g[0] = IPC4M_X.Integrator_CSTATE_e[0];
    IPC4M_B.Integrator_g[1] = IPC4M_X.Integrator_CSTATE_e[1];
    IPC4M_B.Integrator_g[2] = IPC4M_X.Integrator_CSTATE_e[2];
    IPC4M_B.Integrator_g[3] = IPC4M_X.Integrator_CSTATE_e[3];

    /* Sqrt: '<S96>/sqrt' incorporates:
     *  Product: '<S97>/Product'
     *  Product: '<S97>/Product1'
     *  Product: '<S97>/Product2'
     *  Product: '<S97>/Product3'
     *  Sum: '<S97>/Sum'
     */
    rtb_Product4 = sqrt(((IPC4M_B.Integrator_g[0] * IPC4M_B.Integrator_g[0] +
                          IPC4M_B.Integrator_g[1] * IPC4M_B.Integrator_g[1]) +
                         IPC4M_B.Integrator_g[2] * IPC4M_B.Integrator_g[2]) +
                        IPC4M_B.Integrator_g[3] * IPC4M_B.Integrator_g[3]);

    /* SignalConversion: '<S76>/TmpSignal ConversionAt SFunction Inport2' incorporates:
     *  MATLAB Function: '<S7>/Manipulator Position//Orientation in World Frame'
     *  Product: '<S90>/Product'
     *  Product: '<S90>/Product1'
     *  Product: '<S90>/Product2'
     *  Product: '<S90>/Product3'
     */
    rtb_TmpSignalConversionAtSFunct[0] = IPC4M_B.Integrator_g[0] / rtb_Product4;
    rtb_TmpSignalConversionAtSFunct[1] = IPC4M_B.Integrator_g[1] / rtb_Product4;
    rtb_TmpSignalConversionAtSFunct[2] = IPC4M_B.Integrator_g[2] / rtb_Product4;
    rtb_TmpSignalConversionAtSFunct[3] = IPC4M_B.Integrator_g[3] / rtb_Product4;

    /* MATLAB Function: '<S7>/Manipulator Position//Orientation in World Frame' incorporates:
     *  Integrator: '<S13>/Integrator'
     */
    /* MATLAB Function 'Kinematic Coordination/Manipulator Position//Orientation in World Frame': '<S76>:1' */
    /* '<S76>:1:2' */
    for (i = 0; i < 3; i++) {
      x_o[i] = 0.0;
      for (i_1 = 0; i_1 < 28; i_1++) {
        x_o[i] += (real_T)a_0[3 * i_1 + i] * IPC4M_B.x[i_1];
      }
    }

    /* '<S76>:1:4' */
    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    q[0] = rtb_TmpSignalConversionAtSFunct[0];
    q[1] = -rtb_TmpSignalConversionAtSFunct[1];
    q[2] = -rtb_TmpSignalConversionAtSFunct[2];
    q[3] = -rtb_TmpSignalConversionAtSFunct[3];

    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    b_q[0] = rtb_TmpSignalConversionAtSFunct[0];
    b_q[1] = -rtb_TmpSignalConversionAtSFunct[1];
    b_q[2] = -rtb_TmpSignalConversionAtSFunct[2];
    b_q[3] = -rtb_TmpSignalConversionAtSFunct[3];

    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    c_q[0] = rtb_TmpSignalConversionAtSFunct[0];
    c_q[1] = -rtb_TmpSignalConversionAtSFunct[1];
    c_q[2] = -rtb_TmpSignalConversionAtSFunct[2];
    c_q[3] = -rtb_TmpSignalConversionAtSFunct[3];

    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    d_q[0] = rtb_TmpSignalConversionAtSFunct[0];
    d_q[1] = -rtb_TmpSignalConversionAtSFunct[1];
    d_q[2] = -rtb_TmpSignalConversionAtSFunct[2];
    d_q[3] = -rtb_TmpSignalConversionAtSFunct[3];
    tmp_z[0] = 0.0;
    tmp_z[1] = IPC4M_B.x[0] - x_o[0];
    tmp_z[2] = IPC4M_B.x[1] - x_o[1];
    tmp_z[3] = IPC4M_B.x[2] - x_o[2];
    IPC4M_quatmultiply_l(tmp_z, q, tmp_17);
    IPC4M_quatmultiply_l(rtb_TmpSignalConversionAtSFunct, tmp_17, tmp_18);
    tmp_10[0] = 0.0;
    tmp_10[1] = IPC4M_B.x[7] - x_o[0];
    tmp_10[2] = IPC4M_B.x[8] - x_o[1];
    tmp_10[3] = IPC4M_B.x[9] - x_o[2];
    IPC4M_quatmultiply_l(tmp_10, b_q, tmp_17);
    IPC4M_quatmultiply_l(rtb_TmpSignalConversionAtSFunct, tmp_17, tmp_19);
    tmp_11[0] = 0.0;
    tmp_11[1] = IPC4M_B.x[14] - x_o[0];
    tmp_11[2] = IPC4M_B.x[15] - x_o[1];
    tmp_11[3] = IPC4M_B.x[16] - x_o[2];
    IPC4M_quatmultiply_l(tmp_11, c_q, tmp_17);
    IPC4M_quatmultiply_l(rtb_TmpSignalConversionAtSFunct, tmp_17, tmp_1a);
    tmp_12[0] = 0.0;
    tmp_12[1] = IPC4M_B.x[21] - x_o[0];
    tmp_12[2] = IPC4M_B.x[22] - x_o[1];
    tmp_12[3] = IPC4M_B.x[23] - x_o[2];
    IPC4M_quatmultiply_l(tmp_12, d_q, tmp_17);
    IPC4M_quatmultiply_l(rtb_TmpSignalConversionAtSFunct, tmp_17, tmp_1b);
    IPC4M_B.x_d[0] = IPC4M_X.Integrator_CSTATE_i[0] + tmp_18[1];
    IPC4M_B.x_d[1] = IPC4M_X.Integrator_CSTATE_i[1] + tmp_18[2];
    IPC4M_B.x_d[2] = IPC4M_X.Integrator_CSTATE_i[2] + tmp_18[3];
    IPC4M_B.x_d[3] = rtb_TmpSignalConversionAtSFunct[0];
    IPC4M_B.x_d[4] = rtb_TmpSignalConversionAtSFunct[1];
    IPC4M_B.x_d[5] = rtb_TmpSignalConversionAtSFunct[2];
    IPC4M_B.x_d[6] = rtb_TmpSignalConversionAtSFunct[3];
    IPC4M_B.x_d[7] = IPC4M_X.Integrator_CSTATE_i[0] + tmp_19[1];
    IPC4M_B.x_d[8] = IPC4M_X.Integrator_CSTATE_i[1] + tmp_19[2];
    IPC4M_B.x_d[9] = IPC4M_X.Integrator_CSTATE_i[2] + tmp_19[3];
    IPC4M_B.x_d[10] = rtb_TmpSignalConversionAtSFunct[0];
    IPC4M_B.x_d[11] = rtb_TmpSignalConversionAtSFunct[1];
    IPC4M_B.x_d[12] = rtb_TmpSignalConversionAtSFunct[2];
    IPC4M_B.x_d[13] = rtb_TmpSignalConversionAtSFunct[3];
    IPC4M_B.x_d[14] = IPC4M_X.Integrator_CSTATE_i[0] + tmp_1a[1];
    IPC4M_B.x_d[15] = IPC4M_X.Integrator_CSTATE_i[1] + tmp_1a[2];
    IPC4M_B.x_d[16] = IPC4M_X.Integrator_CSTATE_i[2] + tmp_1a[3];
    IPC4M_B.x_d[17] = rtb_TmpSignalConversionAtSFunct[0];
    IPC4M_B.x_d[18] = rtb_TmpSignalConversionAtSFunct[1];
    IPC4M_B.x_d[19] = rtb_TmpSignalConversionAtSFunct[2];
    IPC4M_B.x_d[20] = rtb_TmpSignalConversionAtSFunct[3];
    IPC4M_B.x_d[21] = IPC4M_X.Integrator_CSTATE_i[0] + tmp_1b[1];
    IPC4M_B.x_d[22] = IPC4M_X.Integrator_CSTATE_i[1] + tmp_1b[2];
    IPC4M_B.x_d[23] = IPC4M_X.Integrator_CSTATE_i[2] + tmp_1b[3];
    IPC4M_B.x_d[24] = rtb_TmpSignalConversionAtSFunct[0];
    IPC4M_B.x_d[25] = rtb_TmpSignalConversionAtSFunct[1];
    IPC4M_B.x_d[26] = rtb_TmpSignalConversionAtSFunct[2];
    IPC4M_B.x_d[27] = rtb_TmpSignalConversionAtSFunct[3];

    /* Sum: '<S26>/Sum' incorporates:
     *  Product: '<S26>/Product'
     *  Product: '<S26>/Product1'
     *  Product: '<S26>/Product2'
     *  Product: '<S26>/Product3'
     *  UnaryMinus: '<S22>/Unary Minus'
     *  UnaryMinus: '<S22>/Unary Minus1'
     *  UnaryMinus: '<S22>/Unary Minus2'
     */
    rtb_Sum_k = ((IPC4M_B.x_d[3] * IPC4M_B.x[3] - -IPC4M_B.x_d[4] * IPC4M_B.x[4])
                 - -IPC4M_B.x_d[5] * IPC4M_B.x[5]) - -IPC4M_B.x_d[6] *
      IPC4M_B.x[6];

    /* Sum: '<S27>/Sum' incorporates:
     *  Product: '<S27>/Product'
     *  Product: '<S27>/Product1'
     *  Product: '<S27>/Product2'
     *  Product: '<S27>/Product3'
     *  UnaryMinus: '<S22>/Unary Minus'
     *  UnaryMinus: '<S22>/Unary Minus1'
     *  UnaryMinus: '<S22>/Unary Minus2'
     */
    rtb_Sum_iy = ((IPC4M_B.x_d[3] * IPC4M_B.x[4] + -IPC4M_B.x_d[4] * IPC4M_B.x[3])
                  + -IPC4M_B.x_d[5] * IPC4M_B.x[6]) - -IPC4M_B.x_d[6] *
      IPC4M_B.x[5];

    /* Sum: '<S28>/Sum' incorporates:
     *  Product: '<S28>/Product'
     *  Product: '<S28>/Product1'
     *  Product: '<S28>/Product2'
     *  Product: '<S28>/Product3'
     *  UnaryMinus: '<S22>/Unary Minus'
     *  UnaryMinus: '<S22>/Unary Minus1'
     *  UnaryMinus: '<S22>/Unary Minus2'
     */
    rtb_Sum_bl = ((IPC4M_B.x_d[3] * IPC4M_B.x[5] - -IPC4M_B.x_d[4] * IPC4M_B.x[6])
                  + -IPC4M_B.x_d[5] * IPC4M_B.x[3]) + -IPC4M_B.x_d[6] *
      IPC4M_B.x[4];

    /* Sum: '<S29>/Sum' incorporates:
     *  Product: '<S29>/Product'
     *  Product: '<S29>/Product1'
     *  Product: '<S29>/Product2'
     *  Product: '<S29>/Product3'
     *  UnaryMinus: '<S22>/Unary Minus'
     *  UnaryMinus: '<S22>/Unary Minus1'
     *  UnaryMinus: '<S22>/Unary Minus2'
     */
    rtb_Sum_a5 = ((IPC4M_B.x_d[3] * IPC4M_B.x[6] + -IPC4M_B.x_d[4] * IPC4M_B.x[5])
                  - -IPC4M_B.x_d[5] * IPC4M_B.x[4]) + -IPC4M_B.x_d[6] *
      IPC4M_B.x[3];

    /* Sum: '<S37>/Sum' incorporates:
     *  Product: '<S37>/Product'
     *  Product: '<S37>/Product1'
     *  Product: '<S37>/Product2'
     *  Product: '<S37>/Product3'
     *  UnaryMinus: '<S30>/Unary Minus'
     *  UnaryMinus: '<S30>/Unary Minus1'
     *  UnaryMinus: '<S30>/Unary Minus2'
     */
    rtb_Product4 = ((rtb_Sum_k * IPC4M_B.x[3] - rtb_Sum_iy * -IPC4M_B.x[4]) -
                    rtb_Sum_bl * -IPC4M_B.x[5]) - rtb_Sum_a5 * -IPC4M_B.x[6];

    /* Sum: '<S38>/Sum' incorporates:
     *  Product: '<S38>/Product'
     *  Product: '<S38>/Product1'
     *  Product: '<S38>/Product2'
     *  Product: '<S38>/Product3'
     *  UnaryMinus: '<S30>/Unary Minus'
     *  UnaryMinus: '<S30>/Unary Minus1'
     *  UnaryMinus: '<S30>/Unary Minus2'
     */
    rtb_Product3_eb = ((rtb_Sum_k * -IPC4M_B.x[4] + rtb_Sum_iy * IPC4M_B.x[3]) +
                       rtb_Sum_bl * -IPC4M_B.x[6]) - rtb_Sum_a5 * -IPC4M_B.x[5];

    /* Sum: '<S39>/Sum' incorporates:
     *  Product: '<S39>/Product'
     *  Product: '<S39>/Product1'
     *  Product: '<S39>/Product2'
     *  Product: '<S39>/Product3'
     *  UnaryMinus: '<S30>/Unary Minus'
     *  UnaryMinus: '<S30>/Unary Minus1'
     *  UnaryMinus: '<S30>/Unary Minus2'
     */
    rtb_Sum_e = ((rtb_Sum_k * -IPC4M_B.x[5] - rtb_Sum_iy * -IPC4M_B.x[6]) +
                 rtb_Sum_bl * IPC4M_B.x[3]) + rtb_Sum_a5 * -IPC4M_B.x[4];

    /* Sum: '<S40>/Sum' incorporates:
     *  Product: '<S40>/Product'
     *  Product: '<S40>/Product1'
     *  Product: '<S40>/Product2'
     *  Product: '<S40>/Product3'
     *  UnaryMinus: '<S30>/Unary Minus'
     *  UnaryMinus: '<S30>/Unary Minus1'
     *  UnaryMinus: '<S30>/Unary Minus2'
     */
    rtb_Product2_fj = ((rtb_Sum_k * -IPC4M_B.x[6] + rtb_Sum_iy * -IPC4M_B.x[5])
                       - rtb_Sum_bl * -IPC4M_B.x[4]) + rtb_Sum_a5 * IPC4M_B.x[3];

    /* Sum: '<S33>/Sum' incorporates:
     *  Product: '<S33>/Product'
     *  Product: '<S33>/Product1'
     *  Product: '<S33>/Product2'
     *  Product: '<S33>/Product3'
     */
    IPC4M_B.Sum = ((IPC4M_B.x[3] * rtb_Product4 - IPC4M_B.x[4] * rtb_Product3_eb)
                   - IPC4M_B.x[5] * rtb_Sum_e) - IPC4M_B.x[6] * rtb_Product2_fj;

    /* MATLAB Function: '<S18>/k1; 2kappa1*eta1' */
    /* MATLAB Function 'Impedance control/Manipulator1/k1; 2kappa1*eta1': '<S25>:1' */
    /* '<S25>:1:2' */
    a_1 = 2.0 * IPC4M_B.Sum * IPC4M_P.kappa1;
    memset(&rtb_K_i[0], 0, 36U * sizeof(real_T));
    for (i = 0; i < 3; i++) {
      rtb_K_i[6 * i] = (real_T)b[3 * i] * IPC4M_P.k1;
      rtb_K_i[1 + 6 * i] = (real_T)b[3 * i + 1] * IPC4M_P.k1;
      rtb_K_i[2 + 6 * i] = (real_T)b[3 * i + 2] * IPC4M_P.k1;
    }

    for (i = 0; i < 3; i++) {
      rtb_K_i[3 + 6 * (3 + i)] = (real_T)b[3 * i] * a_1;
      rtb_K_i[4 + 6 * (3 + i)] = (real_T)b[3 * i + 1] * a_1;
      rtb_K_i[5 + 6 * (3 + i)] = (real_T)b[3 * i + 2] * a_1;
    }

    /* End of MATLAB Function: '<S18>/k1; 2kappa1*eta1' */

    /* Sum: '<S18>/p1-p1d' */
    IPC4M_B.p1p1d[0] = IPC4M_B.x[0] - IPC4M_B.x_d[0];
    IPC4M_B.p1p1d[1] = IPC4M_B.x[1] - IPC4M_B.x_d[1];
    IPC4M_B.p1p1d[2] = IPC4M_B.x[2] - IPC4M_B.x_d[2];

    /* Sum: '<S34>/Sum' incorporates:
     *  Product: '<S34>/Product'
     *  Product: '<S34>/Product1'
     *  Product: '<S34>/Product2'
     *  Product: '<S34>/Product3'
     */
    rtb_Sum_g = ((IPC4M_B.x[3] * rtb_Product3_eb + IPC4M_B.x[4] * rtb_Product4)
                 + IPC4M_B.x[5] * rtb_Product2_fj) - IPC4M_B.x[6] * rtb_Sum_e;

    /* Sum: '<S35>/Sum' incorporates:
     *  Product: '<S35>/Product'
     *  Product: '<S35>/Product1'
     *  Product: '<S35>/Product2'
     *  Product: '<S35>/Product3'
     */
    rtb_Sum_m = ((IPC4M_B.x[3] * rtb_Sum_e - IPC4M_B.x[4] * rtb_Product2_fj) +
                 IPC4M_B.x[5] * rtb_Product4) + IPC4M_B.x[6] * rtb_Product3_eb;

    /* Sum: '<S36>/Sum' incorporates:
     *  Product: '<S36>/Product'
     *  Product: '<S36>/Product1'
     *  Product: '<S36>/Product2'
     *  Product: '<S36>/Product3'
     */
    rtb_Sum_e = ((IPC4M_B.x[3] * rtb_Product2_fj + IPC4M_B.x[4] * rtb_Sum_e) -
                 IPC4M_B.x[5] * rtb_Product3_eb) + IPC4M_B.x[6] * rtb_Product4;

    /* SignalConversion: '<S18>/TmpSignal ConversionAtk1(p1-p1d);2kapeta*q1//q1dInport2' */
    tmp_1c[0] = IPC4M_B.p1p1d[0];
    tmp_1c[1] = IPC4M_B.p1p1d[1];
    tmp_1c[2] = IPC4M_B.p1p1d[2];
    tmp_1c[3] = rtb_Sum_g;
    tmp_1c[4] = rtb_Sum_m;
    tmp_1c[5] = rtb_Sum_e;
    for (i = 0; i < 6; i++) {
      /* Product: '<S18>/k1(p1-p1d);2kapeta*q1//q1d' incorporates:
       *  SignalConversion: '<S18>/TmpSignal ConversionAtk1(p1-p1d);2kapeta*q1//q1dInport2'
       */
      IPC4M_B.k1p1p1d2kapetaq1q1d[i] = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        IPC4M_B.k1p1p1d2kapetaq1q1d[i] += rtb_K_i[6 * i_1 + i] * tmp_1c[i_1];
      }

      /* End of Product: '<S18>/k1(p1-p1d);2kapeta*q1//q1d' */

      /* Sum: '<S18>/Add' incorporates:
       *  Product: '<S18>/Product2'
       */
      tmp_1d[i] = IPC4M_B.Gdx_o[i] - IPC4M_B.dxGdx_od[i];
    }

    /* Product: '<S18>/Product2' incorporates:
     *  Constant: '<S18>/Damping'
     */
    for (i = 0; i < 6; i++) {
      IPC4M_B.Product2[i] = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        IPC4M_B.Product2[i] += IPC4M_P.Damping_Value[6 * i_1 + i] * tmp_1d[i_1];
      }
    }

    for (i = 0; i < 5; i++) {
      /* SignalConversion: '<S74>/TmpSignal ConversionAt SFunction Inport1' incorporates:
       *  MATLAB Function: '<S7>/Centripetal Force'
       */
      rtb_TmpSignalConversionAtSFun_e[i] = IPC4M_B.Gain1[i];
    }

    /* MATLAB Function: '<S7>/Centripetal Force' */
    /* MATLAB Function 'Kinematic Coordination/Centripetal Force': '<S74>:1' */
    /* '<S74>:1:2' */
    for (i = 0; i < 3; i++) {
      x_o[i] = 0.0;
      for (i_1 = 0; i_1 < 28; i_1++) {
        x_o[i] += (real_T)a_2[3 * i_1 + i] * IPC4M_B.x[i_1];
      }
    }

    /* '<S74>:1:3' */
    /* generates skew- symmetric matrix from vector */
    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    q[0] = IPC4M_B.x[3];
    q[1] = -IPC4M_B.x[4];
    q[2] = -IPC4M_B.x[5];
    q[3] = -IPC4M_B.x[6];

    /* generates skew- symmetric matrix from vector */
    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    b_q[0] = IPC4M_B.x[3];
    b_q[1] = -IPC4M_B.x[4];
    b_q[2] = -IPC4M_B.x[5];
    b_q[3] = -IPC4M_B.x[6];

    /* generates skew- symmetric matrix from vector */
    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    c_q[0] = IPC4M_B.x[3];
    c_q[1] = -IPC4M_B.x[4];
    c_q[2] = -IPC4M_B.x[5];
    c_q[3] = -IPC4M_B.x[6];

    /* generates skew- symmetric matrix from vector */
    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    d_q[0] = IPC4M_B.x[3];
    d_q[1] = -IPC4M_B.x[4];
    d_q[2] = -IPC4M_B.x[5];
    d_q[3] = -IPC4M_B.x[6];

    /* Derivative: '<S13>/Derivative' */
    if ((IPC4M_DW.TimeStampA >= IPC4M_M->Timing.t[0]) && (IPC4M_DW.TimeStampB >=
         IPC4M_M->Timing.t[0])) {
      for (i = 0; i < 6; i++) {
        rtb_Derivative[i] = 0.0;
      }
    } else {
      rtb_Product4 = IPC4M_DW.TimeStampA;
      lastU = (real_T (*)[6])IPC4M_DW.LastUAtTimeA;
      if (IPC4M_DW.TimeStampA < IPC4M_DW.TimeStampB) {
        if (IPC4M_DW.TimeStampB < IPC4M_M->Timing.t[0]) {
          rtb_Product4 = IPC4M_DW.TimeStampB;
          lastU = (real_T (*)[6])IPC4M_DW.LastUAtTimeB;
        }
      } else {
        if (IPC4M_DW.TimeStampA >= IPC4M_M->Timing.t[0]) {
          rtb_Product4 = IPC4M_DW.TimeStampB;
          lastU = (real_T (*)[6])IPC4M_DW.LastUAtTimeB;
        }
      }

      rtb_Product4 = IPC4M_M->Timing.t[0] - rtb_Product4;
      for (i = 0; i < 6; i++) {
        rtb_Derivative[i] = (IPC4M_B.TmpSignalConversionAtdxGdx_odIn[i] -
                             (*lastU)[i]) / rtb_Product4;
      }
    }

    /* End of Derivative: '<S13>/Derivative' */

    /* MATLAB Function: '<S7>/Centripetal Force' incorporates:
     *  SignalConversion: '<S74>/TmpSignal ConversionAt SFunction Inport1'
     *  Sum: '<S7>/b = G'ddx_o,d + S^2(omega_od)*r'
     */
    tmp_v[0] = 0.0;
    tmp_v[1] = IPC4M_B.x[0] - x_o[0];
    tmp_v[2] = IPC4M_B.x[1] - x_o[1];
    tmp_v[3] = IPC4M_B.x[2] - x_o[2];
    IPC4M_quatmultiply_ec(tmp_v, q, tmp_17);
    IPC4M_quatmultiply_ec(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, tmp_18);
    tmp_w[0] = 0.0;
    tmp_w[1] = IPC4M_B.x[7] - x_o[0];
    tmp_w[2] = IPC4M_B.x[8] - x_o[1];
    tmp_w[3] = IPC4M_B.x[9] - x_o[2];
    IPC4M_quatmultiply_ec(tmp_w, b_q, tmp_17);
    IPC4M_quatmultiply_ec(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, tmp_19);
    tmp_x[0] = 0.0;
    tmp_x[1] = IPC4M_B.x[14] - x_o[0];
    tmp_x[2] = IPC4M_B.x[15] - x_o[1];
    tmp_x[3] = IPC4M_B.x[16] - x_o[2];
    IPC4M_quatmultiply_ec(tmp_x, c_q, tmp_17);
    IPC4M_quatmultiply_ec(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, tmp_1a);
    tmp_y[0] = 0.0;
    tmp_y[1] = IPC4M_B.x[21] - x_o[0];
    tmp_y[2] = IPC4M_B.x[22] - x_o[1];
    tmp_y[3] = IPC4M_B.x[23] - x_o[2];
    IPC4M_quatmultiply_ec(tmp_y, d_q, tmp_17);
    IPC4M_quatmultiply_ec(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, tmp_1b);
    tmp_1e[0] = 0.0;
    tmp_1e[3] = -IPC4M_B.SineWave;
    tmp_1e[6] = rtb_TmpSignalConversionAtSFun_e[4];
    tmp_1e[1] = IPC4M_B.SineWave;
    tmp_1e[4] = 0.0;
    tmp_1e[7] = -rtb_TmpSignalConversionAtSFun_e[3];
    tmp_1e[2] = -rtb_TmpSignalConversionAtSFun_e[4];
    tmp_1e[5] = rtb_TmpSignalConversionAtSFun_e[3];
    tmp_1e[8] = 0.0;
    tmp_1f[0] = 0.0;
    tmp_1f[3] = -IPC4M_B.SineWave;
    tmp_1f[6] = rtb_TmpSignalConversionAtSFun_e[4];
    tmp_1f[1] = IPC4M_B.SineWave;
    tmp_1f[4] = 0.0;
    tmp_1f[7] = -rtb_TmpSignalConversionAtSFun_e[3];
    tmp_1f[2] = -rtb_TmpSignalConversionAtSFun_e[4];
    tmp_1f[5] = rtb_TmpSignalConversionAtSFun_e[3];
    tmp_1f[8] = 0.0;
    for (i = 0; i < 3; i++) {
      for (i_1 = 0; i_1 < 3; i_1++) {
        tmp_1g[i + 3 * i_1] = 0.0;
        tmp_1g[i + 3 * i_1] += tmp_1f[3 * i_1] * tmp_1e[i];
        tmp_1g[i + 3 * i_1] += tmp_1f[3 * i_1 + 1] * tmp_1e[i + 3];
        tmp_1g[i + 3 * i_1] += tmp_1f[3 * i_1 + 2] * tmp_1e[i + 6];
      }
    }

    tmp_1h[0] = 0.0;
    tmp_1h[3] = -IPC4M_B.SineWave;
    tmp_1h[6] = rtb_TmpSignalConversionAtSFun_e[4];
    tmp_1h[1] = IPC4M_B.SineWave;
    tmp_1h[4] = 0.0;
    tmp_1h[7] = -rtb_TmpSignalConversionAtSFun_e[3];
    tmp_1h[2] = -rtb_TmpSignalConversionAtSFun_e[4];
    tmp_1h[5] = rtb_TmpSignalConversionAtSFun_e[3];
    tmp_1h[8] = 0.0;
    tmp_1i[0] = 0.0;
    tmp_1i[3] = -IPC4M_B.SineWave;
    tmp_1i[6] = rtb_TmpSignalConversionAtSFun_e[4];
    tmp_1i[1] = IPC4M_B.SineWave;
    tmp_1i[4] = 0.0;
    tmp_1i[7] = -rtb_TmpSignalConversionAtSFun_e[3];
    tmp_1i[2] = -rtb_TmpSignalConversionAtSFun_e[4];
    tmp_1i[5] = rtb_TmpSignalConversionAtSFun_e[3];
    tmp_1i[8] = 0.0;
    for (i = 0; i < 3; i++) {
      for (i_1 = 0; i_1 < 3; i_1++) {
        tmp_1e[i + 3 * i_1] = 0.0;
        tmp_1e[i + 3 * i_1] += tmp_1i[3 * i_1] * tmp_1h[i];
        tmp_1e[i + 3 * i_1] += tmp_1i[3 * i_1 + 1] * tmp_1h[i + 3];
        tmp_1e[i + 3 * i_1] += tmp_1i[3 * i_1 + 2] * tmp_1h[i + 6];
      }
    }

    tmp_1j[0] = 0.0;
    tmp_1j[3] = -IPC4M_B.SineWave;
    tmp_1j[6] = rtb_TmpSignalConversionAtSFun_e[4];
    tmp_1j[1] = IPC4M_B.SineWave;
    tmp_1j[4] = 0.0;
    tmp_1j[7] = -rtb_TmpSignalConversionAtSFun_e[3];
    tmp_1j[2] = -rtb_TmpSignalConversionAtSFun_e[4];
    tmp_1j[5] = rtb_TmpSignalConversionAtSFun_e[3];
    tmp_1j[8] = 0.0;
    tmp_1k[0] = 0.0;
    tmp_1k[3] = -IPC4M_B.SineWave;
    tmp_1k[6] = rtb_TmpSignalConversionAtSFun_e[4];
    tmp_1k[1] = IPC4M_B.SineWave;
    tmp_1k[4] = 0.0;
    tmp_1k[7] = -rtb_TmpSignalConversionAtSFun_e[3];
    tmp_1k[2] = -rtb_TmpSignalConversionAtSFun_e[4];
    tmp_1k[5] = rtb_TmpSignalConversionAtSFun_e[3];
    tmp_1k[8] = 0.0;
    for (i = 0; i < 3; i++) {
      for (i_1 = 0; i_1 < 3; i_1++) {
        tmp_1f[i + 3 * i_1] = 0.0;
        tmp_1f[i + 3 * i_1] += tmp_1k[3 * i_1] * tmp_1j[i];
        tmp_1f[i + 3 * i_1] += tmp_1k[3 * i_1 + 1] * tmp_1j[i + 3];
        tmp_1f[i + 3 * i_1] += tmp_1k[3 * i_1 + 2] * tmp_1j[i + 6];
      }
    }

    tmp_1l[0] = 0.0;
    tmp_1l[3] = -IPC4M_B.SineWave;
    tmp_1l[6] = rtb_TmpSignalConversionAtSFun_e[4];
    tmp_1l[1] = IPC4M_B.SineWave;
    tmp_1l[4] = 0.0;
    tmp_1l[7] = -rtb_TmpSignalConversionAtSFun_e[3];
    tmp_1l[2] = -rtb_TmpSignalConversionAtSFun_e[4];
    tmp_1l[5] = rtb_TmpSignalConversionAtSFun_e[3];
    tmp_1l[8] = 0.0;
    tmp_1m[0] = 0.0;
    tmp_1m[3] = -IPC4M_B.SineWave;
    tmp_1m[6] = rtb_TmpSignalConversionAtSFun_e[4];
    tmp_1m[1] = IPC4M_B.SineWave;
    tmp_1m[4] = 0.0;
    tmp_1m[7] = -rtb_TmpSignalConversionAtSFun_e[3];
    tmp_1m[2] = -rtb_TmpSignalConversionAtSFun_e[4];
    tmp_1m[5] = rtb_TmpSignalConversionAtSFun_e[3];
    tmp_1m[8] = 0.0;
    for (i = 0; i < 3; i++) {
      for (i_1 = 0; i_1 < 3; i_1++) {
        tmp_1h[i + 3 * i_1] = 0.0;
        tmp_1h[i + 3 * i_1] += tmp_1m[3 * i_1] * tmp_1l[i];
        tmp_1h[i + 3 * i_1] += tmp_1m[3 * i_1 + 1] * tmp_1l[i + 3];
        tmp_1h[i + 3 * i_1] += tmp_1m[3 * i_1 + 2] * tmp_1l[i + 6];
      }
    }

    for (i = 0; i < 3; i++) {
      c_a_1[i] = tmp_1g[i + 6] * tmp_18[3] + (tmp_1g[i + 3] * tmp_18[2] +
        tmp_1g[i] * tmp_18[1]);
    }

    for (i = 0; i < 3; i++) {
      tmp_1n[i] = tmp_1e[i + 6] * tmp_19[3] + (tmp_1e[i + 3] * tmp_19[2] +
        tmp_1e[i] * tmp_19[1]);
    }

    for (i = 0; i < 3; i++) {
      tmp_1o[i] = tmp_1f[i + 6] * tmp_1a[3] + (tmp_1f[i + 3] * tmp_1a[2] +
        tmp_1f[i] * tmp_1a[1]);
    }

    for (i = 0; i < 3; i++) {
      tmp_1p[i] = tmp_1h[i + 6] * tmp_1b[3] + (tmp_1h[i + 3] * tmp_1b[2] +
        tmp_1h[i] * tmp_1b[1]);
    }

    tmp_1q[0] = c_a_1[0];
    tmp_1q[1] = c_a_1[1];
    tmp_1q[2] = c_a_1[2];
    tmp_1q[3] = 0.0;
    tmp_1q[4] = 0.0;
    tmp_1q[5] = 0.0;
    tmp_1q[6] = tmp_1n[0];
    tmp_1q[7] = tmp_1n[1];
    tmp_1q[8] = tmp_1n[2];
    tmp_1q[9] = 0.0;
    tmp_1q[10] = 0.0;
    tmp_1q[11] = 0.0;
    tmp_1q[12] = tmp_1o[0];
    tmp_1q[13] = tmp_1o[1];
    tmp_1q[14] = tmp_1o[2];
    tmp_1q[15] = 0.0;
    tmp_1q[16] = 0.0;
    tmp_1q[17] = 0.0;
    tmp_1q[18] = tmp_1p[0];
    tmp_1q[19] = tmp_1p[1];
    tmp_1q[20] = tmp_1p[2];
    tmp_1q[21] = 0.0;
    tmp_1q[22] = 0.0;
    tmp_1q[23] = 0.0;
    for (i = 0; i < 24; i++) {
      /* Product: '<S7>/G'ddx_o,d' incorporates:
       *  Sum: '<S7>/b = G'ddx_o,d + S^2(omega_od)*r'
       */
      rtb_Transpose_a[i] = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        rtb_Transpose_a[i] += rtb_Transpose_f[24 * i_1 + i] * rtb_Derivative[i_1];
      }

      /* End of Product: '<S7>/G'ddx_o,d' */

      /* Sum: '<S7>/b = G'ddx_o,d + S^2(omega_od)*r' */
      rtb_Add[i] = tmp_1q[i] + rtb_Transpose_a[i];
    }

    /* Sum: '<S18>/Add1' incorporates:
     *  Constant: '<S18>/Inertia'
     *  Product: '<S18>/Product'
     */
    for (i = 0; i < 6; i++) {
      rtb_Product4 = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        rtb_Product4 += IPC4M_P.Inertia_Value[6 * i_1 + i] * rtb_Add[i_1];
      }

      IPC4M_B.Add1[i] = (rtb_Product4 - IPC4M_B.k1p1p1d2kapetaq1q1d[i]) -
        IPC4M_B.Product2[i];
    }

    /* End of Sum: '<S18>/Add1' */

    /* Sum: '<S43>/Sum' incorporates:
     *  Product: '<S43>/Product'
     *  Product: '<S43>/Product1'
     *  Product: '<S43>/Product2'
     *  Product: '<S43>/Product3'
     */
    rtb_Product3_eb = ((IPC4M_B.x_d[10] * IPC4M_B.x_d[10] + IPC4M_B.x_d[11] *
                        IPC4M_B.x_d[11]) + IPC4M_B.x_d[12] * IPC4M_B.x_d[12]) +
      IPC4M_B.x_d[13] * IPC4M_B.x_d[13];

    /* MATLAB Function: '<S19>/MATLAB Function1' incorporates:
     *  Product: '<S42>/Product1'
     *  Product: '<S44>/Product'
     *  Product: '<S44>/Product1'
     *  Product: '<S44>/Product2'
     *  Product: '<S44>/Product3'
     *  Sum: '<S44>/Sum'
     */
    /* MATLAB Function 'Impedance control/Manipulator2/MATLAB Function1': '<S41>:1' */
    /* '<S41>:1:2' */
    a_1 = (((IPC4M_B.x[10] * IPC4M_B.x_d[10] + IPC4M_B.x[11] * IPC4M_B.x_d[11])
            + IPC4M_B.x[12] * IPC4M_B.x_d[12]) + IPC4M_B.x[13] * IPC4M_B.x_d[13])
      / rtb_Product3_eb * 2.0 * IPC4M_P.kappa2;
    memset(&rtb_K_i[0], 0, 36U * sizeof(real_T));
    for (i = 0; i < 3; i++) {
      rtb_K_i[6 * i] = (real_T)b_0[3 * i] * IPC4M_P.k2;
      rtb_K_i[1 + 6 * i] = (real_T)b_0[3 * i + 1] * IPC4M_P.k2;
      rtb_K_i[2 + 6 * i] = (real_T)b_0[3 * i + 2] * IPC4M_P.k2;
    }

    for (i = 0; i < 3; i++) {
      rtb_K_i[3 + 6 * (3 + i)] = (real_T)b_0[3 * i] * a_1;
      rtb_K_i[4 + 6 * (3 + i)] = (real_T)b_0[3 * i + 1] * a_1;
      rtb_K_i[5 + 6 * (3 + i)] = (real_T)b_0[3 * i + 2] * a_1;
    }

    /* End of MATLAB Function: '<S19>/MATLAB Function1' */

    /* Product: '<S42>/Product2' incorporates:
     *  Product: '<S45>/Product'
     *  Product: '<S45>/Product1'
     *  Product: '<S45>/Product2'
     *  Product: '<S45>/Product3'
     *  Sum: '<S45>/Sum'
     */
    rtb_Product2_fj = (((IPC4M_B.x[11] * IPC4M_B.x_d[10] - IPC4M_B.x[10] *
                         IPC4M_B.x_d[11]) + IPC4M_B.x[12] * IPC4M_B.x_d[13]) -
                       IPC4M_B.x[13] * IPC4M_B.x_d[12]) / rtb_Product3_eb;

    /* Product: '<S42>/Product4' incorporates:
     *  Product: '<S46>/Product'
     *  Product: '<S46>/Product1'
     *  Product: '<S46>/Product2'
     *  Product: '<S46>/Product3'
     *  Sum: '<S46>/Sum'
     */
    rtb_Product4 = (((IPC4M_B.x[12] * IPC4M_B.x_d[10] - IPC4M_B.x[10] *
                      IPC4M_B.x_d[12]) - IPC4M_B.x[11] * IPC4M_B.x_d[13]) +
                    IPC4M_B.x[13] * IPC4M_B.x_d[11]) / rtb_Product3_eb;

    /* Product: '<S42>/Product3' incorporates:
     *  Product: '<S47>/Product'
     *  Product: '<S47>/Product1'
     *  Product: '<S47>/Product2'
     *  Product: '<S47>/Product3'
     *  Sum: '<S47>/Sum'
     */
    rtb_Product3_eb = (((IPC4M_B.x[11] * IPC4M_B.x_d[12] - IPC4M_B.x[10] *
                         IPC4M_B.x_d[13]) - IPC4M_B.x[12] * IPC4M_B.x_d[11]) +
                       IPC4M_B.x[13] * IPC4M_B.x_d[10]) / rtb_Product3_eb;

    /* SignalConversion: '<S19>/TmpSignal ConversionAtProduct4Inport2' incorporates:
     *  Sum: '<S19>/Add5'
     */
    tmp_1r[0] = IPC4M_B.x[7] - IPC4M_B.x_d[7];
    tmp_1r[1] = IPC4M_B.x[8] - IPC4M_B.x_d[8];
    tmp_1r[2] = IPC4M_B.x[9] - IPC4M_B.x_d[9];
    tmp_1r[3] = rtb_Product2_fj;
    tmp_1r[4] = rtb_Product4;
    tmp_1r[5] = rtb_Product3_eb;
    for (i = 0; i < 6; i++) {
      /* Product: '<S19>/Product3' incorporates:
       *  Constant: '<S19>/Inertia1'
       *  Sum: '<S19>/Add4'
       */
      tmp_1c[i] = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        tmp_1c[i] += IPC4M_P.Inertia1_Value[6 * i_1 + i] * rtb_Add[6 + i_1];
      }

      /* End of Product: '<S19>/Product3' */

      /* Product: '<S19>/Product4' incorporates:
       *  SignalConversion: '<S19>/TmpSignal ConversionAtProduct4Inport2'
       *  Sum: '<S19>/Add4'
       */
      rtb_K_h[i] = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        rtb_K_h[i] += rtb_K_i[6 * i_1 + i] * tmp_1r[i_1];
      }

      /* End of Product: '<S19>/Product4' */

      /* Sum: '<S19>/Add3' incorporates:
       *  Product: '<S19>/Product5'
       */
      tmp_1d[i] = IPC4M_B.Gdx_o[6 + i] - IPC4M_B.dxGdx_od[6 + i];
    }

    /* Sum: '<S19>/Add4' incorporates:
     *  Constant: '<S19>/Damping1'
     *  Product: '<S19>/Product5'
     */
    for (i = 0; i < 6; i++) {
      rtb_Product4 = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        rtb_Product4 += IPC4M_P.Damping1_Value[6 * i_1 + i] * tmp_1d[i_1];
      }

      IPC4M_B.Add4[i] = (tmp_1c[i] - rtb_K_h[i]) - rtb_Product4;
    }

    /* Sum: '<S50>/Sum' incorporates:
     *  Product: '<S50>/Product'
     *  Product: '<S50>/Product1'
     *  Product: '<S50>/Product2'
     *  Product: '<S50>/Product3'
     */
    rtb_Product3_eb = ((IPC4M_B.x_d[17] * IPC4M_B.x_d[17] + IPC4M_B.x_d[18] *
                        IPC4M_B.x_d[18]) + IPC4M_B.x_d[19] * IPC4M_B.x_d[19]) +
      IPC4M_B.x_d[20] * IPC4M_B.x_d[20];

    /* MATLAB Function: '<S20>/MATLAB Function2' incorporates:
     *  Product: '<S49>/Product1'
     *  Product: '<S51>/Product'
     *  Product: '<S51>/Product1'
     *  Product: '<S51>/Product2'
     *  Product: '<S51>/Product3'
     *  Sum: '<S51>/Sum'
     */
    /* MATLAB Function 'Impedance control/Manipulator3/MATLAB Function2': '<S48>:1' */
    /* '<S48>:1:2' */
    a_1 = (((IPC4M_B.x[17] * IPC4M_B.x_d[17] + IPC4M_B.x[18] * IPC4M_B.x_d[18])
            + IPC4M_B.x[19] * IPC4M_B.x_d[19]) + IPC4M_B.x[20] * IPC4M_B.x_d[20])
      / rtb_Product3_eb * 2.0 * IPC4M_P.kappa3;
    memset(&rtb_K_i[0], 0, 36U * sizeof(real_T));
    for (i = 0; i < 3; i++) {
      rtb_K_i[6 * i] = (real_T)b_1[3 * i] * IPC4M_P.k3;
      rtb_K_i[1 + 6 * i] = (real_T)b_1[3 * i + 1] * IPC4M_P.k3;
      rtb_K_i[2 + 6 * i] = (real_T)b_1[3 * i + 2] * IPC4M_P.k3;
    }

    for (i = 0; i < 3; i++) {
      rtb_K_i[3 + 6 * (3 + i)] = (real_T)b_1[3 * i] * a_1;
      rtb_K_i[4 + 6 * (3 + i)] = (real_T)b_1[3 * i + 1] * a_1;
      rtb_K_i[5 + 6 * (3 + i)] = (real_T)b_1[3 * i + 2] * a_1;
    }

    /* End of MATLAB Function: '<S20>/MATLAB Function2' */

    /* Product: '<S49>/Product2' incorporates:
     *  Product: '<S52>/Product'
     *  Product: '<S52>/Product1'
     *  Product: '<S52>/Product2'
     *  Product: '<S52>/Product3'
     *  Sum: '<S52>/Sum'
     */
    rtb_Product2_fj = (((IPC4M_B.x[18] * IPC4M_B.x_d[17] - IPC4M_B.x[17] *
                         IPC4M_B.x_d[18]) + IPC4M_B.x[19] * IPC4M_B.x_d[20]) -
                       IPC4M_B.x[20] * IPC4M_B.x_d[19]) / rtb_Product3_eb;

    /* Product: '<S49>/Product4' incorporates:
     *  Product: '<S53>/Product'
     *  Product: '<S53>/Product1'
     *  Product: '<S53>/Product2'
     *  Product: '<S53>/Product3'
     *  Sum: '<S53>/Sum'
     */
    rtb_Product4 = (((IPC4M_B.x[19] * IPC4M_B.x_d[17] - IPC4M_B.x[17] *
                      IPC4M_B.x_d[19]) - IPC4M_B.x[18] * IPC4M_B.x_d[20]) +
                    IPC4M_B.x[20] * IPC4M_B.x_d[18]) / rtb_Product3_eb;

    /* Product: '<S49>/Product3' incorporates:
     *  Product: '<S54>/Product'
     *  Product: '<S54>/Product1'
     *  Product: '<S54>/Product2'
     *  Product: '<S54>/Product3'
     *  Sum: '<S54>/Sum'
     */
    rtb_Product3_eb = (((IPC4M_B.x[18] * IPC4M_B.x_d[19] - IPC4M_B.x[17] *
                         IPC4M_B.x_d[20]) - IPC4M_B.x[19] * IPC4M_B.x_d[18]) +
                       IPC4M_B.x[20] * IPC4M_B.x_d[17]) / rtb_Product3_eb;

    /* SignalConversion: '<S20>/TmpSignal ConversionAtProduct7Inport2' incorporates:
     *  Sum: '<S20>/Add8'
     */
    tmp_1s[0] = IPC4M_B.x[14] - IPC4M_B.x_d[14];
    tmp_1s[1] = IPC4M_B.x[15] - IPC4M_B.x_d[15];
    tmp_1s[2] = IPC4M_B.x[16] - IPC4M_B.x_d[16];
    tmp_1s[3] = rtb_Product2_fj;
    tmp_1s[4] = rtb_Product4;
    tmp_1s[5] = rtb_Product3_eb;
    for (i = 0; i < 6; i++) {
      /* Product: '<S20>/Product6' incorporates:
       *  Constant: '<S20>/Inertia2'
       *  Sum: '<S20>/Add7'
       */
      tmp_1c[i] = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        tmp_1c[i] += IPC4M_P.Inertia2_Value[6 * i_1 + i] * rtb_Add[12 + i_1];
      }

      /* End of Product: '<S20>/Product6' */

      /* Product: '<S20>/Product7' incorporates:
       *  SignalConversion: '<S20>/TmpSignal ConversionAtProduct7Inport2'
       *  Sum: '<S20>/Add7'
       */
      rtb_K_h[i] = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        rtb_K_h[i] += rtb_K_i[6 * i_1 + i] * tmp_1s[i_1];
      }

      /* End of Product: '<S20>/Product7' */

      /* Sum: '<S20>/Add6' incorporates:
       *  Product: '<S20>/Product8'
       */
      tmp_1d[i] = IPC4M_B.Gdx_o[12 + i] - IPC4M_B.dxGdx_od[12 + i];
    }

    /* Sum: '<S20>/Add7' incorporates:
     *  Constant: '<S20>/Damping2'
     *  Product: '<S20>/Product8'
     */
    for (i = 0; i < 6; i++) {
      rtb_Product4 = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        rtb_Product4 += IPC4M_P.Damping2_Value[6 * i_1 + i] * tmp_1d[i_1];
      }

      IPC4M_B.Add7[i] = (tmp_1c[i] - rtb_K_h[i]) - rtb_Product4;
    }

    /* Sum: '<S57>/Sum' incorporates:
     *  Product: '<S57>/Product'
     *  Product: '<S57>/Product1'
     *  Product: '<S57>/Product2'
     *  Product: '<S57>/Product3'
     */
    rtb_Product3_eb = ((IPC4M_B.x_d[24] * IPC4M_B.x_d[24] + IPC4M_B.x_d[25] *
                        IPC4M_B.x_d[25]) + IPC4M_B.x_d[26] * IPC4M_B.x_d[26]) +
      IPC4M_B.x_d[27] * IPC4M_B.x_d[27];

    /* MATLAB Function: '<S21>/MATLAB Function3' incorporates:
     *  Product: '<S56>/Product1'
     *  Product: '<S58>/Product'
     *  Product: '<S58>/Product1'
     *  Product: '<S58>/Product2'
     *  Product: '<S58>/Product3'
     *  Sum: '<S58>/Sum'
     */
    /* MATLAB Function 'Impedance control/Manipulator4/MATLAB Function3': '<S55>:1' */
    /* '<S55>:1:2' */
    a_1 = (((IPC4M_B.x[24] * IPC4M_B.x_d[24] + IPC4M_B.x[25] * IPC4M_B.x_d[25])
            + IPC4M_B.x[26] * IPC4M_B.x_d[26]) + IPC4M_B.x[27] * IPC4M_B.x_d[27])
      / rtb_Product3_eb * 2.0 * IPC4M_P.kappa4;
    memset(&rtb_K_i[0], 0, 36U * sizeof(real_T));
    for (i = 0; i < 3; i++) {
      rtb_K_i[6 * i] = (real_T)b_2[3 * i] * IPC4M_P.k4;
      rtb_K_i[1 + 6 * i] = (real_T)b_2[3 * i + 1] * IPC4M_P.k4;
      rtb_K_i[2 + 6 * i] = (real_T)b_2[3 * i + 2] * IPC4M_P.k4;
    }

    for (i = 0; i < 3; i++) {
      rtb_K_i[3 + 6 * (3 + i)] = (real_T)b_2[3 * i] * a_1;
      rtb_K_i[4 + 6 * (3 + i)] = (real_T)b_2[3 * i + 1] * a_1;
      rtb_K_i[5 + 6 * (3 + i)] = (real_T)b_2[3 * i + 2] * a_1;
    }

    /* End of MATLAB Function: '<S21>/MATLAB Function3' */

    /* Product: '<S56>/Product2' incorporates:
     *  Product: '<S59>/Product'
     *  Product: '<S59>/Product1'
     *  Product: '<S59>/Product2'
     *  Product: '<S59>/Product3'
     *  Sum: '<S59>/Sum'
     */
    rtb_Product2_fj = (((IPC4M_B.x[25] * IPC4M_B.x_d[24] - IPC4M_B.x[24] *
                         IPC4M_B.x_d[25]) + IPC4M_B.x[26] * IPC4M_B.x_d[27]) -
                       IPC4M_B.x[27] * IPC4M_B.x_d[26]) / rtb_Product3_eb;

    /* Product: '<S56>/Product4' incorporates:
     *  Product: '<S60>/Product'
     *  Product: '<S60>/Product1'
     *  Product: '<S60>/Product2'
     *  Product: '<S60>/Product3'
     *  Sum: '<S60>/Sum'
     */
    rtb_Product4 = (((IPC4M_B.x[26] * IPC4M_B.x_d[24] - IPC4M_B.x[24] *
                      IPC4M_B.x_d[26]) - IPC4M_B.x[25] * IPC4M_B.x_d[27]) +
                    IPC4M_B.x[27] * IPC4M_B.x_d[25]) / rtb_Product3_eb;

    /* Product: '<S56>/Product3' incorporates:
     *  Product: '<S61>/Product'
     *  Product: '<S61>/Product1'
     *  Product: '<S61>/Product2'
     *  Product: '<S61>/Product3'
     *  Sum: '<S61>/Sum'
     */
    rtb_Product3_eb = (((IPC4M_B.x[25] * IPC4M_B.x_d[26] - IPC4M_B.x[24] *
                         IPC4M_B.x_d[27]) - IPC4M_B.x[26] * IPC4M_B.x_d[25]) +
                       IPC4M_B.x[27] * IPC4M_B.x_d[24]) / rtb_Product3_eb;

    /* SignalConversion: '<S21>/TmpSignal ConversionAtProduct10Inport2' incorporates:
     *  Sum: '<S21>/Add11'
     */
    tmp_1t[0] = IPC4M_B.x[21] - IPC4M_B.x_d[21];
    tmp_1t[1] = IPC4M_B.x[22] - IPC4M_B.x_d[22];
    tmp_1t[2] = IPC4M_B.x[23] - IPC4M_B.x_d[23];
    tmp_1t[3] = rtb_Product2_fj;
    tmp_1t[4] = rtb_Product4;
    tmp_1t[5] = rtb_Product3_eb;
    for (i = 0; i < 6; i++) {
      /* Product: '<S21>/Product9' incorporates:
       *  Constant: '<S21>/Inertia3'
       *  Sum: '<S21>/Add10'
       */
      tmp_1c[i] = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        tmp_1c[i] += IPC4M_P.Inertia3_Value[6 * i_1 + i] * rtb_Add[18 + i_1];
      }

      /* End of Product: '<S21>/Product9' */

      /* Product: '<S21>/Product10' incorporates:
       *  SignalConversion: '<S21>/TmpSignal ConversionAtProduct10Inport2'
       *  Sum: '<S21>/Add10'
       */
      rtb_K_h[i] = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        rtb_K_h[i] += rtb_K_i[6 * i_1 + i] * tmp_1t[i_1];
      }

      /* End of Product: '<S21>/Product10' */

      /* Sum: '<S21>/Add9' incorporates:
       *  Product: '<S21>/Product11'
       */
      tmp_1d[i] = IPC4M_B.Gdx_o[18 + i] - IPC4M_B.dxGdx_od[18 + i];
    }

    /* Sum: '<S21>/Add10' incorporates:
     *  Constant: '<S21>/Damping3'
     *  Product: '<S21>/Product11'
     */
    for (i = 0; i < 6; i++) {
      rtb_Product4 = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        rtb_Product4 += IPC4M_P.Damping3_Value[6 * i_1 + i] * tmp_1d[i_1];
      }

      IPC4M_B.Add10[i] = (tmp_1c[i] - rtb_K_h[i]) - rtb_Product4;
    }

    if (rtmIsMajorTimeStep(IPC4M_M)) {
      /* Sqrt: '<S9>/Sqrt' incorporates:
       *  Constant: '<S9>/Inertia'
       */
      for (i = 0; i < 576; i++) {
        IPC4M_B.Sqrt[i] = sqrt(IPC4M_P.Inertia_Value_h[i]);
      }

      /* End of Sqrt: '<S9>/Sqrt' */
    }

    /* MATLAB Function: '<S9>/Reduced Constraint Matrix' */
    /* MATLAB Function 'Manipulator dynamics/Reduced Constraint Matrix': '<S78>:1' */
    /* x_o = [eye(3) zeros(3,4) eye(3) zeros(3,4) eye(3) zeros(3,4) eye(3) zeros(3,4)] * x; */
    /* '<S78>:1:3' */
    for (i = 0; i < 9; i++) {
      I[i] = 0;
      b_I[i] = 0;
      c_I[i] = 0;
      d_I[i] = 0;
      e_I[i] = 0;
      f_I[i] = 0;
      g_I[i] = 0;
      h_I[i] = 0;
      i_I[i] = 0;
      j_I[i] = 0;
      k_I[i] = 0;
      l_I[i] = 0;
    }

    I[0] = 1;
    I[4] = 1;
    I[8] = 1;

    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    q[0] = IPC4M_B.x[3];
    q[1] = -IPC4M_B.x[4];
    q[2] = -IPC4M_B.x[5];
    q[3] = -IPC4M_B.x[6];
    tmp_u[0] = 0.0;
    tmp_u[1] = IPC4M_P.r[3] - IPC4M_P.r[0];
    tmp_u[2] = IPC4M_P.r[4] - IPC4M_P.r[1];
    tmp_u[3] = IPC4M_P.r[5] - IPC4M_P.r[2];
    IPC4M_quatmultiply_i(tmp_u, q, tmp_17);
    IPC4M_quatmultiply_i(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, tmp_18);

    /* generates skew- symmetric matrix from vector */
    b_I[0] = 1;
    b_I[4] = 1;
    b_I[8] = 1;
    c_I[0] = 1;
    c_I[4] = 1;
    c_I[8] = 1;
    d_I[0] = 1;
    d_I[4] = 1;
    d_I[8] = 1;
    e_I[0] = 1;
    e_I[4] = 1;
    e_I[8] = 1;

    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    q[0] = IPC4M_B.x[3];
    q[1] = -IPC4M_B.x[4];
    q[2] = -IPC4M_B.x[5];
    q[3] = -IPC4M_B.x[6];
    tmp_t[0] = 0.0;
    tmp_t[1] = IPC4M_P.r[6] - IPC4M_P.r[0];
    tmp_t[2] = IPC4M_P.r[7] - IPC4M_P.r[1];
    tmp_t[3] = IPC4M_P.r[8] - IPC4M_P.r[2];
    IPC4M_quatmultiply_i(tmp_t, q, tmp_17);
    IPC4M_quatmultiply_i(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, tmp_19);

    /* generates skew- symmetric matrix from vector */
    f_I[0] = 1;
    f_I[4] = 1;
    f_I[8] = 1;
    g_I[0] = 1;
    g_I[4] = 1;
    g_I[8] = 1;
    h_I[0] = 1;
    h_I[4] = 1;
    h_I[8] = 1;
    i_I[0] = 1;
    i_I[4] = 1;
    i_I[8] = 1;

    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    q[0] = IPC4M_B.x[3];
    q[1] = -IPC4M_B.x[4];
    q[2] = -IPC4M_B.x[5];
    q[3] = -IPC4M_B.x[6];
    tmp_s[0] = 0.0;
    tmp_s[1] = IPC4M_P.r[9] - IPC4M_P.r[0];
    tmp_s[2] = IPC4M_P.r[10] - IPC4M_P.r[1];
    tmp_s[3] = IPC4M_P.r[11] - IPC4M_P.r[2];
    IPC4M_quatmultiply_i(tmp_s, q, tmp_17);
    IPC4M_quatmultiply_i(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, q);

    /* generates skew- symmetric matrix from vector */
    j_I[0] = 1;
    j_I[4] = 1;
    j_I[8] = 1;
    k_I[0] = 1;
    k_I[4] = 1;
    k_I[8] = 1;
    l_I[0] = 1;
    l_I[4] = 1;
    l_I[8] = 1;
    for (i = 0; i < 3; i++) {
      rtb_Ared_b[18 * i] = -(real_T)I[3 * i];
      rtb_Ared_b[1 + 18 * i] = -(real_T)I[3 * i + 1];
      rtb_Ared_b[2 + 18 * i] = -(real_T)I[3 * i + 2];
    }

    rtb_Ared_b[54] = 0.0;
    rtb_Ared_b[72] = -tmp_18[3];
    rtb_Ared_b[90] = tmp_18[2];
    rtb_Ared_b[55] = tmp_18[3];
    rtb_Ared_b[73] = 0.0;
    rtb_Ared_b[91] = -tmp_18[1];
    rtb_Ared_b[56] = -tmp_18[2];
    rtb_Ared_b[74] = tmp_18[1];
    rtb_Ared_b[92] = 0.0;
    for (i = 0; i < 3; i++) {
      rtb_Ared_b[18 * (i + 6)] = b_I[3 * i];
      rtb_Ared_b[1 + 18 * (i + 6)] = b_I[3 * i + 1];
      rtb_Ared_b[2 + 18 * (i + 6)] = b_I[3 * i + 2];
    }

    for (i = 0; i < 15; i++) {
      rtb_Ared_b[18 * (i + 9)] = 0.0;
      rtb_Ared_b[1 + 18 * (i + 9)] = 0.0;
      rtb_Ared_b[2 + 18 * (i + 9)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_Ared_b[3 + 18 * i] = 0.0;
      rtb_Ared_b[4 + 18 * i] = 0.0;
      rtb_Ared_b[5 + 18 * i] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_Ared_b[3 + 18 * (i + 3)] = -(real_T)c_I[3 * i];
      rtb_Ared_b[4 + 18 * (i + 3)] = -(real_T)c_I[3 * i + 1];
      rtb_Ared_b[5 + 18 * (i + 3)] = -(real_T)c_I[3 * i + 2];
    }

    for (i = 0; i < 3; i++) {
      rtb_Ared_b[3 + 18 * (i + 6)] = 0.0;
      rtb_Ared_b[4 + 18 * (i + 6)] = 0.0;
      rtb_Ared_b[5 + 18 * (i + 6)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_Ared_b[3 + 18 * (i + 9)] = d_I[3 * i];
      rtb_Ared_b[4 + 18 * (i + 9)] = d_I[3 * i + 1];
      rtb_Ared_b[5 + 18 * (i + 9)] = d_I[3 * i + 2];
    }

    for (i = 0; i < 12; i++) {
      rtb_Ared_b[3 + 18 * (i + 12)] = 0.0;
      rtb_Ared_b[4 + 18 * (i + 12)] = 0.0;
      rtb_Ared_b[5 + 18 * (i + 12)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_Ared_b[6 + 18 * i] = -(real_T)e_I[3 * i];
      rtb_Ared_b[7 + 18 * i] = -(real_T)e_I[3 * i + 1];
      rtb_Ared_b[8 + 18 * i] = -(real_T)e_I[3 * i + 2];
    }

    rtb_Ared_b[60] = 0.0;
    rtb_Ared_b[78] = -tmp_19[3];
    rtb_Ared_b[96] = tmp_19[2];
    rtb_Ared_b[61] = tmp_19[3];
    rtb_Ared_b[79] = 0.0;
    rtb_Ared_b[97] = -tmp_19[1];
    rtb_Ared_b[62] = -tmp_19[2];
    rtb_Ared_b[80] = tmp_19[1];
    rtb_Ared_b[98] = 0.0;
    for (i = 0; i < 6; i++) {
      rtb_Ared_b[6 + 18 * (i + 6)] = 0.0;
      rtb_Ared_b[7 + 18 * (i + 6)] = 0.0;
      rtb_Ared_b[8 + 18 * (i + 6)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_Ared_b[6 + 18 * (i + 12)] = f_I[3 * i];
      rtb_Ared_b[7 + 18 * (i + 12)] = f_I[3 * i + 1];
      rtb_Ared_b[8 + 18 * (i + 12)] = f_I[3 * i + 2];
    }

    for (i = 0; i < 9; i++) {
      rtb_Ared_b[6 + 18 * (i + 15)] = 0.0;
      rtb_Ared_b[7 + 18 * (i + 15)] = 0.0;
      rtb_Ared_b[8 + 18 * (i + 15)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_Ared_b[9 + 18 * i] = 0.0;
      rtb_Ared_b[10 + 18 * i] = 0.0;
      rtb_Ared_b[11 + 18 * i] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_Ared_b[9 + 18 * (i + 3)] = -(real_T)g_I[3 * i];
      rtb_Ared_b[10 + 18 * (i + 3)] = -(real_T)g_I[3 * i + 1];
      rtb_Ared_b[11 + 18 * (i + 3)] = -(real_T)g_I[3 * i + 2];
    }

    for (i = 0; i < 9; i++) {
      rtb_Ared_b[9 + 18 * (i + 6)] = 0.0;
      rtb_Ared_b[10 + 18 * (i + 6)] = 0.0;
      rtb_Ared_b[11 + 18 * (i + 6)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_Ared_b[9 + 18 * (i + 15)] = h_I[3 * i];
      rtb_Ared_b[10 + 18 * (i + 15)] = h_I[3 * i + 1];
      rtb_Ared_b[11 + 18 * (i + 15)] = h_I[3 * i + 2];
    }

    for (i = 0; i < 6; i++) {
      rtb_Ared_b[9 + 18 * (i + 18)] = 0.0;
      rtb_Ared_b[10 + 18 * (i + 18)] = 0.0;
      rtb_Ared_b[11 + 18 * (i + 18)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_Ared_b[12 + 18 * i] = -(real_T)i_I[3 * i];
      rtb_Ared_b[13 + 18 * i] = -(real_T)i_I[3 * i + 1];
      rtb_Ared_b[14 + 18 * i] = -(real_T)i_I[3 * i + 2];
    }

    rtb_Ared_b[66] = 0.0;
    rtb_Ared_b[84] = -q[3];
    rtb_Ared_b[102] = q[2];
    rtb_Ared_b[67] = q[3];
    rtb_Ared_b[85] = 0.0;
    rtb_Ared_b[103] = -q[1];
    rtb_Ared_b[68] = -q[2];
    rtb_Ared_b[86] = q[1];
    rtb_Ared_b[104] = 0.0;
    for (i = 0; i < 12; i++) {
      rtb_Ared_b[12 + 18 * (i + 6)] = 0.0;
      rtb_Ared_b[13 + 18 * (i + 6)] = 0.0;
      rtb_Ared_b[14 + 18 * (i + 6)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_Ared_b[12 + 18 * (i + 18)] = j_I[3 * i];
      rtb_Ared_b[13 + 18 * (i + 18)] = j_I[3 * i + 1];
      rtb_Ared_b[14 + 18 * (i + 18)] = j_I[3 * i + 2];
    }

    for (i = 0; i < 3; i++) {
      rtb_Ared_b[12 + 18 * (i + 21)] = 0.0;
      rtb_Ared_b[13 + 18 * (i + 21)] = 0.0;
      rtb_Ared_b[14 + 18 * (i + 21)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_Ared_b[15 + 18 * i] = 0.0;
      rtb_Ared_b[16 + 18 * i] = 0.0;
      rtb_Ared_b[17 + 18 * i] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_Ared_b[15 + 18 * (i + 3)] = -(real_T)k_I[3 * i];
      rtb_Ared_b[16 + 18 * (i + 3)] = -(real_T)k_I[3 * i + 1];
      rtb_Ared_b[17 + 18 * (i + 3)] = -(real_T)k_I[3 * i + 2];
    }

    for (i = 0; i < 15; i++) {
      rtb_Ared_b[15 + 18 * (i + 6)] = 0.0;
      rtb_Ared_b[16 + 18 * (i + 6)] = 0.0;
      rtb_Ared_b[17 + 18 * (i + 6)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_Ared_b[15 + 18 * (i + 21)] = l_I[3 * i];
      rtb_Ared_b[16 + 18 * (i + 21)] = l_I[3 * i + 1];
      rtb_Ared_b[17 + 18 * (i + 21)] = l_I[3 * i + 2];
    }

    /* End of MATLAB Function: '<S9>/Reduced Constraint Matrix' */

    /* Product: '<S9>/Mult1' */
    /*  Ared = [-eye(3) skew_sm(quatrot(x(4:7),x(8:10)-x(1:3))) eye(3) zeros(3,15); */
    /*          zeros(3) -eye(3) zeros(3) eye(3) zeros(3,12); */
    /*          -eye(3) skew_sm(quatrot(x(4:7),x(15:17)-x(1:3))) zeros(3,6) eye(3) zeros(3,9); */
    /*          zeros(3) -eye(3) zeros(3,9) eye(3) zeros(3,6); */
    /*          -eye(3) skew_sm(quatrot(x(4:7),x(22:24)-x(1:3))) zeros(3,12) eye(3) zeros(3); */
    /*          zeros(3) -eye(3) zeros(3,15) eye(3)]; */
    /* Copy input to temporary space */
    rt_mrdivide_U1d18x24_U_TXABSG_n(rtb_Ared_b, IPC4M_B.Sqrt, I_0);

    /* S-Function (sdsppinv): '<S9>/Pseudoinverse' */
    memcpy(&Pseudoinverse_X[0], &I_0[0], 432U * sizeof(real_T));

    /* Call SVD */
    i = MWDSP_SVD_D(&Pseudoinverse_X[0U], 18, 24, &Pseudoinverse_S[0U],
                    &Pseudoinverse_E[0U], &Pseudoinverse_WORK[0U],
                    &Pseudoinverse_U[0U], &IPC4M_DW.Pseudoinverse_V[0U], 1);

    /* Only call 'pinv' function if SVD succeeded */
    if (i == 0) {
      MWDSPCG_Pseudoinverse_D(&Pseudoinverse_S[0U], &Pseudoinverse_U[0U],
        &IPC4M_DW.Pseudoinverse_V[0U], &rtb_Pseudoinverse[0U], 18, 24);
    }

    /* End of S-Function (sdsppinv): '<S9>/Pseudoinverse' */

    /* MATLAB Function: '<S2>/ConnectingDamping' */
    /* MATLAB Function 'Connecting Spring/ConnectingDamping': '<S16>:1' */
    /* '<S16>:1:4' */
    /* '<S16>:1:5' */
    /* '<S16>:1:6' */
    for (i = 0; i < 3; i++) {
      c_a_1[i] = 0.0;
      for (i_1 = 0; i_1 < 24; i_1++) {
        c_a_1[i] += (real_T)c_a[3 * i_1 + i] * IPC4M_B.Gdx_o[i_1];
      }
    }

    tmp_1u[0] = IPC4M_B.Gdx_o[0];
    tmp_1u[1] = IPC4M_B.Gdx_o[1];
    tmp_1u[2] = IPC4M_B.Gdx_o[2];
    tmp_1u[3] = IPC4M_B.Gdx_o[6];
    tmp_1u[4] = IPC4M_B.Gdx_o[7];
    tmp_1u[5] = IPC4M_B.Gdx_o[8];
    tmp_1u[6] = IPC4M_B.Gdx_o[12];
    tmp_1u[7] = IPC4M_B.Gdx_o[13];
    tmp_1u[8] = IPC4M_B.Gdx_o[14];
    tmp_1u[9] = IPC4M_B.Gdx_o[18];
    tmp_1u[10] = IPC4M_B.Gdx_o[19];
    tmp_1u[11] = IPC4M_B.Gdx_o[20];
    for (i = 0; i < 12; i++) {
      deltav[i] = tmp_1u[i] - ((real_T)b_a[i + 24] * c_a_1[2] + ((real_T)b_a[i +
        12] * c_a_1[1] + (real_T)b_a[i] * c_a_1[0]));
    }

    /* '<S16>:1:7' */
    /* '<S16>:1:11' */
    deltav_0[0] = deltav[0];
    deltav_0[1] = deltav[1];
    deltav_0[2] = deltav[2];
    deltav_0[3] = deltav[3];
    deltav_0[4] = deltav[4];
    deltav_0[5] = deltav[5];
    deltav_0[6] = deltav[6];
    deltav_0[7] = deltav[7];
    deltav_0[8] = deltav[8];
    deltav_0[9] = deltav[9];
    deltav_0[10] = deltav[10];
    deltav_0[11] = deltav[11];
    for (i = 0; i < 12; i++) {
      tmp_1u[i] = IPC4M_P.Dc * deltav_0[i];
    }

    for (i = 0; i < 12; i++) {
      f_con[i] = 0.0;
      for (i_1 = 0; i_1 < 12; i_1++) {
        f_con[i] += a_3[12 * i_1 + i] * tmp_1u[i_1];
      }
    }

    /* '<S16>:1:12' */
    IPC4M_B.h_con_g[0] = f_con[0];
    IPC4M_B.h_con_g[1] = f_con[1];
    IPC4M_B.h_con_g[2] = f_con[2];
    IPC4M_B.h_con_g[3] = 0.0;
    IPC4M_B.h_con_g[4] = 0.0;
    IPC4M_B.h_con_g[5] = 0.0;
    IPC4M_B.h_con_g[6] = f_con[3];
    IPC4M_B.h_con_g[7] = f_con[4];
    IPC4M_B.h_con_g[8] = f_con[5];
    IPC4M_B.h_con_g[9] = 0.0;
    IPC4M_B.h_con_g[10] = 0.0;
    IPC4M_B.h_con_g[11] = 0.0;
    IPC4M_B.h_con_g[12] = f_con[6];
    IPC4M_B.h_con_g[13] = f_con[7];
    IPC4M_B.h_con_g[14] = f_con[8];
    IPC4M_B.h_con_g[15] = 0.0;
    IPC4M_B.h_con_g[16] = 0.0;
    IPC4M_B.h_con_g[17] = 0.0;
    IPC4M_B.h_con_g[18] = f_con[9];
    IPC4M_B.h_con_g[19] = f_con[10];
    IPC4M_B.h_con_g[20] = f_con[11];
    IPC4M_B.h_con_g[21] = 0.0;
    IPC4M_B.h_con_g[22] = 0.0;
    IPC4M_B.h_con_g[23] = 0.0;

    /* End of MATLAB Function: '<S2>/ConnectingDamping' */

    /* MATLAB Function: '<S2>/ConnectingStiffness' */
    /* MATLAB Function 'Connecting Spring/ConnectingStiffness': '<S17>:1' */
    /* '<S17>:1:4' */
    /* '<S17>:1:5' */
    /* '<S17>:1:6' */
    for (i = 0; i < 3; i++) {
      c_a_1[i] = 0.0;
      for (i_1 = 0; i_1 < 28; i_1++) {
        c_a_1[i] += (real_T)c_a_0[3 * i_1 + i] * IPC4M_B.x[i_1];
      }
    }

    tmp_1v[0] = IPC4M_B.x[0];
    tmp_1v[1] = IPC4M_B.x[1];
    tmp_1v[2] = IPC4M_B.x[2];
    tmp_1v[3] = IPC4M_B.x[7];
    tmp_1v[4] = IPC4M_B.x[8];
    tmp_1v[5] = IPC4M_B.x[9];
    tmp_1v[6] = IPC4M_B.x[14];
    tmp_1v[7] = IPC4M_B.x[15];
    tmp_1v[8] = IPC4M_B.x[16];
    tmp_1v[9] = IPC4M_B.x[21];
    tmp_1v[10] = IPC4M_B.x[22];
    tmp_1v[11] = IPC4M_B.x[23];
    for (i = 0; i < 12; i++) {
      deltav[i] = tmp_1v[i] - ((real_T)b_a_0[i + 24] * c_a_1[2] + ((real_T)
        b_a_0[i + 12] * c_a_1[1] + (real_T)b_a_0[i] * c_a_1[0]));
    }

    /* '<S17>:1:7' */
    rtb_Product4 = (IPC4M_norm(*(real_T (*)[3])&deltav[0]) - IPC4M_P.l[0]) /
      IPC4M_norm(*(real_T (*)[3])&deltav[0]);
    rtb_Product3_eb = (IPC4M_norm(*(real_T (*)[3])&deltav[3]) - IPC4M_P.l[1]) /
      IPC4M_norm(*(real_T (*)[3])&deltav[3]);
    rtb_Product2_fj = (IPC4M_norm(*(real_T (*)[3])&deltav[6]) - IPC4M_P.l[2]) /
      IPC4M_norm(*(real_T (*)[3])&deltav[6]);
    a_1 = (IPC4M_norm(*(real_T (*)[3])&deltav[9]) - IPC4M_P.l[3]) / IPC4M_norm
      (*(real_T (*)[3])&deltav[9]);

    /* '<S17>:1:11' */
    rtb_Product4_0[0] = rtb_Product4 * deltav[0];
    rtb_Product4_0[1] = rtb_Product4 * deltav[1];
    rtb_Product4_0[2] = rtb_Product4 * deltav[2];
    rtb_Product4_0[3] = rtb_Product3_eb * deltav[3];
    rtb_Product4_0[4] = rtb_Product3_eb * deltav[4];
    rtb_Product4_0[5] = rtb_Product3_eb * deltav[5];
    rtb_Product4_0[6] = rtb_Product2_fj * deltav[6];
    rtb_Product4_0[7] = rtb_Product2_fj * deltav[7];
    rtb_Product4_0[8] = rtb_Product2_fj * deltav[8];
    rtb_Product4_0[9] = a_1 * deltav[9];
    rtb_Product4_0[10] = a_1 * deltav[10];
    rtb_Product4_0[11] = a_1 * deltav[11];
    for (i = 0; i < 12; i++) {
      tmp_1u[i] = IPC4M_P.Kc * rtb_Product4_0[i];
    }

    for (i = 0; i < 12; i++) {
      f_con[i] = 0.0;
      for (i_1 = 0; i_1 < 12; i_1++) {
        f_con[i] += a_4[12 * i_1 + i] * tmp_1u[i_1];
      }
    }

    /* '<S17>:1:12' */
    IPC4M_B.h_con[0] = f_con[0];
    IPC4M_B.h_con[1] = f_con[1];
    IPC4M_B.h_con[2] = f_con[2];
    IPC4M_B.h_con[3] = 0.0;
    IPC4M_B.h_con[4] = 0.0;
    IPC4M_B.h_con[5] = 0.0;
    IPC4M_B.h_con[6] = f_con[3];
    IPC4M_B.h_con[7] = f_con[4];
    IPC4M_B.h_con[8] = f_con[5];
    IPC4M_B.h_con[9] = 0.0;
    IPC4M_B.h_con[10] = 0.0;
    IPC4M_B.h_con[11] = 0.0;
    IPC4M_B.h_con[12] = f_con[6];
    IPC4M_B.h_con[13] = f_con[7];
    IPC4M_B.h_con[14] = f_con[8];
    IPC4M_B.h_con[15] = 0.0;
    IPC4M_B.h_con[16] = 0.0;
    IPC4M_B.h_con[17] = 0.0;
    IPC4M_B.h_con[18] = f_con[9];
    IPC4M_B.h_con[19] = f_con[10];
    IPC4M_B.h_con[20] = f_con[11];
    IPC4M_B.h_con[21] = 0.0;
    IPC4M_B.h_con[22] = 0.0;
    IPC4M_B.h_con[23] = 0.0;

    /* End of MATLAB Function: '<S2>/ConnectingStiffness' */

    /* Sum: '<S2>/Add' */
    for (i = 0; i < 24; i++) {
      IPC4M_B.Add[i] = IPC4M_B.h_con[i] - IPC4M_B.h_con_g[i];
    }

    /* End of Sum: '<S2>/Add' */

    /* Sum: '<Root>/Add' */
    for (i = 0; i < 6; i++) {
      rtb_Add[i] = IPC4M_B.Add1[i] + IPC4M_B.Add[i];
    }

    for (i = 0; i < 6; i++) {
      rtb_Add[i + 6] = IPC4M_B.Add[i + 6] + IPC4M_B.Add4[i];
    }

    for (i = 0; i < 6; i++) {
      rtb_Add[i + 12] = IPC4M_B.Add[i + 12] + IPC4M_B.Add7[i];
    }

    for (i = 0; i < 6; i++) {
      rtb_Add[i + 18] = IPC4M_B.Add[i + 18] + IPC4M_B.Add10[i];
    }

    /* End of Sum: '<Root>/Add' */

    /* MATLAB Function: '<S9>/Centripal Force' */
    /* MATLAB Function 'Manipulator dynamics/Centripal Force': '<S77>:1' */
    /* '<S77>:1:2' */
    /* generates skew- symmetric matrix from vector */
    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    q[0] = IPC4M_B.x[3];
    q[1] = -IPC4M_B.x[4];
    q[2] = -IPC4M_B.x[5];
    q[3] = -IPC4M_B.x[6];

    /* generates skew- symmetric matrix from vector */
    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    b_q[0] = IPC4M_B.x[3];
    b_q[1] = -IPC4M_B.x[4];
    b_q[2] = -IPC4M_B.x[5];
    b_q[3] = -IPC4M_B.x[6];

    /* generates skew- symmetric matrix from vector */
    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    c_q[0] = IPC4M_B.x[3];
    c_q[1] = -IPC4M_B.x[4];
    c_q[2] = -IPC4M_B.x[5];
    c_q[3] = -IPC4M_B.x[6];
    tmp_r[0] = 0.0;
    tmp_r[1] = IPC4M_P.r[6] - IPC4M_P.r[0];
    tmp_r[2] = IPC4M_P.r[7] - IPC4M_P.r[1];
    tmp_r[3] = IPC4M_P.r[8] - IPC4M_P.r[2];
    IPC4M_quatmultiply_n3(tmp_r, b_q, tmp_17);
    IPC4M_quatmultiply_n3(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, b_q);

    /*      bred = [skew_sm(dx(4:6))*skew_sm(dx(4:6))*quatrot(x(4:7),(x(8:10)-x(1:3))); */
    /*          zeros(3,1); */
    /*          skew_sm(dx(4:6))*skew_sm(dx(4:6))*quatrot(x(4:7),(x(15:17)-x(1:3))); */
    /*          zeros(3,1); */
    /*          skew_sm(dx(4:6))*skew_sm(dx(4:6))*quatrot(x(4:7),(x(22:24)-x(1:3))); */
    /*          zeros(3,1)]; */
    tmp_p[0] = 0.0;
    tmp_p[1] = IPC4M_P.r[3] - IPC4M_P.r[0];
    tmp_p[2] = IPC4M_P.r[4] - IPC4M_P.r[1];
    tmp_p[3] = IPC4M_P.r[5] - IPC4M_P.r[2];
    IPC4M_quatmultiply_n3(tmp_p, q, tmp_17);
    IPC4M_quatmultiply_n3(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, tmp_18);
    tmp_q[0] = 0.0;
    tmp_q[1] = IPC4M_P.r[9] - IPC4M_P.r[0];
    tmp_q[2] = IPC4M_P.r[10] - IPC4M_P.r[1];
    tmp_q[3] = IPC4M_P.r[11] - IPC4M_P.r[2];
    IPC4M_quatmultiply_n3(tmp_q, c_q, tmp_17);
    IPC4M_quatmultiply_n3(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, tmp_19);

    /* Product: '<S9>/A_//M*hred' incorporates:
     *  Constant: '<S9>/Inertia'
     */
    rt_mldivide_U1d24x24_U_NAKP2m_n(IPC4M_P.Inertia_Value_h, rtb_Add, tmp_1q);

    /* MATLAB Function: '<S9>/Centripal Force' incorporates:
     *  Sum: '<S9>/b_ - A_//M*hred'
     */
    tmp_1w[0] = 0.0;
    tmp_1w[3] = -IPC4M_B.Gdx_o[5];
    tmp_1w[6] = IPC4M_B.Gdx_o[4];
    tmp_1w[1] = IPC4M_B.Gdx_o[5];
    tmp_1w[4] = 0.0;
    tmp_1w[7] = -IPC4M_B.Gdx_o[3];
    tmp_1w[2] = -IPC4M_B.Gdx_o[4];
    tmp_1w[5] = IPC4M_B.Gdx_o[3];
    tmp_1w[8] = 0.0;
    tmp_1x[0] = 0.0;
    tmp_1x[3] = -IPC4M_B.Gdx_o[5];
    tmp_1x[6] = IPC4M_B.Gdx_o[4];
    tmp_1x[1] = IPC4M_B.Gdx_o[5];
    tmp_1x[4] = 0.0;
    tmp_1x[7] = -IPC4M_B.Gdx_o[3];
    tmp_1x[2] = -IPC4M_B.Gdx_o[4];
    tmp_1x[5] = IPC4M_B.Gdx_o[3];
    tmp_1x[8] = 0.0;
    for (i = 0; i < 3; i++) {
      for (i_1 = 0; i_1 < 3; i_1++) {
        tmp_1e[i + 3 * i_1] = 0.0;
        tmp_1e[i + 3 * i_1] += tmp_1x[3 * i_1] * tmp_1w[i];
        tmp_1e[i + 3 * i_1] += tmp_1x[3 * i_1 + 1] * tmp_1w[i + 3];
        tmp_1e[i + 3 * i_1] += tmp_1x[3 * i_1 + 2] * tmp_1w[i + 6];
      }
    }

    tmp_1y[0] = 0.0;
    tmp_1y[3] = -IPC4M_B.Gdx_o[5];
    tmp_1y[6] = IPC4M_B.Gdx_o[4];
    tmp_1y[1] = IPC4M_B.Gdx_o[5];
    tmp_1y[4] = 0.0;
    tmp_1y[7] = -IPC4M_B.Gdx_o[3];
    tmp_1y[2] = -IPC4M_B.Gdx_o[4];
    tmp_1y[5] = IPC4M_B.Gdx_o[3];
    tmp_1y[8] = 0.0;
    tmp_1z[0] = 0.0;
    tmp_1z[3] = -IPC4M_B.Gdx_o[5];
    tmp_1z[6] = IPC4M_B.Gdx_o[4];
    tmp_1z[1] = IPC4M_B.Gdx_o[5];
    tmp_1z[4] = 0.0;
    tmp_1z[7] = -IPC4M_B.Gdx_o[3];
    tmp_1z[2] = -IPC4M_B.Gdx_o[4];
    tmp_1z[5] = IPC4M_B.Gdx_o[3];
    tmp_1z[8] = 0.0;
    for (i = 0; i < 3; i++) {
      for (i_1 = 0; i_1 < 3; i_1++) {
        tmp_1f[i + 3 * i_1] = 0.0;
        tmp_1f[i + 3 * i_1] += tmp_1z[3 * i_1] * tmp_1y[i];
        tmp_1f[i + 3 * i_1] += tmp_1z[3 * i_1 + 1] * tmp_1y[i + 3];
        tmp_1f[i + 3 * i_1] += tmp_1z[3 * i_1 + 2] * tmp_1y[i + 6];
      }
    }

    tmp_20[0] = 0.0;
    tmp_20[3] = -IPC4M_B.Gdx_o[5];
    tmp_20[6] = IPC4M_B.Gdx_o[4];
    tmp_20[1] = IPC4M_B.Gdx_o[5];
    tmp_20[4] = 0.0;
    tmp_20[7] = -IPC4M_B.Gdx_o[3];
    tmp_20[2] = -IPC4M_B.Gdx_o[4];
    tmp_20[5] = IPC4M_B.Gdx_o[3];
    tmp_20[8] = 0.0;
    tmp_21[0] = 0.0;
    tmp_21[3] = -IPC4M_B.Gdx_o[5];
    tmp_21[6] = IPC4M_B.Gdx_o[4];
    tmp_21[1] = IPC4M_B.Gdx_o[5];
    tmp_21[4] = 0.0;
    tmp_21[7] = -IPC4M_B.Gdx_o[3];
    tmp_21[2] = -IPC4M_B.Gdx_o[4];
    tmp_21[5] = IPC4M_B.Gdx_o[3];
    tmp_21[8] = 0.0;
    for (i = 0; i < 3; i++) {
      for (i_1 = 0; i_1 < 3; i_1++) {
        tmp_1g[i + 3 * i_1] = 0.0;
        tmp_1g[i + 3 * i_1] += tmp_21[3 * i_1] * tmp_20[i];
        tmp_1g[i + 3 * i_1] += tmp_21[3 * i_1 + 1] * tmp_20[i + 3];
        tmp_1g[i + 3 * i_1] += tmp_21[3 * i_1 + 2] * tmp_20[i + 6];
      }
    }

    for (i = 0; i < 3; i++) {
      c_a_1[i] = tmp_1e[i + 6] * tmp_18[3] + (tmp_1e[i + 3] * tmp_18[2] +
        tmp_1e[i] * tmp_18[1]);
    }

    for (i = 0; i < 3; i++) {
      tmp_1n[i] = tmp_1f[i + 6] * b_q[3] + (tmp_1f[i + 3] * b_q[2] + tmp_1f[i] *
        b_q[1]);
    }

    for (i = 0; i < 3; i++) {
      tmp_1o[i] = tmp_1g[i + 6] * tmp_19[3] + (tmp_1g[i + 3] * tmp_19[2] +
        tmp_1g[i] * tmp_19[1]);
    }

    tmp_22[0] = c_a_1[0];
    tmp_22[1] = c_a_1[1];
    tmp_22[2] = c_a_1[2];
    tmp_22[3] = 0.0;
    tmp_22[4] = 0.0;
    tmp_22[5] = 0.0;
    tmp_22[6] = tmp_1n[0];
    tmp_22[7] = tmp_1n[1];
    tmp_22[8] = tmp_1n[2];
    tmp_22[9] = 0.0;
    tmp_22[10] = 0.0;
    tmp_22[11] = 0.0;
    tmp_22[12] = tmp_1o[0];
    tmp_22[13] = tmp_1o[1];
    tmp_22[14] = tmp_1o[2];
    tmp_22[15] = 0.0;
    tmp_22[16] = 0.0;
    tmp_22[17] = 0.0;
    for (i = 0; i < 18; i++) {
      /* Product: '<S9>/A_//M*hred' */
      rtb_Ared_f[i] = 0.0;
      for (i_1 = 0; i_1 < 24; i_1++) {
        rtb_Ared_f[i] += rtb_Ared_b[18 * i_1 + i] * tmp_1q[i_1];
      }

      /* Sum: '<S9>/b_ - A_//M*hred' incorporates:
       *  Product: '<S9>/A_//M*hred'
       *  Product: '<S9>/Mult'
       */
      tmp_23[i] = tmp_22[i] - rtb_Ared_f[i];
    }

    /* Product: '<S9>/Mult' */
    for (i = 0; i < 24; i++) {
      rtb_Transpose_a[i] = 0.0;
      for (i_1 = 0; i_1 < 18; i_1++) {
        rtb_Transpose_a[i] += rtb_Pseudoinverse[24 * i_1 + i] * tmp_23[i_1];
      }
    }

    for (i = 0; i < 24; i++) {
      rtb_Mult[i] = 0.0;
      for (i_1 = 0; i_1 < 24; i_1++) {
        rtb_Mult[i] += IPC4M_B.Sqrt[24 * i_1 + i] * rtb_Transpose_a[i_1];
      }
    }

    /* MATLAB Function: '<S9>/World to Object Frame' */
    /* MATLAB Function 'Manipulator dynamics/World to Object Frame': '<S79>:1' */
    /* quatrot(quatconj(x(4:7)')',hw(4:6)); */
    /* quatrot(quatconj(x(4:7)')',hw(10:12)); */
    /* quatrot(quatconj(x(4:7)')',hw(16:18)); */
    /* '<S79>:1:3' */
    q[0] = IPC4M_B.x[3];
    q[1] = -IPC4M_B.x[4];
    q[2] = -IPC4M_B.x[5];
    q[3] = -IPC4M_B.x[6];

    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    b_q[0] = IPC4M_B.x[3];
    b_q[1] = -(-IPC4M_B.x[4]);
    b_q[2] = -(-IPC4M_B.x[5]);
    b_q[3] = -(-IPC4M_B.x[6]);
    c_q[0] = IPC4M_B.x[3];
    c_q[1] = -IPC4M_B.x[4];
    c_q[2] = -IPC4M_B.x[5];
    c_q[3] = -IPC4M_B.x[6];

    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    d_q[0] = IPC4M_B.x[3];
    d_q[1] = -(-IPC4M_B.x[4]);
    d_q[2] = -(-IPC4M_B.x[5]);
    d_q[3] = -(-IPC4M_B.x[6]);
    e_q[0] = IPC4M_B.x[3];
    e_q[1] = -IPC4M_B.x[4];
    e_q[2] = -IPC4M_B.x[5];
    e_q[3] = -IPC4M_B.x[6];

    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    f_q[0] = IPC4M_B.x[3];
    f_q[1] = -(-IPC4M_B.x[4]);
    f_q[2] = -(-IPC4M_B.x[5]);
    f_q[3] = -(-IPC4M_B.x[6]);
    g_q[0] = IPC4M_B.x[3];
    g_q[1] = -IPC4M_B.x[4];
    g_q[2] = -IPC4M_B.x[5];
    g_q[3] = -IPC4M_B.x[6];

    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    h_q[0] = IPC4M_B.x[3];
    h_q[1] = -(-IPC4M_B.x[4]);
    h_q[2] = -(-IPC4M_B.x[5]);
    h_q[3] = -(-IPC4M_B.x[6]);
    tmp_o[0] = 0.0;
    tmp_o[1] = rtb_Mult[6];
    tmp_o[2] = rtb_Mult[7];
    tmp_o[3] = rtb_Mult[8];
    IPC4M_quatmultiply_lm(tmp_o, d_q, tmp_17);
    IPC4M_quatmultiply_lm(c_q, tmp_17, d_q);
    tmp_l[0] = 0.0;
    tmp_l[1] = rtb_Mult[0];
    tmp_l[2] = rtb_Mult[1];
    tmp_l[3] = rtb_Mult[2];
    IPC4M_quatmultiply_lm(tmp_l, b_q, tmp_17);
    IPC4M_quatmultiply_lm(q, tmp_17, tmp_18);
    tmp_m[0] = 0.0;
    tmp_m[1] = rtb_Mult[12];
    tmp_m[2] = rtb_Mult[13];
    tmp_m[3] = rtb_Mult[14];
    IPC4M_quatmultiply_lm(tmp_m, f_q, tmp_17);
    IPC4M_quatmultiply_lm(e_q, tmp_17, tmp_19);
    tmp_n[0] = 0.0;
    tmp_n[1] = rtb_Mult[18];
    tmp_n[2] = rtb_Mult[19];
    tmp_n[3] = rtb_Mult[20];
    IPC4M_quatmultiply_lm(tmp_n, h_q, tmp_17);
    IPC4M_quatmultiply_lm(g_q, tmp_17, tmp_1a);
    IPC4M_B.h_int[0] = tmp_18[1];
    IPC4M_B.h_int[1] = tmp_18[2];
    IPC4M_B.h_int[2] = tmp_18[3];
    IPC4M_B.h_int[3] = rtb_Mult[3];
    IPC4M_B.h_int[4] = rtb_Mult[4];
    IPC4M_B.h_int[5] = rtb_Mult[5];
    IPC4M_B.h_int[6] = d_q[1];
    IPC4M_B.h_int[7] = d_q[2];
    IPC4M_B.h_int[8] = d_q[3];
    IPC4M_B.h_int[9] = rtb_Mult[9];
    IPC4M_B.h_int[10] = rtb_Mult[10];
    IPC4M_B.h_int[11] = rtb_Mult[11];
    IPC4M_B.h_int[12] = tmp_19[1];
    IPC4M_B.h_int[13] = tmp_19[2];
    IPC4M_B.h_int[14] = tmp_19[3];
    IPC4M_B.h_int[15] = rtb_Mult[15];
    IPC4M_B.h_int[16] = rtb_Mult[16];
    IPC4M_B.h_int[17] = rtb_Mult[17];
    IPC4M_B.h_int[18] = tmp_1a[1];
    IPC4M_B.h_int[19] = tmp_1a[2];
    IPC4M_B.h_int[20] = tmp_1a[3];
    IPC4M_B.h_int[21] = rtb_Mult[21];
    IPC4M_B.h_int[22] = rtb_Mult[22];
    IPC4M_B.h_int[23] = rtb_Mult[23];

    /* quatrot(quatconj(x(4:7)')',hw(22:24));]; */
    if (rtmIsMajorTimeStep(IPC4M_M)) {
    }

    /* MATLAB Function: '<S11>/Reduced Constraint Matrix' */
    /* MATLAB Function 'Nullspace/Reduced Constraint Matrix': '<S88>:1' */
    /* '<S88>:1:2' */
    for (i = 0; i < 9; i++) {
      I[i] = 0;
      b_I[i] = 0;
      c_I[i] = 0;
      d_I[i] = 0;
      e_I[i] = 0;
      f_I[i] = 0;
      g_I[i] = 0;
      h_I[i] = 0;
      i_I[i] = 0;
      j_I[i] = 0;
      k_I[i] = 0;
      l_I[i] = 0;
    }

    I[0] = 1;
    I[4] = 1;
    I[8] = 1;

    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    q[0] = IPC4M_B.x[3];
    q[1] = -IPC4M_B.x[4];
    q[2] = -IPC4M_B.x[5];
    q[3] = -IPC4M_B.x[6];
    tmp_k[0] = 0.0;
    tmp_k[1] = IPC4M_P.r[3] - IPC4M_P.r[0];
    tmp_k[2] = IPC4M_P.r[4] - IPC4M_P.r[1];
    tmp_k[3] = IPC4M_P.r[5] - IPC4M_P.r[2];
    IPC4M_quatmultiply_f(tmp_k, q, tmp_17);
    IPC4M_quatmultiply_f(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, tmp_18);

    /* generates skew- symmetric matrix from vector */
    b_I[0] = 1;
    b_I[4] = 1;
    b_I[8] = 1;
    c_I[0] = 1;
    c_I[4] = 1;
    c_I[8] = 1;
    d_I[0] = 1;
    d_I[4] = 1;
    d_I[8] = 1;
    e_I[0] = 1;
    e_I[4] = 1;
    e_I[8] = 1;

    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    q[0] = IPC4M_B.x[3];
    q[1] = -IPC4M_B.x[4];
    q[2] = -IPC4M_B.x[5];
    q[3] = -IPC4M_B.x[6];
    tmp_j[0] = 0.0;
    tmp_j[1] = IPC4M_P.r[6] - IPC4M_P.r[0];
    tmp_j[2] = IPC4M_P.r[7] - IPC4M_P.r[1];
    tmp_j[3] = IPC4M_P.r[8] - IPC4M_P.r[2];
    IPC4M_quatmultiply_f(tmp_j, q, tmp_17);
    IPC4M_quatmultiply_f(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, tmp_19);

    /* generates skew- symmetric matrix from vector */
    f_I[0] = 1;
    f_I[4] = 1;
    f_I[8] = 1;
    g_I[0] = 1;
    g_I[4] = 1;
    g_I[8] = 1;
    h_I[0] = 1;
    h_I[4] = 1;
    h_I[8] = 1;
    i_I[0] = 1;
    i_I[4] = 1;
    i_I[8] = 1;

    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    q[0] = IPC4M_B.x[3];
    q[1] = -IPC4M_B.x[4];
    q[2] = -IPC4M_B.x[5];
    q[3] = -IPC4M_B.x[6];
    tmp_i[0] = 0.0;
    tmp_i[1] = IPC4M_P.r[9] - IPC4M_P.r[0];
    tmp_i[2] = IPC4M_P.r[10] - IPC4M_P.r[1];
    tmp_i[3] = IPC4M_P.r[11] - IPC4M_P.r[2];
    IPC4M_quatmultiply_f(tmp_i, q, tmp_17);
    IPC4M_quatmultiply_f(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, q);

    /* generates skew- symmetric matrix from vector */
    j_I[0] = 1;
    j_I[4] = 1;
    j_I[8] = 1;
    k_I[0] = 1;
    k_I[4] = 1;
    k_I[8] = 1;
    l_I[0] = 1;
    l_I[4] = 1;
    l_I[8] = 1;

    /* MATLAB Function: '<Root>/Object to World Frame' incorporates:
     *  Constant: '<Root>/Desired Internal Forces'
     */
    /* MATLAB Function 'Object to World Frame': '<S12>:1' */
    /* '<S12>:1:3' */
    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    d_q[0] = IPC4M_B.x[3];
    d_q[1] = -IPC4M_B.x[4];
    d_q[2] = -IPC4M_B.x[5];
    d_q[3] = -IPC4M_B.x[6];

    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    b_q[0] = IPC4M_B.x[3];
    b_q[1] = -IPC4M_B.x[4];
    b_q[2] = -IPC4M_B.x[5];
    b_q[3] = -IPC4M_B.x[6];

    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    c_q[0] = IPC4M_B.x[3];
    c_q[1] = -IPC4M_B.x[4];
    c_q[2] = -IPC4M_B.x[5];
    c_q[3] = -IPC4M_B.x[6];
    tmp_h[0] = 0.0;
    tmp_h[1] = IPC4M_P.DesiredInternalForces_Value[6];
    tmp_h[2] = IPC4M_P.DesiredInternalForces_Value[7];
    tmp_h[3] = IPC4M_P.DesiredInternalForces_Value[8];
    IPC4M_quatmultiply_g(tmp_h, b_q, tmp_17);
    IPC4M_quatmultiply_g(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, b_q);
    tmp_f[0] = 0.0;
    tmp_f[1] = IPC4M_P.DesiredInternalForces_Value[0];
    tmp_f[2] = IPC4M_P.DesiredInternalForces_Value[1];
    tmp_f[3] = IPC4M_P.DesiredInternalForces_Value[2];
    IPC4M_quatmultiply_g(tmp_f, d_q, tmp_17);
    IPC4M_quatmultiply_g(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, tmp_1a);
    tmp_g[0] = 0.0;
    tmp_g[1] = IPC4M_P.DesiredInternalForces_Value[12];
    tmp_g[2] = IPC4M_P.DesiredInternalForces_Value[13];
    tmp_g[3] = IPC4M_P.DesiredInternalForces_Value[14];
    IPC4M_quatmultiply_g(tmp_g, c_q, tmp_17);
    IPC4M_quatmultiply_g(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, tmp_1b);

    /* Math: '<S11>/Transpose' incorporates:
     *  MATLAB Function: '<S11>/Reduced Constraint Matrix'
     *  Product: '<S11>/A_' * z'
     */
    for (i = 0; i < 3; i++) {
      I_0[24 * i] = -(real_T)I[i];
      I_0[1 + 24 * i] = -(real_T)I[i + 3];
      I_0[2 + 24 * i] = -(real_T)I[i + 6];
    }

    I_0[3] = 0.0;
    I_0[4] = -tmp_18[3];
    I_0[5] = tmp_18[2];
    I_0[27] = tmp_18[3];
    I_0[28] = 0.0;
    I_0[29] = -tmp_18[1];
    I_0[51] = -tmp_18[2];
    I_0[52] = tmp_18[1];
    I_0[53] = 0.0;
    for (i = 0; i < 3; i++) {
      I_0[6 + 24 * i] = b_I[i];
      I_0[7 + 24 * i] = b_I[i + 3];
      I_0[8 + 24 * i] = b_I[i + 6];
    }

    for (i = 0; i < 3; i++) {
      memset(&I_0[24 * i + 9], 0, 15U * sizeof(real_T));
    }

    for (i = 0; i < 3; i++) {
      I_0[24 * (i + 3)] = 0.0;
      I_0[1 + 24 * (i + 3)] = 0.0;
      I_0[2 + 24 * (i + 3)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      I_0[3 + 24 * (i + 3)] = -(real_T)c_I[i];
      I_0[4 + 24 * (i + 3)] = -(real_T)c_I[i + 3];
      I_0[5 + 24 * (i + 3)] = -(real_T)c_I[i + 6];
    }

    for (i = 0; i < 3; i++) {
      I_0[6 + 24 * (i + 3)] = 0.0;
      I_0[7 + 24 * (i + 3)] = 0.0;
      I_0[8 + 24 * (i + 3)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      I_0[9 + 24 * (i + 3)] = d_I[i];
      I_0[10 + 24 * (i + 3)] = d_I[i + 3];
      I_0[11 + 24 * (i + 3)] = d_I[i + 6];
    }

    for (i = 0; i < 3; i++) {
      memset(&I_0[24 * (i + 3) + 12], 0, 12U * sizeof(real_T));
    }

    for (i = 0; i < 3; i++) {
      I_0[24 * (i + 6)] = -(real_T)e_I[i];
      I_0[1 + 24 * (i + 6)] = -(real_T)e_I[i + 3];
      I_0[2 + 24 * (i + 6)] = -(real_T)e_I[i + 6];
    }

    I_0[147] = 0.0;
    I_0[148] = -tmp_19[3];
    I_0[149] = tmp_19[2];
    I_0[171] = tmp_19[3];
    I_0[172] = 0.0;
    I_0[173] = -tmp_19[1];
    I_0[195] = -tmp_19[2];
    I_0[196] = tmp_19[1];
    I_0[197] = 0.0;
    for (i = 0; i < 3; i++) {
      for (i_1 = 0; i_1 < 6; i_1++) {
        I_0[(i_1 + 24 * (i + 6)) + 6] = 0.0;
      }
    }

    for (i = 0; i < 3; i++) {
      I_0[12 + 24 * (i + 6)] = f_I[i];
      I_0[13 + 24 * (i + 6)] = f_I[i + 3];
      I_0[14 + 24 * (i + 6)] = f_I[i + 6];
    }

    for (i = 0; i < 3; i++) {
      memset(&I_0[24 * (i + 6) + 15], 0, 9U * sizeof(real_T));
    }

    for (i = 0; i < 3; i++) {
      I_0[24 * (i + 9)] = 0.0;
      I_0[1 + 24 * (i + 9)] = 0.0;
      I_0[2 + 24 * (i + 9)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      I_0[3 + 24 * (i + 9)] = -(real_T)g_I[i];
      I_0[4 + 24 * (i + 9)] = -(real_T)g_I[i + 3];
      I_0[5 + 24 * (i + 9)] = -(real_T)g_I[i + 6];
    }

    for (i = 0; i < 3; i++) {
      memset(&I_0[24 * (i + 9) + 6], 0, 9U * sizeof(real_T));
    }

    for (i = 0; i < 3; i++) {
      I_0[15 + 24 * (i + 9)] = h_I[i];
      I_0[16 + 24 * (i + 9)] = h_I[i + 3];
      I_0[17 + 24 * (i + 9)] = h_I[i + 6];
    }

    for (i = 0; i < 3; i++) {
      for (i_1 = 0; i_1 < 6; i_1++) {
        I_0[(i_1 + 24 * (i + 9)) + 18] = 0.0;
      }
    }

    for (i = 0; i < 3; i++) {
      I_0[24 * (i + 12)] = -(real_T)i_I[i];
      I_0[1 + 24 * (i + 12)] = -(real_T)i_I[i + 3];
      I_0[2 + 24 * (i + 12)] = -(real_T)i_I[i + 6];
    }

    I_0[291] = 0.0;
    I_0[292] = -q[3];
    I_0[293] = q[2];
    I_0[315] = q[3];
    I_0[316] = 0.0;
    I_0[317] = -q[1];
    I_0[339] = -q[2];
    I_0[340] = q[1];
    I_0[341] = 0.0;
    for (i = 0; i < 3; i++) {
      memset(&I_0[24 * (i + 12) + 6], 0, 12U * sizeof(real_T));
    }

    for (i = 0; i < 3; i++) {
      I_0[18 + 24 * (i + 12)] = j_I[i];
      I_0[19 + 24 * (i + 12)] = j_I[i + 3];
      I_0[20 + 24 * (i + 12)] = j_I[i + 6];
    }

    for (i = 0; i < 3; i++) {
      I_0[21 + 24 * (i + 12)] = 0.0;
      I_0[22 + 24 * (i + 12)] = 0.0;
      I_0[23 + 24 * (i + 12)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      I_0[24 * (i + 15)] = 0.0;
      I_0[1 + 24 * (i + 15)] = 0.0;
      I_0[2 + 24 * (i + 15)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      I_0[3 + 24 * (i + 15)] = -(real_T)k_I[i];
      I_0[4 + 24 * (i + 15)] = -(real_T)k_I[i + 3];
      I_0[5 + 24 * (i + 15)] = -(real_T)k_I[i + 6];
    }

    for (i = 0; i < 3; i++) {
      memset(&I_0[24 * (i + 15) + 6], 0, 15U * sizeof(real_T));
    }

    for (i = 0; i < 3; i++) {
      I_0[21 + 24 * (i + 15)] = l_I[i];
      I_0[22 + 24 * (i + 15)] = l_I[i + 3];
      I_0[23 + 24 * (i + 15)] = l_I[i + 6];
    }

    /* End of Math: '<S11>/Transpose' */

    /* MATLAB Function: '<Root>/Object to World Frame' incorporates:
     *  Constant: '<Root>/Desired Internal Forces'
     *  Product: '<S11>/A_' * z'
     */
    tmp_24[0] = tmp_1a[1];
    tmp_24[1] = tmp_1a[2];
    tmp_24[2] = tmp_1a[3];
    tmp_24[3] = IPC4M_P.DesiredInternalForces_Value[3];
    tmp_24[4] = IPC4M_P.DesiredInternalForces_Value[4];
    tmp_24[5] = IPC4M_P.DesiredInternalForces_Value[5];
    tmp_24[6] = b_q[1];
    tmp_24[7] = b_q[2];
    tmp_24[8] = b_q[3];
    tmp_24[9] = IPC4M_P.DesiredInternalForces_Value[9];
    tmp_24[10] = IPC4M_P.DesiredInternalForces_Value[10];
    tmp_24[11] = IPC4M_P.DesiredInternalForces_Value[11];
    tmp_24[12] = tmp_1b[1];
    tmp_24[13] = tmp_1b[2];
    tmp_24[14] = tmp_1b[3];
    tmp_24[15] = IPC4M_P.DesiredInternalForces_Value[15];
    tmp_24[16] = IPC4M_P.DesiredInternalForces_Value[16];
    tmp_24[17] = IPC4M_P.DesiredInternalForces_Value[17];
    for (i = 0; i < 24; i++) {
      /* Product: '<S11>/A_' * z' */
      rtb_Mult[i] = 0.0;
      for (i_1 = 0; i_1 < 18; i_1++) {
        rtb_Mult[i] += I_0[24 * i_1 + i] * tmp_24[i_1];
      }

      /* Gain: '<Root>/Negative' */
      IPC4M_B.Negative[i] = IPC4M_P.Negative_Gain * rtb_Mult[i];
    }

    if (rtmIsMajorTimeStep(IPC4M_M)) {
    }

    /* MATLAB Function: '<S1>/MATLAB Function' */
    /* MATLAB Function 'Allocator/MATLAB Function': '<S14>:1' */
    /*  Ared = [-eye(3) skew_sm(quatrot(x(4:7),r(4:6)-r(1:3))) eye(3) zeros(3,15); */
    /*          zeros(3) -eye(3) zeros(3) eye(3) zeros(3,12); */
    /*          -eye(3) skew_sm(quatrot(x(4:7),r(7:9)-r(1:3))) zeros(3,6) eye(3) zeros(3,9); */
    /*          zeros(3) -eye(3) zeros(3,9) eye(3) zeros(3,6); */
    /*          -eye(3) skew_sm(quatrot(x(4:7),r(10:12)-r(1:3))) zeros(3,12) eye(3) zeros(3); */
    /*          zeros(3) -eye(3) zeros(3,15) eye(3)]; */
    /* '<S14>:1:8' */
    for (i = 0; i < 9; i++) {
      I[i] = 0;
      b_I[i] = 0;
      c_I[i] = 0;
      d_I[i] = 0;
      e_I[i] = 0;
      f_I[i] = 0;
      g_I[i] = 0;
      h_I[i] = 0;
      i_I[i] = 0;
      j_I[i] = 0;
      k_I[i] = 0;
      l_I[i] = 0;
    }

    I[0] = 1;
    I[4] = 1;
    I[8] = 1;

    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    q[0] = IPC4M_B.x[3];
    q[1] = -IPC4M_B.x[4];
    q[2] = -IPC4M_B.x[5];
    q[3] = -IPC4M_B.x[6];
    tmp_e[0] = 0.0;
    tmp_e[1] = IPC4M_B.x[7] - IPC4M_B.x[0];
    tmp_e[2] = IPC4M_B.x[8] - IPC4M_B.x[1];
    tmp_e[3] = IPC4M_B.x[9] - IPC4M_B.x[2];
    IPC4M_quatmultiply_b(tmp_e, q, tmp_17);
    IPC4M_quatmultiply_b(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, tmp_18);

    /* generates skew- symmetric matrix from vector */
    b_I[0] = 1;
    b_I[4] = 1;
    b_I[8] = 1;
    c_I[0] = 1;
    c_I[4] = 1;
    c_I[8] = 1;
    d_I[0] = 1;
    d_I[4] = 1;
    d_I[8] = 1;
    e_I[0] = 1;
    e_I[4] = 1;
    e_I[8] = 1;

    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    q[0] = IPC4M_B.x[3];
    q[1] = -IPC4M_B.x[4];
    q[2] = -IPC4M_B.x[5];
    q[3] = -IPC4M_B.x[6];
    tmp_d[0] = 0.0;
    tmp_d[1] = IPC4M_B.x[14] - IPC4M_B.x[0];
    tmp_d[2] = IPC4M_B.x[15] - IPC4M_B.x[1];
    tmp_d[3] = IPC4M_B.x[16] - IPC4M_B.x[2];
    IPC4M_quatmultiply_b(tmp_d, q, tmp_17);
    IPC4M_quatmultiply_b(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, tmp_19);

    /* generates skew- symmetric matrix from vector */
    f_I[0] = 1;
    f_I[4] = 1;
    f_I[8] = 1;
    g_I[0] = 1;
    g_I[4] = 1;
    g_I[8] = 1;
    h_I[0] = 1;
    h_I[4] = 1;
    h_I[8] = 1;
    i_I[0] = 1;
    i_I[4] = 1;
    i_I[8] = 1;

    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    q[0] = IPC4M_B.x[3];
    q[1] = -IPC4M_B.x[4];
    q[2] = -IPC4M_B.x[5];
    q[3] = -IPC4M_B.x[6];
    tmp_c[0] = 0.0;
    tmp_c[1] = IPC4M_B.x[21] - IPC4M_B.x[0];
    tmp_c[2] = IPC4M_B.x[22] - IPC4M_B.x[1];
    tmp_c[3] = IPC4M_B.x[23] - IPC4M_B.x[2];
    IPC4M_quatmultiply_b(tmp_c, q, tmp_17);
    IPC4M_quatmultiply_b(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, q);

    /* generates skew- symmetric matrix from vector */
    j_I[0] = 1;
    j_I[4] = 1;
    j_I[8] = 1;
    k_I[0] = 1;
    k_I[4] = 1;
    k_I[8] = 1;
    l_I[0] = 1;
    l_I[4] = 1;
    l_I[8] = 1;
    for (i = 0; i < 3; i++) {
      rtb_Pseudoinverse[18 * i] = -(real_T)I[3 * i];
      rtb_Pseudoinverse[1 + 18 * i] = -(real_T)I[3 * i + 1];
      rtb_Pseudoinverse[2 + 18 * i] = -(real_T)I[3 * i + 2];
    }

    rtb_Pseudoinverse[54] = 0.0;
    rtb_Pseudoinverse[72] = -tmp_18[3];
    rtb_Pseudoinverse[90] = tmp_18[2];
    rtb_Pseudoinverse[55] = tmp_18[3];
    rtb_Pseudoinverse[73] = 0.0;
    rtb_Pseudoinverse[91] = -tmp_18[1];
    rtb_Pseudoinverse[56] = -tmp_18[2];
    rtb_Pseudoinverse[74] = tmp_18[1];
    rtb_Pseudoinverse[92] = 0.0;
    for (i = 0; i < 3; i++) {
      rtb_Pseudoinverse[18 * (i + 6)] = b_I[3 * i];
      rtb_Pseudoinverse[1 + 18 * (i + 6)] = b_I[3 * i + 1];
      rtb_Pseudoinverse[2 + 18 * (i + 6)] = b_I[3 * i + 2];
    }

    for (i = 0; i < 15; i++) {
      rtb_Pseudoinverse[18 * (i + 9)] = 0.0;
      rtb_Pseudoinverse[1 + 18 * (i + 9)] = 0.0;
      rtb_Pseudoinverse[2 + 18 * (i + 9)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_Pseudoinverse[3 + 18 * i] = 0.0;
      rtb_Pseudoinverse[4 + 18 * i] = 0.0;
      rtb_Pseudoinverse[5 + 18 * i] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_Pseudoinverse[3 + 18 * (i + 3)] = -(real_T)c_I[3 * i];
      rtb_Pseudoinverse[4 + 18 * (i + 3)] = -(real_T)c_I[3 * i + 1];
      rtb_Pseudoinverse[5 + 18 * (i + 3)] = -(real_T)c_I[3 * i + 2];
    }

    for (i = 0; i < 3; i++) {
      rtb_Pseudoinverse[3 + 18 * (i + 6)] = 0.0;
      rtb_Pseudoinverse[4 + 18 * (i + 6)] = 0.0;
      rtb_Pseudoinverse[5 + 18 * (i + 6)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_Pseudoinverse[3 + 18 * (i + 9)] = d_I[3 * i];
      rtb_Pseudoinverse[4 + 18 * (i + 9)] = d_I[3 * i + 1];
      rtb_Pseudoinverse[5 + 18 * (i + 9)] = d_I[3 * i + 2];
    }

    for (i = 0; i < 12; i++) {
      rtb_Pseudoinverse[3 + 18 * (i + 12)] = 0.0;
      rtb_Pseudoinverse[4 + 18 * (i + 12)] = 0.0;
      rtb_Pseudoinverse[5 + 18 * (i + 12)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_Pseudoinverse[6 + 18 * i] = -(real_T)e_I[3 * i];
      rtb_Pseudoinverse[7 + 18 * i] = -(real_T)e_I[3 * i + 1];
      rtb_Pseudoinverse[8 + 18 * i] = -(real_T)e_I[3 * i + 2];
    }

    rtb_Pseudoinverse[60] = 0.0;
    rtb_Pseudoinverse[78] = -tmp_19[3];
    rtb_Pseudoinverse[96] = tmp_19[2];
    rtb_Pseudoinverse[61] = tmp_19[3];
    rtb_Pseudoinverse[79] = 0.0;
    rtb_Pseudoinverse[97] = -tmp_19[1];
    rtb_Pseudoinverse[62] = -tmp_19[2];
    rtb_Pseudoinverse[80] = tmp_19[1];
    rtb_Pseudoinverse[98] = 0.0;
    for (i = 0; i < 6; i++) {
      rtb_Pseudoinverse[6 + 18 * (i + 6)] = 0.0;
      rtb_Pseudoinverse[7 + 18 * (i + 6)] = 0.0;
      rtb_Pseudoinverse[8 + 18 * (i + 6)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_Pseudoinverse[6 + 18 * (i + 12)] = f_I[3 * i];
      rtb_Pseudoinverse[7 + 18 * (i + 12)] = f_I[3 * i + 1];
      rtb_Pseudoinverse[8 + 18 * (i + 12)] = f_I[3 * i + 2];
    }

    for (i = 0; i < 9; i++) {
      rtb_Pseudoinverse[6 + 18 * (i + 15)] = 0.0;
      rtb_Pseudoinverse[7 + 18 * (i + 15)] = 0.0;
      rtb_Pseudoinverse[8 + 18 * (i + 15)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_Pseudoinverse[9 + 18 * i] = 0.0;
      rtb_Pseudoinverse[10 + 18 * i] = 0.0;
      rtb_Pseudoinverse[11 + 18 * i] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_Pseudoinverse[9 + 18 * (i + 3)] = -(real_T)g_I[3 * i];
      rtb_Pseudoinverse[10 + 18 * (i + 3)] = -(real_T)g_I[3 * i + 1];
      rtb_Pseudoinverse[11 + 18 * (i + 3)] = -(real_T)g_I[3 * i + 2];
    }

    for (i = 0; i < 9; i++) {
      rtb_Pseudoinverse[9 + 18 * (i + 6)] = 0.0;
      rtb_Pseudoinverse[10 + 18 * (i + 6)] = 0.0;
      rtb_Pseudoinverse[11 + 18 * (i + 6)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_Pseudoinverse[9 + 18 * (i + 15)] = h_I[3 * i];
      rtb_Pseudoinverse[10 + 18 * (i + 15)] = h_I[3 * i + 1];
      rtb_Pseudoinverse[11 + 18 * (i + 15)] = h_I[3 * i + 2];
    }

    for (i = 0; i < 6; i++) {
      rtb_Pseudoinverse[9 + 18 * (i + 18)] = 0.0;
      rtb_Pseudoinverse[10 + 18 * (i + 18)] = 0.0;
      rtb_Pseudoinverse[11 + 18 * (i + 18)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_Pseudoinverse[12 + 18 * i] = -(real_T)i_I[3 * i];
      rtb_Pseudoinverse[13 + 18 * i] = -(real_T)i_I[3 * i + 1];
      rtb_Pseudoinverse[14 + 18 * i] = -(real_T)i_I[3 * i + 2];
    }

    rtb_Pseudoinverse[66] = 0.0;
    rtb_Pseudoinverse[84] = -q[3];
    rtb_Pseudoinverse[102] = q[2];
    rtb_Pseudoinverse[67] = q[3];
    rtb_Pseudoinverse[85] = 0.0;
    rtb_Pseudoinverse[103] = -q[1];
    rtb_Pseudoinverse[68] = -q[2];
    rtb_Pseudoinverse[86] = q[1];
    rtb_Pseudoinverse[104] = 0.0;
    for (i = 0; i < 12; i++) {
      rtb_Pseudoinverse[12 + 18 * (i + 6)] = 0.0;
      rtb_Pseudoinverse[13 + 18 * (i + 6)] = 0.0;
      rtb_Pseudoinverse[14 + 18 * (i + 6)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_Pseudoinverse[12 + 18 * (i + 18)] = j_I[3 * i];
      rtb_Pseudoinverse[13 + 18 * (i + 18)] = j_I[3 * i + 1];
      rtb_Pseudoinverse[14 + 18 * (i + 18)] = j_I[3 * i + 2];
    }

    for (i = 0; i < 3; i++) {
      rtb_Pseudoinverse[12 + 18 * (i + 21)] = 0.0;
      rtb_Pseudoinverse[13 + 18 * (i + 21)] = 0.0;
      rtb_Pseudoinverse[14 + 18 * (i + 21)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_Pseudoinverse[15 + 18 * i] = 0.0;
      rtb_Pseudoinverse[16 + 18 * i] = 0.0;
      rtb_Pseudoinverse[17 + 18 * i] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_Pseudoinverse[15 + 18 * (i + 3)] = -(real_T)k_I[3 * i];
      rtb_Pseudoinverse[16 + 18 * (i + 3)] = -(real_T)k_I[3 * i + 1];
      rtb_Pseudoinverse[17 + 18 * (i + 3)] = -(real_T)k_I[3 * i + 2];
    }

    for (i = 0; i < 15; i++) {
      rtb_Pseudoinverse[15 + 18 * (i + 6)] = 0.0;
      rtb_Pseudoinverse[16 + 18 * (i + 6)] = 0.0;
      rtb_Pseudoinverse[17 + 18 * (i + 6)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_Pseudoinverse[15 + 18 * (i + 21)] = l_I[3 * i];
      rtb_Pseudoinverse[16 + 18 * (i + 21)] = l_I[3 * i + 1];
      rtb_Pseudoinverse[17 + 18 * (i + 21)] = l_I[3 * i + 2];
    }

    /* End of MATLAB Function: '<S1>/MATLAB Function' */

    /* Sum: '<S1>/Add1' */
    for (i = 0; i < 24; i++) {
      rtb_Mult[i] += rtb_Add[i];
    }

    /* End of Sum: '<S1>/Add1' */

    /* MATLAB Function: '<S1>/MATLAB Function1' */
    /* MATLAB Function 'Allocator/MATLAB Function1': '<S15>:1' */
    /*  bred = [skew_sm(dx(4:6))*skew_sm(dx(4:6))*quatrot(x(4:7),r(4:6)-r(1:3)); */
    /*      zeros(3,1); */
    /*      skew_sm(dx(4:6))*skew_sm(dx(4:6))*quatrot(x(4:7),r(7:9)-r(1:3)); */
    /*      zeros(3,1); */
    /*      skew_sm(dx(4:6))*skew_sm(dx(4:6))*quatrot(x(4:7),r(10:12)-r(1:3)); */
    /*      zeros(3,1)]; */
    /* '<S15>:1:8' */
    /* generates skew- symmetric matrix from vector */
    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    q[0] = IPC4M_B.x[3];
    q[1] = -IPC4M_B.x[4];
    q[2] = -IPC4M_B.x[5];
    q[3] = -IPC4M_B.x[6];

    /* generates skew- symmetric matrix from vector */
    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    b_q[0] = IPC4M_B.x[3];
    b_q[1] = -IPC4M_B.x[4];
    b_q[2] = -IPC4M_B.x[5];
    b_q[3] = -IPC4M_B.x[6];

    /* generates skew- symmetric matrix from vector */
    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    c_q[0] = IPC4M_B.x[3];
    c_q[1] = -IPC4M_B.x[4];
    c_q[2] = -IPC4M_B.x[5];
    c_q[3] = -IPC4M_B.x[6];
    tmp_b[0] = 0.0;
    tmp_b[1] = IPC4M_B.x[14] - IPC4M_B.x[0];
    tmp_b[2] = IPC4M_B.x[15] - IPC4M_B.x[1];
    tmp_b[3] = IPC4M_B.x[16] - IPC4M_B.x[2];
    IPC4M_quatmultiply_n(tmp_b, b_q, tmp_17);
    IPC4M_quatmultiply_n(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, b_q);

    /* Math: '<S1>/Math Function' */
    for (i = 0; i < 18; i++) {
      for (i_1 = 0; i_1 < 24; i_1++) {
        rtb_MathFunction[i_1 + 24 * i] = rtb_Pseudoinverse[18 * i_1 + i];
      }
    }

    /* End of Math: '<S1>/Math Function' */

    /* Product: '<S1>/Divide1' incorporates:
     *  Constant: '<S1>/Inertia'
     */
    rt_mldivide_U1d24x24_U_2VUCyo_n(IPC4M_P.Inertia_Value_l, rtb_MathFunction,
      I_0);

    /* MATLAB Function: '<S1>/MATLAB Function1' */
    tmp_9[0] = 0.0;
    tmp_9[1] = IPC4M_B.x[7] - IPC4M_B.x[0];
    tmp_9[2] = IPC4M_B.x[8] - IPC4M_B.x[1];
    tmp_9[3] = IPC4M_B.x[9] - IPC4M_B.x[2];
    IPC4M_quatmultiply_n(tmp_9, q, tmp_17);
    IPC4M_quatmultiply_n(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, tmp_18);
    tmp_a[0] = 0.0;
    tmp_a[1] = IPC4M_B.x[21] - IPC4M_B.x[0];
    tmp_a[2] = IPC4M_B.x[22] - IPC4M_B.x[1];
    tmp_a[3] = IPC4M_B.x[23] - IPC4M_B.x[2];
    IPC4M_quatmultiply_n(tmp_a, c_q, tmp_17);
    IPC4M_quatmultiply_n(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, tmp_19);

    /* Product: '<S1>/Divide2' incorporates:
     *  Constant: '<S1>/Inertia'
     */
    rt_mldivide_U1d24x24_U_NAKP2m_n(IPC4M_P.Inertia_Value_l, rtb_Mult, tmp_1q);

    /* Product: '<S1>/Divide1' */
    for (i = 0; i < 18; i++) {
      for (i_1 = 0; i_1 < 18; i_1++) {
        rtb_Pseudoinverse_1[i + 18 * i_1] = 0.0;
        for (i_0 = 0; i_0 < 24; i_0++) {
          rtb_Pseudoinverse_1[i + 18 * i_1] += rtb_Pseudoinverse[18 * i_0 + i] *
            I_0[24 * i_1 + i_0];
        }
      }
    }

    /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
     *  Sum: '<S1>/Add'
     */
    tmp_25[0] = 0.0;
    tmp_25[3] = -IPC4M_B.Gdx_o[5];
    tmp_25[6] = IPC4M_B.Gdx_o[4];
    tmp_25[1] = IPC4M_B.Gdx_o[5];
    tmp_25[4] = 0.0;
    tmp_25[7] = -IPC4M_B.Gdx_o[3];
    tmp_25[2] = -IPC4M_B.Gdx_o[4];
    tmp_25[5] = IPC4M_B.Gdx_o[3];
    tmp_25[8] = 0.0;
    tmp_26[0] = 0.0;
    tmp_26[3] = -IPC4M_B.Gdx_o[5];
    tmp_26[6] = IPC4M_B.Gdx_o[4];
    tmp_26[1] = IPC4M_B.Gdx_o[5];
    tmp_26[4] = 0.0;
    tmp_26[7] = -IPC4M_B.Gdx_o[3];
    tmp_26[2] = -IPC4M_B.Gdx_o[4];
    tmp_26[5] = IPC4M_B.Gdx_o[3];
    tmp_26[8] = 0.0;
    for (i = 0; i < 3; i++) {
      for (i_1 = 0; i_1 < 3; i_1++) {
        tmp_1e[i + 3 * i_1] = 0.0;
        tmp_1e[i + 3 * i_1] += tmp_26[3 * i_1] * tmp_25[i];
        tmp_1e[i + 3 * i_1] += tmp_26[3 * i_1 + 1] * tmp_25[i + 3];
        tmp_1e[i + 3 * i_1] += tmp_26[3 * i_1 + 2] * tmp_25[i + 6];
      }
    }

    tmp_27[0] = 0.0;
    tmp_27[3] = -IPC4M_B.Gdx_o[5];
    tmp_27[6] = IPC4M_B.Gdx_o[4];
    tmp_27[1] = IPC4M_B.Gdx_o[5];
    tmp_27[4] = 0.0;
    tmp_27[7] = -IPC4M_B.Gdx_o[3];
    tmp_27[2] = -IPC4M_B.Gdx_o[4];
    tmp_27[5] = IPC4M_B.Gdx_o[3];
    tmp_27[8] = 0.0;
    tmp_28[0] = 0.0;
    tmp_28[3] = -IPC4M_B.Gdx_o[5];
    tmp_28[6] = IPC4M_B.Gdx_o[4];
    tmp_28[1] = IPC4M_B.Gdx_o[5];
    tmp_28[4] = 0.0;
    tmp_28[7] = -IPC4M_B.Gdx_o[3];
    tmp_28[2] = -IPC4M_B.Gdx_o[4];
    tmp_28[5] = IPC4M_B.Gdx_o[3];
    tmp_28[8] = 0.0;
    for (i = 0; i < 3; i++) {
      for (i_1 = 0; i_1 < 3; i_1++) {
        tmp_1f[i + 3 * i_1] = 0.0;
        tmp_1f[i + 3 * i_1] += tmp_28[3 * i_1] * tmp_27[i];
        tmp_1f[i + 3 * i_1] += tmp_28[3 * i_1 + 1] * tmp_27[i + 3];
        tmp_1f[i + 3 * i_1] += tmp_28[3 * i_1 + 2] * tmp_27[i + 6];
      }
    }

    tmp_29[0] = 0.0;
    tmp_29[3] = -IPC4M_B.Gdx_o[5];
    tmp_29[6] = IPC4M_B.Gdx_o[4];
    tmp_29[1] = IPC4M_B.Gdx_o[5];
    tmp_29[4] = 0.0;
    tmp_29[7] = -IPC4M_B.Gdx_o[3];
    tmp_29[2] = -IPC4M_B.Gdx_o[4];
    tmp_29[5] = IPC4M_B.Gdx_o[3];
    tmp_29[8] = 0.0;
    tmp_2a[0] = 0.0;
    tmp_2a[3] = -IPC4M_B.Gdx_o[5];
    tmp_2a[6] = IPC4M_B.Gdx_o[4];
    tmp_2a[1] = IPC4M_B.Gdx_o[5];
    tmp_2a[4] = 0.0;
    tmp_2a[7] = -IPC4M_B.Gdx_o[3];
    tmp_2a[2] = -IPC4M_B.Gdx_o[4];
    tmp_2a[5] = IPC4M_B.Gdx_o[3];
    tmp_2a[8] = 0.0;
    for (i = 0; i < 3; i++) {
      for (i_1 = 0; i_1 < 3; i_1++) {
        tmp_1g[i + 3 * i_1] = 0.0;
        tmp_1g[i + 3 * i_1] += tmp_2a[3 * i_1] * tmp_29[i];
        tmp_1g[i + 3 * i_1] += tmp_2a[3 * i_1 + 1] * tmp_29[i + 3];
        tmp_1g[i + 3 * i_1] += tmp_2a[3 * i_1 + 2] * tmp_29[i + 6];
      }
    }

    for (i = 0; i < 3; i++) {
      c_a_1[i] = tmp_1e[i + 6] * tmp_18[3] + (tmp_1e[i + 3] * tmp_18[2] +
        tmp_1e[i] * tmp_18[1]);
    }

    for (i = 0; i < 3; i++) {
      tmp_1n[i] = tmp_1f[i + 6] * b_q[3] + (tmp_1f[i + 3] * b_q[2] + tmp_1f[i] *
        b_q[1]);
    }

    for (i = 0; i < 3; i++) {
      tmp_1o[i] = tmp_1g[i + 6] * tmp_19[3] + (tmp_1g[i + 3] * tmp_19[2] +
        tmp_1g[i] * tmp_19[1]);
    }

    tmp_2b[0] = c_a_1[0];
    tmp_2b[1] = c_a_1[1];
    tmp_2b[2] = c_a_1[2];
    tmp_2b[3] = 0.0;
    tmp_2b[4] = 0.0;
    tmp_2b[5] = 0.0;
    tmp_2b[6] = tmp_1n[0];
    tmp_2b[7] = tmp_1n[1];
    tmp_2b[8] = tmp_1n[2];
    tmp_2b[9] = 0.0;
    tmp_2b[10] = 0.0;
    tmp_2b[11] = 0.0;
    tmp_2b[12] = tmp_1o[0];
    tmp_2b[13] = tmp_1o[1];
    tmp_2b[14] = tmp_1o[2];
    tmp_2b[15] = 0.0;
    tmp_2b[16] = 0.0;
    tmp_2b[17] = 0.0;
    for (i = 0; i < 18; i++) {
      /* Product: '<S1>/Divide2' */
      rtb_Ared_f[i] = 0.0;
      for (i_1 = 0; i_1 < 24; i_1++) {
        rtb_Ared_f[i] += rtb_Pseudoinverse[18 * i_1 + i] * tmp_1q[i_1];
      }

      /* Sum: '<S1>/Add' incorporates:
       *  Product: '<S1>/Divide2'
       */
      tmp_22[i] = tmp_2b[i] - rtb_Ared_f[i];
    }

    /* Product: '<S1>/Divide' */
    rt_mldivide_U1d18x18_U_2jkRkZaZ(rtb_Pseudoinverse_1, tmp_22, tmp_23);
    for (i = 0; i < 24; i++) {
      rtb_Divide[i] = 0.0;
      for (i_1 = 0; i_1 < 18; i_1++) {
        rtb_Divide[i] += rtb_MathFunction[24 * i_1 + i] * tmp_23[i_1];
      }
    }

    /* End of Product: '<S1>/Divide' */
    if (rtmIsMajorTimeStep(IPC4M_M)) {
    }

    /* Sum: '<S18>/Add2' */
    IPC4M_B.Add2[0] = IPC4M_B.Sum - rtb_Sum_k;
    IPC4M_B.Add2[1] = rtb_Sum_g - rtb_Sum_iy;
    IPC4M_B.Add2[2] = rtb_Sum_m - rtb_Sum_bl;
    IPC4M_B.Add2[3] = rtb_Sum_e - rtb_Sum_a5;
    if (rtmIsMajorTimeStep(IPC4M_M)) {
    }

    /* MATLAB Function: '<S5>/MATLAB Function' */
    /* MATLAB Function 'Interaction dynamics1/MATLAB Function': '<S68>:1' */
    /* '<S68>:1:2' */
    for (i = 0; i < 9; i++) {
      I[i] = 0;
      b_I[i] = 0;
      c_I[i] = 0;
      d_I[i] = 0;
      e_I[i] = 0;
      f_I[i] = 0;
      g_I[i] = 0;
      h_I[i] = 0;
      i_I[i] = 0;
      j_I[i] = 0;
      k_I[i] = 0;
      l_I[i] = 0;
      m_I[i] = 0;
      n_I[i] = 0;
      o_I[i] = 0;
      p_I[i] = 0;
    }

    I[0] = 1;
    I[4] = 1;
    I[8] = 1;

    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    q[0] = IPC4M_B.x[3];
    q[1] = -IPC4M_B.x[4];
    q[2] = -IPC4M_B.x[5];
    q[3] = -IPC4M_B.x[6];
    tmp_8[0] = 0.0;
    tmp_8[1] = IPC4M_P.r[0];
    tmp_8[2] = IPC4M_P.r[1];
    tmp_8[3] = IPC4M_P.r[2];
    IPC4M_quatmultiply_e(tmp_8, q, tmp_17);
    IPC4M_quatmultiply_e(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, tmp_18);

    /* generates skew- symmetric matrix from vector */
    b_I[0] = 1;
    b_I[4] = 1;
    b_I[8] = 1;
    c_I[0] = 1;
    c_I[4] = 1;
    c_I[8] = 1;
    d_I[0] = 1;
    d_I[4] = 1;
    d_I[8] = 1;
    e_I[0] = 1;
    e_I[4] = 1;
    e_I[8] = 1;

    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    q[0] = IPC4M_B.x[3];
    q[1] = -IPC4M_B.x[4];
    q[2] = -IPC4M_B.x[5];
    q[3] = -IPC4M_B.x[6];
    tmp_7[0] = 0.0;
    tmp_7[1] = IPC4M_P.r[3];
    tmp_7[2] = IPC4M_P.r[4];
    tmp_7[3] = IPC4M_P.r[5];
    IPC4M_quatmultiply_e(tmp_7, q, tmp_17);
    IPC4M_quatmultiply_e(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, tmp_19);

    /* generates skew- symmetric matrix from vector */
    f_I[0] = 1;
    f_I[4] = 1;
    f_I[8] = 1;
    g_I[0] = 1;
    g_I[4] = 1;
    g_I[8] = 1;
    h_I[0] = 1;
    h_I[4] = 1;
    h_I[8] = 1;
    i_I[0] = 1;
    i_I[4] = 1;
    i_I[8] = 1;

    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    q[0] = IPC4M_B.x[3];
    q[1] = -IPC4M_B.x[4];
    q[2] = -IPC4M_B.x[5];
    q[3] = -IPC4M_B.x[6];
    tmp_6[0] = 0.0;
    tmp_6[1] = IPC4M_P.r[6];
    tmp_6[2] = IPC4M_P.r[7];
    tmp_6[3] = IPC4M_P.r[8];
    IPC4M_quatmultiply_e(tmp_6, q, tmp_17);
    IPC4M_quatmultiply_e(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, tmp_1a);

    /* generates skew- symmetric matrix from vector */
    j_I[0] = 1;
    j_I[4] = 1;
    j_I[8] = 1;
    k_I[0] = 1;
    k_I[4] = 1;
    k_I[8] = 1;
    l_I[0] = 1;
    l_I[4] = 1;
    l_I[8] = 1;
    m_I[0] = 1;
    m_I[4] = 1;
    m_I[8] = 1;

    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    q[0] = IPC4M_B.x[3];
    q[1] = -IPC4M_B.x[4];
    q[2] = -IPC4M_B.x[5];
    q[3] = -IPC4M_B.x[6];
    tmp_5[0] = 0.0;
    tmp_5[1] = IPC4M_P.r[9];
    tmp_5[2] = IPC4M_P.r[10];
    tmp_5[3] = IPC4M_P.r[11];
    IPC4M_quatmultiply_e(tmp_5, q, tmp_17);
    IPC4M_quatmultiply_e(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, q);

    /* generates skew- symmetric matrix from vector */
    n_I[0] = 1;
    n_I[4] = 1;
    n_I[8] = 1;
    o_I[0] = 1;
    o_I[4] = 1;
    o_I[8] = 1;
    p_I[0] = 1;
    p_I[4] = 1;
    p_I[8] = 1;
    for (i = 0; i < 3; i++) {
      IPC4M_B.A_c[24 * i] = -(real_T)I[3 * i];
      IPC4M_B.A_c[1 + 24 * i] = -(real_T)I[3 * i + 1];
      IPC4M_B.A_c[2 + 24 * i] = -(real_T)I[3 * i + 2];
    }

    IPC4M_B.A_c[72] = 0.0;
    IPC4M_B.A_c[96] = -tmp_18[3];
    IPC4M_B.A_c[120] = tmp_18[2];
    IPC4M_B.A_c[73] = tmp_18[3];
    IPC4M_B.A_c[97] = 0.0;
    IPC4M_B.A_c[121] = -tmp_18[1];
    IPC4M_B.A_c[74] = -tmp_18[2];
    IPC4M_B.A_c[98] = tmp_18[1];
    IPC4M_B.A_c[122] = 0.0;
    for (i = 0; i < 3; i++) {
      IPC4M_B.A_c[24 * (i + 6)] = b_I[3 * i];
      IPC4M_B.A_c[1 + 24 * (i + 6)] = b_I[3 * i + 1];
      IPC4M_B.A_c[2 + 24 * (i + 6)] = b_I[3 * i + 2];
    }

    for (i = 0; i < 21; i++) {
      IPC4M_B.A_c[24 * (i + 9)] = 0.0;
      IPC4M_B.A_c[1 + 24 * (i + 9)] = 0.0;
      IPC4M_B.A_c[2 + 24 * (i + 9)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      IPC4M_B.A_c[3 + 24 * i] = 0.0;
      IPC4M_B.A_c[4 + 24 * i] = 0.0;
      IPC4M_B.A_c[5 + 24 * i] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      IPC4M_B.A_c[3 + 24 * (i + 3)] = -(real_T)c_I[3 * i];
      IPC4M_B.A_c[4 + 24 * (i + 3)] = -(real_T)c_I[3 * i + 1];
      IPC4M_B.A_c[5 + 24 * (i + 3)] = -(real_T)c_I[3 * i + 2];
    }

    for (i = 0; i < 3; i++) {
      IPC4M_B.A_c[3 + 24 * (i + 6)] = 0.0;
      IPC4M_B.A_c[4 + 24 * (i + 6)] = 0.0;
      IPC4M_B.A_c[5 + 24 * (i + 6)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      IPC4M_B.A_c[3 + 24 * (i + 9)] = d_I[3 * i];
      IPC4M_B.A_c[4 + 24 * (i + 9)] = d_I[3 * i + 1];
      IPC4M_B.A_c[5 + 24 * (i + 9)] = d_I[3 * i + 2];
    }

    for (i = 0; i < 18; i++) {
      IPC4M_B.A_c[3 + 24 * (i + 12)] = 0.0;
      IPC4M_B.A_c[4 + 24 * (i + 12)] = 0.0;
      IPC4M_B.A_c[5 + 24 * (i + 12)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      IPC4M_B.A_c[6 + 24 * i] = -(real_T)e_I[3 * i];
      IPC4M_B.A_c[7 + 24 * i] = -(real_T)e_I[3 * i + 1];
      IPC4M_B.A_c[8 + 24 * i] = -(real_T)e_I[3 * i + 2];
    }

    IPC4M_B.A_c[78] = 0.0;
    IPC4M_B.A_c[102] = -tmp_19[3];
    IPC4M_B.A_c[126] = tmp_19[2];
    IPC4M_B.A_c[79] = tmp_19[3];
    IPC4M_B.A_c[103] = 0.0;
    IPC4M_B.A_c[127] = -tmp_19[1];
    IPC4M_B.A_c[80] = -tmp_19[2];
    IPC4M_B.A_c[104] = tmp_19[1];
    IPC4M_B.A_c[128] = 0.0;
    for (i = 0; i < 6; i++) {
      IPC4M_B.A_c[6 + 24 * (i + 6)] = 0.0;
      IPC4M_B.A_c[7 + 24 * (i + 6)] = 0.0;
      IPC4M_B.A_c[8 + 24 * (i + 6)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      IPC4M_B.A_c[6 + 24 * (i + 12)] = f_I[3 * i];
      IPC4M_B.A_c[7 + 24 * (i + 12)] = f_I[3 * i + 1];
      IPC4M_B.A_c[8 + 24 * (i + 12)] = f_I[3 * i + 2];
    }

    for (i = 0; i < 15; i++) {
      IPC4M_B.A_c[6 + 24 * (i + 15)] = 0.0;
      IPC4M_B.A_c[7 + 24 * (i + 15)] = 0.0;
      IPC4M_B.A_c[8 + 24 * (i + 15)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      IPC4M_B.A_c[9 + 24 * i] = 0.0;
      IPC4M_B.A_c[10 + 24 * i] = 0.0;
      IPC4M_B.A_c[11 + 24 * i] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      IPC4M_B.A_c[9 + 24 * (i + 3)] = -(real_T)g_I[3 * i];
      IPC4M_B.A_c[10 + 24 * (i + 3)] = -(real_T)g_I[3 * i + 1];
      IPC4M_B.A_c[11 + 24 * (i + 3)] = -(real_T)g_I[3 * i + 2];
    }

    for (i = 0; i < 9; i++) {
      IPC4M_B.A_c[9 + 24 * (i + 6)] = 0.0;
      IPC4M_B.A_c[10 + 24 * (i + 6)] = 0.0;
      IPC4M_B.A_c[11 + 24 * (i + 6)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      IPC4M_B.A_c[9 + 24 * (i + 15)] = h_I[3 * i];
      IPC4M_B.A_c[10 + 24 * (i + 15)] = h_I[3 * i + 1];
      IPC4M_B.A_c[11 + 24 * (i + 15)] = h_I[3 * i + 2];
    }

    for (i = 0; i < 12; i++) {
      IPC4M_B.A_c[9 + 24 * (i + 18)] = 0.0;
      IPC4M_B.A_c[10 + 24 * (i + 18)] = 0.0;
      IPC4M_B.A_c[11 + 24 * (i + 18)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      IPC4M_B.A_c[12 + 24 * i] = -(real_T)i_I[3 * i];
      IPC4M_B.A_c[13 + 24 * i] = -(real_T)i_I[3 * i + 1];
      IPC4M_B.A_c[14 + 24 * i] = -(real_T)i_I[3 * i + 2];
    }

    IPC4M_B.A_c[84] = 0.0;
    IPC4M_B.A_c[108] = -tmp_1a[3];
    IPC4M_B.A_c[132] = tmp_1a[2];
    IPC4M_B.A_c[85] = tmp_1a[3];
    IPC4M_B.A_c[109] = 0.0;
    IPC4M_B.A_c[133] = -tmp_1a[1];
    IPC4M_B.A_c[86] = -tmp_1a[2];
    IPC4M_B.A_c[110] = tmp_1a[1];
    IPC4M_B.A_c[134] = 0.0;
    for (i = 0; i < 12; i++) {
      IPC4M_B.A_c[12 + 24 * (i + 6)] = 0.0;
      IPC4M_B.A_c[13 + 24 * (i + 6)] = 0.0;
      IPC4M_B.A_c[14 + 24 * (i + 6)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      IPC4M_B.A_c[12 + 24 * (i + 18)] = j_I[3 * i];
      IPC4M_B.A_c[13 + 24 * (i + 18)] = j_I[3 * i + 1];
      IPC4M_B.A_c[14 + 24 * (i + 18)] = j_I[3 * i + 2];
    }

    for (i = 0; i < 9; i++) {
      IPC4M_B.A_c[12 + 24 * (i + 21)] = 0.0;
      IPC4M_B.A_c[13 + 24 * (i + 21)] = 0.0;
      IPC4M_B.A_c[14 + 24 * (i + 21)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      IPC4M_B.A_c[15 + 24 * i] = 0.0;
      IPC4M_B.A_c[16 + 24 * i] = 0.0;
      IPC4M_B.A_c[17 + 24 * i] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      IPC4M_B.A_c[15 + 24 * (i + 3)] = -(real_T)k_I[3 * i];
      IPC4M_B.A_c[16 + 24 * (i + 3)] = -(real_T)k_I[3 * i + 1];
      IPC4M_B.A_c[17 + 24 * (i + 3)] = -(real_T)k_I[3 * i + 2];
    }

    for (i = 0; i < 15; i++) {
      IPC4M_B.A_c[15 + 24 * (i + 6)] = 0.0;
      IPC4M_B.A_c[16 + 24 * (i + 6)] = 0.0;
      IPC4M_B.A_c[17 + 24 * (i + 6)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      IPC4M_B.A_c[15 + 24 * (i + 21)] = l_I[3 * i];
      IPC4M_B.A_c[16 + 24 * (i + 21)] = l_I[3 * i + 1];
      IPC4M_B.A_c[17 + 24 * (i + 21)] = l_I[3 * i + 2];
    }

    for (i = 0; i < 6; i++) {
      IPC4M_B.A_c[15 + 24 * (i + 24)] = 0.0;
      IPC4M_B.A_c[16 + 24 * (i + 24)] = 0.0;
      IPC4M_B.A_c[17 + 24 * (i + 24)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      IPC4M_B.A_c[18 + 24 * i] = -(real_T)m_I[3 * i];
      IPC4M_B.A_c[19 + 24 * i] = -(real_T)m_I[3 * i + 1];
      IPC4M_B.A_c[20 + 24 * i] = -(real_T)m_I[3 * i + 2];
    }

    IPC4M_B.A_c[90] = 0.0;
    IPC4M_B.A_c[114] = -q[3];
    IPC4M_B.A_c[138] = q[2];
    IPC4M_B.A_c[91] = q[3];
    IPC4M_B.A_c[115] = 0.0;
    IPC4M_B.A_c[139] = -q[1];
    IPC4M_B.A_c[92] = -q[2];
    IPC4M_B.A_c[116] = q[1];
    IPC4M_B.A_c[140] = 0.0;
    for (i = 0; i < 18; i++) {
      IPC4M_B.A_c[18 + 24 * (i + 6)] = 0.0;
      IPC4M_B.A_c[19 + 24 * (i + 6)] = 0.0;
      IPC4M_B.A_c[20 + 24 * (i + 6)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      IPC4M_B.A_c[18 + 24 * (i + 24)] = n_I[3 * i];
      IPC4M_B.A_c[19 + 24 * (i + 24)] = n_I[3 * i + 1];
      IPC4M_B.A_c[20 + 24 * (i + 24)] = n_I[3 * i + 2];
    }

    for (i = 0; i < 3; i++) {
      IPC4M_B.A_c[18 + 24 * (i + 27)] = 0.0;
      IPC4M_B.A_c[19 + 24 * (i + 27)] = 0.0;
      IPC4M_B.A_c[20 + 24 * (i + 27)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      IPC4M_B.A_c[21 + 24 * i] = 0.0;
      IPC4M_B.A_c[22 + 24 * i] = 0.0;
      IPC4M_B.A_c[23 + 24 * i] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      IPC4M_B.A_c[21 + 24 * (i + 3)] = -(real_T)o_I[3 * i];
      IPC4M_B.A_c[22 + 24 * (i + 3)] = -(real_T)o_I[3 * i + 1];
      IPC4M_B.A_c[23 + 24 * (i + 3)] = -(real_T)o_I[3 * i + 2];
    }

    for (i = 0; i < 21; i++) {
      IPC4M_B.A_c[21 + 24 * (i + 6)] = 0.0;
      IPC4M_B.A_c[22 + 24 * (i + 6)] = 0.0;
      IPC4M_B.A_c[23 + 24 * (i + 6)] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      IPC4M_B.A_c[21 + 24 * (i + 27)] = p_I[3 * i];
      IPC4M_B.A_c[22 + 24 * (i + 27)] = p_I[3 * i + 1];
      IPC4M_B.A_c[23 + 24 * (i + 27)] = p_I[3 * i + 2];
    }

    /* End of MATLAB Function: '<S5>/MATLAB Function' */

    /* MATLAB Function: '<S5>/Coriolis Force' incorporates:
     *  Sum: '<S5>/h_dist - h_g - j0 S(omega0) omega0 '
     */
    /* MATLAB Function 'Interaction dynamics1/Coriolis Force': '<S67>:1' */
    /* '<S67>:1:2' */
    /* generates skew- symmetric matrix from vector */
    tmp_2c[0] = 0.0;
    tmp_2c[3] = -IPC4M_B.Gdx_o[5];
    tmp_2c[6] = IPC4M_B.Gdx_o[4];
    tmp_2c[1] = IPC4M_B.Gdx_o[5];
    tmp_2c[4] = 0.0;
    tmp_2c[7] = -IPC4M_B.Gdx_o[3];
    tmp_2c[2] = -IPC4M_B.Gdx_o[4];
    tmp_2c[5] = IPC4M_B.Gdx_o[3];
    tmp_2c[8] = 0.0;
    for (i = 0; i < 3; i++) {
      tmp_1e[3 * i] = tmp_2c[3 * i] * IPC4M_P.m0;
      tmp_1e[1 + 3 * i] = tmp_2c[3 * i + 1] * IPC4M_P.m0;
      tmp_1e[2 + 3 * i] = tmp_2c[3 * i + 2] * IPC4M_P.m0;
    }

    tmp_2d[0] = 0.0;
    tmp_2d[3] = -IPC4M_B.Gdx_o[5];
    tmp_2d[6] = IPC4M_B.Gdx_o[4];
    tmp_2d[1] = IPC4M_B.Gdx_o[5];
    tmp_2d[4] = 0.0;
    tmp_2d[7] = -IPC4M_B.Gdx_o[3];
    tmp_2d[2] = -IPC4M_B.Gdx_o[4];
    tmp_2d[5] = IPC4M_B.Gdx_o[3];
    tmp_2d[8] = 0.0;
    for (i = 0; i < 3; i++) {
      tmp_1f[3 * i] = tmp_2d[3 * i] * IPC4M_P.j0;
      tmp_1f[1 + 3 * i] = tmp_2d[3 * i + 1] * IPC4M_P.j0;
      tmp_1f[2 + 3 * i] = tmp_2d[3 * i + 2] * IPC4M_P.j0;
    }

    for (i = 0; i < 3; i++) {
      c_a_1[i] = tmp_1e[i + 6] * IPC4M_B.Gdx_o[2] + (tmp_1e[i + 3] *
        IPC4M_B.Gdx_o[1] + tmp_1e[i] * IPC4M_B.Gdx_o[0]);
    }

    for (i = 0; i < 3; i++) {
      tmp_1n[i] = tmp_1f[i + 6] * IPC4M_B.Gdx_o[5] + (tmp_1f[i + 3] *
        IPC4M_B.Gdx_o[4] + tmp_1f[i] * IPC4M_B.Gdx_o[3]);
    }

    tmp_2e[0] = c_a_1[0];
    tmp_2e[1] = c_a_1[1];
    tmp_2e[2] = c_a_1[2];
    tmp_2e[3] = tmp_1n[0];
    tmp_2e[4] = tmp_1n[1];
    tmp_2e[5] = tmp_1n[2];

    /* End of MATLAB Function: '<S5>/Coriolis Force' */

    /* SignalConversion: '<S5>/TmpSignal ConversionAtM3Inport3' incorporates:
     *  Constant: '<Root>/Distortion'
     *  Constant: '<S5>/Gravitation'
     *  Sum: '<S5>/h_dist - h_g - j0 S(omega0) omega0 '
     */
    for (i = 0; i < 6; i++) {
      rtb_TmpSignalConversionAtM3Inpo[i] = (IPC4M_P.Distortion_Value[i] -
        IPC4M_P.Gravitation_Value[i]) - tmp_2e[i];
    }

    memcpy(&rtb_TmpSignalConversionAtM3Inpo[6], &rtb_Add[0], 24U * sizeof(real_T));

    /* End of SignalConversion: '<S5>/TmpSignal ConversionAtM3Inport3' */

    /* MATLAB Function: '<S5>/Centripetal Force' */
    /* MATLAB Function 'Interaction dynamics1/Centripetal Force': '<S66>:1' */
    /* '<S66>:1:2' */
    /* generates skew- symmetric matrix from vector */
    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    q[0] = IPC4M_B.x[3];
    q[1] = -IPC4M_B.x[4];
    q[2] = -IPC4M_B.x[5];
    q[3] = -IPC4M_B.x[6];

    /* generates skew- symmetric matrix from vector */
    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    b_q[0] = IPC4M_B.x[3];
    b_q[1] = -IPC4M_B.x[4];
    b_q[2] = -IPC4M_B.x[5];
    b_q[3] = -IPC4M_B.x[6];

    /* generates skew- symmetric matrix from vector */
    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    c_q[0] = IPC4M_B.x[3];
    c_q[1] = -IPC4M_B.x[4];
    c_q[2] = -IPC4M_B.x[5];
    c_q[3] = -IPC4M_B.x[6];

    /* generates skew- symmetric matrix from vector */
    /*  Quaternion q based rotation of vector r, e.g. from object-based to world */
    /*  frame */
    d_q[0] = IPC4M_B.x[3];
    d_q[1] = -IPC4M_B.x[4];
    d_q[2] = -IPC4M_B.x[5];
    d_q[3] = -IPC4M_B.x[6];
    tmp_0[0] = 0.0;
    tmp_0[1] = IPC4M_P.r[0];
    tmp_0[2] = IPC4M_P.r[1];
    tmp_0[3] = IPC4M_P.r[2];
    IPC4M_quatmultiply_p(tmp_0, q, tmp_17);
    IPC4M_quatmultiply_p(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, tmp_18);
    tmp_1[0] = 0.0;
    tmp_1[1] = IPC4M_P.r[3];
    tmp_1[2] = IPC4M_P.r[4];
    tmp_1[3] = IPC4M_P.r[5];
    IPC4M_quatmultiply_p(tmp_1, b_q, tmp_17);
    IPC4M_quatmultiply_p(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, tmp_19);
    tmp_2[0] = 0.0;
    tmp_2[1] = IPC4M_P.r[6];
    tmp_2[2] = IPC4M_P.r[7];
    tmp_2[3] = IPC4M_P.r[8];
    IPC4M_quatmultiply_p(tmp_2, c_q, tmp_17);
    IPC4M_quatmultiply_p(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, tmp_1a);
    tmp_3[0] = 0.0;
    tmp_3[1] = IPC4M_P.r[9];
    tmp_3[2] = IPC4M_P.r[10];
    tmp_3[3] = IPC4M_P.r[11];
    IPC4M_quatmultiply_p(tmp_3, d_q, tmp_17);
    IPC4M_quatmultiply_p(*(real_T (*)[4])&IPC4M_B.x[3], tmp_17, tmp_1b);

    /* Product: '<S5>/M3' incorporates:
     *  Constant: '<S5>/Inertia'
     */
    rt_mldivide_U1d30x30_U_kRq1hM_n(IPC4M_P.Inertia_Value_h0,
      rtb_TmpSignalConversionAtM3Inpo, tmp_4);

    /* MATLAB Function: '<S5>/Centripetal Force' incorporates:
     *  Sum: '<S5>/Add'
     */
    tmp_2f[0] = 0.0;
    tmp_2f[3] = -IPC4M_B.Gdx_o[5];
    tmp_2f[6] = IPC4M_B.Gdx_o[4];
    tmp_2f[1] = IPC4M_B.Gdx_o[5];
    tmp_2f[4] = 0.0;
    tmp_2f[7] = -IPC4M_B.Gdx_o[3];
    tmp_2f[2] = -IPC4M_B.Gdx_o[4];
    tmp_2f[5] = IPC4M_B.Gdx_o[3];
    tmp_2f[8] = 0.0;
    tmp_2g[0] = 0.0;
    tmp_2g[3] = -IPC4M_B.Gdx_o[5];
    tmp_2g[6] = IPC4M_B.Gdx_o[4];
    tmp_2g[1] = IPC4M_B.Gdx_o[5];
    tmp_2g[4] = 0.0;
    tmp_2g[7] = -IPC4M_B.Gdx_o[3];
    tmp_2g[2] = -IPC4M_B.Gdx_o[4];
    tmp_2g[5] = IPC4M_B.Gdx_o[3];
    tmp_2g[8] = 0.0;
    for (i = 0; i < 3; i++) {
      for (i_1 = 0; i_1 < 3; i_1++) {
        tmp_1e[i + 3 * i_1] = 0.0;
        tmp_1e[i + 3 * i_1] += tmp_2g[3 * i_1] * tmp_2f[i];
        tmp_1e[i + 3 * i_1] += tmp_2g[3 * i_1 + 1] * tmp_2f[i + 3];
        tmp_1e[i + 3 * i_1] += tmp_2g[3 * i_1 + 2] * tmp_2f[i + 6];
      }
    }

    tmp_2h[0] = 0.0;
    tmp_2h[3] = -IPC4M_B.Gdx_o[5];
    tmp_2h[6] = IPC4M_B.Gdx_o[4];
    tmp_2h[1] = IPC4M_B.Gdx_o[5];
    tmp_2h[4] = 0.0;
    tmp_2h[7] = -IPC4M_B.Gdx_o[3];
    tmp_2h[2] = -IPC4M_B.Gdx_o[4];
    tmp_2h[5] = IPC4M_B.Gdx_o[3];
    tmp_2h[8] = 0.0;
    tmp_2i[0] = 0.0;
    tmp_2i[3] = -IPC4M_B.Gdx_o[5];
    tmp_2i[6] = IPC4M_B.Gdx_o[4];
    tmp_2i[1] = IPC4M_B.Gdx_o[5];
    tmp_2i[4] = 0.0;
    tmp_2i[7] = -IPC4M_B.Gdx_o[3];
    tmp_2i[2] = -IPC4M_B.Gdx_o[4];
    tmp_2i[5] = IPC4M_B.Gdx_o[3];
    tmp_2i[8] = 0.0;
    for (i = 0; i < 3; i++) {
      for (i_1 = 0; i_1 < 3; i_1++) {
        tmp_1f[i + 3 * i_1] = 0.0;
        tmp_1f[i + 3 * i_1] += tmp_2i[3 * i_1] * tmp_2h[i];
        tmp_1f[i + 3 * i_1] += tmp_2i[3 * i_1 + 1] * tmp_2h[i + 3];
        tmp_1f[i + 3 * i_1] += tmp_2i[3 * i_1 + 2] * tmp_2h[i + 6];
      }
    }

    tmp_2j[0] = 0.0;
    tmp_2j[3] = -IPC4M_B.Gdx_o[5];
    tmp_2j[6] = IPC4M_B.Gdx_o[4];
    tmp_2j[1] = IPC4M_B.Gdx_o[5];
    tmp_2j[4] = 0.0;
    tmp_2j[7] = -IPC4M_B.Gdx_o[3];
    tmp_2j[2] = -IPC4M_B.Gdx_o[4];
    tmp_2j[5] = IPC4M_B.Gdx_o[3];
    tmp_2j[8] = 0.0;
    tmp_2k[0] = 0.0;
    tmp_2k[3] = -IPC4M_B.Gdx_o[5];
    tmp_2k[6] = IPC4M_B.Gdx_o[4];
    tmp_2k[1] = IPC4M_B.Gdx_o[5];
    tmp_2k[4] = 0.0;
    tmp_2k[7] = -IPC4M_B.Gdx_o[3];
    tmp_2k[2] = -IPC4M_B.Gdx_o[4];
    tmp_2k[5] = IPC4M_B.Gdx_o[3];
    tmp_2k[8] = 0.0;
    for (i = 0; i < 3; i++) {
      for (i_1 = 0; i_1 < 3; i_1++) {
        tmp_1g[i + 3 * i_1] = 0.0;
        tmp_1g[i + 3 * i_1] += tmp_2k[3 * i_1] * tmp_2j[i];
        tmp_1g[i + 3 * i_1] += tmp_2k[3 * i_1 + 1] * tmp_2j[i + 3];
        tmp_1g[i + 3 * i_1] += tmp_2k[3 * i_1 + 2] * tmp_2j[i + 6];
      }
    }

    tmp_2l[0] = 0.0;
    tmp_2l[3] = -IPC4M_B.Gdx_o[5];
    tmp_2l[6] = IPC4M_B.Gdx_o[4];
    tmp_2l[1] = IPC4M_B.Gdx_o[5];
    tmp_2l[4] = 0.0;
    tmp_2l[7] = -IPC4M_B.Gdx_o[3];
    tmp_2l[2] = -IPC4M_B.Gdx_o[4];
    tmp_2l[5] = IPC4M_B.Gdx_o[3];
    tmp_2l[8] = 0.0;
    tmp_2m[0] = 0.0;
    tmp_2m[3] = -IPC4M_B.Gdx_o[5];
    tmp_2m[6] = IPC4M_B.Gdx_o[4];
    tmp_2m[1] = IPC4M_B.Gdx_o[5];
    tmp_2m[4] = 0.0;
    tmp_2m[7] = -IPC4M_B.Gdx_o[3];
    tmp_2m[2] = -IPC4M_B.Gdx_o[4];
    tmp_2m[5] = IPC4M_B.Gdx_o[3];
    tmp_2m[8] = 0.0;
    for (i = 0; i < 3; i++) {
      for (i_1 = 0; i_1 < 3; i_1++) {
        tmp_1h[i + 3 * i_1] = 0.0;
        tmp_1h[i + 3 * i_1] += tmp_2m[3 * i_1] * tmp_2l[i];
        tmp_1h[i + 3 * i_1] += tmp_2m[3 * i_1 + 1] * tmp_2l[i + 3];
        tmp_1h[i + 3 * i_1] += tmp_2m[3 * i_1 + 2] * tmp_2l[i + 6];
      }
    }

    for (i = 0; i < 3; i++) {
      c_a_1[i] = tmp_1e[i + 6] * tmp_18[3] + (tmp_1e[i + 3] * tmp_18[2] +
        tmp_1e[i] * tmp_18[1]);
    }

    for (i = 0; i < 3; i++) {
      tmp_1n[i] = tmp_1f[i + 6] * tmp_19[3] + (tmp_1f[i + 3] * tmp_19[2] +
        tmp_1f[i] * tmp_19[1]);
    }

    for (i = 0; i < 3; i++) {
      tmp_1o[i] = tmp_1g[i + 6] * tmp_1a[3] + (tmp_1g[i + 3] * tmp_1a[2] +
        tmp_1g[i] * tmp_1a[1]);
    }

    for (i = 0; i < 3; i++) {
      tmp_1p[i] = tmp_1h[i + 6] * tmp_1b[3] + (tmp_1h[i + 3] * tmp_1b[2] +
        tmp_1h[i] * tmp_1b[1]);
    }

    tmp_2n[0] = c_a_1[0];
    tmp_2n[1] = c_a_1[1];
    tmp_2n[2] = c_a_1[2];
    tmp_2n[3] = 0.0;
    tmp_2n[4] = 0.0;
    tmp_2n[5] = 0.0;
    tmp_2n[6] = tmp_1n[0];
    tmp_2n[7] = tmp_1n[1];
    tmp_2n[8] = tmp_1n[2];
    tmp_2n[9] = 0.0;
    tmp_2n[10] = 0.0;
    tmp_2n[11] = 0.0;
    tmp_2n[12] = tmp_1o[0];
    tmp_2n[13] = tmp_1o[1];
    tmp_2n[14] = tmp_1o[2];
    tmp_2n[15] = 0.0;
    tmp_2n[16] = 0.0;
    tmp_2n[17] = 0.0;
    tmp_2n[18] = tmp_1p[0];
    tmp_2n[19] = tmp_1p[1];
    tmp_2n[20] = tmp_1p[2];
    tmp_2n[21] = 0.0;
    tmp_2n[22] = 0.0;
    tmp_2n[23] = 0.0;
    for (i = 0; i < 24; i++) {
      /* Product: '<S5>/M3' */
      rtb_Transpose_a[i] = 0.0;
      for (i_1 = 0; i_1 < 30; i_1++) {
        rtb_Transpose_a[i] += IPC4M_B.A_c[24 * i_1 + i] * tmp_4[i_1];
      }

      /* Sum: '<S5>/Add' incorporates:
       *  Product: '<S5>/M3'
       */
      rtb_Mult[i] = tmp_2n[i] - rtb_Transpose_a[i];
    }

    if (rtmIsMajorTimeStep(IPC4M_M)) {
      /* Sqrt: '<S5>/Sqrt' incorporates:
       *  Constant: '<S5>/Inertia'
       */
      for (i = 0; i < 900; i++) {
        IPC4M_B.Sqrt_n[i] = sqrt(IPC4M_P.Inertia_Value_h0[i]);
      }

      /* End of Sqrt: '<S5>/Sqrt' */
    }

    /* Product: '<S5>/M2' */
    /* Copy input to temporary space */
    rt_mrdivide_U1d24x30_U_zeNn4d_n(IPC4M_B.A_c, IPC4M_B.Sqrt_n, IPC4M_B.dv0);

    /* S-Function (sdsppinv): '<S5>/Pseudoinverse' */
    memcpy(&IPC4M_DW.Pseudoinverse_X_o[0], &IPC4M_B.dv0[0], 720U * sizeof(real_T));

    /* Call SVD */
    i = MWDSP_SVD_D(&IPC4M_DW.Pseudoinverse_X_o[0U], 24, 30, &Pseudoinverse_S_d
                    [0U], &Pseudoinverse_E_d[0U], &Pseudoinverse_WORK_l[0U],
                    &IPC4M_DW.Pseudoinverse_U_b[0U],
                    &IPC4M_DW.Pseudoinverse_V_e[0U], 1);

    /* Only call 'pinv' function if SVD succeeded */
    if (i == 0) {
      MWDSPCG_Pseudoinverse_D(&Pseudoinverse_S_d[0U],
        &IPC4M_DW.Pseudoinverse_U_b[0U], &IPC4M_DW.Pseudoinverse_V_e[0U],
        &IPC4M_B.Pseudoinverse_o[0U], 24, 30);
    }

    /* End of S-Function (sdsppinv): '<S5>/Pseudoinverse' */

    /* Product: '<S5>/M1' */
    for (i = 0; i < 30; i++) {
      rtb_Pseudoinverse_o_0[i] = 0.0;
      for (i_1 = 0; i_1 < 24; i_1++) {
        rtb_Pseudoinverse_o_0[i] += IPC4M_B.Pseudoinverse_o[30 * i_1 + i] *
          rtb_Mult[i_1];
      }
    }

    for (i = 0; i < 30; i++) {
      /* Product: '<S5>/M1' */
      tmp_4[i] = 0.0;
      for (i_1 = 0; i_1 < 30; i_1++) {
        tmp_4[i] += IPC4M_B.Sqrt_n[30 * i_1 + i] * rtb_Pseudoinverse_o_0[i_1];
      }

      /* Sum: '<S5>/Add1' incorporates:
       *  Product: '<S5>/M1'
       */
      tmp[i] = tmp_4[i] + rtb_TmpSignalConversionAtM3Inpo[i];
    }

    /* Product: '<S5>/M' incorporates:
     *  Constant: '<S5>/Inertia'
     */
    rt_mldivide_U1d30x30_U_kRq1hM_n(IPC4M_P.Inertia_Value_h0, tmp, IPC4M_B.M);

    /* Product: '<S6>/M_o*ddx_do' incorporates:
     *  Constant: '<S6>/Object Inertia'
     */
    for (i = 0; i < 6; i++) {
      IPC4M_B.M_oddx_do[i] = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        IPC4M_B.M_oddx_do[i] += IPC4M_P.ObjectInertia_Value[6 * i_1 + i] *
          rtb_Derivative[i_1];
      }
    }

    for (i = 0; i < 5; i++) {
      /* SignalConversion: '<S69>/TmpSignal ConversionAt SFunction Inport1' incorporates:
       *  MATLAB Function: '<S6>/Coriolis Force'
       */
      rtb_TmpSignalConversionAtSFun_e[i] = IPC4M_B.Gain1[i];
    }

    /* End of Product: '<S6>/M_o*ddx_do' */

    /* MATLAB Function: '<S6>/Coriolis Force' incorporates:
     *  SignalConversion: '<S69>/TmpSignal ConversionAt SFunction Inport1'
     */
    /* MATLAB Function 'Inverse Dynamics/Coriolis Force': '<S69>:1' */
    /* '<S69>:1:2' */
    /* generates skew- symmetric matrix from vector */
    tmp_2o[0] = 0.0;
    tmp_2o[3] = -IPC4M_B.SineWave;
    tmp_2o[6] = rtb_TmpSignalConversionAtSFun_e[4];
    tmp_2o[1] = IPC4M_B.SineWave;
    tmp_2o[4] = 0.0;
    tmp_2o[7] = -rtb_TmpSignalConversionAtSFun_e[3];
    tmp_2o[2] = -rtb_TmpSignalConversionAtSFun_e[4];
    tmp_2o[5] = rtb_TmpSignalConversionAtSFun_e[3];
    tmp_2o[8] = 0.0;
    for (i = 0; i < 3; i++) {
      tmp_1e[3 * i] = tmp_2o[3 * i] * IPC4M_P.m0;
      tmp_1e[1 + 3 * i] = tmp_2o[3 * i + 1] * IPC4M_P.m0;
      tmp_1e[2 + 3 * i] = tmp_2o[3 * i + 2] * IPC4M_P.m0;
    }

    tmp_2p[0] = 0.0;
    tmp_2p[3] = -IPC4M_B.SineWave;
    tmp_2p[6] = rtb_TmpSignalConversionAtSFun_e[4];
    tmp_2p[1] = IPC4M_B.SineWave;
    tmp_2p[4] = 0.0;
    tmp_2p[7] = -rtb_TmpSignalConversionAtSFun_e[3];
    tmp_2p[2] = -rtb_TmpSignalConversionAtSFun_e[4];
    tmp_2p[5] = rtb_TmpSignalConversionAtSFun_e[3];
    tmp_2p[8] = 0.0;
    for (i = 0; i < 3; i++) {
      tmp_1f[3 * i] = tmp_2p[3 * i] * IPC4M_P.j0;
      tmp_1f[1 + 3 * i] = tmp_2p[3 * i + 1] * IPC4M_P.j0;
      tmp_1f[2 + 3 * i] = tmp_2p[3 * i + 2] * IPC4M_P.j0;
    }

    for (i = 0; i < 3; i++) {
      c_a_1[i] = tmp_1e[i + 6] * rtb_TmpSignalConversionAtSFun_e[2] + (tmp_1e[i
        + 3] * rtb_TmpSignalConversionAtSFun_e[1] + tmp_1e[i] *
        rtb_TmpSignalConversionAtSFun_e[0]);
    }

    for (i = 0; i < 3; i++) {
      tmp_1n[i] = tmp_1f[i + 6] * IPC4M_B.SineWave + (tmp_1f[i + 3] *
        rtb_TmpSignalConversionAtSFun_e[4] + tmp_1f[i] *
        rtb_TmpSignalConversionAtSFun_e[3]);
    }

    IPC4M_B.hcoriolis[0] = c_a_1[0];
    IPC4M_B.hcoriolis[1] = c_a_1[1];
    IPC4M_B.hcoriolis[2] = c_a_1[2];
    IPC4M_B.hcoriolis[3] = tmp_1n[0];
    IPC4M_B.hcoriolis[4] = tmp_1n[1];
    IPC4M_B.hcoriolis[5] = tmp_1n[2];

    /* MATLAB Function: '<S6>/MATLAB Function3' */
    IPC4M_MATLABFunction3(IPC4M_B.x, &IPC4M_B.sf_MATLABFunction3_a);

    /* S-Function (sdsppinv): '<S6>/Pseudoinverse' */
    /* Copy input to temporary space */
    memcpy(&Pseudoinverse_X_h[0], &IPC4M_B.sf_MATLABFunction3_a.G[0], 144U *
           sizeof(real_T));

    /* Call SVD */
    i = MWDSP_SVD_D(&Pseudoinverse_X_h[0U], 6, 24, &Pseudoinverse_S_h[0U],
                    &Pseudoinverse_E_k[0U], &Pseudoinverse_WORK_lf[0U],
                    &Pseudoinverse_U_a[0U], &IPC4M_DW.Pseudoinverse_V_h[0U], 1);

    /* Only call 'pinv' function if SVD succeeded */
    if (i == 0) {
      MWDSPCG_Pseudoinverse_D(&Pseudoinverse_S_h[0U], &Pseudoinverse_U_a[0U],
        &IPC4M_DW.Pseudoinverse_V_h[0U], &rtb_Pseudoinverse_j[0U], 6, 24);
    }

    /* End of S-Function (sdsppinv): '<S6>/Pseudoinverse' */

    /* Sum: '<S6>/h_od' incorporates:
     *  Constant: '<S6>/Gravitation'
     *  Product: '<S6>/h_d = G+ *h_od'
     */
    for (i = 0; i < 6; i++) {
      tmp_1c[i] = (IPC4M_P.Gravitation_Value_i[i] + IPC4M_B.hcoriolis[i]) +
        IPC4M_B.M_oddx_do[i];
    }

    /* End of Sum: '<S6>/h_od' */

    /* Product: '<S6>/h_d = G+ *h_od' */
    for (i = 0; i < 24; i++) {
      IPC4M_B.h_dGh_od[i] = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        IPC4M_B.h_dGh_od[i] += rtb_Pseudoinverse_j[24 * i_1 + i] * tmp_1c[i_1];
      }
    }

    if (rtmIsMajorTimeStep(IPC4M_M)) {
    }

    /* Math: '<S9>/Transpose' */
    for (i = 0; i < 18; i++) {
      for (i_1 = 0; i_1 < 24; i_1++) {
        rtb_Transpose[i_1 + 24 * i] = rtb_Ared_b[18 * i_1 + i];
      }
    }

    /* End of Math: '<S9>/Transpose' */
    if (rtmIsMajorTimeStep(IPC4M_M)) {
    }

    /* Sum: '<S10>/Add' incorporates:
     *  Fcn: '<S10>/Fcn'
     *  Fcn: '<S10>/Fcn1'
     *  Fcn: '<S10>/Fcn2'
     */
    IPC4M_B.Add_o = (rt_powd_snf(IPC4M_B.x[14], 2.0) + rt_powd_snf(IPC4M_B.x[15],
      2.0)) + rt_powd_snf(IPC4M_B.x[16], 2.0);
    if (rtmIsMajorTimeStep(IPC4M_M)) {
    }

    /* Gain: '<S80>/Gain' */
    x_o[0] = IPC4M_P.Gain_Gain * IPC4M_B.Integrator_f[3];
    x_o[1] = IPC4M_P.Gain_Gain * IPC4M_B.Integrator_f[4];
    x_o[2] = IPC4M_P.Gain_Gain * IPC4M_B.Integrator_f[5];

    /* Sum: '<S84>/Sum' incorporates:
     *  Constant: '<S80>/Constant'
     *  Product: '<S84>/Product'
     *  Product: '<S84>/Product1'
     *  Product: '<S84>/Product2'
     *  Product: '<S84>/Product3'
     */
    IPC4M_B.Sum_l = ((IPC4M_P.Constant_Value * IPC4M_B.Integrator[0] - x_o[0] *
                      IPC4M_B.Integrator[1]) - x_o[1] * IPC4M_B.Integrator[2]) -
      x_o[2] * IPC4M_B.Integrator[3];

    /* Sum: '<S85>/Sum' incorporates:
     *  Constant: '<S80>/Constant'
     *  Product: '<S85>/Product'
     *  Product: '<S85>/Product1'
     *  Product: '<S85>/Product2'
     *  Product: '<S85>/Product3'
     */
    IPC4M_B.Sum_a = ((IPC4M_P.Constant_Value * IPC4M_B.Integrator[1] + x_o[0] *
                      IPC4M_B.Integrator[0]) + x_o[1] * IPC4M_B.Integrator[3]) -
      x_o[2] * IPC4M_B.Integrator[2];

    /* Sum: '<S86>/Sum' incorporates:
     *  Constant: '<S80>/Constant'
     *  Product: '<S86>/Product'
     *  Product: '<S86>/Product1'
     *  Product: '<S86>/Product2'
     *  Product: '<S86>/Product3'
     */
    IPC4M_B.Sum_ak = ((IPC4M_P.Constant_Value * IPC4M_B.Integrator[2] - x_o[0] *
                       IPC4M_B.Integrator[3]) + x_o[1] * IPC4M_B.Integrator[0])
      + x_o[2] * IPC4M_B.Integrator[1];

    /* Sum: '<S87>/Sum' incorporates:
     *  Constant: '<S80>/Constant'
     *  Product: '<S87>/Product'
     *  Product: '<S87>/Product1'
     *  Product: '<S87>/Product2'
     *  Product: '<S87>/Product3'
     */
    IPC4M_B.Sum_e = ((IPC4M_P.Constant_Value * IPC4M_B.Integrator[3] + x_o[0] *
                      IPC4M_B.Integrator[2]) - x_o[1] * IPC4M_B.Integrator[1]) +
      x_o[2] * IPC4M_B.Integrator[0];
    if (rtmIsMajorTimeStep(IPC4M_M)) {
    }

    /* Gain: '<S89>/Gain' */
    x_o[0] = IPC4M_P.Gain_Gain_k * IPC4M_B.Gain1[3];
    x_o[1] = IPC4M_P.Gain_Gain_k * IPC4M_B.Gain1[4];
    x_o[2] = IPC4M_P.Gain_Gain_k * IPC4M_B.SineWave;

    /* Sum: '<S92>/Sum' incorporates:
     *  Constant: '<S89>/Constant'
     *  Product: '<S92>/Product'
     *  Product: '<S92>/Product1'
     *  Product: '<S92>/Product2'
     *  Product: '<S92>/Product3'
     */
    IPC4M_B.Sum_j = ((IPC4M_P.Constant_Value_c * IPC4M_B.Integrator_g[0] - x_o[0]
                      * IPC4M_B.Integrator_g[1]) - x_o[1] *
                     IPC4M_B.Integrator_g[2]) - x_o[2] * IPC4M_B.Integrator_g[3];

    /* Sum: '<S93>/Sum' incorporates:
     *  Constant: '<S89>/Constant'
     *  Product: '<S93>/Product'
     *  Product: '<S93>/Product1'
     *  Product: '<S93>/Product2'
     *  Product: '<S93>/Product3'
     */
    IPC4M_B.Sum_d = ((IPC4M_P.Constant_Value_c * IPC4M_B.Integrator_g[1] + x_o[0]
                      * IPC4M_B.Integrator_g[0]) + x_o[1] *
                     IPC4M_B.Integrator_g[3]) - x_o[2] * IPC4M_B.Integrator_g[2];

    /* Sum: '<S94>/Sum' incorporates:
     *  Constant: '<S89>/Constant'
     *  Product: '<S94>/Product'
     *  Product: '<S94>/Product1'
     *  Product: '<S94>/Product2'
     *  Product: '<S94>/Product3'
     */
    IPC4M_B.Sum_lp = ((IPC4M_P.Constant_Value_c * IPC4M_B.Integrator_g[2] - x_o
                       [0] * IPC4M_B.Integrator_g[3]) + x_o[1] *
                      IPC4M_B.Integrator_g[0]) + x_o[2] * IPC4M_B.Integrator_g[1];

    /* Sum: '<S95>/Sum' incorporates:
     *  Constant: '<S89>/Constant'
     *  Product: '<S95>/Product'
     *  Product: '<S95>/Product1'
     *  Product: '<S95>/Product2'
     *  Product: '<S95>/Product3'
     */
    IPC4M_B.Sum_m = ((IPC4M_P.Constant_Value_c * IPC4M_B.Integrator_g[3] + x_o[0]
                      * IPC4M_B.Integrator_g[2]) - x_o[1] *
                     IPC4M_B.Integrator_g[1]) + x_o[2] * IPC4M_B.Integrator_g[0];
    if (rtmIsMajorTimeStep(IPC4M_M)) {
      /* Constant: '<Root>/Desired Internal Forces1' */
      memcpy(&rtb_DesiredInternalForces1[0],
             &IPC4M_P.DesiredInternalForces1_Value[0], 18U * sizeof(real_T));
    }
  }

  if (rtmIsMajorTimeStep(IPC4M_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(IPC4M_M->rtwLogInfo, (IPC4M_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(IPC4M_M)) {
    real_T (*lastU)[6];
    int32_T i;

    /* Update for Derivative: '<S13>/Derivative' */
    if (IPC4M_DW.TimeStampA == (rtInf)) {
      IPC4M_DW.TimeStampA = IPC4M_M->Timing.t[0];
      lastU = (real_T (*)[6])IPC4M_DW.LastUAtTimeA;
    } else if (IPC4M_DW.TimeStampB == (rtInf)) {
      IPC4M_DW.TimeStampB = IPC4M_M->Timing.t[0];
      lastU = (real_T (*)[6])IPC4M_DW.LastUAtTimeB;
    } else if (IPC4M_DW.TimeStampA < IPC4M_DW.TimeStampB) {
      IPC4M_DW.TimeStampA = IPC4M_M->Timing.t[0];
      lastU = (real_T (*)[6])IPC4M_DW.LastUAtTimeA;
    } else {
      IPC4M_DW.TimeStampB = IPC4M_M->Timing.t[0];
      lastU = (real_T (*)[6])IPC4M_DW.LastUAtTimeB;
    }

    for (i = 0; i < 6; i++) {
      (*lastU)[i] = IPC4M_B.TmpSignalConversionAtdxGdx_odIn[i];
    }

    /* End of Update for Derivative: '<S13>/Derivative' */
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(IPC4M_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(IPC4M_M)!=-1) &&
          !((rtmGetTFinal(IPC4M_M)-(((IPC4M_M->Timing.clockTick1+
               IPC4M_M->Timing.clockTickH1* 4294967296.0)) * 0.01)) >
            (((IPC4M_M->Timing.clockTick1+IPC4M_M->Timing.clockTickH1*
               4294967296.0)) * 0.01) * (DBL_EPSILON))) {
        rtmSetErrorStatus(IPC4M_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&IPC4M_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++IPC4M_M->Timing.clockTick0)) {
      ++IPC4M_M->Timing.clockTickH0;
    }

    IPC4M_M->Timing.t[0] = rtsiGetSolverStopTime(&IPC4M_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      IPC4M_M->Timing.clockTick1++;
      if (!IPC4M_M->Timing.clockTick1) {
        IPC4M_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void IPC4M_derivatives(void)
{
  int32_T i;
  XDot_IPC4M_T *_rtXdot;
  _rtXdot = ((XDot_IPC4M_T *) IPC4M_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S10>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[0] = IPC4M_B.Integrator_f[0];
  _rtXdot->Integrator1_CSTATE[1] = IPC4M_B.Integrator_f[1];
  _rtXdot->Integrator1_CSTATE[2] = IPC4M_B.Integrator_f[2];

  /* Derivatives for Integrator: '<S80>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = IPC4M_B.Sum_l;
  _rtXdot->Integrator_CSTATE[1] = IPC4M_B.Sum_a;
  _rtXdot->Integrator_CSTATE[2] = IPC4M_B.Sum_ak;
  _rtXdot->Integrator_CSTATE[3] = IPC4M_B.Sum_e;

  /* Derivatives for Integrator: '<S10>/Integrator' */
  for (i = 0; i < 6; i++) {
    _rtXdot->Integrator_CSTATE_f[i] = IPC4M_B.M[i];
  }

  /* End of Derivatives for Integrator: '<S10>/Integrator' */

  /* Derivatives for TransferFcn: '<Root>/PT1 Filter' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  _rtXdot->PT1Filter_CSTATE = 0.0;
  _rtXdot->PT1Filter_CSTATE += IPC4M_P.PT1Filter_A * IPC4M_X.PT1Filter_CSTATE;
  _rtXdot->PT1Filter_CSTATE += IPC4M_P.Constant1_Value;

  /* Derivatives for Integrator: '<S13>/Integrator' */
  _rtXdot->Integrator_CSTATE_i[0] = IPC4M_B.Gain1[0];
  _rtXdot->Integrator_CSTATE_i[1] = IPC4M_B.Gain1[1];
  _rtXdot->Integrator_CSTATE_i[2] = IPC4M_B.Gain1[2];

  /* Derivatives for Integrator: '<S89>/Integrator' */
  _rtXdot->Integrator_CSTATE_e[0] = IPC4M_B.Sum_j;
  _rtXdot->Integrator_CSTATE_e[1] = IPC4M_B.Sum_d;
  _rtXdot->Integrator_CSTATE_e[2] = IPC4M_B.Sum_lp;
  _rtXdot->Integrator_CSTATE_e[3] = IPC4M_B.Sum_m;
}

/* Model initialize function */
void IPC4M_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)IPC4M_M, 0,
                sizeof(RT_MODEL_IPC4M_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&IPC4M_M->solverInfo, &IPC4M_M->Timing.simTimeStep);
    rtsiSetTPtr(&IPC4M_M->solverInfo, &rtmGetTPtr(IPC4M_M));
    rtsiSetStepSizePtr(&IPC4M_M->solverInfo, &IPC4M_M->Timing.stepSize0);
    rtsiSetdXPtr(&IPC4M_M->solverInfo, &IPC4M_M->ModelData.derivs);
    rtsiSetContStatesPtr(&IPC4M_M->solverInfo, (real_T **)
                         &IPC4M_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&IPC4M_M->solverInfo, &IPC4M_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&IPC4M_M->solverInfo, (&rtmGetErrorStatus(IPC4M_M)));
    rtsiSetRTModelPtr(&IPC4M_M->solverInfo, IPC4M_M);
  }

  rtsiSetSimTimeStep(&IPC4M_M->solverInfo, MAJOR_TIME_STEP);
  IPC4M_M->ModelData.intgData.y = IPC4M_M->ModelData.odeY;
  IPC4M_M->ModelData.intgData.f[0] = IPC4M_M->ModelData.odeF[0];
  IPC4M_M->ModelData.intgData.f[1] = IPC4M_M->ModelData.odeF[1];
  IPC4M_M->ModelData.intgData.f[2] = IPC4M_M->ModelData.odeF[2];
  IPC4M_M->ModelData.contStates = ((X_IPC4M_T *) &IPC4M_X);
  rtsiSetSolverData(&IPC4M_M->solverInfo, (void *)&IPC4M_M->ModelData.intgData);
  rtsiSetSolverName(&IPC4M_M->solverInfo,"ode3");
  rtmSetTPtr(IPC4M_M, &IPC4M_M->Timing.tArray[0]);
  rtmSetTFinal(IPC4M_M, 10.0);
  IPC4M_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    IPC4M_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(IPC4M_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(IPC4M_M->rtwLogInfo, (NULL));
    rtliSetLogT(IPC4M_M->rtwLogInfo, "tout");
    rtliSetLogX(IPC4M_M->rtwLogInfo, "");
    rtliSetLogXFinal(IPC4M_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(IPC4M_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(IPC4M_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(IPC4M_M->rtwLogInfo, 0);
    rtliSetLogDecimation(IPC4M_M->rtwLogInfo, 1);
    rtliSetLogY(IPC4M_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(IPC4M_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(IPC4M_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &IPC4M_B), 0,
                sizeof(B_IPC4M_T));

  /* states (continuous) */
  {
    (void) memset((void *)&IPC4M_X, 0,
                  sizeof(X_IPC4M_T));
  }

  /* states (dwork) */
  (void) memset((void *)&IPC4M_DW, 0,
                sizeof(DW_IPC4M_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(IPC4M_M->rtwLogInfo, 0.0, rtmGetTFinal
    (IPC4M_M), IPC4M_M->Timing.stepSize0, (&rtmGetErrorStatus(IPC4M_M)));

  {
    int32_T i;

    /* InitializeConditions for Integrator: '<S10>/Integrator1' */
    IPC4M_X.Integrator1_CSTATE[0] = IPC4M_P.Integrator1_IC[0];
    IPC4M_X.Integrator1_CSTATE[1] = IPC4M_P.Integrator1_IC[1];
    IPC4M_X.Integrator1_CSTATE[2] = IPC4M_P.Integrator1_IC[2];

    /* InitializeConditions for Integrator: '<S80>/Integrator' */
    IPC4M_X.Integrator_CSTATE[0] = IPC4M_P.Integrator_IC[0];
    IPC4M_X.Integrator_CSTATE[1] = IPC4M_P.Integrator_IC[1];
    IPC4M_X.Integrator_CSTATE[2] = IPC4M_P.Integrator_IC[2];
    IPC4M_X.Integrator_CSTATE[3] = IPC4M_P.Integrator_IC[3];

    /* InitializeConditions for Integrator: '<S10>/Integrator' */
    for (i = 0; i < 6; i++) {
      IPC4M_X.Integrator_CSTATE_f[i] = IPC4M_P.Integrator_IC_i[i];
    }

    /* End of InitializeConditions for Integrator: '<S10>/Integrator' */

    /* InitializeConditions for TransferFcn: '<Root>/PT1 Filter' */
    IPC4M_X.PT1Filter_CSTATE = 0.0;

    /* InitializeConditions for Integrator: '<S13>/Integrator' */
    IPC4M_X.Integrator_CSTATE_i[0] = IPC4M_P.Integrator_IC_j[0];
    IPC4M_X.Integrator_CSTATE_i[1] = IPC4M_P.Integrator_IC_j[1];
    IPC4M_X.Integrator_CSTATE_i[2] = IPC4M_P.Integrator_IC_j[2];

    /* InitializeConditions for Integrator: '<S89>/Integrator' */
    IPC4M_X.Integrator_CSTATE_e[0] = IPC4M_P.Integrator_IC_o[0];
    IPC4M_X.Integrator_CSTATE_e[1] = IPC4M_P.Integrator_IC_o[1];
    IPC4M_X.Integrator_CSTATE_e[2] = IPC4M_P.Integrator_IC_o[2];
    IPC4M_X.Integrator_CSTATE_e[3] = IPC4M_P.Integrator_IC_o[3];

    /* InitializeConditions for Derivative: '<S13>/Derivative' */
    IPC4M_DW.TimeStampA = (rtInf);
    IPC4M_DW.TimeStampB = (rtInf);
  }
}

/* Model terminate function */
void IPC4M_terminate(void)
{
  /* (no terminate code required) */
}

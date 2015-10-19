/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Model1angular_sfun.h"
#include "c6_Model1angular.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Model1angular_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c6_debug_family_names[5] = { "G", "nargin", "nargout", "r",
  "IV" };

static const char * c6_b_debug_family_names[4] = { "nargin", "nargout", "x", "X"
};

/* Function Declarations */
static void initialize_c6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance);
static void initialize_params_c6_Model1angular(SFc6_Model1angularInstanceStruct *
  chartInstance);
static void enable_c6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance);
static void disable_c6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance);
static void c6_update_debugger_state_c6_Model1angular
  (SFc6_Model1angularInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c6_Model1angular
  (SFc6_Model1angularInstanceStruct *chartInstance);
static void set_sim_state_c6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_st);
static void finalize_c6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance);
static void sf_gateway_c6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance);
static void mdl_start_c6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance);
static void initSimStructsc6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static void c6_emlrt_marshallIn(SFc6_Model1angularInstanceStruct *chartInstance,
  const mxArray *c6_b_IV, const char_T *c6_identifier, real_T c6_y[144]);
static void c6_b_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[144]);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_c_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[6]);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_d_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_e_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[72]);
static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_f_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[9]);
static void c6_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_f_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_g_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[3]);
static void c6_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static void c6_info_helper(const mxArray **c6_info);
static const mxArray *c6_emlrt_marshallOut(const char * c6_u);
static const mxArray *c6_b_emlrt_marshallOut(const uint32_T c6_u);
static void c6_b_info_helper(const mxArray **c6_info);
static void c6_c_info_helper(const mxArray **c6_info);
static void c6_d_info_helper(const mxArray **c6_info);
static void c6_eye(SFc6_Model1angularInstanceStruct *chartInstance, real_T c6_I
                   [9]);
static void c6_eml_switch_helper(SFc6_Model1angularInstanceStruct *chartInstance);
static void c6_pinv(SFc6_Model1angularInstanceStruct *chartInstance, real_T
                    c6_A[72], real_T c6_X[72]);
static void c6_eml_scalar_eg(SFc6_Model1angularInstanceStruct *chartInstance);
static void c6_eml_error(SFc6_Model1angularInstanceStruct *chartInstance);
static void c6_eml_xgesvd(SFc6_Model1angularInstanceStruct *chartInstance,
  real_T c6_A[72], real_T c6_U[72], real_T c6_S[6], real_T c6_V[36]);
static real_T c6_eml_xnrm2(SFc6_Model1angularInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_x[72], int32_T c6_ix0);
static boolean_T c6_use_refblas(SFc6_Model1angularInstanceStruct *chartInstance);
static void c6_threshold(SFc6_Model1angularInstanceStruct *chartInstance);
static real_T c6_abs(SFc6_Model1angularInstanceStruct *chartInstance, real_T
                     c6_x);
static void c6_realmin(SFc6_Model1angularInstanceStruct *chartInstance);
static void c6_check_forloop_overflow_error(SFc6_Model1angularInstanceStruct
  *chartInstance, boolean_T c6_overflow);
static void c6_eps(SFc6_Model1angularInstanceStruct *chartInstance);
static void c6_b_eml_switch_helper(SFc6_Model1angularInstanceStruct
  *chartInstance);
static real_T c6_eml_xdotc(SFc6_Model1angularInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_x[72], int32_T c6_ix0, real_T c6_y[72], int32_T c6_iy0);
static void c6_b_threshold(SFc6_Model1angularInstanceStruct *chartInstance);
static void c6_eml_xaxpy(SFc6_Model1angularInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, int32_T c6_ix0, real_T c6_y[72], int32_T c6_iy0,
  real_T c6_b_y[72]);
static void c6_c_threshold(SFc6_Model1angularInstanceStruct *chartInstance);
static real_T c6_b_eml_xnrm2(SFc6_Model1angularInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_x[6], int32_T c6_ix0);
static void c6_b_eml_xaxpy(SFc6_Model1angularInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, real_T c6_x[72], int32_T c6_ix0, real_T c6_y[12],
  int32_T c6_iy0, real_T c6_b_y[12]);
static void c6_c_eml_xaxpy(SFc6_Model1angularInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, real_T c6_x[12], int32_T c6_ix0, real_T c6_y[72],
  int32_T c6_iy0, real_T c6_b_y[72]);
static real_T c6_b_eml_xdotc(SFc6_Model1angularInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_x[36], int32_T c6_ix0, real_T c6_y[36], int32_T c6_iy0);
static void c6_d_eml_xaxpy(SFc6_Model1angularInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, int32_T c6_ix0, real_T c6_y[36], int32_T c6_iy0,
  real_T c6_b_y[36]);
static void c6_eml_xscal(SFc6_Model1angularInstanceStruct *chartInstance, real_T
  c6_a, real_T c6_x[72], int32_T c6_ix0, real_T c6_b_x[72]);
static void c6_b_eml_xscal(SFc6_Model1angularInstanceStruct *chartInstance,
  real_T c6_a, real_T c6_x[36], int32_T c6_ix0, real_T c6_b_x[36]);
static void c6_b_eml_scalar_eg(SFc6_Model1angularInstanceStruct *chartInstance);
static void c6_b_eml_error(SFc6_Model1angularInstanceStruct *chartInstance);
static real_T c6_sqrt(SFc6_Model1angularInstanceStruct *chartInstance, real_T
                      c6_x);
static void c6_c_eml_error(SFc6_Model1angularInstanceStruct *chartInstance);
static void c6_eml_xrotg(SFc6_Model1angularInstanceStruct *chartInstance, real_T
  c6_a, real_T c6_b, real_T *c6_b_a, real_T *c6_b_b, real_T *c6_c, real_T *c6_s);
static void c6_eml_xrot(SFc6_Model1angularInstanceStruct *chartInstance, real_T
  c6_x[36], int32_T c6_ix0, int32_T c6_iy0, real_T c6_c, real_T c6_s, real_T
  c6_b_x[36]);
static void c6_d_threshold(SFc6_Model1angularInstanceStruct *chartInstance);
static void c6_b_eml_xrot(SFc6_Model1angularInstanceStruct *chartInstance,
  real_T c6_x[72], int32_T c6_ix0, int32_T c6_iy0, real_T c6_c, real_T c6_s,
  real_T c6_b_x[72]);
static void c6_c_eml_scalar_eg(SFc6_Model1angularInstanceStruct *chartInstance);
static void c6_eml_xswap(SFc6_Model1angularInstanceStruct *chartInstance, real_T
  c6_x[36], int32_T c6_ix0, int32_T c6_iy0, real_T c6_b_x[36]);
static void c6_c_eml_switch_helper(SFc6_Model1angularInstanceStruct
  *chartInstance);
static void c6_b_eml_xswap(SFc6_Model1angularInstanceStruct *chartInstance,
  real_T c6_x[72], int32_T c6_ix0, int32_T c6_iy0, real_T c6_b_x[72]);
static void c6_eml_xgemm(SFc6_Model1angularInstanceStruct *chartInstance,
  int32_T c6_k, real_T c6_A[36], real_T c6_B[72], real_T c6_C[72], real_T
  c6_b_C[72]);
static void c6_e_threshold(SFc6_Model1angularInstanceStruct *chartInstance);
static void c6_d_eml_scalar_eg(SFc6_Model1angularInstanceStruct *chartInstance);
static void c6_b_eml_xgemm(SFc6_Model1angularInstanceStruct *chartInstance,
  real_T c6_A[72], real_T c6_B[72], real_T c6_C[144], real_T c6_b_C[144]);
static const mxArray *c6_g_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_h_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static uint8_T c6_i_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_Model1angular, const char_T
  *c6_identifier);
static uint8_T c6_j_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_e_eml_xaxpy(SFc6_Model1angularInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, int32_T c6_ix0, real_T c6_y[72], int32_T c6_iy0);
static void c6_f_eml_xaxpy(SFc6_Model1angularInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, real_T c6_x[72], int32_T c6_ix0, real_T c6_y[12],
  int32_T c6_iy0);
static void c6_g_eml_xaxpy(SFc6_Model1angularInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, real_T c6_x[12], int32_T c6_ix0, real_T c6_y[72],
  int32_T c6_iy0);
static void c6_h_eml_xaxpy(SFc6_Model1angularInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, int32_T c6_ix0, real_T c6_y[36], int32_T c6_iy0);
static void c6_c_eml_xscal(SFc6_Model1angularInstanceStruct *chartInstance,
  real_T c6_a, real_T c6_x[72], int32_T c6_ix0);
static void c6_d_eml_xscal(SFc6_Model1angularInstanceStruct *chartInstance,
  real_T c6_a, real_T c6_x[36], int32_T c6_ix0);
static void c6_b_sqrt(SFc6_Model1angularInstanceStruct *chartInstance, real_T
                      *c6_x);
static void c6_b_eml_xrotg(SFc6_Model1angularInstanceStruct *chartInstance,
  real_T *c6_a, real_T *c6_b, real_T *c6_c, real_T *c6_s);
static void c6_c_eml_xrot(SFc6_Model1angularInstanceStruct *chartInstance,
  real_T c6_x[36], int32_T c6_ix0, int32_T c6_iy0, real_T c6_c, real_T c6_s);
static void c6_d_eml_xrot(SFc6_Model1angularInstanceStruct *chartInstance,
  real_T c6_x[72], int32_T c6_ix0, int32_T c6_iy0, real_T c6_c, real_T c6_s);
static void c6_c_eml_xswap(SFc6_Model1angularInstanceStruct *chartInstance,
  real_T c6_x[36], int32_T c6_ix0, int32_T c6_iy0);
static void c6_d_eml_xswap(SFc6_Model1angularInstanceStruct *chartInstance,
  real_T c6_x[72], int32_T c6_ix0, int32_T c6_iy0);
static void c6_c_eml_xgemm(SFc6_Model1angularInstanceStruct *chartInstance,
  int32_T c6_k, real_T c6_A[36], real_T c6_B[72], real_T c6_C[72]);
static void c6_d_eml_xgemm(SFc6_Model1angularInstanceStruct *chartInstance,
  real_T c6_A[72], real_T c6_B[72], real_T c6_C[144]);
static void init_dsm_address_info(SFc6_Model1angularInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc6_Model1angularInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance)
{
  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c6_is_active_c6_Model1angular = 0U;
}

static void initialize_params_c6_Model1angular(SFc6_Model1angularInstanceStruct *
  chartInstance)
{
  real_T c6_dv0[6];
  int32_T c6_i0;
  sf_mex_import_named("r", sf_mex_get_sfun_param(chartInstance->S, 0, 0), c6_dv0,
                      0, 0, 0U, 1, 0U, 1, 6);
  for (c6_i0 = 0; c6_i0 < 6; c6_i0++) {
    chartInstance->c6_r[c6_i0] = c6_dv0[c6_i0];
  }
}

static void enable_c6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c6_update_debugger_state_c6_Model1angular
  (SFc6_Model1angularInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c6_Model1angular
  (SFc6_Model1angularInstanceStruct *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  int32_T c6_i1;
  real_T c6_u[144];
  const mxArray *c6_b_y = NULL;
  uint8_T c6_hoistedGlobal;
  uint8_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellmatrix(2, 1), false);
  for (c6_i1 = 0; c6_i1 < 144; c6_i1++) {
    c6_u[c6_i1] = (*chartInstance->c6_IV)[c6_i1];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 12, 12),
                false);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_hoistedGlobal = chartInstance->c6_is_active_c6_Model1angular;
  c6_b_u = c6_hoistedGlobal;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  sf_mex_assign(&c6_st, c6_y, false);
  return c6_st;
}

static void set_sim_state_c6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_st)
{
  const mxArray *c6_u;
  real_T c6_dv1[144];
  int32_T c6_i2;
  chartInstance->c6_doneDoubleBufferReInit = true;
  c6_u = sf_mex_dup(c6_st);
  c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 0)), "IV",
                      c6_dv1);
  for (c6_i2 = 0; c6_i2 < 144; c6_i2++) {
    (*chartInstance->c6_IV)[c6_i2] = c6_dv1[c6_i2];
  }

  chartInstance->c6_is_active_c6_Model1angular = c6_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 1)),
     "is_active_c6_Model1angular");
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_Model1angular(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance)
{
  int32_T c6_i3;
  int32_T c6_i4;
  real_T c6_b_r[6];
  uint32_T c6_debug_family_var_map[5];
  real_T c6_G[72];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  real_T c6_b_IV[144];
  int32_T c6_i5;
  real_T c6_x[3];
  uint32_T c6_b_debug_family_var_map[4];
  real_T c6_b_nargin = 1.0;
  real_T c6_b_nargout = 1.0;
  real_T c6_X[9];
  int32_T c6_i6;
  real_T c6_b_x[3];
  real_T c6_c_nargin = 1.0;
  real_T c6_c_nargout = 1.0;
  real_T c6_b_X[9];
  real_T c6_dv2[9];
  real_T c6_dv3[9];
  real_T c6_dv4[9];
  real_T c6_dv5[9];
  int32_T c6_i7;
  int32_T c6_i8;
  int32_T c6_i9;
  int32_T c6_i10;
  int32_T c6_i11;
  int32_T c6_i12;
  int32_T c6_i13;
  int32_T c6_i14;
  int32_T c6_i15;
  int32_T c6_i16;
  int32_T c6_i17;
  int32_T c6_i18;
  int32_T c6_i19;
  int32_T c6_i20;
  int32_T c6_i21;
  int32_T c6_i22;
  int32_T c6_i23;
  int32_T c6_i24;
  int32_T c6_i25;
  int32_T c6_i26;
  int32_T c6_i27;
  int32_T c6_i28;
  int32_T c6_i29;
  int32_T c6_i30;
  int32_T c6_i31;
  int32_T c6_i32;
  int32_T c6_i33;
  int32_T c6_i34;
  int32_T c6_i35;
  int32_T c6_i36;
  int32_T c6_i37;
  real_T c6_I[144];
  int32_T c6_k;
  int32_T c6_b_k;
  int32_T c6_i38;
  real_T c6_b_G[72];
  real_T c6_a[72];
  int32_T c6_i39;
  real_T c6_b[72];
  int32_T c6_i40;
  real_T c6_y[144];
  int32_T c6_i41;
  real_T c6_b_a[72];
  int32_T c6_i42;
  real_T c6_b_b[72];
  int32_T c6_i43;
  int32_T c6_i44;
  int32_T c6_i45;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  for (c6_i3 = 0; c6_i3 < 6; c6_i3++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c6_r[c6_i3], 0U);
  }

  chartInstance->c6_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  for (c6_i4 = 0; c6_i4 < 6; c6_i4++) {
    c6_b_r[c6_i4] = chartInstance->c6_r[c6_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c6_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_G, 0U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 1U, c6_c_sf_marshallOut,
    c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 2U, c6_c_sf_marshallOut,
    c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_b_r, 3U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_b_IV, 4U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 2);
  for (c6_i5 = 0; c6_i5 < 3; c6_i5++) {
    c6_x[c6_i5] = c6_b_r[c6_i5];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c6_b_debug_family_names,
    c6_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_nargin, 0U, c6_c_sf_marshallOut,
    c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_nargout, 1U, c6_c_sf_marshallOut,
    c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_x, 2U, c6_f_sf_marshallOut,
    c6_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_X, 3U, c6_e_sf_marshallOut,
    c6_e_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 3);
  c6_X[0] = 0.0;
  c6_X[3] = -c6_x[2];
  c6_X[6] = c6_x[1];
  c6_X[1] = c6_x[2];
  c6_X[4] = 0.0;
  c6_X[7] = -c6_x[0];
  c6_X[2] = -c6_x[1];
  c6_X[5] = c6_x[0];
  c6_X[8] = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c6_i6 = 0; c6_i6 < 3; c6_i6++) {
    c6_b_x[c6_i6] = c6_b_r[c6_i6 + 3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c6_b_debug_family_names,
    c6_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_nargin, 0U, c6_c_sf_marshallOut,
    c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_nargout, 1U, c6_c_sf_marshallOut,
    c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_b_x, 2U, c6_f_sf_marshallOut,
    c6_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_b_X, 3U, c6_e_sf_marshallOut,
    c6_e_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 3);
  c6_b_X[0] = 0.0;
  c6_b_X[3] = -c6_b_x[2];
  c6_b_X[6] = c6_b_x[1];
  c6_b_X[1] = c6_b_x[2];
  c6_b_X[4] = 0.0;
  c6_b_X[7] = -c6_b_x[0];
  c6_b_X[2] = -c6_b_x[1];
  c6_b_X[5] = c6_b_x[0];
  c6_b_X[8] = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  c6_eye(chartInstance, c6_dv2);
  c6_eye(chartInstance, c6_dv3);
  c6_eye(chartInstance, c6_dv4);
  c6_eye(chartInstance, c6_dv5);
  c6_i7 = 0;
  c6_i8 = 0;
  for (c6_i9 = 0; c6_i9 < 3; c6_i9++) {
    for (c6_i10 = 0; c6_i10 < 3; c6_i10++) {
      c6_G[c6_i10 + c6_i7] = c6_dv2[c6_i10 + c6_i8];
    }

    c6_i7 += 6;
    c6_i8 += 3;
  }

  c6_i11 = 0;
  for (c6_i12 = 0; c6_i12 < 3; c6_i12++) {
    for (c6_i13 = 0; c6_i13 < 3; c6_i13++) {
      c6_G[(c6_i13 + c6_i11) + 18] = 0.0;
    }

    c6_i11 += 6;
  }

  c6_i14 = 0;
  c6_i15 = 0;
  for (c6_i16 = 0; c6_i16 < 3; c6_i16++) {
    for (c6_i17 = 0; c6_i17 < 3; c6_i17++) {
      c6_G[(c6_i17 + c6_i14) + 36] = c6_dv3[c6_i17 + c6_i15];
    }

    c6_i14 += 6;
    c6_i15 += 3;
  }

  c6_i18 = 0;
  for (c6_i19 = 0; c6_i19 < 3; c6_i19++) {
    for (c6_i20 = 0; c6_i20 < 3; c6_i20++) {
      c6_G[(c6_i20 + c6_i18) + 54] = 0.0;
    }

    c6_i18 += 6;
  }

  c6_i21 = 0;
  c6_i22 = 0;
  for (c6_i23 = 0; c6_i23 < 3; c6_i23++) {
    for (c6_i24 = 0; c6_i24 < 3; c6_i24++) {
      c6_G[(c6_i24 + c6_i21) + 3] = c6_X[c6_i24 + c6_i22];
    }

    c6_i21 += 6;
    c6_i22 += 3;
  }

  c6_i25 = 0;
  c6_i26 = 0;
  for (c6_i27 = 0; c6_i27 < 3; c6_i27++) {
    for (c6_i28 = 0; c6_i28 < 3; c6_i28++) {
      c6_G[(c6_i28 + c6_i25) + 21] = c6_dv4[c6_i28 + c6_i26];
    }

    c6_i25 += 6;
    c6_i26 += 3;
  }

  c6_i29 = 0;
  c6_i30 = 0;
  for (c6_i31 = 0; c6_i31 < 3; c6_i31++) {
    for (c6_i32 = 0; c6_i32 < 3; c6_i32++) {
      c6_G[(c6_i32 + c6_i29) + 39] = c6_b_X[c6_i32 + c6_i30];
    }

    c6_i29 += 6;
    c6_i30 += 3;
  }

  c6_i33 = 0;
  c6_i34 = 0;
  for (c6_i35 = 0; c6_i35 < 3; c6_i35++) {
    for (c6_i36 = 0; c6_i36 < 3; c6_i36++) {
      c6_G[(c6_i36 + c6_i33) + 57] = c6_dv5[c6_i36 + c6_i34];
    }

    c6_i33 += 6;
    c6_i34 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 3);
  for (c6_i37 = 0; c6_i37 < 144; c6_i37++) {
    c6_I[c6_i37] = 0.0;
  }

  c6_eml_switch_helper(chartInstance);
  for (c6_k = 1; c6_k < 13; c6_k++) {
    c6_b_k = c6_k;
    c6_I[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_b_k), 1, 12, 1, 0) + 12 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_k), 1, 12, 2, 0) - 1))
      - 1] = 1.0;
  }

  for (c6_i38 = 0; c6_i38 < 72; c6_i38++) {
    c6_b_G[c6_i38] = c6_G[c6_i38];
  }

  c6_pinv(chartInstance, c6_b_G, c6_a);
  for (c6_i39 = 0; c6_i39 < 72; c6_i39++) {
    c6_b[c6_i39] = c6_G[c6_i39];
  }

  c6_d_eml_scalar_eg(chartInstance);
  c6_d_eml_scalar_eg(chartInstance);
  for (c6_i40 = 0; c6_i40 < 144; c6_i40++) {
    c6_y[c6_i40] = 0.0;
  }

  for (c6_i41 = 0; c6_i41 < 72; c6_i41++) {
    c6_b_a[c6_i41] = c6_a[c6_i41];
  }

  for (c6_i42 = 0; c6_i42 < 72; c6_i42++) {
    c6_b_b[c6_i42] = c6_b[c6_i42];
  }

  c6_d_eml_xgemm(chartInstance, c6_b_a, c6_b_b, c6_y);
  for (c6_i43 = 0; c6_i43 < 144; c6_i43++) {
    c6_b_IV[c6_i43] = c6_I[c6_i43] - c6_y[c6_i43];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c6_i44 = 0; c6_i44 < 144; c6_i44++) {
    (*chartInstance->c6_IV)[c6_i44] = c6_b_IV[c6_i44];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Model1angularMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c6_i45 = 0; c6_i45 < 144; c6_i45++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c6_IV)[c6_i45], 1U);
  }
}

static void mdl_start_c6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber)
{
  (void)c6_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c6_chartNumber, c6_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Martin\\Documents\\MATLAB\\Masterarbeit\\Bonitz96\\skew_sm.m"));
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i46;
  int32_T c6_i47;
  int32_T c6_i48;
  real_T c6_b_inData[144];
  int32_T c6_i49;
  int32_T c6_i50;
  int32_T c6_i51;
  real_T c6_u[144];
  const mxArray *c6_y = NULL;
  SFc6_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc6_Model1angularInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_i46 = 0;
  for (c6_i47 = 0; c6_i47 < 12; c6_i47++) {
    for (c6_i48 = 0; c6_i48 < 12; c6_i48++) {
      c6_b_inData[c6_i48 + c6_i46] = (*(real_T (*)[144])c6_inData)[c6_i48 +
        c6_i46];
    }

    c6_i46 += 12;
  }

  c6_i49 = 0;
  for (c6_i50 = 0; c6_i50 < 12; c6_i50++) {
    for (c6_i51 = 0; c6_i51 < 12; c6_i51++) {
      c6_u[c6_i51 + c6_i49] = c6_b_inData[c6_i51 + c6_i49];
    }

    c6_i49 += 12;
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 12, 12), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static void c6_emlrt_marshallIn(SFc6_Model1angularInstanceStruct *chartInstance,
  const mxArray *c6_b_IV, const char_T *c6_identifier, real_T c6_y[144])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_IV), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_b_IV);
}

static void c6_b_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[144])
{
  real_T c6_dv6[144];
  int32_T c6_i52;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv6, 1, 0, 0U, 1, 0U, 2, 12,
                12);
  for (c6_i52 = 0; c6_i52 < 144; c6_i52++) {
    c6_y[c6_i52] = c6_dv6[c6_i52];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_IV;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[144];
  int32_T c6_i53;
  int32_T c6_i54;
  int32_T c6_i55;
  SFc6_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc6_Model1angularInstanceStruct *)chartInstanceVoid;
  c6_b_IV = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_IV), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_b_IV);
  c6_i53 = 0;
  for (c6_i54 = 0; c6_i54 < 12; c6_i54++) {
    for (c6_i55 = 0; c6_i55 < 12; c6_i55++) {
      (*(real_T (*)[144])c6_outData)[c6_i55 + c6_i53] = c6_y[c6_i55 + c6_i53];
    }

    c6_i53 += 12;
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i56;
  real_T c6_b_inData[6];
  int32_T c6_i57;
  real_T c6_u[6];
  const mxArray *c6_y = NULL;
  SFc6_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc6_Model1angularInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i56 = 0; c6_i56 < 6; c6_i56++) {
    c6_b_inData[c6_i56] = (*(real_T (*)[6])c6_inData)[c6_i56];
  }

  for (c6_i57 = 0; c6_i57 < 6; c6_i57++) {
    c6_u[c6_i57] = c6_b_inData[c6_i57];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static void c6_c_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[6])
{
  real_T c6_dv7[6];
  int32_T c6_i58;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv7, 1, 0, 0U, 1, 0U, 1, 6);
  for (c6_i58 = 0; c6_i58 < 6; c6_i58++) {
    c6_y[c6_i58] = c6_dv7[c6_i58];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_r;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[6];
  int32_T c6_i59;
  SFc6_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc6_Model1angularInstanceStruct *)chartInstanceVoid;
  c6_b_r = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_r), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_b_r);
  for (c6_i59 = 0; c6_i59 < 6; c6_i59++) {
    (*(real_T (*)[6])c6_outData)[c6_i59] = c6_y[c6_i59];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc6_Model1angularInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static real_T c6_d_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d0, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_nargout;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc6_Model1angularInstanceStruct *)chartInstanceVoid;
  c6_nargout = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_nargout), &c6_thisId);
  sf_mex_destroy(&c6_nargout);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i60;
  int32_T c6_i61;
  int32_T c6_i62;
  real_T c6_b_inData[72];
  int32_T c6_i63;
  int32_T c6_i64;
  int32_T c6_i65;
  real_T c6_u[72];
  const mxArray *c6_y = NULL;
  SFc6_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc6_Model1angularInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_i60 = 0;
  for (c6_i61 = 0; c6_i61 < 12; c6_i61++) {
    for (c6_i62 = 0; c6_i62 < 6; c6_i62++) {
      c6_b_inData[c6_i62 + c6_i60] = (*(real_T (*)[72])c6_inData)[c6_i62 +
        c6_i60];
    }

    c6_i60 += 6;
  }

  c6_i63 = 0;
  for (c6_i64 = 0; c6_i64 < 12; c6_i64++) {
    for (c6_i65 = 0; c6_i65 < 6; c6_i65++) {
      c6_u[c6_i65 + c6_i63] = c6_b_inData[c6_i65 + c6_i63];
    }

    c6_i63 += 6;
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 6, 12), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static void c6_e_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[72])
{
  real_T c6_dv8[72];
  int32_T c6_i66;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv8, 1, 0, 0U, 1, 0U, 2, 6, 12);
  for (c6_i66 = 0; c6_i66 < 72; c6_i66++) {
    c6_y[c6_i66] = c6_dv8[c6_i66];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_G;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[72];
  int32_T c6_i67;
  int32_T c6_i68;
  int32_T c6_i69;
  SFc6_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc6_Model1angularInstanceStruct *)chartInstanceVoid;
  c6_G = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_G), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_G);
  c6_i67 = 0;
  for (c6_i68 = 0; c6_i68 < 12; c6_i68++) {
    for (c6_i69 = 0; c6_i69 < 6; c6_i69++) {
      (*(real_T (*)[72])c6_outData)[c6_i69 + c6_i67] = c6_y[c6_i69 + c6_i67];
    }

    c6_i67 += 6;
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i70;
  int32_T c6_i71;
  int32_T c6_i72;
  real_T c6_b_inData[9];
  int32_T c6_i73;
  int32_T c6_i74;
  int32_T c6_i75;
  real_T c6_u[9];
  const mxArray *c6_y = NULL;
  SFc6_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc6_Model1angularInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_i70 = 0;
  for (c6_i71 = 0; c6_i71 < 3; c6_i71++) {
    for (c6_i72 = 0; c6_i72 < 3; c6_i72++) {
      c6_b_inData[c6_i72 + c6_i70] = (*(real_T (*)[9])c6_inData)[c6_i72 + c6_i70];
    }

    c6_i70 += 3;
  }

  c6_i73 = 0;
  for (c6_i74 = 0; c6_i74 < 3; c6_i74++) {
    for (c6_i75 = 0; c6_i75 < 3; c6_i75++) {
      c6_u[c6_i75 + c6_i73] = c6_b_inData[c6_i75 + c6_i73];
    }

    c6_i73 += 3;
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static void c6_f_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[9])
{
  real_T c6_dv9[9];
  int32_T c6_i76;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv9, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c6_i76 = 0; c6_i76 < 9; c6_i76++) {
    c6_y[c6_i76] = c6_dv9[c6_i76];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_X;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[9];
  int32_T c6_i77;
  int32_T c6_i78;
  int32_T c6_i79;
  SFc6_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc6_Model1angularInstanceStruct *)chartInstanceVoid;
  c6_X = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_X), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_X);
  c6_i77 = 0;
  for (c6_i78 = 0; c6_i78 < 3; c6_i78++) {
    for (c6_i79 = 0; c6_i79 < 3; c6_i79++) {
      (*(real_T (*)[9])c6_outData)[c6_i79 + c6_i77] = c6_y[c6_i79 + c6_i77];
    }

    c6_i77 += 3;
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_f_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i80;
  real_T c6_b_inData[3];
  int32_T c6_i81;
  real_T c6_u[3];
  const mxArray *c6_y = NULL;
  SFc6_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc6_Model1angularInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i80 = 0; c6_i80 < 3; c6_i80++) {
    c6_b_inData[c6_i80] = (*(real_T (*)[3])c6_inData)[c6_i80];
  }

  for (c6_i81 = 0; c6_i81 < 3; c6_i81++) {
    c6_u[c6_i81] = c6_b_inData[c6_i81];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static void c6_g_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[3])
{
  real_T c6_dv10[3];
  int32_T c6_i82;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv10, 1, 0, 0U, 1, 0U, 1, 3);
  for (c6_i82 = 0; c6_i82 < 3; c6_i82++) {
    c6_y[c6_i82] = c6_dv10[c6_i82];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_x;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[3];
  int32_T c6_i83;
  SFc6_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc6_Model1angularInstanceStruct *)chartInstanceVoid;
  c6_x = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_x), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_x);
  for (c6_i83 = 0; c6_i83 < 3; c6_i83++) {
    (*(real_T (*)[3])c6_outData)[c6_i83] = c6_y[c6_i83];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

const mxArray *sf_c6_Model1angular_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  sf_mex_assign(&c6_nameCaptureInfo, sf_mex_createstruct("structure", 2, 212, 1),
                false);
  c6_info_helper(&c6_nameCaptureInfo);
  c6_b_info_helper(&c6_nameCaptureInfo);
  c6_c_info_helper(&c6_nameCaptureInfo);
  c6_d_info_helper(&c6_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c6_nameCaptureInfo);
  return c6_nameCaptureInfo;
}

static void c6_info_helper(const mxArray **c6_info)
{
  const mxArray *c6_rhs0 = NULL;
  const mxArray *c6_lhs0 = NULL;
  const mxArray *c6_rhs1 = NULL;
  const mxArray *c6_lhs1 = NULL;
  const mxArray *c6_rhs2 = NULL;
  const mxArray *c6_lhs2 = NULL;
  const mxArray *c6_rhs3 = NULL;
  const mxArray *c6_lhs3 = NULL;
  const mxArray *c6_rhs4 = NULL;
  const mxArray *c6_lhs4 = NULL;
  const mxArray *c6_rhs5 = NULL;
  const mxArray *c6_lhs5 = NULL;
  const mxArray *c6_rhs6 = NULL;
  const mxArray *c6_lhs6 = NULL;
  const mxArray *c6_rhs7 = NULL;
  const mxArray *c6_lhs7 = NULL;
  const mxArray *c6_rhs8 = NULL;
  const mxArray *c6_lhs8 = NULL;
  const mxArray *c6_rhs9 = NULL;
  const mxArray *c6_lhs9 = NULL;
  const mxArray *c6_rhs10 = NULL;
  const mxArray *c6_lhs10 = NULL;
  const mxArray *c6_rhs11 = NULL;
  const mxArray *c6_lhs11 = NULL;
  const mxArray *c6_rhs12 = NULL;
  const mxArray *c6_lhs12 = NULL;
  const mxArray *c6_rhs13 = NULL;
  const mxArray *c6_lhs13 = NULL;
  const mxArray *c6_rhs14 = NULL;
  const mxArray *c6_lhs14 = NULL;
  const mxArray *c6_rhs15 = NULL;
  const mxArray *c6_lhs15 = NULL;
  const mxArray *c6_rhs16 = NULL;
  const mxArray *c6_lhs16 = NULL;
  const mxArray *c6_rhs17 = NULL;
  const mxArray *c6_lhs17 = NULL;
  const mxArray *c6_rhs18 = NULL;
  const mxArray *c6_lhs18 = NULL;
  const mxArray *c6_rhs19 = NULL;
  const mxArray *c6_lhs19 = NULL;
  const mxArray *c6_rhs20 = NULL;
  const mxArray *c6_lhs20 = NULL;
  const mxArray *c6_rhs21 = NULL;
  const mxArray *c6_lhs21 = NULL;
  const mxArray *c6_rhs22 = NULL;
  const mxArray *c6_lhs22 = NULL;
  const mxArray *c6_rhs23 = NULL;
  const mxArray *c6_lhs23 = NULL;
  const mxArray *c6_rhs24 = NULL;
  const mxArray *c6_lhs24 = NULL;
  const mxArray *c6_rhs25 = NULL;
  const mxArray *c6_lhs25 = NULL;
  const mxArray *c6_rhs26 = NULL;
  const mxArray *c6_lhs26 = NULL;
  const mxArray *c6_rhs27 = NULL;
  const mxArray *c6_lhs27 = NULL;
  const mxArray *c6_rhs28 = NULL;
  const mxArray *c6_lhs28 = NULL;
  const mxArray *c6_rhs29 = NULL;
  const mxArray *c6_lhs29 = NULL;
  const mxArray *c6_rhs30 = NULL;
  const mxArray *c6_lhs30 = NULL;
  const mxArray *c6_rhs31 = NULL;
  const mxArray *c6_lhs31 = NULL;
  const mxArray *c6_rhs32 = NULL;
  const mxArray *c6_lhs32 = NULL;
  const mxArray *c6_rhs33 = NULL;
  const mxArray *c6_lhs33 = NULL;
  const mxArray *c6_rhs34 = NULL;
  const mxArray *c6_lhs34 = NULL;
  const mxArray *c6_rhs35 = NULL;
  const mxArray *c6_lhs35 = NULL;
  const mxArray *c6_rhs36 = NULL;
  const mxArray *c6_lhs36 = NULL;
  const mxArray *c6_rhs37 = NULL;
  const mxArray *c6_lhs37 = NULL;
  const mxArray *c6_rhs38 = NULL;
  const mxArray *c6_lhs38 = NULL;
  const mxArray *c6_rhs39 = NULL;
  const mxArray *c6_lhs39 = NULL;
  const mxArray *c6_rhs40 = NULL;
  const mxArray *c6_lhs40 = NULL;
  const mxArray *c6_rhs41 = NULL;
  const mxArray *c6_lhs41 = NULL;
  const mxArray *c6_rhs42 = NULL;
  const mxArray *c6_lhs42 = NULL;
  const mxArray *c6_rhs43 = NULL;
  const mxArray *c6_lhs43 = NULL;
  const mxArray *c6_rhs44 = NULL;
  const mxArray *c6_lhs44 = NULL;
  const mxArray *c6_rhs45 = NULL;
  const mxArray *c6_lhs45 = NULL;
  const mxArray *c6_rhs46 = NULL;
  const mxArray *c6_lhs46 = NULL;
  const mxArray *c6_rhs47 = NULL;
  const mxArray *c6_lhs47 = NULL;
  const mxArray *c6_rhs48 = NULL;
  const mxArray *c6_lhs48 = NULL;
  const mxArray *c6_rhs49 = NULL;
  const mxArray *c6_lhs49 = NULL;
  const mxArray *c6_rhs50 = NULL;
  const mxArray *c6_lhs50 = NULL;
  const mxArray *c6_rhs51 = NULL;
  const mxArray *c6_lhs51 = NULL;
  const mxArray *c6_rhs52 = NULL;
  const mxArray *c6_lhs52 = NULL;
  const mxArray *c6_rhs53 = NULL;
  const mxArray *c6_lhs53 = NULL;
  const mxArray *c6_rhs54 = NULL;
  const mxArray *c6_lhs54 = NULL;
  const mxArray *c6_rhs55 = NULL;
  const mxArray *c6_lhs55 = NULL;
  const mxArray *c6_rhs56 = NULL;
  const mxArray *c6_lhs56 = NULL;
  const mxArray *c6_rhs57 = NULL;
  const mxArray *c6_lhs57 = NULL;
  const mxArray *c6_rhs58 = NULL;
  const mxArray *c6_lhs58 = NULL;
  const mxArray *c6_rhs59 = NULL;
  const mxArray *c6_lhs59 = NULL;
  const mxArray *c6_rhs60 = NULL;
  const mxArray *c6_lhs60 = NULL;
  const mxArray *c6_rhs61 = NULL;
  const mxArray *c6_lhs61 = NULL;
  const mxArray *c6_rhs62 = NULL;
  const mxArray *c6_lhs62 = NULL;
  const mxArray *c6_rhs63 = NULL;
  const mxArray *c6_lhs63 = NULL;
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eye"), "name", "name", 0);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1406838348U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c6_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 1);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1368208230U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c6_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c6_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral"),
                  "context", "context", 3);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("isinf"), "name", "name", 3);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1363739056U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c6_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c6_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 5);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_is_integer_class"), "name",
                  "name", 5);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1286843982U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c6_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 6);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("intmax"), "name", "name", 6);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c6_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 7);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c6_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 8);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("intmin"), "name", "name", 8);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c6_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 9);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c6_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 10);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexIntRelop"),
                  "name", "name", 10);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1326753522U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c6_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!apply_float_relop"),
                  "context", "context", 11);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 11);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c6_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass"),
                  "context", "context", 12);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 12);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1326753196U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c6_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass"),
                  "context", "context", 13);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("intmin"), "name", "name", 13);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c6_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 14);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 14);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c6_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("intmax"), "name", "name", 15);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c6_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 16);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1397282622U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c6_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 17);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("isfi"), "name", "name", 17);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 17);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1346535558U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c6_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 18);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1398900798U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c6_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 19);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("intmax"), "name", "name", 19);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c6_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 20);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("intmin"), "name", "name", 20);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c6_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "context", "context", 21);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("skew_sm"), "name", "name", 21);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/MATLAB/Masterarbeit/Bonitz96/skew_sm.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1439587919U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c6_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "context", "context", 22);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("pinv"), "name", "name", 22);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1286844028U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c6_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv"),
                  "context", "context", 23);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 23);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c6_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv"),
                  "context", "context", 24);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 24);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c6_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 25);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c6_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv"),
                  "context", "context", 26);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("svd"), "name", "name", 26);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1286844032U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c6_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 27);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c6_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 28);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1397282622U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c6_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("isfinite"), "name", "name", 29);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1363739056U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c6_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 30);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c6_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("isinf"), "name", "name", 31);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1363739056U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c6_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("isnan"), "name", "name", 32);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1363739058U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c6_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 33);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c6_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_error"), "name", "name",
                  34);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1343855558U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c6_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_xgesvd"), "name", "name",
                  35);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1286844006U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c6_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m"),
                  "context", "context", 36);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_lapack_xgesvd"), "name",
                  "name", 36);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgesvd.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1286844010U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c6_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgesvd.m"),
                  "context", "context", 37);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_matlab_zsvdc"), "name",
                  "name", 37);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1398900806U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c6_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 38);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 38);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c6_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 39);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("min"), "name", "name", 39);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 39);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 39);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1311280518U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c6_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "context",
                  "context", 40);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 40);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1378321184U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c6_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 41);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 41);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 41);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 41);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c6_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 42);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 42);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 42);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c6_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 43);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 43);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 43);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c6_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 44);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 44);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 44);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c6_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 45);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 45);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c6_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 46);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 46);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 46);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 46);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c6_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 47);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 47);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 47);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c6_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 48);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("max"), "name", "name", 48);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 48);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1311280516U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c6_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 49);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 49);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1378321184U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c6_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 50);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 50);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 50);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c6_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 51);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 51);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 51);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c6_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 52);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 52);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 52);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c6_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 53);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 53);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 53);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c6_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 54);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_relop"), "name", "name",
                  54);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("function_handle"),
                  "dominantType", "dominantType", 54);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m"), "resolved",
                  "resolved", 54);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1342476382U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c6_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m"), "context",
                  "context", 55);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexIntRelop"),
                  "name", "name", 55);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                  "resolved", "resolved", 55);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1326753522U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c6_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 56);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("isnan"), "name", "name", 56);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 56);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 56);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1363739058U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c6_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 57);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 57);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 57);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 57);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c6_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 58);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("max"), "name", "name", 58);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 58);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 58);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1311280516U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c6_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 59);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 59);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 59);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1397282622U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c6_rhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 60);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_xnrm2"), "name", "name",
                  60);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 60);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"),
                  "resolved", "resolved", 60);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1376005892U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c6_rhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs60), "lhs", "lhs",
                  60);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"), "context",
                  "context", 61);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 61);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 61);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 61);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 61);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 61);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 61);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 61);
  sf_mex_assign(&c6_rhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs61), "rhs", "rhs",
                  61);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs61), "lhs", "lhs",
                  61);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"), "context",
                  "context", 62);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.blas.xnrm2"),
                  "name", "name", 62);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 62);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "resolved", "resolved", 62);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 62);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 62);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 62);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 62);
  sf_mex_assign(&c6_rhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs62), "rhs", "rhs",
                  62);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs62), "lhs", "lhs",
                  62);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "context", "context", 63);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 63);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 63);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 63);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 63);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 63);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 63);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 63);
  sf_mex_assign(&c6_rhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs63), "rhs", "rhs",
                  63);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs63), "lhs", "lhs",
                  63);
  sf_mex_destroy(&c6_rhs0);
  sf_mex_destroy(&c6_lhs0);
  sf_mex_destroy(&c6_rhs1);
  sf_mex_destroy(&c6_lhs1);
  sf_mex_destroy(&c6_rhs2);
  sf_mex_destroy(&c6_lhs2);
  sf_mex_destroy(&c6_rhs3);
  sf_mex_destroy(&c6_lhs3);
  sf_mex_destroy(&c6_rhs4);
  sf_mex_destroy(&c6_lhs4);
  sf_mex_destroy(&c6_rhs5);
  sf_mex_destroy(&c6_lhs5);
  sf_mex_destroy(&c6_rhs6);
  sf_mex_destroy(&c6_lhs6);
  sf_mex_destroy(&c6_rhs7);
  sf_mex_destroy(&c6_lhs7);
  sf_mex_destroy(&c6_rhs8);
  sf_mex_destroy(&c6_lhs8);
  sf_mex_destroy(&c6_rhs9);
  sf_mex_destroy(&c6_lhs9);
  sf_mex_destroy(&c6_rhs10);
  sf_mex_destroy(&c6_lhs10);
  sf_mex_destroy(&c6_rhs11);
  sf_mex_destroy(&c6_lhs11);
  sf_mex_destroy(&c6_rhs12);
  sf_mex_destroy(&c6_lhs12);
  sf_mex_destroy(&c6_rhs13);
  sf_mex_destroy(&c6_lhs13);
  sf_mex_destroy(&c6_rhs14);
  sf_mex_destroy(&c6_lhs14);
  sf_mex_destroy(&c6_rhs15);
  sf_mex_destroy(&c6_lhs15);
  sf_mex_destroy(&c6_rhs16);
  sf_mex_destroy(&c6_lhs16);
  sf_mex_destroy(&c6_rhs17);
  sf_mex_destroy(&c6_lhs17);
  sf_mex_destroy(&c6_rhs18);
  sf_mex_destroy(&c6_lhs18);
  sf_mex_destroy(&c6_rhs19);
  sf_mex_destroy(&c6_lhs19);
  sf_mex_destroy(&c6_rhs20);
  sf_mex_destroy(&c6_lhs20);
  sf_mex_destroy(&c6_rhs21);
  sf_mex_destroy(&c6_lhs21);
  sf_mex_destroy(&c6_rhs22);
  sf_mex_destroy(&c6_lhs22);
  sf_mex_destroy(&c6_rhs23);
  sf_mex_destroy(&c6_lhs23);
  sf_mex_destroy(&c6_rhs24);
  sf_mex_destroy(&c6_lhs24);
  sf_mex_destroy(&c6_rhs25);
  sf_mex_destroy(&c6_lhs25);
  sf_mex_destroy(&c6_rhs26);
  sf_mex_destroy(&c6_lhs26);
  sf_mex_destroy(&c6_rhs27);
  sf_mex_destroy(&c6_lhs27);
  sf_mex_destroy(&c6_rhs28);
  sf_mex_destroy(&c6_lhs28);
  sf_mex_destroy(&c6_rhs29);
  sf_mex_destroy(&c6_lhs29);
  sf_mex_destroy(&c6_rhs30);
  sf_mex_destroy(&c6_lhs30);
  sf_mex_destroy(&c6_rhs31);
  sf_mex_destroy(&c6_lhs31);
  sf_mex_destroy(&c6_rhs32);
  sf_mex_destroy(&c6_lhs32);
  sf_mex_destroy(&c6_rhs33);
  sf_mex_destroy(&c6_lhs33);
  sf_mex_destroy(&c6_rhs34);
  sf_mex_destroy(&c6_lhs34);
  sf_mex_destroy(&c6_rhs35);
  sf_mex_destroy(&c6_lhs35);
  sf_mex_destroy(&c6_rhs36);
  sf_mex_destroy(&c6_lhs36);
  sf_mex_destroy(&c6_rhs37);
  sf_mex_destroy(&c6_lhs37);
  sf_mex_destroy(&c6_rhs38);
  sf_mex_destroy(&c6_lhs38);
  sf_mex_destroy(&c6_rhs39);
  sf_mex_destroy(&c6_lhs39);
  sf_mex_destroy(&c6_rhs40);
  sf_mex_destroy(&c6_lhs40);
  sf_mex_destroy(&c6_rhs41);
  sf_mex_destroy(&c6_lhs41);
  sf_mex_destroy(&c6_rhs42);
  sf_mex_destroy(&c6_lhs42);
  sf_mex_destroy(&c6_rhs43);
  sf_mex_destroy(&c6_lhs43);
  sf_mex_destroy(&c6_rhs44);
  sf_mex_destroy(&c6_lhs44);
  sf_mex_destroy(&c6_rhs45);
  sf_mex_destroy(&c6_lhs45);
  sf_mex_destroy(&c6_rhs46);
  sf_mex_destroy(&c6_lhs46);
  sf_mex_destroy(&c6_rhs47);
  sf_mex_destroy(&c6_lhs47);
  sf_mex_destroy(&c6_rhs48);
  sf_mex_destroy(&c6_lhs48);
  sf_mex_destroy(&c6_rhs49);
  sf_mex_destroy(&c6_lhs49);
  sf_mex_destroy(&c6_rhs50);
  sf_mex_destroy(&c6_lhs50);
  sf_mex_destroy(&c6_rhs51);
  sf_mex_destroy(&c6_lhs51);
  sf_mex_destroy(&c6_rhs52);
  sf_mex_destroy(&c6_lhs52);
  sf_mex_destroy(&c6_rhs53);
  sf_mex_destroy(&c6_lhs53);
  sf_mex_destroy(&c6_rhs54);
  sf_mex_destroy(&c6_lhs54);
  sf_mex_destroy(&c6_rhs55);
  sf_mex_destroy(&c6_lhs55);
  sf_mex_destroy(&c6_rhs56);
  sf_mex_destroy(&c6_lhs56);
  sf_mex_destroy(&c6_rhs57);
  sf_mex_destroy(&c6_lhs57);
  sf_mex_destroy(&c6_rhs58);
  sf_mex_destroy(&c6_lhs58);
  sf_mex_destroy(&c6_rhs59);
  sf_mex_destroy(&c6_lhs59);
  sf_mex_destroy(&c6_rhs60);
  sf_mex_destroy(&c6_lhs60);
  sf_mex_destroy(&c6_rhs61);
  sf_mex_destroy(&c6_lhs61);
  sf_mex_destroy(&c6_rhs62);
  sf_mex_destroy(&c6_lhs62);
  sf_mex_destroy(&c6_rhs63);
  sf_mex_destroy(&c6_lhs63);
}

static const mxArray *c6_emlrt_marshallOut(const char * c6_u)
{
  const mxArray *c6_y = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c6_u)), false);
  return c6_y;
}

static const mxArray *c6_b_emlrt_marshallOut(const uint32_T c6_u)
{
  const mxArray *c6_y = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 7, 0U, 0U, 0U, 0), false);
  return c6_y;
}

static void c6_b_info_helper(const mxArray **c6_info)
{
  const mxArray *c6_rhs64 = NULL;
  const mxArray *c6_lhs64 = NULL;
  const mxArray *c6_rhs65 = NULL;
  const mxArray *c6_lhs65 = NULL;
  const mxArray *c6_rhs66 = NULL;
  const mxArray *c6_lhs66 = NULL;
  const mxArray *c6_rhs67 = NULL;
  const mxArray *c6_lhs67 = NULL;
  const mxArray *c6_rhs68 = NULL;
  const mxArray *c6_lhs68 = NULL;
  const mxArray *c6_rhs69 = NULL;
  const mxArray *c6_lhs69 = NULL;
  const mxArray *c6_rhs70 = NULL;
  const mxArray *c6_lhs70 = NULL;
  const mxArray *c6_rhs71 = NULL;
  const mxArray *c6_lhs71 = NULL;
  const mxArray *c6_rhs72 = NULL;
  const mxArray *c6_lhs72 = NULL;
  const mxArray *c6_rhs73 = NULL;
  const mxArray *c6_lhs73 = NULL;
  const mxArray *c6_rhs74 = NULL;
  const mxArray *c6_lhs74 = NULL;
  const mxArray *c6_rhs75 = NULL;
  const mxArray *c6_lhs75 = NULL;
  const mxArray *c6_rhs76 = NULL;
  const mxArray *c6_lhs76 = NULL;
  const mxArray *c6_rhs77 = NULL;
  const mxArray *c6_lhs77 = NULL;
  const mxArray *c6_rhs78 = NULL;
  const mxArray *c6_lhs78 = NULL;
  const mxArray *c6_rhs79 = NULL;
  const mxArray *c6_lhs79 = NULL;
  const mxArray *c6_rhs80 = NULL;
  const mxArray *c6_lhs80 = NULL;
  const mxArray *c6_rhs81 = NULL;
  const mxArray *c6_lhs81 = NULL;
  const mxArray *c6_rhs82 = NULL;
  const mxArray *c6_lhs82 = NULL;
  const mxArray *c6_rhs83 = NULL;
  const mxArray *c6_lhs83 = NULL;
  const mxArray *c6_rhs84 = NULL;
  const mxArray *c6_lhs84 = NULL;
  const mxArray *c6_rhs85 = NULL;
  const mxArray *c6_lhs85 = NULL;
  const mxArray *c6_rhs86 = NULL;
  const mxArray *c6_lhs86 = NULL;
  const mxArray *c6_rhs87 = NULL;
  const mxArray *c6_lhs87 = NULL;
  const mxArray *c6_rhs88 = NULL;
  const mxArray *c6_lhs88 = NULL;
  const mxArray *c6_rhs89 = NULL;
  const mxArray *c6_lhs89 = NULL;
  const mxArray *c6_rhs90 = NULL;
  const mxArray *c6_lhs90 = NULL;
  const mxArray *c6_rhs91 = NULL;
  const mxArray *c6_lhs91 = NULL;
  const mxArray *c6_rhs92 = NULL;
  const mxArray *c6_lhs92 = NULL;
  const mxArray *c6_rhs93 = NULL;
  const mxArray *c6_lhs93 = NULL;
  const mxArray *c6_rhs94 = NULL;
  const mxArray *c6_lhs94 = NULL;
  const mxArray *c6_rhs95 = NULL;
  const mxArray *c6_lhs95 = NULL;
  const mxArray *c6_rhs96 = NULL;
  const mxArray *c6_lhs96 = NULL;
  const mxArray *c6_rhs97 = NULL;
  const mxArray *c6_lhs97 = NULL;
  const mxArray *c6_rhs98 = NULL;
  const mxArray *c6_lhs98 = NULL;
  const mxArray *c6_rhs99 = NULL;
  const mxArray *c6_lhs99 = NULL;
  const mxArray *c6_rhs100 = NULL;
  const mxArray *c6_lhs100 = NULL;
  const mxArray *c6_rhs101 = NULL;
  const mxArray *c6_lhs101 = NULL;
  const mxArray *c6_rhs102 = NULL;
  const mxArray *c6_lhs102 = NULL;
  const mxArray *c6_rhs103 = NULL;
  const mxArray *c6_lhs103 = NULL;
  const mxArray *c6_rhs104 = NULL;
  const mxArray *c6_lhs104 = NULL;
  const mxArray *c6_rhs105 = NULL;
  const mxArray *c6_lhs105 = NULL;
  const mxArray *c6_rhs106 = NULL;
  const mxArray *c6_lhs106 = NULL;
  const mxArray *c6_rhs107 = NULL;
  const mxArray *c6_lhs107 = NULL;
  const mxArray *c6_rhs108 = NULL;
  const mxArray *c6_lhs108 = NULL;
  const mxArray *c6_rhs109 = NULL;
  const mxArray *c6_lhs109 = NULL;
  const mxArray *c6_rhs110 = NULL;
  const mxArray *c6_lhs110 = NULL;
  const mxArray *c6_rhs111 = NULL;
  const mxArray *c6_lhs111 = NULL;
  const mxArray *c6_rhs112 = NULL;
  const mxArray *c6_lhs112 = NULL;
  const mxArray *c6_rhs113 = NULL;
  const mxArray *c6_lhs113 = NULL;
  const mxArray *c6_rhs114 = NULL;
  const mxArray *c6_lhs114 = NULL;
  const mxArray *c6_rhs115 = NULL;
  const mxArray *c6_lhs115 = NULL;
  const mxArray *c6_rhs116 = NULL;
  const mxArray *c6_lhs116 = NULL;
  const mxArray *c6_rhs117 = NULL;
  const mxArray *c6_lhs117 = NULL;
  const mxArray *c6_rhs118 = NULL;
  const mxArray *c6_lhs118 = NULL;
  const mxArray *c6_rhs119 = NULL;
  const mxArray *c6_lhs119 = NULL;
  const mxArray *c6_rhs120 = NULL;
  const mxArray *c6_lhs120 = NULL;
  const mxArray *c6_rhs121 = NULL;
  const mxArray *c6_lhs121 = NULL;
  const mxArray *c6_rhs122 = NULL;
  const mxArray *c6_lhs122 = NULL;
  const mxArray *c6_rhs123 = NULL;
  const mxArray *c6_lhs123 = NULL;
  const mxArray *c6_rhs124 = NULL;
  const mxArray *c6_lhs124 = NULL;
  const mxArray *c6_rhs125 = NULL;
  const mxArray *c6_lhs125 = NULL;
  const mxArray *c6_rhs126 = NULL;
  const mxArray *c6_lhs126 = NULL;
  const mxArray *c6_rhs127 = NULL;
  const mxArray *c6_lhs127 = NULL;
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p!below_threshold"),
                  "context", "context", 64);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.blas.threshold"),
                  "name", "name", 64);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 64);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 64);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 64);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 64);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 64);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 64);
  sf_mex_assign(&c6_rhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs64), "rhs", "rhs",
                  64);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs64), "lhs", "lhs",
                  64);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 65);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 65);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 65);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 65);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 65);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 65);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 65);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 65);
  sf_mex_assign(&c6_rhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs65), "rhs", "rhs",
                  65);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs65), "lhs", "lhs",
                  65);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p!below_threshold"),
                  "context", "context", 66);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("length"), "name", "name", 66);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 66);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 66);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1303171406U), "fileTimeLo",
                  "fileTimeLo", 66);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 66);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 66);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 66);
  sf_mex_assign(&c6_rhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs66), "rhs", "rhs",
                  66);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs66), "lhs", "lhs",
                  66);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength"),
                  "context", "context", 67);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 67);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 67);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 67);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 67);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 67);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 67);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 67);
  sf_mex_assign(&c6_rhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs67), "rhs", "rhs",
                  67);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs67), "lhs", "lhs",
                  67);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "context", "context", 68);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.refblas.xnrm2"),
                  "name", "name", 68);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 68);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "resolved", "resolved", 68);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 68);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 68);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 68);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 68);
  sf_mex_assign(&c6_rhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs68), "rhs", "rhs",
                  68);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs68), "lhs", "lhs",
                  68);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 69);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("abs"), "name", "name", 69);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 69);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 69);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1363739052U), "fileTimeLo",
                  "fileTimeLo", 69);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 69);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 69);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 69);
  sf_mex_assign(&c6_rhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs69), "rhs", "rhs",
                  69);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs69), "lhs", "lhs",
                  69);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 70);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 70);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 70);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 70);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 70);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 70);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 70);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 70);
  sf_mex_assign(&c6_rhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs70), "rhs", "rhs",
                  70);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs70), "lhs", "lhs",
                  70);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 71);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 71);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 71);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 71);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1286843912U), "fileTimeLo",
                  "fileTimeLo", 71);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 71);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 71);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 71);
  sf_mex_assign(&c6_rhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs71), "rhs", "rhs",
                  71);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs71), "lhs", "lhs",
                  71);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 72);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("realmin"), "name", "name", 72);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 72);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 72);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1307676442U), "fileTimeLo",
                  "fileTimeLo", 72);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 72);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 72);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 72);
  sf_mex_assign(&c6_rhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs72), "rhs", "rhs",
                  72);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs72), "lhs", "lhs",
                  72);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "context",
                  "context", 73);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_realmin"), "name", "name",
                  73);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 73);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "resolved",
                  "resolved", 73);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1307676444U), "fileTimeLo",
                  "fileTimeLo", 73);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 73);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 73);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 73);
  sf_mex_assign(&c6_rhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs73), "rhs", "rhs",
                  73);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs73), "lhs", "lhs",
                  73);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "context",
                  "context", 74);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 74);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 74);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 74);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1326753196U), "fileTimeLo",
                  "fileTimeLo", 74);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 74);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 74);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 74);
  sf_mex_assign(&c6_rhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs74), "rhs", "rhs",
                  74);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs74), "lhs", "lhs",
                  74);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 75);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 75);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 75);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 75);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1372608360U), "fileTimeLo",
                  "fileTimeLo", 75);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 75);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 75);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 75);
  sf_mex_assign(&c6_rhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs75), "rhs", "rhs",
                  75);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs75), "lhs", "lhs",
                  75);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 76);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 76);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 76);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 76);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1372608360U), "fileTimeLo",
                  "fileTimeLo", 76);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 76);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 76);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 76);
  sf_mex_assign(&c6_rhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs76), "rhs", "rhs",
                  76);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs76), "lhs", "lhs",
                  76);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 77);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 77);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 77);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 77);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1372608360U), "fileTimeLo",
                  "fileTimeLo", 77);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 77);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 77);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 77);
  sf_mex_assign(&c6_rhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs77), "rhs", "rhs",
                  77);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs77), "lhs", "lhs",
                  77);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 78);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 78);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 78);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 78);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1397282622U), "fileTimeLo",
                  "fileTimeLo", 78);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 78);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 78);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 78);
  sf_mex_assign(&c6_rhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs78), "rhs", "rhs",
                  78);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs78), "lhs", "lhs",
                  78);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 79);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "coder.internal.scaleVectorByRecip"), "name", "name", 79);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 79);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "resolved", "resolved", 79);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 79);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 79);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 79);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 79);
  sf_mex_assign(&c6_rhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs79), "rhs", "rhs",
                  79);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs79), "lhs", "lhs",
                  79);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 80);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("realmin"), "name", "name", 80);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 80);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 80);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1307676442U), "fileTimeLo",
                  "fileTimeLo", 80);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 80);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 80);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 80);
  sf_mex_assign(&c6_rhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs80), "rhs", "rhs",
                  80);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs80), "lhs", "lhs",
                  80);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 81);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eps"), "name", "name", 81);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 81);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 81);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1326753196U), "fileTimeLo",
                  "fileTimeLo", 81);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 81);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 81);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 81);
  sf_mex_assign(&c6_rhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs81), "rhs", "rhs",
                  81);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs81), "lhs", "lhs",
                  81);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 82);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 82);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 82);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 82);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1286843982U), "fileTimeLo",
                  "fileTimeLo", 82);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 82);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 82);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 82);
  sf_mex_assign(&c6_rhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs82), "rhs", "rhs",
                  82);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs82), "lhs", "lhs",
                  82);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 83);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_eps"), "name", "name", 83);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 83);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 83);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1326753196U), "fileTimeLo",
                  "fileTimeLo", 83);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 83);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 83);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 83);
  sf_mex_assign(&c6_rhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs83), "rhs", "rhs",
                  83);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs83), "lhs", "lhs",
                  83);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 84);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 84);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 84);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 84);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1326753196U), "fileTimeLo",
                  "fileTimeLo", 84);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 84);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 84);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 84);
  sf_mex_assign(&c6_rhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs84), "rhs", "rhs",
                  84);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs84), "lhs", "lhs",
                  84);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 85);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("mrdivide"), "name", "name", 85);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 85);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 85);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832848U), "fileTimeLo",
                  "fileTimeLo", 85);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 85);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1370035086U), "mFileTimeLo",
                  "mFileTimeLo", 85);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 85);
  sf_mex_assign(&c6_rhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs85), "rhs", "rhs",
                  85);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs85), "lhs", "lhs",
                  85);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 86);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 86);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 86);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 86);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1389742974U), "fileTimeLo",
                  "fileTimeLo", 86);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 86);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 86);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 86);
  sf_mex_assign(&c6_rhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs86), "rhs", "rhs",
                  86);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs86), "lhs", "lhs",
                  86);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 87);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("rdivide"), "name", "name", 87);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 87);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 87);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1363739080U), "fileTimeLo",
                  "fileTimeLo", 87);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 87);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 87);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 87);
  sf_mex_assign(&c6_rhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs87), "rhs", "rhs",
                  87);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs87), "lhs", "lhs",
                  87);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 88);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 88);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 88);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 88);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 88);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 88);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 88);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 88);
  sf_mex_assign(&c6_rhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs88), "rhs", "rhs",
                  88);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs88), "lhs", "lhs",
                  88);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 89);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 89);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 89);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 89);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1286843996U), "fileTimeLo",
                  "fileTimeLo", 89);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 89);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 89);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 89);
  sf_mex_assign(&c6_rhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs89), "rhs", "rhs",
                  89);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs89), "lhs", "lhs",
                  89);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 90);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_div"), "name", "name", 90);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 90);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 90);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1386449152U), "fileTimeLo",
                  "fileTimeLo", 90);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 90);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 90);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 90);
  sf_mex_assign(&c6_rhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs90), "rhs", "rhs",
                  90);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs90), "lhs", "lhs",
                  90);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 91);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 91);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 91);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 91);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 91);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 91);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 91);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 91);
  sf_mex_assign(&c6_rhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs91), "rhs", "rhs",
                  91);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs91), "lhs", "lhs",
                  91);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 92);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("abs"), "name", "name", 92);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 92);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 92);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1363739052U), "fileTimeLo",
                  "fileTimeLo", 92);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 92);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 92);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 92);
  sf_mex_assign(&c6_rhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs92), "rhs", "rhs",
                  92);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs92), "lhs", "lhs",
                  92);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 93);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.blas.xscal"),
                  "name", "name", 93);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 93);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xscal.p"),
                  "resolved", "resolved", 93);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 93);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 93);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 93);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 93);
  sf_mex_assign(&c6_rhs93, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs93, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs93), "rhs", "rhs",
                  93);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs93), "lhs", "lhs",
                  93);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xscal.p"),
                  "context", "context", 94);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 94);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 94);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 94);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 94);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 94);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 94);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 94);
  sf_mex_assign(&c6_rhs94, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs94, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs94), "rhs", "rhs",
                  94);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs94), "lhs", "lhs",
                  94);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xscal.p!below_threshold"),
                  "context", "context", 95);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.blas.threshold"),
                  "name", "name", 95);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 95);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 95);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 95);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 95);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 95);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 95);
  sf_mex_assign(&c6_rhs95, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs95, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs95), "rhs", "rhs",
                  95);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs95), "lhs", "lhs",
                  95);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xscal.p!below_threshold"),
                  "context", "context", 96);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("length"), "name", "name", 96);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 96);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 96);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1303171406U), "fileTimeLo",
                  "fileTimeLo", 96);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 96);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 96);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 96);
  sf_mex_assign(&c6_rhs96, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs96, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs96), "rhs", "rhs",
                  96);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs96), "lhs", "lhs",
                  96);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xscal.p"),
                  "context", "context", 97);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 97);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 97);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 97);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 97);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 97);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 97);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 97);
  sf_mex_assign(&c6_rhs97, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs97, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs97), "rhs", "rhs",
                  97);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs97), "lhs", "lhs",
                  97);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xscal.p"),
                  "context", "context", 98);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.refblas.xscal"),
                  "name", "name", 98);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 98);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xscal.p"),
                  "resolved", "resolved", 98);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 98);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 98);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 98);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 98);
  sf_mex_assign(&c6_rhs98, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs98, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs98), "rhs", "rhs",
                  98);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs98), "lhs", "lhs",
                  98);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xscal.p"),
                  "context", "context", 99);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 99);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 99);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 99);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1372608360U), "fileTimeLo",
                  "fileTimeLo", 99);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 99);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 99);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 99);
  sf_mex_assign(&c6_rhs99, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs99, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs99), "rhs", "rhs",
                  99);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs99), "lhs", "lhs",
                  99);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xscal.p"),
                  "context", "context", 100);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 100);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 100);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 100);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1372608360U), "fileTimeLo",
                  "fileTimeLo", 100);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 100);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 100);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 100);
  sf_mex_assign(&c6_rhs100, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs100, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs100), "rhs", "rhs",
                  100);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs100), "lhs", "lhs",
                  100);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xscal.p"),
                  "context", "context", 101);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 101);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 101);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 101);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1372608360U), "fileTimeLo",
                  "fileTimeLo", 101);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 101);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 101);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 101);
  sf_mex_assign(&c6_rhs101, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs101, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs101), "rhs", "rhs",
                  101);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs101), "lhs", "lhs",
                  101);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xscal.p"),
                  "context", "context", 102);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 102);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 102);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 102);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1397282622U), "fileTimeLo",
                  "fileTimeLo", 102);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 102);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 102);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 102);
  sf_mex_assign(&c6_rhs102, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs102, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs102), "rhs", "rhs",
                  102);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs102), "lhs", "lhs",
                  102);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 103);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 103);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 103);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 103);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1372608360U), "fileTimeLo",
                  "fileTimeLo", 103);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 103);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 103);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 103);
  sf_mex_assign(&c6_rhs103, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs103, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs103), "rhs", "rhs",
                  103);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs103), "lhs", "lhs",
                  103);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 104);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 104);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 104);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 104);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1372608360U), "fileTimeLo",
                  "fileTimeLo", 104);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 104);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 104);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 104);
  sf_mex_assign(&c6_rhs104, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs104, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs104), "rhs", "rhs",
                  104);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs104), "lhs", "lhs",
                  104);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 105);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 105);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 105);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 105);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1372608360U), "fileTimeLo",
                  "fileTimeLo", 105);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 105);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 105);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 105);
  sf_mex_assign(&c6_rhs105, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs105, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs105), "rhs", "rhs",
                  105);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs105), "lhs", "lhs",
                  105);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 106);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 106);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 106);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 106);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1397282622U), "fileTimeLo",
                  "fileTimeLo", 106);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 106);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 106);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 106);
  sf_mex_assign(&c6_rhs106, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs106, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs106), "rhs", "rhs",
                  106);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs106), "lhs", "lhs",
                  106);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 107);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_xdotc"), "name", "name",
                  107);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 107);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m"),
                  "resolved", "resolved", 107);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1376005890U), "fileTimeLo",
                  "fileTimeLo", 107);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 107);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 107);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 107);
  sf_mex_assign(&c6_rhs107, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs107, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs107), "rhs", "rhs",
                  107);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs107), "lhs", "lhs",
                  107);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m"), "context",
                  "context", 108);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 108);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 108);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 108);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 108);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 108);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 108);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 108);
  sf_mex_assign(&c6_rhs108, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs108, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs108), "rhs", "rhs",
                  108);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs108), "lhs", "lhs",
                  108);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m"), "context",
                  "context", 109);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.blas.xdotc"),
                  "name", "name", 109);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 109);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotc.p"),
                  "resolved", "resolved", 109);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 109);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 109);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 109);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 109);
  sf_mex_assign(&c6_rhs109, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs109, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs109), "rhs", "rhs",
                  109);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs109), "lhs", "lhs",
                  109);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotc.p"),
                  "context", "context", 110);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.blas.xdot"),
                  "name", "name", 110);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 110);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "resolved", "resolved", 110);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 110);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 110);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 110);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 110);
  sf_mex_assign(&c6_rhs110, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs110, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs110), "rhs", "rhs",
                  110);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs110), "lhs", "lhs",
                  110);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 111);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 111);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 111);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 111);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 111);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 111);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 111);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 111);
  sf_mex_assign(&c6_rhs111, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs111, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs111), "rhs", "rhs",
                  111);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs111), "lhs", "lhs",
                  111);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p!below_threshold"),
                  "context", "context", 112);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.blas.threshold"),
                  "name", "name", 112);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 112);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 112);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 112);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 112);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 112);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 112);
  sf_mex_assign(&c6_rhs112, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs112, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs112), "rhs", "rhs",
                  112);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs112), "lhs", "lhs",
                  112);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p!below_threshold"),
                  "context", "context", 113);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("length"), "name", "name", 113);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 113);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 113);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1303171406U), "fileTimeLo",
                  "fileTimeLo", 113);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 113);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 113);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 113);
  sf_mex_assign(&c6_rhs113, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs113, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs113), "rhs", "rhs",
                  113);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs113), "lhs", "lhs",
                  113);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 114);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.refblas.xdot"),
                  "name", "name", 114);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 114);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "resolved", "resolved", 114);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 114);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 114);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 114);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 114);
  sf_mex_assign(&c6_rhs114, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs114, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs114), "rhs", "rhs",
                  114);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs114), "lhs", "lhs",
                  114);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "context", "context", 115);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.refblas.xdotx"),
                  "name", "name", 115);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 115);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "resolved", "resolved", 115);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 115);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 115);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 115);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 115);
  sf_mex_assign(&c6_rhs115, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs115, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs115), "rhs", "rhs",
                  115);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs115), "lhs", "lhs",
                  115);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 116);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 116);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 116);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 116);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 116);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 116);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 116);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 116);
  sf_mex_assign(&c6_rhs116, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs116, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs116), "rhs", "rhs",
                  116);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs116), "lhs", "lhs",
                  116);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 117);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 117);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 117);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 117);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1397282622U), "fileTimeLo",
                  "fileTimeLo", 117);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 117);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 117);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 117);
  sf_mex_assign(&c6_rhs117, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs117, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs117), "rhs", "rhs",
                  117);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs117), "lhs", "lhs",
                  117);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 118);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 118);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 118);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 118);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1372608360U), "fileTimeLo",
                  "fileTimeLo", 118);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 118);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 118);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 118);
  sf_mex_assign(&c6_rhs118, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs118, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs118), "rhs", "rhs",
                  118);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs118), "lhs", "lhs",
                  118);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 119);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("mrdivide"), "name", "name",
                  119);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 119);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 119);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832848U), "fileTimeLo",
                  "fileTimeLo", 119);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 119);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1370035086U), "mFileTimeLo",
                  "mFileTimeLo", 119);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 119);
  sf_mex_assign(&c6_rhs119, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs119, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs119), "rhs", "rhs",
                  119);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs119), "lhs", "lhs",
                  119);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 120);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_xaxpy"), "name", "name",
                  120);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 120);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m"),
                  "resolved", "resolved", 120);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 120);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 120);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 120);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 120);
  sf_mex_assign(&c6_rhs120, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs120, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs120), "rhs", "rhs",
                  120);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs120), "lhs", "lhs",
                  120);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m"), "context",
                  "context", 121);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 121);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 121);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 121);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 121);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 121);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 121);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 121);
  sf_mex_assign(&c6_rhs121, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs121, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs121), "rhs", "rhs",
                  121);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs121), "lhs", "lhs",
                  121);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m"), "context",
                  "context", 122);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.blas.xaxpy"),
                  "name", "name", 122);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 122);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xaxpy.p"),
                  "resolved", "resolved", 122);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 122);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 122);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 122);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 122);
  sf_mex_assign(&c6_rhs122, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs122, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs122), "rhs", "rhs",
                  122);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs122), "lhs", "lhs",
                  122);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xaxpy.p"),
                  "context", "context", 123);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 123);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 123);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 123);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 123);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 123);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 123);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 123);
  sf_mex_assign(&c6_rhs123, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs123, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs123), "rhs", "rhs",
                  123);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs123), "lhs", "lhs",
                  123);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xaxpy.p!below_threshold"),
                  "context", "context", 124);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.blas.threshold"),
                  "name", "name", 124);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 124);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 124);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 124);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 124);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 124);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 124);
  sf_mex_assign(&c6_rhs124, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs124, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs124), "rhs", "rhs",
                  124);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs124), "lhs", "lhs",
                  124);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xaxpy.p!below_threshold"),
                  "context", "context", 125);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("length"), "name", "name", 125);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 125);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 125);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1303171406U), "fileTimeLo",
                  "fileTimeLo", 125);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 125);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 125);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 125);
  sf_mex_assign(&c6_rhs125, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs125, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs125), "rhs", "rhs",
                  125);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs125), "lhs", "lhs",
                  125);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xaxpy.p"),
                  "context", "context", 126);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 126);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 126);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 126);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 126);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 126);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 126);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 126);
  sf_mex_assign(&c6_rhs126, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs126, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs126), "rhs", "rhs",
                  126);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs126), "lhs", "lhs",
                  126);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xaxpy.p"),
                  "context", "context", 127);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.refblas.xaxpy"),
                  "name", "name", 127);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 127);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xaxpy.p"),
                  "resolved", "resolved", 127);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 127);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 127);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 127);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 127);
  sf_mex_assign(&c6_rhs127, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs127, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs127), "rhs", "rhs",
                  127);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs127), "lhs", "lhs",
                  127);
  sf_mex_destroy(&c6_rhs64);
  sf_mex_destroy(&c6_lhs64);
  sf_mex_destroy(&c6_rhs65);
  sf_mex_destroy(&c6_lhs65);
  sf_mex_destroy(&c6_rhs66);
  sf_mex_destroy(&c6_lhs66);
  sf_mex_destroy(&c6_rhs67);
  sf_mex_destroy(&c6_lhs67);
  sf_mex_destroy(&c6_rhs68);
  sf_mex_destroy(&c6_lhs68);
  sf_mex_destroy(&c6_rhs69);
  sf_mex_destroy(&c6_lhs69);
  sf_mex_destroy(&c6_rhs70);
  sf_mex_destroy(&c6_lhs70);
  sf_mex_destroy(&c6_rhs71);
  sf_mex_destroy(&c6_lhs71);
  sf_mex_destroy(&c6_rhs72);
  sf_mex_destroy(&c6_lhs72);
  sf_mex_destroy(&c6_rhs73);
  sf_mex_destroy(&c6_lhs73);
  sf_mex_destroy(&c6_rhs74);
  sf_mex_destroy(&c6_lhs74);
  sf_mex_destroy(&c6_rhs75);
  sf_mex_destroy(&c6_lhs75);
  sf_mex_destroy(&c6_rhs76);
  sf_mex_destroy(&c6_lhs76);
  sf_mex_destroy(&c6_rhs77);
  sf_mex_destroy(&c6_lhs77);
  sf_mex_destroy(&c6_rhs78);
  sf_mex_destroy(&c6_lhs78);
  sf_mex_destroy(&c6_rhs79);
  sf_mex_destroy(&c6_lhs79);
  sf_mex_destroy(&c6_rhs80);
  sf_mex_destroy(&c6_lhs80);
  sf_mex_destroy(&c6_rhs81);
  sf_mex_destroy(&c6_lhs81);
  sf_mex_destroy(&c6_rhs82);
  sf_mex_destroy(&c6_lhs82);
  sf_mex_destroy(&c6_rhs83);
  sf_mex_destroy(&c6_lhs83);
  sf_mex_destroy(&c6_rhs84);
  sf_mex_destroy(&c6_lhs84);
  sf_mex_destroy(&c6_rhs85);
  sf_mex_destroy(&c6_lhs85);
  sf_mex_destroy(&c6_rhs86);
  sf_mex_destroy(&c6_lhs86);
  sf_mex_destroy(&c6_rhs87);
  sf_mex_destroy(&c6_lhs87);
  sf_mex_destroy(&c6_rhs88);
  sf_mex_destroy(&c6_lhs88);
  sf_mex_destroy(&c6_rhs89);
  sf_mex_destroy(&c6_lhs89);
  sf_mex_destroy(&c6_rhs90);
  sf_mex_destroy(&c6_lhs90);
  sf_mex_destroy(&c6_rhs91);
  sf_mex_destroy(&c6_lhs91);
  sf_mex_destroy(&c6_rhs92);
  sf_mex_destroy(&c6_lhs92);
  sf_mex_destroy(&c6_rhs93);
  sf_mex_destroy(&c6_lhs93);
  sf_mex_destroy(&c6_rhs94);
  sf_mex_destroy(&c6_lhs94);
  sf_mex_destroy(&c6_rhs95);
  sf_mex_destroy(&c6_lhs95);
  sf_mex_destroy(&c6_rhs96);
  sf_mex_destroy(&c6_lhs96);
  sf_mex_destroy(&c6_rhs97);
  sf_mex_destroy(&c6_lhs97);
  sf_mex_destroy(&c6_rhs98);
  sf_mex_destroy(&c6_lhs98);
  sf_mex_destroy(&c6_rhs99);
  sf_mex_destroy(&c6_lhs99);
  sf_mex_destroy(&c6_rhs100);
  sf_mex_destroy(&c6_lhs100);
  sf_mex_destroy(&c6_rhs101);
  sf_mex_destroy(&c6_lhs101);
  sf_mex_destroy(&c6_rhs102);
  sf_mex_destroy(&c6_lhs102);
  sf_mex_destroy(&c6_rhs103);
  sf_mex_destroy(&c6_lhs103);
  sf_mex_destroy(&c6_rhs104);
  sf_mex_destroy(&c6_lhs104);
  sf_mex_destroy(&c6_rhs105);
  sf_mex_destroy(&c6_lhs105);
  sf_mex_destroy(&c6_rhs106);
  sf_mex_destroy(&c6_lhs106);
  sf_mex_destroy(&c6_rhs107);
  sf_mex_destroy(&c6_lhs107);
  sf_mex_destroy(&c6_rhs108);
  sf_mex_destroy(&c6_lhs108);
  sf_mex_destroy(&c6_rhs109);
  sf_mex_destroy(&c6_lhs109);
  sf_mex_destroy(&c6_rhs110);
  sf_mex_destroy(&c6_lhs110);
  sf_mex_destroy(&c6_rhs111);
  sf_mex_destroy(&c6_lhs111);
  sf_mex_destroy(&c6_rhs112);
  sf_mex_destroy(&c6_lhs112);
  sf_mex_destroy(&c6_rhs113);
  sf_mex_destroy(&c6_lhs113);
  sf_mex_destroy(&c6_rhs114);
  sf_mex_destroy(&c6_lhs114);
  sf_mex_destroy(&c6_rhs115);
  sf_mex_destroy(&c6_lhs115);
  sf_mex_destroy(&c6_rhs116);
  sf_mex_destroy(&c6_lhs116);
  sf_mex_destroy(&c6_rhs117);
  sf_mex_destroy(&c6_lhs117);
  sf_mex_destroy(&c6_rhs118);
  sf_mex_destroy(&c6_lhs118);
  sf_mex_destroy(&c6_rhs119);
  sf_mex_destroy(&c6_lhs119);
  sf_mex_destroy(&c6_rhs120);
  sf_mex_destroy(&c6_lhs120);
  sf_mex_destroy(&c6_rhs121);
  sf_mex_destroy(&c6_lhs121);
  sf_mex_destroy(&c6_rhs122);
  sf_mex_destroy(&c6_lhs122);
  sf_mex_destroy(&c6_rhs123);
  sf_mex_destroy(&c6_lhs123);
  sf_mex_destroy(&c6_rhs124);
  sf_mex_destroy(&c6_lhs124);
  sf_mex_destroy(&c6_rhs125);
  sf_mex_destroy(&c6_lhs125);
  sf_mex_destroy(&c6_rhs126);
  sf_mex_destroy(&c6_lhs126);
  sf_mex_destroy(&c6_rhs127);
  sf_mex_destroy(&c6_lhs127);
}

static void c6_c_info_helper(const mxArray **c6_info)
{
  const mxArray *c6_rhs128 = NULL;
  const mxArray *c6_lhs128 = NULL;
  const mxArray *c6_rhs129 = NULL;
  const mxArray *c6_lhs129 = NULL;
  const mxArray *c6_rhs130 = NULL;
  const mxArray *c6_lhs130 = NULL;
  const mxArray *c6_rhs131 = NULL;
  const mxArray *c6_lhs131 = NULL;
  const mxArray *c6_rhs132 = NULL;
  const mxArray *c6_lhs132 = NULL;
  const mxArray *c6_rhs133 = NULL;
  const mxArray *c6_lhs133 = NULL;
  const mxArray *c6_rhs134 = NULL;
  const mxArray *c6_lhs134 = NULL;
  const mxArray *c6_rhs135 = NULL;
  const mxArray *c6_lhs135 = NULL;
  const mxArray *c6_rhs136 = NULL;
  const mxArray *c6_lhs136 = NULL;
  const mxArray *c6_rhs137 = NULL;
  const mxArray *c6_lhs137 = NULL;
  const mxArray *c6_rhs138 = NULL;
  const mxArray *c6_lhs138 = NULL;
  const mxArray *c6_rhs139 = NULL;
  const mxArray *c6_lhs139 = NULL;
  const mxArray *c6_rhs140 = NULL;
  const mxArray *c6_lhs140 = NULL;
  const mxArray *c6_rhs141 = NULL;
  const mxArray *c6_lhs141 = NULL;
  const mxArray *c6_rhs142 = NULL;
  const mxArray *c6_lhs142 = NULL;
  const mxArray *c6_rhs143 = NULL;
  const mxArray *c6_lhs143 = NULL;
  const mxArray *c6_rhs144 = NULL;
  const mxArray *c6_lhs144 = NULL;
  const mxArray *c6_rhs145 = NULL;
  const mxArray *c6_lhs145 = NULL;
  const mxArray *c6_rhs146 = NULL;
  const mxArray *c6_lhs146 = NULL;
  const mxArray *c6_rhs147 = NULL;
  const mxArray *c6_lhs147 = NULL;
  const mxArray *c6_rhs148 = NULL;
  const mxArray *c6_lhs148 = NULL;
  const mxArray *c6_rhs149 = NULL;
  const mxArray *c6_lhs149 = NULL;
  const mxArray *c6_rhs150 = NULL;
  const mxArray *c6_lhs150 = NULL;
  const mxArray *c6_rhs151 = NULL;
  const mxArray *c6_lhs151 = NULL;
  const mxArray *c6_rhs152 = NULL;
  const mxArray *c6_lhs152 = NULL;
  const mxArray *c6_rhs153 = NULL;
  const mxArray *c6_lhs153 = NULL;
  const mxArray *c6_rhs154 = NULL;
  const mxArray *c6_lhs154 = NULL;
  const mxArray *c6_rhs155 = NULL;
  const mxArray *c6_lhs155 = NULL;
  const mxArray *c6_rhs156 = NULL;
  const mxArray *c6_lhs156 = NULL;
  const mxArray *c6_rhs157 = NULL;
  const mxArray *c6_lhs157 = NULL;
  const mxArray *c6_rhs158 = NULL;
  const mxArray *c6_lhs158 = NULL;
  const mxArray *c6_rhs159 = NULL;
  const mxArray *c6_lhs159 = NULL;
  const mxArray *c6_rhs160 = NULL;
  const mxArray *c6_lhs160 = NULL;
  const mxArray *c6_rhs161 = NULL;
  const mxArray *c6_lhs161 = NULL;
  const mxArray *c6_rhs162 = NULL;
  const mxArray *c6_lhs162 = NULL;
  const mxArray *c6_rhs163 = NULL;
  const mxArray *c6_lhs163 = NULL;
  const mxArray *c6_rhs164 = NULL;
  const mxArray *c6_lhs164 = NULL;
  const mxArray *c6_rhs165 = NULL;
  const mxArray *c6_lhs165 = NULL;
  const mxArray *c6_rhs166 = NULL;
  const mxArray *c6_lhs166 = NULL;
  const mxArray *c6_rhs167 = NULL;
  const mxArray *c6_lhs167 = NULL;
  const mxArray *c6_rhs168 = NULL;
  const mxArray *c6_lhs168 = NULL;
  const mxArray *c6_rhs169 = NULL;
  const mxArray *c6_lhs169 = NULL;
  const mxArray *c6_rhs170 = NULL;
  const mxArray *c6_lhs170 = NULL;
  const mxArray *c6_rhs171 = NULL;
  const mxArray *c6_lhs171 = NULL;
  const mxArray *c6_rhs172 = NULL;
  const mxArray *c6_lhs172 = NULL;
  const mxArray *c6_rhs173 = NULL;
  const mxArray *c6_lhs173 = NULL;
  const mxArray *c6_rhs174 = NULL;
  const mxArray *c6_lhs174 = NULL;
  const mxArray *c6_rhs175 = NULL;
  const mxArray *c6_lhs175 = NULL;
  const mxArray *c6_rhs176 = NULL;
  const mxArray *c6_lhs176 = NULL;
  const mxArray *c6_rhs177 = NULL;
  const mxArray *c6_lhs177 = NULL;
  const mxArray *c6_rhs178 = NULL;
  const mxArray *c6_lhs178 = NULL;
  const mxArray *c6_rhs179 = NULL;
  const mxArray *c6_lhs179 = NULL;
  const mxArray *c6_rhs180 = NULL;
  const mxArray *c6_lhs180 = NULL;
  const mxArray *c6_rhs181 = NULL;
  const mxArray *c6_lhs181 = NULL;
  const mxArray *c6_rhs182 = NULL;
  const mxArray *c6_lhs182 = NULL;
  const mxArray *c6_rhs183 = NULL;
  const mxArray *c6_lhs183 = NULL;
  const mxArray *c6_rhs184 = NULL;
  const mxArray *c6_lhs184 = NULL;
  const mxArray *c6_rhs185 = NULL;
  const mxArray *c6_lhs185 = NULL;
  const mxArray *c6_rhs186 = NULL;
  const mxArray *c6_lhs186 = NULL;
  const mxArray *c6_rhs187 = NULL;
  const mxArray *c6_lhs187 = NULL;
  const mxArray *c6_rhs188 = NULL;
  const mxArray *c6_lhs188 = NULL;
  const mxArray *c6_rhs189 = NULL;
  const mxArray *c6_lhs189 = NULL;
  const mxArray *c6_rhs190 = NULL;
  const mxArray *c6_lhs190 = NULL;
  const mxArray *c6_rhs191 = NULL;
  const mxArray *c6_lhs191 = NULL;
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xaxpy.p"),
                  "context", "context", 128);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.isaUint"),
                  "name", "name", 128);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 128);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/isaUint.p"),
                  "resolved", "resolved", 128);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 128);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 128);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 128);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 128);
  sf_mex_assign(&c6_rhs128, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs128, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs128), "rhs", "rhs",
                  128);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs128), "lhs", "lhs",
                  128);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xaxpy.p"),
                  "context", "context", 129);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 129);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 129);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 129);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1372608360U), "fileTimeLo",
                  "fileTimeLo", 129);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 129);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 129);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 129);
  sf_mex_assign(&c6_rhs129, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs129, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs129), "rhs", "rhs",
                  129);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs129), "lhs", "lhs",
                  129);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xaxpy.p"),
                  "context", "context", 130);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 130);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 130);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 130);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1397282622U), "fileTimeLo",
                  "fileTimeLo", 130);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 130);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 130);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 130);
  sf_mex_assign(&c6_rhs130, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs130, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs130), "rhs", "rhs",
                  130);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs130), "lhs", "lhs",
                  130);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xaxpy.p"),
                  "context", "context", 131);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 131);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 131);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 131);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1372608360U), "fileTimeLo",
                  "fileTimeLo", 131);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 131);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 131);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 131);
  sf_mex_assign(&c6_rhs131, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs131, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs131), "rhs", "rhs",
                  131);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs131), "lhs", "lhs",
                  131);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xaxpy.p"),
                  "context", "context", 132);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 132);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 132);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 132);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1372608360U), "fileTimeLo",
                  "fileTimeLo", 132);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 132);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 132);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 132);
  sf_mex_assign(&c6_rhs132, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs132, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs132), "rhs", "rhs",
                  132);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs132), "lhs", "lhs",
                  132);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 133);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("abs"), "name", "name", 133);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 133);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 133);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1363739052U), "fileTimeLo",
                  "fileTimeLo", 133);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 133);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 133);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 133);
  sf_mex_assign(&c6_rhs133, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs133, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs133), "rhs", "rhs",
                  133);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs133), "lhs", "lhs",
                  133);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 134);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_xscal"), "name", "name",
                  134);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 134);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m"),
                  "resolved", "resolved", 134);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1376005892U), "fileTimeLo",
                  "fileTimeLo", 134);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 134);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 134);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 134);
  sf_mex_assign(&c6_rhs134, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs134, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs134), "rhs", "rhs",
                  134);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs134), "lhs", "lhs",
                  134);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m"), "context",
                  "context", 135);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 135);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 135);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 135);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 135);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 135);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 135);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 135);
  sf_mex_assign(&c6_rhs135, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs135, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs135), "rhs", "rhs",
                  135);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs135), "lhs", "lhs",
                  135);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m"), "context",
                  "context", 136);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.blas.xscal"),
                  "name", "name", 136);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 136);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xscal.p"),
                  "resolved", "resolved", 136);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 136);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 136);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 136);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 136);
  sf_mex_assign(&c6_rhs136, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs136, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs136), "rhs", "rhs",
                  136);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs136), "lhs", "lhs",
                  136);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 137);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("realmin"), "name", "name", 137);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 137);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 137);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1307676442U), "fileTimeLo",
                  "fileTimeLo", 137);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 137);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 137);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 137);
  sf_mex_assign(&c6_rhs137, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs137, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs137), "rhs", "rhs",
                  137);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs137), "lhs", "lhs",
                  137);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 138);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eps"), "name", "name", 138);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 138);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 138);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1326753196U), "fileTimeLo",
                  "fileTimeLo", 138);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 138);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 138);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 138);
  sf_mex_assign(&c6_rhs138, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs138, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs138), "rhs", "rhs",
                  138);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs138), "lhs", "lhs",
                  138);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 139);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 139);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 139);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 139);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 139);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 139);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 139);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 139);
  sf_mex_assign(&c6_rhs139, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs139, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs139), "rhs", "rhs",
                  139);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs139), "lhs", "lhs",
                  139);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 140);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_error"), "name", "name",
                  140);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 140);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 140);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1343855558U), "fileTimeLo",
                  "fileTimeLo", 140);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 140);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 140);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 140);
  sf_mex_assign(&c6_rhs140, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs140, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs140), "rhs", "rhs",
                  140);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs140), "lhs", "lhs",
                  140);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 141);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_const_nonsingleton_dim"),
                  "name", "name", 141);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 141);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "resolved", "resolved", 141);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1372607616U), "fileTimeLo",
                  "fileTimeLo", 141);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 141);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 141);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 141);
  sf_mex_assign(&c6_rhs141, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs141, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs141), "rhs", "rhs",
                  141);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs141), "lhs", "lhs",
                  141);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "context", "context", 142);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "coder.internal.constNonSingletonDim"), "name", "name", 142);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 142);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/constNonSingletonDim.m"),
                  "resolved", "resolved", 142);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1372608360U), "fileTimeLo",
                  "fileTimeLo", 142);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 142);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 142);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 142);
  sf_mex_assign(&c6_rhs142, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs142, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs142), "rhs", "rhs",
                  142);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs142), "lhs", "lhs",
                  142);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 143);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 143);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 143);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 143);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 143);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 143);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 143);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 143);
  sf_mex_assign(&c6_rhs143, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs143, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs143), "rhs", "rhs",
                  143);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs143), "lhs", "lhs",
                  143);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 144);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 144);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 144);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 144);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 144);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 144);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 144);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 144);
  sf_mex_assign(&c6_rhs144, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs144, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs144), "rhs", "rhs",
                  144);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs144), "lhs", "lhs",
                  144);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 145);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 145);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 145);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 145);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 145);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 145);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 145);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 145);
  sf_mex_assign(&c6_rhs145, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs145, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs145), "rhs", "rhs",
                  145);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs145), "lhs", "lhs",
                  145);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 146);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("isnan"), "name", "name", 146);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 146);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 146);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1363739058U), "fileTimeLo",
                  "fileTimeLo", 146);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 146);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 146);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 146);
  sf_mex_assign(&c6_rhs146, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs146, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs146), "rhs", "rhs",
                  146);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs146), "lhs", "lhs",
                  146);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 147);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 147);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 147);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 147);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1372607616U), "fileTimeLo",
                  "fileTimeLo", 147);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 147);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 147);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 147);
  sf_mex_assign(&c6_rhs147, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs147, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs147), "rhs", "rhs",
                  147);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs147), "lhs", "lhs",
                  147);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 148);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 148);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 148);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 148);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1372608360U), "fileTimeLo",
                  "fileTimeLo", 148);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 148);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 148);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 148);
  sf_mex_assign(&c6_rhs148, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs148, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs148), "rhs", "rhs",
                  148);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs148), "lhs", "lhs",
                  148);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 149);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 149);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 149);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 149);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1397282622U), "fileTimeLo",
                  "fileTimeLo", 149);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 149);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 149);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 149);
  sf_mex_assign(&c6_rhs149, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs149, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs149), "rhs", "rhs",
                  149);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs149), "lhs", "lhs",
                  149);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 150);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_relop"), "name", "name",
                  150);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("function_handle"),
                  "dominantType", "dominantType", 150);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m"), "resolved",
                  "resolved", 150);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1342476382U), "fileTimeLo",
                  "fileTimeLo", 150);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 150);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 150);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 150);
  sf_mex_assign(&c6_rhs150, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs150, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs150), "rhs", "rhs",
                  150);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs150), "lhs", "lhs",
                  150);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 151);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("sqrt"), "name", "name", 151);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 151);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 151);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1343855586U), "fileTimeLo",
                  "fileTimeLo", 151);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 151);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 151);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 151);
  sf_mex_assign(&c6_rhs151, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs151, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs151), "rhs", "rhs",
                  151);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs151), "lhs", "lhs",
                  151);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 152);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_error"), "name", "name",
                  152);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 152);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 152);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1343855558U), "fileTimeLo",
                  "fileTimeLo", 152);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 152);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 152);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 152);
  sf_mex_assign(&c6_rhs152, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs152, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs152), "rhs", "rhs",
                  152);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs152), "lhs", "lhs",
                  152);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 153);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_scalar_sqrt"), "name",
                  "name", 153);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 153);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m"),
                  "resolved", "resolved", 153);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1286843938U), "fileTimeLo",
                  "fileTimeLo", 153);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 153);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 153);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 153);
  sf_mex_assign(&c6_rhs153, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs153, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs153), "rhs", "rhs",
                  153);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs153), "lhs", "lhs",
                  153);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 154);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_xrotg"), "name", "name",
                  154);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 154);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m"),
                  "resolved", "resolved", 154);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1376005892U), "fileTimeLo",
                  "fileTimeLo", 154);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 154);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 154);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 154);
  sf_mex_assign(&c6_rhs154, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs154, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs154), "rhs", "rhs",
                  154);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs154), "lhs", "lhs",
                  154);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m"), "context",
                  "context", 155);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 155);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 155);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 155);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 155);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 155);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 155);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 155);
  sf_mex_assign(&c6_rhs155, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs155, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs155), "rhs", "rhs",
                  155);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs155), "lhs", "lhs",
                  155);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m"), "context",
                  "context", 156);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.blas.xrotg"),
                  "name", "name", 156);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 156);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xrotg.p"),
                  "resolved", "resolved", 156);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 156);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 156);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 156);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 156);
  sf_mex_assign(&c6_rhs156, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs156, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs156), "rhs", "rhs",
                  156);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs156), "lhs", "lhs",
                  156);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xrotg.p"),
                  "context", "context", 157);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 157);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 157);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 157);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 157);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 157);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 157);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 157);
  sf_mex_assign(&c6_rhs157, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs157, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs157), "rhs", "rhs",
                  157);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs157), "lhs", "lhs",
                  157);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xrotg.p"),
                  "context", "context", 158);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.refblas.xrotg"),
                  "name", "name", 158);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 158);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xrotg.p"),
                  "resolved", "resolved", 158);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 158);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 158);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 158);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 158);
  sf_mex_assign(&c6_rhs158, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs158, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs158), "rhs", "rhs",
                  158);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs158), "lhs", "lhs",
                  158);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xrotg.p"),
                  "context", "context", 159);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("abs"), "name", "name", 159);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 159);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 159);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1363739052U), "fileTimeLo",
                  "fileTimeLo", 159);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 159);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 159);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 159);
  sf_mex_assign(&c6_rhs159, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs159, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs159), "rhs", "rhs",
                  159);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs159), "lhs", "lhs",
                  159);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xrotg.p"),
                  "context", "context", 160);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("mrdivide"), "name", "name",
                  160);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 160);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 160);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832848U), "fileTimeLo",
                  "fileTimeLo", 160);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 160);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1370035086U), "mFileTimeLo",
                  "mFileTimeLo", 160);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 160);
  sf_mex_assign(&c6_rhs160, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs160, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs160), "rhs", "rhs",
                  160);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs160), "lhs", "lhs",
                  160);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xrotg.p"),
                  "context", "context", 161);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("sqrt"), "name", "name", 161);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 161);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 161);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1343855586U), "fileTimeLo",
                  "fileTimeLo", 161);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 161);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 161);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 161);
  sf_mex_assign(&c6_rhs161, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs161, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs161), "rhs", "rhs",
                  161);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs161), "lhs", "lhs",
                  161);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xrotg.p!eml_ceval_xrotg"),
                  "context", "context", 162);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 162);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 162);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 162);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 162);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 162);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 162);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 162);
  sf_mex_assign(&c6_rhs162, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs162, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs162), "rhs", "rhs",
                  162);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs162), "lhs", "lhs",
                  162);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 163);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_xrot"), "name", "name",
                  163);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 163);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrot.m"), "resolved",
                  "resolved", 163);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1376005892U), "fileTimeLo",
                  "fileTimeLo", 163);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 163);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 163);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 163);
  sf_mex_assign(&c6_rhs163, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs163, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs163), "rhs", "rhs",
                  163);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs163), "lhs", "lhs",
                  163);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrot.m"), "context",
                  "context", 164);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 164);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 164);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 164);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 164);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 164);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 164);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 164);
  sf_mex_assign(&c6_rhs164, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs164, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs164), "rhs", "rhs",
                  164);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs164), "lhs", "lhs",
                  164);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrot.m"), "context",
                  "context", 165);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.blas.xrot"),
                  "name", "name", 165);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 165);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xrot.p"),
                  "resolved", "resolved", 165);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 165);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 165);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 165);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 165);
  sf_mex_assign(&c6_rhs165, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs165, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs165), "rhs", "rhs",
                  165);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs165), "lhs", "lhs",
                  165);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xrot.p"),
                  "context", "context", 166);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 166);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 166);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 166);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 166);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 166);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 166);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 166);
  sf_mex_assign(&c6_rhs166, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs166, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs166), "rhs", "rhs",
                  166);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs166), "lhs", "lhs",
                  166);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xrot.p!below_threshold"),
                  "context", "context", 167);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.blas.threshold"),
                  "name", "name", 167);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 167);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 167);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 167);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 167);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 167);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 167);
  sf_mex_assign(&c6_rhs167, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs167, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs167), "rhs", "rhs",
                  167);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs167), "lhs", "lhs",
                  167);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xrot.p"),
                  "context", "context", 168);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 168);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 168);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 168);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 168);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 168);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 168);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 168);
  sf_mex_assign(&c6_rhs168, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs168, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs168), "rhs", "rhs",
                  168);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs168), "lhs", "lhs",
                  168);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xrot.p"),
                  "context", "context", 169);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.refblas.xrot"),
                  "name", "name", 169);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 169);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xrot.p"),
                  "resolved", "resolved", 169);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 169);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 169);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 169);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 169);
  sf_mex_assign(&c6_rhs169, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs169, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs169), "rhs", "rhs",
                  169);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs169), "lhs", "lhs",
                  169);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xrot.p"),
                  "context", "context", 170);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 170);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 170);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 170);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1397282622U), "fileTimeLo",
                  "fileTimeLo", 170);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 170);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 170);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 170);
  sf_mex_assign(&c6_rhs170, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs170, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs170), "rhs", "rhs",
                  170);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs170), "lhs", "lhs",
                  170);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xrot.p"),
                  "context", "context", 171);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 171);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 171);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 171);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1372608360U), "fileTimeLo",
                  "fileTimeLo", 171);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 171);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 171);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 171);
  sf_mex_assign(&c6_rhs171, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs171, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs171), "rhs", "rhs",
                  171);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs171), "lhs", "lhs",
                  171);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 172);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_xswap"), "name", "name",
                  172);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 172);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m"),
                  "resolved", "resolved", 172);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1376005892U), "fileTimeLo",
                  "fileTimeLo", 172);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 172);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 172);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 172);
  sf_mex_assign(&c6_rhs172, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs172, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs172), "rhs", "rhs",
                  172);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs172), "lhs", "lhs",
                  172);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m"), "context",
                  "context", 173);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 173);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 173);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 173);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 173);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 173);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 173);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 173);
  sf_mex_assign(&c6_rhs173, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs173, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs173), "rhs", "rhs",
                  173);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs173), "lhs", "lhs",
                  173);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m"), "context",
                  "context", 174);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.blas.xswap"),
                  "name", "name", 174);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 174);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p"),
                  "resolved", "resolved", 174);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 174);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 174);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 174);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 174);
  sf_mex_assign(&c6_rhs174, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs174, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs174), "rhs", "rhs",
                  174);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs174), "lhs", "lhs",
                  174);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p"),
                  "context", "context", 175);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 175);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 175);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 175);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 175);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 175);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 175);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 175);
  sf_mex_assign(&c6_rhs175, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs175, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs175), "rhs", "rhs",
                  175);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs175), "lhs", "lhs",
                  175);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p!below_threshold"),
                  "context", "context", 176);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.blas.threshold"),
                  "name", "name", 176);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 176);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 176);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 176);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 176);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 176);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 176);
  sf_mex_assign(&c6_rhs176, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs176, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs176), "rhs", "rhs",
                  176);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs176), "lhs", "lhs",
                  176);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p"),
                  "context", "context", 177);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.refblas.xswap"),
                  "name", "name", 177);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 177);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "resolved", "resolved", 177);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 177);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 177);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 177);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 177);
  sf_mex_assign(&c6_rhs177, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs177, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs177), "rhs", "rhs",
                  177);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs177), "lhs", "lhs",
                  177);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "context", "context", 178);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("abs"), "name", "name", 178);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 178);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 178);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1363739052U), "fileTimeLo",
                  "fileTimeLo", 178);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 178);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 178);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 178);
  sf_mex_assign(&c6_rhs178, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs178, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs178), "rhs", "rhs",
                  178);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs178), "lhs", "lhs",
                  178);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 179);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 179);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 179);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 179);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 179);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 179);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 179);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 179);
  sf_mex_assign(&c6_rhs179, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs179, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs179), "rhs", "rhs",
                  179);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs179), "lhs", "lhs",
                  179);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 180);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 180);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 180);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 180);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1286843912U), "fileTimeLo",
                  "fileTimeLo", 180);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 180);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 180);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 180);
  sf_mex_assign(&c6_rhs180, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs180, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs180), "rhs", "rhs",
                  180);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs180), "lhs", "lhs",
                  180);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "context", "context", 181);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 181);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 181);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 181);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1397282622U), "fileTimeLo",
                  "fileTimeLo", 181);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 181);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 181);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 181);
  sf_mex_assign(&c6_rhs181, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs181, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs181), "rhs", "rhs",
                  181);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs181), "lhs", "lhs",
                  181);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "context", "context", 182);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 182);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 182);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 182);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1372608360U), "fileTimeLo",
                  "fileTimeLo", 182);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 182);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 182);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 182);
  sf_mex_assign(&c6_rhs182, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs182, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs182), "rhs", "rhs",
                  182);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs182), "lhs", "lhs",
                  182);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv"),
                  "context", "context", 183);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eps"), "name", "name", 183);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 183);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 183);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1326753196U), "fileTimeLo",
                  "fileTimeLo", 183);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 183);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 183);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 183);
  sf_mex_assign(&c6_rhs183, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs183, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs183), "rhs", "rhs",
                  183);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs183), "lhs", "lhs",
                  183);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv"),
                  "context", "context", 184);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 184);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 184);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 184);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1397282622U), "fileTimeLo",
                  "fileTimeLo", 184);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 184);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 184);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 184);
  sf_mex_assign(&c6_rhs184, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs184, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs184), "rhs", "rhs",
                  184);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs184), "lhs", "lhs",
                  184);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv"),
                  "context", "context", 185);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 185);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 185);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 185);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1372607616U), "fileTimeLo",
                  "fileTimeLo", 185);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 185);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 185);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 185);
  sf_mex_assign(&c6_rhs185, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs185, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs185), "rhs", "rhs",
                  185);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs185), "lhs", "lhs",
                  185);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 186);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 186);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 186);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 186);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1372608360U), "fileTimeLo",
                  "fileTimeLo", 186);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 186);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 186);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 186);
  sf_mex_assign(&c6_rhs186, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs186, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs186), "rhs", "rhs",
                  186);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs186), "lhs", "lhs",
                  186);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv"),
                  "context", "context", 187);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_div"), "name", "name", 187);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 187);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 187);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1386449152U), "fileTimeLo",
                  "fileTimeLo", 187);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 187);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 187);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 187);
  sf_mex_assign(&c6_rhs187, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs187, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs187), "rhs", "rhs",
                  187);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs187), "lhs", "lhs",
                  187);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv"),
                  "context", "context", 188);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_xscal"), "name", "name",
                  188);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 188);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m"),
                  "resolved", "resolved", 188);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1376005892U), "fileTimeLo",
                  "fileTimeLo", 188);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 188);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 188);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 188);
  sf_mex_assign(&c6_rhs188, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs188, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs188), "rhs", "rhs",
                  188);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs188), "lhs", "lhs",
                  188);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv"),
                  "context", "context", 189);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 189);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 189);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 189);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1372607616U), "fileTimeLo",
                  "fileTimeLo", 189);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 189);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 189);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 189);
  sf_mex_assign(&c6_rhs189, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs189, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs189), "rhs", "rhs",
                  189);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs189), "lhs", "lhs",
                  189);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv"),
                  "context", "context", 190);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  190);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 190);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 190);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1376005890U), "fileTimeLo",
                  "fileTimeLo", 190);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 190);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 190);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 190);
  sf_mex_assign(&c6_rhs190, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs190, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs190), "rhs", "rhs",
                  190);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs190), "lhs", "lhs",
                  190);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 191);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 191);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 191);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 191);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 191);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 191);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 191);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 191);
  sf_mex_assign(&c6_rhs191, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs191, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs191), "rhs", "rhs",
                  191);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs191), "lhs", "lhs",
                  191);
  sf_mex_destroy(&c6_rhs128);
  sf_mex_destroy(&c6_lhs128);
  sf_mex_destroy(&c6_rhs129);
  sf_mex_destroy(&c6_lhs129);
  sf_mex_destroy(&c6_rhs130);
  sf_mex_destroy(&c6_lhs130);
  sf_mex_destroy(&c6_rhs131);
  sf_mex_destroy(&c6_lhs131);
  sf_mex_destroy(&c6_rhs132);
  sf_mex_destroy(&c6_lhs132);
  sf_mex_destroy(&c6_rhs133);
  sf_mex_destroy(&c6_lhs133);
  sf_mex_destroy(&c6_rhs134);
  sf_mex_destroy(&c6_lhs134);
  sf_mex_destroy(&c6_rhs135);
  sf_mex_destroy(&c6_lhs135);
  sf_mex_destroy(&c6_rhs136);
  sf_mex_destroy(&c6_lhs136);
  sf_mex_destroy(&c6_rhs137);
  sf_mex_destroy(&c6_lhs137);
  sf_mex_destroy(&c6_rhs138);
  sf_mex_destroy(&c6_lhs138);
  sf_mex_destroy(&c6_rhs139);
  sf_mex_destroy(&c6_lhs139);
  sf_mex_destroy(&c6_rhs140);
  sf_mex_destroy(&c6_lhs140);
  sf_mex_destroy(&c6_rhs141);
  sf_mex_destroy(&c6_lhs141);
  sf_mex_destroy(&c6_rhs142);
  sf_mex_destroy(&c6_lhs142);
  sf_mex_destroy(&c6_rhs143);
  sf_mex_destroy(&c6_lhs143);
  sf_mex_destroy(&c6_rhs144);
  sf_mex_destroy(&c6_lhs144);
  sf_mex_destroy(&c6_rhs145);
  sf_mex_destroy(&c6_lhs145);
  sf_mex_destroy(&c6_rhs146);
  sf_mex_destroy(&c6_lhs146);
  sf_mex_destroy(&c6_rhs147);
  sf_mex_destroy(&c6_lhs147);
  sf_mex_destroy(&c6_rhs148);
  sf_mex_destroy(&c6_lhs148);
  sf_mex_destroy(&c6_rhs149);
  sf_mex_destroy(&c6_lhs149);
  sf_mex_destroy(&c6_rhs150);
  sf_mex_destroy(&c6_lhs150);
  sf_mex_destroy(&c6_rhs151);
  sf_mex_destroy(&c6_lhs151);
  sf_mex_destroy(&c6_rhs152);
  sf_mex_destroy(&c6_lhs152);
  sf_mex_destroy(&c6_rhs153);
  sf_mex_destroy(&c6_lhs153);
  sf_mex_destroy(&c6_rhs154);
  sf_mex_destroy(&c6_lhs154);
  sf_mex_destroy(&c6_rhs155);
  sf_mex_destroy(&c6_lhs155);
  sf_mex_destroy(&c6_rhs156);
  sf_mex_destroy(&c6_lhs156);
  sf_mex_destroy(&c6_rhs157);
  sf_mex_destroy(&c6_lhs157);
  sf_mex_destroy(&c6_rhs158);
  sf_mex_destroy(&c6_lhs158);
  sf_mex_destroy(&c6_rhs159);
  sf_mex_destroy(&c6_lhs159);
  sf_mex_destroy(&c6_rhs160);
  sf_mex_destroy(&c6_lhs160);
  sf_mex_destroy(&c6_rhs161);
  sf_mex_destroy(&c6_lhs161);
  sf_mex_destroy(&c6_rhs162);
  sf_mex_destroy(&c6_lhs162);
  sf_mex_destroy(&c6_rhs163);
  sf_mex_destroy(&c6_lhs163);
  sf_mex_destroy(&c6_rhs164);
  sf_mex_destroy(&c6_lhs164);
  sf_mex_destroy(&c6_rhs165);
  sf_mex_destroy(&c6_lhs165);
  sf_mex_destroy(&c6_rhs166);
  sf_mex_destroy(&c6_lhs166);
  sf_mex_destroy(&c6_rhs167);
  sf_mex_destroy(&c6_lhs167);
  sf_mex_destroy(&c6_rhs168);
  sf_mex_destroy(&c6_lhs168);
  sf_mex_destroy(&c6_rhs169);
  sf_mex_destroy(&c6_lhs169);
  sf_mex_destroy(&c6_rhs170);
  sf_mex_destroy(&c6_lhs170);
  sf_mex_destroy(&c6_rhs171);
  sf_mex_destroy(&c6_lhs171);
  sf_mex_destroy(&c6_rhs172);
  sf_mex_destroy(&c6_lhs172);
  sf_mex_destroy(&c6_rhs173);
  sf_mex_destroy(&c6_lhs173);
  sf_mex_destroy(&c6_rhs174);
  sf_mex_destroy(&c6_lhs174);
  sf_mex_destroy(&c6_rhs175);
  sf_mex_destroy(&c6_lhs175);
  sf_mex_destroy(&c6_rhs176);
  sf_mex_destroy(&c6_lhs176);
  sf_mex_destroy(&c6_rhs177);
  sf_mex_destroy(&c6_lhs177);
  sf_mex_destroy(&c6_rhs178);
  sf_mex_destroy(&c6_lhs178);
  sf_mex_destroy(&c6_rhs179);
  sf_mex_destroy(&c6_lhs179);
  sf_mex_destroy(&c6_rhs180);
  sf_mex_destroy(&c6_lhs180);
  sf_mex_destroy(&c6_rhs181);
  sf_mex_destroy(&c6_lhs181);
  sf_mex_destroy(&c6_rhs182);
  sf_mex_destroy(&c6_lhs182);
  sf_mex_destroy(&c6_rhs183);
  sf_mex_destroy(&c6_lhs183);
  sf_mex_destroy(&c6_rhs184);
  sf_mex_destroy(&c6_lhs184);
  sf_mex_destroy(&c6_rhs185);
  sf_mex_destroy(&c6_lhs185);
  sf_mex_destroy(&c6_rhs186);
  sf_mex_destroy(&c6_lhs186);
  sf_mex_destroy(&c6_rhs187);
  sf_mex_destroy(&c6_lhs187);
  sf_mex_destroy(&c6_rhs188);
  sf_mex_destroy(&c6_lhs188);
  sf_mex_destroy(&c6_rhs189);
  sf_mex_destroy(&c6_lhs189);
  sf_mex_destroy(&c6_rhs190);
  sf_mex_destroy(&c6_lhs190);
  sf_mex_destroy(&c6_rhs191);
  sf_mex_destroy(&c6_lhs191);
}

static void c6_d_info_helper(const mxArray **c6_info)
{
  const mxArray *c6_rhs192 = NULL;
  const mxArray *c6_lhs192 = NULL;
  const mxArray *c6_rhs193 = NULL;
  const mxArray *c6_lhs193 = NULL;
  const mxArray *c6_rhs194 = NULL;
  const mxArray *c6_lhs194 = NULL;
  const mxArray *c6_rhs195 = NULL;
  const mxArray *c6_lhs195 = NULL;
  const mxArray *c6_rhs196 = NULL;
  const mxArray *c6_lhs196 = NULL;
  const mxArray *c6_rhs197 = NULL;
  const mxArray *c6_lhs197 = NULL;
  const mxArray *c6_rhs198 = NULL;
  const mxArray *c6_lhs198 = NULL;
  const mxArray *c6_rhs199 = NULL;
  const mxArray *c6_lhs199 = NULL;
  const mxArray *c6_rhs200 = NULL;
  const mxArray *c6_lhs200 = NULL;
  const mxArray *c6_rhs201 = NULL;
  const mxArray *c6_lhs201 = NULL;
  const mxArray *c6_rhs202 = NULL;
  const mxArray *c6_lhs202 = NULL;
  const mxArray *c6_rhs203 = NULL;
  const mxArray *c6_lhs203 = NULL;
  const mxArray *c6_rhs204 = NULL;
  const mxArray *c6_lhs204 = NULL;
  const mxArray *c6_rhs205 = NULL;
  const mxArray *c6_lhs205 = NULL;
  const mxArray *c6_rhs206 = NULL;
  const mxArray *c6_lhs206 = NULL;
  const mxArray *c6_rhs207 = NULL;
  const mxArray *c6_lhs207 = NULL;
  const mxArray *c6_rhs208 = NULL;
  const mxArray *c6_lhs208 = NULL;
  const mxArray *c6_rhs209 = NULL;
  const mxArray *c6_lhs209 = NULL;
  const mxArray *c6_rhs210 = NULL;
  const mxArray *c6_lhs210 = NULL;
  const mxArray *c6_rhs211 = NULL;
  const mxArray *c6_lhs211 = NULL;
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 192);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 192);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 192);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 192);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 192);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 192);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 192);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 192);
  sf_mex_assign(&c6_rhs192, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs192, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs192), "rhs", "rhs",
                  192);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs192), "lhs", "lhs",
                  192);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 193);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 193);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 193);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 193);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 193);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 193);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 193);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 193);
  sf_mex_assign(&c6_rhs193, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs193, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs193), "rhs", "rhs",
                  193);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs193), "lhs", "lhs",
                  193);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 194);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.blas.threshold"),
                  "name", "name", 194);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 194);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 194);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 194);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 194);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 194);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 194);
  sf_mex_assign(&c6_rhs194, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs194, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs194), "rhs", "rhs",
                  194);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs194), "lhs", "lhs",
                  194);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 195);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("min"), "name", "name", 195);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 195);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 195);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1311280518U), "fileTimeLo",
                  "fileTimeLo", 195);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 195);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 195);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 195);
  sf_mex_assign(&c6_rhs195, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs195, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs195), "rhs", "rhs",
                  195);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs195), "lhs", "lhs",
                  195);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 196);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 196);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 196);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 196);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 196);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 196);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 196);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 196);
  sf_mex_assign(&c6_rhs196, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs196, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs196), "rhs", "rhs",
                  196);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs196), "lhs", "lhs",
                  196);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 197);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.refblas.xgemm"),
                  "name", "name", 197);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 197);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 197);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 197);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 197);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 197);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 197);
  sf_mex_assign(&c6_rhs197, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs197, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs197), "rhs", "rhs",
                  197);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs197), "lhs", "lhs",
                  197);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "context", "context", 198);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 198);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 198);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 198);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1372608360U), "fileTimeLo",
                  "fileTimeLo", 198);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 198);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 198);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 198);
  sf_mex_assign(&c6_rhs198, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs198, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs198), "rhs", "rhs",
                  198);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs198), "lhs", "lhs",
                  198);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "context", "context", 199);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 199);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 199);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 199);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 199);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 199);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 199);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 199);
  sf_mex_assign(&c6_rhs199, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs199, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs199), "rhs", "rhs",
                  199);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs199), "lhs", "lhs",
                  199);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "context", "context", 200);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 200);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 200);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 200);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1372608360U), "fileTimeLo",
                  "fileTimeLo", 200);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 200);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 200);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 200);
  sf_mex_assign(&c6_rhs200, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs200, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs200), "rhs", "rhs",
                  200);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs200), "lhs", "lhs",
                  200);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "context", "context", 201);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 201);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 201);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 201);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1372608360U), "fileTimeLo",
                  "fileTimeLo", 201);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 201);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 201);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 201);
  sf_mex_assign(&c6_rhs201, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs201, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs201), "rhs", "rhs",
                  201);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs201), "lhs", "lhs",
                  201);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "context", "context", 202);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 202);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 202);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 202);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1397282622U), "fileTimeLo",
                  "fileTimeLo", 202);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 202);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 202);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 202);
  sf_mex_assign(&c6_rhs202, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs202, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs202), "rhs", "rhs",
                  202);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs202), "lhs", "lhs",
                  202);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "context", "context", 203);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 203);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 203);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 203);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1372608360U), "fileTimeLo",
                  "fileTimeLo", 203);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 203);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 203);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 203);
  sf_mex_assign(&c6_rhs203, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs203, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs203), "rhs", "rhs",
                  203);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs203), "lhs", "lhs",
                  203);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "context", "context", 204);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 204);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 204);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 204);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1383902494U), "fileTimeLo",
                  "fileTimeLo", 204);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 204);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 204);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 204);
  sf_mex_assign(&c6_rhs204, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs204, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs204), "rhs", "rhs",
                  204);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs204), "lhs", "lhs",
                  204);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 205);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 205);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 205);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 205);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 205);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 205);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 205);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 205);
  sf_mex_assign(&c6_rhs205, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs205, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs205), "rhs", "rhs",
                  205);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs205), "lhs", "lhs",
                  205);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 206);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 206);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 206);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 206);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 206);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 206);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 206);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 206);
  sf_mex_assign(&c6_rhs206, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs206, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs206), "rhs", "rhs",
                  206);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs206), "lhs", "lhs",
                  206);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 207);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 207);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 207);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 207);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 207);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 207);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 207);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 207);
  sf_mex_assign(&c6_rhs207, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs207, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs207), "rhs", "rhs",
                  207);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs207), "lhs", "lhs",
                  207);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 208);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  208);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 208);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 208);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1376005890U), "fileTimeLo",
                  "fileTimeLo", 208);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 208);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 208);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 208);
  sf_mex_assign(&c6_rhs208, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs208, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs208), "rhs", "rhs",
                  208);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs208), "lhs", "lhs",
                  208);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 209);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.blas.int"),
                  "name", "name", 209);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 209);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/int.p"),
                  "resolved", "resolved", 209);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 209);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 209);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 209);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 209);
  sf_mex_assign(&c6_rhs209, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs209, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs209), "rhs", "rhs",
                  209);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs209), "lhs", "lhs",
                  209);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!ceval_xgemm"),
                  "context", "context", 210);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.blas.size_ptr"),
                  "name", "name", 210);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 210);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/size_ptr.p"),
                  "resolved", "resolved", 210);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 210);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 210);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 210);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 210);
  sf_mex_assign(&c6_rhs210, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs210, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs210), "rhs", "rhs",
                  210);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs210), "lhs", "lhs",
                  210);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!ceval_xgemm"),
                  "context", "context", 211);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.c_cast"),
                  "name", "name", 211);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 211);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/c_cast.p"),
                  "resolved", "resolved", 211);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 211);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 211);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 211);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 211);
  sf_mex_assign(&c6_rhs211, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs211, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs211), "rhs", "rhs",
                  211);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs211), "lhs", "lhs",
                  211);
  sf_mex_destroy(&c6_rhs192);
  sf_mex_destroy(&c6_lhs192);
  sf_mex_destroy(&c6_rhs193);
  sf_mex_destroy(&c6_lhs193);
  sf_mex_destroy(&c6_rhs194);
  sf_mex_destroy(&c6_lhs194);
  sf_mex_destroy(&c6_rhs195);
  sf_mex_destroy(&c6_lhs195);
  sf_mex_destroy(&c6_rhs196);
  sf_mex_destroy(&c6_lhs196);
  sf_mex_destroy(&c6_rhs197);
  sf_mex_destroy(&c6_lhs197);
  sf_mex_destroy(&c6_rhs198);
  sf_mex_destroy(&c6_lhs198);
  sf_mex_destroy(&c6_rhs199);
  sf_mex_destroy(&c6_lhs199);
  sf_mex_destroy(&c6_rhs200);
  sf_mex_destroy(&c6_lhs200);
  sf_mex_destroy(&c6_rhs201);
  sf_mex_destroy(&c6_lhs201);
  sf_mex_destroy(&c6_rhs202);
  sf_mex_destroy(&c6_lhs202);
  sf_mex_destroy(&c6_rhs203);
  sf_mex_destroy(&c6_lhs203);
  sf_mex_destroy(&c6_rhs204);
  sf_mex_destroy(&c6_lhs204);
  sf_mex_destroy(&c6_rhs205);
  sf_mex_destroy(&c6_lhs205);
  sf_mex_destroy(&c6_rhs206);
  sf_mex_destroy(&c6_lhs206);
  sf_mex_destroy(&c6_rhs207);
  sf_mex_destroy(&c6_lhs207);
  sf_mex_destroy(&c6_rhs208);
  sf_mex_destroy(&c6_lhs208);
  sf_mex_destroy(&c6_rhs209);
  sf_mex_destroy(&c6_lhs209);
  sf_mex_destroy(&c6_rhs210);
  sf_mex_destroy(&c6_lhs210);
  sf_mex_destroy(&c6_rhs211);
  sf_mex_destroy(&c6_lhs211);
}

static void c6_eye(SFc6_Model1angularInstanceStruct *chartInstance, real_T c6_I
                   [9])
{
  int32_T c6_i84;
  int32_T c6_k;
  int32_T c6_b_k;
  for (c6_i84 = 0; c6_i84 < 9; c6_i84++) {
    c6_I[c6_i84] = 0.0;
  }

  c6_eml_switch_helper(chartInstance);
  for (c6_k = 1; c6_k < 4; c6_k++) {
    c6_b_k = c6_k;
    c6_I[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_b_k), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_k), 1, 3, 2, 0) - 1)) -
      1] = 1.0;
  }
}

static void c6_eml_switch_helper(SFc6_Model1angularInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_pinv(SFc6_Model1angularInstanceStruct *chartInstance, real_T
                    c6_A[72], real_T c6_X[72])
{
  int32_T c6_i85;
  int32_T c6_i86;
  int32_T c6_i87;
  int32_T c6_i88;
  real_T c6_b_A[72];
  int32_T c6_i89;
  real_T c6_b_X[72];
  int32_T c6_k;
  int32_T c6_b_k;
  real_T c6_x;
  real_T c6_b_x;
  boolean_T c6_b;
  boolean_T c6_b0;
  real_T c6_c_x;
  boolean_T c6_b_b;
  boolean_T c6_b1;
  boolean_T c6_c_b;
  int32_T c6_i90;
  real_T c6_c_A[72];
  real_T c6_V[36];
  real_T c6_s[6];
  real_T c6_U[72];
  int32_T c6_i91;
  real_T c6_S[36];
  int32_T c6_c_k;
  real_T c6_d_k;
  real_T c6_tol;
  int32_T c6_b_r;
  int32_T c6_e_k;
  int32_T c6_f_k;
  int32_T c6_a;
  int32_T c6_b_a;
  int32_T c6_vcol;
  int32_T c6_c_r;
  int32_T c6_d_b;
  int32_T c6_e_b;
  boolean_T c6_overflow;
  int32_T c6_j;
  int32_T c6_b_j;
  real_T c6_y;
  real_T c6_b_y;
  real_T c6_z;
  int32_T c6_c_a;
  int32_T c6_d_a;
  int32_T c6_i92;
  real_T c6_b_V[36];
  int32_T c6_i93;
  real_T c6_b_U[72];
  int32_T c6_i94;
  int32_T c6_i95;
  int32_T c6_i96;
  int32_T c6_i97;
  boolean_T exitg1;
  c6_i85 = 0;
  for (c6_i86 = 0; c6_i86 < 6; c6_i86++) {
    c6_i87 = 0;
    for (c6_i88 = 0; c6_i88 < 12; c6_i88++) {
      c6_b_A[c6_i88 + c6_i85] = c6_A[c6_i87 + c6_i86];
      c6_i87 += 6;
    }

    c6_i85 += 12;
  }

  for (c6_i89 = 0; c6_i89 < 72; c6_i89++) {
    c6_b_X[c6_i89] = 0.0;
  }

  c6_eml_switch_helper(chartInstance);
  for (c6_k = 1; c6_k < 73; c6_k++) {
    c6_b_k = c6_k;
    c6_x = c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_b_k), 1, 72, 1, 0) - 1];
    c6_b_x = c6_x;
    c6_b = muDoubleScalarIsInf(c6_b_x);
    c6_b0 = !c6_b;
    c6_c_x = c6_x;
    c6_b_b = muDoubleScalarIsNaN(c6_c_x);
    c6_b1 = !c6_b_b;
    c6_c_b = (c6_b0 && c6_b1);
    if (!c6_c_b) {
      c6_eml_error(chartInstance);
    }
  }

  for (c6_i90 = 0; c6_i90 < 72; c6_i90++) {
    c6_c_A[c6_i90] = c6_b_A[c6_i90];
  }

  c6_eml_xgesvd(chartInstance, c6_c_A, c6_U, c6_s, c6_V);
  for (c6_i91 = 0; c6_i91 < 36; c6_i91++) {
    c6_S[c6_i91] = 0.0;
  }

  for (c6_c_k = 0; c6_c_k < 6; c6_c_k++) {
    c6_d_k = 1.0 + (real_T)c6_c_k;
    c6_S[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c6_d_k),
           1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c6_d_k), 1, 6, 2, 0) - 1)) - 1] =
      c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c6_d_k), 1, 6, 1, 0) - 1];
  }

  c6_eps(chartInstance);
  c6_tol = 12.0 * c6_S[0] * 2.2204460492503131E-16;
  c6_b_r = 0;
  c6_eml_switch_helper(chartInstance);
  c6_e_k = 1;
  exitg1 = false;
  while ((exitg1 == false) && (c6_e_k < 7)) {
    c6_f_k = c6_e_k;
    if (!(c6_S[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_f_k), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_f_k), 1, 6, 2, 0) - 1)) -
          1] > c6_tol)) {
      exitg1 = true;
    } else {
      c6_a = c6_b_r;
      c6_b_a = c6_a + 1;
      c6_b_r = c6_b_a;
      c6_e_k++;
    }
  }

  if (c6_b_r > 0) {
    c6_vcol = 1;
    c6_c_r = c6_b_r;
    c6_d_b = c6_c_r;
    c6_e_b = c6_d_b;
    if (1 > c6_e_b) {
      c6_overflow = false;
    } else {
      c6_eml_switch_helper(chartInstance);
      c6_eml_switch_helper(chartInstance);
      c6_overflow = (c6_e_b > 2147483646);
    }

    if (c6_overflow) {
      c6_check_forloop_overflow_error(chartInstance, c6_overflow);
    }

    for (c6_j = 1; c6_j <= c6_c_r; c6_j++) {
      c6_b_j = c6_j;
      c6_y = c6_S[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c6_b_j), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                     (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_j), 1, 6, 2, 0)
        - 1)) - 1];
      c6_b_y = c6_y;
      c6_z = 1.0 / c6_b_y;
      c6_d_eml_xscal(chartInstance, c6_z, c6_V, c6_vcol);
      c6_c_a = c6_vcol;
      c6_d_a = c6_c_a + 6;
      c6_vcol = c6_d_a;
    }

    for (c6_i92 = 0; c6_i92 < 36; c6_i92++) {
      c6_b_V[c6_i92] = c6_V[c6_i92];
    }

    for (c6_i93 = 0; c6_i93 < 72; c6_i93++) {
      c6_b_U[c6_i93] = c6_U[c6_i93];
    }

    c6_c_eml_xgemm(chartInstance, c6_b_r, c6_b_V, c6_b_U, c6_b_X);
  }

  c6_i94 = 0;
  for (c6_i95 = 0; c6_i95 < 6; c6_i95++) {
    c6_i96 = 0;
    for (c6_i97 = 0; c6_i97 < 12; c6_i97++) {
      c6_X[c6_i97 + c6_i94] = c6_b_X[c6_i96 + c6_i95];
      c6_i96 += 6;
    }

    c6_i94 += 12;
  }
}

static void c6_eml_scalar_eg(SFc6_Model1angularInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_eml_error(SFc6_Model1angularInstanceStruct *chartInstance)
{
  int32_T c6_i98;
  static char_T c6_cv0[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 's', 'v', 'd', '_', 'm', 'a', 't', 'r', 'i', 'x', 'W', 'i',
    't', 'h', 'N', 'a', 'N', 'I', 'n', 'f' };

  char_T c6_u[33];
  const mxArray *c6_y = NULL;
  (void)chartInstance;
  for (c6_i98 = 0; c6_i98 < 33; c6_i98++) {
    c6_u[c6_i98] = c6_cv0[c6_i98];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 33), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c6_y));
}

static void c6_eml_xgesvd(SFc6_Model1angularInstanceStruct *chartInstance,
  real_T c6_A[72], real_T c6_U[72], real_T c6_S[6], real_T c6_V[36])
{
  int32_T c6_i99;
  real_T c6_b_A[72];
  int32_T c6_i100;
  real_T c6_s[6];
  int32_T c6_i101;
  real_T c6_e[6];
  int32_T c6_i102;
  real_T c6_work[12];
  int32_T c6_i103;
  int32_T c6_i104;
  real_T c6_Vf[36];
  int32_T c6_q;
  int32_T c6_b_q;
  int32_T c6_qp1;
  int32_T c6_qm1;
  int32_T c6_qq;
  int32_T c6_nmq;
  int32_T c6_nmqp1;
  boolean_T c6_apply_transform;
  int32_T c6_i105;
  real_T c6_c_A[72];
  real_T c6_nrm;
  real_T c6_absx;
  real_T c6_d;
  real_T c6_y;
  int32_T c6_n;
  real_T c6_a;
  int32_T c6_ix0;
  real_T c6_x;
  real_T c6_b_x;
  real_T c6_b_y;
  real_T c6_B;
  real_T c6_c_y;
  real_T c6_d_y;
  real_T c6_e_y;
  real_T c6_f_y;
  int32_T c6_b_n;
  real_T c6_b_a;
  int32_T c6_b_ix0;
  int32_T c6_c_n;
  real_T c6_c_a;
  int32_T c6_c_ix0;
  int32_T c6_d_ix0;
  int32_T c6_d_a;
  int32_T c6_c;
  int32_T c6_b;
  int32_T c6_b_c;
  int32_T c6_e_a;
  int32_T c6_b_b;
  int32_T c6_i106;
  int32_T c6_f_a;
  int32_T c6_c_b;
  int32_T c6_g_a;
  int32_T c6_d_b;
  boolean_T c6_overflow;
  int32_T c6_k;
  int32_T c6_b_k;
  int32_T c6_e_ix0;
  int32_T c6_h_a;
  int32_T c6_c_c;
  int32_T c6_e_b;
  int32_T c6_d_c;
  int32_T c6_i_a;
  int32_T c6_f_b;
  int32_T c6_i107;
  int32_T c6_j_a;
  int32_T c6_g_b;
  int32_T c6_k_a;
  int32_T c6_h_b;
  boolean_T c6_b_overflow;
  int32_T c6_c_k;
  int32_T c6_d_k;
  real_T c6_d_A;
  real_T c6_b_B;
  real_T c6_c_x;
  real_T c6_g_y;
  real_T c6_d_x;
  real_T c6_h_y;
  real_T c6_e_x;
  real_T c6_i_y;
  real_T c6_j_y;
  int32_T c6_b_qp1;
  int32_T c6_l_a;
  int32_T c6_m_a;
  boolean_T c6_c_overflow;
  int32_T c6_jj;
  int32_T c6_b_jj;
  int32_T c6_qjj;
  int32_T c6_i108;
  real_T c6_e_A[72];
  int32_T c6_i109;
  real_T c6_f_A[72];
  real_T c6_t;
  real_T c6_g_A;
  real_T c6_c_B;
  real_T c6_f_x;
  real_T c6_k_y;
  real_T c6_g_x;
  real_T c6_l_y;
  real_T c6_h_x;
  real_T c6_m_y;
  real_T c6_n_y;
  int32_T c6_c_q;
  int32_T c6_n_a;
  int32_T c6_o_a;
  boolean_T c6_d_overflow;
  int32_T c6_ii;
  int32_T c6_b_ii;
  int32_T c6_pmq;
  int32_T c6_i110;
  real_T c6_b_e[6];
  real_T c6_b_absx;
  real_T c6_b_d;
  real_T c6_o_y;
  int32_T c6_d_n;
  real_T c6_p_a;
  int32_T c6_f_ix0;
  real_T c6_i_x;
  real_T c6_j_x;
  real_T c6_p_y;
  real_T c6_d_B;
  real_T c6_q_y;
  real_T c6_r_y;
  real_T c6_s_y;
  real_T c6_t_y;
  int32_T c6_e_n;
  real_T c6_q_a;
  int32_T c6_g_ix0;
  int32_T c6_f_n;
  real_T c6_r_a;
  int32_T c6_h_ix0;
  int32_T c6_i_ix0;
  int32_T c6_s_a;
  int32_T c6_e_c;
  int32_T c6_i_b;
  int32_T c6_f_c;
  int32_T c6_t_a;
  int32_T c6_j_b;
  int32_T c6_i111;
  int32_T c6_u_a;
  int32_T c6_k_b;
  int32_T c6_v_a;
  int32_T c6_l_b;
  boolean_T c6_e_overflow;
  int32_T c6_e_k;
  int32_T c6_f_k;
  int32_T c6_j_ix0;
  int32_T c6_w_a;
  int32_T c6_g_c;
  int32_T c6_m_b;
  int32_T c6_h_c;
  int32_T c6_x_a;
  int32_T c6_n_b;
  int32_T c6_i112;
  int32_T c6_y_a;
  int32_T c6_o_b;
  int32_T c6_ab_a;
  int32_T c6_p_b;
  boolean_T c6_f_overflow;
  int32_T c6_g_k;
  int32_T c6_h_k;
  real_T c6_h_A;
  real_T c6_e_B;
  real_T c6_k_x;
  real_T c6_u_y;
  real_T c6_l_x;
  real_T c6_v_y;
  real_T c6_m_x;
  real_T c6_w_y;
  real_T c6_x_y;
  int32_T c6_c_qp1;
  int32_T c6_bb_a;
  int32_T c6_cb_a;
  boolean_T c6_g_overflow;
  int32_T c6_c_ii;
  int32_T c6_d_qp1;
  int32_T c6_db_a;
  int32_T c6_eb_a;
  boolean_T c6_h_overflow;
  int32_T c6_c_jj;
  int32_T c6_qp1jj;
  int32_T c6_i113;
  real_T c6_i_A[72];
  int32_T c6_e_qp1;
  int32_T c6_fb_a;
  int32_T c6_gb_a;
  boolean_T c6_i_overflow;
  int32_T c6_d_jj;
  real_T c6_j_A;
  real_T c6_f_B;
  real_T c6_n_x;
  real_T c6_y_y;
  real_T c6_o_x;
  real_T c6_ab_y;
  real_T c6_p_x;
  real_T c6_bb_y;
  int32_T c6_i114;
  real_T c6_b_work[12];
  int32_T c6_f_qp1;
  int32_T c6_hb_a;
  int32_T c6_ib_a;
  boolean_T c6_j_overflow;
  int32_T c6_d_ii;
  int32_T c6_m;
  int32_T c6_d_q;
  int32_T c6_g_qp1;
  int32_T c6_jb_a;
  int32_T c6_kb_a;
  boolean_T c6_k_overflow;
  int32_T c6_e_jj;
  int32_T c6_i115;
  real_T c6_b_U[72];
  int32_T c6_i116;
  real_T c6_c_U[72];
  real_T c6_k_A;
  real_T c6_g_B;
  real_T c6_q_x;
  real_T c6_cb_y;
  real_T c6_r_x;
  real_T c6_db_y;
  real_T c6_s_x;
  real_T c6_eb_y;
  real_T c6_fb_y;
  int32_T c6_e_q;
  int32_T c6_lb_a;
  int32_T c6_mb_a;
  boolean_T c6_l_overflow;
  int32_T c6_e_ii;
  int32_T c6_i117;
  int32_T c6_q_b;
  int32_T c6_r_b;
  boolean_T c6_m_overflow;
  int32_T c6_f_ii;
  int32_T c6_g_ii;
  int32_T c6_f_q;
  int32_T c6_qp1q;
  int32_T c6_h_qp1;
  int32_T c6_nb_a;
  int32_T c6_ob_a;
  boolean_T c6_n_overflow;
  int32_T c6_f_jj;
  int32_T c6_i118;
  real_T c6_b_Vf[36];
  int32_T c6_i119;
  real_T c6_c_Vf[36];
  real_T c6_l_A;
  real_T c6_h_B;
  real_T c6_t_x;
  real_T c6_gb_y;
  real_T c6_u_x;
  real_T c6_hb_y;
  real_T c6_v_x;
  real_T c6_ib_y;
  real_T c6_jb_y;
  int32_T c6_h_ii;
  int32_T c6_g_q;
  real_T c6_rt;
  real_T c6_m_A;
  real_T c6_i_B;
  real_T c6_w_x;
  real_T c6_kb_y;
  real_T c6_x_x;
  real_T c6_lb_y;
  real_T c6_y_x;
  real_T c6_mb_y;
  real_T c6_b_r;
  real_T c6_n_A;
  real_T c6_j_B;
  real_T c6_ab_x;
  real_T c6_nb_y;
  real_T c6_bb_x;
  real_T c6_ob_y;
  real_T c6_cb_x;
  real_T c6_pb_y;
  real_T c6_qb_y;
  int32_T c6_colq;
  real_T c6_o_A;
  real_T c6_k_B;
  real_T c6_db_x;
  real_T c6_rb_y;
  real_T c6_eb_x;
  real_T c6_sb_y;
  real_T c6_fb_x;
  real_T c6_tb_y;
  int32_T c6_colqp1;
  real_T c6_iter;
  real_T c6_snorm;
  int32_T c6_i_ii;
  real_T c6_varargin_1;
  real_T c6_varargin_2;
  real_T c6_b_varargin_2;
  real_T c6_varargin_3;
  real_T c6_gb_x;
  real_T c6_ub_y;
  real_T c6_hb_x;
  real_T c6_vb_y;
  real_T c6_xk;
  real_T c6_yk;
  real_T c6_ib_x;
  real_T c6_wb_y;
  real_T c6_maxval;
  real_T c6_b_varargin_1;
  real_T c6_c_varargin_2;
  real_T c6_d_varargin_2;
  real_T c6_b_varargin_3;
  real_T c6_jb_x;
  real_T c6_xb_y;
  real_T c6_kb_x;
  real_T c6_yb_y;
  real_T c6_b_xk;
  real_T c6_b_yk;
  real_T c6_lb_x;
  real_T c6_ac_y;
  int32_T c6_i120;
  int32_T c6_pb_a;
  int32_T c6_qb_a;
  boolean_T c6_o_overflow;
  int32_T c6_j_ii;
  real_T c6_test0;
  real_T c6_ztest0;
  real_T c6_kase;
  int32_T c6_qs;
  int32_T c6_b_m;
  int32_T c6_h_q;
  int32_T c6_rb_a;
  int32_T c6_s_b;
  int32_T c6_sb_a;
  int32_T c6_t_b;
  boolean_T c6_p_overflow;
  int32_T c6_k_ii;
  real_T c6_test;
  real_T c6_ztest;
  real_T c6_f;
  int32_T c6_i121;
  int32_T c6_i_q;
  int32_T c6_tb_a;
  int32_T c6_u_b;
  int32_T c6_ub_a;
  int32_T c6_v_b;
  boolean_T c6_q_overflow;
  int32_T c6_i_k;
  int32_T c6_j_k;
  real_T c6_t1;
  real_T c6_b_t1;
  real_T c6_b_f;
  real_T c6_sn;
  real_T c6_cs;
  real_T c6_b_cs;
  real_T c6_b_sn;
  int32_T c6_km1;
  int32_T c6_colk;
  int32_T c6_colm;
  int32_T c6_j_q;
  int32_T c6_c_m;
  int32_T c6_vb_a;
  int32_T c6_w_b;
  int32_T c6_wb_a;
  int32_T c6_x_b;
  boolean_T c6_r_overflow;
  int32_T c6_k_k;
  real_T c6_c_t1;
  real_T c6_unusedU0;
  real_T c6_c_sn;
  real_T c6_c_cs;
  int32_T c6_colqm1;
  int32_T c6_mm1;
  real_T c6_d1;
  real_T c6_d2;
  real_T c6_d3;
  real_T c6_d4;
  real_T c6_d5;
  real_T c6_c_varargin_1[5];
  int32_T c6_ixstart;
  real_T c6_mtmp;
  real_T c6_mb_x;
  boolean_T c6_y_b;
  int32_T c6_ix;
  int32_T c6_b_ix;
  real_T c6_nb_x;
  boolean_T c6_ab_b;
  int32_T c6_xb_a;
  int32_T c6_yb_a;
  int32_T c6_i122;
  int32_T c6_ac_a;
  int32_T c6_bc_a;
  boolean_T c6_s_overflow;
  int32_T c6_c_ix;
  real_T c6_cc_a;
  real_T c6_bb_b;
  boolean_T c6_p;
  real_T c6_b_mtmp;
  real_T c6_scale;
  real_T c6_p_A;
  real_T c6_l_B;
  real_T c6_ob_x;
  real_T c6_bc_y;
  real_T c6_pb_x;
  real_T c6_cc_y;
  real_T c6_qb_x;
  real_T c6_dc_y;
  real_T c6_sm;
  real_T c6_q_A;
  real_T c6_m_B;
  real_T c6_rb_x;
  real_T c6_ec_y;
  real_T c6_sb_x;
  real_T c6_fc_y;
  real_T c6_tb_x;
  real_T c6_gc_y;
  real_T c6_smm1;
  real_T c6_r_A;
  real_T c6_n_B;
  real_T c6_ub_x;
  real_T c6_hc_y;
  real_T c6_vb_x;
  real_T c6_ic_y;
  real_T c6_wb_x;
  real_T c6_jc_y;
  real_T c6_emm1;
  real_T c6_s_A;
  real_T c6_o_B;
  real_T c6_xb_x;
  real_T c6_kc_y;
  real_T c6_yb_x;
  real_T c6_lc_y;
  real_T c6_ac_x;
  real_T c6_mc_y;
  real_T c6_sqds;
  real_T c6_t_A;
  real_T c6_p_B;
  real_T c6_bc_x;
  real_T c6_nc_y;
  real_T c6_cc_x;
  real_T c6_oc_y;
  real_T c6_dc_x;
  real_T c6_pc_y;
  real_T c6_eqds;
  real_T c6_u_A;
  real_T c6_ec_x;
  real_T c6_fc_x;
  real_T c6_gc_x;
  real_T c6_cb_b;
  real_T c6_i_c;
  real_T c6_shift;
  real_T c6_v_A;
  real_T c6_q_B;
  real_T c6_hc_x;
  real_T c6_qc_y;
  real_T c6_ic_x;
  real_T c6_rc_y;
  real_T c6_jc_x;
  real_T c6_sc_y;
  real_T c6_g;
  int32_T c6_k_q;
  int32_T c6_b_mm1;
  int32_T c6_dc_a;
  int32_T c6_db_b;
  int32_T c6_ec_a;
  int32_T c6_eb_b;
  boolean_T c6_t_overflow;
  int32_T c6_l_k;
  int32_T c6_kp1;
  real_T c6_c_f;
  real_T c6_unusedU1;
  real_T c6_d_sn;
  real_T c6_d_cs;
  int32_T c6_colkp1;
  real_T c6_d_f;
  real_T c6_unusedU2;
  real_T c6_e_sn;
  real_T c6_e_cs;
  int32_T c6_m_k;
  int32_T c6_j;
  int32_T c6_b_j;
  int32_T c6_i;
  int32_T c6_b_i;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  boolean_T exitg4;
  boolean_T exitg5;
  boolean_T guard11 = false;
  for (c6_i99 = 0; c6_i99 < 72; c6_i99++) {
    c6_b_A[c6_i99] = c6_A[c6_i99];
  }

  c6_eml_scalar_eg(chartInstance);
  for (c6_i100 = 0; c6_i100 < 6; c6_i100++) {
    c6_s[c6_i100] = 0.0;
  }

  for (c6_i101 = 0; c6_i101 < 6; c6_i101++) {
    c6_e[c6_i101] = 0.0;
  }

  for (c6_i102 = 0; c6_i102 < 12; c6_i102++) {
    c6_work[c6_i102] = 0.0;
  }

  for (c6_i103 = 0; c6_i103 < 72; c6_i103++) {
    c6_U[c6_i103] = 0.0;
  }

  for (c6_i104 = 0; c6_i104 < 36; c6_i104++) {
    c6_Vf[c6_i104] = 0.0;
  }

  c6_eml_switch_helper(chartInstance);
  for (c6_q = 1; c6_q < 7; c6_q++) {
    c6_b_q = c6_q;
    c6_qp1 = c6_b_q + 1;
    c6_qm1 = c6_b_q;
    c6_qq = c6_b_q + 12 * (c6_qm1 - 1);
    c6_nmq = 12 - c6_b_q;
    c6_nmqp1 = c6_nmq + 1;
    c6_apply_transform = false;
    if (c6_b_q <= 6) {
      for (c6_i105 = 0; c6_i105 < 72; c6_i105++) {
        c6_c_A[c6_i105] = c6_b_A[c6_i105];
      }

      c6_nrm = c6_eml_xnrm2(chartInstance, c6_nmqp1, c6_c_A, c6_qq);
      if (c6_nrm > 0.0) {
        c6_apply_transform = true;
        c6_absx = c6_nrm;
        c6_d = c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c6_qq), 1, 72, 1, 0) - 1];
        if (c6_d < 0.0) {
          c6_y = -c6_absx;
        } else {
          c6_y = c6_absx;
        }

        c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_q), 1, 6, 1, 0) - 1] = c6_y;
        c6_n = c6_nmqp1;
        c6_a = c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c6_b_q), 1, 6, 1, 0) - 1];
        c6_ix0 = c6_qq;
        c6_realmin(chartInstance);
        c6_eps(chartInstance);
        c6_x = c6_a;
        c6_b_x = c6_x;
        c6_b_y = muDoubleScalarAbs(c6_b_x);
        if (c6_b_y >= 1.0020841800044864E-292) {
          c6_B = c6_a;
          c6_c_y = c6_B;
          c6_d_y = c6_c_y;
          c6_e_y = c6_d_y;
          c6_f_y = 1.0 / c6_e_y;
          c6_b_n = c6_n;
          c6_b_a = c6_f_y;
          c6_b_ix0 = c6_ix0;
          c6_b_eml_switch_helper(chartInstance);
          c6_c_n = c6_b_n;
          c6_c_a = c6_b_a;
          c6_c_ix0 = c6_b_ix0;
          c6_d_ix0 = c6_c_ix0;
          c6_d_a = c6_c_n;
          c6_c = c6_d_a;
          c6_b = c6_c - 1;
          c6_b_c = c6_b;
          c6_e_a = c6_c_ix0;
          c6_b_b = c6_b_c;
          c6_i106 = c6_e_a + c6_b_b;
          c6_f_a = c6_d_ix0;
          c6_c_b = c6_i106;
          c6_g_a = c6_f_a;
          c6_d_b = c6_c_b;
          if (c6_g_a > c6_d_b) {
            c6_overflow = false;
          } else {
            c6_eml_switch_helper(chartInstance);
            c6_eml_switch_helper(chartInstance);
            c6_overflow = (c6_d_b > 2147483646);
          }

          if (c6_overflow) {
            c6_check_forloop_overflow_error(chartInstance, c6_overflow);
          }

          for (c6_k = c6_d_ix0; c6_k <= c6_i106; c6_k++) {
            c6_b_k = c6_k;
            c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c6_b_k), 1, 72, 1, 0) - 1] = c6_c_a *
              c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
              ("", (real_T)c6_b_k), 1, 72, 1, 0) - 1];
          }
        } else {
          c6_e_ix0 = c6_ix0;
          c6_h_a = c6_n;
          c6_c_c = c6_h_a;
          c6_e_b = c6_c_c - 1;
          c6_d_c = c6_e_b;
          c6_i_a = c6_ix0;
          c6_f_b = c6_d_c;
          c6_i107 = c6_i_a + c6_f_b;
          c6_j_a = c6_e_ix0;
          c6_g_b = c6_i107;
          c6_k_a = c6_j_a;
          c6_h_b = c6_g_b;
          if (c6_k_a > c6_h_b) {
            c6_b_overflow = false;
          } else {
            c6_eml_switch_helper(chartInstance);
            c6_eml_switch_helper(chartInstance);
            c6_b_overflow = (c6_h_b > 2147483646);
          }

          if (c6_b_overflow) {
            c6_check_forloop_overflow_error(chartInstance, c6_b_overflow);
          }

          for (c6_c_k = c6_e_ix0; c6_c_k <= c6_i107; c6_c_k++) {
            c6_d_k = c6_c_k;
            c6_d_A = c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c6_d_k), 1, 72, 1, 0) - 1];
            c6_b_B = c6_a;
            c6_c_x = c6_d_A;
            c6_g_y = c6_b_B;
            c6_d_x = c6_c_x;
            c6_h_y = c6_g_y;
            c6_e_x = c6_d_x;
            c6_i_y = c6_h_y;
            c6_j_y = c6_e_x / c6_i_y;
            c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c6_d_k), 1, 72, 1, 0) - 1] = c6_j_y;
          }
        }

        c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_qq), 1, 72, 1, 0) - 1] = c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK
          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_qq), 1, 72, 1, 0) - 1]
          + 1.0;
        c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_q), 1, 6, 1, 0) - 1] = -c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 6, 1, 0) - 1];
      } else {
        c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_q), 1, 6, 1, 0) - 1] = 0.0;
      }
    }

    c6_b_qp1 = c6_qp1;
    c6_l_a = c6_b_qp1;
    c6_m_a = c6_l_a;
    if (c6_m_a > 6) {
      c6_c_overflow = false;
    } else {
      c6_eml_switch_helper(chartInstance);
      c6_eml_switch_helper(chartInstance);
      c6_c_overflow = false;
    }

    if (c6_c_overflow) {
      c6_check_forloop_overflow_error(chartInstance, c6_c_overflow);
    }

    for (c6_jj = c6_b_qp1; c6_jj < 7; c6_jj++) {
      c6_b_jj = c6_jj;
      c6_qjj = c6_b_q + 12 * (c6_b_jj - 1);
      if (c6_apply_transform) {
        for (c6_i108 = 0; c6_i108 < 72; c6_i108++) {
          c6_e_A[c6_i108] = c6_b_A[c6_i108];
        }

        for (c6_i109 = 0; c6_i109 < 72; c6_i109++) {
          c6_f_A[c6_i109] = c6_b_A[c6_i109];
        }

        c6_t = c6_eml_xdotc(chartInstance, c6_nmqp1, c6_e_A, c6_qq, c6_f_A,
                            c6_qjj);
        c6_g_A = c6_t;
        c6_c_B = c6_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 12, 1, 0) + 12 *
                         (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 6, 2, 0) - 1)) - 1];
        c6_f_x = c6_g_A;
        c6_k_y = c6_c_B;
        c6_g_x = c6_f_x;
        c6_l_y = c6_k_y;
        c6_h_x = c6_g_x;
        c6_m_y = c6_l_y;
        c6_n_y = c6_h_x / c6_m_y;
        c6_t = -c6_n_y;
        c6_e_eml_xaxpy(chartInstance, c6_nmqp1, c6_t, c6_qq, c6_b_A, c6_qjj);
      }

      c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c6_b_jj), 1, 6, 1, 0) - 1] = c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_qjj), 1, 72, 1, 0) - 1];
    }

    if (c6_b_q <= 6) {
      c6_c_q = c6_b_q;
      c6_n_a = c6_c_q;
      c6_o_a = c6_n_a;
      if (c6_o_a > 12) {
        c6_d_overflow = false;
      } else {
        c6_eml_switch_helper(chartInstance);
        c6_eml_switch_helper(chartInstance);
        c6_d_overflow = false;
      }

      if (c6_d_overflow) {
        c6_check_forloop_overflow_error(chartInstance, c6_d_overflow);
      }

      for (c6_ii = c6_c_q; c6_ii < 13; c6_ii++) {
        c6_b_ii = c6_ii;
        c6_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c6_b_ii), 1, 12, 1, 0) + 12 *
              (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c6_b_q), 1, 6, 2, 0) - 1)) - 1] = c6_b_A
          [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c6_b_ii), 1, 12, 1, 0) + 12 * (_SFD_EML_ARRAY_BOUNDS_CHECK
             ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 6, 2, 0) -
             1)) - 1];
      }
    }

    if (c6_b_q <= 4) {
      c6_pmq = 6 - c6_b_q;
      for (c6_i110 = 0; c6_i110 < 6; c6_i110++) {
        c6_b_e[c6_i110] = c6_e[c6_i110];
      }

      c6_nrm = c6_b_eml_xnrm2(chartInstance, c6_pmq, c6_b_e, c6_qp1);
      if (c6_nrm == 0.0) {
        c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_q), 1, 6, 1, 0) - 1] = 0.0;
      } else {
        c6_b_absx = c6_nrm;
        c6_b_d = c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c6_qp1), 1, 6, 1, 0) - 1];
        if (c6_b_d < 0.0) {
          c6_o_y = -c6_b_absx;
        } else {
          c6_o_y = c6_b_absx;
        }

        c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_q), 1, 6, 1, 0) - 1] = c6_o_y;
        c6_d_n = c6_pmq;
        c6_p_a = c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 6, 1, 0) - 1];
        c6_f_ix0 = c6_qp1;
        c6_realmin(chartInstance);
        c6_eps(chartInstance);
        c6_i_x = c6_p_a;
        c6_j_x = c6_i_x;
        c6_p_y = muDoubleScalarAbs(c6_j_x);
        if (c6_p_y >= 1.0020841800044864E-292) {
          c6_d_B = c6_p_a;
          c6_q_y = c6_d_B;
          c6_r_y = c6_q_y;
          c6_s_y = c6_r_y;
          c6_t_y = 1.0 / c6_s_y;
          c6_e_n = c6_d_n;
          c6_q_a = c6_t_y;
          c6_g_ix0 = c6_f_ix0;
          c6_b_eml_switch_helper(chartInstance);
          c6_f_n = c6_e_n;
          c6_r_a = c6_q_a;
          c6_h_ix0 = c6_g_ix0;
          c6_i_ix0 = c6_h_ix0;
          c6_s_a = c6_f_n;
          c6_e_c = c6_s_a;
          c6_i_b = c6_e_c - 1;
          c6_f_c = c6_i_b;
          c6_t_a = c6_h_ix0;
          c6_j_b = c6_f_c;
          c6_i111 = c6_t_a + c6_j_b;
          c6_u_a = c6_i_ix0;
          c6_k_b = c6_i111;
          c6_v_a = c6_u_a;
          c6_l_b = c6_k_b;
          if (c6_v_a > c6_l_b) {
            c6_e_overflow = false;
          } else {
            c6_eml_switch_helper(chartInstance);
            c6_eml_switch_helper(chartInstance);
            c6_e_overflow = (c6_l_b > 2147483646);
          }

          if (c6_e_overflow) {
            c6_check_forloop_overflow_error(chartInstance, c6_e_overflow);
          }

          for (c6_e_k = c6_i_ix0; c6_e_k <= c6_i111; c6_e_k++) {
            c6_f_k = c6_e_k;
            c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c6_f_k), 1, 6, 1, 0) - 1] = c6_r_a *
              c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c6_f_k), 1, 6, 1, 0) - 1];
          }
        } else {
          c6_j_ix0 = c6_f_ix0;
          c6_w_a = c6_d_n;
          c6_g_c = c6_w_a;
          c6_m_b = c6_g_c - 1;
          c6_h_c = c6_m_b;
          c6_x_a = c6_f_ix0;
          c6_n_b = c6_h_c;
          c6_i112 = c6_x_a + c6_n_b;
          c6_y_a = c6_j_ix0;
          c6_o_b = c6_i112;
          c6_ab_a = c6_y_a;
          c6_p_b = c6_o_b;
          if (c6_ab_a > c6_p_b) {
            c6_f_overflow = false;
          } else {
            c6_eml_switch_helper(chartInstance);
            c6_eml_switch_helper(chartInstance);
            c6_f_overflow = (c6_p_b > 2147483646);
          }

          if (c6_f_overflow) {
            c6_check_forloop_overflow_error(chartInstance, c6_f_overflow);
          }

          for (c6_g_k = c6_j_ix0; c6_g_k <= c6_i112; c6_g_k++) {
            c6_h_k = c6_g_k;
            c6_h_A = c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c6_h_k), 1, 6, 1, 0) - 1];
            c6_e_B = c6_p_a;
            c6_k_x = c6_h_A;
            c6_u_y = c6_e_B;
            c6_l_x = c6_k_x;
            c6_v_y = c6_u_y;
            c6_m_x = c6_l_x;
            c6_w_y = c6_v_y;
            c6_x_y = c6_m_x / c6_w_y;
            c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c6_h_k), 1, 6, 1, 0) - 1] = c6_x_y;
          }
        }

        c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_qp1), 1, 6, 1, 0) - 1] = c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_qp1), 1, 6, 1, 0) - 1]
          + 1.0;
        c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_q), 1, 6, 1, 0) - 1] = -c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 6, 1, 0) - 1];
        if (c6_qp1 <= 12) {
          c6_c_qp1 = c6_qp1;
          c6_bb_a = c6_c_qp1;
          c6_cb_a = c6_bb_a;
          if (c6_cb_a > 12) {
            c6_g_overflow = false;
          } else {
            c6_eml_switch_helper(chartInstance);
            c6_eml_switch_helper(chartInstance);
            c6_g_overflow = false;
          }

          if (c6_g_overflow) {
            c6_check_forloop_overflow_error(chartInstance, c6_g_overflow);
          }

          for (c6_c_ii = c6_c_qp1; c6_c_ii < 13; c6_c_ii++) {
            c6_b_ii = c6_c_ii;
            c6_work[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c6_b_ii), 1, 12, 1, 0) - 1] = 0.0;
          }

          c6_d_qp1 = c6_qp1;
          c6_db_a = c6_d_qp1;
          c6_eb_a = c6_db_a;
          if (c6_eb_a > 6) {
            c6_h_overflow = false;
          } else {
            c6_eml_switch_helper(chartInstance);
            c6_eml_switch_helper(chartInstance);
            c6_h_overflow = false;
          }

          if (c6_h_overflow) {
            c6_check_forloop_overflow_error(chartInstance, c6_h_overflow);
          }

          for (c6_c_jj = c6_d_qp1; c6_c_jj < 7; c6_c_jj++) {
            c6_b_jj = c6_c_jj;
            c6_qp1jj = c6_qp1 + 12 * (c6_b_jj - 1);
            for (c6_i113 = 0; c6_i113 < 72; c6_i113++) {
              c6_i_A[c6_i113] = c6_b_A[c6_i113];
            }

            c6_f_eml_xaxpy(chartInstance, c6_nmq,
                           c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c6_b_jj), 1, 6, 1, 0) - 1], c6_i_A,
                           c6_qp1jj, c6_work, c6_qp1);
          }

          c6_e_qp1 = c6_qp1;
          c6_fb_a = c6_e_qp1;
          c6_gb_a = c6_fb_a;
          if (c6_gb_a > 6) {
            c6_i_overflow = false;
          } else {
            c6_eml_switch_helper(chartInstance);
            c6_eml_switch_helper(chartInstance);
            c6_i_overflow = false;
          }

          if (c6_i_overflow) {
            c6_check_forloop_overflow_error(chartInstance, c6_i_overflow);
          }

          for (c6_d_jj = c6_e_qp1; c6_d_jj < 7; c6_d_jj++) {
            c6_b_jj = c6_d_jj;
            c6_j_A = -c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c6_b_jj), 1, 6, 1, 0) - 1];
            c6_f_B = c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c6_qp1), 1, 6, 1, 0) - 1];
            c6_n_x = c6_j_A;
            c6_y_y = c6_f_B;
            c6_o_x = c6_n_x;
            c6_ab_y = c6_y_y;
            c6_p_x = c6_o_x;
            c6_bb_y = c6_ab_y;
            c6_t = c6_p_x / c6_bb_y;
            c6_qp1jj = c6_qp1 + 12 * (c6_b_jj - 1);
            for (c6_i114 = 0; c6_i114 < 12; c6_i114++) {
              c6_b_work[c6_i114] = c6_work[c6_i114];
            }

            c6_g_eml_xaxpy(chartInstance, c6_nmq, c6_t, c6_b_work, c6_qp1,
                           c6_b_A, c6_qp1jj);
          }
        }
      }

      c6_f_qp1 = c6_qp1;
      c6_hb_a = c6_f_qp1;
      c6_ib_a = c6_hb_a;
      if (c6_ib_a > 6) {
        c6_j_overflow = false;
      } else {
        c6_eml_switch_helper(chartInstance);
        c6_eml_switch_helper(chartInstance);
        c6_j_overflow = false;
      }

      if (c6_j_overflow) {
        c6_check_forloop_overflow_error(chartInstance, c6_j_overflow);
      }

      for (c6_d_ii = c6_f_qp1; c6_d_ii < 7; c6_d_ii++) {
        c6_b_ii = c6_d_ii;
        c6_Vf[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c6_b_ii), 1, 6, 1, 0) + 6 *
               (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c6_b_q), 1, 6, 2, 0) - 1)) - 1] =
          c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_ii), 1, 6, 1, 0) - 1];
      }
    }
  }

  c6_m = 5;
  c6_e[4] = c6_b_A[64];
  c6_e[5] = 0.0;
  c6_eml_switch_helper(chartInstance);
  for (c6_d_q = 6; c6_d_q > 0; c6_d_q--) {
    c6_b_q = c6_d_q;
    c6_qp1 = c6_b_q;
    c6_nmq = 13 - c6_b_q;
    c6_nmqp1 = c6_nmq;
    c6_qq = c6_b_q + 12 * (c6_b_q - 1);
    if (c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_q), 1, 6, 1, 0) - 1] != 0.0) {
      c6_g_qp1 = c6_qp1 + 1;
      c6_jb_a = c6_g_qp1;
      c6_kb_a = c6_jb_a;
      if (c6_kb_a > 6) {
        c6_k_overflow = false;
      } else {
        c6_eml_switch_helper(chartInstance);
        c6_eml_switch_helper(chartInstance);
        c6_k_overflow = false;
      }

      if (c6_k_overflow) {
        c6_check_forloop_overflow_error(chartInstance, c6_k_overflow);
      }

      for (c6_e_jj = c6_g_qp1; c6_e_jj < 7; c6_e_jj++) {
        c6_b_jj = c6_e_jj - 1;
        c6_qjj = c6_b_q + 12 * c6_b_jj;
        for (c6_i115 = 0; c6_i115 < 72; c6_i115++) {
          c6_b_U[c6_i115] = c6_U[c6_i115];
        }

        for (c6_i116 = 0; c6_i116 < 72; c6_i116++) {
          c6_c_U[c6_i116] = c6_U[c6_i116];
        }

        c6_t = c6_eml_xdotc(chartInstance, c6_nmqp1, c6_b_U, c6_qq, c6_c_U,
                            c6_qjj);
        c6_k_A = c6_t;
        c6_g_B = c6_U[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c6_qq), 1, 72, 1, 0) - 1];
        c6_q_x = c6_k_A;
        c6_cb_y = c6_g_B;
        c6_r_x = c6_q_x;
        c6_db_y = c6_cb_y;
        c6_s_x = c6_r_x;
        c6_eb_y = c6_db_y;
        c6_fb_y = c6_s_x / c6_eb_y;
        c6_t = -c6_fb_y;
        c6_e_eml_xaxpy(chartInstance, c6_nmqp1, c6_t, c6_qq, c6_U, c6_qjj);
      }

      c6_e_q = c6_b_q;
      c6_lb_a = c6_e_q;
      c6_mb_a = c6_lb_a;
      if (c6_mb_a > 12) {
        c6_l_overflow = false;
      } else {
        c6_eml_switch_helper(chartInstance);
        c6_eml_switch_helper(chartInstance);
        c6_l_overflow = false;
      }

      if (c6_l_overflow) {
        c6_check_forloop_overflow_error(chartInstance, c6_l_overflow);
      }

      for (c6_e_ii = c6_e_q; c6_e_ii < 13; c6_e_ii++) {
        c6_b_ii = c6_e_ii;
        c6_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c6_b_ii), 1, 12, 1, 0) + 12 *
              (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c6_b_q), 1, 6, 2, 0) - 1)) - 1] = -c6_U
          [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c6_b_ii), 1, 12, 1, 0) + 12 * (_SFD_EML_ARRAY_BOUNDS_CHECK
             ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 6, 2, 0) -
             1)) - 1];
      }

      c6_U[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c6_qq), 1, 72, 1, 0) - 1] = c6_U[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_qq), 1, 72, 1, 0) - 1] + 1.0;
      c6_i117 = c6_b_q - 1;
      c6_q_b = c6_i117;
      c6_r_b = c6_q_b;
      if (1 > c6_r_b) {
        c6_m_overflow = false;
      } else {
        c6_eml_switch_helper(chartInstance);
        c6_eml_switch_helper(chartInstance);
        c6_m_overflow = (c6_r_b > 2147483646);
      }

      if (c6_m_overflow) {
        c6_check_forloop_overflow_error(chartInstance, c6_m_overflow);
      }

      for (c6_f_ii = 1; c6_f_ii <= c6_i117; c6_f_ii++) {
        c6_b_ii = c6_f_ii;
        c6_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c6_b_ii), 1, 12, 1, 0) + 12 *
              (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c6_b_q), 1, 6, 2, 0) - 1)) - 1] = 0.0;
      }
    } else {
      c6_eml_switch_helper(chartInstance);
      for (c6_g_ii = 1; c6_g_ii < 13; c6_g_ii++) {
        c6_b_ii = c6_g_ii;
        c6_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c6_b_ii), 1, 12, 1, 0) + 12 *
              (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c6_b_q), 1, 6, 2, 0) - 1)) - 1] = 0.0;
      }

      c6_U[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c6_qq), 1, 72, 1, 0) - 1] = 1.0;
    }
  }

  c6_eml_switch_helper(chartInstance);
  for (c6_f_q = 6; c6_f_q > 0; c6_f_q--) {
    c6_b_q = c6_f_q;
    if (c6_b_q <= 4) {
      if (c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_b_q), 1, 6, 1, 0) - 1] != 0.0) {
        c6_qp1 = c6_b_q + 1;
        c6_pmq = 6 - c6_b_q;
        c6_qp1q = c6_qp1 + 6 * (c6_b_q - 1);
        c6_h_qp1 = c6_qp1;
        c6_nb_a = c6_h_qp1;
        c6_ob_a = c6_nb_a;
        if (c6_ob_a > 6) {
          c6_n_overflow = false;
        } else {
          c6_eml_switch_helper(chartInstance);
          c6_eml_switch_helper(chartInstance);
          c6_n_overflow = false;
        }

        if (c6_n_overflow) {
          c6_check_forloop_overflow_error(chartInstance, c6_n_overflow);
        }

        for (c6_f_jj = c6_h_qp1; c6_f_jj < 7; c6_f_jj++) {
          c6_b_jj = c6_f_jj - 1;
          c6_qp1jj = c6_qp1 + 6 * c6_b_jj;
          for (c6_i118 = 0; c6_i118 < 36; c6_i118++) {
            c6_b_Vf[c6_i118] = c6_Vf[c6_i118];
          }

          for (c6_i119 = 0; c6_i119 < 36; c6_i119++) {
            c6_c_Vf[c6_i119] = c6_Vf[c6_i119];
          }

          c6_t = c6_b_eml_xdotc(chartInstance, c6_pmq, c6_b_Vf, c6_qp1q, c6_c_Vf,
                                c6_qp1jj);
          c6_l_A = c6_t;
          c6_h_B = c6_Vf[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c6_qp1q), 1, 36, 1, 0) - 1];
          c6_t_x = c6_l_A;
          c6_gb_y = c6_h_B;
          c6_u_x = c6_t_x;
          c6_hb_y = c6_gb_y;
          c6_v_x = c6_u_x;
          c6_ib_y = c6_hb_y;
          c6_jb_y = c6_v_x / c6_ib_y;
          c6_t = -c6_jb_y;
          c6_h_eml_xaxpy(chartInstance, c6_pmq, c6_t, c6_qp1q, c6_Vf, c6_qp1jj);
        }
      }
    }

    c6_eml_switch_helper(chartInstance);
    for (c6_h_ii = 1; c6_h_ii < 7; c6_h_ii++) {
      c6_b_ii = c6_h_ii;
      c6_Vf[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
               (real_T)c6_b_ii), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
               "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 6, 2, 0)
              - 1)) - 1] = 0.0;
    }

    c6_Vf[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
             (real_T)c6_b_q), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 6, 2, 0) - 1))
      - 1] = 1.0;
  }

  c6_eml_switch_helper(chartInstance);
  for (c6_g_q = 1; c6_g_q < 7; c6_g_q++) {
    c6_b_q = c6_g_q;
    if (c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_q), 1, 6, 1, 0) - 1] != 0.0) {
      c6_rt = c6_abs(chartInstance, c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 6, 1, 0) - 1]);
      c6_m_A = c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c6_b_q), 1, 6, 1, 0) - 1];
      c6_i_B = c6_rt;
      c6_w_x = c6_m_A;
      c6_kb_y = c6_i_B;
      c6_x_x = c6_w_x;
      c6_lb_y = c6_kb_y;
      c6_y_x = c6_x_x;
      c6_mb_y = c6_lb_y;
      c6_b_r = c6_y_x / c6_mb_y;
      c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c6_b_q), 1, 6, 1, 0) - 1] = c6_rt;
      if (c6_b_q < 6) {
        c6_n_A = c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 6, 1, 0) - 1];
        c6_j_B = c6_b_r;
        c6_ab_x = c6_n_A;
        c6_nb_y = c6_j_B;
        c6_bb_x = c6_ab_x;
        c6_ob_y = c6_nb_y;
        c6_cb_x = c6_bb_x;
        c6_pb_y = c6_ob_y;
        c6_qb_y = c6_cb_x / c6_pb_y;
        c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_q), 1, 6, 1, 0) - 1] = c6_qb_y;
      }

      if (c6_b_q <= 12) {
        c6_colq = 12 * (c6_b_q - 1);
        c6_c_eml_xscal(chartInstance, c6_b_r, c6_U, c6_colq + 1);
      }
    }

    if (c6_b_q < 6) {
      if (c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_b_q), 1, 6, 1, 0) - 1] != 0.0) {
        c6_rt = c6_abs(chartInstance, c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 6, 1, 0) - 1]);
        c6_o_A = c6_rt;
        c6_k_B = c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 6, 1, 0) - 1];
        c6_db_x = c6_o_A;
        c6_rb_y = c6_k_B;
        c6_eb_x = c6_db_x;
        c6_sb_y = c6_rb_y;
        c6_fb_x = c6_eb_x;
        c6_tb_y = c6_sb_y;
        c6_b_r = c6_fb_x / c6_tb_y;
        c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_q), 1, 6, 1, 0) - 1] = c6_rt;
        c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c6_b_q + 1)), 1, 6, 1, 0) - 1] =
          c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c6_b_q + 1)), 1, 6, 1, 0) - 1] * c6_b_r;
        c6_colqp1 = 6 * c6_b_q;
        c6_d_eml_xscal(chartInstance, c6_b_r, c6_Vf, c6_colqp1 + 1);
      }
    }
  }

  c6_iter = 0.0;
  c6_realmin(chartInstance);
  c6_eps(chartInstance);
  c6_snorm = 0.0;
  c6_eml_switch_helper(chartInstance);
  for (c6_i_ii = 1; c6_i_ii < 7; c6_i_ii++) {
    c6_b_ii = c6_i_ii;
    c6_varargin_1 = c6_abs(chartInstance, c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_ii), 1, 6, 1, 0) - 1]);
    c6_varargin_2 = c6_abs(chartInstance, c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_ii), 1, 6, 1, 0) - 1]);
    c6_b_varargin_2 = c6_varargin_1;
    c6_varargin_3 = c6_varargin_2;
    c6_gb_x = c6_b_varargin_2;
    c6_ub_y = c6_varargin_3;
    c6_hb_x = c6_gb_x;
    c6_vb_y = c6_ub_y;
    c6_b_eml_scalar_eg(chartInstance);
    c6_xk = c6_hb_x;
    c6_yk = c6_vb_y;
    c6_ib_x = c6_xk;
    c6_wb_y = c6_yk;
    c6_b_eml_scalar_eg(chartInstance);
    c6_maxval = muDoubleScalarMax(c6_ib_x, c6_wb_y);
    c6_b_varargin_1 = c6_snorm;
    c6_c_varargin_2 = c6_maxval;
    c6_d_varargin_2 = c6_b_varargin_1;
    c6_b_varargin_3 = c6_c_varargin_2;
    c6_jb_x = c6_d_varargin_2;
    c6_xb_y = c6_b_varargin_3;
    c6_kb_x = c6_jb_x;
    c6_yb_y = c6_xb_y;
    c6_b_eml_scalar_eg(chartInstance);
    c6_b_xk = c6_kb_x;
    c6_b_yk = c6_yb_y;
    c6_lb_x = c6_b_xk;
    c6_ac_y = c6_b_yk;
    c6_b_eml_scalar_eg(chartInstance);
    c6_snorm = muDoubleScalarMax(c6_lb_x, c6_ac_y);
  }

  exitg1 = false;
  while ((exitg1 == false) && (c6_m + 1 > 0)) {
    if (c6_iter >= 75.0) {
      c6_b_eml_error(chartInstance);
      exitg1 = true;
    } else {
      c6_b_q = c6_m;
      c6_i120 = c6_m;
      c6_pb_a = c6_i120;
      c6_qb_a = c6_pb_a;
      if (c6_qb_a < 0) {
        c6_o_overflow = false;
      } else {
        c6_eml_switch_helper(chartInstance);
        c6_eml_switch_helper(chartInstance);
        c6_o_overflow = false;
      }

      if (c6_o_overflow) {
        c6_check_forloop_overflow_error(chartInstance, c6_o_overflow);
      }

      c6_j_ii = c6_i120;
      guard3 = false;
      guard4 = false;
      exitg5 = false;
      while ((exitg5 == false) && (c6_j_ii > -1)) {
        c6_b_ii = c6_j_ii;
        c6_b_q = c6_b_ii;
        if (c6_b_ii == 0) {
          exitg5 = true;
        } else {
          c6_test0 = c6_abs(chartInstance, c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_ii), 1,
            6, 1, 0) - 1]) + c6_abs(chartInstance,
            c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                                      (real_T)(c6_b_ii + 1)), 1, 6, 1, 0) - 1]);
          c6_ztest0 = c6_abs(chartInstance, c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_ii),
            1, 6, 1, 0) - 1]);
          c6_eps(chartInstance);
          if (c6_ztest0 <= 2.2204460492503131E-16 * c6_test0) {
            guard4 = true;
            exitg5 = true;
          } else if (c6_ztest0 <= 1.0020841800044864E-292) {
            guard4 = true;
            exitg5 = true;
          } else {
            guard11 = false;
            if (c6_iter > 20.0) {
              c6_eps(chartInstance);
              if (c6_ztest0 <= 2.2204460492503131E-16 * c6_snorm) {
                guard3 = true;
                exitg5 = true;
              } else {
                guard11 = true;
              }
            } else {
              guard11 = true;
            }

            if (guard11 == true) {
              c6_j_ii--;
              guard3 = false;
              guard4 = false;
            }
          }
        }
      }

      if (guard4 == true) {
        guard3 = true;
      }

      if (guard3 == true) {
        c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_ii), 1, 6, 1, 0) - 1] = 0.0;
      }

      if (c6_b_q == c6_m) {
        c6_kase = 4.0;
      } else {
        c6_qs = c6_m + 1;
        c6_b_m = c6_m + 1;
        c6_h_q = c6_b_q;
        c6_rb_a = c6_b_m;
        c6_s_b = c6_h_q;
        c6_sb_a = c6_rb_a;
        c6_t_b = c6_s_b;
        if (c6_sb_a < c6_t_b) {
          c6_p_overflow = false;
        } else {
          c6_eml_switch_helper(chartInstance);
          c6_eml_switch_helper(chartInstance);
          c6_p_overflow = (c6_t_b < -2147483647);
        }

        if (c6_p_overflow) {
          c6_check_forloop_overflow_error(chartInstance, c6_p_overflow);
        }

        c6_k_ii = c6_b_m;
        guard2 = false;
        exitg4 = false;
        while ((exitg4 == false) && (c6_k_ii >= c6_h_q)) {
          c6_b_ii = c6_k_ii;
          c6_qs = c6_b_ii;
          if (c6_b_ii == c6_b_q) {
            exitg4 = true;
          } else {
            c6_test = 0.0;
            if (c6_b_ii < c6_m + 1) {
              c6_test = c6_abs(chartInstance, c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
                "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_ii), 1, 6, 1, 0)
                               - 1]);
            }

            if (c6_b_ii > c6_b_q + 1) {
              c6_test += c6_abs(chartInstance, c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
                "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c6_b_ii - 1)), 1, 6,
                1, 0) - 1]);
            }

            c6_ztest = c6_abs(chartInstance, c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                               (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_ii),
              1, 6, 1, 0) - 1]);
            c6_eps(chartInstance);
            if (c6_ztest <= 2.2204460492503131E-16 * c6_test) {
              guard2 = true;
              exitg4 = true;
            } else if (c6_ztest <= 1.0020841800044864E-292) {
              guard2 = true;
              exitg4 = true;
            } else {
              c6_k_ii--;
              guard2 = false;
            }
          }
        }

        if (guard2 == true) {
          c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_b_ii), 1, 6, 1, 0) - 1] = 0.0;
        }

        if (c6_qs == c6_b_q) {
          c6_kase = 3.0;
        } else if (c6_qs == c6_m + 1) {
          c6_kase = 1.0;
        } else {
          c6_kase = 2.0;
          c6_b_q = c6_qs;
        }
      }

      c6_b_q++;
      switch ((int32_T)_SFD_INTEGER_CHECK("", c6_kase)) {
       case 1:
        c6_f = c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c6_m), 1, 6, 1, 0) - 1];
        c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_m), 1, 6, 1, 0) - 1] = 0.0;
        c6_i121 = c6_m;
        c6_i_q = c6_b_q;
        c6_tb_a = c6_i121;
        c6_u_b = c6_i_q;
        c6_ub_a = c6_tb_a;
        c6_v_b = c6_u_b;
        if (c6_ub_a < c6_v_b) {
          c6_q_overflow = false;
        } else {
          c6_eml_switch_helper(chartInstance);
          c6_eml_switch_helper(chartInstance);
          c6_q_overflow = (c6_v_b < -2147483647);
        }

        if (c6_q_overflow) {
          c6_check_forloop_overflow_error(chartInstance, c6_q_overflow);
        }

        for (c6_i_k = c6_i121; c6_i_k >= c6_i_q; c6_i_k--) {
          c6_j_k = c6_i_k;
          c6_t1 = c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c6_j_k), 1, 6, 1, 0) - 1];
          c6_b_t1 = c6_t1;
          c6_b_f = c6_f;
          c6_b_eml_xrotg(chartInstance, &c6_b_t1, &c6_b_f, &c6_cs, &c6_sn);
          c6_t1 = c6_b_t1;
          c6_f = c6_b_f;
          c6_b_cs = c6_cs;
          c6_b_sn = c6_sn;
          c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_j_k), 1, 6, 1, 0) - 1] = c6_t1;
          if (c6_j_k > c6_b_q) {
            c6_km1 = c6_j_k - 1;
            c6_f = -c6_b_sn * c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c6_km1), 1, 6, 1, 0) - 1];
            c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c6_km1), 1, 6, 1, 0) - 1] =
              c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c6_km1), 1, 6, 1, 0) - 1] * c6_b_cs;
          }

          c6_colk = 6 * (c6_j_k - 1);
          c6_colm = 6 * c6_m;
          c6_c_eml_xrot(chartInstance, c6_Vf, c6_colk + 1, c6_colm + 1, c6_b_cs,
                        c6_b_sn);
        }
        break;

       case 2:
        c6_qm1 = c6_b_q - 1;
        c6_f = c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c6_qm1), 1, 6, 1, 0) - 1];
        c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_qm1), 1, 6, 1, 0) - 1] = 0.0;
        c6_j_q = c6_b_q;
        c6_c_m = c6_m + 1;
        c6_vb_a = c6_j_q;
        c6_w_b = c6_c_m;
        c6_wb_a = c6_vb_a;
        c6_x_b = c6_w_b;
        if (c6_wb_a > c6_x_b) {
          c6_r_overflow = false;
        } else {
          c6_eml_switch_helper(chartInstance);
          c6_eml_switch_helper(chartInstance);
          c6_r_overflow = (c6_x_b > 2147483646);
        }

        if (c6_r_overflow) {
          c6_check_forloop_overflow_error(chartInstance, c6_r_overflow);
        }

        for (c6_k_k = c6_j_q; c6_k_k <= c6_c_m; c6_k_k++) {
          c6_j_k = c6_k_k;
          c6_t1 = c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c6_j_k), 1, 6, 1, 0) - 1];
          c6_c_t1 = c6_t1;
          c6_unusedU0 = c6_f;
          c6_b_eml_xrotg(chartInstance, &c6_c_t1, &c6_unusedU0, &c6_c_cs,
                         &c6_c_sn);
          c6_t1 = c6_c_t1;
          c6_b_cs = c6_c_cs;
          c6_b_sn = c6_c_sn;
          c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_j_k), 1, 6, 1, 0) - 1] = c6_t1;
          c6_f = -c6_b_sn * c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c6_j_k), 1, 6, 1, 0) - 1];
          c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_j_k), 1, 6, 1, 0) - 1] = c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK
            ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_j_k), 1, 6, 1, 0) -
            1] * c6_b_cs;
          c6_colk = 12 * (c6_j_k - 1);
          c6_colqm1 = 12 * (c6_qm1 - 1);
          c6_d_eml_xrot(chartInstance, c6_U, c6_colk + 1, c6_colqm1 + 1, c6_b_cs,
                        c6_b_sn);
        }
        break;

       case 3:
        c6_mm1 = c6_m;
        c6_d1 = c6_abs(chartInstance, c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c6_m + 1)), 1, 6, 1, 0) - 1]);
        c6_d2 = c6_abs(chartInstance, c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_mm1), 1, 6, 1, 0) - 1]);
        c6_d3 = c6_abs(chartInstance, c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_mm1), 1, 6, 1, 0) - 1]);
        c6_d4 = c6_abs(chartInstance, c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 6, 1, 0) - 1]);
        c6_d5 = c6_abs(chartInstance, c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 6, 1, 0) - 1]);
        c6_c_varargin_1[0] = c6_d1;
        c6_c_varargin_1[1] = c6_d2;
        c6_c_varargin_1[2] = c6_d3;
        c6_c_varargin_1[3] = c6_d4;
        c6_c_varargin_1[4] = c6_d5;
        c6_ixstart = 1;
        c6_mtmp = c6_c_varargin_1[0];
        c6_mb_x = c6_mtmp;
        c6_y_b = muDoubleScalarIsNaN(c6_mb_x);
        if (c6_y_b) {
          c6_eml_switch_helper(chartInstance);
          c6_eml_switch_helper(chartInstance);
          c6_ix = 2;
          exitg2 = false;
          while ((exitg2 == false) && (c6_ix < 6)) {
            c6_b_ix = c6_ix;
            c6_ixstart = c6_b_ix;
            c6_nb_x = c6_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c6_b_ix), 1, 5, 1, 0) - 1];
            c6_ab_b = muDoubleScalarIsNaN(c6_nb_x);
            if (!c6_ab_b) {
              c6_mtmp = c6_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c6_b_ix), 1, 5, 1, 0) - 1];
              exitg2 = true;
            } else {
              c6_ix++;
            }
          }
        }

        if (c6_ixstart < 5) {
          c6_xb_a = c6_ixstart;
          c6_yb_a = c6_xb_a + 1;
          c6_i122 = c6_yb_a;
          c6_ac_a = c6_i122;
          c6_bc_a = c6_ac_a;
          if (c6_bc_a > 5) {
            c6_s_overflow = false;
          } else {
            c6_eml_switch_helper(chartInstance);
            c6_eml_switch_helper(chartInstance);
            c6_s_overflow = false;
          }

          if (c6_s_overflow) {
            c6_check_forloop_overflow_error(chartInstance, c6_s_overflow);
          }

          for (c6_c_ix = c6_i122; c6_c_ix < 6; c6_c_ix++) {
            c6_b_ix = c6_c_ix;
            c6_cc_a = c6_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c6_b_ix), 1, 5, 1, 0) - 1];
            c6_bb_b = c6_mtmp;
            c6_p = (c6_cc_a > c6_bb_b);
            if (c6_p) {
              c6_mtmp = c6_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c6_b_ix), 1, 5, 1, 0) - 1];
            }
          }
        }

        c6_b_mtmp = c6_mtmp;
        c6_scale = c6_b_mtmp;
        c6_p_A = c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)(c6_m + 1)), 1, 6, 1, 0) - 1];
        c6_l_B = c6_scale;
        c6_ob_x = c6_p_A;
        c6_bc_y = c6_l_B;
        c6_pb_x = c6_ob_x;
        c6_cc_y = c6_bc_y;
        c6_qb_x = c6_pb_x;
        c6_dc_y = c6_cc_y;
        c6_sm = c6_qb_x / c6_dc_y;
        c6_q_A = c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c6_mm1), 1, 6, 1, 0) - 1];
        c6_m_B = c6_scale;
        c6_rb_x = c6_q_A;
        c6_ec_y = c6_m_B;
        c6_sb_x = c6_rb_x;
        c6_fc_y = c6_ec_y;
        c6_tb_x = c6_sb_x;
        c6_gc_y = c6_fc_y;
        c6_smm1 = c6_tb_x / c6_gc_y;
        c6_r_A = c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c6_mm1), 1, 6, 1, 0) - 1];
        c6_n_B = c6_scale;
        c6_ub_x = c6_r_A;
        c6_hc_y = c6_n_B;
        c6_vb_x = c6_ub_x;
        c6_ic_y = c6_hc_y;
        c6_wb_x = c6_vb_x;
        c6_jc_y = c6_ic_y;
        c6_emm1 = c6_wb_x / c6_jc_y;
        c6_s_A = c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 6, 1, 0) - 1];
        c6_o_B = c6_scale;
        c6_xb_x = c6_s_A;
        c6_kc_y = c6_o_B;
        c6_yb_x = c6_xb_x;
        c6_lc_y = c6_kc_y;
        c6_ac_x = c6_yb_x;
        c6_mc_y = c6_lc_y;
        c6_sqds = c6_ac_x / c6_mc_y;
        c6_t_A = c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 6, 1, 0) - 1];
        c6_p_B = c6_scale;
        c6_bc_x = c6_t_A;
        c6_nc_y = c6_p_B;
        c6_cc_x = c6_bc_x;
        c6_oc_y = c6_nc_y;
        c6_dc_x = c6_cc_x;
        c6_pc_y = c6_oc_y;
        c6_eqds = c6_dc_x / c6_pc_y;
        c6_u_A = (c6_smm1 + c6_sm) * (c6_smm1 - c6_sm) + c6_emm1 * c6_emm1;
        c6_ec_x = c6_u_A;
        c6_fc_x = c6_ec_x;
        c6_gc_x = c6_fc_x;
        c6_cb_b = c6_gc_x / 2.0;
        c6_i_c = c6_sm * c6_emm1;
        c6_i_c *= c6_i_c;
        guard1 = false;
        if (c6_cb_b != 0.0) {
          guard1 = true;
        } else if (c6_i_c != 0.0) {
          guard1 = true;
        } else {
          c6_shift = 0.0;
        }

        if (guard1 == true) {
          c6_shift = c6_cb_b * c6_cb_b + c6_i_c;
          c6_b_sqrt(chartInstance, &c6_shift);
          if (c6_cb_b < 0.0) {
            c6_shift = -c6_shift;
          }

          c6_v_A = c6_i_c;
          c6_q_B = c6_cb_b + c6_shift;
          c6_hc_x = c6_v_A;
          c6_qc_y = c6_q_B;
          c6_ic_x = c6_hc_x;
          c6_rc_y = c6_qc_y;
          c6_jc_x = c6_ic_x;
          c6_sc_y = c6_rc_y;
          c6_shift = c6_jc_x / c6_sc_y;
        }

        c6_f = (c6_sqds + c6_sm) * (c6_sqds - c6_sm) + c6_shift;
        c6_g = c6_sqds * c6_eqds;
        c6_k_q = c6_b_q;
        c6_b_mm1 = c6_mm1;
        c6_dc_a = c6_k_q;
        c6_db_b = c6_b_mm1;
        c6_ec_a = c6_dc_a;
        c6_eb_b = c6_db_b;
        if (c6_ec_a > c6_eb_b) {
          c6_t_overflow = false;
        } else {
          c6_eml_switch_helper(chartInstance);
          c6_eml_switch_helper(chartInstance);
          c6_t_overflow = (c6_eb_b > 2147483646);
        }

        if (c6_t_overflow) {
          c6_check_forloop_overflow_error(chartInstance, c6_t_overflow);
        }

        for (c6_l_k = c6_k_q; c6_l_k <= c6_b_mm1; c6_l_k++) {
          c6_j_k = c6_l_k;
          c6_km1 = c6_j_k;
          c6_kp1 = c6_j_k + 1;
          c6_c_f = c6_f;
          c6_unusedU1 = c6_g;
          c6_b_eml_xrotg(chartInstance, &c6_c_f, &c6_unusedU1, &c6_d_cs,
                         &c6_d_sn);
          c6_f = c6_c_f;
          c6_b_cs = c6_d_cs;
          c6_b_sn = c6_d_sn;
          if (c6_j_k > c6_b_q) {
            c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)(c6_km1 - 1)), 1, 6, 1, 0) - 1] = c6_f;
          }

          c6_f = c6_b_cs * c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c6_j_k), 1, 6, 1, 0) - 1] + c6_b_sn *
            c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_j_k), 1, 6, 1, 0) - 1];
          c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_j_k), 1, 6, 1, 0) - 1] = c6_b_cs *
            c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_j_k), 1, 6, 1, 0) - 1] - c6_b_sn *
            c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_j_k), 1, 6, 1, 0) - 1];
          c6_g = c6_b_sn * c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c6_kp1), 1, 6, 1, 0) - 1];
          c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_kp1), 1, 6, 1, 0) - 1] = c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK
            ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_kp1), 1, 6, 1, 0) -
            1] * c6_b_cs;
          c6_colk = 6 * (c6_j_k - 1);
          c6_colkp1 = 6 * c6_j_k;
          c6_c_eml_xrot(chartInstance, c6_Vf, c6_colk + 1, c6_colkp1 + 1,
                        c6_b_cs, c6_b_sn);
          c6_d_f = c6_f;
          c6_unusedU2 = c6_g;
          c6_b_eml_xrotg(chartInstance, &c6_d_f, &c6_unusedU2, &c6_e_cs,
                         &c6_e_sn);
          c6_f = c6_d_f;
          c6_b_cs = c6_e_cs;
          c6_b_sn = c6_e_sn;
          c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_j_k), 1, 6, 1, 0) - 1] = c6_f;
          c6_f = c6_b_cs * c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c6_j_k), 1, 6, 1, 0) - 1] + c6_b_sn *
            c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_kp1), 1, 6, 1, 0) - 1];
          c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_kp1), 1, 6, 1, 0) - 1] = -c6_b_sn *
            c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_j_k), 1, 6, 1, 0) - 1] + c6_b_cs *
            c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_kp1), 1, 6, 1, 0) - 1];
          c6_g = c6_b_sn * c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c6_kp1), 1, 6, 1, 0) - 1];
          c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_kp1), 1, 6, 1, 0) - 1] = c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK
            ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_kp1), 1, 6, 1, 0) -
            1] * c6_b_cs;
          if (c6_j_k < 12) {
            c6_colk = 12 * (c6_j_k - 1);
            c6_colkp1 = 12 * c6_j_k;
            c6_d_eml_xrot(chartInstance, c6_U, c6_colk + 1, c6_colkp1 + 1,
                          c6_b_cs, c6_b_sn);
          }
        }

        c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_m), 1, 6, 1, 0) - 1] = c6_f;
        c6_iter++;
        break;

       default:
        if (c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c6_b_q), 1, 6, 1, 0) - 1] < 0.0) {
          c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_b_q), 1, 6, 1, 0) - 1] =
            -c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_b_q), 1, 6, 1, 0) - 1];
          c6_colq = 6 * (c6_b_q - 1);
          c6_c_eml_scalar_eg(chartInstance);
          c6_d_eml_xscal(chartInstance, -1.0, c6_Vf, c6_colq + 1);
        }

        c6_qp1 = c6_b_q + 1;
        exitg3 = false;
        while ((exitg3 == false) && (c6_b_q < 6)) {
          if (c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c6_b_q), 1, 6, 1, 0) - 1] <
              c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c6_qp1), 1, 6, 1, 0) - 1]) {
            c6_rt = c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 6, 1, 0) - 1];
            c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c6_b_q), 1, 6, 1, 0) - 1] =
              c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c6_qp1), 1, 6, 1, 0) - 1];
            c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c6_qp1), 1, 6, 1, 0) - 1] = c6_rt;
            if (c6_b_q < 6) {
              c6_colq = 6 * (c6_b_q - 1);
              c6_colqp1 = 6 * c6_b_q;
              c6_c_eml_xswap(chartInstance, c6_Vf, c6_colq + 1, c6_colqp1 + 1);
            }

            if (c6_b_q < 12) {
              c6_colq = 12 * (c6_b_q - 1);
              c6_colqp1 = 12 * c6_b_q;
              c6_d_eml_xswap(chartInstance, c6_U, c6_colq + 1, c6_colqp1 + 1);
            }

            c6_b_q = c6_qp1;
            c6_qp1 = c6_b_q + 1;
          } else {
            exitg3 = true;
          }
        }

        c6_iter = 0.0;
        c6_m--;
        break;
      }
    }
  }

  c6_eml_switch_helper(chartInstance);
  for (c6_m_k = 1; c6_m_k < 7; c6_m_k++) {
    c6_j_k = c6_m_k;
    c6_S[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c6_j_k), 1, 6, 1, 0) - 1] = c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c6_j_k), 1, 6, 1, 0) - 1];
  }

  c6_eml_switch_helper(chartInstance);
  for (c6_j = 1; c6_j < 7; c6_j++) {
    c6_b_j = c6_j;
    c6_eml_switch_helper(chartInstance);
    for (c6_i = 1; c6_i < 7; c6_i++) {
      c6_b_i = c6_i;
      c6_V[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c6_b_i), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_j), 1, 6, 2, 0) - 1))
        - 1] = c6_Vf[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c6_b_i), 1, 6, 1, 0) + 6 *
                      (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c6_b_j), 1, 6, 2, 0) - 1)) - 1];
    }
  }
}

static real_T c6_eml_xnrm2(SFc6_Model1angularInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_x[72], int32_T c6_ix0)
{
  real_T c6_y;
  int32_T c6_b_n;
  int32_T c6_b_ix0;
  int32_T c6_c_n;
  int32_T c6_c_ix0;
  real_T c6_b_x;
  real_T c6_c_x;
  real_T c6_scale;
  int32_T c6_kstart;
  int32_T c6_a;
  int32_T c6_c;
  int32_T c6_b_a;
  int32_T c6_b_c;
  int32_T c6_c_a;
  int32_T c6_b;
  int32_T c6_kend;
  int32_T c6_b_kstart;
  int32_T c6_b_kend;
  int32_T c6_d_a;
  int32_T c6_b_b;
  int32_T c6_e_a;
  int32_T c6_c_b;
  boolean_T c6_overflow;
  int32_T c6_k;
  int32_T c6_b_k;
  real_T c6_d_x;
  real_T c6_e_x;
  real_T c6_absxk;
  real_T c6_t;
  c6_b_n = c6_n;
  c6_b_ix0 = c6_ix0;
  c6_threshold(chartInstance);
  c6_c_n = c6_b_n;
  c6_c_ix0 = c6_b_ix0;
  c6_y = 0.0;
  if (c6_c_n < 1) {
  } else if (c6_c_n == 1) {
    c6_b_x = c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_c_ix0), 1, 72, 1, 0) - 1];
    c6_c_x = c6_b_x;
    c6_y = muDoubleScalarAbs(c6_c_x);
  } else {
    c6_realmin(chartInstance);
    c6_scale = 2.2250738585072014E-308;
    c6_kstart = c6_c_ix0;
    c6_a = c6_c_n;
    c6_c = c6_a;
    c6_b_a = c6_c - 1;
    c6_b_c = c6_b_a;
    c6_c_a = c6_kstart;
    c6_b = c6_b_c;
    c6_kend = c6_c_a + c6_b;
    c6_b_kstart = c6_kstart;
    c6_b_kend = c6_kend;
    c6_d_a = c6_b_kstart;
    c6_b_b = c6_b_kend;
    c6_e_a = c6_d_a;
    c6_c_b = c6_b_b;
    if (c6_e_a > c6_c_b) {
      c6_overflow = false;
    } else {
      c6_eml_switch_helper(chartInstance);
      c6_eml_switch_helper(chartInstance);
      c6_overflow = (c6_c_b > 2147483646);
    }

    if (c6_overflow) {
      c6_check_forloop_overflow_error(chartInstance, c6_overflow);
    }

    for (c6_k = c6_b_kstart; c6_k <= c6_b_kend; c6_k++) {
      c6_b_k = c6_k;
      c6_d_x = c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c6_b_k), 1, 72, 1, 0) - 1];
      c6_e_x = c6_d_x;
      c6_absxk = muDoubleScalarAbs(c6_e_x);
      if (c6_absxk > c6_scale) {
        c6_t = c6_scale / c6_absxk;
        c6_y = 1.0 + c6_y * c6_t * c6_t;
        c6_scale = c6_absxk;
      } else {
        c6_t = c6_absxk / c6_scale;
        c6_y += c6_t * c6_t;
      }
    }

    c6_y = c6_scale * muDoubleScalarSqrt(c6_y);
  }

  return c6_y;
}

static boolean_T c6_use_refblas(SFc6_Model1angularInstanceStruct *chartInstance)
{
  (void)chartInstance;
  return false;
}

static void c6_threshold(SFc6_Model1angularInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c6_abs(SFc6_Model1angularInstanceStruct *chartInstance, real_T
                     c6_x)
{
  real_T c6_b_x;
  (void)chartInstance;
  c6_b_x = c6_x;
  return muDoubleScalarAbs(c6_b_x);
}

static void c6_realmin(SFc6_Model1angularInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_check_forloop_overflow_error(SFc6_Model1angularInstanceStruct
  *chartInstance, boolean_T c6_overflow)
{
  int32_T c6_i123;
  static char_T c6_cv1[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c6_u[34];
  const mxArray *c6_y = NULL;
  int32_T c6_i124;
  static char_T c6_cv2[5] = { 'i', 'n', 't', '3', '2' };

  char_T c6_b_u[5];
  const mxArray *c6_b_y = NULL;
  (void)chartInstance;
  if (!c6_overflow) {
  } else {
    for (c6_i123 = 0; c6_i123 < 34; c6_i123++) {
      c6_u[c6_i123] = c6_cv1[c6_i123];
    }

    c6_y = NULL;
    sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    for (c6_i124 = 0; c6_i124 < 5; c6_i124++) {
      c6_b_u[c6_i124] = c6_cv2[c6_i124];
    }

    c6_b_y = NULL;
    sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_b_u, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 2U, 14, c6_y, 14, c6_b_y));
  }
}

static void c6_eps(SFc6_Model1angularInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_b_eml_switch_helper(SFc6_Model1angularInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static real_T c6_eml_xdotc(SFc6_Model1angularInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_x[72], int32_T c6_ix0, real_T c6_y[72], int32_T c6_iy0)
{
  real_T c6_d;
  int32_T c6_b_n;
  int32_T c6_b_ix0;
  int32_T c6_b_iy0;
  int32_T c6_c_n;
  int32_T c6_c_ix0;
  int32_T c6_c_iy0;
  int32_T c6_d_n;
  int32_T c6_d_ix0;
  int32_T c6_d_iy0;
  int32_T c6_e_n;
  int32_T c6_e_ix0;
  int32_T c6_e_iy0;
  int32_T c6_ix;
  int32_T c6_iy;
  int32_T c6_f_n;
  int32_T c6_b;
  int32_T c6_b_b;
  boolean_T c6_overflow;
  int32_T c6_k;
  int32_T c6_a;
  int32_T c6_b_a;
  c6_b_n = c6_n;
  c6_b_ix0 = c6_ix0;
  c6_b_iy0 = c6_iy0;
  c6_c_n = c6_b_n;
  c6_c_ix0 = c6_b_ix0;
  c6_c_iy0 = c6_b_iy0;
  c6_b_threshold(chartInstance);
  c6_d_n = c6_c_n;
  c6_d_ix0 = c6_c_ix0;
  c6_d_iy0 = c6_c_iy0;
  c6_e_n = c6_d_n;
  c6_e_ix0 = c6_d_ix0;
  c6_e_iy0 = c6_d_iy0;
  c6_d = 0.0;
  if (c6_e_n < 1) {
  } else {
    c6_ix = c6_e_ix0;
    c6_iy = c6_e_iy0;
    c6_f_n = c6_e_n;
    c6_b = c6_f_n;
    c6_b_b = c6_b;
    if (1 > c6_b_b) {
      c6_overflow = false;
    } else {
      c6_eml_switch_helper(chartInstance);
      c6_eml_switch_helper(chartInstance);
      c6_overflow = (c6_b_b > 2147483646);
    }

    if (c6_overflow) {
      c6_check_forloop_overflow_error(chartInstance, c6_overflow);
    }

    for (c6_k = 1; c6_k <= c6_f_n; c6_k++) {
      c6_d += c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c6_ix), 1, 72, 1, 0) - 1] * c6_y[_SFD_EML_ARRAY_BOUNDS_CHECK
        ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_iy), 1, 72, 1, 0) - 1];
      c6_a = c6_ix + 1;
      c6_ix = c6_a;
      c6_b_a = c6_iy + 1;
      c6_iy = c6_b_a;
    }
  }

  return c6_d;
}

static void c6_b_threshold(SFc6_Model1angularInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_eml_xaxpy(SFc6_Model1angularInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, int32_T c6_ix0, real_T c6_y[72], int32_T c6_iy0,
  real_T c6_b_y[72])
{
  int32_T c6_i125;
  for (c6_i125 = 0; c6_i125 < 72; c6_i125++) {
    c6_b_y[c6_i125] = c6_y[c6_i125];
  }

  c6_e_eml_xaxpy(chartInstance, c6_n, c6_a, c6_ix0, c6_b_y, c6_iy0);
}

static void c6_c_threshold(SFc6_Model1angularInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c6_b_eml_xnrm2(SFc6_Model1angularInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_x[6], int32_T c6_ix0)
{
  real_T c6_y;
  int32_T c6_b_n;
  int32_T c6_b_ix0;
  int32_T c6_c_n;
  int32_T c6_c_ix0;
  real_T c6_b_x;
  real_T c6_c_x;
  real_T c6_scale;
  int32_T c6_kstart;
  int32_T c6_a;
  int32_T c6_c;
  int32_T c6_b_a;
  int32_T c6_b_c;
  int32_T c6_c_a;
  int32_T c6_b;
  int32_T c6_kend;
  int32_T c6_b_kstart;
  int32_T c6_b_kend;
  int32_T c6_d_a;
  int32_T c6_b_b;
  int32_T c6_e_a;
  int32_T c6_c_b;
  boolean_T c6_overflow;
  int32_T c6_k;
  int32_T c6_b_k;
  real_T c6_d_x;
  real_T c6_e_x;
  real_T c6_absxk;
  real_T c6_t;
  c6_b_n = c6_n;
  c6_b_ix0 = c6_ix0;
  c6_threshold(chartInstance);
  c6_c_n = c6_b_n;
  c6_c_ix0 = c6_b_ix0;
  c6_y = 0.0;
  if (c6_c_n < 1) {
  } else if (c6_c_n == 1) {
    c6_b_x = c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_c_ix0), 1, 6, 1, 0) - 1];
    c6_c_x = c6_b_x;
    c6_y = muDoubleScalarAbs(c6_c_x);
  } else {
    c6_realmin(chartInstance);
    c6_scale = 2.2250738585072014E-308;
    c6_kstart = c6_c_ix0;
    c6_a = c6_c_n;
    c6_c = c6_a;
    c6_b_a = c6_c - 1;
    c6_b_c = c6_b_a;
    c6_c_a = c6_kstart;
    c6_b = c6_b_c;
    c6_kend = c6_c_a + c6_b;
    c6_b_kstart = c6_kstart;
    c6_b_kend = c6_kend;
    c6_d_a = c6_b_kstart;
    c6_b_b = c6_b_kend;
    c6_e_a = c6_d_a;
    c6_c_b = c6_b_b;
    if (c6_e_a > c6_c_b) {
      c6_overflow = false;
    } else {
      c6_eml_switch_helper(chartInstance);
      c6_eml_switch_helper(chartInstance);
      c6_overflow = (c6_c_b > 2147483646);
    }

    if (c6_overflow) {
      c6_check_forloop_overflow_error(chartInstance, c6_overflow);
    }

    for (c6_k = c6_b_kstart; c6_k <= c6_b_kend; c6_k++) {
      c6_b_k = c6_k;
      c6_d_x = c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c6_b_k), 1, 6, 1, 0) - 1];
      c6_e_x = c6_d_x;
      c6_absxk = muDoubleScalarAbs(c6_e_x);
      if (c6_absxk > c6_scale) {
        c6_t = c6_scale / c6_absxk;
        c6_y = 1.0 + c6_y * c6_t * c6_t;
        c6_scale = c6_absxk;
      } else {
        c6_t = c6_absxk / c6_scale;
        c6_y += c6_t * c6_t;
      }
    }

    c6_y = c6_scale * muDoubleScalarSqrt(c6_y);
  }

  return c6_y;
}

static void c6_b_eml_xaxpy(SFc6_Model1angularInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, real_T c6_x[72], int32_T c6_ix0, real_T c6_y[12],
  int32_T c6_iy0, real_T c6_b_y[12])
{
  int32_T c6_i126;
  int32_T c6_i127;
  real_T c6_b_x[72];
  for (c6_i126 = 0; c6_i126 < 12; c6_i126++) {
    c6_b_y[c6_i126] = c6_y[c6_i126];
  }

  for (c6_i127 = 0; c6_i127 < 72; c6_i127++) {
    c6_b_x[c6_i127] = c6_x[c6_i127];
  }

  c6_f_eml_xaxpy(chartInstance, c6_n, c6_a, c6_b_x, c6_ix0, c6_b_y, c6_iy0);
}

static void c6_c_eml_xaxpy(SFc6_Model1angularInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, real_T c6_x[12], int32_T c6_ix0, real_T c6_y[72],
  int32_T c6_iy0, real_T c6_b_y[72])
{
  int32_T c6_i128;
  int32_T c6_i129;
  real_T c6_b_x[12];
  for (c6_i128 = 0; c6_i128 < 72; c6_i128++) {
    c6_b_y[c6_i128] = c6_y[c6_i128];
  }

  for (c6_i129 = 0; c6_i129 < 12; c6_i129++) {
    c6_b_x[c6_i129] = c6_x[c6_i129];
  }

  c6_g_eml_xaxpy(chartInstance, c6_n, c6_a, c6_b_x, c6_ix0, c6_b_y, c6_iy0);
}

static real_T c6_b_eml_xdotc(SFc6_Model1angularInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_x[36], int32_T c6_ix0, real_T c6_y[36], int32_T c6_iy0)
{
  real_T c6_d;
  int32_T c6_b_n;
  int32_T c6_b_ix0;
  int32_T c6_b_iy0;
  int32_T c6_c_n;
  int32_T c6_c_ix0;
  int32_T c6_c_iy0;
  int32_T c6_d_n;
  int32_T c6_d_ix0;
  int32_T c6_d_iy0;
  int32_T c6_e_n;
  int32_T c6_e_ix0;
  int32_T c6_e_iy0;
  int32_T c6_ix;
  int32_T c6_iy;
  int32_T c6_f_n;
  int32_T c6_b;
  int32_T c6_b_b;
  boolean_T c6_overflow;
  int32_T c6_k;
  int32_T c6_a;
  int32_T c6_b_a;
  c6_b_n = c6_n;
  c6_b_ix0 = c6_ix0;
  c6_b_iy0 = c6_iy0;
  c6_c_n = c6_b_n;
  c6_c_ix0 = c6_b_ix0;
  c6_c_iy0 = c6_b_iy0;
  c6_b_threshold(chartInstance);
  c6_d_n = c6_c_n;
  c6_d_ix0 = c6_c_ix0;
  c6_d_iy0 = c6_c_iy0;
  c6_e_n = c6_d_n;
  c6_e_ix0 = c6_d_ix0;
  c6_e_iy0 = c6_d_iy0;
  c6_d = 0.0;
  if (c6_e_n < 1) {
  } else {
    c6_ix = c6_e_ix0;
    c6_iy = c6_e_iy0;
    c6_f_n = c6_e_n;
    c6_b = c6_f_n;
    c6_b_b = c6_b;
    if (1 > c6_b_b) {
      c6_overflow = false;
    } else {
      c6_eml_switch_helper(chartInstance);
      c6_eml_switch_helper(chartInstance);
      c6_overflow = (c6_b_b > 2147483646);
    }

    if (c6_overflow) {
      c6_check_forloop_overflow_error(chartInstance, c6_overflow);
    }

    for (c6_k = 1; c6_k <= c6_f_n; c6_k++) {
      c6_d += c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c6_ix), 1, 36, 1, 0) - 1] * c6_y[_SFD_EML_ARRAY_BOUNDS_CHECK
        ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_iy), 1, 36, 1, 0) - 1];
      c6_a = c6_ix + 1;
      c6_ix = c6_a;
      c6_b_a = c6_iy + 1;
      c6_iy = c6_b_a;
    }
  }

  return c6_d;
}

static void c6_d_eml_xaxpy(SFc6_Model1angularInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, int32_T c6_ix0, real_T c6_y[36], int32_T c6_iy0,
  real_T c6_b_y[36])
{
  int32_T c6_i130;
  for (c6_i130 = 0; c6_i130 < 36; c6_i130++) {
    c6_b_y[c6_i130] = c6_y[c6_i130];
  }

  c6_h_eml_xaxpy(chartInstance, c6_n, c6_a, c6_ix0, c6_b_y, c6_iy0);
}

static void c6_eml_xscal(SFc6_Model1angularInstanceStruct *chartInstance, real_T
  c6_a, real_T c6_x[72], int32_T c6_ix0, real_T c6_b_x[72])
{
  int32_T c6_i131;
  for (c6_i131 = 0; c6_i131 < 72; c6_i131++) {
    c6_b_x[c6_i131] = c6_x[c6_i131];
  }

  c6_c_eml_xscal(chartInstance, c6_a, c6_b_x, c6_ix0);
}

static void c6_b_eml_xscal(SFc6_Model1angularInstanceStruct *chartInstance,
  real_T c6_a, real_T c6_x[36], int32_T c6_ix0, real_T c6_b_x[36])
{
  int32_T c6_i132;
  for (c6_i132 = 0; c6_i132 < 36; c6_i132++) {
    c6_b_x[c6_i132] = c6_x[c6_i132];
  }

  c6_d_eml_xscal(chartInstance, c6_a, c6_b_x, c6_ix0);
}

static void c6_b_eml_scalar_eg(SFc6_Model1angularInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_b_eml_error(SFc6_Model1angularInstanceStruct *chartInstance)
{
  int32_T c6_i133;
  static char_T c6_cv3[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 's', 'v', 'd', '_', 'N', 'o', 'C', 'o', 'n', 'v', 'e', 'r',
    'g', 'e', 'n', 'c', 'e' };

  char_T c6_u[30];
  const mxArray *c6_y = NULL;
  (void)chartInstance;
  for (c6_i133 = 0; c6_i133 < 30; c6_i133++) {
    c6_u[c6_i133] = c6_cv3[c6_i133];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 30), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c6_y));
}

static real_T c6_sqrt(SFc6_Model1angularInstanceStruct *chartInstance, real_T
                      c6_x)
{
  real_T c6_b_x;
  c6_b_x = c6_x;
  c6_b_sqrt(chartInstance, &c6_b_x);
  return c6_b_x;
}

static void c6_c_eml_error(SFc6_Model1angularInstanceStruct *chartInstance)
{
  int32_T c6_i134;
  static char_T c6_cv4[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c6_u[30];
  const mxArray *c6_y = NULL;
  int32_T c6_i135;
  static char_T c6_cv5[4] = { 's', 'q', 'r', 't' };

  char_T c6_b_u[4];
  const mxArray *c6_b_y = NULL;
  (void)chartInstance;
  for (c6_i134 = 0; c6_i134 < 30; c6_i134++) {
    c6_u[c6_i134] = c6_cv4[c6_i134];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 30), false);
  for (c6_i135 = 0; c6_i135 < 4; c6_i135++) {
    c6_b_u[c6_i135] = c6_cv5[c6_i135];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c6_y, 14, c6_b_y));
}

static void c6_eml_xrotg(SFc6_Model1angularInstanceStruct *chartInstance, real_T
  c6_a, real_T c6_b, real_T *c6_b_a, real_T *c6_b_b, real_T *c6_c, real_T *c6_s)
{
  *c6_b_a = c6_a;
  *c6_b_b = c6_b;
  c6_b_eml_xrotg(chartInstance, c6_b_a, c6_b_b, c6_c, c6_s);
}

static void c6_eml_xrot(SFc6_Model1angularInstanceStruct *chartInstance, real_T
  c6_x[36], int32_T c6_ix0, int32_T c6_iy0, real_T c6_c, real_T c6_s, real_T
  c6_b_x[36])
{
  int32_T c6_i136;
  for (c6_i136 = 0; c6_i136 < 36; c6_i136++) {
    c6_b_x[c6_i136] = c6_x[c6_i136];
  }

  c6_c_eml_xrot(chartInstance, c6_b_x, c6_ix0, c6_iy0, c6_c, c6_s);
}

static void c6_d_threshold(SFc6_Model1angularInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_b_eml_xrot(SFc6_Model1angularInstanceStruct *chartInstance,
  real_T c6_x[72], int32_T c6_ix0, int32_T c6_iy0, real_T c6_c, real_T c6_s,
  real_T c6_b_x[72])
{
  int32_T c6_i137;
  for (c6_i137 = 0; c6_i137 < 72; c6_i137++) {
    c6_b_x[c6_i137] = c6_x[c6_i137];
  }

  c6_d_eml_xrot(chartInstance, c6_b_x, c6_ix0, c6_iy0, c6_c, c6_s);
}

static void c6_c_eml_scalar_eg(SFc6_Model1angularInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_eml_xswap(SFc6_Model1angularInstanceStruct *chartInstance, real_T
  c6_x[36], int32_T c6_ix0, int32_T c6_iy0, real_T c6_b_x[36])
{
  int32_T c6_i138;
  for (c6_i138 = 0; c6_i138 < 36; c6_i138++) {
    c6_b_x[c6_i138] = c6_x[c6_i138];
  }

  c6_c_eml_xswap(chartInstance, c6_b_x, c6_ix0, c6_iy0);
}

static void c6_c_eml_switch_helper(SFc6_Model1angularInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c6_b_eml_xswap(SFc6_Model1angularInstanceStruct *chartInstance,
  real_T c6_x[72], int32_T c6_ix0, int32_T c6_iy0, real_T c6_b_x[72])
{
  int32_T c6_i139;
  for (c6_i139 = 0; c6_i139 < 72; c6_i139++) {
    c6_b_x[c6_i139] = c6_x[c6_i139];
  }

  c6_d_eml_xswap(chartInstance, c6_b_x, c6_ix0, c6_iy0);
}

static void c6_eml_xgemm(SFc6_Model1angularInstanceStruct *chartInstance,
  int32_T c6_k, real_T c6_A[36], real_T c6_B[72], real_T c6_C[72], real_T
  c6_b_C[72])
{
  int32_T c6_i140;
  int32_T c6_i141;
  real_T c6_b_A[36];
  int32_T c6_i142;
  real_T c6_b_B[72];
  for (c6_i140 = 0; c6_i140 < 72; c6_i140++) {
    c6_b_C[c6_i140] = c6_C[c6_i140];
  }

  for (c6_i141 = 0; c6_i141 < 36; c6_i141++) {
    c6_b_A[c6_i141] = c6_A[c6_i141];
  }

  for (c6_i142 = 0; c6_i142 < 72; c6_i142++) {
    c6_b_B[c6_i142] = c6_B[c6_i142];
  }

  c6_c_eml_xgemm(chartInstance, c6_k, c6_b_A, c6_b_B, c6_b_C);
}

static void c6_e_threshold(SFc6_Model1angularInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_d_eml_scalar_eg(SFc6_Model1angularInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_b_eml_xgemm(SFc6_Model1angularInstanceStruct *chartInstance,
  real_T c6_A[72], real_T c6_B[72], real_T c6_C[144], real_T c6_b_C[144])
{
  int32_T c6_i143;
  int32_T c6_i144;
  real_T c6_b_A[72];
  int32_T c6_i145;
  real_T c6_b_B[72];
  for (c6_i143 = 0; c6_i143 < 144; c6_i143++) {
    c6_b_C[c6_i143] = c6_C[c6_i143];
  }

  for (c6_i144 = 0; c6_i144 < 72; c6_i144++) {
    c6_b_A[c6_i144] = c6_A[c6_i144];
  }

  for (c6_i145 = 0; c6_i145 < 72; c6_i145++) {
    c6_b_B[c6_i145] = c6_B[c6_i145];
  }

  c6_d_eml_xgemm(chartInstance, c6_b_A, c6_b_B, c6_b_C);
}

static const mxArray *c6_g_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc6_Model1angularInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static int32_T c6_h_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i146;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i146, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i146;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_sfEvent;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc6_Model1angularInstanceStruct *)chartInstanceVoid;
  c6_b_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_sfEvent),
    &c6_thisId);
  sf_mex_destroy(&c6_b_sfEvent);
  *(int32_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static uint8_T c6_i_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_Model1angular, const char_T
  *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_active_c6_Model1angular), &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_Model1angular);
  return c6_y;
}

static uint8_T c6_j_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_e_eml_xaxpy(SFc6_Model1angularInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, int32_T c6_ix0, real_T c6_y[72], int32_T c6_iy0)
{
  int32_T c6_b_n;
  real_T c6_b_a;
  int32_T c6_b_ix0;
  int32_T c6_b_iy0;
  int32_T c6_c_n;
  real_T c6_c_a;
  int32_T c6_c_ix0;
  int32_T c6_c_iy0;
  int32_T c6_d_a;
  int32_T c6_ix;
  int32_T c6_e_a;
  int32_T c6_iy;
  int32_T c6_f_a;
  int32_T c6_i147;
  int32_T c6_b;
  int32_T c6_b_b;
  boolean_T c6_overflow;
  int32_T c6_k;
  int32_T c6_g_a;
  int32_T c6_c;
  int32_T c6_h_a;
  int32_T c6_b_c;
  int32_T c6_i_a;
  int32_T c6_c_c;
  int32_T c6_j_a;
  int32_T c6_k_a;
  c6_b_n = c6_n;
  c6_b_a = c6_a;
  c6_b_ix0 = c6_ix0;
  c6_b_iy0 = c6_iy0;
  c6_c_threshold(chartInstance);
  c6_c_n = c6_b_n;
  c6_c_a = c6_b_a;
  c6_c_ix0 = c6_b_ix0;
  c6_c_iy0 = c6_b_iy0;
  if (c6_c_n < 1) {
  } else if (c6_c_a == 0.0) {
  } else {
    c6_d_a = c6_c_ix0 - 1;
    c6_ix = c6_d_a;
    c6_e_a = c6_c_iy0 - 1;
    c6_iy = c6_e_a;
    c6_f_a = c6_c_n - 1;
    c6_i147 = c6_f_a;
    c6_b = c6_i147;
    c6_b_b = c6_b;
    if (0 > c6_b_b) {
      c6_overflow = false;
    } else {
      c6_eml_switch_helper(chartInstance);
      c6_eml_switch_helper(chartInstance);
      c6_overflow = (c6_b_b > 2147483646);
    }

    if (c6_overflow) {
      c6_check_forloop_overflow_error(chartInstance, c6_overflow);
    }

    for (c6_k = 0; c6_k <= c6_i147; c6_k++) {
      c6_g_a = c6_iy;
      c6_c = c6_g_a;
      c6_h_a = c6_iy;
      c6_b_c = c6_h_a;
      c6_i_a = c6_ix;
      c6_c_c = c6_i_a;
      c6_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c6_c + 1)), 1, 72, 1, 0) - 1] =
        c6_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c6_b_c + 1)), 1, 72, 1, 0) - 1] + c6_c_a *
        c6_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c6_c_c + 1)), 1, 72, 1, 0) - 1];
      c6_j_a = c6_ix + 1;
      c6_ix = c6_j_a;
      c6_k_a = c6_iy + 1;
      c6_iy = c6_k_a;
    }
  }
}

static void c6_f_eml_xaxpy(SFc6_Model1angularInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, real_T c6_x[72], int32_T c6_ix0, real_T c6_y[12],
  int32_T c6_iy0)
{
  int32_T c6_b_n;
  real_T c6_b_a;
  int32_T c6_b_ix0;
  int32_T c6_b_iy0;
  int32_T c6_c_n;
  real_T c6_c_a;
  int32_T c6_c_ix0;
  int32_T c6_c_iy0;
  int32_T c6_d_a;
  int32_T c6_ix;
  int32_T c6_e_a;
  int32_T c6_iy;
  int32_T c6_f_a;
  int32_T c6_i148;
  int32_T c6_b;
  int32_T c6_b_b;
  boolean_T c6_overflow;
  int32_T c6_k;
  int32_T c6_g_a;
  int32_T c6_c;
  int32_T c6_h_a;
  int32_T c6_b_c;
  int32_T c6_i_a;
  int32_T c6_c_c;
  int32_T c6_j_a;
  int32_T c6_k_a;
  c6_b_n = c6_n;
  c6_b_a = c6_a;
  c6_b_ix0 = c6_ix0;
  c6_b_iy0 = c6_iy0;
  c6_c_threshold(chartInstance);
  c6_c_n = c6_b_n;
  c6_c_a = c6_b_a;
  c6_c_ix0 = c6_b_ix0;
  c6_c_iy0 = c6_b_iy0;
  if (c6_c_n < 1) {
  } else if (c6_c_a == 0.0) {
  } else {
    c6_d_a = c6_c_ix0 - 1;
    c6_ix = c6_d_a;
    c6_e_a = c6_c_iy0 - 1;
    c6_iy = c6_e_a;
    c6_f_a = c6_c_n - 1;
    c6_i148 = c6_f_a;
    c6_b = c6_i148;
    c6_b_b = c6_b;
    if (0 > c6_b_b) {
      c6_overflow = false;
    } else {
      c6_eml_switch_helper(chartInstance);
      c6_eml_switch_helper(chartInstance);
      c6_overflow = (c6_b_b > 2147483646);
    }

    if (c6_overflow) {
      c6_check_forloop_overflow_error(chartInstance, c6_overflow);
    }

    for (c6_k = 0; c6_k <= c6_i148; c6_k++) {
      c6_g_a = c6_iy;
      c6_c = c6_g_a;
      c6_h_a = c6_iy;
      c6_b_c = c6_h_a;
      c6_i_a = c6_ix;
      c6_c_c = c6_i_a;
      c6_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c6_c + 1)), 1, 12, 1, 0) - 1] =
        c6_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c6_b_c + 1)), 1, 12, 1, 0) - 1] + c6_c_a *
        c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c6_c_c + 1)), 1, 72, 1, 0) - 1];
      c6_j_a = c6_ix + 1;
      c6_ix = c6_j_a;
      c6_k_a = c6_iy + 1;
      c6_iy = c6_k_a;
    }
  }
}

static void c6_g_eml_xaxpy(SFc6_Model1angularInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, real_T c6_x[12], int32_T c6_ix0, real_T c6_y[72],
  int32_T c6_iy0)
{
  int32_T c6_b_n;
  real_T c6_b_a;
  int32_T c6_b_ix0;
  int32_T c6_b_iy0;
  int32_T c6_c_n;
  real_T c6_c_a;
  int32_T c6_c_ix0;
  int32_T c6_c_iy0;
  int32_T c6_d_a;
  int32_T c6_ix;
  int32_T c6_e_a;
  int32_T c6_iy;
  int32_T c6_f_a;
  int32_T c6_i149;
  int32_T c6_b;
  int32_T c6_b_b;
  boolean_T c6_overflow;
  int32_T c6_k;
  int32_T c6_g_a;
  int32_T c6_c;
  int32_T c6_h_a;
  int32_T c6_b_c;
  int32_T c6_i_a;
  int32_T c6_c_c;
  int32_T c6_j_a;
  int32_T c6_k_a;
  c6_b_n = c6_n;
  c6_b_a = c6_a;
  c6_b_ix0 = c6_ix0;
  c6_b_iy0 = c6_iy0;
  c6_c_threshold(chartInstance);
  c6_c_n = c6_b_n;
  c6_c_a = c6_b_a;
  c6_c_ix0 = c6_b_ix0;
  c6_c_iy0 = c6_b_iy0;
  if (c6_c_n < 1) {
  } else if (c6_c_a == 0.0) {
  } else {
    c6_d_a = c6_c_ix0 - 1;
    c6_ix = c6_d_a;
    c6_e_a = c6_c_iy0 - 1;
    c6_iy = c6_e_a;
    c6_f_a = c6_c_n - 1;
    c6_i149 = c6_f_a;
    c6_b = c6_i149;
    c6_b_b = c6_b;
    if (0 > c6_b_b) {
      c6_overflow = false;
    } else {
      c6_eml_switch_helper(chartInstance);
      c6_eml_switch_helper(chartInstance);
      c6_overflow = (c6_b_b > 2147483646);
    }

    if (c6_overflow) {
      c6_check_forloop_overflow_error(chartInstance, c6_overflow);
    }

    for (c6_k = 0; c6_k <= c6_i149; c6_k++) {
      c6_g_a = c6_iy;
      c6_c = c6_g_a;
      c6_h_a = c6_iy;
      c6_b_c = c6_h_a;
      c6_i_a = c6_ix;
      c6_c_c = c6_i_a;
      c6_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c6_c + 1)), 1, 72, 1, 0) - 1] =
        c6_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c6_b_c + 1)), 1, 72, 1, 0) - 1] + c6_c_a *
        c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c6_c_c + 1)), 1, 12, 1, 0) - 1];
      c6_j_a = c6_ix + 1;
      c6_ix = c6_j_a;
      c6_k_a = c6_iy + 1;
      c6_iy = c6_k_a;
    }
  }
}

static void c6_h_eml_xaxpy(SFc6_Model1angularInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, int32_T c6_ix0, real_T c6_y[36], int32_T c6_iy0)
{
  int32_T c6_b_n;
  real_T c6_b_a;
  int32_T c6_b_ix0;
  int32_T c6_b_iy0;
  int32_T c6_c_n;
  real_T c6_c_a;
  int32_T c6_c_ix0;
  int32_T c6_c_iy0;
  int32_T c6_d_a;
  int32_T c6_ix;
  int32_T c6_e_a;
  int32_T c6_iy;
  int32_T c6_f_a;
  int32_T c6_i150;
  int32_T c6_b;
  int32_T c6_b_b;
  boolean_T c6_overflow;
  int32_T c6_k;
  int32_T c6_g_a;
  int32_T c6_c;
  int32_T c6_h_a;
  int32_T c6_b_c;
  int32_T c6_i_a;
  int32_T c6_c_c;
  int32_T c6_j_a;
  int32_T c6_k_a;
  c6_b_n = c6_n;
  c6_b_a = c6_a;
  c6_b_ix0 = c6_ix0;
  c6_b_iy0 = c6_iy0;
  c6_c_threshold(chartInstance);
  c6_c_n = c6_b_n;
  c6_c_a = c6_b_a;
  c6_c_ix0 = c6_b_ix0;
  c6_c_iy0 = c6_b_iy0;
  if (c6_c_n < 1) {
  } else if (c6_c_a == 0.0) {
  } else {
    c6_d_a = c6_c_ix0 - 1;
    c6_ix = c6_d_a;
    c6_e_a = c6_c_iy0 - 1;
    c6_iy = c6_e_a;
    c6_f_a = c6_c_n - 1;
    c6_i150 = c6_f_a;
    c6_b = c6_i150;
    c6_b_b = c6_b;
    if (0 > c6_b_b) {
      c6_overflow = false;
    } else {
      c6_eml_switch_helper(chartInstance);
      c6_eml_switch_helper(chartInstance);
      c6_overflow = (c6_b_b > 2147483646);
    }

    if (c6_overflow) {
      c6_check_forloop_overflow_error(chartInstance, c6_overflow);
    }

    for (c6_k = 0; c6_k <= c6_i150; c6_k++) {
      c6_g_a = c6_iy;
      c6_c = c6_g_a;
      c6_h_a = c6_iy;
      c6_b_c = c6_h_a;
      c6_i_a = c6_ix;
      c6_c_c = c6_i_a;
      c6_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c6_c + 1)), 1, 36, 1, 0) - 1] =
        c6_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c6_b_c + 1)), 1, 36, 1, 0) - 1] + c6_c_a *
        c6_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c6_c_c + 1)), 1, 36, 1, 0) - 1];
      c6_j_a = c6_ix + 1;
      c6_ix = c6_j_a;
      c6_k_a = c6_iy + 1;
      c6_iy = c6_k_a;
    }
  }
}

static void c6_c_eml_xscal(SFc6_Model1angularInstanceStruct *chartInstance,
  real_T c6_a, real_T c6_x[72], int32_T c6_ix0)
{
  real_T c6_b_a;
  int32_T c6_b_ix0;
  real_T c6_c_a;
  int32_T c6_c_ix0;
  int32_T c6_d_ix0;
  int32_T c6_d_a;
  int32_T c6_i151;
  int32_T c6_e_a;
  int32_T c6_b;
  int32_T c6_f_a;
  int32_T c6_b_b;
  boolean_T c6_overflow;
  int32_T c6_k;
  int32_T c6_b_k;
  c6_b_a = c6_a;
  c6_b_ix0 = c6_ix0;
  c6_b_eml_switch_helper(chartInstance);
  c6_c_a = c6_b_a;
  c6_c_ix0 = c6_b_ix0;
  c6_d_ix0 = c6_c_ix0;
  c6_d_a = c6_c_ix0 + 11;
  c6_i151 = c6_d_a;
  c6_e_a = c6_d_ix0;
  c6_b = c6_i151;
  c6_f_a = c6_e_a;
  c6_b_b = c6_b;
  if (c6_f_a > c6_b_b) {
    c6_overflow = false;
  } else {
    c6_eml_switch_helper(chartInstance);
    c6_eml_switch_helper(chartInstance);
    c6_overflow = (c6_b_b > 2147483646);
  }

  if (c6_overflow) {
    c6_check_forloop_overflow_error(chartInstance, c6_overflow);
  }

  for (c6_k = c6_d_ix0; c6_k <= c6_i151; c6_k++) {
    c6_b_k = c6_k;
    c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c6_b_k), 1, 72, 1, 0) - 1] = c6_c_a * c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_k), 1, 72, 1, 0) - 1];
  }
}

static void c6_d_eml_xscal(SFc6_Model1angularInstanceStruct *chartInstance,
  real_T c6_a, real_T c6_x[36], int32_T c6_ix0)
{
  real_T c6_b_a;
  int32_T c6_b_ix0;
  real_T c6_c_a;
  int32_T c6_c_ix0;
  int32_T c6_d_ix0;
  int32_T c6_d_a;
  int32_T c6_i152;
  int32_T c6_e_a;
  int32_T c6_b;
  int32_T c6_f_a;
  int32_T c6_b_b;
  boolean_T c6_overflow;
  int32_T c6_k;
  int32_T c6_b_k;
  c6_b_a = c6_a;
  c6_b_ix0 = c6_ix0;
  c6_b_eml_switch_helper(chartInstance);
  c6_c_a = c6_b_a;
  c6_c_ix0 = c6_b_ix0;
  c6_d_ix0 = c6_c_ix0;
  c6_d_a = c6_c_ix0 + 5;
  c6_i152 = c6_d_a;
  c6_e_a = c6_d_ix0;
  c6_b = c6_i152;
  c6_f_a = c6_e_a;
  c6_b_b = c6_b;
  if (c6_f_a > c6_b_b) {
    c6_overflow = false;
  } else {
    c6_eml_switch_helper(chartInstance);
    c6_eml_switch_helper(chartInstance);
    c6_overflow = (c6_b_b > 2147483646);
  }

  if (c6_overflow) {
    c6_check_forloop_overflow_error(chartInstance, c6_overflow);
  }

  for (c6_k = c6_d_ix0; c6_k <= c6_i152; c6_k++) {
    c6_b_k = c6_k;
    c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c6_b_k), 1, 36, 1, 0) - 1] = c6_c_a * c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_k), 1, 36, 1, 0) - 1];
  }
}

static void c6_b_sqrt(SFc6_Model1angularInstanceStruct *chartInstance, real_T
                      *c6_x)
{
  if (*c6_x < 0.0) {
    c6_c_eml_error(chartInstance);
  }

  *c6_x = muDoubleScalarSqrt(*c6_x);
}

static void c6_b_eml_xrotg(SFc6_Model1angularInstanceStruct *chartInstance,
  real_T *c6_a, real_T *c6_b, real_T *c6_c, real_T *c6_s)
{
  real_T c6_b_a;
  real_T c6_b_b;
  real_T c6_c_b;
  real_T c6_c_a;
  real_T c6_d_a;
  real_T c6_d_b;
  real_T c6_e_b;
  real_T c6_e_a;
  real_T c6_b_c;
  real_T c6_b_s;
  double * c6_a_t;
  double * c6_b_t;
  double * c6_c_t;
  double * c6_s_t;
  real_T c6_c_c;
  real_T c6_c_s;
  (void)chartInstance;
  c6_b_a = *c6_a;
  c6_b_b = *c6_b;
  c6_c_b = c6_b_b;
  c6_c_a = c6_b_a;
  c6_d_a = c6_c_a;
  c6_d_b = c6_c_b;
  c6_e_b = c6_d_b;
  c6_e_a = c6_d_a;
  c6_b_c = 0.0;
  c6_b_s = 0.0;
  c6_a_t = (double *)(&c6_e_a);
  c6_b_t = (double *)(&c6_e_b);
  c6_c_t = (double *)(&c6_b_c);
  c6_s_t = (double *)(&c6_b_s);
  drotg(c6_a_t, c6_b_t, c6_c_t, c6_s_t);
  c6_c_a = c6_e_a;
  c6_c_b = c6_e_b;
  c6_c_c = c6_b_c;
  c6_c_s = c6_b_s;
  *c6_a = c6_c_a;
  *c6_b = c6_c_b;
  *c6_c = c6_c_c;
  *c6_s = c6_c_s;
}

static void c6_c_eml_xrot(SFc6_Model1angularInstanceStruct *chartInstance,
  real_T c6_x[36], int32_T c6_ix0, int32_T c6_iy0, real_T c6_c, real_T c6_s)
{
  int32_T c6_b_ix0;
  int32_T c6_b_iy0;
  real_T c6_b_c;
  real_T c6_b_s;
  int32_T c6_c_ix0;
  int32_T c6_c_iy0;
  real_T c6_c_c;
  real_T c6_c_s;
  int32_T c6_ix;
  int32_T c6_iy;
  int32_T c6_k;
  real_T c6_temp;
  int32_T c6_a;
  int32_T c6_b_a;
  c6_b_ix0 = c6_ix0;
  c6_b_iy0 = c6_iy0;
  c6_b_c = c6_c;
  c6_b_s = c6_s;
  c6_d_threshold(chartInstance);
  c6_c_ix0 = c6_b_ix0;
  c6_c_iy0 = c6_b_iy0;
  c6_c_c = c6_b_c;
  c6_c_s = c6_b_s;
  c6_ix = c6_c_ix0;
  c6_iy = c6_c_iy0;
  c6_eml_switch_helper(chartInstance);
  for (c6_k = 1; c6_k < 7; c6_k++) {
    c6_temp = c6_c_c * c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c6_ix), 1, 36, 1, 0) - 1] + c6_c_s *
      c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_iy), 1, 36, 1, 0) - 1];
    c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c6_iy), 1, 36, 1, 0) - 1] = c6_c_c * c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_iy), 1, 36, 1, 0) - 1] - c6_c_s
      * c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_ix), 1, 36, 1, 0) - 1];
    c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c6_ix), 1, 36, 1, 0) - 1] = c6_temp;
    c6_a = c6_iy + 1;
    c6_iy = c6_a;
    c6_b_a = c6_ix + 1;
    c6_ix = c6_b_a;
  }
}

static void c6_d_eml_xrot(SFc6_Model1angularInstanceStruct *chartInstance,
  real_T c6_x[72], int32_T c6_ix0, int32_T c6_iy0, real_T c6_c, real_T c6_s)
{
  int32_T c6_b_ix0;
  int32_T c6_b_iy0;
  real_T c6_b_c;
  real_T c6_b_s;
  int32_T c6_c_ix0;
  int32_T c6_c_iy0;
  real_T c6_c_c;
  real_T c6_c_s;
  int32_T c6_ix;
  int32_T c6_iy;
  int32_T c6_k;
  real_T c6_temp;
  int32_T c6_a;
  int32_T c6_b_a;
  c6_b_ix0 = c6_ix0;
  c6_b_iy0 = c6_iy0;
  c6_b_c = c6_c;
  c6_b_s = c6_s;
  c6_d_threshold(chartInstance);
  c6_c_ix0 = c6_b_ix0;
  c6_c_iy0 = c6_b_iy0;
  c6_c_c = c6_b_c;
  c6_c_s = c6_b_s;
  c6_ix = c6_c_ix0;
  c6_iy = c6_c_iy0;
  c6_eml_switch_helper(chartInstance);
  for (c6_k = 1; c6_k < 13; c6_k++) {
    c6_temp = c6_c_c * c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c6_ix), 1, 72, 1, 0) - 1] + c6_c_s *
      c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_iy), 1, 72, 1, 0) - 1];
    c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c6_iy), 1, 72, 1, 0) - 1] = c6_c_c * c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_iy), 1, 72, 1, 0) - 1] - c6_c_s
      * c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_ix), 1, 72, 1, 0) - 1];
    c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c6_ix), 1, 72, 1, 0) - 1] = c6_temp;
    c6_a = c6_iy + 1;
    c6_iy = c6_a;
    c6_b_a = c6_ix + 1;
    c6_ix = c6_b_a;
  }
}

static void c6_c_eml_xswap(SFc6_Model1angularInstanceStruct *chartInstance,
  real_T c6_x[36], int32_T c6_ix0, int32_T c6_iy0)
{
  int32_T c6_b_ix0;
  int32_T c6_b_iy0;
  int32_T c6_c_ix0;
  int32_T c6_c_iy0;
  int32_T c6_ix;
  int32_T c6_iy;
  int32_T c6_k;
  real_T c6_temp;
  int32_T c6_a;
  int32_T c6_b_a;
  c6_b_ix0 = c6_ix0;
  c6_b_iy0 = c6_iy0;
  c6_c_eml_switch_helper(chartInstance);
  c6_c_ix0 = c6_b_ix0;
  c6_c_iy0 = c6_b_iy0;
  c6_ix = c6_c_ix0;
  c6_iy = c6_c_iy0;
  c6_eml_switch_helper(chartInstance);
  for (c6_k = 1; c6_k < 7; c6_k++) {
    c6_temp = c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c6_ix), 1, 36, 1, 0) - 1];
    c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c6_ix), 1, 36, 1, 0) - 1] = c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c6_iy), 1, 36, 1, 0) - 1];
    c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c6_iy), 1, 36, 1, 0) - 1] = c6_temp;
    c6_a = c6_ix + 1;
    c6_ix = c6_a;
    c6_b_a = c6_iy + 1;
    c6_iy = c6_b_a;
  }
}

static void c6_d_eml_xswap(SFc6_Model1angularInstanceStruct *chartInstance,
  real_T c6_x[72], int32_T c6_ix0, int32_T c6_iy0)
{
  int32_T c6_b_ix0;
  int32_T c6_b_iy0;
  int32_T c6_c_ix0;
  int32_T c6_c_iy0;
  int32_T c6_ix;
  int32_T c6_iy;
  int32_T c6_k;
  real_T c6_temp;
  int32_T c6_a;
  int32_T c6_b_a;
  c6_b_ix0 = c6_ix0;
  c6_b_iy0 = c6_iy0;
  c6_c_eml_switch_helper(chartInstance);
  c6_c_ix0 = c6_b_ix0;
  c6_c_iy0 = c6_b_iy0;
  c6_ix = c6_c_ix0;
  c6_iy = c6_c_iy0;
  c6_eml_switch_helper(chartInstance);
  for (c6_k = 1; c6_k < 13; c6_k++) {
    c6_temp = c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c6_ix), 1, 72, 1, 0) - 1];
    c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c6_ix), 1, 72, 1, 0) - 1] = c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c6_iy), 1, 72, 1, 0) - 1];
    c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c6_iy), 1, 72, 1, 0) - 1] = c6_temp;
    c6_a = c6_ix + 1;
    c6_ix = c6_a;
    c6_b_a = c6_iy + 1;
    c6_iy = c6_b_a;
  }
}

static void c6_c_eml_xgemm(SFc6_Model1angularInstanceStruct *chartInstance,
  int32_T c6_k, real_T c6_A[36], real_T c6_B[72], real_T c6_C[72])
{
  int32_T c6_b_k;
  int32_T c6_c_k;
  int32_T c6_a;
  int32_T c6_km1;
  int32_T c6_cr;
  int32_T c6_b_cr;
  int32_T c6_b_a;
  int32_T c6_i153;
  int32_T c6_c_a;
  int32_T c6_i154;
  int32_T c6_d_a;
  int32_T c6_b;
  int32_T c6_e_a;
  int32_T c6_b_b;
  boolean_T c6_overflow;
  int32_T c6_ic;
  int32_T c6_b_ic;
  int32_T c6_br;
  int32_T c6_c_cr;
  int32_T c6_ar;
  int32_T c6_f_a;
  int32_T c6_b_br;
  int32_T c6_c_b;
  int32_T c6_c;
  int32_T c6_g_a;
  int32_T c6_d_b;
  int32_T c6_i155;
  int32_T c6_h_a;
  int32_T c6_e_b;
  int32_T c6_i_a;
  int32_T c6_f_b;
  boolean_T c6_b_overflow;
  int32_T c6_ib;
  int32_T c6_b_ib;
  real_T c6_temp;
  int32_T c6_ia;
  int32_T c6_j_a;
  int32_T c6_i156;
  int32_T c6_k_a;
  int32_T c6_i157;
  int32_T c6_l_a;
  int32_T c6_g_b;
  int32_T c6_m_a;
  int32_T c6_h_b;
  boolean_T c6_c_overflow;
  int32_T c6_c_ic;
  int32_T c6_n_a;
  int32_T c6_o_a;
  c6_b_k = c6_k;
  if (c6_use_refblas(chartInstance)) {
  } else {
    c6_e_threshold(chartInstance);
  }

  c6_c_k = c6_b_k;
  c6_a = c6_c_k;
  c6_km1 = c6_a;
  c6_eml_switch_helper(chartInstance);
  for (c6_cr = 0; c6_cr < 67; c6_cr += 6) {
    c6_b_cr = c6_cr;
    c6_b_a = c6_b_cr + 1;
    c6_i153 = c6_b_a;
    c6_c_a = c6_b_cr + 6;
    c6_i154 = c6_c_a;
    c6_d_a = c6_i153;
    c6_b = c6_i154;
    c6_e_a = c6_d_a;
    c6_b_b = c6_b;
    if (c6_e_a > c6_b_b) {
      c6_overflow = false;
    } else {
      c6_eml_switch_helper(chartInstance);
      c6_eml_switch_helper(chartInstance);
      c6_overflow = (c6_b_b > 2147483646);
    }

    if (c6_overflow) {
      c6_check_forloop_overflow_error(chartInstance, c6_overflow);
    }

    for (c6_ic = c6_i153; c6_ic <= c6_i154; c6_ic++) {
      c6_b_ic = c6_ic;
      c6_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c6_b_ic), 1, 72, 1, 0) - 1] = 0.0;
    }
  }

  c6_br = 0;
  c6_eml_switch_helper(chartInstance);
  for (c6_c_cr = 0; c6_c_cr < 67; c6_c_cr += 6) {
    c6_b_cr = c6_c_cr;
    c6_ar = 0;
    c6_f_a = c6_br + 1;
    c6_br = c6_f_a;
    c6_b_br = c6_br;
    c6_c_b = c6_km1 - 1;
    c6_c = 12 * c6_c_b;
    c6_g_a = c6_br;
    c6_d_b = c6_c;
    c6_i155 = c6_g_a + c6_d_b;
    c6_h_a = c6_b_br;
    c6_e_b = c6_i155;
    c6_i_a = c6_h_a;
    c6_f_b = c6_e_b;
    if (c6_i_a > c6_f_b) {
      c6_b_overflow = false;
    } else {
      c6_eml_switch_helper(chartInstance);
      c6_eml_switch_helper(chartInstance);
      c6_b_overflow = (c6_f_b > 2147483635);
    }

    if (c6_b_overflow) {
      c6_check_forloop_overflow_error(chartInstance, c6_b_overflow);
    }

    for (c6_ib = c6_b_br; c6_ib <= c6_i155; c6_ib += 12) {
      c6_b_ib = c6_ib;
      if (c6_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_b_ib), 1, 72, 1, 0) - 1] != 0.0) {
        c6_temp = c6_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c6_b_ib), 1, 72, 1, 0) - 1];
        c6_ia = c6_ar;
        c6_j_a = c6_b_cr + 1;
        c6_i156 = c6_j_a;
        c6_k_a = c6_b_cr + 6;
        c6_i157 = c6_k_a;
        c6_l_a = c6_i156;
        c6_g_b = c6_i157;
        c6_m_a = c6_l_a;
        c6_h_b = c6_g_b;
        if (c6_m_a > c6_h_b) {
          c6_c_overflow = false;
        } else {
          c6_eml_switch_helper(chartInstance);
          c6_eml_switch_helper(chartInstance);
          c6_c_overflow = (c6_h_b > 2147483646);
        }

        if (c6_c_overflow) {
          c6_check_forloop_overflow_error(chartInstance, c6_c_overflow);
        }

        for (c6_c_ic = c6_i156; c6_c_ic <= c6_i157; c6_c_ic++) {
          c6_b_ic = c6_c_ic;
          c6_n_a = c6_ia + 1;
          c6_ia = c6_n_a;
          c6_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_b_ic), 1, 72, 1, 0) - 1] =
            c6_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_b_ic), 1, 72, 1, 0) - 1] + c6_temp *
            c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_ia), 1, 36, 1, 0) - 1];
        }
      }

      c6_o_a = c6_ar + 6;
      c6_ar = c6_o_a;
    }
  }
}

static void c6_d_eml_xgemm(SFc6_Model1angularInstanceStruct *chartInstance,
  real_T c6_A[72], real_T c6_B[72], real_T c6_C[144])
{
  real_T c6_alpha1;
  real_T c6_beta1;
  char_T c6_TRANSB;
  char_T c6_TRANSA;
  ptrdiff_t c6_m_t;
  ptrdiff_t c6_n_t;
  ptrdiff_t c6_k_t;
  ptrdiff_t c6_lda_t;
  ptrdiff_t c6_ldb_t;
  ptrdiff_t c6_ldc_t;
  double * c6_alpha1_t;
  double * c6_Aia0_t;
  double * c6_Bib0_t;
  double * c6_beta1_t;
  double * c6_Cic0_t;
  c6_e_threshold(chartInstance);
  c6_alpha1 = 1.0;
  c6_beta1 = 0.0;
  c6_TRANSB = 'N';
  c6_TRANSA = 'N';
  c6_m_t = (ptrdiff_t)(12);
  c6_n_t = (ptrdiff_t)(12);
  c6_k_t = (ptrdiff_t)(6);
  c6_lda_t = (ptrdiff_t)(12);
  c6_ldb_t = (ptrdiff_t)(6);
  c6_ldc_t = (ptrdiff_t)(12);
  c6_alpha1_t = (double *)(&c6_alpha1);
  c6_Aia0_t = (double *)(&c6_A[0]);
  c6_Bib0_t = (double *)(&c6_B[0]);
  c6_beta1_t = (double *)(&c6_beta1);
  c6_Cic0_t = (double *)(&c6_C[0]);
  dgemm(&c6_TRANSA, &c6_TRANSB, &c6_m_t, &c6_n_t, &c6_k_t, c6_alpha1_t,
        c6_Aia0_t, &c6_lda_t, c6_Bib0_t, &c6_ldb_t, c6_beta1_t, c6_Cic0_t,
        &c6_ldc_t);
}

static void init_dsm_address_info(SFc6_Model1angularInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc6_Model1angularInstanceStruct
  *chartInstance)
{
  chartInstance->c6_IV = (real_T (*)[144])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c6_Model1angular_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2848953112U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(847771310U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1703611369U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(570655403U);
}

mxArray* sf_c6_Model1angular_get_post_codegen_info(void);
mxArray *sf_c6_Model1angular_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("PDOjJD7CaMZuAXN1UghOMH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(12);
      pr[1] = (double)(12);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c6_Model1angular_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c6_Model1angular_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c6_Model1angular_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "incompatibleSymbol", };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 3, infoFields);
  mxArray *fallbackReason = mxCreateString("feature_off");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxArray *fallbackType = mxCreateString("early");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c6_Model1angular_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c6_Model1angular_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c6_Model1angular(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"IV\",},{M[8],M[0],T\"is_active_c6_Model1angular\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_Model1angular_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_Model1angularInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc6_Model1angularInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Model1angularMachineNumber_,
           6,
           1,
           1,
           0,
           2,
           0,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_Model1angularMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Model1angularMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Model1angularMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,10,0,0,"r");
          _SFD_SET_DATA_PROPS(1,2,0,1,"IV");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,147);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"skew_sm",0,-1,127);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)
            c6_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 12;
          dimVector[1]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)
            c6_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c6_r);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c6_IV);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Model1angularMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "AODkGV0qQXVaZIFOnEcNSB";
}

static void sf_opaque_initialize_c6_Model1angular(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_Model1angularInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c6_Model1angular((SFc6_Model1angularInstanceStruct*)
    chartInstanceVar);
  initialize_c6_Model1angular((SFc6_Model1angularInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c6_Model1angular(void *chartInstanceVar)
{
  enable_c6_Model1angular((SFc6_Model1angularInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_Model1angular(void *chartInstanceVar)
{
  disable_c6_Model1angular((SFc6_Model1angularInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c6_Model1angular(void *chartInstanceVar)
{
  sf_gateway_c6_Model1angular((SFc6_Model1angularInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c6_Model1angular(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c6_Model1angular((SFc6_Model1angularInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c6_Model1angular(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c6_Model1angular((SFc6_Model1angularInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c6_Model1angular(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_Model1angularInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Model1angular_optimization_info();
    }

    finalize_c6_Model1angular((SFc6_Model1angularInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_Model1angular((SFc6_Model1angularInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_Model1angular(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c6_Model1angular((SFc6_Model1angularInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_Model1angular(SimStruct *S)
{
  /* Actual parameters from chart:
     r
   */
  const char_T *rtParamNames[] = { "r" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for r*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Model1angular_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,6,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,6);
    if (chartIsInlinable) {
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,6,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(935589698U));
  ssSetChecksum1(S,(4142367465U));
  ssSetChecksum2(S,(1477172493U));
  ssSetChecksum3(S,(3836496495U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c6_Model1angular(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_Model1angular(SimStruct *S)
{
  SFc6_Model1angularInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc6_Model1angularInstanceStruct *)utMalloc(sizeof
    (SFc6_Model1angularInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_Model1angularInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c6_Model1angular;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c6_Model1angular;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c6_Model1angular;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_Model1angular;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c6_Model1angular;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c6_Model1angular;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c6_Model1angular;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c6_Model1angular;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_Model1angular;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_Model1angular;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c6_Model1angular;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->checksum = SF_RUNTIME_INFO_CHECKSUM;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  crtInfo->compiledInfo = NULL;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c6_Model1angular_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_Model1angular(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_Model1angular(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_Model1angular(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_Model1angular_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

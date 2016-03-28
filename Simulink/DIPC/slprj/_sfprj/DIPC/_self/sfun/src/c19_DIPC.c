/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DIPC_sfun.h"
#include "c19_DIPC.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DIPC_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c19_debug_family_names[10] = { "Ms", "nargin", "nargout",
  "x", "mv", "jv", "m1", "j1", "rv", "M" };

static const char * c19_b_debug_family_names[6] = { "rwq", "nargin", "nargout",
  "q", "r", "rw" };

static const char * c19_c_debug_family_names[4] = { "nargin", "nargout", "x",
  "X" };

/* Function Declarations */
static void initialize_c19_DIPC(SFc19_DIPCInstanceStruct *chartInstance);
static void initialize_params_c19_DIPC(SFc19_DIPCInstanceStruct *chartInstance);
static void enable_c19_DIPC(SFc19_DIPCInstanceStruct *chartInstance);
static void disable_c19_DIPC(SFc19_DIPCInstanceStruct *chartInstance);
static void c19_update_debugger_state_c19_DIPC(SFc19_DIPCInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c19_DIPC(SFc19_DIPCInstanceStruct
  *chartInstance);
static void set_sim_state_c19_DIPC(SFc19_DIPCInstanceStruct *chartInstance,
  const mxArray *c19_st);
static void finalize_c19_DIPC(SFc19_DIPCInstanceStruct *chartInstance);
static void sf_gateway_c19_DIPC(SFc19_DIPCInstanceStruct *chartInstance);
static void mdl_start_c19_DIPC(SFc19_DIPCInstanceStruct *chartInstance);
static void initSimStructsc19_DIPC(SFc19_DIPCInstanceStruct *chartInstance);
static void c19_quatrot(SFc19_DIPCInstanceStruct *chartInstance, real_T c19_q[4],
  real_T c19_r[3], real_T c19_rw[3]);
static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber, uint32_T c19_instanceNumber);
static const mxArray *c19_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static void c19_emlrt_marshallIn(SFc19_DIPCInstanceStruct *chartInstance, const
  mxArray *c19_b_M, const char_T *c19_identifier, real_T c19_y[36]);
static void c19_b_emlrt_marshallIn(SFc19_DIPCInstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId, real_T c19_y[36]);
static void c19_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_b_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static void c19_c_emlrt_marshallIn(SFc19_DIPCInstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId, real_T c19_y[12]);
static void c19_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_c_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static real_T c19_d_emlrt_marshallIn(SFc19_DIPCInstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_d_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static const mxArray *c19_e_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static void c19_e_emlrt_marshallIn(SFc19_DIPCInstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId, real_T c19_y[9]);
static void c19_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_f_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static void c19_f_emlrt_marshallIn(SFc19_DIPCInstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId, real_T c19_y[3]);
static void c19_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_g_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static void c19_g_emlrt_marshallIn(SFc19_DIPCInstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId, real_T c19_y[4]);
static void c19_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static void c19_info_helper(const mxArray **c19_info);
static const mxArray *c19_emlrt_marshallOut(const char * c19_u);
static const mxArray *c19_b_emlrt_marshallOut(const uint32_T c19_u);
static void c19_quatmultiply(SFc19_DIPCInstanceStruct *chartInstance, real_T
  c19_q[4], real_T c19_r[4], real_T c19_qout[4]);
static void c19_mpower(SFc19_DIPCInstanceStruct *chartInstance, real_T c19_a[9],
  real_T c19_c[9]);
static void c19_eml_scalar_eg(SFc19_DIPCInstanceStruct *chartInstance);
static void c19_eml_xgemm(SFc19_DIPCInstanceStruct *chartInstance, real_T c19_A
  [9], real_T c19_B[9], real_T c19_C[9], real_T c19_b_C[9]);
static const mxArray *c19_h_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static int32_T c19_h_emlrt_marshallIn(SFc19_DIPCInstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static uint8_T c19_i_emlrt_marshallIn(SFc19_DIPCInstanceStruct *chartInstance,
  const mxArray *c19_b_is_active_c19_DIPC, const char_T *c19_identifier);
static uint8_T c19_j_emlrt_marshallIn(SFc19_DIPCInstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_b_eml_xgemm(SFc19_DIPCInstanceStruct *chartInstance, real_T
  c19_A[9], real_T c19_B[9], real_T c19_C[9]);
static void init_dsm_address_info(SFc19_DIPCInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc19_DIPCInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c19_DIPC(SFc19_DIPCInstanceStruct *chartInstance)
{
  chartInstance->c19_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c19_is_active_c19_DIPC = 0U;
}

static void initialize_params_c19_DIPC(SFc19_DIPCInstanceStruct *chartInstance)
{
  real_T c19_d0;
  real_T c19_d1;
  real_T c19_d2;
  real_T c19_d3;
  real_T c19_dv0[12];
  int32_T c19_i0;
  sf_mex_import_named("mv", sf_mex_get_sfun_param(chartInstance->S, 3, 0),
                      &c19_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c19_mv = c19_d0;
  sf_mex_import_named("jv", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c19_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c19_jv = c19_d1;
  sf_mex_import_named("m1", sf_mex_get_sfun_param(chartInstance->S, 2, 0),
                      &c19_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c19_m1 = c19_d2;
  sf_mex_import_named("j1", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c19_d3, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c19_j1 = c19_d3;
  sf_mex_import_named("rv", sf_mex_get_sfun_param(chartInstance->S, 4, 0),
                      c19_dv0, 0, 0, 0U, 1, 0U, 1, 12);
  for (c19_i0 = 0; c19_i0 < 12; c19_i0++) {
    chartInstance->c19_rv[c19_i0] = c19_dv0[c19_i0];
  }
}

static void enable_c19_DIPC(SFc19_DIPCInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c19_DIPC(SFc19_DIPCInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c19_update_debugger_state_c19_DIPC(SFc19_DIPCInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c19_DIPC(SFc19_DIPCInstanceStruct
  *chartInstance)
{
  const mxArray *c19_st;
  const mxArray *c19_y = NULL;
  int32_T c19_i1;
  real_T c19_u[36];
  const mxArray *c19_b_y = NULL;
  uint8_T c19_hoistedGlobal;
  uint8_T c19_b_u;
  const mxArray *c19_c_y = NULL;
  c19_st = NULL;
  c19_st = NULL;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_createcellmatrix(2, 1), false);
  for (c19_i1 = 0; c19_i1 < 36; c19_i1++) {
    c19_u[c19_i1] = (*chartInstance->c19_M)[c19_i1];
  }

  c19_b_y = NULL;
  sf_mex_assign(&c19_b_y, sf_mex_create("y", c19_u, 0, 0U, 1U, 0U, 2, 6, 6),
                false);
  sf_mex_setcell(c19_y, 0, c19_b_y);
  c19_hoistedGlobal = chartInstance->c19_is_active_c19_DIPC;
  c19_b_u = c19_hoistedGlobal;
  c19_c_y = NULL;
  sf_mex_assign(&c19_c_y, sf_mex_create("y", &c19_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c19_y, 1, c19_c_y);
  sf_mex_assign(&c19_st, c19_y, false);
  return c19_st;
}

static void set_sim_state_c19_DIPC(SFc19_DIPCInstanceStruct *chartInstance,
  const mxArray *c19_st)
{
  const mxArray *c19_u;
  real_T c19_dv1[36];
  int32_T c19_i2;
  chartInstance->c19_doneDoubleBufferReInit = true;
  c19_u = sf_mex_dup(c19_st);
  c19_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c19_u, 0)), "M",
                       c19_dv1);
  for (c19_i2 = 0; c19_i2 < 36; c19_i2++) {
    (*chartInstance->c19_M)[c19_i2] = c19_dv1[c19_i2];
  }

  chartInstance->c19_is_active_c19_DIPC = c19_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c19_u, 1)), "is_active_c19_DIPC");
  sf_mex_destroy(&c19_u);
  c19_update_debugger_state_c19_DIPC(chartInstance);
  sf_mex_destroy(&c19_st);
}

static void finalize_c19_DIPC(SFc19_DIPCInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c19_DIPC(SFc19_DIPCInstanceStruct *chartInstance)
{
  int32_T c19_i3;
  real_T c19_hoistedGlobal;
  real_T c19_b_hoistedGlobal;
  real_T c19_c_hoistedGlobal;
  real_T c19_d_hoistedGlobal;
  int32_T c19_i4;
  real_T c19_b_x[7];
  real_T c19_b_mv;
  real_T c19_b_jv;
  real_T c19_b_m1;
  real_T c19_b_j1;
  int32_T c19_i5;
  real_T c19_b_rv[12];
  uint32_T c19_debug_family_var_map[10];
  real_T c19_Ms[9];
  real_T c19_nargin = 6.0;
  real_T c19_nargout = 1.0;
  real_T c19_b_M[36];
  int32_T c19_i6;
  real_T c19_c_x[4];
  int32_T c19_i7;
  real_T c19_c_rv[3];
  real_T c19_dv2[3];
  int32_T c19_i8;
  real_T c19_d_x[3];
  uint32_T c19_b_debug_family_var_map[4];
  real_T c19_b_nargin = 1.0;
  real_T c19_b_nargout = 1.0;
  real_T c19_X[9];
  int32_T c19_i9;
  real_T c19_e_x[4];
  int32_T c19_i10;
  real_T c19_d_rv[3];
  real_T c19_dv3[3];
  int32_T c19_i11;
  real_T c19_f_x[3];
  real_T c19_c_nargin = 1.0;
  real_T c19_c_nargout = 1.0;
  real_T c19_b_X[9];
  int32_T c19_i12;
  real_T c19_g_x[4];
  int32_T c19_i13;
  real_T c19_e_rv[3];
  real_T c19_dv4[3];
  int32_T c19_i14;
  real_T c19_h_x[3];
  real_T c19_d_nargin = 1.0;
  real_T c19_d_nargout = 1.0;
  real_T c19_c_X[9];
  int32_T c19_i15;
  real_T c19_i_x[4];
  int32_T c19_i16;
  real_T c19_f_rv[3];
  real_T c19_dv5[3];
  int32_T c19_i17;
  real_T c19_j_x[3];
  real_T c19_e_nargin = 1.0;
  real_T c19_e_nargout = 1.0;
  real_T c19_d_X[9];
  real_T c19_a;
  int32_T c19_i18;
  real_T c19_b[9];
  int32_T c19_i19;
  real_T c19_b_a;
  int32_T c19_i20;
  static real_T c19_b_b[9] = { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 };

  real_T c19_y[9];
  real_T c19_c_a;
  int32_T c19_i21;
  real_T c19_b_y[9];
  int32_T c19_i22;
  real_T c19_k_x[4];
  int32_T c19_i23;
  real_T c19_g_rv[3];
  real_T c19_dv6[3];
  int32_T c19_i24;
  real_T c19_l_x[3];
  real_T c19_f_nargin = 1.0;
  real_T c19_f_nargout = 1.0;
  real_T c19_e_X[9];
  int32_T c19_i25;
  real_T c19_m_x[4];
  int32_T c19_i26;
  real_T c19_h_rv[3];
  real_T c19_dv7[3];
  int32_T c19_i27;
  real_T c19_n_x[3];
  real_T c19_g_nargin = 1.0;
  real_T c19_g_nargout = 1.0;
  real_T c19_f_X[9];
  int32_T c19_i28;
  real_T c19_o_x[4];
  int32_T c19_i29;
  real_T c19_i_rv[3];
  real_T c19_dv8[3];
  int32_T c19_i30;
  real_T c19_p_x[3];
  real_T c19_h_nargin = 1.0;
  real_T c19_h_nargout = 1.0;
  real_T c19_g_X[9];
  int32_T c19_i31;
  real_T c19_q_x[4];
  int32_T c19_i32;
  real_T c19_j_rv[3];
  real_T c19_dv9[3];
  int32_T c19_i33;
  real_T c19_r_x[3];
  real_T c19_i_nargin = 1.0;
  real_T c19_i_nargout = 1.0;
  real_T c19_h_X[9];
  real_T c19_d_a;
  int32_T c19_i34;
  real_T c19_i_X[9];
  int32_T c19_i35;
  real_T c19_j_X[9];
  real_T c19_dv10[9];
  int32_T c19_i36;
  real_T c19_k_X[9];
  real_T c19_dv11[9];
  int32_T c19_i37;
  real_T c19_l_X[9];
  real_T c19_dv12[9];
  int32_T c19_i38;
  int32_T c19_i39;
  int32_T c19_i40;
  int32_T c19_i41;
  int32_T c19_i42;
  int32_T c19_i43;
  int32_T c19_i44;
  int32_T c19_i45;
  int32_T c19_i46;
  int32_T c19_i47;
  int32_T c19_i48;
  int32_T c19_i49;
  int32_T c19_i50;
  int32_T c19_i51;
  int32_T c19_i52;
  int32_T c19_i53;
  int32_T c19_i54;
  int32_T c19_i55;
  int32_T c19_i56;
  int32_T c19_i57;
  int32_T c19_i58;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 15U, chartInstance->c19_sfEvent);
  for (c19_i3 = 0; c19_i3 < 7; c19_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c19_x)[c19_i3], 0U);
  }

  chartInstance->c19_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 15U, chartInstance->c19_sfEvent);
  c19_hoistedGlobal = chartInstance->c19_mv;
  c19_b_hoistedGlobal = chartInstance->c19_jv;
  c19_c_hoistedGlobal = chartInstance->c19_m1;
  c19_d_hoistedGlobal = chartInstance->c19_j1;
  for (c19_i4 = 0; c19_i4 < 7; c19_i4++) {
    c19_b_x[c19_i4] = (*chartInstance->c19_x)[c19_i4];
  }

  c19_b_mv = c19_hoistedGlobal;
  c19_b_jv = c19_b_hoistedGlobal;
  c19_b_m1 = c19_c_hoistedGlobal;
  c19_b_j1 = c19_d_hoistedGlobal;
  for (c19_i5 = 0; c19_i5 < 12; c19_i5++) {
    c19_b_rv[c19_i5] = chartInstance->c19_rv[c19_i5];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c19_debug_family_names,
    c19_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c19_Ms, 0U, c19_e_sf_marshallOut,
    c19_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_nargin, 1U, c19_c_sf_marshallOut,
    c19_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_nargout, 2U, c19_c_sf_marshallOut,
    c19_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c19_b_x, 3U, c19_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_b_mv, 4U, c19_c_sf_marshallOut,
    c19_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_b_jv, 5U, c19_c_sf_marshallOut,
    c19_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_b_m1, 6U, c19_c_sf_marshallOut,
    c19_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_b_j1, 7U, c19_c_sf_marshallOut,
    c19_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c19_b_rv, 8U, c19_b_sf_marshallOut,
    c19_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c19_b_M, 9U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 3);
  for (c19_i6 = 0; c19_i6 < 4; c19_i6++) {
    c19_c_x[c19_i6] = c19_b_x[c19_i6 + 3];
  }

  for (c19_i7 = 0; c19_i7 < 3; c19_i7++) {
    c19_c_rv[c19_i7] = c19_b_rv[c19_i7];
  }

  c19_quatrot(chartInstance, c19_c_x, c19_c_rv, c19_dv2);
  for (c19_i8 = 0; c19_i8 < 3; c19_i8++) {
    c19_d_x[c19_i8] = c19_dv2[c19_i8];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c19_c_debug_family_names,
    c19_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_b_nargin, 0U, c19_c_sf_marshallOut,
    c19_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_b_nargout, 1U, c19_c_sf_marshallOut,
    c19_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c19_d_x, 2U, c19_f_sf_marshallOut,
    c19_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c19_X, 3U, c19_e_sf_marshallOut,
    c19_d_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c19_sfEvent, 3);
  c19_X[0] = 0.0;
  c19_X[3] = -c19_d_x[2];
  c19_X[6] = c19_d_x[1];
  c19_X[1] = c19_d_x[2];
  c19_X[4] = 0.0;
  c19_X[7] = -c19_d_x[0];
  c19_X[2] = -c19_d_x[1];
  c19_X[5] = c19_d_x[0];
  c19_X[8] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c19_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c19_i9 = 0; c19_i9 < 4; c19_i9++) {
    c19_e_x[c19_i9] = c19_b_x[c19_i9 + 3];
  }

  for (c19_i10 = 0; c19_i10 < 3; c19_i10++) {
    c19_d_rv[c19_i10] = c19_b_rv[c19_i10 + 3];
  }

  c19_quatrot(chartInstance, c19_e_x, c19_d_rv, c19_dv3);
  for (c19_i11 = 0; c19_i11 < 3; c19_i11++) {
    c19_f_x[c19_i11] = c19_dv3[c19_i11];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c19_c_debug_family_names,
    c19_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_c_nargin, 0U, c19_c_sf_marshallOut,
    c19_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_c_nargout, 1U, c19_c_sf_marshallOut,
    c19_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c19_f_x, 2U, c19_f_sf_marshallOut,
    c19_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c19_b_X, 3U, c19_e_sf_marshallOut,
    c19_d_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c19_sfEvent, 3);
  c19_b_X[0] = 0.0;
  c19_b_X[3] = -c19_f_x[2];
  c19_b_X[6] = c19_f_x[1];
  c19_b_X[1] = c19_f_x[2];
  c19_b_X[4] = 0.0;
  c19_b_X[7] = -c19_f_x[0];
  c19_b_X[2] = -c19_f_x[1];
  c19_b_X[5] = c19_f_x[0];
  c19_b_X[8] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c19_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c19_i12 = 0; c19_i12 < 4; c19_i12++) {
    c19_g_x[c19_i12] = c19_b_x[c19_i12 + 3];
  }

  for (c19_i13 = 0; c19_i13 < 3; c19_i13++) {
    c19_e_rv[c19_i13] = c19_b_rv[c19_i13 + 6];
  }

  c19_quatrot(chartInstance, c19_g_x, c19_e_rv, c19_dv4);
  for (c19_i14 = 0; c19_i14 < 3; c19_i14++) {
    c19_h_x[c19_i14] = c19_dv4[c19_i14];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c19_c_debug_family_names,
    c19_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_d_nargin, 0U, c19_c_sf_marshallOut,
    c19_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_d_nargout, 1U, c19_c_sf_marshallOut,
    c19_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c19_h_x, 2U, c19_f_sf_marshallOut,
    c19_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c19_c_X, 3U, c19_e_sf_marshallOut,
    c19_d_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c19_sfEvent, 3);
  c19_c_X[0] = 0.0;
  c19_c_X[3] = -c19_h_x[2];
  c19_c_X[6] = c19_h_x[1];
  c19_c_X[1] = c19_h_x[2];
  c19_c_X[4] = 0.0;
  c19_c_X[7] = -c19_h_x[0];
  c19_c_X[2] = -c19_h_x[1];
  c19_c_X[5] = c19_h_x[0];
  c19_c_X[8] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c19_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c19_i15 = 0; c19_i15 < 4; c19_i15++) {
    c19_i_x[c19_i15] = c19_b_x[c19_i15 + 3];
  }

  for (c19_i16 = 0; c19_i16 < 3; c19_i16++) {
    c19_f_rv[c19_i16] = c19_b_rv[c19_i16 + 9];
  }

  c19_quatrot(chartInstance, c19_i_x, c19_f_rv, c19_dv5);
  for (c19_i17 = 0; c19_i17 < 3; c19_i17++) {
    c19_j_x[c19_i17] = c19_dv5[c19_i17];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c19_c_debug_family_names,
    c19_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_e_nargin, 0U, c19_c_sf_marshallOut,
    c19_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_e_nargout, 1U, c19_c_sf_marshallOut,
    c19_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c19_j_x, 2U, c19_f_sf_marshallOut,
    c19_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c19_d_X, 3U, c19_e_sf_marshallOut,
    c19_d_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c19_sfEvent, 3);
  c19_d_X[0] = 0.0;
  c19_d_X[3] = -c19_j_x[2];
  c19_d_X[6] = c19_j_x[1];
  c19_d_X[1] = c19_j_x[2];
  c19_d_X[4] = 0.0;
  c19_d_X[7] = -c19_j_x[0];
  c19_d_X[2] = -c19_j_x[1];
  c19_d_X[5] = c19_j_x[0];
  c19_d_X[8] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c19_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  c19_a = 4.0 * c19_b_m1;
  for (c19_i18 = 0; c19_i18 < 9; c19_i18++) {
    c19_b[c19_i18] = ((c19_X[c19_i18] + c19_b_X[c19_i18]) + c19_c_X[c19_i18]) +
      c19_d_X[c19_i18];
  }

  for (c19_i19 = 0; c19_i19 < 9; c19_i19++) {
    c19_Ms[c19_i19] = c19_a * c19_b[c19_i19];
  }

  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 5);
  c19_b_a = c19_b_mv + 4.0 * c19_b_m1;
  for (c19_i20 = 0; c19_i20 < 9; c19_i20++) {
    c19_y[c19_i20] = c19_b_a * c19_b_b[c19_i20];
  }

  c19_c_a = c19_b_jv + 4.0 * c19_b_j1;
  for (c19_i21 = 0; c19_i21 < 9; c19_i21++) {
    c19_b_y[c19_i21] = c19_c_a * c19_b_b[c19_i21];
  }

  for (c19_i22 = 0; c19_i22 < 4; c19_i22++) {
    c19_k_x[c19_i22] = c19_b_x[c19_i22 + 3];
  }

  for (c19_i23 = 0; c19_i23 < 3; c19_i23++) {
    c19_g_rv[c19_i23] = c19_b_rv[c19_i23];
  }

  c19_quatrot(chartInstance, c19_k_x, c19_g_rv, c19_dv6);
  for (c19_i24 = 0; c19_i24 < 3; c19_i24++) {
    c19_l_x[c19_i24] = c19_dv6[c19_i24];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c19_c_debug_family_names,
    c19_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_f_nargin, 0U, c19_c_sf_marshallOut,
    c19_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_f_nargout, 1U, c19_c_sf_marshallOut,
    c19_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c19_l_x, 2U, c19_f_sf_marshallOut,
    c19_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c19_e_X, 3U, c19_e_sf_marshallOut,
    c19_d_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c19_sfEvent, 3);
  c19_e_X[0] = 0.0;
  c19_e_X[3] = -c19_l_x[2];
  c19_e_X[6] = c19_l_x[1];
  c19_e_X[1] = c19_l_x[2];
  c19_e_X[4] = 0.0;
  c19_e_X[7] = -c19_l_x[0];
  c19_e_X[2] = -c19_l_x[1];
  c19_e_X[5] = c19_l_x[0];
  c19_e_X[8] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c19_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c19_i25 = 0; c19_i25 < 4; c19_i25++) {
    c19_m_x[c19_i25] = c19_b_x[c19_i25 + 3];
  }

  for (c19_i26 = 0; c19_i26 < 3; c19_i26++) {
    c19_h_rv[c19_i26] = c19_b_rv[c19_i26 + 3];
  }

  c19_quatrot(chartInstance, c19_m_x, c19_h_rv, c19_dv7);
  for (c19_i27 = 0; c19_i27 < 3; c19_i27++) {
    c19_n_x[c19_i27] = c19_dv7[c19_i27];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c19_c_debug_family_names,
    c19_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_g_nargin, 0U, c19_c_sf_marshallOut,
    c19_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_g_nargout, 1U, c19_c_sf_marshallOut,
    c19_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c19_n_x, 2U, c19_f_sf_marshallOut,
    c19_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c19_f_X, 3U, c19_e_sf_marshallOut,
    c19_d_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c19_sfEvent, 3);
  c19_f_X[0] = 0.0;
  c19_f_X[3] = -c19_n_x[2];
  c19_f_X[6] = c19_n_x[1];
  c19_f_X[1] = c19_n_x[2];
  c19_f_X[4] = 0.0;
  c19_f_X[7] = -c19_n_x[0];
  c19_f_X[2] = -c19_n_x[1];
  c19_f_X[5] = c19_n_x[0];
  c19_f_X[8] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c19_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c19_i28 = 0; c19_i28 < 4; c19_i28++) {
    c19_o_x[c19_i28] = c19_b_x[c19_i28 + 3];
  }

  for (c19_i29 = 0; c19_i29 < 3; c19_i29++) {
    c19_i_rv[c19_i29] = c19_b_rv[c19_i29 + 6];
  }

  c19_quatrot(chartInstance, c19_o_x, c19_i_rv, c19_dv8);
  for (c19_i30 = 0; c19_i30 < 3; c19_i30++) {
    c19_p_x[c19_i30] = c19_dv8[c19_i30];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c19_c_debug_family_names,
    c19_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_h_nargin, 0U, c19_c_sf_marshallOut,
    c19_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_h_nargout, 1U, c19_c_sf_marshallOut,
    c19_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c19_p_x, 2U, c19_f_sf_marshallOut,
    c19_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c19_g_X, 3U, c19_e_sf_marshallOut,
    c19_d_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c19_sfEvent, 3);
  c19_g_X[0] = 0.0;
  c19_g_X[3] = -c19_p_x[2];
  c19_g_X[6] = c19_p_x[1];
  c19_g_X[1] = c19_p_x[2];
  c19_g_X[4] = 0.0;
  c19_g_X[7] = -c19_p_x[0];
  c19_g_X[2] = -c19_p_x[1];
  c19_g_X[5] = c19_p_x[0];
  c19_g_X[8] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c19_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c19_i31 = 0; c19_i31 < 4; c19_i31++) {
    c19_q_x[c19_i31] = c19_b_x[c19_i31 + 3];
  }

  for (c19_i32 = 0; c19_i32 < 3; c19_i32++) {
    c19_j_rv[c19_i32] = c19_b_rv[c19_i32 + 9];
  }

  c19_quatrot(chartInstance, c19_q_x, c19_j_rv, c19_dv9);
  for (c19_i33 = 0; c19_i33 < 3; c19_i33++) {
    c19_r_x[c19_i33] = c19_dv9[c19_i33];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c19_c_debug_family_names,
    c19_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_i_nargin, 0U, c19_c_sf_marshallOut,
    c19_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_i_nargout, 1U, c19_c_sf_marshallOut,
    c19_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c19_r_x, 2U, c19_f_sf_marshallOut,
    c19_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c19_h_X, 3U, c19_e_sf_marshallOut,
    c19_d_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c19_sfEvent, 3);
  c19_h_X[0] = 0.0;
  c19_h_X[3] = -c19_r_x[2];
  c19_h_X[6] = c19_r_x[1];
  c19_h_X[1] = c19_r_x[2];
  c19_h_X[4] = 0.0;
  c19_h_X[7] = -c19_r_x[0];
  c19_h_X[2] = -c19_r_x[1];
  c19_h_X[5] = c19_r_x[0];
  c19_h_X[8] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c19_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  c19_d_a = 4.0 * c19_b_m1;
  for (c19_i34 = 0; c19_i34 < 9; c19_i34++) {
    c19_i_X[c19_i34] = c19_e_X[c19_i34];
  }

  c19_mpower(chartInstance, c19_i_X, c19_b);
  for (c19_i35 = 0; c19_i35 < 9; c19_i35++) {
    c19_j_X[c19_i35] = c19_f_X[c19_i35];
  }

  c19_mpower(chartInstance, c19_j_X, c19_dv10);
  for (c19_i36 = 0; c19_i36 < 9; c19_i36++) {
    c19_k_X[c19_i36] = c19_g_X[c19_i36];
  }

  c19_mpower(chartInstance, c19_k_X, c19_dv11);
  for (c19_i37 = 0; c19_i37 < 9; c19_i37++) {
    c19_l_X[c19_i37] = c19_h_X[c19_i37];
  }

  c19_mpower(chartInstance, c19_l_X, c19_dv12);
  for (c19_i38 = 0; c19_i38 < 9; c19_i38++) {
    c19_b[c19_i38] = ((c19_b[c19_i38] + c19_dv10[c19_i38]) + c19_dv11[c19_i38])
      + c19_dv12[c19_i38];
  }

  for (c19_i39 = 0; c19_i39 < 9; c19_i39++) {
    c19_b[c19_i39] *= c19_d_a;
  }

  c19_i40 = 0;
  c19_i41 = 0;
  for (c19_i42 = 0; c19_i42 < 3; c19_i42++) {
    for (c19_i43 = 0; c19_i43 < 3; c19_i43++) {
      c19_b_M[c19_i43 + c19_i40] = c19_y[c19_i43 + c19_i41];
    }

    c19_i40 += 6;
    c19_i41 += 3;
  }

  c19_i44 = 0;
  c19_i45 = 0;
  for (c19_i46 = 0; c19_i46 < 3; c19_i46++) {
    for (c19_i47 = 0; c19_i47 < 3; c19_i47++) {
      c19_b_M[(c19_i47 + c19_i44) + 18] = -c19_Ms[c19_i47 + c19_i45];
    }

    c19_i44 += 6;
    c19_i45 += 3;
  }

  c19_i48 = 0;
  c19_i49 = 0;
  for (c19_i50 = 0; c19_i50 < 3; c19_i50++) {
    for (c19_i51 = 0; c19_i51 < 3; c19_i51++) {
      c19_b_M[(c19_i51 + c19_i48) + 3] = c19_Ms[c19_i51 + c19_i49];
    }

    c19_i48 += 6;
    c19_i49 += 3;
  }

  c19_i52 = 0;
  c19_i53 = 0;
  for (c19_i54 = 0; c19_i54 < 3; c19_i54++) {
    for (c19_i55 = 0; c19_i55 < 3; c19_i55++) {
      c19_b_M[(c19_i55 + c19_i52) + 21] = c19_b_y[c19_i55 + c19_i53] -
        c19_b[c19_i55 + c19_i53];
    }

    c19_i52 += 6;
    c19_i53 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, -5);
  _SFD_SYMBOL_SCOPE_POP();
  for (c19_i56 = 0; c19_i56 < 36; c19_i56++) {
    (*chartInstance->c19_M)[c19_i56] = c19_b_M[c19_i56];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c19_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DIPCMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c19_i57 = 0; c19_i57 < 36; c19_i57++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c19_M)[c19_i57], 1U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c19_mv, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c19_jv, 3U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c19_m1, 4U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c19_j1, 5U);
  for (c19_i58 = 0; c19_i58 < 12; c19_i58++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c19_rv[c19_i58], 6U);
  }
}

static void mdl_start_c19_DIPC(SFc19_DIPCInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc19_DIPC(SFc19_DIPCInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c19_quatrot(SFc19_DIPCInstanceStruct *chartInstance, real_T c19_q[4],
  real_T c19_r[3], real_T c19_rw[3])
{
  uint32_T c19_debug_family_var_map[6];
  real_T c19_rwq[4];
  real_T c19_nargin = 2.0;
  real_T c19_nargout = 1.0;
  int32_T c19_i59;
  real_T c19_b_q[4];
  int32_T c19_k;
  real_T c19_b_k;
  real_T c19_dv13[4];
  int32_T c19_i60;
  int32_T c19_i61;
  real_T c19_c_q[4];
  real_T c19_dv14[4];
  int32_T c19_i62;
  real_T c19_d_q[4];
  int32_T c19_i63;
  real_T c19_dv15[4];
  int32_T c19_i64;
  int32_T c19_i65;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c19_b_debug_family_names,
    c19_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c19_rwq, 0U, c19_g_sf_marshallOut,
    c19_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_nargin, 1U, c19_c_sf_marshallOut,
    c19_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_nargout, 2U, c19_c_sf_marshallOut,
    c19_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c19_q, 3U, c19_g_sf_marshallOut,
    c19_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c19_r, 4U, c19_f_sf_marshallOut,
    c19_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c19_rw, 5U, c19_f_sf_marshallOut,
    c19_e_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c19_sfEvent, 4);
  for (c19_i59 = 0; c19_i59 < 4; c19_i59++) {
    c19_b_q[c19_i59] = c19_q[c19_i59];
  }

  for (c19_k = 0; c19_k < 3; c19_k++) {
    c19_b_k = 2.0 + (real_T)c19_k;
    c19_b_q[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c19_b_k), 1, 4, 1, 0) - 1] = -c19_b_q[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", c19_b_k), 1, 4, 1, 0) - 1];
  }

  c19_dv13[0] = 0.0;
  for (c19_i60 = 0; c19_i60 < 3; c19_i60++) {
    c19_dv13[c19_i60 + 1] = c19_r[c19_i60];
  }

  for (c19_i61 = 0; c19_i61 < 4; c19_i61++) {
    c19_c_q[c19_i61] = c19_b_q[c19_i61];
  }

  c19_quatmultiply(chartInstance, c19_dv13, c19_c_q, c19_dv14);
  for (c19_i62 = 0; c19_i62 < 4; c19_i62++) {
    c19_d_q[c19_i62] = c19_q[c19_i62];
  }

  for (c19_i63 = 0; c19_i63 < 4; c19_i63++) {
    c19_dv15[c19_i63] = c19_dv14[c19_i63];
  }

  c19_quatmultiply(chartInstance, c19_d_q, c19_dv15, c19_b_q);
  for (c19_i64 = 0; c19_i64 < 4; c19_i64++) {
    c19_rwq[c19_i64] = c19_b_q[c19_i64];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c19_sfEvent, 5);
  for (c19_i65 = 0; c19_i65 < 3; c19_i65++) {
    c19_rw[c19_i65] = c19_rwq[c19_i65 + 1];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c19_sfEvent, -5);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber, uint32_T c19_instanceNumber)
{
  (void)c19_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c19_chartNumber, c19_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Martin\\Documents\\Git\\Simulink\\DIPC\\quatrot.m"));
  _SFD_SCRIPT_TRANSLATION(c19_chartNumber, c19_instanceNumber, 1U,
    sf_debug_get_script_id(
    "C:\\Users\\Martin\\Documents\\Git\\Simulink\\DIPC\\skew_sm.m"));
}

static const mxArray *c19_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  int32_T c19_i66;
  int32_T c19_i67;
  int32_T c19_i68;
  real_T c19_b_inData[36];
  int32_T c19_i69;
  int32_T c19_i70;
  int32_T c19_i71;
  real_T c19_u[36];
  const mxArray *c19_y = NULL;
  SFc19_DIPCInstanceStruct *chartInstance;
  chartInstance = (SFc19_DIPCInstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_i66 = 0;
  for (c19_i67 = 0; c19_i67 < 6; c19_i67++) {
    for (c19_i68 = 0; c19_i68 < 6; c19_i68++) {
      c19_b_inData[c19_i68 + c19_i66] = (*(real_T (*)[36])c19_inData)[c19_i68 +
        c19_i66];
    }

    c19_i66 += 6;
  }

  c19_i69 = 0;
  for (c19_i70 = 0; c19_i70 < 6; c19_i70++) {
    for (c19_i71 = 0; c19_i71 < 6; c19_i71++) {
      c19_u[c19_i71 + c19_i69] = c19_b_inData[c19_i71 + c19_i69];
    }

    c19_i69 += 6;
  }

  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", c19_u, 0, 0U, 1U, 0U, 2, 6, 6), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static void c19_emlrt_marshallIn(SFc19_DIPCInstanceStruct *chartInstance, const
  mxArray *c19_b_M, const char_T *c19_identifier, real_T c19_y[36])
{
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_M), &c19_thisId, c19_y);
  sf_mex_destroy(&c19_b_M);
}

static void c19_b_emlrt_marshallIn(SFc19_DIPCInstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId, real_T c19_y[36])
{
  real_T c19_dv16[36];
  int32_T c19_i72;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), c19_dv16, 1, 0, 0U, 1, 0U, 2, 6,
                6);
  for (c19_i72 = 0; c19_i72 < 36; c19_i72++) {
    c19_y[c19_i72] = c19_dv16[c19_i72];
  }

  sf_mex_destroy(&c19_u);
}

static void c19_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_b_M;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  real_T c19_y[36];
  int32_T c19_i73;
  int32_T c19_i74;
  int32_T c19_i75;
  SFc19_DIPCInstanceStruct *chartInstance;
  chartInstance = (SFc19_DIPCInstanceStruct *)chartInstanceVoid;
  c19_b_M = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_M), &c19_thisId, c19_y);
  sf_mex_destroy(&c19_b_M);
  c19_i73 = 0;
  for (c19_i74 = 0; c19_i74 < 6; c19_i74++) {
    for (c19_i75 = 0; c19_i75 < 6; c19_i75++) {
      (*(real_T (*)[36])c19_outData)[c19_i75 + c19_i73] = c19_y[c19_i75 +
        c19_i73];
    }

    c19_i73 += 6;
  }

  sf_mex_destroy(&c19_mxArrayInData);
}

static const mxArray *c19_b_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  int32_T c19_i76;
  real_T c19_b_inData[12];
  int32_T c19_i77;
  real_T c19_u[12];
  const mxArray *c19_y = NULL;
  SFc19_DIPCInstanceStruct *chartInstance;
  chartInstance = (SFc19_DIPCInstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  for (c19_i76 = 0; c19_i76 < 12; c19_i76++) {
    c19_b_inData[c19_i76] = (*(real_T (*)[12])c19_inData)[c19_i76];
  }

  for (c19_i77 = 0; c19_i77 < 12; c19_i77++) {
    c19_u[c19_i77] = c19_b_inData[c19_i77];
  }

  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", c19_u, 0, 0U, 1U, 0U, 1, 12), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static void c19_c_emlrt_marshallIn(SFc19_DIPCInstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId, real_T c19_y[12])
{
  real_T c19_dv17[12];
  int32_T c19_i78;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), c19_dv17, 1, 0, 0U, 1, 0U, 1,
                12);
  for (c19_i78 = 0; c19_i78 < 12; c19_i78++) {
    c19_y[c19_i78] = c19_dv17[c19_i78];
  }

  sf_mex_destroy(&c19_u);
}

static void c19_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_b_rv;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  real_T c19_y[12];
  int32_T c19_i79;
  SFc19_DIPCInstanceStruct *chartInstance;
  chartInstance = (SFc19_DIPCInstanceStruct *)chartInstanceVoid;
  c19_b_rv = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_rv), &c19_thisId, c19_y);
  sf_mex_destroy(&c19_b_rv);
  for (c19_i79 = 0; c19_i79 < 12; c19_i79++) {
    (*(real_T (*)[12])c19_outData)[c19_i79] = c19_y[c19_i79];
  }

  sf_mex_destroy(&c19_mxArrayInData);
}

static const mxArray *c19_c_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  real_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_DIPCInstanceStruct *chartInstance;
  chartInstance = (SFc19_DIPCInstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(real_T *)c19_inData;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static real_T c19_d_emlrt_marshallIn(SFc19_DIPCInstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  real_T c19_y;
  real_T c19_d4;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_d4, 1, 0, 0U, 0, 0U, 0);
  c19_y = c19_d4;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_b_j1;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  real_T c19_y;
  SFc19_DIPCInstanceStruct *chartInstance;
  chartInstance = (SFc19_DIPCInstanceStruct *)chartInstanceVoid;
  c19_b_j1 = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_j1),
    &c19_thisId);
  sf_mex_destroy(&c19_b_j1);
  *(real_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

static const mxArray *c19_d_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  int32_T c19_i80;
  real_T c19_b_inData[7];
  int32_T c19_i81;
  real_T c19_u[7];
  const mxArray *c19_y = NULL;
  SFc19_DIPCInstanceStruct *chartInstance;
  chartInstance = (SFc19_DIPCInstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  for (c19_i80 = 0; c19_i80 < 7; c19_i80++) {
    c19_b_inData[c19_i80] = (*(real_T (*)[7])c19_inData)[c19_i80];
  }

  for (c19_i81 = 0; c19_i81 < 7; c19_i81++) {
    c19_u[c19_i81] = c19_b_inData[c19_i81];
  }

  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", c19_u, 0, 0U, 1U, 0U, 1, 7), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static const mxArray *c19_e_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  int32_T c19_i82;
  int32_T c19_i83;
  int32_T c19_i84;
  real_T c19_b_inData[9];
  int32_T c19_i85;
  int32_T c19_i86;
  int32_T c19_i87;
  real_T c19_u[9];
  const mxArray *c19_y = NULL;
  SFc19_DIPCInstanceStruct *chartInstance;
  chartInstance = (SFc19_DIPCInstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_i82 = 0;
  for (c19_i83 = 0; c19_i83 < 3; c19_i83++) {
    for (c19_i84 = 0; c19_i84 < 3; c19_i84++) {
      c19_b_inData[c19_i84 + c19_i82] = (*(real_T (*)[9])c19_inData)[c19_i84 +
        c19_i82];
    }

    c19_i82 += 3;
  }

  c19_i85 = 0;
  for (c19_i86 = 0; c19_i86 < 3; c19_i86++) {
    for (c19_i87 = 0; c19_i87 < 3; c19_i87++) {
      c19_u[c19_i87 + c19_i85] = c19_b_inData[c19_i87 + c19_i85];
    }

    c19_i85 += 3;
  }

  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", c19_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static void c19_e_emlrt_marshallIn(SFc19_DIPCInstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId, real_T c19_y[9])
{
  real_T c19_dv18[9];
  int32_T c19_i88;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), c19_dv18, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c19_i88 = 0; c19_i88 < 9; c19_i88++) {
    c19_y[c19_i88] = c19_dv18[c19_i88];
  }

  sf_mex_destroy(&c19_u);
}

static void c19_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_Ms;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  real_T c19_y[9];
  int32_T c19_i89;
  int32_T c19_i90;
  int32_T c19_i91;
  SFc19_DIPCInstanceStruct *chartInstance;
  chartInstance = (SFc19_DIPCInstanceStruct *)chartInstanceVoid;
  c19_Ms = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_Ms), &c19_thisId, c19_y);
  sf_mex_destroy(&c19_Ms);
  c19_i89 = 0;
  for (c19_i90 = 0; c19_i90 < 3; c19_i90++) {
    for (c19_i91 = 0; c19_i91 < 3; c19_i91++) {
      (*(real_T (*)[9])c19_outData)[c19_i91 + c19_i89] = c19_y[c19_i91 + c19_i89];
    }

    c19_i89 += 3;
  }

  sf_mex_destroy(&c19_mxArrayInData);
}

static const mxArray *c19_f_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  int32_T c19_i92;
  real_T c19_b_inData[3];
  int32_T c19_i93;
  real_T c19_u[3];
  const mxArray *c19_y = NULL;
  SFc19_DIPCInstanceStruct *chartInstance;
  chartInstance = (SFc19_DIPCInstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  for (c19_i92 = 0; c19_i92 < 3; c19_i92++) {
    c19_b_inData[c19_i92] = (*(real_T (*)[3])c19_inData)[c19_i92];
  }

  for (c19_i93 = 0; c19_i93 < 3; c19_i93++) {
    c19_u[c19_i93] = c19_b_inData[c19_i93];
  }

  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", c19_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static void c19_f_emlrt_marshallIn(SFc19_DIPCInstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId, real_T c19_y[3])
{
  real_T c19_dv19[3];
  int32_T c19_i94;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), c19_dv19, 1, 0, 0U, 1, 0U, 1, 3);
  for (c19_i94 = 0; c19_i94 < 3; c19_i94++) {
    c19_y[c19_i94] = c19_dv19[c19_i94];
  }

  sf_mex_destroy(&c19_u);
}

static void c19_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_rw;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  real_T c19_y[3];
  int32_T c19_i95;
  SFc19_DIPCInstanceStruct *chartInstance;
  chartInstance = (SFc19_DIPCInstanceStruct *)chartInstanceVoid;
  c19_rw = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_rw), &c19_thisId, c19_y);
  sf_mex_destroy(&c19_rw);
  for (c19_i95 = 0; c19_i95 < 3; c19_i95++) {
    (*(real_T (*)[3])c19_outData)[c19_i95] = c19_y[c19_i95];
  }

  sf_mex_destroy(&c19_mxArrayInData);
}

static const mxArray *c19_g_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  int32_T c19_i96;
  real_T c19_b_inData[4];
  int32_T c19_i97;
  real_T c19_u[4];
  const mxArray *c19_y = NULL;
  SFc19_DIPCInstanceStruct *chartInstance;
  chartInstance = (SFc19_DIPCInstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  for (c19_i96 = 0; c19_i96 < 4; c19_i96++) {
    c19_b_inData[c19_i96] = (*(real_T (*)[4])c19_inData)[c19_i96];
  }

  for (c19_i97 = 0; c19_i97 < 4; c19_i97++) {
    c19_u[c19_i97] = c19_b_inData[c19_i97];
  }

  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", c19_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static void c19_g_emlrt_marshallIn(SFc19_DIPCInstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId, real_T c19_y[4])
{
  real_T c19_dv20[4];
  int32_T c19_i98;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), c19_dv20, 1, 0, 0U, 1, 0U, 1, 4);
  for (c19_i98 = 0; c19_i98 < 4; c19_i98++) {
    c19_y[c19_i98] = c19_dv20[c19_i98];
  }

  sf_mex_destroy(&c19_u);
}

static void c19_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_q;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  real_T c19_y[4];
  int32_T c19_i99;
  SFc19_DIPCInstanceStruct *chartInstance;
  chartInstance = (SFc19_DIPCInstanceStruct *)chartInstanceVoid;
  c19_q = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_q), &c19_thisId, c19_y);
  sf_mex_destroy(&c19_q);
  for (c19_i99 = 0; c19_i99 < 4; c19_i99++) {
    (*(real_T (*)[4])c19_outData)[c19_i99] = c19_y[c19_i99];
  }

  sf_mex_destroy(&c19_mxArrayInData);
}

const mxArray *sf_c19_DIPC_get_eml_resolved_functions_info(void)
{
  const mxArray *c19_nameCaptureInfo = NULL;
  c19_nameCaptureInfo = NULL;
  sf_mex_assign(&c19_nameCaptureInfo, sf_mex_createstruct("structure", 2, 52, 1),
                false);
  c19_info_helper(&c19_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c19_nameCaptureInfo);
  return c19_nameCaptureInfo;
}

static void c19_info_helper(const mxArray **c19_info)
{
  const mxArray *c19_rhs0 = NULL;
  const mxArray *c19_lhs0 = NULL;
  const mxArray *c19_rhs1 = NULL;
  const mxArray *c19_lhs1 = NULL;
  const mxArray *c19_rhs2 = NULL;
  const mxArray *c19_lhs2 = NULL;
  const mxArray *c19_rhs3 = NULL;
  const mxArray *c19_lhs3 = NULL;
  const mxArray *c19_rhs4 = NULL;
  const mxArray *c19_lhs4 = NULL;
  const mxArray *c19_rhs5 = NULL;
  const mxArray *c19_lhs5 = NULL;
  const mxArray *c19_rhs6 = NULL;
  const mxArray *c19_lhs6 = NULL;
  const mxArray *c19_rhs7 = NULL;
  const mxArray *c19_lhs7 = NULL;
  const mxArray *c19_rhs8 = NULL;
  const mxArray *c19_lhs8 = NULL;
  const mxArray *c19_rhs9 = NULL;
  const mxArray *c19_lhs9 = NULL;
  const mxArray *c19_rhs10 = NULL;
  const mxArray *c19_lhs10 = NULL;
  const mxArray *c19_rhs11 = NULL;
  const mxArray *c19_lhs11 = NULL;
  const mxArray *c19_rhs12 = NULL;
  const mxArray *c19_lhs12 = NULL;
  const mxArray *c19_rhs13 = NULL;
  const mxArray *c19_lhs13 = NULL;
  const mxArray *c19_rhs14 = NULL;
  const mxArray *c19_lhs14 = NULL;
  const mxArray *c19_rhs15 = NULL;
  const mxArray *c19_lhs15 = NULL;
  const mxArray *c19_rhs16 = NULL;
  const mxArray *c19_lhs16 = NULL;
  const mxArray *c19_rhs17 = NULL;
  const mxArray *c19_lhs17 = NULL;
  const mxArray *c19_rhs18 = NULL;
  const mxArray *c19_lhs18 = NULL;
  const mxArray *c19_rhs19 = NULL;
  const mxArray *c19_lhs19 = NULL;
  const mxArray *c19_rhs20 = NULL;
  const mxArray *c19_lhs20 = NULL;
  const mxArray *c19_rhs21 = NULL;
  const mxArray *c19_lhs21 = NULL;
  const mxArray *c19_rhs22 = NULL;
  const mxArray *c19_lhs22 = NULL;
  const mxArray *c19_rhs23 = NULL;
  const mxArray *c19_lhs23 = NULL;
  const mxArray *c19_rhs24 = NULL;
  const mxArray *c19_lhs24 = NULL;
  const mxArray *c19_rhs25 = NULL;
  const mxArray *c19_lhs25 = NULL;
  const mxArray *c19_rhs26 = NULL;
  const mxArray *c19_lhs26 = NULL;
  const mxArray *c19_rhs27 = NULL;
  const mxArray *c19_lhs27 = NULL;
  const mxArray *c19_rhs28 = NULL;
  const mxArray *c19_lhs28 = NULL;
  const mxArray *c19_rhs29 = NULL;
  const mxArray *c19_lhs29 = NULL;
  const mxArray *c19_rhs30 = NULL;
  const mxArray *c19_lhs30 = NULL;
  const mxArray *c19_rhs31 = NULL;
  const mxArray *c19_lhs31 = NULL;
  const mxArray *c19_rhs32 = NULL;
  const mxArray *c19_lhs32 = NULL;
  const mxArray *c19_rhs33 = NULL;
  const mxArray *c19_lhs33 = NULL;
  const mxArray *c19_rhs34 = NULL;
  const mxArray *c19_lhs34 = NULL;
  const mxArray *c19_rhs35 = NULL;
  const mxArray *c19_lhs35 = NULL;
  const mxArray *c19_rhs36 = NULL;
  const mxArray *c19_lhs36 = NULL;
  const mxArray *c19_rhs37 = NULL;
  const mxArray *c19_lhs37 = NULL;
  const mxArray *c19_rhs38 = NULL;
  const mxArray *c19_lhs38 = NULL;
  const mxArray *c19_rhs39 = NULL;
  const mxArray *c19_lhs39 = NULL;
  const mxArray *c19_rhs40 = NULL;
  const mxArray *c19_lhs40 = NULL;
  const mxArray *c19_rhs41 = NULL;
  const mxArray *c19_lhs41 = NULL;
  const mxArray *c19_rhs42 = NULL;
  const mxArray *c19_lhs42 = NULL;
  const mxArray *c19_rhs43 = NULL;
  const mxArray *c19_lhs43 = NULL;
  const mxArray *c19_rhs44 = NULL;
  const mxArray *c19_lhs44 = NULL;
  const mxArray *c19_rhs45 = NULL;
  const mxArray *c19_lhs45 = NULL;
  const mxArray *c19_rhs46 = NULL;
  const mxArray *c19_lhs46 = NULL;
  const mxArray *c19_rhs47 = NULL;
  const mxArray *c19_lhs47 = NULL;
  const mxArray *c19_rhs48 = NULL;
  const mxArray *c19_lhs48 = NULL;
  const mxArray *c19_rhs49 = NULL;
  const mxArray *c19_lhs49 = NULL;
  const mxArray *c19_rhs50 = NULL;
  const mxArray *c19_lhs50 = NULL;
  const mxArray *c19_rhs51 = NULL;
  const mxArray *c19_lhs51 = NULL;
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("quatrot"), "name", "name", 0);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DIPC/quatrot.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1446631716U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c19_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DIPC/quatrot.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("quatconj"), "name", "name",
                  1);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatconj.p"), "resolved", "resolved",
                  1);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1410808258U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c19_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DIPC/quatrot.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("quatmultiply"), "name",
                  "name", 2);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatmultiply.p"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1410808258U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c19_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatmultiply.p"), "context",
                  "context", 3);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("max"), "name", "name", 3);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1311280516U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c19_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 4);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1378321184U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c19_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 5);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 5);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c19_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 6);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c19_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 7);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 7);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c19_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 8);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c19_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 9);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 9);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c19_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 10);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 10);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c19_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 11);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 11);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c19_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(""), "context", "context", 12);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("skew_sm"), "name", "name",
                  12);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DIPC/skew_sm.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1445505143U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c19_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(""), "context", "context", 13);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 13);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1383902494U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c19_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 14);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 14);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c19_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(""), "context", "context", 15);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("eye"), "name", "name", 15);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1406838348U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c19_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 16);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1368208230U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c19_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 17);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 17);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c19_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral"),
                  "context", "context", 18);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("isinf"), "name", "name", 18);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1363739056U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c19_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 19);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c19_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 20);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("eml_is_integer_class"),
                  "name", "name", 20);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1286843982U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c19_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 21);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("intmax"), "name", "name", 21);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c19_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 22);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c19_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 23);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("intmin"), "name", "name", 23);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c19_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 24);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c19_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 25);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "coder.internal.indexIntRelop"), "name", "name", 25);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1326753522U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c19_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!apply_float_relop"),
                  "context", "context", 26);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 26);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c19_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass"),
                  "context", "context", 27);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 27);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1326753196U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c19_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass"),
                  "context", "context", 28);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("intmin"), "name", "name", 28);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c19_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 29);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 29);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c19_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 30);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("intmax"), "name", "name", 30);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c19_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 31);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1397282622U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c19_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 32);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("isfi"), "name", "name", 32);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 32);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1346535558U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c19_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 33);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1398900798U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c19_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 34);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("intmax"), "name", "name", 34);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c19_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 35);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("intmin"), "name", "name", 35);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 35);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c19_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(""), "context", "context", 36);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("mpower"), "name", "name", 36);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1363739078U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c19_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 37);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c19_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 38);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("ismatrix"), "name", "name",
                  38);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1331330058U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c19_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 39);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 39);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1286843926U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c19_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power"),
                  "context", "context", 40);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 40);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 40);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c19_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power"),
                  "context", "context", 41);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 41);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1383902494U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c19_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 42);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 42);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c19_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 43);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 43);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 43);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c19_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 44);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  44);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1376005890U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c19_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 45);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 45);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c19_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 46);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 46);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c19_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 47);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 47);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c19_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 48);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 48);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 48);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c19_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 49);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 49);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c19_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 50);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 50);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 50);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c19_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 51);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 51);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 51);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c19_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs51), "lhs", "lhs",
                  51);
  sf_mex_destroy(&c19_rhs0);
  sf_mex_destroy(&c19_lhs0);
  sf_mex_destroy(&c19_rhs1);
  sf_mex_destroy(&c19_lhs1);
  sf_mex_destroy(&c19_rhs2);
  sf_mex_destroy(&c19_lhs2);
  sf_mex_destroy(&c19_rhs3);
  sf_mex_destroy(&c19_lhs3);
  sf_mex_destroy(&c19_rhs4);
  sf_mex_destroy(&c19_lhs4);
  sf_mex_destroy(&c19_rhs5);
  sf_mex_destroy(&c19_lhs5);
  sf_mex_destroy(&c19_rhs6);
  sf_mex_destroy(&c19_lhs6);
  sf_mex_destroy(&c19_rhs7);
  sf_mex_destroy(&c19_lhs7);
  sf_mex_destroy(&c19_rhs8);
  sf_mex_destroy(&c19_lhs8);
  sf_mex_destroy(&c19_rhs9);
  sf_mex_destroy(&c19_lhs9);
  sf_mex_destroy(&c19_rhs10);
  sf_mex_destroy(&c19_lhs10);
  sf_mex_destroy(&c19_rhs11);
  sf_mex_destroy(&c19_lhs11);
  sf_mex_destroy(&c19_rhs12);
  sf_mex_destroy(&c19_lhs12);
  sf_mex_destroy(&c19_rhs13);
  sf_mex_destroy(&c19_lhs13);
  sf_mex_destroy(&c19_rhs14);
  sf_mex_destroy(&c19_lhs14);
  sf_mex_destroy(&c19_rhs15);
  sf_mex_destroy(&c19_lhs15);
  sf_mex_destroy(&c19_rhs16);
  sf_mex_destroy(&c19_lhs16);
  sf_mex_destroy(&c19_rhs17);
  sf_mex_destroy(&c19_lhs17);
  sf_mex_destroy(&c19_rhs18);
  sf_mex_destroy(&c19_lhs18);
  sf_mex_destroy(&c19_rhs19);
  sf_mex_destroy(&c19_lhs19);
  sf_mex_destroy(&c19_rhs20);
  sf_mex_destroy(&c19_lhs20);
  sf_mex_destroy(&c19_rhs21);
  sf_mex_destroy(&c19_lhs21);
  sf_mex_destroy(&c19_rhs22);
  sf_mex_destroy(&c19_lhs22);
  sf_mex_destroy(&c19_rhs23);
  sf_mex_destroy(&c19_lhs23);
  sf_mex_destroy(&c19_rhs24);
  sf_mex_destroy(&c19_lhs24);
  sf_mex_destroy(&c19_rhs25);
  sf_mex_destroy(&c19_lhs25);
  sf_mex_destroy(&c19_rhs26);
  sf_mex_destroy(&c19_lhs26);
  sf_mex_destroy(&c19_rhs27);
  sf_mex_destroy(&c19_lhs27);
  sf_mex_destroy(&c19_rhs28);
  sf_mex_destroy(&c19_lhs28);
  sf_mex_destroy(&c19_rhs29);
  sf_mex_destroy(&c19_lhs29);
  sf_mex_destroy(&c19_rhs30);
  sf_mex_destroy(&c19_lhs30);
  sf_mex_destroy(&c19_rhs31);
  sf_mex_destroy(&c19_lhs31);
  sf_mex_destroy(&c19_rhs32);
  sf_mex_destroy(&c19_lhs32);
  sf_mex_destroy(&c19_rhs33);
  sf_mex_destroy(&c19_lhs33);
  sf_mex_destroy(&c19_rhs34);
  sf_mex_destroy(&c19_lhs34);
  sf_mex_destroy(&c19_rhs35);
  sf_mex_destroy(&c19_lhs35);
  sf_mex_destroy(&c19_rhs36);
  sf_mex_destroy(&c19_lhs36);
  sf_mex_destroy(&c19_rhs37);
  sf_mex_destroy(&c19_lhs37);
  sf_mex_destroy(&c19_rhs38);
  sf_mex_destroy(&c19_lhs38);
  sf_mex_destroy(&c19_rhs39);
  sf_mex_destroy(&c19_lhs39);
  sf_mex_destroy(&c19_rhs40);
  sf_mex_destroy(&c19_lhs40);
  sf_mex_destroy(&c19_rhs41);
  sf_mex_destroy(&c19_lhs41);
  sf_mex_destroy(&c19_rhs42);
  sf_mex_destroy(&c19_lhs42);
  sf_mex_destroy(&c19_rhs43);
  sf_mex_destroy(&c19_lhs43);
  sf_mex_destroy(&c19_rhs44);
  sf_mex_destroy(&c19_lhs44);
  sf_mex_destroy(&c19_rhs45);
  sf_mex_destroy(&c19_lhs45);
  sf_mex_destroy(&c19_rhs46);
  sf_mex_destroy(&c19_lhs46);
  sf_mex_destroy(&c19_rhs47);
  sf_mex_destroy(&c19_lhs47);
  sf_mex_destroy(&c19_rhs48);
  sf_mex_destroy(&c19_lhs48);
  sf_mex_destroy(&c19_rhs49);
  sf_mex_destroy(&c19_lhs49);
  sf_mex_destroy(&c19_rhs50);
  sf_mex_destroy(&c19_lhs50);
  sf_mex_destroy(&c19_rhs51);
  sf_mex_destroy(&c19_lhs51);
}

static const mxArray *c19_emlrt_marshallOut(const char * c19_u)
{
  const mxArray *c19_y = NULL;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", c19_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c19_u)), false);
  return c19_y;
}

static const mxArray *c19_b_emlrt_marshallOut(const uint32_T c19_u)
{
  const mxArray *c19_y = NULL;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 7, 0U, 0U, 0U, 0), false);
  return c19_y;
}

static void c19_quatmultiply(SFc19_DIPCInstanceStruct *chartInstance, real_T
  c19_q[4], real_T c19_r[4], real_T c19_qout[4])
{
  real_T c19_q1;
  real_T c19_q2;
  real_T c19_q3;
  real_T c19_q4;
  real_T c19_r1;
  real_T c19_r2;
  real_T c19_r3;
  real_T c19_r4;
  (void)chartInstance;
  c19_q1 = c19_q[0];
  c19_q2 = c19_q[1];
  c19_q3 = c19_q[2];
  c19_q4 = c19_q[3];
  c19_r1 = c19_r[0];
  c19_r2 = c19_r[1];
  c19_r3 = c19_r[2];
  c19_r4 = c19_r[3];
  c19_qout[0] = ((c19_q1 * c19_r1 - c19_q2 * c19_r2) - c19_q3 * c19_r3) - c19_q4
    * c19_r4;
  c19_qout[1] = (c19_q1 * c19_r2 + c19_r1 * c19_q2) + (c19_q3 * c19_r4 - c19_q4 *
    c19_r3);
  c19_qout[2] = (c19_q1 * c19_r3 + c19_r1 * c19_q3) + (c19_q4 * c19_r2 - c19_q2 *
    c19_r4);
  c19_qout[3] = (c19_q1 * c19_r4 + c19_r1 * c19_q4) + (c19_q2 * c19_r3 - c19_q3 *
    c19_r2);
}

static void c19_mpower(SFc19_DIPCInstanceStruct *chartInstance, real_T c19_a[9],
  real_T c19_c[9])
{
  int32_T c19_i100;
  int32_T c19_i101;
  real_T c19_b_a[9];
  int32_T c19_i102;
  real_T c19_c_a[9];
  c19_eml_scalar_eg(chartInstance);
  c19_eml_scalar_eg(chartInstance);
  for (c19_i100 = 0; c19_i100 < 9; c19_i100++) {
    c19_c[c19_i100] = 0.0;
  }

  for (c19_i101 = 0; c19_i101 < 9; c19_i101++) {
    c19_b_a[c19_i101] = c19_a[c19_i101];
  }

  for (c19_i102 = 0; c19_i102 < 9; c19_i102++) {
    c19_c_a[c19_i102] = c19_a[c19_i102];
  }

  c19_b_eml_xgemm(chartInstance, c19_b_a, c19_c_a, c19_c);
}

static void c19_eml_scalar_eg(SFc19_DIPCInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c19_eml_xgemm(SFc19_DIPCInstanceStruct *chartInstance, real_T c19_A
  [9], real_T c19_B[9], real_T c19_C[9], real_T c19_b_C[9])
{
  int32_T c19_i103;
  int32_T c19_i104;
  real_T c19_b_A[9];
  int32_T c19_i105;
  real_T c19_b_B[9];
  for (c19_i103 = 0; c19_i103 < 9; c19_i103++) {
    c19_b_C[c19_i103] = c19_C[c19_i103];
  }

  for (c19_i104 = 0; c19_i104 < 9; c19_i104++) {
    c19_b_A[c19_i104] = c19_A[c19_i104];
  }

  for (c19_i105 = 0; c19_i105 < 9; c19_i105++) {
    c19_b_B[c19_i105] = c19_B[c19_i105];
  }

  c19_b_eml_xgemm(chartInstance, c19_b_A, c19_b_B, c19_b_C);
}

static const mxArray *c19_h_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  int32_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_DIPCInstanceStruct *chartInstance;
  chartInstance = (SFc19_DIPCInstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(int32_T *)c19_inData;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static int32_T c19_h_emlrt_marshallIn(SFc19_DIPCInstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  int32_T c19_y;
  int32_T c19_i106;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_i106, 1, 6, 0U, 0, 0U, 0);
  c19_y = c19_i106;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_b_sfEvent;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  int32_T c19_y;
  SFc19_DIPCInstanceStruct *chartInstance;
  chartInstance = (SFc19_DIPCInstanceStruct *)chartInstanceVoid;
  c19_b_sfEvent = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_sfEvent),
    &c19_thisId);
  sf_mex_destroy(&c19_b_sfEvent);
  *(int32_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

static uint8_T c19_i_emlrt_marshallIn(SFc19_DIPCInstanceStruct *chartInstance,
  const mxArray *c19_b_is_active_c19_DIPC, const char_T *c19_identifier)
{
  uint8_T c19_y;
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c19_b_is_active_c19_DIPC), &c19_thisId);
  sf_mex_destroy(&c19_b_is_active_c19_DIPC);
  return c19_y;
}

static uint8_T c19_j_emlrt_marshallIn(SFc19_DIPCInstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  uint8_T c19_y;
  uint8_T c19_u0;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_u0, 1, 3, 0U, 0, 0U, 0);
  c19_y = c19_u0;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_b_eml_xgemm(SFc19_DIPCInstanceStruct *chartInstance, real_T
  c19_A[9], real_T c19_B[9], real_T c19_C[9])
{
  int32_T c19_i107;
  int32_T c19_i108;
  int32_T c19_i109;
  int32_T c19_i110;
  int32_T c19_i111;
  (void)chartInstance;
  for (c19_i107 = 0; c19_i107 < 3; c19_i107++) {
    c19_i108 = 0;
    for (c19_i109 = 0; c19_i109 < 3; c19_i109++) {
      c19_C[c19_i108 + c19_i107] = 0.0;
      c19_i110 = 0;
      for (c19_i111 = 0; c19_i111 < 3; c19_i111++) {
        c19_C[c19_i108 + c19_i107] += c19_A[c19_i110 + c19_i107] *
          c19_B[c19_i111 + c19_i108];
        c19_i110 += 3;
      }

      c19_i108 += 3;
    }
  }
}

static void init_dsm_address_info(SFc19_DIPCInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc19_DIPCInstanceStruct *chartInstance)
{
  chartInstance->c19_x = (real_T (*)[7])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c19_M = (real_T (*)[36])ssGetOutputPortSignal_wrapper
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

void sf_c19_DIPC_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1232183287U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2841783465U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1861601705U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1170828738U);
}

mxArray* sf_c19_DIPC_get_post_codegen_info(void);
mxArray *sf_c19_DIPC_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("h3vVVKF3gwbrLTcdPXxofC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(7);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(12);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(6);
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
    mxArray* mxPostCodegenInfo = sf_c19_DIPC_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c19_DIPC_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c19_DIPC_jit_fallback_info(void)
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

mxArray *sf_c19_DIPC_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c19_DIPC_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c19_DIPC(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"M\",},{M[8],M[0],T\"is_active_c19_DIPC\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c19_DIPC_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc19_DIPCInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc19_DIPCInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DIPCMachineNumber_,
           19,
           1,
           1,
           0,
           7,
           0,
           0,
           0,
           0,
           2,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_DIPCMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_DIPCMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _DIPCMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"x");
          _SFD_SET_DATA_PROPS(1,2,0,1,"M");
          _SFD_SET_DATA_PROPS(2,10,0,0,"mv");
          _SFD_SET_DATA_PROPS(3,10,0,0,"jv");
          _SFD_SET_DATA_PROPS(4,10,0,0,"m1");
          _SFD_SET_DATA_PROPS(5,10,0,0,"j1");
          _SFD_SET_DATA_PROPS(6,10,0,0,"rv");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,398);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"quatrot",0,-1,191);
        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"skew_sm",0,-1,127);

        {
          unsigned int dimVector[1];
          dimVector[0]= 7;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c19_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 6;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c19_sf_marshallOut,(MexInFcnForType)
            c19_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_c_sf_marshallOut,(MexInFcnForType)
          c19_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_c_sf_marshallOut,(MexInFcnForType)
          c19_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_c_sf_marshallOut,(MexInFcnForType)
          c19_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_c_sf_marshallOut,(MexInFcnForType)
          c19_c_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c19_b_sf_marshallOut,(MexInFcnForType)
            c19_b_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c19_x);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c19_M);
        _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c19_mv);
        _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c19_jv);
        _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c19_m1);
        _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c19_j1);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c19_rv);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _DIPCMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "tiZ8MYTkWJes7W5zPmPS";
}

static void sf_opaque_initialize_c19_DIPC(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc19_DIPCInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c19_DIPC((SFc19_DIPCInstanceStruct*) chartInstanceVar);
  initialize_c19_DIPC((SFc19_DIPCInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c19_DIPC(void *chartInstanceVar)
{
  enable_c19_DIPC((SFc19_DIPCInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c19_DIPC(void *chartInstanceVar)
{
  disable_c19_DIPC((SFc19_DIPCInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c19_DIPC(void *chartInstanceVar)
{
  sf_gateway_c19_DIPC((SFc19_DIPCInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c19_DIPC(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c19_DIPC((SFc19_DIPCInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c19_DIPC(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c19_DIPC((SFc19_DIPCInstanceStruct*)chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c19_DIPC(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc19_DIPCInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DIPC_optimization_info();
    }

    finalize_c19_DIPC((SFc19_DIPCInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc19_DIPC((SFc19_DIPCInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c19_DIPC(SimStruct *S)
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
    initialize_params_c19_DIPC((SFc19_DIPCInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c19_DIPC(SimStruct *S)
{
  /* Actual parameters from chart:
     j1 jv m1 mv rv
   */
  const char_T *rtParamNames[] = { "j1", "jv", "m1", "mv", "rv" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for j1*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for jv*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for m1*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);

  /* registration for mv*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_DOUBLE);

  /* registration for rv*/
  ssRegDlgParamAsRunTimeParam(S, 4, 4, rtParamNames[4], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DIPC_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      19);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,19,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,19,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,19);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,19,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,19,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,19);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3819334779U));
  ssSetChecksum1(S,(153892307U));
  ssSetChecksum2(S,(1936012047U));
  ssSetChecksum3(S,(3489681054U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c19_DIPC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c19_DIPC(SimStruct *S)
{
  SFc19_DIPCInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc19_DIPCInstanceStruct *)utMalloc(sizeof
    (SFc19_DIPCInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc19_DIPCInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c19_DIPC;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c19_DIPC;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c19_DIPC;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c19_DIPC;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c19_DIPC;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c19_DIPC;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c19_DIPC;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c19_DIPC;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c19_DIPC;
  chartInstance->chartInfo.mdlStart = mdlStart_c19_DIPC;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c19_DIPC;
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

void c19_DIPC_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c19_DIPC(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c19_DIPC(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c19_DIPC(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c19_DIPC_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

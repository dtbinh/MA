/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DePascali4M_sfun.h"
#include "c22_DePascali4M.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DePascali4M_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c22_debug_family_names[6] = { "nargin", "nargout", "p_do",
  "q_do", "r", "x_d" };

static const char * c22_b_debug_family_names[6] = { "rwq", "nargin", "nargout",
  "q", "r", "rw" };

/* Function Declarations */
static void initialize_c22_DePascali4M(SFc22_DePascali4MInstanceStruct
  *chartInstance);
static void initialize_params_c22_DePascali4M(SFc22_DePascali4MInstanceStruct
  *chartInstance);
static void enable_c22_DePascali4M(SFc22_DePascali4MInstanceStruct
  *chartInstance);
static void disable_c22_DePascali4M(SFc22_DePascali4MInstanceStruct
  *chartInstance);
static void c22_update_debugger_state_c22_DePascali4M
  (SFc22_DePascali4MInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c22_DePascali4M
  (SFc22_DePascali4MInstanceStruct *chartInstance);
static void set_sim_state_c22_DePascali4M(SFc22_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c22_st);
static void finalize_c22_DePascali4M(SFc22_DePascali4MInstanceStruct
  *chartInstance);
static void sf_gateway_c22_DePascali4M(SFc22_DePascali4MInstanceStruct
  *chartInstance);
static void mdl_start_c22_DePascali4M(SFc22_DePascali4MInstanceStruct
  *chartInstance);
static void initSimStructsc22_DePascali4M(SFc22_DePascali4MInstanceStruct
  *chartInstance);
static void c22_quatrot(SFc22_DePascali4MInstanceStruct *chartInstance, real_T
  c22_q[4], real_T c22_b_r[3], real_T c22_rw[3]);
static void init_script_number_translation(uint32_T c22_machineNumber, uint32_T
  c22_chartNumber, uint32_T c22_instanceNumber);
static const mxArray *c22_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static void c22_emlrt_marshallIn(SFc22_DePascali4MInstanceStruct *chartInstance,
  const mxArray *c22_b_x_d, const char_T *c22_identifier, real_T c22_y[28]);
static void c22_b_emlrt_marshallIn(SFc22_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId,
  real_T c22_y[28]);
static void c22_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static const mxArray *c22_b_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static void c22_c_emlrt_marshallIn(SFc22_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId,
  real_T c22_y[12]);
static void c22_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static const mxArray *c22_c_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static const mxArray *c22_d_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static const mxArray *c22_e_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static real_T c22_d_emlrt_marshallIn(SFc22_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId);
static void c22_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static void c22_e_emlrt_marshallIn(SFc22_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId,
  real_T c22_y[3]);
static void c22_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static void c22_f_emlrt_marshallIn(SFc22_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId,
  real_T c22_y[4]);
static void c22_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static void c22_info_helper(const mxArray **c22_info);
static const mxArray *c22_emlrt_marshallOut(const char * c22_u);
static const mxArray *c22_b_emlrt_marshallOut(const uint32_T c22_u);
static void c22_quatmultiply(SFc22_DePascali4MInstanceStruct *chartInstance,
  real_T c22_q[4], real_T c22_b_r[4], real_T c22_qout[4]);
static const mxArray *c22_f_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static int32_T c22_g_emlrt_marshallIn(SFc22_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId);
static void c22_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static uint8_T c22_h_emlrt_marshallIn(SFc22_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c22_b_is_active_c22_DePascali4M, const char_T
  *c22_identifier);
static uint8_T c22_i_emlrt_marshallIn(SFc22_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId);
static void init_dsm_address_info(SFc22_DePascali4MInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc22_DePascali4MInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c22_DePascali4M(SFc22_DePascali4MInstanceStruct
  *chartInstance)
{
  chartInstance->c22_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c22_is_active_c22_DePascali4M = 0U;
}

static void initialize_params_c22_DePascali4M(SFc22_DePascali4MInstanceStruct
  *chartInstance)
{
  real_T c22_dv0[12];
  int32_T c22_i0;
  sf_mex_import_named("r", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      c22_dv0, 0, 0, 0U, 1, 0U, 1, 12);
  for (c22_i0 = 0; c22_i0 < 12; c22_i0++) {
    chartInstance->c22_r[c22_i0] = c22_dv0[c22_i0];
  }
}

static void enable_c22_DePascali4M(SFc22_DePascali4MInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c22_DePascali4M(SFc22_DePascali4MInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c22_update_debugger_state_c22_DePascali4M
  (SFc22_DePascali4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c22_DePascali4M
  (SFc22_DePascali4MInstanceStruct *chartInstance)
{
  const mxArray *c22_st;
  const mxArray *c22_y = NULL;
  int32_T c22_i1;
  real_T c22_u[28];
  const mxArray *c22_b_y = NULL;
  uint8_T c22_hoistedGlobal;
  uint8_T c22_b_u;
  const mxArray *c22_c_y = NULL;
  c22_st = NULL;
  c22_st = NULL;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_createcellmatrix(2, 1), false);
  for (c22_i1 = 0; c22_i1 < 28; c22_i1++) {
    c22_u[c22_i1] = (*chartInstance->c22_x_d)[c22_i1];
  }

  c22_b_y = NULL;
  sf_mex_assign(&c22_b_y, sf_mex_create("y", c22_u, 0, 0U, 1U, 0U, 1, 28), false);
  sf_mex_setcell(c22_y, 0, c22_b_y);
  c22_hoistedGlobal = chartInstance->c22_is_active_c22_DePascali4M;
  c22_b_u = c22_hoistedGlobal;
  c22_c_y = NULL;
  sf_mex_assign(&c22_c_y, sf_mex_create("y", &c22_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c22_y, 1, c22_c_y);
  sf_mex_assign(&c22_st, c22_y, false);
  return c22_st;
}

static void set_sim_state_c22_DePascali4M(SFc22_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c22_st)
{
  const mxArray *c22_u;
  real_T c22_dv1[28];
  int32_T c22_i2;
  chartInstance->c22_doneDoubleBufferReInit = true;
  c22_u = sf_mex_dup(c22_st);
  c22_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c22_u, 0)),
                       "x_d", c22_dv1);
  for (c22_i2 = 0; c22_i2 < 28; c22_i2++) {
    (*chartInstance->c22_x_d)[c22_i2] = c22_dv1[c22_i2];
  }

  chartInstance->c22_is_active_c22_DePascali4M = c22_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c22_u, 1)),
     "is_active_c22_DePascali4M");
  sf_mex_destroy(&c22_u);
  c22_update_debugger_state_c22_DePascali4M(chartInstance);
  sf_mex_destroy(&c22_st);
}

static void finalize_c22_DePascali4M(SFc22_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c22_DePascali4M(SFc22_DePascali4MInstanceStruct
  *chartInstance)
{
  int32_T c22_i3;
  int32_T c22_i4;
  int32_T c22_i5;
  real_T c22_b_p_do[3];
  int32_T c22_i6;
  real_T c22_b_q_do[4];
  int32_T c22_i7;
  real_T c22_b_r[12];
  uint32_T c22_debug_family_var_map[6];
  real_T c22_nargin = 3.0;
  real_T c22_nargout = 1.0;
  real_T c22_b_x_d[28];
  int32_T c22_i8;
  real_T c22_c_q_do[4];
  int32_T c22_i9;
  real_T c22_c_r[3];
  real_T c22_dv2[3];
  int32_T c22_i10;
  real_T c22_d_q_do[4];
  int32_T c22_i11;
  real_T c22_d_r[3];
  real_T c22_dv3[3];
  int32_T c22_i12;
  real_T c22_e_q_do[4];
  int32_T c22_i13;
  real_T c22_e_r[3];
  real_T c22_dv4[3];
  int32_T c22_i14;
  real_T c22_f_q_do[4];
  int32_T c22_i15;
  real_T c22_f_r[3];
  real_T c22_dv5[3];
  int32_T c22_i16;
  int32_T c22_i17;
  int32_T c22_i18;
  int32_T c22_i19;
  int32_T c22_i20;
  int32_T c22_i21;
  int32_T c22_i22;
  int32_T c22_i23;
  int32_T c22_i24;
  int32_T c22_i25;
  int32_T c22_i26;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c22_sfEvent);
  for (c22_i3 = 0; c22_i3 < 3; c22_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c22_p_do)[c22_i3], 0U);
  }

  for (c22_i4 = 0; c22_i4 < 4; c22_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c22_q_do)[c22_i4], 1U);
  }

  chartInstance->c22_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c22_sfEvent);
  for (c22_i5 = 0; c22_i5 < 3; c22_i5++) {
    c22_b_p_do[c22_i5] = (*chartInstance->c22_p_do)[c22_i5];
  }

  for (c22_i6 = 0; c22_i6 < 4; c22_i6++) {
    c22_b_q_do[c22_i6] = (*chartInstance->c22_q_do)[c22_i6];
  }

  for (c22_i7 = 0; c22_i7 < 12; c22_i7++) {
    c22_b_r[c22_i7] = chartInstance->c22_r[c22_i7];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c22_debug_family_names,
    c22_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_nargin, 0U, c22_e_sf_marshallOut,
    c22_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_nargout, 1U, c22_e_sf_marshallOut,
    c22_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c22_b_p_do, 2U, c22_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c22_b_q_do, 3U, c22_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c22_b_r, 4U, c22_b_sf_marshallOut,
    c22_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c22_b_x_d, 5U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 3);
  for (c22_i8 = 0; c22_i8 < 4; c22_i8++) {
    c22_c_q_do[c22_i8] = c22_b_q_do[c22_i8];
  }

  for (c22_i9 = 0; c22_i9 < 3; c22_i9++) {
    c22_c_r[c22_i9] = c22_b_r[c22_i9];
  }

  c22_quatrot(chartInstance, c22_c_q_do, c22_c_r, c22_dv2);
  for (c22_i10 = 0; c22_i10 < 4; c22_i10++) {
    c22_d_q_do[c22_i10] = c22_b_q_do[c22_i10];
  }

  for (c22_i11 = 0; c22_i11 < 3; c22_i11++) {
    c22_d_r[c22_i11] = c22_b_r[c22_i11 + 3];
  }

  c22_quatrot(chartInstance, c22_d_q_do, c22_d_r, c22_dv3);
  for (c22_i12 = 0; c22_i12 < 4; c22_i12++) {
    c22_e_q_do[c22_i12] = c22_b_q_do[c22_i12];
  }

  for (c22_i13 = 0; c22_i13 < 3; c22_i13++) {
    c22_e_r[c22_i13] = c22_b_r[c22_i13 + 6];
  }

  c22_quatrot(chartInstance, c22_e_q_do, c22_e_r, c22_dv4);
  for (c22_i14 = 0; c22_i14 < 4; c22_i14++) {
    c22_f_q_do[c22_i14] = c22_b_q_do[c22_i14];
  }

  for (c22_i15 = 0; c22_i15 < 3; c22_i15++) {
    c22_f_r[c22_i15] = c22_b_r[c22_i15 + 9];
  }

  c22_quatrot(chartInstance, c22_f_q_do, c22_f_r, c22_dv5);
  for (c22_i16 = 0; c22_i16 < 3; c22_i16++) {
    c22_b_x_d[c22_i16] = c22_b_p_do[c22_i16] + c22_dv2[c22_i16];
  }

  for (c22_i17 = 0; c22_i17 < 4; c22_i17++) {
    c22_b_x_d[c22_i17 + 3] = c22_b_q_do[c22_i17];
  }

  for (c22_i18 = 0; c22_i18 < 3; c22_i18++) {
    c22_b_x_d[c22_i18 + 7] = c22_b_p_do[c22_i18] + c22_dv3[c22_i18];
  }

  for (c22_i19 = 0; c22_i19 < 4; c22_i19++) {
    c22_b_x_d[c22_i19 + 10] = c22_b_q_do[c22_i19];
  }

  for (c22_i20 = 0; c22_i20 < 3; c22_i20++) {
    c22_b_x_d[c22_i20 + 14] = c22_b_p_do[c22_i20] + c22_dv4[c22_i20];
  }

  for (c22_i21 = 0; c22_i21 < 4; c22_i21++) {
    c22_b_x_d[c22_i21 + 17] = c22_b_q_do[c22_i21];
  }

  for (c22_i22 = 0; c22_i22 < 3; c22_i22++) {
    c22_b_x_d[c22_i22 + 21] = c22_b_p_do[c22_i22] + c22_dv5[c22_i22];
  }

  for (c22_i23 = 0; c22_i23 < 4; c22_i23++) {
    c22_b_x_d[c22_i23 + 24] = c22_b_q_do[c22_i23];
  }

  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c22_i24 = 0; c22_i24 < 28; c22_i24++) {
    (*chartInstance->c22_x_d)[c22_i24] = c22_b_x_d[c22_i24];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c22_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DePascali4MMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c22_i25 = 0; c22_i25 < 28; c22_i25++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c22_x_d)[c22_i25], 2U);
  }

  for (c22_i26 = 0; c22_i26 < 12; c22_i26++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c22_r[c22_i26], 3U);
  }
}

static void mdl_start_c22_DePascali4M(SFc22_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc22_DePascali4M(SFc22_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c22_quatrot(SFc22_DePascali4MInstanceStruct *chartInstance, real_T
  c22_q[4], real_T c22_b_r[3], real_T c22_rw[3])
{
  uint32_T c22_debug_family_var_map[6];
  real_T c22_rwq[4];
  real_T c22_nargin = 2.0;
  real_T c22_nargout = 1.0;
  int32_T c22_i27;
  real_T c22_b_q[4];
  int32_T c22_k;
  real_T c22_b_k;
  real_T c22_dv6[4];
  int32_T c22_i28;
  int32_T c22_i29;
  real_T c22_c_q[4];
  real_T c22_dv7[4];
  int32_T c22_i30;
  real_T c22_d_q[4];
  int32_T c22_i31;
  real_T c22_dv8[4];
  int32_T c22_i32;
  int32_T c22_i33;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c22_b_debug_family_names,
    c22_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c22_rwq, 0U, c22_c_sf_marshallOut,
    c22_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_nargin, 1U, c22_e_sf_marshallOut,
    c22_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_nargout, 2U, c22_e_sf_marshallOut,
    c22_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c22_q, 3U, c22_c_sf_marshallOut,
    c22_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c22_b_r, 4U, c22_d_sf_marshallOut,
    c22_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c22_rw, 5U, c22_d_sf_marshallOut,
    c22_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c22_sfEvent, 4);
  for (c22_i27 = 0; c22_i27 < 4; c22_i27++) {
    c22_b_q[c22_i27] = c22_q[c22_i27];
  }

  for (c22_k = 0; c22_k < 3; c22_k++) {
    c22_b_k = 2.0 + (real_T)c22_k;
    c22_b_q[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c22_b_k), 1, 4, 1, 0) - 1] = -c22_b_q[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", c22_b_k), 1, 4, 1, 0) - 1];
  }

  c22_dv6[0] = 0.0;
  for (c22_i28 = 0; c22_i28 < 3; c22_i28++) {
    c22_dv6[c22_i28 + 1] = c22_b_r[c22_i28];
  }

  for (c22_i29 = 0; c22_i29 < 4; c22_i29++) {
    c22_c_q[c22_i29] = c22_b_q[c22_i29];
  }

  c22_quatmultiply(chartInstance, c22_dv6, c22_c_q, c22_dv7);
  for (c22_i30 = 0; c22_i30 < 4; c22_i30++) {
    c22_d_q[c22_i30] = c22_q[c22_i30];
  }

  for (c22_i31 = 0; c22_i31 < 4; c22_i31++) {
    c22_dv8[c22_i31] = c22_dv7[c22_i31];
  }

  c22_quatmultiply(chartInstance, c22_d_q, c22_dv8, c22_b_q);
  for (c22_i32 = 0; c22_i32 < 4; c22_i32++) {
    c22_rwq[c22_i32] = c22_b_q[c22_i32];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c22_sfEvent, 5);
  for (c22_i33 = 0; c22_i33 < 3; c22_i33++) {
    c22_rw[c22_i33] = c22_rwq[c22_i33 + 1];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c22_sfEvent, -5);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c22_machineNumber, uint32_T
  c22_chartNumber, uint32_T c22_instanceNumber)
{
  (void)c22_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c22_chartNumber, c22_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Martin\\Documents\\Git\\Simulink\\DIPC - constrained\\quatrot.m"));
}

static const mxArray *c22_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  int32_T c22_i34;
  real_T c22_b_inData[28];
  int32_T c22_i35;
  real_T c22_u[28];
  const mxArray *c22_y = NULL;
  SFc22_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc22_DePascali4MInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  for (c22_i34 = 0; c22_i34 < 28; c22_i34++) {
    c22_b_inData[c22_i34] = (*(real_T (*)[28])c22_inData)[c22_i34];
  }

  for (c22_i35 = 0; c22_i35 < 28; c22_i35++) {
    c22_u[c22_i35] = c22_b_inData[c22_i35];
  }

  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", c22_u, 0, 0U, 1U, 0U, 1, 28), false);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, false);
  return c22_mxArrayOutData;
}

static void c22_emlrt_marshallIn(SFc22_DePascali4MInstanceStruct *chartInstance,
  const mxArray *c22_b_x_d, const char_T *c22_identifier, real_T c22_y[28])
{
  emlrtMsgIdentifier c22_thisId;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_b_x_d), &c22_thisId,
    c22_y);
  sf_mex_destroy(&c22_b_x_d);
}

static void c22_b_emlrt_marshallIn(SFc22_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId,
  real_T c22_y[28])
{
  real_T c22_dv9[28];
  int32_T c22_i36;
  (void)chartInstance;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), c22_dv9, 1, 0, 0U, 1, 0U, 1, 28);
  for (c22_i36 = 0; c22_i36 < 28; c22_i36++) {
    c22_y[c22_i36] = c22_dv9[c22_i36];
  }

  sf_mex_destroy(&c22_u);
}

static void c22_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_b_x_d;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  real_T c22_y[28];
  int32_T c22_i37;
  SFc22_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc22_DePascali4MInstanceStruct *)chartInstanceVoid;
  c22_b_x_d = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_b_x_d), &c22_thisId,
    c22_y);
  sf_mex_destroy(&c22_b_x_d);
  for (c22_i37 = 0; c22_i37 < 28; c22_i37++) {
    (*(real_T (*)[28])c22_outData)[c22_i37] = c22_y[c22_i37];
  }

  sf_mex_destroy(&c22_mxArrayInData);
}

static const mxArray *c22_b_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  int32_T c22_i38;
  real_T c22_b_inData[12];
  int32_T c22_i39;
  real_T c22_u[12];
  const mxArray *c22_y = NULL;
  SFc22_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc22_DePascali4MInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  for (c22_i38 = 0; c22_i38 < 12; c22_i38++) {
    c22_b_inData[c22_i38] = (*(real_T (*)[12])c22_inData)[c22_i38];
  }

  for (c22_i39 = 0; c22_i39 < 12; c22_i39++) {
    c22_u[c22_i39] = c22_b_inData[c22_i39];
  }

  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", c22_u, 0, 0U, 1U, 0U, 1, 12), false);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, false);
  return c22_mxArrayOutData;
}

static void c22_c_emlrt_marshallIn(SFc22_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId,
  real_T c22_y[12])
{
  real_T c22_dv10[12];
  int32_T c22_i40;
  (void)chartInstance;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), c22_dv10, 1, 0, 0U, 1, 0U, 1,
                12);
  for (c22_i40 = 0; c22_i40 < 12; c22_i40++) {
    c22_y[c22_i40] = c22_dv10[c22_i40];
  }

  sf_mex_destroy(&c22_u);
}

static void c22_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_b_r;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  real_T c22_y[12];
  int32_T c22_i41;
  SFc22_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc22_DePascali4MInstanceStruct *)chartInstanceVoid;
  c22_b_r = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_b_r), &c22_thisId, c22_y);
  sf_mex_destroy(&c22_b_r);
  for (c22_i41 = 0; c22_i41 < 12; c22_i41++) {
    (*(real_T (*)[12])c22_outData)[c22_i41] = c22_y[c22_i41];
  }

  sf_mex_destroy(&c22_mxArrayInData);
}

static const mxArray *c22_c_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  int32_T c22_i42;
  real_T c22_b_inData[4];
  int32_T c22_i43;
  real_T c22_u[4];
  const mxArray *c22_y = NULL;
  SFc22_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc22_DePascali4MInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  for (c22_i42 = 0; c22_i42 < 4; c22_i42++) {
    c22_b_inData[c22_i42] = (*(real_T (*)[4])c22_inData)[c22_i42];
  }

  for (c22_i43 = 0; c22_i43 < 4; c22_i43++) {
    c22_u[c22_i43] = c22_b_inData[c22_i43];
  }

  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", c22_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, false);
  return c22_mxArrayOutData;
}

static const mxArray *c22_d_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  int32_T c22_i44;
  real_T c22_b_inData[3];
  int32_T c22_i45;
  real_T c22_u[3];
  const mxArray *c22_y = NULL;
  SFc22_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc22_DePascali4MInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  for (c22_i44 = 0; c22_i44 < 3; c22_i44++) {
    c22_b_inData[c22_i44] = (*(real_T (*)[3])c22_inData)[c22_i44];
  }

  for (c22_i45 = 0; c22_i45 < 3; c22_i45++) {
    c22_u[c22_i45] = c22_b_inData[c22_i45];
  }

  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", c22_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, false);
  return c22_mxArrayOutData;
}

static const mxArray *c22_e_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  real_T c22_u;
  const mxArray *c22_y = NULL;
  SFc22_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc22_DePascali4MInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  c22_u = *(real_T *)c22_inData;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", &c22_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, false);
  return c22_mxArrayOutData;
}

static real_T c22_d_emlrt_marshallIn(SFc22_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId)
{
  real_T c22_y;
  real_T c22_d0;
  (void)chartInstance;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), &c22_d0, 1, 0, 0U, 0, 0U, 0);
  c22_y = c22_d0;
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static void c22_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_nargout;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  real_T c22_y;
  SFc22_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc22_DePascali4MInstanceStruct *)chartInstanceVoid;
  c22_nargout = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_nargout),
    &c22_thisId);
  sf_mex_destroy(&c22_nargout);
  *(real_T *)c22_outData = c22_y;
  sf_mex_destroy(&c22_mxArrayInData);
}

static void c22_e_emlrt_marshallIn(SFc22_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId,
  real_T c22_y[3])
{
  real_T c22_dv11[3];
  int32_T c22_i46;
  (void)chartInstance;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), c22_dv11, 1, 0, 0U, 1, 0U, 1, 3);
  for (c22_i46 = 0; c22_i46 < 3; c22_i46++) {
    c22_y[c22_i46] = c22_dv11[c22_i46];
  }

  sf_mex_destroy(&c22_u);
}

static void c22_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_rw;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  real_T c22_y[3];
  int32_T c22_i47;
  SFc22_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc22_DePascali4MInstanceStruct *)chartInstanceVoid;
  c22_rw = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_rw), &c22_thisId, c22_y);
  sf_mex_destroy(&c22_rw);
  for (c22_i47 = 0; c22_i47 < 3; c22_i47++) {
    (*(real_T (*)[3])c22_outData)[c22_i47] = c22_y[c22_i47];
  }

  sf_mex_destroy(&c22_mxArrayInData);
}

static void c22_f_emlrt_marshallIn(SFc22_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId,
  real_T c22_y[4])
{
  real_T c22_dv12[4];
  int32_T c22_i48;
  (void)chartInstance;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), c22_dv12, 1, 0, 0U, 1, 0U, 1, 4);
  for (c22_i48 = 0; c22_i48 < 4; c22_i48++) {
    c22_y[c22_i48] = c22_dv12[c22_i48];
  }

  sf_mex_destroy(&c22_u);
}

static void c22_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_q;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  real_T c22_y[4];
  int32_T c22_i49;
  SFc22_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc22_DePascali4MInstanceStruct *)chartInstanceVoid;
  c22_q = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_q), &c22_thisId, c22_y);
  sf_mex_destroy(&c22_q);
  for (c22_i49 = 0; c22_i49 < 4; c22_i49++) {
    (*(real_T (*)[4])c22_outData)[c22_i49] = c22_y[c22_i49];
  }

  sf_mex_destroy(&c22_mxArrayInData);
}

const mxArray *sf_c22_DePascali4M_get_eml_resolved_functions_info(void)
{
  const mxArray *c22_nameCaptureInfo = NULL;
  c22_nameCaptureInfo = NULL;
  sf_mex_assign(&c22_nameCaptureInfo, sf_mex_createstruct("structure", 2, 12, 1),
                false);
  c22_info_helper(&c22_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c22_nameCaptureInfo);
  return c22_nameCaptureInfo;
}

static void c22_info_helper(const mxArray **c22_info)
{
  const mxArray *c22_rhs0 = NULL;
  const mxArray *c22_lhs0 = NULL;
  const mxArray *c22_rhs1 = NULL;
  const mxArray *c22_lhs1 = NULL;
  const mxArray *c22_rhs2 = NULL;
  const mxArray *c22_lhs2 = NULL;
  const mxArray *c22_rhs3 = NULL;
  const mxArray *c22_lhs3 = NULL;
  const mxArray *c22_rhs4 = NULL;
  const mxArray *c22_lhs4 = NULL;
  const mxArray *c22_rhs5 = NULL;
  const mxArray *c22_lhs5 = NULL;
  const mxArray *c22_rhs6 = NULL;
  const mxArray *c22_lhs6 = NULL;
  const mxArray *c22_rhs7 = NULL;
  const mxArray *c22_lhs7 = NULL;
  const mxArray *c22_rhs8 = NULL;
  const mxArray *c22_lhs8 = NULL;
  const mxArray *c22_rhs9 = NULL;
  const mxArray *c22_lhs9 = NULL;
  const mxArray *c22_rhs10 = NULL;
  const mxArray *c22_lhs10 = NULL;
  const mxArray *c22_rhs11 = NULL;
  const mxArray *c22_lhs11 = NULL;
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("quatrot"), "name", "name", 0);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DIPC - constrained/quatrot.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1446631716U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c22_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DIPC - constrained/quatrot.m"),
                  "context", "context", 1);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("quatconj"), "name", "name",
                  1);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatconj.p"), "resolved", "resolved",
                  1);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1410808258U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c22_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DIPC - constrained/quatrot.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("quatmultiply"), "name",
                  "name", 2);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatmultiply.p"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1410808258U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c22_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatmultiply.p"), "context",
                  "context", 3);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("max"), "name", "name", 3);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1311280516U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c22_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 4);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1378321184U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c22_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 5);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 5);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c22_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 6);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c22_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 7);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 7);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c22_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 8);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c22_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 9);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 9);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c22_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 10);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 10);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c22_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 11);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 11);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c22_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs11), "lhs", "lhs",
                  11);
  sf_mex_destroy(&c22_rhs0);
  sf_mex_destroy(&c22_lhs0);
  sf_mex_destroy(&c22_rhs1);
  sf_mex_destroy(&c22_lhs1);
  sf_mex_destroy(&c22_rhs2);
  sf_mex_destroy(&c22_lhs2);
  sf_mex_destroy(&c22_rhs3);
  sf_mex_destroy(&c22_lhs3);
  sf_mex_destroy(&c22_rhs4);
  sf_mex_destroy(&c22_lhs4);
  sf_mex_destroy(&c22_rhs5);
  sf_mex_destroy(&c22_lhs5);
  sf_mex_destroy(&c22_rhs6);
  sf_mex_destroy(&c22_lhs6);
  sf_mex_destroy(&c22_rhs7);
  sf_mex_destroy(&c22_lhs7);
  sf_mex_destroy(&c22_rhs8);
  sf_mex_destroy(&c22_lhs8);
  sf_mex_destroy(&c22_rhs9);
  sf_mex_destroy(&c22_lhs9);
  sf_mex_destroy(&c22_rhs10);
  sf_mex_destroy(&c22_lhs10);
  sf_mex_destroy(&c22_rhs11);
  sf_mex_destroy(&c22_lhs11);
}

static const mxArray *c22_emlrt_marshallOut(const char * c22_u)
{
  const mxArray *c22_y = NULL;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", c22_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c22_u)), false);
  return c22_y;
}

static const mxArray *c22_b_emlrt_marshallOut(const uint32_T c22_u)
{
  const mxArray *c22_y = NULL;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", &c22_u, 7, 0U, 0U, 0U, 0), false);
  return c22_y;
}

static void c22_quatmultiply(SFc22_DePascali4MInstanceStruct *chartInstance,
  real_T c22_q[4], real_T c22_b_r[4], real_T c22_qout[4])
{
  real_T c22_q1;
  real_T c22_q2;
  real_T c22_q3;
  real_T c22_q4;
  real_T c22_r1;
  real_T c22_r2;
  real_T c22_r3;
  real_T c22_r4;
  (void)chartInstance;
  c22_q1 = c22_q[0];
  c22_q2 = c22_q[1];
  c22_q3 = c22_q[2];
  c22_q4 = c22_q[3];
  c22_r1 = c22_b_r[0];
  c22_r2 = c22_b_r[1];
  c22_r3 = c22_b_r[2];
  c22_r4 = c22_b_r[3];
  c22_qout[0] = ((c22_q1 * c22_r1 - c22_q2 * c22_r2) - c22_q3 * c22_r3) - c22_q4
    * c22_r4;
  c22_qout[1] = (c22_q1 * c22_r2 + c22_r1 * c22_q2) + (c22_q3 * c22_r4 - c22_q4 *
    c22_r3);
  c22_qout[2] = (c22_q1 * c22_r3 + c22_r1 * c22_q3) + (c22_q4 * c22_r2 - c22_q2 *
    c22_r4);
  c22_qout[3] = (c22_q1 * c22_r4 + c22_r1 * c22_q4) + (c22_q2 * c22_r3 - c22_q3 *
    c22_r2);
}

static const mxArray *c22_f_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  int32_T c22_u;
  const mxArray *c22_y = NULL;
  SFc22_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc22_DePascali4MInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  c22_u = *(int32_T *)c22_inData;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", &c22_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, false);
  return c22_mxArrayOutData;
}

static int32_T c22_g_emlrt_marshallIn(SFc22_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId)
{
  int32_T c22_y;
  int32_T c22_i50;
  (void)chartInstance;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), &c22_i50, 1, 6, 0U, 0, 0U, 0);
  c22_y = c22_i50;
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static void c22_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_b_sfEvent;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  int32_T c22_y;
  SFc22_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc22_DePascali4MInstanceStruct *)chartInstanceVoid;
  c22_b_sfEvent = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_b_sfEvent),
    &c22_thisId);
  sf_mex_destroy(&c22_b_sfEvent);
  *(int32_T *)c22_outData = c22_y;
  sf_mex_destroy(&c22_mxArrayInData);
}

static uint8_T c22_h_emlrt_marshallIn(SFc22_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c22_b_is_active_c22_DePascali4M, const char_T
  *c22_identifier)
{
  uint8_T c22_y;
  emlrtMsgIdentifier c22_thisId;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c22_b_is_active_c22_DePascali4M), &c22_thisId);
  sf_mex_destroy(&c22_b_is_active_c22_DePascali4M);
  return c22_y;
}

static uint8_T c22_i_emlrt_marshallIn(SFc22_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId)
{
  uint8_T c22_y;
  uint8_T c22_u0;
  (void)chartInstance;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), &c22_u0, 1, 3, 0U, 0, 0U, 0);
  c22_y = c22_u0;
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static void init_dsm_address_info(SFc22_DePascali4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc22_DePascali4MInstanceStruct
  *chartInstance)
{
  chartInstance->c22_p_do = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c22_q_do = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c22_x_d = (real_T (*)[28])ssGetOutputPortSignal_wrapper
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

void sf_c22_DePascali4M_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(612581107U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(845730659U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2367879929U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1585542955U);
}

mxArray* sf_c22_DePascali4M_get_post_codegen_info(void);
mxArray *sf_c22_DePascali4M_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("j9maIqGCXDgdd4rsMwtlXF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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
      pr[0] = (double)(4);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(12);
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
      pr[0] = (double)(28);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c22_DePascali4M_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c22_DePascali4M_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c22_DePascali4M_jit_fallback_info(void)
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

mxArray *sf_c22_DePascali4M_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c22_DePascali4M_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c22_DePascali4M(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"x_d\",},{M[8],M[0],T\"is_active_c22_DePascali4M\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c22_DePascali4M_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc22_DePascali4MInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc22_DePascali4MInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DePascali4MMachineNumber_,
           22,
           1,
           1,
           0,
           4,
           0,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_DePascali4MMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_DePascali4MMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _DePascali4MMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"p_do");
          _SFD_SET_DATA_PROPS(1,1,1,0,"q_do");
          _SFD_SET_DATA_PROPS(2,2,0,1,"x_d");
          _SFD_SET_DATA_PROPS(3,10,0,0,"r");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,251);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"quatrot",0,-1,191);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c22_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c22_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 28;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c22_sf_marshallOut,(MexInFcnForType)
            c22_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c22_b_sf_marshallOut,(MexInFcnForType)
            c22_b_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c22_p_do);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c22_q_do);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c22_x_d);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c22_r);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _DePascali4MMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "DpTkc1bOHKC86DQmcFu5WB";
}

static void sf_opaque_initialize_c22_DePascali4M(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc22_DePascali4MInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c22_DePascali4M((SFc22_DePascali4MInstanceStruct*)
    chartInstanceVar);
  initialize_c22_DePascali4M((SFc22_DePascali4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c22_DePascali4M(void *chartInstanceVar)
{
  enable_c22_DePascali4M((SFc22_DePascali4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c22_DePascali4M(void *chartInstanceVar)
{
  disable_c22_DePascali4M((SFc22_DePascali4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c22_DePascali4M(void *chartInstanceVar)
{
  sf_gateway_c22_DePascali4M((SFc22_DePascali4MInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c22_DePascali4M(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c22_DePascali4M((SFc22_DePascali4MInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c22_DePascali4M(SimStruct* S, const mxArray *
  st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c22_DePascali4M((SFc22_DePascali4MInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c22_DePascali4M(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc22_DePascali4MInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DePascali4M_optimization_info();
    }

    finalize_c22_DePascali4M((SFc22_DePascali4MInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc22_DePascali4M((SFc22_DePascali4MInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c22_DePascali4M(SimStruct *S)
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
    initialize_params_c22_DePascali4M((SFc22_DePascali4MInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c22_DePascali4M(SimStruct *S)
{
  /* Actual parameters from chart:
     r
   */
  const char_T *rtParamNames[] = { "r" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for r*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DePascali4M_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      22);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,22,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,22,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,22);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,22,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,22,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,22);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1040815523U));
  ssSetChecksum1(S,(2344656572U));
  ssSetChecksum2(S,(1797676069U));
  ssSetChecksum3(S,(1093715503U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c22_DePascali4M(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c22_DePascali4M(SimStruct *S)
{
  SFc22_DePascali4MInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc22_DePascali4MInstanceStruct *)utMalloc(sizeof
    (SFc22_DePascali4MInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc22_DePascali4MInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c22_DePascali4M;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c22_DePascali4M;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c22_DePascali4M;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c22_DePascali4M;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c22_DePascali4M;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c22_DePascali4M;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c22_DePascali4M;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c22_DePascali4M;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c22_DePascali4M;
  chartInstance->chartInfo.mdlStart = mdlStart_c22_DePascali4M;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c22_DePascali4M;
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

void c22_DePascali4M_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c22_DePascali4M(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c22_DePascali4M(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c22_DePascali4M(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c22_DePascali4M_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
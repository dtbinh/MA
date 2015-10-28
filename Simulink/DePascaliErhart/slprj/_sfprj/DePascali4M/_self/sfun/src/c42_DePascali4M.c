/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DePascali4M_sfun.h"
#include "c42_DePascali4M.h"
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
static const char * c42_debug_family_names[13] = { "zwt1", "zwr1", "zwt2",
  "zwr2", "zwt3", "zwr3", "zwt4", "zwr4", "nargin", "nargout", "z", "x", "z_w" };

/* Function Declarations */
static void initialize_c42_DePascali4M(SFc42_DePascali4MInstanceStruct
  *chartInstance);
static void initialize_params_c42_DePascali4M(SFc42_DePascali4MInstanceStruct
  *chartInstance);
static void enable_c42_DePascali4M(SFc42_DePascali4MInstanceStruct
  *chartInstance);
static void disable_c42_DePascali4M(SFc42_DePascali4MInstanceStruct
  *chartInstance);
static void c42_update_debugger_state_c42_DePascali4M
  (SFc42_DePascali4MInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c42_DePascali4M
  (SFc42_DePascali4MInstanceStruct *chartInstance);
static void set_sim_state_c42_DePascali4M(SFc42_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c42_st);
static void finalize_c42_DePascali4M(SFc42_DePascali4MInstanceStruct
  *chartInstance);
static void sf_gateway_c42_DePascali4M(SFc42_DePascali4MInstanceStruct
  *chartInstance);
static void mdl_start_c42_DePascali4M(SFc42_DePascali4MInstanceStruct
  *chartInstance);
static void initSimStructsc42_DePascali4M(SFc42_DePascali4MInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c42_machineNumber, uint32_T
  c42_chartNumber, uint32_T c42_instanceNumber);
static const mxArray *c42_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData);
static void c42_emlrt_marshallIn(SFc42_DePascali4MInstanceStruct *chartInstance,
  const mxArray *c42_b_z_w, const char_T *c42_identifier, real_T c42_y[24]);
static void c42_b_emlrt_marshallIn(SFc42_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId,
  real_T c42_y[24]);
static void c42_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c42_mxArrayInData, const char_T *c42_varName, void *c42_outData);
static const mxArray *c42_b_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData);
static const mxArray *c42_c_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData);
static real_T c42_c_emlrt_marshallIn(SFc42_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId);
static void c42_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c42_mxArrayInData, const char_T *c42_varName, void *c42_outData);
static const mxArray *c42_d_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData);
static void c42_d_emlrt_marshallIn(SFc42_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId,
  real_T c42_y[4]);
static void c42_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c42_mxArrayInData, const char_T *c42_varName, void *c42_outData);
static void c42_info_helper(const mxArray **c42_info);
static const mxArray *c42_emlrt_marshallOut(const char * c42_u);
static const mxArray *c42_b_emlrt_marshallOut(const uint32_T c42_u);
static void c42_quatmultiply(SFc42_DePascali4MInstanceStruct *chartInstance,
  real_T c42_q[4], real_T c42_r[4], real_T c42_qout[4]);
static const mxArray *c42_e_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData);
static int32_T c42_e_emlrt_marshallIn(SFc42_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId);
static void c42_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c42_mxArrayInData, const char_T *c42_varName, void *c42_outData);
static uint8_T c42_f_emlrt_marshallIn(SFc42_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c42_b_is_active_c42_DePascali4M, const char_T
  *c42_identifier);
static uint8_T c42_g_emlrt_marshallIn(SFc42_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId);
static void init_dsm_address_info(SFc42_DePascali4MInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc42_DePascali4MInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c42_DePascali4M(SFc42_DePascali4MInstanceStruct
  *chartInstance)
{
  chartInstance->c42_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c42_is_active_c42_DePascali4M = 0U;
}

static void initialize_params_c42_DePascali4M(SFc42_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c42_DePascali4M(SFc42_DePascali4MInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c42_DePascali4M(SFc42_DePascali4MInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c42_update_debugger_state_c42_DePascali4M
  (SFc42_DePascali4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c42_DePascali4M
  (SFc42_DePascali4MInstanceStruct *chartInstance)
{
  const mxArray *c42_st;
  const mxArray *c42_y = NULL;
  int32_T c42_i0;
  real_T c42_u[24];
  const mxArray *c42_b_y = NULL;
  uint8_T c42_hoistedGlobal;
  uint8_T c42_b_u;
  const mxArray *c42_c_y = NULL;
  c42_st = NULL;
  c42_st = NULL;
  c42_y = NULL;
  sf_mex_assign(&c42_y, sf_mex_createcellmatrix(2, 1), false);
  for (c42_i0 = 0; c42_i0 < 24; c42_i0++) {
    c42_u[c42_i0] = (*chartInstance->c42_z_w)[c42_i0];
  }

  c42_b_y = NULL;
  sf_mex_assign(&c42_b_y, sf_mex_create("y", c42_u, 0, 0U, 1U, 0U, 1, 24), false);
  sf_mex_setcell(c42_y, 0, c42_b_y);
  c42_hoistedGlobal = chartInstance->c42_is_active_c42_DePascali4M;
  c42_b_u = c42_hoistedGlobal;
  c42_c_y = NULL;
  sf_mex_assign(&c42_c_y, sf_mex_create("y", &c42_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c42_y, 1, c42_c_y);
  sf_mex_assign(&c42_st, c42_y, false);
  return c42_st;
}

static void set_sim_state_c42_DePascali4M(SFc42_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c42_st)
{
  const mxArray *c42_u;
  real_T c42_dv0[24];
  int32_T c42_i1;
  chartInstance->c42_doneDoubleBufferReInit = true;
  c42_u = sf_mex_dup(c42_st);
  c42_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c42_u, 0)),
                       "z_w", c42_dv0);
  for (c42_i1 = 0; c42_i1 < 24; c42_i1++) {
    (*chartInstance->c42_z_w)[c42_i1] = c42_dv0[c42_i1];
  }

  chartInstance->c42_is_active_c42_DePascali4M = c42_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c42_u, 1)),
     "is_active_c42_DePascali4M");
  sf_mex_destroy(&c42_u);
  c42_update_debugger_state_c42_DePascali4M(chartInstance);
  sf_mex_destroy(&c42_st);
}

static void finalize_c42_DePascali4M(SFc42_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c42_DePascali4M(SFc42_DePascali4MInstanceStruct
  *chartInstance)
{
  int32_T c42_i2;
  int32_T c42_i3;
  int32_T c42_i4;
  real_T c42_b_z[24];
  int32_T c42_i5;
  real_T c42_b_x[28];
  uint32_T c42_debug_family_var_map[13];
  real_T c42_zwt1[4];
  real_T c42_zwr1[4];
  real_T c42_zwt2[4];
  real_T c42_zwr2[4];
  real_T c42_zwt3[4];
  real_T c42_zwr3[4];
  real_T c42_zwt4[4];
  real_T c42_zwr4[4];
  real_T c42_nargin = 2.0;
  real_T c42_nargout = 1.0;
  real_T c42_b_z_w[24];
  int32_T c42_i6;
  real_T c42_q[4];
  int32_T c42_k;
  real_T c42_b_k;
  real_T c42_dv1[4];
  int32_T c42_i7;
  int32_T c42_i8;
  real_T c42_b_q[4];
  real_T c42_dv2[4];
  int32_T c42_i9;
  real_T c42_c_x[4];
  int32_T c42_i10;
  real_T c42_dv3[4];
  int32_T c42_i11;
  int32_T c42_i12;
  int32_T c42_c_k;
  real_T c42_d_k;
  real_T c42_dv4[4];
  int32_T c42_i13;
  int32_T c42_i14;
  real_T c42_c_q[4];
  int32_T c42_i15;
  real_T c42_d_x[4];
  int32_T c42_i16;
  real_T c42_dv5[4];
  int32_T c42_i17;
  int32_T c42_i18;
  int32_T c42_e_k;
  real_T c42_f_k;
  real_T c42_dv6[4];
  int32_T c42_i19;
  int32_T c42_i20;
  real_T c42_d_q[4];
  int32_T c42_i21;
  real_T c42_e_x[4];
  int32_T c42_i22;
  real_T c42_dv7[4];
  int32_T c42_i23;
  int32_T c42_i24;
  int32_T c42_g_k;
  real_T c42_h_k;
  real_T c42_dv8[4];
  int32_T c42_i25;
  int32_T c42_i26;
  real_T c42_e_q[4];
  int32_T c42_i27;
  real_T c42_f_x[4];
  int32_T c42_i28;
  real_T c42_dv9[4];
  int32_T c42_i29;
  int32_T c42_i30;
  int32_T c42_i_k;
  real_T c42_j_k;
  real_T c42_dv10[4];
  int32_T c42_i31;
  int32_T c42_i32;
  real_T c42_f_q[4];
  int32_T c42_i33;
  real_T c42_g_x[4];
  int32_T c42_i34;
  real_T c42_dv11[4];
  int32_T c42_i35;
  int32_T c42_i36;
  int32_T c42_k_k;
  real_T c42_l_k;
  real_T c42_dv12[4];
  int32_T c42_i37;
  int32_T c42_i38;
  real_T c42_g_q[4];
  int32_T c42_i39;
  real_T c42_h_x[4];
  int32_T c42_i40;
  real_T c42_dv13[4];
  int32_T c42_i41;
  int32_T c42_i42;
  int32_T c42_m_k;
  real_T c42_n_k;
  real_T c42_dv14[4];
  int32_T c42_i43;
  int32_T c42_i44;
  real_T c42_h_q[4];
  int32_T c42_i45;
  real_T c42_i_x[4];
  int32_T c42_i46;
  real_T c42_dv15[4];
  int32_T c42_i47;
  int32_T c42_i48;
  int32_T c42_o_k;
  real_T c42_p_k;
  real_T c42_dv16[4];
  int32_T c42_i49;
  int32_T c42_i50;
  real_T c42_i_q[4];
  int32_T c42_i51;
  real_T c42_j_x[4];
  int32_T c42_i52;
  real_T c42_dv17[4];
  int32_T c42_i53;
  int32_T c42_i54;
  int32_T c42_i55;
  int32_T c42_i56;
  int32_T c42_i57;
  int32_T c42_i58;
  int32_T c42_i59;
  int32_T c42_i60;
  int32_T c42_i61;
  int32_T c42_i62;
  int32_T c42_i63;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 20U, chartInstance->c42_sfEvent);
  for (c42_i2 = 0; c42_i2 < 24; c42_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c42_z)[c42_i2], 0U);
  }

  for (c42_i3 = 0; c42_i3 < 28; c42_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c42_x)[c42_i3], 1U);
  }

  chartInstance->c42_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 20U, chartInstance->c42_sfEvent);
  for (c42_i4 = 0; c42_i4 < 24; c42_i4++) {
    c42_b_z[c42_i4] = (*chartInstance->c42_z)[c42_i4];
  }

  for (c42_i5 = 0; c42_i5 < 28; c42_i5++) {
    c42_b_x[c42_i5] = (*chartInstance->c42_x)[c42_i5];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c42_debug_family_names,
    c42_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c42_zwt1, 0U, c42_d_sf_marshallOut,
    c42_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c42_zwr1, 1U, c42_d_sf_marshallOut,
    c42_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c42_zwt2, 2U, c42_d_sf_marshallOut,
    c42_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c42_zwr2, 3U, c42_d_sf_marshallOut,
    c42_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c42_zwt3, 4U, c42_d_sf_marshallOut,
    c42_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c42_zwr3, 5U, c42_d_sf_marshallOut,
    c42_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c42_zwt4, 6U, c42_d_sf_marshallOut,
    c42_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c42_zwr4, 7U, c42_d_sf_marshallOut,
    c42_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c42_nargin, 8U, c42_c_sf_marshallOut,
    c42_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c42_nargout, 9U, c42_c_sf_marshallOut,
    c42_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c42_b_z, 10U, c42_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c42_b_x, 11U, c42_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c42_b_z_w, 12U, c42_sf_marshallOut,
    c42_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c42_sfEvent, 2);
  for (c42_i6 = 0; c42_i6 < 4; c42_i6++) {
    c42_q[c42_i6] = c42_b_x[c42_i6 + 3];
  }

  for (c42_k = 0; c42_k < 3; c42_k++) {
    c42_b_k = 2.0 + (real_T)c42_k;
    c42_q[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c42_b_k), 1, 4, 1, 0) - 1] = -c42_q[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", c42_b_k), 1, 4, 1, 0) - 1];
  }

  c42_dv1[0] = 0.0;
  for (c42_i7 = 0; c42_i7 < 3; c42_i7++) {
    c42_dv1[c42_i7 + 1] = c42_b_z[c42_i7];
  }

  for (c42_i8 = 0; c42_i8 < 4; c42_i8++) {
    c42_b_q[c42_i8] = c42_q[c42_i8];
  }

  c42_quatmultiply(chartInstance, c42_dv1, c42_b_q, c42_dv2);
  for (c42_i9 = 0; c42_i9 < 4; c42_i9++) {
    c42_c_x[c42_i9] = c42_b_x[c42_i9 + 3];
  }

  for (c42_i10 = 0; c42_i10 < 4; c42_i10++) {
    c42_dv3[c42_i10] = c42_dv2[c42_i10];
  }

  c42_quatmultiply(chartInstance, c42_c_x, c42_dv3, c42_q);
  for (c42_i11 = 0; c42_i11 < 4; c42_i11++) {
    c42_zwt1[c42_i11] = c42_q[c42_i11];
  }

  _SFD_EML_CALL(0U, chartInstance->c42_sfEvent, 3);
  for (c42_i12 = 0; c42_i12 < 4; c42_i12++) {
    c42_q[c42_i12] = c42_b_x[c42_i12 + 3];
  }

  for (c42_c_k = 0; c42_c_k < 3; c42_c_k++) {
    c42_d_k = 2.0 + (real_T)c42_c_k;
    c42_q[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c42_d_k), 1, 4, 1, 0) - 1] = -c42_q[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", c42_d_k), 1, 4, 1, 0) - 1];
  }

  c42_dv4[0] = 0.0;
  for (c42_i13 = 0; c42_i13 < 3; c42_i13++) {
    c42_dv4[c42_i13 + 1] = c42_b_z[c42_i13 + 3];
  }

  for (c42_i14 = 0; c42_i14 < 4; c42_i14++) {
    c42_c_q[c42_i14] = c42_q[c42_i14];
  }

  c42_quatmultiply(chartInstance, c42_dv4, c42_c_q, c42_dv2);
  for (c42_i15 = 0; c42_i15 < 4; c42_i15++) {
    c42_d_x[c42_i15] = c42_b_x[c42_i15 + 3];
  }

  for (c42_i16 = 0; c42_i16 < 4; c42_i16++) {
    c42_dv5[c42_i16] = c42_dv2[c42_i16];
  }

  c42_quatmultiply(chartInstance, c42_d_x, c42_dv5, c42_q);
  for (c42_i17 = 0; c42_i17 < 4; c42_i17++) {
    c42_zwr1[c42_i17] = c42_q[c42_i17];
  }

  _SFD_EML_CALL(0U, chartInstance->c42_sfEvent, 4);
  for (c42_i18 = 0; c42_i18 < 4; c42_i18++) {
    c42_q[c42_i18] = c42_b_x[c42_i18 + 3];
  }

  for (c42_e_k = 0; c42_e_k < 3; c42_e_k++) {
    c42_f_k = 2.0 + (real_T)c42_e_k;
    c42_q[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c42_f_k), 1, 4, 1, 0) - 1] = -c42_q[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", c42_f_k), 1, 4, 1, 0) - 1];
  }

  c42_dv6[0] = 0.0;
  for (c42_i19 = 0; c42_i19 < 3; c42_i19++) {
    c42_dv6[c42_i19 + 1] = c42_b_z[c42_i19 + 6];
  }

  for (c42_i20 = 0; c42_i20 < 4; c42_i20++) {
    c42_d_q[c42_i20] = c42_q[c42_i20];
  }

  c42_quatmultiply(chartInstance, c42_dv6, c42_d_q, c42_dv2);
  for (c42_i21 = 0; c42_i21 < 4; c42_i21++) {
    c42_e_x[c42_i21] = c42_b_x[c42_i21 + 3];
  }

  for (c42_i22 = 0; c42_i22 < 4; c42_i22++) {
    c42_dv7[c42_i22] = c42_dv2[c42_i22];
  }

  c42_quatmultiply(chartInstance, c42_e_x, c42_dv7, c42_q);
  for (c42_i23 = 0; c42_i23 < 4; c42_i23++) {
    c42_zwt2[c42_i23] = c42_q[c42_i23];
  }

  _SFD_EML_CALL(0U, chartInstance->c42_sfEvent, 5);
  for (c42_i24 = 0; c42_i24 < 4; c42_i24++) {
    c42_q[c42_i24] = c42_b_x[c42_i24 + 3];
  }

  for (c42_g_k = 0; c42_g_k < 3; c42_g_k++) {
    c42_h_k = 2.0 + (real_T)c42_g_k;
    c42_q[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c42_h_k), 1, 4, 1, 0) - 1] = -c42_q[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", c42_h_k), 1, 4, 1, 0) - 1];
  }

  c42_dv8[0] = 0.0;
  for (c42_i25 = 0; c42_i25 < 3; c42_i25++) {
    c42_dv8[c42_i25 + 1] = c42_b_z[c42_i25 + 9];
  }

  for (c42_i26 = 0; c42_i26 < 4; c42_i26++) {
    c42_e_q[c42_i26] = c42_q[c42_i26];
  }

  c42_quatmultiply(chartInstance, c42_dv8, c42_e_q, c42_dv2);
  for (c42_i27 = 0; c42_i27 < 4; c42_i27++) {
    c42_f_x[c42_i27] = c42_b_x[c42_i27 + 3];
  }

  for (c42_i28 = 0; c42_i28 < 4; c42_i28++) {
    c42_dv9[c42_i28] = c42_dv2[c42_i28];
  }

  c42_quatmultiply(chartInstance, c42_f_x, c42_dv9, c42_q);
  for (c42_i29 = 0; c42_i29 < 4; c42_i29++) {
    c42_zwr2[c42_i29] = c42_q[c42_i29];
  }

  _SFD_EML_CALL(0U, chartInstance->c42_sfEvent, 6);
  for (c42_i30 = 0; c42_i30 < 4; c42_i30++) {
    c42_q[c42_i30] = c42_b_x[c42_i30 + 3];
  }

  for (c42_i_k = 0; c42_i_k < 3; c42_i_k++) {
    c42_j_k = 2.0 + (real_T)c42_i_k;
    c42_q[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c42_j_k), 1, 4, 1, 0) - 1] = -c42_q[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", c42_j_k), 1, 4, 1, 0) - 1];
  }

  c42_dv10[0] = 0.0;
  for (c42_i31 = 0; c42_i31 < 3; c42_i31++) {
    c42_dv10[c42_i31 + 1] = c42_b_z[c42_i31 + 12];
  }

  for (c42_i32 = 0; c42_i32 < 4; c42_i32++) {
    c42_f_q[c42_i32] = c42_q[c42_i32];
  }

  c42_quatmultiply(chartInstance, c42_dv10, c42_f_q, c42_dv2);
  for (c42_i33 = 0; c42_i33 < 4; c42_i33++) {
    c42_g_x[c42_i33] = c42_b_x[c42_i33 + 3];
  }

  for (c42_i34 = 0; c42_i34 < 4; c42_i34++) {
    c42_dv11[c42_i34] = c42_dv2[c42_i34];
  }

  c42_quatmultiply(chartInstance, c42_g_x, c42_dv11, c42_q);
  for (c42_i35 = 0; c42_i35 < 4; c42_i35++) {
    c42_zwt3[c42_i35] = c42_q[c42_i35];
  }

  _SFD_EML_CALL(0U, chartInstance->c42_sfEvent, 7);
  for (c42_i36 = 0; c42_i36 < 4; c42_i36++) {
    c42_q[c42_i36] = c42_b_x[c42_i36 + 3];
  }

  for (c42_k_k = 0; c42_k_k < 3; c42_k_k++) {
    c42_l_k = 2.0 + (real_T)c42_k_k;
    c42_q[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c42_l_k), 1, 4, 1, 0) - 1] = -c42_q[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", c42_l_k), 1, 4, 1, 0) - 1];
  }

  c42_dv12[0] = 0.0;
  for (c42_i37 = 0; c42_i37 < 3; c42_i37++) {
    c42_dv12[c42_i37 + 1] = c42_b_z[c42_i37 + 15];
  }

  for (c42_i38 = 0; c42_i38 < 4; c42_i38++) {
    c42_g_q[c42_i38] = c42_q[c42_i38];
  }

  c42_quatmultiply(chartInstance, c42_dv12, c42_g_q, c42_dv2);
  for (c42_i39 = 0; c42_i39 < 4; c42_i39++) {
    c42_h_x[c42_i39] = c42_b_x[c42_i39 + 3];
  }

  for (c42_i40 = 0; c42_i40 < 4; c42_i40++) {
    c42_dv13[c42_i40] = c42_dv2[c42_i40];
  }

  c42_quatmultiply(chartInstance, c42_h_x, c42_dv13, c42_q);
  for (c42_i41 = 0; c42_i41 < 4; c42_i41++) {
    c42_zwr3[c42_i41] = c42_q[c42_i41];
  }

  _SFD_EML_CALL(0U, chartInstance->c42_sfEvent, 8);
  for (c42_i42 = 0; c42_i42 < 4; c42_i42++) {
    c42_q[c42_i42] = c42_b_x[c42_i42 + 3];
  }

  for (c42_m_k = 0; c42_m_k < 3; c42_m_k++) {
    c42_n_k = 2.0 + (real_T)c42_m_k;
    c42_q[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c42_n_k), 1, 4, 1, 0) - 1] = -c42_q[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", c42_n_k), 1, 4, 1, 0) - 1];
  }

  c42_dv14[0] = 0.0;
  for (c42_i43 = 0; c42_i43 < 3; c42_i43++) {
    c42_dv14[c42_i43 + 1] = c42_b_z[c42_i43 + 18];
  }

  for (c42_i44 = 0; c42_i44 < 4; c42_i44++) {
    c42_h_q[c42_i44] = c42_q[c42_i44];
  }

  c42_quatmultiply(chartInstance, c42_dv14, c42_h_q, c42_dv2);
  for (c42_i45 = 0; c42_i45 < 4; c42_i45++) {
    c42_i_x[c42_i45] = c42_b_x[c42_i45 + 3];
  }

  for (c42_i46 = 0; c42_i46 < 4; c42_i46++) {
    c42_dv15[c42_i46] = c42_dv2[c42_i46];
  }

  c42_quatmultiply(chartInstance, c42_i_x, c42_dv15, c42_q);
  for (c42_i47 = 0; c42_i47 < 4; c42_i47++) {
    c42_zwt4[c42_i47] = c42_q[c42_i47];
  }

  _SFD_EML_CALL(0U, chartInstance->c42_sfEvent, 9);
  for (c42_i48 = 0; c42_i48 < 4; c42_i48++) {
    c42_q[c42_i48] = c42_b_x[c42_i48 + 3];
  }

  for (c42_o_k = 0; c42_o_k < 3; c42_o_k++) {
    c42_p_k = 2.0 + (real_T)c42_o_k;
    c42_q[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c42_p_k), 1, 4, 1, 0) - 1] = -c42_q[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", c42_p_k), 1, 4, 1, 0) - 1];
  }

  c42_dv16[0] = 0.0;
  for (c42_i49 = 0; c42_i49 < 3; c42_i49++) {
    c42_dv16[c42_i49 + 1] = c42_b_z[c42_i49 + 21];
  }

  for (c42_i50 = 0; c42_i50 < 4; c42_i50++) {
    c42_i_q[c42_i50] = c42_q[c42_i50];
  }

  c42_quatmultiply(chartInstance, c42_dv16, c42_i_q, c42_dv2);
  for (c42_i51 = 0; c42_i51 < 4; c42_i51++) {
    c42_j_x[c42_i51] = c42_b_x[c42_i51 + 3];
  }

  for (c42_i52 = 0; c42_i52 < 4; c42_i52++) {
    c42_dv17[c42_i52] = c42_dv2[c42_i52];
  }

  c42_quatmultiply(chartInstance, c42_j_x, c42_dv17, c42_q);
  for (c42_i53 = 0; c42_i53 < 4; c42_i53++) {
    c42_zwr4[c42_i53] = c42_q[c42_i53];
  }

  _SFD_EML_CALL(0U, chartInstance->c42_sfEvent, 12);
  for (c42_i54 = 0; c42_i54 < 3; c42_i54++) {
    c42_b_z_w[c42_i54] = c42_zwt1[c42_i54 + 1];
  }

  for (c42_i55 = 0; c42_i55 < 3; c42_i55++) {
    c42_b_z_w[c42_i55 + 3] = c42_zwr1[c42_i55 + 1];
  }

  for (c42_i56 = 0; c42_i56 < 3; c42_i56++) {
    c42_b_z_w[c42_i56 + 6] = c42_zwt2[c42_i56 + 1];
  }

  for (c42_i57 = 0; c42_i57 < 3; c42_i57++) {
    c42_b_z_w[c42_i57 + 9] = c42_zwr2[c42_i57 + 1];
  }

  for (c42_i58 = 0; c42_i58 < 3; c42_i58++) {
    c42_b_z_w[c42_i58 + 12] = c42_zwt3[c42_i58 + 1];
  }

  for (c42_i59 = 0; c42_i59 < 3; c42_i59++) {
    c42_b_z_w[c42_i59 + 15] = c42_zwr3[c42_i59 + 1];
  }

  for (c42_i60 = 0; c42_i60 < 3; c42_i60++) {
    c42_b_z_w[c42_i60 + 18] = c42_zwt4[c42_i60 + 1];
  }

  for (c42_i61 = 0; c42_i61 < 3; c42_i61++) {
    c42_b_z_w[c42_i61 + 21] = c42_zwr4[c42_i61 + 1];
  }

  _SFD_EML_CALL(0U, chartInstance->c42_sfEvent, -12);
  _SFD_SYMBOL_SCOPE_POP();
  for (c42_i62 = 0; c42_i62 < 24; c42_i62++) {
    (*chartInstance->c42_z_w)[c42_i62] = c42_b_z_w[c42_i62];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, chartInstance->c42_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DePascali4MMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c42_i63 = 0; c42_i63 < 24; c42_i63++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c42_z_w)[c42_i63], 2U);
  }
}

static void mdl_start_c42_DePascali4M(SFc42_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc42_DePascali4M(SFc42_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c42_machineNumber, uint32_T
  c42_chartNumber, uint32_T c42_instanceNumber)
{
  (void)c42_machineNumber;
  (void)c42_chartNumber;
  (void)c42_instanceNumber;
}

static const mxArray *c42_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData)
{
  const mxArray *c42_mxArrayOutData = NULL;
  int32_T c42_i64;
  real_T c42_b_inData[24];
  int32_T c42_i65;
  real_T c42_u[24];
  const mxArray *c42_y = NULL;
  SFc42_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc42_DePascali4MInstanceStruct *)chartInstanceVoid;
  c42_mxArrayOutData = NULL;
  for (c42_i64 = 0; c42_i64 < 24; c42_i64++) {
    c42_b_inData[c42_i64] = (*(real_T (*)[24])c42_inData)[c42_i64];
  }

  for (c42_i65 = 0; c42_i65 < 24; c42_i65++) {
    c42_u[c42_i65] = c42_b_inData[c42_i65];
  }

  c42_y = NULL;
  sf_mex_assign(&c42_y, sf_mex_create("y", c42_u, 0, 0U, 1U, 0U, 1, 24), false);
  sf_mex_assign(&c42_mxArrayOutData, c42_y, false);
  return c42_mxArrayOutData;
}

static void c42_emlrt_marshallIn(SFc42_DePascali4MInstanceStruct *chartInstance,
  const mxArray *c42_b_z_w, const char_T *c42_identifier, real_T c42_y[24])
{
  emlrtMsgIdentifier c42_thisId;
  c42_thisId.fIdentifier = c42_identifier;
  c42_thisId.fParent = NULL;
  c42_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c42_b_z_w), &c42_thisId,
    c42_y);
  sf_mex_destroy(&c42_b_z_w);
}

static void c42_b_emlrt_marshallIn(SFc42_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId,
  real_T c42_y[24])
{
  real_T c42_dv18[24];
  int32_T c42_i66;
  (void)chartInstance;
  sf_mex_import(c42_parentId, sf_mex_dup(c42_u), c42_dv18, 1, 0, 0U, 1, 0U, 1,
                24);
  for (c42_i66 = 0; c42_i66 < 24; c42_i66++) {
    c42_y[c42_i66] = c42_dv18[c42_i66];
  }

  sf_mex_destroy(&c42_u);
}

static void c42_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c42_mxArrayInData, const char_T *c42_varName, void *c42_outData)
{
  const mxArray *c42_b_z_w;
  const char_T *c42_identifier;
  emlrtMsgIdentifier c42_thisId;
  real_T c42_y[24];
  int32_T c42_i67;
  SFc42_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc42_DePascali4MInstanceStruct *)chartInstanceVoid;
  c42_b_z_w = sf_mex_dup(c42_mxArrayInData);
  c42_identifier = c42_varName;
  c42_thisId.fIdentifier = c42_identifier;
  c42_thisId.fParent = NULL;
  c42_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c42_b_z_w), &c42_thisId,
    c42_y);
  sf_mex_destroy(&c42_b_z_w);
  for (c42_i67 = 0; c42_i67 < 24; c42_i67++) {
    (*(real_T (*)[24])c42_outData)[c42_i67] = c42_y[c42_i67];
  }

  sf_mex_destroy(&c42_mxArrayInData);
}

static const mxArray *c42_b_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData)
{
  const mxArray *c42_mxArrayOutData = NULL;
  int32_T c42_i68;
  real_T c42_b_inData[28];
  int32_T c42_i69;
  real_T c42_u[28];
  const mxArray *c42_y = NULL;
  SFc42_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc42_DePascali4MInstanceStruct *)chartInstanceVoid;
  c42_mxArrayOutData = NULL;
  for (c42_i68 = 0; c42_i68 < 28; c42_i68++) {
    c42_b_inData[c42_i68] = (*(real_T (*)[28])c42_inData)[c42_i68];
  }

  for (c42_i69 = 0; c42_i69 < 28; c42_i69++) {
    c42_u[c42_i69] = c42_b_inData[c42_i69];
  }

  c42_y = NULL;
  sf_mex_assign(&c42_y, sf_mex_create("y", c42_u, 0, 0U, 1U, 0U, 1, 28), false);
  sf_mex_assign(&c42_mxArrayOutData, c42_y, false);
  return c42_mxArrayOutData;
}

static const mxArray *c42_c_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData)
{
  const mxArray *c42_mxArrayOutData = NULL;
  real_T c42_u;
  const mxArray *c42_y = NULL;
  SFc42_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc42_DePascali4MInstanceStruct *)chartInstanceVoid;
  c42_mxArrayOutData = NULL;
  c42_u = *(real_T *)c42_inData;
  c42_y = NULL;
  sf_mex_assign(&c42_y, sf_mex_create("y", &c42_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c42_mxArrayOutData, c42_y, false);
  return c42_mxArrayOutData;
}

static real_T c42_c_emlrt_marshallIn(SFc42_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId)
{
  real_T c42_y;
  real_T c42_d0;
  (void)chartInstance;
  sf_mex_import(c42_parentId, sf_mex_dup(c42_u), &c42_d0, 1, 0, 0U, 0, 0U, 0);
  c42_y = c42_d0;
  sf_mex_destroy(&c42_u);
  return c42_y;
}

static void c42_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c42_mxArrayInData, const char_T *c42_varName, void *c42_outData)
{
  const mxArray *c42_nargout;
  const char_T *c42_identifier;
  emlrtMsgIdentifier c42_thisId;
  real_T c42_y;
  SFc42_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc42_DePascali4MInstanceStruct *)chartInstanceVoid;
  c42_nargout = sf_mex_dup(c42_mxArrayInData);
  c42_identifier = c42_varName;
  c42_thisId.fIdentifier = c42_identifier;
  c42_thisId.fParent = NULL;
  c42_y = c42_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c42_nargout),
    &c42_thisId);
  sf_mex_destroy(&c42_nargout);
  *(real_T *)c42_outData = c42_y;
  sf_mex_destroy(&c42_mxArrayInData);
}

static const mxArray *c42_d_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData)
{
  const mxArray *c42_mxArrayOutData = NULL;
  int32_T c42_i70;
  real_T c42_b_inData[4];
  int32_T c42_i71;
  real_T c42_u[4];
  const mxArray *c42_y = NULL;
  SFc42_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc42_DePascali4MInstanceStruct *)chartInstanceVoid;
  c42_mxArrayOutData = NULL;
  for (c42_i70 = 0; c42_i70 < 4; c42_i70++) {
    c42_b_inData[c42_i70] = (*(real_T (*)[4])c42_inData)[c42_i70];
  }

  for (c42_i71 = 0; c42_i71 < 4; c42_i71++) {
    c42_u[c42_i71] = c42_b_inData[c42_i71];
  }

  c42_y = NULL;
  sf_mex_assign(&c42_y, sf_mex_create("y", c42_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c42_mxArrayOutData, c42_y, false);
  return c42_mxArrayOutData;
}

static void c42_d_emlrt_marshallIn(SFc42_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId,
  real_T c42_y[4])
{
  real_T c42_dv19[4];
  int32_T c42_i72;
  (void)chartInstance;
  sf_mex_import(c42_parentId, sf_mex_dup(c42_u), c42_dv19, 1, 0, 0U, 1, 0U, 1, 4);
  for (c42_i72 = 0; c42_i72 < 4; c42_i72++) {
    c42_y[c42_i72] = c42_dv19[c42_i72];
  }

  sf_mex_destroy(&c42_u);
}

static void c42_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c42_mxArrayInData, const char_T *c42_varName, void *c42_outData)
{
  const mxArray *c42_zwr4;
  const char_T *c42_identifier;
  emlrtMsgIdentifier c42_thisId;
  real_T c42_y[4];
  int32_T c42_i73;
  SFc42_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc42_DePascali4MInstanceStruct *)chartInstanceVoid;
  c42_zwr4 = sf_mex_dup(c42_mxArrayInData);
  c42_identifier = c42_varName;
  c42_thisId.fIdentifier = c42_identifier;
  c42_thisId.fParent = NULL;
  c42_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c42_zwr4), &c42_thisId, c42_y);
  sf_mex_destroy(&c42_zwr4);
  for (c42_i73 = 0; c42_i73 < 4; c42_i73++) {
    (*(real_T (*)[4])c42_outData)[c42_i73] = c42_y[c42_i73];
  }

  sf_mex_destroy(&c42_mxArrayInData);
}

const mxArray *sf_c42_DePascali4M_get_eml_resolved_functions_info(void)
{
  const mxArray *c42_nameCaptureInfo = NULL;
  c42_nameCaptureInfo = NULL;
  sf_mex_assign(&c42_nameCaptureInfo, sf_mex_createstruct("structure", 2, 11, 1),
                false);
  c42_info_helper(&c42_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c42_nameCaptureInfo);
  return c42_nameCaptureInfo;
}

static void c42_info_helper(const mxArray **c42_info)
{
  const mxArray *c42_rhs0 = NULL;
  const mxArray *c42_lhs0 = NULL;
  const mxArray *c42_rhs1 = NULL;
  const mxArray *c42_lhs1 = NULL;
  const mxArray *c42_rhs2 = NULL;
  const mxArray *c42_lhs2 = NULL;
  const mxArray *c42_rhs3 = NULL;
  const mxArray *c42_lhs3 = NULL;
  const mxArray *c42_rhs4 = NULL;
  const mxArray *c42_lhs4 = NULL;
  const mxArray *c42_rhs5 = NULL;
  const mxArray *c42_lhs5 = NULL;
  const mxArray *c42_rhs6 = NULL;
  const mxArray *c42_lhs6 = NULL;
  const mxArray *c42_rhs7 = NULL;
  const mxArray *c42_lhs7 = NULL;
  const mxArray *c42_rhs8 = NULL;
  const mxArray *c42_lhs8 = NULL;
  const mxArray *c42_rhs9 = NULL;
  const mxArray *c42_lhs9 = NULL;
  const mxArray *c42_rhs10 = NULL;
  const mxArray *c42_lhs10 = NULL;
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut("quatconj"), "name", "name",
                  0);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatconj.p"), "resolved", "resolved",
                  0);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(1410808258U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c42_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c42_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c42_info, sf_mex_duplicatearraysafe(&c42_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c42_info, sf_mex_duplicatearraysafe(&c42_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut("quatmultiply"), "name",
                  "name", 1);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatmultiply.p"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(1410808258U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c42_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c42_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c42_info, sf_mex_duplicatearraysafe(&c42_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c42_info, sf_mex_duplicatearraysafe(&c42_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatmultiply.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut("max"), "name", "name", 2);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(1311280516U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c42_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c42_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c42_info, sf_mex_duplicatearraysafe(&c42_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c42_info, sf_mex_duplicatearraysafe(&c42_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 3);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(1378321184U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c42_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c42_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c42_info, sf_mex_duplicatearraysafe(&c42_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c42_info, sf_mex_duplicatearraysafe(&c42_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 4);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 4);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c42_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c42_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c42_info, sf_mex_duplicatearraysafe(&c42_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c42_info, sf_mex_duplicatearraysafe(&c42_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 5);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c42_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c42_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c42_info, sf_mex_duplicatearraysafe(&c42_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c42_info, sf_mex_duplicatearraysafe(&c42_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 6);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 6);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c42_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c42_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c42_info, sf_mex_duplicatearraysafe(&c42_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c42_info, sf_mex_duplicatearraysafe(&c42_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 7);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c42_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c42_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c42_info, sf_mex_duplicatearraysafe(&c42_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c42_info, sf_mex_duplicatearraysafe(&c42_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 8);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 8);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c42_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c42_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c42_info, sf_mex_duplicatearraysafe(&c42_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c42_info, sf_mex_duplicatearraysafe(&c42_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 9);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 9);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c42_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c42_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c42_info, sf_mex_duplicatearraysafe(&c42_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c42_info, sf_mex_duplicatearraysafe(&c42_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 10);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 10);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c42_info, c42_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c42_info, c42_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c42_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c42_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c42_info, sf_mex_duplicatearraysafe(&c42_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c42_info, sf_mex_duplicatearraysafe(&c42_lhs10), "lhs", "lhs",
                  10);
  sf_mex_destroy(&c42_rhs0);
  sf_mex_destroy(&c42_lhs0);
  sf_mex_destroy(&c42_rhs1);
  sf_mex_destroy(&c42_lhs1);
  sf_mex_destroy(&c42_rhs2);
  sf_mex_destroy(&c42_lhs2);
  sf_mex_destroy(&c42_rhs3);
  sf_mex_destroy(&c42_lhs3);
  sf_mex_destroy(&c42_rhs4);
  sf_mex_destroy(&c42_lhs4);
  sf_mex_destroy(&c42_rhs5);
  sf_mex_destroy(&c42_lhs5);
  sf_mex_destroy(&c42_rhs6);
  sf_mex_destroy(&c42_lhs6);
  sf_mex_destroy(&c42_rhs7);
  sf_mex_destroy(&c42_lhs7);
  sf_mex_destroy(&c42_rhs8);
  sf_mex_destroy(&c42_lhs8);
  sf_mex_destroy(&c42_rhs9);
  sf_mex_destroy(&c42_lhs9);
  sf_mex_destroy(&c42_rhs10);
  sf_mex_destroy(&c42_lhs10);
}

static const mxArray *c42_emlrt_marshallOut(const char * c42_u)
{
  const mxArray *c42_y = NULL;
  c42_y = NULL;
  sf_mex_assign(&c42_y, sf_mex_create("y", c42_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c42_u)), false);
  return c42_y;
}

static const mxArray *c42_b_emlrt_marshallOut(const uint32_T c42_u)
{
  const mxArray *c42_y = NULL;
  c42_y = NULL;
  sf_mex_assign(&c42_y, sf_mex_create("y", &c42_u, 7, 0U, 0U, 0U, 0), false);
  return c42_y;
}

static void c42_quatmultiply(SFc42_DePascali4MInstanceStruct *chartInstance,
  real_T c42_q[4], real_T c42_r[4], real_T c42_qout[4])
{
  real_T c42_q1;
  real_T c42_q2;
  real_T c42_q3;
  real_T c42_q4;
  real_T c42_r1;
  real_T c42_r2;
  real_T c42_r3;
  real_T c42_r4;
  (void)chartInstance;
  c42_q1 = c42_q[0];
  c42_q2 = c42_q[1];
  c42_q3 = c42_q[2];
  c42_q4 = c42_q[3];
  c42_r1 = c42_r[0];
  c42_r2 = c42_r[1];
  c42_r3 = c42_r[2];
  c42_r4 = c42_r[3];
  c42_qout[0] = ((c42_q1 * c42_r1 - c42_q2 * c42_r2) - c42_q3 * c42_r3) - c42_q4
    * c42_r4;
  c42_qout[1] = (c42_q1 * c42_r2 + c42_r1 * c42_q2) + (c42_q3 * c42_r4 - c42_q4 *
    c42_r3);
  c42_qout[2] = (c42_q1 * c42_r3 + c42_r1 * c42_q3) + (c42_q4 * c42_r2 - c42_q2 *
    c42_r4);
  c42_qout[3] = (c42_q1 * c42_r4 + c42_r1 * c42_q4) + (c42_q2 * c42_r3 - c42_q3 *
    c42_r2);
}

static const mxArray *c42_e_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData)
{
  const mxArray *c42_mxArrayOutData = NULL;
  int32_T c42_u;
  const mxArray *c42_y = NULL;
  SFc42_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc42_DePascali4MInstanceStruct *)chartInstanceVoid;
  c42_mxArrayOutData = NULL;
  c42_u = *(int32_T *)c42_inData;
  c42_y = NULL;
  sf_mex_assign(&c42_y, sf_mex_create("y", &c42_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c42_mxArrayOutData, c42_y, false);
  return c42_mxArrayOutData;
}

static int32_T c42_e_emlrt_marshallIn(SFc42_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId)
{
  int32_T c42_y;
  int32_T c42_i74;
  (void)chartInstance;
  sf_mex_import(c42_parentId, sf_mex_dup(c42_u), &c42_i74, 1, 6, 0U, 0, 0U, 0);
  c42_y = c42_i74;
  sf_mex_destroy(&c42_u);
  return c42_y;
}

static void c42_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c42_mxArrayInData, const char_T *c42_varName, void *c42_outData)
{
  const mxArray *c42_b_sfEvent;
  const char_T *c42_identifier;
  emlrtMsgIdentifier c42_thisId;
  int32_T c42_y;
  SFc42_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc42_DePascali4MInstanceStruct *)chartInstanceVoid;
  c42_b_sfEvent = sf_mex_dup(c42_mxArrayInData);
  c42_identifier = c42_varName;
  c42_thisId.fIdentifier = c42_identifier;
  c42_thisId.fParent = NULL;
  c42_y = c42_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c42_b_sfEvent),
    &c42_thisId);
  sf_mex_destroy(&c42_b_sfEvent);
  *(int32_T *)c42_outData = c42_y;
  sf_mex_destroy(&c42_mxArrayInData);
}

static uint8_T c42_f_emlrt_marshallIn(SFc42_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c42_b_is_active_c42_DePascali4M, const char_T
  *c42_identifier)
{
  uint8_T c42_y;
  emlrtMsgIdentifier c42_thisId;
  c42_thisId.fIdentifier = c42_identifier;
  c42_thisId.fParent = NULL;
  c42_y = c42_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c42_b_is_active_c42_DePascali4M), &c42_thisId);
  sf_mex_destroy(&c42_b_is_active_c42_DePascali4M);
  return c42_y;
}

static uint8_T c42_g_emlrt_marshallIn(SFc42_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId)
{
  uint8_T c42_y;
  uint8_T c42_u0;
  (void)chartInstance;
  sf_mex_import(c42_parentId, sf_mex_dup(c42_u), &c42_u0, 1, 3, 0U, 0, 0U, 0);
  c42_y = c42_u0;
  sf_mex_destroy(&c42_u);
  return c42_y;
}

static void init_dsm_address_info(SFc42_DePascali4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc42_DePascali4MInstanceStruct
  *chartInstance)
{
  chartInstance->c42_z = (real_T (*)[24])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c42_x = (real_T (*)[28])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c42_z_w = (real_T (*)[24])ssGetOutputPortSignal_wrapper
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

void sf_c42_DePascali4M_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2539079838U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(869680496U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1844813434U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1540072503U);
}

mxArray* sf_c42_DePascali4M_get_post_codegen_info(void);
mxArray *sf_c42_DePascali4M_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("KIeRCEkbdV66yJ7xhHqYCG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(24);
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
      pr[0] = (double)(28);
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(24);
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
    mxArray* mxPostCodegenInfo = sf_c42_DePascali4M_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c42_DePascali4M_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c42_DePascali4M_jit_fallback_info(void)
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

mxArray *sf_c42_DePascali4M_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c42_DePascali4M_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c42_DePascali4M(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"z_w\",},{M[8],M[0],T\"is_active_c42_DePascali4M\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c42_DePascali4M_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc42_DePascali4MInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc42_DePascali4MInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DePascali4MMachineNumber_,
           42,
           1,
           1,
           0,
           3,
           0,
           0,
           0,
           0,
           0,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"z");
          _SFD_SET_DATA_PROPS(1,1,1,0,"x");
          _SFD_SET_DATA_PROPS(2,2,0,1,"z_w");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,821);

        {
          unsigned int dimVector[1];
          dimVector[0]= 24;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c42_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 28;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c42_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 24;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c42_sf_marshallOut,(MexInFcnForType)
            c42_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c42_z);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c42_x);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c42_z_w);
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
  return "bGk6kg9os7bmbBDfAcCbWC";
}

static void sf_opaque_initialize_c42_DePascali4M(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc42_DePascali4MInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c42_DePascali4M((SFc42_DePascali4MInstanceStruct*)
    chartInstanceVar);
  initialize_c42_DePascali4M((SFc42_DePascali4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c42_DePascali4M(void *chartInstanceVar)
{
  enable_c42_DePascali4M((SFc42_DePascali4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c42_DePascali4M(void *chartInstanceVar)
{
  disable_c42_DePascali4M((SFc42_DePascali4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c42_DePascali4M(void *chartInstanceVar)
{
  sf_gateway_c42_DePascali4M((SFc42_DePascali4MInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c42_DePascali4M(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c42_DePascali4M((SFc42_DePascali4MInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c42_DePascali4M(SimStruct* S, const mxArray *
  st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c42_DePascali4M((SFc42_DePascali4MInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c42_DePascali4M(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc42_DePascali4MInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DePascali4M_optimization_info();
    }

    finalize_c42_DePascali4M((SFc42_DePascali4MInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc42_DePascali4M((SFc42_DePascali4MInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c42_DePascali4M(SimStruct *S)
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
    initialize_params_c42_DePascali4M((SFc42_DePascali4MInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c42_DePascali4M(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DePascali4M_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      42);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,42,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,42,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,42);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,42,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,42,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,42);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(549778729U));
  ssSetChecksum1(S,(554662236U));
  ssSetChecksum2(S,(552596220U));
  ssSetChecksum3(S,(3073289901U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c42_DePascali4M(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c42_DePascali4M(SimStruct *S)
{
  SFc42_DePascali4MInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc42_DePascali4MInstanceStruct *)utMalloc(sizeof
    (SFc42_DePascali4MInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc42_DePascali4MInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c42_DePascali4M;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c42_DePascali4M;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c42_DePascali4M;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c42_DePascali4M;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c42_DePascali4M;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c42_DePascali4M;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c42_DePascali4M;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c42_DePascali4M;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c42_DePascali4M;
  chartInstance->chartInfo.mdlStart = mdlStart_c42_DePascali4M;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c42_DePascali4M;
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

void c42_DePascali4M_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c42_DePascali4M(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c42_DePascali4M(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c42_DePascali4M(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c42_DePascali4M_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

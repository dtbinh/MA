/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DePascali4M_sfun.h"
#include "c38_DePascali4M.h"
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
static const char * c38_debug_family_names[5] = { "nargin", "nargout", "r", "x",
  "Ared" };

static const char * c38_b_debug_family_names[6] = { "rwq", "nargin", "nargout",
  "q", "r", "rw" };

static const char * c38_c_debug_family_names[4] = { "nargin", "nargout", "x",
  "X" };

/* Function Declarations */
static void initialize_c38_DePascali4M(SFc38_DePascali4MInstanceStruct
  *chartInstance);
static void initialize_params_c38_DePascali4M(SFc38_DePascali4MInstanceStruct
  *chartInstance);
static void enable_c38_DePascali4M(SFc38_DePascali4MInstanceStruct
  *chartInstance);
static void disable_c38_DePascali4M(SFc38_DePascali4MInstanceStruct
  *chartInstance);
static void c38_update_debugger_state_c38_DePascali4M
  (SFc38_DePascali4MInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c38_DePascali4M
  (SFc38_DePascali4MInstanceStruct *chartInstance);
static void set_sim_state_c38_DePascali4M(SFc38_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c38_st);
static void finalize_c38_DePascali4M(SFc38_DePascali4MInstanceStruct
  *chartInstance);
static void sf_gateway_c38_DePascali4M(SFc38_DePascali4MInstanceStruct
  *chartInstance);
static void mdl_start_c38_DePascali4M(SFc38_DePascali4MInstanceStruct
  *chartInstance);
static void initSimStructsc38_DePascali4M(SFc38_DePascali4MInstanceStruct
  *chartInstance);
static void c38_quatrot(SFc38_DePascali4MInstanceStruct *chartInstance, real_T
  c38_q[4], real_T c38_b_r[3], real_T c38_rw[3]);
static void init_script_number_translation(uint32_T c38_machineNumber, uint32_T
  c38_chartNumber, uint32_T c38_instanceNumber);
static const mxArray *c38_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData);
static void c38_emlrt_marshallIn(SFc38_DePascali4MInstanceStruct *chartInstance,
  const mxArray *c38_b_Ared, const char_T *c38_identifier, real_T c38_y[432]);
static void c38_b_emlrt_marshallIn(SFc38_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId,
  real_T c38_y[432]);
static void c38_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData);
static const mxArray *c38_b_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData);
static const mxArray *c38_c_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData);
static void c38_c_emlrt_marshallIn(SFc38_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId,
  real_T c38_y[12]);
static void c38_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData);
static const mxArray *c38_d_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData);
static real_T c38_d_emlrt_marshallIn(SFc38_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId);
static void c38_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData);
static const mxArray *c38_e_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData);
static void c38_e_emlrt_marshallIn(SFc38_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId,
  real_T c38_y[3]);
static void c38_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData);
static const mxArray *c38_f_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData);
static void c38_f_emlrt_marshallIn(SFc38_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId,
  real_T c38_y[4]);
static void c38_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData);
static const mxArray *c38_g_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData);
static void c38_g_emlrt_marshallIn(SFc38_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId,
  real_T c38_y[9]);
static void c38_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData);
static void c38_info_helper(const mxArray **c38_info);
static const mxArray *c38_emlrt_marshallOut(const char * c38_u);
static const mxArray *c38_b_emlrt_marshallOut(const uint32_T c38_u);
static void c38_eye(SFc38_DePascali4MInstanceStruct *chartInstance, real_T
                    c38_I[9]);
static void c38_quatmultiply(SFc38_DePascali4MInstanceStruct *chartInstance,
  real_T c38_q[4], real_T c38_b_r[4], real_T c38_qout[4]);
static const mxArray *c38_h_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData);
static int32_T c38_h_emlrt_marshallIn(SFc38_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId);
static void c38_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData);
static uint8_T c38_i_emlrt_marshallIn(SFc38_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c38_b_is_active_c38_DePascali4M, const char_T
  *c38_identifier);
static uint8_T c38_j_emlrt_marshallIn(SFc38_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId);
static void init_dsm_address_info(SFc38_DePascali4MInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc38_DePascali4MInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c38_DePascali4M(SFc38_DePascali4MInstanceStruct
  *chartInstance)
{
  chartInstance->c38_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c38_is_active_c38_DePascali4M = 0U;
}

static void initialize_params_c38_DePascali4M(SFc38_DePascali4MInstanceStruct
  *chartInstance)
{
  real_T c38_dv0[12];
  int32_T c38_i0;
  sf_mex_import_named("r", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      c38_dv0, 0, 0, 0U, 1, 0U, 1, 12);
  for (c38_i0 = 0; c38_i0 < 12; c38_i0++) {
    chartInstance->c38_r[c38_i0] = c38_dv0[c38_i0];
  }
}

static void enable_c38_DePascali4M(SFc38_DePascali4MInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c38_DePascali4M(SFc38_DePascali4MInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c38_update_debugger_state_c38_DePascali4M
  (SFc38_DePascali4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c38_DePascali4M
  (SFc38_DePascali4MInstanceStruct *chartInstance)
{
  const mxArray *c38_st;
  const mxArray *c38_y = NULL;
  int32_T c38_i1;
  real_T c38_u[432];
  const mxArray *c38_b_y = NULL;
  uint8_T c38_hoistedGlobal;
  uint8_T c38_b_u;
  const mxArray *c38_c_y = NULL;
  c38_st = NULL;
  c38_st = NULL;
  c38_y = NULL;
  sf_mex_assign(&c38_y, sf_mex_createcellmatrix(2, 1), false);
  for (c38_i1 = 0; c38_i1 < 432; c38_i1++) {
    c38_u[c38_i1] = (*chartInstance->c38_Ared)[c38_i1];
  }

  c38_b_y = NULL;
  sf_mex_assign(&c38_b_y, sf_mex_create("y", c38_u, 0, 0U, 1U, 0U, 2, 18, 24),
                false);
  sf_mex_setcell(c38_y, 0, c38_b_y);
  c38_hoistedGlobal = chartInstance->c38_is_active_c38_DePascali4M;
  c38_b_u = c38_hoistedGlobal;
  c38_c_y = NULL;
  sf_mex_assign(&c38_c_y, sf_mex_create("y", &c38_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c38_y, 1, c38_c_y);
  sf_mex_assign(&c38_st, c38_y, false);
  return c38_st;
}

static void set_sim_state_c38_DePascali4M(SFc38_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c38_st)
{
  const mxArray *c38_u;
  real_T c38_dv1[432];
  int32_T c38_i2;
  chartInstance->c38_doneDoubleBufferReInit = true;
  c38_u = sf_mex_dup(c38_st);
  c38_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c38_u, 0)),
                       "Ared", c38_dv1);
  for (c38_i2 = 0; c38_i2 < 432; c38_i2++) {
    (*chartInstance->c38_Ared)[c38_i2] = c38_dv1[c38_i2];
  }

  chartInstance->c38_is_active_c38_DePascali4M = c38_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c38_u, 1)),
     "is_active_c38_DePascali4M");
  sf_mex_destroy(&c38_u);
  c38_update_debugger_state_c38_DePascali4M(chartInstance);
  sf_mex_destroy(&c38_st);
}

static void finalize_c38_DePascali4M(SFc38_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c38_DePascali4M(SFc38_DePascali4MInstanceStruct
  *chartInstance)
{
  int32_T c38_i3;
  int32_T c38_i4;
  real_T c38_b_r[12];
  int32_T c38_i5;
  real_T c38_b_x[28];
  uint32_T c38_debug_family_var_map[5];
  real_T c38_nargin = 2.0;
  real_T c38_nargout = 1.0;
  real_T c38_b_Ared[432];
  int32_T c38_i6;
  real_T c38_c_x[4];
  int32_T c38_i7;
  real_T c38_c_r[3];
  real_T c38_dv2[3];
  int32_T c38_i8;
  real_T c38_d_x[3];
  uint32_T c38_b_debug_family_var_map[4];
  real_T c38_b_nargin = 1.0;
  real_T c38_b_nargout = 1.0;
  real_T c38_X[9];
  int32_T c38_i9;
  real_T c38_e_x[4];
  int32_T c38_i10;
  real_T c38_d_r[3];
  real_T c38_dv3[3];
  int32_T c38_i11;
  real_T c38_f_x[3];
  real_T c38_c_nargin = 1.0;
  real_T c38_c_nargout = 1.0;
  real_T c38_b_X[9];
  int32_T c38_i12;
  real_T c38_g_x[4];
  int32_T c38_i13;
  real_T c38_e_r[3];
  real_T c38_dv4[3];
  int32_T c38_i14;
  real_T c38_h_x[3];
  real_T c38_d_nargin = 1.0;
  real_T c38_d_nargout = 1.0;
  real_T c38_c_X[9];
  real_T c38_dv5[9];
  real_T c38_dv6[9];
  real_T c38_dv7[9];
  real_T c38_dv8[9];
  real_T c38_dv9[9];
  real_T c38_dv10[9];
  real_T c38_dv11[9];
  real_T c38_dv12[9];
  real_T c38_dv13[9];
  real_T c38_dv14[9];
  real_T c38_dv15[9];
  real_T c38_dv16[9];
  int32_T c38_i15;
  int32_T c38_i16;
  int32_T c38_i17;
  int32_T c38_i18;
  int32_T c38_i19;
  int32_T c38_i20;
  int32_T c38_i21;
  int32_T c38_i22;
  int32_T c38_i23;
  int32_T c38_i24;
  int32_T c38_i25;
  int32_T c38_i26;
  int32_T c38_i27;
  int32_T c38_i28;
  int32_T c38_i29;
  int32_T c38_i30;
  int32_T c38_i31;
  int32_T c38_i32;
  int32_T c38_i33;
  int32_T c38_i34;
  int32_T c38_i35;
  int32_T c38_i36;
  int32_T c38_i37;
  int32_T c38_i38;
  int32_T c38_i39;
  int32_T c38_i40;
  int32_T c38_i41;
  int32_T c38_i42;
  int32_T c38_i43;
  int32_T c38_i44;
  int32_T c38_i45;
  int32_T c38_i46;
  int32_T c38_i47;
  int32_T c38_i48;
  int32_T c38_i49;
  int32_T c38_i50;
  int32_T c38_i51;
  int32_T c38_i52;
  int32_T c38_i53;
  int32_T c38_i54;
  int32_T c38_i55;
  int32_T c38_i56;
  int32_T c38_i57;
  int32_T c38_i58;
  int32_T c38_i59;
  int32_T c38_i60;
  int32_T c38_i61;
  int32_T c38_i62;
  int32_T c38_i63;
  int32_T c38_i64;
  int32_T c38_i65;
  int32_T c38_i66;
  int32_T c38_i67;
  int32_T c38_i68;
  int32_T c38_i69;
  int32_T c38_i70;
  int32_T c38_i71;
  int32_T c38_i72;
  int32_T c38_i73;
  int32_T c38_i74;
  int32_T c38_i75;
  int32_T c38_i76;
  int32_T c38_i77;
  int32_T c38_i78;
  int32_T c38_i79;
  int32_T c38_i80;
  int32_T c38_i81;
  int32_T c38_i82;
  int32_T c38_i83;
  int32_T c38_i84;
  int32_T c38_i85;
  int32_T c38_i86;
  int32_T c38_i87;
  int32_T c38_i88;
  int32_T c38_i89;
  int32_T c38_i90;
  int32_T c38_i91;
  int32_T c38_i92;
  int32_T c38_i93;
  int32_T c38_i94;
  int32_T c38_i95;
  int32_T c38_i96;
  int32_T c38_i97;
  int32_T c38_i98;
  int32_T c38_i99;
  int32_T c38_i100;
  int32_T c38_i101;
  int32_T c38_i102;
  int32_T c38_i103;
  int32_T c38_i104;
  int32_T c38_i105;
  int32_T c38_i106;
  int32_T c38_i107;
  int32_T c38_i108;
  int32_T c38_i109;
  int32_T c38_i110;
  int32_T c38_i111;
  int32_T c38_i112;
  int32_T c38_i113;
  int32_T c38_i114;
  int32_T c38_i115;
  int32_T c38_i116;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 16U, chartInstance->c38_sfEvent);
  for (c38_i3 = 0; c38_i3 < 12; c38_i3++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c38_r[c38_i3], 0U);
  }

  chartInstance->c38_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 16U, chartInstance->c38_sfEvent);
  for (c38_i4 = 0; c38_i4 < 12; c38_i4++) {
    c38_b_r[c38_i4] = chartInstance->c38_r[c38_i4];
  }

  for (c38_i5 = 0; c38_i5 < 28; c38_i5++) {
    c38_b_x[c38_i5] = (*chartInstance->c38_x)[c38_i5];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c38_debug_family_names,
    c38_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c38_nargin, 0U, c38_d_sf_marshallOut,
    c38_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c38_nargout, 1U, c38_d_sf_marshallOut,
    c38_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c38_b_r, 2U, c38_c_sf_marshallOut,
    c38_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c38_b_x, 3U, c38_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c38_b_Ared, 4U, c38_sf_marshallOut,
    c38_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 2);
  for (c38_i6 = 0; c38_i6 < 4; c38_i6++) {
    c38_c_x[c38_i6] = c38_b_x[c38_i6 + 3];
  }

  for (c38_i7 = 0; c38_i7 < 3; c38_i7++) {
    c38_c_r[c38_i7] = c38_b_r[c38_i7 + 3] - c38_b_r[c38_i7];
  }

  c38_quatrot(chartInstance, c38_c_x, c38_c_r, c38_dv2);
  for (c38_i8 = 0; c38_i8 < 3; c38_i8++) {
    c38_d_x[c38_i8] = c38_dv2[c38_i8];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c38_c_debug_family_names,
    c38_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c38_b_nargin, 0U, c38_d_sf_marshallOut,
    c38_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c38_b_nargout, 1U, c38_d_sf_marshallOut,
    c38_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c38_d_x, 2U, c38_e_sf_marshallOut,
    c38_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c38_X, 3U, c38_g_sf_marshallOut,
    c38_f_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c38_sfEvent, 3);
  c38_X[0] = 0.0;
  c38_X[3] = -c38_d_x[2];
  c38_X[6] = c38_d_x[1];
  c38_X[1] = c38_d_x[2];
  c38_X[4] = 0.0;
  c38_X[7] = -c38_d_x[0];
  c38_X[2] = -c38_d_x[1];
  c38_X[5] = c38_d_x[0];
  c38_X[8] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c38_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c38_i9 = 0; c38_i9 < 4; c38_i9++) {
    c38_e_x[c38_i9] = c38_b_x[c38_i9 + 3];
  }

  for (c38_i10 = 0; c38_i10 < 3; c38_i10++) {
    c38_d_r[c38_i10] = c38_b_r[c38_i10 + 6] - c38_b_r[c38_i10];
  }

  c38_quatrot(chartInstance, c38_e_x, c38_d_r, c38_dv3);
  for (c38_i11 = 0; c38_i11 < 3; c38_i11++) {
    c38_f_x[c38_i11] = c38_dv3[c38_i11];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c38_c_debug_family_names,
    c38_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c38_c_nargin, 0U, c38_d_sf_marshallOut,
    c38_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c38_c_nargout, 1U, c38_d_sf_marshallOut,
    c38_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c38_f_x, 2U, c38_e_sf_marshallOut,
    c38_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c38_b_X, 3U, c38_g_sf_marshallOut,
    c38_f_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c38_sfEvent, 3);
  c38_b_X[0] = 0.0;
  c38_b_X[3] = -c38_f_x[2];
  c38_b_X[6] = c38_f_x[1];
  c38_b_X[1] = c38_f_x[2];
  c38_b_X[4] = 0.0;
  c38_b_X[7] = -c38_f_x[0];
  c38_b_X[2] = -c38_f_x[1];
  c38_b_X[5] = c38_f_x[0];
  c38_b_X[8] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c38_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c38_i12 = 0; c38_i12 < 4; c38_i12++) {
    c38_g_x[c38_i12] = c38_b_x[c38_i12 + 3];
  }

  for (c38_i13 = 0; c38_i13 < 3; c38_i13++) {
    c38_e_r[c38_i13] = c38_b_r[c38_i13 + 9] - c38_b_r[c38_i13];
  }

  c38_quatrot(chartInstance, c38_g_x, c38_e_r, c38_dv4);
  for (c38_i14 = 0; c38_i14 < 3; c38_i14++) {
    c38_h_x[c38_i14] = c38_dv4[c38_i14];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c38_c_debug_family_names,
    c38_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c38_d_nargin, 0U, c38_d_sf_marshallOut,
    c38_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c38_d_nargout, 1U, c38_d_sf_marshallOut,
    c38_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c38_h_x, 2U, c38_e_sf_marshallOut,
    c38_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c38_c_X, 3U, c38_g_sf_marshallOut,
    c38_f_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c38_sfEvent, 3);
  c38_c_X[0] = 0.0;
  c38_c_X[3] = -c38_h_x[2];
  c38_c_X[6] = c38_h_x[1];
  c38_c_X[1] = c38_h_x[2];
  c38_c_X[4] = 0.0;
  c38_c_X[7] = -c38_h_x[0];
  c38_c_X[2] = -c38_h_x[1];
  c38_c_X[5] = c38_h_x[0];
  c38_c_X[8] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c38_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  c38_eye(chartInstance, c38_dv5);
  c38_eye(chartInstance, c38_dv6);
  c38_eye(chartInstance, c38_dv7);
  c38_eye(chartInstance, c38_dv8);
  c38_eye(chartInstance, c38_dv9);
  c38_eye(chartInstance, c38_dv10);
  c38_eye(chartInstance, c38_dv11);
  c38_eye(chartInstance, c38_dv12);
  c38_eye(chartInstance, c38_dv13);
  c38_eye(chartInstance, c38_dv14);
  c38_eye(chartInstance, c38_dv15);
  c38_eye(chartInstance, c38_dv16);
  c38_i15 = 0;
  c38_i16 = 0;
  for (c38_i17 = 0; c38_i17 < 3; c38_i17++) {
    for (c38_i18 = 0; c38_i18 < 3; c38_i18++) {
      c38_b_Ared[c38_i18 + c38_i15] = -c38_dv5[c38_i18 + c38_i16];
    }

    c38_i15 += 18;
    c38_i16 += 3;
  }

  c38_i19 = 0;
  c38_i20 = 0;
  for (c38_i21 = 0; c38_i21 < 3; c38_i21++) {
    for (c38_i22 = 0; c38_i22 < 3; c38_i22++) {
      c38_b_Ared[(c38_i22 + c38_i19) + 54] = c38_X[c38_i22 + c38_i20];
    }

    c38_i19 += 18;
    c38_i20 += 3;
  }

  c38_i23 = 0;
  c38_i24 = 0;
  for (c38_i25 = 0; c38_i25 < 3; c38_i25++) {
    for (c38_i26 = 0; c38_i26 < 3; c38_i26++) {
      c38_b_Ared[(c38_i26 + c38_i23) + 108] = c38_dv6[c38_i26 + c38_i24];
    }

    c38_i23 += 18;
    c38_i24 += 3;
  }

  c38_i27 = 0;
  for (c38_i28 = 0; c38_i28 < 15; c38_i28++) {
    for (c38_i29 = 0; c38_i29 < 3; c38_i29++) {
      c38_b_Ared[(c38_i29 + c38_i27) + 162] = 0.0;
    }

    c38_i27 += 18;
  }

  c38_i30 = 0;
  for (c38_i31 = 0; c38_i31 < 3; c38_i31++) {
    for (c38_i32 = 0; c38_i32 < 3; c38_i32++) {
      c38_b_Ared[(c38_i32 + c38_i30) + 3] = 0.0;
    }

    c38_i30 += 18;
  }

  c38_i33 = 0;
  c38_i34 = 0;
  for (c38_i35 = 0; c38_i35 < 3; c38_i35++) {
    for (c38_i36 = 0; c38_i36 < 3; c38_i36++) {
      c38_b_Ared[(c38_i36 + c38_i33) + 57] = -c38_dv7[c38_i36 + c38_i34];
    }

    c38_i33 += 18;
    c38_i34 += 3;
  }

  c38_i37 = 0;
  for (c38_i38 = 0; c38_i38 < 3; c38_i38++) {
    for (c38_i39 = 0; c38_i39 < 3; c38_i39++) {
      c38_b_Ared[(c38_i39 + c38_i37) + 111] = 0.0;
    }

    c38_i37 += 18;
  }

  c38_i40 = 0;
  c38_i41 = 0;
  for (c38_i42 = 0; c38_i42 < 3; c38_i42++) {
    for (c38_i43 = 0; c38_i43 < 3; c38_i43++) {
      c38_b_Ared[(c38_i43 + c38_i40) + 165] = c38_dv8[c38_i43 + c38_i41];
    }

    c38_i40 += 18;
    c38_i41 += 3;
  }

  c38_i44 = 0;
  for (c38_i45 = 0; c38_i45 < 12; c38_i45++) {
    for (c38_i46 = 0; c38_i46 < 3; c38_i46++) {
      c38_b_Ared[(c38_i46 + c38_i44) + 219] = 0.0;
    }

    c38_i44 += 18;
  }

  c38_i47 = 0;
  c38_i48 = 0;
  for (c38_i49 = 0; c38_i49 < 3; c38_i49++) {
    for (c38_i50 = 0; c38_i50 < 3; c38_i50++) {
      c38_b_Ared[(c38_i50 + c38_i47) + 6] = -c38_dv9[c38_i50 + c38_i48];
    }

    c38_i47 += 18;
    c38_i48 += 3;
  }

  c38_i51 = 0;
  c38_i52 = 0;
  for (c38_i53 = 0; c38_i53 < 3; c38_i53++) {
    for (c38_i54 = 0; c38_i54 < 3; c38_i54++) {
      c38_b_Ared[(c38_i54 + c38_i51) + 60] = c38_b_X[c38_i54 + c38_i52];
    }

    c38_i51 += 18;
    c38_i52 += 3;
  }

  c38_i55 = 0;
  for (c38_i56 = 0; c38_i56 < 6; c38_i56++) {
    for (c38_i57 = 0; c38_i57 < 3; c38_i57++) {
      c38_b_Ared[(c38_i57 + c38_i55) + 114] = 0.0;
    }

    c38_i55 += 18;
  }

  c38_i58 = 0;
  c38_i59 = 0;
  for (c38_i60 = 0; c38_i60 < 3; c38_i60++) {
    for (c38_i61 = 0; c38_i61 < 3; c38_i61++) {
      c38_b_Ared[(c38_i61 + c38_i58) + 222] = c38_dv10[c38_i61 + c38_i59];
    }

    c38_i58 += 18;
    c38_i59 += 3;
  }

  c38_i62 = 0;
  for (c38_i63 = 0; c38_i63 < 9; c38_i63++) {
    for (c38_i64 = 0; c38_i64 < 3; c38_i64++) {
      c38_b_Ared[(c38_i64 + c38_i62) + 276] = 0.0;
    }

    c38_i62 += 18;
  }

  c38_i65 = 0;
  for (c38_i66 = 0; c38_i66 < 3; c38_i66++) {
    for (c38_i67 = 0; c38_i67 < 3; c38_i67++) {
      c38_b_Ared[(c38_i67 + c38_i65) + 9] = 0.0;
    }

    c38_i65 += 18;
  }

  c38_i68 = 0;
  c38_i69 = 0;
  for (c38_i70 = 0; c38_i70 < 3; c38_i70++) {
    for (c38_i71 = 0; c38_i71 < 3; c38_i71++) {
      c38_b_Ared[(c38_i71 + c38_i68) + 63] = -c38_dv11[c38_i71 + c38_i69];
    }

    c38_i68 += 18;
    c38_i69 += 3;
  }

  c38_i72 = 0;
  for (c38_i73 = 0; c38_i73 < 9; c38_i73++) {
    for (c38_i74 = 0; c38_i74 < 3; c38_i74++) {
      c38_b_Ared[(c38_i74 + c38_i72) + 117] = 0.0;
    }

    c38_i72 += 18;
  }

  c38_i75 = 0;
  c38_i76 = 0;
  for (c38_i77 = 0; c38_i77 < 3; c38_i77++) {
    for (c38_i78 = 0; c38_i78 < 3; c38_i78++) {
      c38_b_Ared[(c38_i78 + c38_i75) + 279] = c38_dv12[c38_i78 + c38_i76];
    }

    c38_i75 += 18;
    c38_i76 += 3;
  }

  c38_i79 = 0;
  for (c38_i80 = 0; c38_i80 < 6; c38_i80++) {
    for (c38_i81 = 0; c38_i81 < 3; c38_i81++) {
      c38_b_Ared[(c38_i81 + c38_i79) + 333] = 0.0;
    }

    c38_i79 += 18;
  }

  c38_i82 = 0;
  c38_i83 = 0;
  for (c38_i84 = 0; c38_i84 < 3; c38_i84++) {
    for (c38_i85 = 0; c38_i85 < 3; c38_i85++) {
      c38_b_Ared[(c38_i85 + c38_i82) + 12] = -c38_dv13[c38_i85 + c38_i83];
    }

    c38_i82 += 18;
    c38_i83 += 3;
  }

  c38_i86 = 0;
  c38_i87 = 0;
  for (c38_i88 = 0; c38_i88 < 3; c38_i88++) {
    for (c38_i89 = 0; c38_i89 < 3; c38_i89++) {
      c38_b_Ared[(c38_i89 + c38_i86) + 66] = c38_c_X[c38_i89 + c38_i87];
    }

    c38_i86 += 18;
    c38_i87 += 3;
  }

  c38_i90 = 0;
  for (c38_i91 = 0; c38_i91 < 12; c38_i91++) {
    for (c38_i92 = 0; c38_i92 < 3; c38_i92++) {
      c38_b_Ared[(c38_i92 + c38_i90) + 120] = 0.0;
    }

    c38_i90 += 18;
  }

  c38_i93 = 0;
  c38_i94 = 0;
  for (c38_i95 = 0; c38_i95 < 3; c38_i95++) {
    for (c38_i96 = 0; c38_i96 < 3; c38_i96++) {
      c38_b_Ared[(c38_i96 + c38_i93) + 336] = c38_dv14[c38_i96 + c38_i94];
    }

    c38_i93 += 18;
    c38_i94 += 3;
  }

  c38_i97 = 0;
  for (c38_i98 = 0; c38_i98 < 3; c38_i98++) {
    for (c38_i99 = 0; c38_i99 < 3; c38_i99++) {
      c38_b_Ared[(c38_i99 + c38_i97) + 390] = 0.0;
    }

    c38_i97 += 18;
  }

  c38_i100 = 0;
  for (c38_i101 = 0; c38_i101 < 3; c38_i101++) {
    for (c38_i102 = 0; c38_i102 < 3; c38_i102++) {
      c38_b_Ared[(c38_i102 + c38_i100) + 15] = 0.0;
    }

    c38_i100 += 18;
  }

  c38_i103 = 0;
  c38_i104 = 0;
  for (c38_i105 = 0; c38_i105 < 3; c38_i105++) {
    for (c38_i106 = 0; c38_i106 < 3; c38_i106++) {
      c38_b_Ared[(c38_i106 + c38_i103) + 69] = -c38_dv15[c38_i106 + c38_i104];
    }

    c38_i103 += 18;
    c38_i104 += 3;
  }

  c38_i107 = 0;
  for (c38_i108 = 0; c38_i108 < 15; c38_i108++) {
    for (c38_i109 = 0; c38_i109 < 3; c38_i109++) {
      c38_b_Ared[(c38_i109 + c38_i107) + 123] = 0.0;
    }

    c38_i107 += 18;
  }

  c38_i110 = 0;
  c38_i111 = 0;
  for (c38_i112 = 0; c38_i112 < 3; c38_i112++) {
    for (c38_i113 = 0; c38_i113 < 3; c38_i113++) {
      c38_b_Ared[(c38_i113 + c38_i110) + 393] = c38_dv16[c38_i113 + c38_i111];
    }

    c38_i110 += 18;
    c38_i111 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, -2);
  _SFD_SYMBOL_SCOPE_POP();
  for (c38_i114 = 0; c38_i114 < 432; c38_i114++) {
    (*chartInstance->c38_Ared)[c38_i114] = c38_b_Ared[c38_i114];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c38_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DePascali4MMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c38_i115 = 0; c38_i115 < 432; c38_i115++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c38_Ared)[c38_i115], 1U);
  }

  for (c38_i116 = 0; c38_i116 < 28; c38_i116++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c38_x)[c38_i116], 2U);
  }
}

static void mdl_start_c38_DePascali4M(SFc38_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc38_DePascali4M(SFc38_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c38_quatrot(SFc38_DePascali4MInstanceStruct *chartInstance, real_T
  c38_q[4], real_T c38_b_r[3], real_T c38_rw[3])
{
  uint32_T c38_debug_family_var_map[6];
  real_T c38_rwq[4];
  real_T c38_nargin = 2.0;
  real_T c38_nargout = 1.0;
  int32_T c38_i117;
  real_T c38_b_q[4];
  int32_T c38_k;
  real_T c38_b_k;
  real_T c38_dv17[4];
  int32_T c38_i118;
  int32_T c38_i119;
  real_T c38_c_q[4];
  real_T c38_dv18[4];
  int32_T c38_i120;
  real_T c38_d_q[4];
  int32_T c38_i121;
  real_T c38_dv19[4];
  int32_T c38_i122;
  int32_T c38_i123;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c38_b_debug_family_names,
    c38_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c38_rwq, 0U, c38_f_sf_marshallOut,
    c38_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c38_nargin, 1U, c38_d_sf_marshallOut,
    c38_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c38_nargout, 2U, c38_d_sf_marshallOut,
    c38_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c38_q, 3U, c38_f_sf_marshallOut,
    c38_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c38_b_r, 4U, c38_e_sf_marshallOut,
    c38_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c38_rw, 5U, c38_e_sf_marshallOut,
    c38_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c38_sfEvent, 4);
  for (c38_i117 = 0; c38_i117 < 4; c38_i117++) {
    c38_b_q[c38_i117] = c38_q[c38_i117];
  }

  for (c38_k = 0; c38_k < 3; c38_k++) {
    c38_b_k = 2.0 + (real_T)c38_k;
    c38_b_q[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c38_b_k), 1, 4, 1, 0) - 1] = -c38_b_q[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", c38_b_k), 1, 4, 1, 0) - 1];
  }

  c38_dv17[0] = 0.0;
  for (c38_i118 = 0; c38_i118 < 3; c38_i118++) {
    c38_dv17[c38_i118 + 1] = c38_b_r[c38_i118];
  }

  for (c38_i119 = 0; c38_i119 < 4; c38_i119++) {
    c38_c_q[c38_i119] = c38_b_q[c38_i119];
  }

  c38_quatmultiply(chartInstance, c38_dv17, c38_c_q, c38_dv18);
  for (c38_i120 = 0; c38_i120 < 4; c38_i120++) {
    c38_d_q[c38_i120] = c38_q[c38_i120];
  }

  for (c38_i121 = 0; c38_i121 < 4; c38_i121++) {
    c38_dv19[c38_i121] = c38_dv18[c38_i121];
  }

  c38_quatmultiply(chartInstance, c38_d_q, c38_dv19, c38_b_q);
  for (c38_i122 = 0; c38_i122 < 4; c38_i122++) {
    c38_rwq[c38_i122] = c38_b_q[c38_i122];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c38_sfEvent, 5);
  for (c38_i123 = 0; c38_i123 < 3; c38_i123++) {
    c38_rw[c38_i123] = c38_rwq[c38_i123 + 1];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c38_sfEvent, -5);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c38_machineNumber, uint32_T
  c38_chartNumber, uint32_T c38_instanceNumber)
{
  (void)c38_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c38_chartNumber, c38_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Martin\\Documents\\Git\\Simulink\\DIPC - constrained\\quatrot.m"));
  _SFD_SCRIPT_TRANSLATION(c38_chartNumber, c38_instanceNumber, 1U,
    sf_debug_get_script_id(
    "C:\\Users\\Martin\\Documents\\Git\\Simulink\\DIPC - constrained\\skew_sm.m"));
}

static const mxArray *c38_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData)
{
  const mxArray *c38_mxArrayOutData = NULL;
  int32_T c38_i124;
  int32_T c38_i125;
  int32_T c38_i126;
  real_T c38_b_inData[432];
  int32_T c38_i127;
  int32_T c38_i128;
  int32_T c38_i129;
  real_T c38_u[432];
  const mxArray *c38_y = NULL;
  SFc38_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc38_DePascali4MInstanceStruct *)chartInstanceVoid;
  c38_mxArrayOutData = NULL;
  c38_i124 = 0;
  for (c38_i125 = 0; c38_i125 < 24; c38_i125++) {
    for (c38_i126 = 0; c38_i126 < 18; c38_i126++) {
      c38_b_inData[c38_i126 + c38_i124] = (*(real_T (*)[432])c38_inData)
        [c38_i126 + c38_i124];
    }

    c38_i124 += 18;
  }

  c38_i127 = 0;
  for (c38_i128 = 0; c38_i128 < 24; c38_i128++) {
    for (c38_i129 = 0; c38_i129 < 18; c38_i129++) {
      c38_u[c38_i129 + c38_i127] = c38_b_inData[c38_i129 + c38_i127];
    }

    c38_i127 += 18;
  }

  c38_y = NULL;
  sf_mex_assign(&c38_y, sf_mex_create("y", c38_u, 0, 0U, 1U, 0U, 2, 18, 24),
                false);
  sf_mex_assign(&c38_mxArrayOutData, c38_y, false);
  return c38_mxArrayOutData;
}

static void c38_emlrt_marshallIn(SFc38_DePascali4MInstanceStruct *chartInstance,
  const mxArray *c38_b_Ared, const char_T *c38_identifier, real_T c38_y[432])
{
  emlrtMsgIdentifier c38_thisId;
  c38_thisId.fIdentifier = c38_identifier;
  c38_thisId.fParent = NULL;
  c38_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c38_b_Ared), &c38_thisId,
    c38_y);
  sf_mex_destroy(&c38_b_Ared);
}

static void c38_b_emlrt_marshallIn(SFc38_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId,
  real_T c38_y[432])
{
  real_T c38_dv20[432];
  int32_T c38_i130;
  (void)chartInstance;
  sf_mex_import(c38_parentId, sf_mex_dup(c38_u), c38_dv20, 1, 0, 0U, 1, 0U, 2,
                18, 24);
  for (c38_i130 = 0; c38_i130 < 432; c38_i130++) {
    c38_y[c38_i130] = c38_dv20[c38_i130];
  }

  sf_mex_destroy(&c38_u);
}

static void c38_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData)
{
  const mxArray *c38_b_Ared;
  const char_T *c38_identifier;
  emlrtMsgIdentifier c38_thisId;
  real_T c38_y[432];
  int32_T c38_i131;
  int32_T c38_i132;
  int32_T c38_i133;
  SFc38_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc38_DePascali4MInstanceStruct *)chartInstanceVoid;
  c38_b_Ared = sf_mex_dup(c38_mxArrayInData);
  c38_identifier = c38_varName;
  c38_thisId.fIdentifier = c38_identifier;
  c38_thisId.fParent = NULL;
  c38_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c38_b_Ared), &c38_thisId,
    c38_y);
  sf_mex_destroy(&c38_b_Ared);
  c38_i131 = 0;
  for (c38_i132 = 0; c38_i132 < 24; c38_i132++) {
    for (c38_i133 = 0; c38_i133 < 18; c38_i133++) {
      (*(real_T (*)[432])c38_outData)[c38_i133 + c38_i131] = c38_y[c38_i133 +
        c38_i131];
    }

    c38_i131 += 18;
  }

  sf_mex_destroy(&c38_mxArrayInData);
}

static const mxArray *c38_b_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData)
{
  const mxArray *c38_mxArrayOutData = NULL;
  int32_T c38_i134;
  real_T c38_b_inData[28];
  int32_T c38_i135;
  real_T c38_u[28];
  const mxArray *c38_y = NULL;
  SFc38_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc38_DePascali4MInstanceStruct *)chartInstanceVoid;
  c38_mxArrayOutData = NULL;
  for (c38_i134 = 0; c38_i134 < 28; c38_i134++) {
    c38_b_inData[c38_i134] = (*(real_T (*)[28])c38_inData)[c38_i134];
  }

  for (c38_i135 = 0; c38_i135 < 28; c38_i135++) {
    c38_u[c38_i135] = c38_b_inData[c38_i135];
  }

  c38_y = NULL;
  sf_mex_assign(&c38_y, sf_mex_create("y", c38_u, 0, 0U, 1U, 0U, 1, 28), false);
  sf_mex_assign(&c38_mxArrayOutData, c38_y, false);
  return c38_mxArrayOutData;
}

static const mxArray *c38_c_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData)
{
  const mxArray *c38_mxArrayOutData = NULL;
  int32_T c38_i136;
  real_T c38_b_inData[12];
  int32_T c38_i137;
  real_T c38_u[12];
  const mxArray *c38_y = NULL;
  SFc38_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc38_DePascali4MInstanceStruct *)chartInstanceVoid;
  c38_mxArrayOutData = NULL;
  for (c38_i136 = 0; c38_i136 < 12; c38_i136++) {
    c38_b_inData[c38_i136] = (*(real_T (*)[12])c38_inData)[c38_i136];
  }

  for (c38_i137 = 0; c38_i137 < 12; c38_i137++) {
    c38_u[c38_i137] = c38_b_inData[c38_i137];
  }

  c38_y = NULL;
  sf_mex_assign(&c38_y, sf_mex_create("y", c38_u, 0, 0U, 1U, 0U, 1, 12), false);
  sf_mex_assign(&c38_mxArrayOutData, c38_y, false);
  return c38_mxArrayOutData;
}

static void c38_c_emlrt_marshallIn(SFc38_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId,
  real_T c38_y[12])
{
  real_T c38_dv21[12];
  int32_T c38_i138;
  (void)chartInstance;
  sf_mex_import(c38_parentId, sf_mex_dup(c38_u), c38_dv21, 1, 0, 0U, 1, 0U, 1,
                12);
  for (c38_i138 = 0; c38_i138 < 12; c38_i138++) {
    c38_y[c38_i138] = c38_dv21[c38_i138];
  }

  sf_mex_destroy(&c38_u);
}

static void c38_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData)
{
  const mxArray *c38_b_r;
  const char_T *c38_identifier;
  emlrtMsgIdentifier c38_thisId;
  real_T c38_y[12];
  int32_T c38_i139;
  SFc38_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc38_DePascali4MInstanceStruct *)chartInstanceVoid;
  c38_b_r = sf_mex_dup(c38_mxArrayInData);
  c38_identifier = c38_varName;
  c38_thisId.fIdentifier = c38_identifier;
  c38_thisId.fParent = NULL;
  c38_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c38_b_r), &c38_thisId, c38_y);
  sf_mex_destroy(&c38_b_r);
  for (c38_i139 = 0; c38_i139 < 12; c38_i139++) {
    (*(real_T (*)[12])c38_outData)[c38_i139] = c38_y[c38_i139];
  }

  sf_mex_destroy(&c38_mxArrayInData);
}

static const mxArray *c38_d_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData)
{
  const mxArray *c38_mxArrayOutData = NULL;
  real_T c38_u;
  const mxArray *c38_y = NULL;
  SFc38_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc38_DePascali4MInstanceStruct *)chartInstanceVoid;
  c38_mxArrayOutData = NULL;
  c38_u = *(real_T *)c38_inData;
  c38_y = NULL;
  sf_mex_assign(&c38_y, sf_mex_create("y", &c38_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c38_mxArrayOutData, c38_y, false);
  return c38_mxArrayOutData;
}

static real_T c38_d_emlrt_marshallIn(SFc38_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId)
{
  real_T c38_y;
  real_T c38_d0;
  (void)chartInstance;
  sf_mex_import(c38_parentId, sf_mex_dup(c38_u), &c38_d0, 1, 0, 0U, 0, 0U, 0);
  c38_y = c38_d0;
  sf_mex_destroy(&c38_u);
  return c38_y;
}

static void c38_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData)
{
  const mxArray *c38_nargout;
  const char_T *c38_identifier;
  emlrtMsgIdentifier c38_thisId;
  real_T c38_y;
  SFc38_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc38_DePascali4MInstanceStruct *)chartInstanceVoid;
  c38_nargout = sf_mex_dup(c38_mxArrayInData);
  c38_identifier = c38_varName;
  c38_thisId.fIdentifier = c38_identifier;
  c38_thisId.fParent = NULL;
  c38_y = c38_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c38_nargout),
    &c38_thisId);
  sf_mex_destroy(&c38_nargout);
  *(real_T *)c38_outData = c38_y;
  sf_mex_destroy(&c38_mxArrayInData);
}

static const mxArray *c38_e_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData)
{
  const mxArray *c38_mxArrayOutData = NULL;
  int32_T c38_i140;
  real_T c38_b_inData[3];
  int32_T c38_i141;
  real_T c38_u[3];
  const mxArray *c38_y = NULL;
  SFc38_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc38_DePascali4MInstanceStruct *)chartInstanceVoid;
  c38_mxArrayOutData = NULL;
  for (c38_i140 = 0; c38_i140 < 3; c38_i140++) {
    c38_b_inData[c38_i140] = (*(real_T (*)[3])c38_inData)[c38_i140];
  }

  for (c38_i141 = 0; c38_i141 < 3; c38_i141++) {
    c38_u[c38_i141] = c38_b_inData[c38_i141];
  }

  c38_y = NULL;
  sf_mex_assign(&c38_y, sf_mex_create("y", c38_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c38_mxArrayOutData, c38_y, false);
  return c38_mxArrayOutData;
}

static void c38_e_emlrt_marshallIn(SFc38_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId,
  real_T c38_y[3])
{
  real_T c38_dv22[3];
  int32_T c38_i142;
  (void)chartInstance;
  sf_mex_import(c38_parentId, sf_mex_dup(c38_u), c38_dv22, 1, 0, 0U, 1, 0U, 1, 3);
  for (c38_i142 = 0; c38_i142 < 3; c38_i142++) {
    c38_y[c38_i142] = c38_dv22[c38_i142];
  }

  sf_mex_destroy(&c38_u);
}

static void c38_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData)
{
  const mxArray *c38_rw;
  const char_T *c38_identifier;
  emlrtMsgIdentifier c38_thisId;
  real_T c38_y[3];
  int32_T c38_i143;
  SFc38_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc38_DePascali4MInstanceStruct *)chartInstanceVoid;
  c38_rw = sf_mex_dup(c38_mxArrayInData);
  c38_identifier = c38_varName;
  c38_thisId.fIdentifier = c38_identifier;
  c38_thisId.fParent = NULL;
  c38_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c38_rw), &c38_thisId, c38_y);
  sf_mex_destroy(&c38_rw);
  for (c38_i143 = 0; c38_i143 < 3; c38_i143++) {
    (*(real_T (*)[3])c38_outData)[c38_i143] = c38_y[c38_i143];
  }

  sf_mex_destroy(&c38_mxArrayInData);
}

static const mxArray *c38_f_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData)
{
  const mxArray *c38_mxArrayOutData = NULL;
  int32_T c38_i144;
  real_T c38_b_inData[4];
  int32_T c38_i145;
  real_T c38_u[4];
  const mxArray *c38_y = NULL;
  SFc38_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc38_DePascali4MInstanceStruct *)chartInstanceVoid;
  c38_mxArrayOutData = NULL;
  for (c38_i144 = 0; c38_i144 < 4; c38_i144++) {
    c38_b_inData[c38_i144] = (*(real_T (*)[4])c38_inData)[c38_i144];
  }

  for (c38_i145 = 0; c38_i145 < 4; c38_i145++) {
    c38_u[c38_i145] = c38_b_inData[c38_i145];
  }

  c38_y = NULL;
  sf_mex_assign(&c38_y, sf_mex_create("y", c38_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c38_mxArrayOutData, c38_y, false);
  return c38_mxArrayOutData;
}

static void c38_f_emlrt_marshallIn(SFc38_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId,
  real_T c38_y[4])
{
  real_T c38_dv23[4];
  int32_T c38_i146;
  (void)chartInstance;
  sf_mex_import(c38_parentId, sf_mex_dup(c38_u), c38_dv23, 1, 0, 0U, 1, 0U, 1, 4);
  for (c38_i146 = 0; c38_i146 < 4; c38_i146++) {
    c38_y[c38_i146] = c38_dv23[c38_i146];
  }

  sf_mex_destroy(&c38_u);
}

static void c38_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData)
{
  const mxArray *c38_q;
  const char_T *c38_identifier;
  emlrtMsgIdentifier c38_thisId;
  real_T c38_y[4];
  int32_T c38_i147;
  SFc38_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc38_DePascali4MInstanceStruct *)chartInstanceVoid;
  c38_q = sf_mex_dup(c38_mxArrayInData);
  c38_identifier = c38_varName;
  c38_thisId.fIdentifier = c38_identifier;
  c38_thisId.fParent = NULL;
  c38_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c38_q), &c38_thisId, c38_y);
  sf_mex_destroy(&c38_q);
  for (c38_i147 = 0; c38_i147 < 4; c38_i147++) {
    (*(real_T (*)[4])c38_outData)[c38_i147] = c38_y[c38_i147];
  }

  sf_mex_destroy(&c38_mxArrayInData);
}

static const mxArray *c38_g_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData)
{
  const mxArray *c38_mxArrayOutData = NULL;
  int32_T c38_i148;
  int32_T c38_i149;
  int32_T c38_i150;
  real_T c38_b_inData[9];
  int32_T c38_i151;
  int32_T c38_i152;
  int32_T c38_i153;
  real_T c38_u[9];
  const mxArray *c38_y = NULL;
  SFc38_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc38_DePascali4MInstanceStruct *)chartInstanceVoid;
  c38_mxArrayOutData = NULL;
  c38_i148 = 0;
  for (c38_i149 = 0; c38_i149 < 3; c38_i149++) {
    for (c38_i150 = 0; c38_i150 < 3; c38_i150++) {
      c38_b_inData[c38_i150 + c38_i148] = (*(real_T (*)[9])c38_inData)[c38_i150
        + c38_i148];
    }

    c38_i148 += 3;
  }

  c38_i151 = 0;
  for (c38_i152 = 0; c38_i152 < 3; c38_i152++) {
    for (c38_i153 = 0; c38_i153 < 3; c38_i153++) {
      c38_u[c38_i153 + c38_i151] = c38_b_inData[c38_i153 + c38_i151];
    }

    c38_i151 += 3;
  }

  c38_y = NULL;
  sf_mex_assign(&c38_y, sf_mex_create("y", c38_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c38_mxArrayOutData, c38_y, false);
  return c38_mxArrayOutData;
}

static void c38_g_emlrt_marshallIn(SFc38_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId,
  real_T c38_y[9])
{
  real_T c38_dv24[9];
  int32_T c38_i154;
  (void)chartInstance;
  sf_mex_import(c38_parentId, sf_mex_dup(c38_u), c38_dv24, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c38_i154 = 0; c38_i154 < 9; c38_i154++) {
    c38_y[c38_i154] = c38_dv24[c38_i154];
  }

  sf_mex_destroy(&c38_u);
}

static void c38_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData)
{
  const mxArray *c38_X;
  const char_T *c38_identifier;
  emlrtMsgIdentifier c38_thisId;
  real_T c38_y[9];
  int32_T c38_i155;
  int32_T c38_i156;
  int32_T c38_i157;
  SFc38_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc38_DePascali4MInstanceStruct *)chartInstanceVoid;
  c38_X = sf_mex_dup(c38_mxArrayInData);
  c38_identifier = c38_varName;
  c38_thisId.fIdentifier = c38_identifier;
  c38_thisId.fParent = NULL;
  c38_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c38_X), &c38_thisId, c38_y);
  sf_mex_destroy(&c38_X);
  c38_i155 = 0;
  for (c38_i156 = 0; c38_i156 < 3; c38_i156++) {
    for (c38_i157 = 0; c38_i157 < 3; c38_i157++) {
      (*(real_T (*)[9])c38_outData)[c38_i157 + c38_i155] = c38_y[c38_i157 +
        c38_i155];
    }

    c38_i155 += 3;
  }

  sf_mex_destroy(&c38_mxArrayInData);
}

const mxArray *sf_c38_DePascali4M_get_eml_resolved_functions_info(void)
{
  const mxArray *c38_nameCaptureInfo = NULL;
  c38_nameCaptureInfo = NULL;
  sf_mex_assign(&c38_nameCaptureInfo, sf_mex_createstruct("structure", 2, 34, 1),
                false);
  c38_info_helper(&c38_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c38_nameCaptureInfo);
  return c38_nameCaptureInfo;
}

static void c38_info_helper(const mxArray **c38_info)
{
  const mxArray *c38_rhs0 = NULL;
  const mxArray *c38_lhs0 = NULL;
  const mxArray *c38_rhs1 = NULL;
  const mxArray *c38_lhs1 = NULL;
  const mxArray *c38_rhs2 = NULL;
  const mxArray *c38_lhs2 = NULL;
  const mxArray *c38_rhs3 = NULL;
  const mxArray *c38_lhs3 = NULL;
  const mxArray *c38_rhs4 = NULL;
  const mxArray *c38_lhs4 = NULL;
  const mxArray *c38_rhs5 = NULL;
  const mxArray *c38_lhs5 = NULL;
  const mxArray *c38_rhs6 = NULL;
  const mxArray *c38_lhs6 = NULL;
  const mxArray *c38_rhs7 = NULL;
  const mxArray *c38_lhs7 = NULL;
  const mxArray *c38_rhs8 = NULL;
  const mxArray *c38_lhs8 = NULL;
  const mxArray *c38_rhs9 = NULL;
  const mxArray *c38_lhs9 = NULL;
  const mxArray *c38_rhs10 = NULL;
  const mxArray *c38_lhs10 = NULL;
  const mxArray *c38_rhs11 = NULL;
  const mxArray *c38_lhs11 = NULL;
  const mxArray *c38_rhs12 = NULL;
  const mxArray *c38_lhs12 = NULL;
  const mxArray *c38_rhs13 = NULL;
  const mxArray *c38_lhs13 = NULL;
  const mxArray *c38_rhs14 = NULL;
  const mxArray *c38_lhs14 = NULL;
  const mxArray *c38_rhs15 = NULL;
  const mxArray *c38_lhs15 = NULL;
  const mxArray *c38_rhs16 = NULL;
  const mxArray *c38_lhs16 = NULL;
  const mxArray *c38_rhs17 = NULL;
  const mxArray *c38_lhs17 = NULL;
  const mxArray *c38_rhs18 = NULL;
  const mxArray *c38_lhs18 = NULL;
  const mxArray *c38_rhs19 = NULL;
  const mxArray *c38_lhs19 = NULL;
  const mxArray *c38_rhs20 = NULL;
  const mxArray *c38_lhs20 = NULL;
  const mxArray *c38_rhs21 = NULL;
  const mxArray *c38_lhs21 = NULL;
  const mxArray *c38_rhs22 = NULL;
  const mxArray *c38_lhs22 = NULL;
  const mxArray *c38_rhs23 = NULL;
  const mxArray *c38_lhs23 = NULL;
  const mxArray *c38_rhs24 = NULL;
  const mxArray *c38_lhs24 = NULL;
  const mxArray *c38_rhs25 = NULL;
  const mxArray *c38_lhs25 = NULL;
  const mxArray *c38_rhs26 = NULL;
  const mxArray *c38_lhs26 = NULL;
  const mxArray *c38_rhs27 = NULL;
  const mxArray *c38_lhs27 = NULL;
  const mxArray *c38_rhs28 = NULL;
  const mxArray *c38_lhs28 = NULL;
  const mxArray *c38_rhs29 = NULL;
  const mxArray *c38_lhs29 = NULL;
  const mxArray *c38_rhs30 = NULL;
  const mxArray *c38_lhs30 = NULL;
  const mxArray *c38_rhs31 = NULL;
  const mxArray *c38_lhs31 = NULL;
  const mxArray *c38_rhs32 = NULL;
  const mxArray *c38_lhs32 = NULL;
  const mxArray *c38_rhs33 = NULL;
  const mxArray *c38_lhs33 = NULL;
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("eye"), "name", "name", 0);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1406838348U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c38_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 1);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1368208230U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c38_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c38_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral"),
                  "context", "context", 3);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("isinf"), "name", "name", 3);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1363739056U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c38_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c38_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 5);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("eml_is_integer_class"),
                  "name", "name", 5);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1286843982U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c38_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 6);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("intmax"), "name", "name", 6);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c38_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 7);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c38_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 8);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("intmin"), "name", "name", 8);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c38_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 9);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c38_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 10);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "coder.internal.indexIntRelop"), "name", "name", 10);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1326753522U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c38_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!apply_float_relop"),
                  "context", "context", 11);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 11);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c38_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass"),
                  "context", "context", 12);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 12);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1326753196U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c38_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass"),
                  "context", "context", 13);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("intmin"), "name", "name", 13);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c38_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 14);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 14);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c38_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("intmax"), "name", "name", 15);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c38_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 16);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1397282622U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c38_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 17);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("isfi"), "name", "name", 17);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 17);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1346535558U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c38_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 18);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1398900798U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c38_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 19);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("intmax"), "name", "name", 19);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c38_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 20);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("intmin"), "name", "name", 20);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c38_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(""), "context", "context", 21);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("quatrot"), "name", "name",
                  21);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DIPC - constrained/quatrot.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1446631716U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c38_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DIPC - constrained/quatrot.m"),
                  "context", "context", 22);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("quatconj"), "name", "name",
                  22);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatconj.p"), "resolved", "resolved",
                  22);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1410808258U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c38_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DIPC - constrained/quatrot.m"),
                  "context", "context", 23);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("quatmultiply"), "name",
                  "name", 23);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatmultiply.p"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1410808258U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c38_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatmultiply.p"), "context",
                  "context", 24);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("max"), "name", "name", 24);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1311280516U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c38_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 25);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1378321184U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c38_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 26);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 26);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c38_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 27);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c38_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 28);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 28);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c38_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 29);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 29);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c38_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 30);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 30);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c38_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 31);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 31);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c38_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 32);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 32);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c38_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(""), "context", "context", 33);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("skew_sm"), "name", "name",
                  33);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DIPC - constrained/skew_sm.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1445505143U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c38_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs33), "lhs", "lhs",
                  33);
  sf_mex_destroy(&c38_rhs0);
  sf_mex_destroy(&c38_lhs0);
  sf_mex_destroy(&c38_rhs1);
  sf_mex_destroy(&c38_lhs1);
  sf_mex_destroy(&c38_rhs2);
  sf_mex_destroy(&c38_lhs2);
  sf_mex_destroy(&c38_rhs3);
  sf_mex_destroy(&c38_lhs3);
  sf_mex_destroy(&c38_rhs4);
  sf_mex_destroy(&c38_lhs4);
  sf_mex_destroy(&c38_rhs5);
  sf_mex_destroy(&c38_lhs5);
  sf_mex_destroy(&c38_rhs6);
  sf_mex_destroy(&c38_lhs6);
  sf_mex_destroy(&c38_rhs7);
  sf_mex_destroy(&c38_lhs7);
  sf_mex_destroy(&c38_rhs8);
  sf_mex_destroy(&c38_lhs8);
  sf_mex_destroy(&c38_rhs9);
  sf_mex_destroy(&c38_lhs9);
  sf_mex_destroy(&c38_rhs10);
  sf_mex_destroy(&c38_lhs10);
  sf_mex_destroy(&c38_rhs11);
  sf_mex_destroy(&c38_lhs11);
  sf_mex_destroy(&c38_rhs12);
  sf_mex_destroy(&c38_lhs12);
  sf_mex_destroy(&c38_rhs13);
  sf_mex_destroy(&c38_lhs13);
  sf_mex_destroy(&c38_rhs14);
  sf_mex_destroy(&c38_lhs14);
  sf_mex_destroy(&c38_rhs15);
  sf_mex_destroy(&c38_lhs15);
  sf_mex_destroy(&c38_rhs16);
  sf_mex_destroy(&c38_lhs16);
  sf_mex_destroy(&c38_rhs17);
  sf_mex_destroy(&c38_lhs17);
  sf_mex_destroy(&c38_rhs18);
  sf_mex_destroy(&c38_lhs18);
  sf_mex_destroy(&c38_rhs19);
  sf_mex_destroy(&c38_lhs19);
  sf_mex_destroy(&c38_rhs20);
  sf_mex_destroy(&c38_lhs20);
  sf_mex_destroy(&c38_rhs21);
  sf_mex_destroy(&c38_lhs21);
  sf_mex_destroy(&c38_rhs22);
  sf_mex_destroy(&c38_lhs22);
  sf_mex_destroy(&c38_rhs23);
  sf_mex_destroy(&c38_lhs23);
  sf_mex_destroy(&c38_rhs24);
  sf_mex_destroy(&c38_lhs24);
  sf_mex_destroy(&c38_rhs25);
  sf_mex_destroy(&c38_lhs25);
  sf_mex_destroy(&c38_rhs26);
  sf_mex_destroy(&c38_lhs26);
  sf_mex_destroy(&c38_rhs27);
  sf_mex_destroy(&c38_lhs27);
  sf_mex_destroy(&c38_rhs28);
  sf_mex_destroy(&c38_lhs28);
  sf_mex_destroy(&c38_rhs29);
  sf_mex_destroy(&c38_lhs29);
  sf_mex_destroy(&c38_rhs30);
  sf_mex_destroy(&c38_lhs30);
  sf_mex_destroy(&c38_rhs31);
  sf_mex_destroy(&c38_lhs31);
  sf_mex_destroy(&c38_rhs32);
  sf_mex_destroy(&c38_lhs32);
  sf_mex_destroy(&c38_rhs33);
  sf_mex_destroy(&c38_lhs33);
}

static const mxArray *c38_emlrt_marshallOut(const char * c38_u)
{
  const mxArray *c38_y = NULL;
  c38_y = NULL;
  sf_mex_assign(&c38_y, sf_mex_create("y", c38_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c38_u)), false);
  return c38_y;
}

static const mxArray *c38_b_emlrt_marshallOut(const uint32_T c38_u)
{
  const mxArray *c38_y = NULL;
  c38_y = NULL;
  sf_mex_assign(&c38_y, sf_mex_create("y", &c38_u, 7, 0U, 0U, 0U, 0), false);
  return c38_y;
}

static void c38_eye(SFc38_DePascali4MInstanceStruct *chartInstance, real_T
                    c38_I[9])
{
  int32_T c38_i158;
  int32_T c38_k;
  int32_T c38_b_k;
  (void)chartInstance;
  for (c38_i158 = 0; c38_i158 < 9; c38_i158++) {
    c38_I[c38_i158] = 0.0;
  }

  for (c38_k = 1; c38_k < 4; c38_k++) {
    c38_b_k = c38_k;
    c38_I[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
             (real_T)c38_b_k), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c38_b_k), 1, 3, 2, 0) - 1))
      - 1] = 1.0;
  }
}

static void c38_quatmultiply(SFc38_DePascali4MInstanceStruct *chartInstance,
  real_T c38_q[4], real_T c38_b_r[4], real_T c38_qout[4])
{
  real_T c38_q1;
  real_T c38_q2;
  real_T c38_q3;
  real_T c38_q4;
  real_T c38_r1;
  real_T c38_r2;
  real_T c38_r3;
  real_T c38_r4;
  (void)chartInstance;
  c38_q1 = c38_q[0];
  c38_q2 = c38_q[1];
  c38_q3 = c38_q[2];
  c38_q4 = c38_q[3];
  c38_r1 = c38_b_r[0];
  c38_r2 = c38_b_r[1];
  c38_r3 = c38_b_r[2];
  c38_r4 = c38_b_r[3];
  c38_qout[0] = ((c38_q1 * c38_r1 - c38_q2 * c38_r2) - c38_q3 * c38_r3) - c38_q4
    * c38_r4;
  c38_qout[1] = (c38_q1 * c38_r2 + c38_r1 * c38_q2) + (c38_q3 * c38_r4 - c38_q4 *
    c38_r3);
  c38_qout[2] = (c38_q1 * c38_r3 + c38_r1 * c38_q3) + (c38_q4 * c38_r2 - c38_q2 *
    c38_r4);
  c38_qout[3] = (c38_q1 * c38_r4 + c38_r1 * c38_q4) + (c38_q2 * c38_r3 - c38_q3 *
    c38_r2);
}

static const mxArray *c38_h_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData)
{
  const mxArray *c38_mxArrayOutData = NULL;
  int32_T c38_u;
  const mxArray *c38_y = NULL;
  SFc38_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc38_DePascali4MInstanceStruct *)chartInstanceVoid;
  c38_mxArrayOutData = NULL;
  c38_u = *(int32_T *)c38_inData;
  c38_y = NULL;
  sf_mex_assign(&c38_y, sf_mex_create("y", &c38_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c38_mxArrayOutData, c38_y, false);
  return c38_mxArrayOutData;
}

static int32_T c38_h_emlrt_marshallIn(SFc38_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId)
{
  int32_T c38_y;
  int32_T c38_i159;
  (void)chartInstance;
  sf_mex_import(c38_parentId, sf_mex_dup(c38_u), &c38_i159, 1, 6, 0U, 0, 0U, 0);
  c38_y = c38_i159;
  sf_mex_destroy(&c38_u);
  return c38_y;
}

static void c38_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData)
{
  const mxArray *c38_b_sfEvent;
  const char_T *c38_identifier;
  emlrtMsgIdentifier c38_thisId;
  int32_T c38_y;
  SFc38_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc38_DePascali4MInstanceStruct *)chartInstanceVoid;
  c38_b_sfEvent = sf_mex_dup(c38_mxArrayInData);
  c38_identifier = c38_varName;
  c38_thisId.fIdentifier = c38_identifier;
  c38_thisId.fParent = NULL;
  c38_y = c38_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c38_b_sfEvent),
    &c38_thisId);
  sf_mex_destroy(&c38_b_sfEvent);
  *(int32_T *)c38_outData = c38_y;
  sf_mex_destroy(&c38_mxArrayInData);
}

static uint8_T c38_i_emlrt_marshallIn(SFc38_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c38_b_is_active_c38_DePascali4M, const char_T
  *c38_identifier)
{
  uint8_T c38_y;
  emlrtMsgIdentifier c38_thisId;
  c38_thisId.fIdentifier = c38_identifier;
  c38_thisId.fParent = NULL;
  c38_y = c38_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c38_b_is_active_c38_DePascali4M), &c38_thisId);
  sf_mex_destroy(&c38_b_is_active_c38_DePascali4M);
  return c38_y;
}

static uint8_T c38_j_emlrt_marshallIn(SFc38_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId)
{
  uint8_T c38_y;
  uint8_T c38_u0;
  (void)chartInstance;
  sf_mex_import(c38_parentId, sf_mex_dup(c38_u), &c38_u0, 1, 3, 0U, 0, 0U, 0);
  c38_y = c38_u0;
  sf_mex_destroy(&c38_u);
  return c38_y;
}

static void init_dsm_address_info(SFc38_DePascali4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc38_DePascali4MInstanceStruct
  *chartInstance)
{
  chartInstance->c38_Ared = (real_T (*)[432])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c38_x = (real_T (*)[28])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
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

void sf_c38_DePascali4M_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3983115216U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(795050607U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3947910735U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(761940546U);
}

mxArray* sf_c38_DePascali4M_get_post_codegen_info(void);
mxArray *sf_c38_DePascali4M_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("2DzyioPLwtmX08rJePnILC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
      pr[0] = (double)(18);
      pr[1] = (double)(24);
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
    mxArray* mxPostCodegenInfo = sf_c38_DePascali4M_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c38_DePascali4M_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c38_DePascali4M_jit_fallback_info(void)
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

mxArray *sf_c38_DePascali4M_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c38_DePascali4M_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c38_DePascali4M(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Ared\",},{M[8],M[0],T\"is_active_c38_DePascali4M\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c38_DePascali4M_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc38_DePascali4MInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc38_DePascali4MInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DePascali4MMachineNumber_,
           38,
           1,
           1,
           0,
           3,
           0,
           0,
           0,
           0,
           2,
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
          _SFD_SET_DATA_PROPS(0,10,0,0,"r");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Ared");
          _SFD_SET_DATA_PROPS(2,1,1,0,"x");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,445);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"quatrot",0,-1,191);
        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"skew_sm",0,-1,127);

        {
          unsigned int dimVector[1];
          dimVector[0]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c38_c_sf_marshallOut,(MexInFcnForType)
            c38_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 18;
          dimVector[1]= 24;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c38_sf_marshallOut,(MexInFcnForType)
            c38_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 28;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c38_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c38_r);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c38_Ared);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c38_x);
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
  return "KoBjyPLZLMM3KD77IWLpFB";
}

static void sf_opaque_initialize_c38_DePascali4M(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc38_DePascali4MInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c38_DePascali4M((SFc38_DePascali4MInstanceStruct*)
    chartInstanceVar);
  initialize_c38_DePascali4M((SFc38_DePascali4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c38_DePascali4M(void *chartInstanceVar)
{
  enable_c38_DePascali4M((SFc38_DePascali4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c38_DePascali4M(void *chartInstanceVar)
{
  disable_c38_DePascali4M((SFc38_DePascali4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c38_DePascali4M(void *chartInstanceVar)
{
  sf_gateway_c38_DePascali4M((SFc38_DePascali4MInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c38_DePascali4M(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c38_DePascali4M((SFc38_DePascali4MInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c38_DePascali4M(SimStruct* S, const mxArray *
  st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c38_DePascali4M((SFc38_DePascali4MInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c38_DePascali4M(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc38_DePascali4MInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DePascali4M_optimization_info();
    }

    finalize_c38_DePascali4M((SFc38_DePascali4MInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc38_DePascali4M((SFc38_DePascali4MInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c38_DePascali4M(SimStruct *S)
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
    initialize_params_c38_DePascali4M((SFc38_DePascali4MInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c38_DePascali4M(SimStruct *S)
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
      38);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,38,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,38,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,38);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,38,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,38,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,38);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(107690761U));
  ssSetChecksum1(S,(1410728348U));
  ssSetChecksum2(S,(3026597884U));
  ssSetChecksum3(S,(3672240086U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c38_DePascali4M(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c38_DePascali4M(SimStruct *S)
{
  SFc38_DePascali4MInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc38_DePascali4MInstanceStruct *)utMalloc(sizeof
    (SFc38_DePascali4MInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc38_DePascali4MInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c38_DePascali4M;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c38_DePascali4M;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c38_DePascali4M;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c38_DePascali4M;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c38_DePascali4M;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c38_DePascali4M;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c38_DePascali4M;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c38_DePascali4M;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c38_DePascali4M;
  chartInstance->chartInfo.mdlStart = mdlStart_c38_DePascali4M;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c38_DePascali4M;
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

void c38_DePascali4M_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c38_DePascali4M(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c38_DePascali4M(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c38_DePascali4M(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c38_DePascali4M_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

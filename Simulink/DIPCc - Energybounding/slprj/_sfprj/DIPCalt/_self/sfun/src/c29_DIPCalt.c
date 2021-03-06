/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DIPCalt_sfun.h"
#include "c29_DIPCalt.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DIPCalt_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c29_debug_family_names[5] = { "nargin", "nargout", "rv", "x",
  "A" };

static const char * c29_b_debug_family_names[6] = { "rwq", "nargin", "nargout",
  "q", "r", "rw" };

static const char * c29_c_debug_family_names[4] = { "nargin", "nargout", "x",
  "X" };

/* Function Declarations */
static void initialize_c29_DIPCalt(SFc29_DIPCaltInstanceStruct *chartInstance);
static void initialize_params_c29_DIPCalt(SFc29_DIPCaltInstanceStruct
  *chartInstance);
static void enable_c29_DIPCalt(SFc29_DIPCaltInstanceStruct *chartInstance);
static void disable_c29_DIPCalt(SFc29_DIPCaltInstanceStruct *chartInstance);
static void c29_update_debugger_state_c29_DIPCalt(SFc29_DIPCaltInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c29_DIPCalt(SFc29_DIPCaltInstanceStruct
  *chartInstance);
static void set_sim_state_c29_DIPCalt(SFc29_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c29_st);
static void finalize_c29_DIPCalt(SFc29_DIPCaltInstanceStruct *chartInstance);
static void sf_gateway_c29_DIPCalt(SFc29_DIPCaltInstanceStruct *chartInstance);
static void mdl_start_c29_DIPCalt(SFc29_DIPCaltInstanceStruct *chartInstance);
static void initSimStructsc29_DIPCalt(SFc29_DIPCaltInstanceStruct *chartInstance);
static void c29_quatrot(SFc29_DIPCaltInstanceStruct *chartInstance, real_T
  c29_q[4], real_T c29_r[3], real_T c29_rw[3]);
static void init_script_number_translation(uint32_T c29_machineNumber, uint32_T
  c29_chartNumber, uint32_T c29_instanceNumber);
static const mxArray *c29_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData);
static void c29_emlrt_marshallIn(SFc29_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c29_b_A, const char_T *c29_identifier, real_T c29_y[720]);
static void c29_b_emlrt_marshallIn(SFc29_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId, real_T c29_y[720]);
static void c29_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData);
static const mxArray *c29_b_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData);
static const mxArray *c29_c_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData);
static void c29_c_emlrt_marshallIn(SFc29_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId, real_T c29_y[12]);
static void c29_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData);
static const mxArray *c29_d_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData);
static real_T c29_d_emlrt_marshallIn(SFc29_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId);
static void c29_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData);
static const mxArray *c29_e_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData);
static void c29_e_emlrt_marshallIn(SFc29_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId, real_T c29_y[3]);
static void c29_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData);
static const mxArray *c29_f_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData);
static void c29_f_emlrt_marshallIn(SFc29_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId, real_T c29_y[4]);
static void c29_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData);
static const mxArray *c29_g_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData);
static void c29_g_emlrt_marshallIn(SFc29_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId, real_T c29_y[9]);
static void c29_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData);
static void c29_info_helper(const mxArray **c29_info);
static const mxArray *c29_emlrt_marshallOut(const char * c29_u);
static const mxArray *c29_b_emlrt_marshallOut(const uint32_T c29_u);
static void c29_eye(SFc29_DIPCaltInstanceStruct *chartInstance, real_T c29_I[9]);
static void c29_quatmultiply(SFc29_DIPCaltInstanceStruct *chartInstance, real_T
  c29_q[4], real_T c29_r[4], real_T c29_qout[4]);
static const mxArray *c29_h_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData);
static int32_T c29_h_emlrt_marshallIn(SFc29_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId);
static void c29_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData);
static uint8_T c29_i_emlrt_marshallIn(SFc29_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c29_b_is_active_c29_DIPCalt, const char_T *c29_identifier);
static uint8_T c29_j_emlrt_marshallIn(SFc29_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId);
static void init_dsm_address_info(SFc29_DIPCaltInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc29_DIPCaltInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c29_DIPCalt(SFc29_DIPCaltInstanceStruct *chartInstance)
{
  chartInstance->c29_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c29_is_active_c29_DIPCalt = 0U;
}

static void initialize_params_c29_DIPCalt(SFc29_DIPCaltInstanceStruct
  *chartInstance)
{
  real_T c29_dv0[12];
  int32_T c29_i0;
  sf_mex_import_named("rv", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      c29_dv0, 0, 0, 0U, 1, 0U, 1, 12);
  for (c29_i0 = 0; c29_i0 < 12; c29_i0++) {
    chartInstance->c29_rv[c29_i0] = c29_dv0[c29_i0];
  }
}

static void enable_c29_DIPCalt(SFc29_DIPCaltInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c29_DIPCalt(SFc29_DIPCaltInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c29_update_debugger_state_c29_DIPCalt(SFc29_DIPCaltInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c29_DIPCalt(SFc29_DIPCaltInstanceStruct
  *chartInstance)
{
  const mxArray *c29_st;
  const mxArray *c29_y = NULL;
  int32_T c29_i1;
  real_T c29_u[720];
  const mxArray *c29_b_y = NULL;
  uint8_T c29_hoistedGlobal;
  uint8_T c29_b_u;
  const mxArray *c29_c_y = NULL;
  c29_st = NULL;
  c29_st = NULL;
  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_createcellmatrix(2, 1), false);
  for (c29_i1 = 0; c29_i1 < 720; c29_i1++) {
    c29_u[c29_i1] = (*chartInstance->c29_A)[c29_i1];
  }

  c29_b_y = NULL;
  sf_mex_assign(&c29_b_y, sf_mex_create("y", c29_u, 0, 0U, 1U, 0U, 2, 24, 30),
                false);
  sf_mex_setcell(c29_y, 0, c29_b_y);
  c29_hoistedGlobal = chartInstance->c29_is_active_c29_DIPCalt;
  c29_b_u = c29_hoistedGlobal;
  c29_c_y = NULL;
  sf_mex_assign(&c29_c_y, sf_mex_create("y", &c29_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c29_y, 1, c29_c_y);
  sf_mex_assign(&c29_st, c29_y, false);
  return c29_st;
}

static void set_sim_state_c29_DIPCalt(SFc29_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c29_st)
{
  const mxArray *c29_u;
  real_T c29_dv1[720];
  int32_T c29_i2;
  chartInstance->c29_doneDoubleBufferReInit = true;
  c29_u = sf_mex_dup(c29_st);
  c29_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c29_u, 0)), "A",
                       c29_dv1);
  for (c29_i2 = 0; c29_i2 < 720; c29_i2++) {
    (*chartInstance->c29_A)[c29_i2] = c29_dv1[c29_i2];
  }

  chartInstance->c29_is_active_c29_DIPCalt = c29_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c29_u, 1)),
     "is_active_c29_DIPCalt");
  sf_mex_destroy(&c29_u);
  c29_update_debugger_state_c29_DIPCalt(chartInstance);
  sf_mex_destroy(&c29_st);
}

static void finalize_c29_DIPCalt(SFc29_DIPCaltInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c29_DIPCalt(SFc29_DIPCaltInstanceStruct *chartInstance)
{
  int32_T c29_i3;
  int32_T c29_i4;
  real_T c29_b_rv[12];
  int32_T c29_i5;
  real_T c29_b_x[7];
  uint32_T c29_debug_family_var_map[5];
  real_T c29_nargin = 2.0;
  real_T c29_nargout = 1.0;
  real_T c29_b_A[720];
  int32_T c29_i6;
  real_T c29_c_x[4];
  int32_T c29_i7;
  real_T c29_c_rv[3];
  real_T c29_dv2[3];
  int32_T c29_i8;
  real_T c29_d_x[3];
  uint32_T c29_b_debug_family_var_map[4];
  real_T c29_b_nargin = 1.0;
  real_T c29_b_nargout = 1.0;
  real_T c29_X[9];
  int32_T c29_i9;
  real_T c29_e_x[4];
  int32_T c29_i10;
  real_T c29_d_rv[3];
  real_T c29_dv3[3];
  int32_T c29_i11;
  real_T c29_f_x[3];
  real_T c29_c_nargin = 1.0;
  real_T c29_c_nargout = 1.0;
  real_T c29_b_X[9];
  int32_T c29_i12;
  real_T c29_g_x[4];
  int32_T c29_i13;
  real_T c29_e_rv[3];
  real_T c29_dv4[3];
  int32_T c29_i14;
  real_T c29_h_x[3];
  real_T c29_d_nargin = 1.0;
  real_T c29_d_nargout = 1.0;
  real_T c29_c_X[9];
  int32_T c29_i15;
  real_T c29_i_x[4];
  int32_T c29_i16;
  real_T c29_f_rv[3];
  real_T c29_dv5[3];
  int32_T c29_i17;
  real_T c29_j_x[3];
  real_T c29_e_nargin = 1.0;
  real_T c29_e_nargout = 1.0;
  real_T c29_d_X[9];
  real_T c29_dv6[9];
  real_T c29_dv7[9];
  real_T c29_dv8[9];
  real_T c29_dv9[9];
  real_T c29_dv10[9];
  real_T c29_dv11[9];
  real_T c29_dv12[9];
  real_T c29_dv13[9];
  real_T c29_dv14[9];
  real_T c29_dv15[9];
  real_T c29_dv16[9];
  real_T c29_dv17[9];
  real_T c29_dv18[9];
  real_T c29_dv19[9];
  real_T c29_dv20[9];
  real_T c29_dv21[9];
  int32_T c29_i18;
  int32_T c29_i19;
  int32_T c29_i20;
  int32_T c29_i21;
  int32_T c29_i22;
  int32_T c29_i23;
  int32_T c29_i24;
  int32_T c29_i25;
  int32_T c29_i26;
  int32_T c29_i27;
  int32_T c29_i28;
  int32_T c29_i29;
  int32_T c29_i30;
  int32_T c29_i31;
  int32_T c29_i32;
  int32_T c29_i33;
  int32_T c29_i34;
  int32_T c29_i35;
  int32_T c29_i36;
  int32_T c29_i37;
  int32_T c29_i38;
  int32_T c29_i39;
  int32_T c29_i40;
  int32_T c29_i41;
  int32_T c29_i42;
  int32_T c29_i43;
  int32_T c29_i44;
  int32_T c29_i45;
  int32_T c29_i46;
  int32_T c29_i47;
  int32_T c29_i48;
  int32_T c29_i49;
  int32_T c29_i50;
  int32_T c29_i51;
  int32_T c29_i52;
  int32_T c29_i53;
  int32_T c29_i54;
  int32_T c29_i55;
  int32_T c29_i56;
  int32_T c29_i57;
  int32_T c29_i58;
  int32_T c29_i59;
  int32_T c29_i60;
  int32_T c29_i61;
  int32_T c29_i62;
  int32_T c29_i63;
  int32_T c29_i64;
  int32_T c29_i65;
  int32_T c29_i66;
  int32_T c29_i67;
  int32_T c29_i68;
  int32_T c29_i69;
  int32_T c29_i70;
  int32_T c29_i71;
  int32_T c29_i72;
  int32_T c29_i73;
  int32_T c29_i74;
  int32_T c29_i75;
  int32_T c29_i76;
  int32_T c29_i77;
  int32_T c29_i78;
  int32_T c29_i79;
  int32_T c29_i80;
  int32_T c29_i81;
  int32_T c29_i82;
  int32_T c29_i83;
  int32_T c29_i84;
  int32_T c29_i85;
  int32_T c29_i86;
  int32_T c29_i87;
  int32_T c29_i88;
  int32_T c29_i89;
  int32_T c29_i90;
  int32_T c29_i91;
  int32_T c29_i92;
  int32_T c29_i93;
  int32_T c29_i94;
  int32_T c29_i95;
  int32_T c29_i96;
  int32_T c29_i97;
  int32_T c29_i98;
  int32_T c29_i99;
  int32_T c29_i100;
  int32_T c29_i101;
  int32_T c29_i102;
  int32_T c29_i103;
  int32_T c29_i104;
  int32_T c29_i105;
  int32_T c29_i106;
  int32_T c29_i107;
  int32_T c29_i108;
  int32_T c29_i109;
  int32_T c29_i110;
  int32_T c29_i111;
  int32_T c29_i112;
  int32_T c29_i113;
  int32_T c29_i114;
  int32_T c29_i115;
  int32_T c29_i116;
  int32_T c29_i117;
  int32_T c29_i118;
  int32_T c29_i119;
  int32_T c29_i120;
  int32_T c29_i121;
  int32_T c29_i122;
  int32_T c29_i123;
  int32_T c29_i124;
  int32_T c29_i125;
  int32_T c29_i126;
  int32_T c29_i127;
  int32_T c29_i128;
  int32_T c29_i129;
  int32_T c29_i130;
  int32_T c29_i131;
  int32_T c29_i132;
  int32_T c29_i133;
  int32_T c29_i134;
  int32_T c29_i135;
  int32_T c29_i136;
  int32_T c29_i137;
  int32_T c29_i138;
  int32_T c29_i139;
  int32_T c29_i140;
  int32_T c29_i141;
  int32_T c29_i142;
  int32_T c29_i143;
  int32_T c29_i144;
  int32_T c29_i145;
  int32_T c29_i146;
  int32_T c29_i147;
  int32_T c29_i148;
  int32_T c29_i149;
  int32_T c29_i150;
  int32_T c29_i151;
  int32_T c29_i152;
  int32_T c29_i153;
  int32_T c29_i154;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 12U, chartInstance->c29_sfEvent);
  for (c29_i3 = 0; c29_i3 < 12; c29_i3++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c29_rv[c29_i3], 0U);
  }

  chartInstance->c29_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 12U, chartInstance->c29_sfEvent);
  for (c29_i4 = 0; c29_i4 < 12; c29_i4++) {
    c29_b_rv[c29_i4] = chartInstance->c29_rv[c29_i4];
  }

  for (c29_i5 = 0; c29_i5 < 7; c29_i5++) {
    c29_b_x[c29_i5] = (*chartInstance->c29_x)[c29_i5];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c29_debug_family_names,
    c29_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c29_nargin, 0U, c29_d_sf_marshallOut,
    c29_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c29_nargout, 1U, c29_d_sf_marshallOut,
    c29_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c29_b_rv, 2U, c29_c_sf_marshallOut,
    c29_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c29_b_x, 3U, c29_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c29_b_A, 4U, c29_sf_marshallOut,
    c29_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c29_sfEvent, 2);
  for (c29_i6 = 0; c29_i6 < 4; c29_i6++) {
    c29_c_x[c29_i6] = c29_b_x[c29_i6 + 3];
  }

  for (c29_i7 = 0; c29_i7 < 3; c29_i7++) {
    c29_c_rv[c29_i7] = c29_b_rv[c29_i7];
  }

  c29_quatrot(chartInstance, c29_c_x, c29_c_rv, c29_dv2);
  for (c29_i8 = 0; c29_i8 < 3; c29_i8++) {
    c29_d_x[c29_i8] = c29_dv2[c29_i8];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c29_c_debug_family_names,
    c29_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c29_b_nargin, 0U, c29_d_sf_marshallOut,
    c29_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c29_b_nargout, 1U, c29_d_sf_marshallOut,
    c29_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c29_d_x, 2U, c29_e_sf_marshallOut,
    c29_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c29_X, 3U, c29_g_sf_marshallOut,
    c29_f_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c29_sfEvent, 3);
  c29_X[0] = 0.0;
  c29_X[3] = -c29_d_x[2];
  c29_X[6] = c29_d_x[1];
  c29_X[1] = c29_d_x[2];
  c29_X[4] = 0.0;
  c29_X[7] = -c29_d_x[0];
  c29_X[2] = -c29_d_x[1];
  c29_X[5] = c29_d_x[0];
  c29_X[8] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c29_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c29_i9 = 0; c29_i9 < 4; c29_i9++) {
    c29_e_x[c29_i9] = c29_b_x[c29_i9 + 3];
  }

  for (c29_i10 = 0; c29_i10 < 3; c29_i10++) {
    c29_d_rv[c29_i10] = c29_b_rv[c29_i10 + 3];
  }

  c29_quatrot(chartInstance, c29_e_x, c29_d_rv, c29_dv3);
  for (c29_i11 = 0; c29_i11 < 3; c29_i11++) {
    c29_f_x[c29_i11] = c29_dv3[c29_i11];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c29_c_debug_family_names,
    c29_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c29_c_nargin, 0U, c29_d_sf_marshallOut,
    c29_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c29_c_nargout, 1U, c29_d_sf_marshallOut,
    c29_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c29_f_x, 2U, c29_e_sf_marshallOut,
    c29_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c29_b_X, 3U, c29_g_sf_marshallOut,
    c29_f_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c29_sfEvent, 3);
  c29_b_X[0] = 0.0;
  c29_b_X[3] = -c29_f_x[2];
  c29_b_X[6] = c29_f_x[1];
  c29_b_X[1] = c29_f_x[2];
  c29_b_X[4] = 0.0;
  c29_b_X[7] = -c29_f_x[0];
  c29_b_X[2] = -c29_f_x[1];
  c29_b_X[5] = c29_f_x[0];
  c29_b_X[8] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c29_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c29_i12 = 0; c29_i12 < 4; c29_i12++) {
    c29_g_x[c29_i12] = c29_b_x[c29_i12 + 3];
  }

  for (c29_i13 = 0; c29_i13 < 3; c29_i13++) {
    c29_e_rv[c29_i13] = c29_b_rv[c29_i13 + 6];
  }

  c29_quatrot(chartInstance, c29_g_x, c29_e_rv, c29_dv4);
  for (c29_i14 = 0; c29_i14 < 3; c29_i14++) {
    c29_h_x[c29_i14] = c29_dv4[c29_i14];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c29_c_debug_family_names,
    c29_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c29_d_nargin, 0U, c29_d_sf_marshallOut,
    c29_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c29_d_nargout, 1U, c29_d_sf_marshallOut,
    c29_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c29_h_x, 2U, c29_e_sf_marshallOut,
    c29_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c29_c_X, 3U, c29_g_sf_marshallOut,
    c29_f_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c29_sfEvent, 3);
  c29_c_X[0] = 0.0;
  c29_c_X[3] = -c29_h_x[2];
  c29_c_X[6] = c29_h_x[1];
  c29_c_X[1] = c29_h_x[2];
  c29_c_X[4] = 0.0;
  c29_c_X[7] = -c29_h_x[0];
  c29_c_X[2] = -c29_h_x[1];
  c29_c_X[5] = c29_h_x[0];
  c29_c_X[8] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c29_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c29_i15 = 0; c29_i15 < 4; c29_i15++) {
    c29_i_x[c29_i15] = c29_b_x[c29_i15 + 3];
  }

  for (c29_i16 = 0; c29_i16 < 3; c29_i16++) {
    c29_f_rv[c29_i16] = c29_b_rv[c29_i16 + 9];
  }

  c29_quatrot(chartInstance, c29_i_x, c29_f_rv, c29_dv5);
  for (c29_i17 = 0; c29_i17 < 3; c29_i17++) {
    c29_j_x[c29_i17] = c29_dv5[c29_i17];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c29_c_debug_family_names,
    c29_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c29_e_nargin, 0U, c29_d_sf_marshallOut,
    c29_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c29_e_nargout, 1U, c29_d_sf_marshallOut,
    c29_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c29_j_x, 2U, c29_e_sf_marshallOut,
    c29_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c29_d_X, 3U, c29_g_sf_marshallOut,
    c29_f_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c29_sfEvent, 3);
  c29_d_X[0] = 0.0;
  c29_d_X[3] = -c29_j_x[2];
  c29_d_X[6] = c29_j_x[1];
  c29_d_X[1] = c29_j_x[2];
  c29_d_X[4] = 0.0;
  c29_d_X[7] = -c29_j_x[0];
  c29_d_X[2] = -c29_j_x[1];
  c29_d_X[5] = c29_j_x[0];
  c29_d_X[8] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c29_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  c29_eye(chartInstance, c29_dv6);
  c29_eye(chartInstance, c29_dv7);
  c29_eye(chartInstance, c29_dv8);
  c29_eye(chartInstance, c29_dv9);
  c29_eye(chartInstance, c29_dv10);
  c29_eye(chartInstance, c29_dv11);
  c29_eye(chartInstance, c29_dv12);
  c29_eye(chartInstance, c29_dv13);
  c29_eye(chartInstance, c29_dv14);
  c29_eye(chartInstance, c29_dv15);
  c29_eye(chartInstance, c29_dv16);
  c29_eye(chartInstance, c29_dv17);
  c29_eye(chartInstance, c29_dv18);
  c29_eye(chartInstance, c29_dv19);
  c29_eye(chartInstance, c29_dv20);
  c29_eye(chartInstance, c29_dv21);
  c29_i18 = 0;
  c29_i19 = 0;
  for (c29_i20 = 0; c29_i20 < 3; c29_i20++) {
    for (c29_i21 = 0; c29_i21 < 3; c29_i21++) {
      c29_b_A[c29_i21 + c29_i18] = -c29_dv6[c29_i21 + c29_i19];
    }

    c29_i18 += 24;
    c29_i19 += 3;
  }

  c29_i22 = 0;
  c29_i23 = 0;
  for (c29_i24 = 0; c29_i24 < 3; c29_i24++) {
    for (c29_i25 = 0; c29_i25 < 3; c29_i25++) {
      c29_b_A[(c29_i25 + c29_i22) + 72] = c29_X[c29_i25 + c29_i23];
    }

    c29_i22 += 24;
    c29_i23 += 3;
  }

  c29_i26 = 0;
  c29_i27 = 0;
  for (c29_i28 = 0; c29_i28 < 3; c29_i28++) {
    for (c29_i29 = 0; c29_i29 < 3; c29_i29++) {
      c29_b_A[(c29_i29 + c29_i26) + 144] = c29_dv7[c29_i29 + c29_i27];
    }

    c29_i26 += 24;
    c29_i27 += 3;
  }

  c29_i30 = 0;
  for (c29_i31 = 0; c29_i31 < 21; c29_i31++) {
    for (c29_i32 = 0; c29_i32 < 3; c29_i32++) {
      c29_b_A[(c29_i32 + c29_i30) + 216] = 0.0;
    }

    c29_i30 += 24;
  }

  c29_i33 = 0;
  for (c29_i34 = 0; c29_i34 < 3; c29_i34++) {
    for (c29_i35 = 0; c29_i35 < 3; c29_i35++) {
      c29_b_A[(c29_i35 + c29_i33) + 3] = 0.0;
    }

    c29_i33 += 24;
  }

  c29_i36 = 0;
  c29_i37 = 0;
  for (c29_i38 = 0; c29_i38 < 3; c29_i38++) {
    for (c29_i39 = 0; c29_i39 < 3; c29_i39++) {
      c29_b_A[(c29_i39 + c29_i36) + 75] = -c29_dv8[c29_i39 + c29_i37];
    }

    c29_i36 += 24;
    c29_i37 += 3;
  }

  c29_i40 = 0;
  for (c29_i41 = 0; c29_i41 < 3; c29_i41++) {
    for (c29_i42 = 0; c29_i42 < 3; c29_i42++) {
      c29_b_A[(c29_i42 + c29_i40) + 147] = 0.0;
    }

    c29_i40 += 24;
  }

  c29_i43 = 0;
  c29_i44 = 0;
  for (c29_i45 = 0; c29_i45 < 3; c29_i45++) {
    for (c29_i46 = 0; c29_i46 < 3; c29_i46++) {
      c29_b_A[(c29_i46 + c29_i43) + 219] = c29_dv9[c29_i46 + c29_i44];
    }

    c29_i43 += 24;
    c29_i44 += 3;
  }

  c29_i47 = 0;
  for (c29_i48 = 0; c29_i48 < 18; c29_i48++) {
    for (c29_i49 = 0; c29_i49 < 3; c29_i49++) {
      c29_b_A[(c29_i49 + c29_i47) + 291] = 0.0;
    }

    c29_i47 += 24;
  }

  c29_i50 = 0;
  c29_i51 = 0;
  for (c29_i52 = 0; c29_i52 < 3; c29_i52++) {
    for (c29_i53 = 0; c29_i53 < 3; c29_i53++) {
      c29_b_A[(c29_i53 + c29_i50) + 6] = -c29_dv10[c29_i53 + c29_i51];
    }

    c29_i50 += 24;
    c29_i51 += 3;
  }

  c29_i54 = 0;
  c29_i55 = 0;
  for (c29_i56 = 0; c29_i56 < 3; c29_i56++) {
    for (c29_i57 = 0; c29_i57 < 3; c29_i57++) {
      c29_b_A[(c29_i57 + c29_i54) + 78] = c29_b_X[c29_i57 + c29_i55];
    }

    c29_i54 += 24;
    c29_i55 += 3;
  }

  c29_i58 = 0;
  for (c29_i59 = 0; c29_i59 < 6; c29_i59++) {
    for (c29_i60 = 0; c29_i60 < 3; c29_i60++) {
      c29_b_A[(c29_i60 + c29_i58) + 150] = 0.0;
    }

    c29_i58 += 24;
  }

  c29_i61 = 0;
  c29_i62 = 0;
  for (c29_i63 = 0; c29_i63 < 3; c29_i63++) {
    for (c29_i64 = 0; c29_i64 < 3; c29_i64++) {
      c29_b_A[(c29_i64 + c29_i61) + 294] = c29_dv11[c29_i64 + c29_i62];
    }

    c29_i61 += 24;
    c29_i62 += 3;
  }

  c29_i65 = 0;
  for (c29_i66 = 0; c29_i66 < 15; c29_i66++) {
    for (c29_i67 = 0; c29_i67 < 3; c29_i67++) {
      c29_b_A[(c29_i67 + c29_i65) + 366] = 0.0;
    }

    c29_i65 += 24;
  }

  c29_i68 = 0;
  for (c29_i69 = 0; c29_i69 < 3; c29_i69++) {
    for (c29_i70 = 0; c29_i70 < 3; c29_i70++) {
      c29_b_A[(c29_i70 + c29_i68) + 9] = 0.0;
    }

    c29_i68 += 24;
  }

  c29_i71 = 0;
  c29_i72 = 0;
  for (c29_i73 = 0; c29_i73 < 3; c29_i73++) {
    for (c29_i74 = 0; c29_i74 < 3; c29_i74++) {
      c29_b_A[(c29_i74 + c29_i71) + 81] = -c29_dv12[c29_i74 + c29_i72];
    }

    c29_i71 += 24;
    c29_i72 += 3;
  }

  c29_i75 = 0;
  for (c29_i76 = 0; c29_i76 < 9; c29_i76++) {
    for (c29_i77 = 0; c29_i77 < 3; c29_i77++) {
      c29_b_A[(c29_i77 + c29_i75) + 153] = 0.0;
    }

    c29_i75 += 24;
  }

  c29_i78 = 0;
  c29_i79 = 0;
  for (c29_i80 = 0; c29_i80 < 3; c29_i80++) {
    for (c29_i81 = 0; c29_i81 < 3; c29_i81++) {
      c29_b_A[(c29_i81 + c29_i78) + 369] = c29_dv13[c29_i81 + c29_i79];
    }

    c29_i78 += 24;
    c29_i79 += 3;
  }

  c29_i82 = 0;
  for (c29_i83 = 0; c29_i83 < 12; c29_i83++) {
    for (c29_i84 = 0; c29_i84 < 3; c29_i84++) {
      c29_b_A[(c29_i84 + c29_i82) + 441] = 0.0;
    }

    c29_i82 += 24;
  }

  c29_i85 = 0;
  c29_i86 = 0;
  for (c29_i87 = 0; c29_i87 < 3; c29_i87++) {
    for (c29_i88 = 0; c29_i88 < 3; c29_i88++) {
      c29_b_A[(c29_i88 + c29_i85) + 12] = -c29_dv14[c29_i88 + c29_i86];
    }

    c29_i85 += 24;
    c29_i86 += 3;
  }

  c29_i89 = 0;
  c29_i90 = 0;
  for (c29_i91 = 0; c29_i91 < 3; c29_i91++) {
    for (c29_i92 = 0; c29_i92 < 3; c29_i92++) {
      c29_b_A[(c29_i92 + c29_i89) + 84] = c29_c_X[c29_i92 + c29_i90];
    }

    c29_i89 += 24;
    c29_i90 += 3;
  }

  c29_i93 = 0;
  for (c29_i94 = 0; c29_i94 < 12; c29_i94++) {
    for (c29_i95 = 0; c29_i95 < 3; c29_i95++) {
      c29_b_A[(c29_i95 + c29_i93) + 156] = 0.0;
    }

    c29_i93 += 24;
  }

  c29_i96 = 0;
  c29_i97 = 0;
  for (c29_i98 = 0; c29_i98 < 3; c29_i98++) {
    for (c29_i99 = 0; c29_i99 < 3; c29_i99++) {
      c29_b_A[(c29_i99 + c29_i96) + 444] = c29_dv15[c29_i99 + c29_i97];
    }

    c29_i96 += 24;
    c29_i97 += 3;
  }

  c29_i100 = 0;
  for (c29_i101 = 0; c29_i101 < 9; c29_i101++) {
    for (c29_i102 = 0; c29_i102 < 3; c29_i102++) {
      c29_b_A[(c29_i102 + c29_i100) + 516] = 0.0;
    }

    c29_i100 += 24;
  }

  c29_i103 = 0;
  for (c29_i104 = 0; c29_i104 < 3; c29_i104++) {
    for (c29_i105 = 0; c29_i105 < 3; c29_i105++) {
      c29_b_A[(c29_i105 + c29_i103) + 15] = 0.0;
    }

    c29_i103 += 24;
  }

  c29_i106 = 0;
  c29_i107 = 0;
  for (c29_i108 = 0; c29_i108 < 3; c29_i108++) {
    for (c29_i109 = 0; c29_i109 < 3; c29_i109++) {
      c29_b_A[(c29_i109 + c29_i106) + 87] = -c29_dv16[c29_i109 + c29_i107];
    }

    c29_i106 += 24;
    c29_i107 += 3;
  }

  c29_i110 = 0;
  for (c29_i111 = 0; c29_i111 < 15; c29_i111++) {
    for (c29_i112 = 0; c29_i112 < 3; c29_i112++) {
      c29_b_A[(c29_i112 + c29_i110) + 159] = 0.0;
    }

    c29_i110 += 24;
  }

  c29_i113 = 0;
  c29_i114 = 0;
  for (c29_i115 = 0; c29_i115 < 3; c29_i115++) {
    for (c29_i116 = 0; c29_i116 < 3; c29_i116++) {
      c29_b_A[(c29_i116 + c29_i113) + 519] = c29_dv17[c29_i116 + c29_i114];
    }

    c29_i113 += 24;
    c29_i114 += 3;
  }

  c29_i117 = 0;
  for (c29_i118 = 0; c29_i118 < 6; c29_i118++) {
    for (c29_i119 = 0; c29_i119 < 3; c29_i119++) {
      c29_b_A[(c29_i119 + c29_i117) + 591] = 0.0;
    }

    c29_i117 += 24;
  }

  c29_i120 = 0;
  c29_i121 = 0;
  for (c29_i122 = 0; c29_i122 < 3; c29_i122++) {
    for (c29_i123 = 0; c29_i123 < 3; c29_i123++) {
      c29_b_A[(c29_i123 + c29_i120) + 18] = -c29_dv18[c29_i123 + c29_i121];
    }

    c29_i120 += 24;
    c29_i121 += 3;
  }

  c29_i124 = 0;
  c29_i125 = 0;
  for (c29_i126 = 0; c29_i126 < 3; c29_i126++) {
    for (c29_i127 = 0; c29_i127 < 3; c29_i127++) {
      c29_b_A[(c29_i127 + c29_i124) + 90] = c29_d_X[c29_i127 + c29_i125];
    }

    c29_i124 += 24;
    c29_i125 += 3;
  }

  c29_i128 = 0;
  for (c29_i129 = 0; c29_i129 < 18; c29_i129++) {
    for (c29_i130 = 0; c29_i130 < 3; c29_i130++) {
      c29_b_A[(c29_i130 + c29_i128) + 162] = 0.0;
    }

    c29_i128 += 24;
  }

  c29_i131 = 0;
  c29_i132 = 0;
  for (c29_i133 = 0; c29_i133 < 3; c29_i133++) {
    for (c29_i134 = 0; c29_i134 < 3; c29_i134++) {
      c29_b_A[(c29_i134 + c29_i131) + 594] = c29_dv19[c29_i134 + c29_i132];
    }

    c29_i131 += 24;
    c29_i132 += 3;
  }

  c29_i135 = 0;
  for (c29_i136 = 0; c29_i136 < 3; c29_i136++) {
    for (c29_i137 = 0; c29_i137 < 3; c29_i137++) {
      c29_b_A[(c29_i137 + c29_i135) + 666] = 0.0;
    }

    c29_i135 += 24;
  }

  c29_i138 = 0;
  for (c29_i139 = 0; c29_i139 < 3; c29_i139++) {
    for (c29_i140 = 0; c29_i140 < 3; c29_i140++) {
      c29_b_A[(c29_i140 + c29_i138) + 21] = 0.0;
    }

    c29_i138 += 24;
  }

  c29_i141 = 0;
  c29_i142 = 0;
  for (c29_i143 = 0; c29_i143 < 3; c29_i143++) {
    for (c29_i144 = 0; c29_i144 < 3; c29_i144++) {
      c29_b_A[(c29_i144 + c29_i141) + 93] = -c29_dv20[c29_i144 + c29_i142];
    }

    c29_i141 += 24;
    c29_i142 += 3;
  }

  c29_i145 = 0;
  for (c29_i146 = 0; c29_i146 < 21; c29_i146++) {
    for (c29_i147 = 0; c29_i147 < 3; c29_i147++) {
      c29_b_A[(c29_i147 + c29_i145) + 165] = 0.0;
    }

    c29_i145 += 24;
  }

  c29_i148 = 0;
  c29_i149 = 0;
  for (c29_i150 = 0; c29_i150 < 3; c29_i150++) {
    for (c29_i151 = 0; c29_i151 < 3; c29_i151++) {
      c29_b_A[(c29_i151 + c29_i148) + 669] = c29_dv21[c29_i151 + c29_i149];
    }

    c29_i148 += 24;
    c29_i149 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c29_sfEvent, -2);
  _SFD_SYMBOL_SCOPE_POP();
  for (c29_i152 = 0; c29_i152 < 720; c29_i152++) {
    (*chartInstance->c29_A)[c29_i152] = c29_b_A[c29_i152];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c29_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DIPCaltMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c29_i153 = 0; c29_i153 < 720; c29_i153++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c29_A)[c29_i153], 1U);
  }

  for (c29_i154 = 0; c29_i154 < 7; c29_i154++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c29_x)[c29_i154], 2U);
  }
}

static void mdl_start_c29_DIPCalt(SFc29_DIPCaltInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc29_DIPCalt(SFc29_DIPCaltInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c29_quatrot(SFc29_DIPCaltInstanceStruct *chartInstance, real_T
  c29_q[4], real_T c29_r[3], real_T c29_rw[3])
{
  uint32_T c29_debug_family_var_map[6];
  real_T c29_rwq[4];
  real_T c29_nargin = 2.0;
  real_T c29_nargout = 1.0;
  int32_T c29_i155;
  real_T c29_b_q[4];
  int32_T c29_k;
  real_T c29_b_k;
  real_T c29_dv22[4];
  int32_T c29_i156;
  int32_T c29_i157;
  real_T c29_c_q[4];
  real_T c29_dv23[4];
  int32_T c29_i158;
  real_T c29_d_q[4];
  int32_T c29_i159;
  real_T c29_dv24[4];
  int32_T c29_i160;
  int32_T c29_i161;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c29_b_debug_family_names,
    c29_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c29_rwq, 0U, c29_f_sf_marshallOut,
    c29_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c29_nargin, 1U, c29_d_sf_marshallOut,
    c29_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c29_nargout, 2U, c29_d_sf_marshallOut,
    c29_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c29_q, 3U, c29_f_sf_marshallOut,
    c29_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c29_r, 4U, c29_e_sf_marshallOut,
    c29_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c29_rw, 5U, c29_e_sf_marshallOut,
    c29_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c29_sfEvent, 4);
  for (c29_i155 = 0; c29_i155 < 4; c29_i155++) {
    c29_b_q[c29_i155] = c29_q[c29_i155];
  }

  for (c29_k = 0; c29_k < 3; c29_k++) {
    c29_b_k = 2.0 + (real_T)c29_k;
    c29_b_q[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c29_b_k), 1, 4, 1, 0) - 1] = -c29_b_q[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", c29_b_k), 1, 4, 1, 0) - 1];
  }

  c29_dv22[0] = 0.0;
  for (c29_i156 = 0; c29_i156 < 3; c29_i156++) {
    c29_dv22[c29_i156 + 1] = c29_r[c29_i156];
  }

  for (c29_i157 = 0; c29_i157 < 4; c29_i157++) {
    c29_c_q[c29_i157] = c29_b_q[c29_i157];
  }

  c29_quatmultiply(chartInstance, c29_dv22, c29_c_q, c29_dv23);
  for (c29_i158 = 0; c29_i158 < 4; c29_i158++) {
    c29_d_q[c29_i158] = c29_q[c29_i158];
  }

  for (c29_i159 = 0; c29_i159 < 4; c29_i159++) {
    c29_dv24[c29_i159] = c29_dv23[c29_i159];
  }

  c29_quatmultiply(chartInstance, c29_d_q, c29_dv24, c29_b_q);
  for (c29_i160 = 0; c29_i160 < 4; c29_i160++) {
    c29_rwq[c29_i160] = c29_b_q[c29_i160];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c29_sfEvent, 5);
  for (c29_i161 = 0; c29_i161 < 3; c29_i161++) {
    c29_rw[c29_i161] = c29_rwq[c29_i161 + 1];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c29_sfEvent, -5);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c29_machineNumber, uint32_T
  c29_chartNumber, uint32_T c29_instanceNumber)
{
  (void)c29_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c29_chartNumber, c29_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Martin\\Documents\\Git\\Simulink\\DIPCc - Energybounding\\quatrot.m"));
  _SFD_SCRIPT_TRANSLATION(c29_chartNumber, c29_instanceNumber, 1U,
    sf_debug_get_script_id(
    "C:\\Users\\Martin\\Documents\\Git\\Simulink\\DIPCc - Energybounding\\skew_sm.m"));
}

static const mxArray *c29_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData)
{
  const mxArray *c29_mxArrayOutData = NULL;
  int32_T c29_i162;
  int32_T c29_i163;
  int32_T c29_i164;
  real_T c29_b_inData[720];
  int32_T c29_i165;
  int32_T c29_i166;
  int32_T c29_i167;
  real_T c29_u[720];
  const mxArray *c29_y = NULL;
  SFc29_DIPCaltInstanceStruct *chartInstance;
  chartInstance = (SFc29_DIPCaltInstanceStruct *)chartInstanceVoid;
  c29_mxArrayOutData = NULL;
  c29_i162 = 0;
  for (c29_i163 = 0; c29_i163 < 30; c29_i163++) {
    for (c29_i164 = 0; c29_i164 < 24; c29_i164++) {
      c29_b_inData[c29_i164 + c29_i162] = (*(real_T (*)[720])c29_inData)
        [c29_i164 + c29_i162];
    }

    c29_i162 += 24;
  }

  c29_i165 = 0;
  for (c29_i166 = 0; c29_i166 < 30; c29_i166++) {
    for (c29_i167 = 0; c29_i167 < 24; c29_i167++) {
      c29_u[c29_i167 + c29_i165] = c29_b_inData[c29_i167 + c29_i165];
    }

    c29_i165 += 24;
  }

  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_create("y", c29_u, 0, 0U, 1U, 0U, 2, 24, 30),
                false);
  sf_mex_assign(&c29_mxArrayOutData, c29_y, false);
  return c29_mxArrayOutData;
}

static void c29_emlrt_marshallIn(SFc29_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c29_b_A, const char_T *c29_identifier, real_T c29_y[720])
{
  emlrtMsgIdentifier c29_thisId;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c29_b_A), &c29_thisId, c29_y);
  sf_mex_destroy(&c29_b_A);
}

static void c29_b_emlrt_marshallIn(SFc29_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId, real_T c29_y[720])
{
  real_T c29_dv25[720];
  int32_T c29_i168;
  (void)chartInstance;
  sf_mex_import(c29_parentId, sf_mex_dup(c29_u), c29_dv25, 1, 0, 0U, 1, 0U, 2,
                24, 30);
  for (c29_i168 = 0; c29_i168 < 720; c29_i168++) {
    c29_y[c29_i168] = c29_dv25[c29_i168];
  }

  sf_mex_destroy(&c29_u);
}

static void c29_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData)
{
  const mxArray *c29_b_A;
  const char_T *c29_identifier;
  emlrtMsgIdentifier c29_thisId;
  real_T c29_y[720];
  int32_T c29_i169;
  int32_T c29_i170;
  int32_T c29_i171;
  SFc29_DIPCaltInstanceStruct *chartInstance;
  chartInstance = (SFc29_DIPCaltInstanceStruct *)chartInstanceVoid;
  c29_b_A = sf_mex_dup(c29_mxArrayInData);
  c29_identifier = c29_varName;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c29_b_A), &c29_thisId, c29_y);
  sf_mex_destroy(&c29_b_A);
  c29_i169 = 0;
  for (c29_i170 = 0; c29_i170 < 30; c29_i170++) {
    for (c29_i171 = 0; c29_i171 < 24; c29_i171++) {
      (*(real_T (*)[720])c29_outData)[c29_i171 + c29_i169] = c29_y[c29_i171 +
        c29_i169];
    }

    c29_i169 += 24;
  }

  sf_mex_destroy(&c29_mxArrayInData);
}

static const mxArray *c29_b_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData)
{
  const mxArray *c29_mxArrayOutData = NULL;
  int32_T c29_i172;
  real_T c29_b_inData[7];
  int32_T c29_i173;
  real_T c29_u[7];
  const mxArray *c29_y = NULL;
  SFc29_DIPCaltInstanceStruct *chartInstance;
  chartInstance = (SFc29_DIPCaltInstanceStruct *)chartInstanceVoid;
  c29_mxArrayOutData = NULL;
  for (c29_i172 = 0; c29_i172 < 7; c29_i172++) {
    c29_b_inData[c29_i172] = (*(real_T (*)[7])c29_inData)[c29_i172];
  }

  for (c29_i173 = 0; c29_i173 < 7; c29_i173++) {
    c29_u[c29_i173] = c29_b_inData[c29_i173];
  }

  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_create("y", c29_u, 0, 0U, 1U, 0U, 1, 7), false);
  sf_mex_assign(&c29_mxArrayOutData, c29_y, false);
  return c29_mxArrayOutData;
}

static const mxArray *c29_c_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData)
{
  const mxArray *c29_mxArrayOutData = NULL;
  int32_T c29_i174;
  real_T c29_b_inData[12];
  int32_T c29_i175;
  real_T c29_u[12];
  const mxArray *c29_y = NULL;
  SFc29_DIPCaltInstanceStruct *chartInstance;
  chartInstance = (SFc29_DIPCaltInstanceStruct *)chartInstanceVoid;
  c29_mxArrayOutData = NULL;
  for (c29_i174 = 0; c29_i174 < 12; c29_i174++) {
    c29_b_inData[c29_i174] = (*(real_T (*)[12])c29_inData)[c29_i174];
  }

  for (c29_i175 = 0; c29_i175 < 12; c29_i175++) {
    c29_u[c29_i175] = c29_b_inData[c29_i175];
  }

  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_create("y", c29_u, 0, 0U, 1U, 0U, 1, 12), false);
  sf_mex_assign(&c29_mxArrayOutData, c29_y, false);
  return c29_mxArrayOutData;
}

static void c29_c_emlrt_marshallIn(SFc29_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId, real_T c29_y[12])
{
  real_T c29_dv26[12];
  int32_T c29_i176;
  (void)chartInstance;
  sf_mex_import(c29_parentId, sf_mex_dup(c29_u), c29_dv26, 1, 0, 0U, 1, 0U, 1,
                12);
  for (c29_i176 = 0; c29_i176 < 12; c29_i176++) {
    c29_y[c29_i176] = c29_dv26[c29_i176];
  }

  sf_mex_destroy(&c29_u);
}

static void c29_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData)
{
  const mxArray *c29_b_rv;
  const char_T *c29_identifier;
  emlrtMsgIdentifier c29_thisId;
  real_T c29_y[12];
  int32_T c29_i177;
  SFc29_DIPCaltInstanceStruct *chartInstance;
  chartInstance = (SFc29_DIPCaltInstanceStruct *)chartInstanceVoid;
  c29_b_rv = sf_mex_dup(c29_mxArrayInData);
  c29_identifier = c29_varName;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c29_b_rv), &c29_thisId, c29_y);
  sf_mex_destroy(&c29_b_rv);
  for (c29_i177 = 0; c29_i177 < 12; c29_i177++) {
    (*(real_T (*)[12])c29_outData)[c29_i177] = c29_y[c29_i177];
  }

  sf_mex_destroy(&c29_mxArrayInData);
}

static const mxArray *c29_d_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData)
{
  const mxArray *c29_mxArrayOutData = NULL;
  real_T c29_u;
  const mxArray *c29_y = NULL;
  SFc29_DIPCaltInstanceStruct *chartInstance;
  chartInstance = (SFc29_DIPCaltInstanceStruct *)chartInstanceVoid;
  c29_mxArrayOutData = NULL;
  c29_u = *(real_T *)c29_inData;
  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_create("y", &c29_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c29_mxArrayOutData, c29_y, false);
  return c29_mxArrayOutData;
}

static real_T c29_d_emlrt_marshallIn(SFc29_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId)
{
  real_T c29_y;
  real_T c29_d0;
  (void)chartInstance;
  sf_mex_import(c29_parentId, sf_mex_dup(c29_u), &c29_d0, 1, 0, 0U, 0, 0U, 0);
  c29_y = c29_d0;
  sf_mex_destroy(&c29_u);
  return c29_y;
}

static void c29_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData)
{
  const mxArray *c29_nargout;
  const char_T *c29_identifier;
  emlrtMsgIdentifier c29_thisId;
  real_T c29_y;
  SFc29_DIPCaltInstanceStruct *chartInstance;
  chartInstance = (SFc29_DIPCaltInstanceStruct *)chartInstanceVoid;
  c29_nargout = sf_mex_dup(c29_mxArrayInData);
  c29_identifier = c29_varName;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_y = c29_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c29_nargout),
    &c29_thisId);
  sf_mex_destroy(&c29_nargout);
  *(real_T *)c29_outData = c29_y;
  sf_mex_destroy(&c29_mxArrayInData);
}

static const mxArray *c29_e_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData)
{
  const mxArray *c29_mxArrayOutData = NULL;
  int32_T c29_i178;
  real_T c29_b_inData[3];
  int32_T c29_i179;
  real_T c29_u[3];
  const mxArray *c29_y = NULL;
  SFc29_DIPCaltInstanceStruct *chartInstance;
  chartInstance = (SFc29_DIPCaltInstanceStruct *)chartInstanceVoid;
  c29_mxArrayOutData = NULL;
  for (c29_i178 = 0; c29_i178 < 3; c29_i178++) {
    c29_b_inData[c29_i178] = (*(real_T (*)[3])c29_inData)[c29_i178];
  }

  for (c29_i179 = 0; c29_i179 < 3; c29_i179++) {
    c29_u[c29_i179] = c29_b_inData[c29_i179];
  }

  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_create("y", c29_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c29_mxArrayOutData, c29_y, false);
  return c29_mxArrayOutData;
}

static void c29_e_emlrt_marshallIn(SFc29_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId, real_T c29_y[3])
{
  real_T c29_dv27[3];
  int32_T c29_i180;
  (void)chartInstance;
  sf_mex_import(c29_parentId, sf_mex_dup(c29_u), c29_dv27, 1, 0, 0U, 1, 0U, 1, 3);
  for (c29_i180 = 0; c29_i180 < 3; c29_i180++) {
    c29_y[c29_i180] = c29_dv27[c29_i180];
  }

  sf_mex_destroy(&c29_u);
}

static void c29_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData)
{
  const mxArray *c29_rw;
  const char_T *c29_identifier;
  emlrtMsgIdentifier c29_thisId;
  real_T c29_y[3];
  int32_T c29_i181;
  SFc29_DIPCaltInstanceStruct *chartInstance;
  chartInstance = (SFc29_DIPCaltInstanceStruct *)chartInstanceVoid;
  c29_rw = sf_mex_dup(c29_mxArrayInData);
  c29_identifier = c29_varName;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c29_rw), &c29_thisId, c29_y);
  sf_mex_destroy(&c29_rw);
  for (c29_i181 = 0; c29_i181 < 3; c29_i181++) {
    (*(real_T (*)[3])c29_outData)[c29_i181] = c29_y[c29_i181];
  }

  sf_mex_destroy(&c29_mxArrayInData);
}

static const mxArray *c29_f_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData)
{
  const mxArray *c29_mxArrayOutData = NULL;
  int32_T c29_i182;
  real_T c29_b_inData[4];
  int32_T c29_i183;
  real_T c29_u[4];
  const mxArray *c29_y = NULL;
  SFc29_DIPCaltInstanceStruct *chartInstance;
  chartInstance = (SFc29_DIPCaltInstanceStruct *)chartInstanceVoid;
  c29_mxArrayOutData = NULL;
  for (c29_i182 = 0; c29_i182 < 4; c29_i182++) {
    c29_b_inData[c29_i182] = (*(real_T (*)[4])c29_inData)[c29_i182];
  }

  for (c29_i183 = 0; c29_i183 < 4; c29_i183++) {
    c29_u[c29_i183] = c29_b_inData[c29_i183];
  }

  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_create("y", c29_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c29_mxArrayOutData, c29_y, false);
  return c29_mxArrayOutData;
}

static void c29_f_emlrt_marshallIn(SFc29_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId, real_T c29_y[4])
{
  real_T c29_dv28[4];
  int32_T c29_i184;
  (void)chartInstance;
  sf_mex_import(c29_parentId, sf_mex_dup(c29_u), c29_dv28, 1, 0, 0U, 1, 0U, 1, 4);
  for (c29_i184 = 0; c29_i184 < 4; c29_i184++) {
    c29_y[c29_i184] = c29_dv28[c29_i184];
  }

  sf_mex_destroy(&c29_u);
}

static void c29_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData)
{
  const mxArray *c29_q;
  const char_T *c29_identifier;
  emlrtMsgIdentifier c29_thisId;
  real_T c29_y[4];
  int32_T c29_i185;
  SFc29_DIPCaltInstanceStruct *chartInstance;
  chartInstance = (SFc29_DIPCaltInstanceStruct *)chartInstanceVoid;
  c29_q = sf_mex_dup(c29_mxArrayInData);
  c29_identifier = c29_varName;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c29_q), &c29_thisId, c29_y);
  sf_mex_destroy(&c29_q);
  for (c29_i185 = 0; c29_i185 < 4; c29_i185++) {
    (*(real_T (*)[4])c29_outData)[c29_i185] = c29_y[c29_i185];
  }

  sf_mex_destroy(&c29_mxArrayInData);
}

static const mxArray *c29_g_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData)
{
  const mxArray *c29_mxArrayOutData = NULL;
  int32_T c29_i186;
  int32_T c29_i187;
  int32_T c29_i188;
  real_T c29_b_inData[9];
  int32_T c29_i189;
  int32_T c29_i190;
  int32_T c29_i191;
  real_T c29_u[9];
  const mxArray *c29_y = NULL;
  SFc29_DIPCaltInstanceStruct *chartInstance;
  chartInstance = (SFc29_DIPCaltInstanceStruct *)chartInstanceVoid;
  c29_mxArrayOutData = NULL;
  c29_i186 = 0;
  for (c29_i187 = 0; c29_i187 < 3; c29_i187++) {
    for (c29_i188 = 0; c29_i188 < 3; c29_i188++) {
      c29_b_inData[c29_i188 + c29_i186] = (*(real_T (*)[9])c29_inData)[c29_i188
        + c29_i186];
    }

    c29_i186 += 3;
  }

  c29_i189 = 0;
  for (c29_i190 = 0; c29_i190 < 3; c29_i190++) {
    for (c29_i191 = 0; c29_i191 < 3; c29_i191++) {
      c29_u[c29_i191 + c29_i189] = c29_b_inData[c29_i191 + c29_i189];
    }

    c29_i189 += 3;
  }

  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_create("y", c29_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c29_mxArrayOutData, c29_y, false);
  return c29_mxArrayOutData;
}

static void c29_g_emlrt_marshallIn(SFc29_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId, real_T c29_y[9])
{
  real_T c29_dv29[9];
  int32_T c29_i192;
  (void)chartInstance;
  sf_mex_import(c29_parentId, sf_mex_dup(c29_u), c29_dv29, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c29_i192 = 0; c29_i192 < 9; c29_i192++) {
    c29_y[c29_i192] = c29_dv29[c29_i192];
  }

  sf_mex_destroy(&c29_u);
}

static void c29_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData)
{
  const mxArray *c29_X;
  const char_T *c29_identifier;
  emlrtMsgIdentifier c29_thisId;
  real_T c29_y[9];
  int32_T c29_i193;
  int32_T c29_i194;
  int32_T c29_i195;
  SFc29_DIPCaltInstanceStruct *chartInstance;
  chartInstance = (SFc29_DIPCaltInstanceStruct *)chartInstanceVoid;
  c29_X = sf_mex_dup(c29_mxArrayInData);
  c29_identifier = c29_varName;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c29_X), &c29_thisId, c29_y);
  sf_mex_destroy(&c29_X);
  c29_i193 = 0;
  for (c29_i194 = 0; c29_i194 < 3; c29_i194++) {
    for (c29_i195 = 0; c29_i195 < 3; c29_i195++) {
      (*(real_T (*)[9])c29_outData)[c29_i195 + c29_i193] = c29_y[c29_i195 +
        c29_i193];
    }

    c29_i193 += 3;
  }

  sf_mex_destroy(&c29_mxArrayInData);
}

const mxArray *sf_c29_DIPCalt_get_eml_resolved_functions_info(void)
{
  const mxArray *c29_nameCaptureInfo = NULL;
  c29_nameCaptureInfo = NULL;
  sf_mex_assign(&c29_nameCaptureInfo, sf_mex_createstruct("structure", 2, 34, 1),
                false);
  c29_info_helper(&c29_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c29_nameCaptureInfo);
  return c29_nameCaptureInfo;
}

static void c29_info_helper(const mxArray **c29_info)
{
  const mxArray *c29_rhs0 = NULL;
  const mxArray *c29_lhs0 = NULL;
  const mxArray *c29_rhs1 = NULL;
  const mxArray *c29_lhs1 = NULL;
  const mxArray *c29_rhs2 = NULL;
  const mxArray *c29_lhs2 = NULL;
  const mxArray *c29_rhs3 = NULL;
  const mxArray *c29_lhs3 = NULL;
  const mxArray *c29_rhs4 = NULL;
  const mxArray *c29_lhs4 = NULL;
  const mxArray *c29_rhs5 = NULL;
  const mxArray *c29_lhs5 = NULL;
  const mxArray *c29_rhs6 = NULL;
  const mxArray *c29_lhs6 = NULL;
  const mxArray *c29_rhs7 = NULL;
  const mxArray *c29_lhs7 = NULL;
  const mxArray *c29_rhs8 = NULL;
  const mxArray *c29_lhs8 = NULL;
  const mxArray *c29_rhs9 = NULL;
  const mxArray *c29_lhs9 = NULL;
  const mxArray *c29_rhs10 = NULL;
  const mxArray *c29_lhs10 = NULL;
  const mxArray *c29_rhs11 = NULL;
  const mxArray *c29_lhs11 = NULL;
  const mxArray *c29_rhs12 = NULL;
  const mxArray *c29_lhs12 = NULL;
  const mxArray *c29_rhs13 = NULL;
  const mxArray *c29_lhs13 = NULL;
  const mxArray *c29_rhs14 = NULL;
  const mxArray *c29_lhs14 = NULL;
  const mxArray *c29_rhs15 = NULL;
  const mxArray *c29_lhs15 = NULL;
  const mxArray *c29_rhs16 = NULL;
  const mxArray *c29_lhs16 = NULL;
  const mxArray *c29_rhs17 = NULL;
  const mxArray *c29_lhs17 = NULL;
  const mxArray *c29_rhs18 = NULL;
  const mxArray *c29_lhs18 = NULL;
  const mxArray *c29_rhs19 = NULL;
  const mxArray *c29_lhs19 = NULL;
  const mxArray *c29_rhs20 = NULL;
  const mxArray *c29_lhs20 = NULL;
  const mxArray *c29_rhs21 = NULL;
  const mxArray *c29_lhs21 = NULL;
  const mxArray *c29_rhs22 = NULL;
  const mxArray *c29_lhs22 = NULL;
  const mxArray *c29_rhs23 = NULL;
  const mxArray *c29_lhs23 = NULL;
  const mxArray *c29_rhs24 = NULL;
  const mxArray *c29_lhs24 = NULL;
  const mxArray *c29_rhs25 = NULL;
  const mxArray *c29_lhs25 = NULL;
  const mxArray *c29_rhs26 = NULL;
  const mxArray *c29_lhs26 = NULL;
  const mxArray *c29_rhs27 = NULL;
  const mxArray *c29_lhs27 = NULL;
  const mxArray *c29_rhs28 = NULL;
  const mxArray *c29_lhs28 = NULL;
  const mxArray *c29_rhs29 = NULL;
  const mxArray *c29_lhs29 = NULL;
  const mxArray *c29_rhs30 = NULL;
  const mxArray *c29_lhs30 = NULL;
  const mxArray *c29_rhs31 = NULL;
  const mxArray *c29_lhs31 = NULL;
  const mxArray *c29_rhs32 = NULL;
  const mxArray *c29_lhs32 = NULL;
  const mxArray *c29_rhs33 = NULL;
  const mxArray *c29_lhs33 = NULL;
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("eye"), "name", "name", 0);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1406838348U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c29_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 1);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1368208230U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c29_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c29_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral"),
                  "context", "context", 3);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("isinf"), "name", "name", 3);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1363739056U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c29_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c29_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 5);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("eml_is_integer_class"),
                  "name", "name", 5);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1286843982U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c29_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 6);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("intmax"), "name", "name", 6);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c29_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 7);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c29_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 8);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("intmin"), "name", "name", 8);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c29_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 9);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c29_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 10);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "coder.internal.indexIntRelop"), "name", "name", 10);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1326753522U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c29_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!apply_float_relop"),
                  "context", "context", 11);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 11);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c29_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass"),
                  "context", "context", 12);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 12);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1326753196U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c29_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass"),
                  "context", "context", 13);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("intmin"), "name", "name", 13);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c29_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 14);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 14);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c29_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("intmax"), "name", "name", 15);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c29_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 16);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1397282622U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c29_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 17);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("isfi"), "name", "name", 17);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 17);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1346535558U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c29_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 18);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1398900798U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c29_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 19);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("intmax"), "name", "name", 19);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c29_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 20);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("intmin"), "name", "name", 20);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c29_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(""), "context", "context", 21);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("quatrot"), "name", "name",
                  21);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DIPCc - Energybounding/quatrot.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1462213506U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c29_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DIPCc - Energybounding/quatrot.m"),
                  "context", "context", 22);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("quatconj"), "name", "name",
                  22);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatconj.p"), "resolved", "resolved",
                  22);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1410808258U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c29_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DIPCc - Energybounding/quatrot.m"),
                  "context", "context", 23);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("quatmultiply"), "name",
                  "name", 23);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatmultiply.p"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1410808258U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c29_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatmultiply.p"), "context",
                  "context", 24);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("max"), "name", "name", 24);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1311280516U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c29_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 25);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1378321184U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c29_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 26);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 26);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c29_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 27);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c29_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 28);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 28);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c29_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 29);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 29);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c29_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 30);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 30);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c29_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 31);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 31);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c29_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 32);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 32);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c29_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(""), "context", "context", 33);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("skew_sm"), "name", "name",
                  33);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DIPCc - Energybounding/skew_sm.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1462213506U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c29_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs33), "lhs", "lhs",
                  33);
  sf_mex_destroy(&c29_rhs0);
  sf_mex_destroy(&c29_lhs0);
  sf_mex_destroy(&c29_rhs1);
  sf_mex_destroy(&c29_lhs1);
  sf_mex_destroy(&c29_rhs2);
  sf_mex_destroy(&c29_lhs2);
  sf_mex_destroy(&c29_rhs3);
  sf_mex_destroy(&c29_lhs3);
  sf_mex_destroy(&c29_rhs4);
  sf_mex_destroy(&c29_lhs4);
  sf_mex_destroy(&c29_rhs5);
  sf_mex_destroy(&c29_lhs5);
  sf_mex_destroy(&c29_rhs6);
  sf_mex_destroy(&c29_lhs6);
  sf_mex_destroy(&c29_rhs7);
  sf_mex_destroy(&c29_lhs7);
  sf_mex_destroy(&c29_rhs8);
  sf_mex_destroy(&c29_lhs8);
  sf_mex_destroy(&c29_rhs9);
  sf_mex_destroy(&c29_lhs9);
  sf_mex_destroy(&c29_rhs10);
  sf_mex_destroy(&c29_lhs10);
  sf_mex_destroy(&c29_rhs11);
  sf_mex_destroy(&c29_lhs11);
  sf_mex_destroy(&c29_rhs12);
  sf_mex_destroy(&c29_lhs12);
  sf_mex_destroy(&c29_rhs13);
  sf_mex_destroy(&c29_lhs13);
  sf_mex_destroy(&c29_rhs14);
  sf_mex_destroy(&c29_lhs14);
  sf_mex_destroy(&c29_rhs15);
  sf_mex_destroy(&c29_lhs15);
  sf_mex_destroy(&c29_rhs16);
  sf_mex_destroy(&c29_lhs16);
  sf_mex_destroy(&c29_rhs17);
  sf_mex_destroy(&c29_lhs17);
  sf_mex_destroy(&c29_rhs18);
  sf_mex_destroy(&c29_lhs18);
  sf_mex_destroy(&c29_rhs19);
  sf_mex_destroy(&c29_lhs19);
  sf_mex_destroy(&c29_rhs20);
  sf_mex_destroy(&c29_lhs20);
  sf_mex_destroy(&c29_rhs21);
  sf_mex_destroy(&c29_lhs21);
  sf_mex_destroy(&c29_rhs22);
  sf_mex_destroy(&c29_lhs22);
  sf_mex_destroy(&c29_rhs23);
  sf_mex_destroy(&c29_lhs23);
  sf_mex_destroy(&c29_rhs24);
  sf_mex_destroy(&c29_lhs24);
  sf_mex_destroy(&c29_rhs25);
  sf_mex_destroy(&c29_lhs25);
  sf_mex_destroy(&c29_rhs26);
  sf_mex_destroy(&c29_lhs26);
  sf_mex_destroy(&c29_rhs27);
  sf_mex_destroy(&c29_lhs27);
  sf_mex_destroy(&c29_rhs28);
  sf_mex_destroy(&c29_lhs28);
  sf_mex_destroy(&c29_rhs29);
  sf_mex_destroy(&c29_lhs29);
  sf_mex_destroy(&c29_rhs30);
  sf_mex_destroy(&c29_lhs30);
  sf_mex_destroy(&c29_rhs31);
  sf_mex_destroy(&c29_lhs31);
  sf_mex_destroy(&c29_rhs32);
  sf_mex_destroy(&c29_lhs32);
  sf_mex_destroy(&c29_rhs33);
  sf_mex_destroy(&c29_lhs33);
}

static const mxArray *c29_emlrt_marshallOut(const char * c29_u)
{
  const mxArray *c29_y = NULL;
  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_create("y", c29_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c29_u)), false);
  return c29_y;
}

static const mxArray *c29_b_emlrt_marshallOut(const uint32_T c29_u)
{
  const mxArray *c29_y = NULL;
  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_create("y", &c29_u, 7, 0U, 0U, 0U, 0), false);
  return c29_y;
}

static void c29_eye(SFc29_DIPCaltInstanceStruct *chartInstance, real_T c29_I[9])
{
  int32_T c29_i196;
  int32_T c29_k;
  int32_T c29_b_k;
  (void)chartInstance;
  for (c29_i196 = 0; c29_i196 < 9; c29_i196++) {
    c29_I[c29_i196] = 0.0;
  }

  for (c29_k = 1; c29_k < 4; c29_k++) {
    c29_b_k = c29_k;
    c29_I[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
             (real_T)c29_b_k), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c29_b_k), 1, 3, 2, 0) - 1))
      - 1] = 1.0;
  }
}

static void c29_quatmultiply(SFc29_DIPCaltInstanceStruct *chartInstance, real_T
  c29_q[4], real_T c29_r[4], real_T c29_qout[4])
{
  real_T c29_q1;
  real_T c29_q2;
  real_T c29_q3;
  real_T c29_q4;
  real_T c29_r1;
  real_T c29_r2;
  real_T c29_r3;
  real_T c29_r4;
  (void)chartInstance;
  c29_q1 = c29_q[0];
  c29_q2 = c29_q[1];
  c29_q3 = c29_q[2];
  c29_q4 = c29_q[3];
  c29_r1 = c29_r[0];
  c29_r2 = c29_r[1];
  c29_r3 = c29_r[2];
  c29_r4 = c29_r[3];
  c29_qout[0] = ((c29_q1 * c29_r1 - c29_q2 * c29_r2) - c29_q3 * c29_r3) - c29_q4
    * c29_r4;
  c29_qout[1] = (c29_q1 * c29_r2 + c29_r1 * c29_q2) + (c29_q3 * c29_r4 - c29_q4 *
    c29_r3);
  c29_qout[2] = (c29_q1 * c29_r3 + c29_r1 * c29_q3) + (c29_q4 * c29_r2 - c29_q2 *
    c29_r4);
  c29_qout[3] = (c29_q1 * c29_r4 + c29_r1 * c29_q4) + (c29_q2 * c29_r3 - c29_q3 *
    c29_r2);
}

static const mxArray *c29_h_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData)
{
  const mxArray *c29_mxArrayOutData = NULL;
  int32_T c29_u;
  const mxArray *c29_y = NULL;
  SFc29_DIPCaltInstanceStruct *chartInstance;
  chartInstance = (SFc29_DIPCaltInstanceStruct *)chartInstanceVoid;
  c29_mxArrayOutData = NULL;
  c29_u = *(int32_T *)c29_inData;
  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_create("y", &c29_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c29_mxArrayOutData, c29_y, false);
  return c29_mxArrayOutData;
}

static int32_T c29_h_emlrt_marshallIn(SFc29_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId)
{
  int32_T c29_y;
  int32_T c29_i197;
  (void)chartInstance;
  sf_mex_import(c29_parentId, sf_mex_dup(c29_u), &c29_i197, 1, 6, 0U, 0, 0U, 0);
  c29_y = c29_i197;
  sf_mex_destroy(&c29_u);
  return c29_y;
}

static void c29_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData)
{
  const mxArray *c29_b_sfEvent;
  const char_T *c29_identifier;
  emlrtMsgIdentifier c29_thisId;
  int32_T c29_y;
  SFc29_DIPCaltInstanceStruct *chartInstance;
  chartInstance = (SFc29_DIPCaltInstanceStruct *)chartInstanceVoid;
  c29_b_sfEvent = sf_mex_dup(c29_mxArrayInData);
  c29_identifier = c29_varName;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_y = c29_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c29_b_sfEvent),
    &c29_thisId);
  sf_mex_destroy(&c29_b_sfEvent);
  *(int32_T *)c29_outData = c29_y;
  sf_mex_destroy(&c29_mxArrayInData);
}

static uint8_T c29_i_emlrt_marshallIn(SFc29_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c29_b_is_active_c29_DIPCalt, const char_T *c29_identifier)
{
  uint8_T c29_y;
  emlrtMsgIdentifier c29_thisId;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_y = c29_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c29_b_is_active_c29_DIPCalt), &c29_thisId);
  sf_mex_destroy(&c29_b_is_active_c29_DIPCalt);
  return c29_y;
}

static uint8_T c29_j_emlrt_marshallIn(SFc29_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId)
{
  uint8_T c29_y;
  uint8_T c29_u0;
  (void)chartInstance;
  sf_mex_import(c29_parentId, sf_mex_dup(c29_u), &c29_u0, 1, 3, 0U, 0, 0U, 0);
  c29_y = c29_u0;
  sf_mex_destroy(&c29_u);
  return c29_y;
}

static void init_dsm_address_info(SFc29_DIPCaltInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc29_DIPCaltInstanceStruct *chartInstance)
{
  chartInstance->c29_A = (real_T (*)[720])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c29_x = (real_T (*)[7])ssGetInputPortSignal_wrapper
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

void sf_c29_DIPCalt_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1172117118U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(221853289U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(984624105U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1120541888U);
}

mxArray* sf_c29_DIPCalt_get_post_codegen_info(void);
mxArray *sf_c29_DIPCalt_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("yMDaBA1W276qX2OfTSAkKH");
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
      pr[0] = (double)(24);
      pr[1] = (double)(30);
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
    mxArray* mxPostCodegenInfo = sf_c29_DIPCalt_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c29_DIPCalt_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c29_DIPCalt_jit_fallback_info(void)
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

mxArray *sf_c29_DIPCalt_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c29_DIPCalt_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c29_DIPCalt(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"A\",},{M[8],M[0],T\"is_active_c29_DIPCalt\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c29_DIPCalt_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc29_DIPCaltInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc29_DIPCaltInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DIPCaltMachineNumber_,
           29,
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
        init_script_number_translation(_DIPCaltMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_DIPCaltMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _DIPCaltMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,10,0,0,"rv");
          _SFD_SET_DATA_PROPS(1,2,0,1,"A");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,553);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"quatrot",0,-1,191);
        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"skew_sm",0,-1,127);

        {
          unsigned int dimVector[1];
          dimVector[0]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c29_c_sf_marshallOut,(MexInFcnForType)
            c29_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 24;
          dimVector[1]= 30;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c29_sf_marshallOut,(MexInFcnForType)
            c29_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 7;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c29_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c29_rv);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c29_A);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c29_x);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _DIPCaltMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "bebCeimQRLUNrJCuUBUPo";
}

static void sf_opaque_initialize_c29_DIPCalt(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc29_DIPCaltInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c29_DIPCalt((SFc29_DIPCaltInstanceStruct*) chartInstanceVar);
  initialize_c29_DIPCalt((SFc29_DIPCaltInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c29_DIPCalt(void *chartInstanceVar)
{
  enable_c29_DIPCalt((SFc29_DIPCaltInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c29_DIPCalt(void *chartInstanceVar)
{
  disable_c29_DIPCalt((SFc29_DIPCaltInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c29_DIPCalt(void *chartInstanceVar)
{
  sf_gateway_c29_DIPCalt((SFc29_DIPCaltInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c29_DIPCalt(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c29_DIPCalt((SFc29_DIPCaltInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c29_DIPCalt(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c29_DIPCalt((SFc29_DIPCaltInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c29_DIPCalt(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc29_DIPCaltInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DIPCalt_optimization_info();
    }

    finalize_c29_DIPCalt((SFc29_DIPCaltInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc29_DIPCalt((SFc29_DIPCaltInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c29_DIPCalt(SimStruct *S)
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
    initialize_params_c29_DIPCalt((SFc29_DIPCaltInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c29_DIPCalt(SimStruct *S)
{
  /* Actual parameters from chart:
     rv
   */
  const char_T *rtParamNames[] = { "rv" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for rv*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DIPCalt_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      29);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,29,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,29,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,29);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,29,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,29,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,29);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3562001673U));
  ssSetChecksum1(S,(1453687448U));
  ssSetChecksum2(S,(2925275005U));
  ssSetChecksum3(S,(4054823678U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c29_DIPCalt(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c29_DIPCalt(SimStruct *S)
{
  SFc29_DIPCaltInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc29_DIPCaltInstanceStruct *)utMalloc(sizeof
    (SFc29_DIPCaltInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc29_DIPCaltInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c29_DIPCalt;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c29_DIPCalt;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c29_DIPCalt;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c29_DIPCalt;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c29_DIPCalt;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c29_DIPCalt;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c29_DIPCalt;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c29_DIPCalt;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c29_DIPCalt;
  chartInstance->chartInfo.mdlStart = mdlStart_c29_DIPCalt;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c29_DIPCalt;
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

void c29_DIPCalt_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c29_DIPCalt(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c29_DIPCalt(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c29_DIPCalt(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c29_DIPCalt_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

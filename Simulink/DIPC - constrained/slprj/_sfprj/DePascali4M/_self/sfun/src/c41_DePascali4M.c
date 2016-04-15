/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DePascali4M_sfun.h"
#include "c41_DePascali4M.h"
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
static const char * c41_debug_family_names[5] = { "nargin", "nargout", "z", "x",
  "z_w" };

static const char * c41_b_debug_family_names[6] = { "rwq", "nargin", "nargout",
  "q", "r", "rw" };

/* Function Declarations */
static void initialize_c41_DePascali4M(SFc41_DePascali4MInstanceStruct
  *chartInstance);
static void initialize_params_c41_DePascali4M(SFc41_DePascali4MInstanceStruct
  *chartInstance);
static void enable_c41_DePascali4M(SFc41_DePascali4MInstanceStruct
  *chartInstance);
static void disable_c41_DePascali4M(SFc41_DePascali4MInstanceStruct
  *chartInstance);
static void c41_update_debugger_state_c41_DePascali4M
  (SFc41_DePascali4MInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c41_DePascali4M
  (SFc41_DePascali4MInstanceStruct *chartInstance);
static void set_sim_state_c41_DePascali4M(SFc41_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c41_st);
static void finalize_c41_DePascali4M(SFc41_DePascali4MInstanceStruct
  *chartInstance);
static void sf_gateway_c41_DePascali4M(SFc41_DePascali4MInstanceStruct
  *chartInstance);
static void mdl_start_c41_DePascali4M(SFc41_DePascali4MInstanceStruct
  *chartInstance);
static void initSimStructsc41_DePascali4M(SFc41_DePascali4MInstanceStruct
  *chartInstance);
static void c41_quatrot(SFc41_DePascali4MInstanceStruct *chartInstance, real_T
  c41_q[4], real_T c41_r[3], real_T c41_rw[3]);
static void init_script_number_translation(uint32_T c41_machineNumber, uint32_T
  c41_chartNumber, uint32_T c41_instanceNumber);
static const mxArray *c41_sf_marshallOut(void *chartInstanceVoid, void
  *c41_inData);
static void c41_emlrt_marshallIn(SFc41_DePascali4MInstanceStruct *chartInstance,
  const mxArray *c41_b_z_w, const char_T *c41_identifier, real_T c41_y[18]);
static void c41_b_emlrt_marshallIn(SFc41_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c41_u, const emlrtMsgIdentifier *c41_parentId,
  real_T c41_y[18]);
static void c41_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c41_mxArrayInData, const char_T *c41_varName, void *c41_outData);
static const mxArray *c41_b_sf_marshallOut(void *chartInstanceVoid, void
  *c41_inData);
static const mxArray *c41_c_sf_marshallOut(void *chartInstanceVoid, void
  *c41_inData);
static real_T c41_c_emlrt_marshallIn(SFc41_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c41_u, const emlrtMsgIdentifier *c41_parentId);
static void c41_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c41_mxArrayInData, const char_T *c41_varName, void *c41_outData);
static const mxArray *c41_d_sf_marshallOut(void *chartInstanceVoid, void
  *c41_inData);
static void c41_d_emlrt_marshallIn(SFc41_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c41_u, const emlrtMsgIdentifier *c41_parentId,
  real_T c41_y[3]);
static void c41_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c41_mxArrayInData, const char_T *c41_varName, void *c41_outData);
static const mxArray *c41_e_sf_marshallOut(void *chartInstanceVoid, void
  *c41_inData);
static void c41_e_emlrt_marshallIn(SFc41_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c41_u, const emlrtMsgIdentifier *c41_parentId,
  real_T c41_y[4]);
static void c41_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c41_mxArrayInData, const char_T *c41_varName, void *c41_outData);
static void c41_info_helper(const mxArray **c41_info);
static const mxArray *c41_emlrt_marshallOut(const char * c41_u);
static const mxArray *c41_b_emlrt_marshallOut(const uint32_T c41_u);
static void c41_quatmultiply(SFc41_DePascali4MInstanceStruct *chartInstance,
  real_T c41_q[4], real_T c41_r[4], real_T c41_qout[4]);
static const mxArray *c41_f_sf_marshallOut(void *chartInstanceVoid, void
  *c41_inData);
static int32_T c41_f_emlrt_marshallIn(SFc41_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c41_u, const emlrtMsgIdentifier *c41_parentId);
static void c41_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c41_mxArrayInData, const char_T *c41_varName, void *c41_outData);
static uint8_T c41_g_emlrt_marshallIn(SFc41_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c41_b_is_active_c41_DePascali4M, const char_T
  *c41_identifier);
static uint8_T c41_h_emlrt_marshallIn(SFc41_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c41_u, const emlrtMsgIdentifier *c41_parentId);
static void init_dsm_address_info(SFc41_DePascali4MInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc41_DePascali4MInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c41_DePascali4M(SFc41_DePascali4MInstanceStruct
  *chartInstance)
{
  chartInstance->c41_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c41_is_active_c41_DePascali4M = 0U;
}

static void initialize_params_c41_DePascali4M(SFc41_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c41_DePascali4M(SFc41_DePascali4MInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c41_DePascali4M(SFc41_DePascali4MInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c41_update_debugger_state_c41_DePascali4M
  (SFc41_DePascali4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c41_DePascali4M
  (SFc41_DePascali4MInstanceStruct *chartInstance)
{
  const mxArray *c41_st;
  const mxArray *c41_y = NULL;
  int32_T c41_i0;
  real_T c41_u[18];
  const mxArray *c41_b_y = NULL;
  uint8_T c41_hoistedGlobal;
  uint8_T c41_b_u;
  const mxArray *c41_c_y = NULL;
  c41_st = NULL;
  c41_st = NULL;
  c41_y = NULL;
  sf_mex_assign(&c41_y, sf_mex_createcellmatrix(2, 1), false);
  for (c41_i0 = 0; c41_i0 < 18; c41_i0++) {
    c41_u[c41_i0] = (*chartInstance->c41_z_w)[c41_i0];
  }

  c41_b_y = NULL;
  sf_mex_assign(&c41_b_y, sf_mex_create("y", c41_u, 0, 0U, 1U, 0U, 1, 18), false);
  sf_mex_setcell(c41_y, 0, c41_b_y);
  c41_hoistedGlobal = chartInstance->c41_is_active_c41_DePascali4M;
  c41_b_u = c41_hoistedGlobal;
  c41_c_y = NULL;
  sf_mex_assign(&c41_c_y, sf_mex_create("y", &c41_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c41_y, 1, c41_c_y);
  sf_mex_assign(&c41_st, c41_y, false);
  return c41_st;
}

static void set_sim_state_c41_DePascali4M(SFc41_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c41_st)
{
  const mxArray *c41_u;
  real_T c41_dv0[18];
  int32_T c41_i1;
  chartInstance->c41_doneDoubleBufferReInit = true;
  c41_u = sf_mex_dup(c41_st);
  c41_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c41_u, 0)),
                       "z_w", c41_dv0);
  for (c41_i1 = 0; c41_i1 < 18; c41_i1++) {
    (*chartInstance->c41_z_w)[c41_i1] = c41_dv0[c41_i1];
  }

  chartInstance->c41_is_active_c41_DePascali4M = c41_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c41_u, 1)),
     "is_active_c41_DePascali4M");
  sf_mex_destroy(&c41_u);
  c41_update_debugger_state_c41_DePascali4M(chartInstance);
  sf_mex_destroy(&c41_st);
}

static void finalize_c41_DePascali4M(SFc41_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c41_DePascali4M(SFc41_DePascali4MInstanceStruct
  *chartInstance)
{
  int32_T c41_i2;
  int32_T c41_i3;
  int32_T c41_i4;
  real_T c41_b_z[18];
  int32_T c41_i5;
  real_T c41_b_x[28];
  uint32_T c41_debug_family_var_map[5];
  real_T c41_nargin = 2.0;
  real_T c41_nargout = 1.0;
  real_T c41_b_z_w[18];
  int32_T c41_i6;
  real_T c41_c_x[4];
  int32_T c41_i7;
  real_T c41_c_z[3];
  real_T c41_dv1[3];
  int32_T c41_i8;
  real_T c41_d_x[4];
  int32_T c41_i9;
  real_T c41_d_z[3];
  real_T c41_dv2[3];
  int32_T c41_i10;
  real_T c41_e_x[4];
  int32_T c41_i11;
  real_T c41_e_z[3];
  real_T c41_dv3[3];
  int32_T c41_i12;
  int32_T c41_i13;
  int32_T c41_i14;
  int32_T c41_i15;
  int32_T c41_i16;
  int32_T c41_i17;
  int32_T c41_i18;
  int32_T c41_i19;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 19U, chartInstance->c41_sfEvent);
  for (c41_i2 = 0; c41_i2 < 18; c41_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c41_z)[c41_i2], 0U);
  }

  for (c41_i3 = 0; c41_i3 < 28; c41_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c41_x)[c41_i3], 1U);
  }

  chartInstance->c41_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 19U, chartInstance->c41_sfEvent);
  for (c41_i4 = 0; c41_i4 < 18; c41_i4++) {
    c41_b_z[c41_i4] = (*chartInstance->c41_z)[c41_i4];
  }

  for (c41_i5 = 0; c41_i5 < 28; c41_i5++) {
    c41_b_x[c41_i5] = (*chartInstance->c41_x)[c41_i5];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c41_debug_family_names,
    c41_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c41_nargin, 0U, c41_c_sf_marshallOut,
    c41_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c41_nargout, 1U, c41_c_sf_marshallOut,
    c41_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c41_b_z, 2U, c41_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c41_b_x, 3U, c41_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c41_b_z_w, 4U, c41_sf_marshallOut,
    c41_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c41_sfEvent, 3);
  for (c41_i6 = 0; c41_i6 < 4; c41_i6++) {
    c41_c_x[c41_i6] = c41_b_x[c41_i6 + 3];
  }

  for (c41_i7 = 0; c41_i7 < 3; c41_i7++) {
    c41_c_z[c41_i7] = c41_b_z[c41_i7];
  }

  c41_quatrot(chartInstance, c41_c_x, c41_c_z, c41_dv1);
  for (c41_i8 = 0; c41_i8 < 4; c41_i8++) {
    c41_d_x[c41_i8] = c41_b_x[c41_i8 + 3];
  }

  for (c41_i9 = 0; c41_i9 < 3; c41_i9++) {
    c41_d_z[c41_i9] = c41_b_z[c41_i9 + 6];
  }

  c41_quatrot(chartInstance, c41_d_x, c41_d_z, c41_dv2);
  for (c41_i10 = 0; c41_i10 < 4; c41_i10++) {
    c41_e_x[c41_i10] = c41_b_x[c41_i10 + 3];
  }

  for (c41_i11 = 0; c41_i11 < 3; c41_i11++) {
    c41_e_z[c41_i11] = c41_b_z[c41_i11 + 12];
  }

  c41_quatrot(chartInstance, c41_e_x, c41_e_z, c41_dv3);
  for (c41_i12 = 0; c41_i12 < 3; c41_i12++) {
    c41_b_z_w[c41_i12] = c41_dv1[c41_i12];
  }

  for (c41_i13 = 0; c41_i13 < 3; c41_i13++) {
    c41_b_z_w[c41_i13 + 3] = c41_b_z[c41_i13 + 3];
  }

  for (c41_i14 = 0; c41_i14 < 3; c41_i14++) {
    c41_b_z_w[c41_i14 + 6] = c41_dv2[c41_i14];
  }

  for (c41_i15 = 0; c41_i15 < 3; c41_i15++) {
    c41_b_z_w[c41_i15 + 9] = c41_b_z[c41_i15 + 9];
  }

  for (c41_i16 = 0; c41_i16 < 3; c41_i16++) {
    c41_b_z_w[c41_i16 + 12] = c41_dv3[c41_i16];
  }

  for (c41_i17 = 0; c41_i17 < 3; c41_i17++) {
    c41_b_z_w[c41_i17 + 15] = c41_b_z[c41_i17 + 15];
  }

  _SFD_EML_CALL(0U, chartInstance->c41_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c41_i18 = 0; c41_i18 < 18; c41_i18++) {
    (*chartInstance->c41_z_w)[c41_i18] = c41_b_z_w[c41_i18];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c41_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DePascali4MMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c41_i19 = 0; c41_i19 < 18; c41_i19++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c41_z_w)[c41_i19], 2U);
  }
}

static void mdl_start_c41_DePascali4M(SFc41_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc41_DePascali4M(SFc41_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c41_quatrot(SFc41_DePascali4MInstanceStruct *chartInstance, real_T
  c41_q[4], real_T c41_r[3], real_T c41_rw[3])
{
  uint32_T c41_debug_family_var_map[6];
  real_T c41_rwq[4];
  real_T c41_nargin = 2.0;
  real_T c41_nargout = 1.0;
  int32_T c41_i20;
  real_T c41_b_q[4];
  int32_T c41_k;
  real_T c41_b_k;
  real_T c41_dv4[4];
  int32_T c41_i21;
  int32_T c41_i22;
  real_T c41_c_q[4];
  real_T c41_dv5[4];
  int32_T c41_i23;
  real_T c41_d_q[4];
  int32_T c41_i24;
  real_T c41_dv6[4];
  int32_T c41_i25;
  int32_T c41_i26;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c41_b_debug_family_names,
    c41_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c41_rwq, 0U, c41_e_sf_marshallOut,
    c41_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c41_nargin, 1U, c41_c_sf_marshallOut,
    c41_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c41_nargout, 2U, c41_c_sf_marshallOut,
    c41_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c41_q, 3U, c41_e_sf_marshallOut,
    c41_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c41_r, 4U, c41_d_sf_marshallOut,
    c41_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c41_rw, 5U, c41_d_sf_marshallOut,
    c41_c_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c41_sfEvent, 4);
  for (c41_i20 = 0; c41_i20 < 4; c41_i20++) {
    c41_b_q[c41_i20] = c41_q[c41_i20];
  }

  for (c41_k = 0; c41_k < 3; c41_k++) {
    c41_b_k = 2.0 + (real_T)c41_k;
    c41_b_q[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c41_b_k), 1, 4, 1, 0) - 1] = -c41_b_q[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", c41_b_k), 1, 4, 1, 0) - 1];
  }

  c41_dv4[0] = 0.0;
  for (c41_i21 = 0; c41_i21 < 3; c41_i21++) {
    c41_dv4[c41_i21 + 1] = c41_r[c41_i21];
  }

  for (c41_i22 = 0; c41_i22 < 4; c41_i22++) {
    c41_c_q[c41_i22] = c41_b_q[c41_i22];
  }

  c41_quatmultiply(chartInstance, c41_dv4, c41_c_q, c41_dv5);
  for (c41_i23 = 0; c41_i23 < 4; c41_i23++) {
    c41_d_q[c41_i23] = c41_q[c41_i23];
  }

  for (c41_i24 = 0; c41_i24 < 4; c41_i24++) {
    c41_dv6[c41_i24] = c41_dv5[c41_i24];
  }

  c41_quatmultiply(chartInstance, c41_d_q, c41_dv6, c41_b_q);
  for (c41_i25 = 0; c41_i25 < 4; c41_i25++) {
    c41_rwq[c41_i25] = c41_b_q[c41_i25];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c41_sfEvent, 5);
  for (c41_i26 = 0; c41_i26 < 3; c41_i26++) {
    c41_rw[c41_i26] = c41_rwq[c41_i26 + 1];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c41_sfEvent, -5);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c41_machineNumber, uint32_T
  c41_chartNumber, uint32_T c41_instanceNumber)
{
  (void)c41_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c41_chartNumber, c41_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Martin\\Documents\\Git\\Simulink\\DIPC - constrained\\quatrot.m"));
}

static const mxArray *c41_sf_marshallOut(void *chartInstanceVoid, void
  *c41_inData)
{
  const mxArray *c41_mxArrayOutData = NULL;
  int32_T c41_i27;
  real_T c41_b_inData[18];
  int32_T c41_i28;
  real_T c41_u[18];
  const mxArray *c41_y = NULL;
  SFc41_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc41_DePascali4MInstanceStruct *)chartInstanceVoid;
  c41_mxArrayOutData = NULL;
  for (c41_i27 = 0; c41_i27 < 18; c41_i27++) {
    c41_b_inData[c41_i27] = (*(real_T (*)[18])c41_inData)[c41_i27];
  }

  for (c41_i28 = 0; c41_i28 < 18; c41_i28++) {
    c41_u[c41_i28] = c41_b_inData[c41_i28];
  }

  c41_y = NULL;
  sf_mex_assign(&c41_y, sf_mex_create("y", c41_u, 0, 0U, 1U, 0U, 1, 18), false);
  sf_mex_assign(&c41_mxArrayOutData, c41_y, false);
  return c41_mxArrayOutData;
}

static void c41_emlrt_marshallIn(SFc41_DePascali4MInstanceStruct *chartInstance,
  const mxArray *c41_b_z_w, const char_T *c41_identifier, real_T c41_y[18])
{
  emlrtMsgIdentifier c41_thisId;
  c41_thisId.fIdentifier = c41_identifier;
  c41_thisId.fParent = NULL;
  c41_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c41_b_z_w), &c41_thisId,
    c41_y);
  sf_mex_destroy(&c41_b_z_w);
}

static void c41_b_emlrt_marshallIn(SFc41_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c41_u, const emlrtMsgIdentifier *c41_parentId,
  real_T c41_y[18])
{
  real_T c41_dv7[18];
  int32_T c41_i29;
  (void)chartInstance;
  sf_mex_import(c41_parentId, sf_mex_dup(c41_u), c41_dv7, 1, 0, 0U, 1, 0U, 1, 18);
  for (c41_i29 = 0; c41_i29 < 18; c41_i29++) {
    c41_y[c41_i29] = c41_dv7[c41_i29];
  }

  sf_mex_destroy(&c41_u);
}

static void c41_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c41_mxArrayInData, const char_T *c41_varName, void *c41_outData)
{
  const mxArray *c41_b_z_w;
  const char_T *c41_identifier;
  emlrtMsgIdentifier c41_thisId;
  real_T c41_y[18];
  int32_T c41_i30;
  SFc41_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc41_DePascali4MInstanceStruct *)chartInstanceVoid;
  c41_b_z_w = sf_mex_dup(c41_mxArrayInData);
  c41_identifier = c41_varName;
  c41_thisId.fIdentifier = c41_identifier;
  c41_thisId.fParent = NULL;
  c41_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c41_b_z_w), &c41_thisId,
    c41_y);
  sf_mex_destroy(&c41_b_z_w);
  for (c41_i30 = 0; c41_i30 < 18; c41_i30++) {
    (*(real_T (*)[18])c41_outData)[c41_i30] = c41_y[c41_i30];
  }

  sf_mex_destroy(&c41_mxArrayInData);
}

static const mxArray *c41_b_sf_marshallOut(void *chartInstanceVoid, void
  *c41_inData)
{
  const mxArray *c41_mxArrayOutData = NULL;
  int32_T c41_i31;
  real_T c41_b_inData[28];
  int32_T c41_i32;
  real_T c41_u[28];
  const mxArray *c41_y = NULL;
  SFc41_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc41_DePascali4MInstanceStruct *)chartInstanceVoid;
  c41_mxArrayOutData = NULL;
  for (c41_i31 = 0; c41_i31 < 28; c41_i31++) {
    c41_b_inData[c41_i31] = (*(real_T (*)[28])c41_inData)[c41_i31];
  }

  for (c41_i32 = 0; c41_i32 < 28; c41_i32++) {
    c41_u[c41_i32] = c41_b_inData[c41_i32];
  }

  c41_y = NULL;
  sf_mex_assign(&c41_y, sf_mex_create("y", c41_u, 0, 0U, 1U, 0U, 1, 28), false);
  sf_mex_assign(&c41_mxArrayOutData, c41_y, false);
  return c41_mxArrayOutData;
}

static const mxArray *c41_c_sf_marshallOut(void *chartInstanceVoid, void
  *c41_inData)
{
  const mxArray *c41_mxArrayOutData = NULL;
  real_T c41_u;
  const mxArray *c41_y = NULL;
  SFc41_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc41_DePascali4MInstanceStruct *)chartInstanceVoid;
  c41_mxArrayOutData = NULL;
  c41_u = *(real_T *)c41_inData;
  c41_y = NULL;
  sf_mex_assign(&c41_y, sf_mex_create("y", &c41_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c41_mxArrayOutData, c41_y, false);
  return c41_mxArrayOutData;
}

static real_T c41_c_emlrt_marshallIn(SFc41_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c41_u, const emlrtMsgIdentifier *c41_parentId)
{
  real_T c41_y;
  real_T c41_d0;
  (void)chartInstance;
  sf_mex_import(c41_parentId, sf_mex_dup(c41_u), &c41_d0, 1, 0, 0U, 0, 0U, 0);
  c41_y = c41_d0;
  sf_mex_destroy(&c41_u);
  return c41_y;
}

static void c41_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c41_mxArrayInData, const char_T *c41_varName, void *c41_outData)
{
  const mxArray *c41_nargout;
  const char_T *c41_identifier;
  emlrtMsgIdentifier c41_thisId;
  real_T c41_y;
  SFc41_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc41_DePascali4MInstanceStruct *)chartInstanceVoid;
  c41_nargout = sf_mex_dup(c41_mxArrayInData);
  c41_identifier = c41_varName;
  c41_thisId.fIdentifier = c41_identifier;
  c41_thisId.fParent = NULL;
  c41_y = c41_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c41_nargout),
    &c41_thisId);
  sf_mex_destroy(&c41_nargout);
  *(real_T *)c41_outData = c41_y;
  sf_mex_destroy(&c41_mxArrayInData);
}

static const mxArray *c41_d_sf_marshallOut(void *chartInstanceVoid, void
  *c41_inData)
{
  const mxArray *c41_mxArrayOutData = NULL;
  int32_T c41_i33;
  real_T c41_b_inData[3];
  int32_T c41_i34;
  real_T c41_u[3];
  const mxArray *c41_y = NULL;
  SFc41_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc41_DePascali4MInstanceStruct *)chartInstanceVoid;
  c41_mxArrayOutData = NULL;
  for (c41_i33 = 0; c41_i33 < 3; c41_i33++) {
    c41_b_inData[c41_i33] = (*(real_T (*)[3])c41_inData)[c41_i33];
  }

  for (c41_i34 = 0; c41_i34 < 3; c41_i34++) {
    c41_u[c41_i34] = c41_b_inData[c41_i34];
  }

  c41_y = NULL;
  sf_mex_assign(&c41_y, sf_mex_create("y", c41_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c41_mxArrayOutData, c41_y, false);
  return c41_mxArrayOutData;
}

static void c41_d_emlrt_marshallIn(SFc41_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c41_u, const emlrtMsgIdentifier *c41_parentId,
  real_T c41_y[3])
{
  real_T c41_dv8[3];
  int32_T c41_i35;
  (void)chartInstance;
  sf_mex_import(c41_parentId, sf_mex_dup(c41_u), c41_dv8, 1, 0, 0U, 1, 0U, 1, 3);
  for (c41_i35 = 0; c41_i35 < 3; c41_i35++) {
    c41_y[c41_i35] = c41_dv8[c41_i35];
  }

  sf_mex_destroy(&c41_u);
}

static void c41_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c41_mxArrayInData, const char_T *c41_varName, void *c41_outData)
{
  const mxArray *c41_rw;
  const char_T *c41_identifier;
  emlrtMsgIdentifier c41_thisId;
  real_T c41_y[3];
  int32_T c41_i36;
  SFc41_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc41_DePascali4MInstanceStruct *)chartInstanceVoid;
  c41_rw = sf_mex_dup(c41_mxArrayInData);
  c41_identifier = c41_varName;
  c41_thisId.fIdentifier = c41_identifier;
  c41_thisId.fParent = NULL;
  c41_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c41_rw), &c41_thisId, c41_y);
  sf_mex_destroy(&c41_rw);
  for (c41_i36 = 0; c41_i36 < 3; c41_i36++) {
    (*(real_T (*)[3])c41_outData)[c41_i36] = c41_y[c41_i36];
  }

  sf_mex_destroy(&c41_mxArrayInData);
}

static const mxArray *c41_e_sf_marshallOut(void *chartInstanceVoid, void
  *c41_inData)
{
  const mxArray *c41_mxArrayOutData = NULL;
  int32_T c41_i37;
  real_T c41_b_inData[4];
  int32_T c41_i38;
  real_T c41_u[4];
  const mxArray *c41_y = NULL;
  SFc41_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc41_DePascali4MInstanceStruct *)chartInstanceVoid;
  c41_mxArrayOutData = NULL;
  for (c41_i37 = 0; c41_i37 < 4; c41_i37++) {
    c41_b_inData[c41_i37] = (*(real_T (*)[4])c41_inData)[c41_i37];
  }

  for (c41_i38 = 0; c41_i38 < 4; c41_i38++) {
    c41_u[c41_i38] = c41_b_inData[c41_i38];
  }

  c41_y = NULL;
  sf_mex_assign(&c41_y, sf_mex_create("y", c41_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c41_mxArrayOutData, c41_y, false);
  return c41_mxArrayOutData;
}

static void c41_e_emlrt_marshallIn(SFc41_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c41_u, const emlrtMsgIdentifier *c41_parentId,
  real_T c41_y[4])
{
  real_T c41_dv9[4];
  int32_T c41_i39;
  (void)chartInstance;
  sf_mex_import(c41_parentId, sf_mex_dup(c41_u), c41_dv9, 1, 0, 0U, 1, 0U, 1, 4);
  for (c41_i39 = 0; c41_i39 < 4; c41_i39++) {
    c41_y[c41_i39] = c41_dv9[c41_i39];
  }

  sf_mex_destroy(&c41_u);
}

static void c41_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c41_mxArrayInData, const char_T *c41_varName, void *c41_outData)
{
  const mxArray *c41_q;
  const char_T *c41_identifier;
  emlrtMsgIdentifier c41_thisId;
  real_T c41_y[4];
  int32_T c41_i40;
  SFc41_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc41_DePascali4MInstanceStruct *)chartInstanceVoid;
  c41_q = sf_mex_dup(c41_mxArrayInData);
  c41_identifier = c41_varName;
  c41_thisId.fIdentifier = c41_identifier;
  c41_thisId.fParent = NULL;
  c41_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c41_q), &c41_thisId, c41_y);
  sf_mex_destroy(&c41_q);
  for (c41_i40 = 0; c41_i40 < 4; c41_i40++) {
    (*(real_T (*)[4])c41_outData)[c41_i40] = c41_y[c41_i40];
  }

  sf_mex_destroy(&c41_mxArrayInData);
}

const mxArray *sf_c41_DePascali4M_get_eml_resolved_functions_info(void)
{
  const mxArray *c41_nameCaptureInfo = NULL;
  c41_nameCaptureInfo = NULL;
  sf_mex_assign(&c41_nameCaptureInfo, sf_mex_createstruct("structure", 2, 12, 1),
                false);
  c41_info_helper(&c41_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c41_nameCaptureInfo);
  return c41_nameCaptureInfo;
}

static void c41_info_helper(const mxArray **c41_info)
{
  const mxArray *c41_rhs0 = NULL;
  const mxArray *c41_lhs0 = NULL;
  const mxArray *c41_rhs1 = NULL;
  const mxArray *c41_lhs1 = NULL;
  const mxArray *c41_rhs2 = NULL;
  const mxArray *c41_lhs2 = NULL;
  const mxArray *c41_rhs3 = NULL;
  const mxArray *c41_lhs3 = NULL;
  const mxArray *c41_rhs4 = NULL;
  const mxArray *c41_lhs4 = NULL;
  const mxArray *c41_rhs5 = NULL;
  const mxArray *c41_lhs5 = NULL;
  const mxArray *c41_rhs6 = NULL;
  const mxArray *c41_lhs6 = NULL;
  const mxArray *c41_rhs7 = NULL;
  const mxArray *c41_lhs7 = NULL;
  const mxArray *c41_rhs8 = NULL;
  const mxArray *c41_lhs8 = NULL;
  const mxArray *c41_rhs9 = NULL;
  const mxArray *c41_lhs9 = NULL;
  const mxArray *c41_rhs10 = NULL;
  const mxArray *c41_lhs10 = NULL;
  const mxArray *c41_rhs11 = NULL;
  const mxArray *c41_lhs11 = NULL;
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut("quatrot"), "name", "name", 0);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DIPC - constrained/quatrot.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(1446631716U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c41_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c41_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c41_info, sf_mex_duplicatearraysafe(&c41_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c41_info, sf_mex_duplicatearraysafe(&c41_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DIPC - constrained/quatrot.m"),
                  "context", "context", 1);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut("quatconj"), "name", "name",
                  1);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatconj.p"), "resolved", "resolved",
                  1);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(1410808258U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c41_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c41_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c41_info, sf_mex_duplicatearraysafe(&c41_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c41_info, sf_mex_duplicatearraysafe(&c41_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DIPC - constrained/quatrot.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut("quatmultiply"), "name",
                  "name", 2);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatmultiply.p"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(1410808258U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c41_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c41_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c41_info, sf_mex_duplicatearraysafe(&c41_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c41_info, sf_mex_duplicatearraysafe(&c41_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatmultiply.p"), "context",
                  "context", 3);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut("max"), "name", "name", 3);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(1311280516U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c41_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c41_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c41_info, sf_mex_duplicatearraysafe(&c41_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c41_info, sf_mex_duplicatearraysafe(&c41_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 4);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(1378321184U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c41_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c41_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c41_info, sf_mex_duplicatearraysafe(&c41_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c41_info, sf_mex_duplicatearraysafe(&c41_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 5);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 5);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c41_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c41_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c41_info, sf_mex_duplicatearraysafe(&c41_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c41_info, sf_mex_duplicatearraysafe(&c41_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 6);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c41_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c41_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c41_info, sf_mex_duplicatearraysafe(&c41_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c41_info, sf_mex_duplicatearraysafe(&c41_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 7);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 7);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c41_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c41_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c41_info, sf_mex_duplicatearraysafe(&c41_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c41_info, sf_mex_duplicatearraysafe(&c41_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 8);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c41_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c41_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c41_info, sf_mex_duplicatearraysafe(&c41_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c41_info, sf_mex_duplicatearraysafe(&c41_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 9);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 9);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c41_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c41_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c41_info, sf_mex_duplicatearraysafe(&c41_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c41_info, sf_mex_duplicatearraysafe(&c41_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 10);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 10);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c41_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c41_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c41_info, sf_mex_duplicatearraysafe(&c41_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c41_info, sf_mex_duplicatearraysafe(&c41_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 11);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 11);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c41_info, c41_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c41_info, c41_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c41_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c41_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c41_info, sf_mex_duplicatearraysafe(&c41_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c41_info, sf_mex_duplicatearraysafe(&c41_lhs11), "lhs", "lhs",
                  11);
  sf_mex_destroy(&c41_rhs0);
  sf_mex_destroy(&c41_lhs0);
  sf_mex_destroy(&c41_rhs1);
  sf_mex_destroy(&c41_lhs1);
  sf_mex_destroy(&c41_rhs2);
  sf_mex_destroy(&c41_lhs2);
  sf_mex_destroy(&c41_rhs3);
  sf_mex_destroy(&c41_lhs3);
  sf_mex_destroy(&c41_rhs4);
  sf_mex_destroy(&c41_lhs4);
  sf_mex_destroy(&c41_rhs5);
  sf_mex_destroy(&c41_lhs5);
  sf_mex_destroy(&c41_rhs6);
  sf_mex_destroy(&c41_lhs6);
  sf_mex_destroy(&c41_rhs7);
  sf_mex_destroy(&c41_lhs7);
  sf_mex_destroy(&c41_rhs8);
  sf_mex_destroy(&c41_lhs8);
  sf_mex_destroy(&c41_rhs9);
  sf_mex_destroy(&c41_lhs9);
  sf_mex_destroy(&c41_rhs10);
  sf_mex_destroy(&c41_lhs10);
  sf_mex_destroy(&c41_rhs11);
  sf_mex_destroy(&c41_lhs11);
}

static const mxArray *c41_emlrt_marshallOut(const char * c41_u)
{
  const mxArray *c41_y = NULL;
  c41_y = NULL;
  sf_mex_assign(&c41_y, sf_mex_create("y", c41_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c41_u)), false);
  return c41_y;
}

static const mxArray *c41_b_emlrt_marshallOut(const uint32_T c41_u)
{
  const mxArray *c41_y = NULL;
  c41_y = NULL;
  sf_mex_assign(&c41_y, sf_mex_create("y", &c41_u, 7, 0U, 0U, 0U, 0), false);
  return c41_y;
}

static void c41_quatmultiply(SFc41_DePascali4MInstanceStruct *chartInstance,
  real_T c41_q[4], real_T c41_r[4], real_T c41_qout[4])
{
  real_T c41_q1;
  real_T c41_q2;
  real_T c41_q3;
  real_T c41_q4;
  real_T c41_r1;
  real_T c41_r2;
  real_T c41_r3;
  real_T c41_r4;
  (void)chartInstance;
  c41_q1 = c41_q[0];
  c41_q2 = c41_q[1];
  c41_q3 = c41_q[2];
  c41_q4 = c41_q[3];
  c41_r1 = c41_r[0];
  c41_r2 = c41_r[1];
  c41_r3 = c41_r[2];
  c41_r4 = c41_r[3];
  c41_qout[0] = ((c41_q1 * c41_r1 - c41_q2 * c41_r2) - c41_q3 * c41_r3) - c41_q4
    * c41_r4;
  c41_qout[1] = (c41_q1 * c41_r2 + c41_r1 * c41_q2) + (c41_q3 * c41_r4 - c41_q4 *
    c41_r3);
  c41_qout[2] = (c41_q1 * c41_r3 + c41_r1 * c41_q3) + (c41_q4 * c41_r2 - c41_q2 *
    c41_r4);
  c41_qout[3] = (c41_q1 * c41_r4 + c41_r1 * c41_q4) + (c41_q2 * c41_r3 - c41_q3 *
    c41_r2);
}

static const mxArray *c41_f_sf_marshallOut(void *chartInstanceVoid, void
  *c41_inData)
{
  const mxArray *c41_mxArrayOutData = NULL;
  int32_T c41_u;
  const mxArray *c41_y = NULL;
  SFc41_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc41_DePascali4MInstanceStruct *)chartInstanceVoid;
  c41_mxArrayOutData = NULL;
  c41_u = *(int32_T *)c41_inData;
  c41_y = NULL;
  sf_mex_assign(&c41_y, sf_mex_create("y", &c41_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c41_mxArrayOutData, c41_y, false);
  return c41_mxArrayOutData;
}

static int32_T c41_f_emlrt_marshallIn(SFc41_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c41_u, const emlrtMsgIdentifier *c41_parentId)
{
  int32_T c41_y;
  int32_T c41_i41;
  (void)chartInstance;
  sf_mex_import(c41_parentId, sf_mex_dup(c41_u), &c41_i41, 1, 6, 0U, 0, 0U, 0);
  c41_y = c41_i41;
  sf_mex_destroy(&c41_u);
  return c41_y;
}

static void c41_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c41_mxArrayInData, const char_T *c41_varName, void *c41_outData)
{
  const mxArray *c41_b_sfEvent;
  const char_T *c41_identifier;
  emlrtMsgIdentifier c41_thisId;
  int32_T c41_y;
  SFc41_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc41_DePascali4MInstanceStruct *)chartInstanceVoid;
  c41_b_sfEvent = sf_mex_dup(c41_mxArrayInData);
  c41_identifier = c41_varName;
  c41_thisId.fIdentifier = c41_identifier;
  c41_thisId.fParent = NULL;
  c41_y = c41_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c41_b_sfEvent),
    &c41_thisId);
  sf_mex_destroy(&c41_b_sfEvent);
  *(int32_T *)c41_outData = c41_y;
  sf_mex_destroy(&c41_mxArrayInData);
}

static uint8_T c41_g_emlrt_marshallIn(SFc41_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c41_b_is_active_c41_DePascali4M, const char_T
  *c41_identifier)
{
  uint8_T c41_y;
  emlrtMsgIdentifier c41_thisId;
  c41_thisId.fIdentifier = c41_identifier;
  c41_thisId.fParent = NULL;
  c41_y = c41_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c41_b_is_active_c41_DePascali4M), &c41_thisId);
  sf_mex_destroy(&c41_b_is_active_c41_DePascali4M);
  return c41_y;
}

static uint8_T c41_h_emlrt_marshallIn(SFc41_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c41_u, const emlrtMsgIdentifier *c41_parentId)
{
  uint8_T c41_y;
  uint8_T c41_u0;
  (void)chartInstance;
  sf_mex_import(c41_parentId, sf_mex_dup(c41_u), &c41_u0, 1, 3, 0U, 0, 0U, 0);
  c41_y = c41_u0;
  sf_mex_destroy(&c41_u);
  return c41_y;
}

static void init_dsm_address_info(SFc41_DePascali4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc41_DePascali4MInstanceStruct
  *chartInstance)
{
  chartInstance->c41_z = (real_T (*)[18])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c41_x = (real_T (*)[28])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c41_z_w = (real_T (*)[18])ssGetOutputPortSignal_wrapper
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

void sf_c41_DePascali4M_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(320847253U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4164905898U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(285879975U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2076912496U);
}

mxArray* sf_c41_DePascali4M_get_post_codegen_info(void);
mxArray *sf_c41_DePascali4M_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("ohjSsRrin3v7xGDfF8zJEB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(18);
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
      pr[0] = (double)(18);
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
    mxArray* mxPostCodegenInfo = sf_c41_DePascali4M_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c41_DePascali4M_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c41_DePascali4M_jit_fallback_info(void)
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

mxArray *sf_c41_DePascali4M_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c41_DePascali4M_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c41_DePascali4M(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"z_w\",},{M[8],M[0],T\"is_active_c41_DePascali4M\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c41_DePascali4M_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc41_DePascali4MInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc41_DePascali4MInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DePascali4MMachineNumber_,
           41,
           1,
           1,
           0,
           3,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,184);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"quatrot",0,-1,191);

        {
          unsigned int dimVector[1];
          dimVector[0]= 18;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c41_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 28;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c41_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 18;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c41_sf_marshallOut,(MexInFcnForType)
            c41_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c41_z);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c41_x);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c41_z_w);
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
  return "n3HQL5BUZGjOWC5ir8NIcH";
}

static void sf_opaque_initialize_c41_DePascali4M(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc41_DePascali4MInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c41_DePascali4M((SFc41_DePascali4MInstanceStruct*)
    chartInstanceVar);
  initialize_c41_DePascali4M((SFc41_DePascali4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c41_DePascali4M(void *chartInstanceVar)
{
  enable_c41_DePascali4M((SFc41_DePascali4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c41_DePascali4M(void *chartInstanceVar)
{
  disable_c41_DePascali4M((SFc41_DePascali4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c41_DePascali4M(void *chartInstanceVar)
{
  sf_gateway_c41_DePascali4M((SFc41_DePascali4MInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c41_DePascali4M(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c41_DePascali4M((SFc41_DePascali4MInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c41_DePascali4M(SimStruct* S, const mxArray *
  st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c41_DePascali4M((SFc41_DePascali4MInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c41_DePascali4M(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc41_DePascali4MInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DePascali4M_optimization_info();
    }

    finalize_c41_DePascali4M((SFc41_DePascali4MInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc41_DePascali4M((SFc41_DePascali4MInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c41_DePascali4M(SimStruct *S)
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
    initialize_params_c41_DePascali4M((SFc41_DePascali4MInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c41_DePascali4M(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DePascali4M_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      41);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,41,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,41,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,41);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,41,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,41,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,41);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1253707288U));
  ssSetChecksum1(S,(2873465532U));
  ssSetChecksum2(S,(563964845U));
  ssSetChecksum3(S,(3467326251U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c41_DePascali4M(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c41_DePascali4M(SimStruct *S)
{
  SFc41_DePascali4MInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc41_DePascali4MInstanceStruct *)utMalloc(sizeof
    (SFc41_DePascali4MInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc41_DePascali4MInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c41_DePascali4M;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c41_DePascali4M;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c41_DePascali4M;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c41_DePascali4M;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c41_DePascali4M;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c41_DePascali4M;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c41_DePascali4M;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c41_DePascali4M;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c41_DePascali4M;
  chartInstance->chartInfo.mdlStart = mdlStart_c41_DePascali4M;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c41_DePascali4M;
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

void c41_DePascali4M_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c41_DePascali4M(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c41_DePascali4M(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c41_DePascali4M(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c41_DePascali4M_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

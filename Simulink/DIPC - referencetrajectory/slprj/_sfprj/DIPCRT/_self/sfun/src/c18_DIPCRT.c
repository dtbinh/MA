/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DIPCRT_sfun.h"
#include "c18_DIPCRT.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DIPCRT_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c18_debug_family_names[6] = { "nargin", "nargout", "dx",
  "j1", "m1", "hcoriolis" };

static const char * c18_b_debug_family_names[4] = { "nargin", "nargout", "x",
  "X" };

/* Function Declarations */
static void initialize_c18_DIPCRT(SFc18_DIPCRTInstanceStruct *chartInstance);
static void initialize_params_c18_DIPCRT(SFc18_DIPCRTInstanceStruct
  *chartInstance);
static void enable_c18_DIPCRT(SFc18_DIPCRTInstanceStruct *chartInstance);
static void disable_c18_DIPCRT(SFc18_DIPCRTInstanceStruct *chartInstance);
static void c18_update_debugger_state_c18_DIPCRT(SFc18_DIPCRTInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c18_DIPCRT(SFc18_DIPCRTInstanceStruct
  *chartInstance);
static void set_sim_state_c18_DIPCRT(SFc18_DIPCRTInstanceStruct *chartInstance,
  const mxArray *c18_st);
static void finalize_c18_DIPCRT(SFc18_DIPCRTInstanceStruct *chartInstance);
static void sf_gateway_c18_DIPCRT(SFc18_DIPCRTInstanceStruct *chartInstance);
static void mdl_start_c18_DIPCRT(SFc18_DIPCRTInstanceStruct *chartInstance);
static void initSimStructsc18_DIPCRT(SFc18_DIPCRTInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c18_machineNumber, uint32_T
  c18_chartNumber, uint32_T c18_instanceNumber);
static const mxArray *c18_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static void c18_emlrt_marshallIn(SFc18_DIPCRTInstanceStruct *chartInstance,
  const mxArray *c18_b_hcoriolis, const char_T *c18_identifier, real_T c18_y[6]);
static void c18_b_emlrt_marshallIn(SFc18_DIPCRTInstanceStruct *chartInstance,
  const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId, real_T c18_y[6]);
static void c18_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static const mxArray *c18_b_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static real_T c18_c_emlrt_marshallIn(SFc18_DIPCRTInstanceStruct *chartInstance,
  const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void c18_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static const mxArray *c18_c_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static void c18_d_emlrt_marshallIn(SFc18_DIPCRTInstanceStruct *chartInstance,
  const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId, real_T c18_y[9]);
static void c18_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static const mxArray *c18_d_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static void c18_e_emlrt_marshallIn(SFc18_DIPCRTInstanceStruct *chartInstance,
  const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId, real_T c18_y[3]);
static void c18_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static void c18_info_helper(const mxArray **c18_info);
static const mxArray *c18_emlrt_marshallOut(const char * c18_u);
static const mxArray *c18_b_emlrt_marshallOut(const uint32_T c18_u);
static void c18_eml_scalar_eg(SFc18_DIPCRTInstanceStruct *chartInstance);
static void c18_eml_xgemm(SFc18_DIPCRTInstanceStruct *chartInstance, real_T
  c18_A[9], real_T c18_B[3], real_T c18_C[3], real_T c18_b_C[3]);
static const mxArray *c18_e_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static int32_T c18_f_emlrt_marshallIn(SFc18_DIPCRTInstanceStruct *chartInstance,
  const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void c18_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static uint8_T c18_g_emlrt_marshallIn(SFc18_DIPCRTInstanceStruct *chartInstance,
  const mxArray *c18_b_is_active_c18_DIPCRT, const char_T *c18_identifier);
static uint8_T c18_h_emlrt_marshallIn(SFc18_DIPCRTInstanceStruct *chartInstance,
  const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void c18_b_eml_xgemm(SFc18_DIPCRTInstanceStruct *chartInstance, real_T
  c18_A[9], real_T c18_B[3], real_T c18_C[3]);
static void init_dsm_address_info(SFc18_DIPCRTInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc18_DIPCRTInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c18_DIPCRT(SFc18_DIPCRTInstanceStruct *chartInstance)
{
  chartInstance->c18_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c18_is_active_c18_DIPCRT = 0U;
}

static void initialize_params_c18_DIPCRT(SFc18_DIPCRTInstanceStruct
  *chartInstance)
{
  real_T c18_d0;
  real_T c18_d1;
  sf_mex_import_named("j1", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c18_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c18_j1 = c18_d0;
  sf_mex_import_named("m1", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c18_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c18_m1 = c18_d1;
}

static void enable_c18_DIPCRT(SFc18_DIPCRTInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c18_DIPCRT(SFc18_DIPCRTInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c18_update_debugger_state_c18_DIPCRT(SFc18_DIPCRTInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c18_DIPCRT(SFc18_DIPCRTInstanceStruct
  *chartInstance)
{
  const mxArray *c18_st;
  const mxArray *c18_y = NULL;
  int32_T c18_i0;
  real_T c18_u[6];
  const mxArray *c18_b_y = NULL;
  uint8_T c18_hoistedGlobal;
  uint8_T c18_b_u;
  const mxArray *c18_c_y = NULL;
  c18_st = NULL;
  c18_st = NULL;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_createcellmatrix(2, 1), false);
  for (c18_i0 = 0; c18_i0 < 6; c18_i0++) {
    c18_u[c18_i0] = (*chartInstance->c18_hcoriolis)[c18_i0];
  }

  c18_b_y = NULL;
  sf_mex_assign(&c18_b_y, sf_mex_create("y", c18_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_setcell(c18_y, 0, c18_b_y);
  c18_hoistedGlobal = chartInstance->c18_is_active_c18_DIPCRT;
  c18_b_u = c18_hoistedGlobal;
  c18_c_y = NULL;
  sf_mex_assign(&c18_c_y, sf_mex_create("y", &c18_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c18_y, 1, c18_c_y);
  sf_mex_assign(&c18_st, c18_y, false);
  return c18_st;
}

static void set_sim_state_c18_DIPCRT(SFc18_DIPCRTInstanceStruct *chartInstance,
  const mxArray *c18_st)
{
  const mxArray *c18_u;
  real_T c18_dv0[6];
  int32_T c18_i1;
  chartInstance->c18_doneDoubleBufferReInit = true;
  c18_u = sf_mex_dup(c18_st);
  c18_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c18_u, 0)),
                       "hcoriolis", c18_dv0);
  for (c18_i1 = 0; c18_i1 < 6; c18_i1++) {
    (*chartInstance->c18_hcoriolis)[c18_i1] = c18_dv0[c18_i1];
  }

  chartInstance->c18_is_active_c18_DIPCRT = c18_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c18_u, 1)), "is_active_c18_DIPCRT");
  sf_mex_destroy(&c18_u);
  c18_update_debugger_state_c18_DIPCRT(chartInstance);
  sf_mex_destroy(&c18_st);
}

static void finalize_c18_DIPCRT(SFc18_DIPCRTInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c18_DIPCRT(SFc18_DIPCRTInstanceStruct *chartInstance)
{
  int32_T c18_i2;
  real_T c18_hoistedGlobal;
  real_T c18_b_hoistedGlobal;
  int32_T c18_i3;
  real_T c18_b_dx[6];
  real_T c18_b_j1;
  real_T c18_b_m1;
  uint32_T c18_debug_family_var_map[6];
  real_T c18_nargin = 3.0;
  real_T c18_nargout = 1.0;
  real_T c18_b_hcoriolis[6];
  int32_T c18_i4;
  real_T c18_x[3];
  uint32_T c18_b_debug_family_var_map[4];
  real_T c18_b_nargin = 1.0;
  real_T c18_b_nargout = 1.0;
  real_T c18_X[9];
  real_T c18_a;
  int32_T c18_i5;
  real_T c18_b[9];
  int32_T c18_i6;
  int32_T c18_i7;
  real_T c18_b_b[3];
  int32_T c18_i8;
  real_T c18_y[3];
  int32_T c18_i9;
  real_T c18_c_b[9];
  int32_T c18_i10;
  real_T c18_d_b[3];
  int32_T c18_i11;
  real_T c18_b_x[3];
  real_T c18_c_nargin = 1.0;
  real_T c18_c_nargout = 1.0;
  real_T c18_b_X[9];
  real_T c18_b_a;
  int32_T c18_i12;
  int32_T c18_i13;
  int32_T c18_i14;
  int32_T c18_i15;
  real_T c18_b_y[3];
  int32_T c18_i16;
  real_T c18_e_b[9];
  int32_T c18_i17;
  real_T c18_f_b[3];
  int32_T c18_i18;
  int32_T c18_i19;
  int32_T c18_i20;
  int32_T c18_i21;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 14U, chartInstance->c18_sfEvent);
  for (c18_i2 = 0; c18_i2 < 6; c18_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c18_dx)[c18_i2], 0U);
  }

  chartInstance->c18_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 14U, chartInstance->c18_sfEvent);
  c18_hoistedGlobal = chartInstance->c18_j1;
  c18_b_hoistedGlobal = chartInstance->c18_m1;
  for (c18_i3 = 0; c18_i3 < 6; c18_i3++) {
    c18_b_dx[c18_i3] = (*chartInstance->c18_dx)[c18_i3];
  }

  c18_b_j1 = c18_hoistedGlobal;
  c18_b_m1 = c18_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c18_debug_family_names,
    c18_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_nargin, 0U, c18_b_sf_marshallOut,
    c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_nargout, 1U, c18_b_sf_marshallOut,
    c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c18_b_dx, 2U, c18_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_b_j1, 3U, c18_b_sf_marshallOut,
    c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_b_m1, 4U, c18_b_sf_marshallOut,
    c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c18_b_hcoriolis, 5U, c18_sf_marshallOut,
    c18_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 2);
  for (c18_i4 = 0; c18_i4 < 3; c18_i4++) {
    c18_x[c18_i4] = c18_b_dx[c18_i4 + 3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c18_b_debug_family_names,
    c18_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_b_nargin, 0U, c18_b_sf_marshallOut,
    c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_b_nargout, 1U, c18_b_sf_marshallOut,
    c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c18_x, 2U, c18_d_sf_marshallOut,
    c18_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c18_X, 3U, c18_c_sf_marshallOut,
    c18_c_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c18_sfEvent, 3);
  c18_X[0] = 0.0;
  c18_X[3] = -c18_x[2];
  c18_X[6] = c18_x[1];
  c18_X[1] = c18_x[2];
  c18_X[4] = 0.0;
  c18_X[7] = -c18_x[0];
  c18_X[2] = -c18_x[1];
  c18_X[5] = c18_x[0];
  c18_X[8] = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c18_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  c18_a = c18_b_m1;
  for (c18_i5 = 0; c18_i5 < 9; c18_i5++) {
    c18_b[c18_i5] = c18_X[c18_i5];
  }

  for (c18_i6 = 0; c18_i6 < 9; c18_i6++) {
    c18_b[c18_i6] *= c18_a;
  }

  for (c18_i7 = 0; c18_i7 < 3; c18_i7++) {
    c18_b_b[c18_i7] = c18_b_dx[c18_i7];
  }

  c18_eml_scalar_eg(chartInstance);
  c18_eml_scalar_eg(chartInstance);
  for (c18_i8 = 0; c18_i8 < 3; c18_i8++) {
    c18_y[c18_i8] = 0.0;
  }

  for (c18_i9 = 0; c18_i9 < 9; c18_i9++) {
    c18_c_b[c18_i9] = c18_b[c18_i9];
  }

  for (c18_i10 = 0; c18_i10 < 3; c18_i10++) {
    c18_d_b[c18_i10] = c18_b_b[c18_i10];
  }

  c18_b_eml_xgemm(chartInstance, c18_c_b, c18_d_b, c18_y);
  for (c18_i11 = 0; c18_i11 < 3; c18_i11++) {
    c18_b_x[c18_i11] = c18_b_dx[c18_i11 + 3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c18_b_debug_family_names,
    c18_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_c_nargin, 0U, c18_b_sf_marshallOut,
    c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_c_nargout, 1U, c18_b_sf_marshallOut,
    c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c18_b_x, 2U, c18_d_sf_marshallOut,
    c18_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c18_b_X, 3U, c18_c_sf_marshallOut,
    c18_c_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c18_sfEvent, 3);
  c18_b_X[0] = 0.0;
  c18_b_X[3] = -c18_b_x[2];
  c18_b_X[6] = c18_b_x[1];
  c18_b_X[1] = c18_b_x[2];
  c18_b_X[4] = 0.0;
  c18_b_X[7] = -c18_b_x[0];
  c18_b_X[2] = -c18_b_x[1];
  c18_b_X[5] = c18_b_x[0];
  c18_b_X[8] = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c18_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  c18_b_a = c18_b_j1;
  for (c18_i12 = 0; c18_i12 < 9; c18_i12++) {
    c18_b[c18_i12] = c18_b_X[c18_i12];
  }

  for (c18_i13 = 0; c18_i13 < 9; c18_i13++) {
    c18_b[c18_i13] *= c18_b_a;
  }

  for (c18_i14 = 0; c18_i14 < 3; c18_i14++) {
    c18_b_b[c18_i14] = c18_b_dx[c18_i14 + 3];
  }

  c18_eml_scalar_eg(chartInstance);
  c18_eml_scalar_eg(chartInstance);
  for (c18_i15 = 0; c18_i15 < 3; c18_i15++) {
    c18_b_y[c18_i15] = 0.0;
  }

  for (c18_i16 = 0; c18_i16 < 9; c18_i16++) {
    c18_e_b[c18_i16] = c18_b[c18_i16];
  }

  for (c18_i17 = 0; c18_i17 < 3; c18_i17++) {
    c18_f_b[c18_i17] = c18_b_b[c18_i17];
  }

  c18_b_eml_xgemm(chartInstance, c18_e_b, c18_f_b, c18_b_y);
  for (c18_i18 = 0; c18_i18 < 3; c18_i18++) {
    c18_b_hcoriolis[c18_i18] = c18_y[c18_i18];
  }

  for (c18_i19 = 0; c18_i19 < 3; c18_i19++) {
    c18_b_hcoriolis[c18_i19 + 3] = c18_b_y[c18_i19];
  }

  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, -2);
  _SFD_SYMBOL_SCOPE_POP();
  for (c18_i20 = 0; c18_i20 < 6; c18_i20++) {
    (*chartInstance->c18_hcoriolis)[c18_i20] = c18_b_hcoriolis[c18_i20];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c18_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DIPCRTMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c18_i21 = 0; c18_i21 < 6; c18_i21++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c18_hcoriolis)[c18_i21], 1U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c18_j1, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c18_m1, 3U);
}

static void mdl_start_c18_DIPCRT(SFc18_DIPCRTInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc18_DIPCRT(SFc18_DIPCRTInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c18_machineNumber, uint32_T
  c18_chartNumber, uint32_T c18_instanceNumber)
{
  (void)c18_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c18_chartNumber, c18_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Martin\\Documents\\Git\\Simulink\\DIPC - referencetrajectory\\skew_sm.m"));
}

static const mxArray *c18_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_i22;
  real_T c18_b_inData[6];
  int32_T c18_i23;
  real_T c18_u[6];
  const mxArray *c18_y = NULL;
  SFc18_DIPCRTInstanceStruct *chartInstance;
  chartInstance = (SFc18_DIPCRTInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  for (c18_i22 = 0; c18_i22 < 6; c18_i22++) {
    c18_b_inData[c18_i22] = (*(real_T (*)[6])c18_inData)[c18_i22];
  }

  for (c18_i23 = 0; c18_i23 < 6; c18_i23++) {
    c18_u[c18_i23] = c18_b_inData[c18_i23];
  }

  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", c18_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static void c18_emlrt_marshallIn(SFc18_DIPCRTInstanceStruct *chartInstance,
  const mxArray *c18_b_hcoriolis, const char_T *c18_identifier, real_T c18_y[6])
{
  emlrtMsgIdentifier c18_thisId;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_b_hcoriolis), &c18_thisId,
    c18_y);
  sf_mex_destroy(&c18_b_hcoriolis);
}

static void c18_b_emlrt_marshallIn(SFc18_DIPCRTInstanceStruct *chartInstance,
  const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId, real_T c18_y[6])
{
  real_T c18_dv1[6];
  int32_T c18_i24;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), c18_dv1, 1, 0, 0U, 1, 0U, 1, 6);
  for (c18_i24 = 0; c18_i24 < 6; c18_i24++) {
    c18_y[c18_i24] = c18_dv1[c18_i24];
  }

  sf_mex_destroy(&c18_u);
}

static void c18_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_b_hcoriolis;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  real_T c18_y[6];
  int32_T c18_i25;
  SFc18_DIPCRTInstanceStruct *chartInstance;
  chartInstance = (SFc18_DIPCRTInstanceStruct *)chartInstanceVoid;
  c18_b_hcoriolis = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_b_hcoriolis), &c18_thisId,
    c18_y);
  sf_mex_destroy(&c18_b_hcoriolis);
  for (c18_i25 = 0; c18_i25 < 6; c18_i25++) {
    (*(real_T (*)[6])c18_outData)[c18_i25] = c18_y[c18_i25];
  }

  sf_mex_destroy(&c18_mxArrayInData);
}

static const mxArray *c18_b_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  real_T c18_u;
  const mxArray *c18_y = NULL;
  SFc18_DIPCRTInstanceStruct *chartInstance;
  chartInstance = (SFc18_DIPCRTInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_u = *(real_T *)c18_inData;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", &c18_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static real_T c18_c_emlrt_marshallIn(SFc18_DIPCRTInstanceStruct *chartInstance,
  const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  real_T c18_y;
  real_T c18_d2;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_d2, 1, 0, 0U, 0, 0U, 0);
  c18_y = c18_d2;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void c18_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_b_m1;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  real_T c18_y;
  SFc18_DIPCRTInstanceStruct *chartInstance;
  chartInstance = (SFc18_DIPCRTInstanceStruct *)chartInstanceVoid;
  c18_b_m1 = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_b_m1),
    &c18_thisId);
  sf_mex_destroy(&c18_b_m1);
  *(real_T *)c18_outData = c18_y;
  sf_mex_destroy(&c18_mxArrayInData);
}

static const mxArray *c18_c_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_i26;
  int32_T c18_i27;
  int32_T c18_i28;
  real_T c18_b_inData[9];
  int32_T c18_i29;
  int32_T c18_i30;
  int32_T c18_i31;
  real_T c18_u[9];
  const mxArray *c18_y = NULL;
  SFc18_DIPCRTInstanceStruct *chartInstance;
  chartInstance = (SFc18_DIPCRTInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_i26 = 0;
  for (c18_i27 = 0; c18_i27 < 3; c18_i27++) {
    for (c18_i28 = 0; c18_i28 < 3; c18_i28++) {
      c18_b_inData[c18_i28 + c18_i26] = (*(real_T (*)[9])c18_inData)[c18_i28 +
        c18_i26];
    }

    c18_i26 += 3;
  }

  c18_i29 = 0;
  for (c18_i30 = 0; c18_i30 < 3; c18_i30++) {
    for (c18_i31 = 0; c18_i31 < 3; c18_i31++) {
      c18_u[c18_i31 + c18_i29] = c18_b_inData[c18_i31 + c18_i29];
    }

    c18_i29 += 3;
  }

  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", c18_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static void c18_d_emlrt_marshallIn(SFc18_DIPCRTInstanceStruct *chartInstance,
  const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId, real_T c18_y[9])
{
  real_T c18_dv2[9];
  int32_T c18_i32;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), c18_dv2, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c18_i32 = 0; c18_i32 < 9; c18_i32++) {
    c18_y[c18_i32] = c18_dv2[c18_i32];
  }

  sf_mex_destroy(&c18_u);
}

static void c18_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_X;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  real_T c18_y[9];
  int32_T c18_i33;
  int32_T c18_i34;
  int32_T c18_i35;
  SFc18_DIPCRTInstanceStruct *chartInstance;
  chartInstance = (SFc18_DIPCRTInstanceStruct *)chartInstanceVoid;
  c18_X = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_X), &c18_thisId, c18_y);
  sf_mex_destroy(&c18_X);
  c18_i33 = 0;
  for (c18_i34 = 0; c18_i34 < 3; c18_i34++) {
    for (c18_i35 = 0; c18_i35 < 3; c18_i35++) {
      (*(real_T (*)[9])c18_outData)[c18_i35 + c18_i33] = c18_y[c18_i35 + c18_i33];
    }

    c18_i33 += 3;
  }

  sf_mex_destroy(&c18_mxArrayInData);
}

static const mxArray *c18_d_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_i36;
  real_T c18_b_inData[3];
  int32_T c18_i37;
  real_T c18_u[3];
  const mxArray *c18_y = NULL;
  SFc18_DIPCRTInstanceStruct *chartInstance;
  chartInstance = (SFc18_DIPCRTInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  for (c18_i36 = 0; c18_i36 < 3; c18_i36++) {
    c18_b_inData[c18_i36] = (*(real_T (*)[3])c18_inData)[c18_i36];
  }

  for (c18_i37 = 0; c18_i37 < 3; c18_i37++) {
    c18_u[c18_i37] = c18_b_inData[c18_i37];
  }

  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", c18_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static void c18_e_emlrt_marshallIn(SFc18_DIPCRTInstanceStruct *chartInstance,
  const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId, real_T c18_y[3])
{
  real_T c18_dv3[3];
  int32_T c18_i38;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), c18_dv3, 1, 0, 0U, 1, 0U, 1, 3);
  for (c18_i38 = 0; c18_i38 < 3; c18_i38++) {
    c18_y[c18_i38] = c18_dv3[c18_i38];
  }

  sf_mex_destroy(&c18_u);
}

static void c18_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_x;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  real_T c18_y[3];
  int32_T c18_i39;
  SFc18_DIPCRTInstanceStruct *chartInstance;
  chartInstance = (SFc18_DIPCRTInstanceStruct *)chartInstanceVoid;
  c18_x = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_x), &c18_thisId, c18_y);
  sf_mex_destroy(&c18_x);
  for (c18_i39 = 0; c18_i39 < 3; c18_i39++) {
    (*(real_T (*)[3])c18_outData)[c18_i39] = c18_y[c18_i39];
  }

  sf_mex_destroy(&c18_mxArrayInData);
}

const mxArray *sf_c18_DIPCRT_get_eml_resolved_functions_info(void)
{
  const mxArray *c18_nameCaptureInfo = NULL;
  c18_nameCaptureInfo = NULL;
  sf_mex_assign(&c18_nameCaptureInfo, sf_mex_createstruct("structure", 2, 14, 1),
                false);
  c18_info_helper(&c18_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c18_nameCaptureInfo);
  return c18_nameCaptureInfo;
}

static void c18_info_helper(const mxArray **c18_info)
{
  const mxArray *c18_rhs0 = NULL;
  const mxArray *c18_lhs0 = NULL;
  const mxArray *c18_rhs1 = NULL;
  const mxArray *c18_lhs1 = NULL;
  const mxArray *c18_rhs2 = NULL;
  const mxArray *c18_lhs2 = NULL;
  const mxArray *c18_rhs3 = NULL;
  const mxArray *c18_lhs3 = NULL;
  const mxArray *c18_rhs4 = NULL;
  const mxArray *c18_lhs4 = NULL;
  const mxArray *c18_rhs5 = NULL;
  const mxArray *c18_lhs5 = NULL;
  const mxArray *c18_rhs6 = NULL;
  const mxArray *c18_lhs6 = NULL;
  const mxArray *c18_rhs7 = NULL;
  const mxArray *c18_lhs7 = NULL;
  const mxArray *c18_rhs8 = NULL;
  const mxArray *c18_lhs8 = NULL;
  const mxArray *c18_rhs9 = NULL;
  const mxArray *c18_lhs9 = NULL;
  const mxArray *c18_rhs10 = NULL;
  const mxArray *c18_lhs10 = NULL;
  const mxArray *c18_rhs11 = NULL;
  const mxArray *c18_lhs11 = NULL;
  const mxArray *c18_rhs12 = NULL;
  const mxArray *c18_lhs12 = NULL;
  const mxArray *c18_rhs13 = NULL;
  const mxArray *c18_lhs13 = NULL;
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("skew_sm"), "name", "name", 0);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DIPC - referencetrajectory/skew_sm.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1460657806U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c18_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 1);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1383902494U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c18_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 2);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c18_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 3);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 3);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c18_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 4);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 4);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c18_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 5);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c18_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  6);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1376005890U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c18_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 7);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c18_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 8);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c18_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 9);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 9);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c18_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 10);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 10);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c18_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 11);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 11);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c18_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 12);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 12);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c18_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 13);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 13);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c18_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs13), "lhs", "lhs",
                  13);
  sf_mex_destroy(&c18_rhs0);
  sf_mex_destroy(&c18_lhs0);
  sf_mex_destroy(&c18_rhs1);
  sf_mex_destroy(&c18_lhs1);
  sf_mex_destroy(&c18_rhs2);
  sf_mex_destroy(&c18_lhs2);
  sf_mex_destroy(&c18_rhs3);
  sf_mex_destroy(&c18_lhs3);
  sf_mex_destroy(&c18_rhs4);
  sf_mex_destroy(&c18_lhs4);
  sf_mex_destroy(&c18_rhs5);
  sf_mex_destroy(&c18_lhs5);
  sf_mex_destroy(&c18_rhs6);
  sf_mex_destroy(&c18_lhs6);
  sf_mex_destroy(&c18_rhs7);
  sf_mex_destroy(&c18_lhs7);
  sf_mex_destroy(&c18_rhs8);
  sf_mex_destroy(&c18_lhs8);
  sf_mex_destroy(&c18_rhs9);
  sf_mex_destroy(&c18_lhs9);
  sf_mex_destroy(&c18_rhs10);
  sf_mex_destroy(&c18_lhs10);
  sf_mex_destroy(&c18_rhs11);
  sf_mex_destroy(&c18_lhs11);
  sf_mex_destroy(&c18_rhs12);
  sf_mex_destroy(&c18_lhs12);
  sf_mex_destroy(&c18_rhs13);
  sf_mex_destroy(&c18_lhs13);
}

static const mxArray *c18_emlrt_marshallOut(const char * c18_u)
{
  const mxArray *c18_y = NULL;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", c18_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c18_u)), false);
  return c18_y;
}

static const mxArray *c18_b_emlrt_marshallOut(const uint32_T c18_u)
{
  const mxArray *c18_y = NULL;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", &c18_u, 7, 0U, 0U, 0U, 0), false);
  return c18_y;
}

static void c18_eml_scalar_eg(SFc18_DIPCRTInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c18_eml_xgemm(SFc18_DIPCRTInstanceStruct *chartInstance, real_T
  c18_A[9], real_T c18_B[3], real_T c18_C[3], real_T c18_b_C[3])
{
  int32_T c18_i40;
  int32_T c18_i41;
  real_T c18_b_A[9];
  int32_T c18_i42;
  real_T c18_b_B[3];
  for (c18_i40 = 0; c18_i40 < 3; c18_i40++) {
    c18_b_C[c18_i40] = c18_C[c18_i40];
  }

  for (c18_i41 = 0; c18_i41 < 9; c18_i41++) {
    c18_b_A[c18_i41] = c18_A[c18_i41];
  }

  for (c18_i42 = 0; c18_i42 < 3; c18_i42++) {
    c18_b_B[c18_i42] = c18_B[c18_i42];
  }

  c18_b_eml_xgemm(chartInstance, c18_b_A, c18_b_B, c18_b_C);
}

static const mxArray *c18_e_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_u;
  const mxArray *c18_y = NULL;
  SFc18_DIPCRTInstanceStruct *chartInstance;
  chartInstance = (SFc18_DIPCRTInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_u = *(int32_T *)c18_inData;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", &c18_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static int32_T c18_f_emlrt_marshallIn(SFc18_DIPCRTInstanceStruct *chartInstance,
  const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  int32_T c18_y;
  int32_T c18_i43;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_i43, 1, 6, 0U, 0, 0U, 0);
  c18_y = c18_i43;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void c18_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_b_sfEvent;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  int32_T c18_y;
  SFc18_DIPCRTInstanceStruct *chartInstance;
  chartInstance = (SFc18_DIPCRTInstanceStruct *)chartInstanceVoid;
  c18_b_sfEvent = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_b_sfEvent),
    &c18_thisId);
  sf_mex_destroy(&c18_b_sfEvent);
  *(int32_T *)c18_outData = c18_y;
  sf_mex_destroy(&c18_mxArrayInData);
}

static uint8_T c18_g_emlrt_marshallIn(SFc18_DIPCRTInstanceStruct *chartInstance,
  const mxArray *c18_b_is_active_c18_DIPCRT, const char_T *c18_identifier)
{
  uint8_T c18_y;
  emlrtMsgIdentifier c18_thisId;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c18_b_is_active_c18_DIPCRT), &c18_thisId);
  sf_mex_destroy(&c18_b_is_active_c18_DIPCRT);
  return c18_y;
}

static uint8_T c18_h_emlrt_marshallIn(SFc18_DIPCRTInstanceStruct *chartInstance,
  const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  uint8_T c18_y;
  uint8_T c18_u0;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_u0, 1, 3, 0U, 0, 0U, 0);
  c18_y = c18_u0;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void c18_b_eml_xgemm(SFc18_DIPCRTInstanceStruct *chartInstance, real_T
  c18_A[9], real_T c18_B[3], real_T c18_C[3])
{
  int32_T c18_i44;
  int32_T c18_i45;
  int32_T c18_i46;
  (void)chartInstance;
  for (c18_i44 = 0; c18_i44 < 3; c18_i44++) {
    c18_C[c18_i44] = 0.0;
    c18_i45 = 0;
    for (c18_i46 = 0; c18_i46 < 3; c18_i46++) {
      c18_C[c18_i44] += c18_A[c18_i45 + c18_i44] * c18_B[c18_i46];
      c18_i45 += 3;
    }
  }
}

static void init_dsm_address_info(SFc18_DIPCRTInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc18_DIPCRTInstanceStruct *chartInstance)
{
  chartInstance->c18_dx = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c18_hcoriolis = (real_T (*)[6])ssGetOutputPortSignal_wrapper
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

void sf_c18_DIPCRT_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3458758602U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2996865967U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2893575346U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2615567886U);
}

mxArray* sf_c18_DIPCRT_get_post_codegen_info(void);
mxArray *sf_c18_DIPCRT_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("2pAN8XqKE50gbCmGGn0nmB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c18_DIPCRT_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c18_DIPCRT_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c18_DIPCRT_jit_fallback_info(void)
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

mxArray *sf_c18_DIPCRT_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c18_DIPCRT_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c18_DIPCRT(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"hcoriolis\",},{M[8],M[0],T\"is_active_c18_DIPCRT\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c18_DIPCRT_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc18_DIPCRTInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc18_DIPCRTInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DIPCRTMachineNumber_,
           18,
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
        init_script_number_translation(_DIPCRTMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_DIPCRTMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _DIPCRTMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"dx");
          _SFD_SET_DATA_PROPS(1,2,0,1,"hcoriolis");
          _SFD_SET_DATA_PROPS(2,10,0,0,"j1");
          _SFD_SET_DATA_PROPS(3,10,0,0,"m1");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,124);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"skew_sm",0,-1,127);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c18_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c18_sf_marshallOut,(MexInFcnForType)
            c18_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c18_b_sf_marshallOut,(MexInFcnForType)
          c18_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c18_b_sf_marshallOut,(MexInFcnForType)
          c18_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c18_dx);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c18_hcoriolis);
        _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c18_j1);
        _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c18_m1);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _DIPCRTMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "39vboBrh4eZBpQB8o12LJ";
}

static void sf_opaque_initialize_c18_DIPCRT(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc18_DIPCRTInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c18_DIPCRT((SFc18_DIPCRTInstanceStruct*) chartInstanceVar);
  initialize_c18_DIPCRT((SFc18_DIPCRTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c18_DIPCRT(void *chartInstanceVar)
{
  enable_c18_DIPCRT((SFc18_DIPCRTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c18_DIPCRT(void *chartInstanceVar)
{
  disable_c18_DIPCRT((SFc18_DIPCRTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c18_DIPCRT(void *chartInstanceVar)
{
  sf_gateway_c18_DIPCRT((SFc18_DIPCRTInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c18_DIPCRT(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c18_DIPCRT((SFc18_DIPCRTInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c18_DIPCRT(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c18_DIPCRT((SFc18_DIPCRTInstanceStruct*)chartInfo->chartInstance,
    st);
}

static void sf_opaque_terminate_c18_DIPCRT(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc18_DIPCRTInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DIPCRT_optimization_info();
    }

    finalize_c18_DIPCRT((SFc18_DIPCRTInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc18_DIPCRT((SFc18_DIPCRTInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c18_DIPCRT(SimStruct *S)
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
    initialize_params_c18_DIPCRT((SFc18_DIPCRTInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c18_DIPCRT(SimStruct *S)
{
  /* Actual parameters from chart:
     j1 m1
   */
  const char_T *rtParamNames[] = { "j1", "m1" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for j1*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for m1*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DIPCRT_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      18);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,18,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,18,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,18);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,18,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,18,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,18);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3655757172U));
  ssSetChecksum1(S,(87589767U));
  ssSetChecksum2(S,(785608370U));
  ssSetChecksum3(S,(3048254812U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c18_DIPCRT(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c18_DIPCRT(SimStruct *S)
{
  SFc18_DIPCRTInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc18_DIPCRTInstanceStruct *)utMalloc(sizeof
    (SFc18_DIPCRTInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc18_DIPCRTInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c18_DIPCRT;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c18_DIPCRT;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c18_DIPCRT;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c18_DIPCRT;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c18_DIPCRT;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c18_DIPCRT;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c18_DIPCRT;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c18_DIPCRT;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c18_DIPCRT;
  chartInstance->chartInfo.mdlStart = mdlStart_c18_DIPCRT;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c18_DIPCRT;
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

void c18_DIPCRT_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c18_DIPCRT(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c18_DIPCRT(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c18_DIPCRT(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c18_DIPCRT_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Model1angular_sfun.h"
#include "c10_Model1angular.h"
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
static const char * c10_debug_family_names[5] = { "nargin", "nargout", "dx", "r",
  "rot" };

static const char * c10_b_debug_family_names[4] = { "nargin", "nargout", "x",
  "X" };

/* Function Declarations */
static void initialize_c10_Model1angular(SFc10_Model1angularInstanceStruct
  *chartInstance);
static void initialize_params_c10_Model1angular
  (SFc10_Model1angularInstanceStruct *chartInstance);
static void enable_c10_Model1angular(SFc10_Model1angularInstanceStruct
  *chartInstance);
static void disable_c10_Model1angular(SFc10_Model1angularInstanceStruct
  *chartInstance);
static void c10_update_debugger_state_c10_Model1angular
  (SFc10_Model1angularInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c10_Model1angular
  (SFc10_Model1angularInstanceStruct *chartInstance);
static void set_sim_state_c10_Model1angular(SFc10_Model1angularInstanceStruct
  *chartInstance, const mxArray *c10_st);
static void finalize_c10_Model1angular(SFc10_Model1angularInstanceStruct
  *chartInstance);
static void sf_gateway_c10_Model1angular(SFc10_Model1angularInstanceStruct
  *chartInstance);
static void mdl_start_c10_Model1angular(SFc10_Model1angularInstanceStruct
  *chartInstance);
static void initSimStructsc10_Model1angular(SFc10_Model1angularInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber, uint32_T c10_instanceNumber);
static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_emlrt_marshallIn(SFc10_Model1angularInstanceStruct
  *chartInstance, const mxArray *c10_b_rot, const char_T *c10_identifier, real_T
  c10_y[18]);
static void c10_b_emlrt_marshallIn(SFc10_Model1angularInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[18]);
static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_c_emlrt_marshallIn(SFc10_Model1angularInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[6]);
static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static real_T c10_d_emlrt_marshallIn(SFc10_Model1angularInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_e_emlrt_marshallIn(SFc10_Model1angularInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[9]);
static void c10_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_e_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_f_emlrt_marshallIn(SFc10_Model1angularInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[3]);
static void c10_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static void c10_info_helper(const mxArray **c10_info);
static const mxArray *c10_emlrt_marshallOut(const char * c10_u);
static const mxArray *c10_b_emlrt_marshallOut(const uint32_T c10_u);
static void c10_eml_scalar_eg(SFc10_Model1angularInstanceStruct *chartInstance);
static void c10_eml_xgemm(SFc10_Model1angularInstanceStruct *chartInstance,
  real_T c10_A[9], real_T c10_B[3], real_T c10_C[3], real_T c10_b_C[3]);
static const mxArray *c10_f_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static int32_T c10_g_emlrt_marshallIn(SFc10_Model1angularInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static uint8_T c10_h_emlrt_marshallIn(SFc10_Model1angularInstanceStruct
  *chartInstance, const mxArray *c10_b_is_active_c10_Model1angular, const char_T
  *c10_identifier);
static uint8_T c10_i_emlrt_marshallIn(SFc10_Model1angularInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_b_eml_xgemm(SFc10_Model1angularInstanceStruct *chartInstance,
  real_T c10_A[9], real_T c10_B[3], real_T c10_C[3]);
static void init_dsm_address_info(SFc10_Model1angularInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc10_Model1angularInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c10_Model1angular(SFc10_Model1angularInstanceStruct
  *chartInstance)
{
  chartInstance->c10_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c10_is_active_c10_Model1angular = 0U;
}

static void initialize_params_c10_Model1angular
  (SFc10_Model1angularInstanceStruct *chartInstance)
{
  real_T c10_dv0[6];
  int32_T c10_i0;
  sf_mex_import_named("r", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      c10_dv0, 0, 0, 0U, 1, 0U, 1, 6);
  for (c10_i0 = 0; c10_i0 < 6; c10_i0++) {
    chartInstance->c10_r[c10_i0] = c10_dv0[c10_i0];
  }
}

static void enable_c10_Model1angular(SFc10_Model1angularInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c10_Model1angular(SFc10_Model1angularInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c10_update_debugger_state_c10_Model1angular
  (SFc10_Model1angularInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c10_Model1angular
  (SFc10_Model1angularInstanceStruct *chartInstance)
{
  const mxArray *c10_st;
  const mxArray *c10_y = NULL;
  int32_T c10_i1;
  real_T c10_u[18];
  const mxArray *c10_b_y = NULL;
  uint8_T c10_hoistedGlobal;
  uint8_T c10_b_u;
  const mxArray *c10_c_y = NULL;
  c10_st = NULL;
  c10_st = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_createcellmatrix(2, 1), false);
  for (c10_i1 = 0; c10_i1 < 18; c10_i1++) {
    c10_u[c10_i1] = (*chartInstance->c10_rot)[c10_i1];
  }

  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 18), false);
  sf_mex_setcell(c10_y, 0, c10_b_y);
  c10_hoistedGlobal = chartInstance->c10_is_active_c10_Model1angular;
  c10_b_u = c10_hoistedGlobal;
  c10_c_y = NULL;
  sf_mex_assign(&c10_c_y, sf_mex_create("y", &c10_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c10_y, 1, c10_c_y);
  sf_mex_assign(&c10_st, c10_y, false);
  return c10_st;
}

static void set_sim_state_c10_Model1angular(SFc10_Model1angularInstanceStruct
  *chartInstance, const mxArray *c10_st)
{
  const mxArray *c10_u;
  real_T c10_dv1[18];
  int32_T c10_i2;
  chartInstance->c10_doneDoubleBufferReInit = true;
  c10_u = sf_mex_dup(c10_st);
  c10_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 0)),
                       "rot", c10_dv1);
  for (c10_i2 = 0; c10_i2 < 18; c10_i2++) {
    (*chartInstance->c10_rot)[c10_i2] = c10_dv1[c10_i2];
  }

  chartInstance->c10_is_active_c10_Model1angular = c10_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 1)),
     "is_active_c10_Model1angular");
  sf_mex_destroy(&c10_u);
  c10_update_debugger_state_c10_Model1angular(chartInstance);
  sf_mex_destroy(&c10_st);
}

static void finalize_c10_Model1angular(SFc10_Model1angularInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c10_Model1angular(SFc10_Model1angularInstanceStruct
  *chartInstance)
{
  int32_T c10_i3;
  int32_T c10_i4;
  real_T c10_b_dx[18];
  int32_T c10_i5;
  real_T c10_b_r[6];
  uint32_T c10_debug_family_var_map[5];
  real_T c10_nargin = 2.0;
  real_T c10_nargout = 1.0;
  real_T c10_b_rot[18];
  int32_T c10_i6;
  real_T c10_x[3];
  uint32_T c10_b_debug_family_var_map[4];
  real_T c10_b_nargin = 1.0;
  real_T c10_b_nargout = 1.0;
  real_T c10_X[9];
  int32_T c10_i7;
  real_T c10_a[9];
  int32_T c10_i8;
  real_T c10_b[3];
  int32_T c10_i9;
  real_T c10_y[3];
  int32_T c10_i10;
  real_T c10_b_a[9];
  int32_T c10_i11;
  real_T c10_b_b[3];
  int32_T c10_i12;
  real_T c10_b_x[3];
  real_T c10_c_nargin = 1.0;
  real_T c10_c_nargout = 1.0;
  real_T c10_b_X[9];
  int32_T c10_i13;
  int32_T c10_i14;
  int32_T c10_i15;
  real_T c10_b_y[3];
  int32_T c10_i16;
  real_T c10_c_a[9];
  int32_T c10_i17;
  real_T c10_c_b[3];
  int32_T c10_i18;
  int32_T c10_i19;
  int32_T c10_i20;
  int32_T c10_i21;
  int32_T c10_i22;
  int32_T c10_i23;
  int32_T c10_i24;
  int32_T c10_i25;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 8U, chartInstance->c10_sfEvent);
  for (c10_i3 = 0; c10_i3 < 18; c10_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c10_dx)[c10_i3], 0U);
  }

  chartInstance->c10_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c10_sfEvent);
  for (c10_i4 = 0; c10_i4 < 18; c10_i4++) {
    c10_b_dx[c10_i4] = (*chartInstance->c10_dx)[c10_i4];
  }

  for (c10_i5 = 0; c10_i5 < 6; c10_i5++) {
    c10_b_r[c10_i5] = chartInstance->c10_r[c10_i5];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c10_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 0U, c10_c_sf_marshallOut,
    c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 1U, c10_c_sf_marshallOut,
    c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_b_dx, 2U, c10_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_b_r, 3U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_b_rot, 4U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 2);
  for (c10_i6 = 0; c10_i6 < 3; c10_i6++) {
    c10_x[c10_i6] = c10_b_dx[c10_i6 + 3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c10_b_debug_family_names,
    c10_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargin, 0U, c10_c_sf_marshallOut,
    c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargout, 1U, c10_c_sf_marshallOut,
    c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_x, 2U, c10_e_sf_marshallOut,
    c10_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_X, 3U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  c10_X[0] = 0.0;
  c10_X[3] = -c10_x[2];
  c10_X[6] = c10_x[1];
  c10_X[1] = c10_x[2];
  c10_X[4] = 0.0;
  c10_X[7] = -c10_x[0];
  c10_X[2] = -c10_x[1];
  c10_X[5] = c10_x[0];
  c10_X[8] = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c10_i7 = 0; c10_i7 < 9; c10_i7++) {
    c10_a[c10_i7] = c10_X[c10_i7];
  }

  for (c10_i8 = 0; c10_i8 < 3; c10_i8++) {
    c10_b[c10_i8] = c10_b_r[c10_i8];
  }

  c10_eml_scalar_eg(chartInstance);
  c10_eml_scalar_eg(chartInstance);
  for (c10_i9 = 0; c10_i9 < 3; c10_i9++) {
    c10_y[c10_i9] = 0.0;
  }

  for (c10_i10 = 0; c10_i10 < 9; c10_i10++) {
    c10_b_a[c10_i10] = c10_a[c10_i10];
  }

  for (c10_i11 = 0; c10_i11 < 3; c10_i11++) {
    c10_b_b[c10_i11] = c10_b[c10_i11];
  }

  c10_b_eml_xgemm(chartInstance, c10_b_a, c10_b_b, c10_y);
  for (c10_i12 = 0; c10_i12 < 3; c10_i12++) {
    c10_b_x[c10_i12] = c10_b_dx[c10_i12 + 3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c10_b_debug_family_names,
    c10_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_nargin, 0U, c10_c_sf_marshallOut,
    c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_nargout, 1U, c10_c_sf_marshallOut,
    c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_b_x, 2U, c10_e_sf_marshallOut,
    c10_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_b_X, 3U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  c10_b_X[0] = 0.0;
  c10_b_X[3] = -c10_b_x[2];
  c10_b_X[6] = c10_b_x[1];
  c10_b_X[1] = c10_b_x[2];
  c10_b_X[4] = 0.0;
  c10_b_X[7] = -c10_b_x[0];
  c10_b_X[2] = -c10_b_x[1];
  c10_b_X[5] = c10_b_x[0];
  c10_b_X[8] = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c10_i13 = 0; c10_i13 < 9; c10_i13++) {
    c10_a[c10_i13] = c10_b_X[c10_i13];
  }

  for (c10_i14 = 0; c10_i14 < 3; c10_i14++) {
    c10_b[c10_i14] = c10_b_r[c10_i14 + 3];
  }

  c10_eml_scalar_eg(chartInstance);
  c10_eml_scalar_eg(chartInstance);
  for (c10_i15 = 0; c10_i15 < 3; c10_i15++) {
    c10_b_y[c10_i15] = 0.0;
  }

  for (c10_i16 = 0; c10_i16 < 9; c10_i16++) {
    c10_c_a[c10_i16] = c10_a[c10_i16];
  }

  for (c10_i17 = 0; c10_i17 < 3; c10_i17++) {
    c10_c_b[c10_i17] = c10_b[c10_i17];
  }

  c10_b_eml_xgemm(chartInstance, c10_c_a, c10_c_b, c10_b_y);
  for (c10_i18 = 0; c10_i18 < 6; c10_i18++) {
    c10_b_rot[c10_i18] = 0.0;
  }

  for (c10_i19 = 0; c10_i19 < 3; c10_i19++) {
    c10_b_rot[c10_i19 + 6] = c10_y[c10_i19];
  }

  for (c10_i20 = 0; c10_i20 < 3; c10_i20++) {
    c10_b_rot[c10_i20 + 9] = 0.0;
  }

  for (c10_i21 = 0; c10_i21 < 3; c10_i21++) {
    c10_b_rot[c10_i21 + 12] = c10_b_y[c10_i21];
  }

  for (c10_i22 = 0; c10_i22 < 3; c10_i22++) {
    c10_b_rot[c10_i22 + 15] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -2);
  _SFD_SYMBOL_SCOPE_POP();
  for (c10_i23 = 0; c10_i23 < 18; c10_i23++) {
    (*chartInstance->c10_rot)[c10_i23] = c10_b_rot[c10_i23];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c10_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Model1angularMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c10_i24 = 0; c10_i24 < 18; c10_i24++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c10_rot)[c10_i24], 1U);
  }

  for (c10_i25 = 0; c10_i25 < 6; c10_i25++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c10_r[c10_i25], 2U);
  }
}

static void mdl_start_c10_Model1angular(SFc10_Model1angularInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc10_Model1angular(SFc10_Model1angularInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber, uint32_T c10_instanceNumber)
{
  (void)c10_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c10_chartNumber, c10_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Martin\\Documents\\MATLAB\\Masterarbeit\\skew_sm.m"));
}

static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i26;
  real_T c10_b_inData[18];
  int32_T c10_i27;
  real_T c10_u[18];
  const mxArray *c10_y = NULL;
  SFc10_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc10_Model1angularInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i26 = 0; c10_i26 < 18; c10_i26++) {
    c10_b_inData[c10_i26] = (*(real_T (*)[18])c10_inData)[c10_i26];
  }

  for (c10_i27 = 0; c10_i27 < 18; c10_i27++) {
    c10_u[c10_i27] = c10_b_inData[c10_i27];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 18), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static void c10_emlrt_marshallIn(SFc10_Model1angularInstanceStruct
  *chartInstance, const mxArray *c10_b_rot, const char_T *c10_identifier, real_T
  c10_y[18])
{
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_rot), &c10_thisId,
    c10_y);
  sf_mex_destroy(&c10_b_rot);
}

static void c10_b_emlrt_marshallIn(SFc10_Model1angularInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[18])
{
  real_T c10_dv2[18];
  int32_T c10_i28;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv2, 1, 0, 0U, 1, 0U, 1, 18);
  for (c10_i28 = 0; c10_i28 < 18; c10_i28++) {
    c10_y[c10_i28] = c10_dv2[c10_i28];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_rot;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y[18];
  int32_T c10_i29;
  SFc10_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc10_Model1angularInstanceStruct *)chartInstanceVoid;
  c10_b_rot = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_rot), &c10_thisId,
    c10_y);
  sf_mex_destroy(&c10_b_rot);
  for (c10_i29 = 0; c10_i29 < 18; c10_i29++) {
    (*(real_T (*)[18])c10_outData)[c10_i29] = c10_y[c10_i29];
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i30;
  real_T c10_b_inData[6];
  int32_T c10_i31;
  real_T c10_u[6];
  const mxArray *c10_y = NULL;
  SFc10_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc10_Model1angularInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i30 = 0; c10_i30 < 6; c10_i30++) {
    c10_b_inData[c10_i30] = (*(real_T (*)[6])c10_inData)[c10_i30];
  }

  for (c10_i31 = 0; c10_i31 < 6; c10_i31++) {
    c10_u[c10_i31] = c10_b_inData[c10_i31];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static void c10_c_emlrt_marshallIn(SFc10_Model1angularInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[6])
{
  real_T c10_dv3[6];
  int32_T c10_i32;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv3, 1, 0, 0U, 1, 0U, 1, 6);
  for (c10_i32 = 0; c10_i32 < 6; c10_i32++) {
    c10_y[c10_i32] = c10_dv3[c10_i32];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_r;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y[6];
  int32_T c10_i33;
  SFc10_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc10_Model1angularInstanceStruct *)chartInstanceVoid;
  c10_b_r = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_r), &c10_thisId, c10_y);
  sf_mex_destroy(&c10_b_r);
  for (c10_i33 = 0; c10_i33 < 6; c10_i33++) {
    (*(real_T (*)[6])c10_outData)[c10_i33] = c10_y[c10_i33];
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  real_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc10_Model1angularInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(real_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static real_T c10_d_emlrt_marshallIn(SFc10_Model1angularInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  real_T c10_y;
  real_T c10_d0;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_d0, 1, 0, 0U, 0, 0U, 0);
  c10_y = c10_d0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_nargout;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y;
  SFc10_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc10_Model1angularInstanceStruct *)chartInstanceVoid;
  c10_nargout = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_nargout),
    &c10_thisId);
  sf_mex_destroy(&c10_nargout);
  *(real_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i34;
  int32_T c10_i35;
  int32_T c10_i36;
  real_T c10_b_inData[9];
  int32_T c10_i37;
  int32_T c10_i38;
  int32_T c10_i39;
  real_T c10_u[9];
  const mxArray *c10_y = NULL;
  SFc10_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc10_Model1angularInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_i34 = 0;
  for (c10_i35 = 0; c10_i35 < 3; c10_i35++) {
    for (c10_i36 = 0; c10_i36 < 3; c10_i36++) {
      c10_b_inData[c10_i36 + c10_i34] = (*(real_T (*)[9])c10_inData)[c10_i36 +
        c10_i34];
    }

    c10_i34 += 3;
  }

  c10_i37 = 0;
  for (c10_i38 = 0; c10_i38 < 3; c10_i38++) {
    for (c10_i39 = 0; c10_i39 < 3; c10_i39++) {
      c10_u[c10_i39 + c10_i37] = c10_b_inData[c10_i39 + c10_i37];
    }

    c10_i37 += 3;
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static void c10_e_emlrt_marshallIn(SFc10_Model1angularInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[9])
{
  real_T c10_dv4[9];
  int32_T c10_i40;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv4, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c10_i40 = 0; c10_i40 < 9; c10_i40++) {
    c10_y[c10_i40] = c10_dv4[c10_i40];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_X;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y[9];
  int32_T c10_i41;
  int32_T c10_i42;
  int32_T c10_i43;
  SFc10_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc10_Model1angularInstanceStruct *)chartInstanceVoid;
  c10_X = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_X), &c10_thisId, c10_y);
  sf_mex_destroy(&c10_X);
  c10_i41 = 0;
  for (c10_i42 = 0; c10_i42 < 3; c10_i42++) {
    for (c10_i43 = 0; c10_i43 < 3; c10_i43++) {
      (*(real_T (*)[9])c10_outData)[c10_i43 + c10_i41] = c10_y[c10_i43 + c10_i41];
    }

    c10_i41 += 3;
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_e_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i44;
  real_T c10_b_inData[3];
  int32_T c10_i45;
  real_T c10_u[3];
  const mxArray *c10_y = NULL;
  SFc10_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc10_Model1angularInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i44 = 0; c10_i44 < 3; c10_i44++) {
    c10_b_inData[c10_i44] = (*(real_T (*)[3])c10_inData)[c10_i44];
  }

  for (c10_i45 = 0; c10_i45 < 3; c10_i45++) {
    c10_u[c10_i45] = c10_b_inData[c10_i45];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static void c10_f_emlrt_marshallIn(SFc10_Model1angularInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[3])
{
  real_T c10_dv5[3];
  int32_T c10_i46;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv5, 1, 0, 0U, 1, 0U, 1, 3);
  for (c10_i46 = 0; c10_i46 < 3; c10_i46++) {
    c10_y[c10_i46] = c10_dv5[c10_i46];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_x;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y[3];
  int32_T c10_i47;
  SFc10_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc10_Model1angularInstanceStruct *)chartInstanceVoid;
  c10_x = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_x), &c10_thisId, c10_y);
  sf_mex_destroy(&c10_x);
  for (c10_i47 = 0; c10_i47 < 3; c10_i47++) {
    (*(real_T (*)[3])c10_outData)[c10_i47] = c10_y[c10_i47];
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

const mxArray *sf_c10_Model1angular_get_eml_resolved_functions_info(void)
{
  const mxArray *c10_nameCaptureInfo = NULL;
  c10_nameCaptureInfo = NULL;
  sf_mex_assign(&c10_nameCaptureInfo, sf_mex_createstruct("structure", 2, 14, 1),
                false);
  c10_info_helper(&c10_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c10_nameCaptureInfo);
  return c10_nameCaptureInfo;
}

static void c10_info_helper(const mxArray **c10_info)
{
  const mxArray *c10_rhs0 = NULL;
  const mxArray *c10_lhs0 = NULL;
  const mxArray *c10_rhs1 = NULL;
  const mxArray *c10_lhs1 = NULL;
  const mxArray *c10_rhs2 = NULL;
  const mxArray *c10_lhs2 = NULL;
  const mxArray *c10_rhs3 = NULL;
  const mxArray *c10_lhs3 = NULL;
  const mxArray *c10_rhs4 = NULL;
  const mxArray *c10_lhs4 = NULL;
  const mxArray *c10_rhs5 = NULL;
  const mxArray *c10_lhs5 = NULL;
  const mxArray *c10_rhs6 = NULL;
  const mxArray *c10_lhs6 = NULL;
  const mxArray *c10_rhs7 = NULL;
  const mxArray *c10_lhs7 = NULL;
  const mxArray *c10_rhs8 = NULL;
  const mxArray *c10_lhs8 = NULL;
  const mxArray *c10_rhs9 = NULL;
  const mxArray *c10_lhs9 = NULL;
  const mxArray *c10_rhs10 = NULL;
  const mxArray *c10_lhs10 = NULL;
  const mxArray *c10_rhs11 = NULL;
  const mxArray *c10_lhs11 = NULL;
  const mxArray *c10_rhs12 = NULL;
  const mxArray *c10_lhs12 = NULL;
  const mxArray *c10_rhs13 = NULL;
  const mxArray *c10_lhs13 = NULL;
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("skew_sm"), "name", "name", 0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/MATLAB/Masterarbeit/skew_sm.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1439587919U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c10_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1383902494U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c10_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 2);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c10_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 3);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 3);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c10_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 4);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 4);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c10_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 5);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c10_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  6);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1376005890U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c10_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 7);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c10_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 8);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c10_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 9);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 9);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c10_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 10);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 10);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c10_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 11);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 11);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c10_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 12);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 12);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c10_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 13);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 13);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c10_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs13), "lhs", "lhs",
                  13);
  sf_mex_destroy(&c10_rhs0);
  sf_mex_destroy(&c10_lhs0);
  sf_mex_destroy(&c10_rhs1);
  sf_mex_destroy(&c10_lhs1);
  sf_mex_destroy(&c10_rhs2);
  sf_mex_destroy(&c10_lhs2);
  sf_mex_destroy(&c10_rhs3);
  sf_mex_destroy(&c10_lhs3);
  sf_mex_destroy(&c10_rhs4);
  sf_mex_destroy(&c10_lhs4);
  sf_mex_destroy(&c10_rhs5);
  sf_mex_destroy(&c10_lhs5);
  sf_mex_destroy(&c10_rhs6);
  sf_mex_destroy(&c10_lhs6);
  sf_mex_destroy(&c10_rhs7);
  sf_mex_destroy(&c10_lhs7);
  sf_mex_destroy(&c10_rhs8);
  sf_mex_destroy(&c10_lhs8);
  sf_mex_destroy(&c10_rhs9);
  sf_mex_destroy(&c10_lhs9);
  sf_mex_destroy(&c10_rhs10);
  sf_mex_destroy(&c10_lhs10);
  sf_mex_destroy(&c10_rhs11);
  sf_mex_destroy(&c10_lhs11);
  sf_mex_destroy(&c10_rhs12);
  sf_mex_destroy(&c10_lhs12);
  sf_mex_destroy(&c10_rhs13);
  sf_mex_destroy(&c10_lhs13);
}

static const mxArray *c10_emlrt_marshallOut(const char * c10_u)
{
  const mxArray *c10_y = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c10_u)), false);
  return c10_y;
}

static const mxArray *c10_b_emlrt_marshallOut(const uint32_T c10_u)
{
  const mxArray *c10_y = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 7, 0U, 0U, 0U, 0), false);
  return c10_y;
}

static void c10_eml_scalar_eg(SFc10_Model1angularInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c10_eml_xgemm(SFc10_Model1angularInstanceStruct *chartInstance,
  real_T c10_A[9], real_T c10_B[3], real_T c10_C[3], real_T c10_b_C[3])
{
  int32_T c10_i48;
  int32_T c10_i49;
  real_T c10_b_A[9];
  int32_T c10_i50;
  real_T c10_b_B[3];
  for (c10_i48 = 0; c10_i48 < 3; c10_i48++) {
    c10_b_C[c10_i48] = c10_C[c10_i48];
  }

  for (c10_i49 = 0; c10_i49 < 9; c10_i49++) {
    c10_b_A[c10_i49] = c10_A[c10_i49];
  }

  for (c10_i50 = 0; c10_i50 < 3; c10_i50++) {
    c10_b_B[c10_i50] = c10_B[c10_i50];
  }

  c10_b_eml_xgemm(chartInstance, c10_b_A, c10_b_B, c10_b_C);
}

static const mxArray *c10_f_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc10_Model1angularInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(int32_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static int32_T c10_g_emlrt_marshallIn(SFc10_Model1angularInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  int32_T c10_y;
  int32_T c10_i51;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_i51, 1, 6, 0U, 0, 0U, 0);
  c10_y = c10_i51;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_sfEvent;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  int32_T c10_y;
  SFc10_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc10_Model1angularInstanceStruct *)chartInstanceVoid;
  c10_b_sfEvent = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_sfEvent),
    &c10_thisId);
  sf_mex_destroy(&c10_b_sfEvent);
  *(int32_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static uint8_T c10_h_emlrt_marshallIn(SFc10_Model1angularInstanceStruct
  *chartInstance, const mxArray *c10_b_is_active_c10_Model1angular, const char_T
  *c10_identifier)
{
  uint8_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c10_b_is_active_c10_Model1angular), &c10_thisId);
  sf_mex_destroy(&c10_b_is_active_c10_Model1angular);
  return c10_y;
}

static uint8_T c10_i_emlrt_marshallIn(SFc10_Model1angularInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  uint8_T c10_y;
  uint8_T c10_u0;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_u0, 1, 3, 0U, 0, 0U, 0);
  c10_y = c10_u0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_b_eml_xgemm(SFc10_Model1angularInstanceStruct *chartInstance,
  real_T c10_A[9], real_T c10_B[3], real_T c10_C[3])
{
  int32_T c10_i52;
  int32_T c10_i53;
  int32_T c10_i54;
  (void)chartInstance;
  for (c10_i52 = 0; c10_i52 < 3; c10_i52++) {
    c10_C[c10_i52] = 0.0;
    c10_i53 = 0;
    for (c10_i54 = 0; c10_i54 < 3; c10_i54++) {
      c10_C[c10_i52] += c10_A[c10_i53 + c10_i52] * c10_B[c10_i54];
      c10_i53 += 3;
    }
  }
}

static void init_dsm_address_info(SFc10_Model1angularInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc10_Model1angularInstanceStruct
  *chartInstance)
{
  chartInstance->c10_dx = (real_T (*)[18])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c10_rot = (real_T (*)[18])ssGetOutputPortSignal_wrapper
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

void sf_c10_Model1angular_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3596749073U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2977038818U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3023921789U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3437659616U);
}

mxArray* sf_c10_Model1angular_get_post_codegen_info(void);
mxArray *sf_c10_Model1angular_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("YWawQFBGs3iUZv2YJ6diED");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
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
    mxArray* mxPostCodegenInfo = sf_c10_Model1angular_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c10_Model1angular_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c10_Model1angular_jit_fallback_info(void)
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

mxArray *sf_c10_Model1angular_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c10_Model1angular_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c10_Model1angular(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"rot\",},{M[8],M[0],T\"is_active_c10_Model1angular\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c10_Model1angular_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc10_Model1angularInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc10_Model1angularInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Model1angularMachineNumber_,
           10,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"dx");
          _SFD_SET_DATA_PROPS(1,2,0,1,"rot");
          _SFD_SET_DATA_PROPS(2,10,0,0,"r");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,144);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"skew_sm",0,-1,127);

        {
          unsigned int dimVector[1];
          dimVector[0]= 18;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 18;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)
            c10_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)
            c10_b_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c10_dx);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c10_rot);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c10_r);
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
  return "SyMMPbImyp5DSf4al94PfG";
}

static void sf_opaque_initialize_c10_Model1angular(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc10_Model1angularInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c10_Model1angular((SFc10_Model1angularInstanceStruct*)
    chartInstanceVar);
  initialize_c10_Model1angular((SFc10_Model1angularInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c10_Model1angular(void *chartInstanceVar)
{
  enable_c10_Model1angular((SFc10_Model1angularInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c10_Model1angular(void *chartInstanceVar)
{
  disable_c10_Model1angular((SFc10_Model1angularInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c10_Model1angular(void *chartInstanceVar)
{
  sf_gateway_c10_Model1angular((SFc10_Model1angularInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c10_Model1angular(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c10_Model1angular((SFc10_Model1angularInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c10_Model1angular(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c10_Model1angular((SFc10_Model1angularInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c10_Model1angular(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc10_Model1angularInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Model1angular_optimization_info();
    }

    finalize_c10_Model1angular((SFc10_Model1angularInstanceStruct*)
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
  initSimStructsc10_Model1angular((SFc10_Model1angularInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c10_Model1angular(SimStruct *S)
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
    initialize_params_c10_Model1angular((SFc10_Model1angularInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c10_Model1angular(SimStruct *S)
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
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      10);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,10,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,10,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,10);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,10,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,10,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,10);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(233156052U));
  ssSetChecksum1(S,(3223895044U));
  ssSetChecksum2(S,(2819599783U));
  ssSetChecksum3(S,(271078635U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c10_Model1angular(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c10_Model1angular(SimStruct *S)
{
  SFc10_Model1angularInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc10_Model1angularInstanceStruct *)utMalloc(sizeof
    (SFc10_Model1angularInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc10_Model1angularInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c10_Model1angular;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c10_Model1angular;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c10_Model1angular;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c10_Model1angular;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c10_Model1angular;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c10_Model1angular;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c10_Model1angular;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c10_Model1angular;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c10_Model1angular;
  chartInstance->chartInfo.mdlStart = mdlStart_c10_Model1angular;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c10_Model1angular;
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

void c10_Model1angular_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c10_Model1angular(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c10_Model1angular(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c10_Model1angular(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c10_Model1angular_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

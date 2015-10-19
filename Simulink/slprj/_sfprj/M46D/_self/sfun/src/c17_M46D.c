/* Include files */

#include <stddef.h>
#include "blas.h"
#include "M46D_sfun.h"
#include "c17_M46D.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "M46D_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c17_debug_family_names[5] = { "nargin", "nargout", "dx", "r",
  "rot" };

static const char * c17_b_debug_family_names[4] = { "nargin", "nargout", "x",
  "X" };

/* Function Declarations */
static void initialize_c17_M46D(SFc17_M46DInstanceStruct *chartInstance);
static void initialize_params_c17_M46D(SFc17_M46DInstanceStruct *chartInstance);
static void enable_c17_M46D(SFc17_M46DInstanceStruct *chartInstance);
static void disable_c17_M46D(SFc17_M46DInstanceStruct *chartInstance);
static void c17_update_debugger_state_c17_M46D(SFc17_M46DInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c17_M46D(SFc17_M46DInstanceStruct
  *chartInstance);
static void set_sim_state_c17_M46D(SFc17_M46DInstanceStruct *chartInstance,
  const mxArray *c17_st);
static void finalize_c17_M46D(SFc17_M46DInstanceStruct *chartInstance);
static void sf_gateway_c17_M46D(SFc17_M46DInstanceStruct *chartInstance);
static void mdl_start_c17_M46D(SFc17_M46DInstanceStruct *chartInstance);
static void initSimStructsc17_M46D(SFc17_M46DInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c17_machineNumber, uint32_T
  c17_chartNumber, uint32_T c17_instanceNumber);
static const mxArray *c17_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static void c17_emlrt_marshallIn(SFc17_M46DInstanceStruct *chartInstance, const
  mxArray *c17_b_rot, const char_T *c17_identifier, real_T c17_y[6]);
static void c17_b_emlrt_marshallIn(SFc17_M46DInstanceStruct *chartInstance,
  const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId, real_T c17_y[6]);
static void c17_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static const mxArray *c17_b_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static void c17_c_emlrt_marshallIn(SFc17_M46DInstanceStruct *chartInstance,
  const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId, real_T c17_y[12]);
static void c17_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static const mxArray *c17_c_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static real_T c17_d_emlrt_marshallIn(SFc17_M46DInstanceStruct *chartInstance,
  const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void c17_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static const mxArray *c17_d_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static void c17_e_emlrt_marshallIn(SFc17_M46DInstanceStruct *chartInstance,
  const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId, real_T c17_y[9]);
static void c17_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static const mxArray *c17_e_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static void c17_f_emlrt_marshallIn(SFc17_M46DInstanceStruct *chartInstance,
  const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId, real_T c17_y[3]);
static void c17_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static void c17_info_helper(const mxArray **c17_info);
static const mxArray *c17_emlrt_marshallOut(const char * c17_u);
static const mxArray *c17_b_emlrt_marshallOut(const uint32_T c17_u);
static void c17_eml_scalar_eg(SFc17_M46DInstanceStruct *chartInstance);
static void c17_eml_xgemm(SFc17_M46DInstanceStruct *chartInstance, real_T c17_A
  [9], real_T c17_B[3], real_T c17_C[3], real_T c17_b_C[3]);
static const mxArray *c17_f_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static int32_T c17_g_emlrt_marshallIn(SFc17_M46DInstanceStruct *chartInstance,
  const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void c17_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static uint8_T c17_h_emlrt_marshallIn(SFc17_M46DInstanceStruct *chartInstance,
  const mxArray *c17_b_is_active_c17_M46D, const char_T *c17_identifier);
static uint8_T c17_i_emlrt_marshallIn(SFc17_M46DInstanceStruct *chartInstance,
  const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void c17_b_eml_xgemm(SFc17_M46DInstanceStruct *chartInstance, real_T
  c17_A[9], real_T c17_B[3], real_T c17_C[3]);
static void init_dsm_address_info(SFc17_M46DInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc17_M46DInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c17_M46D(SFc17_M46DInstanceStruct *chartInstance)
{
  chartInstance->c17_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c17_is_active_c17_M46D = 0U;
}

static void initialize_params_c17_M46D(SFc17_M46DInstanceStruct *chartInstance)
{
  real_T c17_dv0[12];
  int32_T c17_i0;
  sf_mex_import_named("r", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      c17_dv0, 0, 0, 0U, 1, 0U, 1, 12);
  for (c17_i0 = 0; c17_i0 < 12; c17_i0++) {
    chartInstance->c17_r[c17_i0] = c17_dv0[c17_i0];
  }
}

static void enable_c17_M46D(SFc17_M46DInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c17_M46D(SFc17_M46DInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c17_update_debugger_state_c17_M46D(SFc17_M46DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c17_M46D(SFc17_M46DInstanceStruct
  *chartInstance)
{
  const mxArray *c17_st;
  const mxArray *c17_y = NULL;
  int32_T c17_i1;
  real_T c17_u[6];
  const mxArray *c17_b_y = NULL;
  uint8_T c17_hoistedGlobal;
  uint8_T c17_b_u;
  const mxArray *c17_c_y = NULL;
  c17_st = NULL;
  c17_st = NULL;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_createcellmatrix(2, 1), false);
  for (c17_i1 = 0; c17_i1 < 6; c17_i1++) {
    c17_u[c17_i1] = (*chartInstance->c17_rot)[c17_i1];
  }

  c17_b_y = NULL;
  sf_mex_assign(&c17_b_y, sf_mex_create("y", c17_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_setcell(c17_y, 0, c17_b_y);
  c17_hoistedGlobal = chartInstance->c17_is_active_c17_M46D;
  c17_b_u = c17_hoistedGlobal;
  c17_c_y = NULL;
  sf_mex_assign(&c17_c_y, sf_mex_create("y", &c17_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c17_y, 1, c17_c_y);
  sf_mex_assign(&c17_st, c17_y, false);
  return c17_st;
}

static void set_sim_state_c17_M46D(SFc17_M46DInstanceStruct *chartInstance,
  const mxArray *c17_st)
{
  const mxArray *c17_u;
  real_T c17_dv1[6];
  int32_T c17_i2;
  chartInstance->c17_doneDoubleBufferReInit = true;
  c17_u = sf_mex_dup(c17_st);
  c17_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c17_u, 0)),
                       "rot", c17_dv1);
  for (c17_i2 = 0; c17_i2 < 6; c17_i2++) {
    (*chartInstance->c17_rot)[c17_i2] = c17_dv1[c17_i2];
  }

  chartInstance->c17_is_active_c17_M46D = c17_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c17_u, 1)), "is_active_c17_M46D");
  sf_mex_destroy(&c17_u);
  c17_update_debugger_state_c17_M46D(chartInstance);
  sf_mex_destroy(&c17_st);
}

static void finalize_c17_M46D(SFc17_M46DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c17_M46D(SFc17_M46DInstanceStruct *chartInstance)
{
  int32_T c17_i3;
  int32_T c17_i4;
  real_T c17_b_dx[6];
  int32_T c17_i5;
  real_T c17_b_r[12];
  uint32_T c17_debug_family_var_map[5];
  real_T c17_nargin = 2.0;
  real_T c17_nargout = 1.0;
  real_T c17_b_rot[6];
  int32_T c17_i6;
  real_T c17_x[3];
  uint32_T c17_b_debug_family_var_map[4];
  real_T c17_b_nargin = 1.0;
  real_T c17_b_nargout = 1.0;
  real_T c17_X[9];
  int32_T c17_i7;
  real_T c17_a[9];
  int32_T c17_i8;
  real_T c17_b[3];
  int32_T c17_i9;
  real_T c17_y[3];
  int32_T c17_i10;
  real_T c17_b_a[9];
  int32_T c17_i11;
  real_T c17_b_b[3];
  int32_T c17_i12;
  int32_T c17_i13;
  int32_T c17_i14;
  int32_T c17_i15;
  int32_T c17_i16;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 15U, chartInstance->c17_sfEvent);
  for (c17_i3 = 0; c17_i3 < 6; c17_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c17_dx)[c17_i3], 0U);
  }

  chartInstance->c17_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 15U, chartInstance->c17_sfEvent);
  for (c17_i4 = 0; c17_i4 < 6; c17_i4++) {
    c17_b_dx[c17_i4] = (*chartInstance->c17_dx)[c17_i4];
  }

  for (c17_i5 = 0; c17_i5 < 12; c17_i5++) {
    c17_b_r[c17_i5] = chartInstance->c17_r[c17_i5];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c17_debug_family_names,
    c17_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_nargin, 0U, c17_c_sf_marshallOut,
    c17_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_nargout, 1U, c17_c_sf_marshallOut,
    c17_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c17_b_dx, 2U, c17_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c17_b_r, 3U, c17_b_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c17_b_rot, 4U, c17_sf_marshallOut,
    c17_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 2);
  for (c17_i6 = 0; c17_i6 < 3; c17_i6++) {
    c17_x[c17_i6] = c17_b_dx[c17_i6 + 3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c17_b_debug_family_names,
    c17_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_b_nargin, 0U, c17_c_sf_marshallOut,
    c17_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_b_nargout, 1U, c17_c_sf_marshallOut,
    c17_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c17_x, 2U, c17_e_sf_marshallOut,
    c17_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c17_X, 3U, c17_d_sf_marshallOut,
    c17_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c17_sfEvent, 3);
  c17_X[0] = 0.0;
  c17_X[3] = -c17_x[2];
  c17_X[6] = c17_x[1];
  c17_X[1] = c17_x[2];
  c17_X[4] = 0.0;
  c17_X[7] = -c17_x[0];
  c17_X[2] = -c17_x[1];
  c17_X[5] = c17_x[0];
  c17_X[8] = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c17_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c17_i7 = 0; c17_i7 < 9; c17_i7++) {
    c17_a[c17_i7] = c17_X[c17_i7];
  }

  for (c17_i8 = 0; c17_i8 < 3; c17_i8++) {
    c17_b[c17_i8] = c17_b_r[c17_i8 + 6];
  }

  c17_eml_scalar_eg(chartInstance);
  c17_eml_scalar_eg(chartInstance);
  for (c17_i9 = 0; c17_i9 < 3; c17_i9++) {
    c17_y[c17_i9] = 0.0;
  }

  for (c17_i10 = 0; c17_i10 < 9; c17_i10++) {
    c17_b_a[c17_i10] = c17_a[c17_i10];
  }

  for (c17_i11 = 0; c17_i11 < 3; c17_i11++) {
    c17_b_b[c17_i11] = c17_b[c17_i11];
  }

  c17_b_eml_xgemm(chartInstance, c17_b_a, c17_b_b, c17_y);
  for (c17_i12 = 0; c17_i12 < 3; c17_i12++) {
    c17_b_rot[c17_i12] = c17_y[c17_i12];
  }

  for (c17_i13 = 0; c17_i13 < 3; c17_i13++) {
    c17_b_rot[c17_i13 + 3] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, -2);
  _SFD_SYMBOL_SCOPE_POP();
  for (c17_i14 = 0; c17_i14 < 6; c17_i14++) {
    (*chartInstance->c17_rot)[c17_i14] = c17_b_rot[c17_i14];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c17_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_M46DMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c17_i15 = 0; c17_i15 < 6; c17_i15++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c17_rot)[c17_i15], 1U);
  }

  for (c17_i16 = 0; c17_i16 < 12; c17_i16++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c17_r[c17_i16], 2U);
  }
}

static void mdl_start_c17_M46D(SFc17_M46DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc17_M46D(SFc17_M46DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c17_machineNumber, uint32_T
  c17_chartNumber, uint32_T c17_instanceNumber)
{
  (void)c17_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c17_chartNumber, c17_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Martin\\Documents\\MATLAB\\Masterarbeit\\skew_sm.m"));
}

static const mxArray *c17_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  int32_T c17_i17;
  real_T c17_b_inData[6];
  int32_T c17_i18;
  real_T c17_u[6];
  const mxArray *c17_y = NULL;
  SFc17_M46DInstanceStruct *chartInstance;
  chartInstance = (SFc17_M46DInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  for (c17_i17 = 0; c17_i17 < 6; c17_i17++) {
    c17_b_inData[c17_i17] = (*(real_T (*)[6])c17_inData)[c17_i17];
  }

  for (c17_i18 = 0; c17_i18 < 6; c17_i18++) {
    c17_u[c17_i18] = c17_b_inData[c17_i18];
  }

  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", c17_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static void c17_emlrt_marshallIn(SFc17_M46DInstanceStruct *chartInstance, const
  mxArray *c17_b_rot, const char_T *c17_identifier, real_T c17_y[6])
{
  emlrtMsgIdentifier c17_thisId;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_b_rot), &c17_thisId,
    c17_y);
  sf_mex_destroy(&c17_b_rot);
}

static void c17_b_emlrt_marshallIn(SFc17_M46DInstanceStruct *chartInstance,
  const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId, real_T c17_y[6])
{
  real_T c17_dv2[6];
  int32_T c17_i19;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), c17_dv2, 1, 0, 0U, 1, 0U, 1, 6);
  for (c17_i19 = 0; c17_i19 < 6; c17_i19++) {
    c17_y[c17_i19] = c17_dv2[c17_i19];
  }

  sf_mex_destroy(&c17_u);
}

static void c17_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_b_rot;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  real_T c17_y[6];
  int32_T c17_i20;
  SFc17_M46DInstanceStruct *chartInstance;
  chartInstance = (SFc17_M46DInstanceStruct *)chartInstanceVoid;
  c17_b_rot = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_b_rot), &c17_thisId,
    c17_y);
  sf_mex_destroy(&c17_b_rot);
  for (c17_i20 = 0; c17_i20 < 6; c17_i20++) {
    (*(real_T (*)[6])c17_outData)[c17_i20] = c17_y[c17_i20];
  }

  sf_mex_destroy(&c17_mxArrayInData);
}

static const mxArray *c17_b_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  int32_T c17_i21;
  real_T c17_b_inData[12];
  int32_T c17_i22;
  real_T c17_u[12];
  const mxArray *c17_y = NULL;
  SFc17_M46DInstanceStruct *chartInstance;
  chartInstance = (SFc17_M46DInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  for (c17_i21 = 0; c17_i21 < 12; c17_i21++) {
    c17_b_inData[c17_i21] = (*(real_T (*)[12])c17_inData)[c17_i21];
  }

  for (c17_i22 = 0; c17_i22 < 12; c17_i22++) {
    c17_u[c17_i22] = c17_b_inData[c17_i22];
  }

  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", c17_u, 0, 0U, 1U, 0U, 1, 12), false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static void c17_c_emlrt_marshallIn(SFc17_M46DInstanceStruct *chartInstance,
  const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId, real_T c17_y[12])
{
  real_T c17_dv3[12];
  int32_T c17_i23;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), c17_dv3, 1, 0, 0U, 1, 0U, 1, 12);
  for (c17_i23 = 0; c17_i23 < 12; c17_i23++) {
    c17_y[c17_i23] = c17_dv3[c17_i23];
  }

  sf_mex_destroy(&c17_u);
}

static void c17_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_b_r;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  real_T c17_y[12];
  int32_T c17_i24;
  SFc17_M46DInstanceStruct *chartInstance;
  chartInstance = (SFc17_M46DInstanceStruct *)chartInstanceVoid;
  c17_b_r = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_b_r), &c17_thisId, c17_y);
  sf_mex_destroy(&c17_b_r);
  for (c17_i24 = 0; c17_i24 < 12; c17_i24++) {
    (*(real_T (*)[12])c17_outData)[c17_i24] = c17_y[c17_i24];
  }

  sf_mex_destroy(&c17_mxArrayInData);
}

static const mxArray *c17_c_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  real_T c17_u;
  const mxArray *c17_y = NULL;
  SFc17_M46DInstanceStruct *chartInstance;
  chartInstance = (SFc17_M46DInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_u = *(real_T *)c17_inData;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static real_T c17_d_emlrt_marshallIn(SFc17_M46DInstanceStruct *chartInstance,
  const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId)
{
  real_T c17_y;
  real_T c17_d0;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), &c17_d0, 1, 0, 0U, 0, 0U, 0);
  c17_y = c17_d0;
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static void c17_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_nargout;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  real_T c17_y;
  SFc17_M46DInstanceStruct *chartInstance;
  chartInstance = (SFc17_M46DInstanceStruct *)chartInstanceVoid;
  c17_nargout = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_nargout),
    &c17_thisId);
  sf_mex_destroy(&c17_nargout);
  *(real_T *)c17_outData = c17_y;
  sf_mex_destroy(&c17_mxArrayInData);
}

static const mxArray *c17_d_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  int32_T c17_i25;
  int32_T c17_i26;
  int32_T c17_i27;
  real_T c17_b_inData[9];
  int32_T c17_i28;
  int32_T c17_i29;
  int32_T c17_i30;
  real_T c17_u[9];
  const mxArray *c17_y = NULL;
  SFc17_M46DInstanceStruct *chartInstance;
  chartInstance = (SFc17_M46DInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_i25 = 0;
  for (c17_i26 = 0; c17_i26 < 3; c17_i26++) {
    for (c17_i27 = 0; c17_i27 < 3; c17_i27++) {
      c17_b_inData[c17_i27 + c17_i25] = (*(real_T (*)[9])c17_inData)[c17_i27 +
        c17_i25];
    }

    c17_i25 += 3;
  }

  c17_i28 = 0;
  for (c17_i29 = 0; c17_i29 < 3; c17_i29++) {
    for (c17_i30 = 0; c17_i30 < 3; c17_i30++) {
      c17_u[c17_i30 + c17_i28] = c17_b_inData[c17_i30 + c17_i28];
    }

    c17_i28 += 3;
  }

  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", c17_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static void c17_e_emlrt_marshallIn(SFc17_M46DInstanceStruct *chartInstance,
  const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId, real_T c17_y[9])
{
  real_T c17_dv4[9];
  int32_T c17_i31;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), c17_dv4, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c17_i31 = 0; c17_i31 < 9; c17_i31++) {
    c17_y[c17_i31] = c17_dv4[c17_i31];
  }

  sf_mex_destroy(&c17_u);
}

static void c17_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_X;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  real_T c17_y[9];
  int32_T c17_i32;
  int32_T c17_i33;
  int32_T c17_i34;
  SFc17_M46DInstanceStruct *chartInstance;
  chartInstance = (SFc17_M46DInstanceStruct *)chartInstanceVoid;
  c17_X = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_X), &c17_thisId, c17_y);
  sf_mex_destroy(&c17_X);
  c17_i32 = 0;
  for (c17_i33 = 0; c17_i33 < 3; c17_i33++) {
    for (c17_i34 = 0; c17_i34 < 3; c17_i34++) {
      (*(real_T (*)[9])c17_outData)[c17_i34 + c17_i32] = c17_y[c17_i34 + c17_i32];
    }

    c17_i32 += 3;
  }

  sf_mex_destroy(&c17_mxArrayInData);
}

static const mxArray *c17_e_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  int32_T c17_i35;
  real_T c17_b_inData[3];
  int32_T c17_i36;
  real_T c17_u[3];
  const mxArray *c17_y = NULL;
  SFc17_M46DInstanceStruct *chartInstance;
  chartInstance = (SFc17_M46DInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  for (c17_i35 = 0; c17_i35 < 3; c17_i35++) {
    c17_b_inData[c17_i35] = (*(real_T (*)[3])c17_inData)[c17_i35];
  }

  for (c17_i36 = 0; c17_i36 < 3; c17_i36++) {
    c17_u[c17_i36] = c17_b_inData[c17_i36];
  }

  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", c17_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static void c17_f_emlrt_marshallIn(SFc17_M46DInstanceStruct *chartInstance,
  const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId, real_T c17_y[3])
{
  real_T c17_dv5[3];
  int32_T c17_i37;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), c17_dv5, 1, 0, 0U, 1, 0U, 1, 3);
  for (c17_i37 = 0; c17_i37 < 3; c17_i37++) {
    c17_y[c17_i37] = c17_dv5[c17_i37];
  }

  sf_mex_destroy(&c17_u);
}

static void c17_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_x;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  real_T c17_y[3];
  int32_T c17_i38;
  SFc17_M46DInstanceStruct *chartInstance;
  chartInstance = (SFc17_M46DInstanceStruct *)chartInstanceVoid;
  c17_x = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_x), &c17_thisId, c17_y);
  sf_mex_destroy(&c17_x);
  for (c17_i38 = 0; c17_i38 < 3; c17_i38++) {
    (*(real_T (*)[3])c17_outData)[c17_i38] = c17_y[c17_i38];
  }

  sf_mex_destroy(&c17_mxArrayInData);
}

const mxArray *sf_c17_M46D_get_eml_resolved_functions_info(void)
{
  const mxArray *c17_nameCaptureInfo = NULL;
  c17_nameCaptureInfo = NULL;
  sf_mex_assign(&c17_nameCaptureInfo, sf_mex_createstruct("structure", 2, 14, 1),
                false);
  c17_info_helper(&c17_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c17_nameCaptureInfo);
  return c17_nameCaptureInfo;
}

static void c17_info_helper(const mxArray **c17_info)
{
  const mxArray *c17_rhs0 = NULL;
  const mxArray *c17_lhs0 = NULL;
  const mxArray *c17_rhs1 = NULL;
  const mxArray *c17_lhs1 = NULL;
  const mxArray *c17_rhs2 = NULL;
  const mxArray *c17_lhs2 = NULL;
  const mxArray *c17_rhs3 = NULL;
  const mxArray *c17_lhs3 = NULL;
  const mxArray *c17_rhs4 = NULL;
  const mxArray *c17_lhs4 = NULL;
  const mxArray *c17_rhs5 = NULL;
  const mxArray *c17_lhs5 = NULL;
  const mxArray *c17_rhs6 = NULL;
  const mxArray *c17_lhs6 = NULL;
  const mxArray *c17_rhs7 = NULL;
  const mxArray *c17_lhs7 = NULL;
  const mxArray *c17_rhs8 = NULL;
  const mxArray *c17_lhs8 = NULL;
  const mxArray *c17_rhs9 = NULL;
  const mxArray *c17_lhs9 = NULL;
  const mxArray *c17_rhs10 = NULL;
  const mxArray *c17_lhs10 = NULL;
  const mxArray *c17_rhs11 = NULL;
  const mxArray *c17_lhs11 = NULL;
  const mxArray *c17_rhs12 = NULL;
  const mxArray *c17_lhs12 = NULL;
  const mxArray *c17_rhs13 = NULL;
  const mxArray *c17_lhs13 = NULL;
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("skew_sm"), "name", "name", 0);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/MATLAB/Masterarbeit/skew_sm.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1439587919U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c17_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 1);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1383902494U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c17_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 2);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c17_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 3);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 3);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c17_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 4);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 4);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c17_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 5);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c17_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  6);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1376005890U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c17_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 7);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c17_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 8);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c17_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 9);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 9);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c17_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 10);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 10);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c17_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 11);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 11);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c17_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 12);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 12);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c17_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 13);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 13);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c17_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs13), "lhs", "lhs",
                  13);
  sf_mex_destroy(&c17_rhs0);
  sf_mex_destroy(&c17_lhs0);
  sf_mex_destroy(&c17_rhs1);
  sf_mex_destroy(&c17_lhs1);
  sf_mex_destroy(&c17_rhs2);
  sf_mex_destroy(&c17_lhs2);
  sf_mex_destroy(&c17_rhs3);
  sf_mex_destroy(&c17_lhs3);
  sf_mex_destroy(&c17_rhs4);
  sf_mex_destroy(&c17_lhs4);
  sf_mex_destroy(&c17_rhs5);
  sf_mex_destroy(&c17_lhs5);
  sf_mex_destroy(&c17_rhs6);
  sf_mex_destroy(&c17_lhs6);
  sf_mex_destroy(&c17_rhs7);
  sf_mex_destroy(&c17_lhs7);
  sf_mex_destroy(&c17_rhs8);
  sf_mex_destroy(&c17_lhs8);
  sf_mex_destroy(&c17_rhs9);
  sf_mex_destroy(&c17_lhs9);
  sf_mex_destroy(&c17_rhs10);
  sf_mex_destroy(&c17_lhs10);
  sf_mex_destroy(&c17_rhs11);
  sf_mex_destroy(&c17_lhs11);
  sf_mex_destroy(&c17_rhs12);
  sf_mex_destroy(&c17_lhs12);
  sf_mex_destroy(&c17_rhs13);
  sf_mex_destroy(&c17_lhs13);
}

static const mxArray *c17_emlrt_marshallOut(const char * c17_u)
{
  const mxArray *c17_y = NULL;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", c17_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c17_u)), false);
  return c17_y;
}

static const mxArray *c17_b_emlrt_marshallOut(const uint32_T c17_u)
{
  const mxArray *c17_y = NULL;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 7, 0U, 0U, 0U, 0), false);
  return c17_y;
}

static void c17_eml_scalar_eg(SFc17_M46DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c17_eml_xgemm(SFc17_M46DInstanceStruct *chartInstance, real_T c17_A
  [9], real_T c17_B[3], real_T c17_C[3], real_T c17_b_C[3])
{
  int32_T c17_i39;
  int32_T c17_i40;
  real_T c17_b_A[9];
  int32_T c17_i41;
  real_T c17_b_B[3];
  for (c17_i39 = 0; c17_i39 < 3; c17_i39++) {
    c17_b_C[c17_i39] = c17_C[c17_i39];
  }

  for (c17_i40 = 0; c17_i40 < 9; c17_i40++) {
    c17_b_A[c17_i40] = c17_A[c17_i40];
  }

  for (c17_i41 = 0; c17_i41 < 3; c17_i41++) {
    c17_b_B[c17_i41] = c17_B[c17_i41];
  }

  c17_b_eml_xgemm(chartInstance, c17_b_A, c17_b_B, c17_b_C);
}

static const mxArray *c17_f_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  int32_T c17_u;
  const mxArray *c17_y = NULL;
  SFc17_M46DInstanceStruct *chartInstance;
  chartInstance = (SFc17_M46DInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_u = *(int32_T *)c17_inData;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static int32_T c17_g_emlrt_marshallIn(SFc17_M46DInstanceStruct *chartInstance,
  const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId)
{
  int32_T c17_y;
  int32_T c17_i42;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), &c17_i42, 1, 6, 0U, 0, 0U, 0);
  c17_y = c17_i42;
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static void c17_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_b_sfEvent;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  int32_T c17_y;
  SFc17_M46DInstanceStruct *chartInstance;
  chartInstance = (SFc17_M46DInstanceStruct *)chartInstanceVoid;
  c17_b_sfEvent = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_b_sfEvent),
    &c17_thisId);
  sf_mex_destroy(&c17_b_sfEvent);
  *(int32_T *)c17_outData = c17_y;
  sf_mex_destroy(&c17_mxArrayInData);
}

static uint8_T c17_h_emlrt_marshallIn(SFc17_M46DInstanceStruct *chartInstance,
  const mxArray *c17_b_is_active_c17_M46D, const char_T *c17_identifier)
{
  uint8_T c17_y;
  emlrtMsgIdentifier c17_thisId;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c17_b_is_active_c17_M46D), &c17_thisId);
  sf_mex_destroy(&c17_b_is_active_c17_M46D);
  return c17_y;
}

static uint8_T c17_i_emlrt_marshallIn(SFc17_M46DInstanceStruct *chartInstance,
  const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId)
{
  uint8_T c17_y;
  uint8_T c17_u0;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), &c17_u0, 1, 3, 0U, 0, 0U, 0);
  c17_y = c17_u0;
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static void c17_b_eml_xgemm(SFc17_M46DInstanceStruct *chartInstance, real_T
  c17_A[9], real_T c17_B[3], real_T c17_C[3])
{
  int32_T c17_i43;
  int32_T c17_i44;
  int32_T c17_i45;
  (void)chartInstance;
  for (c17_i43 = 0; c17_i43 < 3; c17_i43++) {
    c17_C[c17_i43] = 0.0;
    c17_i44 = 0;
    for (c17_i45 = 0; c17_i45 < 3; c17_i45++) {
      c17_C[c17_i43] += c17_A[c17_i44 + c17_i43] * c17_B[c17_i45];
      c17_i44 += 3;
    }
  }
}

static void init_dsm_address_info(SFc17_M46DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc17_M46DInstanceStruct *chartInstance)
{
  chartInstance->c17_dx = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c17_rot = (real_T (*)[6])ssGetOutputPortSignal_wrapper
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

void sf_c17_M46D_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2810729776U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1762748256U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2958964441U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2308504559U);
}

mxArray* sf_c17_M46D_get_post_codegen_info(void);
mxArray *sf_c17_M46D_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Y6dkn0vu8Kfqi8yRTztzyD");
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
    mxArray* mxPostCodegenInfo = sf_c17_M46D_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c17_M46D_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c17_M46D_jit_fallback_info(void)
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

mxArray *sf_c17_M46D_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c17_M46D_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c17_M46D(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"rot\",},{M[8],M[0],T\"is_active_c17_M46D\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c17_M46D_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc17_M46DInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc17_M46DInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _M46DMachineNumber_,
           17,
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
        init_script_number_translation(_M46DMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_M46DMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _M46DMachineNumber_,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,83);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"skew_sm",0,-1,127);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c17_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c17_sf_marshallOut,(MexInFcnForType)
            c17_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)
            c17_b_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c17_dx);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c17_rot);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c17_r);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _M46DMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "az7l7RdE1rHqSDukqaeCWG";
}

static void sf_opaque_initialize_c17_M46D(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc17_M46DInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c17_M46D((SFc17_M46DInstanceStruct*) chartInstanceVar);
  initialize_c17_M46D((SFc17_M46DInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c17_M46D(void *chartInstanceVar)
{
  enable_c17_M46D((SFc17_M46DInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c17_M46D(void *chartInstanceVar)
{
  disable_c17_M46D((SFc17_M46DInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c17_M46D(void *chartInstanceVar)
{
  sf_gateway_c17_M46D((SFc17_M46DInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c17_M46D(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c17_M46D((SFc17_M46DInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c17_M46D(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c17_M46D((SFc17_M46DInstanceStruct*)chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c17_M46D(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc17_M46DInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_M46D_optimization_info();
    }

    finalize_c17_M46D((SFc17_M46DInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc17_M46D((SFc17_M46DInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c17_M46D(SimStruct *S)
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
    initialize_params_c17_M46D((SFc17_M46DInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c17_M46D(SimStruct *S)
{
  /* Actual parameters from chart:
     r
   */
  const char_T *rtParamNames[] = { "r" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for r*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_M46D_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      17);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,17,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,17,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,17);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,17,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,17,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,17);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4165555108U));
  ssSetChecksum1(S,(713938716U));
  ssSetChecksum2(S,(4070833821U));
  ssSetChecksum3(S,(1432471429U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c17_M46D(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c17_M46D(SimStruct *S)
{
  SFc17_M46DInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc17_M46DInstanceStruct *)utMalloc(sizeof
    (SFc17_M46DInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc17_M46DInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c17_M46D;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c17_M46D;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c17_M46D;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c17_M46D;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c17_M46D;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c17_M46D;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c17_M46D;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c17_M46D;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c17_M46D;
  chartInstance->chartInfo.mdlStart = mdlStart_c17_M46D;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c17_M46D;
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

void c17_M46D_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c17_M46D(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c17_M46D(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c17_M46D(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c17_M46D_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

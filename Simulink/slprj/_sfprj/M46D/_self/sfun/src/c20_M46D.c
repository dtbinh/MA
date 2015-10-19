/* Include files */

#include <stddef.h>
#include "blas.h"
#include "M46D_sfun.h"
#include "c20_M46D.h"
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
static const char * c20_debug_family_names[5] = { "nargin", "nargout", "dx", "r",
  "rot" };

static const char * c20_b_debug_family_names[4] = { "nargin", "nargout", "x",
  "X" };

/* Function Declarations */
static void initialize_c20_M46D(SFc20_M46DInstanceStruct *chartInstance);
static void initialize_params_c20_M46D(SFc20_M46DInstanceStruct *chartInstance);
static void enable_c20_M46D(SFc20_M46DInstanceStruct *chartInstance);
static void disable_c20_M46D(SFc20_M46DInstanceStruct *chartInstance);
static void c20_update_debugger_state_c20_M46D(SFc20_M46DInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c20_M46D(SFc20_M46DInstanceStruct
  *chartInstance);
static void set_sim_state_c20_M46D(SFc20_M46DInstanceStruct *chartInstance,
  const mxArray *c20_st);
static void finalize_c20_M46D(SFc20_M46DInstanceStruct *chartInstance);
static void sf_gateway_c20_M46D(SFc20_M46DInstanceStruct *chartInstance);
static void mdl_start_c20_M46D(SFc20_M46DInstanceStruct *chartInstance);
static void initSimStructsc20_M46D(SFc20_M46DInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber, uint32_T c20_instanceNumber);
static const mxArray *c20_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static void c20_emlrt_marshallIn(SFc20_M46DInstanceStruct *chartInstance, const
  mxArray *c20_b_rot, const char_T *c20_identifier, real_T c20_y[6]);
static void c20_b_emlrt_marshallIn(SFc20_M46DInstanceStruct *chartInstance,
  const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId, real_T c20_y[6]);
static void c20_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_b_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static void c20_c_emlrt_marshallIn(SFc20_M46DInstanceStruct *chartInstance,
  const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId, real_T c20_y[12]);
static void c20_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_c_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static real_T c20_d_emlrt_marshallIn(SFc20_M46DInstanceStruct *chartInstance,
  const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_d_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static void c20_e_emlrt_marshallIn(SFc20_M46DInstanceStruct *chartInstance,
  const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId, real_T c20_y[9]);
static void c20_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_e_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static void c20_f_emlrt_marshallIn(SFc20_M46DInstanceStruct *chartInstance,
  const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId, real_T c20_y[3]);
static void c20_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static void c20_info_helper(const mxArray **c20_info);
static const mxArray *c20_emlrt_marshallOut(const char * c20_u);
static const mxArray *c20_b_emlrt_marshallOut(const uint32_T c20_u);
static void c20_eml_scalar_eg(SFc20_M46DInstanceStruct *chartInstance);
static void c20_eml_xgemm(SFc20_M46DInstanceStruct *chartInstance, real_T c20_A
  [9], real_T c20_B[3], real_T c20_C[3], real_T c20_b_C[3]);
static const mxArray *c20_f_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static int32_T c20_g_emlrt_marshallIn(SFc20_M46DInstanceStruct *chartInstance,
  const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static uint8_T c20_h_emlrt_marshallIn(SFc20_M46DInstanceStruct *chartInstance,
  const mxArray *c20_b_is_active_c20_M46D, const char_T *c20_identifier);
static uint8_T c20_i_emlrt_marshallIn(SFc20_M46DInstanceStruct *chartInstance,
  const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_b_eml_xgemm(SFc20_M46DInstanceStruct *chartInstance, real_T
  c20_A[9], real_T c20_B[3], real_T c20_C[3]);
static void init_dsm_address_info(SFc20_M46DInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc20_M46DInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c20_M46D(SFc20_M46DInstanceStruct *chartInstance)
{
  chartInstance->c20_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c20_is_active_c20_M46D = 0U;
}

static void initialize_params_c20_M46D(SFc20_M46DInstanceStruct *chartInstance)
{
  real_T c20_dv0[12];
  int32_T c20_i0;
  sf_mex_import_named("r", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      c20_dv0, 0, 0, 0U, 1, 0U, 1, 12);
  for (c20_i0 = 0; c20_i0 < 12; c20_i0++) {
    chartInstance->c20_r[c20_i0] = c20_dv0[c20_i0];
  }
}

static void enable_c20_M46D(SFc20_M46DInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c20_M46D(SFc20_M46DInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c20_update_debugger_state_c20_M46D(SFc20_M46DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c20_M46D(SFc20_M46DInstanceStruct
  *chartInstance)
{
  const mxArray *c20_st;
  const mxArray *c20_y = NULL;
  int32_T c20_i1;
  real_T c20_u[6];
  const mxArray *c20_b_y = NULL;
  uint8_T c20_hoistedGlobal;
  uint8_T c20_b_u;
  const mxArray *c20_c_y = NULL;
  c20_st = NULL;
  c20_st = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_createcellmatrix(2, 1), false);
  for (c20_i1 = 0; c20_i1 < 6; c20_i1++) {
    c20_u[c20_i1] = (*chartInstance->c20_rot)[c20_i1];
  }

  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_setcell(c20_y, 0, c20_b_y);
  c20_hoistedGlobal = chartInstance->c20_is_active_c20_M46D;
  c20_b_u = c20_hoistedGlobal;
  c20_c_y = NULL;
  sf_mex_assign(&c20_c_y, sf_mex_create("y", &c20_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 1, c20_c_y);
  sf_mex_assign(&c20_st, c20_y, false);
  return c20_st;
}

static void set_sim_state_c20_M46D(SFc20_M46DInstanceStruct *chartInstance,
  const mxArray *c20_st)
{
  const mxArray *c20_u;
  real_T c20_dv1[6];
  int32_T c20_i2;
  chartInstance->c20_doneDoubleBufferReInit = true;
  c20_u = sf_mex_dup(c20_st);
  c20_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 0)),
                       "rot", c20_dv1);
  for (c20_i2 = 0; c20_i2 < 6; c20_i2++) {
    (*chartInstance->c20_rot)[c20_i2] = c20_dv1[c20_i2];
  }

  chartInstance->c20_is_active_c20_M46D = c20_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c20_u, 1)), "is_active_c20_M46D");
  sf_mex_destroy(&c20_u);
  c20_update_debugger_state_c20_M46D(chartInstance);
  sf_mex_destroy(&c20_st);
}

static void finalize_c20_M46D(SFc20_M46DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c20_M46D(SFc20_M46DInstanceStruct *chartInstance)
{
  int32_T c20_i3;
  int32_T c20_i4;
  real_T c20_b_dx[6];
  int32_T c20_i5;
  real_T c20_b_r[12];
  uint32_T c20_debug_family_var_map[5];
  real_T c20_nargin = 2.0;
  real_T c20_nargout = 1.0;
  real_T c20_b_rot[6];
  int32_T c20_i6;
  real_T c20_x[3];
  uint32_T c20_b_debug_family_var_map[4];
  real_T c20_b_nargin = 1.0;
  real_T c20_b_nargout = 1.0;
  real_T c20_X[9];
  int32_T c20_i7;
  real_T c20_a[9];
  int32_T c20_i8;
  real_T c20_b[3];
  int32_T c20_i9;
  real_T c20_y[3];
  int32_T c20_i10;
  real_T c20_b_a[9];
  int32_T c20_i11;
  real_T c20_b_b[3];
  int32_T c20_i12;
  int32_T c20_i13;
  int32_T c20_i14;
  int32_T c20_i15;
  int32_T c20_i16;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 18U, chartInstance->c20_sfEvent);
  for (c20_i3 = 0; c20_i3 < 6; c20_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c20_dx)[c20_i3], 0U);
  }

  chartInstance->c20_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 18U, chartInstance->c20_sfEvent);
  for (c20_i4 = 0; c20_i4 < 6; c20_i4++) {
    c20_b_dx[c20_i4] = (*chartInstance->c20_dx)[c20_i4];
  }

  for (c20_i5 = 0; c20_i5 < 12; c20_i5++) {
    c20_b_r[c20_i5] = chartInstance->c20_r[c20_i5];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c20_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 0U, c20_c_sf_marshallOut,
    c20_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 1U, c20_c_sf_marshallOut,
    c20_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_b_dx, 2U, c20_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_b_r, 3U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_b_rot, 4U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 2);
  for (c20_i6 = 0; c20_i6 < 3; c20_i6++) {
    c20_x[c20_i6] = c20_b_dx[c20_i6 + 3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c20_b_debug_family_names,
    c20_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargin, 0U, c20_c_sf_marshallOut,
    c20_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargout, 1U, c20_c_sf_marshallOut,
    c20_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_x, 2U, c20_e_sf_marshallOut,
    c20_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_X, 3U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 3);
  c20_X[0] = 0.0;
  c20_X[3] = -c20_x[2];
  c20_X[6] = c20_x[1];
  c20_X[1] = c20_x[2];
  c20_X[4] = 0.0;
  c20_X[7] = -c20_x[0];
  c20_X[2] = -c20_x[1];
  c20_X[5] = c20_x[0];
  c20_X[8] = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c20_i7 = 0; c20_i7 < 9; c20_i7++) {
    c20_a[c20_i7] = c20_X[c20_i7];
  }

  for (c20_i8 = 0; c20_i8 < 3; c20_i8++) {
    c20_b[c20_i8] = c20_b_r[c20_i8 + 9];
  }

  c20_eml_scalar_eg(chartInstance);
  c20_eml_scalar_eg(chartInstance);
  for (c20_i9 = 0; c20_i9 < 3; c20_i9++) {
    c20_y[c20_i9] = 0.0;
  }

  for (c20_i10 = 0; c20_i10 < 9; c20_i10++) {
    c20_b_a[c20_i10] = c20_a[c20_i10];
  }

  for (c20_i11 = 0; c20_i11 < 3; c20_i11++) {
    c20_b_b[c20_i11] = c20_b[c20_i11];
  }

  c20_b_eml_xgemm(chartInstance, c20_b_a, c20_b_b, c20_y);
  for (c20_i12 = 0; c20_i12 < 3; c20_i12++) {
    c20_b_rot[c20_i12] = c20_y[c20_i12];
  }

  for (c20_i13 = 0; c20_i13 < 3; c20_i13++) {
    c20_b_rot[c20_i13 + 3] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, -2);
  _SFD_SYMBOL_SCOPE_POP();
  for (c20_i14 = 0; c20_i14 < 6; c20_i14++) {
    (*chartInstance->c20_rot)[c20_i14] = c20_b_rot[c20_i14];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c20_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_M46DMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c20_i15 = 0; c20_i15 < 6; c20_i15++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c20_rot)[c20_i15], 1U);
  }

  for (c20_i16 = 0; c20_i16 < 12; c20_i16++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c20_r[c20_i16], 2U);
  }
}

static void mdl_start_c20_M46D(SFc20_M46DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc20_M46D(SFc20_M46DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber, uint32_T c20_instanceNumber)
{
  (void)c20_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c20_chartNumber, c20_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Martin\\Documents\\MATLAB\\Masterarbeit\\skew_sm.m"));
}

static const mxArray *c20_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i17;
  real_T c20_b_inData[6];
  int32_T c20_i18;
  real_T c20_u[6];
  const mxArray *c20_y = NULL;
  SFc20_M46DInstanceStruct *chartInstance;
  chartInstance = (SFc20_M46DInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i17 = 0; c20_i17 < 6; c20_i17++) {
    c20_b_inData[c20_i17] = (*(real_T (*)[6])c20_inData)[c20_i17];
  }

  for (c20_i18 = 0; c20_i18 < 6; c20_i18++) {
    c20_u[c20_i18] = c20_b_inData[c20_i18];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static void c20_emlrt_marshallIn(SFc20_M46DInstanceStruct *chartInstance, const
  mxArray *c20_b_rot, const char_T *c20_identifier, real_T c20_y[6])
{
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_rot), &c20_thisId,
    c20_y);
  sf_mex_destroy(&c20_b_rot);
}

static void c20_b_emlrt_marshallIn(SFc20_M46DInstanceStruct *chartInstance,
  const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId, real_T c20_y[6])
{
  real_T c20_dv2[6];
  int32_T c20_i19;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), c20_dv2, 1, 0, 0U, 1, 0U, 1, 6);
  for (c20_i19 = 0; c20_i19 < 6; c20_i19++) {
    c20_y[c20_i19] = c20_dv2[c20_i19];
  }

  sf_mex_destroy(&c20_u);
}

static void c20_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_b_rot;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y[6];
  int32_T c20_i20;
  SFc20_M46DInstanceStruct *chartInstance;
  chartInstance = (SFc20_M46DInstanceStruct *)chartInstanceVoid;
  c20_b_rot = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_rot), &c20_thisId,
    c20_y);
  sf_mex_destroy(&c20_b_rot);
  for (c20_i20 = 0; c20_i20 < 6; c20_i20++) {
    (*(real_T (*)[6])c20_outData)[c20_i20] = c20_y[c20_i20];
  }

  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_b_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i21;
  real_T c20_b_inData[12];
  int32_T c20_i22;
  real_T c20_u[12];
  const mxArray *c20_y = NULL;
  SFc20_M46DInstanceStruct *chartInstance;
  chartInstance = (SFc20_M46DInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i21 = 0; c20_i21 < 12; c20_i21++) {
    c20_b_inData[c20_i21] = (*(real_T (*)[12])c20_inData)[c20_i21];
  }

  for (c20_i22 = 0; c20_i22 < 12; c20_i22++) {
    c20_u[c20_i22] = c20_b_inData[c20_i22];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 1, 12), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static void c20_c_emlrt_marshallIn(SFc20_M46DInstanceStruct *chartInstance,
  const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId, real_T c20_y[12])
{
  real_T c20_dv3[12];
  int32_T c20_i23;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), c20_dv3, 1, 0, 0U, 1, 0U, 1, 12);
  for (c20_i23 = 0; c20_i23 < 12; c20_i23++) {
    c20_y[c20_i23] = c20_dv3[c20_i23];
  }

  sf_mex_destroy(&c20_u);
}

static void c20_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_b_r;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y[12];
  int32_T c20_i24;
  SFc20_M46DInstanceStruct *chartInstance;
  chartInstance = (SFc20_M46DInstanceStruct *)chartInstanceVoid;
  c20_b_r = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_r), &c20_thisId, c20_y);
  sf_mex_destroy(&c20_b_r);
  for (c20_i24 = 0; c20_i24 < 12; c20_i24++) {
    (*(real_T (*)[12])c20_outData)[c20_i24] = c20_y[c20_i24];
  }

  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_c_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  real_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_M46DInstanceStruct *chartInstance;
  chartInstance = (SFc20_M46DInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(real_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static real_T c20_d_emlrt_marshallIn(SFc20_M46DInstanceStruct *chartInstance,
  const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  real_T c20_y;
  real_T c20_d0;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_d0, 1, 0, 0U, 0, 0U, 0);
  c20_y = c20_d0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_nargout;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y;
  SFc20_M46DInstanceStruct *chartInstance;
  chartInstance = (SFc20_M46DInstanceStruct *)chartInstanceVoid;
  c20_nargout = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_nargout),
    &c20_thisId);
  sf_mex_destroy(&c20_nargout);
  *(real_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_d_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i25;
  int32_T c20_i26;
  int32_T c20_i27;
  real_T c20_b_inData[9];
  int32_T c20_i28;
  int32_T c20_i29;
  int32_T c20_i30;
  real_T c20_u[9];
  const mxArray *c20_y = NULL;
  SFc20_M46DInstanceStruct *chartInstance;
  chartInstance = (SFc20_M46DInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_i25 = 0;
  for (c20_i26 = 0; c20_i26 < 3; c20_i26++) {
    for (c20_i27 = 0; c20_i27 < 3; c20_i27++) {
      c20_b_inData[c20_i27 + c20_i25] = (*(real_T (*)[9])c20_inData)[c20_i27 +
        c20_i25];
    }

    c20_i25 += 3;
  }

  c20_i28 = 0;
  for (c20_i29 = 0; c20_i29 < 3; c20_i29++) {
    for (c20_i30 = 0; c20_i30 < 3; c20_i30++) {
      c20_u[c20_i30 + c20_i28] = c20_b_inData[c20_i30 + c20_i28];
    }

    c20_i28 += 3;
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static void c20_e_emlrt_marshallIn(SFc20_M46DInstanceStruct *chartInstance,
  const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId, real_T c20_y[9])
{
  real_T c20_dv4[9];
  int32_T c20_i31;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), c20_dv4, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c20_i31 = 0; c20_i31 < 9; c20_i31++) {
    c20_y[c20_i31] = c20_dv4[c20_i31];
  }

  sf_mex_destroy(&c20_u);
}

static void c20_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_X;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y[9];
  int32_T c20_i32;
  int32_T c20_i33;
  int32_T c20_i34;
  SFc20_M46DInstanceStruct *chartInstance;
  chartInstance = (SFc20_M46DInstanceStruct *)chartInstanceVoid;
  c20_X = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_X), &c20_thisId, c20_y);
  sf_mex_destroy(&c20_X);
  c20_i32 = 0;
  for (c20_i33 = 0; c20_i33 < 3; c20_i33++) {
    for (c20_i34 = 0; c20_i34 < 3; c20_i34++) {
      (*(real_T (*)[9])c20_outData)[c20_i34 + c20_i32] = c20_y[c20_i34 + c20_i32];
    }

    c20_i32 += 3;
  }

  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_e_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i35;
  real_T c20_b_inData[3];
  int32_T c20_i36;
  real_T c20_u[3];
  const mxArray *c20_y = NULL;
  SFc20_M46DInstanceStruct *chartInstance;
  chartInstance = (SFc20_M46DInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i35 = 0; c20_i35 < 3; c20_i35++) {
    c20_b_inData[c20_i35] = (*(real_T (*)[3])c20_inData)[c20_i35];
  }

  for (c20_i36 = 0; c20_i36 < 3; c20_i36++) {
    c20_u[c20_i36] = c20_b_inData[c20_i36];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static void c20_f_emlrt_marshallIn(SFc20_M46DInstanceStruct *chartInstance,
  const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId, real_T c20_y[3])
{
  real_T c20_dv5[3];
  int32_T c20_i37;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), c20_dv5, 1, 0, 0U, 1, 0U, 1, 3);
  for (c20_i37 = 0; c20_i37 < 3; c20_i37++) {
    c20_y[c20_i37] = c20_dv5[c20_i37];
  }

  sf_mex_destroy(&c20_u);
}

static void c20_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_x;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y[3];
  int32_T c20_i38;
  SFc20_M46DInstanceStruct *chartInstance;
  chartInstance = (SFc20_M46DInstanceStruct *)chartInstanceVoid;
  c20_x = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_x), &c20_thisId, c20_y);
  sf_mex_destroy(&c20_x);
  for (c20_i38 = 0; c20_i38 < 3; c20_i38++) {
    (*(real_T (*)[3])c20_outData)[c20_i38] = c20_y[c20_i38];
  }

  sf_mex_destroy(&c20_mxArrayInData);
}

const mxArray *sf_c20_M46D_get_eml_resolved_functions_info(void)
{
  const mxArray *c20_nameCaptureInfo = NULL;
  c20_nameCaptureInfo = NULL;
  sf_mex_assign(&c20_nameCaptureInfo, sf_mex_createstruct("structure", 2, 14, 1),
                false);
  c20_info_helper(&c20_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c20_nameCaptureInfo);
  return c20_nameCaptureInfo;
}

static void c20_info_helper(const mxArray **c20_info)
{
  const mxArray *c20_rhs0 = NULL;
  const mxArray *c20_lhs0 = NULL;
  const mxArray *c20_rhs1 = NULL;
  const mxArray *c20_lhs1 = NULL;
  const mxArray *c20_rhs2 = NULL;
  const mxArray *c20_lhs2 = NULL;
  const mxArray *c20_rhs3 = NULL;
  const mxArray *c20_lhs3 = NULL;
  const mxArray *c20_rhs4 = NULL;
  const mxArray *c20_lhs4 = NULL;
  const mxArray *c20_rhs5 = NULL;
  const mxArray *c20_lhs5 = NULL;
  const mxArray *c20_rhs6 = NULL;
  const mxArray *c20_lhs6 = NULL;
  const mxArray *c20_rhs7 = NULL;
  const mxArray *c20_lhs7 = NULL;
  const mxArray *c20_rhs8 = NULL;
  const mxArray *c20_lhs8 = NULL;
  const mxArray *c20_rhs9 = NULL;
  const mxArray *c20_lhs9 = NULL;
  const mxArray *c20_rhs10 = NULL;
  const mxArray *c20_lhs10 = NULL;
  const mxArray *c20_rhs11 = NULL;
  const mxArray *c20_lhs11 = NULL;
  const mxArray *c20_rhs12 = NULL;
  const mxArray *c20_lhs12 = NULL;
  const mxArray *c20_rhs13 = NULL;
  const mxArray *c20_lhs13 = NULL;
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("skew_sm"), "name", "name", 0);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/MATLAB/Masterarbeit/skew_sm.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1439587919U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c20_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 1);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1383902494U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c20_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 2);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c20_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 3);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 3);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c20_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 4);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 4);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c20_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 5);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c20_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  6);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1376005890U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c20_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 7);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c20_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 8);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c20_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 9);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 9);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c20_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 10);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 10);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c20_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 11);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 11);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c20_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 12);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 12);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c20_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 13);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 13);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c20_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs13), "lhs", "lhs",
                  13);
  sf_mex_destroy(&c20_rhs0);
  sf_mex_destroy(&c20_lhs0);
  sf_mex_destroy(&c20_rhs1);
  sf_mex_destroy(&c20_lhs1);
  sf_mex_destroy(&c20_rhs2);
  sf_mex_destroy(&c20_lhs2);
  sf_mex_destroy(&c20_rhs3);
  sf_mex_destroy(&c20_lhs3);
  sf_mex_destroy(&c20_rhs4);
  sf_mex_destroy(&c20_lhs4);
  sf_mex_destroy(&c20_rhs5);
  sf_mex_destroy(&c20_lhs5);
  sf_mex_destroy(&c20_rhs6);
  sf_mex_destroy(&c20_lhs6);
  sf_mex_destroy(&c20_rhs7);
  sf_mex_destroy(&c20_lhs7);
  sf_mex_destroy(&c20_rhs8);
  sf_mex_destroy(&c20_lhs8);
  sf_mex_destroy(&c20_rhs9);
  sf_mex_destroy(&c20_lhs9);
  sf_mex_destroy(&c20_rhs10);
  sf_mex_destroy(&c20_lhs10);
  sf_mex_destroy(&c20_rhs11);
  sf_mex_destroy(&c20_lhs11);
  sf_mex_destroy(&c20_rhs12);
  sf_mex_destroy(&c20_lhs12);
  sf_mex_destroy(&c20_rhs13);
  sf_mex_destroy(&c20_lhs13);
}

static const mxArray *c20_emlrt_marshallOut(const char * c20_u)
{
  const mxArray *c20_y = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c20_u)), false);
  return c20_y;
}

static const mxArray *c20_b_emlrt_marshallOut(const uint32_T c20_u)
{
  const mxArray *c20_y = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 7, 0U, 0U, 0U, 0), false);
  return c20_y;
}

static void c20_eml_scalar_eg(SFc20_M46DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c20_eml_xgemm(SFc20_M46DInstanceStruct *chartInstance, real_T c20_A
  [9], real_T c20_B[3], real_T c20_C[3], real_T c20_b_C[3])
{
  int32_T c20_i39;
  int32_T c20_i40;
  real_T c20_b_A[9];
  int32_T c20_i41;
  real_T c20_b_B[3];
  for (c20_i39 = 0; c20_i39 < 3; c20_i39++) {
    c20_b_C[c20_i39] = c20_C[c20_i39];
  }

  for (c20_i40 = 0; c20_i40 < 9; c20_i40++) {
    c20_b_A[c20_i40] = c20_A[c20_i40];
  }

  for (c20_i41 = 0; c20_i41 < 3; c20_i41++) {
    c20_b_B[c20_i41] = c20_B[c20_i41];
  }

  c20_b_eml_xgemm(chartInstance, c20_b_A, c20_b_B, c20_b_C);
}

static const mxArray *c20_f_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_M46DInstanceStruct *chartInstance;
  chartInstance = (SFc20_M46DInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(int32_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static int32_T c20_g_emlrt_marshallIn(SFc20_M46DInstanceStruct *chartInstance,
  const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  int32_T c20_y;
  int32_T c20_i42;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_i42, 1, 6, 0U, 0, 0U, 0);
  c20_y = c20_i42;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_b_sfEvent;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  int32_T c20_y;
  SFc20_M46DInstanceStruct *chartInstance;
  chartInstance = (SFc20_M46DInstanceStruct *)chartInstanceVoid;
  c20_b_sfEvent = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_sfEvent),
    &c20_thisId);
  sf_mex_destroy(&c20_b_sfEvent);
  *(int32_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static uint8_T c20_h_emlrt_marshallIn(SFc20_M46DInstanceStruct *chartInstance,
  const mxArray *c20_b_is_active_c20_M46D, const char_T *c20_identifier)
{
  uint8_T c20_y;
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c20_b_is_active_c20_M46D), &c20_thisId);
  sf_mex_destroy(&c20_b_is_active_c20_M46D);
  return c20_y;
}

static uint8_T c20_i_emlrt_marshallIn(SFc20_M46DInstanceStruct *chartInstance,
  const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  uint8_T c20_y;
  uint8_T c20_u0;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_u0, 1, 3, 0U, 0, 0U, 0);
  c20_y = c20_u0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_b_eml_xgemm(SFc20_M46DInstanceStruct *chartInstance, real_T
  c20_A[9], real_T c20_B[3], real_T c20_C[3])
{
  int32_T c20_i43;
  int32_T c20_i44;
  int32_T c20_i45;
  (void)chartInstance;
  for (c20_i43 = 0; c20_i43 < 3; c20_i43++) {
    c20_C[c20_i43] = 0.0;
    c20_i44 = 0;
    for (c20_i45 = 0; c20_i45 < 3; c20_i45++) {
      c20_C[c20_i43] += c20_A[c20_i44 + c20_i43] * c20_B[c20_i45];
      c20_i44 += 3;
    }
  }
}

static void init_dsm_address_info(SFc20_M46DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc20_M46DInstanceStruct *chartInstance)
{
  chartInstance->c20_dx = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c20_rot = (real_T (*)[6])ssGetOutputPortSignal_wrapper
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

void sf_c20_M46D_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1904116602U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(332740314U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(973130013U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4163565743U);
}

mxArray* sf_c20_M46D_get_post_codegen_info(void);
mxArray *sf_c20_M46D_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Wmbfw5SMBcEw16dh6FQ3SE");
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
    mxArray* mxPostCodegenInfo = sf_c20_M46D_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c20_M46D_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c20_M46D_jit_fallback_info(void)
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

mxArray *sf_c20_M46D_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c20_M46D_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c20_M46D(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"rot\",},{M[8],M[0],T\"is_active_c20_M46D\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c20_M46D_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc20_M46DInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc20_M46DInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _M46DMachineNumber_,
           20,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,85);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"skew_sm",0,-1,127);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)
            c20_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
            c20_b_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c20_dx);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c20_rot);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c20_r);
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
  return "VkKwN8kCVkRlou36wCBdx";
}

static void sf_opaque_initialize_c20_M46D(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc20_M46DInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c20_M46D((SFc20_M46DInstanceStruct*) chartInstanceVar);
  initialize_c20_M46D((SFc20_M46DInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c20_M46D(void *chartInstanceVar)
{
  enable_c20_M46D((SFc20_M46DInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c20_M46D(void *chartInstanceVar)
{
  disable_c20_M46D((SFc20_M46DInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c20_M46D(void *chartInstanceVar)
{
  sf_gateway_c20_M46D((SFc20_M46DInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c20_M46D(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c20_M46D((SFc20_M46DInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c20_M46D(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c20_M46D((SFc20_M46DInstanceStruct*)chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c20_M46D(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc20_M46DInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_M46D_optimization_info();
    }

    finalize_c20_M46D((SFc20_M46DInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc20_M46D((SFc20_M46DInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c20_M46D(SimStruct *S)
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
    initialize_params_c20_M46D((SFc20_M46DInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c20_M46D(SimStruct *S)
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
      20);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,20,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,20,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,20);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,20,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,20,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,20);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(831123748U));
  ssSetChecksum1(S,(3613365815U));
  ssSetChecksum2(S,(2768279835U));
  ssSetChecksum3(S,(535436721U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c20_M46D(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c20_M46D(SimStruct *S)
{
  SFc20_M46DInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc20_M46DInstanceStruct *)utMalloc(sizeof
    (SFc20_M46DInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc20_M46DInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c20_M46D;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c20_M46D;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c20_M46D;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c20_M46D;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c20_M46D;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c20_M46D;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c20_M46D;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c20_M46D;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c20_M46D;
  chartInstance->chartInfo.mdlStart = mdlStart_c20_M46D;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c20_M46D;
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

void c20_M46D_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c20_M46D(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c20_M46D(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c20_M46D(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c20_M46D_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

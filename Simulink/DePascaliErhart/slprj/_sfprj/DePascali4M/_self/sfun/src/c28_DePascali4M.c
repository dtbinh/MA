/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DePascali4M_sfun.h"
#include "c28_DePascali4M.h"
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
static const char * c28_debug_family_names[6] = { "nargin", "nargout", "eta3",
  "k3", "kappa3", "K" };

/* Function Declarations */
static void initialize_c28_DePascali4M(SFc28_DePascali4MInstanceStruct
  *chartInstance);
static void initialize_params_c28_DePascali4M(SFc28_DePascali4MInstanceStruct
  *chartInstance);
static void enable_c28_DePascali4M(SFc28_DePascali4MInstanceStruct
  *chartInstance);
static void disable_c28_DePascali4M(SFc28_DePascali4MInstanceStruct
  *chartInstance);
static void c28_update_debugger_state_c28_DePascali4M
  (SFc28_DePascali4MInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c28_DePascali4M
  (SFc28_DePascali4MInstanceStruct *chartInstance);
static void set_sim_state_c28_DePascali4M(SFc28_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c28_st);
static void finalize_c28_DePascali4M(SFc28_DePascali4MInstanceStruct
  *chartInstance);
static void sf_gateway_c28_DePascali4M(SFc28_DePascali4MInstanceStruct
  *chartInstance);
static void mdl_start_c28_DePascali4M(SFc28_DePascali4MInstanceStruct
  *chartInstance);
static void initSimStructsc28_DePascali4M(SFc28_DePascali4MInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c28_machineNumber, uint32_T
  c28_chartNumber, uint32_T c28_instanceNumber);
static const mxArray *c28_sf_marshallOut(void *chartInstanceVoid, void
  *c28_inData);
static void c28_emlrt_marshallIn(SFc28_DePascali4MInstanceStruct *chartInstance,
  const mxArray *c28_b_K, const char_T *c28_identifier, real_T c28_y[36]);
static void c28_b_emlrt_marshallIn(SFc28_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId,
  real_T c28_y[36]);
static void c28_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData);
static const mxArray *c28_b_sf_marshallOut(void *chartInstanceVoid, void
  *c28_inData);
static real_T c28_c_emlrt_marshallIn(SFc28_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId);
static void c28_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData);
static void c28_info_helper(const mxArray **c28_info);
static const mxArray *c28_emlrt_marshallOut(const char * c28_u);
static const mxArray *c28_b_emlrt_marshallOut(const uint32_T c28_u);
static const mxArray *c28_c_sf_marshallOut(void *chartInstanceVoid, void
  *c28_inData);
static int32_T c28_d_emlrt_marshallIn(SFc28_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId);
static void c28_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData);
static uint8_T c28_e_emlrt_marshallIn(SFc28_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c28_b_is_active_c28_DePascali4M, const char_T
  *c28_identifier);
static uint8_T c28_f_emlrt_marshallIn(SFc28_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId);
static void init_dsm_address_info(SFc28_DePascali4MInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc28_DePascali4MInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c28_DePascali4M(SFc28_DePascali4MInstanceStruct
  *chartInstance)
{
  chartInstance->c28_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c28_is_active_c28_DePascali4M = 0U;
}

static void initialize_params_c28_DePascali4M(SFc28_DePascali4MInstanceStruct
  *chartInstance)
{
  real_T c28_d0;
  real_T c28_d1;
  sf_mex_import_named("k3", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c28_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c28_k3 = c28_d0;
  sf_mex_import_named("kappa3", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c28_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c28_kappa3 = c28_d1;
}

static void enable_c28_DePascali4M(SFc28_DePascali4MInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c28_DePascali4M(SFc28_DePascali4MInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c28_update_debugger_state_c28_DePascali4M
  (SFc28_DePascali4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c28_DePascali4M
  (SFc28_DePascali4MInstanceStruct *chartInstance)
{
  const mxArray *c28_st;
  const mxArray *c28_y = NULL;
  int32_T c28_i0;
  real_T c28_u[36];
  const mxArray *c28_b_y = NULL;
  uint8_T c28_hoistedGlobal;
  uint8_T c28_b_u;
  const mxArray *c28_c_y = NULL;
  c28_st = NULL;
  c28_st = NULL;
  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_createcellmatrix(2, 1), false);
  for (c28_i0 = 0; c28_i0 < 36; c28_i0++) {
    c28_u[c28_i0] = (*chartInstance->c28_K)[c28_i0];
  }

  c28_b_y = NULL;
  sf_mex_assign(&c28_b_y, sf_mex_create("y", c28_u, 0, 0U, 1U, 0U, 2, 6, 6),
                false);
  sf_mex_setcell(c28_y, 0, c28_b_y);
  c28_hoistedGlobal = chartInstance->c28_is_active_c28_DePascali4M;
  c28_b_u = c28_hoistedGlobal;
  c28_c_y = NULL;
  sf_mex_assign(&c28_c_y, sf_mex_create("y", &c28_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c28_y, 1, c28_c_y);
  sf_mex_assign(&c28_st, c28_y, false);
  return c28_st;
}

static void set_sim_state_c28_DePascali4M(SFc28_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c28_st)
{
  const mxArray *c28_u;
  real_T c28_dv0[36];
  int32_T c28_i1;
  chartInstance->c28_doneDoubleBufferReInit = true;
  c28_u = sf_mex_dup(c28_st);
  c28_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c28_u, 0)), "K",
                       c28_dv0);
  for (c28_i1 = 0; c28_i1 < 36; c28_i1++) {
    (*chartInstance->c28_K)[c28_i1] = c28_dv0[c28_i1];
  }

  chartInstance->c28_is_active_c28_DePascali4M = c28_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c28_u, 1)),
     "is_active_c28_DePascali4M");
  sf_mex_destroy(&c28_u);
  c28_update_debugger_state_c28_DePascali4M(chartInstance);
  sf_mex_destroy(&c28_st);
}

static void finalize_c28_DePascali4M(SFc28_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c28_DePascali4M(SFc28_DePascali4MInstanceStruct
  *chartInstance)
{
  real_T c28_hoistedGlobal;
  real_T c28_b_hoistedGlobal;
  real_T c28_c_hoistedGlobal;
  real_T c28_b_eta3;
  real_T c28_b_k3;
  real_T c28_b_kappa3;
  uint32_T c28_debug_family_var_map[6];
  real_T c28_nargin = 3.0;
  real_T c28_nargout = 1.0;
  real_T c28_b_K[36];
  real_T c28_a;
  int32_T c28_i2;
  static real_T c28_b[9] = { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 };

  real_T c28_y[9];
  real_T c28_b_a;
  int32_T c28_i3;
  real_T c28_b_y[9];
  int32_T c28_i4;
  int32_T c28_i5;
  int32_T c28_i6;
  int32_T c28_i7;
  int32_T c28_i8;
  int32_T c28_i9;
  int32_T c28_i10;
  int32_T c28_i11;
  int32_T c28_i12;
  int32_T c28_i13;
  int32_T c28_i14;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 8U, chartInstance->c28_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c28_eta3, 0U);
  chartInstance->c28_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c28_sfEvent);
  c28_hoistedGlobal = *chartInstance->c28_eta3;
  c28_b_hoistedGlobal = chartInstance->c28_k3;
  c28_c_hoistedGlobal = chartInstance->c28_kappa3;
  c28_b_eta3 = c28_hoistedGlobal;
  c28_b_k3 = c28_b_hoistedGlobal;
  c28_b_kappa3 = c28_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c28_debug_family_names,
    c28_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_nargin, 0U, c28_b_sf_marshallOut,
    c28_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_nargout, 1U, c28_b_sf_marshallOut,
    c28_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c28_b_eta3, 2U, c28_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_b_k3, 3U, c28_b_sf_marshallOut,
    c28_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_b_kappa3, 4U, c28_b_sf_marshallOut,
    c28_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c28_b_K, 5U, c28_sf_marshallOut,
    c28_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 2);
  c28_a = c28_b_k3;
  for (c28_i2 = 0; c28_i2 < 9; c28_i2++) {
    c28_y[c28_i2] = c28_a * c28_b[c28_i2];
  }

  c28_b_a = 2.0 * c28_b_eta3 * c28_b_kappa3;
  for (c28_i3 = 0; c28_i3 < 9; c28_i3++) {
    c28_b_y[c28_i3] = c28_b_a * c28_b[c28_i3];
  }

  for (c28_i4 = 0; c28_i4 < 36; c28_i4++) {
    c28_b_K[c28_i4] = 0.0;
  }

  c28_i5 = 0;
  c28_i6 = 0;
  for (c28_i7 = 0; c28_i7 < 3; c28_i7++) {
    for (c28_i8 = 0; c28_i8 < 3; c28_i8++) {
      c28_b_K[c28_i8 + c28_i5] = c28_y[c28_i8 + c28_i6];
    }

    c28_i5 += 6;
    c28_i6 += 3;
  }

  c28_i9 = 0;
  c28_i10 = 0;
  for (c28_i11 = 0; c28_i11 < 3; c28_i11++) {
    for (c28_i12 = 0; c28_i12 < 3; c28_i12++) {
      c28_b_K[(c28_i12 + c28_i9) + 21] = c28_b_y[c28_i12 + c28_i10];
    }

    c28_i9 += 6;
    c28_i10 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, -2);
  _SFD_SYMBOL_SCOPE_POP();
  for (c28_i13 = 0; c28_i13 < 36; c28_i13++) {
    (*chartInstance->c28_K)[c28_i13] = c28_b_K[c28_i13];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c28_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DePascali4MMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c28_i14 = 0; c28_i14 < 36; c28_i14++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c28_K)[c28_i14], 1U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c28_k3, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c28_kappa3, 3U);
}

static void mdl_start_c28_DePascali4M(SFc28_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc28_DePascali4M(SFc28_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c28_machineNumber, uint32_T
  c28_chartNumber, uint32_T c28_instanceNumber)
{
  (void)c28_machineNumber;
  (void)c28_chartNumber;
  (void)c28_instanceNumber;
}

static const mxArray *c28_sf_marshallOut(void *chartInstanceVoid, void
  *c28_inData)
{
  const mxArray *c28_mxArrayOutData = NULL;
  int32_T c28_i15;
  int32_T c28_i16;
  int32_T c28_i17;
  real_T c28_b_inData[36];
  int32_T c28_i18;
  int32_T c28_i19;
  int32_T c28_i20;
  real_T c28_u[36];
  const mxArray *c28_y = NULL;
  SFc28_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc28_DePascali4MInstanceStruct *)chartInstanceVoid;
  c28_mxArrayOutData = NULL;
  c28_i15 = 0;
  for (c28_i16 = 0; c28_i16 < 6; c28_i16++) {
    for (c28_i17 = 0; c28_i17 < 6; c28_i17++) {
      c28_b_inData[c28_i17 + c28_i15] = (*(real_T (*)[36])c28_inData)[c28_i17 +
        c28_i15];
    }

    c28_i15 += 6;
  }

  c28_i18 = 0;
  for (c28_i19 = 0; c28_i19 < 6; c28_i19++) {
    for (c28_i20 = 0; c28_i20 < 6; c28_i20++) {
      c28_u[c28_i20 + c28_i18] = c28_b_inData[c28_i20 + c28_i18];
    }

    c28_i18 += 6;
  }

  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_create("y", c28_u, 0, 0U, 1U, 0U, 2, 6, 6), false);
  sf_mex_assign(&c28_mxArrayOutData, c28_y, false);
  return c28_mxArrayOutData;
}

static void c28_emlrt_marshallIn(SFc28_DePascali4MInstanceStruct *chartInstance,
  const mxArray *c28_b_K, const char_T *c28_identifier, real_T c28_y[36])
{
  emlrtMsgIdentifier c28_thisId;
  c28_thisId.fIdentifier = c28_identifier;
  c28_thisId.fParent = NULL;
  c28_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c28_b_K), &c28_thisId, c28_y);
  sf_mex_destroy(&c28_b_K);
}

static void c28_b_emlrt_marshallIn(SFc28_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId,
  real_T c28_y[36])
{
  real_T c28_dv1[36];
  int32_T c28_i21;
  (void)chartInstance;
  sf_mex_import(c28_parentId, sf_mex_dup(c28_u), c28_dv1, 1, 0, 0U, 1, 0U, 2, 6,
                6);
  for (c28_i21 = 0; c28_i21 < 36; c28_i21++) {
    c28_y[c28_i21] = c28_dv1[c28_i21];
  }

  sf_mex_destroy(&c28_u);
}

static void c28_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData)
{
  const mxArray *c28_b_K;
  const char_T *c28_identifier;
  emlrtMsgIdentifier c28_thisId;
  real_T c28_y[36];
  int32_T c28_i22;
  int32_T c28_i23;
  int32_T c28_i24;
  SFc28_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc28_DePascali4MInstanceStruct *)chartInstanceVoid;
  c28_b_K = sf_mex_dup(c28_mxArrayInData);
  c28_identifier = c28_varName;
  c28_thisId.fIdentifier = c28_identifier;
  c28_thisId.fParent = NULL;
  c28_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c28_b_K), &c28_thisId, c28_y);
  sf_mex_destroy(&c28_b_K);
  c28_i22 = 0;
  for (c28_i23 = 0; c28_i23 < 6; c28_i23++) {
    for (c28_i24 = 0; c28_i24 < 6; c28_i24++) {
      (*(real_T (*)[36])c28_outData)[c28_i24 + c28_i22] = c28_y[c28_i24 +
        c28_i22];
    }

    c28_i22 += 6;
  }

  sf_mex_destroy(&c28_mxArrayInData);
}

static const mxArray *c28_b_sf_marshallOut(void *chartInstanceVoid, void
  *c28_inData)
{
  const mxArray *c28_mxArrayOutData = NULL;
  real_T c28_u;
  const mxArray *c28_y = NULL;
  SFc28_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc28_DePascali4MInstanceStruct *)chartInstanceVoid;
  c28_mxArrayOutData = NULL;
  c28_u = *(real_T *)c28_inData;
  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_create("y", &c28_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c28_mxArrayOutData, c28_y, false);
  return c28_mxArrayOutData;
}

static real_T c28_c_emlrt_marshallIn(SFc28_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId)
{
  real_T c28_y;
  real_T c28_d2;
  (void)chartInstance;
  sf_mex_import(c28_parentId, sf_mex_dup(c28_u), &c28_d2, 1, 0, 0U, 0, 0U, 0);
  c28_y = c28_d2;
  sf_mex_destroy(&c28_u);
  return c28_y;
}

static void c28_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData)
{
  const mxArray *c28_b_kappa3;
  const char_T *c28_identifier;
  emlrtMsgIdentifier c28_thisId;
  real_T c28_y;
  SFc28_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc28_DePascali4MInstanceStruct *)chartInstanceVoid;
  c28_b_kappa3 = sf_mex_dup(c28_mxArrayInData);
  c28_identifier = c28_varName;
  c28_thisId.fIdentifier = c28_identifier;
  c28_thisId.fParent = NULL;
  c28_y = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c28_b_kappa3),
    &c28_thisId);
  sf_mex_destroy(&c28_b_kappa3);
  *(real_T *)c28_outData = c28_y;
  sf_mex_destroy(&c28_mxArrayInData);
}

const mxArray *sf_c28_DePascali4M_get_eml_resolved_functions_info(void)
{
  const mxArray *c28_nameCaptureInfo = NULL;
  c28_nameCaptureInfo = NULL;
  sf_mex_assign(&c28_nameCaptureInfo, sf_mex_createstruct("structure", 2, 31, 1),
                false);
  c28_info_helper(&c28_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c28_nameCaptureInfo);
  return c28_nameCaptureInfo;
}

static void c28_info_helper(const mxArray **c28_info)
{
  const mxArray *c28_rhs0 = NULL;
  const mxArray *c28_lhs0 = NULL;
  const mxArray *c28_rhs1 = NULL;
  const mxArray *c28_lhs1 = NULL;
  const mxArray *c28_rhs2 = NULL;
  const mxArray *c28_lhs2 = NULL;
  const mxArray *c28_rhs3 = NULL;
  const mxArray *c28_lhs3 = NULL;
  const mxArray *c28_rhs4 = NULL;
  const mxArray *c28_lhs4 = NULL;
  const mxArray *c28_rhs5 = NULL;
  const mxArray *c28_lhs5 = NULL;
  const mxArray *c28_rhs6 = NULL;
  const mxArray *c28_lhs6 = NULL;
  const mxArray *c28_rhs7 = NULL;
  const mxArray *c28_lhs7 = NULL;
  const mxArray *c28_rhs8 = NULL;
  const mxArray *c28_lhs8 = NULL;
  const mxArray *c28_rhs9 = NULL;
  const mxArray *c28_lhs9 = NULL;
  const mxArray *c28_rhs10 = NULL;
  const mxArray *c28_lhs10 = NULL;
  const mxArray *c28_rhs11 = NULL;
  const mxArray *c28_lhs11 = NULL;
  const mxArray *c28_rhs12 = NULL;
  const mxArray *c28_lhs12 = NULL;
  const mxArray *c28_rhs13 = NULL;
  const mxArray *c28_lhs13 = NULL;
  const mxArray *c28_rhs14 = NULL;
  const mxArray *c28_lhs14 = NULL;
  const mxArray *c28_rhs15 = NULL;
  const mxArray *c28_lhs15 = NULL;
  const mxArray *c28_rhs16 = NULL;
  const mxArray *c28_lhs16 = NULL;
  const mxArray *c28_rhs17 = NULL;
  const mxArray *c28_lhs17 = NULL;
  const mxArray *c28_rhs18 = NULL;
  const mxArray *c28_lhs18 = NULL;
  const mxArray *c28_rhs19 = NULL;
  const mxArray *c28_lhs19 = NULL;
  const mxArray *c28_rhs20 = NULL;
  const mxArray *c28_lhs20 = NULL;
  const mxArray *c28_rhs21 = NULL;
  const mxArray *c28_lhs21 = NULL;
  const mxArray *c28_rhs22 = NULL;
  const mxArray *c28_lhs22 = NULL;
  const mxArray *c28_rhs23 = NULL;
  const mxArray *c28_lhs23 = NULL;
  const mxArray *c28_rhs24 = NULL;
  const mxArray *c28_lhs24 = NULL;
  const mxArray *c28_rhs25 = NULL;
  const mxArray *c28_lhs25 = NULL;
  const mxArray *c28_rhs26 = NULL;
  const mxArray *c28_lhs26 = NULL;
  const mxArray *c28_rhs27 = NULL;
  const mxArray *c28_lhs27 = NULL;
  const mxArray *c28_rhs28 = NULL;
  const mxArray *c28_lhs28 = NULL;
  const mxArray *c28_rhs29 = NULL;
  const mxArray *c28_lhs29 = NULL;
  const mxArray *c28_rhs30 = NULL;
  const mxArray *c28_lhs30 = NULL;
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eye"), "name", "name", 0);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1406838348U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c28_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 1);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1368208230U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c28_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c28_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral"),
                  "context", "context", 3);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("isinf"), "name", "name", 3);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1363739056U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c28_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c28_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 5);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_is_integer_class"),
                  "name", "name", 5);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1286843982U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c28_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 6);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("intmax"), "name", "name", 6);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c28_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 7);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c28_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 8);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("intmin"), "name", "name", 8);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c28_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 9);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c28_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 10);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "coder.internal.indexIntRelop"), "name", "name", 10);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1326753522U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c28_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!apply_float_relop"),
                  "context", "context", 11);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 11);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c28_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass"),
                  "context", "context", 12);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 12);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1326753196U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c28_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass"),
                  "context", "context", 13);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("intmin"), "name", "name", 13);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c28_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 14);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 14);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c28_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("intmax"), "name", "name", 15);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c28_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 16);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1397282622U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c28_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 17);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("isfi"), "name", "name", 17);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 17);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1346535558U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c28_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 18);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1398900798U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c28_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 19);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("intmax"), "name", "name", 19);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c28_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 20);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("intmin"), "name", "name", 20);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c28_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(""), "context", "context", 21);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 21);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1383902494U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c28_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 22);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 22);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c28_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(""), "context", "context", 23);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("blkdiag"), "name", "name",
                  23);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/blkdiag.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1307676438U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c28_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/blkdiag.m!output_size"),
                  "context", "context", 24);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 24);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c28_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/blkdiag.m!output_size"),
                  "context", "context", 25);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 25);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1372607616U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c28_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 26);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1372608360U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c28_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/blkdiag.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 27);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c28_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 28);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c28_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/blkdiag.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 29);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c28_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/blkdiag.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 30);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1372607616U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c28_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs30), "lhs", "lhs",
                  30);
  sf_mex_destroy(&c28_rhs0);
  sf_mex_destroy(&c28_lhs0);
  sf_mex_destroy(&c28_rhs1);
  sf_mex_destroy(&c28_lhs1);
  sf_mex_destroy(&c28_rhs2);
  sf_mex_destroy(&c28_lhs2);
  sf_mex_destroy(&c28_rhs3);
  sf_mex_destroy(&c28_lhs3);
  sf_mex_destroy(&c28_rhs4);
  sf_mex_destroy(&c28_lhs4);
  sf_mex_destroy(&c28_rhs5);
  sf_mex_destroy(&c28_lhs5);
  sf_mex_destroy(&c28_rhs6);
  sf_mex_destroy(&c28_lhs6);
  sf_mex_destroy(&c28_rhs7);
  sf_mex_destroy(&c28_lhs7);
  sf_mex_destroy(&c28_rhs8);
  sf_mex_destroy(&c28_lhs8);
  sf_mex_destroy(&c28_rhs9);
  sf_mex_destroy(&c28_lhs9);
  sf_mex_destroy(&c28_rhs10);
  sf_mex_destroy(&c28_lhs10);
  sf_mex_destroy(&c28_rhs11);
  sf_mex_destroy(&c28_lhs11);
  sf_mex_destroy(&c28_rhs12);
  sf_mex_destroy(&c28_lhs12);
  sf_mex_destroy(&c28_rhs13);
  sf_mex_destroy(&c28_lhs13);
  sf_mex_destroy(&c28_rhs14);
  sf_mex_destroy(&c28_lhs14);
  sf_mex_destroy(&c28_rhs15);
  sf_mex_destroy(&c28_lhs15);
  sf_mex_destroy(&c28_rhs16);
  sf_mex_destroy(&c28_lhs16);
  sf_mex_destroy(&c28_rhs17);
  sf_mex_destroy(&c28_lhs17);
  sf_mex_destroy(&c28_rhs18);
  sf_mex_destroy(&c28_lhs18);
  sf_mex_destroy(&c28_rhs19);
  sf_mex_destroy(&c28_lhs19);
  sf_mex_destroy(&c28_rhs20);
  sf_mex_destroy(&c28_lhs20);
  sf_mex_destroy(&c28_rhs21);
  sf_mex_destroy(&c28_lhs21);
  sf_mex_destroy(&c28_rhs22);
  sf_mex_destroy(&c28_lhs22);
  sf_mex_destroy(&c28_rhs23);
  sf_mex_destroy(&c28_lhs23);
  sf_mex_destroy(&c28_rhs24);
  sf_mex_destroy(&c28_lhs24);
  sf_mex_destroy(&c28_rhs25);
  sf_mex_destroy(&c28_lhs25);
  sf_mex_destroy(&c28_rhs26);
  sf_mex_destroy(&c28_lhs26);
  sf_mex_destroy(&c28_rhs27);
  sf_mex_destroy(&c28_lhs27);
  sf_mex_destroy(&c28_rhs28);
  sf_mex_destroy(&c28_lhs28);
  sf_mex_destroy(&c28_rhs29);
  sf_mex_destroy(&c28_lhs29);
  sf_mex_destroy(&c28_rhs30);
  sf_mex_destroy(&c28_lhs30);
}

static const mxArray *c28_emlrt_marshallOut(const char * c28_u)
{
  const mxArray *c28_y = NULL;
  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_create("y", c28_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c28_u)), false);
  return c28_y;
}

static const mxArray *c28_b_emlrt_marshallOut(const uint32_T c28_u)
{
  const mxArray *c28_y = NULL;
  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_create("y", &c28_u, 7, 0U, 0U, 0U, 0), false);
  return c28_y;
}

static const mxArray *c28_c_sf_marshallOut(void *chartInstanceVoid, void
  *c28_inData)
{
  const mxArray *c28_mxArrayOutData = NULL;
  int32_T c28_u;
  const mxArray *c28_y = NULL;
  SFc28_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc28_DePascali4MInstanceStruct *)chartInstanceVoid;
  c28_mxArrayOutData = NULL;
  c28_u = *(int32_T *)c28_inData;
  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_create("y", &c28_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c28_mxArrayOutData, c28_y, false);
  return c28_mxArrayOutData;
}

static int32_T c28_d_emlrt_marshallIn(SFc28_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId)
{
  int32_T c28_y;
  int32_T c28_i25;
  (void)chartInstance;
  sf_mex_import(c28_parentId, sf_mex_dup(c28_u), &c28_i25, 1, 6, 0U, 0, 0U, 0);
  c28_y = c28_i25;
  sf_mex_destroy(&c28_u);
  return c28_y;
}

static void c28_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData)
{
  const mxArray *c28_b_sfEvent;
  const char_T *c28_identifier;
  emlrtMsgIdentifier c28_thisId;
  int32_T c28_y;
  SFc28_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc28_DePascali4MInstanceStruct *)chartInstanceVoid;
  c28_b_sfEvent = sf_mex_dup(c28_mxArrayInData);
  c28_identifier = c28_varName;
  c28_thisId.fIdentifier = c28_identifier;
  c28_thisId.fParent = NULL;
  c28_y = c28_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c28_b_sfEvent),
    &c28_thisId);
  sf_mex_destroy(&c28_b_sfEvent);
  *(int32_T *)c28_outData = c28_y;
  sf_mex_destroy(&c28_mxArrayInData);
}

static uint8_T c28_e_emlrt_marshallIn(SFc28_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c28_b_is_active_c28_DePascali4M, const char_T
  *c28_identifier)
{
  uint8_T c28_y;
  emlrtMsgIdentifier c28_thisId;
  c28_thisId.fIdentifier = c28_identifier;
  c28_thisId.fParent = NULL;
  c28_y = c28_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c28_b_is_active_c28_DePascali4M), &c28_thisId);
  sf_mex_destroy(&c28_b_is_active_c28_DePascali4M);
  return c28_y;
}

static uint8_T c28_f_emlrt_marshallIn(SFc28_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId)
{
  uint8_T c28_y;
  uint8_T c28_u0;
  (void)chartInstance;
  sf_mex_import(c28_parentId, sf_mex_dup(c28_u), &c28_u0, 1, 3, 0U, 0, 0U, 0);
  c28_y = c28_u0;
  sf_mex_destroy(&c28_u);
  return c28_y;
}

static void init_dsm_address_info(SFc28_DePascali4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc28_DePascali4MInstanceStruct
  *chartInstance)
{
  chartInstance->c28_eta3 = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c28_K = (real_T (*)[36])ssGetOutputPortSignal_wrapper
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

void sf_c28_DePascali4M_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1106142417U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(53631877U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2657409153U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1661272448U);
}

mxArray* sf_c28_DePascali4M_get_post_codegen_info(void);
mxArray *sf_c28_DePascali4M_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("sLHGNKXSj83cDKtOezOigD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxArray* mxPostCodegenInfo = sf_c28_DePascali4M_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c28_DePascali4M_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c28_DePascali4M_jit_fallback_info(void)
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

mxArray *sf_c28_DePascali4M_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c28_DePascali4M_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c28_DePascali4M(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"K\",},{M[8],M[0],T\"is_active_c28_DePascali4M\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c28_DePascali4M_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc28_DePascali4MInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc28_DePascali4MInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DePascali4MMachineNumber_,
           28,
           1,
           1,
           0,
           4,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"eta3");
          _SFD_SET_DATA_PROPS(1,2,0,1,"K");
          _SFD_SET_DATA_PROPS(2,10,0,0,"k3");
          _SFD_SET_DATA_PROPS(3,10,0,0,"kappa3");
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
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c28_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 6;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c28_sf_marshallOut,(MexInFcnForType)
            c28_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c28_b_sf_marshallOut,(MexInFcnForType)
          c28_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c28_b_sf_marshallOut,(MexInFcnForType)
          c28_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c28_eta3);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c28_K);
        _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c28_k3);
        _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c28_kappa3);
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
  return "kcdYQPfxjOTPB1CZTYjNeH";
}

static void sf_opaque_initialize_c28_DePascali4M(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc28_DePascali4MInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c28_DePascali4M((SFc28_DePascali4MInstanceStruct*)
    chartInstanceVar);
  initialize_c28_DePascali4M((SFc28_DePascali4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c28_DePascali4M(void *chartInstanceVar)
{
  enable_c28_DePascali4M((SFc28_DePascali4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c28_DePascali4M(void *chartInstanceVar)
{
  disable_c28_DePascali4M((SFc28_DePascali4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c28_DePascali4M(void *chartInstanceVar)
{
  sf_gateway_c28_DePascali4M((SFc28_DePascali4MInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c28_DePascali4M(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c28_DePascali4M((SFc28_DePascali4MInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c28_DePascali4M(SimStruct* S, const mxArray *
  st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c28_DePascali4M((SFc28_DePascali4MInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c28_DePascali4M(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc28_DePascali4MInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DePascali4M_optimization_info();
    }

    finalize_c28_DePascali4M((SFc28_DePascali4MInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc28_DePascali4M((SFc28_DePascali4MInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c28_DePascali4M(SimStruct *S)
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
    initialize_params_c28_DePascali4M((SFc28_DePascali4MInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c28_DePascali4M(SimStruct *S)
{
  /* Actual parameters from chart:
     k3 kappa3
   */
  const char_T *rtParamNames[] = { "k3", "kappa3" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for k3*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for kappa3*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DePascali4M_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      28);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,28,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,28,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,28);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,28,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,28,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,28);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1072593772U));
  ssSetChecksum1(S,(3481271471U));
  ssSetChecksum2(S,(4221617086U));
  ssSetChecksum3(S,(835662570U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c28_DePascali4M(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c28_DePascali4M(SimStruct *S)
{
  SFc28_DePascali4MInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc28_DePascali4MInstanceStruct *)utMalloc(sizeof
    (SFc28_DePascali4MInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc28_DePascali4MInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c28_DePascali4M;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c28_DePascali4M;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c28_DePascali4M;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c28_DePascali4M;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c28_DePascali4M;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c28_DePascali4M;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c28_DePascali4M;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c28_DePascali4M;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c28_DePascali4M;
  chartInstance->chartInfo.mdlStart = mdlStart_c28_DePascali4M;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c28_DePascali4M;
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

void c28_DePascali4M_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c28_DePascali4M(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c28_DePascali4M(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c28_DePascali4M(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c28_DePascali4M_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

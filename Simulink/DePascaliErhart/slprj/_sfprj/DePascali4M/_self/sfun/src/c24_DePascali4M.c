/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DePascali4M_sfun.h"
#include "c24_DePascali4M.h"
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
static const char * c24_debug_family_names[5] = { "nargin", "nargout", "dx_do",
  "j0", "C_o" };

static const char * c24_b_debug_family_names[4] = { "nargin", "nargout", "x",
  "X" };

/* Function Declarations */
static void initialize_c24_DePascali4M(SFc24_DePascali4MInstanceStruct
  *chartInstance);
static void initialize_params_c24_DePascali4M(SFc24_DePascali4MInstanceStruct
  *chartInstance);
static void enable_c24_DePascali4M(SFc24_DePascali4MInstanceStruct
  *chartInstance);
static void disable_c24_DePascali4M(SFc24_DePascali4MInstanceStruct
  *chartInstance);
static void c24_update_debugger_state_c24_DePascali4M
  (SFc24_DePascali4MInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c24_DePascali4M
  (SFc24_DePascali4MInstanceStruct *chartInstance);
static void set_sim_state_c24_DePascali4M(SFc24_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c24_st);
static void finalize_c24_DePascali4M(SFc24_DePascali4MInstanceStruct
  *chartInstance);
static void sf_gateway_c24_DePascali4M(SFc24_DePascali4MInstanceStruct
  *chartInstance);
static void mdl_start_c24_DePascali4M(SFc24_DePascali4MInstanceStruct
  *chartInstance);
static void initSimStructsc24_DePascali4M(SFc24_DePascali4MInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c24_machineNumber, uint32_T
  c24_chartNumber, uint32_T c24_instanceNumber);
static const mxArray *c24_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static void c24_emlrt_marshallIn(SFc24_DePascali4MInstanceStruct *chartInstance,
  const mxArray *c24_b_C_o, const char_T *c24_identifier, real_T c24_y[36]);
static void c24_b_emlrt_marshallIn(SFc24_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  real_T c24_y[36]);
static void c24_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static const mxArray *c24_b_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static real_T c24_c_emlrt_marshallIn(SFc24_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void c24_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static const mxArray *c24_c_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static const mxArray *c24_d_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static void c24_d_emlrt_marshallIn(SFc24_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  real_T c24_y[9]);
static void c24_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static const mxArray *c24_e_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static void c24_e_emlrt_marshallIn(SFc24_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  real_T c24_y[3]);
static void c24_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static void c24_info_helper(const mxArray **c24_info);
static const mxArray *c24_emlrt_marshallOut(const char * c24_u);
static const mxArray *c24_b_emlrt_marshallOut(const uint32_T c24_u);
static const mxArray *c24_f_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static int32_T c24_f_emlrt_marshallIn(SFc24_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void c24_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static uint8_T c24_g_emlrt_marshallIn(SFc24_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c24_b_is_active_c24_DePascali4M, const char_T
  *c24_identifier);
static uint8_T c24_h_emlrt_marshallIn(SFc24_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void init_dsm_address_info(SFc24_DePascali4MInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc24_DePascali4MInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c24_DePascali4M(SFc24_DePascali4MInstanceStruct
  *chartInstance)
{
  chartInstance->c24_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c24_is_active_c24_DePascali4M = 0U;
}

static void initialize_params_c24_DePascali4M(SFc24_DePascali4MInstanceStruct
  *chartInstance)
{
  real_T c24_d0;
  sf_mex_import_named("j0", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c24_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c24_j0 = c24_d0;
}

static void enable_c24_DePascali4M(SFc24_DePascali4MInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c24_DePascali4M(SFc24_DePascali4MInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c24_update_debugger_state_c24_DePascali4M
  (SFc24_DePascali4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c24_DePascali4M
  (SFc24_DePascali4MInstanceStruct *chartInstance)
{
  const mxArray *c24_st;
  const mxArray *c24_y = NULL;
  int32_T c24_i0;
  real_T c24_u[36];
  const mxArray *c24_b_y = NULL;
  uint8_T c24_hoistedGlobal;
  uint8_T c24_b_u;
  const mxArray *c24_c_y = NULL;
  c24_st = NULL;
  c24_st = NULL;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_createcellmatrix(2, 1), false);
  for (c24_i0 = 0; c24_i0 < 36; c24_i0++) {
    c24_u[c24_i0] = (*chartInstance->c24_C_o)[c24_i0];
  }

  c24_b_y = NULL;
  sf_mex_assign(&c24_b_y, sf_mex_create("y", c24_u, 0, 0U, 1U, 0U, 2, 6, 6),
                false);
  sf_mex_setcell(c24_y, 0, c24_b_y);
  c24_hoistedGlobal = chartInstance->c24_is_active_c24_DePascali4M;
  c24_b_u = c24_hoistedGlobal;
  c24_c_y = NULL;
  sf_mex_assign(&c24_c_y, sf_mex_create("y", &c24_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c24_y, 1, c24_c_y);
  sf_mex_assign(&c24_st, c24_y, false);
  return c24_st;
}

static void set_sim_state_c24_DePascali4M(SFc24_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c24_st)
{
  const mxArray *c24_u;
  real_T c24_dv0[36];
  int32_T c24_i1;
  chartInstance->c24_doneDoubleBufferReInit = true;
  c24_u = sf_mex_dup(c24_st);
  c24_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c24_u, 0)),
                       "C_o", c24_dv0);
  for (c24_i1 = 0; c24_i1 < 36; c24_i1++) {
    (*chartInstance->c24_C_o)[c24_i1] = c24_dv0[c24_i1];
  }

  chartInstance->c24_is_active_c24_DePascali4M = c24_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c24_u, 1)),
     "is_active_c24_DePascali4M");
  sf_mex_destroy(&c24_u);
  c24_update_debugger_state_c24_DePascali4M(chartInstance);
  sf_mex_destroy(&c24_st);
}

static void finalize_c24_DePascali4M(SFc24_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c24_DePascali4M(SFc24_DePascali4MInstanceStruct
  *chartInstance)
{
  int32_T c24_i2;
  real_T c24_hoistedGlobal;
  int32_T c24_i3;
  real_T c24_b_dx_do[6];
  real_T c24_b_j0;
  uint32_T c24_debug_family_var_map[5];
  real_T c24_nargin = 2.0;
  real_T c24_nargout = 1.0;
  real_T c24_b_C_o[36];
  int32_T c24_i4;
  real_T c24_x[3];
  uint32_T c24_b_debug_family_var_map[4];
  real_T c24_b_nargin = 1.0;
  real_T c24_b_nargout = 1.0;
  real_T c24_X[9];
  real_T c24_a;
  int32_T c24_i5;
  real_T c24_b[9];
  int32_T c24_i6;
  int32_T c24_i7;
  int32_T c24_i8;
  int32_T c24_i9;
  int32_T c24_i10;
  int32_T c24_i11;
  int32_T c24_i12;
  int32_T c24_i13;
  int32_T c24_i14;
  int32_T c24_i15;
  int32_T c24_i16;
  int32_T c24_i17;
  int32_T c24_i18;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c24_sfEvent);
  for (c24_i2 = 0; c24_i2 < 6; c24_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c24_dx_do)[c24_i2], 0U);
  }

  chartInstance->c24_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c24_sfEvent);
  c24_hoistedGlobal = chartInstance->c24_j0;
  for (c24_i3 = 0; c24_i3 < 6; c24_i3++) {
    c24_b_dx_do[c24_i3] = (*chartInstance->c24_dx_do)[c24_i3];
  }

  c24_b_j0 = c24_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c24_debug_family_names,
    c24_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_nargin, 0U, c24_b_sf_marshallOut,
    c24_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_nargout, 1U, c24_b_sf_marshallOut,
    c24_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c24_b_dx_do, 2U, c24_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_b_j0, 3U, c24_b_sf_marshallOut,
    c24_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_b_C_o, 4U, c24_sf_marshallOut,
    c24_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 2);
  for (c24_i4 = 0; c24_i4 < 3; c24_i4++) {
    c24_x[c24_i4] = c24_b_dx_do[c24_i4 + 3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c24_b_debug_family_names,
    c24_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_b_nargin, 0U, c24_b_sf_marshallOut,
    c24_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_b_nargout, 1U, c24_b_sf_marshallOut,
    c24_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_x, 2U, c24_e_sf_marshallOut,
    c24_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_X, 3U, c24_d_sf_marshallOut,
    c24_c_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, 3);
  c24_X[0] = 0.0;
  c24_X[3] = -c24_x[2];
  c24_X[6] = c24_x[1];
  c24_X[1] = c24_x[2];
  c24_X[4] = 0.0;
  c24_X[7] = -c24_x[0];
  c24_X[2] = -c24_x[1];
  c24_X[5] = c24_x[0];
  c24_X[8] = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  c24_a = c24_b_j0;
  for (c24_i5 = 0; c24_i5 < 9; c24_i5++) {
    c24_b[c24_i5] = c24_X[c24_i5];
  }

  for (c24_i6 = 0; c24_i6 < 9; c24_i6++) {
    c24_b[c24_i6] *= c24_a;
  }

  c24_i7 = 0;
  for (c24_i8 = 0; c24_i8 < 6; c24_i8++) {
    for (c24_i9 = 0; c24_i9 < 3; c24_i9++) {
      c24_b_C_o[c24_i9 + c24_i7] = 0.0;
    }

    c24_i7 += 6;
  }

  c24_i10 = 0;
  for (c24_i11 = 0; c24_i11 < 3; c24_i11++) {
    for (c24_i12 = 0; c24_i12 < 3; c24_i12++) {
      c24_b_C_o[(c24_i12 + c24_i10) + 3] = 0.0;
    }

    c24_i10 += 6;
  }

  c24_i13 = 0;
  c24_i14 = 0;
  for (c24_i15 = 0; c24_i15 < 3; c24_i15++) {
    for (c24_i16 = 0; c24_i16 < 3; c24_i16++) {
      c24_b_C_o[(c24_i16 + c24_i13) + 21] = c24_b[c24_i16 + c24_i14];
    }

    c24_i13 += 6;
    c24_i14 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, -2);
  _SFD_SYMBOL_SCOPE_POP();
  for (c24_i17 = 0; c24_i17 < 36; c24_i17++) {
    (*chartInstance->c24_C_o)[c24_i17] = c24_b_C_o[c24_i17];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c24_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DePascali4MMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c24_i18 = 0; c24_i18 < 36; c24_i18++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c24_C_o)[c24_i18], 1U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c24_j0, 2U);
}

static void mdl_start_c24_DePascali4M(SFc24_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc24_DePascali4M(SFc24_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c24_machineNumber, uint32_T
  c24_chartNumber, uint32_T c24_instanceNumber)
{
  (void)c24_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c24_chartNumber, c24_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Martin\\Documents\\Git\\Simulink\\DePascaliErhart\\skew_sm.m"));
}

static const mxArray *c24_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_i19;
  int32_T c24_i20;
  int32_T c24_i21;
  real_T c24_b_inData[36];
  int32_T c24_i22;
  int32_T c24_i23;
  int32_T c24_i24;
  real_T c24_u[36];
  const mxArray *c24_y = NULL;
  SFc24_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc24_DePascali4MInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_i19 = 0;
  for (c24_i20 = 0; c24_i20 < 6; c24_i20++) {
    for (c24_i21 = 0; c24_i21 < 6; c24_i21++) {
      c24_b_inData[c24_i21 + c24_i19] = (*(real_T (*)[36])c24_inData)[c24_i21 +
        c24_i19];
    }

    c24_i19 += 6;
  }

  c24_i22 = 0;
  for (c24_i23 = 0; c24_i23 < 6; c24_i23++) {
    for (c24_i24 = 0; c24_i24 < 6; c24_i24++) {
      c24_u[c24_i24 + c24_i22] = c24_b_inData[c24_i24 + c24_i22];
    }

    c24_i22 += 6;
  }

  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", c24_u, 0, 0U, 1U, 0U, 2, 6, 6), false);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, false);
  return c24_mxArrayOutData;
}

static void c24_emlrt_marshallIn(SFc24_DePascali4MInstanceStruct *chartInstance,
  const mxArray *c24_b_C_o, const char_T *c24_identifier, real_T c24_y[36])
{
  emlrtMsgIdentifier c24_thisId;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_C_o), &c24_thisId,
    c24_y);
  sf_mex_destroy(&c24_b_C_o);
}

static void c24_b_emlrt_marshallIn(SFc24_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  real_T c24_y[36])
{
  real_T c24_dv1[36];
  int32_T c24_i25;
  (void)chartInstance;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), c24_dv1, 1, 0, 0U, 1, 0U, 2, 6,
                6);
  for (c24_i25 = 0; c24_i25 < 36; c24_i25++) {
    c24_y[c24_i25] = c24_dv1[c24_i25];
  }

  sf_mex_destroy(&c24_u);
}

static void c24_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_b_C_o;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  real_T c24_y[36];
  int32_T c24_i26;
  int32_T c24_i27;
  int32_T c24_i28;
  SFc24_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc24_DePascali4MInstanceStruct *)chartInstanceVoid;
  c24_b_C_o = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_C_o), &c24_thisId,
    c24_y);
  sf_mex_destroy(&c24_b_C_o);
  c24_i26 = 0;
  for (c24_i27 = 0; c24_i27 < 6; c24_i27++) {
    for (c24_i28 = 0; c24_i28 < 6; c24_i28++) {
      (*(real_T (*)[36])c24_outData)[c24_i28 + c24_i26] = c24_y[c24_i28 +
        c24_i26];
    }

    c24_i26 += 6;
  }

  sf_mex_destroy(&c24_mxArrayInData);
}

static const mxArray *c24_b_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  real_T c24_u;
  const mxArray *c24_y = NULL;
  SFc24_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc24_DePascali4MInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_u = *(real_T *)c24_inData;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", &c24_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, false);
  return c24_mxArrayOutData;
}

static real_T c24_c_emlrt_marshallIn(SFc24_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  real_T c24_y;
  real_T c24_d1;
  (void)chartInstance;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_d1, 1, 0, 0U, 0, 0U, 0);
  c24_y = c24_d1;
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void c24_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_b_j0;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  real_T c24_y;
  SFc24_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc24_DePascali4MInstanceStruct *)chartInstanceVoid;
  c24_b_j0 = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_j0),
    &c24_thisId);
  sf_mex_destroy(&c24_b_j0);
  *(real_T *)c24_outData = c24_y;
  sf_mex_destroy(&c24_mxArrayInData);
}

static const mxArray *c24_c_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_i29;
  real_T c24_b_inData[6];
  int32_T c24_i30;
  real_T c24_u[6];
  const mxArray *c24_y = NULL;
  SFc24_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc24_DePascali4MInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  for (c24_i29 = 0; c24_i29 < 6; c24_i29++) {
    c24_b_inData[c24_i29] = (*(real_T (*)[6])c24_inData)[c24_i29];
  }

  for (c24_i30 = 0; c24_i30 < 6; c24_i30++) {
    c24_u[c24_i30] = c24_b_inData[c24_i30];
  }

  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", c24_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, false);
  return c24_mxArrayOutData;
}

static const mxArray *c24_d_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_i31;
  int32_T c24_i32;
  int32_T c24_i33;
  real_T c24_b_inData[9];
  int32_T c24_i34;
  int32_T c24_i35;
  int32_T c24_i36;
  real_T c24_u[9];
  const mxArray *c24_y = NULL;
  SFc24_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc24_DePascali4MInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_i31 = 0;
  for (c24_i32 = 0; c24_i32 < 3; c24_i32++) {
    for (c24_i33 = 0; c24_i33 < 3; c24_i33++) {
      c24_b_inData[c24_i33 + c24_i31] = (*(real_T (*)[9])c24_inData)[c24_i33 +
        c24_i31];
    }

    c24_i31 += 3;
  }

  c24_i34 = 0;
  for (c24_i35 = 0; c24_i35 < 3; c24_i35++) {
    for (c24_i36 = 0; c24_i36 < 3; c24_i36++) {
      c24_u[c24_i36 + c24_i34] = c24_b_inData[c24_i36 + c24_i34];
    }

    c24_i34 += 3;
  }

  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", c24_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, false);
  return c24_mxArrayOutData;
}

static void c24_d_emlrt_marshallIn(SFc24_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  real_T c24_y[9])
{
  real_T c24_dv2[9];
  int32_T c24_i37;
  (void)chartInstance;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), c24_dv2, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c24_i37 = 0; c24_i37 < 9; c24_i37++) {
    c24_y[c24_i37] = c24_dv2[c24_i37];
  }

  sf_mex_destroy(&c24_u);
}

static void c24_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_X;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  real_T c24_y[9];
  int32_T c24_i38;
  int32_T c24_i39;
  int32_T c24_i40;
  SFc24_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc24_DePascali4MInstanceStruct *)chartInstanceVoid;
  c24_X = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_X), &c24_thisId, c24_y);
  sf_mex_destroy(&c24_X);
  c24_i38 = 0;
  for (c24_i39 = 0; c24_i39 < 3; c24_i39++) {
    for (c24_i40 = 0; c24_i40 < 3; c24_i40++) {
      (*(real_T (*)[9])c24_outData)[c24_i40 + c24_i38] = c24_y[c24_i40 + c24_i38];
    }

    c24_i38 += 3;
  }

  sf_mex_destroy(&c24_mxArrayInData);
}

static const mxArray *c24_e_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_i41;
  real_T c24_b_inData[3];
  int32_T c24_i42;
  real_T c24_u[3];
  const mxArray *c24_y = NULL;
  SFc24_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc24_DePascali4MInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  for (c24_i41 = 0; c24_i41 < 3; c24_i41++) {
    c24_b_inData[c24_i41] = (*(real_T (*)[3])c24_inData)[c24_i41];
  }

  for (c24_i42 = 0; c24_i42 < 3; c24_i42++) {
    c24_u[c24_i42] = c24_b_inData[c24_i42];
  }

  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", c24_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, false);
  return c24_mxArrayOutData;
}

static void c24_e_emlrt_marshallIn(SFc24_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  real_T c24_y[3])
{
  real_T c24_dv3[3];
  int32_T c24_i43;
  (void)chartInstance;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), c24_dv3, 1, 0, 0U, 1, 0U, 1, 3);
  for (c24_i43 = 0; c24_i43 < 3; c24_i43++) {
    c24_y[c24_i43] = c24_dv3[c24_i43];
  }

  sf_mex_destroy(&c24_u);
}

static void c24_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_x;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  real_T c24_y[3];
  int32_T c24_i44;
  SFc24_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc24_DePascali4MInstanceStruct *)chartInstanceVoid;
  c24_x = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_x), &c24_thisId, c24_y);
  sf_mex_destroy(&c24_x);
  for (c24_i44 = 0; c24_i44 < 3; c24_i44++) {
    (*(real_T (*)[3])c24_outData)[c24_i44] = c24_y[c24_i44];
  }

  sf_mex_destroy(&c24_mxArrayInData);
}

const mxArray *sf_c24_DePascali4M_get_eml_resolved_functions_info(void)
{
  const mxArray *c24_nameCaptureInfo = NULL;
  c24_nameCaptureInfo = NULL;
  sf_mex_assign(&c24_nameCaptureInfo, sf_mex_createstruct("structure", 2, 3, 1),
                false);
  c24_info_helper(&c24_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c24_nameCaptureInfo);
  return c24_nameCaptureInfo;
}

static void c24_info_helper(const mxArray **c24_info)
{
  const mxArray *c24_rhs0 = NULL;
  const mxArray *c24_lhs0 = NULL;
  const mxArray *c24_rhs1 = NULL;
  const mxArray *c24_lhs1 = NULL;
  const mxArray *c24_rhs2 = NULL;
  const mxArray *c24_lhs2 = NULL;
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("skew_sm"), "name", "name", 0);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DePascaliErhart/skew_sm.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1445505143U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c24_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 1);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1383902494U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c24_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 2);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c24_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs2), "lhs", "lhs",
                  2);
  sf_mex_destroy(&c24_rhs0);
  sf_mex_destroy(&c24_lhs0);
  sf_mex_destroy(&c24_rhs1);
  sf_mex_destroy(&c24_lhs1);
  sf_mex_destroy(&c24_rhs2);
  sf_mex_destroy(&c24_lhs2);
}

static const mxArray *c24_emlrt_marshallOut(const char * c24_u)
{
  const mxArray *c24_y = NULL;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", c24_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c24_u)), false);
  return c24_y;
}

static const mxArray *c24_b_emlrt_marshallOut(const uint32_T c24_u)
{
  const mxArray *c24_y = NULL;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", &c24_u, 7, 0U, 0U, 0U, 0), false);
  return c24_y;
}

static const mxArray *c24_f_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_u;
  const mxArray *c24_y = NULL;
  SFc24_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc24_DePascali4MInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_u = *(int32_T *)c24_inData;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", &c24_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, false);
  return c24_mxArrayOutData;
}

static int32_T c24_f_emlrt_marshallIn(SFc24_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  int32_T c24_y;
  int32_T c24_i45;
  (void)chartInstance;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_i45, 1, 6, 0U, 0, 0U, 0);
  c24_y = c24_i45;
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void c24_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_b_sfEvent;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  int32_T c24_y;
  SFc24_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc24_DePascali4MInstanceStruct *)chartInstanceVoid;
  c24_b_sfEvent = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_sfEvent),
    &c24_thisId);
  sf_mex_destroy(&c24_b_sfEvent);
  *(int32_T *)c24_outData = c24_y;
  sf_mex_destroy(&c24_mxArrayInData);
}

static uint8_T c24_g_emlrt_marshallIn(SFc24_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c24_b_is_active_c24_DePascali4M, const char_T
  *c24_identifier)
{
  uint8_T c24_y;
  emlrtMsgIdentifier c24_thisId;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c24_b_is_active_c24_DePascali4M), &c24_thisId);
  sf_mex_destroy(&c24_b_is_active_c24_DePascali4M);
  return c24_y;
}

static uint8_T c24_h_emlrt_marshallIn(SFc24_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  uint8_T c24_y;
  uint8_T c24_u0;
  (void)chartInstance;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_u0, 1, 3, 0U, 0, 0U, 0);
  c24_y = c24_u0;
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void init_dsm_address_info(SFc24_DePascali4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc24_DePascali4MInstanceStruct
  *chartInstance)
{
  chartInstance->c24_dx_do = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c24_C_o = (real_T (*)[36])ssGetOutputPortSignal_wrapper
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

void sf_c24_DePascali4M_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4240855882U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(470846746U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2988603299U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1616052272U);
}

mxArray* sf_c24_DePascali4M_get_post_codegen_info(void);
mxArray *sf_c24_DePascali4M_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("5jpWwWFFE3pGqHXDtwSMe");
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
    mxArray* mxPostCodegenInfo = sf_c24_DePascali4M_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c24_DePascali4M_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c24_DePascali4M_jit_fallback_info(void)
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

mxArray *sf_c24_DePascali4M_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c24_DePascali4M_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c24_DePascali4M(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"C_o\",},{M[8],M[0],T\"is_active_c24_DePascali4M\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c24_DePascali4M_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc24_DePascali4MInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc24_DePascali4MInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DePascali4MMachineNumber_,
           24,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"dx_do");
          _SFD_SET_DATA_PROPS(1,2,0,1,"C_o");
          _SFD_SET_DATA_PROPS(2,10,0,0,"j0");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,94);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"skew_sm",0,-1,127);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c24_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 6;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c24_sf_marshallOut,(MexInFcnForType)
            c24_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c24_b_sf_marshallOut,(MexInFcnForType)
          c24_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c24_dx_do);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c24_C_o);
        _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c24_j0);
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
  return "uCPDCSXCzS21LuFiQz5HhB";
}

static void sf_opaque_initialize_c24_DePascali4M(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc24_DePascali4MInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c24_DePascali4M((SFc24_DePascali4MInstanceStruct*)
    chartInstanceVar);
  initialize_c24_DePascali4M((SFc24_DePascali4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c24_DePascali4M(void *chartInstanceVar)
{
  enable_c24_DePascali4M((SFc24_DePascali4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c24_DePascali4M(void *chartInstanceVar)
{
  disable_c24_DePascali4M((SFc24_DePascali4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c24_DePascali4M(void *chartInstanceVar)
{
  sf_gateway_c24_DePascali4M((SFc24_DePascali4MInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c24_DePascali4M(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c24_DePascali4M((SFc24_DePascali4MInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c24_DePascali4M(SimStruct* S, const mxArray *
  st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c24_DePascali4M((SFc24_DePascali4MInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c24_DePascali4M(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc24_DePascali4MInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DePascali4M_optimization_info();
    }

    finalize_c24_DePascali4M((SFc24_DePascali4MInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc24_DePascali4M((SFc24_DePascali4MInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c24_DePascali4M(SimStruct *S)
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
    initialize_params_c24_DePascali4M((SFc24_DePascali4MInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c24_DePascali4M(SimStruct *S)
{
  /* Actual parameters from chart:
     j0
   */
  const char_T *rtParamNames[] = { "j0" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for j0*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DePascali4M_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      24);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,24,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,24,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,24);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,24,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,24,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,24);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2744536695U));
  ssSetChecksum1(S,(2789575466U));
  ssSetChecksum2(S,(87849327U));
  ssSetChecksum3(S,(2397655320U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c24_DePascali4M(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c24_DePascali4M(SimStruct *S)
{
  SFc24_DePascali4MInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc24_DePascali4MInstanceStruct *)utMalloc(sizeof
    (SFc24_DePascali4MInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc24_DePascali4MInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c24_DePascali4M;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c24_DePascali4M;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c24_DePascali4M;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c24_DePascali4M;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c24_DePascali4M;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c24_DePascali4M;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c24_DePascali4M;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c24_DePascali4M;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c24_DePascali4M;
  chartInstance->chartInfo.mdlStart = mdlStart_c24_DePascali4M;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c24_DePascali4M;
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

void c24_DePascali4M_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c24_DePascali4M(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c24_DePascali4M(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c24_DePascali4M(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c24_DePascali4M_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

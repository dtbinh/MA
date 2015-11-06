/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DePascali4M_sfun.h"
#include "c32_DePascali4M.h"
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
static const char * c32_debug_family_names[7] = { "nargin", "nargout", "G", "M",
  "m0", "j0", "Mapp" };

/* Function Declarations */
static void initialize_c32_DePascali4M(SFc32_DePascali4MInstanceStruct
  *chartInstance);
static void initialize_params_c32_DePascali4M(SFc32_DePascali4MInstanceStruct
  *chartInstance);
static void enable_c32_DePascali4M(SFc32_DePascali4MInstanceStruct
  *chartInstance);
static void disable_c32_DePascali4M(SFc32_DePascali4MInstanceStruct
  *chartInstance);
static void c32_update_debugger_state_c32_DePascali4M
  (SFc32_DePascali4MInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c32_DePascali4M
  (SFc32_DePascali4MInstanceStruct *chartInstance);
static void set_sim_state_c32_DePascali4M(SFc32_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c32_st);
static void finalize_c32_DePascali4M(SFc32_DePascali4MInstanceStruct
  *chartInstance);
static void sf_gateway_c32_DePascali4M(SFc32_DePascali4MInstanceStruct
  *chartInstance);
static void mdl_start_c32_DePascali4M(SFc32_DePascali4MInstanceStruct
  *chartInstance);
static void c32_chartstep_c32_DePascali4M(SFc32_DePascali4MInstanceStruct
  *chartInstance);
static void initSimStructsc32_DePascali4M(SFc32_DePascali4MInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c32_machineNumber, uint32_T
  c32_chartNumber, uint32_T c32_instanceNumber);
static const mxArray *c32_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData);
static void c32_emlrt_marshallIn(SFc32_DePascali4MInstanceStruct *chartInstance,
  const mxArray *c32_b_Mapp, const char_T *c32_identifier, real_T c32_y[36]);
static void c32_b_emlrt_marshallIn(SFc32_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId,
  real_T c32_y[36]);
static void c32_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData);
static const mxArray *c32_b_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData);
static real_T c32_c_emlrt_marshallIn(SFc32_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId);
static void c32_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData);
static const mxArray *c32_c_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData);
static const mxArray *c32_d_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData);
static void c32_info_helper(const mxArray **c32_info);
static const mxArray *c32_emlrt_marshallOut(const char * c32_u);
static const mxArray *c32_b_emlrt_marshallOut(const uint32_T c32_u);
static void c32_eml_scalar_eg(SFc32_DePascali4MInstanceStruct *chartInstance);
static void c32_eml_xgemm(SFc32_DePascali4MInstanceStruct *chartInstance, real_T
  c32_A[144], real_T c32_B[576], real_T c32_C[144], real_T c32_b_C[144]);
static void c32_threshold(SFc32_DePascali4MInstanceStruct *chartInstance);
static void c32_b_eml_scalar_eg(SFc32_DePascali4MInstanceStruct *chartInstance);
static void c32_b_eml_xgemm(SFc32_DePascali4MInstanceStruct *chartInstance,
  real_T c32_A[144], real_T c32_B[144], real_T c32_C[36], real_T c32_b_C[36]);
static const mxArray *c32_e_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData);
static int32_T c32_d_emlrt_marshallIn(SFc32_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId);
static void c32_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData);
static uint8_T c32_e_emlrt_marshallIn(SFc32_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c32_b_is_active_c32_DePascali4M, const char_T
  *c32_identifier);
static uint8_T c32_f_emlrt_marshallIn(SFc32_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId);
static void c32_c_eml_xgemm(SFc32_DePascali4MInstanceStruct *chartInstance,
  real_T c32_A[144], real_T c32_B[576], real_T c32_C[144]);
static void c32_d_eml_xgemm(SFc32_DePascali4MInstanceStruct *chartInstance,
  real_T c32_A[144], real_T c32_B[144], real_T c32_C[36]);
static void init_dsm_address_info(SFc32_DePascali4MInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc32_DePascali4MInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c32_DePascali4M(SFc32_DePascali4MInstanceStruct
  *chartInstance)
{
  chartInstance->c32_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c32_is_active_c32_DePascali4M = 0U;
}

static void initialize_params_c32_DePascali4M(SFc32_DePascali4MInstanceStruct
  *chartInstance)
{
  real_T c32_d0;
  real_T c32_d1;
  sf_mex_import_named("m0", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c32_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c32_m0 = c32_d0;
  sf_mex_import_named("j0", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c32_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c32_j0 = c32_d1;
}

static void enable_c32_DePascali4M(SFc32_DePascali4MInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c32_DePascali4M(SFc32_DePascali4MInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c32_update_debugger_state_c32_DePascali4M
  (SFc32_DePascali4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c32_DePascali4M
  (SFc32_DePascali4MInstanceStruct *chartInstance)
{
  const mxArray *c32_st;
  const mxArray *c32_y = NULL;
  int32_T c32_i0;
  real_T c32_u[36];
  const mxArray *c32_b_y = NULL;
  uint8_T c32_hoistedGlobal;
  uint8_T c32_b_u;
  const mxArray *c32_c_y = NULL;
  c32_st = NULL;
  c32_st = NULL;
  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_createcellmatrix(2, 1), false);
  for (c32_i0 = 0; c32_i0 < 36; c32_i0++) {
    c32_u[c32_i0] = (*chartInstance->c32_Mapp)[c32_i0];
  }

  c32_b_y = NULL;
  sf_mex_assign(&c32_b_y, sf_mex_create("y", c32_u, 0, 0U, 1U, 0U, 2, 6, 6),
                false);
  sf_mex_setcell(c32_y, 0, c32_b_y);
  c32_hoistedGlobal = chartInstance->c32_is_active_c32_DePascali4M;
  c32_b_u = c32_hoistedGlobal;
  c32_c_y = NULL;
  sf_mex_assign(&c32_c_y, sf_mex_create("y", &c32_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c32_y, 1, c32_c_y);
  sf_mex_assign(&c32_st, c32_y, false);
  return c32_st;
}

static void set_sim_state_c32_DePascali4M(SFc32_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c32_st)
{
  const mxArray *c32_u;
  real_T c32_dv0[36];
  int32_T c32_i1;
  chartInstance->c32_doneDoubleBufferReInit = true;
  c32_u = sf_mex_dup(c32_st);
  c32_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c32_u, 0)),
                       "Mapp", c32_dv0);
  for (c32_i1 = 0; c32_i1 < 36; c32_i1++) {
    (*chartInstance->c32_Mapp)[c32_i1] = c32_dv0[c32_i1];
  }

  chartInstance->c32_is_active_c32_DePascali4M = c32_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c32_u, 1)),
     "is_active_c32_DePascali4M");
  sf_mex_destroy(&c32_u);
  c32_update_debugger_state_c32_DePascali4M(chartInstance);
  sf_mex_destroy(&c32_st);
}

static void finalize_c32_DePascali4M(SFc32_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c32_DePascali4M(SFc32_DePascali4MInstanceStruct
  *chartInstance)
{
  int32_T c32_i2;
  int32_T c32_i3;
  int32_T c32_i4;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 12U, chartInstance->c32_sfEvent);
  for (c32_i2 = 0; c32_i2 < 144; c32_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c32_G)[c32_i2], 0U);
  }

  chartInstance->c32_sfEvent = CALL_EVENT;
  c32_chartstep_c32_DePascali4M(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DePascali4MMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c32_i3 = 0; c32_i3 < 36; c32_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c32_Mapp)[c32_i3], 1U);
  }

  for (c32_i4 = 0; c32_i4 < 576; c32_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c32_M)[c32_i4], 2U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c32_m0, 3U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c32_j0, 4U);
}

static void mdl_start_c32_DePascali4M(SFc32_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c32_chartstep_c32_DePascali4M(SFc32_DePascali4MInstanceStruct
  *chartInstance)
{
  real_T c32_hoistedGlobal;
  real_T c32_b_hoistedGlobal;
  int32_T c32_i5;
  real_T c32_b_G[144];
  int32_T c32_i6;
  real_T c32_b_M[576];
  real_T c32_b_m0;
  real_T c32_b_j0;
  uint32_T c32_debug_family_var_map[7];
  real_T c32_nargin = 4.0;
  real_T c32_nargout = 1.0;
  real_T c32_b_Mapp[36];
  real_T c32_a;
  int32_T c32_i7;
  static real_T c32_b[9] = { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 };

  real_T c32_y[9];
  real_T c32_b_a;
  int32_T c32_i8;
  real_T c32_b_y[9];
  int32_T c32_i9;
  real_T c32_c_y[36];
  int32_T c32_i10;
  int32_T c32_i11;
  int32_T c32_i12;
  int32_T c32_i13;
  int32_T c32_i14;
  int32_T c32_i15;
  int32_T c32_i16;
  int32_T c32_i17;
  int32_T c32_i18;
  real_T c32_c_a[144];
  int32_T c32_i19;
  real_T c32_b_b[576];
  int32_T c32_i20;
  real_T c32_d_y[144];
  int32_T c32_i21;
  real_T c32_d_a[144];
  int32_T c32_i22;
  real_T c32_c_b[576];
  int32_T c32_i23;
  int32_T c32_i24;
  int32_T c32_i25;
  int32_T c32_i26;
  real_T c32_d_b[144];
  int32_T c32_i27;
  real_T c32_e_y[36];
  int32_T c32_i28;
  real_T c32_f_y[144];
  int32_T c32_i29;
  real_T c32_e_b[144];
  int32_T c32_i30;
  int32_T c32_i31;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 12U, chartInstance->c32_sfEvent);
  c32_hoistedGlobal = chartInstance->c32_m0;
  c32_b_hoistedGlobal = chartInstance->c32_j0;
  for (c32_i5 = 0; c32_i5 < 144; c32_i5++) {
    c32_b_G[c32_i5] = (*chartInstance->c32_G)[c32_i5];
  }

  for (c32_i6 = 0; c32_i6 < 576; c32_i6++) {
    c32_b_M[c32_i6] = (*chartInstance->c32_M)[c32_i6];
  }

  c32_b_m0 = c32_hoistedGlobal;
  c32_b_j0 = c32_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c32_debug_family_names,
    c32_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c32_nargin, 0U, c32_b_sf_marshallOut,
    c32_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c32_nargout, 1U, c32_b_sf_marshallOut,
    c32_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c32_b_G, 2U, c32_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c32_b_M, 3U, c32_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c32_b_m0, 4U, c32_b_sf_marshallOut,
    c32_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c32_b_j0, 5U, c32_b_sf_marshallOut,
    c32_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c32_b_Mapp, 6U, c32_sf_marshallOut,
    c32_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, 2);
  c32_a = c32_b_m0;
  for (c32_i7 = 0; c32_i7 < 9; c32_i7++) {
    c32_y[c32_i7] = c32_a * c32_b[c32_i7];
  }

  c32_b_a = c32_b_j0;
  for (c32_i8 = 0; c32_i8 < 9; c32_i8++) {
    c32_b_y[c32_i8] = c32_b_a * c32_b[c32_i8];
  }

  for (c32_i9 = 0; c32_i9 < 36; c32_i9++) {
    c32_c_y[c32_i9] = 0.0;
  }

  c32_i10 = 0;
  c32_i11 = 0;
  for (c32_i12 = 0; c32_i12 < 3; c32_i12++) {
    for (c32_i13 = 0; c32_i13 < 3; c32_i13++) {
      c32_c_y[c32_i13 + c32_i10] = c32_y[c32_i13 + c32_i11];
    }

    c32_i10 += 6;
    c32_i11 += 3;
  }

  c32_i14 = 0;
  c32_i15 = 0;
  for (c32_i16 = 0; c32_i16 < 3; c32_i16++) {
    for (c32_i17 = 0; c32_i17 < 3; c32_i17++) {
      c32_c_y[(c32_i17 + c32_i14) + 21] = c32_b_y[c32_i17 + c32_i15];
    }

    c32_i14 += 6;
    c32_i15 += 3;
  }

  for (c32_i18 = 0; c32_i18 < 144; c32_i18++) {
    c32_c_a[c32_i18] = c32_b_G[c32_i18];
  }

  for (c32_i19 = 0; c32_i19 < 576; c32_i19++) {
    c32_b_b[c32_i19] = c32_b_M[c32_i19];
  }

  c32_eml_scalar_eg(chartInstance);
  c32_eml_scalar_eg(chartInstance);
  for (c32_i20 = 0; c32_i20 < 144; c32_i20++) {
    c32_d_y[c32_i20] = 0.0;
  }

  for (c32_i21 = 0; c32_i21 < 144; c32_i21++) {
    c32_d_a[c32_i21] = c32_c_a[c32_i21];
  }

  for (c32_i22 = 0; c32_i22 < 576; c32_i22++) {
    c32_c_b[c32_i22] = c32_b_b[c32_i22];
  }

  c32_c_eml_xgemm(chartInstance, c32_d_a, c32_c_b, c32_d_y);
  c32_i23 = 0;
  for (c32_i24 = 0; c32_i24 < 6; c32_i24++) {
    c32_i25 = 0;
    for (c32_i26 = 0; c32_i26 < 24; c32_i26++) {
      c32_d_b[c32_i26 + c32_i23] = c32_b_G[c32_i25 + c32_i24];
      c32_i25 += 6;
    }

    c32_i23 += 24;
  }

  c32_b_eml_scalar_eg(chartInstance);
  c32_b_eml_scalar_eg(chartInstance);
  for (c32_i27 = 0; c32_i27 < 36; c32_i27++) {
    c32_e_y[c32_i27] = 0.0;
  }

  for (c32_i28 = 0; c32_i28 < 144; c32_i28++) {
    c32_f_y[c32_i28] = c32_d_y[c32_i28];
  }

  for (c32_i29 = 0; c32_i29 < 144; c32_i29++) {
    c32_e_b[c32_i29] = c32_d_b[c32_i29];
  }

  c32_d_eml_xgemm(chartInstance, c32_f_y, c32_e_b, c32_e_y);
  for (c32_i30 = 0; c32_i30 < 36; c32_i30++) {
    c32_b_Mapp[c32_i30] = c32_c_y[c32_i30] + c32_e_y[c32_i30];
  }

  _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, -2);
  _SFD_SYMBOL_SCOPE_POP();
  for (c32_i31 = 0; c32_i31 < 36; c32_i31++) {
    (*chartInstance->c32_Mapp)[c32_i31] = c32_b_Mapp[c32_i31];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c32_sfEvent);
}

static void initSimStructsc32_DePascali4M(SFc32_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c32_machineNumber, uint32_T
  c32_chartNumber, uint32_T c32_instanceNumber)
{
  (void)c32_machineNumber;
  (void)c32_chartNumber;
  (void)c32_instanceNumber;
}

static const mxArray *c32_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData)
{
  const mxArray *c32_mxArrayOutData = NULL;
  int32_T c32_i32;
  int32_T c32_i33;
  int32_T c32_i34;
  real_T c32_b_inData[36];
  int32_T c32_i35;
  int32_T c32_i36;
  int32_T c32_i37;
  real_T c32_u[36];
  const mxArray *c32_y = NULL;
  SFc32_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc32_DePascali4MInstanceStruct *)chartInstanceVoid;
  c32_mxArrayOutData = NULL;
  c32_i32 = 0;
  for (c32_i33 = 0; c32_i33 < 6; c32_i33++) {
    for (c32_i34 = 0; c32_i34 < 6; c32_i34++) {
      c32_b_inData[c32_i34 + c32_i32] = (*(real_T (*)[36])c32_inData)[c32_i34 +
        c32_i32];
    }

    c32_i32 += 6;
  }

  c32_i35 = 0;
  for (c32_i36 = 0; c32_i36 < 6; c32_i36++) {
    for (c32_i37 = 0; c32_i37 < 6; c32_i37++) {
      c32_u[c32_i37 + c32_i35] = c32_b_inData[c32_i37 + c32_i35];
    }

    c32_i35 += 6;
  }

  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_create("y", c32_u, 0, 0U, 1U, 0U, 2, 6, 6), false);
  sf_mex_assign(&c32_mxArrayOutData, c32_y, false);
  return c32_mxArrayOutData;
}

static void c32_emlrt_marshallIn(SFc32_DePascali4MInstanceStruct *chartInstance,
  const mxArray *c32_b_Mapp, const char_T *c32_identifier, real_T c32_y[36])
{
  emlrtMsgIdentifier c32_thisId;
  c32_thisId.fIdentifier = c32_identifier;
  c32_thisId.fParent = NULL;
  c32_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c32_b_Mapp), &c32_thisId,
    c32_y);
  sf_mex_destroy(&c32_b_Mapp);
}

static void c32_b_emlrt_marshallIn(SFc32_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId,
  real_T c32_y[36])
{
  real_T c32_dv1[36];
  int32_T c32_i38;
  (void)chartInstance;
  sf_mex_import(c32_parentId, sf_mex_dup(c32_u), c32_dv1, 1, 0, 0U, 1, 0U, 2, 6,
                6);
  for (c32_i38 = 0; c32_i38 < 36; c32_i38++) {
    c32_y[c32_i38] = c32_dv1[c32_i38];
  }

  sf_mex_destroy(&c32_u);
}

static void c32_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData)
{
  const mxArray *c32_b_Mapp;
  const char_T *c32_identifier;
  emlrtMsgIdentifier c32_thisId;
  real_T c32_y[36];
  int32_T c32_i39;
  int32_T c32_i40;
  int32_T c32_i41;
  SFc32_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc32_DePascali4MInstanceStruct *)chartInstanceVoid;
  c32_b_Mapp = sf_mex_dup(c32_mxArrayInData);
  c32_identifier = c32_varName;
  c32_thisId.fIdentifier = c32_identifier;
  c32_thisId.fParent = NULL;
  c32_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c32_b_Mapp), &c32_thisId,
    c32_y);
  sf_mex_destroy(&c32_b_Mapp);
  c32_i39 = 0;
  for (c32_i40 = 0; c32_i40 < 6; c32_i40++) {
    for (c32_i41 = 0; c32_i41 < 6; c32_i41++) {
      (*(real_T (*)[36])c32_outData)[c32_i41 + c32_i39] = c32_y[c32_i41 +
        c32_i39];
    }

    c32_i39 += 6;
  }

  sf_mex_destroy(&c32_mxArrayInData);
}

static const mxArray *c32_b_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData)
{
  const mxArray *c32_mxArrayOutData = NULL;
  real_T c32_u;
  const mxArray *c32_y = NULL;
  SFc32_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc32_DePascali4MInstanceStruct *)chartInstanceVoid;
  c32_mxArrayOutData = NULL;
  c32_u = *(real_T *)c32_inData;
  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_create("y", &c32_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c32_mxArrayOutData, c32_y, false);
  return c32_mxArrayOutData;
}

static real_T c32_c_emlrt_marshallIn(SFc32_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId)
{
  real_T c32_y;
  real_T c32_d2;
  (void)chartInstance;
  sf_mex_import(c32_parentId, sf_mex_dup(c32_u), &c32_d2, 1, 0, 0U, 0, 0U, 0);
  c32_y = c32_d2;
  sf_mex_destroy(&c32_u);
  return c32_y;
}

static void c32_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData)
{
  const mxArray *c32_b_j0;
  const char_T *c32_identifier;
  emlrtMsgIdentifier c32_thisId;
  real_T c32_y;
  SFc32_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc32_DePascali4MInstanceStruct *)chartInstanceVoid;
  c32_b_j0 = sf_mex_dup(c32_mxArrayInData);
  c32_identifier = c32_varName;
  c32_thisId.fIdentifier = c32_identifier;
  c32_thisId.fParent = NULL;
  c32_y = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c32_b_j0),
    &c32_thisId);
  sf_mex_destroy(&c32_b_j0);
  *(real_T *)c32_outData = c32_y;
  sf_mex_destroy(&c32_mxArrayInData);
}

static const mxArray *c32_c_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData)
{
  const mxArray *c32_mxArrayOutData = NULL;
  int32_T c32_i42;
  int32_T c32_i43;
  int32_T c32_i44;
  real_T c32_b_inData[576];
  int32_T c32_i45;
  int32_T c32_i46;
  int32_T c32_i47;
  real_T c32_u[576];
  const mxArray *c32_y = NULL;
  SFc32_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc32_DePascali4MInstanceStruct *)chartInstanceVoid;
  c32_mxArrayOutData = NULL;
  c32_i42 = 0;
  for (c32_i43 = 0; c32_i43 < 24; c32_i43++) {
    for (c32_i44 = 0; c32_i44 < 24; c32_i44++) {
      c32_b_inData[c32_i44 + c32_i42] = (*(real_T (*)[576])c32_inData)[c32_i44 +
        c32_i42];
    }

    c32_i42 += 24;
  }

  c32_i45 = 0;
  for (c32_i46 = 0; c32_i46 < 24; c32_i46++) {
    for (c32_i47 = 0; c32_i47 < 24; c32_i47++) {
      c32_u[c32_i47 + c32_i45] = c32_b_inData[c32_i47 + c32_i45];
    }

    c32_i45 += 24;
  }

  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_create("y", c32_u, 0, 0U, 1U, 0U, 2, 24, 24),
                false);
  sf_mex_assign(&c32_mxArrayOutData, c32_y, false);
  return c32_mxArrayOutData;
}

static const mxArray *c32_d_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData)
{
  const mxArray *c32_mxArrayOutData = NULL;
  int32_T c32_i48;
  int32_T c32_i49;
  int32_T c32_i50;
  real_T c32_b_inData[144];
  int32_T c32_i51;
  int32_T c32_i52;
  int32_T c32_i53;
  real_T c32_u[144];
  const mxArray *c32_y = NULL;
  SFc32_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc32_DePascali4MInstanceStruct *)chartInstanceVoid;
  c32_mxArrayOutData = NULL;
  c32_i48 = 0;
  for (c32_i49 = 0; c32_i49 < 24; c32_i49++) {
    for (c32_i50 = 0; c32_i50 < 6; c32_i50++) {
      c32_b_inData[c32_i50 + c32_i48] = (*(real_T (*)[144])c32_inData)[c32_i50 +
        c32_i48];
    }

    c32_i48 += 6;
  }

  c32_i51 = 0;
  for (c32_i52 = 0; c32_i52 < 24; c32_i52++) {
    for (c32_i53 = 0; c32_i53 < 6; c32_i53++) {
      c32_u[c32_i53 + c32_i51] = c32_b_inData[c32_i53 + c32_i51];
    }

    c32_i51 += 6;
  }

  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_create("y", c32_u, 0, 0U, 1U, 0U, 2, 6, 24),
                false);
  sf_mex_assign(&c32_mxArrayOutData, c32_y, false);
  return c32_mxArrayOutData;
}

const mxArray *sf_c32_DePascali4M_get_eml_resolved_functions_info(void)
{
  const mxArray *c32_nameCaptureInfo = NULL;
  c32_nameCaptureInfo = NULL;
  sf_mex_assign(&c32_nameCaptureInfo, sf_mex_createstruct("structure", 2, 44, 1),
                false);
  c32_info_helper(&c32_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c32_nameCaptureInfo);
  return c32_nameCaptureInfo;
}

static void c32_info_helper(const mxArray **c32_info)
{
  const mxArray *c32_rhs0 = NULL;
  const mxArray *c32_lhs0 = NULL;
  const mxArray *c32_rhs1 = NULL;
  const mxArray *c32_lhs1 = NULL;
  const mxArray *c32_rhs2 = NULL;
  const mxArray *c32_lhs2 = NULL;
  const mxArray *c32_rhs3 = NULL;
  const mxArray *c32_lhs3 = NULL;
  const mxArray *c32_rhs4 = NULL;
  const mxArray *c32_lhs4 = NULL;
  const mxArray *c32_rhs5 = NULL;
  const mxArray *c32_lhs5 = NULL;
  const mxArray *c32_rhs6 = NULL;
  const mxArray *c32_lhs6 = NULL;
  const mxArray *c32_rhs7 = NULL;
  const mxArray *c32_lhs7 = NULL;
  const mxArray *c32_rhs8 = NULL;
  const mxArray *c32_lhs8 = NULL;
  const mxArray *c32_rhs9 = NULL;
  const mxArray *c32_lhs9 = NULL;
  const mxArray *c32_rhs10 = NULL;
  const mxArray *c32_lhs10 = NULL;
  const mxArray *c32_rhs11 = NULL;
  const mxArray *c32_lhs11 = NULL;
  const mxArray *c32_rhs12 = NULL;
  const mxArray *c32_lhs12 = NULL;
  const mxArray *c32_rhs13 = NULL;
  const mxArray *c32_lhs13 = NULL;
  const mxArray *c32_rhs14 = NULL;
  const mxArray *c32_lhs14 = NULL;
  const mxArray *c32_rhs15 = NULL;
  const mxArray *c32_lhs15 = NULL;
  const mxArray *c32_rhs16 = NULL;
  const mxArray *c32_lhs16 = NULL;
  const mxArray *c32_rhs17 = NULL;
  const mxArray *c32_lhs17 = NULL;
  const mxArray *c32_rhs18 = NULL;
  const mxArray *c32_lhs18 = NULL;
  const mxArray *c32_rhs19 = NULL;
  const mxArray *c32_lhs19 = NULL;
  const mxArray *c32_rhs20 = NULL;
  const mxArray *c32_lhs20 = NULL;
  const mxArray *c32_rhs21 = NULL;
  const mxArray *c32_lhs21 = NULL;
  const mxArray *c32_rhs22 = NULL;
  const mxArray *c32_lhs22 = NULL;
  const mxArray *c32_rhs23 = NULL;
  const mxArray *c32_lhs23 = NULL;
  const mxArray *c32_rhs24 = NULL;
  const mxArray *c32_lhs24 = NULL;
  const mxArray *c32_rhs25 = NULL;
  const mxArray *c32_lhs25 = NULL;
  const mxArray *c32_rhs26 = NULL;
  const mxArray *c32_lhs26 = NULL;
  const mxArray *c32_rhs27 = NULL;
  const mxArray *c32_lhs27 = NULL;
  const mxArray *c32_rhs28 = NULL;
  const mxArray *c32_lhs28 = NULL;
  const mxArray *c32_rhs29 = NULL;
  const mxArray *c32_lhs29 = NULL;
  const mxArray *c32_rhs30 = NULL;
  const mxArray *c32_lhs30 = NULL;
  const mxArray *c32_rhs31 = NULL;
  const mxArray *c32_lhs31 = NULL;
  const mxArray *c32_rhs32 = NULL;
  const mxArray *c32_lhs32 = NULL;
  const mxArray *c32_rhs33 = NULL;
  const mxArray *c32_lhs33 = NULL;
  const mxArray *c32_rhs34 = NULL;
  const mxArray *c32_lhs34 = NULL;
  const mxArray *c32_rhs35 = NULL;
  const mxArray *c32_lhs35 = NULL;
  const mxArray *c32_rhs36 = NULL;
  const mxArray *c32_lhs36 = NULL;
  const mxArray *c32_rhs37 = NULL;
  const mxArray *c32_lhs37 = NULL;
  const mxArray *c32_rhs38 = NULL;
  const mxArray *c32_lhs38 = NULL;
  const mxArray *c32_rhs39 = NULL;
  const mxArray *c32_lhs39 = NULL;
  const mxArray *c32_rhs40 = NULL;
  const mxArray *c32_lhs40 = NULL;
  const mxArray *c32_rhs41 = NULL;
  const mxArray *c32_lhs41 = NULL;
  const mxArray *c32_rhs42 = NULL;
  const mxArray *c32_lhs42 = NULL;
  const mxArray *c32_rhs43 = NULL;
  const mxArray *c32_lhs43 = NULL;
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eye"), "name", "name", 0);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1406838348U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c32_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 1);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1368208230U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c32_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c32_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral"),
                  "context", "context", 3);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("isinf"), "name", "name", 3);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1363739056U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c32_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c32_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 5);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_is_integer_class"),
                  "name", "name", 5);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1286843982U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c32_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 6);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("intmax"), "name", "name", 6);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c32_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 7);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c32_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 8);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("intmin"), "name", "name", 8);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c32_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 9);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c32_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 10);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "coder.internal.indexIntRelop"), "name", "name", 10);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1326753522U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c32_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!apply_float_relop"),
                  "context", "context", 11);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 11);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c32_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass"),
                  "context", "context", 12);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 12);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1326753196U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c32_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass"),
                  "context", "context", 13);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("intmin"), "name", "name", 13);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c32_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 14);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 14);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c32_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("intmax"), "name", "name", 15);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c32_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 16);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1397282622U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c32_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 17);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("isfi"), "name", "name", 17);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 17);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1346535558U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c32_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 18);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1398900798U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c32_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 19);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("intmax"), "name", "name", 19);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c32_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 20);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("intmin"), "name", "name", 20);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c32_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "context", "context", 21);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 21);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1383902494U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c32_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 22);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 22);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c32_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "context", "context", 23);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("blkdiag"), "name", "name",
                  23);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/blkdiag.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1307676438U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c32_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/blkdiag.m!output_size"),
                  "context", "context", 24);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 24);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c32_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/blkdiag.m!output_size"),
                  "context", "context", 25);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 25);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1372607616U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c32_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 26);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1372608360U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c32_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/blkdiag.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 27);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c32_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 28);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c32_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/blkdiag.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 29);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c32_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/blkdiag.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 30);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1372607616U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c32_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 31);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 31);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c32_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 32);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 32);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c32_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 33);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  33);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1376005890U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c32_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 34);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c32_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 35);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c32_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 36);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 36);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c32_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 37);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 37);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c32_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 38);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 38);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c32_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 39);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 39);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c32_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 40);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 40);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c32_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 41);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("coder.internal.blas.int"),
                  "name", "name", 41);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/int.p"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c32_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!ceval_xgemm"),
                  "context", "context", 42);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "coder.internal.blas.size_ptr"), "name", "name", 42);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/size_ptr.p"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c32_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!ceval_xgemm"),
                  "context", "context", 43);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("coder.internal.c_cast"),
                  "name", "name", 43);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c32_info, c32_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/c_cast.p"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c32_info, c32_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c32_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c32_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c32_info, sf_mex_duplicatearraysafe(&c32_lhs43), "lhs", "lhs",
                  43);
  sf_mex_destroy(&c32_rhs0);
  sf_mex_destroy(&c32_lhs0);
  sf_mex_destroy(&c32_rhs1);
  sf_mex_destroy(&c32_lhs1);
  sf_mex_destroy(&c32_rhs2);
  sf_mex_destroy(&c32_lhs2);
  sf_mex_destroy(&c32_rhs3);
  sf_mex_destroy(&c32_lhs3);
  sf_mex_destroy(&c32_rhs4);
  sf_mex_destroy(&c32_lhs4);
  sf_mex_destroy(&c32_rhs5);
  sf_mex_destroy(&c32_lhs5);
  sf_mex_destroy(&c32_rhs6);
  sf_mex_destroy(&c32_lhs6);
  sf_mex_destroy(&c32_rhs7);
  sf_mex_destroy(&c32_lhs7);
  sf_mex_destroy(&c32_rhs8);
  sf_mex_destroy(&c32_lhs8);
  sf_mex_destroy(&c32_rhs9);
  sf_mex_destroy(&c32_lhs9);
  sf_mex_destroy(&c32_rhs10);
  sf_mex_destroy(&c32_lhs10);
  sf_mex_destroy(&c32_rhs11);
  sf_mex_destroy(&c32_lhs11);
  sf_mex_destroy(&c32_rhs12);
  sf_mex_destroy(&c32_lhs12);
  sf_mex_destroy(&c32_rhs13);
  sf_mex_destroy(&c32_lhs13);
  sf_mex_destroy(&c32_rhs14);
  sf_mex_destroy(&c32_lhs14);
  sf_mex_destroy(&c32_rhs15);
  sf_mex_destroy(&c32_lhs15);
  sf_mex_destroy(&c32_rhs16);
  sf_mex_destroy(&c32_lhs16);
  sf_mex_destroy(&c32_rhs17);
  sf_mex_destroy(&c32_lhs17);
  sf_mex_destroy(&c32_rhs18);
  sf_mex_destroy(&c32_lhs18);
  sf_mex_destroy(&c32_rhs19);
  sf_mex_destroy(&c32_lhs19);
  sf_mex_destroy(&c32_rhs20);
  sf_mex_destroy(&c32_lhs20);
  sf_mex_destroy(&c32_rhs21);
  sf_mex_destroy(&c32_lhs21);
  sf_mex_destroy(&c32_rhs22);
  sf_mex_destroy(&c32_lhs22);
  sf_mex_destroy(&c32_rhs23);
  sf_mex_destroy(&c32_lhs23);
  sf_mex_destroy(&c32_rhs24);
  sf_mex_destroy(&c32_lhs24);
  sf_mex_destroy(&c32_rhs25);
  sf_mex_destroy(&c32_lhs25);
  sf_mex_destroy(&c32_rhs26);
  sf_mex_destroy(&c32_lhs26);
  sf_mex_destroy(&c32_rhs27);
  sf_mex_destroy(&c32_lhs27);
  sf_mex_destroy(&c32_rhs28);
  sf_mex_destroy(&c32_lhs28);
  sf_mex_destroy(&c32_rhs29);
  sf_mex_destroy(&c32_lhs29);
  sf_mex_destroy(&c32_rhs30);
  sf_mex_destroy(&c32_lhs30);
  sf_mex_destroy(&c32_rhs31);
  sf_mex_destroy(&c32_lhs31);
  sf_mex_destroy(&c32_rhs32);
  sf_mex_destroy(&c32_lhs32);
  sf_mex_destroy(&c32_rhs33);
  sf_mex_destroy(&c32_lhs33);
  sf_mex_destroy(&c32_rhs34);
  sf_mex_destroy(&c32_lhs34);
  sf_mex_destroy(&c32_rhs35);
  sf_mex_destroy(&c32_lhs35);
  sf_mex_destroy(&c32_rhs36);
  sf_mex_destroy(&c32_lhs36);
  sf_mex_destroy(&c32_rhs37);
  sf_mex_destroy(&c32_lhs37);
  sf_mex_destroy(&c32_rhs38);
  sf_mex_destroy(&c32_lhs38);
  sf_mex_destroy(&c32_rhs39);
  sf_mex_destroy(&c32_lhs39);
  sf_mex_destroy(&c32_rhs40);
  sf_mex_destroy(&c32_lhs40);
  sf_mex_destroy(&c32_rhs41);
  sf_mex_destroy(&c32_lhs41);
  sf_mex_destroy(&c32_rhs42);
  sf_mex_destroy(&c32_lhs42);
  sf_mex_destroy(&c32_rhs43);
  sf_mex_destroy(&c32_lhs43);
}

static const mxArray *c32_emlrt_marshallOut(const char * c32_u)
{
  const mxArray *c32_y = NULL;
  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_create("y", c32_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c32_u)), false);
  return c32_y;
}

static const mxArray *c32_b_emlrt_marshallOut(const uint32_T c32_u)
{
  const mxArray *c32_y = NULL;
  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_create("y", &c32_u, 7, 0U, 0U, 0U, 0), false);
  return c32_y;
}

static void c32_eml_scalar_eg(SFc32_DePascali4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c32_eml_xgemm(SFc32_DePascali4MInstanceStruct *chartInstance, real_T
  c32_A[144], real_T c32_B[576], real_T c32_C[144], real_T c32_b_C[144])
{
  int32_T c32_i54;
  int32_T c32_i55;
  real_T c32_b_A[144];
  int32_T c32_i56;
  real_T c32_b_B[576];
  for (c32_i54 = 0; c32_i54 < 144; c32_i54++) {
    c32_b_C[c32_i54] = c32_C[c32_i54];
  }

  for (c32_i55 = 0; c32_i55 < 144; c32_i55++) {
    c32_b_A[c32_i55] = c32_A[c32_i55];
  }

  for (c32_i56 = 0; c32_i56 < 576; c32_i56++) {
    c32_b_B[c32_i56] = c32_B[c32_i56];
  }

  c32_c_eml_xgemm(chartInstance, c32_b_A, c32_b_B, c32_b_C);
}

static void c32_threshold(SFc32_DePascali4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c32_b_eml_scalar_eg(SFc32_DePascali4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c32_b_eml_xgemm(SFc32_DePascali4MInstanceStruct *chartInstance,
  real_T c32_A[144], real_T c32_B[144], real_T c32_C[36], real_T c32_b_C[36])
{
  int32_T c32_i57;
  int32_T c32_i58;
  real_T c32_b_A[144];
  int32_T c32_i59;
  real_T c32_b_B[144];
  for (c32_i57 = 0; c32_i57 < 36; c32_i57++) {
    c32_b_C[c32_i57] = c32_C[c32_i57];
  }

  for (c32_i58 = 0; c32_i58 < 144; c32_i58++) {
    c32_b_A[c32_i58] = c32_A[c32_i58];
  }

  for (c32_i59 = 0; c32_i59 < 144; c32_i59++) {
    c32_b_B[c32_i59] = c32_B[c32_i59];
  }

  c32_d_eml_xgemm(chartInstance, c32_b_A, c32_b_B, c32_b_C);
}

static const mxArray *c32_e_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData)
{
  const mxArray *c32_mxArrayOutData = NULL;
  int32_T c32_u;
  const mxArray *c32_y = NULL;
  SFc32_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc32_DePascali4MInstanceStruct *)chartInstanceVoid;
  c32_mxArrayOutData = NULL;
  c32_u = *(int32_T *)c32_inData;
  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_create("y", &c32_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c32_mxArrayOutData, c32_y, false);
  return c32_mxArrayOutData;
}

static int32_T c32_d_emlrt_marshallIn(SFc32_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId)
{
  int32_T c32_y;
  int32_T c32_i60;
  (void)chartInstance;
  sf_mex_import(c32_parentId, sf_mex_dup(c32_u), &c32_i60, 1, 6, 0U, 0, 0U, 0);
  c32_y = c32_i60;
  sf_mex_destroy(&c32_u);
  return c32_y;
}

static void c32_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData)
{
  const mxArray *c32_b_sfEvent;
  const char_T *c32_identifier;
  emlrtMsgIdentifier c32_thisId;
  int32_T c32_y;
  SFc32_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc32_DePascali4MInstanceStruct *)chartInstanceVoid;
  c32_b_sfEvent = sf_mex_dup(c32_mxArrayInData);
  c32_identifier = c32_varName;
  c32_thisId.fIdentifier = c32_identifier;
  c32_thisId.fParent = NULL;
  c32_y = c32_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c32_b_sfEvent),
    &c32_thisId);
  sf_mex_destroy(&c32_b_sfEvent);
  *(int32_T *)c32_outData = c32_y;
  sf_mex_destroy(&c32_mxArrayInData);
}

static uint8_T c32_e_emlrt_marshallIn(SFc32_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c32_b_is_active_c32_DePascali4M, const char_T
  *c32_identifier)
{
  uint8_T c32_y;
  emlrtMsgIdentifier c32_thisId;
  c32_thisId.fIdentifier = c32_identifier;
  c32_thisId.fParent = NULL;
  c32_y = c32_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c32_b_is_active_c32_DePascali4M), &c32_thisId);
  sf_mex_destroy(&c32_b_is_active_c32_DePascali4M);
  return c32_y;
}

static uint8_T c32_f_emlrt_marshallIn(SFc32_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId)
{
  uint8_T c32_y;
  uint8_T c32_u0;
  (void)chartInstance;
  sf_mex_import(c32_parentId, sf_mex_dup(c32_u), &c32_u0, 1, 3, 0U, 0, 0U, 0);
  c32_y = c32_u0;
  sf_mex_destroy(&c32_u);
  return c32_y;
}

static void c32_c_eml_xgemm(SFc32_DePascali4MInstanceStruct *chartInstance,
  real_T c32_A[144], real_T c32_B[576], real_T c32_C[144])
{
  real_T c32_alpha1;
  real_T c32_beta1;
  char_T c32_TRANSB;
  char_T c32_TRANSA;
  ptrdiff_t c32_m_t;
  ptrdiff_t c32_n_t;
  ptrdiff_t c32_k_t;
  ptrdiff_t c32_lda_t;
  ptrdiff_t c32_ldb_t;
  ptrdiff_t c32_ldc_t;
  double * c32_alpha1_t;
  double * c32_Aia0_t;
  double * c32_Bib0_t;
  double * c32_beta1_t;
  double * c32_Cic0_t;
  c32_threshold(chartInstance);
  c32_alpha1 = 1.0;
  c32_beta1 = 0.0;
  c32_TRANSB = 'N';
  c32_TRANSA = 'N';
  c32_m_t = (ptrdiff_t)(6);
  c32_n_t = (ptrdiff_t)(24);
  c32_k_t = (ptrdiff_t)(24);
  c32_lda_t = (ptrdiff_t)(6);
  c32_ldb_t = (ptrdiff_t)(24);
  c32_ldc_t = (ptrdiff_t)(6);
  c32_alpha1_t = (double *)(&c32_alpha1);
  c32_Aia0_t = (double *)(&c32_A[0]);
  c32_Bib0_t = (double *)(&c32_B[0]);
  c32_beta1_t = (double *)(&c32_beta1);
  c32_Cic0_t = (double *)(&c32_C[0]);
  dgemm(&c32_TRANSA, &c32_TRANSB, &c32_m_t, &c32_n_t, &c32_k_t, c32_alpha1_t,
        c32_Aia0_t, &c32_lda_t, c32_Bib0_t, &c32_ldb_t, c32_beta1_t, c32_Cic0_t,
        &c32_ldc_t);
}

static void c32_d_eml_xgemm(SFc32_DePascali4MInstanceStruct *chartInstance,
  real_T c32_A[144], real_T c32_B[144], real_T c32_C[36])
{
  real_T c32_alpha1;
  real_T c32_beta1;
  char_T c32_TRANSB;
  char_T c32_TRANSA;
  ptrdiff_t c32_m_t;
  ptrdiff_t c32_n_t;
  ptrdiff_t c32_k_t;
  ptrdiff_t c32_lda_t;
  ptrdiff_t c32_ldb_t;
  ptrdiff_t c32_ldc_t;
  double * c32_alpha1_t;
  double * c32_Aia0_t;
  double * c32_Bib0_t;
  double * c32_beta1_t;
  double * c32_Cic0_t;
  c32_threshold(chartInstance);
  c32_alpha1 = 1.0;
  c32_beta1 = 0.0;
  c32_TRANSB = 'N';
  c32_TRANSA = 'N';
  c32_m_t = (ptrdiff_t)(6);
  c32_n_t = (ptrdiff_t)(6);
  c32_k_t = (ptrdiff_t)(24);
  c32_lda_t = (ptrdiff_t)(6);
  c32_ldb_t = (ptrdiff_t)(24);
  c32_ldc_t = (ptrdiff_t)(6);
  c32_alpha1_t = (double *)(&c32_alpha1);
  c32_Aia0_t = (double *)(&c32_A[0]);
  c32_Bib0_t = (double *)(&c32_B[0]);
  c32_beta1_t = (double *)(&c32_beta1);
  c32_Cic0_t = (double *)(&c32_C[0]);
  dgemm(&c32_TRANSA, &c32_TRANSB, &c32_m_t, &c32_n_t, &c32_k_t, c32_alpha1_t,
        c32_Aia0_t, &c32_lda_t, c32_Bib0_t, &c32_ldb_t, c32_beta1_t, c32_Cic0_t,
        &c32_ldc_t);
}

static void init_dsm_address_info(SFc32_DePascali4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc32_DePascali4MInstanceStruct
  *chartInstance)
{
  chartInstance->c32_G = (real_T (*)[144])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c32_Mapp = (real_T (*)[36])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c32_M = (real_T (*)[576])ssGetInputPortSignal_wrapper
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

void sf_c32_DePascali4M_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2661515473U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3368719712U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1409763080U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3578054566U);
}

mxArray* sf_c32_DePascali4M_get_post_codegen_info(void);
mxArray *sf_c32_DePascali4M_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("IEwzOVJMjHMsKbp8BgHA5B");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(24);
      pr[1] = (double)(24);
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
    mxArray* mxPostCodegenInfo = sf_c32_DePascali4M_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c32_DePascali4M_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c32_DePascali4M_jit_fallback_info(void)
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

mxArray *sf_c32_DePascali4M_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c32_DePascali4M_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c32_DePascali4M(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Mapp\",},{M[8],M[0],T\"is_active_c32_DePascali4M\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c32_DePascali4M_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc32_DePascali4MInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc32_DePascali4MInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DePascali4MMachineNumber_,
           32,
           1,
           1,
           0,
           5,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"G");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Mapp");
          _SFD_SET_DATA_PROPS(2,1,1,0,"M");
          _SFD_SET_DATA_PROPS(3,10,0,0,"m0");
          _SFD_SET_DATA_PROPS(4,10,0,0,"j0");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,88);

        {
          unsigned int dimVector[2];
          dimVector[0]= 6;
          dimVector[1]= 24;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c32_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 6;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c32_sf_marshallOut,(MexInFcnForType)
            c32_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 24;
          dimVector[1]= 24;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c32_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c32_b_sf_marshallOut,(MexInFcnForType)
          c32_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c32_b_sf_marshallOut,(MexInFcnForType)
          c32_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c32_G);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c32_Mapp);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c32_M);
        _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c32_m0);
        _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c32_j0);
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
  return "uRz8o2Wwn2hU5cpcT6jmkG";
}

static void sf_opaque_initialize_c32_DePascali4M(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc32_DePascali4MInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c32_DePascali4M((SFc32_DePascali4MInstanceStruct*)
    chartInstanceVar);
  initialize_c32_DePascali4M((SFc32_DePascali4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c32_DePascali4M(void *chartInstanceVar)
{
  enable_c32_DePascali4M((SFc32_DePascali4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c32_DePascali4M(void *chartInstanceVar)
{
  disable_c32_DePascali4M((SFc32_DePascali4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c32_DePascali4M(void *chartInstanceVar)
{
  sf_gateway_c32_DePascali4M((SFc32_DePascali4MInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c32_DePascali4M(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c32_DePascali4M((SFc32_DePascali4MInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c32_DePascali4M(SimStruct* S, const mxArray *
  st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c32_DePascali4M((SFc32_DePascali4MInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c32_DePascali4M(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc32_DePascali4MInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DePascali4M_optimization_info();
    }

    finalize_c32_DePascali4M((SFc32_DePascali4MInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc32_DePascali4M((SFc32_DePascali4MInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c32_DePascali4M(SimStruct *S)
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
    initialize_params_c32_DePascali4M((SFc32_DePascali4MInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c32_DePascali4M(SimStruct *S)
{
  /* Actual parameters from chart:
     j0 m0
   */
  const char_T *rtParamNames[] = { "j0", "m0" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for j0*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for m0*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DePascali4M_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      32);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,32,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,32,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,32);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,32,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,32,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,32);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2559810969U));
  ssSetChecksum1(S,(663400393U));
  ssSetChecksum2(S,(3027584257U));
  ssSetChecksum3(S,(304417514U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c32_DePascali4M(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c32_DePascali4M(SimStruct *S)
{
  SFc32_DePascali4MInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc32_DePascali4MInstanceStruct *)utMalloc(sizeof
    (SFc32_DePascali4MInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc32_DePascali4MInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c32_DePascali4M;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c32_DePascali4M;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c32_DePascali4M;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c32_DePascali4M;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c32_DePascali4M;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c32_DePascali4M;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c32_DePascali4M;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c32_DePascali4M;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c32_DePascali4M;
  chartInstance->chartInfo.mdlStart = mdlStart_c32_DePascali4M;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c32_DePascali4M;
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

void c32_DePascali4M_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c32_DePascali4M(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c32_DePascali4M(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c32_DePascali4M(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c32_DePascali4M_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

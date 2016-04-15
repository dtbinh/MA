/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DePascali4M_sfun.h"
#include "c23_DePascali4M.h"
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
static const char * c23_debug_family_names[6] = { "nargin", "nargout", "dx_do",
  "r", "x", "b" };

static const char * c23_b_debug_family_names[4] = { "nargin", "nargout", "x",
  "X" };

static const char * c23_c_debug_family_names[6] = { "rwq", "nargin", "nargout",
  "q", "r", "rw" };

/* Function Declarations */
static void initialize_c23_DePascali4M(SFc23_DePascali4MInstanceStruct
  *chartInstance);
static void initialize_params_c23_DePascali4M(SFc23_DePascali4MInstanceStruct
  *chartInstance);
static void enable_c23_DePascali4M(SFc23_DePascali4MInstanceStruct
  *chartInstance);
static void disable_c23_DePascali4M(SFc23_DePascali4MInstanceStruct
  *chartInstance);
static void c23_update_debugger_state_c23_DePascali4M
  (SFc23_DePascali4MInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c23_DePascali4M
  (SFc23_DePascali4MInstanceStruct *chartInstance);
static void set_sim_state_c23_DePascali4M(SFc23_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c23_st);
static void finalize_c23_DePascali4M(SFc23_DePascali4MInstanceStruct
  *chartInstance);
static void sf_gateway_c23_DePascali4M(SFc23_DePascali4MInstanceStruct
  *chartInstance);
static void mdl_start_c23_DePascali4M(SFc23_DePascali4MInstanceStruct
  *chartInstance);
static void c23_chartstep_c23_DePascali4M(SFc23_DePascali4MInstanceStruct
  *chartInstance);
static void initSimStructsc23_DePascali4M(SFc23_DePascali4MInstanceStruct
  *chartInstance);
static void c23_skew_sm(SFc23_DePascali4MInstanceStruct *chartInstance, real_T
  c23_b_x[3], real_T c23_X[9]);
static void c23_quatrot(SFc23_DePascali4MInstanceStruct *chartInstance, real_T
  c23_q[4], real_T c23_b_r[3], real_T c23_rw[3]);
static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber, uint32_T c23_instanceNumber);
static const mxArray *c23_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static void c23_emlrt_marshallIn(SFc23_DePascali4MInstanceStruct *chartInstance,
  const mxArray *c23_b_b, const char_T *c23_identifier, real_T c23_y[24]);
static void c23_b_emlrt_marshallIn(SFc23_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  real_T c23_y[24]);
static void c23_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_b_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static const mxArray *c23_c_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static void c23_c_emlrt_marshallIn(SFc23_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  real_T c23_y[12]);
static void c23_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_d_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static const mxArray *c23_e_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static real_T c23_d_emlrt_marshallIn(SFc23_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_f_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static void c23_e_emlrt_marshallIn(SFc23_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  real_T c23_y[9]);
static void c23_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_g_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static void c23_f_emlrt_marshallIn(SFc23_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  real_T c23_y[3]);
static void c23_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_h_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static void c23_g_emlrt_marshallIn(SFc23_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  real_T c23_y[4]);
static void c23_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static void c23_info_helper(const mxArray **c23_info);
static const mxArray *c23_emlrt_marshallOut(const char * c23_u);
static const mxArray *c23_b_emlrt_marshallOut(const uint32_T c23_u);
static void c23_eml_scalar_eg(SFc23_DePascali4MInstanceStruct *chartInstance);
static void c23_threshold(SFc23_DePascali4MInstanceStruct *chartInstance);
static void c23_quatmultiply(SFc23_DePascali4MInstanceStruct *chartInstance,
  real_T c23_q[4], real_T c23_b_r[4], real_T c23_qout[4]);
static void c23_b_eml_scalar_eg(SFc23_DePascali4MInstanceStruct *chartInstance);
static const mxArray *c23_i_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static int32_T c23_h_emlrt_marshallIn(SFc23_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static uint8_T c23_i_emlrt_marshallIn(SFc23_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c23_b_is_active_c23_DePascali4M, const char_T
  *c23_identifier);
static uint8_T c23_j_emlrt_marshallIn(SFc23_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void init_dsm_address_info(SFc23_DePascali4MInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc23_DePascali4MInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c23_DePascali4M(SFc23_DePascali4MInstanceStruct
  *chartInstance)
{
  chartInstance->c23_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c23_is_active_c23_DePascali4M = 0U;
}

static void initialize_params_c23_DePascali4M(SFc23_DePascali4MInstanceStruct
  *chartInstance)
{
  real_T c23_dv0[12];
  int32_T c23_i0;
  sf_mex_import_named("r", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      c23_dv0, 0, 0, 0U, 1, 0U, 1, 12);
  for (c23_i0 = 0; c23_i0 < 12; c23_i0++) {
    chartInstance->c23_r[c23_i0] = c23_dv0[c23_i0];
  }
}

static void enable_c23_DePascali4M(SFc23_DePascali4MInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c23_DePascali4M(SFc23_DePascali4MInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c23_update_debugger_state_c23_DePascali4M
  (SFc23_DePascali4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c23_DePascali4M
  (SFc23_DePascali4MInstanceStruct *chartInstance)
{
  const mxArray *c23_st;
  const mxArray *c23_y = NULL;
  int32_T c23_i1;
  real_T c23_u[24];
  const mxArray *c23_b_y = NULL;
  uint8_T c23_hoistedGlobal;
  uint8_T c23_b_u;
  const mxArray *c23_c_y = NULL;
  c23_st = NULL;
  c23_st = NULL;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_createcellmatrix(2, 1), false);
  for (c23_i1 = 0; c23_i1 < 24; c23_i1++) {
    c23_u[c23_i1] = (*chartInstance->c23_b)[c23_i1];
  }

  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", c23_u, 0, 0U, 1U, 0U, 1, 24), false);
  sf_mex_setcell(c23_y, 0, c23_b_y);
  c23_hoistedGlobal = chartInstance->c23_is_active_c23_DePascali4M;
  c23_b_u = c23_hoistedGlobal;
  c23_c_y = NULL;
  sf_mex_assign(&c23_c_y, sf_mex_create("y", &c23_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c23_y, 1, c23_c_y);
  sf_mex_assign(&c23_st, c23_y, false);
  return c23_st;
}

static void set_sim_state_c23_DePascali4M(SFc23_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c23_st)
{
  const mxArray *c23_u;
  real_T c23_dv1[24];
  int32_T c23_i2;
  chartInstance->c23_doneDoubleBufferReInit = true;
  c23_u = sf_mex_dup(c23_st);
  c23_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c23_u, 0)), "b",
                       c23_dv1);
  for (c23_i2 = 0; c23_i2 < 24; c23_i2++) {
    (*chartInstance->c23_b)[c23_i2] = c23_dv1[c23_i2];
  }

  chartInstance->c23_is_active_c23_DePascali4M = c23_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c23_u, 1)),
     "is_active_c23_DePascali4M");
  sf_mex_destroy(&c23_u);
  c23_update_debugger_state_c23_DePascali4M(chartInstance);
  sf_mex_destroy(&c23_st);
}

static void finalize_c23_DePascali4M(SFc23_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c23_DePascali4M(SFc23_DePascali4MInstanceStruct
  *chartInstance)
{
  int32_T c23_i3;
  int32_T c23_i4;
  int32_T c23_i5;
  int32_T c23_i6;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c23_sfEvent);
  for (c23_i3 = 0; c23_i3 < 6; c23_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c23_dx_do)[c23_i3], 0U);
  }

  chartInstance->c23_sfEvent = CALL_EVENT;
  c23_chartstep_c23_DePascali4M(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DePascali4MMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c23_i4 = 0; c23_i4 < 24; c23_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c23_b)[c23_i4], 1U);
  }

  for (c23_i5 = 0; c23_i5 < 12; c23_i5++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c23_r[c23_i5], 2U);
  }

  for (c23_i6 = 0; c23_i6 < 28; c23_i6++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c23_x)[c23_i6], 3U);
  }
}

static void mdl_start_c23_DePascali4M(SFc23_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c23_chartstep_c23_DePascali4M(SFc23_DePascali4MInstanceStruct
  *chartInstance)
{
  int32_T c23_i7;
  real_T c23_b_dx_do[6];
  int32_T c23_i8;
  real_T c23_b_r[12];
  int32_T c23_i9;
  real_T c23_b_x[28];
  uint32_T c23_debug_family_var_map[6];
  real_T c23_nargin = 3.0;
  real_T c23_nargout = 1.0;
  real_T c23_b_b[24];
  int32_T c23_i10;
  real_T c23_c_dx_do[3];
  real_T c23_a[9];
  int32_T c23_i11;
  real_T c23_d_dx_do[3];
  real_T c23_c_b[9];
  int32_T c23_i12;
  int32_T c23_i13;
  int32_T c23_i14;
  real_T c23_y[9];
  int32_T c23_i15;
  int32_T c23_i16;
  int32_T c23_i17;
  real_T c23_c_x[4];
  int32_T c23_i18;
  real_T c23_c_r[3];
  real_T c23_d_b[3];
  int32_T c23_i19;
  real_T c23_b_y[3];
  int32_T c23_i20;
  int32_T c23_i21;
  int32_T c23_i22;
  real_T c23_e_dx_do[3];
  int32_T c23_i23;
  real_T c23_f_dx_do[3];
  int32_T c23_i24;
  int32_T c23_i25;
  int32_T c23_i26;
  int32_T c23_i27;
  int32_T c23_i28;
  int32_T c23_i29;
  real_T c23_d_x[4];
  int32_T c23_i30;
  real_T c23_d_r[3];
  int32_T c23_i31;
  real_T c23_c_y[3];
  int32_T c23_i32;
  int32_T c23_i33;
  int32_T c23_i34;
  real_T c23_g_dx_do[3];
  int32_T c23_i35;
  real_T c23_h_dx_do[3];
  int32_T c23_i36;
  int32_T c23_i37;
  int32_T c23_i38;
  int32_T c23_i39;
  int32_T c23_i40;
  int32_T c23_i41;
  real_T c23_e_x[4];
  int32_T c23_i42;
  real_T c23_e_r[3];
  int32_T c23_i43;
  real_T c23_d_y[3];
  int32_T c23_i44;
  int32_T c23_i45;
  int32_T c23_i46;
  real_T c23_f_x[3];
  uint32_T c23_b_debug_family_var_map[4];
  real_T c23_b_nargin = 1.0;
  real_T c23_b_nargout = 1.0;
  real_T c23_X[9];
  int32_T c23_i47;
  real_T c23_g_x[3];
  real_T c23_c_nargin = 1.0;
  real_T c23_c_nargout = 1.0;
  real_T c23_b_X[9];
  int32_T c23_i48;
  int32_T c23_i49;
  int32_T c23_i50;
  int32_T c23_i51;
  int32_T c23_i52;
  int32_T c23_i53;
  int32_T c23_i54;
  int32_T c23_i55;
  real_T c23_h_x[4];
  int32_T c23_i56;
  real_T c23_f_r[3];
  int32_T c23_i57;
  real_T c23_e_y[3];
  int32_T c23_i58;
  int32_T c23_i59;
  int32_T c23_i60;
  int32_T c23_i61;
  int32_T c23_i62;
  int32_T c23_i63;
  int32_T c23_i64;
  int32_T c23_i65;
  int32_T c23_i66;
  int32_T c23_i67;
  int32_T c23_i68;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c23_sfEvent);
  for (c23_i7 = 0; c23_i7 < 6; c23_i7++) {
    c23_b_dx_do[c23_i7] = (*chartInstance->c23_dx_do)[c23_i7];
  }

  for (c23_i8 = 0; c23_i8 < 12; c23_i8++) {
    c23_b_r[c23_i8] = chartInstance->c23_r[c23_i8];
  }

  for (c23_i9 = 0; c23_i9 < 28; c23_i9++) {
    c23_b_x[c23_i9] = (*chartInstance->c23_x)[c23_i9];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c23_debug_family_names,
    c23_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_nargin, 0U, c23_e_sf_marshallOut,
    c23_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_nargout, 1U, c23_e_sf_marshallOut,
    c23_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c23_b_dx_do, 2U, c23_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c23_b_r, 3U, c23_c_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c23_b_x, 4U, c23_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c23_b_b, 5U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 2);
  for (c23_i10 = 0; c23_i10 < 3; c23_i10++) {
    c23_c_dx_do[c23_i10] = c23_b_dx_do[c23_i10 + 3];
  }

  c23_skew_sm(chartInstance, c23_c_dx_do, c23_a);
  for (c23_i11 = 0; c23_i11 < 3; c23_i11++) {
    c23_d_dx_do[c23_i11] = c23_b_dx_do[c23_i11 + 3];
  }

  c23_skew_sm(chartInstance, c23_d_dx_do, c23_c_b);
  c23_eml_scalar_eg(chartInstance);
  c23_eml_scalar_eg(chartInstance);
  c23_threshold(chartInstance);
  for (c23_i12 = 0; c23_i12 < 3; c23_i12++) {
    c23_i13 = 0;
    for (c23_i14 = 0; c23_i14 < 3; c23_i14++) {
      c23_y[c23_i13 + c23_i12] = 0.0;
      c23_i15 = 0;
      for (c23_i16 = 0; c23_i16 < 3; c23_i16++) {
        c23_y[c23_i13 + c23_i12] += c23_a[c23_i15 + c23_i12] * c23_c_b[c23_i16 +
          c23_i13];
        c23_i15 += 3;
      }

      c23_i13 += 3;
    }
  }

  for (c23_i17 = 0; c23_i17 < 4; c23_i17++) {
    c23_c_x[c23_i17] = c23_b_x[c23_i17 + 3];
  }

  for (c23_i18 = 0; c23_i18 < 3; c23_i18++) {
    c23_c_r[c23_i18] = c23_b_r[c23_i18];
  }

  c23_quatrot(chartInstance, c23_c_x, c23_c_r, c23_d_b);
  c23_b_eml_scalar_eg(chartInstance);
  c23_b_eml_scalar_eg(chartInstance);
  c23_threshold(chartInstance);
  for (c23_i19 = 0; c23_i19 < 3; c23_i19++) {
    c23_b_y[c23_i19] = 0.0;
    c23_i20 = 0;
    for (c23_i21 = 0; c23_i21 < 3; c23_i21++) {
      c23_b_y[c23_i19] += c23_y[c23_i20 + c23_i19] * c23_d_b[c23_i21];
      c23_i20 += 3;
    }
  }

  for (c23_i22 = 0; c23_i22 < 3; c23_i22++) {
    c23_e_dx_do[c23_i22] = c23_b_dx_do[c23_i22 + 3];
  }

  c23_skew_sm(chartInstance, c23_e_dx_do, c23_a);
  for (c23_i23 = 0; c23_i23 < 3; c23_i23++) {
    c23_f_dx_do[c23_i23] = c23_b_dx_do[c23_i23 + 3];
  }

  c23_skew_sm(chartInstance, c23_f_dx_do, c23_c_b);
  c23_eml_scalar_eg(chartInstance);
  c23_eml_scalar_eg(chartInstance);
  c23_threshold(chartInstance);
  for (c23_i24 = 0; c23_i24 < 3; c23_i24++) {
    c23_i25 = 0;
    for (c23_i26 = 0; c23_i26 < 3; c23_i26++) {
      c23_y[c23_i25 + c23_i24] = 0.0;
      c23_i27 = 0;
      for (c23_i28 = 0; c23_i28 < 3; c23_i28++) {
        c23_y[c23_i25 + c23_i24] += c23_a[c23_i27 + c23_i24] * c23_c_b[c23_i28 +
          c23_i25];
        c23_i27 += 3;
      }

      c23_i25 += 3;
    }
  }

  for (c23_i29 = 0; c23_i29 < 4; c23_i29++) {
    c23_d_x[c23_i29] = c23_b_x[c23_i29 + 3];
  }

  for (c23_i30 = 0; c23_i30 < 3; c23_i30++) {
    c23_d_r[c23_i30] = c23_b_r[c23_i30 + 3];
  }

  c23_quatrot(chartInstance, c23_d_x, c23_d_r, c23_d_b);
  c23_b_eml_scalar_eg(chartInstance);
  c23_b_eml_scalar_eg(chartInstance);
  c23_threshold(chartInstance);
  for (c23_i31 = 0; c23_i31 < 3; c23_i31++) {
    c23_c_y[c23_i31] = 0.0;
    c23_i32 = 0;
    for (c23_i33 = 0; c23_i33 < 3; c23_i33++) {
      c23_c_y[c23_i31] += c23_y[c23_i32 + c23_i31] * c23_d_b[c23_i33];
      c23_i32 += 3;
    }
  }

  for (c23_i34 = 0; c23_i34 < 3; c23_i34++) {
    c23_g_dx_do[c23_i34] = c23_b_dx_do[c23_i34 + 3];
  }

  c23_skew_sm(chartInstance, c23_g_dx_do, c23_a);
  for (c23_i35 = 0; c23_i35 < 3; c23_i35++) {
    c23_h_dx_do[c23_i35] = c23_b_dx_do[c23_i35 + 3];
  }

  c23_skew_sm(chartInstance, c23_h_dx_do, c23_c_b);
  c23_eml_scalar_eg(chartInstance);
  c23_eml_scalar_eg(chartInstance);
  c23_threshold(chartInstance);
  for (c23_i36 = 0; c23_i36 < 3; c23_i36++) {
    c23_i37 = 0;
    for (c23_i38 = 0; c23_i38 < 3; c23_i38++) {
      c23_y[c23_i37 + c23_i36] = 0.0;
      c23_i39 = 0;
      for (c23_i40 = 0; c23_i40 < 3; c23_i40++) {
        c23_y[c23_i37 + c23_i36] += c23_a[c23_i39 + c23_i36] * c23_c_b[c23_i40 +
          c23_i37];
        c23_i39 += 3;
      }

      c23_i37 += 3;
    }
  }

  for (c23_i41 = 0; c23_i41 < 4; c23_i41++) {
    c23_e_x[c23_i41] = c23_b_x[c23_i41 + 3];
  }

  for (c23_i42 = 0; c23_i42 < 3; c23_i42++) {
    c23_e_r[c23_i42] = c23_b_r[c23_i42 + 6];
  }

  c23_quatrot(chartInstance, c23_e_x, c23_e_r, c23_d_b);
  c23_b_eml_scalar_eg(chartInstance);
  c23_b_eml_scalar_eg(chartInstance);
  c23_threshold(chartInstance);
  for (c23_i43 = 0; c23_i43 < 3; c23_i43++) {
    c23_d_y[c23_i43] = 0.0;
    c23_i44 = 0;
    for (c23_i45 = 0; c23_i45 < 3; c23_i45++) {
      c23_d_y[c23_i43] += c23_y[c23_i44 + c23_i43] * c23_d_b[c23_i45];
      c23_i44 += 3;
    }
  }

  for (c23_i46 = 0; c23_i46 < 3; c23_i46++) {
    c23_f_x[c23_i46] = c23_b_dx_do[c23_i46 + 3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c23_b_debug_family_names,
    c23_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_nargin, 0U, c23_e_sf_marshallOut,
    c23_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_nargout, 1U, c23_e_sf_marshallOut,
    c23_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c23_f_x, 2U, c23_g_sf_marshallOut,
    c23_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c23_X, 3U, c23_f_sf_marshallOut,
    c23_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c23_sfEvent, 3);
  c23_X[0] = 0.0;
  c23_X[3] = -c23_f_x[2];
  c23_X[6] = c23_f_x[1];
  c23_X[1] = c23_f_x[2];
  c23_X[4] = 0.0;
  c23_X[7] = -c23_f_x[0];
  c23_X[2] = -c23_f_x[1];
  c23_X[5] = c23_f_x[0];
  c23_X[8] = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c23_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c23_i47 = 0; c23_i47 < 3; c23_i47++) {
    c23_g_x[c23_i47] = c23_b_dx_do[c23_i47 + 3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c23_b_debug_family_names,
    c23_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_c_nargin, 0U, c23_e_sf_marshallOut,
    c23_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_c_nargout, 1U, c23_e_sf_marshallOut,
    c23_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c23_g_x, 2U, c23_g_sf_marshallOut,
    c23_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c23_b_X, 3U, c23_f_sf_marshallOut,
    c23_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c23_sfEvent, 3);
  c23_b_X[0] = 0.0;
  c23_b_X[3] = -c23_g_x[2];
  c23_b_X[6] = c23_g_x[1];
  c23_b_X[1] = c23_g_x[2];
  c23_b_X[4] = 0.0;
  c23_b_X[7] = -c23_g_x[0];
  c23_b_X[2] = -c23_g_x[1];
  c23_b_X[5] = c23_g_x[0];
  c23_b_X[8] = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c23_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c23_i48 = 0; c23_i48 < 9; c23_i48++) {
    c23_a[c23_i48] = c23_X[c23_i48];
  }

  for (c23_i49 = 0; c23_i49 < 9; c23_i49++) {
    c23_c_b[c23_i49] = c23_b_X[c23_i49];
  }

  c23_eml_scalar_eg(chartInstance);
  c23_eml_scalar_eg(chartInstance);
  c23_threshold(chartInstance);
  for (c23_i50 = 0; c23_i50 < 3; c23_i50++) {
    c23_i51 = 0;
    for (c23_i52 = 0; c23_i52 < 3; c23_i52++) {
      c23_y[c23_i51 + c23_i50] = 0.0;
      c23_i53 = 0;
      for (c23_i54 = 0; c23_i54 < 3; c23_i54++) {
        c23_y[c23_i51 + c23_i50] += c23_a[c23_i53 + c23_i50] * c23_c_b[c23_i54 +
          c23_i51];
        c23_i53 += 3;
      }

      c23_i51 += 3;
    }
  }

  for (c23_i55 = 0; c23_i55 < 4; c23_i55++) {
    c23_h_x[c23_i55] = c23_b_x[c23_i55 + 3];
  }

  for (c23_i56 = 0; c23_i56 < 3; c23_i56++) {
    c23_f_r[c23_i56] = c23_b_r[c23_i56 + 9];
  }

  c23_quatrot(chartInstance, c23_h_x, c23_f_r, c23_d_b);
  c23_b_eml_scalar_eg(chartInstance);
  c23_b_eml_scalar_eg(chartInstance);
  c23_threshold(chartInstance);
  for (c23_i57 = 0; c23_i57 < 3; c23_i57++) {
    c23_e_y[c23_i57] = 0.0;
    c23_i58 = 0;
    for (c23_i59 = 0; c23_i59 < 3; c23_i59++) {
      c23_e_y[c23_i57] += c23_y[c23_i58 + c23_i57] * c23_d_b[c23_i59];
      c23_i58 += 3;
    }
  }

  for (c23_i60 = 0; c23_i60 < 3; c23_i60++) {
    c23_b_b[c23_i60] = c23_b_y[c23_i60];
  }

  for (c23_i61 = 0; c23_i61 < 3; c23_i61++) {
    c23_b_b[c23_i61 + 3] = 0.0;
  }

  for (c23_i62 = 0; c23_i62 < 3; c23_i62++) {
    c23_b_b[c23_i62 + 6] = c23_c_y[c23_i62];
  }

  for (c23_i63 = 0; c23_i63 < 3; c23_i63++) {
    c23_b_b[c23_i63 + 9] = 0.0;
  }

  for (c23_i64 = 0; c23_i64 < 3; c23_i64++) {
    c23_b_b[c23_i64 + 12] = c23_d_y[c23_i64];
  }

  for (c23_i65 = 0; c23_i65 < 3; c23_i65++) {
    c23_b_b[c23_i65 + 15] = 0.0;
  }

  for (c23_i66 = 0; c23_i66 < 3; c23_i66++) {
    c23_b_b[c23_i66 + 18] = c23_e_y[c23_i66];
  }

  for (c23_i67 = 0; c23_i67 < 3; c23_i67++) {
    c23_b_b[c23_i67 + 21] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, -2);
  _SFD_SYMBOL_SCOPE_POP();
  for (c23_i68 = 0; c23_i68 < 24; c23_i68++) {
    (*chartInstance->c23_b)[c23_i68] = c23_b_b[c23_i68];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c23_sfEvent);
}

static void initSimStructsc23_DePascali4M(SFc23_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c23_skew_sm(SFc23_DePascali4MInstanceStruct *chartInstance, real_T
  c23_b_x[3], real_T c23_X[9])
{
  uint32_T c23_debug_family_var_map[4];
  real_T c23_nargin = 1.0;
  real_T c23_nargout = 1.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c23_b_debug_family_names,
    c23_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_nargin, 0U, c23_e_sf_marshallOut,
    c23_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_nargout, 1U, c23_e_sf_marshallOut,
    c23_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c23_b_x, 2U, c23_g_sf_marshallOut,
    c23_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c23_X, 3U, c23_f_sf_marshallOut,
    c23_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c23_sfEvent, 3);
  c23_X[0] = 0.0;
  c23_X[3] = -c23_b_x[2];
  c23_X[6] = c23_b_x[1];
  c23_X[1] = c23_b_x[2];
  c23_X[4] = 0.0;
  c23_X[7] = -c23_b_x[0];
  c23_X[2] = -c23_b_x[1];
  c23_X[5] = c23_b_x[0];
  c23_X[8] = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c23_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c23_quatrot(SFc23_DePascali4MInstanceStruct *chartInstance, real_T
  c23_q[4], real_T c23_b_r[3], real_T c23_rw[3])
{
  uint32_T c23_debug_family_var_map[6];
  real_T c23_rwq[4];
  real_T c23_nargin = 2.0;
  real_T c23_nargout = 1.0;
  int32_T c23_i69;
  real_T c23_b_q[4];
  int32_T c23_k;
  real_T c23_b_k;
  real_T c23_dv2[4];
  int32_T c23_i70;
  int32_T c23_i71;
  real_T c23_c_q[4];
  real_T c23_dv3[4];
  int32_T c23_i72;
  real_T c23_d_q[4];
  int32_T c23_i73;
  real_T c23_dv4[4];
  int32_T c23_i74;
  int32_T c23_i75;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c23_c_debug_family_names,
    c23_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c23_rwq, 0U, c23_h_sf_marshallOut,
    c23_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_nargin, 1U, c23_e_sf_marshallOut,
    c23_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_nargout, 2U, c23_e_sf_marshallOut,
    c23_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c23_q, 3U, c23_h_sf_marshallOut,
    c23_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c23_b_r, 4U, c23_g_sf_marshallOut,
    c23_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c23_rw, 5U, c23_g_sf_marshallOut,
    c23_e_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c23_sfEvent, 4);
  for (c23_i69 = 0; c23_i69 < 4; c23_i69++) {
    c23_b_q[c23_i69] = c23_q[c23_i69];
  }

  for (c23_k = 0; c23_k < 3; c23_k++) {
    c23_b_k = 2.0 + (real_T)c23_k;
    c23_b_q[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c23_b_k), 1, 4, 1, 0) - 1] = -c23_b_q[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", c23_b_k), 1, 4, 1, 0) - 1];
  }

  c23_dv2[0] = 0.0;
  for (c23_i70 = 0; c23_i70 < 3; c23_i70++) {
    c23_dv2[c23_i70 + 1] = c23_b_r[c23_i70];
  }

  for (c23_i71 = 0; c23_i71 < 4; c23_i71++) {
    c23_c_q[c23_i71] = c23_b_q[c23_i71];
  }

  c23_quatmultiply(chartInstance, c23_dv2, c23_c_q, c23_dv3);
  for (c23_i72 = 0; c23_i72 < 4; c23_i72++) {
    c23_d_q[c23_i72] = c23_q[c23_i72];
  }

  for (c23_i73 = 0; c23_i73 < 4; c23_i73++) {
    c23_dv4[c23_i73] = c23_dv3[c23_i73];
  }

  c23_quatmultiply(chartInstance, c23_d_q, c23_dv4, c23_b_q);
  for (c23_i74 = 0; c23_i74 < 4; c23_i74++) {
    c23_rwq[c23_i74] = c23_b_q[c23_i74];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c23_sfEvent, 5);
  for (c23_i75 = 0; c23_i75 < 3; c23_i75++) {
    c23_rw[c23_i75] = c23_rwq[c23_i75 + 1];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c23_sfEvent, -5);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber, uint32_T c23_instanceNumber)
{
  (void)c23_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c23_chartNumber, c23_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Martin\\Documents\\Git\\Simulink\\DIPC - constrained\\skew_sm.m"));
  _SFD_SCRIPT_TRANSLATION(c23_chartNumber, c23_instanceNumber, 1U,
    sf_debug_get_script_id(
    "C:\\Users\\Martin\\Documents\\Git\\Simulink\\DIPC - constrained\\quatrot.m"));
}

static const mxArray *c23_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_i76;
  real_T c23_b_inData[24];
  int32_T c23_i77;
  real_T c23_u[24];
  const mxArray *c23_y = NULL;
  SFc23_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc23_DePascali4MInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  for (c23_i76 = 0; c23_i76 < 24; c23_i76++) {
    c23_b_inData[c23_i76] = (*(real_T (*)[24])c23_inData)[c23_i76];
  }

  for (c23_i77 = 0; c23_i77 < 24; c23_i77++) {
    c23_u[c23_i77] = c23_b_inData[c23_i77];
  }

  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", c23_u, 0, 0U, 1U, 0U, 1, 24), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static void c23_emlrt_marshallIn(SFc23_DePascali4MInstanceStruct *chartInstance,
  const mxArray *c23_b_b, const char_T *c23_identifier, real_T c23_y[24])
{
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_b), &c23_thisId, c23_y);
  sf_mex_destroy(&c23_b_b);
}

static void c23_b_emlrt_marshallIn(SFc23_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  real_T c23_y[24])
{
  real_T c23_dv5[24];
  int32_T c23_i78;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), c23_dv5, 1, 0, 0U, 1, 0U, 1, 24);
  for (c23_i78 = 0; c23_i78 < 24; c23_i78++) {
    c23_y[c23_i78] = c23_dv5[c23_i78];
  }

  sf_mex_destroy(&c23_u);
}

static void c23_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_b_b;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  real_T c23_y[24];
  int32_T c23_i79;
  SFc23_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc23_DePascali4MInstanceStruct *)chartInstanceVoid;
  c23_b_b = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_b), &c23_thisId, c23_y);
  sf_mex_destroy(&c23_b_b);
  for (c23_i79 = 0; c23_i79 < 24; c23_i79++) {
    (*(real_T (*)[24])c23_outData)[c23_i79] = c23_y[c23_i79];
  }

  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_b_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_i80;
  real_T c23_b_inData[28];
  int32_T c23_i81;
  real_T c23_u[28];
  const mxArray *c23_y = NULL;
  SFc23_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc23_DePascali4MInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  for (c23_i80 = 0; c23_i80 < 28; c23_i80++) {
    c23_b_inData[c23_i80] = (*(real_T (*)[28])c23_inData)[c23_i80];
  }

  for (c23_i81 = 0; c23_i81 < 28; c23_i81++) {
    c23_u[c23_i81] = c23_b_inData[c23_i81];
  }

  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", c23_u, 0, 0U, 1U, 0U, 1, 28), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static const mxArray *c23_c_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_i82;
  real_T c23_b_inData[12];
  int32_T c23_i83;
  real_T c23_u[12];
  const mxArray *c23_y = NULL;
  SFc23_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc23_DePascali4MInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  for (c23_i82 = 0; c23_i82 < 12; c23_i82++) {
    c23_b_inData[c23_i82] = (*(real_T (*)[12])c23_inData)[c23_i82];
  }

  for (c23_i83 = 0; c23_i83 < 12; c23_i83++) {
    c23_u[c23_i83] = c23_b_inData[c23_i83];
  }

  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", c23_u, 0, 0U, 1U, 0U, 1, 12), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static void c23_c_emlrt_marshallIn(SFc23_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  real_T c23_y[12])
{
  real_T c23_dv6[12];
  int32_T c23_i84;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), c23_dv6, 1, 0, 0U, 1, 0U, 1, 12);
  for (c23_i84 = 0; c23_i84 < 12; c23_i84++) {
    c23_y[c23_i84] = c23_dv6[c23_i84];
  }

  sf_mex_destroy(&c23_u);
}

static void c23_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_b_r;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  real_T c23_y[12];
  int32_T c23_i85;
  SFc23_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc23_DePascali4MInstanceStruct *)chartInstanceVoid;
  c23_b_r = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_r), &c23_thisId, c23_y);
  sf_mex_destroy(&c23_b_r);
  for (c23_i85 = 0; c23_i85 < 12; c23_i85++) {
    (*(real_T (*)[12])c23_outData)[c23_i85] = c23_y[c23_i85];
  }

  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_d_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_i86;
  real_T c23_b_inData[6];
  int32_T c23_i87;
  real_T c23_u[6];
  const mxArray *c23_y = NULL;
  SFc23_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc23_DePascali4MInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  for (c23_i86 = 0; c23_i86 < 6; c23_i86++) {
    c23_b_inData[c23_i86] = (*(real_T (*)[6])c23_inData)[c23_i86];
  }

  for (c23_i87 = 0; c23_i87 < 6; c23_i87++) {
    c23_u[c23_i87] = c23_b_inData[c23_i87];
  }

  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", c23_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static const mxArray *c23_e_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  real_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc23_DePascali4MInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(real_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static real_T c23_d_emlrt_marshallIn(SFc23_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  real_T c23_y;
  real_T c23_d0;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_d0, 1, 0, 0U, 0, 0U, 0);
  c23_y = c23_d0;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_nargout;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  real_T c23_y;
  SFc23_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc23_DePascali4MInstanceStruct *)chartInstanceVoid;
  c23_nargout = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_nargout),
    &c23_thisId);
  sf_mex_destroy(&c23_nargout);
  *(real_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_f_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_i88;
  int32_T c23_i89;
  int32_T c23_i90;
  real_T c23_b_inData[9];
  int32_T c23_i91;
  int32_T c23_i92;
  int32_T c23_i93;
  real_T c23_u[9];
  const mxArray *c23_y = NULL;
  SFc23_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc23_DePascali4MInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_i88 = 0;
  for (c23_i89 = 0; c23_i89 < 3; c23_i89++) {
    for (c23_i90 = 0; c23_i90 < 3; c23_i90++) {
      c23_b_inData[c23_i90 + c23_i88] = (*(real_T (*)[9])c23_inData)[c23_i90 +
        c23_i88];
    }

    c23_i88 += 3;
  }

  c23_i91 = 0;
  for (c23_i92 = 0; c23_i92 < 3; c23_i92++) {
    for (c23_i93 = 0; c23_i93 < 3; c23_i93++) {
      c23_u[c23_i93 + c23_i91] = c23_b_inData[c23_i93 + c23_i91];
    }

    c23_i91 += 3;
  }

  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", c23_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static void c23_e_emlrt_marshallIn(SFc23_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  real_T c23_y[9])
{
  real_T c23_dv7[9];
  int32_T c23_i94;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), c23_dv7, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c23_i94 = 0; c23_i94 < 9; c23_i94++) {
    c23_y[c23_i94] = c23_dv7[c23_i94];
  }

  sf_mex_destroy(&c23_u);
}

static void c23_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_X;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  real_T c23_y[9];
  int32_T c23_i95;
  int32_T c23_i96;
  int32_T c23_i97;
  SFc23_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc23_DePascali4MInstanceStruct *)chartInstanceVoid;
  c23_X = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_X), &c23_thisId, c23_y);
  sf_mex_destroy(&c23_X);
  c23_i95 = 0;
  for (c23_i96 = 0; c23_i96 < 3; c23_i96++) {
    for (c23_i97 = 0; c23_i97 < 3; c23_i97++) {
      (*(real_T (*)[9])c23_outData)[c23_i97 + c23_i95] = c23_y[c23_i97 + c23_i95];
    }

    c23_i95 += 3;
  }

  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_g_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_i98;
  real_T c23_b_inData[3];
  int32_T c23_i99;
  real_T c23_u[3];
  const mxArray *c23_y = NULL;
  SFc23_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc23_DePascali4MInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  for (c23_i98 = 0; c23_i98 < 3; c23_i98++) {
    c23_b_inData[c23_i98] = (*(real_T (*)[3])c23_inData)[c23_i98];
  }

  for (c23_i99 = 0; c23_i99 < 3; c23_i99++) {
    c23_u[c23_i99] = c23_b_inData[c23_i99];
  }

  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", c23_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static void c23_f_emlrt_marshallIn(SFc23_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  real_T c23_y[3])
{
  real_T c23_dv8[3];
  int32_T c23_i100;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), c23_dv8, 1, 0, 0U, 1, 0U, 1, 3);
  for (c23_i100 = 0; c23_i100 < 3; c23_i100++) {
    c23_y[c23_i100] = c23_dv8[c23_i100];
  }

  sf_mex_destroy(&c23_u);
}

static void c23_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_b_x;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  real_T c23_y[3];
  int32_T c23_i101;
  SFc23_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc23_DePascali4MInstanceStruct *)chartInstanceVoid;
  c23_b_x = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_x), &c23_thisId, c23_y);
  sf_mex_destroy(&c23_b_x);
  for (c23_i101 = 0; c23_i101 < 3; c23_i101++) {
    (*(real_T (*)[3])c23_outData)[c23_i101] = c23_y[c23_i101];
  }

  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_h_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_i102;
  real_T c23_b_inData[4];
  int32_T c23_i103;
  real_T c23_u[4];
  const mxArray *c23_y = NULL;
  SFc23_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc23_DePascali4MInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  for (c23_i102 = 0; c23_i102 < 4; c23_i102++) {
    c23_b_inData[c23_i102] = (*(real_T (*)[4])c23_inData)[c23_i102];
  }

  for (c23_i103 = 0; c23_i103 < 4; c23_i103++) {
    c23_u[c23_i103] = c23_b_inData[c23_i103];
  }

  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", c23_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static void c23_g_emlrt_marshallIn(SFc23_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  real_T c23_y[4])
{
  real_T c23_dv9[4];
  int32_T c23_i104;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), c23_dv9, 1, 0, 0U, 1, 0U, 1, 4);
  for (c23_i104 = 0; c23_i104 < 4; c23_i104++) {
    c23_y[c23_i104] = c23_dv9[c23_i104];
  }

  sf_mex_destroy(&c23_u);
}

static void c23_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_q;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  real_T c23_y[4];
  int32_T c23_i105;
  SFc23_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc23_DePascali4MInstanceStruct *)chartInstanceVoid;
  c23_q = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_q), &c23_thisId, c23_y);
  sf_mex_destroy(&c23_q);
  for (c23_i105 = 0; c23_i105 < 4; c23_i105++) {
    (*(real_T (*)[4])c23_outData)[c23_i105] = c23_y[c23_i105];
  }

  sf_mex_destroy(&c23_mxArrayInData);
}

const mxArray *sf_c23_DePascali4M_get_eml_resolved_functions_info(void)
{
  const mxArray *c23_nameCaptureInfo = NULL;
  c23_nameCaptureInfo = NULL;
  sf_mex_assign(&c23_nameCaptureInfo, sf_mex_createstruct("structure", 2, 25, 1),
                false);
  c23_info_helper(&c23_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c23_nameCaptureInfo);
  return c23_nameCaptureInfo;
}

static void c23_info_helper(const mxArray **c23_info)
{
  const mxArray *c23_rhs0 = NULL;
  const mxArray *c23_lhs0 = NULL;
  const mxArray *c23_rhs1 = NULL;
  const mxArray *c23_lhs1 = NULL;
  const mxArray *c23_rhs2 = NULL;
  const mxArray *c23_lhs2 = NULL;
  const mxArray *c23_rhs3 = NULL;
  const mxArray *c23_lhs3 = NULL;
  const mxArray *c23_rhs4 = NULL;
  const mxArray *c23_lhs4 = NULL;
  const mxArray *c23_rhs5 = NULL;
  const mxArray *c23_lhs5 = NULL;
  const mxArray *c23_rhs6 = NULL;
  const mxArray *c23_lhs6 = NULL;
  const mxArray *c23_rhs7 = NULL;
  const mxArray *c23_lhs7 = NULL;
  const mxArray *c23_rhs8 = NULL;
  const mxArray *c23_lhs8 = NULL;
  const mxArray *c23_rhs9 = NULL;
  const mxArray *c23_lhs9 = NULL;
  const mxArray *c23_rhs10 = NULL;
  const mxArray *c23_lhs10 = NULL;
  const mxArray *c23_rhs11 = NULL;
  const mxArray *c23_lhs11 = NULL;
  const mxArray *c23_rhs12 = NULL;
  const mxArray *c23_lhs12 = NULL;
  const mxArray *c23_rhs13 = NULL;
  const mxArray *c23_lhs13 = NULL;
  const mxArray *c23_rhs14 = NULL;
  const mxArray *c23_lhs14 = NULL;
  const mxArray *c23_rhs15 = NULL;
  const mxArray *c23_lhs15 = NULL;
  const mxArray *c23_rhs16 = NULL;
  const mxArray *c23_lhs16 = NULL;
  const mxArray *c23_rhs17 = NULL;
  const mxArray *c23_lhs17 = NULL;
  const mxArray *c23_rhs18 = NULL;
  const mxArray *c23_lhs18 = NULL;
  const mxArray *c23_rhs19 = NULL;
  const mxArray *c23_lhs19 = NULL;
  const mxArray *c23_rhs20 = NULL;
  const mxArray *c23_lhs20 = NULL;
  const mxArray *c23_rhs21 = NULL;
  const mxArray *c23_lhs21 = NULL;
  const mxArray *c23_rhs22 = NULL;
  const mxArray *c23_lhs22 = NULL;
  const mxArray *c23_rhs23 = NULL;
  const mxArray *c23_lhs23 = NULL;
  const mxArray *c23_rhs24 = NULL;
  const mxArray *c23_lhs24 = NULL;
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("skew_sm"), "name", "name", 0);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DIPC - constrained/skew_sm.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1445505143U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c23_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 1);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1383902494U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c23_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 2);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c23_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 3);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 3);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c23_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 4);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 4);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c23_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 5);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c23_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  6);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1376005890U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c23_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 7);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c23_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 8);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c23_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 9);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 9);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c23_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 10);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 10);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c23_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 11);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 11);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c23_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 12);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 12);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c23_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 13);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 13);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c23_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(""), "context", "context", 14);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("quatrot"), "name", "name",
                  14);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DIPC - constrained/quatrot.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1446631716U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c23_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DIPC - constrained/quatrot.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("quatconj"), "name", "name",
                  15);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatconj.p"), "resolved", "resolved",
                  15);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1410808258U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c23_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DIPC - constrained/quatrot.m"),
                  "context", "context", 16);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("quatmultiply"), "name",
                  "name", 16);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatmultiply.p"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1410808258U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c23_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatmultiply.p"), "context",
                  "context", 17);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("max"), "name", "name", 17);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1311280516U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c23_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 18);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1378321184U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c23_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 19);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 19);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c23_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 20);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 20);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c23_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 21);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 21);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c23_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 22);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 22);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c23_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 23);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 23);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c23_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 24);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 24);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c23_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs24), "lhs", "lhs",
                  24);
  sf_mex_destroy(&c23_rhs0);
  sf_mex_destroy(&c23_lhs0);
  sf_mex_destroy(&c23_rhs1);
  sf_mex_destroy(&c23_lhs1);
  sf_mex_destroy(&c23_rhs2);
  sf_mex_destroy(&c23_lhs2);
  sf_mex_destroy(&c23_rhs3);
  sf_mex_destroy(&c23_lhs3);
  sf_mex_destroy(&c23_rhs4);
  sf_mex_destroy(&c23_lhs4);
  sf_mex_destroy(&c23_rhs5);
  sf_mex_destroy(&c23_lhs5);
  sf_mex_destroy(&c23_rhs6);
  sf_mex_destroy(&c23_lhs6);
  sf_mex_destroy(&c23_rhs7);
  sf_mex_destroy(&c23_lhs7);
  sf_mex_destroy(&c23_rhs8);
  sf_mex_destroy(&c23_lhs8);
  sf_mex_destroy(&c23_rhs9);
  sf_mex_destroy(&c23_lhs9);
  sf_mex_destroy(&c23_rhs10);
  sf_mex_destroy(&c23_lhs10);
  sf_mex_destroy(&c23_rhs11);
  sf_mex_destroy(&c23_lhs11);
  sf_mex_destroy(&c23_rhs12);
  sf_mex_destroy(&c23_lhs12);
  sf_mex_destroy(&c23_rhs13);
  sf_mex_destroy(&c23_lhs13);
  sf_mex_destroy(&c23_rhs14);
  sf_mex_destroy(&c23_lhs14);
  sf_mex_destroy(&c23_rhs15);
  sf_mex_destroy(&c23_lhs15);
  sf_mex_destroy(&c23_rhs16);
  sf_mex_destroy(&c23_lhs16);
  sf_mex_destroy(&c23_rhs17);
  sf_mex_destroy(&c23_lhs17);
  sf_mex_destroy(&c23_rhs18);
  sf_mex_destroy(&c23_lhs18);
  sf_mex_destroy(&c23_rhs19);
  sf_mex_destroy(&c23_lhs19);
  sf_mex_destroy(&c23_rhs20);
  sf_mex_destroy(&c23_lhs20);
  sf_mex_destroy(&c23_rhs21);
  sf_mex_destroy(&c23_lhs21);
  sf_mex_destroy(&c23_rhs22);
  sf_mex_destroy(&c23_lhs22);
  sf_mex_destroy(&c23_rhs23);
  sf_mex_destroy(&c23_lhs23);
  sf_mex_destroy(&c23_rhs24);
  sf_mex_destroy(&c23_lhs24);
}

static const mxArray *c23_emlrt_marshallOut(const char * c23_u)
{
  const mxArray *c23_y = NULL;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", c23_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c23_u)), false);
  return c23_y;
}

static const mxArray *c23_b_emlrt_marshallOut(const uint32_T c23_u)
{
  const mxArray *c23_y = NULL;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 7, 0U, 0U, 0U, 0), false);
  return c23_y;
}

static void c23_eml_scalar_eg(SFc23_DePascali4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c23_threshold(SFc23_DePascali4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c23_quatmultiply(SFc23_DePascali4MInstanceStruct *chartInstance,
  real_T c23_q[4], real_T c23_b_r[4], real_T c23_qout[4])
{
  real_T c23_q1;
  real_T c23_q2;
  real_T c23_q3;
  real_T c23_q4;
  real_T c23_r1;
  real_T c23_r2;
  real_T c23_r3;
  real_T c23_r4;
  (void)chartInstance;
  c23_q1 = c23_q[0];
  c23_q2 = c23_q[1];
  c23_q3 = c23_q[2];
  c23_q4 = c23_q[3];
  c23_r1 = c23_b_r[0];
  c23_r2 = c23_b_r[1];
  c23_r3 = c23_b_r[2];
  c23_r4 = c23_b_r[3];
  c23_qout[0] = ((c23_q1 * c23_r1 - c23_q2 * c23_r2) - c23_q3 * c23_r3) - c23_q4
    * c23_r4;
  c23_qout[1] = (c23_q1 * c23_r2 + c23_r1 * c23_q2) + (c23_q3 * c23_r4 - c23_q4 *
    c23_r3);
  c23_qout[2] = (c23_q1 * c23_r3 + c23_r1 * c23_q3) + (c23_q4 * c23_r2 - c23_q2 *
    c23_r4);
  c23_qout[3] = (c23_q1 * c23_r4 + c23_r1 * c23_q4) + (c23_q2 * c23_r3 - c23_q3 *
    c23_r2);
}

static void c23_b_eml_scalar_eg(SFc23_DePascali4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *c23_i_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc23_DePascali4MInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(int32_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static int32_T c23_h_emlrt_marshallIn(SFc23_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  int32_T c23_y;
  int32_T c23_i106;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_i106, 1, 6, 0U, 0, 0U, 0);
  c23_y = c23_i106;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_b_sfEvent;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  int32_T c23_y;
  SFc23_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc23_DePascali4MInstanceStruct *)chartInstanceVoid;
  c23_b_sfEvent = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_sfEvent),
    &c23_thisId);
  sf_mex_destroy(&c23_b_sfEvent);
  *(int32_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static uint8_T c23_i_emlrt_marshallIn(SFc23_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c23_b_is_active_c23_DePascali4M, const char_T
  *c23_identifier)
{
  uint8_T c23_y;
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c23_b_is_active_c23_DePascali4M), &c23_thisId);
  sf_mex_destroy(&c23_b_is_active_c23_DePascali4M);
  return c23_y;
}

static uint8_T c23_j_emlrt_marshallIn(SFc23_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  uint8_T c23_y;
  uint8_T c23_u0;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_u0, 1, 3, 0U, 0, 0U, 0);
  c23_y = c23_u0;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void init_dsm_address_info(SFc23_DePascali4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc23_DePascali4MInstanceStruct
  *chartInstance)
{
  chartInstance->c23_dx_do = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c23_b = (real_T (*)[24])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c23_x = (real_T (*)[28])ssGetInputPortSignal_wrapper
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

void sf_c23_DePascali4M_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3694291409U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2310969651U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(782441100U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4253247403U);
}

mxArray* sf_c23_DePascali4M_get_post_codegen_info(void);
mxArray *sf_c23_DePascali4M_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("GlfztGmXSk9HxHD4f6bw8");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxArray* mxPostCodegenInfo = sf_c23_DePascali4M_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c23_DePascali4M_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c23_DePascali4M_jit_fallback_info(void)
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

mxArray *sf_c23_DePascali4M_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c23_DePascali4M_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c23_DePascali4M(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"b\",},{M[8],M[0],T\"is_active_c23_DePascali4M\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c23_DePascali4M_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc23_DePascali4MInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc23_DePascali4MInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DePascali4MMachineNumber_,
           23,
           1,
           1,
           0,
           4,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"dx_do");
          _SFD_SET_DATA_PROPS(1,2,0,1,"b");
          _SFD_SET_DATA_PROPS(2,10,0,0,"r");
          _SFD_SET_DATA_PROPS(3,1,1,0,"x");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,387);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"skew_sm",0,-1,127);
        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"quatrot",0,-1,191);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c23_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 24;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c23_sf_marshallOut,(MexInFcnForType)
            c23_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c23_c_sf_marshallOut,(MexInFcnForType)
            c23_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 28;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c23_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c23_dx_do);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c23_b);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c23_r);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c23_x);
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
  return "CDeSXRTFuIUIKFya1XyhUB";
}

static void sf_opaque_initialize_c23_DePascali4M(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc23_DePascali4MInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c23_DePascali4M((SFc23_DePascali4MInstanceStruct*)
    chartInstanceVar);
  initialize_c23_DePascali4M((SFc23_DePascali4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c23_DePascali4M(void *chartInstanceVar)
{
  enable_c23_DePascali4M((SFc23_DePascali4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c23_DePascali4M(void *chartInstanceVar)
{
  disable_c23_DePascali4M((SFc23_DePascali4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c23_DePascali4M(void *chartInstanceVar)
{
  sf_gateway_c23_DePascali4M((SFc23_DePascali4MInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c23_DePascali4M(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c23_DePascali4M((SFc23_DePascali4MInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c23_DePascali4M(SimStruct* S, const mxArray *
  st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c23_DePascali4M((SFc23_DePascali4MInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c23_DePascali4M(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc23_DePascali4MInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DePascali4M_optimization_info();
    }

    finalize_c23_DePascali4M((SFc23_DePascali4MInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc23_DePascali4M((SFc23_DePascali4MInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c23_DePascali4M(SimStruct *S)
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
    initialize_params_c23_DePascali4M((SFc23_DePascali4MInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c23_DePascali4M(SimStruct *S)
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
      23);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,23,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,23,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,23);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,23,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,23,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,23);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2563359800U));
  ssSetChecksum1(S,(3828046720U));
  ssSetChecksum2(S,(2630102277U));
  ssSetChecksum3(S,(3665733951U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c23_DePascali4M(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c23_DePascali4M(SimStruct *S)
{
  SFc23_DePascali4MInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc23_DePascali4MInstanceStruct *)utMalloc(sizeof
    (SFc23_DePascali4MInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc23_DePascali4MInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c23_DePascali4M;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c23_DePascali4M;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c23_DePascali4M;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c23_DePascali4M;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c23_DePascali4M;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c23_DePascali4M;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c23_DePascali4M;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c23_DePascali4M;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c23_DePascali4M;
  chartInstance->chartInfo.mdlStart = mdlStart_c23_DePascali4M;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c23_DePascali4M;
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

void c23_DePascali4M_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c23_DePascali4M(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c23_DePascali4M(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c23_DePascali4M(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c23_DePascali4M_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

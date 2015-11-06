/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DePascali4M_sfun.h"
#include "c35_DePascali4M.h"
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
static const char * c35_debug_family_names[6] = { "nargin", "nargout", "dx", "r",
  "x", "b" };

static const char * c35_b_debug_family_names[4] = { "nargin", "nargout", "x",
  "X" };

static const char * c35_c_debug_family_names[6] = { "rwq", "nargin", "nargout",
  "q", "r", "rw" };

/* Function Declarations */
static void initialize_c35_DePascali4M(SFc35_DePascali4MInstanceStruct
  *chartInstance);
static void initialize_params_c35_DePascali4M(SFc35_DePascali4MInstanceStruct
  *chartInstance);
static void enable_c35_DePascali4M(SFc35_DePascali4MInstanceStruct
  *chartInstance);
static void disable_c35_DePascali4M(SFc35_DePascali4MInstanceStruct
  *chartInstance);
static void c35_update_debugger_state_c35_DePascali4M
  (SFc35_DePascali4MInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c35_DePascali4M
  (SFc35_DePascali4MInstanceStruct *chartInstance);
static void set_sim_state_c35_DePascali4M(SFc35_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c35_st);
static void finalize_c35_DePascali4M(SFc35_DePascali4MInstanceStruct
  *chartInstance);
static void sf_gateway_c35_DePascali4M(SFc35_DePascali4MInstanceStruct
  *chartInstance);
static void mdl_start_c35_DePascali4M(SFc35_DePascali4MInstanceStruct
  *chartInstance);
static void c35_chartstep_c35_DePascali4M(SFc35_DePascali4MInstanceStruct
  *chartInstance);
static void initSimStructsc35_DePascali4M(SFc35_DePascali4MInstanceStruct
  *chartInstance);
static void c35_skew_sm(SFc35_DePascali4MInstanceStruct *chartInstance, real_T
  c35_b_x[3], real_T c35_X[9]);
static void c35_quatrot(SFc35_DePascali4MInstanceStruct *chartInstance, real_T
  c35_q[4], real_T c35_b_r[3], real_T c35_rw[3]);
static void init_script_number_translation(uint32_T c35_machineNumber, uint32_T
  c35_chartNumber, uint32_T c35_instanceNumber);
static const mxArray *c35_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static void c35_emlrt_marshallIn(SFc35_DePascali4MInstanceStruct *chartInstance,
  const mxArray *c35_b_b, const char_T *c35_identifier, real_T c35_y[24]);
static void c35_b_emlrt_marshallIn(SFc35_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId,
  real_T c35_y[24]);
static void c35_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static const mxArray *c35_b_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static const mxArray *c35_c_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static void c35_c_emlrt_marshallIn(SFc35_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId,
  real_T c35_y[12]);
static void c35_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static const mxArray *c35_d_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static real_T c35_d_emlrt_marshallIn(SFc35_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId);
static void c35_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static const mxArray *c35_e_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static void c35_e_emlrt_marshallIn(SFc35_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId,
  real_T c35_y[9]);
static void c35_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static const mxArray *c35_f_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static void c35_f_emlrt_marshallIn(SFc35_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId,
  real_T c35_y[3]);
static void c35_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static const mxArray *c35_g_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static void c35_g_emlrt_marshallIn(SFc35_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId,
  real_T c35_y[4]);
static void c35_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static void c35_info_helper(const mxArray **c35_info);
static const mxArray *c35_emlrt_marshallOut(const char * c35_u);
static const mxArray *c35_b_emlrt_marshallOut(const uint32_T c35_u);
static void c35_eml_scalar_eg(SFc35_DePascali4MInstanceStruct *chartInstance);
static void c35_threshold(SFc35_DePascali4MInstanceStruct *chartInstance);
static void c35_quatmultiply(SFc35_DePascali4MInstanceStruct *chartInstance,
  real_T c35_q[4], real_T c35_b_r[4], real_T c35_qout[4]);
static void c35_b_eml_scalar_eg(SFc35_DePascali4MInstanceStruct *chartInstance);
static const mxArray *c35_h_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static int32_T c35_h_emlrt_marshallIn(SFc35_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId);
static void c35_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static uint8_T c35_i_emlrt_marshallIn(SFc35_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c35_b_is_active_c35_DePascali4M, const char_T
  *c35_identifier);
static uint8_T c35_j_emlrt_marshallIn(SFc35_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId);
static void init_dsm_address_info(SFc35_DePascali4MInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc35_DePascali4MInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c35_DePascali4M(SFc35_DePascali4MInstanceStruct
  *chartInstance)
{
  chartInstance->c35_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c35_is_active_c35_DePascali4M = 0U;
}

static void initialize_params_c35_DePascali4M(SFc35_DePascali4MInstanceStruct
  *chartInstance)
{
  real_T c35_dv0[12];
  int32_T c35_i0;
  sf_mex_import_named("r", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      c35_dv0, 0, 0, 0U, 1, 0U, 1, 12);
  for (c35_i0 = 0; c35_i0 < 12; c35_i0++) {
    chartInstance->c35_r[c35_i0] = c35_dv0[c35_i0];
  }
}

static void enable_c35_DePascali4M(SFc35_DePascali4MInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c35_DePascali4M(SFc35_DePascali4MInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c35_update_debugger_state_c35_DePascali4M
  (SFc35_DePascali4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c35_DePascali4M
  (SFc35_DePascali4MInstanceStruct *chartInstance)
{
  const mxArray *c35_st;
  const mxArray *c35_y = NULL;
  int32_T c35_i1;
  real_T c35_u[24];
  const mxArray *c35_b_y = NULL;
  uint8_T c35_hoistedGlobal;
  uint8_T c35_b_u;
  const mxArray *c35_c_y = NULL;
  c35_st = NULL;
  c35_st = NULL;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_createcellmatrix(2, 1), false);
  for (c35_i1 = 0; c35_i1 < 24; c35_i1++) {
    c35_u[c35_i1] = (*chartInstance->c35_b)[c35_i1];
  }

  c35_b_y = NULL;
  sf_mex_assign(&c35_b_y, sf_mex_create("y", c35_u, 0, 0U, 1U, 0U, 1, 24), false);
  sf_mex_setcell(c35_y, 0, c35_b_y);
  c35_hoistedGlobal = chartInstance->c35_is_active_c35_DePascali4M;
  c35_b_u = c35_hoistedGlobal;
  c35_c_y = NULL;
  sf_mex_assign(&c35_c_y, sf_mex_create("y", &c35_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c35_y, 1, c35_c_y);
  sf_mex_assign(&c35_st, c35_y, false);
  return c35_st;
}

static void set_sim_state_c35_DePascali4M(SFc35_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c35_st)
{
  const mxArray *c35_u;
  real_T c35_dv1[24];
  int32_T c35_i2;
  chartInstance->c35_doneDoubleBufferReInit = true;
  c35_u = sf_mex_dup(c35_st);
  c35_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c35_u, 0)), "b",
                       c35_dv1);
  for (c35_i2 = 0; c35_i2 < 24; c35_i2++) {
    (*chartInstance->c35_b)[c35_i2] = c35_dv1[c35_i2];
  }

  chartInstance->c35_is_active_c35_DePascali4M = c35_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c35_u, 1)),
     "is_active_c35_DePascali4M");
  sf_mex_destroy(&c35_u);
  c35_update_debugger_state_c35_DePascali4M(chartInstance);
  sf_mex_destroy(&c35_st);
}

static void finalize_c35_DePascali4M(SFc35_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c35_DePascali4M(SFc35_DePascali4MInstanceStruct
  *chartInstance)
{
  int32_T c35_i3;
  int32_T c35_i4;
  int32_T c35_i5;
  int32_T c35_i6;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 15U, chartInstance->c35_sfEvent);
  for (c35_i3 = 0; c35_i3 < 24; c35_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c35_dx)[c35_i3], 0U);
  }

  chartInstance->c35_sfEvent = CALL_EVENT;
  c35_chartstep_c35_DePascali4M(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DePascali4MMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c35_i4 = 0; c35_i4 < 24; c35_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c35_b)[c35_i4], 1U);
  }

  for (c35_i5 = 0; c35_i5 < 12; c35_i5++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c35_r[c35_i5], 2U);
  }

  for (c35_i6 = 0; c35_i6 < 28; c35_i6++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c35_x)[c35_i6], 3U);
  }
}

static void mdl_start_c35_DePascali4M(SFc35_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c35_chartstep_c35_DePascali4M(SFc35_DePascali4MInstanceStruct
  *chartInstance)
{
  int32_T c35_i7;
  real_T c35_b_dx[24];
  int32_T c35_i8;
  real_T c35_b_r[12];
  int32_T c35_i9;
  real_T c35_b_x[28];
  uint32_T c35_debug_family_var_map[6];
  real_T c35_nargin = 3.0;
  real_T c35_nargout = 1.0;
  real_T c35_b_b[24];
  int32_T c35_i10;
  real_T c35_c_dx[3];
  real_T c35_a[9];
  int32_T c35_i11;
  real_T c35_d_dx[3];
  real_T c35_c_b[9];
  int32_T c35_i12;
  int32_T c35_i13;
  int32_T c35_i14;
  real_T c35_y[9];
  int32_T c35_i15;
  int32_T c35_i16;
  int32_T c35_i17;
  real_T c35_c_x[4];
  int32_T c35_i18;
  real_T c35_c_r[3];
  real_T c35_d_b[3];
  int32_T c35_i19;
  real_T c35_b_y[3];
  int32_T c35_i20;
  int32_T c35_i21;
  int32_T c35_i22;
  real_T c35_e_dx[3];
  int32_T c35_i23;
  real_T c35_f_dx[3];
  int32_T c35_i24;
  int32_T c35_i25;
  int32_T c35_i26;
  int32_T c35_i27;
  int32_T c35_i28;
  int32_T c35_i29;
  real_T c35_d_x[4];
  int32_T c35_i30;
  real_T c35_d_r[3];
  int32_T c35_i31;
  real_T c35_c_y[3];
  int32_T c35_i32;
  int32_T c35_i33;
  int32_T c35_i34;
  real_T c35_g_dx[3];
  int32_T c35_i35;
  real_T c35_h_dx[3];
  int32_T c35_i36;
  int32_T c35_i37;
  int32_T c35_i38;
  int32_T c35_i39;
  int32_T c35_i40;
  int32_T c35_i41;
  real_T c35_e_x[4];
  int32_T c35_i42;
  real_T c35_e_r[3];
  int32_T c35_i43;
  real_T c35_d_y[3];
  int32_T c35_i44;
  int32_T c35_i45;
  int32_T c35_i46;
  real_T c35_f_x[3];
  uint32_T c35_b_debug_family_var_map[4];
  real_T c35_b_nargin = 1.0;
  real_T c35_b_nargout = 1.0;
  real_T c35_X[9];
  int32_T c35_i47;
  real_T c35_g_x[3];
  real_T c35_c_nargin = 1.0;
  real_T c35_c_nargout = 1.0;
  real_T c35_b_X[9];
  int32_T c35_i48;
  int32_T c35_i49;
  int32_T c35_i50;
  int32_T c35_i51;
  int32_T c35_i52;
  int32_T c35_i53;
  int32_T c35_i54;
  int32_T c35_i55;
  real_T c35_h_x[4];
  int32_T c35_i56;
  real_T c35_f_r[3];
  int32_T c35_i57;
  real_T c35_e_y[3];
  int32_T c35_i58;
  int32_T c35_i59;
  int32_T c35_i60;
  int32_T c35_i61;
  int32_T c35_i62;
  int32_T c35_i63;
  int32_T c35_i64;
  int32_T c35_i65;
  int32_T c35_i66;
  int32_T c35_i67;
  int32_T c35_i68;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 15U, chartInstance->c35_sfEvent);
  for (c35_i7 = 0; c35_i7 < 24; c35_i7++) {
    c35_b_dx[c35_i7] = (*chartInstance->c35_dx)[c35_i7];
  }

  for (c35_i8 = 0; c35_i8 < 12; c35_i8++) {
    c35_b_r[c35_i8] = chartInstance->c35_r[c35_i8];
  }

  for (c35_i9 = 0; c35_i9 < 28; c35_i9++) {
    c35_b_x[c35_i9] = (*chartInstance->c35_x)[c35_i9];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c35_debug_family_names,
    c35_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_nargin, 0U, c35_d_sf_marshallOut,
    c35_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_nargout, 1U, c35_d_sf_marshallOut,
    c35_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c35_b_dx, 2U, c35_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c35_b_r, 3U, c35_c_sf_marshallOut,
    c35_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c35_b_x, 4U, c35_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c35_b_b, 5U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 2);
  for (c35_i10 = 0; c35_i10 < 3; c35_i10++) {
    c35_c_dx[c35_i10] = c35_b_dx[c35_i10 + 3];
  }

  c35_skew_sm(chartInstance, c35_c_dx, c35_a);
  for (c35_i11 = 0; c35_i11 < 3; c35_i11++) {
    c35_d_dx[c35_i11] = c35_b_dx[c35_i11 + 3];
  }

  c35_skew_sm(chartInstance, c35_d_dx, c35_c_b);
  c35_eml_scalar_eg(chartInstance);
  c35_eml_scalar_eg(chartInstance);
  c35_threshold(chartInstance);
  for (c35_i12 = 0; c35_i12 < 3; c35_i12++) {
    c35_i13 = 0;
    for (c35_i14 = 0; c35_i14 < 3; c35_i14++) {
      c35_y[c35_i13 + c35_i12] = 0.0;
      c35_i15 = 0;
      for (c35_i16 = 0; c35_i16 < 3; c35_i16++) {
        c35_y[c35_i13 + c35_i12] += c35_a[c35_i15 + c35_i12] * c35_c_b[c35_i16 +
          c35_i13];
        c35_i15 += 3;
      }

      c35_i13 += 3;
    }
  }

  for (c35_i17 = 0; c35_i17 < 4; c35_i17++) {
    c35_c_x[c35_i17] = c35_b_x[c35_i17 + 3];
  }

  for (c35_i18 = 0; c35_i18 < 3; c35_i18++) {
    c35_c_r[c35_i18] = c35_b_r[c35_i18];
  }

  c35_quatrot(chartInstance, c35_c_x, c35_c_r, c35_d_b);
  c35_b_eml_scalar_eg(chartInstance);
  c35_b_eml_scalar_eg(chartInstance);
  c35_threshold(chartInstance);
  for (c35_i19 = 0; c35_i19 < 3; c35_i19++) {
    c35_b_y[c35_i19] = 0.0;
    c35_i20 = 0;
    for (c35_i21 = 0; c35_i21 < 3; c35_i21++) {
      c35_b_y[c35_i19] += c35_y[c35_i20 + c35_i19] * c35_d_b[c35_i21];
      c35_i20 += 3;
    }
  }

  for (c35_i22 = 0; c35_i22 < 3; c35_i22++) {
    c35_e_dx[c35_i22] = c35_b_dx[c35_i22 + 3];
  }

  c35_skew_sm(chartInstance, c35_e_dx, c35_a);
  for (c35_i23 = 0; c35_i23 < 3; c35_i23++) {
    c35_f_dx[c35_i23] = c35_b_dx[c35_i23 + 3];
  }

  c35_skew_sm(chartInstance, c35_f_dx, c35_c_b);
  c35_eml_scalar_eg(chartInstance);
  c35_eml_scalar_eg(chartInstance);
  c35_threshold(chartInstance);
  for (c35_i24 = 0; c35_i24 < 3; c35_i24++) {
    c35_i25 = 0;
    for (c35_i26 = 0; c35_i26 < 3; c35_i26++) {
      c35_y[c35_i25 + c35_i24] = 0.0;
      c35_i27 = 0;
      for (c35_i28 = 0; c35_i28 < 3; c35_i28++) {
        c35_y[c35_i25 + c35_i24] += c35_a[c35_i27 + c35_i24] * c35_c_b[c35_i28 +
          c35_i25];
        c35_i27 += 3;
      }

      c35_i25 += 3;
    }
  }

  for (c35_i29 = 0; c35_i29 < 4; c35_i29++) {
    c35_d_x[c35_i29] = c35_b_x[c35_i29 + 3];
  }

  for (c35_i30 = 0; c35_i30 < 3; c35_i30++) {
    c35_d_r[c35_i30] = c35_b_r[c35_i30 + 3];
  }

  c35_quatrot(chartInstance, c35_d_x, c35_d_r, c35_d_b);
  c35_b_eml_scalar_eg(chartInstance);
  c35_b_eml_scalar_eg(chartInstance);
  c35_threshold(chartInstance);
  for (c35_i31 = 0; c35_i31 < 3; c35_i31++) {
    c35_c_y[c35_i31] = 0.0;
    c35_i32 = 0;
    for (c35_i33 = 0; c35_i33 < 3; c35_i33++) {
      c35_c_y[c35_i31] += c35_y[c35_i32 + c35_i31] * c35_d_b[c35_i33];
      c35_i32 += 3;
    }
  }

  for (c35_i34 = 0; c35_i34 < 3; c35_i34++) {
    c35_g_dx[c35_i34] = c35_b_dx[c35_i34 + 3];
  }

  c35_skew_sm(chartInstance, c35_g_dx, c35_a);
  for (c35_i35 = 0; c35_i35 < 3; c35_i35++) {
    c35_h_dx[c35_i35] = c35_b_dx[c35_i35 + 3];
  }

  c35_skew_sm(chartInstance, c35_h_dx, c35_c_b);
  c35_eml_scalar_eg(chartInstance);
  c35_eml_scalar_eg(chartInstance);
  c35_threshold(chartInstance);
  for (c35_i36 = 0; c35_i36 < 3; c35_i36++) {
    c35_i37 = 0;
    for (c35_i38 = 0; c35_i38 < 3; c35_i38++) {
      c35_y[c35_i37 + c35_i36] = 0.0;
      c35_i39 = 0;
      for (c35_i40 = 0; c35_i40 < 3; c35_i40++) {
        c35_y[c35_i37 + c35_i36] += c35_a[c35_i39 + c35_i36] * c35_c_b[c35_i40 +
          c35_i37];
        c35_i39 += 3;
      }

      c35_i37 += 3;
    }
  }

  for (c35_i41 = 0; c35_i41 < 4; c35_i41++) {
    c35_e_x[c35_i41] = c35_b_x[c35_i41 + 3];
  }

  for (c35_i42 = 0; c35_i42 < 3; c35_i42++) {
    c35_e_r[c35_i42] = c35_b_r[c35_i42 + 6];
  }

  c35_quatrot(chartInstance, c35_e_x, c35_e_r, c35_d_b);
  c35_b_eml_scalar_eg(chartInstance);
  c35_b_eml_scalar_eg(chartInstance);
  c35_threshold(chartInstance);
  for (c35_i43 = 0; c35_i43 < 3; c35_i43++) {
    c35_d_y[c35_i43] = 0.0;
    c35_i44 = 0;
    for (c35_i45 = 0; c35_i45 < 3; c35_i45++) {
      c35_d_y[c35_i43] += c35_y[c35_i44 + c35_i43] * c35_d_b[c35_i45];
      c35_i44 += 3;
    }
  }

  for (c35_i46 = 0; c35_i46 < 3; c35_i46++) {
    c35_f_x[c35_i46] = c35_b_dx[c35_i46 + 3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c35_b_debug_family_names,
    c35_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_b_nargin, 0U, c35_d_sf_marshallOut,
    c35_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_b_nargout, 1U, c35_d_sf_marshallOut,
    c35_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c35_f_x, 2U, c35_f_sf_marshallOut,
    c35_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c35_X, 3U, c35_e_sf_marshallOut,
    c35_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c35_sfEvent, 3);
  c35_X[0] = 0.0;
  c35_X[3] = -c35_f_x[2];
  c35_X[6] = c35_f_x[1];
  c35_X[1] = c35_f_x[2];
  c35_X[4] = 0.0;
  c35_X[7] = -c35_f_x[0];
  c35_X[2] = -c35_f_x[1];
  c35_X[5] = c35_f_x[0];
  c35_X[8] = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c35_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c35_i47 = 0; c35_i47 < 3; c35_i47++) {
    c35_g_x[c35_i47] = c35_b_dx[c35_i47 + 3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c35_b_debug_family_names,
    c35_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_c_nargin, 0U, c35_d_sf_marshallOut,
    c35_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_c_nargout, 1U, c35_d_sf_marshallOut,
    c35_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c35_g_x, 2U, c35_f_sf_marshallOut,
    c35_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c35_b_X, 3U, c35_e_sf_marshallOut,
    c35_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c35_sfEvent, 3);
  c35_b_X[0] = 0.0;
  c35_b_X[3] = -c35_g_x[2];
  c35_b_X[6] = c35_g_x[1];
  c35_b_X[1] = c35_g_x[2];
  c35_b_X[4] = 0.0;
  c35_b_X[7] = -c35_g_x[0];
  c35_b_X[2] = -c35_g_x[1];
  c35_b_X[5] = c35_g_x[0];
  c35_b_X[8] = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c35_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c35_i48 = 0; c35_i48 < 9; c35_i48++) {
    c35_a[c35_i48] = c35_X[c35_i48];
  }

  for (c35_i49 = 0; c35_i49 < 9; c35_i49++) {
    c35_c_b[c35_i49] = c35_b_X[c35_i49];
  }

  c35_eml_scalar_eg(chartInstance);
  c35_eml_scalar_eg(chartInstance);
  c35_threshold(chartInstance);
  for (c35_i50 = 0; c35_i50 < 3; c35_i50++) {
    c35_i51 = 0;
    for (c35_i52 = 0; c35_i52 < 3; c35_i52++) {
      c35_y[c35_i51 + c35_i50] = 0.0;
      c35_i53 = 0;
      for (c35_i54 = 0; c35_i54 < 3; c35_i54++) {
        c35_y[c35_i51 + c35_i50] += c35_a[c35_i53 + c35_i50] * c35_c_b[c35_i54 +
          c35_i51];
        c35_i53 += 3;
      }

      c35_i51 += 3;
    }
  }

  for (c35_i55 = 0; c35_i55 < 4; c35_i55++) {
    c35_h_x[c35_i55] = c35_b_x[c35_i55 + 3];
  }

  for (c35_i56 = 0; c35_i56 < 3; c35_i56++) {
    c35_f_r[c35_i56] = c35_b_r[c35_i56 + 9];
  }

  c35_quatrot(chartInstance, c35_h_x, c35_f_r, c35_d_b);
  c35_b_eml_scalar_eg(chartInstance);
  c35_b_eml_scalar_eg(chartInstance);
  c35_threshold(chartInstance);
  for (c35_i57 = 0; c35_i57 < 3; c35_i57++) {
    c35_e_y[c35_i57] = 0.0;
    c35_i58 = 0;
    for (c35_i59 = 0; c35_i59 < 3; c35_i59++) {
      c35_e_y[c35_i57] += c35_y[c35_i58 + c35_i57] * c35_d_b[c35_i59];
      c35_i58 += 3;
    }
  }

  for (c35_i60 = 0; c35_i60 < 3; c35_i60++) {
    c35_b_b[c35_i60] = c35_b_y[c35_i60];
  }

  for (c35_i61 = 0; c35_i61 < 3; c35_i61++) {
    c35_b_b[c35_i61 + 3] = 0.0;
  }

  for (c35_i62 = 0; c35_i62 < 3; c35_i62++) {
    c35_b_b[c35_i62 + 6] = c35_c_y[c35_i62];
  }

  for (c35_i63 = 0; c35_i63 < 3; c35_i63++) {
    c35_b_b[c35_i63 + 9] = 0.0;
  }

  for (c35_i64 = 0; c35_i64 < 3; c35_i64++) {
    c35_b_b[c35_i64 + 12] = c35_d_y[c35_i64];
  }

  for (c35_i65 = 0; c35_i65 < 3; c35_i65++) {
    c35_b_b[c35_i65 + 15] = 0.0;
  }

  for (c35_i66 = 0; c35_i66 < 3; c35_i66++) {
    c35_b_b[c35_i66 + 18] = c35_e_y[c35_i66];
  }

  for (c35_i67 = 0; c35_i67 < 3; c35_i67++) {
    c35_b_b[c35_i67 + 21] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, -2);
  _SFD_SYMBOL_SCOPE_POP();
  for (c35_i68 = 0; c35_i68 < 24; c35_i68++) {
    (*chartInstance->c35_b)[c35_i68] = c35_b_b[c35_i68];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c35_sfEvent);
}

static void initSimStructsc35_DePascali4M(SFc35_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c35_skew_sm(SFc35_DePascali4MInstanceStruct *chartInstance, real_T
  c35_b_x[3], real_T c35_X[9])
{
  uint32_T c35_debug_family_var_map[4];
  real_T c35_nargin = 1.0;
  real_T c35_nargout = 1.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c35_b_debug_family_names,
    c35_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_nargin, 0U, c35_d_sf_marshallOut,
    c35_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_nargout, 1U, c35_d_sf_marshallOut,
    c35_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c35_b_x, 2U, c35_f_sf_marshallOut,
    c35_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c35_X, 3U, c35_e_sf_marshallOut,
    c35_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c35_sfEvent, 3);
  c35_X[0] = 0.0;
  c35_X[3] = -c35_b_x[2];
  c35_X[6] = c35_b_x[1];
  c35_X[1] = c35_b_x[2];
  c35_X[4] = 0.0;
  c35_X[7] = -c35_b_x[0];
  c35_X[2] = -c35_b_x[1];
  c35_X[5] = c35_b_x[0];
  c35_X[8] = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c35_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c35_quatrot(SFc35_DePascali4MInstanceStruct *chartInstance, real_T
  c35_q[4], real_T c35_b_r[3], real_T c35_rw[3])
{
  uint32_T c35_debug_family_var_map[6];
  real_T c35_rwq[4];
  real_T c35_nargin = 2.0;
  real_T c35_nargout = 1.0;
  int32_T c35_i69;
  real_T c35_b_q[4];
  int32_T c35_k;
  real_T c35_b_k;
  real_T c35_dv2[4];
  int32_T c35_i70;
  int32_T c35_i71;
  real_T c35_c_q[4];
  real_T c35_dv3[4];
  int32_T c35_i72;
  real_T c35_d_q[4];
  int32_T c35_i73;
  real_T c35_dv4[4];
  int32_T c35_i74;
  int32_T c35_i75;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c35_c_debug_family_names,
    c35_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c35_rwq, 0U, c35_g_sf_marshallOut,
    c35_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_nargin, 1U, c35_d_sf_marshallOut,
    c35_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_nargout, 2U, c35_d_sf_marshallOut,
    c35_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c35_q, 3U, c35_g_sf_marshallOut,
    c35_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c35_b_r, 4U, c35_f_sf_marshallOut,
    c35_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c35_rw, 5U, c35_f_sf_marshallOut,
    c35_e_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c35_sfEvent, 4);
  for (c35_i69 = 0; c35_i69 < 4; c35_i69++) {
    c35_b_q[c35_i69] = c35_q[c35_i69];
  }

  for (c35_k = 0; c35_k < 3; c35_k++) {
    c35_b_k = 2.0 + (real_T)c35_k;
    c35_b_q[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c35_b_k), 1, 4, 1, 0) - 1] = -c35_b_q[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", c35_b_k), 1, 4, 1, 0) - 1];
  }

  c35_dv2[0] = 0.0;
  for (c35_i70 = 0; c35_i70 < 3; c35_i70++) {
    c35_dv2[c35_i70 + 1] = c35_b_r[c35_i70];
  }

  for (c35_i71 = 0; c35_i71 < 4; c35_i71++) {
    c35_c_q[c35_i71] = c35_b_q[c35_i71];
  }

  c35_quatmultiply(chartInstance, c35_dv2, c35_c_q, c35_dv3);
  for (c35_i72 = 0; c35_i72 < 4; c35_i72++) {
    c35_d_q[c35_i72] = c35_q[c35_i72];
  }

  for (c35_i73 = 0; c35_i73 < 4; c35_i73++) {
    c35_dv4[c35_i73] = c35_dv3[c35_i73];
  }

  c35_quatmultiply(chartInstance, c35_d_q, c35_dv4, c35_b_q);
  for (c35_i74 = 0; c35_i74 < 4; c35_i74++) {
    c35_rwq[c35_i74] = c35_b_q[c35_i74];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c35_sfEvent, 5);
  for (c35_i75 = 0; c35_i75 < 3; c35_i75++) {
    c35_rw[c35_i75] = c35_rwq[c35_i75 + 1];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c35_sfEvent, -5);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c35_machineNumber, uint32_T
  c35_chartNumber, uint32_T c35_instanceNumber)
{
  (void)c35_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c35_chartNumber, c35_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Martin\\Documents\\Git\\Simulink\\DePascaliErhart\\skew_sm.m"));
  _SFD_SCRIPT_TRANSLATION(c35_chartNumber, c35_instanceNumber, 1U,
    sf_debug_get_script_id(
    "C:\\Users\\Martin\\Documents\\Git\\Simulink\\DePascaliErhart\\quatrot.m"));
}

static const mxArray *c35_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  int32_T c35_i76;
  real_T c35_b_inData[24];
  int32_T c35_i77;
  real_T c35_u[24];
  const mxArray *c35_y = NULL;
  SFc35_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc35_DePascali4MInstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  for (c35_i76 = 0; c35_i76 < 24; c35_i76++) {
    c35_b_inData[c35_i76] = (*(real_T (*)[24])c35_inData)[c35_i76];
  }

  for (c35_i77 = 0; c35_i77 < 24; c35_i77++) {
    c35_u[c35_i77] = c35_b_inData[c35_i77];
  }

  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", c35_u, 0, 0U, 1U, 0U, 1, 24), false);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, false);
  return c35_mxArrayOutData;
}

static void c35_emlrt_marshallIn(SFc35_DePascali4MInstanceStruct *chartInstance,
  const mxArray *c35_b_b, const char_T *c35_identifier, real_T c35_y[24])
{
  emlrtMsgIdentifier c35_thisId;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_b_b), &c35_thisId, c35_y);
  sf_mex_destroy(&c35_b_b);
}

static void c35_b_emlrt_marshallIn(SFc35_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId,
  real_T c35_y[24])
{
  real_T c35_dv5[24];
  int32_T c35_i78;
  (void)chartInstance;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), c35_dv5, 1, 0, 0U, 1, 0U, 1, 24);
  for (c35_i78 = 0; c35_i78 < 24; c35_i78++) {
    c35_y[c35_i78] = c35_dv5[c35_i78];
  }

  sf_mex_destroy(&c35_u);
}

static void c35_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_b_b;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  real_T c35_y[24];
  int32_T c35_i79;
  SFc35_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc35_DePascali4MInstanceStruct *)chartInstanceVoid;
  c35_b_b = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_b_b), &c35_thisId, c35_y);
  sf_mex_destroy(&c35_b_b);
  for (c35_i79 = 0; c35_i79 < 24; c35_i79++) {
    (*(real_T (*)[24])c35_outData)[c35_i79] = c35_y[c35_i79];
  }

  sf_mex_destroy(&c35_mxArrayInData);
}

static const mxArray *c35_b_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  int32_T c35_i80;
  real_T c35_b_inData[28];
  int32_T c35_i81;
  real_T c35_u[28];
  const mxArray *c35_y = NULL;
  SFc35_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc35_DePascali4MInstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  for (c35_i80 = 0; c35_i80 < 28; c35_i80++) {
    c35_b_inData[c35_i80] = (*(real_T (*)[28])c35_inData)[c35_i80];
  }

  for (c35_i81 = 0; c35_i81 < 28; c35_i81++) {
    c35_u[c35_i81] = c35_b_inData[c35_i81];
  }

  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", c35_u, 0, 0U, 1U, 0U, 1, 28), false);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, false);
  return c35_mxArrayOutData;
}

static const mxArray *c35_c_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  int32_T c35_i82;
  real_T c35_b_inData[12];
  int32_T c35_i83;
  real_T c35_u[12];
  const mxArray *c35_y = NULL;
  SFc35_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc35_DePascali4MInstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  for (c35_i82 = 0; c35_i82 < 12; c35_i82++) {
    c35_b_inData[c35_i82] = (*(real_T (*)[12])c35_inData)[c35_i82];
  }

  for (c35_i83 = 0; c35_i83 < 12; c35_i83++) {
    c35_u[c35_i83] = c35_b_inData[c35_i83];
  }

  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", c35_u, 0, 0U, 1U, 0U, 1, 12), false);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, false);
  return c35_mxArrayOutData;
}

static void c35_c_emlrt_marshallIn(SFc35_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId,
  real_T c35_y[12])
{
  real_T c35_dv6[12];
  int32_T c35_i84;
  (void)chartInstance;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), c35_dv6, 1, 0, 0U, 1, 0U, 1, 12);
  for (c35_i84 = 0; c35_i84 < 12; c35_i84++) {
    c35_y[c35_i84] = c35_dv6[c35_i84];
  }

  sf_mex_destroy(&c35_u);
}

static void c35_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_b_r;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  real_T c35_y[12];
  int32_T c35_i85;
  SFc35_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc35_DePascali4MInstanceStruct *)chartInstanceVoid;
  c35_b_r = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_b_r), &c35_thisId, c35_y);
  sf_mex_destroy(&c35_b_r);
  for (c35_i85 = 0; c35_i85 < 12; c35_i85++) {
    (*(real_T (*)[12])c35_outData)[c35_i85] = c35_y[c35_i85];
  }

  sf_mex_destroy(&c35_mxArrayInData);
}

static const mxArray *c35_d_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  real_T c35_u;
  const mxArray *c35_y = NULL;
  SFc35_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc35_DePascali4MInstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  c35_u = *(real_T *)c35_inData;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", &c35_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, false);
  return c35_mxArrayOutData;
}

static real_T c35_d_emlrt_marshallIn(SFc35_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId)
{
  real_T c35_y;
  real_T c35_d0;
  (void)chartInstance;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), &c35_d0, 1, 0, 0U, 0, 0U, 0);
  c35_y = c35_d0;
  sf_mex_destroy(&c35_u);
  return c35_y;
}

static void c35_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_nargout;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  real_T c35_y;
  SFc35_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc35_DePascali4MInstanceStruct *)chartInstanceVoid;
  c35_nargout = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_nargout),
    &c35_thisId);
  sf_mex_destroy(&c35_nargout);
  *(real_T *)c35_outData = c35_y;
  sf_mex_destroy(&c35_mxArrayInData);
}

static const mxArray *c35_e_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  int32_T c35_i86;
  int32_T c35_i87;
  int32_T c35_i88;
  real_T c35_b_inData[9];
  int32_T c35_i89;
  int32_T c35_i90;
  int32_T c35_i91;
  real_T c35_u[9];
  const mxArray *c35_y = NULL;
  SFc35_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc35_DePascali4MInstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  c35_i86 = 0;
  for (c35_i87 = 0; c35_i87 < 3; c35_i87++) {
    for (c35_i88 = 0; c35_i88 < 3; c35_i88++) {
      c35_b_inData[c35_i88 + c35_i86] = (*(real_T (*)[9])c35_inData)[c35_i88 +
        c35_i86];
    }

    c35_i86 += 3;
  }

  c35_i89 = 0;
  for (c35_i90 = 0; c35_i90 < 3; c35_i90++) {
    for (c35_i91 = 0; c35_i91 < 3; c35_i91++) {
      c35_u[c35_i91 + c35_i89] = c35_b_inData[c35_i91 + c35_i89];
    }

    c35_i89 += 3;
  }

  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", c35_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, false);
  return c35_mxArrayOutData;
}

static void c35_e_emlrt_marshallIn(SFc35_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId,
  real_T c35_y[9])
{
  real_T c35_dv7[9];
  int32_T c35_i92;
  (void)chartInstance;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), c35_dv7, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c35_i92 = 0; c35_i92 < 9; c35_i92++) {
    c35_y[c35_i92] = c35_dv7[c35_i92];
  }

  sf_mex_destroy(&c35_u);
}

static void c35_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_X;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  real_T c35_y[9];
  int32_T c35_i93;
  int32_T c35_i94;
  int32_T c35_i95;
  SFc35_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc35_DePascali4MInstanceStruct *)chartInstanceVoid;
  c35_X = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_X), &c35_thisId, c35_y);
  sf_mex_destroy(&c35_X);
  c35_i93 = 0;
  for (c35_i94 = 0; c35_i94 < 3; c35_i94++) {
    for (c35_i95 = 0; c35_i95 < 3; c35_i95++) {
      (*(real_T (*)[9])c35_outData)[c35_i95 + c35_i93] = c35_y[c35_i95 + c35_i93];
    }

    c35_i93 += 3;
  }

  sf_mex_destroy(&c35_mxArrayInData);
}

static const mxArray *c35_f_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  int32_T c35_i96;
  real_T c35_b_inData[3];
  int32_T c35_i97;
  real_T c35_u[3];
  const mxArray *c35_y = NULL;
  SFc35_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc35_DePascali4MInstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  for (c35_i96 = 0; c35_i96 < 3; c35_i96++) {
    c35_b_inData[c35_i96] = (*(real_T (*)[3])c35_inData)[c35_i96];
  }

  for (c35_i97 = 0; c35_i97 < 3; c35_i97++) {
    c35_u[c35_i97] = c35_b_inData[c35_i97];
  }

  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", c35_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, false);
  return c35_mxArrayOutData;
}

static void c35_f_emlrt_marshallIn(SFc35_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId,
  real_T c35_y[3])
{
  real_T c35_dv8[3];
  int32_T c35_i98;
  (void)chartInstance;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), c35_dv8, 1, 0, 0U, 1, 0U, 1, 3);
  for (c35_i98 = 0; c35_i98 < 3; c35_i98++) {
    c35_y[c35_i98] = c35_dv8[c35_i98];
  }

  sf_mex_destroy(&c35_u);
}

static void c35_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_b_x;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  real_T c35_y[3];
  int32_T c35_i99;
  SFc35_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc35_DePascali4MInstanceStruct *)chartInstanceVoid;
  c35_b_x = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_b_x), &c35_thisId, c35_y);
  sf_mex_destroy(&c35_b_x);
  for (c35_i99 = 0; c35_i99 < 3; c35_i99++) {
    (*(real_T (*)[3])c35_outData)[c35_i99] = c35_y[c35_i99];
  }

  sf_mex_destroy(&c35_mxArrayInData);
}

static const mxArray *c35_g_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  int32_T c35_i100;
  real_T c35_b_inData[4];
  int32_T c35_i101;
  real_T c35_u[4];
  const mxArray *c35_y = NULL;
  SFc35_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc35_DePascali4MInstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  for (c35_i100 = 0; c35_i100 < 4; c35_i100++) {
    c35_b_inData[c35_i100] = (*(real_T (*)[4])c35_inData)[c35_i100];
  }

  for (c35_i101 = 0; c35_i101 < 4; c35_i101++) {
    c35_u[c35_i101] = c35_b_inData[c35_i101];
  }

  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", c35_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, false);
  return c35_mxArrayOutData;
}

static void c35_g_emlrt_marshallIn(SFc35_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId,
  real_T c35_y[4])
{
  real_T c35_dv9[4];
  int32_T c35_i102;
  (void)chartInstance;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), c35_dv9, 1, 0, 0U, 1, 0U, 1, 4);
  for (c35_i102 = 0; c35_i102 < 4; c35_i102++) {
    c35_y[c35_i102] = c35_dv9[c35_i102];
  }

  sf_mex_destroy(&c35_u);
}

static void c35_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_q;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  real_T c35_y[4];
  int32_T c35_i103;
  SFc35_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc35_DePascali4MInstanceStruct *)chartInstanceVoid;
  c35_q = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_q), &c35_thisId, c35_y);
  sf_mex_destroy(&c35_q);
  for (c35_i103 = 0; c35_i103 < 4; c35_i103++) {
    (*(real_T (*)[4])c35_outData)[c35_i103] = c35_y[c35_i103];
  }

  sf_mex_destroy(&c35_mxArrayInData);
}

const mxArray *sf_c35_DePascali4M_get_eml_resolved_functions_info(void)
{
  const mxArray *c35_nameCaptureInfo = NULL;
  c35_nameCaptureInfo = NULL;
  sf_mex_assign(&c35_nameCaptureInfo, sf_mex_createstruct("structure", 2, 25, 1),
                false);
  c35_info_helper(&c35_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c35_nameCaptureInfo);
  return c35_nameCaptureInfo;
}

static void c35_info_helper(const mxArray **c35_info)
{
  const mxArray *c35_rhs0 = NULL;
  const mxArray *c35_lhs0 = NULL;
  const mxArray *c35_rhs1 = NULL;
  const mxArray *c35_lhs1 = NULL;
  const mxArray *c35_rhs2 = NULL;
  const mxArray *c35_lhs2 = NULL;
  const mxArray *c35_rhs3 = NULL;
  const mxArray *c35_lhs3 = NULL;
  const mxArray *c35_rhs4 = NULL;
  const mxArray *c35_lhs4 = NULL;
  const mxArray *c35_rhs5 = NULL;
  const mxArray *c35_lhs5 = NULL;
  const mxArray *c35_rhs6 = NULL;
  const mxArray *c35_lhs6 = NULL;
  const mxArray *c35_rhs7 = NULL;
  const mxArray *c35_lhs7 = NULL;
  const mxArray *c35_rhs8 = NULL;
  const mxArray *c35_lhs8 = NULL;
  const mxArray *c35_rhs9 = NULL;
  const mxArray *c35_lhs9 = NULL;
  const mxArray *c35_rhs10 = NULL;
  const mxArray *c35_lhs10 = NULL;
  const mxArray *c35_rhs11 = NULL;
  const mxArray *c35_lhs11 = NULL;
  const mxArray *c35_rhs12 = NULL;
  const mxArray *c35_lhs12 = NULL;
  const mxArray *c35_rhs13 = NULL;
  const mxArray *c35_lhs13 = NULL;
  const mxArray *c35_rhs14 = NULL;
  const mxArray *c35_lhs14 = NULL;
  const mxArray *c35_rhs15 = NULL;
  const mxArray *c35_lhs15 = NULL;
  const mxArray *c35_rhs16 = NULL;
  const mxArray *c35_lhs16 = NULL;
  const mxArray *c35_rhs17 = NULL;
  const mxArray *c35_lhs17 = NULL;
  const mxArray *c35_rhs18 = NULL;
  const mxArray *c35_lhs18 = NULL;
  const mxArray *c35_rhs19 = NULL;
  const mxArray *c35_lhs19 = NULL;
  const mxArray *c35_rhs20 = NULL;
  const mxArray *c35_lhs20 = NULL;
  const mxArray *c35_rhs21 = NULL;
  const mxArray *c35_lhs21 = NULL;
  const mxArray *c35_rhs22 = NULL;
  const mxArray *c35_lhs22 = NULL;
  const mxArray *c35_rhs23 = NULL;
  const mxArray *c35_lhs23 = NULL;
  const mxArray *c35_rhs24 = NULL;
  const mxArray *c35_lhs24 = NULL;
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("skew_sm"), "name", "name", 0);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DePascaliErhart/skew_sm.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1445505143U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c35_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 1);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1383902494U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c35_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 2);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c35_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 3);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 3);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c35_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 4);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 4);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c35_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 5);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c35_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  6);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1376005890U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c35_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 7);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c35_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 8);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c35_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 9);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 9);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c35_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 10);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 10);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c35_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 11);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 11);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c35_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 12);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 12);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c35_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 13);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 13);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c35_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "context", "context", 14);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("quatrot"), "name", "name",
                  14);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DePascaliErhart/quatrot.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1446631716U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c35_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DePascaliErhart/quatrot.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("quatconj"), "name", "name",
                  15);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatconj.p"), "resolved", "resolved",
                  15);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410808258U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c35_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DePascaliErhart/quatrot.m"),
                  "context", "context", 16);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("quatmultiply"), "name",
                  "name", 16);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatmultiply.p"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410808258U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c35_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatmultiply.p"), "context",
                  "context", 17);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("max"), "name", "name", 17);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1311280516U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c35_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 18);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1378321184U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c35_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 19);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 19);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c35_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 20);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 20);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c35_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 21);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 21);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c35_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 22);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 22);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c35_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 23);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 23);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c35_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 24);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 24);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c35_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs24), "lhs", "lhs",
                  24);
  sf_mex_destroy(&c35_rhs0);
  sf_mex_destroy(&c35_lhs0);
  sf_mex_destroy(&c35_rhs1);
  sf_mex_destroy(&c35_lhs1);
  sf_mex_destroy(&c35_rhs2);
  sf_mex_destroy(&c35_lhs2);
  sf_mex_destroy(&c35_rhs3);
  sf_mex_destroy(&c35_lhs3);
  sf_mex_destroy(&c35_rhs4);
  sf_mex_destroy(&c35_lhs4);
  sf_mex_destroy(&c35_rhs5);
  sf_mex_destroy(&c35_lhs5);
  sf_mex_destroy(&c35_rhs6);
  sf_mex_destroy(&c35_lhs6);
  sf_mex_destroy(&c35_rhs7);
  sf_mex_destroy(&c35_lhs7);
  sf_mex_destroy(&c35_rhs8);
  sf_mex_destroy(&c35_lhs8);
  sf_mex_destroy(&c35_rhs9);
  sf_mex_destroy(&c35_lhs9);
  sf_mex_destroy(&c35_rhs10);
  sf_mex_destroy(&c35_lhs10);
  sf_mex_destroy(&c35_rhs11);
  sf_mex_destroy(&c35_lhs11);
  sf_mex_destroy(&c35_rhs12);
  sf_mex_destroy(&c35_lhs12);
  sf_mex_destroy(&c35_rhs13);
  sf_mex_destroy(&c35_lhs13);
  sf_mex_destroy(&c35_rhs14);
  sf_mex_destroy(&c35_lhs14);
  sf_mex_destroy(&c35_rhs15);
  sf_mex_destroy(&c35_lhs15);
  sf_mex_destroy(&c35_rhs16);
  sf_mex_destroy(&c35_lhs16);
  sf_mex_destroy(&c35_rhs17);
  sf_mex_destroy(&c35_lhs17);
  sf_mex_destroy(&c35_rhs18);
  sf_mex_destroy(&c35_lhs18);
  sf_mex_destroy(&c35_rhs19);
  sf_mex_destroy(&c35_lhs19);
  sf_mex_destroy(&c35_rhs20);
  sf_mex_destroy(&c35_lhs20);
  sf_mex_destroy(&c35_rhs21);
  sf_mex_destroy(&c35_lhs21);
  sf_mex_destroy(&c35_rhs22);
  sf_mex_destroy(&c35_lhs22);
  sf_mex_destroy(&c35_rhs23);
  sf_mex_destroy(&c35_lhs23);
  sf_mex_destroy(&c35_rhs24);
  sf_mex_destroy(&c35_lhs24);
}

static const mxArray *c35_emlrt_marshallOut(const char * c35_u)
{
  const mxArray *c35_y = NULL;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", c35_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c35_u)), false);
  return c35_y;
}

static const mxArray *c35_b_emlrt_marshallOut(const uint32_T c35_u)
{
  const mxArray *c35_y = NULL;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", &c35_u, 7, 0U, 0U, 0U, 0), false);
  return c35_y;
}

static void c35_eml_scalar_eg(SFc35_DePascali4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c35_threshold(SFc35_DePascali4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c35_quatmultiply(SFc35_DePascali4MInstanceStruct *chartInstance,
  real_T c35_q[4], real_T c35_b_r[4], real_T c35_qout[4])
{
  real_T c35_q1;
  real_T c35_q2;
  real_T c35_q3;
  real_T c35_q4;
  real_T c35_r1;
  real_T c35_r2;
  real_T c35_r3;
  real_T c35_r4;
  (void)chartInstance;
  c35_q1 = c35_q[0];
  c35_q2 = c35_q[1];
  c35_q3 = c35_q[2];
  c35_q4 = c35_q[3];
  c35_r1 = c35_b_r[0];
  c35_r2 = c35_b_r[1];
  c35_r3 = c35_b_r[2];
  c35_r4 = c35_b_r[3];
  c35_qout[0] = ((c35_q1 * c35_r1 - c35_q2 * c35_r2) - c35_q3 * c35_r3) - c35_q4
    * c35_r4;
  c35_qout[1] = (c35_q1 * c35_r2 + c35_r1 * c35_q2) + (c35_q3 * c35_r4 - c35_q4 *
    c35_r3);
  c35_qout[2] = (c35_q1 * c35_r3 + c35_r1 * c35_q3) + (c35_q4 * c35_r2 - c35_q2 *
    c35_r4);
  c35_qout[3] = (c35_q1 * c35_r4 + c35_r1 * c35_q4) + (c35_q2 * c35_r3 - c35_q3 *
    c35_r2);
}

static void c35_b_eml_scalar_eg(SFc35_DePascali4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *c35_h_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  int32_T c35_u;
  const mxArray *c35_y = NULL;
  SFc35_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc35_DePascali4MInstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  c35_u = *(int32_T *)c35_inData;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", &c35_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, false);
  return c35_mxArrayOutData;
}

static int32_T c35_h_emlrt_marshallIn(SFc35_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId)
{
  int32_T c35_y;
  int32_T c35_i104;
  (void)chartInstance;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), &c35_i104, 1, 6, 0U, 0, 0U, 0);
  c35_y = c35_i104;
  sf_mex_destroy(&c35_u);
  return c35_y;
}

static void c35_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_b_sfEvent;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  int32_T c35_y;
  SFc35_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc35_DePascali4MInstanceStruct *)chartInstanceVoid;
  c35_b_sfEvent = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_b_sfEvent),
    &c35_thisId);
  sf_mex_destroy(&c35_b_sfEvent);
  *(int32_T *)c35_outData = c35_y;
  sf_mex_destroy(&c35_mxArrayInData);
}

static uint8_T c35_i_emlrt_marshallIn(SFc35_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c35_b_is_active_c35_DePascali4M, const char_T
  *c35_identifier)
{
  uint8_T c35_y;
  emlrtMsgIdentifier c35_thisId;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c35_b_is_active_c35_DePascali4M), &c35_thisId);
  sf_mex_destroy(&c35_b_is_active_c35_DePascali4M);
  return c35_y;
}

static uint8_T c35_j_emlrt_marshallIn(SFc35_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId)
{
  uint8_T c35_y;
  uint8_T c35_u0;
  (void)chartInstance;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), &c35_u0, 1, 3, 0U, 0, 0U, 0);
  c35_y = c35_u0;
  sf_mex_destroy(&c35_u);
  return c35_y;
}

static void init_dsm_address_info(SFc35_DePascali4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc35_DePascali4MInstanceStruct
  *chartInstance)
{
  chartInstance->c35_dx = (real_T (*)[24])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c35_b = (real_T (*)[24])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c35_x = (real_T (*)[28])ssGetInputPortSignal_wrapper
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

void sf_c35_DePascali4M_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2171432780U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3006218270U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(598362265U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2568961385U);
}

mxArray* sf_c35_DePascali4M_get_post_codegen_info(void);
mxArray *sf_c35_DePascali4M_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("MNIWBbuNFTZjpPbKWaFHcH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxArray* mxPostCodegenInfo = sf_c35_DePascali4M_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c35_DePascali4M_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c35_DePascali4M_jit_fallback_info(void)
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

mxArray *sf_c35_DePascali4M_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c35_DePascali4M_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c35_DePascali4M(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"b\",},{M[8],M[0],T\"is_active_c35_DePascali4M\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c35_DePascali4M_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc35_DePascali4MInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc35_DePascali4MInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DePascali4MMachineNumber_,
           35,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"dx");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,360);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"skew_sm",0,-1,127);
        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"quatrot",0,-1,191);

        {
          unsigned int dimVector[1];
          dimVector[0]= 24;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 24;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)
            c35_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c35_c_sf_marshallOut,(MexInFcnForType)
            c35_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 28;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c35_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c35_dx);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c35_b);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c35_r);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c35_x);
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
  return "vEneZyO80AXkO3fgcTZVhD";
}

static void sf_opaque_initialize_c35_DePascali4M(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc35_DePascali4MInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c35_DePascali4M((SFc35_DePascali4MInstanceStruct*)
    chartInstanceVar);
  initialize_c35_DePascali4M((SFc35_DePascali4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c35_DePascali4M(void *chartInstanceVar)
{
  enable_c35_DePascali4M((SFc35_DePascali4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c35_DePascali4M(void *chartInstanceVar)
{
  disable_c35_DePascali4M((SFc35_DePascali4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c35_DePascali4M(void *chartInstanceVar)
{
  sf_gateway_c35_DePascali4M((SFc35_DePascali4MInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c35_DePascali4M(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c35_DePascali4M((SFc35_DePascali4MInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c35_DePascali4M(SimStruct* S, const mxArray *
  st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c35_DePascali4M((SFc35_DePascali4MInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c35_DePascali4M(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc35_DePascali4MInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DePascali4M_optimization_info();
    }

    finalize_c35_DePascali4M((SFc35_DePascali4MInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc35_DePascali4M((SFc35_DePascali4MInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c35_DePascali4M(SimStruct *S)
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
    initialize_params_c35_DePascali4M((SFc35_DePascali4MInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c35_DePascali4M(SimStruct *S)
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
      35);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,35,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,35,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,35);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,35,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,35,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,35);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1534470654U));
  ssSetChecksum1(S,(3913611368U));
  ssSetChecksum2(S,(3588081784U));
  ssSetChecksum3(S,(4123450687U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c35_DePascali4M(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c35_DePascali4M(SimStruct *S)
{
  SFc35_DePascali4MInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc35_DePascali4MInstanceStruct *)utMalloc(sizeof
    (SFc35_DePascali4MInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc35_DePascali4MInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c35_DePascali4M;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c35_DePascali4M;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c35_DePascali4M;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c35_DePascali4M;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c35_DePascali4M;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c35_DePascali4M;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c35_DePascali4M;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c35_DePascali4M;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c35_DePascali4M;
  chartInstance->chartInfo.mdlStart = mdlStart_c35_DePascali4M;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c35_DePascali4M;
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

void c35_DePascali4M_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c35_DePascali4M(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c35_DePascali4M(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c35_DePascali4M(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c35_DePascali4M_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

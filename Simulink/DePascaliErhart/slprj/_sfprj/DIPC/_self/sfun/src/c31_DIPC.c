/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DIPC_sfun.h"
#include "c31_DIPC.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DIPC_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c31_debug_family_names[6] = { "nargin", "nargout", "r", "x",
  "dx", "bred" };

static const char * c31_b_debug_family_names[4] = { "nargin", "nargout", "x",
  "X" };

static const char * c31_c_debug_family_names[6] = { "rwq", "nargin", "nargout",
  "q", "r", "rw" };

/* Function Declarations */
static void initialize_c31_DIPC(SFc31_DIPCInstanceStruct *chartInstance);
static void initialize_params_c31_DIPC(SFc31_DIPCInstanceStruct *chartInstance);
static void enable_c31_DIPC(SFc31_DIPCInstanceStruct *chartInstance);
static void disable_c31_DIPC(SFc31_DIPCInstanceStruct *chartInstance);
static void c31_update_debugger_state_c31_DIPC(SFc31_DIPCInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c31_DIPC(SFc31_DIPCInstanceStruct
  *chartInstance);
static void set_sim_state_c31_DIPC(SFc31_DIPCInstanceStruct *chartInstance,
  const mxArray *c31_st);
static void finalize_c31_DIPC(SFc31_DIPCInstanceStruct *chartInstance);
static void sf_gateway_c31_DIPC(SFc31_DIPCInstanceStruct *chartInstance);
static void mdl_start_c31_DIPC(SFc31_DIPCInstanceStruct *chartInstance);
static void c31_chartstep_c31_DIPC(SFc31_DIPCInstanceStruct *chartInstance);
static void initSimStructsc31_DIPC(SFc31_DIPCInstanceStruct *chartInstance);
static void c31_skew_sm(SFc31_DIPCInstanceStruct *chartInstance, real_T c31_b_x
  [3], real_T c31_X[9]);
static void c31_quatrot(SFc31_DIPCInstanceStruct *chartInstance, real_T c31_q[4],
  real_T c31_b_r[3], real_T c31_rw[3]);
static void init_script_number_translation(uint32_T c31_machineNumber, uint32_T
  c31_chartNumber, uint32_T c31_instanceNumber);
static const mxArray *c31_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData);
static void c31_emlrt_marshallIn(SFc31_DIPCInstanceStruct *chartInstance, const
  mxArray *c31_b_bred, const char_T *c31_identifier, real_T c31_y[18]);
static void c31_b_emlrt_marshallIn(SFc31_DIPCInstanceStruct *chartInstance,
  const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId, real_T c31_y[18]);
static void c31_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData);
static const mxArray *c31_b_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData);
static const mxArray *c31_c_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData);
static const mxArray *c31_d_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData);
static void c31_c_emlrt_marshallIn(SFc31_DIPCInstanceStruct *chartInstance,
  const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId, real_T c31_y[12]);
static void c31_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData);
static const mxArray *c31_e_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData);
static real_T c31_d_emlrt_marshallIn(SFc31_DIPCInstanceStruct *chartInstance,
  const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId);
static void c31_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData);
static const mxArray *c31_f_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData);
static void c31_e_emlrt_marshallIn(SFc31_DIPCInstanceStruct *chartInstance,
  const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId, real_T c31_y[9]);
static void c31_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData);
static const mxArray *c31_g_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData);
static void c31_f_emlrt_marshallIn(SFc31_DIPCInstanceStruct *chartInstance,
  const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId, real_T c31_y[3]);
static void c31_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData);
static const mxArray *c31_h_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData);
static void c31_g_emlrt_marshallIn(SFc31_DIPCInstanceStruct *chartInstance,
  const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId, real_T c31_y[4]);
static void c31_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData);
static void c31_info_helper(const mxArray **c31_info);
static const mxArray *c31_emlrt_marshallOut(const char * c31_u);
static const mxArray *c31_b_emlrt_marshallOut(const uint32_T c31_u);
static void c31_eml_scalar_eg(SFc31_DIPCInstanceStruct *chartInstance);
static void c31_threshold(SFc31_DIPCInstanceStruct *chartInstance);
static void c31_quatmultiply(SFc31_DIPCInstanceStruct *chartInstance, real_T
  c31_q[4], real_T c31_b_r[4], real_T c31_qout[4]);
static void c31_b_eml_scalar_eg(SFc31_DIPCInstanceStruct *chartInstance);
static const mxArray *c31_i_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData);
static int32_T c31_h_emlrt_marshallIn(SFc31_DIPCInstanceStruct *chartInstance,
  const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId);
static void c31_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData);
static uint8_T c31_i_emlrt_marshallIn(SFc31_DIPCInstanceStruct *chartInstance,
  const mxArray *c31_b_is_active_c31_DIPC, const char_T *c31_identifier);
static uint8_T c31_j_emlrt_marshallIn(SFc31_DIPCInstanceStruct *chartInstance,
  const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId);
static void init_dsm_address_info(SFc31_DIPCInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc31_DIPCInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c31_DIPC(SFc31_DIPCInstanceStruct *chartInstance)
{
  chartInstance->c31_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c31_is_active_c31_DIPC = 0U;
}

static void initialize_params_c31_DIPC(SFc31_DIPCInstanceStruct *chartInstance)
{
  real_T c31_dv0[12];
  int32_T c31_i0;
  sf_mex_import_named("r", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      c31_dv0, 0, 0, 0U, 1, 0U, 1, 12);
  for (c31_i0 = 0; c31_i0 < 12; c31_i0++) {
    chartInstance->c31_r[c31_i0] = c31_dv0[c31_i0];
  }
}

static void enable_c31_DIPC(SFc31_DIPCInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c31_DIPC(SFc31_DIPCInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c31_update_debugger_state_c31_DIPC(SFc31_DIPCInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c31_DIPC(SFc31_DIPCInstanceStruct
  *chartInstance)
{
  const mxArray *c31_st;
  const mxArray *c31_y = NULL;
  int32_T c31_i1;
  real_T c31_u[18];
  const mxArray *c31_b_y = NULL;
  uint8_T c31_hoistedGlobal;
  uint8_T c31_b_u;
  const mxArray *c31_c_y = NULL;
  c31_st = NULL;
  c31_st = NULL;
  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_createcellmatrix(2, 1), false);
  for (c31_i1 = 0; c31_i1 < 18; c31_i1++) {
    c31_u[c31_i1] = (*chartInstance->c31_bred)[c31_i1];
  }

  c31_b_y = NULL;
  sf_mex_assign(&c31_b_y, sf_mex_create("y", c31_u, 0, 0U, 1U, 0U, 1, 18), false);
  sf_mex_setcell(c31_y, 0, c31_b_y);
  c31_hoistedGlobal = chartInstance->c31_is_active_c31_DIPC;
  c31_b_u = c31_hoistedGlobal;
  c31_c_y = NULL;
  sf_mex_assign(&c31_c_y, sf_mex_create("y", &c31_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c31_y, 1, c31_c_y);
  sf_mex_assign(&c31_st, c31_y, false);
  return c31_st;
}

static void set_sim_state_c31_DIPC(SFc31_DIPCInstanceStruct *chartInstance,
  const mxArray *c31_st)
{
  const mxArray *c31_u;
  real_T c31_dv1[18];
  int32_T c31_i2;
  chartInstance->c31_doneDoubleBufferReInit = true;
  c31_u = sf_mex_dup(c31_st);
  c31_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c31_u, 0)),
                       "bred", c31_dv1);
  for (c31_i2 = 0; c31_i2 < 18; c31_i2++) {
    (*chartInstance->c31_bred)[c31_i2] = c31_dv1[c31_i2];
  }

  chartInstance->c31_is_active_c31_DIPC = c31_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c31_u, 1)), "is_active_c31_DIPC");
  sf_mex_destroy(&c31_u);
  c31_update_debugger_state_c31_DIPC(chartInstance);
  sf_mex_destroy(&c31_st);
}

static void finalize_c31_DIPC(SFc31_DIPCInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c31_DIPC(SFc31_DIPCInstanceStruct *chartInstance)
{
  int32_T c31_i3;
  int32_T c31_i4;
  int32_T c31_i5;
  int32_T c31_i6;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 14U, chartInstance->c31_sfEvent);
  for (c31_i3 = 0; c31_i3 < 12; c31_i3++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c31_r[c31_i3], 0U);
  }

  for (c31_i4 = 0; c31_i4 < 28; c31_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c31_x)[c31_i4], 1U);
  }

  chartInstance->c31_sfEvent = CALL_EVENT;
  c31_chartstep_c31_DIPC(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DIPCMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c31_i5 = 0; c31_i5 < 18; c31_i5++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c31_bred)[c31_i5], 2U);
  }

  for (c31_i6 = 0; c31_i6 < 24; c31_i6++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c31_dx)[c31_i6], 3U);
  }
}

static void mdl_start_c31_DIPC(SFc31_DIPCInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c31_chartstep_c31_DIPC(SFc31_DIPCInstanceStruct *chartInstance)
{
  int32_T c31_i7;
  real_T c31_b_r[12];
  int32_T c31_i8;
  real_T c31_b_x[28];
  int32_T c31_i9;
  real_T c31_b_dx[24];
  uint32_T c31_debug_family_var_map[6];
  real_T c31_nargin = 3.0;
  real_T c31_nargout = 1.0;
  real_T c31_b_bred[18];
  int32_T c31_i10;
  real_T c31_c_dx[3];
  real_T c31_a[9];
  int32_T c31_i11;
  real_T c31_d_dx[3];
  real_T c31_b[9];
  int32_T c31_i12;
  int32_T c31_i13;
  int32_T c31_i14;
  real_T c31_y[9];
  int32_T c31_i15;
  int32_T c31_i16;
  int32_T c31_i17;
  real_T c31_c_x[4];
  int32_T c31_i18;
  real_T c31_c_r[3];
  real_T c31_b_b[3];
  int32_T c31_i19;
  real_T c31_b_y[3];
  int32_T c31_i20;
  int32_T c31_i21;
  int32_T c31_i22;
  real_T c31_e_dx[3];
  int32_T c31_i23;
  real_T c31_f_dx[3];
  int32_T c31_i24;
  int32_T c31_i25;
  int32_T c31_i26;
  int32_T c31_i27;
  int32_T c31_i28;
  int32_T c31_i29;
  real_T c31_d_x[4];
  int32_T c31_i30;
  real_T c31_d_r[3];
  int32_T c31_i31;
  real_T c31_c_y[3];
  int32_T c31_i32;
  int32_T c31_i33;
  int32_T c31_i34;
  real_T c31_e_x[3];
  uint32_T c31_b_debug_family_var_map[4];
  real_T c31_b_nargin = 1.0;
  real_T c31_b_nargout = 1.0;
  real_T c31_X[9];
  int32_T c31_i35;
  real_T c31_g_dx[3];
  int32_T c31_i36;
  int32_T c31_i37;
  int32_T c31_i38;
  int32_T c31_i39;
  int32_T c31_i40;
  int32_T c31_i41;
  int32_T c31_i42;
  real_T c31_f_x[4];
  int32_T c31_i43;
  real_T c31_e_r[3];
  int32_T c31_i44;
  real_T c31_d_y[3];
  int32_T c31_i45;
  int32_T c31_i46;
  int32_T c31_i47;
  int32_T c31_i48;
  int32_T c31_i49;
  int32_T c31_i50;
  int32_T c31_i51;
  int32_T c31_i52;
  int32_T c31_i53;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 14U, chartInstance->c31_sfEvent);
  for (c31_i7 = 0; c31_i7 < 12; c31_i7++) {
    c31_b_r[c31_i7] = chartInstance->c31_r[c31_i7];
  }

  for (c31_i8 = 0; c31_i8 < 28; c31_i8++) {
    c31_b_x[c31_i8] = (*chartInstance->c31_x)[c31_i8];
  }

  for (c31_i9 = 0; c31_i9 < 24; c31_i9++) {
    c31_b_dx[c31_i9] = (*chartInstance->c31_dx)[c31_i9];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c31_debug_family_names,
    c31_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_nargin, 0U, c31_e_sf_marshallOut,
    c31_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_nargout, 1U, c31_e_sf_marshallOut,
    c31_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c31_b_r, 2U, c31_d_sf_marshallOut,
    c31_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c31_b_x, 3U, c31_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c31_b_dx, 4U, c31_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c31_b_bred, 5U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 2);
  for (c31_i10 = 0; c31_i10 < 3; c31_i10++) {
    c31_c_dx[c31_i10] = c31_b_dx[c31_i10 + 3];
  }

  c31_skew_sm(chartInstance, c31_c_dx, c31_a);
  for (c31_i11 = 0; c31_i11 < 3; c31_i11++) {
    c31_d_dx[c31_i11] = c31_b_dx[c31_i11 + 3];
  }

  c31_skew_sm(chartInstance, c31_d_dx, c31_b);
  c31_eml_scalar_eg(chartInstance);
  c31_eml_scalar_eg(chartInstance);
  c31_threshold(chartInstance);
  for (c31_i12 = 0; c31_i12 < 3; c31_i12++) {
    c31_i13 = 0;
    for (c31_i14 = 0; c31_i14 < 3; c31_i14++) {
      c31_y[c31_i13 + c31_i12] = 0.0;
      c31_i15 = 0;
      for (c31_i16 = 0; c31_i16 < 3; c31_i16++) {
        c31_y[c31_i13 + c31_i12] += c31_a[c31_i15 + c31_i12] * c31_b[c31_i16 +
          c31_i13];
        c31_i15 += 3;
      }

      c31_i13 += 3;
    }
  }

  for (c31_i17 = 0; c31_i17 < 4; c31_i17++) {
    c31_c_x[c31_i17] = c31_b_x[c31_i17 + 3];
  }

  for (c31_i18 = 0; c31_i18 < 3; c31_i18++) {
    c31_c_r[c31_i18] = c31_b_r[c31_i18 + 3] - c31_b_r[c31_i18];
  }

  c31_quatrot(chartInstance, c31_c_x, c31_c_r, c31_b_b);
  c31_b_eml_scalar_eg(chartInstance);
  c31_b_eml_scalar_eg(chartInstance);
  c31_threshold(chartInstance);
  for (c31_i19 = 0; c31_i19 < 3; c31_i19++) {
    c31_b_y[c31_i19] = 0.0;
    c31_i20 = 0;
    for (c31_i21 = 0; c31_i21 < 3; c31_i21++) {
      c31_b_y[c31_i19] += c31_y[c31_i20 + c31_i19] * c31_b_b[c31_i21];
      c31_i20 += 3;
    }
  }

  for (c31_i22 = 0; c31_i22 < 3; c31_i22++) {
    c31_e_dx[c31_i22] = c31_b_dx[c31_i22 + 3];
  }

  c31_skew_sm(chartInstance, c31_e_dx, c31_a);
  for (c31_i23 = 0; c31_i23 < 3; c31_i23++) {
    c31_f_dx[c31_i23] = c31_b_dx[c31_i23 + 3];
  }

  c31_skew_sm(chartInstance, c31_f_dx, c31_b);
  c31_eml_scalar_eg(chartInstance);
  c31_eml_scalar_eg(chartInstance);
  c31_threshold(chartInstance);
  for (c31_i24 = 0; c31_i24 < 3; c31_i24++) {
    c31_i25 = 0;
    for (c31_i26 = 0; c31_i26 < 3; c31_i26++) {
      c31_y[c31_i25 + c31_i24] = 0.0;
      c31_i27 = 0;
      for (c31_i28 = 0; c31_i28 < 3; c31_i28++) {
        c31_y[c31_i25 + c31_i24] += c31_a[c31_i27 + c31_i24] * c31_b[c31_i28 +
          c31_i25];
        c31_i27 += 3;
      }

      c31_i25 += 3;
    }
  }

  for (c31_i29 = 0; c31_i29 < 4; c31_i29++) {
    c31_d_x[c31_i29] = c31_b_x[c31_i29 + 3];
  }

  for (c31_i30 = 0; c31_i30 < 3; c31_i30++) {
    c31_d_r[c31_i30] = c31_b_r[c31_i30 + 6] - c31_b_r[c31_i30];
  }

  c31_quatrot(chartInstance, c31_d_x, c31_d_r, c31_b_b);
  c31_b_eml_scalar_eg(chartInstance);
  c31_b_eml_scalar_eg(chartInstance);
  c31_threshold(chartInstance);
  for (c31_i31 = 0; c31_i31 < 3; c31_i31++) {
    c31_c_y[c31_i31] = 0.0;
    c31_i32 = 0;
    for (c31_i33 = 0; c31_i33 < 3; c31_i33++) {
      c31_c_y[c31_i31] += c31_y[c31_i32 + c31_i31] * c31_b_b[c31_i33];
      c31_i32 += 3;
    }
  }

  for (c31_i34 = 0; c31_i34 < 3; c31_i34++) {
    c31_e_x[c31_i34] = c31_b_dx[c31_i34 + 3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c31_b_debug_family_names,
    c31_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_b_nargin, 0U, c31_e_sf_marshallOut,
    c31_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_b_nargout, 1U, c31_e_sf_marshallOut,
    c31_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c31_e_x, 2U, c31_g_sf_marshallOut,
    c31_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c31_X, 3U, c31_f_sf_marshallOut,
    c31_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c31_sfEvent, 3);
  c31_X[0] = 0.0;
  c31_X[3] = -c31_e_x[2];
  c31_X[6] = c31_e_x[1];
  c31_X[1] = c31_e_x[2];
  c31_X[4] = 0.0;
  c31_X[7] = -c31_e_x[0];
  c31_X[2] = -c31_e_x[1];
  c31_X[5] = c31_e_x[0];
  c31_X[8] = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c31_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c31_i35 = 0; c31_i35 < 3; c31_i35++) {
    c31_g_dx[c31_i35] = c31_b_dx[c31_i35 + 3];
  }

  c31_skew_sm(chartInstance, c31_g_dx, c31_a);
  for (c31_i36 = 0; c31_i36 < 9; c31_i36++) {
    c31_b[c31_i36] = c31_X[c31_i36];
  }

  c31_eml_scalar_eg(chartInstance);
  c31_eml_scalar_eg(chartInstance);
  c31_threshold(chartInstance);
  for (c31_i37 = 0; c31_i37 < 3; c31_i37++) {
    c31_i38 = 0;
    for (c31_i39 = 0; c31_i39 < 3; c31_i39++) {
      c31_y[c31_i38 + c31_i37] = 0.0;
      c31_i40 = 0;
      for (c31_i41 = 0; c31_i41 < 3; c31_i41++) {
        c31_y[c31_i38 + c31_i37] += c31_a[c31_i40 + c31_i37] * c31_b[c31_i41 +
          c31_i38];
        c31_i40 += 3;
      }

      c31_i38 += 3;
    }
  }

  for (c31_i42 = 0; c31_i42 < 4; c31_i42++) {
    c31_f_x[c31_i42] = c31_b_x[c31_i42 + 3];
  }

  for (c31_i43 = 0; c31_i43 < 3; c31_i43++) {
    c31_e_r[c31_i43] = c31_b_r[c31_i43 + 9] - c31_b_r[c31_i43];
  }

  c31_quatrot(chartInstance, c31_f_x, c31_e_r, c31_b_b);
  c31_b_eml_scalar_eg(chartInstance);
  c31_b_eml_scalar_eg(chartInstance);
  c31_threshold(chartInstance);
  for (c31_i44 = 0; c31_i44 < 3; c31_i44++) {
    c31_d_y[c31_i44] = 0.0;
    c31_i45 = 0;
    for (c31_i46 = 0; c31_i46 < 3; c31_i46++) {
      c31_d_y[c31_i44] += c31_y[c31_i45 + c31_i44] * c31_b_b[c31_i46];
      c31_i45 += 3;
    }
  }

  for (c31_i47 = 0; c31_i47 < 3; c31_i47++) {
    c31_b_bred[c31_i47] = c31_b_y[c31_i47];
  }

  for (c31_i48 = 0; c31_i48 < 3; c31_i48++) {
    c31_b_bred[c31_i48 + 3] = 0.0;
  }

  for (c31_i49 = 0; c31_i49 < 3; c31_i49++) {
    c31_b_bred[c31_i49 + 6] = c31_c_y[c31_i49];
  }

  for (c31_i50 = 0; c31_i50 < 3; c31_i50++) {
    c31_b_bred[c31_i50 + 9] = 0.0;
  }

  for (c31_i51 = 0; c31_i51 < 3; c31_i51++) {
    c31_b_bred[c31_i51 + 12] = c31_d_y[c31_i51];
  }

  for (c31_i52 = 0; c31_i52 < 3; c31_i52++) {
    c31_b_bred[c31_i52 + 15] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, -2);
  _SFD_SYMBOL_SCOPE_POP();
  for (c31_i53 = 0; c31_i53 < 18; c31_i53++) {
    (*chartInstance->c31_bred)[c31_i53] = c31_b_bred[c31_i53];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c31_sfEvent);
}

static void initSimStructsc31_DIPC(SFc31_DIPCInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c31_skew_sm(SFc31_DIPCInstanceStruct *chartInstance, real_T c31_b_x
  [3], real_T c31_X[9])
{
  uint32_T c31_debug_family_var_map[4];
  real_T c31_nargin = 1.0;
  real_T c31_nargout = 1.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c31_b_debug_family_names,
    c31_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_nargin, 0U, c31_e_sf_marshallOut,
    c31_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_nargout, 1U, c31_e_sf_marshallOut,
    c31_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c31_b_x, 2U, c31_g_sf_marshallOut,
    c31_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c31_X, 3U, c31_f_sf_marshallOut,
    c31_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c31_sfEvent, 3);
  c31_X[0] = 0.0;
  c31_X[3] = -c31_b_x[2];
  c31_X[6] = c31_b_x[1];
  c31_X[1] = c31_b_x[2];
  c31_X[4] = 0.0;
  c31_X[7] = -c31_b_x[0];
  c31_X[2] = -c31_b_x[1];
  c31_X[5] = c31_b_x[0];
  c31_X[8] = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c31_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c31_quatrot(SFc31_DIPCInstanceStruct *chartInstance, real_T c31_q[4],
  real_T c31_b_r[3], real_T c31_rw[3])
{
  uint32_T c31_debug_family_var_map[6];
  real_T c31_rwq[4];
  real_T c31_nargin = 2.0;
  real_T c31_nargout = 1.0;
  int32_T c31_i54;
  real_T c31_b_q[4];
  int32_T c31_k;
  real_T c31_b_k;
  real_T c31_dv2[4];
  int32_T c31_i55;
  int32_T c31_i56;
  real_T c31_c_q[4];
  real_T c31_dv3[4];
  int32_T c31_i57;
  real_T c31_d_q[4];
  int32_T c31_i58;
  real_T c31_dv4[4];
  int32_T c31_i59;
  int32_T c31_i60;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c31_c_debug_family_names,
    c31_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c31_rwq, 0U, c31_h_sf_marshallOut,
    c31_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_nargin, 1U, c31_e_sf_marshallOut,
    c31_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_nargout, 2U, c31_e_sf_marshallOut,
    c31_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c31_q, 3U, c31_h_sf_marshallOut,
    c31_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c31_b_r, 4U, c31_g_sf_marshallOut,
    c31_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c31_rw, 5U, c31_g_sf_marshallOut,
    c31_e_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c31_sfEvent, 4);
  for (c31_i54 = 0; c31_i54 < 4; c31_i54++) {
    c31_b_q[c31_i54] = c31_q[c31_i54];
  }

  for (c31_k = 0; c31_k < 3; c31_k++) {
    c31_b_k = 2.0 + (real_T)c31_k;
    c31_b_q[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c31_b_k), 1, 4, 1, 0) - 1] = -c31_b_q[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", c31_b_k), 1, 4, 1, 0) - 1];
  }

  c31_dv2[0] = 0.0;
  for (c31_i55 = 0; c31_i55 < 3; c31_i55++) {
    c31_dv2[c31_i55 + 1] = c31_b_r[c31_i55];
  }

  for (c31_i56 = 0; c31_i56 < 4; c31_i56++) {
    c31_c_q[c31_i56] = c31_b_q[c31_i56];
  }

  c31_quatmultiply(chartInstance, c31_dv2, c31_c_q, c31_dv3);
  for (c31_i57 = 0; c31_i57 < 4; c31_i57++) {
    c31_d_q[c31_i57] = c31_q[c31_i57];
  }

  for (c31_i58 = 0; c31_i58 < 4; c31_i58++) {
    c31_dv4[c31_i58] = c31_dv3[c31_i58];
  }

  c31_quatmultiply(chartInstance, c31_d_q, c31_dv4, c31_b_q);
  for (c31_i59 = 0; c31_i59 < 4; c31_i59++) {
    c31_rwq[c31_i59] = c31_b_q[c31_i59];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c31_sfEvent, 5);
  for (c31_i60 = 0; c31_i60 < 3; c31_i60++) {
    c31_rw[c31_i60] = c31_rwq[c31_i60 + 1];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c31_sfEvent, -5);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c31_machineNumber, uint32_T
  c31_chartNumber, uint32_T c31_instanceNumber)
{
  (void)c31_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c31_chartNumber, c31_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Martin\\Documents\\Git\\Simulink\\DePascaliErhart\\skew_sm.m"));
  _SFD_SCRIPT_TRANSLATION(c31_chartNumber, c31_instanceNumber, 1U,
    sf_debug_get_script_id(
    "C:\\Users\\Martin\\Documents\\Git\\Simulink\\DePascaliErhart\\quatrot.m"));
}

static const mxArray *c31_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData)
{
  const mxArray *c31_mxArrayOutData = NULL;
  int32_T c31_i61;
  real_T c31_b_inData[18];
  int32_T c31_i62;
  real_T c31_u[18];
  const mxArray *c31_y = NULL;
  SFc31_DIPCInstanceStruct *chartInstance;
  chartInstance = (SFc31_DIPCInstanceStruct *)chartInstanceVoid;
  c31_mxArrayOutData = NULL;
  for (c31_i61 = 0; c31_i61 < 18; c31_i61++) {
    c31_b_inData[c31_i61] = (*(real_T (*)[18])c31_inData)[c31_i61];
  }

  for (c31_i62 = 0; c31_i62 < 18; c31_i62++) {
    c31_u[c31_i62] = c31_b_inData[c31_i62];
  }

  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_create("y", c31_u, 0, 0U, 1U, 0U, 1, 18), false);
  sf_mex_assign(&c31_mxArrayOutData, c31_y, false);
  return c31_mxArrayOutData;
}

static void c31_emlrt_marshallIn(SFc31_DIPCInstanceStruct *chartInstance, const
  mxArray *c31_b_bred, const char_T *c31_identifier, real_T c31_y[18])
{
  emlrtMsgIdentifier c31_thisId;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c31_b_bred), &c31_thisId,
    c31_y);
  sf_mex_destroy(&c31_b_bred);
}

static void c31_b_emlrt_marshallIn(SFc31_DIPCInstanceStruct *chartInstance,
  const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId, real_T c31_y[18])
{
  real_T c31_dv5[18];
  int32_T c31_i63;
  (void)chartInstance;
  sf_mex_import(c31_parentId, sf_mex_dup(c31_u), c31_dv5, 1, 0, 0U, 1, 0U, 1, 18);
  for (c31_i63 = 0; c31_i63 < 18; c31_i63++) {
    c31_y[c31_i63] = c31_dv5[c31_i63];
  }

  sf_mex_destroy(&c31_u);
}

static void c31_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData)
{
  const mxArray *c31_b_bred;
  const char_T *c31_identifier;
  emlrtMsgIdentifier c31_thisId;
  real_T c31_y[18];
  int32_T c31_i64;
  SFc31_DIPCInstanceStruct *chartInstance;
  chartInstance = (SFc31_DIPCInstanceStruct *)chartInstanceVoid;
  c31_b_bred = sf_mex_dup(c31_mxArrayInData);
  c31_identifier = c31_varName;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c31_b_bred), &c31_thisId,
    c31_y);
  sf_mex_destroy(&c31_b_bred);
  for (c31_i64 = 0; c31_i64 < 18; c31_i64++) {
    (*(real_T (*)[18])c31_outData)[c31_i64] = c31_y[c31_i64];
  }

  sf_mex_destroy(&c31_mxArrayInData);
}

static const mxArray *c31_b_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData)
{
  const mxArray *c31_mxArrayOutData = NULL;
  int32_T c31_i65;
  real_T c31_b_inData[24];
  int32_T c31_i66;
  real_T c31_u[24];
  const mxArray *c31_y = NULL;
  SFc31_DIPCInstanceStruct *chartInstance;
  chartInstance = (SFc31_DIPCInstanceStruct *)chartInstanceVoid;
  c31_mxArrayOutData = NULL;
  for (c31_i65 = 0; c31_i65 < 24; c31_i65++) {
    c31_b_inData[c31_i65] = (*(real_T (*)[24])c31_inData)[c31_i65];
  }

  for (c31_i66 = 0; c31_i66 < 24; c31_i66++) {
    c31_u[c31_i66] = c31_b_inData[c31_i66];
  }

  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_create("y", c31_u, 0, 0U, 1U, 0U, 1, 24), false);
  sf_mex_assign(&c31_mxArrayOutData, c31_y, false);
  return c31_mxArrayOutData;
}

static const mxArray *c31_c_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData)
{
  const mxArray *c31_mxArrayOutData = NULL;
  int32_T c31_i67;
  real_T c31_b_inData[28];
  int32_T c31_i68;
  real_T c31_u[28];
  const mxArray *c31_y = NULL;
  SFc31_DIPCInstanceStruct *chartInstance;
  chartInstance = (SFc31_DIPCInstanceStruct *)chartInstanceVoid;
  c31_mxArrayOutData = NULL;
  for (c31_i67 = 0; c31_i67 < 28; c31_i67++) {
    c31_b_inData[c31_i67] = (*(real_T (*)[28])c31_inData)[c31_i67];
  }

  for (c31_i68 = 0; c31_i68 < 28; c31_i68++) {
    c31_u[c31_i68] = c31_b_inData[c31_i68];
  }

  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_create("y", c31_u, 0, 0U, 1U, 0U, 1, 28), false);
  sf_mex_assign(&c31_mxArrayOutData, c31_y, false);
  return c31_mxArrayOutData;
}

static const mxArray *c31_d_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData)
{
  const mxArray *c31_mxArrayOutData = NULL;
  int32_T c31_i69;
  real_T c31_b_inData[12];
  int32_T c31_i70;
  real_T c31_u[12];
  const mxArray *c31_y = NULL;
  SFc31_DIPCInstanceStruct *chartInstance;
  chartInstance = (SFc31_DIPCInstanceStruct *)chartInstanceVoid;
  c31_mxArrayOutData = NULL;
  for (c31_i69 = 0; c31_i69 < 12; c31_i69++) {
    c31_b_inData[c31_i69] = (*(real_T (*)[12])c31_inData)[c31_i69];
  }

  for (c31_i70 = 0; c31_i70 < 12; c31_i70++) {
    c31_u[c31_i70] = c31_b_inData[c31_i70];
  }

  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_create("y", c31_u, 0, 0U, 1U, 0U, 1, 12), false);
  sf_mex_assign(&c31_mxArrayOutData, c31_y, false);
  return c31_mxArrayOutData;
}

static void c31_c_emlrt_marshallIn(SFc31_DIPCInstanceStruct *chartInstance,
  const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId, real_T c31_y[12])
{
  real_T c31_dv6[12];
  int32_T c31_i71;
  (void)chartInstance;
  sf_mex_import(c31_parentId, sf_mex_dup(c31_u), c31_dv6, 1, 0, 0U, 1, 0U, 1, 12);
  for (c31_i71 = 0; c31_i71 < 12; c31_i71++) {
    c31_y[c31_i71] = c31_dv6[c31_i71];
  }

  sf_mex_destroy(&c31_u);
}

static void c31_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData)
{
  const mxArray *c31_b_r;
  const char_T *c31_identifier;
  emlrtMsgIdentifier c31_thisId;
  real_T c31_y[12];
  int32_T c31_i72;
  SFc31_DIPCInstanceStruct *chartInstance;
  chartInstance = (SFc31_DIPCInstanceStruct *)chartInstanceVoid;
  c31_b_r = sf_mex_dup(c31_mxArrayInData);
  c31_identifier = c31_varName;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c31_b_r), &c31_thisId, c31_y);
  sf_mex_destroy(&c31_b_r);
  for (c31_i72 = 0; c31_i72 < 12; c31_i72++) {
    (*(real_T (*)[12])c31_outData)[c31_i72] = c31_y[c31_i72];
  }

  sf_mex_destroy(&c31_mxArrayInData);
}

static const mxArray *c31_e_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData)
{
  const mxArray *c31_mxArrayOutData = NULL;
  real_T c31_u;
  const mxArray *c31_y = NULL;
  SFc31_DIPCInstanceStruct *chartInstance;
  chartInstance = (SFc31_DIPCInstanceStruct *)chartInstanceVoid;
  c31_mxArrayOutData = NULL;
  c31_u = *(real_T *)c31_inData;
  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_create("y", &c31_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c31_mxArrayOutData, c31_y, false);
  return c31_mxArrayOutData;
}

static real_T c31_d_emlrt_marshallIn(SFc31_DIPCInstanceStruct *chartInstance,
  const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId)
{
  real_T c31_y;
  real_T c31_d0;
  (void)chartInstance;
  sf_mex_import(c31_parentId, sf_mex_dup(c31_u), &c31_d0, 1, 0, 0U, 0, 0U, 0);
  c31_y = c31_d0;
  sf_mex_destroy(&c31_u);
  return c31_y;
}

static void c31_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData)
{
  const mxArray *c31_nargout;
  const char_T *c31_identifier;
  emlrtMsgIdentifier c31_thisId;
  real_T c31_y;
  SFc31_DIPCInstanceStruct *chartInstance;
  chartInstance = (SFc31_DIPCInstanceStruct *)chartInstanceVoid;
  c31_nargout = sf_mex_dup(c31_mxArrayInData);
  c31_identifier = c31_varName;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_y = c31_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c31_nargout),
    &c31_thisId);
  sf_mex_destroy(&c31_nargout);
  *(real_T *)c31_outData = c31_y;
  sf_mex_destroy(&c31_mxArrayInData);
}

static const mxArray *c31_f_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData)
{
  const mxArray *c31_mxArrayOutData = NULL;
  int32_T c31_i73;
  int32_T c31_i74;
  int32_T c31_i75;
  real_T c31_b_inData[9];
  int32_T c31_i76;
  int32_T c31_i77;
  int32_T c31_i78;
  real_T c31_u[9];
  const mxArray *c31_y = NULL;
  SFc31_DIPCInstanceStruct *chartInstance;
  chartInstance = (SFc31_DIPCInstanceStruct *)chartInstanceVoid;
  c31_mxArrayOutData = NULL;
  c31_i73 = 0;
  for (c31_i74 = 0; c31_i74 < 3; c31_i74++) {
    for (c31_i75 = 0; c31_i75 < 3; c31_i75++) {
      c31_b_inData[c31_i75 + c31_i73] = (*(real_T (*)[9])c31_inData)[c31_i75 +
        c31_i73];
    }

    c31_i73 += 3;
  }

  c31_i76 = 0;
  for (c31_i77 = 0; c31_i77 < 3; c31_i77++) {
    for (c31_i78 = 0; c31_i78 < 3; c31_i78++) {
      c31_u[c31_i78 + c31_i76] = c31_b_inData[c31_i78 + c31_i76];
    }

    c31_i76 += 3;
  }

  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_create("y", c31_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c31_mxArrayOutData, c31_y, false);
  return c31_mxArrayOutData;
}

static void c31_e_emlrt_marshallIn(SFc31_DIPCInstanceStruct *chartInstance,
  const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId, real_T c31_y[9])
{
  real_T c31_dv7[9];
  int32_T c31_i79;
  (void)chartInstance;
  sf_mex_import(c31_parentId, sf_mex_dup(c31_u), c31_dv7, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c31_i79 = 0; c31_i79 < 9; c31_i79++) {
    c31_y[c31_i79] = c31_dv7[c31_i79];
  }

  sf_mex_destroy(&c31_u);
}

static void c31_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData)
{
  const mxArray *c31_X;
  const char_T *c31_identifier;
  emlrtMsgIdentifier c31_thisId;
  real_T c31_y[9];
  int32_T c31_i80;
  int32_T c31_i81;
  int32_T c31_i82;
  SFc31_DIPCInstanceStruct *chartInstance;
  chartInstance = (SFc31_DIPCInstanceStruct *)chartInstanceVoid;
  c31_X = sf_mex_dup(c31_mxArrayInData);
  c31_identifier = c31_varName;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c31_X), &c31_thisId, c31_y);
  sf_mex_destroy(&c31_X);
  c31_i80 = 0;
  for (c31_i81 = 0; c31_i81 < 3; c31_i81++) {
    for (c31_i82 = 0; c31_i82 < 3; c31_i82++) {
      (*(real_T (*)[9])c31_outData)[c31_i82 + c31_i80] = c31_y[c31_i82 + c31_i80];
    }

    c31_i80 += 3;
  }

  sf_mex_destroy(&c31_mxArrayInData);
}

static const mxArray *c31_g_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData)
{
  const mxArray *c31_mxArrayOutData = NULL;
  int32_T c31_i83;
  real_T c31_b_inData[3];
  int32_T c31_i84;
  real_T c31_u[3];
  const mxArray *c31_y = NULL;
  SFc31_DIPCInstanceStruct *chartInstance;
  chartInstance = (SFc31_DIPCInstanceStruct *)chartInstanceVoid;
  c31_mxArrayOutData = NULL;
  for (c31_i83 = 0; c31_i83 < 3; c31_i83++) {
    c31_b_inData[c31_i83] = (*(real_T (*)[3])c31_inData)[c31_i83];
  }

  for (c31_i84 = 0; c31_i84 < 3; c31_i84++) {
    c31_u[c31_i84] = c31_b_inData[c31_i84];
  }

  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_create("y", c31_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c31_mxArrayOutData, c31_y, false);
  return c31_mxArrayOutData;
}

static void c31_f_emlrt_marshallIn(SFc31_DIPCInstanceStruct *chartInstance,
  const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId, real_T c31_y[3])
{
  real_T c31_dv8[3];
  int32_T c31_i85;
  (void)chartInstance;
  sf_mex_import(c31_parentId, sf_mex_dup(c31_u), c31_dv8, 1, 0, 0U, 1, 0U, 1, 3);
  for (c31_i85 = 0; c31_i85 < 3; c31_i85++) {
    c31_y[c31_i85] = c31_dv8[c31_i85];
  }

  sf_mex_destroy(&c31_u);
}

static void c31_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData)
{
  const mxArray *c31_b_x;
  const char_T *c31_identifier;
  emlrtMsgIdentifier c31_thisId;
  real_T c31_y[3];
  int32_T c31_i86;
  SFc31_DIPCInstanceStruct *chartInstance;
  chartInstance = (SFc31_DIPCInstanceStruct *)chartInstanceVoid;
  c31_b_x = sf_mex_dup(c31_mxArrayInData);
  c31_identifier = c31_varName;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c31_b_x), &c31_thisId, c31_y);
  sf_mex_destroy(&c31_b_x);
  for (c31_i86 = 0; c31_i86 < 3; c31_i86++) {
    (*(real_T (*)[3])c31_outData)[c31_i86] = c31_y[c31_i86];
  }

  sf_mex_destroy(&c31_mxArrayInData);
}

static const mxArray *c31_h_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData)
{
  const mxArray *c31_mxArrayOutData = NULL;
  int32_T c31_i87;
  real_T c31_b_inData[4];
  int32_T c31_i88;
  real_T c31_u[4];
  const mxArray *c31_y = NULL;
  SFc31_DIPCInstanceStruct *chartInstance;
  chartInstance = (SFc31_DIPCInstanceStruct *)chartInstanceVoid;
  c31_mxArrayOutData = NULL;
  for (c31_i87 = 0; c31_i87 < 4; c31_i87++) {
    c31_b_inData[c31_i87] = (*(real_T (*)[4])c31_inData)[c31_i87];
  }

  for (c31_i88 = 0; c31_i88 < 4; c31_i88++) {
    c31_u[c31_i88] = c31_b_inData[c31_i88];
  }

  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_create("y", c31_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c31_mxArrayOutData, c31_y, false);
  return c31_mxArrayOutData;
}

static void c31_g_emlrt_marshallIn(SFc31_DIPCInstanceStruct *chartInstance,
  const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId, real_T c31_y[4])
{
  real_T c31_dv9[4];
  int32_T c31_i89;
  (void)chartInstance;
  sf_mex_import(c31_parentId, sf_mex_dup(c31_u), c31_dv9, 1, 0, 0U, 1, 0U, 1, 4);
  for (c31_i89 = 0; c31_i89 < 4; c31_i89++) {
    c31_y[c31_i89] = c31_dv9[c31_i89];
  }

  sf_mex_destroy(&c31_u);
}

static void c31_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData)
{
  const mxArray *c31_q;
  const char_T *c31_identifier;
  emlrtMsgIdentifier c31_thisId;
  real_T c31_y[4];
  int32_T c31_i90;
  SFc31_DIPCInstanceStruct *chartInstance;
  chartInstance = (SFc31_DIPCInstanceStruct *)chartInstanceVoid;
  c31_q = sf_mex_dup(c31_mxArrayInData);
  c31_identifier = c31_varName;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c31_q), &c31_thisId, c31_y);
  sf_mex_destroy(&c31_q);
  for (c31_i90 = 0; c31_i90 < 4; c31_i90++) {
    (*(real_T (*)[4])c31_outData)[c31_i90] = c31_y[c31_i90];
  }

  sf_mex_destroy(&c31_mxArrayInData);
}

const mxArray *sf_c31_DIPC_get_eml_resolved_functions_info(void)
{
  const mxArray *c31_nameCaptureInfo = NULL;
  c31_nameCaptureInfo = NULL;
  sf_mex_assign(&c31_nameCaptureInfo, sf_mex_createstruct("structure", 2, 25, 1),
                false);
  c31_info_helper(&c31_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c31_nameCaptureInfo);
  return c31_nameCaptureInfo;
}

static void c31_info_helper(const mxArray **c31_info)
{
  const mxArray *c31_rhs0 = NULL;
  const mxArray *c31_lhs0 = NULL;
  const mxArray *c31_rhs1 = NULL;
  const mxArray *c31_lhs1 = NULL;
  const mxArray *c31_rhs2 = NULL;
  const mxArray *c31_lhs2 = NULL;
  const mxArray *c31_rhs3 = NULL;
  const mxArray *c31_lhs3 = NULL;
  const mxArray *c31_rhs4 = NULL;
  const mxArray *c31_lhs4 = NULL;
  const mxArray *c31_rhs5 = NULL;
  const mxArray *c31_lhs5 = NULL;
  const mxArray *c31_rhs6 = NULL;
  const mxArray *c31_lhs6 = NULL;
  const mxArray *c31_rhs7 = NULL;
  const mxArray *c31_lhs7 = NULL;
  const mxArray *c31_rhs8 = NULL;
  const mxArray *c31_lhs8 = NULL;
  const mxArray *c31_rhs9 = NULL;
  const mxArray *c31_lhs9 = NULL;
  const mxArray *c31_rhs10 = NULL;
  const mxArray *c31_lhs10 = NULL;
  const mxArray *c31_rhs11 = NULL;
  const mxArray *c31_lhs11 = NULL;
  const mxArray *c31_rhs12 = NULL;
  const mxArray *c31_lhs12 = NULL;
  const mxArray *c31_rhs13 = NULL;
  const mxArray *c31_lhs13 = NULL;
  const mxArray *c31_rhs14 = NULL;
  const mxArray *c31_lhs14 = NULL;
  const mxArray *c31_rhs15 = NULL;
  const mxArray *c31_lhs15 = NULL;
  const mxArray *c31_rhs16 = NULL;
  const mxArray *c31_lhs16 = NULL;
  const mxArray *c31_rhs17 = NULL;
  const mxArray *c31_lhs17 = NULL;
  const mxArray *c31_rhs18 = NULL;
  const mxArray *c31_lhs18 = NULL;
  const mxArray *c31_rhs19 = NULL;
  const mxArray *c31_lhs19 = NULL;
  const mxArray *c31_rhs20 = NULL;
  const mxArray *c31_lhs20 = NULL;
  const mxArray *c31_rhs21 = NULL;
  const mxArray *c31_lhs21 = NULL;
  const mxArray *c31_rhs22 = NULL;
  const mxArray *c31_lhs22 = NULL;
  const mxArray *c31_rhs23 = NULL;
  const mxArray *c31_lhs23 = NULL;
  const mxArray *c31_rhs24 = NULL;
  const mxArray *c31_lhs24 = NULL;
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("skew_sm"), "name", "name", 0);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DePascaliErhart/skew_sm.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1445505143U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c31_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 1);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1383902494U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c31_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 2);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c31_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 3);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 3);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c31_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 4);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 4);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c31_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 5);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c31_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  6);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1376005890U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c31_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 7);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c31_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 8);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c31_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 9);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 9);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c31_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 10);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 10);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c31_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 11);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 11);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c31_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 12);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 12);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c31_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 13);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 13);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c31_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(""), "context", "context", 14);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("quatrot"), "name", "name",
                  14);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DePascaliErhart/quatrot.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1446631716U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c31_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DePascaliErhart/quatrot.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("quatconj"), "name", "name",
                  15);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatconj.p"), "resolved", "resolved",
                  15);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1410808258U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c31_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DePascaliErhart/quatrot.m"),
                  "context", "context", 16);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("quatmultiply"), "name",
                  "name", 16);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatmultiply.p"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1410808258U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c31_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatmultiply.p"), "context",
                  "context", 17);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("max"), "name", "name", 17);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1311280516U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c31_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 18);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1378321184U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c31_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 19);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 19);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c31_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 20);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 20);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c31_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 21);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 21);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c31_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 22);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 22);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c31_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 23);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 23);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c31_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 24);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 24);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c31_info, c31_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c31_info, c31_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c31_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c31_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c31_info, sf_mex_duplicatearraysafe(&c31_lhs24), "lhs", "lhs",
                  24);
  sf_mex_destroy(&c31_rhs0);
  sf_mex_destroy(&c31_lhs0);
  sf_mex_destroy(&c31_rhs1);
  sf_mex_destroy(&c31_lhs1);
  sf_mex_destroy(&c31_rhs2);
  sf_mex_destroy(&c31_lhs2);
  sf_mex_destroy(&c31_rhs3);
  sf_mex_destroy(&c31_lhs3);
  sf_mex_destroy(&c31_rhs4);
  sf_mex_destroy(&c31_lhs4);
  sf_mex_destroy(&c31_rhs5);
  sf_mex_destroy(&c31_lhs5);
  sf_mex_destroy(&c31_rhs6);
  sf_mex_destroy(&c31_lhs6);
  sf_mex_destroy(&c31_rhs7);
  sf_mex_destroy(&c31_lhs7);
  sf_mex_destroy(&c31_rhs8);
  sf_mex_destroy(&c31_lhs8);
  sf_mex_destroy(&c31_rhs9);
  sf_mex_destroy(&c31_lhs9);
  sf_mex_destroy(&c31_rhs10);
  sf_mex_destroy(&c31_lhs10);
  sf_mex_destroy(&c31_rhs11);
  sf_mex_destroy(&c31_lhs11);
  sf_mex_destroy(&c31_rhs12);
  sf_mex_destroy(&c31_lhs12);
  sf_mex_destroy(&c31_rhs13);
  sf_mex_destroy(&c31_lhs13);
  sf_mex_destroy(&c31_rhs14);
  sf_mex_destroy(&c31_lhs14);
  sf_mex_destroy(&c31_rhs15);
  sf_mex_destroy(&c31_lhs15);
  sf_mex_destroy(&c31_rhs16);
  sf_mex_destroy(&c31_lhs16);
  sf_mex_destroy(&c31_rhs17);
  sf_mex_destroy(&c31_lhs17);
  sf_mex_destroy(&c31_rhs18);
  sf_mex_destroy(&c31_lhs18);
  sf_mex_destroy(&c31_rhs19);
  sf_mex_destroy(&c31_lhs19);
  sf_mex_destroy(&c31_rhs20);
  sf_mex_destroy(&c31_lhs20);
  sf_mex_destroy(&c31_rhs21);
  sf_mex_destroy(&c31_lhs21);
  sf_mex_destroy(&c31_rhs22);
  sf_mex_destroy(&c31_lhs22);
  sf_mex_destroy(&c31_rhs23);
  sf_mex_destroy(&c31_lhs23);
  sf_mex_destroy(&c31_rhs24);
  sf_mex_destroy(&c31_lhs24);
}

static const mxArray *c31_emlrt_marshallOut(const char * c31_u)
{
  const mxArray *c31_y = NULL;
  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_create("y", c31_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c31_u)), false);
  return c31_y;
}

static const mxArray *c31_b_emlrt_marshallOut(const uint32_T c31_u)
{
  const mxArray *c31_y = NULL;
  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_create("y", &c31_u, 7, 0U, 0U, 0U, 0), false);
  return c31_y;
}

static void c31_eml_scalar_eg(SFc31_DIPCInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c31_threshold(SFc31_DIPCInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c31_quatmultiply(SFc31_DIPCInstanceStruct *chartInstance, real_T
  c31_q[4], real_T c31_b_r[4], real_T c31_qout[4])
{
  real_T c31_q1;
  real_T c31_q2;
  real_T c31_q3;
  real_T c31_q4;
  real_T c31_r1;
  real_T c31_r2;
  real_T c31_r3;
  real_T c31_r4;
  (void)chartInstance;
  c31_q1 = c31_q[0];
  c31_q2 = c31_q[1];
  c31_q3 = c31_q[2];
  c31_q4 = c31_q[3];
  c31_r1 = c31_b_r[0];
  c31_r2 = c31_b_r[1];
  c31_r3 = c31_b_r[2];
  c31_r4 = c31_b_r[3];
  c31_qout[0] = ((c31_q1 * c31_r1 - c31_q2 * c31_r2) - c31_q3 * c31_r3) - c31_q4
    * c31_r4;
  c31_qout[1] = (c31_q1 * c31_r2 + c31_r1 * c31_q2) + (c31_q3 * c31_r4 - c31_q4 *
    c31_r3);
  c31_qout[2] = (c31_q1 * c31_r3 + c31_r1 * c31_q3) + (c31_q4 * c31_r2 - c31_q2 *
    c31_r4);
  c31_qout[3] = (c31_q1 * c31_r4 + c31_r1 * c31_q4) + (c31_q2 * c31_r3 - c31_q3 *
    c31_r2);
}

static void c31_b_eml_scalar_eg(SFc31_DIPCInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *c31_i_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData)
{
  const mxArray *c31_mxArrayOutData = NULL;
  int32_T c31_u;
  const mxArray *c31_y = NULL;
  SFc31_DIPCInstanceStruct *chartInstance;
  chartInstance = (SFc31_DIPCInstanceStruct *)chartInstanceVoid;
  c31_mxArrayOutData = NULL;
  c31_u = *(int32_T *)c31_inData;
  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_create("y", &c31_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c31_mxArrayOutData, c31_y, false);
  return c31_mxArrayOutData;
}

static int32_T c31_h_emlrt_marshallIn(SFc31_DIPCInstanceStruct *chartInstance,
  const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId)
{
  int32_T c31_y;
  int32_T c31_i91;
  (void)chartInstance;
  sf_mex_import(c31_parentId, sf_mex_dup(c31_u), &c31_i91, 1, 6, 0U, 0, 0U, 0);
  c31_y = c31_i91;
  sf_mex_destroy(&c31_u);
  return c31_y;
}

static void c31_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData)
{
  const mxArray *c31_b_sfEvent;
  const char_T *c31_identifier;
  emlrtMsgIdentifier c31_thisId;
  int32_T c31_y;
  SFc31_DIPCInstanceStruct *chartInstance;
  chartInstance = (SFc31_DIPCInstanceStruct *)chartInstanceVoid;
  c31_b_sfEvent = sf_mex_dup(c31_mxArrayInData);
  c31_identifier = c31_varName;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_y = c31_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c31_b_sfEvent),
    &c31_thisId);
  sf_mex_destroy(&c31_b_sfEvent);
  *(int32_T *)c31_outData = c31_y;
  sf_mex_destroy(&c31_mxArrayInData);
}

static uint8_T c31_i_emlrt_marshallIn(SFc31_DIPCInstanceStruct *chartInstance,
  const mxArray *c31_b_is_active_c31_DIPC, const char_T *c31_identifier)
{
  uint8_T c31_y;
  emlrtMsgIdentifier c31_thisId;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_y = c31_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c31_b_is_active_c31_DIPC), &c31_thisId);
  sf_mex_destroy(&c31_b_is_active_c31_DIPC);
  return c31_y;
}

static uint8_T c31_j_emlrt_marshallIn(SFc31_DIPCInstanceStruct *chartInstance,
  const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId)
{
  uint8_T c31_y;
  uint8_T c31_u0;
  (void)chartInstance;
  sf_mex_import(c31_parentId, sf_mex_dup(c31_u), &c31_u0, 1, 3, 0U, 0, 0U, 0);
  c31_y = c31_u0;
  sf_mex_destroy(&c31_u);
  return c31_y;
}

static void init_dsm_address_info(SFc31_DIPCInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc31_DIPCInstanceStruct *chartInstance)
{
  chartInstance->c31_x = (real_T (*)[28])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c31_bred = (real_T (*)[18])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c31_dx = (real_T (*)[24])ssGetInputPortSignal_wrapper
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

void sf_c31_DIPC_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4107131104U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2600238230U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2043460046U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(652570667U);
}

mxArray* sf_c31_DIPC_get_post_codegen_info(void);
mxArray *sf_c31_DIPC_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("L4cHfneDxO6L1Btml4R76");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(28);
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
      pr[0] = (double)(24);
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
    mxArray* mxPostCodegenInfo = sf_c31_DIPC_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c31_DIPC_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c31_DIPC_jit_fallback_info(void)
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

mxArray *sf_c31_DIPC_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c31_DIPC_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c31_DIPC(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"bred\",},{M[8],M[0],T\"is_active_c31_DIPC\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c31_DIPC_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc31_DIPCInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc31_DIPCInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DIPCMachineNumber_,
           31,
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
        init_script_number_translation(_DIPCMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_DIPCMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _DIPCMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,10,0,0,"r");
          _SFD_SET_DATA_PROPS(1,1,1,0,"x");
          _SFD_SET_DATA_PROPS(2,2,0,1,"bred");
          _SFD_SET_DATA_PROPS(3,1,1,0,"dx");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,336);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"skew_sm",0,-1,127);
        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"quatrot",0,-1,191);

        {
          unsigned int dimVector[1];
          dimVector[0]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c31_d_sf_marshallOut,(MexInFcnForType)
            c31_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 28;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c31_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 18;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c31_sf_marshallOut,(MexInFcnForType)
            c31_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 24;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c31_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c31_r);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c31_x);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c31_bred);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c31_dx);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _DIPCMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "WuMhkbnscSKHTcaYGq7t0C";
}

static void sf_opaque_initialize_c31_DIPC(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc31_DIPCInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c31_DIPC((SFc31_DIPCInstanceStruct*) chartInstanceVar);
  initialize_c31_DIPC((SFc31_DIPCInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c31_DIPC(void *chartInstanceVar)
{
  enable_c31_DIPC((SFc31_DIPCInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c31_DIPC(void *chartInstanceVar)
{
  disable_c31_DIPC((SFc31_DIPCInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c31_DIPC(void *chartInstanceVar)
{
  sf_gateway_c31_DIPC((SFc31_DIPCInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c31_DIPC(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c31_DIPC((SFc31_DIPCInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c31_DIPC(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c31_DIPC((SFc31_DIPCInstanceStruct*)chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c31_DIPC(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc31_DIPCInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DIPC_optimization_info();
    }

    finalize_c31_DIPC((SFc31_DIPCInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc31_DIPC((SFc31_DIPCInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c31_DIPC(SimStruct *S)
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
    initialize_params_c31_DIPC((SFc31_DIPCInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c31_DIPC(SimStruct *S)
{
  /* Actual parameters from chart:
     r
   */
  const char_T *rtParamNames[] = { "r" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for r*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DIPC_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      31);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,31,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,31,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,31);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,31,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,31,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,31);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(283259703U));
  ssSetChecksum1(S,(1236606528U));
  ssSetChecksum2(S,(483739048U));
  ssSetChecksum3(S,(980283455U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c31_DIPC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c31_DIPC(SimStruct *S)
{
  SFc31_DIPCInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc31_DIPCInstanceStruct *)utMalloc(sizeof
    (SFc31_DIPCInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc31_DIPCInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c31_DIPC;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c31_DIPC;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c31_DIPC;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c31_DIPC;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c31_DIPC;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c31_DIPC;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c31_DIPC;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c31_DIPC;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c31_DIPC;
  chartInstance->chartInfo.mdlStart = mdlStart_c31_DIPC;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c31_DIPC;
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

void c31_DIPC_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c31_DIPC(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c31_DIPC(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c31_DIPC(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c31_DIPC_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

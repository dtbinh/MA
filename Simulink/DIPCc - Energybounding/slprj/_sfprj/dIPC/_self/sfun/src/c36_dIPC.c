/* Include files */

#include <stddef.h>
#include "blas.h"
#include "dIPC_sfun.h"
#include "c36_dIPC.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "dIPC_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c36_debug_family_names[5] = { "nargin", "nargout", "r", "x",
  "G" };

static const char * c36_b_debug_family_names[6] = { "rwq", "nargin", "nargout",
  "q", "r", "rw" };

static const char * c36_c_debug_family_names[4] = { "nargin", "nargout", "x",
  "X" };

/* Function Declarations */
static void initialize_c36_dIPC(SFc36_dIPCInstanceStruct *chartInstance);
static void initialize_params_c36_dIPC(SFc36_dIPCInstanceStruct *chartInstance);
static void enable_c36_dIPC(SFc36_dIPCInstanceStruct *chartInstance);
static void disable_c36_dIPC(SFc36_dIPCInstanceStruct *chartInstance);
static void c36_update_debugger_state_c36_dIPC(SFc36_dIPCInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c36_dIPC(SFc36_dIPCInstanceStruct
  *chartInstance);
static void set_sim_state_c36_dIPC(SFc36_dIPCInstanceStruct *chartInstance,
  const mxArray *c36_st);
static void finalize_c36_dIPC(SFc36_dIPCInstanceStruct *chartInstance);
static void sf_gateway_c36_dIPC(SFc36_dIPCInstanceStruct *chartInstance);
static void mdl_start_c36_dIPC(SFc36_dIPCInstanceStruct *chartInstance);
static void initSimStructsc36_dIPC(SFc36_dIPCInstanceStruct *chartInstance);
static void c36_quatrot(SFc36_dIPCInstanceStruct *chartInstance, real_T c36_q[4],
  real_T c36_b_r[3], real_T c36_rw[3]);
static void init_script_number_translation(uint32_T c36_machineNumber, uint32_T
  c36_chartNumber, uint32_T c36_instanceNumber);
static const mxArray *c36_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static void c36_emlrt_marshallIn(SFc36_dIPCInstanceStruct *chartInstance, const
  mxArray *c36_b_G, const char_T *c36_identifier, real_T c36_y[72]);
static void c36_b_emlrt_marshallIn(SFc36_dIPCInstanceStruct *chartInstance,
  const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId, real_T c36_y[72]);
static void c36_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData);
static const mxArray *c36_b_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static const mxArray *c36_c_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static void c36_c_emlrt_marshallIn(SFc36_dIPCInstanceStruct *chartInstance,
  const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId, real_T c36_y[6]);
static void c36_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData);
static const mxArray *c36_d_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static real_T c36_d_emlrt_marshallIn(SFc36_dIPCInstanceStruct *chartInstance,
  const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId);
static void c36_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData);
static const mxArray *c36_e_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static void c36_e_emlrt_marshallIn(SFc36_dIPCInstanceStruct *chartInstance,
  const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId, real_T c36_y[3]);
static void c36_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData);
static const mxArray *c36_f_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static void c36_f_emlrt_marshallIn(SFc36_dIPCInstanceStruct *chartInstance,
  const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId, real_T c36_y[4]);
static void c36_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData);
static const mxArray *c36_g_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static void c36_g_emlrt_marshallIn(SFc36_dIPCInstanceStruct *chartInstance,
  const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId, real_T c36_y[9]);
static void c36_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData);
static void c36_info_helper(const mxArray **c36_info);
static const mxArray *c36_emlrt_marshallOut(const char * c36_u);
static const mxArray *c36_b_emlrt_marshallOut(const uint32_T c36_u);
static void c36_eye(SFc36_dIPCInstanceStruct *chartInstance, real_T c36_I[9]);
static void c36_quatmultiply(SFc36_dIPCInstanceStruct *chartInstance, real_T
  c36_q[4], real_T c36_b_r[4], real_T c36_qout[4]);
static const mxArray *c36_h_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static int32_T c36_h_emlrt_marshallIn(SFc36_dIPCInstanceStruct *chartInstance,
  const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId);
static void c36_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData);
static uint8_T c36_i_emlrt_marshallIn(SFc36_dIPCInstanceStruct *chartInstance,
  const mxArray *c36_b_is_active_c36_dIPC, const char_T *c36_identifier);
static uint8_T c36_j_emlrt_marshallIn(SFc36_dIPCInstanceStruct *chartInstance,
  const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId);
static void init_dsm_address_info(SFc36_dIPCInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc36_dIPCInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c36_dIPC(SFc36_dIPCInstanceStruct *chartInstance)
{
  chartInstance->c36_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c36_is_active_c36_dIPC = 0U;
}

static void initialize_params_c36_dIPC(SFc36_dIPCInstanceStruct *chartInstance)
{
  real_T c36_dv0[6];
  int32_T c36_i0;
  sf_mex_import_named("r", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      c36_dv0, 0, 0, 0U, 1, 0U, 1, 6);
  for (c36_i0 = 0; c36_i0 < 6; c36_i0++) {
    chartInstance->c36_r[c36_i0] = c36_dv0[c36_i0];
  }
}

static void enable_c36_dIPC(SFc36_dIPCInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c36_dIPC(SFc36_dIPCInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c36_update_debugger_state_c36_dIPC(SFc36_dIPCInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c36_dIPC(SFc36_dIPCInstanceStruct
  *chartInstance)
{
  const mxArray *c36_st;
  const mxArray *c36_y = NULL;
  int32_T c36_i1;
  real_T c36_u[72];
  const mxArray *c36_b_y = NULL;
  uint8_T c36_hoistedGlobal;
  uint8_T c36_b_u;
  const mxArray *c36_c_y = NULL;
  c36_st = NULL;
  c36_st = NULL;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_createcellmatrix(2, 1), false);
  for (c36_i1 = 0; c36_i1 < 72; c36_i1++) {
    c36_u[c36_i1] = (*chartInstance->c36_G)[c36_i1];
  }

  c36_b_y = NULL;
  sf_mex_assign(&c36_b_y, sf_mex_create("y", c36_u, 0, 0U, 1U, 0U, 2, 6, 12),
                false);
  sf_mex_setcell(c36_y, 0, c36_b_y);
  c36_hoistedGlobal = chartInstance->c36_is_active_c36_dIPC;
  c36_b_u = c36_hoistedGlobal;
  c36_c_y = NULL;
  sf_mex_assign(&c36_c_y, sf_mex_create("y", &c36_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c36_y, 1, c36_c_y);
  sf_mex_assign(&c36_st, c36_y, false);
  return c36_st;
}

static void set_sim_state_c36_dIPC(SFc36_dIPCInstanceStruct *chartInstance,
  const mxArray *c36_st)
{
  const mxArray *c36_u;
  real_T c36_dv1[72];
  int32_T c36_i2;
  chartInstance->c36_doneDoubleBufferReInit = true;
  c36_u = sf_mex_dup(c36_st);
  c36_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c36_u, 0)), "G",
                       c36_dv1);
  for (c36_i2 = 0; c36_i2 < 72; c36_i2++) {
    (*chartInstance->c36_G)[c36_i2] = c36_dv1[c36_i2];
  }

  chartInstance->c36_is_active_c36_dIPC = c36_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c36_u, 1)), "is_active_c36_dIPC");
  sf_mex_destroy(&c36_u);
  c36_update_debugger_state_c36_dIPC(chartInstance);
  sf_mex_destroy(&c36_st);
}

static void finalize_c36_dIPC(SFc36_dIPCInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c36_dIPC(SFc36_dIPCInstanceStruct *chartInstance)
{
  int32_T c36_i3;
  int32_T c36_i4;
  real_T c36_b_r[6];
  int32_T c36_i5;
  real_T c36_b_x[14];
  uint32_T c36_debug_family_var_map[5];
  real_T c36_nargin = 2.0;
  real_T c36_nargout = 1.0;
  real_T c36_b_G[72];
  int32_T c36_i6;
  real_T c36_c_x[4];
  int32_T c36_i7;
  real_T c36_c_r[3];
  real_T c36_dv2[3];
  int32_T c36_i8;
  real_T c36_d_x[3];
  uint32_T c36_b_debug_family_var_map[4];
  real_T c36_b_nargin = 1.0;
  real_T c36_b_nargout = 1.0;
  real_T c36_X[9];
  int32_T c36_i9;
  real_T c36_e_x[4];
  int32_T c36_i10;
  real_T c36_d_r[3];
  real_T c36_dv3[3];
  int32_T c36_i11;
  real_T c36_f_x[3];
  real_T c36_c_nargin = 1.0;
  real_T c36_c_nargout = 1.0;
  real_T c36_b_X[9];
  real_T c36_dv4[9];
  real_T c36_dv5[9];
  real_T c36_dv6[9];
  real_T c36_dv7[9];
  int32_T c36_i12;
  int32_T c36_i13;
  int32_T c36_i14;
  int32_T c36_i15;
  int32_T c36_i16;
  int32_T c36_i17;
  int32_T c36_i18;
  int32_T c36_i19;
  int32_T c36_i20;
  int32_T c36_i21;
  int32_T c36_i22;
  int32_T c36_i23;
  int32_T c36_i24;
  int32_T c36_i25;
  int32_T c36_i26;
  int32_T c36_i27;
  int32_T c36_i28;
  int32_T c36_i29;
  int32_T c36_i30;
  int32_T c36_i31;
  int32_T c36_i32;
  int32_T c36_i33;
  int32_T c36_i34;
  int32_T c36_i35;
  int32_T c36_i36;
  int32_T c36_i37;
  int32_T c36_i38;
  int32_T c36_i39;
  int32_T c36_i40;
  int32_T c36_i41;
  int32_T c36_i42;
  int32_T c36_i43;
  int32_T c36_i44;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 15U, chartInstance->c36_sfEvent);
  for (c36_i3 = 0; c36_i3 < 6; c36_i3++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c36_r[c36_i3], 0U);
  }

  chartInstance->c36_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 15U, chartInstance->c36_sfEvent);
  for (c36_i4 = 0; c36_i4 < 6; c36_i4++) {
    c36_b_r[c36_i4] = chartInstance->c36_r[c36_i4];
  }

  for (c36_i5 = 0; c36_i5 < 14; c36_i5++) {
    c36_b_x[c36_i5] = (*chartInstance->c36_x)[c36_i5];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c36_debug_family_names,
    c36_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_nargin, 0U, c36_d_sf_marshallOut,
    c36_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_nargout, 1U, c36_d_sf_marshallOut,
    c36_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c36_b_r, 2U, c36_c_sf_marshallOut,
    c36_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c36_b_x, 3U, c36_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c36_b_G, 4U, c36_sf_marshallOut,
    c36_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 2);
  for (c36_i6 = 0; c36_i6 < 4; c36_i6++) {
    c36_c_x[c36_i6] = c36_b_x[c36_i6 + 3];
  }

  for (c36_i7 = 0; c36_i7 < 3; c36_i7++) {
    c36_c_r[c36_i7] = c36_b_r[c36_i7];
  }

  c36_quatrot(chartInstance, c36_c_x, c36_c_r, c36_dv2);
  for (c36_i8 = 0; c36_i8 < 3; c36_i8++) {
    c36_d_x[c36_i8] = c36_dv2[c36_i8];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c36_c_debug_family_names,
    c36_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_b_nargin, 0U, c36_d_sf_marshallOut,
    c36_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_b_nargout, 1U, c36_d_sf_marshallOut,
    c36_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c36_d_x, 2U, c36_e_sf_marshallOut,
    c36_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c36_X, 3U, c36_g_sf_marshallOut,
    c36_f_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c36_sfEvent, 3);
  c36_X[0] = 0.0;
  c36_X[3] = -c36_d_x[2];
  c36_X[6] = c36_d_x[1];
  c36_X[1] = c36_d_x[2];
  c36_X[4] = 0.0;
  c36_X[7] = -c36_d_x[0];
  c36_X[2] = -c36_d_x[1];
  c36_X[5] = c36_d_x[0];
  c36_X[8] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c36_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c36_i9 = 0; c36_i9 < 4; c36_i9++) {
    c36_e_x[c36_i9] = c36_b_x[c36_i9 + 3];
  }

  for (c36_i10 = 0; c36_i10 < 3; c36_i10++) {
    c36_d_r[c36_i10] = c36_b_r[c36_i10 + 3];
  }

  c36_quatrot(chartInstance, c36_e_x, c36_d_r, c36_dv3);
  for (c36_i11 = 0; c36_i11 < 3; c36_i11++) {
    c36_f_x[c36_i11] = c36_dv3[c36_i11];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c36_c_debug_family_names,
    c36_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_c_nargin, 0U, c36_d_sf_marshallOut,
    c36_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_c_nargout, 1U, c36_d_sf_marshallOut,
    c36_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c36_f_x, 2U, c36_e_sf_marshallOut,
    c36_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c36_b_X, 3U, c36_g_sf_marshallOut,
    c36_f_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c36_sfEvent, 3);
  c36_b_X[0] = 0.0;
  c36_b_X[3] = -c36_f_x[2];
  c36_b_X[6] = c36_f_x[1];
  c36_b_X[1] = c36_f_x[2];
  c36_b_X[4] = 0.0;
  c36_b_X[7] = -c36_f_x[0];
  c36_b_X[2] = -c36_f_x[1];
  c36_b_X[5] = c36_f_x[0];
  c36_b_X[8] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c36_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  c36_eye(chartInstance, c36_dv4);
  c36_eye(chartInstance, c36_dv5);
  c36_eye(chartInstance, c36_dv6);
  c36_eye(chartInstance, c36_dv7);
  c36_i12 = 0;
  c36_i13 = 0;
  for (c36_i14 = 0; c36_i14 < 3; c36_i14++) {
    for (c36_i15 = 0; c36_i15 < 3; c36_i15++) {
      c36_b_G[c36_i15 + c36_i12] = c36_dv4[c36_i15 + c36_i13];
    }

    c36_i12 += 6;
    c36_i13 += 3;
  }

  c36_i16 = 0;
  for (c36_i17 = 0; c36_i17 < 3; c36_i17++) {
    for (c36_i18 = 0; c36_i18 < 3; c36_i18++) {
      c36_b_G[(c36_i18 + c36_i16) + 18] = 0.0;
    }

    c36_i16 += 6;
  }

  c36_i19 = 0;
  c36_i20 = 0;
  for (c36_i21 = 0; c36_i21 < 3; c36_i21++) {
    for (c36_i22 = 0; c36_i22 < 3; c36_i22++) {
      c36_b_G[(c36_i22 + c36_i19) + 36] = c36_dv5[c36_i22 + c36_i20];
    }

    c36_i19 += 6;
    c36_i20 += 3;
  }

  c36_i23 = 0;
  for (c36_i24 = 0; c36_i24 < 3; c36_i24++) {
    for (c36_i25 = 0; c36_i25 < 3; c36_i25++) {
      c36_b_G[(c36_i25 + c36_i23) + 54] = 0.0;
    }

    c36_i23 += 6;
  }

  c36_i26 = 0;
  c36_i27 = 0;
  for (c36_i28 = 0; c36_i28 < 3; c36_i28++) {
    for (c36_i29 = 0; c36_i29 < 3; c36_i29++) {
      c36_b_G[(c36_i29 + c36_i26) + 3] = c36_X[c36_i29 + c36_i27];
    }

    c36_i26 += 6;
    c36_i27 += 3;
  }

  c36_i30 = 0;
  c36_i31 = 0;
  for (c36_i32 = 0; c36_i32 < 3; c36_i32++) {
    for (c36_i33 = 0; c36_i33 < 3; c36_i33++) {
      c36_b_G[(c36_i33 + c36_i30) + 21] = c36_dv6[c36_i33 + c36_i31];
    }

    c36_i30 += 6;
    c36_i31 += 3;
  }

  c36_i34 = 0;
  c36_i35 = 0;
  for (c36_i36 = 0; c36_i36 < 3; c36_i36++) {
    for (c36_i37 = 0; c36_i37 < 3; c36_i37++) {
      c36_b_G[(c36_i37 + c36_i34) + 39] = c36_b_X[c36_i37 + c36_i35];
    }

    c36_i34 += 6;
    c36_i35 += 3;
  }

  c36_i38 = 0;
  c36_i39 = 0;
  for (c36_i40 = 0; c36_i40 < 3; c36_i40++) {
    for (c36_i41 = 0; c36_i41 < 3; c36_i41++) {
      c36_b_G[(c36_i41 + c36_i38) + 57] = c36_dv7[c36_i41 + c36_i39];
    }

    c36_i38 += 6;
    c36_i39 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, -2);
  _SFD_SYMBOL_SCOPE_POP();
  for (c36_i42 = 0; c36_i42 < 72; c36_i42++) {
    (*chartInstance->c36_G)[c36_i42] = c36_b_G[c36_i42];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c36_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_dIPCMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c36_i43 = 0; c36_i43 < 72; c36_i43++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c36_G)[c36_i43], 1U);
  }

  for (c36_i44 = 0; c36_i44 < 14; c36_i44++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c36_x)[c36_i44], 2U);
  }
}

static void mdl_start_c36_dIPC(SFc36_dIPCInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc36_dIPC(SFc36_dIPCInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c36_quatrot(SFc36_dIPCInstanceStruct *chartInstance, real_T c36_q[4],
  real_T c36_b_r[3], real_T c36_rw[3])
{
  uint32_T c36_debug_family_var_map[6];
  real_T c36_rwq[4];
  real_T c36_nargin = 2.0;
  real_T c36_nargout = 1.0;
  int32_T c36_i45;
  real_T c36_b_q[4];
  int32_T c36_k;
  real_T c36_b_k;
  real_T c36_dv8[4];
  int32_T c36_i46;
  int32_T c36_i47;
  real_T c36_c_q[4];
  real_T c36_dv9[4];
  int32_T c36_i48;
  real_T c36_d_q[4];
  int32_T c36_i49;
  real_T c36_dv10[4];
  int32_T c36_i50;
  int32_T c36_i51;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c36_b_debug_family_names,
    c36_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c36_rwq, 0U, c36_f_sf_marshallOut,
    c36_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_nargin, 1U, c36_d_sf_marshallOut,
    c36_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_nargout, 2U, c36_d_sf_marshallOut,
    c36_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c36_q, 3U, c36_f_sf_marshallOut,
    c36_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c36_b_r, 4U, c36_e_sf_marshallOut,
    c36_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c36_rw, 5U, c36_e_sf_marshallOut,
    c36_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c36_sfEvent, 4);
  for (c36_i45 = 0; c36_i45 < 4; c36_i45++) {
    c36_b_q[c36_i45] = c36_q[c36_i45];
  }

  for (c36_k = 0; c36_k < 3; c36_k++) {
    c36_b_k = 2.0 + (real_T)c36_k;
    c36_b_q[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c36_b_k), 1, 4, 1, 0) - 1] = -c36_b_q[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", c36_b_k), 1, 4, 1, 0) - 1];
  }

  c36_dv8[0] = 0.0;
  for (c36_i46 = 0; c36_i46 < 3; c36_i46++) {
    c36_dv8[c36_i46 + 1] = c36_b_r[c36_i46];
  }

  for (c36_i47 = 0; c36_i47 < 4; c36_i47++) {
    c36_c_q[c36_i47] = c36_b_q[c36_i47];
  }

  c36_quatmultiply(chartInstance, c36_dv8, c36_c_q, c36_dv9);
  for (c36_i48 = 0; c36_i48 < 4; c36_i48++) {
    c36_d_q[c36_i48] = c36_q[c36_i48];
  }

  for (c36_i49 = 0; c36_i49 < 4; c36_i49++) {
    c36_dv10[c36_i49] = c36_dv9[c36_i49];
  }

  c36_quatmultiply(chartInstance, c36_d_q, c36_dv10, c36_b_q);
  for (c36_i50 = 0; c36_i50 < 4; c36_i50++) {
    c36_rwq[c36_i50] = c36_b_q[c36_i50];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c36_sfEvent, 5);
  for (c36_i51 = 0; c36_i51 < 3; c36_i51++) {
    c36_rw[c36_i51] = c36_rwq[c36_i51 + 1];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c36_sfEvent, -5);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c36_machineNumber, uint32_T
  c36_chartNumber, uint32_T c36_instanceNumber)
{
  (void)c36_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c36_chartNumber, c36_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Martin\\Documents\\Git\\Simulink\\DIPCc - Energybounding\\quatrot.m"));
  _SFD_SCRIPT_TRANSLATION(c36_chartNumber, c36_instanceNumber, 1U,
    sf_debug_get_script_id(
    "C:\\Users\\Martin\\Documents\\Git\\Simulink\\DIPCc - Energybounding\\skew_sm.m"));
}

static const mxArray *c36_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData)
{
  const mxArray *c36_mxArrayOutData = NULL;
  int32_T c36_i52;
  int32_T c36_i53;
  int32_T c36_i54;
  real_T c36_b_inData[72];
  int32_T c36_i55;
  int32_T c36_i56;
  int32_T c36_i57;
  real_T c36_u[72];
  const mxArray *c36_y = NULL;
  SFc36_dIPCInstanceStruct *chartInstance;
  chartInstance = (SFc36_dIPCInstanceStruct *)chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  c36_i52 = 0;
  for (c36_i53 = 0; c36_i53 < 12; c36_i53++) {
    for (c36_i54 = 0; c36_i54 < 6; c36_i54++) {
      c36_b_inData[c36_i54 + c36_i52] = (*(real_T (*)[72])c36_inData)[c36_i54 +
        c36_i52];
    }

    c36_i52 += 6;
  }

  c36_i55 = 0;
  for (c36_i56 = 0; c36_i56 < 12; c36_i56++) {
    for (c36_i57 = 0; c36_i57 < 6; c36_i57++) {
      c36_u[c36_i57 + c36_i55] = c36_b_inData[c36_i57 + c36_i55];
    }

    c36_i55 += 6;
  }

  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", c36_u, 0, 0U, 1U, 0U, 2, 6, 12),
                false);
  sf_mex_assign(&c36_mxArrayOutData, c36_y, false);
  return c36_mxArrayOutData;
}

static void c36_emlrt_marshallIn(SFc36_dIPCInstanceStruct *chartInstance, const
  mxArray *c36_b_G, const char_T *c36_identifier, real_T c36_y[72])
{
  emlrtMsgIdentifier c36_thisId;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c36_b_G), &c36_thisId, c36_y);
  sf_mex_destroy(&c36_b_G);
}

static void c36_b_emlrt_marshallIn(SFc36_dIPCInstanceStruct *chartInstance,
  const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId, real_T c36_y[72])
{
  real_T c36_dv11[72];
  int32_T c36_i58;
  (void)chartInstance;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_u), c36_dv11, 1, 0, 0U, 1, 0U, 2, 6,
                12);
  for (c36_i58 = 0; c36_i58 < 72; c36_i58++) {
    c36_y[c36_i58] = c36_dv11[c36_i58];
  }

  sf_mex_destroy(&c36_u);
}

static void c36_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData)
{
  const mxArray *c36_b_G;
  const char_T *c36_identifier;
  emlrtMsgIdentifier c36_thisId;
  real_T c36_y[72];
  int32_T c36_i59;
  int32_T c36_i60;
  int32_T c36_i61;
  SFc36_dIPCInstanceStruct *chartInstance;
  chartInstance = (SFc36_dIPCInstanceStruct *)chartInstanceVoid;
  c36_b_G = sf_mex_dup(c36_mxArrayInData);
  c36_identifier = c36_varName;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c36_b_G), &c36_thisId, c36_y);
  sf_mex_destroy(&c36_b_G);
  c36_i59 = 0;
  for (c36_i60 = 0; c36_i60 < 12; c36_i60++) {
    for (c36_i61 = 0; c36_i61 < 6; c36_i61++) {
      (*(real_T (*)[72])c36_outData)[c36_i61 + c36_i59] = c36_y[c36_i61 +
        c36_i59];
    }

    c36_i59 += 6;
  }

  sf_mex_destroy(&c36_mxArrayInData);
}

static const mxArray *c36_b_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData)
{
  const mxArray *c36_mxArrayOutData = NULL;
  int32_T c36_i62;
  real_T c36_b_inData[14];
  int32_T c36_i63;
  real_T c36_u[14];
  const mxArray *c36_y = NULL;
  SFc36_dIPCInstanceStruct *chartInstance;
  chartInstance = (SFc36_dIPCInstanceStruct *)chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  for (c36_i62 = 0; c36_i62 < 14; c36_i62++) {
    c36_b_inData[c36_i62] = (*(real_T (*)[14])c36_inData)[c36_i62];
  }

  for (c36_i63 = 0; c36_i63 < 14; c36_i63++) {
    c36_u[c36_i63] = c36_b_inData[c36_i63];
  }

  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", c36_u, 0, 0U, 1U, 0U, 1, 14), false);
  sf_mex_assign(&c36_mxArrayOutData, c36_y, false);
  return c36_mxArrayOutData;
}

static const mxArray *c36_c_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData)
{
  const mxArray *c36_mxArrayOutData = NULL;
  int32_T c36_i64;
  real_T c36_b_inData[6];
  int32_T c36_i65;
  real_T c36_u[6];
  const mxArray *c36_y = NULL;
  SFc36_dIPCInstanceStruct *chartInstance;
  chartInstance = (SFc36_dIPCInstanceStruct *)chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  for (c36_i64 = 0; c36_i64 < 6; c36_i64++) {
    c36_b_inData[c36_i64] = (*(real_T (*)[6])c36_inData)[c36_i64];
  }

  for (c36_i65 = 0; c36_i65 < 6; c36_i65++) {
    c36_u[c36_i65] = c36_b_inData[c36_i65];
  }

  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", c36_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c36_mxArrayOutData, c36_y, false);
  return c36_mxArrayOutData;
}

static void c36_c_emlrt_marshallIn(SFc36_dIPCInstanceStruct *chartInstance,
  const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId, real_T c36_y[6])
{
  real_T c36_dv12[6];
  int32_T c36_i66;
  (void)chartInstance;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_u), c36_dv12, 1, 0, 0U, 1, 0U, 1, 6);
  for (c36_i66 = 0; c36_i66 < 6; c36_i66++) {
    c36_y[c36_i66] = c36_dv12[c36_i66];
  }

  sf_mex_destroy(&c36_u);
}

static void c36_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData)
{
  const mxArray *c36_b_r;
  const char_T *c36_identifier;
  emlrtMsgIdentifier c36_thisId;
  real_T c36_y[6];
  int32_T c36_i67;
  SFc36_dIPCInstanceStruct *chartInstance;
  chartInstance = (SFc36_dIPCInstanceStruct *)chartInstanceVoid;
  c36_b_r = sf_mex_dup(c36_mxArrayInData);
  c36_identifier = c36_varName;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c36_b_r), &c36_thisId, c36_y);
  sf_mex_destroy(&c36_b_r);
  for (c36_i67 = 0; c36_i67 < 6; c36_i67++) {
    (*(real_T (*)[6])c36_outData)[c36_i67] = c36_y[c36_i67];
  }

  sf_mex_destroy(&c36_mxArrayInData);
}

static const mxArray *c36_d_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData)
{
  const mxArray *c36_mxArrayOutData = NULL;
  real_T c36_u;
  const mxArray *c36_y = NULL;
  SFc36_dIPCInstanceStruct *chartInstance;
  chartInstance = (SFc36_dIPCInstanceStruct *)chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  c36_u = *(real_T *)c36_inData;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", &c36_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c36_mxArrayOutData, c36_y, false);
  return c36_mxArrayOutData;
}

static real_T c36_d_emlrt_marshallIn(SFc36_dIPCInstanceStruct *chartInstance,
  const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId)
{
  real_T c36_y;
  real_T c36_d0;
  (void)chartInstance;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_u), &c36_d0, 1, 0, 0U, 0, 0U, 0);
  c36_y = c36_d0;
  sf_mex_destroy(&c36_u);
  return c36_y;
}

static void c36_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData)
{
  const mxArray *c36_nargout;
  const char_T *c36_identifier;
  emlrtMsgIdentifier c36_thisId;
  real_T c36_y;
  SFc36_dIPCInstanceStruct *chartInstance;
  chartInstance = (SFc36_dIPCInstanceStruct *)chartInstanceVoid;
  c36_nargout = sf_mex_dup(c36_mxArrayInData);
  c36_identifier = c36_varName;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_y = c36_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c36_nargout),
    &c36_thisId);
  sf_mex_destroy(&c36_nargout);
  *(real_T *)c36_outData = c36_y;
  sf_mex_destroy(&c36_mxArrayInData);
}

static const mxArray *c36_e_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData)
{
  const mxArray *c36_mxArrayOutData = NULL;
  int32_T c36_i68;
  real_T c36_b_inData[3];
  int32_T c36_i69;
  real_T c36_u[3];
  const mxArray *c36_y = NULL;
  SFc36_dIPCInstanceStruct *chartInstance;
  chartInstance = (SFc36_dIPCInstanceStruct *)chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  for (c36_i68 = 0; c36_i68 < 3; c36_i68++) {
    c36_b_inData[c36_i68] = (*(real_T (*)[3])c36_inData)[c36_i68];
  }

  for (c36_i69 = 0; c36_i69 < 3; c36_i69++) {
    c36_u[c36_i69] = c36_b_inData[c36_i69];
  }

  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", c36_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c36_mxArrayOutData, c36_y, false);
  return c36_mxArrayOutData;
}

static void c36_e_emlrt_marshallIn(SFc36_dIPCInstanceStruct *chartInstance,
  const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId, real_T c36_y[3])
{
  real_T c36_dv13[3];
  int32_T c36_i70;
  (void)chartInstance;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_u), c36_dv13, 1, 0, 0U, 1, 0U, 1, 3);
  for (c36_i70 = 0; c36_i70 < 3; c36_i70++) {
    c36_y[c36_i70] = c36_dv13[c36_i70];
  }

  sf_mex_destroy(&c36_u);
}

static void c36_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData)
{
  const mxArray *c36_rw;
  const char_T *c36_identifier;
  emlrtMsgIdentifier c36_thisId;
  real_T c36_y[3];
  int32_T c36_i71;
  SFc36_dIPCInstanceStruct *chartInstance;
  chartInstance = (SFc36_dIPCInstanceStruct *)chartInstanceVoid;
  c36_rw = sf_mex_dup(c36_mxArrayInData);
  c36_identifier = c36_varName;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c36_rw), &c36_thisId, c36_y);
  sf_mex_destroy(&c36_rw);
  for (c36_i71 = 0; c36_i71 < 3; c36_i71++) {
    (*(real_T (*)[3])c36_outData)[c36_i71] = c36_y[c36_i71];
  }

  sf_mex_destroy(&c36_mxArrayInData);
}

static const mxArray *c36_f_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData)
{
  const mxArray *c36_mxArrayOutData = NULL;
  int32_T c36_i72;
  real_T c36_b_inData[4];
  int32_T c36_i73;
  real_T c36_u[4];
  const mxArray *c36_y = NULL;
  SFc36_dIPCInstanceStruct *chartInstance;
  chartInstance = (SFc36_dIPCInstanceStruct *)chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  for (c36_i72 = 0; c36_i72 < 4; c36_i72++) {
    c36_b_inData[c36_i72] = (*(real_T (*)[4])c36_inData)[c36_i72];
  }

  for (c36_i73 = 0; c36_i73 < 4; c36_i73++) {
    c36_u[c36_i73] = c36_b_inData[c36_i73];
  }

  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", c36_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c36_mxArrayOutData, c36_y, false);
  return c36_mxArrayOutData;
}

static void c36_f_emlrt_marshallIn(SFc36_dIPCInstanceStruct *chartInstance,
  const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId, real_T c36_y[4])
{
  real_T c36_dv14[4];
  int32_T c36_i74;
  (void)chartInstance;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_u), c36_dv14, 1, 0, 0U, 1, 0U, 1, 4);
  for (c36_i74 = 0; c36_i74 < 4; c36_i74++) {
    c36_y[c36_i74] = c36_dv14[c36_i74];
  }

  sf_mex_destroy(&c36_u);
}

static void c36_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData)
{
  const mxArray *c36_q;
  const char_T *c36_identifier;
  emlrtMsgIdentifier c36_thisId;
  real_T c36_y[4];
  int32_T c36_i75;
  SFc36_dIPCInstanceStruct *chartInstance;
  chartInstance = (SFc36_dIPCInstanceStruct *)chartInstanceVoid;
  c36_q = sf_mex_dup(c36_mxArrayInData);
  c36_identifier = c36_varName;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c36_q), &c36_thisId, c36_y);
  sf_mex_destroy(&c36_q);
  for (c36_i75 = 0; c36_i75 < 4; c36_i75++) {
    (*(real_T (*)[4])c36_outData)[c36_i75] = c36_y[c36_i75];
  }

  sf_mex_destroy(&c36_mxArrayInData);
}

static const mxArray *c36_g_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData)
{
  const mxArray *c36_mxArrayOutData = NULL;
  int32_T c36_i76;
  int32_T c36_i77;
  int32_T c36_i78;
  real_T c36_b_inData[9];
  int32_T c36_i79;
  int32_T c36_i80;
  int32_T c36_i81;
  real_T c36_u[9];
  const mxArray *c36_y = NULL;
  SFc36_dIPCInstanceStruct *chartInstance;
  chartInstance = (SFc36_dIPCInstanceStruct *)chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  c36_i76 = 0;
  for (c36_i77 = 0; c36_i77 < 3; c36_i77++) {
    for (c36_i78 = 0; c36_i78 < 3; c36_i78++) {
      c36_b_inData[c36_i78 + c36_i76] = (*(real_T (*)[9])c36_inData)[c36_i78 +
        c36_i76];
    }

    c36_i76 += 3;
  }

  c36_i79 = 0;
  for (c36_i80 = 0; c36_i80 < 3; c36_i80++) {
    for (c36_i81 = 0; c36_i81 < 3; c36_i81++) {
      c36_u[c36_i81 + c36_i79] = c36_b_inData[c36_i81 + c36_i79];
    }

    c36_i79 += 3;
  }

  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", c36_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c36_mxArrayOutData, c36_y, false);
  return c36_mxArrayOutData;
}

static void c36_g_emlrt_marshallIn(SFc36_dIPCInstanceStruct *chartInstance,
  const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId, real_T c36_y[9])
{
  real_T c36_dv15[9];
  int32_T c36_i82;
  (void)chartInstance;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_u), c36_dv15, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c36_i82 = 0; c36_i82 < 9; c36_i82++) {
    c36_y[c36_i82] = c36_dv15[c36_i82];
  }

  sf_mex_destroy(&c36_u);
}

static void c36_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData)
{
  const mxArray *c36_X;
  const char_T *c36_identifier;
  emlrtMsgIdentifier c36_thisId;
  real_T c36_y[9];
  int32_T c36_i83;
  int32_T c36_i84;
  int32_T c36_i85;
  SFc36_dIPCInstanceStruct *chartInstance;
  chartInstance = (SFc36_dIPCInstanceStruct *)chartInstanceVoid;
  c36_X = sf_mex_dup(c36_mxArrayInData);
  c36_identifier = c36_varName;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c36_X), &c36_thisId, c36_y);
  sf_mex_destroy(&c36_X);
  c36_i83 = 0;
  for (c36_i84 = 0; c36_i84 < 3; c36_i84++) {
    for (c36_i85 = 0; c36_i85 < 3; c36_i85++) {
      (*(real_T (*)[9])c36_outData)[c36_i85 + c36_i83] = c36_y[c36_i85 + c36_i83];
    }

    c36_i83 += 3;
  }

  sf_mex_destroy(&c36_mxArrayInData);
}

const mxArray *sf_c36_dIPC_get_eml_resolved_functions_info(void)
{
  const mxArray *c36_nameCaptureInfo = NULL;
  c36_nameCaptureInfo = NULL;
  sf_mex_assign(&c36_nameCaptureInfo, sf_mex_createstruct("structure", 2, 34, 1),
                false);
  c36_info_helper(&c36_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c36_nameCaptureInfo);
  return c36_nameCaptureInfo;
}

static void c36_info_helper(const mxArray **c36_info)
{
  const mxArray *c36_rhs0 = NULL;
  const mxArray *c36_lhs0 = NULL;
  const mxArray *c36_rhs1 = NULL;
  const mxArray *c36_lhs1 = NULL;
  const mxArray *c36_rhs2 = NULL;
  const mxArray *c36_lhs2 = NULL;
  const mxArray *c36_rhs3 = NULL;
  const mxArray *c36_lhs3 = NULL;
  const mxArray *c36_rhs4 = NULL;
  const mxArray *c36_lhs4 = NULL;
  const mxArray *c36_rhs5 = NULL;
  const mxArray *c36_lhs5 = NULL;
  const mxArray *c36_rhs6 = NULL;
  const mxArray *c36_lhs6 = NULL;
  const mxArray *c36_rhs7 = NULL;
  const mxArray *c36_lhs7 = NULL;
  const mxArray *c36_rhs8 = NULL;
  const mxArray *c36_lhs8 = NULL;
  const mxArray *c36_rhs9 = NULL;
  const mxArray *c36_lhs9 = NULL;
  const mxArray *c36_rhs10 = NULL;
  const mxArray *c36_lhs10 = NULL;
  const mxArray *c36_rhs11 = NULL;
  const mxArray *c36_lhs11 = NULL;
  const mxArray *c36_rhs12 = NULL;
  const mxArray *c36_lhs12 = NULL;
  const mxArray *c36_rhs13 = NULL;
  const mxArray *c36_lhs13 = NULL;
  const mxArray *c36_rhs14 = NULL;
  const mxArray *c36_lhs14 = NULL;
  const mxArray *c36_rhs15 = NULL;
  const mxArray *c36_lhs15 = NULL;
  const mxArray *c36_rhs16 = NULL;
  const mxArray *c36_lhs16 = NULL;
  const mxArray *c36_rhs17 = NULL;
  const mxArray *c36_lhs17 = NULL;
  const mxArray *c36_rhs18 = NULL;
  const mxArray *c36_lhs18 = NULL;
  const mxArray *c36_rhs19 = NULL;
  const mxArray *c36_lhs19 = NULL;
  const mxArray *c36_rhs20 = NULL;
  const mxArray *c36_lhs20 = NULL;
  const mxArray *c36_rhs21 = NULL;
  const mxArray *c36_lhs21 = NULL;
  const mxArray *c36_rhs22 = NULL;
  const mxArray *c36_lhs22 = NULL;
  const mxArray *c36_rhs23 = NULL;
  const mxArray *c36_lhs23 = NULL;
  const mxArray *c36_rhs24 = NULL;
  const mxArray *c36_lhs24 = NULL;
  const mxArray *c36_rhs25 = NULL;
  const mxArray *c36_lhs25 = NULL;
  const mxArray *c36_rhs26 = NULL;
  const mxArray *c36_lhs26 = NULL;
  const mxArray *c36_rhs27 = NULL;
  const mxArray *c36_lhs27 = NULL;
  const mxArray *c36_rhs28 = NULL;
  const mxArray *c36_lhs28 = NULL;
  const mxArray *c36_rhs29 = NULL;
  const mxArray *c36_lhs29 = NULL;
  const mxArray *c36_rhs30 = NULL;
  const mxArray *c36_lhs30 = NULL;
  const mxArray *c36_rhs31 = NULL;
  const mxArray *c36_lhs31 = NULL;
  const mxArray *c36_rhs32 = NULL;
  const mxArray *c36_lhs32 = NULL;
  const mxArray *c36_rhs33 = NULL;
  const mxArray *c36_lhs33 = NULL;
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eye"), "name", "name", 0);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1406838348U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c36_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 1);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1368208230U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c36_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c36_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral"),
                  "context", "context", 3);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("isinf"), "name", "name", 3);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1363739056U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c36_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c36_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 5);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_is_integer_class"),
                  "name", "name", 5);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1286843982U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c36_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 6);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("intmax"), "name", "name", 6);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c36_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 7);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c36_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 8);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("intmin"), "name", "name", 8);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c36_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 9);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c36_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 10);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "coder.internal.indexIntRelop"), "name", "name", 10);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1326753522U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c36_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!apply_float_relop"),
                  "context", "context", 11);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 11);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c36_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass"),
                  "context", "context", 12);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 12);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1326753196U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c36_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass"),
                  "context", "context", 13);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("intmin"), "name", "name", 13);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c36_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 14);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 14);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c36_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("intmax"), "name", "name", 15);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c36_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 16);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1397282622U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c36_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 17);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("isfi"), "name", "name", 17);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 17);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1346535558U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c36_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 18);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1398900798U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c36_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 19);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("intmax"), "name", "name", 19);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c36_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 20);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("intmin"), "name", "name", 20);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c36_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(""), "context", "context", 21);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("quatrot"), "name", "name",
                  21);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DIPCc - Energybounding/quatrot.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1462213506U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c36_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DIPCc - Energybounding/quatrot.m"),
                  "context", "context", 22);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("quatconj"), "name", "name",
                  22);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatconj.p"), "resolved", "resolved",
                  22);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1410808258U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c36_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DIPCc - Energybounding/quatrot.m"),
                  "context", "context", 23);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("quatmultiply"), "name",
                  "name", 23);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatmultiply.p"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1410808258U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c36_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatmultiply.p"), "context",
                  "context", 24);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("max"), "name", "name", 24);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1311280516U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c36_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 25);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1378321184U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c36_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 26);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 26);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c36_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 27);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c36_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 28);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 28);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c36_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 29);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 29);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c36_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 30);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 30);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c36_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 31);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 31);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c36_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 32);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 32);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c36_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(""), "context", "context", 33);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("skew_sm"), "name", "name",
                  33);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DIPCc - Energybounding/skew_sm.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1462213506U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c36_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs33), "lhs", "lhs",
                  33);
  sf_mex_destroy(&c36_rhs0);
  sf_mex_destroy(&c36_lhs0);
  sf_mex_destroy(&c36_rhs1);
  sf_mex_destroy(&c36_lhs1);
  sf_mex_destroy(&c36_rhs2);
  sf_mex_destroy(&c36_lhs2);
  sf_mex_destroy(&c36_rhs3);
  sf_mex_destroy(&c36_lhs3);
  sf_mex_destroy(&c36_rhs4);
  sf_mex_destroy(&c36_lhs4);
  sf_mex_destroy(&c36_rhs5);
  sf_mex_destroy(&c36_lhs5);
  sf_mex_destroy(&c36_rhs6);
  sf_mex_destroy(&c36_lhs6);
  sf_mex_destroy(&c36_rhs7);
  sf_mex_destroy(&c36_lhs7);
  sf_mex_destroy(&c36_rhs8);
  sf_mex_destroy(&c36_lhs8);
  sf_mex_destroy(&c36_rhs9);
  sf_mex_destroy(&c36_lhs9);
  sf_mex_destroy(&c36_rhs10);
  sf_mex_destroy(&c36_lhs10);
  sf_mex_destroy(&c36_rhs11);
  sf_mex_destroy(&c36_lhs11);
  sf_mex_destroy(&c36_rhs12);
  sf_mex_destroy(&c36_lhs12);
  sf_mex_destroy(&c36_rhs13);
  sf_mex_destroy(&c36_lhs13);
  sf_mex_destroy(&c36_rhs14);
  sf_mex_destroy(&c36_lhs14);
  sf_mex_destroy(&c36_rhs15);
  sf_mex_destroy(&c36_lhs15);
  sf_mex_destroy(&c36_rhs16);
  sf_mex_destroy(&c36_lhs16);
  sf_mex_destroy(&c36_rhs17);
  sf_mex_destroy(&c36_lhs17);
  sf_mex_destroy(&c36_rhs18);
  sf_mex_destroy(&c36_lhs18);
  sf_mex_destroy(&c36_rhs19);
  sf_mex_destroy(&c36_lhs19);
  sf_mex_destroy(&c36_rhs20);
  sf_mex_destroy(&c36_lhs20);
  sf_mex_destroy(&c36_rhs21);
  sf_mex_destroy(&c36_lhs21);
  sf_mex_destroy(&c36_rhs22);
  sf_mex_destroy(&c36_lhs22);
  sf_mex_destroy(&c36_rhs23);
  sf_mex_destroy(&c36_lhs23);
  sf_mex_destroy(&c36_rhs24);
  sf_mex_destroy(&c36_lhs24);
  sf_mex_destroy(&c36_rhs25);
  sf_mex_destroy(&c36_lhs25);
  sf_mex_destroy(&c36_rhs26);
  sf_mex_destroy(&c36_lhs26);
  sf_mex_destroy(&c36_rhs27);
  sf_mex_destroy(&c36_lhs27);
  sf_mex_destroy(&c36_rhs28);
  sf_mex_destroy(&c36_lhs28);
  sf_mex_destroy(&c36_rhs29);
  sf_mex_destroy(&c36_lhs29);
  sf_mex_destroy(&c36_rhs30);
  sf_mex_destroy(&c36_lhs30);
  sf_mex_destroy(&c36_rhs31);
  sf_mex_destroy(&c36_lhs31);
  sf_mex_destroy(&c36_rhs32);
  sf_mex_destroy(&c36_lhs32);
  sf_mex_destroy(&c36_rhs33);
  sf_mex_destroy(&c36_lhs33);
}

static const mxArray *c36_emlrt_marshallOut(const char * c36_u)
{
  const mxArray *c36_y = NULL;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", c36_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c36_u)), false);
  return c36_y;
}

static const mxArray *c36_b_emlrt_marshallOut(const uint32_T c36_u)
{
  const mxArray *c36_y = NULL;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", &c36_u, 7, 0U, 0U, 0U, 0), false);
  return c36_y;
}

static void c36_eye(SFc36_dIPCInstanceStruct *chartInstance, real_T c36_I[9])
{
  int32_T c36_i86;
  int32_T c36_k;
  int32_T c36_b_k;
  (void)chartInstance;
  for (c36_i86 = 0; c36_i86 < 9; c36_i86++) {
    c36_I[c36_i86] = 0.0;
  }

  for (c36_k = 1; c36_k < 4; c36_k++) {
    c36_b_k = c36_k;
    c36_I[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
             (real_T)c36_b_k), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c36_b_k), 1, 3, 2, 0) - 1))
      - 1] = 1.0;
  }
}

static void c36_quatmultiply(SFc36_dIPCInstanceStruct *chartInstance, real_T
  c36_q[4], real_T c36_b_r[4], real_T c36_qout[4])
{
  real_T c36_q1;
  real_T c36_q2;
  real_T c36_q3;
  real_T c36_q4;
  real_T c36_r1;
  real_T c36_r2;
  real_T c36_r3;
  real_T c36_r4;
  (void)chartInstance;
  c36_q1 = c36_q[0];
  c36_q2 = c36_q[1];
  c36_q3 = c36_q[2];
  c36_q4 = c36_q[3];
  c36_r1 = c36_b_r[0];
  c36_r2 = c36_b_r[1];
  c36_r3 = c36_b_r[2];
  c36_r4 = c36_b_r[3];
  c36_qout[0] = ((c36_q1 * c36_r1 - c36_q2 * c36_r2) - c36_q3 * c36_r3) - c36_q4
    * c36_r4;
  c36_qout[1] = (c36_q1 * c36_r2 + c36_r1 * c36_q2) + (c36_q3 * c36_r4 - c36_q4 *
    c36_r3);
  c36_qout[2] = (c36_q1 * c36_r3 + c36_r1 * c36_q3) + (c36_q4 * c36_r2 - c36_q2 *
    c36_r4);
  c36_qout[3] = (c36_q1 * c36_r4 + c36_r1 * c36_q4) + (c36_q2 * c36_r3 - c36_q3 *
    c36_r2);
}

static const mxArray *c36_h_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData)
{
  const mxArray *c36_mxArrayOutData = NULL;
  int32_T c36_u;
  const mxArray *c36_y = NULL;
  SFc36_dIPCInstanceStruct *chartInstance;
  chartInstance = (SFc36_dIPCInstanceStruct *)chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  c36_u = *(int32_T *)c36_inData;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", &c36_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c36_mxArrayOutData, c36_y, false);
  return c36_mxArrayOutData;
}

static int32_T c36_h_emlrt_marshallIn(SFc36_dIPCInstanceStruct *chartInstance,
  const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId)
{
  int32_T c36_y;
  int32_T c36_i87;
  (void)chartInstance;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_u), &c36_i87, 1, 6, 0U, 0, 0U, 0);
  c36_y = c36_i87;
  sf_mex_destroy(&c36_u);
  return c36_y;
}

static void c36_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData)
{
  const mxArray *c36_b_sfEvent;
  const char_T *c36_identifier;
  emlrtMsgIdentifier c36_thisId;
  int32_T c36_y;
  SFc36_dIPCInstanceStruct *chartInstance;
  chartInstance = (SFc36_dIPCInstanceStruct *)chartInstanceVoid;
  c36_b_sfEvent = sf_mex_dup(c36_mxArrayInData);
  c36_identifier = c36_varName;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_y = c36_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c36_b_sfEvent),
    &c36_thisId);
  sf_mex_destroy(&c36_b_sfEvent);
  *(int32_T *)c36_outData = c36_y;
  sf_mex_destroy(&c36_mxArrayInData);
}

static uint8_T c36_i_emlrt_marshallIn(SFc36_dIPCInstanceStruct *chartInstance,
  const mxArray *c36_b_is_active_c36_dIPC, const char_T *c36_identifier)
{
  uint8_T c36_y;
  emlrtMsgIdentifier c36_thisId;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_y = c36_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c36_b_is_active_c36_dIPC), &c36_thisId);
  sf_mex_destroy(&c36_b_is_active_c36_dIPC);
  return c36_y;
}

static uint8_T c36_j_emlrt_marshallIn(SFc36_dIPCInstanceStruct *chartInstance,
  const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId)
{
  uint8_T c36_y;
  uint8_T c36_u0;
  (void)chartInstance;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_u), &c36_u0, 1, 3, 0U, 0, 0U, 0);
  c36_y = c36_u0;
  sf_mex_destroy(&c36_u);
  return c36_y;
}

static void init_dsm_address_info(SFc36_dIPCInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc36_dIPCInstanceStruct *chartInstance)
{
  chartInstance->c36_G = (real_T (*)[72])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c36_x = (real_T (*)[14])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
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

void sf_c36_dIPC_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1143120787U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1757361242U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3493220082U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1197228855U);
}

mxArray* sf_c36_dIPC_get_post_codegen_info(void);
mxArray *sf_c36_dIPC_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("NclAjU358XfMasIaGBRAIE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(14);
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
      pr[0] = (double)(6);
      pr[1] = (double)(12);
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
    mxArray* mxPostCodegenInfo = sf_c36_dIPC_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c36_dIPC_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c36_dIPC_jit_fallback_info(void)
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

mxArray *sf_c36_dIPC_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c36_dIPC_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c36_dIPC(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"G\",},{M[8],M[0],T\"is_active_c36_dIPC\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c36_dIPC_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc36_dIPCInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc36_dIPCInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _dIPCMachineNumber_,
           36,
           1,
           1,
           0,
           3,
           0,
           0,
           0,
           0,
           2,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_dIPCMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_dIPCMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _dIPCMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,10,0,0,"r");
          _SFD_SET_DATA_PROPS(1,2,0,1,"G");
          _SFD_SET_DATA_PROPS(2,1,1,0,"x");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,151);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"quatrot",0,-1,191);
        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"skew_sm",0,-1,127);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c36_c_sf_marshallOut,(MexInFcnForType)
            c36_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 6;
          dimVector[1]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c36_sf_marshallOut,(MexInFcnForType)
            c36_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 14;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c36_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c36_r);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c36_G);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c36_x);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _dIPCMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "0zwG4pQUZPlmlLKPpVhTOE";
}

static void sf_opaque_initialize_c36_dIPC(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc36_dIPCInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c36_dIPC((SFc36_dIPCInstanceStruct*) chartInstanceVar);
  initialize_c36_dIPC((SFc36_dIPCInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c36_dIPC(void *chartInstanceVar)
{
  enable_c36_dIPC((SFc36_dIPCInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c36_dIPC(void *chartInstanceVar)
{
  disable_c36_dIPC((SFc36_dIPCInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c36_dIPC(void *chartInstanceVar)
{
  sf_gateway_c36_dIPC((SFc36_dIPCInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c36_dIPC(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c36_dIPC((SFc36_dIPCInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c36_dIPC(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c36_dIPC((SFc36_dIPCInstanceStruct*)chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c36_dIPC(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc36_dIPCInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_dIPC_optimization_info();
    }

    finalize_c36_dIPC((SFc36_dIPCInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc36_dIPC((SFc36_dIPCInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c36_dIPC(SimStruct *S)
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
    initialize_params_c36_dIPC((SFc36_dIPCInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c36_dIPC(SimStruct *S)
{
  /* Actual parameters from chart:
     r
   */
  const char_T *rtParamNames[] = { "r" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for r*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_dIPC_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      36);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,36,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,36,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,36);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,36,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,36,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,36);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(731409632U));
  ssSetChecksum1(S,(928651065U));
  ssSetChecksum2(S,(2324181288U));
  ssSetChecksum3(S,(4267410638U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c36_dIPC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c36_dIPC(SimStruct *S)
{
  SFc36_dIPCInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc36_dIPCInstanceStruct *)utMalloc(sizeof
    (SFc36_dIPCInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc36_dIPCInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c36_dIPC;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c36_dIPC;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c36_dIPC;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c36_dIPC;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c36_dIPC;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c36_dIPC;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c36_dIPC;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c36_dIPC;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c36_dIPC;
  chartInstance->chartInfo.mdlStart = mdlStart_c36_dIPC;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c36_dIPC;
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

void c36_dIPC_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c36_dIPC(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c36_dIPC(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c36_dIPC(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c36_dIPC_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

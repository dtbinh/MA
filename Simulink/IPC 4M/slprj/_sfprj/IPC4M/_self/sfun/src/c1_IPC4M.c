/* Include files */

#include <stddef.h>
#include "blas.h"
#include "IPC4M_sfun.h"
#include "c1_IPC4M.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "IPC4M_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c1_debug_family_names[17] = { "p1", "p2", "p3", "p4", "r1n",
  "r1", "r3n", "r3", "r2", "q0", "q1", "q2", "q3", "nargin", "nargout", "x",
  "x_o" };

static const char * c1_b_debug_family_names[4] = { "nargin", "nargout", "x", "X"
};

/* Function Declarations */
static void initialize_c1_IPC4M(SFc1_IPC4MInstanceStruct *chartInstance);
static void initialize_params_c1_IPC4M(SFc1_IPC4MInstanceStruct *chartInstance);
static void enable_c1_IPC4M(SFc1_IPC4MInstanceStruct *chartInstance);
static void disable_c1_IPC4M(SFc1_IPC4MInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_IPC4M(SFc1_IPC4MInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c1_IPC4M(SFc1_IPC4MInstanceStruct
  *chartInstance);
static void set_sim_state_c1_IPC4M(SFc1_IPC4MInstanceStruct *chartInstance,
  const mxArray *c1_st);
static void finalize_c1_IPC4M(SFc1_IPC4MInstanceStruct *chartInstance);
static void sf_gateway_c1_IPC4M(SFc1_IPC4MInstanceStruct *chartInstance);
static void mdl_start_c1_IPC4M(SFc1_IPC4MInstanceStruct *chartInstance);
static void c1_chartstep_c1_IPC4M(SFc1_IPC4MInstanceStruct *chartInstance);
static void initSimStructsc1_IPC4M(SFc1_IPC4MInstanceStruct *chartInstance);
static void c1_skew_sm(SFc1_IPC4MInstanceStruct *chartInstance, real_T c1_b_x[3],
  real_T c1_X[9]);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_IPC4MInstanceStruct *chartInstance, const
  mxArray *c1_b_x_o, const char_T *c1_identifier, real_T c1_y[7]);
static void c1_b_emlrt_marshallIn(SFc1_IPC4MInstanceStruct *chartInstance, const
  mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[7]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_c_emlrt_marshallIn(SFc1_IPC4MInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_d_emlrt_marshallIn(SFc1_IPC4MInstanceStruct *chartInstance, const
  mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3]);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_e_emlrt_marshallIn(SFc1_IPC4MInstanceStruct *chartInstance, const
  mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[9]);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(const mxArray **c1_info);
static const mxArray *c1_emlrt_marshallOut(const char * c1_u);
static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u);
static real_T c1_norm(SFc1_IPC4MInstanceStruct *chartInstance, real_T c1_b_x[3]);
static real_T c1_eml_xnrm2(SFc1_IPC4MInstanceStruct *chartInstance, real_T
  c1_b_x[3]);
static void c1_below_threshold(SFc1_IPC4MInstanceStruct *chartInstance);
static void c1_eml_scalar_eg(SFc1_IPC4MInstanceStruct *chartInstance);
static void c1_threshold(SFc1_IPC4MInstanceStruct *chartInstance);
static void c1_eml_error(SFc1_IPC4MInstanceStruct *chartInstance);
static void c1_b_eml_scalar_eg(SFc1_IPC4MInstanceStruct *chartInstance);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_f_emlrt_marshallIn(SFc1_IPC4MInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_g_emlrt_marshallIn(SFc1_IPC4MInstanceStruct *chartInstance,
  const mxArray *c1_b_is_active_c1_IPC4M, const char_T *c1_identifier);
static uint8_T c1_h_emlrt_marshallIn(SFc1_IPC4MInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_IPC4MInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc1_IPC4MInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_IPC4M(SFc1_IPC4MInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc1_IPC4M(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_is_active_c1_IPC4M = 0U;
}

static void initialize_params_c1_IPC4M(SFc1_IPC4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_IPC4M(SFc1_IPC4MInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_IPC4M(SFc1_IPC4MInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_IPC4M(SFc1_IPC4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_IPC4M(SFc1_IPC4MInstanceStruct
  *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  const mxArray *c1_b_y = NULL;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_u;
  const mxArray *c1_c_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(2, 1), false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", *chartInstance->c1_x_o, 0, 0U, 1U,
    0U, 1, 7), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_IPC4M;
  c1_u = c1_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_IPC4M(SFc1_IPC4MInstanceStruct *chartInstance,
  const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[7];
  int32_T c1_i0;
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("x_o", c1_u, 0)),
                      "x_o", c1_dv0);
  for (c1_i0 = 0; c1_i0 < 7; c1_i0++) {
    (*chartInstance->c1_x_o)[c1_i0] = c1_dv0[c1_i0];
  }

  chartInstance->c1_is_active_c1_IPC4M = c1_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_active_c1_IPC4M", c1_u, 1)),
    "is_active_c1_IPC4M");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_IPC4M(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_IPC4M(SFc1_IPC4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c1_IPC4M(SFc1_IPC4MInstanceStruct *chartInstance)
{
  int32_T c1_i1;
  int32_T c1_i2;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i1 = 0; c1_i1 < 28; c1_i1++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_x)[c1_i1], 0U, 1U, 0U,
                          chartInstance->c1_sfEvent, false);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_IPC4M(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_IPC4MMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c1_i2 = 0; c1_i2 < 7; c1_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_x_o)[c1_i2], 1U, 1U, 0U,
                          chartInstance->c1_sfEvent, false);
  }
}

static void mdl_start_c1_IPC4M(SFc1_IPC4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_chartstep_c1_IPC4M(SFc1_IPC4MInstanceStruct *chartInstance)
{
  int32_T c1_i3;
  real_T c1_b_x[28];
  uint32_T c1_debug_family_var_map[17];
  real_T c1_p1[3];
  real_T c1_p2[3];
  real_T c1_p3[3];
  real_T c1_p4[3];
  real_T c1_r1n[3];
  real_T c1_r1[3];
  real_T c1_r3n[3];
  real_T c1_r3[3];
  real_T c1_r2[3];
  real_T c1_q0;
  real_T c1_q1;
  real_T c1_q2;
  real_T c1_q3;
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  real_T c1_b_x_o[7];
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  real_T c1_A[3];
  int32_T c1_i9;
  real_T c1_b_p1[3];
  real_T c1_B;
  real_T c1_y;
  real_T c1_b_y;
  real_T c1_c_y;
  int32_T c1_i10;
  int32_T c1_i11;
  real_T c1_b_A[3];
  int32_T c1_i12;
  real_T c1_b_p2[3];
  real_T c1_b_B;
  real_T c1_d_y;
  real_T c1_e_y;
  real_T c1_f_y;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  real_T c1_b_r1n[3];
  real_T c1_c_B;
  real_T c1_g_y;
  real_T c1_h_y;
  real_T c1_i_y;
  int32_T c1_i17;
  int32_T c1_i18;
  real_T c1_c_p1[3];
  real_T c1_a[9];
  int32_T c1_i19;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i30;
  real_T c1_b_r3n[3];
  real_T c1_d_B;
  real_T c1_j_y;
  real_T c1_k_y;
  real_T c1_l_y;
  int32_T c1_i31;
  int32_T c1_i32;
  real_T c1_b_r3[3];
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i40;
  int32_T c1_i41;
  int32_T c1_i42;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_c_A;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_m_y;
  real_T c1_d_A;
  real_T c1_e_B;
  real_T c1_h_x;
  real_T c1_n_y;
  real_T c1_i_x;
  real_T c1_o_y;
  real_T c1_j_x;
  real_T c1_p_y;
  real_T c1_e_A;
  real_T c1_k_x;
  real_T c1_l_x;
  real_T c1_m_x;
  real_T c1_q_y;
  real_T c1_f_A;
  real_T c1_f_B;
  real_T c1_n_x;
  real_T c1_r_y;
  real_T c1_o_x;
  real_T c1_s_y;
  real_T c1_p_x;
  real_T c1_t_y;
  real_T c1_g_A;
  real_T c1_q_x;
  real_T c1_r_x;
  real_T c1_s_x;
  real_T c1_u_y;
  real_T c1_h_A;
  real_T c1_g_B;
  real_T c1_t_x;
  real_T c1_v_y;
  real_T c1_u_x;
  real_T c1_w_y;
  real_T c1_v_x;
  real_T c1_x_y;
  int32_T c1_i43;
  real_T c1_b[28];
  int32_T c1_i44;
  int32_T c1_i45;
  int32_T c1_i46;
  static real_T c1_b_a[84] = { 0.25, 0.0, 0.0, 0.0, 0.25, 0.0, 0.0, 0.0, 0.25,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.25, 0.0, 0.0,
    0.0, 0.25, 0.0, 0.0, 0.0, 0.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.25, 0.0, 0.0, 0.0, 0.25, 0.0, 0.0, 0.0, 0.25, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.25, 0.0, 0.0, 0.0, 0.25, 0.0,
    0.0, 0.0, 0.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c1_i47;
  int32_T c1_i48;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i3 = 0; c1_i3 < 28; c1_i3++) {
    c1_b_x[c1_i3] = (*chartInstance->c1_x)[c1_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 17U, 17U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_p1, 0U, c1_d_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_p2, 1U, c1_d_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_p3, 2U, c1_d_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_p4, 3U, c1_d_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_r1n, 4U, c1_d_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_r1, 5U, c1_d_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_r3n, 6U, c1_d_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_r3, 7U, c1_d_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_r2, 8U, c1_d_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_q0, 9U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_q1, 10U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_q2, 11U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_q3, 12U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 13U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 14U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_b_x, 15U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_b_x_o, 16U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 2);
  for (c1_i4 = 0; c1_i4 < 3; c1_i4++) {
    c1_p1[c1_i4] = c1_b_x[c1_i4];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 2);
  for (c1_i5 = 0; c1_i5 < 3; c1_i5++) {
    c1_p2[c1_i5] = c1_b_x[c1_i5 + 7];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 2);
  for (c1_i6 = 0; c1_i6 < 3; c1_i6++) {
    c1_p3[c1_i6] = c1_b_x[c1_i6 + 14];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 2);
  for (c1_i7 = 0; c1_i7 < 3; c1_i7++) {
    c1_p4[c1_i7] = c1_b_x[c1_i7 + 21];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 3);
  for (c1_i8 = 0; c1_i8 < 3; c1_i8++) {
    c1_A[c1_i8] = c1_p1[c1_i8] - c1_p3[c1_i8];
  }

  for (c1_i9 = 0; c1_i9 < 3; c1_i9++) {
    c1_b_p1[c1_i9] = c1_p1[c1_i9] - c1_p3[c1_i9];
  }

  c1_B = c1_norm(chartInstance, c1_b_p1);
  c1_y = c1_B;
  c1_b_y = c1_y;
  c1_c_y = c1_b_y;
  for (c1_i10 = 0; c1_i10 < 3; c1_i10++) {
    c1_A[c1_i10] /= c1_c_y;
  }

  for (c1_i11 = 0; c1_i11 < 3; c1_i11++) {
    c1_b_A[c1_i11] = c1_p2[c1_i11] - c1_p4[c1_i11];
  }

  for (c1_i12 = 0; c1_i12 < 3; c1_i12++) {
    c1_b_p2[c1_i12] = c1_p2[c1_i12] - c1_p4[c1_i12];
  }

  c1_b_B = c1_norm(chartInstance, c1_b_p2);
  c1_d_y = c1_b_B;
  c1_e_y = c1_d_y;
  c1_f_y = c1_e_y;
  for (c1_i13 = 0; c1_i13 < 3; c1_i13++) {
    c1_b_A[c1_i13] /= c1_f_y;
  }

  for (c1_i14 = 0; c1_i14 < 3; c1_i14++) {
    c1_r1n[c1_i14] = c1_A[c1_i14] + c1_b_A[c1_i14];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  for (c1_i15 = 0; c1_i15 < 3; c1_i15++) {
    c1_A[c1_i15] = c1_r1n[c1_i15];
  }

  for (c1_i16 = 0; c1_i16 < 3; c1_i16++) {
    c1_b_r1n[c1_i16] = c1_r1n[c1_i16];
  }

  c1_c_B = c1_norm(chartInstance, c1_b_r1n);
  c1_g_y = c1_c_B;
  c1_h_y = c1_g_y;
  c1_i_y = c1_h_y;
  for (c1_i17 = 0; c1_i17 < 3; c1_i17++) {
    c1_r1[c1_i17] = c1_A[c1_i17] / c1_i_y;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  for (c1_i18 = 0; c1_i18 < 3; c1_i18++) {
    c1_c_p1[c1_i18] = c1_p1[c1_i18] - c1_p2[c1_i18];
  }

  c1_skew_sm(chartInstance, c1_c_p1, c1_a);
  for (c1_i19 = 0; c1_i19 < 3; c1_i19++) {
    c1_A[c1_i19] = c1_p2[c1_i19] - c1_p4[c1_i19];
  }

  c1_eml_scalar_eg(chartInstance);
  c1_eml_scalar_eg(chartInstance);
  for (c1_i20 = 0; c1_i20 < 3; c1_i20++) {
    c1_r3n[c1_i20] = 0.0;
  }

  for (c1_i21 = 0; c1_i21 < 3; c1_i21++) {
    c1_r3n[c1_i21] = 0.0;
  }

  for (c1_i22 = 0; c1_i22 < 3; c1_i22++) {
    c1_b_A[c1_i22] = c1_r3n[c1_i22];
  }

  for (c1_i23 = 0; c1_i23 < 3; c1_i23++) {
    c1_r3n[c1_i23] = c1_b_A[c1_i23];
  }

  c1_threshold(chartInstance);
  for (c1_i24 = 0; c1_i24 < 3; c1_i24++) {
    c1_b_A[c1_i24] = c1_r3n[c1_i24];
  }

  for (c1_i25 = 0; c1_i25 < 3; c1_i25++) {
    c1_r3n[c1_i25] = c1_b_A[c1_i25];
  }

  for (c1_i26 = 0; c1_i26 < 3; c1_i26++) {
    c1_r3n[c1_i26] = 0.0;
    c1_i27 = 0;
    for (c1_i28 = 0; c1_i28 < 3; c1_i28++) {
      c1_r3n[c1_i26] += c1_a[c1_i27 + c1_i26] * c1_A[c1_i28];
      c1_i27 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i29 = 0; c1_i29 < 3; c1_i29++) {
    c1_A[c1_i29] = c1_r3n[c1_i29];
  }

  for (c1_i30 = 0; c1_i30 < 3; c1_i30++) {
    c1_b_r3n[c1_i30] = c1_r3n[c1_i30];
  }

  c1_d_B = c1_norm(chartInstance, c1_b_r3n);
  c1_j_y = c1_d_B;
  c1_k_y = c1_j_y;
  c1_l_y = c1_k_y;
  for (c1_i31 = 0; c1_i31 < 3; c1_i31++) {
    c1_r3[c1_i31] = c1_A[c1_i31] / c1_l_y;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  for (c1_i32 = 0; c1_i32 < 3; c1_i32++) {
    c1_b_r3[c1_i32] = c1_r3[c1_i32];
  }

  c1_skew_sm(chartInstance, c1_b_r3, c1_a);
  for (c1_i33 = 0; c1_i33 < 3; c1_i33++) {
    c1_A[c1_i33] = c1_r1[c1_i33];
  }

  c1_eml_scalar_eg(chartInstance);
  c1_eml_scalar_eg(chartInstance);
  for (c1_i34 = 0; c1_i34 < 3; c1_i34++) {
    c1_r2[c1_i34] = 0.0;
  }

  for (c1_i35 = 0; c1_i35 < 3; c1_i35++) {
    c1_r2[c1_i35] = 0.0;
  }

  for (c1_i36 = 0; c1_i36 < 3; c1_i36++) {
    c1_b_A[c1_i36] = c1_r2[c1_i36];
  }

  for (c1_i37 = 0; c1_i37 < 3; c1_i37++) {
    c1_r2[c1_i37] = c1_b_A[c1_i37];
  }

  c1_threshold(chartInstance);
  for (c1_i38 = 0; c1_i38 < 3; c1_i38++) {
    c1_b_A[c1_i38] = c1_r2[c1_i38];
  }

  for (c1_i39 = 0; c1_i39 < 3; c1_i39++) {
    c1_r2[c1_i39] = c1_b_A[c1_i39];
  }

  for (c1_i40 = 0; c1_i40 < 3; c1_i40++) {
    c1_r2[c1_i40] = 0.0;
    c1_i41 = 0;
    for (c1_i42 = 0; c1_i42 < 3; c1_i42++) {
      c1_r2[c1_i40] += c1_a[c1_i41 + c1_i40] * c1_A[c1_i42];
      c1_i41 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_c_x = (c1_r1[0] + c1_r2[1]) + c1_r3[2];
  c1_d_x = c1_c_x;
  if (c1_d_x < 0.0) {
    c1_eml_error(chartInstance);
  }

  c1_d_x = muDoubleScalarSqrt(c1_d_x);
  c1_q0 = 0.5 * c1_d_x;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
  c1_c_A = c1_r2[2] - c1_r3[1];
  c1_e_x = c1_c_A;
  c1_f_x = c1_e_x;
  c1_g_x = c1_f_x;
  c1_m_y = c1_g_x / 4.0;
  c1_d_A = c1_m_y;
  c1_e_B = c1_q0;
  c1_h_x = c1_d_A;
  c1_n_y = c1_e_B;
  c1_i_x = c1_h_x;
  c1_o_y = c1_n_y;
  c1_j_x = c1_i_x;
  c1_p_y = c1_o_y;
  c1_q1 = c1_j_x / c1_p_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
  c1_e_A = c1_r3[0] - c1_r1[2];
  c1_k_x = c1_e_A;
  c1_l_x = c1_k_x;
  c1_m_x = c1_l_x;
  c1_q_y = c1_m_x / 4.0;
  c1_f_A = c1_q_y;
  c1_f_B = c1_q0;
  c1_n_x = c1_f_A;
  c1_r_y = c1_f_B;
  c1_o_x = c1_n_x;
  c1_s_y = c1_r_y;
  c1_p_x = c1_o_x;
  c1_t_y = c1_s_y;
  c1_q2 = c1_p_x / c1_t_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
  c1_g_A = c1_r1[1] - c1_r2[0];
  c1_q_x = c1_g_A;
  c1_r_x = c1_q_x;
  c1_s_x = c1_r_x;
  c1_u_y = c1_s_x / 4.0;
  c1_h_A = c1_u_y;
  c1_g_B = c1_q0;
  c1_t_x = c1_h_A;
  c1_v_y = c1_g_B;
  c1_u_x = c1_t_x;
  c1_w_y = c1_v_y;
  c1_v_x = c1_u_x;
  c1_x_y = c1_w_y;
  c1_q3 = c1_v_x / c1_x_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 12);
  for (c1_i43 = 0; c1_i43 < 28; c1_i43++) {
    c1_b[c1_i43] = c1_b_x[c1_i43];
  }

  c1_b_eml_scalar_eg(chartInstance);
  c1_b_eml_scalar_eg(chartInstance);
  c1_threshold(chartInstance);
  for (c1_i44 = 0; c1_i44 < 3; c1_i44++) {
    c1_A[c1_i44] = 0.0;
    c1_i45 = 0;
    for (c1_i46 = 0; c1_i46 < 28; c1_i46++) {
      c1_A[c1_i44] += c1_b_a[c1_i45 + c1_i44] * c1_b[c1_i46];
      c1_i45 += 3;
    }
  }

  for (c1_i47 = 0; c1_i47 < 3; c1_i47++) {
    c1_b_x_o[c1_i47] = c1_A[c1_i47];
  }

  c1_b_x_o[3] = c1_q0;
  c1_b_x_o[4] = c1_q1;
  c1_b_x_o[5] = c1_q2;
  c1_b_x_o[6] = c1_q3;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -12);
  _SFD_SYMBOL_SCOPE_POP();
  for (c1_i48 = 0; c1_i48 < 7; c1_i48++) {
    (*chartInstance->c1_x_o)[c1_i48] = c1_b_x_o[c1_i48];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_IPC4M(SFc1_IPC4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_skew_sm(SFc1_IPC4MInstanceStruct *chartInstance, real_T c1_b_x[3],
  real_T c1_X[9])
{
  uint32_T c1_debug_family_var_map[4];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c1_b_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_b_x, 2U, c1_d_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_X, 3U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  c1_X[0] = 0.0;
  c1_X[3] = -c1_b_x[2];
  c1_X[6] = c1_b_x[1];
  c1_X[1] = c1_b_x[2];
  c1_X[4] = 0.0;
  c1_X[7] = -c1_b_x[0];
  c1_X[2] = -c1_b_x[1];
  c1_X[5] = c1_b_x[0];
  c1_X[8] = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)c1_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, c1_instanceNumber, 0U,
    sf_debug_get_script_id("/home/mangerer/MAgit/MA/Simulink/IPC 4M/skew_sm.m"));
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i49;
  real_T c1_u[7];
  const mxArray *c1_y = NULL;
  SFc1_IPC4MInstanceStruct *chartInstance;
  chartInstance = (SFc1_IPC4MInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i49 = 0; c1_i49 < 7; c1_i49++) {
    c1_u[c1_i49] = (*(real_T (*)[7])c1_inData)[c1_i49];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 7), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_IPC4MInstanceStruct *chartInstance, const
  mxArray *c1_b_x_o, const char_T *c1_identifier, real_T c1_y[7])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_x_o), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_x_o);
}

static void c1_b_emlrt_marshallIn(SFc1_IPC4MInstanceStruct *chartInstance, const
  mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[7])
{
  real_T c1_dv1[7];
  int32_T c1_i50;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv1, 1, 0, 0U, 1, 0U, 1, 7);
  for (c1_i50 = 0; c1_i50 < 7; c1_i50++) {
    c1_y[c1_i50] = c1_dv1[c1_i50];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_x_o;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[7];
  int32_T c1_i51;
  SFc1_IPC4MInstanceStruct *chartInstance;
  chartInstance = (SFc1_IPC4MInstanceStruct *)chartInstanceVoid;
  c1_b_x_o = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_x_o), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_x_o);
  for (c1_i51 = 0; c1_i51 < 7; c1_i51++) {
    (*(real_T (*)[7])c1_outData)[c1_i51] = c1_y[c1_i51];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i52;
  real_T c1_u[28];
  const mxArray *c1_y = NULL;
  SFc1_IPC4MInstanceStruct *chartInstance;
  chartInstance = (SFc1_IPC4MInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i52 = 0; c1_i52 < 28; c1_i52++) {
    c1_u[c1_i52] = (*(real_T (*)[28])c1_inData)[c1_i52];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 28), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_IPC4MInstanceStruct *chartInstance;
  chartInstance = (SFc1_IPC4MInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_c_emlrt_marshallIn(SFc1_IPC4MInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_IPC4MInstanceStruct *chartInstance;
  chartInstance = (SFc1_IPC4MInstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i53;
  real_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_IPC4MInstanceStruct *chartInstance;
  chartInstance = (SFc1_IPC4MInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i53 = 0; c1_i53 < 3; c1_i53++) {
    c1_u[c1_i53] = (*(real_T (*)[3])c1_inData)[c1_i53];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_d_emlrt_marshallIn(SFc1_IPC4MInstanceStruct *chartInstance, const
  mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3])
{
  real_T c1_dv2[3];
  int32_T c1_i54;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv2, 1, 0, 0U, 1, 0U, 1, 3);
  for (c1_i54 = 0; c1_i54 < 3; c1_i54++) {
    c1_y[c1_i54] = c1_dv2[c1_i54];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_r2;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[3];
  int32_T c1_i55;
  SFc1_IPC4MInstanceStruct *chartInstance;
  chartInstance = (SFc1_IPC4MInstanceStruct *)chartInstanceVoid;
  c1_r2 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_r2), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_r2);
  for (c1_i55 = 0; c1_i55 < 3; c1_i55++) {
    (*(real_T (*)[3])c1_outData)[c1_i55] = c1_y[c1_i55];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i56;
  int32_T c1_i57;
  int32_T c1_i58;
  real_T c1_u[9];
  const mxArray *c1_y = NULL;
  SFc1_IPC4MInstanceStruct *chartInstance;
  chartInstance = (SFc1_IPC4MInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i56 = 0;
  for (c1_i57 = 0; c1_i57 < 3; c1_i57++) {
    for (c1_i58 = 0; c1_i58 < 3; c1_i58++) {
      c1_u[c1_i58 + c1_i56] = (*(real_T (*)[9])c1_inData)[c1_i58 + c1_i56];
    }

    c1_i56 += 3;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_e_emlrt_marshallIn(SFc1_IPC4MInstanceStruct *chartInstance, const
  mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[9])
{
  real_T c1_dv3[9];
  int32_T c1_i59;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv3, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c1_i59 = 0; c1_i59 < 9; c1_i59++) {
    c1_y[c1_i59] = c1_dv3[c1_i59];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_X;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[9];
  int32_T c1_i60;
  int32_T c1_i61;
  int32_T c1_i62;
  SFc1_IPC4MInstanceStruct *chartInstance;
  chartInstance = (SFc1_IPC4MInstanceStruct *)chartInstanceVoid;
  c1_X = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_X), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_X);
  c1_i60 = 0;
  for (c1_i61 = 0; c1_i61 < 3; c1_i61++) {
    for (c1_i62 = 0; c1_i62 < 3; c1_i62++) {
      (*(real_T (*)[9])c1_outData)[c1_i62 + c1_i60] = c1_y[c1_i62 + c1_i60];
    }

    c1_i60 += 3;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_IPC4M_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_createstruct("structure", 2, 1, 1),
                false);
  c1_info_helper(&c1_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(const mxArray **c1_info)
{
  const mxArray *c1_rhs0 = NULL;
  const mxArray *c1_lhs0 = NULL;
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("skew_sm"), "name", "name", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[E]/home/mangerer/MAgit/MA/Simulink/IPC 4M/skew_sm.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1445244068U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c1_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs0), "lhs", "lhs", 0);
  sf_mex_destroy(&c1_rhs0);
  sf_mex_destroy(&c1_lhs0);
}

static const mxArray *c1_emlrt_marshallOut(const char * c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c1_u)), false);
  return c1_y;
}

static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 7, 0U, 0U, 0U, 0), false);
  return c1_y;
}

static real_T c1_norm(SFc1_IPC4MInstanceStruct *chartInstance, real_T c1_b_x[3])
{
  int32_T c1_i63;
  real_T c1_c_x[3];
  for (c1_i63 = 0; c1_i63 < 3; c1_i63++) {
    c1_c_x[c1_i63] = c1_b_x[c1_i63];
  }

  return c1_eml_xnrm2(chartInstance, c1_c_x);
}

static real_T c1_eml_xnrm2(SFc1_IPC4MInstanceStruct *chartInstance, real_T
  c1_b_x[3])
{
  real_T c1_y;
  real_T c1_scale;
  int32_T c1_k;
  int32_T c1_b_k;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_absxk;
  real_T c1_t;
  c1_below_threshold(chartInstance);
  c1_y = 0.0;
  c1_scale = 2.2250738585072014E-308;
  for (c1_k = 1; c1_k < 4; c1_k++) {
    c1_b_k = c1_k;
    c1_c_x = c1_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_b_k), 1, 3, 1, 0) - 1];
    c1_d_x = c1_c_x;
    c1_absxk = muDoubleScalarAbs(c1_d_x);
    if (c1_absxk > c1_scale) {
      c1_t = c1_scale / c1_absxk;
      c1_y = 1.0 + c1_y * c1_t * c1_t;
      c1_scale = c1_absxk;
    } else {
      c1_t = c1_absxk / c1_scale;
      c1_y += c1_t * c1_t;
    }
  }

  return c1_scale * muDoubleScalarSqrt(c1_y);
}

static void c1_below_threshold(SFc1_IPC4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_eml_scalar_eg(SFc1_IPC4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_threshold(SFc1_IPC4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_eml_error(SFc1_IPC4MInstanceStruct *chartInstance)
{
  const mxArray *c1_y = NULL;
  static char_T c1_u[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  const mxArray *c1_b_y = NULL;
  static char_T c1_b_u[4] = { 's', 'q', 'r', 't' };

  (void)chartInstance;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 30), false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c1_y, 14, c1_b_y));
}

static void c1_b_eml_scalar_eg(SFc1_IPC4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_IPC4MInstanceStruct *chartInstance;
  chartInstance = (SFc1_IPC4MInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_f_emlrt_marshallIn(SFc1_IPC4MInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i64;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i64, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i64;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_IPC4MInstanceStruct *chartInstance;
  chartInstance = (SFc1_IPC4MInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_g_emlrt_marshallIn(SFc1_IPC4MInstanceStruct *chartInstance,
  const mxArray *c1_b_is_active_c1_IPC4M, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_is_active_c1_IPC4M),
    &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_IPC4M);
  return c1_y;
}

static uint8_T c1_h_emlrt_marshallIn(SFc1_IPC4MInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_IPC4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_IPC4MInstanceStruct *chartInstance)
{
  chartInstance->c1_x_o = (real_T (*)[7])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_x = (real_T (*)[28])ssGetInputPortSignal_wrapper
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

void sf_c1_IPC4M_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4023188164U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(16862653U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1474038210U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2503481304U);
}

mxArray* sf_c1_IPC4M_get_post_codegen_info(void);
mxArray *sf_c1_IPC4M_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("wye9xuVupMYsLhis7zNDWH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(28);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(7);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c1_IPC4M_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_IPC4M_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_IPC4M_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("pre");
  mxArray *fallbackReason = mxCreateString("hasBreakpoints");
  mxArray *hiddenFallbackType = mxCreateString("none");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c1_IPC4M_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c1_IPC4M_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c1_IPC4M(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"x_o\",},{M[8],M[0],T\"is_active_c1_IPC4M\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_IPC4M_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_IPC4MInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc1_IPC4MInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _IPC4MMachineNumber_,
           1,
           1,
           1,
           0,
           2,
           0,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_IPC4MMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_IPC4MMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _IPC4MMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"x");
          _SFD_SET_DATA_PROPS(1,2,0,1,"x_o");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,450);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"skew_sm",0,-1,127);

        {
          unsigned int dimVector[1];
          dimVector[0]= 28;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 7;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _IPC4MMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_IPC4MInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc1_IPC4MInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c1_x_o);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c1_x);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "s4wbWZ6h7rBgtktTaxU1hpB";
}

static void sf_opaque_initialize_c1_IPC4M(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_IPC4MInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c1_IPC4M((SFc1_IPC4MInstanceStruct*) chartInstanceVar);
  initialize_c1_IPC4M((SFc1_IPC4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_IPC4M(void *chartInstanceVar)
{
  enable_c1_IPC4M((SFc1_IPC4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_IPC4M(void *chartInstanceVar)
{
  disable_c1_IPC4M((SFc1_IPC4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_IPC4M(void *chartInstanceVar)
{
  sf_gateway_c1_IPC4M((SFc1_IPC4MInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_IPC4M(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c1_IPC4M((SFc1_IPC4MInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_IPC4M(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c1_IPC4M((SFc1_IPC4MInstanceStruct*)chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c1_IPC4M(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_IPC4MInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_IPC4M_optimization_info();
    }

    finalize_c1_IPC4M((SFc1_IPC4MInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_IPC4M((SFc1_IPC4MInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_IPC4M(SimStruct *S)
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
    initialize_params_c1_IPC4M((SFc1_IPC4MInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_IPC4M(SimStruct *S)
{
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_IPC4M_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2524915713U));
  ssSetChecksum1(S,(3536708836U));
  ssSetChecksum2(S,(1230344490U));
  ssSetChecksum3(S,(1504261061U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_IPC4M(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_IPC4M(SimStruct *S)
{
  SFc1_IPC4MInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc1_IPC4MInstanceStruct *)utMalloc(sizeof
    (SFc1_IPC4MInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_IPC4MInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_IPC4M;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_IPC4M;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_IPC4M;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_IPC4M;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_IPC4M;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_IPC4M;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_IPC4M;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_IPC4M;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_IPC4M;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_IPC4M;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_IPC4M;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->isEnhancedMooreMachine = 0;
  crtInfo->checksum = SF_RUNTIME_INFO_CHECKSUM;
  crtInfo->fCheckOverflow = sf_runtime_overflow_check_is_on(S);
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  crtInfo->compiledInfo = NULL;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
}

void c1_IPC4M_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_IPC4M(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_IPC4M(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_IPC4M(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_IPC4M_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

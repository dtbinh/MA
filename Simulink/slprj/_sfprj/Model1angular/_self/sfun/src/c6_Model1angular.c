/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Model1angular_sfun.h"
#include "c6_Model1angular.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Model1angular_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c6_debug_family_names[10] = { "nargin", "nargout", "r", "m0",
  "m1", "m2", "j0", "j1", "j2", "G_Mplus" };

static const char * c6_b_debug_family_names[4] = { "nargin", "nargout", "x", "X"
};

/* Function Declarations */
static void initialize_c6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance);
static void initialize_params_c6_Model1angular(SFc6_Model1angularInstanceStruct *
  chartInstance);
static void enable_c6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance);
static void disable_c6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance);
static void c6_update_debugger_state_c6_Model1angular
  (SFc6_Model1angularInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c6_Model1angular
  (SFc6_Model1angularInstanceStruct *chartInstance);
static void set_sim_state_c6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_st);
static void finalize_c6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance);
static void sf_gateway_c6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance);
static void mdl_start_c6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance);
static void c6_chartstep_c6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance);
static void initSimStructsc6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static void c6_emlrt_marshallIn(SFc6_Model1angularInstanceStruct *chartInstance,
  const mxArray *c6_b_G_Mplus, const char_T *c6_identifier, real_T c6_y[72]);
static void c6_b_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[72]);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_c_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_d_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[6]);
static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_e_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[9]);
static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_f_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[3]);
static void c6_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static void c6_info_helper(const mxArray **c6_info);
static const mxArray *c6_emlrt_marshallOut(const char * c6_u);
static const mxArray *c6_b_emlrt_marshallOut(const uint32_T c6_u);
static const mxArray *c6_f_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_g_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static uint8_T c6_h_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_Model1angular, const char_T
  *c6_identifier);
static uint8_T c6_i_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void init_dsm_address_info(SFc6_Model1angularInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc6_Model1angularInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance)
{
  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c6_is_active_c6_Model1angular = 0U;
}

static void initialize_params_c6_Model1angular(SFc6_Model1angularInstanceStruct *
  chartInstance)
{
  real_T c6_dv0[6];
  int32_T c6_i0;
  real_T c6_d0;
  real_T c6_d1;
  real_T c6_d2;
  real_T c6_d3;
  real_T c6_d4;
  real_T c6_d5;
  sf_mex_import_named("r", sf_mex_get_sfun_param(chartInstance->S, 6, 0), c6_dv0,
                      0, 0, 0U, 1, 0U, 1, 6);
  for (c6_i0 = 0; c6_i0 < 6; c6_i0++) {
    chartInstance->c6_r[c6_i0] = c6_dv0[c6_i0];
  }

  sf_mex_import_named("m0", sf_mex_get_sfun_param(chartInstance->S, 3, 0),
                      &c6_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c6_m0 = c6_d0;
  sf_mex_import_named("m1", sf_mex_get_sfun_param(chartInstance->S, 4, 0),
                      &c6_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c6_m1 = c6_d1;
  sf_mex_import_named("m2", sf_mex_get_sfun_param(chartInstance->S, 5, 0),
                      &c6_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c6_m2 = c6_d2;
  sf_mex_import_named("j0", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c6_d3, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c6_j0 = c6_d3;
  sf_mex_import_named("j1", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c6_d4, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c6_j1 = c6_d4;
  sf_mex_import_named("j2", sf_mex_get_sfun_param(chartInstance->S, 2, 0),
                      &c6_d5, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c6_j2 = c6_d5;
}

static void enable_c6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c6_update_debugger_state_c6_Model1angular
  (SFc6_Model1angularInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c6_Model1angular
  (SFc6_Model1angularInstanceStruct *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  int32_T c6_i1;
  real_T c6_u[72];
  const mxArray *c6_b_y = NULL;
  uint8_T c6_hoistedGlobal;
  uint8_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellmatrix(2, 1), false);
  for (c6_i1 = 0; c6_i1 < 72; c6_i1++) {
    c6_u[c6_i1] = (*chartInstance->c6_G_Mplus)[c6_i1];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 12, 6),
                false);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_hoistedGlobal = chartInstance->c6_is_active_c6_Model1angular;
  c6_b_u = c6_hoistedGlobal;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  sf_mex_assign(&c6_st, c6_y, false);
  return c6_st;
}

static void set_sim_state_c6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_st)
{
  const mxArray *c6_u;
  real_T c6_dv1[72];
  int32_T c6_i2;
  chartInstance->c6_doneDoubleBufferReInit = true;
  c6_u = sf_mex_dup(c6_st);
  c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 0)),
                      "G_Mplus", c6_dv1);
  for (c6_i2 = 0; c6_i2 < 72; c6_i2++) {
    (*chartInstance->c6_G_Mplus)[c6_i2] = c6_dv1[c6_i2];
  }

  chartInstance->c6_is_active_c6_Model1angular = c6_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 1)),
     "is_active_c6_Model1angular");
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_Model1angular(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance)
{
  int32_T c6_i3;
  int32_T c6_i4;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  for (c6_i3 = 0; c6_i3 < 6; c6_i3++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c6_r[c6_i3], 0U);
  }

  chartInstance->c6_sfEvent = CALL_EVENT;
  c6_chartstep_c6_Model1angular(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Model1angularMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c6_i4 = 0; c6_i4 < 72; c6_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c6_G_Mplus)[c6_i4], 1U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c6_m0, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c6_m1, 3U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c6_m2, 4U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c6_j0, 5U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c6_j1, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c6_j2, 7U);
}

static void mdl_start_c6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c6_chartstep_c6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance)
{
  real_T c6_hoistedGlobal;
  real_T c6_b_hoistedGlobal;
  real_T c6_c_hoistedGlobal;
  real_T c6_d_hoistedGlobal;
  real_T c6_e_hoistedGlobal;
  real_T c6_f_hoistedGlobal;
  int32_T c6_i5;
  real_T c6_b_r[6];
  real_T c6_b_m0;
  real_T c6_b_m1;
  real_T c6_b_m2;
  real_T c6_b_j0;
  real_T c6_b_j1;
  real_T c6_b_j2;
  uint32_T c6_debug_family_var_map[10];
  real_T c6_nargin = 7.0;
  real_T c6_nargout = 1.0;
  real_T c6_b_G_Mplus[72];
  real_T c6_A;
  real_T c6_B;
  real_T c6_x;
  real_T c6_y;
  real_T c6_b_x;
  real_T c6_b_y;
  real_T c6_c_x;
  real_T c6_c_y;
  real_T c6_d_y;
  real_T c6_a;
  int32_T c6_i6;
  static real_T c6_b[9] = { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 };

  real_T c6_e_y[9];
  real_T c6_b_A;
  real_T c6_b_B;
  real_T c6_d_x;
  real_T c6_f_y;
  real_T c6_e_x;
  real_T c6_g_y;
  real_T c6_f_x;
  real_T c6_h_y;
  real_T c6_i_y;
  int32_T c6_i7;
  real_T c6_g_x[3];
  uint32_T c6_b_debug_family_var_map[4];
  real_T c6_b_nargin = 1.0;
  real_T c6_b_nargout = 1.0;
  real_T c6_X[9];
  real_T c6_b_a;
  int32_T c6_i8;
  real_T c6_b_b[9];
  int32_T c6_i9;
  real_T c6_c_A;
  real_T c6_c_B;
  real_T c6_h_x;
  real_T c6_j_y;
  real_T c6_i_x;
  real_T c6_k_y;
  real_T c6_j_x;
  real_T c6_l_y;
  real_T c6_m_y;
  real_T c6_c_a;
  int32_T c6_i10;
  real_T c6_n_y[9];
  real_T c6_d_A;
  real_T c6_d_B;
  real_T c6_k_x;
  real_T c6_o_y;
  real_T c6_l_x;
  real_T c6_p_y;
  real_T c6_m_x;
  real_T c6_q_y;
  real_T c6_r_y;
  real_T c6_d_a;
  int32_T c6_i11;
  real_T c6_s_y[9];
  real_T c6_e_A;
  real_T c6_e_B;
  real_T c6_n_x;
  real_T c6_t_y;
  real_T c6_o_x;
  real_T c6_u_y;
  real_T c6_p_x;
  real_T c6_v_y;
  real_T c6_w_y;
  int32_T c6_i12;
  real_T c6_q_x[3];
  real_T c6_c_nargin = 1.0;
  real_T c6_c_nargout = 1.0;
  real_T c6_b_X[9];
  real_T c6_e_a;
  int32_T c6_i13;
  real_T c6_c_b[9];
  int32_T c6_i14;
  real_T c6_f_A;
  real_T c6_f_B;
  real_T c6_r_x;
  real_T c6_x_y;
  real_T c6_s_x;
  real_T c6_y_y;
  real_T c6_t_x;
  real_T c6_ab_y;
  real_T c6_bb_y;
  real_T c6_f_a;
  int32_T c6_i15;
  real_T c6_cb_y[9];
  int32_T c6_i16;
  int32_T c6_i17;
  int32_T c6_i18;
  int32_T c6_i19;
  int32_T c6_i20;
  int32_T c6_i21;
  int32_T c6_i22;
  int32_T c6_i23;
  int32_T c6_i24;
  int32_T c6_i25;
  int32_T c6_i26;
  int32_T c6_i27;
  int32_T c6_i28;
  int32_T c6_i29;
  int32_T c6_i30;
  int32_T c6_i31;
  int32_T c6_i32;
  int32_T c6_i33;
  int32_T c6_i34;
  int32_T c6_i35;
  int32_T c6_i36;
  int32_T c6_i37;
  int32_T c6_i38;
  int32_T c6_i39;
  int32_T c6_i40;
  int32_T c6_i41;
  int32_T c6_i42;
  int32_T c6_i43;
  int32_T c6_i44;
  int32_T c6_i45;
  int32_T c6_i46;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  c6_hoistedGlobal = chartInstance->c6_m0;
  c6_b_hoistedGlobal = chartInstance->c6_m1;
  c6_c_hoistedGlobal = chartInstance->c6_m2;
  c6_d_hoistedGlobal = chartInstance->c6_j0;
  c6_e_hoistedGlobal = chartInstance->c6_j1;
  c6_f_hoistedGlobal = chartInstance->c6_j2;
  for (c6_i5 = 0; c6_i5 < 6; c6_i5++) {
    c6_b_r[c6_i5] = chartInstance->c6_r[c6_i5];
  }

  c6_b_m0 = c6_hoistedGlobal;
  c6_b_m1 = c6_b_hoistedGlobal;
  c6_b_m2 = c6_c_hoistedGlobal;
  c6_b_j0 = c6_d_hoistedGlobal;
  c6_b_j1 = c6_e_hoistedGlobal;
  c6_b_j2 = c6_f_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c6_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 1U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_b_r, 2U, c6_c_sf_marshallOut,
    c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_m0, 3U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_m1, 4U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_m2, 5U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_j0, 6U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_j1, 7U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_j2, 8U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_b_G_Mplus, 9U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 2);
  c6_A = c6_b_m1;
  c6_B = c6_b_m0;
  c6_x = c6_A;
  c6_y = c6_B;
  c6_b_x = c6_x;
  c6_b_y = c6_y;
  c6_c_x = c6_b_x;
  c6_c_y = c6_b_y;
  c6_d_y = c6_c_x / c6_c_y;
  c6_a = c6_d_y;
  for (c6_i6 = 0; c6_i6 < 9; c6_i6++) {
    c6_e_y[c6_i6] = c6_a * c6_b[c6_i6];
  }

  c6_b_A = c6_b_m1;
  c6_b_B = c6_b_j0;
  c6_d_x = c6_b_A;
  c6_f_y = c6_b_B;
  c6_e_x = c6_d_x;
  c6_g_y = c6_f_y;
  c6_f_x = c6_e_x;
  c6_h_y = c6_g_y;
  c6_i_y = c6_f_x / c6_h_y;
  for (c6_i7 = 0; c6_i7 < 3; c6_i7++) {
    c6_g_x[c6_i7] = c6_b_r[c6_i7];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c6_b_debug_family_names,
    c6_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_nargin, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_nargout, 1U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_g_x, 2U, c6_e_sf_marshallOut,
    c6_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_X, 3U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 3);
  c6_X[0] = 0.0;
  c6_X[3] = -c6_g_x[2];
  c6_X[6] = c6_g_x[1];
  c6_X[1] = c6_g_x[2];
  c6_X[4] = 0.0;
  c6_X[7] = -c6_g_x[0];
  c6_X[2] = -c6_g_x[1];
  c6_X[5] = c6_g_x[0];
  c6_X[8] = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  c6_b_a = c6_i_y;
  for (c6_i8 = 0; c6_i8 < 9; c6_i8++) {
    c6_b_b[c6_i8] = c6_X[c6_i8];
  }

  for (c6_i9 = 0; c6_i9 < 9; c6_i9++) {
    c6_b_b[c6_i9] *= c6_b_a;
  }

  c6_c_A = c6_b_j1;
  c6_c_B = c6_b_j0;
  c6_h_x = c6_c_A;
  c6_j_y = c6_c_B;
  c6_i_x = c6_h_x;
  c6_k_y = c6_j_y;
  c6_j_x = c6_i_x;
  c6_l_y = c6_k_y;
  c6_m_y = c6_j_x / c6_l_y;
  c6_c_a = c6_m_y;
  for (c6_i10 = 0; c6_i10 < 9; c6_i10++) {
    c6_n_y[c6_i10] = c6_c_a * c6_b[c6_i10];
  }

  c6_d_A = c6_b_m2;
  c6_d_B = c6_b_m0;
  c6_k_x = c6_d_A;
  c6_o_y = c6_d_B;
  c6_l_x = c6_k_x;
  c6_p_y = c6_o_y;
  c6_m_x = c6_l_x;
  c6_q_y = c6_p_y;
  c6_r_y = c6_m_x / c6_q_y;
  c6_d_a = c6_r_y;
  for (c6_i11 = 0; c6_i11 < 9; c6_i11++) {
    c6_s_y[c6_i11] = c6_d_a * c6_b[c6_i11];
  }

  c6_e_A = c6_b_m2;
  c6_e_B = c6_b_j0;
  c6_n_x = c6_e_A;
  c6_t_y = c6_e_B;
  c6_o_x = c6_n_x;
  c6_u_y = c6_t_y;
  c6_p_x = c6_o_x;
  c6_v_y = c6_u_y;
  c6_w_y = c6_p_x / c6_v_y;
  for (c6_i12 = 0; c6_i12 < 3; c6_i12++) {
    c6_q_x[c6_i12] = c6_b_r[c6_i12 + 3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c6_b_debug_family_names,
    c6_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_nargin, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_nargout, 1U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_q_x, 2U, c6_e_sf_marshallOut,
    c6_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_b_X, 3U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 3);
  c6_b_X[0] = 0.0;
  c6_b_X[3] = -c6_q_x[2];
  c6_b_X[6] = c6_q_x[1];
  c6_b_X[1] = c6_q_x[2];
  c6_b_X[4] = 0.0;
  c6_b_X[7] = -c6_q_x[0];
  c6_b_X[2] = -c6_q_x[1];
  c6_b_X[5] = c6_q_x[0];
  c6_b_X[8] = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  c6_e_a = c6_w_y;
  for (c6_i13 = 0; c6_i13 < 9; c6_i13++) {
    c6_c_b[c6_i13] = c6_b_X[c6_i13];
  }

  for (c6_i14 = 0; c6_i14 < 9; c6_i14++) {
    c6_c_b[c6_i14] *= c6_e_a;
  }

  c6_f_A = c6_b_j2;
  c6_f_B = c6_b_j0;
  c6_r_x = c6_f_A;
  c6_x_y = c6_f_B;
  c6_s_x = c6_r_x;
  c6_y_y = c6_x_y;
  c6_t_x = c6_s_x;
  c6_ab_y = c6_y_y;
  c6_bb_y = c6_t_x / c6_ab_y;
  c6_f_a = c6_bb_y;
  for (c6_i15 = 0; c6_i15 < 9; c6_i15++) {
    c6_cb_y[c6_i15] = c6_f_a * c6_b[c6_i15];
  }

  c6_i16 = 0;
  c6_i17 = 0;
  for (c6_i18 = 0; c6_i18 < 3; c6_i18++) {
    for (c6_i19 = 0; c6_i19 < 3; c6_i19++) {
      c6_b_G_Mplus[c6_i19 + c6_i16] = c6_e_y[c6_i19 + c6_i17];
    }

    c6_i16 += 12;
    c6_i17 += 3;
  }

  c6_i20 = 0;
  for (c6_i21 = 0; c6_i21 < 3; c6_i21++) {
    c6_i22 = 0;
    for (c6_i23 = 0; c6_i23 < 3; c6_i23++) {
      c6_b_G_Mplus[(c6_i23 + c6_i20) + 36] = c6_b_b[c6_i22 + c6_i21];
      c6_i22 += 3;
    }

    c6_i20 += 12;
  }

  c6_i24 = 0;
  for (c6_i25 = 0; c6_i25 < 3; c6_i25++) {
    for (c6_i26 = 0; c6_i26 < 3; c6_i26++) {
      c6_b_G_Mplus[(c6_i26 + c6_i24) + 3] = 0.0;
    }

    c6_i24 += 12;
  }

  c6_i27 = 0;
  c6_i28 = 0;
  for (c6_i29 = 0; c6_i29 < 3; c6_i29++) {
    for (c6_i30 = 0; c6_i30 < 3; c6_i30++) {
      c6_b_G_Mplus[(c6_i30 + c6_i27) + 39] = c6_n_y[c6_i30 + c6_i28];
    }

    c6_i27 += 12;
    c6_i28 += 3;
  }

  c6_i31 = 0;
  c6_i32 = 0;
  for (c6_i33 = 0; c6_i33 < 3; c6_i33++) {
    for (c6_i34 = 0; c6_i34 < 3; c6_i34++) {
      c6_b_G_Mplus[(c6_i34 + c6_i31) + 6] = c6_s_y[c6_i34 + c6_i32];
    }

    c6_i31 += 12;
    c6_i32 += 3;
  }

  c6_i35 = 0;
  for (c6_i36 = 0; c6_i36 < 3; c6_i36++) {
    c6_i37 = 0;
    for (c6_i38 = 0; c6_i38 < 3; c6_i38++) {
      c6_b_G_Mplus[(c6_i38 + c6_i35) + 42] = c6_c_b[c6_i37 + c6_i36];
      c6_i37 += 3;
    }

    c6_i35 += 12;
  }

  c6_i39 = 0;
  for (c6_i40 = 0; c6_i40 < 3; c6_i40++) {
    for (c6_i41 = 0; c6_i41 < 3; c6_i41++) {
      c6_b_G_Mplus[(c6_i41 + c6_i39) + 9] = 0.0;
    }

    c6_i39 += 12;
  }

  c6_i42 = 0;
  c6_i43 = 0;
  for (c6_i44 = 0; c6_i44 < 3; c6_i44++) {
    for (c6_i45 = 0; c6_i45 < 3; c6_i45++) {
      c6_b_G_Mplus[(c6_i45 + c6_i42) + 45] = c6_cb_y[c6_i45 + c6_i43];
    }

    c6_i42 += 12;
    c6_i43 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -2);
  _SFD_SYMBOL_SCOPE_POP();
  for (c6_i46 = 0; c6_i46 < 72; c6_i46++) {
    (*chartInstance->c6_G_Mplus)[c6_i46] = c6_b_G_Mplus[c6_i46];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
}

static void initSimStructsc6_Model1angular(SFc6_Model1angularInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber)
{
  (void)c6_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c6_chartNumber, c6_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Martin\\Documents\\MATLAB\\Masterarbeit\\skew_sm.m"));
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i47;
  int32_T c6_i48;
  int32_T c6_i49;
  real_T c6_b_inData[72];
  int32_T c6_i50;
  int32_T c6_i51;
  int32_T c6_i52;
  real_T c6_u[72];
  const mxArray *c6_y = NULL;
  SFc6_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc6_Model1angularInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_i47 = 0;
  for (c6_i48 = 0; c6_i48 < 6; c6_i48++) {
    for (c6_i49 = 0; c6_i49 < 12; c6_i49++) {
      c6_b_inData[c6_i49 + c6_i47] = (*(real_T (*)[72])c6_inData)[c6_i49 +
        c6_i47];
    }

    c6_i47 += 12;
  }

  c6_i50 = 0;
  for (c6_i51 = 0; c6_i51 < 6; c6_i51++) {
    for (c6_i52 = 0; c6_i52 < 12; c6_i52++) {
      c6_u[c6_i52 + c6_i50] = c6_b_inData[c6_i52 + c6_i50];
    }

    c6_i50 += 12;
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 12, 6), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static void c6_emlrt_marshallIn(SFc6_Model1angularInstanceStruct *chartInstance,
  const mxArray *c6_b_G_Mplus, const char_T *c6_identifier, real_T c6_y[72])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_G_Mplus), &c6_thisId,
                        c6_y);
  sf_mex_destroy(&c6_b_G_Mplus);
}

static void c6_b_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[72])
{
  real_T c6_dv2[72];
  int32_T c6_i53;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv2, 1, 0, 0U, 1, 0U, 2, 12, 6);
  for (c6_i53 = 0; c6_i53 < 72; c6_i53++) {
    c6_y[c6_i53] = c6_dv2[c6_i53];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_G_Mplus;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[72];
  int32_T c6_i54;
  int32_T c6_i55;
  int32_T c6_i56;
  SFc6_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc6_Model1angularInstanceStruct *)chartInstanceVoid;
  c6_b_G_Mplus = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_G_Mplus), &c6_thisId,
                        c6_y);
  sf_mex_destroy(&c6_b_G_Mplus);
  c6_i54 = 0;
  for (c6_i55 = 0; c6_i55 < 6; c6_i55++) {
    for (c6_i56 = 0; c6_i56 < 12; c6_i56++) {
      (*(real_T (*)[72])c6_outData)[c6_i56 + c6_i54] = c6_y[c6_i56 + c6_i54];
    }

    c6_i54 += 12;
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc6_Model1angularInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static real_T c6_c_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d6;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d6, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d6;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_j2;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc6_Model1angularInstanceStruct *)chartInstanceVoid;
  c6_b_j2 = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_j2), &c6_thisId);
  sf_mex_destroy(&c6_b_j2);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i57;
  real_T c6_b_inData[6];
  int32_T c6_i58;
  real_T c6_u[6];
  const mxArray *c6_y = NULL;
  SFc6_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc6_Model1angularInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i57 = 0; c6_i57 < 6; c6_i57++) {
    c6_b_inData[c6_i57] = (*(real_T (*)[6])c6_inData)[c6_i57];
  }

  for (c6_i58 = 0; c6_i58 < 6; c6_i58++) {
    c6_u[c6_i58] = c6_b_inData[c6_i58];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static void c6_d_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[6])
{
  real_T c6_dv3[6];
  int32_T c6_i59;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv3, 1, 0, 0U, 1, 0U, 1, 6);
  for (c6_i59 = 0; c6_i59 < 6; c6_i59++) {
    c6_y[c6_i59] = c6_dv3[c6_i59];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_r;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[6];
  int32_T c6_i60;
  SFc6_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc6_Model1angularInstanceStruct *)chartInstanceVoid;
  c6_b_r = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_r), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_b_r);
  for (c6_i60 = 0; c6_i60 < 6; c6_i60++) {
    (*(real_T (*)[6])c6_outData)[c6_i60] = c6_y[c6_i60];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i61;
  int32_T c6_i62;
  int32_T c6_i63;
  real_T c6_b_inData[9];
  int32_T c6_i64;
  int32_T c6_i65;
  int32_T c6_i66;
  real_T c6_u[9];
  const mxArray *c6_y = NULL;
  SFc6_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc6_Model1angularInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_i61 = 0;
  for (c6_i62 = 0; c6_i62 < 3; c6_i62++) {
    for (c6_i63 = 0; c6_i63 < 3; c6_i63++) {
      c6_b_inData[c6_i63 + c6_i61] = (*(real_T (*)[9])c6_inData)[c6_i63 + c6_i61];
    }

    c6_i61 += 3;
  }

  c6_i64 = 0;
  for (c6_i65 = 0; c6_i65 < 3; c6_i65++) {
    for (c6_i66 = 0; c6_i66 < 3; c6_i66++) {
      c6_u[c6_i66 + c6_i64] = c6_b_inData[c6_i66 + c6_i64];
    }

    c6_i64 += 3;
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static void c6_e_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[9])
{
  real_T c6_dv4[9];
  int32_T c6_i67;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv4, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c6_i67 = 0; c6_i67 < 9; c6_i67++) {
    c6_y[c6_i67] = c6_dv4[c6_i67];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_X;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[9];
  int32_T c6_i68;
  int32_T c6_i69;
  int32_T c6_i70;
  SFc6_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc6_Model1angularInstanceStruct *)chartInstanceVoid;
  c6_X = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_X), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_X);
  c6_i68 = 0;
  for (c6_i69 = 0; c6_i69 < 3; c6_i69++) {
    for (c6_i70 = 0; c6_i70 < 3; c6_i70++) {
      (*(real_T (*)[9])c6_outData)[c6_i70 + c6_i68] = c6_y[c6_i70 + c6_i68];
    }

    c6_i68 += 3;
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i71;
  real_T c6_b_inData[3];
  int32_T c6_i72;
  real_T c6_u[3];
  const mxArray *c6_y = NULL;
  SFc6_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc6_Model1angularInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i71 = 0; c6_i71 < 3; c6_i71++) {
    c6_b_inData[c6_i71] = (*(real_T (*)[3])c6_inData)[c6_i71];
  }

  for (c6_i72 = 0; c6_i72 < 3; c6_i72++) {
    c6_u[c6_i72] = c6_b_inData[c6_i72];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static void c6_f_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[3])
{
  real_T c6_dv5[3];
  int32_T c6_i73;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv5, 1, 0, 0U, 1, 0U, 1, 3);
  for (c6_i73 = 0; c6_i73 < 3; c6_i73++) {
    c6_y[c6_i73] = c6_dv5[c6_i73];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_x;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[3];
  int32_T c6_i74;
  SFc6_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc6_Model1angularInstanceStruct *)chartInstanceVoid;
  c6_x = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_x), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_x);
  for (c6_i74 = 0; c6_i74 < 3; c6_i74++) {
    (*(real_T (*)[3])c6_outData)[c6_i74] = c6_y[c6_i74];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

const mxArray *sf_c6_Model1angular_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  sf_mex_assign(&c6_nameCaptureInfo, sf_mex_createstruct("structure", 2, 31, 1),
                false);
  c6_info_helper(&c6_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c6_nameCaptureInfo);
  return c6_nameCaptureInfo;
}

static void c6_info_helper(const mxArray **c6_info)
{
  const mxArray *c6_rhs0 = NULL;
  const mxArray *c6_lhs0 = NULL;
  const mxArray *c6_rhs1 = NULL;
  const mxArray *c6_lhs1 = NULL;
  const mxArray *c6_rhs2 = NULL;
  const mxArray *c6_lhs2 = NULL;
  const mxArray *c6_rhs3 = NULL;
  const mxArray *c6_lhs3 = NULL;
  const mxArray *c6_rhs4 = NULL;
  const mxArray *c6_lhs4 = NULL;
  const mxArray *c6_rhs5 = NULL;
  const mxArray *c6_lhs5 = NULL;
  const mxArray *c6_rhs6 = NULL;
  const mxArray *c6_lhs6 = NULL;
  const mxArray *c6_rhs7 = NULL;
  const mxArray *c6_lhs7 = NULL;
  const mxArray *c6_rhs8 = NULL;
  const mxArray *c6_lhs8 = NULL;
  const mxArray *c6_rhs9 = NULL;
  const mxArray *c6_lhs9 = NULL;
  const mxArray *c6_rhs10 = NULL;
  const mxArray *c6_lhs10 = NULL;
  const mxArray *c6_rhs11 = NULL;
  const mxArray *c6_lhs11 = NULL;
  const mxArray *c6_rhs12 = NULL;
  const mxArray *c6_lhs12 = NULL;
  const mxArray *c6_rhs13 = NULL;
  const mxArray *c6_lhs13 = NULL;
  const mxArray *c6_rhs14 = NULL;
  const mxArray *c6_lhs14 = NULL;
  const mxArray *c6_rhs15 = NULL;
  const mxArray *c6_lhs15 = NULL;
  const mxArray *c6_rhs16 = NULL;
  const mxArray *c6_lhs16 = NULL;
  const mxArray *c6_rhs17 = NULL;
  const mxArray *c6_lhs17 = NULL;
  const mxArray *c6_rhs18 = NULL;
  const mxArray *c6_lhs18 = NULL;
  const mxArray *c6_rhs19 = NULL;
  const mxArray *c6_lhs19 = NULL;
  const mxArray *c6_rhs20 = NULL;
  const mxArray *c6_lhs20 = NULL;
  const mxArray *c6_rhs21 = NULL;
  const mxArray *c6_lhs21 = NULL;
  const mxArray *c6_rhs22 = NULL;
  const mxArray *c6_lhs22 = NULL;
  const mxArray *c6_rhs23 = NULL;
  const mxArray *c6_lhs23 = NULL;
  const mxArray *c6_rhs24 = NULL;
  const mxArray *c6_lhs24 = NULL;
  const mxArray *c6_rhs25 = NULL;
  const mxArray *c6_lhs25 = NULL;
  const mxArray *c6_rhs26 = NULL;
  const mxArray *c6_lhs26 = NULL;
  const mxArray *c6_rhs27 = NULL;
  const mxArray *c6_lhs27 = NULL;
  const mxArray *c6_rhs28 = NULL;
  const mxArray *c6_lhs28 = NULL;
  const mxArray *c6_rhs29 = NULL;
  const mxArray *c6_lhs29 = NULL;
  const mxArray *c6_rhs30 = NULL;
  const mxArray *c6_lhs30 = NULL;
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("mrdivide"), "name", "name", 0);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832848U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1370035086U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c6_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1389742974U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c6_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1363739080U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c6_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c6_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1286843996U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c6_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1386449152U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c6_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c6_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eye"), "name", "name", 7);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1406838348U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c6_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 8);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1368208230U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c6_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 9);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c6_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral"),
                  "context", "context", 10);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("isinf"), "name", "name", 10);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1363739056U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c6_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 11);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c6_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 12);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_is_integer_class"), "name",
                  "name", 12);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1286843982U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c6_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 13);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("intmax"), "name", "name", 13);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c6_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 14);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c6_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 15);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("intmin"), "name", "name", 15);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c6_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 16);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c6_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 17);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexIntRelop"),
                  "name", "name", 17);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1326753522U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c6_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!apply_float_relop"),
                  "context", "context", 18);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 18);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c6_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass"),
                  "context", "context", 19);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 19);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1326753196U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c6_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass"),
                  "context", "context", 20);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("intmin"), "name", "name", 20);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c6_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 21);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 21);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c6_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 22);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("intmax"), "name", "name", 22);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c6_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 23);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1397282622U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c6_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 24);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("isfi"), "name", "name", 24);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 24);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1346535558U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c6_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 25);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1398900798U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c6_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 26);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("intmax"), "name", "name", 26);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c6_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 27);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("intmin"), "name", "name", 27);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c6_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "context", "context", 28);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 28);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1383902494U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c6_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 29);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 29);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c6_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "context", "context", 30);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("skew_sm"), "name", "name", 30);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/MATLAB/Masterarbeit/skew_sm.m"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1439587919U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c6_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs30), "lhs", "lhs",
                  30);
  sf_mex_destroy(&c6_rhs0);
  sf_mex_destroy(&c6_lhs0);
  sf_mex_destroy(&c6_rhs1);
  sf_mex_destroy(&c6_lhs1);
  sf_mex_destroy(&c6_rhs2);
  sf_mex_destroy(&c6_lhs2);
  sf_mex_destroy(&c6_rhs3);
  sf_mex_destroy(&c6_lhs3);
  sf_mex_destroy(&c6_rhs4);
  sf_mex_destroy(&c6_lhs4);
  sf_mex_destroy(&c6_rhs5);
  sf_mex_destroy(&c6_lhs5);
  sf_mex_destroy(&c6_rhs6);
  sf_mex_destroy(&c6_lhs6);
  sf_mex_destroy(&c6_rhs7);
  sf_mex_destroy(&c6_lhs7);
  sf_mex_destroy(&c6_rhs8);
  sf_mex_destroy(&c6_lhs8);
  sf_mex_destroy(&c6_rhs9);
  sf_mex_destroy(&c6_lhs9);
  sf_mex_destroy(&c6_rhs10);
  sf_mex_destroy(&c6_lhs10);
  sf_mex_destroy(&c6_rhs11);
  sf_mex_destroy(&c6_lhs11);
  sf_mex_destroy(&c6_rhs12);
  sf_mex_destroy(&c6_lhs12);
  sf_mex_destroy(&c6_rhs13);
  sf_mex_destroy(&c6_lhs13);
  sf_mex_destroy(&c6_rhs14);
  sf_mex_destroy(&c6_lhs14);
  sf_mex_destroy(&c6_rhs15);
  sf_mex_destroy(&c6_lhs15);
  sf_mex_destroy(&c6_rhs16);
  sf_mex_destroy(&c6_lhs16);
  sf_mex_destroy(&c6_rhs17);
  sf_mex_destroy(&c6_lhs17);
  sf_mex_destroy(&c6_rhs18);
  sf_mex_destroy(&c6_lhs18);
  sf_mex_destroy(&c6_rhs19);
  sf_mex_destroy(&c6_lhs19);
  sf_mex_destroy(&c6_rhs20);
  sf_mex_destroy(&c6_lhs20);
  sf_mex_destroy(&c6_rhs21);
  sf_mex_destroy(&c6_lhs21);
  sf_mex_destroy(&c6_rhs22);
  sf_mex_destroy(&c6_lhs22);
  sf_mex_destroy(&c6_rhs23);
  sf_mex_destroy(&c6_lhs23);
  sf_mex_destroy(&c6_rhs24);
  sf_mex_destroy(&c6_lhs24);
  sf_mex_destroy(&c6_rhs25);
  sf_mex_destroy(&c6_lhs25);
  sf_mex_destroy(&c6_rhs26);
  sf_mex_destroy(&c6_lhs26);
  sf_mex_destroy(&c6_rhs27);
  sf_mex_destroy(&c6_lhs27);
  sf_mex_destroy(&c6_rhs28);
  sf_mex_destroy(&c6_lhs28);
  sf_mex_destroy(&c6_rhs29);
  sf_mex_destroy(&c6_lhs29);
  sf_mex_destroy(&c6_rhs30);
  sf_mex_destroy(&c6_lhs30);
}

static const mxArray *c6_emlrt_marshallOut(const char * c6_u)
{
  const mxArray *c6_y = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c6_u)), false);
  return c6_y;
}

static const mxArray *c6_b_emlrt_marshallOut(const uint32_T c6_u)
{
  const mxArray *c6_y = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 7, 0U, 0U, 0U, 0), false);
  return c6_y;
}

static const mxArray *c6_f_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc6_Model1angularInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static int32_T c6_g_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i75;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i75, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i75;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_sfEvent;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc6_Model1angularInstanceStruct *)chartInstanceVoid;
  c6_b_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_sfEvent),
    &c6_thisId);
  sf_mex_destroy(&c6_b_sfEvent);
  *(int32_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static uint8_T c6_h_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_Model1angular, const char_T
  *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_active_c6_Model1angular), &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_Model1angular);
  return c6_y;
}

static uint8_T c6_i_emlrt_marshallIn(SFc6_Model1angularInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void init_dsm_address_info(SFc6_Model1angularInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc6_Model1angularInstanceStruct
  *chartInstance)
{
  chartInstance->c6_G_Mplus = (real_T (*)[72])ssGetOutputPortSignal_wrapper
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

void sf_c6_Model1angular_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2608250205U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1287291452U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2472909111U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2086922625U);
}

mxArray* sf_c6_Model1angular_get_post_codegen_info(void);
mxArray *sf_c6_Model1angular_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("X50Mez57yMviwO1l4r16c");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(12);
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
    mxArray* mxPostCodegenInfo = sf_c6_Model1angular_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c6_Model1angular_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c6_Model1angular_jit_fallback_info(void)
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

mxArray *sf_c6_Model1angular_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c6_Model1angular_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c6_Model1angular(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"G_Mplus\",},{M[8],M[0],T\"is_active_c6_Model1angular\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_Model1angular_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_Model1angularInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc6_Model1angularInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Model1angularMachineNumber_,
           6,
           1,
           1,
           0,
           8,
           0,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_Model1angularMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Model1angularMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Model1angularMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,10,0,0,"r");
          _SFD_SET_DATA_PROPS(1,2,0,1,"G_Mplus");
          _SFD_SET_DATA_PROPS(2,10,0,0,"m0");
          _SFD_SET_DATA_PROPS(3,10,0,0,"m1");
          _SFD_SET_DATA_PROPS(4,10,0,0,"m2");
          _SFD_SET_DATA_PROPS(5,10,0,0,"j0");
          _SFD_SET_DATA_PROPS(6,10,0,0,"j1");
          _SFD_SET_DATA_PROPS(7,10,0,0,"j2");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,200);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"skew_sm",0,-1,127);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_c_sf_marshallOut,(MexInFcnForType)
            c6_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 12;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)
            c6_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)c6_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)c6_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)c6_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)c6_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)c6_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)c6_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c6_r);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c6_G_Mplus);
        _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c6_m0);
        _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c6_m1);
        _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c6_m2);
        _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c6_j0);
        _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c6_j1);
        _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c6_j2);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Model1angularMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "vjkdhjGGYmnV4zESGUsZCC";
}

static void sf_opaque_initialize_c6_Model1angular(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_Model1angularInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c6_Model1angular((SFc6_Model1angularInstanceStruct*)
    chartInstanceVar);
  initialize_c6_Model1angular((SFc6_Model1angularInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c6_Model1angular(void *chartInstanceVar)
{
  enable_c6_Model1angular((SFc6_Model1angularInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_Model1angular(void *chartInstanceVar)
{
  disable_c6_Model1angular((SFc6_Model1angularInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c6_Model1angular(void *chartInstanceVar)
{
  sf_gateway_c6_Model1angular((SFc6_Model1angularInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c6_Model1angular(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c6_Model1angular((SFc6_Model1angularInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c6_Model1angular(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c6_Model1angular((SFc6_Model1angularInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c6_Model1angular(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_Model1angularInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Model1angular_optimization_info();
    }

    finalize_c6_Model1angular((SFc6_Model1angularInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_Model1angular((SFc6_Model1angularInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_Model1angular(SimStruct *S)
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
    initialize_params_c6_Model1angular((SFc6_Model1angularInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_Model1angular(SimStruct *S)
{
  /* Actual parameters from chart:
     j0 j1 j2 m0 m1 m2 r
   */
  const char_T *rtParamNames[] = { "j0", "j1", "j2", "m0", "m1", "m2", "r" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for j0*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for j1*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for j2*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);

  /* registration for m0*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_DOUBLE);

  /* registration for m1*/
  ssRegDlgParamAsRunTimeParam(S, 4, 4, rtParamNames[4], SS_DOUBLE);

  /* registration for m2*/
  ssRegDlgParamAsRunTimeParam(S, 5, 5, rtParamNames[5], SS_DOUBLE);

  /* registration for r*/
  ssRegDlgParamAsRunTimeParam(S, 6, 6, rtParamNames[6], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Model1angular_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,6,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,6);
    if (chartIsInlinable) {
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,6,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1503341197U));
  ssSetChecksum1(S,(3630153147U));
  ssSetChecksum2(S,(2880594033U));
  ssSetChecksum3(S,(311798250U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c6_Model1angular(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_Model1angular(SimStruct *S)
{
  SFc6_Model1angularInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc6_Model1angularInstanceStruct *)utMalloc(sizeof
    (SFc6_Model1angularInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_Model1angularInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c6_Model1angular;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c6_Model1angular;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c6_Model1angular;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_Model1angular;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c6_Model1angular;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c6_Model1angular;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c6_Model1angular;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c6_Model1angular;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_Model1angular;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_Model1angular;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c6_Model1angular;
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

void c6_Model1angular_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_Model1angular(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_Model1angular(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_Model1angular(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_Model1angular_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

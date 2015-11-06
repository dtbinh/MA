/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DePascali4M_sfun.h"
#include "c4_DePascali4M.h"
#include "mwmathutil.h"
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
static const char * c4_debug_family_names[22] = { "r1", "r2", "r3", "r4", "x1",
  "y1", "z1", "x2", "y2", "z2", "x3", "y3", "z3", "x4", "y4", "z4", "J4inv",
  "nargin", "nargout", "x", "r", "Ginv" };

static const char * c4_b_debug_family_names[6] = { "rwq", "nargin", "nargout",
  "q", "r", "rw" };

static const char * c4_c_debug_family_names[4] = { "nargin", "nargout", "x", "X"
};

/* Function Declarations */
static void initialize_c4_DePascali4M(SFc4_DePascali4MInstanceStruct
  *chartInstance);
static void initialize_params_c4_DePascali4M(SFc4_DePascali4MInstanceStruct
  *chartInstance);
static void enable_c4_DePascali4M(SFc4_DePascali4MInstanceStruct *chartInstance);
static void disable_c4_DePascali4M(SFc4_DePascali4MInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_DePascali4M
  (SFc4_DePascali4MInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_DePascali4M
  (SFc4_DePascali4MInstanceStruct *chartInstance);
static void set_sim_state_c4_DePascali4M(SFc4_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c4_st);
static void finalize_c4_DePascali4M(SFc4_DePascali4MInstanceStruct
  *chartInstance);
static void sf_gateway_c4_DePascali4M(SFc4_DePascali4MInstanceStruct
  *chartInstance);
static void mdl_start_c4_DePascali4M(SFc4_DePascali4MInstanceStruct
  *chartInstance);
static void c4_chartstep_c4_DePascali4M(SFc4_DePascali4MInstanceStruct
  *chartInstance);
static void initSimStructsc4_DePascali4M(SFc4_DePascali4MInstanceStruct
  *chartInstance);
static void c4_quatrot(SFc4_DePascali4MInstanceStruct *chartInstance, real_T
  c4_q[4], real_T c4_b_r[3], real_T c4_rw[3]);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static void c4_emlrt_marshallIn(SFc4_DePascali4MInstanceStruct *chartInstance,
  const mxArray *c4_b_Ginv, const char_T *c4_identifier, real_T c4_y[144]);
static void c4_b_emlrt_marshallIn(SFc4_DePascali4MInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[144]);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_c_emlrt_marshallIn(SFc4_DePascali4MInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[12]);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_d_emlrt_marshallIn(SFc4_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_e_emlrt_marshallIn(SFc4_DePascali4MInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[9]);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_f_emlrt_marshallIn(SFc4_DePascali4MInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[3]);
static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_g_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_g_emlrt_marshallIn(SFc4_DePascali4MInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[4]);
static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static void c4_info_helper(const mxArray **c4_info);
static const mxArray *c4_emlrt_marshallOut(const char * c4_u);
static const mxArray *c4_b_emlrt_marshallOut(const uint32_T c4_u);
static void c4_quatmultiply(SFc4_DePascali4MInstanceStruct *chartInstance,
  real_T c4_q[4], real_T c4_b_r[4], real_T c4_qout[4]);
static void c4_eml_scalar_eg(SFc4_DePascali4MInstanceStruct *chartInstance);
static real_T c4_mpower(SFc4_DePascali4MInstanceStruct *chartInstance, real_T
  c4_a);
static real_T c4_b_mpower(SFc4_DePascali4MInstanceStruct *chartInstance, real_T
  c4_a);
static real_T c4_c_mpower(SFc4_DePascali4MInstanceStruct *chartInstance, real_T
  c4_a);
static void c4_eye(SFc4_DePascali4MInstanceStruct *chartInstance, real_T c4_I[9]);
static void c4_b_eml_scalar_eg(SFc4_DePascali4MInstanceStruct *chartInstance);
static void c4_eml_xgemm(SFc4_DePascali4MInstanceStruct *chartInstance, real_T
  c4_A[9], real_T c4_B[9], real_T c4_C[9], real_T c4_b_C[9]);
static const mxArray *c4_h_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_h_emlrt_marshallIn(SFc4_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_i_emlrt_marshallIn(SFc4_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_DePascali4M, const char_T
  *c4_identifier);
static uint8_T c4_j_emlrt_marshallIn(SFc4_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_eml_xgemm(SFc4_DePascali4MInstanceStruct *chartInstance, real_T
  c4_A[9], real_T c4_B[9], real_T c4_C[9]);
static void init_dsm_address_info(SFc4_DePascali4MInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc4_DePascali4MInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_DePascali4M(SFc4_DePascali4MInstanceStruct
  *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_is_active_c4_DePascali4M = 0U;
}

static void initialize_params_c4_DePascali4M(SFc4_DePascali4MInstanceStruct
  *chartInstance)
{
  real_T c4_dv0[12];
  int32_T c4_i0;
  sf_mex_import_named("r", sf_mex_get_sfun_param(chartInstance->S, 0, 0), c4_dv0,
                      0, 0, 0U, 1, 0U, 1, 12);
  for (c4_i0 = 0; c4_i0 < 12; c4_i0++) {
    chartInstance->c4_r[c4_i0] = c4_dv0[c4_i0];
  }
}

static void enable_c4_DePascali4M(SFc4_DePascali4MInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_DePascali4M(SFc4_DePascali4MInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c4_update_debugger_state_c4_DePascali4M
  (SFc4_DePascali4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c4_DePascali4M
  (SFc4_DePascali4MInstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  int32_T c4_i1;
  real_T c4_u[144];
  const mxArray *c4_b_y = NULL;
  uint8_T c4_hoistedGlobal;
  uint8_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(2, 1), false);
  for (c4_i1 = 0; c4_i1 < 144; c4_i1++) {
    c4_u[c4_i1] = (*chartInstance->c4_Ginv)[c4_i1];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 24, 6),
                false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_hoistedGlobal = chartInstance->c4_is_active_c4_DePascali4M;
  c4_b_u = c4_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_DePascali4M(SFc4_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T c4_dv1[144];
  int32_T c4_i2;
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)), "Ginv",
                      c4_dv1);
  for (c4_i2 = 0; c4_i2 < 144; c4_i2++) {
    (*chartInstance->c4_Ginv)[c4_i2] = c4_dv1[c4_i2];
  }

  chartInstance->c4_is_active_c4_DePascali4M = c4_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)),
     "is_active_c4_DePascali4M");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_DePascali4M(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_DePascali4M(SFc4_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c4_DePascali4M(SFc4_DePascali4MInstanceStruct
  *chartInstance)
{
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
  for (c4_i3 = 0; c4_i3 < 28; c4_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c4_x)[c4_i3], 0U);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  c4_chartstep_c4_DePascali4M(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DePascali4MMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c4_i4 = 0; c4_i4 < 144; c4_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c4_Ginv)[c4_i4], 1U);
  }

  for (c4_i5 = 0; c4_i5 < 12; c4_i5++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_r[c4_i5], 2U);
  }
}

static void mdl_start_c4_DePascali4M(SFc4_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c4_chartstep_c4_DePascali4M(SFc4_DePascali4MInstanceStruct
  *chartInstance)
{
  int32_T c4_i6;
  real_T c4_b_x[28];
  int32_T c4_i7;
  real_T c4_b_r[12];
  uint32_T c4_debug_family_var_map[22];
  real_T c4_r1[3];
  real_T c4_r2[3];
  real_T c4_r3[3];
  real_T c4_r4[3];
  real_T c4_x1;
  real_T c4_y1;
  real_T c4_z1;
  real_T c4_x2;
  real_T c4_y2;
  real_T c4_z2;
  real_T c4_x3;
  real_T c4_y3;
  real_T c4_z3;
  real_T c4_x4;
  real_T c4_y4;
  real_T c4_z4;
  real_T c4_J4inv[9];
  real_T c4_nargin = 2.0;
  real_T c4_nargout = 1.0;
  real_T c4_b_Ginv[144];
  int32_T c4_i8;
  real_T c4_c_x[4];
  int32_T c4_i9;
  real_T c4_c_r[3];
  real_T c4_dv2[3];
  int32_T c4_i10;
  int32_T c4_i11;
  real_T c4_d_x[4];
  int32_T c4_i12;
  real_T c4_d_r[3];
  real_T c4_dv3[3];
  int32_T c4_i13;
  int32_T c4_i14;
  real_T c4_e_x[4];
  int32_T c4_i15;
  real_T c4_e_r[3];
  real_T c4_dv4[3];
  int32_T c4_i16;
  int32_T c4_i17;
  real_T c4_f_x[4];
  int32_T c4_i18;
  real_T c4_f_r[3];
  real_T c4_dv5[3];
  int32_T c4_i19;
  real_T c4_A;
  real_T c4_d0;
  real_T c4_d1;
  real_T c4_d2;
  real_T c4_d3;
  real_T c4_d4;
  real_T c4_d5;
  real_T c4_d6;
  real_T c4_d7;
  real_T c4_d8;
  real_T c4_d9;
  real_T c4_d10;
  real_T c4_d11;
  real_T c4_d12;
  real_T c4_d13;
  real_T c4_d14;
  real_T c4_d15;
  real_T c4_d16;
  real_T c4_d17;
  real_T c4_d18;
  real_T c4_d19;
  real_T c4_B;
  real_T c4_g_x;
  real_T c4_y;
  real_T c4_h_x;
  real_T c4_b_y;
  real_T c4_i_x;
  real_T c4_c_y;
  real_T c4_d_y;
  real_T c4_b_A;
  real_T c4_d20;
  real_T c4_d21;
  real_T c4_d22;
  real_T c4_d23;
  real_T c4_d24;
  real_T c4_d25;
  real_T c4_d26;
  real_T c4_d27;
  real_T c4_d28;
  real_T c4_d29;
  real_T c4_d30;
  real_T c4_d31;
  real_T c4_d32;
  real_T c4_d33;
  real_T c4_d34;
  real_T c4_d35;
  real_T c4_d36;
  real_T c4_d37;
  real_T c4_d38;
  real_T c4_d39;
  real_T c4_b_B;
  real_T c4_j_x;
  real_T c4_e_y;
  real_T c4_k_x;
  real_T c4_f_y;
  real_T c4_l_x;
  real_T c4_g_y;
  real_T c4_h_y;
  real_T c4_c_A;
  real_T c4_d40;
  real_T c4_d41;
  real_T c4_d42;
  real_T c4_d43;
  real_T c4_d44;
  real_T c4_d45;
  real_T c4_d46;
  real_T c4_d47;
  real_T c4_d48;
  real_T c4_d49;
  real_T c4_d50;
  real_T c4_d51;
  real_T c4_d52;
  real_T c4_d53;
  real_T c4_d54;
  real_T c4_d55;
  real_T c4_d56;
  real_T c4_d57;
  real_T c4_d58;
  real_T c4_d59;
  real_T c4_c_B;
  real_T c4_m_x;
  real_T c4_i_y;
  real_T c4_n_x;
  real_T c4_j_y;
  real_T c4_o_x;
  real_T c4_k_y;
  real_T c4_l_y;
  real_T c4_d_A;
  real_T c4_d60;
  real_T c4_d61;
  real_T c4_d62;
  real_T c4_d63;
  real_T c4_d64;
  real_T c4_d65;
  real_T c4_d66;
  real_T c4_d67;
  real_T c4_d68;
  real_T c4_d69;
  real_T c4_d70;
  real_T c4_d71;
  real_T c4_d72;
  real_T c4_d73;
  real_T c4_d74;
  real_T c4_d75;
  real_T c4_d76;
  real_T c4_d77;
  real_T c4_d78;
  real_T c4_d79;
  real_T c4_d_B;
  real_T c4_p_x;
  real_T c4_m_y;
  real_T c4_q_x;
  real_T c4_n_y;
  real_T c4_r_x;
  real_T c4_o_y;
  real_T c4_p_y;
  real_T c4_e_A;
  real_T c4_d80;
  real_T c4_d81;
  real_T c4_d82;
  real_T c4_d83;
  real_T c4_d84;
  real_T c4_d85;
  real_T c4_d86;
  real_T c4_d87;
  real_T c4_d88;
  real_T c4_d89;
  real_T c4_d90;
  real_T c4_d91;
  real_T c4_d92;
  real_T c4_d93;
  real_T c4_d94;
  real_T c4_d95;
  real_T c4_d96;
  real_T c4_d97;
  real_T c4_d98;
  real_T c4_d99;
  real_T c4_e_B;
  real_T c4_s_x;
  real_T c4_q_y;
  real_T c4_t_x;
  real_T c4_r_y;
  real_T c4_u_x;
  real_T c4_s_y;
  real_T c4_t_y;
  real_T c4_f_A;
  real_T c4_d100;
  real_T c4_d101;
  real_T c4_d102;
  real_T c4_d103;
  real_T c4_d104;
  real_T c4_d105;
  real_T c4_d106;
  real_T c4_d107;
  real_T c4_d108;
  real_T c4_d109;
  real_T c4_d110;
  real_T c4_d111;
  real_T c4_d112;
  real_T c4_d113;
  real_T c4_d114;
  real_T c4_d115;
  real_T c4_d116;
  real_T c4_d117;
  real_T c4_d118;
  real_T c4_d119;
  real_T c4_f_B;
  real_T c4_v_x;
  real_T c4_u_y;
  real_T c4_w_x;
  real_T c4_v_y;
  real_T c4_x_x;
  real_T c4_w_y;
  real_T c4_x_y;
  real_T c4_g_A;
  real_T c4_d120;
  real_T c4_d121;
  real_T c4_d122;
  real_T c4_d123;
  real_T c4_d124;
  real_T c4_d125;
  real_T c4_d126;
  real_T c4_d127;
  real_T c4_d128;
  real_T c4_d129;
  real_T c4_d130;
  real_T c4_d131;
  real_T c4_d132;
  real_T c4_d133;
  real_T c4_d134;
  real_T c4_d135;
  real_T c4_d136;
  real_T c4_d137;
  real_T c4_d138;
  real_T c4_d139;
  real_T c4_g_B;
  real_T c4_y_x;
  real_T c4_y_y;
  real_T c4_ab_x;
  real_T c4_ab_y;
  real_T c4_bb_x;
  real_T c4_bb_y;
  real_T c4_cb_y;
  real_T c4_h_A;
  real_T c4_d140;
  real_T c4_d141;
  real_T c4_d142;
  real_T c4_d143;
  real_T c4_d144;
  real_T c4_d145;
  real_T c4_d146;
  real_T c4_d147;
  real_T c4_d148;
  real_T c4_d149;
  real_T c4_d150;
  real_T c4_d151;
  real_T c4_d152;
  real_T c4_d153;
  real_T c4_d154;
  real_T c4_d155;
  real_T c4_d156;
  real_T c4_d157;
  real_T c4_d158;
  real_T c4_d159;
  real_T c4_h_B;
  real_T c4_cb_x;
  real_T c4_db_y;
  real_T c4_db_x;
  real_T c4_eb_y;
  real_T c4_eb_x;
  real_T c4_fb_y;
  real_T c4_gb_y;
  real_T c4_i_A;
  real_T c4_d160;
  real_T c4_d161;
  real_T c4_d162;
  real_T c4_d163;
  real_T c4_d164;
  real_T c4_d165;
  real_T c4_d166;
  real_T c4_d167;
  real_T c4_d168;
  real_T c4_d169;
  real_T c4_d170;
  real_T c4_d171;
  real_T c4_d172;
  real_T c4_d173;
  real_T c4_d174;
  real_T c4_d175;
  real_T c4_d176;
  real_T c4_d177;
  real_T c4_d178;
  real_T c4_d179;
  real_T c4_i_B;
  real_T c4_fb_x;
  real_T c4_hb_y;
  real_T c4_gb_x;
  real_T c4_ib_y;
  real_T c4_hb_x;
  real_T c4_jb_y;
  real_T c4_kb_y;
  int32_T c4_i20;
  real_T c4_ib_x[4];
  int32_T c4_i21;
  real_T c4_g_r[3];
  real_T c4_dv6[3];
  int32_T c4_i22;
  real_T c4_jb_x[3];
  uint32_T c4_b_debug_family_var_map[4];
  real_T c4_b_nargin = 1.0;
  real_T c4_b_nargout = 1.0;
  real_T c4_X[9];
  int32_T c4_i23;
  real_T c4_a[9];
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  real_T c4_b[9];
  int32_T c4_i28;
  real_T c4_lb_y[9];
  int32_T c4_i29;
  real_T c4_b_a[9];
  int32_T c4_i30;
  real_T c4_b_b[9];
  int32_T c4_i31;
  real_T c4_kb_x[4];
  int32_T c4_i32;
  real_T c4_h_r[3];
  real_T c4_dv7[3];
  int32_T c4_i33;
  real_T c4_lb_x[3];
  real_T c4_c_nargin = 1.0;
  real_T c4_c_nargout = 1.0;
  real_T c4_b_X[9];
  int32_T c4_i34;
  int32_T c4_i35;
  int32_T c4_i36;
  int32_T c4_i37;
  int32_T c4_i38;
  int32_T c4_i39;
  real_T c4_mb_y[9];
  int32_T c4_i40;
  real_T c4_c_a[9];
  int32_T c4_i41;
  real_T c4_c_b[9];
  int32_T c4_i42;
  real_T c4_mb_x[4];
  int32_T c4_i43;
  real_T c4_i_r[3];
  real_T c4_dv8[3];
  int32_T c4_i44;
  real_T c4_nb_x[3];
  real_T c4_d_nargin = 1.0;
  real_T c4_d_nargout = 1.0;
  real_T c4_c_X[9];
  int32_T c4_i45;
  int32_T c4_i46;
  int32_T c4_i47;
  int32_T c4_i48;
  int32_T c4_i49;
  int32_T c4_i50;
  real_T c4_nb_y[9];
  int32_T c4_i51;
  real_T c4_d_a[9];
  int32_T c4_i52;
  real_T c4_d_b[9];
  int32_T c4_i53;
  real_T c4_ob_x[4];
  int32_T c4_i54;
  real_T c4_j_r[3];
  real_T c4_dv9[3];
  int32_T c4_i55;
  real_T c4_pb_x[3];
  real_T c4_e_nargin = 1.0;
  real_T c4_e_nargout = 1.0;
  real_T c4_d_X[9];
  int32_T c4_i56;
  int32_T c4_i57;
  int32_T c4_i58;
  int32_T c4_i59;
  int32_T c4_i60;
  int32_T c4_i61;
  real_T c4_ob_y[9];
  int32_T c4_i62;
  real_T c4_e_a[9];
  int32_T c4_i63;
  real_T c4_e_b[9];
  real_T c4_dv10[9];
  real_T c4_dv11[9];
  int32_T c4_i64;
  int32_T c4_i65;
  int32_T c4_i66;
  int32_T c4_i67;
  real_T c4_f_b[144];
  int32_T c4_i68;
  int32_T c4_i69;
  int32_T c4_i70;
  int32_T c4_i71;
  int32_T c4_i72;
  int32_T c4_i73;
  int32_T c4_i74;
  int32_T c4_i75;
  int32_T c4_i76;
  int32_T c4_i77;
  int32_T c4_i78;
  int32_T c4_i79;
  int32_T c4_i80;
  int32_T c4_i81;
  int32_T c4_i82;
  int32_T c4_i83;
  int32_T c4_i84;
  int32_T c4_i85;
  int32_T c4_i86;
  int32_T c4_i87;
  int32_T c4_i88;
  int32_T c4_i89;
  int32_T c4_i90;
  int32_T c4_i91;
  int32_T c4_i92;
  int32_T c4_i93;
  int32_T c4_i94;
  int32_T c4_i95;
  int32_T c4_i96;
  int32_T c4_i97;
  int32_T c4_i98;
  int32_T c4_i99;
  int32_T c4_i100;
  int32_T c4_i101;
  int32_T c4_i102;
  int32_T c4_i103;
  int32_T c4_i104;
  int32_T c4_i105;
  int32_T c4_i106;
  int32_T c4_i107;
  int32_T c4_i108;
  int32_T c4_i109;
  int32_T c4_i110;
  int32_T c4_i111;
  int32_T c4_i112;
  int32_T c4_i113;
  int32_T c4_i114;
  int32_T c4_i115;
  int32_T c4_i116;
  int32_T c4_i117;
  int32_T c4_i118;
  int32_T c4_i119;
  int32_T c4_i120;
  int32_T c4_i121;
  int32_T c4_i122;
  int32_T c4_i123;
  int32_T c4_i124;
  int32_T c4_i125;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
  for (c4_i6 = 0; c4_i6 < 28; c4_i6++) {
    c4_b_x[c4_i6] = (*chartInstance->c4_x)[c4_i6];
  }

  for (c4_i7 = 0; c4_i7 < 12; c4_i7++) {
    c4_b_r[c4_i7] = chartInstance->c4_r[c4_i7];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 22U, 22U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_r1, 0U, c4_f_sf_marshallOut,
    c4_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_r2, 1U, c4_f_sf_marshallOut,
    c4_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_r3, 2U, c4_f_sf_marshallOut,
    c4_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_r4, 3U, c4_f_sf_marshallOut,
    c4_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_x1, 4U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_y1, 5U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_z1, 6U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_x2, 7U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_y2, 8U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_z2, 9U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_x3, 10U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_y3, 11U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_z3, 12U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_x4, 13U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_y4, 14U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_z4, 15U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_J4inv, 16U, c4_e_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 17U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 18U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_b_x, 19U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_b_r, 20U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_b_Ginv, 21U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 2);
  for (c4_i8 = 0; c4_i8 < 4; c4_i8++) {
    c4_c_x[c4_i8] = c4_b_x[c4_i8 + 3];
  }

  for (c4_i9 = 0; c4_i9 < 3; c4_i9++) {
    c4_c_r[c4_i9] = c4_b_r[c4_i9];
  }

  c4_quatrot(chartInstance, c4_c_x, c4_c_r, c4_dv2);
  for (c4_i10 = 0; c4_i10 < 3; c4_i10++) {
    c4_r1[c4_i10] = c4_dv2[c4_i10];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 3);
  for (c4_i11 = 0; c4_i11 < 4; c4_i11++) {
    c4_d_x[c4_i11] = c4_b_x[c4_i11 + 3];
  }

  for (c4_i12 = 0; c4_i12 < 3; c4_i12++) {
    c4_d_r[c4_i12] = c4_b_r[c4_i12 + 3];
  }

  c4_quatrot(chartInstance, c4_d_x, c4_d_r, c4_dv3);
  for (c4_i13 = 0; c4_i13 < 3; c4_i13++) {
    c4_r2[c4_i13] = c4_dv3[c4_i13];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 4);
  for (c4_i14 = 0; c4_i14 < 4; c4_i14++) {
    c4_e_x[c4_i14] = c4_b_x[c4_i14 + 3];
  }

  for (c4_i15 = 0; c4_i15 < 3; c4_i15++) {
    c4_e_r[c4_i15] = c4_b_r[c4_i15 + 6];
  }

  c4_quatrot(chartInstance, c4_e_x, c4_e_r, c4_dv4);
  for (c4_i16 = 0; c4_i16 < 3; c4_i16++) {
    c4_r3[c4_i16] = c4_dv4[c4_i16];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 5);
  for (c4_i17 = 0; c4_i17 < 4; c4_i17++) {
    c4_f_x[c4_i17] = c4_b_x[c4_i17 + 3];
  }

  for (c4_i18 = 0; c4_i18 < 3; c4_i18++) {
    c4_f_r[c4_i18] = c4_b_r[c4_i18 + 9];
  }

  c4_quatrot(chartInstance, c4_f_x, c4_f_r, c4_dv5);
  for (c4_i19 = 0; c4_i19 < 3; c4_i19++) {
    c4_r4[c4_i19] = c4_dv5[c4_i19];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 6);
  c4_x1 = c4_r1[0];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_y1 = c4_r1[1];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_z1 = c4_r1[2];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 9);
  c4_x2 = c4_r2[0];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 10);
  c4_y2 = c4_r2[1];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 11);
  c4_z2 = c4_r2[2];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 12);
  c4_x3 = c4_r3[0];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 13);
  c4_y3 = c4_r3[1];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 14);
  c4_z3 = c4_r3[2];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 15);
  c4_x4 = c4_r4[0];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 16);
  c4_y4 = c4_r4[1];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 17);
  c4_z4 = c4_r4[2];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 19);
  c4_A = 4.0 *
    ((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x2) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x4)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x4)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_x4)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y2)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2)) +
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2)) +
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z1)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z1)) +
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1)) +
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) +
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3)) + 8.0 *
    c4_mpower(chartInstance, c4_x1)) + 8.0 * c4_mpower(chartInstance, c4_x2)) +
    c4_b_mpower(chartInstance, c4_x1)) + 8.0 * c4_mpower(chartInstance, c4_x3))
                       + c4_b_mpower(chartInstance, c4_x2)) + 8.0 * c4_mpower
                      (chartInstance, c4_x4)) + c4_b_mpower(chartInstance, c4_x3))
                    + c4_b_mpower(chartInstance, c4_x4)) + 4.0 * c4_mpower
                   (chartInstance, c4_y1)) + 4.0 * c4_mpower(chartInstance,
    c4_y2)) + 4.0 * c4_mpower(chartInstance, c4_y3)) + 4.0 * c4_mpower
                (chartInstance, c4_y4)) + 4.0 * c4_mpower(chartInstance, c4_z1))
              + 4.0 * c4_mpower(chartInstance, c4_z2)) + 4.0 * c4_mpower
             (chartInstance, c4_z3)) + 4.0 * c4_mpower(chartInstance, c4_z4)) -
           2.0 * c4_y1 * c4_y2 * c4_z1 * c4_z2) - 2.0 * c4_y1 * c4_y3 * c4_z1 *
          c4_z3) - 2.0 * c4_y1 * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_y2 * c4_y3 *
        c4_z2 * c4_z3) - 2.0 * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 2.0 * c4_y3 *
      c4_y4 * c4_z3 * c4_z4) + 16.0);
  c4_d0 = 2.0 * c4_x2;
  c4_d1 = 2.0 * c4_x1 * c4_mpower(chartInstance, c4_x3);
  c4_d2 = 2.0 * c4_x2 * c4_x3 * c4_y2;
  c4_d3 = 2.0 * c4_x1 * c4_mpower(chartInstance, c4_x2) * c4_x4 * c4_z1;
  c4_d4 = 2.0 * c4_x1 * c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_z1 * c4_z3;
  c4_d5 = 2.0 * c4_x1;
  c4_d6 = 2.0 * c4_c_mpower(chartInstance, c4_x1) * c4_x3;
  c4_d7 = 2.0 * c4_x1 * c4_c_mpower(chartInstance, c4_x3) * c4_y1;
  c4_d8 = 2.0 * c4_x1 * c4_x3 * c4_c_mpower(chartInstance, c4_y1) * c4_y3;
  c4_d9 = 2.0 * c4_mpower(chartInstance, c4_x3);
  c4_d10 = 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y4);
  c4_d11 = 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z3);
  c4_d12 = c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1);
  c4_d13 = c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z1);
  c4_d14 = c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_z3);
  c4_d15 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x2) + 8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x3)) + 8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x4)) + 8.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_x3)) + 8.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_x4)) + 8.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
    c4_x4)) + 8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_y1)) + 12.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_y2)) + 12.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y1)) + 12.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_y3)) + 8.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y2)) + 12.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
    c4_y1)) + c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_y2))
    + 12.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y4))
    + c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_y1)) +
    12.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_y3)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_y1)) + 8.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y3)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2)) +
    c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_y2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_y1)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2)) +
    c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) +
    c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_y2)) + 8.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3)) + 8.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z1)) + 12.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2)) + 12.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z3)) + 8.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_z1)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z3)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z2)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4)) + 8.0 *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_z3)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z4)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z3)) + 12.0 *
                       c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_z2)) + c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1))
                     + 8.0 * c4_mpower(chartInstance, c4_y2) * c4_mpower
                     (chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x1) *
                    c4_b_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance,
    c4_x2) * c4_b_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance,
    c4_x1) * c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x3) *
                 c4_b_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower
                (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z4)) +
               c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_z3)) + c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_z1))
             + 12.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
              c4_z3)) + c4_b_mpower(chartInstance, c4_x3) * c4_mpower
            (chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_x4) *
           c4_mpower(chartInstance, c4_z1)) + 8.0 * c4_mpower(chartInstance,
           c4_y3) * c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance,
          c4_x2) * c4_b_mpower(chartInstance, c4_z4)) + c4_b_mpower
        (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
       (chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_z2)) + 8.0 *
      c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) +
     c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_z4);
  c4_d16 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d15 + c4_d14) + c4_b_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y1) *
    c4_b_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) *
    c4_b_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y1) *
    c4_b_mpower(chartInstance, c4_z3)) + 12.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y3) *
    c4_b_mpower(chartInstance, c4_z1)) + 8.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 12.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y1) *
    c4_b_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) *
    c4_b_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y3) *
    c4_b_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y4) *
    c4_b_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y2) *
    c4_b_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) *
    c4_b_mpower(chartInstance, c4_z2)) + 8.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y3) *
    c4_b_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) *
    c4_b_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + 8.0 * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + 8.0 * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z4)) + 8.0 * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + 32.0 * c4_mpower(chartInstance, c4_x1)) +
    32.0 * c4_mpower(chartInstance, c4_x2)) + 4.0 * c4_b_mpower(chartInstance,
    c4_x1)) + 32.0 * c4_mpower(chartInstance, c4_x3)) + 4.0 * c4_b_mpower
    (chartInstance, c4_x2)) + 32.0 * c4_mpower(chartInstance, c4_x4)) + 4.0 *
    c4_b_mpower(chartInstance, c4_x3)) + 4.0 * c4_b_mpower(chartInstance, c4_x4))
    + 32.0 * c4_mpower(chartInstance, c4_y1)) + 32.0 * c4_mpower(chartInstance,
    c4_y2)) + 4.0 * c4_b_mpower(chartInstance, c4_y1)) + 32.0 * c4_mpower
    (chartInstance, c4_y3)) + 4.0 * c4_b_mpower(chartInstance, c4_y2)) + 32.0 *
    c4_mpower(chartInstance, c4_y4)) + 4.0 * c4_b_mpower(chartInstance, c4_y3))
    + 4.0 * c4_b_mpower(chartInstance, c4_y4)) + 32.0 * c4_mpower(chartInstance,
    c4_z1)) + 32.0 * c4_mpower(chartInstance, c4_z2)) + 4.0 * c4_b_mpower
    (chartInstance, c4_z1)) + 32.0 * c4_mpower(chartInstance, c4_z3)) + 4.0 *
    c4_b_mpower(chartInstance, c4_z2)) + 32.0 * c4_mpower(chartInstance, c4_z4))
    + 4.0 * c4_b_mpower(chartInstance, c4_z3)) + 4.0 * c4_b_mpower(chartInstance,
    c4_z4)) + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
                       c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y4)) + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
                      c4_mpower(chartInstance, c4_y3)) + 2.0 * c4_mpower
                     (chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x4) *
                     c4_mpower(chartInstance, c4_y2)) + c4_mpower(chartInstance,
    c4_x2) * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2))
                   + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower
                   (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) +
                  2.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower
                  (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4)) +
                 2.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x4) * c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x2) *
                c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y3))
               + c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_x4) * c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance,
    c4_x3) * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1))
             + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x4)
             * c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance,
             c4_x2) * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
             c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower
           (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
          c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_x4) *
          c4_mpower(chartInstance, c4_y2)) + c4_mpower(chartInstance, c4_x2) *
         c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4)) +
        c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_x4) *
        c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x3) *
       c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4)) +
      c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x2) *
      c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_x1) *
     c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_z2);
  c4_d17 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d16 + c4_d13) + c4_d12 * c4_mpower(chartInstance,
    c4_y3)) + c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
                       c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
    c4_y1) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance,
    c4_x3) * c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3))
                     + 2.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower
                     (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z2)) +
                    2.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower
                    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) +
                   2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
                   (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z3)) +
                  2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
                  (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) +
                 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance,
    c4_x1) * c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z4))
               + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance,
    c4_x2) * c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3))
             + 2.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
              c4_y2) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
            (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4) * c4_mpower
            (chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
           c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z4)) +
          2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2)
          * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance,
          c4_x4) * c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance,
          c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
        (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
       c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y4) *
       c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
      c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
     c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4) *
     c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4);
  c4_d18 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d17 + c4_d11) + c4_d10 * c4_mpower(chartInstance,
    c4_z2)) + c4_d9 * c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance,
    c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance,
    c4_x4) * c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3))
    + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z1)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) - 8.0 *
    c4_x1 * c4_x2 * c4_y1 * c4_y2) - 8.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3) - 8.0 *
    c4_x1 * c4_x4 * c4_y1 * c4_y4) - 8.0 * c4_x2 * c4_x3 * c4_y2 * c4_y3) - 8.0 *
                      c4_x2 * c4_x4 * c4_y2 * c4_y4) - 8.0 * c4_x3 * c4_x4 *
                     c4_y3 * c4_y4) - 8.0 * c4_x1 * c4_x2 * c4_z1 * c4_z2) - 8.0
                   * c4_x1 * c4_x3 * c4_z1 * c4_z3) - 8.0 * c4_x1 * c4_x4 *
                  c4_z1 * c4_z4) - 8.0 * c4_x2 * c4_x3 * c4_z2 * c4_z3) - 8.0 *
                c4_x2 * c4_x4 * c4_z2 * c4_z4) - 8.0 * c4_x3 * c4_x4 * c4_z3 *
               c4_z4) - 8.0 * c4_y1 * c4_y2 * c4_z1 * c4_z2) - 8.0 * c4_y1 *
             c4_y3 * c4_z1 * c4_z3) - 8.0 * c4_y1 * c4_y4 * c4_z1 * c4_z4) - 8.0
           * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 8.0 * c4_y2 * c4_y4 * c4_z2 *
          c4_z4) - 8.0 * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x2 *
        c4_y1 * c4_c_mpower(chartInstance, c4_y2)) - 2.0 * c4_x1 * c4_x2 *
       c4_c_mpower(chartInstance, c4_y1) * c4_y2) - 2.0 * c4_x1 * c4_c_mpower
      (chartInstance, c4_x2) * c4_y1 * c4_y2) - 2.0 * c4_c_mpower(chartInstance,
      c4_x1) * c4_x2 * c4_y1 * c4_y2) - 2.0 * c4_x1 * c4_x3 * c4_y1 *
    c4_c_mpower(chartInstance, c4_y3);
  c4_d19 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d18 - c4_d8) - c4_d7 * c4_y3) - c4_d6 * c4_y1 *
    c4_y3) - c4_d5 * c4_x4 * c4_y1 * c4_c_mpower(chartInstance, c4_y4)) - 2.0 *
    c4_x1 * c4_x4 * c4_c_mpower(chartInstance, c4_y1) * c4_y4) - 2.0 * c4_x1 *
    c4_c_mpower(chartInstance, c4_x4) * c4_y1 * c4_y4) - 2.0 * c4_x2 * c4_x3 *
    c4_y2 * c4_c_mpower(chartInstance, c4_y3)) - 2.0 * c4_x2 * c4_x3 *
    c4_c_mpower(chartInstance, c4_y2) * c4_y3) - 2.0 * c4_x2 * c4_c_mpower
    (chartInstance, c4_x3) * c4_y2 * c4_y3) - 2.0 * c4_c_mpower(chartInstance,
    c4_x1) * c4_x4 * c4_y1 * c4_y4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) *
    c4_x3 * c4_y2 * c4_y3) - 2.0 * c4_x2 * c4_x4 * c4_y2 * c4_c_mpower
    (chartInstance, c4_y4)) - 2.0 * c4_x2 * c4_x4 * c4_c_mpower(chartInstance,
    c4_y2) * c4_y4) - 2.0 * c4_x2 * c4_c_mpower(chartInstance, c4_x4) * c4_y2 *
    c4_y4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) * c4_x4 * c4_y2 * c4_y4) -
    2.0 * c4_x3 * c4_x4 * c4_y3 * c4_c_mpower(chartInstance, c4_y4)) - 2.0 *
    c4_x3 * c4_x4 * c4_c_mpower(chartInstance, c4_y3) * c4_y4) - 2.0 * c4_x3 *
    c4_c_mpower(chartInstance, c4_x4) * c4_y3 * c4_y4) - 2.0 * c4_c_mpower
    (chartInstance, c4_x3) * c4_x4 * c4_y3 * c4_y4) - 2.0 * c4_x1 * c4_x2 *
    c4_z1 * c4_c_mpower(chartInstance, c4_z2)) - 2.0 * c4_x1 * c4_x2 *
    c4_c_mpower(chartInstance, c4_z1) * c4_z2) - 2.0 * c4_x1 * c4_c_mpower
    (chartInstance, c4_x2) * c4_z1 * c4_z2) - 2.0 * c4_c_mpower(chartInstance,
    c4_x1) * c4_x2 * c4_z1 * c4_z2) - 2.0 * c4_x1 * c4_x3 * c4_z1 * c4_c_mpower
    (chartInstance, c4_z3)) - 2.0 * c4_x1 * c4_x3 * c4_c_mpower(chartInstance,
    c4_z1) * c4_z3) - 2.0 * c4_x1 * c4_c_mpower(chartInstance, c4_x3) * c4_z1 *
    c4_z3) - 2.0 * c4_c_mpower(chartInstance, c4_x1) * c4_x3 * c4_z1 * c4_z3) -
    2.0 * c4_x1 * c4_x4 * c4_z1 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x1 * c4_x4 * c4_c_mpower(chartInstance, c4_z1) * c4_z4) - 2.0 * c4_x1 *
    c4_c_mpower(chartInstance, c4_x4) * c4_z1 * c4_z4) - 2.0 * c4_x2 * c4_x3 *
    c4_z2 * c4_c_mpower(chartInstance, c4_z3)) - 2.0 * c4_x2 * c4_x3 *
    c4_c_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 * c4_x2 * c4_c_mpower
    (chartInstance, c4_x3) * c4_z2 * c4_z3) - 2.0 * c4_c_mpower(chartInstance,
    c4_x1) * c4_x4 * c4_z1 * c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) *
    c4_x3 * c4_z2 * c4_z3) - 2.0 * c4_x2 * c4_x4 * c4_z2 * c4_c_mpower
    (chartInstance, c4_z4)) - 2.0 * c4_x2 * c4_x4 * c4_c_mpower(chartInstance,
    c4_z2) * c4_z4) - 2.0 * c4_x2 * c4_c_mpower(chartInstance, c4_x4) * c4_z2 *
    c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) * c4_x4 * c4_z2 * c4_z4) -
    2.0 * c4_x3 * c4_x4 * c4_z3 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x3 * c4_x4 * c4_c_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_x3 *
    c4_c_mpower(chartInstance, c4_x4) * c4_z3 * c4_z4) - 2.0 * c4_c_mpower
    (chartInstance, c4_x3) * c4_x4 * c4_z3 * c4_z4) - 2.0 * c4_y1 * c4_y2 *
    c4_z1 * c4_c_mpower(chartInstance, c4_z2)) - 2.0 * c4_y1 * c4_y2 *
    c4_c_mpower(chartInstance, c4_z1) * c4_z2) - 2.0 * c4_y1 * c4_c_mpower
    (chartInstance, c4_y2) * c4_z1 * c4_z2) - 2.0 * c4_c_mpower(chartInstance,
    c4_y1) * c4_y2 * c4_z1 * c4_z2) - 2.0 * c4_y1 * c4_y3 * c4_z1 * c4_c_mpower
    (chartInstance, c4_z3)) - 2.0 * c4_y1 * c4_y3 * c4_c_mpower(chartInstance,
    c4_z1) * c4_z3) - 2.0 * c4_y1 * c4_c_mpower(chartInstance, c4_y3) * c4_z1 *
    c4_z3) - 2.0 * c4_c_mpower(chartInstance, c4_y1) * c4_y3 * c4_z1 * c4_z3) -
    2.0 * c4_y1 * c4_y4 * c4_z1 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_y1 * c4_y4 * c4_c_mpower(chartInstance, c4_z1) * c4_z4) - 2.0 * c4_y1 *
    c4_c_mpower(chartInstance, c4_y4) * c4_z1 * c4_z4) - 2.0 * c4_y2 * c4_y3 *
    c4_z2 * c4_c_mpower(chartInstance, c4_z3)) - 2.0 * c4_y2 * c4_y3 *
    c4_c_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 * c4_y2 * c4_c_mpower
    (chartInstance, c4_y3) * c4_z2 * c4_z3) - 2.0 * c4_c_mpower(chartInstance,
    c4_y1) * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_y2) *
    c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_y2 * c4_y4 * c4_z2 * c4_c_mpower
    (chartInstance, c4_z4)) - 2.0 * c4_y2 * c4_y4 * c4_c_mpower(chartInstance,
    c4_z2) * c4_z4) - 2.0 * c4_y2 * c4_c_mpower(chartInstance, c4_y4) * c4_z2 *
    c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_y2) * c4_y4 * c4_z2 * c4_z4) -
    2.0 * c4_y3 * c4_y4 * c4_z3 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_y3 * c4_y4 * c4_c_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_y3 *
    c4_c_mpower(chartInstance, c4_y4) * c4_z3 * c4_z4) - 2.0 * c4_c_mpower
    (chartInstance, c4_y3) * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x2 *
    c4_mpower(chartInstance, c4_x3) * c4_y1 * c4_y2) - 2.0 * c4_x1 * c4_x2 *
    c4_mpower(chartInstance, c4_x4) * c4_y1 * c4_y2) - 2.0 * c4_x1 * c4_mpower
    (chartInstance, c4_x2) * c4_x3 * c4_y1 * c4_y3) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x2 * c4_x3 * c4_y2 * c4_y3) - 2.0 * c4_x1 *
    c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_y1 * c4_y3) - 2.0 * c4_x1 *
    c4_mpower(chartInstance, c4_x2) * c4_x4 * c4_y1 * c4_y4) - 2.0 * c4_x1 *
    c4_mpower(chartInstance, c4_x3) * c4_x4 * c4_y1 * c4_y4) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x2 * c4_x4 * c4_y2 * c4_y4) - 2.0 * c4_x2 *
    c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_y2 * c4_y3) - 2.0 * c4_x2 *
    c4_mpower(chartInstance, c4_x3) * c4_x4 * c4_y2 * c4_y4) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x3 * c4_x4 * c4_y3 * c4_y4) - 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_x3 * c4_x4 * c4_y3 * c4_y4) - 2.0 * c4_x1 *
    c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_y3)) - 2.0 * c4_x1 *
                       c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_y4))
                      - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_mpower(chartInstance,
    c4_y2) * c4_y3) - 2.0 * c4_x2 * c4_x3 * c4_mpower(chartInstance, c4_y1) *
                     c4_y2 * c4_y3) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3 *
                    c4_mpower(chartInstance, c4_y4)) - 2.0 * c4_x1 * c4_x4 *
                   c4_y1 * c4_mpower(chartInstance, c4_y2) * c4_y4) - 2.0 *
                  c4_x1 * c4_x4 * c4_y1 * c4_mpower(chartInstance, c4_y3) *
                  c4_y4) - 2.0 * c4_x2 * c4_x4 * c4_mpower(chartInstance, c4_y1)
                 * c4_y2 * c4_y4) - 2.0 * c4_x2 * c4_x3 * c4_y2 * c4_y3 *
                c4_mpower(chartInstance, c4_y4)) - 2.0 * c4_x2 * c4_x4 * c4_y2 *
               c4_mpower(chartInstance, c4_y3) * c4_y4) - 2.0 * c4_x3 * c4_x4 *
              c4_mpower(chartInstance, c4_y1) * c4_y3 * c4_y4) - 2.0 * c4_x3 *
             c4_x4 * c4_mpower(chartInstance, c4_y2) * c4_y3 * c4_y4) - 2.0 *
            c4_x1 * c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_z1)) -
           2.0 * c4_x1 * c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_z2))
          - 2.0 * c4_x1 * c4_x2 * c4_mpower(chartInstance, c4_x3) * c4_z1 *
          c4_z2) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3 * c4_mpower(chartInstance,
          c4_z1)) - 2.0 * c4_x1 * c4_x2 * c4_mpower(chartInstance, c4_x4) *
        c4_z1 * c4_z2) - 2.0 * c4_x1 * c4_mpower(chartInstance, c4_x2) * c4_x3 *
       c4_z1 * c4_z3) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3 * c4_mpower
      (chartInstance, c4_z3)) - 2.0 * c4_x1 * c4_x4 * c4_y1 * c4_y4 * c4_mpower
     (chartInstance, c4_z1)) - 2.0 * c4_mpower(chartInstance, c4_x1) * c4_x2 *
    c4_x3 * c4_z2 * c4_z3;
  c4_B =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d19 - c4_d4) - c4_d3 * c4_z4) - c4_d2 * c4_y3 *
    c4_mpower(chartInstance, c4_z2)) - c4_d1 * c4_x4 * c4_z1 * c4_z4) - c4_d0 *
    c4_x3 * c4_y2 * c4_y3 * c4_mpower(chartInstance, c4_z3)) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x2 * c4_x4 * c4_z2 * c4_z4) - 2.0 * c4_x1 *
    c4_x4 * c4_y1 * c4_y4 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_x2 *
    c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_z2 * c4_z3) - 2.0 * c4_x2 *
    c4_x4 * c4_y2 * c4_y4 * c4_mpower(chartInstance, c4_z2)) - 2.0 * c4_x2 *
    c4_mpower(chartInstance, c4_x3) * c4_x4 * c4_z2 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x3 * c4_x4 * c4_z3 * c4_z4) - 2.0 * c4_x2 *
    c4_x4 * c4_y2 * c4_y4 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_x3 * c4_x4 * c4_z3 * c4_z4) - 2.0 * c4_x3 *
    c4_x4 * c4_y3 * c4_y4 * c4_mpower(chartInstance, c4_z3)) - 2.0 * c4_x3 *
    c4_x4 * c4_y3 * c4_y4 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_x1 *
    c4_x2 * c4_mpower(chartInstance, c4_y1) * c4_z1 * c4_z2) - 2.0 * c4_x1 *
    c4_x2 * c4_mpower(chartInstance, c4_y2) * c4_z1 * c4_z2) - 2.0 * c4_x1 *
    c4_x3 * c4_mpower(chartInstance, c4_y1) * c4_z1 * c4_z3) - 2.0 * c4_x1 *
    c4_x3 * c4_mpower(chartInstance, c4_y3) * c4_z1 * c4_z3) - 2.0 * c4_x1 *
    c4_x4 * c4_mpower(chartInstance, c4_y1) * c4_z1 * c4_z4) - 2.0 * c4_x2 *
    c4_x3 * c4_mpower(chartInstance, c4_y2) * c4_z2 * c4_z3) - 2.0 * c4_x2 *
    c4_x3 * c4_mpower(chartInstance, c4_y3) * c4_z2 * c4_z3) - 2.0 * c4_x1 *
    c4_x4 * c4_mpower(chartInstance, c4_y4) * c4_z1 * c4_z4) - 2.0 * c4_x2 *
    c4_x4 * c4_mpower(chartInstance, c4_y2) * c4_z2 * c4_z4) - 2.0 * c4_x2 *
    c4_x4 * c4_mpower(chartInstance, c4_y4) * c4_z2 * c4_z4) - 2.0 * c4_x3 *
    c4_x4 * c4_mpower(chartInstance, c4_y3) * c4_z3 * c4_z4) - 2.0 * c4_x3 *
    c4_x4 * c4_mpower(chartInstance, c4_y4) * c4_z3 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_y1 * c4_y2 * c4_z1 * c4_z2) - 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_y1 * c4_y2 * c4_z1 * c4_z2) - 2.0 * c4_x1 *
    c4_x2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z3)) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_y1 * c4_y3 * c4_z1 * c4_z3) - 2.0 * c4_x1 *
    c4_x2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_x1 *
    c4_x3 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 * c4_x2 *
    c4_x3 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z3) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_y1 * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x3) * c4_y1 * c4_y3 * c4_z1 * c4_z3) - 2.0 * c4_x1 *
    c4_x3 * c4_z1 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_x1 *
    c4_x4 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_x1 *
    c4_x4 * c4_z1 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_x2 *
    c4_x4 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x3) * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_x2 *
    c4_x3 * c4_z2 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x4) * c4_y1 * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_x2 *
    c4_x4 * c4_z2 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_x3 *
    c4_x4 * c4_mpower(chartInstance, c4_z1) * c4_z3 * c4_z4) - 2.0 * c4_x3 *
    c4_x4 * c4_mpower(chartInstance, c4_z2) * c4_z3 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x4) * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x3) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x4) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_y1 *
    c4_y2 * c4_mpower(chartInstance, c4_y3) * c4_z1 * c4_z2) - 2.0 * c4_y1 *
    c4_y2 * c4_mpower(chartInstance, c4_y4) * c4_z1 * c4_z2) - 2.0 * c4_y1 *
    c4_mpower(chartInstance, c4_y2) * c4_y3 * c4_z1 * c4_z3) - 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_y1 *
    c4_y3 * c4_mpower(chartInstance, c4_y4) * c4_z1 * c4_z3) - 2.0 * c4_y1 *
    c4_mpower(chartInstance, c4_y2) * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_y1 *
    c4_mpower(chartInstance, c4_y3) * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 2.0 * c4_y2 *
    c4_y3 * c4_mpower(chartInstance, c4_y4) * c4_z2 * c4_z3) - 2.0 * c4_y2 *
    c4_mpower(chartInstance, c4_y3) * c4_y4 * c4_z2 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_y2) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_y1 *
    c4_y2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z3)) - 2.0 * c4_y1 *
    c4_y2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_y1 *
    c4_y3 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 * c4_y2 *
    c4_y3 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z3) - 2.0 * c4_y1 *
    c4_y3 * c4_z1 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_y1 *
    c4_y4 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z4) - 2.0 * c4_y1 *
    c4_y4 * c4_z1 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_y2 *
    c4_y4 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z4) - 2.0 * c4_y2 *
    c4_y3 * c4_z2 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_y2 *
    c4_y4 * c4_z2 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_y3 *
    c4_y4 * c4_mpower(chartInstance, c4_z1) * c4_z3 * c4_z4) - 2.0 * c4_y3 *
    c4_y4 * c4_mpower(chartInstance, c4_z2) * c4_z3 * c4_z4) - 2.0 * c4_x1 *
    c4_x2 * c4_y1 * c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_x1 * c4_x2 * c4_y2 * c4_y3
    * c4_z1 * c4_z3) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y2 * c4_z2 * c4_z3) -
    2.0 * c4_x1 * c4_x3 * c4_y2 * c4_y3 * c4_z1 * c4_z2) - 2.0 * c4_x2 * c4_x3 *
    c4_y1 * c4_y2 * c4_z1 * c4_z3) - 2.0 * c4_x2 * c4_x3 * c4_y1 * c4_y3 * c4_z1
                       * c4_z2) - 2.0 * c4_x1 * c4_x2 * c4_y1 * c4_y4 * c4_z2 *
                      c4_z4) - 2.0 * c4_x1 * c4_x2 * c4_y2 * c4_y4 * c4_z1 *
                     c4_z4) - 2.0 * c4_x1 * c4_x4 * c4_y1 * c4_y2 * c4_z2 *
                    c4_z4) - 2.0 * c4_x1 * c4_x4 * c4_y2 * c4_y4 * c4_z1 * c4_z2)
                  - 2.0 * c4_x2 * c4_x4 * c4_y1 * c4_y2 * c4_z1 * c4_z4) - 2.0 *
                 c4_x2 * c4_x4 * c4_y1 * c4_y4 * c4_z1 * c4_z2) - 2.0 * c4_x1 *
                c4_x3 * c4_y1 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x3 *
               c4_y3 * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_x1 * c4_x4 * c4_y1 *
              c4_y3 * c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x4 * c4_y3 * c4_y4 *
             c4_z1 * c4_z3) - 2.0 * c4_x3 * c4_x4 * c4_y1 * c4_y3 * c4_z1 *
            c4_z4) - 2.0 * c4_x3 * c4_x4 * c4_y1 * c4_y4 * c4_z1 * c4_z3) - 2.0 *
          c4_x2 * c4_x3 * c4_y2 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_x2 * c4_x3 *
         c4_y3 * c4_y4 * c4_z2 * c4_z4) - 2.0 * c4_x2 * c4_x4 * c4_y2 * c4_y3 *
        c4_z3 * c4_z4) - 2.0 * c4_x2 * c4_x4 * c4_y3 * c4_y4 * c4_z2 * c4_z3) -
      2.0 * c4_x3 * c4_x4 * c4_y2 * c4_y3 * c4_z2 * c4_z4) - 2.0 * c4_x3 * c4_x4
     * c4_y2 * c4_y4 * c4_z2 * c4_z3) + 64.0;
  c4_g_x = c4_A;
  c4_y = c4_B;
  c4_h_x = c4_g_x;
  c4_b_y = c4_y;
  c4_i_x = c4_h_x;
  c4_c_y = c4_b_y;
  c4_d_y = c4_i_x / c4_c_y;
  c4_b_A = 4.0 * (((((((((((((((((((((((((((((((((((((((((((((((((((4.0 * c4_x1 *
    c4_y1 + 4.0 * c4_x2 * c4_y2) + 4.0 * c4_x3 * c4_y3) + 4.0 * c4_x4 * c4_y4) +
    c4_x1 * c4_c_mpower(chartInstance, c4_y1)) + c4_c_mpower(chartInstance,
    c4_x1) * c4_y1) + c4_x2 * c4_c_mpower(chartInstance, c4_y2)) + c4_c_mpower
    (chartInstance, c4_x2) * c4_y2) + c4_x3 * c4_c_mpower(chartInstance, c4_y3))
    + c4_c_mpower(chartInstance, c4_x3) * c4_y3) + c4_x4 * c4_c_mpower
    (chartInstance, c4_y4)) + c4_c_mpower(chartInstance, c4_x4) * c4_y4) + c4_x1
    * c4_mpower(chartInstance, c4_x2) * c4_y1) + c4_x1 * c4_mpower(chartInstance,
    c4_x3) * c4_y1) + c4_mpower(chartInstance, c4_x1) * c4_x2 * c4_y2) + c4_x1 *
    c4_mpower(chartInstance, c4_x4) * c4_y1) + c4_x2 * c4_mpower(chartInstance,
    c4_x3) * c4_y2) + c4_mpower(chartInstance, c4_x1) * c4_x3 * c4_y3) + c4_x2 *
    c4_mpower(chartInstance, c4_x4) * c4_y2) + c4_mpower(chartInstance, c4_x2) *
    c4_x3 * c4_y3) + c4_mpower(chartInstance, c4_x1) * c4_x4 * c4_y4) + c4_x3 *
    c4_mpower(chartInstance, c4_x4) * c4_y3) + c4_mpower(chartInstance, c4_x2) *
    c4_x4 * c4_y4) + c4_mpower(chartInstance, c4_x3) * c4_x4 * c4_y4) + c4_x1 *
    c4_y1 * c4_mpower(chartInstance, c4_y2)) + c4_x1 * c4_y1 * c4_mpower
    (chartInstance, c4_y3)) + c4_x2 * c4_mpower(chartInstance, c4_y1) * c4_y2) +
    c4_x1 * c4_y1 * c4_mpower(chartInstance, c4_y4)) + c4_x2 * c4_y2 * c4_mpower
    (chartInstance, c4_y3)) + c4_x3 * c4_mpower(chartInstance, c4_y1) * c4_y3) +
    c4_x2 * c4_y2 * c4_mpower(chartInstance, c4_y4)) + c4_x3 * c4_mpower
    (chartInstance, c4_y2) * c4_y3) + c4_x4 * c4_mpower(chartInstance, c4_y1) *
    c4_y4) + c4_x3 * c4_y3 * c4_mpower(chartInstance, c4_y4)) + c4_x4 *
    c4_mpower(chartInstance, c4_y2) * c4_y4) + c4_x4 * c4_mpower(chartInstance,
    c4_y3) * c4_y4) + c4_x1 * c4_y1 * c4_mpower(chartInstance, c4_z1)) + c4_x2 *
    c4_y2 * c4_mpower(chartInstance, c4_z2)) + c4_x3 * c4_y3 * c4_mpower
    (chartInstance, c4_z3)) + c4_x4 * c4_y4 * c4_mpower(chartInstance, c4_z4)) +
    c4_x1 * c4_y2 * c4_z1 * c4_z2) + c4_x2 * c4_y1 * c4_z1 * c4_z2) + c4_x1 *
    c4_y3 * c4_z1 * c4_z3) + c4_x3 * c4_y1 * c4_z1 * c4_z3) + c4_x1 * c4_y4 *
    c4_z1 * c4_z4) + c4_x2 * c4_y3 * c4_z2 * c4_z3) + c4_x3 * c4_y2 * c4_z2 *
                       c4_z3) + c4_x4 * c4_y1 * c4_z1 * c4_z4) + c4_x2 * c4_y4 *
                     c4_z2 * c4_z4) + c4_x4 * c4_y2 * c4_z2 * c4_z4) + c4_x3 *
                   c4_y4 * c4_z3 * c4_z4) + c4_x4 * c4_y3 * c4_z3 * c4_z4);
  c4_d20 = 2.0 * c4_x2;
  c4_d21 = 2.0 * c4_x1 * c4_mpower(chartInstance, c4_x3);
  c4_d22 = 2.0 * c4_x2 * c4_x3 * c4_y2;
  c4_d23 = 2.0 * c4_x1 * c4_mpower(chartInstance, c4_x2) * c4_x4 * c4_z1;
  c4_d24 = 2.0 * c4_x1 * c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_z1 * c4_z3;
  c4_d25 = 2.0 * c4_x1;
  c4_d26 = 2.0 * c4_c_mpower(chartInstance, c4_x1) * c4_x3;
  c4_d27 = 2.0 * c4_x1 * c4_c_mpower(chartInstance, c4_x3) * c4_y1;
  c4_d28 = 2.0 * c4_x1 * c4_x3 * c4_c_mpower(chartInstance, c4_y1) * c4_y3;
  c4_d29 = 2.0 * c4_mpower(chartInstance, c4_x3);
  c4_d30 = 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y4);
  c4_d31 = 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z3);
  c4_d32 = c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1);
  c4_d33 = c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z1);
  c4_d34 = c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_z3);
  c4_d35 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x2) + 8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x3)) + 8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x4)) + 8.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_x3)) + 8.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_x4)) + 8.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
    c4_x4)) + 8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_y1)) + 12.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_y2)) + 12.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y1)) + 12.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_y3)) + 8.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y2)) + 12.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
    c4_y1)) + c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_y2))
    + 12.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y4))
    + c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_y1)) +
    12.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_y3)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_y1)) + 8.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y3)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2)) +
    c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_y2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_y1)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2)) +
    c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) +
    c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_y2)) + 8.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3)) + 8.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z1)) + 12.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2)) + 12.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z3)) + 8.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_z1)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z3)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z2)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4)) + 8.0 *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_z3)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z4)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z3)) + 12.0 *
                       c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_z2)) + c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1))
                     + 8.0 * c4_mpower(chartInstance, c4_y2) * c4_mpower
                     (chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x1) *
                    c4_b_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance,
    c4_x2) * c4_b_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance,
    c4_x1) * c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x3) *
                 c4_b_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower
                (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z4)) +
               c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_z3)) + c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_z1))
             + 12.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
              c4_z3)) + c4_b_mpower(chartInstance, c4_x3) * c4_mpower
            (chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_x4) *
           c4_mpower(chartInstance, c4_z1)) + 8.0 * c4_mpower(chartInstance,
           c4_y3) * c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance,
          c4_x2) * c4_b_mpower(chartInstance, c4_z4)) + c4_b_mpower
        (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
       (chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_z2)) + 8.0 *
      c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) +
     c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_z4);
  c4_d36 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d35 + c4_d34) + c4_b_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y1) *
    c4_b_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) *
    c4_b_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y1) *
    c4_b_mpower(chartInstance, c4_z3)) + 12.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y3) *
    c4_b_mpower(chartInstance, c4_z1)) + 8.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 12.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y1) *
    c4_b_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) *
    c4_b_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y3) *
    c4_b_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y4) *
    c4_b_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y2) *
    c4_b_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) *
    c4_b_mpower(chartInstance, c4_z2)) + 8.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y3) *
    c4_b_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) *
    c4_b_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + 8.0 * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + 8.0 * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z4)) + 8.0 * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + 32.0 * c4_mpower(chartInstance, c4_x1)) +
    32.0 * c4_mpower(chartInstance, c4_x2)) + 4.0 * c4_b_mpower(chartInstance,
    c4_x1)) + 32.0 * c4_mpower(chartInstance, c4_x3)) + 4.0 * c4_b_mpower
    (chartInstance, c4_x2)) + 32.0 * c4_mpower(chartInstance, c4_x4)) + 4.0 *
    c4_b_mpower(chartInstance, c4_x3)) + 4.0 * c4_b_mpower(chartInstance, c4_x4))
    + 32.0 * c4_mpower(chartInstance, c4_y1)) + 32.0 * c4_mpower(chartInstance,
    c4_y2)) + 4.0 * c4_b_mpower(chartInstance, c4_y1)) + 32.0 * c4_mpower
    (chartInstance, c4_y3)) + 4.0 * c4_b_mpower(chartInstance, c4_y2)) + 32.0 *
    c4_mpower(chartInstance, c4_y4)) + 4.0 * c4_b_mpower(chartInstance, c4_y3))
    + 4.0 * c4_b_mpower(chartInstance, c4_y4)) + 32.0 * c4_mpower(chartInstance,
    c4_z1)) + 32.0 * c4_mpower(chartInstance, c4_z2)) + 4.0 * c4_b_mpower
    (chartInstance, c4_z1)) + 32.0 * c4_mpower(chartInstance, c4_z3)) + 4.0 *
    c4_b_mpower(chartInstance, c4_z2)) + 32.0 * c4_mpower(chartInstance, c4_z4))
    + 4.0 * c4_b_mpower(chartInstance, c4_z3)) + 4.0 * c4_b_mpower(chartInstance,
    c4_z4)) + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
                       c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y4)) + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
                      c4_mpower(chartInstance, c4_y3)) + 2.0 * c4_mpower
                     (chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x4) *
                     c4_mpower(chartInstance, c4_y2)) + c4_mpower(chartInstance,
    c4_x2) * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2))
                   + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower
                   (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) +
                  2.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower
                  (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4)) +
                 2.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x4) * c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x2) *
                c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y3))
               + c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_x4) * c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance,
    c4_x3) * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1))
             + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x4)
             * c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance,
             c4_x2) * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
             c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower
           (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
          c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_x4) *
          c4_mpower(chartInstance, c4_y2)) + c4_mpower(chartInstance, c4_x2) *
         c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4)) +
        c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_x4) *
        c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x3) *
       c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4)) +
      c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x2) *
      c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_x1) *
     c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_z2);
  c4_d37 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d36 + c4_d33) + c4_d32 * c4_mpower(chartInstance,
    c4_y3)) + c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
                       c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
    c4_y1) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance,
    c4_x3) * c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3))
                     + 2.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower
                     (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z2)) +
                    2.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower
                    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) +
                   2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
                   (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z3)) +
                  2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
                  (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) +
                 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance,
    c4_x1) * c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z4))
               + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance,
    c4_x2) * c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3))
             + 2.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
              c4_y2) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
            (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4) * c4_mpower
            (chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
           c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z4)) +
          2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2)
          * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance,
          c4_x4) * c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance,
          c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
        (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
       c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y4) *
       c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
      c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
     c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4) *
     c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4);
  c4_d38 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d37 + c4_d31) + c4_d30 * c4_mpower(chartInstance,
    c4_z2)) + c4_d29 * c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance,
    c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance,
    c4_x4) * c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3))
    + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z1)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) - 8.0 *
    c4_x1 * c4_x2 * c4_y1 * c4_y2) - 8.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3) - 8.0 *
    c4_x1 * c4_x4 * c4_y1 * c4_y4) - 8.0 * c4_x2 * c4_x3 * c4_y2 * c4_y3) - 8.0 *
                      c4_x2 * c4_x4 * c4_y2 * c4_y4) - 8.0 * c4_x3 * c4_x4 *
                     c4_y3 * c4_y4) - 8.0 * c4_x1 * c4_x2 * c4_z1 * c4_z2) - 8.0
                   * c4_x1 * c4_x3 * c4_z1 * c4_z3) - 8.0 * c4_x1 * c4_x4 *
                  c4_z1 * c4_z4) - 8.0 * c4_x2 * c4_x3 * c4_z2 * c4_z3) - 8.0 *
                c4_x2 * c4_x4 * c4_z2 * c4_z4) - 8.0 * c4_x3 * c4_x4 * c4_z3 *
               c4_z4) - 8.0 * c4_y1 * c4_y2 * c4_z1 * c4_z2) - 8.0 * c4_y1 *
             c4_y3 * c4_z1 * c4_z3) - 8.0 * c4_y1 * c4_y4 * c4_z1 * c4_z4) - 8.0
           * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 8.0 * c4_y2 * c4_y4 * c4_z2 *
          c4_z4) - 8.0 * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x2 *
        c4_y1 * c4_c_mpower(chartInstance, c4_y2)) - 2.0 * c4_x1 * c4_x2 *
       c4_c_mpower(chartInstance, c4_y1) * c4_y2) - 2.0 * c4_x1 * c4_c_mpower
      (chartInstance, c4_x2) * c4_y1 * c4_y2) - 2.0 * c4_c_mpower(chartInstance,
      c4_x1) * c4_x2 * c4_y1 * c4_y2) - 2.0 * c4_x1 * c4_x3 * c4_y1 *
    c4_c_mpower(chartInstance, c4_y3);
  c4_d39 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d38 - c4_d28) - c4_d27 * c4_y3) - c4_d26 * c4_y1 *
    c4_y3) - c4_d25 * c4_x4 * c4_y1 * c4_c_mpower(chartInstance, c4_y4)) - 2.0 *
    c4_x1 * c4_x4 * c4_c_mpower(chartInstance, c4_y1) * c4_y4) - 2.0 * c4_x1 *
    c4_c_mpower(chartInstance, c4_x4) * c4_y1 * c4_y4) - 2.0 * c4_x2 * c4_x3 *
    c4_y2 * c4_c_mpower(chartInstance, c4_y3)) - 2.0 * c4_x2 * c4_x3 *
    c4_c_mpower(chartInstance, c4_y2) * c4_y3) - 2.0 * c4_x2 * c4_c_mpower
    (chartInstance, c4_x3) * c4_y2 * c4_y3) - 2.0 * c4_c_mpower(chartInstance,
    c4_x1) * c4_x4 * c4_y1 * c4_y4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) *
    c4_x3 * c4_y2 * c4_y3) - 2.0 * c4_x2 * c4_x4 * c4_y2 * c4_c_mpower
    (chartInstance, c4_y4)) - 2.0 * c4_x2 * c4_x4 * c4_c_mpower(chartInstance,
    c4_y2) * c4_y4) - 2.0 * c4_x2 * c4_c_mpower(chartInstance, c4_x4) * c4_y2 *
    c4_y4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) * c4_x4 * c4_y2 * c4_y4) -
    2.0 * c4_x3 * c4_x4 * c4_y3 * c4_c_mpower(chartInstance, c4_y4)) - 2.0 *
    c4_x3 * c4_x4 * c4_c_mpower(chartInstance, c4_y3) * c4_y4) - 2.0 * c4_x3 *
    c4_c_mpower(chartInstance, c4_x4) * c4_y3 * c4_y4) - 2.0 * c4_c_mpower
    (chartInstance, c4_x3) * c4_x4 * c4_y3 * c4_y4) - 2.0 * c4_x1 * c4_x2 *
    c4_z1 * c4_c_mpower(chartInstance, c4_z2)) - 2.0 * c4_x1 * c4_x2 *
    c4_c_mpower(chartInstance, c4_z1) * c4_z2) - 2.0 * c4_x1 * c4_c_mpower
    (chartInstance, c4_x2) * c4_z1 * c4_z2) - 2.0 * c4_c_mpower(chartInstance,
    c4_x1) * c4_x2 * c4_z1 * c4_z2) - 2.0 * c4_x1 * c4_x3 * c4_z1 * c4_c_mpower
    (chartInstance, c4_z3)) - 2.0 * c4_x1 * c4_x3 * c4_c_mpower(chartInstance,
    c4_z1) * c4_z3) - 2.0 * c4_x1 * c4_c_mpower(chartInstance, c4_x3) * c4_z1 *
    c4_z3) - 2.0 * c4_c_mpower(chartInstance, c4_x1) * c4_x3 * c4_z1 * c4_z3) -
    2.0 * c4_x1 * c4_x4 * c4_z1 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x1 * c4_x4 * c4_c_mpower(chartInstance, c4_z1) * c4_z4) - 2.0 * c4_x1 *
    c4_c_mpower(chartInstance, c4_x4) * c4_z1 * c4_z4) - 2.0 * c4_x2 * c4_x3 *
    c4_z2 * c4_c_mpower(chartInstance, c4_z3)) - 2.0 * c4_x2 * c4_x3 *
    c4_c_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 * c4_x2 * c4_c_mpower
    (chartInstance, c4_x3) * c4_z2 * c4_z3) - 2.0 * c4_c_mpower(chartInstance,
    c4_x1) * c4_x4 * c4_z1 * c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) *
    c4_x3 * c4_z2 * c4_z3) - 2.0 * c4_x2 * c4_x4 * c4_z2 * c4_c_mpower
    (chartInstance, c4_z4)) - 2.0 * c4_x2 * c4_x4 * c4_c_mpower(chartInstance,
    c4_z2) * c4_z4) - 2.0 * c4_x2 * c4_c_mpower(chartInstance, c4_x4) * c4_z2 *
    c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) * c4_x4 * c4_z2 * c4_z4) -
    2.0 * c4_x3 * c4_x4 * c4_z3 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x3 * c4_x4 * c4_c_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_x3 *
    c4_c_mpower(chartInstance, c4_x4) * c4_z3 * c4_z4) - 2.0 * c4_c_mpower
    (chartInstance, c4_x3) * c4_x4 * c4_z3 * c4_z4) - 2.0 * c4_y1 * c4_y2 *
    c4_z1 * c4_c_mpower(chartInstance, c4_z2)) - 2.0 * c4_y1 * c4_y2 *
    c4_c_mpower(chartInstance, c4_z1) * c4_z2) - 2.0 * c4_y1 * c4_c_mpower
    (chartInstance, c4_y2) * c4_z1 * c4_z2) - 2.0 * c4_c_mpower(chartInstance,
    c4_y1) * c4_y2 * c4_z1 * c4_z2) - 2.0 * c4_y1 * c4_y3 * c4_z1 * c4_c_mpower
    (chartInstance, c4_z3)) - 2.0 * c4_y1 * c4_y3 * c4_c_mpower(chartInstance,
    c4_z1) * c4_z3) - 2.0 * c4_y1 * c4_c_mpower(chartInstance, c4_y3) * c4_z1 *
    c4_z3) - 2.0 * c4_c_mpower(chartInstance, c4_y1) * c4_y3 * c4_z1 * c4_z3) -
    2.0 * c4_y1 * c4_y4 * c4_z1 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_y1 * c4_y4 * c4_c_mpower(chartInstance, c4_z1) * c4_z4) - 2.0 * c4_y1 *
    c4_c_mpower(chartInstance, c4_y4) * c4_z1 * c4_z4) - 2.0 * c4_y2 * c4_y3 *
    c4_z2 * c4_c_mpower(chartInstance, c4_z3)) - 2.0 * c4_y2 * c4_y3 *
    c4_c_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 * c4_y2 * c4_c_mpower
    (chartInstance, c4_y3) * c4_z2 * c4_z3) - 2.0 * c4_c_mpower(chartInstance,
    c4_y1) * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_y2) *
    c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_y2 * c4_y4 * c4_z2 * c4_c_mpower
    (chartInstance, c4_z4)) - 2.0 * c4_y2 * c4_y4 * c4_c_mpower(chartInstance,
    c4_z2) * c4_z4) - 2.0 * c4_y2 * c4_c_mpower(chartInstance, c4_y4) * c4_z2 *
    c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_y2) * c4_y4 * c4_z2 * c4_z4) -
    2.0 * c4_y3 * c4_y4 * c4_z3 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_y3 * c4_y4 * c4_c_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_y3 *
    c4_c_mpower(chartInstance, c4_y4) * c4_z3 * c4_z4) - 2.0 * c4_c_mpower
    (chartInstance, c4_y3) * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x2 *
    c4_mpower(chartInstance, c4_x3) * c4_y1 * c4_y2) - 2.0 * c4_x1 * c4_x2 *
    c4_mpower(chartInstance, c4_x4) * c4_y1 * c4_y2) - 2.0 * c4_x1 * c4_mpower
    (chartInstance, c4_x2) * c4_x3 * c4_y1 * c4_y3) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x2 * c4_x3 * c4_y2 * c4_y3) - 2.0 * c4_x1 *
    c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_y1 * c4_y3) - 2.0 * c4_x1 *
    c4_mpower(chartInstance, c4_x2) * c4_x4 * c4_y1 * c4_y4) - 2.0 * c4_x1 *
    c4_mpower(chartInstance, c4_x3) * c4_x4 * c4_y1 * c4_y4) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x2 * c4_x4 * c4_y2 * c4_y4) - 2.0 * c4_x2 *
    c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_y2 * c4_y3) - 2.0 * c4_x2 *
    c4_mpower(chartInstance, c4_x3) * c4_x4 * c4_y2 * c4_y4) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x3 * c4_x4 * c4_y3 * c4_y4) - 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_x3 * c4_x4 * c4_y3 * c4_y4) - 2.0 * c4_x1 *
    c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_y3)) - 2.0 * c4_x1 *
                       c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_y4))
                      - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_mpower(chartInstance,
    c4_y2) * c4_y3) - 2.0 * c4_x2 * c4_x3 * c4_mpower(chartInstance, c4_y1) *
                     c4_y2 * c4_y3) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3 *
                    c4_mpower(chartInstance, c4_y4)) - 2.0 * c4_x1 * c4_x4 *
                   c4_y1 * c4_mpower(chartInstance, c4_y2) * c4_y4) - 2.0 *
                  c4_x1 * c4_x4 * c4_y1 * c4_mpower(chartInstance, c4_y3) *
                  c4_y4) - 2.0 * c4_x2 * c4_x4 * c4_mpower(chartInstance, c4_y1)
                 * c4_y2 * c4_y4) - 2.0 * c4_x2 * c4_x3 * c4_y2 * c4_y3 *
                c4_mpower(chartInstance, c4_y4)) - 2.0 * c4_x2 * c4_x4 * c4_y2 *
               c4_mpower(chartInstance, c4_y3) * c4_y4) - 2.0 * c4_x3 * c4_x4 *
              c4_mpower(chartInstance, c4_y1) * c4_y3 * c4_y4) - 2.0 * c4_x3 *
             c4_x4 * c4_mpower(chartInstance, c4_y2) * c4_y3 * c4_y4) - 2.0 *
            c4_x1 * c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_z1)) -
           2.0 * c4_x1 * c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_z2))
          - 2.0 * c4_x1 * c4_x2 * c4_mpower(chartInstance, c4_x3) * c4_z1 *
          c4_z2) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3 * c4_mpower(chartInstance,
          c4_z1)) - 2.0 * c4_x1 * c4_x2 * c4_mpower(chartInstance, c4_x4) *
        c4_z1 * c4_z2) - 2.0 * c4_x1 * c4_mpower(chartInstance, c4_x2) * c4_x3 *
       c4_z1 * c4_z3) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3 * c4_mpower
      (chartInstance, c4_z3)) - 2.0 * c4_x1 * c4_x4 * c4_y1 * c4_y4 * c4_mpower
     (chartInstance, c4_z1)) - 2.0 * c4_mpower(chartInstance, c4_x1) * c4_x2 *
    c4_x3 * c4_z2 * c4_z3;
  c4_b_B =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d39 - c4_d24) - c4_d23 * c4_z4) - c4_d22 * c4_y3 *
    c4_mpower(chartInstance, c4_z2)) - c4_d21 * c4_x4 * c4_z1 * c4_z4) - c4_d20 *
    c4_x3 * c4_y2 * c4_y3 * c4_mpower(chartInstance, c4_z3)) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x2 * c4_x4 * c4_z2 * c4_z4) - 2.0 * c4_x1 *
    c4_x4 * c4_y1 * c4_y4 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_x2 *
    c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_z2 * c4_z3) - 2.0 * c4_x2 *
    c4_x4 * c4_y2 * c4_y4 * c4_mpower(chartInstance, c4_z2)) - 2.0 * c4_x2 *
    c4_mpower(chartInstance, c4_x3) * c4_x4 * c4_z2 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x3 * c4_x4 * c4_z3 * c4_z4) - 2.0 * c4_x2 *
    c4_x4 * c4_y2 * c4_y4 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_x3 * c4_x4 * c4_z3 * c4_z4) - 2.0 * c4_x3 *
    c4_x4 * c4_y3 * c4_y4 * c4_mpower(chartInstance, c4_z3)) - 2.0 * c4_x3 *
    c4_x4 * c4_y3 * c4_y4 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_x1 *
    c4_x2 * c4_mpower(chartInstance, c4_y1) * c4_z1 * c4_z2) - 2.0 * c4_x1 *
    c4_x2 * c4_mpower(chartInstance, c4_y2) * c4_z1 * c4_z2) - 2.0 * c4_x1 *
    c4_x3 * c4_mpower(chartInstance, c4_y1) * c4_z1 * c4_z3) - 2.0 * c4_x1 *
    c4_x3 * c4_mpower(chartInstance, c4_y3) * c4_z1 * c4_z3) - 2.0 * c4_x1 *
    c4_x4 * c4_mpower(chartInstance, c4_y1) * c4_z1 * c4_z4) - 2.0 * c4_x2 *
    c4_x3 * c4_mpower(chartInstance, c4_y2) * c4_z2 * c4_z3) - 2.0 * c4_x2 *
    c4_x3 * c4_mpower(chartInstance, c4_y3) * c4_z2 * c4_z3) - 2.0 * c4_x1 *
    c4_x4 * c4_mpower(chartInstance, c4_y4) * c4_z1 * c4_z4) - 2.0 * c4_x2 *
    c4_x4 * c4_mpower(chartInstance, c4_y2) * c4_z2 * c4_z4) - 2.0 * c4_x2 *
    c4_x4 * c4_mpower(chartInstance, c4_y4) * c4_z2 * c4_z4) - 2.0 * c4_x3 *
    c4_x4 * c4_mpower(chartInstance, c4_y3) * c4_z3 * c4_z4) - 2.0 * c4_x3 *
    c4_x4 * c4_mpower(chartInstance, c4_y4) * c4_z3 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_y1 * c4_y2 * c4_z1 * c4_z2) - 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_y1 * c4_y2 * c4_z1 * c4_z2) - 2.0 * c4_x1 *
    c4_x2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z3)) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_y1 * c4_y3 * c4_z1 * c4_z3) - 2.0 * c4_x1 *
    c4_x2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_x1 *
    c4_x3 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 * c4_x2 *
    c4_x3 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z3) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_y1 * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x3) * c4_y1 * c4_y3 * c4_z1 * c4_z3) - 2.0 * c4_x1 *
    c4_x3 * c4_z1 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_x1 *
    c4_x4 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_x1 *
    c4_x4 * c4_z1 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_x2 *
    c4_x4 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x3) * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_x2 *
    c4_x3 * c4_z2 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x4) * c4_y1 * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_x2 *
    c4_x4 * c4_z2 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_x3 *
    c4_x4 * c4_mpower(chartInstance, c4_z1) * c4_z3 * c4_z4) - 2.0 * c4_x3 *
    c4_x4 * c4_mpower(chartInstance, c4_z2) * c4_z3 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x4) * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x3) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x4) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_y1 *
    c4_y2 * c4_mpower(chartInstance, c4_y3) * c4_z1 * c4_z2) - 2.0 * c4_y1 *
    c4_y2 * c4_mpower(chartInstance, c4_y4) * c4_z1 * c4_z2) - 2.0 * c4_y1 *
    c4_mpower(chartInstance, c4_y2) * c4_y3 * c4_z1 * c4_z3) - 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_y1 *
    c4_y3 * c4_mpower(chartInstance, c4_y4) * c4_z1 * c4_z3) - 2.0 * c4_y1 *
    c4_mpower(chartInstance, c4_y2) * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_y1 *
    c4_mpower(chartInstance, c4_y3) * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 2.0 * c4_y2 *
    c4_y3 * c4_mpower(chartInstance, c4_y4) * c4_z2 * c4_z3) - 2.0 * c4_y2 *
    c4_mpower(chartInstance, c4_y3) * c4_y4 * c4_z2 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_y2) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_y1 *
    c4_y2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z3)) - 2.0 * c4_y1 *
    c4_y2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_y1 *
    c4_y3 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 * c4_y2 *
    c4_y3 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z3) - 2.0 * c4_y1 *
    c4_y3 * c4_z1 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_y1 *
    c4_y4 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z4) - 2.0 * c4_y1 *
    c4_y4 * c4_z1 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_y2 *
    c4_y4 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z4) - 2.0 * c4_y2 *
    c4_y3 * c4_z2 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_y2 *
    c4_y4 * c4_z2 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_y3 *
    c4_y4 * c4_mpower(chartInstance, c4_z1) * c4_z3 * c4_z4) - 2.0 * c4_y3 *
    c4_y4 * c4_mpower(chartInstance, c4_z2) * c4_z3 * c4_z4) - 2.0 * c4_x1 *
    c4_x2 * c4_y1 * c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_x1 * c4_x2 * c4_y2 * c4_y3
    * c4_z1 * c4_z3) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y2 * c4_z2 * c4_z3) -
    2.0 * c4_x1 * c4_x3 * c4_y2 * c4_y3 * c4_z1 * c4_z2) - 2.0 * c4_x2 * c4_x3 *
    c4_y1 * c4_y2 * c4_z1 * c4_z3) - 2.0 * c4_x2 * c4_x3 * c4_y1 * c4_y3 * c4_z1
                       * c4_z2) - 2.0 * c4_x1 * c4_x2 * c4_y1 * c4_y4 * c4_z2 *
                      c4_z4) - 2.0 * c4_x1 * c4_x2 * c4_y2 * c4_y4 * c4_z1 *
                     c4_z4) - 2.0 * c4_x1 * c4_x4 * c4_y1 * c4_y2 * c4_z2 *
                    c4_z4) - 2.0 * c4_x1 * c4_x4 * c4_y2 * c4_y4 * c4_z1 * c4_z2)
                  - 2.0 * c4_x2 * c4_x4 * c4_y1 * c4_y2 * c4_z1 * c4_z4) - 2.0 *
                 c4_x2 * c4_x4 * c4_y1 * c4_y4 * c4_z1 * c4_z2) - 2.0 * c4_x1 *
                c4_x3 * c4_y1 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x3 *
               c4_y3 * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_x1 * c4_x4 * c4_y1 *
              c4_y3 * c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x4 * c4_y3 * c4_y4 *
             c4_z1 * c4_z3) - 2.0 * c4_x3 * c4_x4 * c4_y1 * c4_y3 * c4_z1 *
            c4_z4) - 2.0 * c4_x3 * c4_x4 * c4_y1 * c4_y4 * c4_z1 * c4_z3) - 2.0 *
          c4_x2 * c4_x3 * c4_y2 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_x2 * c4_x3 *
         c4_y3 * c4_y4 * c4_z2 * c4_z4) - 2.0 * c4_x2 * c4_x4 * c4_y2 * c4_y3 *
        c4_z3 * c4_z4) - 2.0 * c4_x2 * c4_x4 * c4_y3 * c4_y4 * c4_z2 * c4_z3) -
      2.0 * c4_x3 * c4_x4 * c4_y2 * c4_y3 * c4_z2 * c4_z4) - 2.0 * c4_x3 * c4_x4
     * c4_y2 * c4_y4 * c4_z2 * c4_z3) + 64.0;
  c4_j_x = c4_b_A;
  c4_e_y = c4_b_B;
  c4_k_x = c4_j_x;
  c4_f_y = c4_e_y;
  c4_l_x = c4_k_x;
  c4_g_y = c4_f_y;
  c4_h_y = c4_l_x / c4_g_y;
  c4_c_A = 4.0 * (((((((((((((((((((((((((((((((((((((((((((((((((((4.0 * c4_x1 *
    c4_z1 + 4.0 * c4_x2 * c4_z2) + 4.0 * c4_x3 * c4_z3) + 4.0 * c4_x4 * c4_z4) +
    c4_x1 * c4_c_mpower(chartInstance, c4_z1)) + c4_c_mpower(chartInstance,
    c4_x1) * c4_z1) + c4_x2 * c4_c_mpower(chartInstance, c4_z2)) + c4_c_mpower
    (chartInstance, c4_x2) * c4_z2) + c4_x3 * c4_c_mpower(chartInstance, c4_z3))
    + c4_c_mpower(chartInstance, c4_x3) * c4_z3) + c4_x4 * c4_c_mpower
    (chartInstance, c4_z4)) + c4_c_mpower(chartInstance, c4_x4) * c4_z4) + c4_x1
    * c4_mpower(chartInstance, c4_x2) * c4_z1) + c4_x1 * c4_mpower(chartInstance,
    c4_x3) * c4_z1) + c4_mpower(chartInstance, c4_x1) * c4_x2 * c4_z2) + c4_x1 *
    c4_mpower(chartInstance, c4_x4) * c4_z1) + c4_x2 * c4_mpower(chartInstance,
    c4_x3) * c4_z2) + c4_mpower(chartInstance, c4_x1) * c4_x3 * c4_z3) + c4_x2 *
    c4_mpower(chartInstance, c4_x4) * c4_z2) + c4_mpower(chartInstance, c4_x2) *
    c4_x3 * c4_z3) + c4_mpower(chartInstance, c4_x1) * c4_x4 * c4_z4) + c4_x3 *
    c4_mpower(chartInstance, c4_x4) * c4_z3) + c4_mpower(chartInstance, c4_x2) *
    c4_x4 * c4_z4) + c4_mpower(chartInstance, c4_x3) * c4_x4 * c4_z4) + c4_x1 *
    c4_mpower(chartInstance, c4_y1) * c4_z1) + c4_x2 * c4_mpower(chartInstance,
    c4_y2) * c4_z2) + c4_x3 * c4_mpower(chartInstance, c4_y3) * c4_z3) + c4_x4 *
    c4_mpower(chartInstance, c4_y4) * c4_z4) + c4_x1 * c4_z1 * c4_mpower
    (chartInstance, c4_z2)) + c4_x1 * c4_z1 * c4_mpower(chartInstance, c4_z3)) +
    c4_x2 * c4_mpower(chartInstance, c4_z1) * c4_z2) + c4_x1 * c4_z1 * c4_mpower
    (chartInstance, c4_z4)) + c4_x2 * c4_z2 * c4_mpower(chartInstance, c4_z3)) +
    c4_x3 * c4_mpower(chartInstance, c4_z1) * c4_z3) + c4_x2 * c4_z2 * c4_mpower
                                   (chartInstance, c4_z4)) + c4_x3 * c4_mpower
    (chartInstance, c4_z2) * c4_z3) + c4_x4 * c4_mpower(chartInstance, c4_z1) *
    c4_z4) + c4_x3 * c4_z3 * c4_mpower(chartInstance, c4_z4)) + c4_x4 *
    c4_mpower(chartInstance, c4_z2) * c4_z4) + c4_x4 * c4_mpower(chartInstance,
    c4_z3) * c4_z4) + c4_x1 * c4_y1 * c4_y2 * c4_z2) + c4_x2 * c4_y1 * c4_y2 *
    c4_z1) + c4_x1 * c4_y1 * c4_y3 * c4_z3) + c4_x3 * c4_y1 * c4_y3 * c4_z1) +
    c4_x1 * c4_y1 * c4_y4 * c4_z4) + c4_x2 * c4_y2 * c4_y3 * c4_z3) + c4_x3 *
                       c4_y2 * c4_y3 * c4_z2) + c4_x4 * c4_y1 * c4_y4 * c4_z1) +
                     c4_x2 * c4_y2 * c4_y4 * c4_z4) + c4_x4 * c4_y2 * c4_y4 *
                    c4_z2) + c4_x3 * c4_y3 * c4_y4 * c4_z4) + c4_x4 * c4_y3 *
                  c4_y4 * c4_z3);
  c4_d40 = 2.0 * c4_x2;
  c4_d41 = 2.0 * c4_x1 * c4_mpower(chartInstance, c4_x3);
  c4_d42 = 2.0 * c4_x2 * c4_x3 * c4_y2;
  c4_d43 = 2.0 * c4_x1 * c4_mpower(chartInstance, c4_x2) * c4_x4 * c4_z1;
  c4_d44 = 2.0 * c4_x1 * c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_z1 * c4_z3;
  c4_d45 = 2.0 * c4_x1;
  c4_d46 = 2.0 * c4_c_mpower(chartInstance, c4_x1) * c4_x3;
  c4_d47 = 2.0 * c4_x1 * c4_c_mpower(chartInstance, c4_x3) * c4_y1;
  c4_d48 = 2.0 * c4_x1 * c4_x3 * c4_c_mpower(chartInstance, c4_y1) * c4_y3;
  c4_d49 = 2.0 * c4_mpower(chartInstance, c4_x3);
  c4_d50 = 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y4);
  c4_d51 = 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z3);
  c4_d52 = c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1);
  c4_d53 = c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z1);
  c4_d54 = c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_z3);
  c4_d55 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x2) + 8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x3)) + 8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x4)) + 8.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_x3)) + 8.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_x4)) + 8.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
    c4_x4)) + 8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_y1)) + 12.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_y2)) + 12.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y1)) + 12.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_y3)) + 8.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y2)) + 12.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
    c4_y1)) + c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_y2))
    + 12.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y4))
    + c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_y1)) +
    12.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_y3)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_y1)) + 8.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y3)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2)) +
    c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_y2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_y1)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2)) +
    c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) +
    c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_y2)) + 8.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3)) + 8.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z1)) + 12.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2)) + 12.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z3)) + 8.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_z1)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z3)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z2)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4)) + 8.0 *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_z3)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z4)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z3)) + 12.0 *
                       c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_z2)) + c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1))
                     + 8.0 * c4_mpower(chartInstance, c4_y2) * c4_mpower
                     (chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x1) *
                    c4_b_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance,
    c4_x2) * c4_b_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance,
    c4_x1) * c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x3) *
                 c4_b_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower
                (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z4)) +
               c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_z3)) + c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_z1))
             + 12.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
              c4_z3)) + c4_b_mpower(chartInstance, c4_x3) * c4_mpower
            (chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_x4) *
           c4_mpower(chartInstance, c4_z1)) + 8.0 * c4_mpower(chartInstance,
           c4_y3) * c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance,
          c4_x2) * c4_b_mpower(chartInstance, c4_z4)) + c4_b_mpower
        (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
       (chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_z2)) + 8.0 *
      c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) +
     c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_z4);
  c4_d56 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d55 + c4_d54) + c4_b_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y1) *
    c4_b_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) *
    c4_b_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y1) *
    c4_b_mpower(chartInstance, c4_z3)) + 12.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y3) *
    c4_b_mpower(chartInstance, c4_z1)) + 8.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 12.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y1) *
    c4_b_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) *
    c4_b_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y3) *
    c4_b_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y4) *
    c4_b_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y2) *
    c4_b_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) *
    c4_b_mpower(chartInstance, c4_z2)) + 8.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y3) *
    c4_b_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) *
    c4_b_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + 8.0 * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + 8.0 * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z4)) + 8.0 * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + 32.0 * c4_mpower(chartInstance, c4_x1)) +
    32.0 * c4_mpower(chartInstance, c4_x2)) + 4.0 * c4_b_mpower(chartInstance,
    c4_x1)) + 32.0 * c4_mpower(chartInstance, c4_x3)) + 4.0 * c4_b_mpower
    (chartInstance, c4_x2)) + 32.0 * c4_mpower(chartInstance, c4_x4)) + 4.0 *
    c4_b_mpower(chartInstance, c4_x3)) + 4.0 * c4_b_mpower(chartInstance, c4_x4))
    + 32.0 * c4_mpower(chartInstance, c4_y1)) + 32.0 * c4_mpower(chartInstance,
    c4_y2)) + 4.0 * c4_b_mpower(chartInstance, c4_y1)) + 32.0 * c4_mpower
    (chartInstance, c4_y3)) + 4.0 * c4_b_mpower(chartInstance, c4_y2)) + 32.0 *
    c4_mpower(chartInstance, c4_y4)) + 4.0 * c4_b_mpower(chartInstance, c4_y3))
    + 4.0 * c4_b_mpower(chartInstance, c4_y4)) + 32.0 * c4_mpower(chartInstance,
    c4_z1)) + 32.0 * c4_mpower(chartInstance, c4_z2)) + 4.0 * c4_b_mpower
    (chartInstance, c4_z1)) + 32.0 * c4_mpower(chartInstance, c4_z3)) + 4.0 *
    c4_b_mpower(chartInstance, c4_z2)) + 32.0 * c4_mpower(chartInstance, c4_z4))
    + 4.0 * c4_b_mpower(chartInstance, c4_z3)) + 4.0 * c4_b_mpower(chartInstance,
    c4_z4)) + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
                       c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y4)) + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
                      c4_mpower(chartInstance, c4_y3)) + 2.0 * c4_mpower
                     (chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x4) *
                     c4_mpower(chartInstance, c4_y2)) + c4_mpower(chartInstance,
    c4_x2) * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2))
                   + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower
                   (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) +
                  2.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower
                  (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4)) +
                 2.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x4) * c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x2) *
                c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y3))
               + c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_x4) * c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance,
    c4_x3) * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1))
             + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x4)
             * c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance,
             c4_x2) * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
             c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower
           (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
          c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_x4) *
          c4_mpower(chartInstance, c4_y2)) + c4_mpower(chartInstance, c4_x2) *
         c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4)) +
        c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_x4) *
        c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x3) *
       c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4)) +
      c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x2) *
      c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_x1) *
     c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_z2);
  c4_d57 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d56 + c4_d53) + c4_d52 * c4_mpower(chartInstance,
    c4_y3)) + c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
                       c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
    c4_y1) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance,
    c4_x3) * c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3))
                     + 2.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower
                     (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z2)) +
                    2.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower
                    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) +
                   2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
                   (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z3)) +
                  2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
                  (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) +
                 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance,
    c4_x1) * c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z4))
               + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance,
    c4_x2) * c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3))
             + 2.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
              c4_y2) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
            (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4) * c4_mpower
            (chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
           c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z4)) +
          2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2)
          * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance,
          c4_x4) * c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance,
          c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
        (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
       c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y4) *
       c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
      c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
     c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4) *
     c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4);
  c4_d58 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d57 + c4_d51) + c4_d50 * c4_mpower(chartInstance,
    c4_z2)) + c4_d49 * c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance,
    c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance,
    c4_x4) * c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3))
    + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z1)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) - 8.0 *
    c4_x1 * c4_x2 * c4_y1 * c4_y2) - 8.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3) - 8.0 *
    c4_x1 * c4_x4 * c4_y1 * c4_y4) - 8.0 * c4_x2 * c4_x3 * c4_y2 * c4_y3) - 8.0 *
                      c4_x2 * c4_x4 * c4_y2 * c4_y4) - 8.0 * c4_x3 * c4_x4 *
                     c4_y3 * c4_y4) - 8.0 * c4_x1 * c4_x2 * c4_z1 * c4_z2) - 8.0
                   * c4_x1 * c4_x3 * c4_z1 * c4_z3) - 8.0 * c4_x1 * c4_x4 *
                  c4_z1 * c4_z4) - 8.0 * c4_x2 * c4_x3 * c4_z2 * c4_z3) - 8.0 *
                c4_x2 * c4_x4 * c4_z2 * c4_z4) - 8.0 * c4_x3 * c4_x4 * c4_z3 *
               c4_z4) - 8.0 * c4_y1 * c4_y2 * c4_z1 * c4_z2) - 8.0 * c4_y1 *
             c4_y3 * c4_z1 * c4_z3) - 8.0 * c4_y1 * c4_y4 * c4_z1 * c4_z4) - 8.0
           * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 8.0 * c4_y2 * c4_y4 * c4_z2 *
          c4_z4) - 8.0 * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x2 *
        c4_y1 * c4_c_mpower(chartInstance, c4_y2)) - 2.0 * c4_x1 * c4_x2 *
       c4_c_mpower(chartInstance, c4_y1) * c4_y2) - 2.0 * c4_x1 * c4_c_mpower
      (chartInstance, c4_x2) * c4_y1 * c4_y2) - 2.0 * c4_c_mpower(chartInstance,
      c4_x1) * c4_x2 * c4_y1 * c4_y2) - 2.0 * c4_x1 * c4_x3 * c4_y1 *
    c4_c_mpower(chartInstance, c4_y3);
  c4_d59 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d58 - c4_d48) - c4_d47 * c4_y3) - c4_d46 * c4_y1 *
    c4_y3) - c4_d45 * c4_x4 * c4_y1 * c4_c_mpower(chartInstance, c4_y4)) - 2.0 *
    c4_x1 * c4_x4 * c4_c_mpower(chartInstance, c4_y1) * c4_y4) - 2.0 * c4_x1 *
    c4_c_mpower(chartInstance, c4_x4) * c4_y1 * c4_y4) - 2.0 * c4_x2 * c4_x3 *
    c4_y2 * c4_c_mpower(chartInstance, c4_y3)) - 2.0 * c4_x2 * c4_x3 *
    c4_c_mpower(chartInstance, c4_y2) * c4_y3) - 2.0 * c4_x2 * c4_c_mpower
    (chartInstance, c4_x3) * c4_y2 * c4_y3) - 2.0 * c4_c_mpower(chartInstance,
    c4_x1) * c4_x4 * c4_y1 * c4_y4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) *
    c4_x3 * c4_y2 * c4_y3) - 2.0 * c4_x2 * c4_x4 * c4_y2 * c4_c_mpower
    (chartInstance, c4_y4)) - 2.0 * c4_x2 * c4_x4 * c4_c_mpower(chartInstance,
    c4_y2) * c4_y4) - 2.0 * c4_x2 * c4_c_mpower(chartInstance, c4_x4) * c4_y2 *
    c4_y4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) * c4_x4 * c4_y2 * c4_y4) -
    2.0 * c4_x3 * c4_x4 * c4_y3 * c4_c_mpower(chartInstance, c4_y4)) - 2.0 *
    c4_x3 * c4_x4 * c4_c_mpower(chartInstance, c4_y3) * c4_y4) - 2.0 * c4_x3 *
    c4_c_mpower(chartInstance, c4_x4) * c4_y3 * c4_y4) - 2.0 * c4_c_mpower
    (chartInstance, c4_x3) * c4_x4 * c4_y3 * c4_y4) - 2.0 * c4_x1 * c4_x2 *
    c4_z1 * c4_c_mpower(chartInstance, c4_z2)) - 2.0 * c4_x1 * c4_x2 *
    c4_c_mpower(chartInstance, c4_z1) * c4_z2) - 2.0 * c4_x1 * c4_c_mpower
    (chartInstance, c4_x2) * c4_z1 * c4_z2) - 2.0 * c4_c_mpower(chartInstance,
    c4_x1) * c4_x2 * c4_z1 * c4_z2) - 2.0 * c4_x1 * c4_x3 * c4_z1 * c4_c_mpower
    (chartInstance, c4_z3)) - 2.0 * c4_x1 * c4_x3 * c4_c_mpower(chartInstance,
    c4_z1) * c4_z3) - 2.0 * c4_x1 * c4_c_mpower(chartInstance, c4_x3) * c4_z1 *
    c4_z3) - 2.0 * c4_c_mpower(chartInstance, c4_x1) * c4_x3 * c4_z1 * c4_z3) -
    2.0 * c4_x1 * c4_x4 * c4_z1 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x1 * c4_x4 * c4_c_mpower(chartInstance, c4_z1) * c4_z4) - 2.0 * c4_x1 *
    c4_c_mpower(chartInstance, c4_x4) * c4_z1 * c4_z4) - 2.0 * c4_x2 * c4_x3 *
    c4_z2 * c4_c_mpower(chartInstance, c4_z3)) - 2.0 * c4_x2 * c4_x3 *
    c4_c_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 * c4_x2 * c4_c_mpower
    (chartInstance, c4_x3) * c4_z2 * c4_z3) - 2.0 * c4_c_mpower(chartInstance,
    c4_x1) * c4_x4 * c4_z1 * c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) *
    c4_x3 * c4_z2 * c4_z3) - 2.0 * c4_x2 * c4_x4 * c4_z2 * c4_c_mpower
    (chartInstance, c4_z4)) - 2.0 * c4_x2 * c4_x4 * c4_c_mpower(chartInstance,
    c4_z2) * c4_z4) - 2.0 * c4_x2 * c4_c_mpower(chartInstance, c4_x4) * c4_z2 *
    c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) * c4_x4 * c4_z2 * c4_z4) -
    2.0 * c4_x3 * c4_x4 * c4_z3 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x3 * c4_x4 * c4_c_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_x3 *
    c4_c_mpower(chartInstance, c4_x4) * c4_z3 * c4_z4) - 2.0 * c4_c_mpower
    (chartInstance, c4_x3) * c4_x4 * c4_z3 * c4_z4) - 2.0 * c4_y1 * c4_y2 *
    c4_z1 * c4_c_mpower(chartInstance, c4_z2)) - 2.0 * c4_y1 * c4_y2 *
    c4_c_mpower(chartInstance, c4_z1) * c4_z2) - 2.0 * c4_y1 * c4_c_mpower
    (chartInstance, c4_y2) * c4_z1 * c4_z2) - 2.0 * c4_c_mpower(chartInstance,
    c4_y1) * c4_y2 * c4_z1 * c4_z2) - 2.0 * c4_y1 * c4_y3 * c4_z1 * c4_c_mpower
    (chartInstance, c4_z3)) - 2.0 * c4_y1 * c4_y3 * c4_c_mpower(chartInstance,
    c4_z1) * c4_z3) - 2.0 * c4_y1 * c4_c_mpower(chartInstance, c4_y3) * c4_z1 *
    c4_z3) - 2.0 * c4_c_mpower(chartInstance, c4_y1) * c4_y3 * c4_z1 * c4_z3) -
    2.0 * c4_y1 * c4_y4 * c4_z1 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_y1 * c4_y4 * c4_c_mpower(chartInstance, c4_z1) * c4_z4) - 2.0 * c4_y1 *
    c4_c_mpower(chartInstance, c4_y4) * c4_z1 * c4_z4) - 2.0 * c4_y2 * c4_y3 *
    c4_z2 * c4_c_mpower(chartInstance, c4_z3)) - 2.0 * c4_y2 * c4_y3 *
    c4_c_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 * c4_y2 * c4_c_mpower
    (chartInstance, c4_y3) * c4_z2 * c4_z3) - 2.0 * c4_c_mpower(chartInstance,
    c4_y1) * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_y2) *
    c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_y2 * c4_y4 * c4_z2 * c4_c_mpower
    (chartInstance, c4_z4)) - 2.0 * c4_y2 * c4_y4 * c4_c_mpower(chartInstance,
    c4_z2) * c4_z4) - 2.0 * c4_y2 * c4_c_mpower(chartInstance, c4_y4) * c4_z2 *
    c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_y2) * c4_y4 * c4_z2 * c4_z4) -
    2.0 * c4_y3 * c4_y4 * c4_z3 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_y3 * c4_y4 * c4_c_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_y3 *
    c4_c_mpower(chartInstance, c4_y4) * c4_z3 * c4_z4) - 2.0 * c4_c_mpower
    (chartInstance, c4_y3) * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x2 *
    c4_mpower(chartInstance, c4_x3) * c4_y1 * c4_y2) - 2.0 * c4_x1 * c4_x2 *
    c4_mpower(chartInstance, c4_x4) * c4_y1 * c4_y2) - 2.0 * c4_x1 * c4_mpower
    (chartInstance, c4_x2) * c4_x3 * c4_y1 * c4_y3) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x2 * c4_x3 * c4_y2 * c4_y3) - 2.0 * c4_x1 *
    c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_y1 * c4_y3) - 2.0 * c4_x1 *
    c4_mpower(chartInstance, c4_x2) * c4_x4 * c4_y1 * c4_y4) - 2.0 * c4_x1 *
    c4_mpower(chartInstance, c4_x3) * c4_x4 * c4_y1 * c4_y4) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x2 * c4_x4 * c4_y2 * c4_y4) - 2.0 * c4_x2 *
    c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_y2 * c4_y3) - 2.0 * c4_x2 *
    c4_mpower(chartInstance, c4_x3) * c4_x4 * c4_y2 * c4_y4) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x3 * c4_x4 * c4_y3 * c4_y4) - 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_x3 * c4_x4 * c4_y3 * c4_y4) - 2.0 * c4_x1 *
    c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_y3)) - 2.0 * c4_x1 *
                       c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_y4))
                      - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_mpower(chartInstance,
    c4_y2) * c4_y3) - 2.0 * c4_x2 * c4_x3 * c4_mpower(chartInstance, c4_y1) *
                     c4_y2 * c4_y3) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3 *
                    c4_mpower(chartInstance, c4_y4)) - 2.0 * c4_x1 * c4_x4 *
                   c4_y1 * c4_mpower(chartInstance, c4_y2) * c4_y4) - 2.0 *
                  c4_x1 * c4_x4 * c4_y1 * c4_mpower(chartInstance, c4_y3) *
                  c4_y4) - 2.0 * c4_x2 * c4_x4 * c4_mpower(chartInstance, c4_y1)
                 * c4_y2 * c4_y4) - 2.0 * c4_x2 * c4_x3 * c4_y2 * c4_y3 *
                c4_mpower(chartInstance, c4_y4)) - 2.0 * c4_x2 * c4_x4 * c4_y2 *
               c4_mpower(chartInstance, c4_y3) * c4_y4) - 2.0 * c4_x3 * c4_x4 *
              c4_mpower(chartInstance, c4_y1) * c4_y3 * c4_y4) - 2.0 * c4_x3 *
             c4_x4 * c4_mpower(chartInstance, c4_y2) * c4_y3 * c4_y4) - 2.0 *
            c4_x1 * c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_z1)) -
           2.0 * c4_x1 * c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_z2))
          - 2.0 * c4_x1 * c4_x2 * c4_mpower(chartInstance, c4_x3) * c4_z1 *
          c4_z2) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3 * c4_mpower(chartInstance,
          c4_z1)) - 2.0 * c4_x1 * c4_x2 * c4_mpower(chartInstance, c4_x4) *
        c4_z1 * c4_z2) - 2.0 * c4_x1 * c4_mpower(chartInstance, c4_x2) * c4_x3 *
       c4_z1 * c4_z3) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3 * c4_mpower
      (chartInstance, c4_z3)) - 2.0 * c4_x1 * c4_x4 * c4_y1 * c4_y4 * c4_mpower
     (chartInstance, c4_z1)) - 2.0 * c4_mpower(chartInstance, c4_x1) * c4_x2 *
    c4_x3 * c4_z2 * c4_z3;
  c4_c_B =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d59 - c4_d44) - c4_d43 * c4_z4) - c4_d42 * c4_y3 *
    c4_mpower(chartInstance, c4_z2)) - c4_d41 * c4_x4 * c4_z1 * c4_z4) - c4_d40 *
    c4_x3 * c4_y2 * c4_y3 * c4_mpower(chartInstance, c4_z3)) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x2 * c4_x4 * c4_z2 * c4_z4) - 2.0 * c4_x1 *
    c4_x4 * c4_y1 * c4_y4 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_x2 *
    c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_z2 * c4_z3) - 2.0 * c4_x2 *
    c4_x4 * c4_y2 * c4_y4 * c4_mpower(chartInstance, c4_z2)) - 2.0 * c4_x2 *
    c4_mpower(chartInstance, c4_x3) * c4_x4 * c4_z2 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x3 * c4_x4 * c4_z3 * c4_z4) - 2.0 * c4_x2 *
    c4_x4 * c4_y2 * c4_y4 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_x3 * c4_x4 * c4_z3 * c4_z4) - 2.0 * c4_x3 *
    c4_x4 * c4_y3 * c4_y4 * c4_mpower(chartInstance, c4_z3)) - 2.0 * c4_x3 *
    c4_x4 * c4_y3 * c4_y4 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_x1 *
    c4_x2 * c4_mpower(chartInstance, c4_y1) * c4_z1 * c4_z2) - 2.0 * c4_x1 *
    c4_x2 * c4_mpower(chartInstance, c4_y2) * c4_z1 * c4_z2) - 2.0 * c4_x1 *
    c4_x3 * c4_mpower(chartInstance, c4_y1) * c4_z1 * c4_z3) - 2.0 * c4_x1 *
    c4_x3 * c4_mpower(chartInstance, c4_y3) * c4_z1 * c4_z3) - 2.0 * c4_x1 *
    c4_x4 * c4_mpower(chartInstance, c4_y1) * c4_z1 * c4_z4) - 2.0 * c4_x2 *
    c4_x3 * c4_mpower(chartInstance, c4_y2) * c4_z2 * c4_z3) - 2.0 * c4_x2 *
    c4_x3 * c4_mpower(chartInstance, c4_y3) * c4_z2 * c4_z3) - 2.0 * c4_x1 *
    c4_x4 * c4_mpower(chartInstance, c4_y4) * c4_z1 * c4_z4) - 2.0 * c4_x2 *
    c4_x4 * c4_mpower(chartInstance, c4_y2) * c4_z2 * c4_z4) - 2.0 * c4_x2 *
    c4_x4 * c4_mpower(chartInstance, c4_y4) * c4_z2 * c4_z4) - 2.0 * c4_x3 *
    c4_x4 * c4_mpower(chartInstance, c4_y3) * c4_z3 * c4_z4) - 2.0 * c4_x3 *
    c4_x4 * c4_mpower(chartInstance, c4_y4) * c4_z3 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_y1 * c4_y2 * c4_z1 * c4_z2) - 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_y1 * c4_y2 * c4_z1 * c4_z2) - 2.0 * c4_x1 *
    c4_x2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z3)) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_y1 * c4_y3 * c4_z1 * c4_z3) - 2.0 * c4_x1 *
    c4_x2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_x1 *
    c4_x3 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 * c4_x2 *
    c4_x3 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z3) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_y1 * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x3) * c4_y1 * c4_y3 * c4_z1 * c4_z3) - 2.0 * c4_x1 *
    c4_x3 * c4_z1 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_x1 *
    c4_x4 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_x1 *
    c4_x4 * c4_z1 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_x2 *
    c4_x4 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x3) * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_x2 *
    c4_x3 * c4_z2 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x4) * c4_y1 * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_x2 *
    c4_x4 * c4_z2 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_x3 *
    c4_x4 * c4_mpower(chartInstance, c4_z1) * c4_z3 * c4_z4) - 2.0 * c4_x3 *
    c4_x4 * c4_mpower(chartInstance, c4_z2) * c4_z3 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x4) * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x3) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x4) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_y1 *
    c4_y2 * c4_mpower(chartInstance, c4_y3) * c4_z1 * c4_z2) - 2.0 * c4_y1 *
    c4_y2 * c4_mpower(chartInstance, c4_y4) * c4_z1 * c4_z2) - 2.0 * c4_y1 *
    c4_mpower(chartInstance, c4_y2) * c4_y3 * c4_z1 * c4_z3) - 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_y1 *
    c4_y3 * c4_mpower(chartInstance, c4_y4) * c4_z1 * c4_z3) - 2.0 * c4_y1 *
    c4_mpower(chartInstance, c4_y2) * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_y1 *
    c4_mpower(chartInstance, c4_y3) * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 2.0 * c4_y2 *
    c4_y3 * c4_mpower(chartInstance, c4_y4) * c4_z2 * c4_z3) - 2.0 * c4_y2 *
    c4_mpower(chartInstance, c4_y3) * c4_y4 * c4_z2 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_y2) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_y1 *
    c4_y2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z3)) - 2.0 * c4_y1 *
    c4_y2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_y1 *
    c4_y3 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 * c4_y2 *
    c4_y3 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z3) - 2.0 * c4_y1 *
    c4_y3 * c4_z1 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_y1 *
    c4_y4 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z4) - 2.0 * c4_y1 *
    c4_y4 * c4_z1 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_y2 *
    c4_y4 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z4) - 2.0 * c4_y2 *
    c4_y3 * c4_z2 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_y2 *
    c4_y4 * c4_z2 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_y3 *
    c4_y4 * c4_mpower(chartInstance, c4_z1) * c4_z3 * c4_z4) - 2.0 * c4_y3 *
    c4_y4 * c4_mpower(chartInstance, c4_z2) * c4_z3 * c4_z4) - 2.0 * c4_x1 *
    c4_x2 * c4_y1 * c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_x1 * c4_x2 * c4_y2 * c4_y3
    * c4_z1 * c4_z3) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y2 * c4_z2 * c4_z3) -
    2.0 * c4_x1 * c4_x3 * c4_y2 * c4_y3 * c4_z1 * c4_z2) - 2.0 * c4_x2 * c4_x3 *
    c4_y1 * c4_y2 * c4_z1 * c4_z3) - 2.0 * c4_x2 * c4_x3 * c4_y1 * c4_y3 * c4_z1
                       * c4_z2) - 2.0 * c4_x1 * c4_x2 * c4_y1 * c4_y4 * c4_z2 *
                      c4_z4) - 2.0 * c4_x1 * c4_x2 * c4_y2 * c4_y4 * c4_z1 *
                     c4_z4) - 2.0 * c4_x1 * c4_x4 * c4_y1 * c4_y2 * c4_z2 *
                    c4_z4) - 2.0 * c4_x1 * c4_x4 * c4_y2 * c4_y4 * c4_z1 * c4_z2)
                  - 2.0 * c4_x2 * c4_x4 * c4_y1 * c4_y2 * c4_z1 * c4_z4) - 2.0 *
                 c4_x2 * c4_x4 * c4_y1 * c4_y4 * c4_z1 * c4_z2) - 2.0 * c4_x1 *
                c4_x3 * c4_y1 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x3 *
               c4_y3 * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_x1 * c4_x4 * c4_y1 *
              c4_y3 * c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x4 * c4_y3 * c4_y4 *
             c4_z1 * c4_z3) - 2.0 * c4_x3 * c4_x4 * c4_y1 * c4_y3 * c4_z1 *
            c4_z4) - 2.0 * c4_x3 * c4_x4 * c4_y1 * c4_y4 * c4_z1 * c4_z3) - 2.0 *
          c4_x2 * c4_x3 * c4_y2 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_x2 * c4_x3 *
         c4_y3 * c4_y4 * c4_z2 * c4_z4) - 2.0 * c4_x2 * c4_x4 * c4_y2 * c4_y3 *
        c4_z3 * c4_z4) - 2.0 * c4_x2 * c4_x4 * c4_y3 * c4_y4 * c4_z2 * c4_z3) -
      2.0 * c4_x3 * c4_x4 * c4_y2 * c4_y3 * c4_z2 * c4_z4) - 2.0 * c4_x3 * c4_x4
     * c4_y2 * c4_y4 * c4_z2 * c4_z3) + 64.0;
  c4_m_x = c4_c_A;
  c4_i_y = c4_c_B;
  c4_n_x = c4_m_x;
  c4_j_y = c4_i_y;
  c4_o_x = c4_n_x;
  c4_k_y = c4_j_y;
  c4_l_y = c4_o_x / c4_k_y;
  c4_d_A = 4.0 * (((((((((((((((((((((((((((((((((((((((((((((((((((4.0 * c4_x1 *
    c4_y1 + 4.0 * c4_x2 * c4_y2) + 4.0 * c4_x3 * c4_y3) + 4.0 * c4_x4 * c4_y4) +
    c4_x1 * c4_c_mpower(chartInstance, c4_y1)) + c4_c_mpower(chartInstance,
    c4_x1) * c4_y1) + c4_x2 * c4_c_mpower(chartInstance, c4_y2)) + c4_c_mpower
    (chartInstance, c4_x2) * c4_y2) + c4_x3 * c4_c_mpower(chartInstance, c4_y3))
    + c4_c_mpower(chartInstance, c4_x3) * c4_y3) + c4_x4 * c4_c_mpower
    (chartInstance, c4_y4)) + c4_c_mpower(chartInstance, c4_x4) * c4_y4) + c4_x1
    * c4_mpower(chartInstance, c4_x2) * c4_y1) + c4_x1 * c4_mpower(chartInstance,
    c4_x3) * c4_y1) + c4_mpower(chartInstance, c4_x1) * c4_x2 * c4_y2) + c4_x1 *
    c4_mpower(chartInstance, c4_x4) * c4_y1) + c4_x2 * c4_mpower(chartInstance,
    c4_x3) * c4_y2) + c4_mpower(chartInstance, c4_x1) * c4_x3 * c4_y3) + c4_x2 *
    c4_mpower(chartInstance, c4_x4) * c4_y2) + c4_mpower(chartInstance, c4_x2) *
    c4_x3 * c4_y3) + c4_mpower(chartInstance, c4_x1) * c4_x4 * c4_y4) + c4_x3 *
    c4_mpower(chartInstance, c4_x4) * c4_y3) + c4_mpower(chartInstance, c4_x2) *
    c4_x4 * c4_y4) + c4_mpower(chartInstance, c4_x3) * c4_x4 * c4_y4) + c4_x1 *
    c4_y1 * c4_mpower(chartInstance, c4_y2)) + c4_x1 * c4_y1 * c4_mpower
    (chartInstance, c4_y3)) + c4_x2 * c4_mpower(chartInstance, c4_y1) * c4_y2) +
    c4_x1 * c4_y1 * c4_mpower(chartInstance, c4_y4)) + c4_x2 * c4_y2 * c4_mpower
    (chartInstance, c4_y3)) + c4_x3 * c4_mpower(chartInstance, c4_y1) * c4_y3) +
    c4_x2 * c4_y2 * c4_mpower(chartInstance, c4_y4)) + c4_x3 * c4_mpower
    (chartInstance, c4_y2) * c4_y3) + c4_x4 * c4_mpower(chartInstance, c4_y1) *
    c4_y4) + c4_x3 * c4_y3 * c4_mpower(chartInstance, c4_y4)) + c4_x4 *
    c4_mpower(chartInstance, c4_y2) * c4_y4) + c4_x4 * c4_mpower(chartInstance,
    c4_y3) * c4_y4) + c4_x1 * c4_y1 * c4_mpower(chartInstance, c4_z1)) + c4_x2 *
    c4_y2 * c4_mpower(chartInstance, c4_z2)) + c4_x3 * c4_y3 * c4_mpower
    (chartInstance, c4_z3)) + c4_x4 * c4_y4 * c4_mpower(chartInstance, c4_z4)) +
    c4_x1 * c4_y2 * c4_z1 * c4_z2) + c4_x2 * c4_y1 * c4_z1 * c4_z2) + c4_x1 *
    c4_y3 * c4_z1 * c4_z3) + c4_x3 * c4_y1 * c4_z1 * c4_z3) + c4_x1 * c4_y4 *
    c4_z1 * c4_z4) + c4_x2 * c4_y3 * c4_z2 * c4_z3) + c4_x3 * c4_y2 * c4_z2 *
                       c4_z3) + c4_x4 * c4_y1 * c4_z1 * c4_z4) + c4_x2 * c4_y4 *
                     c4_z2 * c4_z4) + c4_x4 * c4_y2 * c4_z2 * c4_z4) + c4_x3 *
                   c4_y4 * c4_z3 * c4_z4) + c4_x4 * c4_y3 * c4_z3 * c4_z4);
  c4_d60 = 2.0 * c4_x2;
  c4_d61 = 2.0 * c4_x1 * c4_mpower(chartInstance, c4_x3);
  c4_d62 = 2.0 * c4_x2 * c4_x3 * c4_y2;
  c4_d63 = 2.0 * c4_x1 * c4_mpower(chartInstance, c4_x2) * c4_x4 * c4_z1;
  c4_d64 = 2.0 * c4_x1 * c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_z1 * c4_z3;
  c4_d65 = 2.0 * c4_x1;
  c4_d66 = 2.0 * c4_c_mpower(chartInstance, c4_x1) * c4_x3;
  c4_d67 = 2.0 * c4_x1 * c4_c_mpower(chartInstance, c4_x3) * c4_y1;
  c4_d68 = 2.0 * c4_x1 * c4_x3 * c4_c_mpower(chartInstance, c4_y1) * c4_y3;
  c4_d69 = 2.0 * c4_mpower(chartInstance, c4_x3);
  c4_d70 = 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y4);
  c4_d71 = 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z3);
  c4_d72 = c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1);
  c4_d73 = c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z1);
  c4_d74 = c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_z3);
  c4_d75 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x2) + 8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x3)) + 8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x4)) + 8.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_x3)) + 8.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_x4)) + 8.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
    c4_x4)) + 8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_y1)) + 12.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_y2)) + 12.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y1)) + 12.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_y3)) + 8.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y2)) + 12.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
    c4_y1)) + c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_y2))
    + 12.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y4))
    + c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_y1)) +
    12.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_y3)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_y1)) + 8.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y3)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2)) +
    c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_y2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_y1)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2)) +
    c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) +
    c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_y2)) + 8.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3)) + 8.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z1)) + 12.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2)) + 12.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z3)) + 8.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_z1)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z3)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z2)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4)) + 8.0 *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_z3)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z4)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z3)) + 12.0 *
                       c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_z2)) + c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1))
                     + 8.0 * c4_mpower(chartInstance, c4_y2) * c4_mpower
                     (chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x1) *
                    c4_b_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance,
    c4_x2) * c4_b_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance,
    c4_x1) * c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x3) *
                 c4_b_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower
                (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z4)) +
               c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_z3)) + c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_z1))
             + 12.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
              c4_z3)) + c4_b_mpower(chartInstance, c4_x3) * c4_mpower
            (chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_x4) *
           c4_mpower(chartInstance, c4_z1)) + 8.0 * c4_mpower(chartInstance,
           c4_y3) * c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance,
          c4_x2) * c4_b_mpower(chartInstance, c4_z4)) + c4_b_mpower
        (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
       (chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_z2)) + 8.0 *
      c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) +
     c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_z4);
  c4_d76 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d75 + c4_d74) + c4_b_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y1) *
    c4_b_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) *
    c4_b_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y1) *
    c4_b_mpower(chartInstance, c4_z3)) + 12.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y3) *
    c4_b_mpower(chartInstance, c4_z1)) + 8.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 12.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y1) *
    c4_b_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) *
    c4_b_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y3) *
    c4_b_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y4) *
    c4_b_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y2) *
    c4_b_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) *
    c4_b_mpower(chartInstance, c4_z2)) + 8.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y3) *
    c4_b_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) *
    c4_b_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + 8.0 * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + 8.0 * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z4)) + 8.0 * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + 32.0 * c4_mpower(chartInstance, c4_x1)) +
    32.0 * c4_mpower(chartInstance, c4_x2)) + 4.0 * c4_b_mpower(chartInstance,
    c4_x1)) + 32.0 * c4_mpower(chartInstance, c4_x3)) + 4.0 * c4_b_mpower
    (chartInstance, c4_x2)) + 32.0 * c4_mpower(chartInstance, c4_x4)) + 4.0 *
    c4_b_mpower(chartInstance, c4_x3)) + 4.0 * c4_b_mpower(chartInstance, c4_x4))
    + 32.0 * c4_mpower(chartInstance, c4_y1)) + 32.0 * c4_mpower(chartInstance,
    c4_y2)) + 4.0 * c4_b_mpower(chartInstance, c4_y1)) + 32.0 * c4_mpower
    (chartInstance, c4_y3)) + 4.0 * c4_b_mpower(chartInstance, c4_y2)) + 32.0 *
    c4_mpower(chartInstance, c4_y4)) + 4.0 * c4_b_mpower(chartInstance, c4_y3))
    + 4.0 * c4_b_mpower(chartInstance, c4_y4)) + 32.0 * c4_mpower(chartInstance,
    c4_z1)) + 32.0 * c4_mpower(chartInstance, c4_z2)) + 4.0 * c4_b_mpower
    (chartInstance, c4_z1)) + 32.0 * c4_mpower(chartInstance, c4_z3)) + 4.0 *
    c4_b_mpower(chartInstance, c4_z2)) + 32.0 * c4_mpower(chartInstance, c4_z4))
    + 4.0 * c4_b_mpower(chartInstance, c4_z3)) + 4.0 * c4_b_mpower(chartInstance,
    c4_z4)) + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
                       c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y4)) + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
                      c4_mpower(chartInstance, c4_y3)) + 2.0 * c4_mpower
                     (chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x4) *
                     c4_mpower(chartInstance, c4_y2)) + c4_mpower(chartInstance,
    c4_x2) * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2))
                   + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower
                   (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) +
                  2.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower
                  (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4)) +
                 2.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x4) * c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x2) *
                c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y3))
               + c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_x4) * c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance,
    c4_x3) * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1))
             + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x4)
             * c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance,
             c4_x2) * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
             c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower
           (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
          c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_x4) *
          c4_mpower(chartInstance, c4_y2)) + c4_mpower(chartInstance, c4_x2) *
         c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4)) +
        c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_x4) *
        c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x3) *
       c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4)) +
      c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x2) *
      c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_x1) *
     c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_z2);
  c4_d77 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d76 + c4_d73) + c4_d72 * c4_mpower(chartInstance,
    c4_y3)) + c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
                       c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
    c4_y1) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance,
    c4_x3) * c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3))
                     + 2.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower
                     (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z2)) +
                    2.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower
                    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) +
                   2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
                   (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z3)) +
                  2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
                  (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) +
                 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance,
    c4_x1) * c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z4))
               + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance,
    c4_x2) * c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3))
             + 2.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
              c4_y2) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
            (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4) * c4_mpower
            (chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
           c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z4)) +
          2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2)
          * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance,
          c4_x4) * c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance,
          c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
        (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
       c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y4) *
       c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
      c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
     c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4) *
     c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4);
  c4_d78 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d77 + c4_d71) + c4_d70 * c4_mpower(chartInstance,
    c4_z2)) + c4_d69 * c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance,
    c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance,
    c4_x4) * c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3))
    + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z1)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) - 8.0 *
    c4_x1 * c4_x2 * c4_y1 * c4_y2) - 8.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3) - 8.0 *
    c4_x1 * c4_x4 * c4_y1 * c4_y4) - 8.0 * c4_x2 * c4_x3 * c4_y2 * c4_y3) - 8.0 *
                      c4_x2 * c4_x4 * c4_y2 * c4_y4) - 8.0 * c4_x3 * c4_x4 *
                     c4_y3 * c4_y4) - 8.0 * c4_x1 * c4_x2 * c4_z1 * c4_z2) - 8.0
                   * c4_x1 * c4_x3 * c4_z1 * c4_z3) - 8.0 * c4_x1 * c4_x4 *
                  c4_z1 * c4_z4) - 8.0 * c4_x2 * c4_x3 * c4_z2 * c4_z3) - 8.0 *
                c4_x2 * c4_x4 * c4_z2 * c4_z4) - 8.0 * c4_x3 * c4_x4 * c4_z3 *
               c4_z4) - 8.0 * c4_y1 * c4_y2 * c4_z1 * c4_z2) - 8.0 * c4_y1 *
             c4_y3 * c4_z1 * c4_z3) - 8.0 * c4_y1 * c4_y4 * c4_z1 * c4_z4) - 8.0
           * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 8.0 * c4_y2 * c4_y4 * c4_z2 *
          c4_z4) - 8.0 * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x2 *
        c4_y1 * c4_c_mpower(chartInstance, c4_y2)) - 2.0 * c4_x1 * c4_x2 *
       c4_c_mpower(chartInstance, c4_y1) * c4_y2) - 2.0 * c4_x1 * c4_c_mpower
      (chartInstance, c4_x2) * c4_y1 * c4_y2) - 2.0 * c4_c_mpower(chartInstance,
      c4_x1) * c4_x2 * c4_y1 * c4_y2) - 2.0 * c4_x1 * c4_x3 * c4_y1 *
    c4_c_mpower(chartInstance, c4_y3);
  c4_d79 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d78 - c4_d68) - c4_d67 * c4_y3) - c4_d66 * c4_y1 *
    c4_y3) - c4_d65 * c4_x4 * c4_y1 * c4_c_mpower(chartInstance, c4_y4)) - 2.0 *
    c4_x1 * c4_x4 * c4_c_mpower(chartInstance, c4_y1) * c4_y4) - 2.0 * c4_x1 *
    c4_c_mpower(chartInstance, c4_x4) * c4_y1 * c4_y4) - 2.0 * c4_x2 * c4_x3 *
    c4_y2 * c4_c_mpower(chartInstance, c4_y3)) - 2.0 * c4_x2 * c4_x3 *
    c4_c_mpower(chartInstance, c4_y2) * c4_y3) - 2.0 * c4_x2 * c4_c_mpower
    (chartInstance, c4_x3) * c4_y2 * c4_y3) - 2.0 * c4_c_mpower(chartInstance,
    c4_x1) * c4_x4 * c4_y1 * c4_y4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) *
    c4_x3 * c4_y2 * c4_y3) - 2.0 * c4_x2 * c4_x4 * c4_y2 * c4_c_mpower
    (chartInstance, c4_y4)) - 2.0 * c4_x2 * c4_x4 * c4_c_mpower(chartInstance,
    c4_y2) * c4_y4) - 2.0 * c4_x2 * c4_c_mpower(chartInstance, c4_x4) * c4_y2 *
    c4_y4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) * c4_x4 * c4_y2 * c4_y4) -
    2.0 * c4_x3 * c4_x4 * c4_y3 * c4_c_mpower(chartInstance, c4_y4)) - 2.0 *
    c4_x3 * c4_x4 * c4_c_mpower(chartInstance, c4_y3) * c4_y4) - 2.0 * c4_x3 *
    c4_c_mpower(chartInstance, c4_x4) * c4_y3 * c4_y4) - 2.0 * c4_c_mpower
    (chartInstance, c4_x3) * c4_x4 * c4_y3 * c4_y4) - 2.0 * c4_x1 * c4_x2 *
    c4_z1 * c4_c_mpower(chartInstance, c4_z2)) - 2.0 * c4_x1 * c4_x2 *
    c4_c_mpower(chartInstance, c4_z1) * c4_z2) - 2.0 * c4_x1 * c4_c_mpower
    (chartInstance, c4_x2) * c4_z1 * c4_z2) - 2.0 * c4_c_mpower(chartInstance,
    c4_x1) * c4_x2 * c4_z1 * c4_z2) - 2.0 * c4_x1 * c4_x3 * c4_z1 * c4_c_mpower
    (chartInstance, c4_z3)) - 2.0 * c4_x1 * c4_x3 * c4_c_mpower(chartInstance,
    c4_z1) * c4_z3) - 2.0 * c4_x1 * c4_c_mpower(chartInstance, c4_x3) * c4_z1 *
    c4_z3) - 2.0 * c4_c_mpower(chartInstance, c4_x1) * c4_x3 * c4_z1 * c4_z3) -
    2.0 * c4_x1 * c4_x4 * c4_z1 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x1 * c4_x4 * c4_c_mpower(chartInstance, c4_z1) * c4_z4) - 2.0 * c4_x1 *
    c4_c_mpower(chartInstance, c4_x4) * c4_z1 * c4_z4) - 2.0 * c4_x2 * c4_x3 *
    c4_z2 * c4_c_mpower(chartInstance, c4_z3)) - 2.0 * c4_x2 * c4_x3 *
    c4_c_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 * c4_x2 * c4_c_mpower
    (chartInstance, c4_x3) * c4_z2 * c4_z3) - 2.0 * c4_c_mpower(chartInstance,
    c4_x1) * c4_x4 * c4_z1 * c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) *
    c4_x3 * c4_z2 * c4_z3) - 2.0 * c4_x2 * c4_x4 * c4_z2 * c4_c_mpower
    (chartInstance, c4_z4)) - 2.0 * c4_x2 * c4_x4 * c4_c_mpower(chartInstance,
    c4_z2) * c4_z4) - 2.0 * c4_x2 * c4_c_mpower(chartInstance, c4_x4) * c4_z2 *
    c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) * c4_x4 * c4_z2 * c4_z4) -
    2.0 * c4_x3 * c4_x4 * c4_z3 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x3 * c4_x4 * c4_c_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_x3 *
    c4_c_mpower(chartInstance, c4_x4) * c4_z3 * c4_z4) - 2.0 * c4_c_mpower
    (chartInstance, c4_x3) * c4_x4 * c4_z3 * c4_z4) - 2.0 * c4_y1 * c4_y2 *
    c4_z1 * c4_c_mpower(chartInstance, c4_z2)) - 2.0 * c4_y1 * c4_y2 *
    c4_c_mpower(chartInstance, c4_z1) * c4_z2) - 2.0 * c4_y1 * c4_c_mpower
    (chartInstance, c4_y2) * c4_z1 * c4_z2) - 2.0 * c4_c_mpower(chartInstance,
    c4_y1) * c4_y2 * c4_z1 * c4_z2) - 2.0 * c4_y1 * c4_y3 * c4_z1 * c4_c_mpower
    (chartInstance, c4_z3)) - 2.0 * c4_y1 * c4_y3 * c4_c_mpower(chartInstance,
    c4_z1) * c4_z3) - 2.0 * c4_y1 * c4_c_mpower(chartInstance, c4_y3) * c4_z1 *
    c4_z3) - 2.0 * c4_c_mpower(chartInstance, c4_y1) * c4_y3 * c4_z1 * c4_z3) -
    2.0 * c4_y1 * c4_y4 * c4_z1 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_y1 * c4_y4 * c4_c_mpower(chartInstance, c4_z1) * c4_z4) - 2.0 * c4_y1 *
    c4_c_mpower(chartInstance, c4_y4) * c4_z1 * c4_z4) - 2.0 * c4_y2 * c4_y3 *
    c4_z2 * c4_c_mpower(chartInstance, c4_z3)) - 2.0 * c4_y2 * c4_y3 *
    c4_c_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 * c4_y2 * c4_c_mpower
    (chartInstance, c4_y3) * c4_z2 * c4_z3) - 2.0 * c4_c_mpower(chartInstance,
    c4_y1) * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_y2) *
    c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_y2 * c4_y4 * c4_z2 * c4_c_mpower
    (chartInstance, c4_z4)) - 2.0 * c4_y2 * c4_y4 * c4_c_mpower(chartInstance,
    c4_z2) * c4_z4) - 2.0 * c4_y2 * c4_c_mpower(chartInstance, c4_y4) * c4_z2 *
    c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_y2) * c4_y4 * c4_z2 * c4_z4) -
    2.0 * c4_y3 * c4_y4 * c4_z3 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_y3 * c4_y4 * c4_c_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_y3 *
    c4_c_mpower(chartInstance, c4_y4) * c4_z3 * c4_z4) - 2.0 * c4_c_mpower
    (chartInstance, c4_y3) * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x2 *
    c4_mpower(chartInstance, c4_x3) * c4_y1 * c4_y2) - 2.0 * c4_x1 * c4_x2 *
    c4_mpower(chartInstance, c4_x4) * c4_y1 * c4_y2) - 2.0 * c4_x1 * c4_mpower
    (chartInstance, c4_x2) * c4_x3 * c4_y1 * c4_y3) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x2 * c4_x3 * c4_y2 * c4_y3) - 2.0 * c4_x1 *
    c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_y1 * c4_y3) - 2.0 * c4_x1 *
    c4_mpower(chartInstance, c4_x2) * c4_x4 * c4_y1 * c4_y4) - 2.0 * c4_x1 *
    c4_mpower(chartInstance, c4_x3) * c4_x4 * c4_y1 * c4_y4) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x2 * c4_x4 * c4_y2 * c4_y4) - 2.0 * c4_x2 *
    c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_y2 * c4_y3) - 2.0 * c4_x2 *
    c4_mpower(chartInstance, c4_x3) * c4_x4 * c4_y2 * c4_y4) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x3 * c4_x4 * c4_y3 * c4_y4) - 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_x3 * c4_x4 * c4_y3 * c4_y4) - 2.0 * c4_x1 *
    c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_y3)) - 2.0 * c4_x1 *
                       c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_y4))
                      - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_mpower(chartInstance,
    c4_y2) * c4_y3) - 2.0 * c4_x2 * c4_x3 * c4_mpower(chartInstance, c4_y1) *
                     c4_y2 * c4_y3) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3 *
                    c4_mpower(chartInstance, c4_y4)) - 2.0 * c4_x1 * c4_x4 *
                   c4_y1 * c4_mpower(chartInstance, c4_y2) * c4_y4) - 2.0 *
                  c4_x1 * c4_x4 * c4_y1 * c4_mpower(chartInstance, c4_y3) *
                  c4_y4) - 2.0 * c4_x2 * c4_x4 * c4_mpower(chartInstance, c4_y1)
                 * c4_y2 * c4_y4) - 2.0 * c4_x2 * c4_x3 * c4_y2 * c4_y3 *
                c4_mpower(chartInstance, c4_y4)) - 2.0 * c4_x2 * c4_x4 * c4_y2 *
               c4_mpower(chartInstance, c4_y3) * c4_y4) - 2.0 * c4_x3 * c4_x4 *
              c4_mpower(chartInstance, c4_y1) * c4_y3 * c4_y4) - 2.0 * c4_x3 *
             c4_x4 * c4_mpower(chartInstance, c4_y2) * c4_y3 * c4_y4) - 2.0 *
            c4_x1 * c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_z1)) -
           2.0 * c4_x1 * c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_z2))
          - 2.0 * c4_x1 * c4_x2 * c4_mpower(chartInstance, c4_x3) * c4_z1 *
          c4_z2) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3 * c4_mpower(chartInstance,
          c4_z1)) - 2.0 * c4_x1 * c4_x2 * c4_mpower(chartInstance, c4_x4) *
        c4_z1 * c4_z2) - 2.0 * c4_x1 * c4_mpower(chartInstance, c4_x2) * c4_x3 *
       c4_z1 * c4_z3) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3 * c4_mpower
      (chartInstance, c4_z3)) - 2.0 * c4_x1 * c4_x4 * c4_y1 * c4_y4 * c4_mpower
     (chartInstance, c4_z1)) - 2.0 * c4_mpower(chartInstance, c4_x1) * c4_x2 *
    c4_x3 * c4_z2 * c4_z3;
  c4_d_B =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d79 - c4_d64) - c4_d63 * c4_z4) - c4_d62 * c4_y3 *
    c4_mpower(chartInstance, c4_z2)) - c4_d61 * c4_x4 * c4_z1 * c4_z4) - c4_d60 *
    c4_x3 * c4_y2 * c4_y3 * c4_mpower(chartInstance, c4_z3)) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x2 * c4_x4 * c4_z2 * c4_z4) - 2.0 * c4_x1 *
    c4_x4 * c4_y1 * c4_y4 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_x2 *
    c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_z2 * c4_z3) - 2.0 * c4_x2 *
    c4_x4 * c4_y2 * c4_y4 * c4_mpower(chartInstance, c4_z2)) - 2.0 * c4_x2 *
    c4_mpower(chartInstance, c4_x3) * c4_x4 * c4_z2 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x3 * c4_x4 * c4_z3 * c4_z4) - 2.0 * c4_x2 *
    c4_x4 * c4_y2 * c4_y4 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_x3 * c4_x4 * c4_z3 * c4_z4) - 2.0 * c4_x3 *
    c4_x4 * c4_y3 * c4_y4 * c4_mpower(chartInstance, c4_z3)) - 2.0 * c4_x3 *
    c4_x4 * c4_y3 * c4_y4 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_x1 *
    c4_x2 * c4_mpower(chartInstance, c4_y1) * c4_z1 * c4_z2) - 2.0 * c4_x1 *
    c4_x2 * c4_mpower(chartInstance, c4_y2) * c4_z1 * c4_z2) - 2.0 * c4_x1 *
    c4_x3 * c4_mpower(chartInstance, c4_y1) * c4_z1 * c4_z3) - 2.0 * c4_x1 *
    c4_x3 * c4_mpower(chartInstance, c4_y3) * c4_z1 * c4_z3) - 2.0 * c4_x1 *
    c4_x4 * c4_mpower(chartInstance, c4_y1) * c4_z1 * c4_z4) - 2.0 * c4_x2 *
    c4_x3 * c4_mpower(chartInstance, c4_y2) * c4_z2 * c4_z3) - 2.0 * c4_x2 *
    c4_x3 * c4_mpower(chartInstance, c4_y3) * c4_z2 * c4_z3) - 2.0 * c4_x1 *
    c4_x4 * c4_mpower(chartInstance, c4_y4) * c4_z1 * c4_z4) - 2.0 * c4_x2 *
    c4_x4 * c4_mpower(chartInstance, c4_y2) * c4_z2 * c4_z4) - 2.0 * c4_x2 *
    c4_x4 * c4_mpower(chartInstance, c4_y4) * c4_z2 * c4_z4) - 2.0 * c4_x3 *
    c4_x4 * c4_mpower(chartInstance, c4_y3) * c4_z3 * c4_z4) - 2.0 * c4_x3 *
    c4_x4 * c4_mpower(chartInstance, c4_y4) * c4_z3 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_y1 * c4_y2 * c4_z1 * c4_z2) - 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_y1 * c4_y2 * c4_z1 * c4_z2) - 2.0 * c4_x1 *
    c4_x2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z3)) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_y1 * c4_y3 * c4_z1 * c4_z3) - 2.0 * c4_x1 *
    c4_x2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_x1 *
    c4_x3 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 * c4_x2 *
    c4_x3 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z3) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_y1 * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x3) * c4_y1 * c4_y3 * c4_z1 * c4_z3) - 2.0 * c4_x1 *
    c4_x3 * c4_z1 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_x1 *
    c4_x4 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_x1 *
    c4_x4 * c4_z1 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_x2 *
    c4_x4 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x3) * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_x2 *
    c4_x3 * c4_z2 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x4) * c4_y1 * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_x2 *
    c4_x4 * c4_z2 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_x3 *
    c4_x4 * c4_mpower(chartInstance, c4_z1) * c4_z3 * c4_z4) - 2.0 * c4_x3 *
    c4_x4 * c4_mpower(chartInstance, c4_z2) * c4_z3 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x4) * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x3) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x4) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_y1 *
    c4_y2 * c4_mpower(chartInstance, c4_y3) * c4_z1 * c4_z2) - 2.0 * c4_y1 *
    c4_y2 * c4_mpower(chartInstance, c4_y4) * c4_z1 * c4_z2) - 2.0 * c4_y1 *
    c4_mpower(chartInstance, c4_y2) * c4_y3 * c4_z1 * c4_z3) - 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_y1 *
    c4_y3 * c4_mpower(chartInstance, c4_y4) * c4_z1 * c4_z3) - 2.0 * c4_y1 *
    c4_mpower(chartInstance, c4_y2) * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_y1 *
    c4_mpower(chartInstance, c4_y3) * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 2.0 * c4_y2 *
    c4_y3 * c4_mpower(chartInstance, c4_y4) * c4_z2 * c4_z3) - 2.0 * c4_y2 *
    c4_mpower(chartInstance, c4_y3) * c4_y4 * c4_z2 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_y2) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_y1 *
    c4_y2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z3)) - 2.0 * c4_y1 *
    c4_y2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_y1 *
    c4_y3 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 * c4_y2 *
    c4_y3 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z3) - 2.0 * c4_y1 *
    c4_y3 * c4_z1 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_y1 *
    c4_y4 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z4) - 2.0 * c4_y1 *
    c4_y4 * c4_z1 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_y2 *
    c4_y4 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z4) - 2.0 * c4_y2 *
    c4_y3 * c4_z2 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_y2 *
    c4_y4 * c4_z2 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_y3 *
    c4_y4 * c4_mpower(chartInstance, c4_z1) * c4_z3 * c4_z4) - 2.0 * c4_y3 *
    c4_y4 * c4_mpower(chartInstance, c4_z2) * c4_z3 * c4_z4) - 2.0 * c4_x1 *
    c4_x2 * c4_y1 * c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_x1 * c4_x2 * c4_y2 * c4_y3
    * c4_z1 * c4_z3) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y2 * c4_z2 * c4_z3) -
    2.0 * c4_x1 * c4_x3 * c4_y2 * c4_y3 * c4_z1 * c4_z2) - 2.0 * c4_x2 * c4_x3 *
    c4_y1 * c4_y2 * c4_z1 * c4_z3) - 2.0 * c4_x2 * c4_x3 * c4_y1 * c4_y3 * c4_z1
                       * c4_z2) - 2.0 * c4_x1 * c4_x2 * c4_y1 * c4_y4 * c4_z2 *
                      c4_z4) - 2.0 * c4_x1 * c4_x2 * c4_y2 * c4_y4 * c4_z1 *
                     c4_z4) - 2.0 * c4_x1 * c4_x4 * c4_y1 * c4_y2 * c4_z2 *
                    c4_z4) - 2.0 * c4_x1 * c4_x4 * c4_y2 * c4_y4 * c4_z1 * c4_z2)
                  - 2.0 * c4_x2 * c4_x4 * c4_y1 * c4_y2 * c4_z1 * c4_z4) - 2.0 *
                 c4_x2 * c4_x4 * c4_y1 * c4_y4 * c4_z1 * c4_z2) - 2.0 * c4_x1 *
                c4_x3 * c4_y1 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x3 *
               c4_y3 * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_x1 * c4_x4 * c4_y1 *
              c4_y3 * c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x4 * c4_y3 * c4_y4 *
             c4_z1 * c4_z3) - 2.0 * c4_x3 * c4_x4 * c4_y1 * c4_y3 * c4_z1 *
            c4_z4) - 2.0 * c4_x3 * c4_x4 * c4_y1 * c4_y4 * c4_z1 * c4_z3) - 2.0 *
          c4_x2 * c4_x3 * c4_y2 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_x2 * c4_x3 *
         c4_y3 * c4_y4 * c4_z2 * c4_z4) - 2.0 * c4_x2 * c4_x4 * c4_y2 * c4_y3 *
        c4_z3 * c4_z4) - 2.0 * c4_x2 * c4_x4 * c4_y3 * c4_y4 * c4_z2 * c4_z3) -
      2.0 * c4_x3 * c4_x4 * c4_y2 * c4_y3 * c4_z2 * c4_z4) - 2.0 * c4_x3 * c4_x4
     * c4_y2 * c4_y4 * c4_z2 * c4_z3) + 64.0;
  c4_p_x = c4_d_A;
  c4_m_y = c4_d_B;
  c4_q_x = c4_p_x;
  c4_n_y = c4_m_y;
  c4_r_x = c4_q_x;
  c4_o_y = c4_n_y;
  c4_p_y = c4_r_x / c4_o_y;
  c4_e_A = 4.0 *
    ((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((c4_mpower
    (chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1) + c4_mpower
    (chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y2)) + c4_mpower
    (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1)) + c4_mpower
    (chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3)) + c4_mpower
    (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2)) + c4_mpower
    (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1)) + c4_mpower
    (chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y4)) + c4_mpower
    (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3)) + c4_mpower
    (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2)) + c4_mpower
    (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) + c4_mpower
    (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y4)) + c4_mpower
    (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y3)) + c4_mpower
    (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2)) + c4_mpower
    (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4)) + c4_mpower
    (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3)) + c4_mpower
    (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4)) + c4_mpower
    (chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z2)) + c4_mpower
    (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2)) + c4_mpower
    (chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z3)) + c4_mpower
    (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3)) + c4_mpower
    (chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z3)) + c4_mpower
    (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z2)) + c4_mpower
    (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3)) + c4_mpower
    (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y4)) + c4_mpower
    (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4)) + c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1)) + c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2)) + c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z1)) + c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z3)) + c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) + c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1)) + c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3)) + c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z2)) + c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z3)) + c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) + c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3)) + c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z4)) + 4.0 * c4_mpower
    (chartInstance, c4_x1)) + 4.0 * c4_mpower(chartInstance, c4_x2)) + 4.0 *
    c4_mpower(chartInstance, c4_x3)) + 4.0 * c4_mpower(chartInstance, c4_x4)) +
                       8.0 * c4_mpower(chartInstance, c4_y1)) + 8.0 * c4_mpower
                      (chartInstance, c4_y2)) + c4_b_mpower(chartInstance, c4_y1))
                    + 8.0 * c4_mpower(chartInstance, c4_y3)) + c4_b_mpower
                   (chartInstance, c4_y2)) + 8.0 * c4_mpower(chartInstance,
    c4_y4)) + c4_b_mpower(chartInstance, c4_y3)) + c4_b_mpower(chartInstance,
    c4_y4)) + 4.0 * c4_mpower(chartInstance, c4_z1)) + 4.0 * c4_mpower
              (chartInstance, c4_z2)) + 4.0 * c4_mpower(chartInstance, c4_z3)) +
            4.0 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_x1 * c4_x2 * c4_z1
           * c4_z2) - 2.0 * c4_x1 * c4_x3 * c4_z1 * c4_z3) - 2.0 * c4_x1 * c4_x4
         * c4_z1 * c4_z4) - 2.0 * c4_x2 * c4_x3 * c4_z2 * c4_z3) - 2.0 * c4_x2 *
       c4_x4 * c4_z2 * c4_z4) - 2.0 * c4_x3 * c4_x4 * c4_z3 * c4_z4) + 16.0);
  c4_d80 = 2.0 * c4_x2;
  c4_d81 = 2.0 * c4_x1 * c4_mpower(chartInstance, c4_x3);
  c4_d82 = 2.0 * c4_x2 * c4_x3 * c4_y2;
  c4_d83 = 2.0 * c4_x1 * c4_mpower(chartInstance, c4_x2) * c4_x4 * c4_z1;
  c4_d84 = 2.0 * c4_x1 * c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_z1 * c4_z3;
  c4_d85 = 2.0 * c4_x1;
  c4_d86 = 2.0 * c4_c_mpower(chartInstance, c4_x1) * c4_x3;
  c4_d87 = 2.0 * c4_x1 * c4_c_mpower(chartInstance, c4_x3) * c4_y1;
  c4_d88 = 2.0 * c4_x1 * c4_x3 * c4_c_mpower(chartInstance, c4_y1) * c4_y3;
  c4_d89 = 2.0 * c4_mpower(chartInstance, c4_x3);
  c4_d90 = 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y4);
  c4_d91 = 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z3);
  c4_d92 = c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1);
  c4_d93 = c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z1);
  c4_d94 = c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_z3);
  c4_d95 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x2) + 8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x3)) + 8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x4)) + 8.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_x3)) + 8.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_x4)) + 8.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
    c4_x4)) + 8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_y1)) + 12.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_y2)) + 12.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y1)) + 12.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_y3)) + 8.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y2)) + 12.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
    c4_y1)) + c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_y2))
    + 12.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y4))
    + c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_y1)) +
    12.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_y3)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_y1)) + 8.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y3)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2)) +
    c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_y2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_y1)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2)) +
    c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) +
    c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_y2)) + 8.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3)) + 8.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z1)) + 12.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2)) + 12.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z3)) + 8.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_z1)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z3)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z2)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4)) + 8.0 *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_z3)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z4)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z3)) + 12.0 *
                       c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_z2)) + c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1))
                     + 8.0 * c4_mpower(chartInstance, c4_y2) * c4_mpower
                     (chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x1) *
                    c4_b_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance,
    c4_x2) * c4_b_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance,
    c4_x1) * c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x3) *
                 c4_b_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower
                (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z4)) +
               c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_z3)) + c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_z1))
             + 12.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
              c4_z3)) + c4_b_mpower(chartInstance, c4_x3) * c4_mpower
            (chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_x4) *
           c4_mpower(chartInstance, c4_z1)) + 8.0 * c4_mpower(chartInstance,
           c4_y3) * c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance,
          c4_x2) * c4_b_mpower(chartInstance, c4_z4)) + c4_b_mpower
        (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
       (chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_z2)) + 8.0 *
      c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) +
     c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_z4);
  c4_d96 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d95 + c4_d94) + c4_b_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y1) *
    c4_b_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) *
    c4_b_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y1) *
    c4_b_mpower(chartInstance, c4_z3)) + 12.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y3) *
    c4_b_mpower(chartInstance, c4_z1)) + 8.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 12.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y1) *
    c4_b_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) *
    c4_b_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y3) *
    c4_b_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y4) *
    c4_b_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y2) *
    c4_b_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) *
    c4_b_mpower(chartInstance, c4_z2)) + 8.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y3) *
    c4_b_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) *
    c4_b_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + 8.0 * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + 8.0 * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z4)) + 8.0 * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + 32.0 * c4_mpower(chartInstance, c4_x1)) +
    32.0 * c4_mpower(chartInstance, c4_x2)) + 4.0 * c4_b_mpower(chartInstance,
    c4_x1)) + 32.0 * c4_mpower(chartInstance, c4_x3)) + 4.0 * c4_b_mpower
    (chartInstance, c4_x2)) + 32.0 * c4_mpower(chartInstance, c4_x4)) + 4.0 *
    c4_b_mpower(chartInstance, c4_x3)) + 4.0 * c4_b_mpower(chartInstance, c4_x4))
    + 32.0 * c4_mpower(chartInstance, c4_y1)) + 32.0 * c4_mpower(chartInstance,
    c4_y2)) + 4.0 * c4_b_mpower(chartInstance, c4_y1)) + 32.0 * c4_mpower
    (chartInstance, c4_y3)) + 4.0 * c4_b_mpower(chartInstance, c4_y2)) + 32.0 *
    c4_mpower(chartInstance, c4_y4)) + 4.0 * c4_b_mpower(chartInstance, c4_y3))
    + 4.0 * c4_b_mpower(chartInstance, c4_y4)) + 32.0 * c4_mpower(chartInstance,
    c4_z1)) + 32.0 * c4_mpower(chartInstance, c4_z2)) + 4.0 * c4_b_mpower
    (chartInstance, c4_z1)) + 32.0 * c4_mpower(chartInstance, c4_z3)) + 4.0 *
    c4_b_mpower(chartInstance, c4_z2)) + 32.0 * c4_mpower(chartInstance, c4_z4))
    + 4.0 * c4_b_mpower(chartInstance, c4_z3)) + 4.0 * c4_b_mpower(chartInstance,
    c4_z4)) + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
                       c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y4)) + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
                      c4_mpower(chartInstance, c4_y3)) + 2.0 * c4_mpower
                     (chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x4) *
                     c4_mpower(chartInstance, c4_y2)) + c4_mpower(chartInstance,
    c4_x2) * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2))
                   + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower
                   (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) +
                  2.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower
                  (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4)) +
                 2.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x4) * c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x2) *
                c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y3))
               + c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_x4) * c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance,
    c4_x3) * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1))
             + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x4)
             * c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance,
             c4_x2) * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
             c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower
           (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
          c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_x4) *
          c4_mpower(chartInstance, c4_y2)) + c4_mpower(chartInstance, c4_x2) *
         c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4)) +
        c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_x4) *
        c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x3) *
       c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4)) +
      c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x2) *
      c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_x1) *
     c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_z2);
  c4_d97 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d96 + c4_d93) + c4_d92 * c4_mpower(chartInstance,
    c4_y3)) + c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
                       c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
    c4_y1) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance,
    c4_x3) * c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3))
                     + 2.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower
                     (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z2)) +
                    2.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower
                    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) +
                   2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
                   (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z3)) +
                  2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
                  (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) +
                 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance,
    c4_x1) * c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z4))
               + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance,
    c4_x2) * c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3))
             + 2.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
              c4_y2) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
            (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4) * c4_mpower
            (chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
           c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z4)) +
          2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2)
          * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance,
          c4_x4) * c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance,
          c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
        (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
       c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y4) *
       c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
      c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
     c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4) *
     c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4);
  c4_d98 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d97 + c4_d91) + c4_d90 * c4_mpower(chartInstance,
    c4_z2)) + c4_d89 * c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance,
    c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance,
    c4_x4) * c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3))
    + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z1)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) - 8.0 *
    c4_x1 * c4_x2 * c4_y1 * c4_y2) - 8.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3) - 8.0 *
    c4_x1 * c4_x4 * c4_y1 * c4_y4) - 8.0 * c4_x2 * c4_x3 * c4_y2 * c4_y3) - 8.0 *
                      c4_x2 * c4_x4 * c4_y2 * c4_y4) - 8.0 * c4_x3 * c4_x4 *
                     c4_y3 * c4_y4) - 8.0 * c4_x1 * c4_x2 * c4_z1 * c4_z2) - 8.0
                   * c4_x1 * c4_x3 * c4_z1 * c4_z3) - 8.0 * c4_x1 * c4_x4 *
                  c4_z1 * c4_z4) - 8.0 * c4_x2 * c4_x3 * c4_z2 * c4_z3) - 8.0 *
                c4_x2 * c4_x4 * c4_z2 * c4_z4) - 8.0 * c4_x3 * c4_x4 * c4_z3 *
               c4_z4) - 8.0 * c4_y1 * c4_y2 * c4_z1 * c4_z2) - 8.0 * c4_y1 *
             c4_y3 * c4_z1 * c4_z3) - 8.0 * c4_y1 * c4_y4 * c4_z1 * c4_z4) - 8.0
           * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 8.0 * c4_y2 * c4_y4 * c4_z2 *
          c4_z4) - 8.0 * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x2 *
        c4_y1 * c4_c_mpower(chartInstance, c4_y2)) - 2.0 * c4_x1 * c4_x2 *
       c4_c_mpower(chartInstance, c4_y1) * c4_y2) - 2.0 * c4_x1 * c4_c_mpower
      (chartInstance, c4_x2) * c4_y1 * c4_y2) - 2.0 * c4_c_mpower(chartInstance,
      c4_x1) * c4_x2 * c4_y1 * c4_y2) - 2.0 * c4_x1 * c4_x3 * c4_y1 *
    c4_c_mpower(chartInstance, c4_y3);
  c4_d99 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d98 - c4_d88) - c4_d87 * c4_y3) - c4_d86 * c4_y1 *
    c4_y3) - c4_d85 * c4_x4 * c4_y1 * c4_c_mpower(chartInstance, c4_y4)) - 2.0 *
    c4_x1 * c4_x4 * c4_c_mpower(chartInstance, c4_y1) * c4_y4) - 2.0 * c4_x1 *
    c4_c_mpower(chartInstance, c4_x4) * c4_y1 * c4_y4) - 2.0 * c4_x2 * c4_x3 *
    c4_y2 * c4_c_mpower(chartInstance, c4_y3)) - 2.0 * c4_x2 * c4_x3 *
    c4_c_mpower(chartInstance, c4_y2) * c4_y3) - 2.0 * c4_x2 * c4_c_mpower
    (chartInstance, c4_x3) * c4_y2 * c4_y3) - 2.0 * c4_c_mpower(chartInstance,
    c4_x1) * c4_x4 * c4_y1 * c4_y4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) *
    c4_x3 * c4_y2 * c4_y3) - 2.0 * c4_x2 * c4_x4 * c4_y2 * c4_c_mpower
    (chartInstance, c4_y4)) - 2.0 * c4_x2 * c4_x4 * c4_c_mpower(chartInstance,
    c4_y2) * c4_y4) - 2.0 * c4_x2 * c4_c_mpower(chartInstance, c4_x4) * c4_y2 *
    c4_y4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) * c4_x4 * c4_y2 * c4_y4) -
    2.0 * c4_x3 * c4_x4 * c4_y3 * c4_c_mpower(chartInstance, c4_y4)) - 2.0 *
    c4_x3 * c4_x4 * c4_c_mpower(chartInstance, c4_y3) * c4_y4) - 2.0 * c4_x3 *
    c4_c_mpower(chartInstance, c4_x4) * c4_y3 * c4_y4) - 2.0 * c4_c_mpower
    (chartInstance, c4_x3) * c4_x4 * c4_y3 * c4_y4) - 2.0 * c4_x1 * c4_x2 *
    c4_z1 * c4_c_mpower(chartInstance, c4_z2)) - 2.0 * c4_x1 * c4_x2 *
    c4_c_mpower(chartInstance, c4_z1) * c4_z2) - 2.0 * c4_x1 * c4_c_mpower
    (chartInstance, c4_x2) * c4_z1 * c4_z2) - 2.0 * c4_c_mpower(chartInstance,
    c4_x1) * c4_x2 * c4_z1 * c4_z2) - 2.0 * c4_x1 * c4_x3 * c4_z1 * c4_c_mpower
    (chartInstance, c4_z3)) - 2.0 * c4_x1 * c4_x3 * c4_c_mpower(chartInstance,
    c4_z1) * c4_z3) - 2.0 * c4_x1 * c4_c_mpower(chartInstance, c4_x3) * c4_z1 *
    c4_z3) - 2.0 * c4_c_mpower(chartInstance, c4_x1) * c4_x3 * c4_z1 * c4_z3) -
    2.0 * c4_x1 * c4_x4 * c4_z1 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x1 * c4_x4 * c4_c_mpower(chartInstance, c4_z1) * c4_z4) - 2.0 * c4_x1 *
    c4_c_mpower(chartInstance, c4_x4) * c4_z1 * c4_z4) - 2.0 * c4_x2 * c4_x3 *
    c4_z2 * c4_c_mpower(chartInstance, c4_z3)) - 2.0 * c4_x2 * c4_x3 *
    c4_c_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 * c4_x2 * c4_c_mpower
    (chartInstance, c4_x3) * c4_z2 * c4_z3) - 2.0 * c4_c_mpower(chartInstance,
    c4_x1) * c4_x4 * c4_z1 * c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) *
    c4_x3 * c4_z2 * c4_z3) - 2.0 * c4_x2 * c4_x4 * c4_z2 * c4_c_mpower
    (chartInstance, c4_z4)) - 2.0 * c4_x2 * c4_x4 * c4_c_mpower(chartInstance,
    c4_z2) * c4_z4) - 2.0 * c4_x2 * c4_c_mpower(chartInstance, c4_x4) * c4_z2 *
    c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) * c4_x4 * c4_z2 * c4_z4) -
    2.0 * c4_x3 * c4_x4 * c4_z3 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x3 * c4_x4 * c4_c_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_x3 *
    c4_c_mpower(chartInstance, c4_x4) * c4_z3 * c4_z4) - 2.0 * c4_c_mpower
    (chartInstance, c4_x3) * c4_x4 * c4_z3 * c4_z4) - 2.0 * c4_y1 * c4_y2 *
    c4_z1 * c4_c_mpower(chartInstance, c4_z2)) - 2.0 * c4_y1 * c4_y2 *
    c4_c_mpower(chartInstance, c4_z1) * c4_z2) - 2.0 * c4_y1 * c4_c_mpower
    (chartInstance, c4_y2) * c4_z1 * c4_z2) - 2.0 * c4_c_mpower(chartInstance,
    c4_y1) * c4_y2 * c4_z1 * c4_z2) - 2.0 * c4_y1 * c4_y3 * c4_z1 * c4_c_mpower
    (chartInstance, c4_z3)) - 2.0 * c4_y1 * c4_y3 * c4_c_mpower(chartInstance,
    c4_z1) * c4_z3) - 2.0 * c4_y1 * c4_c_mpower(chartInstance, c4_y3) * c4_z1 *
    c4_z3) - 2.0 * c4_c_mpower(chartInstance, c4_y1) * c4_y3 * c4_z1 * c4_z3) -
    2.0 * c4_y1 * c4_y4 * c4_z1 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_y1 * c4_y4 * c4_c_mpower(chartInstance, c4_z1) * c4_z4) - 2.0 * c4_y1 *
    c4_c_mpower(chartInstance, c4_y4) * c4_z1 * c4_z4) - 2.0 * c4_y2 * c4_y3 *
    c4_z2 * c4_c_mpower(chartInstance, c4_z3)) - 2.0 * c4_y2 * c4_y3 *
    c4_c_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 * c4_y2 * c4_c_mpower
    (chartInstance, c4_y3) * c4_z2 * c4_z3) - 2.0 * c4_c_mpower(chartInstance,
    c4_y1) * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_y2) *
    c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_y2 * c4_y4 * c4_z2 * c4_c_mpower
    (chartInstance, c4_z4)) - 2.0 * c4_y2 * c4_y4 * c4_c_mpower(chartInstance,
    c4_z2) * c4_z4) - 2.0 * c4_y2 * c4_c_mpower(chartInstance, c4_y4) * c4_z2 *
    c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_y2) * c4_y4 * c4_z2 * c4_z4) -
    2.0 * c4_y3 * c4_y4 * c4_z3 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_y3 * c4_y4 * c4_c_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_y3 *
    c4_c_mpower(chartInstance, c4_y4) * c4_z3 * c4_z4) - 2.0 * c4_c_mpower
    (chartInstance, c4_y3) * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x2 *
    c4_mpower(chartInstance, c4_x3) * c4_y1 * c4_y2) - 2.0 * c4_x1 * c4_x2 *
    c4_mpower(chartInstance, c4_x4) * c4_y1 * c4_y2) - 2.0 * c4_x1 * c4_mpower
    (chartInstance, c4_x2) * c4_x3 * c4_y1 * c4_y3) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x2 * c4_x3 * c4_y2 * c4_y3) - 2.0 * c4_x1 *
    c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_y1 * c4_y3) - 2.0 * c4_x1 *
    c4_mpower(chartInstance, c4_x2) * c4_x4 * c4_y1 * c4_y4) - 2.0 * c4_x1 *
    c4_mpower(chartInstance, c4_x3) * c4_x4 * c4_y1 * c4_y4) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x2 * c4_x4 * c4_y2 * c4_y4) - 2.0 * c4_x2 *
    c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_y2 * c4_y3) - 2.0 * c4_x2 *
    c4_mpower(chartInstance, c4_x3) * c4_x4 * c4_y2 * c4_y4) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x3 * c4_x4 * c4_y3 * c4_y4) - 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_x3 * c4_x4 * c4_y3 * c4_y4) - 2.0 * c4_x1 *
    c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_y3)) - 2.0 * c4_x1 *
                       c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_y4))
                      - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_mpower(chartInstance,
    c4_y2) * c4_y3) - 2.0 * c4_x2 * c4_x3 * c4_mpower(chartInstance, c4_y1) *
                     c4_y2 * c4_y3) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3 *
                    c4_mpower(chartInstance, c4_y4)) - 2.0 * c4_x1 * c4_x4 *
                   c4_y1 * c4_mpower(chartInstance, c4_y2) * c4_y4) - 2.0 *
                  c4_x1 * c4_x4 * c4_y1 * c4_mpower(chartInstance, c4_y3) *
                  c4_y4) - 2.0 * c4_x2 * c4_x4 * c4_mpower(chartInstance, c4_y1)
                 * c4_y2 * c4_y4) - 2.0 * c4_x2 * c4_x3 * c4_y2 * c4_y3 *
                c4_mpower(chartInstance, c4_y4)) - 2.0 * c4_x2 * c4_x4 * c4_y2 *
               c4_mpower(chartInstance, c4_y3) * c4_y4) - 2.0 * c4_x3 * c4_x4 *
              c4_mpower(chartInstance, c4_y1) * c4_y3 * c4_y4) - 2.0 * c4_x3 *
             c4_x4 * c4_mpower(chartInstance, c4_y2) * c4_y3 * c4_y4) - 2.0 *
            c4_x1 * c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_z1)) -
           2.0 * c4_x1 * c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_z2))
          - 2.0 * c4_x1 * c4_x2 * c4_mpower(chartInstance, c4_x3) * c4_z1 *
          c4_z2) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3 * c4_mpower(chartInstance,
          c4_z1)) - 2.0 * c4_x1 * c4_x2 * c4_mpower(chartInstance, c4_x4) *
        c4_z1 * c4_z2) - 2.0 * c4_x1 * c4_mpower(chartInstance, c4_x2) * c4_x3 *
       c4_z1 * c4_z3) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3 * c4_mpower
      (chartInstance, c4_z3)) - 2.0 * c4_x1 * c4_x4 * c4_y1 * c4_y4 * c4_mpower
     (chartInstance, c4_z1)) - 2.0 * c4_mpower(chartInstance, c4_x1) * c4_x2 *
    c4_x3 * c4_z2 * c4_z3;
  c4_e_B =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d99 - c4_d84) - c4_d83 * c4_z4) - c4_d82 * c4_y3 *
    c4_mpower(chartInstance, c4_z2)) - c4_d81 * c4_x4 * c4_z1 * c4_z4) - c4_d80 *
    c4_x3 * c4_y2 * c4_y3 * c4_mpower(chartInstance, c4_z3)) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x2 * c4_x4 * c4_z2 * c4_z4) - 2.0 * c4_x1 *
    c4_x4 * c4_y1 * c4_y4 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_x2 *
    c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_z2 * c4_z3) - 2.0 * c4_x2 *
    c4_x4 * c4_y2 * c4_y4 * c4_mpower(chartInstance, c4_z2)) - 2.0 * c4_x2 *
    c4_mpower(chartInstance, c4_x3) * c4_x4 * c4_z2 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x3 * c4_x4 * c4_z3 * c4_z4) - 2.0 * c4_x2 *
    c4_x4 * c4_y2 * c4_y4 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_x3 * c4_x4 * c4_z3 * c4_z4) - 2.0 * c4_x3 *
    c4_x4 * c4_y3 * c4_y4 * c4_mpower(chartInstance, c4_z3)) - 2.0 * c4_x3 *
    c4_x4 * c4_y3 * c4_y4 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_x1 *
    c4_x2 * c4_mpower(chartInstance, c4_y1) * c4_z1 * c4_z2) - 2.0 * c4_x1 *
    c4_x2 * c4_mpower(chartInstance, c4_y2) * c4_z1 * c4_z2) - 2.0 * c4_x1 *
    c4_x3 * c4_mpower(chartInstance, c4_y1) * c4_z1 * c4_z3) - 2.0 * c4_x1 *
    c4_x3 * c4_mpower(chartInstance, c4_y3) * c4_z1 * c4_z3) - 2.0 * c4_x1 *
    c4_x4 * c4_mpower(chartInstance, c4_y1) * c4_z1 * c4_z4) - 2.0 * c4_x2 *
    c4_x3 * c4_mpower(chartInstance, c4_y2) * c4_z2 * c4_z3) - 2.0 * c4_x2 *
    c4_x3 * c4_mpower(chartInstance, c4_y3) * c4_z2 * c4_z3) - 2.0 * c4_x1 *
    c4_x4 * c4_mpower(chartInstance, c4_y4) * c4_z1 * c4_z4) - 2.0 * c4_x2 *
    c4_x4 * c4_mpower(chartInstance, c4_y2) * c4_z2 * c4_z4) - 2.0 * c4_x2 *
    c4_x4 * c4_mpower(chartInstance, c4_y4) * c4_z2 * c4_z4) - 2.0 * c4_x3 *
    c4_x4 * c4_mpower(chartInstance, c4_y3) * c4_z3 * c4_z4) - 2.0 * c4_x3 *
    c4_x4 * c4_mpower(chartInstance, c4_y4) * c4_z3 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_y1 * c4_y2 * c4_z1 * c4_z2) - 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_y1 * c4_y2 * c4_z1 * c4_z2) - 2.0 * c4_x1 *
    c4_x2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z3)) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_y1 * c4_y3 * c4_z1 * c4_z3) - 2.0 * c4_x1 *
    c4_x2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_x1 *
    c4_x3 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 * c4_x2 *
    c4_x3 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z3) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_y1 * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x3) * c4_y1 * c4_y3 * c4_z1 * c4_z3) - 2.0 * c4_x1 *
    c4_x3 * c4_z1 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_x1 *
    c4_x4 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_x1 *
    c4_x4 * c4_z1 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_x2 *
    c4_x4 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x3) * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_x2 *
    c4_x3 * c4_z2 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x4) * c4_y1 * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_x2 *
    c4_x4 * c4_z2 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_x3 *
    c4_x4 * c4_mpower(chartInstance, c4_z1) * c4_z3 * c4_z4) - 2.0 * c4_x3 *
    c4_x4 * c4_mpower(chartInstance, c4_z2) * c4_z3 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x4) * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x3) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_x4) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_y1 *
    c4_y2 * c4_mpower(chartInstance, c4_y3) * c4_z1 * c4_z2) - 2.0 * c4_y1 *
    c4_y2 * c4_mpower(chartInstance, c4_y4) * c4_z1 * c4_z2) - 2.0 * c4_y1 *
    c4_mpower(chartInstance, c4_y2) * c4_y3 * c4_z1 * c4_z3) - 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_y1 *
    c4_y3 * c4_mpower(chartInstance, c4_y4) * c4_z1 * c4_z3) - 2.0 * c4_y1 *
    c4_mpower(chartInstance, c4_y2) * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_y1 *
    c4_mpower(chartInstance, c4_y3) * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 2.0 * c4_y2 *
    c4_y3 * c4_mpower(chartInstance, c4_y4) * c4_z2 * c4_z3) - 2.0 * c4_y2 *
    c4_mpower(chartInstance, c4_y3) * c4_y4 * c4_z2 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_mpower
    (chartInstance, c4_y2) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_y1 *
    c4_y2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z3)) - 2.0 * c4_y1 *
    c4_y2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_y1 *
    c4_y3 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 * c4_y2 *
    c4_y3 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z3) - 2.0 * c4_y1 *
    c4_y3 * c4_z1 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_y1 *
    c4_y4 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z4) - 2.0 * c4_y1 *
    c4_y4 * c4_z1 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_y2 *
    c4_y4 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z4) - 2.0 * c4_y2 *
    c4_y3 * c4_z2 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 * c4_y2 *
    c4_y4 * c4_z2 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_y3 *
    c4_y4 * c4_mpower(chartInstance, c4_z1) * c4_z3 * c4_z4) - 2.0 * c4_y3 *
    c4_y4 * c4_mpower(chartInstance, c4_z2) * c4_z3 * c4_z4) - 2.0 * c4_x1 *
    c4_x2 * c4_y1 * c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_x1 * c4_x2 * c4_y2 * c4_y3
    * c4_z1 * c4_z3) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y2 * c4_z2 * c4_z3) -
    2.0 * c4_x1 * c4_x3 * c4_y2 * c4_y3 * c4_z1 * c4_z2) - 2.0 * c4_x2 * c4_x3 *
    c4_y1 * c4_y2 * c4_z1 * c4_z3) - 2.0 * c4_x2 * c4_x3 * c4_y1 * c4_y3 * c4_z1
                       * c4_z2) - 2.0 * c4_x1 * c4_x2 * c4_y1 * c4_y4 * c4_z2 *
                      c4_z4) - 2.0 * c4_x1 * c4_x2 * c4_y2 * c4_y4 * c4_z1 *
                     c4_z4) - 2.0 * c4_x1 * c4_x4 * c4_y1 * c4_y2 * c4_z2 *
                    c4_z4) - 2.0 * c4_x1 * c4_x4 * c4_y2 * c4_y4 * c4_z1 * c4_z2)
                  - 2.0 * c4_x2 * c4_x4 * c4_y1 * c4_y2 * c4_z1 * c4_z4) - 2.0 *
                 c4_x2 * c4_x4 * c4_y1 * c4_y4 * c4_z1 * c4_z2) - 2.0 * c4_x1 *
                c4_x3 * c4_y1 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x3 *
               c4_y3 * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_x1 * c4_x4 * c4_y1 *
              c4_y3 * c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x4 * c4_y3 * c4_y4 *
             c4_z1 * c4_z3) - 2.0 * c4_x3 * c4_x4 * c4_y1 * c4_y3 * c4_z1 *
            c4_z4) - 2.0 * c4_x3 * c4_x4 * c4_y1 * c4_y4 * c4_z1 * c4_z3) - 2.0 *
          c4_x2 * c4_x3 * c4_y2 * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_x2 * c4_x3 *
         c4_y3 * c4_y4 * c4_z2 * c4_z4) - 2.0 * c4_x2 * c4_x4 * c4_y2 * c4_y3 *
        c4_z3 * c4_z4) - 2.0 * c4_x2 * c4_x4 * c4_y3 * c4_y4 * c4_z2 * c4_z3) -
      2.0 * c4_x3 * c4_x4 * c4_y2 * c4_y3 * c4_z2 * c4_z4) - 2.0 * c4_x3 * c4_x4
     * c4_y2 * c4_y4 * c4_z2 * c4_z3) + 64.0;
  c4_s_x = c4_e_A;
  c4_q_y = c4_e_B;
  c4_t_x = c4_s_x;
  c4_r_y = c4_q_y;
  c4_u_x = c4_t_x;
  c4_s_y = c4_r_y;
  c4_t_y = c4_u_x / c4_s_y;
  c4_f_A = 4.0 * (((((((((((((((((((((((((((((((((((((((((((((((((((4.0 * c4_y1 *
    c4_z1 + 4.0 * c4_y2 * c4_z2) + 4.0 * c4_y3 * c4_z3) + 4.0 * c4_y4 * c4_z4) +
    c4_y1 * c4_c_mpower(chartInstance, c4_z1)) + c4_c_mpower(chartInstance,
    c4_y1) * c4_z1) + c4_y2 * c4_c_mpower(chartInstance, c4_z2)) + c4_c_mpower
    (chartInstance, c4_y2) * c4_z2) + c4_y3 * c4_c_mpower(chartInstance, c4_z3))
    + c4_c_mpower(chartInstance, c4_y3) * c4_z3) + c4_y4 * c4_c_mpower
    (chartInstance, c4_z4)) + c4_c_mpower(chartInstance, c4_y4) * c4_z4) +
    c4_mpower(chartInstance, c4_x1) * c4_y1 * c4_z1) + c4_mpower(chartInstance,
    c4_x2) * c4_y2 * c4_z2) + c4_mpower(chartInstance, c4_x3) * c4_y3 * c4_z3) +
    c4_mpower(chartInstance, c4_x4) * c4_y4 * c4_z4) + c4_y1 * c4_mpower
    (chartInstance, c4_y2) * c4_z1) + c4_y1 * c4_mpower(chartInstance, c4_y3) *
    c4_z1) + c4_mpower(chartInstance, c4_y1) * c4_y2 * c4_z2) + c4_y1 *
    c4_mpower(chartInstance, c4_y4) * c4_z1) + c4_y2 * c4_mpower(chartInstance,
    c4_y3) * c4_z2) + c4_mpower(chartInstance, c4_y1) * c4_y3 * c4_z3) + c4_y2 *
    c4_mpower(chartInstance, c4_y4) * c4_z2) + c4_mpower(chartInstance, c4_y2) *
    c4_y3 * c4_z3) + c4_mpower(chartInstance, c4_y1) * c4_y4 * c4_z4) + c4_y3 *
    c4_mpower(chartInstance, c4_y4) * c4_z3) + c4_mpower(chartInstance, c4_y2) *
    c4_y4 * c4_z4) + c4_mpower(chartInstance, c4_y3) * c4_y4 * c4_z4) + c4_y1 *
    c4_z1 * c4_mpower(chartInstance, c4_z2)) + c4_y1 * c4_z1 * c4_mpower
    (chartInstance, c4_z3)) + c4_y2 * c4_mpower(chartInstance, c4_z1) * c4_z2) +
    c4_y1 * c4_z1 * c4_mpower(chartInstance, c4_z4)) + c4_y2 * c4_z2 * c4_mpower
    (chartInstance, c4_z3)) + c4_y3 * c4_mpower(chartInstance, c4_z1) * c4_z3) +
    c4_y2 * c4_z2 * c4_mpower(chartInstance, c4_z4)) + c4_y3 * c4_mpower
    (chartInstance, c4_z2) * c4_z3) + c4_y4 * c4_mpower(chartInstance, c4_z1) *
    c4_z4) + c4_y3 * c4_z3 * c4_mpower(chartInstance, c4_z4)) + c4_y4 *
    c4_mpower(chartInstance, c4_z2) * c4_z4) + c4_y4 * c4_mpower(chartInstance,
    c4_z3) * c4_z4) + c4_x1 * c4_x2 * c4_y1 * c4_z2) + c4_x1 * c4_x2 * c4_y2 *
    c4_z1) + c4_x1 * c4_x3 * c4_y1 * c4_z3) + c4_x1 * c4_x3 * c4_y3 * c4_z1) +
    c4_x1 * c4_x4 * c4_y1 * c4_z4) + c4_x1 * c4_x4 * c4_y4 * c4_z1) + c4_x2 *
                       c4_x3 * c4_y2 * c4_z3) + c4_x2 * c4_x3 * c4_y3 * c4_z2) +
                     c4_x2 * c4_x4 * c4_y2 * c4_z4) + c4_x2 * c4_x4 * c4_y4 *
                    c4_z2) + c4_x3 * c4_x4 * c4_y3 * c4_z4) + c4_x3 * c4_x4 *
                  c4_y4 * c4_z3);
  c4_d100 = 2.0 * c4_x2;
  c4_d101 = 2.0 * c4_x1 * c4_mpower(chartInstance, c4_x3);
  c4_d102 = 2.0 * c4_x2 * c4_x3 * c4_y2;
  c4_d103 = 2.0 * c4_x1 * c4_mpower(chartInstance, c4_x2) * c4_x4 * c4_z1;
  c4_d104 = 2.0 * c4_x1 * c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_z1 *
    c4_z3;
  c4_d105 = 2.0 * c4_x1;
  c4_d106 = 2.0 * c4_c_mpower(chartInstance, c4_x1) * c4_x3;
  c4_d107 = 2.0 * c4_x1 * c4_c_mpower(chartInstance, c4_x3) * c4_y1;
  c4_d108 = 2.0 * c4_x1 * c4_x3 * c4_c_mpower(chartInstance, c4_y1) * c4_y3;
  c4_d109 = 2.0 * c4_mpower(chartInstance, c4_x3);
  c4_d110 = 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y4);
  c4_d111 = 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z3);
  c4_d112 = c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1);
  c4_d113 = c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z1);
  c4_d114 = c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_z3);
  c4_d115 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x2) + 8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x3)) + 8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x4)) + 8.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_x3)) + 8.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_x4)) + 8.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
    c4_x4)) + 8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_y1)) + 12.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_y2)) + 12.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y1)) + 12.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_y3)) + 8.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y2)) + 12.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
    c4_y1)) + c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_y2))
    + 12.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y4))
    + c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_y1)) +
    12.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_y3)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_y1)) + 8.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y3)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2)) +
    c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_y2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_y1)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2)) +
    c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) +
    c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_y2)) + 8.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3)) + 8.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z1)) + 12.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2)) + 12.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z3)) + 8.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_z1)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z3)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z2)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4)) + 8.0 *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_z3)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z4)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z3)) + 12.0 *
                       c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_z2)) + c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1))
                     + 8.0 * c4_mpower(chartInstance, c4_y2) * c4_mpower
                     (chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x1) *
                    c4_b_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance,
    c4_x2) * c4_b_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance,
    c4_x1) * c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x3) *
                 c4_b_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower
                (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z4)) +
               c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_z3)) + c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_z1))
             + 12.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
              c4_z3)) + c4_b_mpower(chartInstance, c4_x3) * c4_mpower
            (chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_x4) *
           c4_mpower(chartInstance, c4_z1)) + 8.0 * c4_mpower(chartInstance,
           c4_y3) * c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance,
          c4_x2) * c4_b_mpower(chartInstance, c4_z4)) + c4_b_mpower
        (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
       (chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_z2)) + 8.0 *
      c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) +
     c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_z4);
  c4_d116 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d115 + c4_d114) + c4_b_mpower(chartInstance, c4_x3)
    * c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y1) *
    c4_b_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) *
    c4_b_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y1) *
    c4_b_mpower(chartInstance, c4_z3)) + 12.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y3) *
    c4_b_mpower(chartInstance, c4_z1)) + 8.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 12.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y1) *
    c4_b_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) *
    c4_b_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y3) *
    c4_b_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y4) *
    c4_b_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y2) *
    c4_b_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) *
    c4_b_mpower(chartInstance, c4_z2)) + 8.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y3) *
    c4_b_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) *
    c4_b_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + 8.0 * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + 8.0 * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z4)) + 8.0 * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + 32.0 * c4_mpower(chartInstance, c4_x1)) +
    32.0 * c4_mpower(chartInstance, c4_x2)) + 4.0 * c4_b_mpower(chartInstance,
    c4_x1)) + 32.0 * c4_mpower(chartInstance, c4_x3)) + 4.0 * c4_b_mpower
    (chartInstance, c4_x2)) + 32.0 * c4_mpower(chartInstance, c4_x4)) + 4.0 *
    c4_b_mpower(chartInstance, c4_x3)) + 4.0 * c4_b_mpower(chartInstance, c4_x4))
    + 32.0 * c4_mpower(chartInstance, c4_y1)) + 32.0 * c4_mpower(chartInstance,
    c4_y2)) + 4.0 * c4_b_mpower(chartInstance, c4_y1)) + 32.0 * c4_mpower
    (chartInstance, c4_y3)) + 4.0 * c4_b_mpower(chartInstance, c4_y2)) + 32.0 *
    c4_mpower(chartInstance, c4_y4)) + 4.0 * c4_b_mpower(chartInstance, c4_y3))
    + 4.0 * c4_b_mpower(chartInstance, c4_y4)) + 32.0 * c4_mpower(chartInstance,
    c4_z1)) + 32.0 * c4_mpower(chartInstance, c4_z2)) + 4.0 * c4_b_mpower
    (chartInstance, c4_z1)) + 32.0 * c4_mpower(chartInstance, c4_z3)) + 4.0 *
    c4_b_mpower(chartInstance, c4_z2)) + 32.0 * c4_mpower(chartInstance, c4_z4))
    + 4.0 * c4_b_mpower(chartInstance, c4_z3)) + 4.0 * c4_b_mpower(chartInstance,
    c4_z4)) + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
                       c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y4)) + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
                      c4_mpower(chartInstance, c4_y3)) + 2.0 * c4_mpower
                     (chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x4) *
                     c4_mpower(chartInstance, c4_y2)) + c4_mpower(chartInstance,
    c4_x2) * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2))
                   + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower
                   (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) +
                  2.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower
                  (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4)) +
                 2.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x4) * c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x2) *
                c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y3))
               + c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_x4) * c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance,
    c4_x3) * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1))
             + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x4)
             * c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance,
             c4_x2) * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
             c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower
           (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
          c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_x4) *
          c4_mpower(chartInstance, c4_y2)) + c4_mpower(chartInstance, c4_x2) *
         c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4)) +
        c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_x4) *
        c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x3) *
       c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4)) +
      c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x2) *
      c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_x1) *
     c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_z2);
  c4_d117 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d116 + c4_d113) + c4_d112 * c4_mpower(chartInstance,
    c4_y3)) + c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
                       c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
    c4_y1) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance,
    c4_x3) * c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3))
                     + 2.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower
                     (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z2)) +
                    2.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower
                    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) +
                   2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
                   (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z3)) +
                  2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
                  (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) +
                 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance,
    c4_x1) * c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z4))
               + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance,
    c4_x2) * c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3))
             + 2.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
              c4_y2) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
            (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4) * c4_mpower
            (chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
           c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z4)) +
          2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2)
          * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance,
          c4_x4) * c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance,
          c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
        (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
       c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y4) *
       c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
      c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
     c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4) *
     c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4);
  c4_d118 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d117 + c4_d111) + c4_d110 * c4_mpower(chartInstance,
    c4_z2)) + c4_d109 * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
    (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x1) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) + c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_x1) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) + c4_mpower
    (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) + c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_x1) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower
    (chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x2) * c4_mpower
    (chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) + c4_mpower
    (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower
    (chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3)) + c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower
    (chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
    (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x4) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
    (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_x3) * c4_mpower
    (chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x4) * c4_mpower
    (chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) + c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) + c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) + c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z3) * c4_mpower
    (chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3) * c4_mpower
    (chartInstance, c4_z4)) - 8.0 * c4_x1 * c4_x2 * c4_y1 * c4_y2) - 8.0 * c4_x1
    * c4_x3 * c4_y1 * c4_y3) - 8.0 * c4_x1 * c4_x4 * c4_y1 * c4_y4) - 8.0 *
                       c4_x2 * c4_x3 * c4_y2 * c4_y3) - 8.0 * c4_x2 * c4_x4 *
                      c4_y2 * c4_y4) - 8.0 * c4_x3 * c4_x4 * c4_y3 * c4_y4) -
                    8.0 * c4_x1 * c4_x2 * c4_z1 * c4_z2) - 8.0 * c4_x1 * c4_x3 *
                   c4_z1 * c4_z3) - 8.0 * c4_x1 * c4_x4 * c4_z1 * c4_z4) - 8.0 *
                 c4_x2 * c4_x3 * c4_z2 * c4_z3) - 8.0 * c4_x2 * c4_x4 * c4_z2 *
                c4_z4) - 8.0 * c4_x3 * c4_x4 * c4_z3 * c4_z4) - 8.0 * c4_y1 *
              c4_y2 * c4_z1 * c4_z2) - 8.0 * c4_y1 * c4_y3 * c4_z1 * c4_z3) -
            8.0 * c4_y1 * c4_y4 * c4_z1 * c4_z4) - 8.0 * c4_y2 * c4_y3 * c4_z2 *
           c4_z3) - 8.0 * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 8.0 * c4_y3 * c4_y4 *
         c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x2 * c4_y1 * c4_c_mpower
        (chartInstance, c4_y2)) - 2.0 * c4_x1 * c4_x2 * c4_c_mpower
       (chartInstance, c4_y1) * c4_y2) - 2.0 * c4_x1 * c4_c_mpower(chartInstance,
       c4_x2) * c4_y1 * c4_y2) - 2.0 * c4_c_mpower(chartInstance, c4_x1) * c4_x2
     * c4_y1 * c4_y2) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_c_mpower(chartInstance,
    c4_y3);
  c4_d119 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d118 - c4_d108) - c4_d107 * c4_y3) - c4_d106 *
    c4_y1 * c4_y3) - c4_d105 * c4_x4 * c4_y1 * c4_c_mpower(chartInstance, c4_y4))
    - 2.0 * c4_x1 * c4_x4 * c4_c_mpower(chartInstance, c4_y1) * c4_y4) - 2.0 *
    c4_x1 * c4_c_mpower(chartInstance, c4_x4) * c4_y1 * c4_y4) - 2.0 * c4_x2 *
    c4_x3 * c4_y2 * c4_c_mpower(chartInstance, c4_y3)) - 2.0 * c4_x2 * c4_x3 *
    c4_c_mpower(chartInstance, c4_y2) * c4_y3) - 2.0 * c4_x2 * c4_c_mpower
    (chartInstance, c4_x3) * c4_y2 * c4_y3) - 2.0 * c4_c_mpower(chartInstance,
    c4_x1) * c4_x4 * c4_y1 * c4_y4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) *
    c4_x3 * c4_y2 * c4_y3) - 2.0 * c4_x2 * c4_x4 * c4_y2 * c4_c_mpower
    (chartInstance, c4_y4)) - 2.0 * c4_x2 * c4_x4 * c4_c_mpower(chartInstance,
    c4_y2) * c4_y4) - 2.0 * c4_x2 * c4_c_mpower(chartInstance, c4_x4) * c4_y2 *
    c4_y4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) * c4_x4 * c4_y2 * c4_y4) -
    2.0 * c4_x3 * c4_x4 * c4_y3 * c4_c_mpower(chartInstance, c4_y4)) - 2.0 *
    c4_x3 * c4_x4 * c4_c_mpower(chartInstance, c4_y3) * c4_y4) - 2.0 * c4_x3 *
    c4_c_mpower(chartInstance, c4_x4) * c4_y3 * c4_y4) - 2.0 * c4_c_mpower
    (chartInstance, c4_x3) * c4_x4 * c4_y3 * c4_y4) - 2.0 * c4_x1 * c4_x2 *
    c4_z1 * c4_c_mpower(chartInstance, c4_z2)) - 2.0 * c4_x1 * c4_x2 *
    c4_c_mpower(chartInstance, c4_z1) * c4_z2) - 2.0 * c4_x1 * c4_c_mpower
    (chartInstance, c4_x2) * c4_z1 * c4_z2) - 2.0 * c4_c_mpower(chartInstance,
    c4_x1) * c4_x2 * c4_z1 * c4_z2) - 2.0 * c4_x1 * c4_x3 * c4_z1 * c4_c_mpower
    (chartInstance, c4_z3)) - 2.0 * c4_x1 * c4_x3 * c4_c_mpower(chartInstance,
    c4_z1) * c4_z3) - 2.0 * c4_x1 * c4_c_mpower(chartInstance, c4_x3) * c4_z1 *
    c4_z3) - 2.0 * c4_c_mpower(chartInstance, c4_x1) * c4_x3 * c4_z1 * c4_z3) -
    2.0 * c4_x1 * c4_x4 * c4_z1 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x1 * c4_x4 * c4_c_mpower(chartInstance, c4_z1) * c4_z4) - 2.0 * c4_x1 *
    c4_c_mpower(chartInstance, c4_x4) * c4_z1 * c4_z4) - 2.0 * c4_x2 * c4_x3 *
    c4_z2 * c4_c_mpower(chartInstance, c4_z3)) - 2.0 * c4_x2 * c4_x3 *
    c4_c_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 * c4_x2 * c4_c_mpower
    (chartInstance, c4_x3) * c4_z2 * c4_z3) - 2.0 * c4_c_mpower(chartInstance,
    c4_x1) * c4_x4 * c4_z1 * c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) *
    c4_x3 * c4_z2 * c4_z3) - 2.0 * c4_x2 * c4_x4 * c4_z2 * c4_c_mpower
    (chartInstance, c4_z4)) - 2.0 * c4_x2 * c4_x4 * c4_c_mpower(chartInstance,
    c4_z2) * c4_z4) - 2.0 * c4_x2 * c4_c_mpower(chartInstance, c4_x4) * c4_z2 *
    c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) * c4_x4 * c4_z2 * c4_z4) -
    2.0 * c4_x3 * c4_x4 * c4_z3 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x3 * c4_x4 * c4_c_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_x3 *
    c4_c_mpower(chartInstance, c4_x4) * c4_z3 * c4_z4) - 2.0 * c4_c_mpower
    (chartInstance, c4_x3) * c4_x4 * c4_z3 * c4_z4) - 2.0 * c4_y1 * c4_y2 *
    c4_z1 * c4_c_mpower(chartInstance, c4_z2)) - 2.0 * c4_y1 * c4_y2 *
    c4_c_mpower(chartInstance, c4_z1) * c4_z2) - 2.0 * c4_y1 * c4_c_mpower
    (chartInstance, c4_y2) * c4_z1 * c4_z2) - 2.0 * c4_c_mpower(chartInstance,
    c4_y1) * c4_y2 * c4_z1 * c4_z2) - 2.0 * c4_y1 * c4_y3 * c4_z1 * c4_c_mpower
    (chartInstance, c4_z3)) - 2.0 * c4_y1 * c4_y3 * c4_c_mpower(chartInstance,
    c4_z1) * c4_z3) - 2.0 * c4_y1 * c4_c_mpower(chartInstance, c4_y3) * c4_z1 *
    c4_z3) - 2.0 * c4_c_mpower(chartInstance, c4_y1) * c4_y3 * c4_z1 * c4_z3) -
    2.0 * c4_y1 * c4_y4 * c4_z1 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_y1 * c4_y4 * c4_c_mpower(chartInstance, c4_z1) * c4_z4) - 2.0 * c4_y1 *
    c4_c_mpower(chartInstance, c4_y4) * c4_z1 * c4_z4) - 2.0 * c4_y2 * c4_y3 *
    c4_z2 * c4_c_mpower(chartInstance, c4_z3)) - 2.0 * c4_y2 * c4_y3 *
    c4_c_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 * c4_y2 * c4_c_mpower
    (chartInstance, c4_y3) * c4_z2 * c4_z3) - 2.0 * c4_c_mpower(chartInstance,
    c4_y1) * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_y2) *
    c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_y2 * c4_y4 * c4_z2 * c4_c_mpower
    (chartInstance, c4_z4)) - 2.0 * c4_y2 * c4_y4 * c4_c_mpower(chartInstance,
    c4_z2) * c4_z4) - 2.0 * c4_y2 * c4_c_mpower(chartInstance, c4_y4) * c4_z2 *
    c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_y2) * c4_y4 * c4_z2 * c4_z4) -
    2.0 * c4_y3 * c4_y4 * c4_z3 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_y3 * c4_y4 * c4_c_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_y3 *
    c4_c_mpower(chartInstance, c4_y4) * c4_z3 * c4_z4) - 2.0 * c4_c_mpower
    (chartInstance, c4_y3) * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x2 *
    c4_mpower(chartInstance, c4_x3) * c4_y1 * c4_y2) - 2.0 * c4_x1 * c4_x2 *
    c4_mpower(chartInstance, c4_x4) * c4_y1 * c4_y2) - 2.0 * c4_x1 * c4_mpower
    (chartInstance, c4_x2) * c4_x3 * c4_y1 * c4_y3) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x2 * c4_x3 * c4_y2 * c4_y3) - 2.0 * c4_x1 *
    c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_y1 * c4_y3) - 2.0 * c4_x1 *
    c4_mpower(chartInstance, c4_x2) * c4_x4 * c4_y1 * c4_y4) - 2.0 * c4_x1 *
    c4_mpower(chartInstance, c4_x3) * c4_x4 * c4_y1 * c4_y4) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x2 * c4_x4 * c4_y2 * c4_y4) - 2.0 * c4_x2 *
    c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_y2 * c4_y3) - 2.0 * c4_x2 *
    c4_mpower(chartInstance, c4_x3) * c4_x4 * c4_y2 * c4_y4) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x3 * c4_x4 * c4_y3 * c4_y4) - 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_x3 * c4_x4 * c4_y3 * c4_y4) - 2.0 * c4_x1 *
    c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_y3)) - 2.0 * c4_x1 *
                       c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_y4))
                      - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_mpower(chartInstance,
    c4_y2) * c4_y3) - 2.0 * c4_x2 * c4_x3 * c4_mpower(chartInstance, c4_y1) *
                     c4_y2 * c4_y3) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3 *
                    c4_mpower(chartInstance, c4_y4)) - 2.0 * c4_x1 * c4_x4 *
                   c4_y1 * c4_mpower(chartInstance, c4_y2) * c4_y4) - 2.0 *
                  c4_x1 * c4_x4 * c4_y1 * c4_mpower(chartInstance, c4_y3) *
                  c4_y4) - 2.0 * c4_x2 * c4_x4 * c4_mpower(chartInstance, c4_y1)
                 * c4_y2 * c4_y4) - 2.0 * c4_x2 * c4_x3 * c4_y2 * c4_y3 *
                c4_mpower(chartInstance, c4_y4)) - 2.0 * c4_x2 * c4_x4 * c4_y2 *
               c4_mpower(chartInstance, c4_y3) * c4_y4) - 2.0 * c4_x3 * c4_x4 *
              c4_mpower(chartInstance, c4_y1) * c4_y3 * c4_y4) - 2.0 * c4_x3 *
             c4_x4 * c4_mpower(chartInstance, c4_y2) * c4_y3 * c4_y4) - 2.0 *
            c4_x1 * c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_z1)) -
           2.0 * c4_x1 * c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_z2))
          - 2.0 * c4_x1 * c4_x2 * c4_mpower(chartInstance, c4_x3) * c4_z1 *
          c4_z2) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3 * c4_mpower(chartInstance,
          c4_z1)) - 2.0 * c4_x1 * c4_x2 * c4_mpower(chartInstance, c4_x4) *
        c4_z1 * c4_z2) - 2.0 * c4_x1 * c4_mpower(chartInstance, c4_x2) * c4_x3 *
       c4_z1 * c4_z3) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3 * c4_mpower
      (chartInstance, c4_z3)) - 2.0 * c4_x1 * c4_x4 * c4_y1 * c4_y4 * c4_mpower
     (chartInstance, c4_z1)) - 2.0 * c4_mpower(chartInstance, c4_x1) * c4_x2 *
    c4_x3 * c4_z2 * c4_z3;
  c4_f_B =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d119 - c4_d104) - c4_d103 * c4_z4) - c4_d102 *
    c4_y3 * c4_mpower(chartInstance, c4_z2)) - c4_d101 * c4_x4 * c4_z1 * c4_z4)
    - c4_d100 * c4_x3 * c4_y2 * c4_y3 * c4_mpower(chartInstance, c4_z3)) - 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_x2 * c4_x4 * c4_z2 * c4_z4) - 2.0 *
    c4_x1 * c4_x4 * c4_y1 * c4_y4 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x2 * c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_z2 * c4_z3) - 2.0 *
    c4_x2 * c4_x4 * c4_y2 * c4_y4 * c4_mpower(chartInstance, c4_z2)) - 2.0 *
    c4_x2 * c4_mpower(chartInstance, c4_x3) * c4_x4 * c4_z2 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_x3 * c4_x4 * c4_z3 * c4_z4) - 2.0 *
    c4_x2 * c4_x4 * c4_y2 * c4_y4 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_x3 * c4_x4 * c4_z3 * c4_z4) - 2.0 *
    c4_x3 * c4_x4 * c4_y3 * c4_y4 * c4_mpower(chartInstance, c4_z3)) - 2.0 *
    c4_x3 * c4_x4 * c4_y3 * c4_y4 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x1 * c4_x2 * c4_mpower(chartInstance, c4_y1) * c4_z1 * c4_z2) - 2.0 *
    c4_x1 * c4_x2 * c4_mpower(chartInstance, c4_y2) * c4_z1 * c4_z2) - 2.0 *
    c4_x1 * c4_x3 * c4_mpower(chartInstance, c4_y1) * c4_z1 * c4_z3) - 2.0 *
    c4_x1 * c4_x3 * c4_mpower(chartInstance, c4_y3) * c4_z1 * c4_z3) - 2.0 *
    c4_x1 * c4_x4 * c4_mpower(chartInstance, c4_y1) * c4_z1 * c4_z4) - 2.0 *
    c4_x2 * c4_x3 * c4_mpower(chartInstance, c4_y2) * c4_z2 * c4_z3) - 2.0 *
    c4_x2 * c4_x3 * c4_mpower(chartInstance, c4_y3) * c4_z2 * c4_z3) - 2.0 *
    c4_x1 * c4_x4 * c4_mpower(chartInstance, c4_y4) * c4_z1 * c4_z4) - 2.0 *
    c4_x2 * c4_x4 * c4_mpower(chartInstance, c4_y2) * c4_z2 * c4_z4) - 2.0 *
    c4_x2 * c4_x4 * c4_mpower(chartInstance, c4_y4) * c4_z2 * c4_z4) - 2.0 *
    c4_x3 * c4_x4 * c4_mpower(chartInstance, c4_y3) * c4_z3 * c4_z4) - 2.0 *
    c4_x3 * c4_x4 * c4_mpower(chartInstance, c4_y4) * c4_z3 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_y1 * c4_y2 * c4_z1 * c4_z2) - 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_y1 * c4_y2 * c4_z1 * c4_z2) - 2.0 *
    c4_x1 * c4_x2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z3)) - 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_y1 * c4_y3 * c4_z1 * c4_z3) - 2.0 *
    c4_x1 * c4_x2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x1 * c4_x3 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 *
    c4_x2 * c4_x3 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z3) - 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_y1 * c4_y4 * c4_z1 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_y1 * c4_y3 * c4_z1 * c4_z3) - 2.0 *
    c4_x1 * c4_x3 * c4_z1 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x1 * c4_x4 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 2.0 *
    c4_x1 * c4_x4 * c4_z1 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 *
    c4_x2 * c4_x4 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 2.0 *
    c4_x2 * c4_x3 * c4_z2 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_y1 * c4_y4 * c4_z1 * c4_z4) - 2.0 *
    c4_x2 * c4_x4 * c4_z2 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 *
    c4_x3 * c4_x4 * c4_mpower(chartInstance, c4_z1) * c4_z3 * c4_z4) - 2.0 *
    c4_x3 * c4_x4 * c4_mpower(chartInstance, c4_z2) * c4_z3 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 *
    c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_y3) * c4_z1 * c4_z2) - 2.0 *
    c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_y4) * c4_z1 * c4_z2) - 2.0 *
    c4_y1 * c4_mpower(chartInstance, c4_y2) * c4_y3 * c4_z1 * c4_z3) - 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 2.0 *
    c4_y1 * c4_y3 * c4_mpower(chartInstance, c4_y4) * c4_z1 * c4_z3) - 2.0 *
    c4_y1 * c4_mpower(chartInstance, c4_y2) * c4_y4 * c4_z1 * c4_z4) - 2.0 *
    c4_y1 * c4_mpower(chartInstance, c4_y3) * c4_y4 * c4_z1 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 2.0 *
    c4_y2 * c4_y3 * c4_mpower(chartInstance, c4_y4) * c4_z2 * c4_z3) - 2.0 *
    c4_y2 * c4_mpower(chartInstance, c4_y3) * c4_y4 * c4_z2 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_y2) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 *
    c4_y1 * c4_y2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z3)) - 2.0 *
    c4_y1 * c4_y2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_y1 * c4_y3 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 *
    c4_y2 * c4_y3 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z3) - 2.0 *
    c4_y1 * c4_y3 * c4_z1 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_y1 * c4_y4 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z4) - 2.0 *
    c4_y1 * c4_y4 * c4_z1 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 *
    c4_y2 * c4_y4 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z4) - 2.0 *
    c4_y2 * c4_y3 * c4_z2 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_y2 * c4_y4 * c4_z2 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 *
    c4_y3 * c4_y4 * c4_mpower(chartInstance, c4_z1) * c4_z3 * c4_z4) - 2.0 *
    c4_y3 * c4_y4 * c4_mpower(chartInstance, c4_z2) * c4_z3 * c4_z4) - 2.0 *
    c4_x1 * c4_x2 * c4_y1 * c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_x1 * c4_x2 * c4_y2
    * c4_y3 * c4_z1 * c4_z3) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y2 * c4_z2 *
    c4_z3) - 2.0 * c4_x1 * c4_x3 * c4_y2 * c4_y3 * c4_z1 * c4_z2) - 2.0 * c4_x2 *
    c4_x3 * c4_y1 * c4_y2 * c4_z1 * c4_z3) - 2.0 * c4_x2 * c4_x3 * c4_y1 * c4_y3
                       * c4_z1 * c4_z2) - 2.0 * c4_x1 * c4_x2 * c4_y1 * c4_y4 *
                      c4_z2 * c4_z4) - 2.0 * c4_x1 * c4_x2 * c4_y2 * c4_y4 *
                     c4_z1 * c4_z4) - 2.0 * c4_x1 * c4_x4 * c4_y1 * c4_y2 *
                    c4_z2 * c4_z4) - 2.0 * c4_x1 * c4_x4 * c4_y2 * c4_y4 * c4_z1
                   * c4_z2) - 2.0 * c4_x2 * c4_x4 * c4_y1 * c4_y2 * c4_z1 *
                  c4_z4) - 2.0 * c4_x2 * c4_x4 * c4_y1 * c4_y4 * c4_z1 * c4_z2)
                - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y4 * c4_z3 * c4_z4) - 2.0 *
               c4_x1 * c4_x3 * c4_y3 * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_x1 *
              c4_x4 * c4_y1 * c4_y3 * c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x4 *
             c4_y3 * c4_y4 * c4_z1 * c4_z3) - 2.0 * c4_x3 * c4_x4 * c4_y1 *
            c4_y3 * c4_z1 * c4_z4) - 2.0 * c4_x3 * c4_x4 * c4_y1 * c4_y4 * c4_z1
           * c4_z3) - 2.0 * c4_x2 * c4_x3 * c4_y2 * c4_y4 * c4_z3 * c4_z4) - 2.0
         * c4_x2 * c4_x3 * c4_y3 * c4_y4 * c4_z2 * c4_z4) - 2.0 * c4_x2 * c4_x4 *
        c4_y2 * c4_y3 * c4_z3 * c4_z4) - 2.0 * c4_x2 * c4_x4 * c4_y3 * c4_y4 *
       c4_z2 * c4_z3) - 2.0 * c4_x3 * c4_x4 * c4_y2 * c4_y3 * c4_z2 * c4_z4) -
     2.0 * c4_x3 * c4_x4 * c4_y2 * c4_y4 * c4_z2 * c4_z3) + 64.0;
  c4_v_x = c4_f_A;
  c4_u_y = c4_f_B;
  c4_w_x = c4_v_x;
  c4_v_y = c4_u_y;
  c4_x_x = c4_w_x;
  c4_w_y = c4_v_y;
  c4_x_y = c4_x_x / c4_w_y;
  c4_g_A = 4.0 * (((((((((((((((((((((((((((((((((((((((((((((((((((4.0 * c4_x1 *
    c4_z1 + 4.0 * c4_x2 * c4_z2) + 4.0 * c4_x3 * c4_z3) + 4.0 * c4_x4 * c4_z4) +
    c4_x1 * c4_c_mpower(chartInstance, c4_z1)) + c4_c_mpower(chartInstance,
    c4_x1) * c4_z1) + c4_x2 * c4_c_mpower(chartInstance, c4_z2)) + c4_c_mpower
    (chartInstance, c4_x2) * c4_z2) + c4_x3 * c4_c_mpower(chartInstance, c4_z3))
    + c4_c_mpower(chartInstance, c4_x3) * c4_z3) + c4_x4 * c4_c_mpower
    (chartInstance, c4_z4)) + c4_c_mpower(chartInstance, c4_x4) * c4_z4) + c4_x1
    * c4_mpower(chartInstance, c4_x2) * c4_z1) + c4_x1 * c4_mpower(chartInstance,
    c4_x3) * c4_z1) + c4_mpower(chartInstance, c4_x1) * c4_x2 * c4_z2) + c4_x1 *
    c4_mpower(chartInstance, c4_x4) * c4_z1) + c4_x2 * c4_mpower(chartInstance,
    c4_x3) * c4_z2) + c4_mpower(chartInstance, c4_x1) * c4_x3 * c4_z3) + c4_x2 *
    c4_mpower(chartInstance, c4_x4) * c4_z2) + c4_mpower(chartInstance, c4_x2) *
    c4_x3 * c4_z3) + c4_mpower(chartInstance, c4_x1) * c4_x4 * c4_z4) + c4_x3 *
    c4_mpower(chartInstance, c4_x4) * c4_z3) + c4_mpower(chartInstance, c4_x2) *
    c4_x4 * c4_z4) + c4_mpower(chartInstance, c4_x3) * c4_x4 * c4_z4) + c4_x1 *
    c4_mpower(chartInstance, c4_y1) * c4_z1) + c4_x2 * c4_mpower(chartInstance,
    c4_y2) * c4_z2) + c4_x3 * c4_mpower(chartInstance, c4_y3) * c4_z3) + c4_x4 *
    c4_mpower(chartInstance, c4_y4) * c4_z4) + c4_x1 * c4_z1 * c4_mpower
    (chartInstance, c4_z2)) + c4_x1 * c4_z1 * c4_mpower(chartInstance, c4_z3)) +
    c4_x2 * c4_mpower(chartInstance, c4_z1) * c4_z2) + c4_x1 * c4_z1 * c4_mpower
    (chartInstance, c4_z4)) + c4_x2 * c4_z2 * c4_mpower(chartInstance, c4_z3)) +
    c4_x3 * c4_mpower(chartInstance, c4_z1) * c4_z3) + c4_x2 * c4_z2 * c4_mpower
                                   (chartInstance, c4_z4)) + c4_x3 * c4_mpower
    (chartInstance, c4_z2) * c4_z3) + c4_x4 * c4_mpower(chartInstance, c4_z1) *
    c4_z4) + c4_x3 * c4_z3 * c4_mpower(chartInstance, c4_z4)) + c4_x4 *
    c4_mpower(chartInstance, c4_z2) * c4_z4) + c4_x4 * c4_mpower(chartInstance,
    c4_z3) * c4_z4) + c4_x1 * c4_y1 * c4_y2 * c4_z2) + c4_x2 * c4_y1 * c4_y2 *
    c4_z1) + c4_x1 * c4_y1 * c4_y3 * c4_z3) + c4_x3 * c4_y1 * c4_y3 * c4_z1) +
    c4_x1 * c4_y1 * c4_y4 * c4_z4) + c4_x2 * c4_y2 * c4_y3 * c4_z3) + c4_x3 *
                       c4_y2 * c4_y3 * c4_z2) + c4_x4 * c4_y1 * c4_y4 * c4_z1) +
                     c4_x2 * c4_y2 * c4_y4 * c4_z4) + c4_x4 * c4_y2 * c4_y4 *
                    c4_z2) + c4_x3 * c4_y3 * c4_y4 * c4_z4) + c4_x4 * c4_y3 *
                  c4_y4 * c4_z3);
  c4_d120 = 2.0 * c4_x2;
  c4_d121 = 2.0 * c4_x1 * c4_mpower(chartInstance, c4_x3);
  c4_d122 = 2.0 * c4_x2 * c4_x3 * c4_y2;
  c4_d123 = 2.0 * c4_x1 * c4_mpower(chartInstance, c4_x2) * c4_x4 * c4_z1;
  c4_d124 = 2.0 * c4_x1 * c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_z1 *
    c4_z3;
  c4_d125 = 2.0 * c4_x1;
  c4_d126 = 2.0 * c4_c_mpower(chartInstance, c4_x1) * c4_x3;
  c4_d127 = 2.0 * c4_x1 * c4_c_mpower(chartInstance, c4_x3) * c4_y1;
  c4_d128 = 2.0 * c4_x1 * c4_x3 * c4_c_mpower(chartInstance, c4_y1) * c4_y3;
  c4_d129 = 2.0 * c4_mpower(chartInstance, c4_x3);
  c4_d130 = 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y4);
  c4_d131 = 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z3);
  c4_d132 = c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1);
  c4_d133 = c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z1);
  c4_d134 = c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_z3);
  c4_d135 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x2) + 8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x3)) + 8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x4)) + 8.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_x3)) + 8.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_x4)) + 8.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
    c4_x4)) + 8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_y1)) + 12.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_y2)) + 12.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y1)) + 12.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_y3)) + 8.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y2)) + 12.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
    c4_y1)) + c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_y2))
    + 12.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y4))
    + c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_y1)) +
    12.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_y3)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_y1)) + 8.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y3)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2)) +
    c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_y2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_y1)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2)) +
    c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) +
    c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_y2)) + 8.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3)) + 8.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z1)) + 12.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2)) + 12.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z3)) + 8.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_z1)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z3)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z2)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4)) + 8.0 *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_z3)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z4)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z3)) + 12.0 *
                       c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_z2)) + c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1))
                     + 8.0 * c4_mpower(chartInstance, c4_y2) * c4_mpower
                     (chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x1) *
                    c4_b_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance,
    c4_x2) * c4_b_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance,
    c4_x1) * c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x3) *
                 c4_b_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower
                (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z4)) +
               c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_z3)) + c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_z1))
             + 12.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
              c4_z3)) + c4_b_mpower(chartInstance, c4_x3) * c4_mpower
            (chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_x4) *
           c4_mpower(chartInstance, c4_z1)) + 8.0 * c4_mpower(chartInstance,
           c4_y3) * c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance,
          c4_x2) * c4_b_mpower(chartInstance, c4_z4)) + c4_b_mpower
        (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
       (chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_z2)) + 8.0 *
      c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) +
     c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_z4);
  c4_d136 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d135 + c4_d134) + c4_b_mpower(chartInstance, c4_x3)
    * c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y1) *
    c4_b_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) *
    c4_b_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y1) *
    c4_b_mpower(chartInstance, c4_z3)) + 12.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y3) *
    c4_b_mpower(chartInstance, c4_z1)) + 8.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 12.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y1) *
    c4_b_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) *
    c4_b_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y3) *
    c4_b_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y4) *
    c4_b_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y2) *
    c4_b_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) *
    c4_b_mpower(chartInstance, c4_z2)) + 8.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y3) *
    c4_b_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) *
    c4_b_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + 8.0 * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + 8.0 * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z4)) + 8.0 * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + 32.0 * c4_mpower(chartInstance, c4_x1)) +
    32.0 * c4_mpower(chartInstance, c4_x2)) + 4.0 * c4_b_mpower(chartInstance,
    c4_x1)) + 32.0 * c4_mpower(chartInstance, c4_x3)) + 4.0 * c4_b_mpower
    (chartInstance, c4_x2)) + 32.0 * c4_mpower(chartInstance, c4_x4)) + 4.0 *
    c4_b_mpower(chartInstance, c4_x3)) + 4.0 * c4_b_mpower(chartInstance, c4_x4))
    + 32.0 * c4_mpower(chartInstance, c4_y1)) + 32.0 * c4_mpower(chartInstance,
    c4_y2)) + 4.0 * c4_b_mpower(chartInstance, c4_y1)) + 32.0 * c4_mpower
    (chartInstance, c4_y3)) + 4.0 * c4_b_mpower(chartInstance, c4_y2)) + 32.0 *
    c4_mpower(chartInstance, c4_y4)) + 4.0 * c4_b_mpower(chartInstance, c4_y3))
    + 4.0 * c4_b_mpower(chartInstance, c4_y4)) + 32.0 * c4_mpower(chartInstance,
    c4_z1)) + 32.0 * c4_mpower(chartInstance, c4_z2)) + 4.0 * c4_b_mpower
    (chartInstance, c4_z1)) + 32.0 * c4_mpower(chartInstance, c4_z3)) + 4.0 *
    c4_b_mpower(chartInstance, c4_z2)) + 32.0 * c4_mpower(chartInstance, c4_z4))
    + 4.0 * c4_b_mpower(chartInstance, c4_z3)) + 4.0 * c4_b_mpower(chartInstance,
    c4_z4)) + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
                       c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y4)) + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
                      c4_mpower(chartInstance, c4_y3)) + 2.0 * c4_mpower
                     (chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x4) *
                     c4_mpower(chartInstance, c4_y2)) + c4_mpower(chartInstance,
    c4_x2) * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2))
                   + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower
                   (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) +
                  2.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower
                  (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4)) +
                 2.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x4) * c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x2) *
                c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y3))
               + c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_x4) * c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance,
    c4_x3) * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1))
             + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x4)
             * c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance,
             c4_x2) * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
             c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower
           (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
          c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_x4) *
          c4_mpower(chartInstance, c4_y2)) + c4_mpower(chartInstance, c4_x2) *
         c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4)) +
        c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_x4) *
        c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x3) *
       c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4)) +
      c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x2) *
      c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_x1) *
     c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_z2);
  c4_d137 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d136 + c4_d133) + c4_d132 * c4_mpower(chartInstance,
    c4_y3)) + c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
                       c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
    c4_y1) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance,
    c4_x3) * c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3))
                     + 2.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower
                     (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z2)) +
                    2.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower
                    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) +
                   2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
                   (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z3)) +
                  2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
                  (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) +
                 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance,
    c4_x1) * c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z4))
               + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance,
    c4_x2) * c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3))
             + 2.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
              c4_y2) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
            (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4) * c4_mpower
            (chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
           c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z4)) +
          2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2)
          * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance,
          c4_x4) * c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance,
          c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
        (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
       c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y4) *
       c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
      c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
     c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4) *
     c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4);
  c4_d138 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d137 + c4_d131) + c4_d130 * c4_mpower(chartInstance,
    c4_z2)) + c4_d129 * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
    (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x1) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) + c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_x1) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) + c4_mpower
    (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) + c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_x1) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower
    (chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x2) * c4_mpower
    (chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) + c4_mpower
    (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower
    (chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3)) + c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower
    (chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
    (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x4) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
    (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_x3) * c4_mpower
    (chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x4) * c4_mpower
    (chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) + c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) + c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) + c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z3) * c4_mpower
    (chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3) * c4_mpower
    (chartInstance, c4_z4)) - 8.0 * c4_x1 * c4_x2 * c4_y1 * c4_y2) - 8.0 * c4_x1
    * c4_x3 * c4_y1 * c4_y3) - 8.0 * c4_x1 * c4_x4 * c4_y1 * c4_y4) - 8.0 *
                       c4_x2 * c4_x3 * c4_y2 * c4_y3) - 8.0 * c4_x2 * c4_x4 *
                      c4_y2 * c4_y4) - 8.0 * c4_x3 * c4_x4 * c4_y3 * c4_y4) -
                    8.0 * c4_x1 * c4_x2 * c4_z1 * c4_z2) - 8.0 * c4_x1 * c4_x3 *
                   c4_z1 * c4_z3) - 8.0 * c4_x1 * c4_x4 * c4_z1 * c4_z4) - 8.0 *
                 c4_x2 * c4_x3 * c4_z2 * c4_z3) - 8.0 * c4_x2 * c4_x4 * c4_z2 *
                c4_z4) - 8.0 * c4_x3 * c4_x4 * c4_z3 * c4_z4) - 8.0 * c4_y1 *
              c4_y2 * c4_z1 * c4_z2) - 8.0 * c4_y1 * c4_y3 * c4_z1 * c4_z3) -
            8.0 * c4_y1 * c4_y4 * c4_z1 * c4_z4) - 8.0 * c4_y2 * c4_y3 * c4_z2 *
           c4_z3) - 8.0 * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 8.0 * c4_y3 * c4_y4 *
         c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x2 * c4_y1 * c4_c_mpower
        (chartInstance, c4_y2)) - 2.0 * c4_x1 * c4_x2 * c4_c_mpower
       (chartInstance, c4_y1) * c4_y2) - 2.0 * c4_x1 * c4_c_mpower(chartInstance,
       c4_x2) * c4_y1 * c4_y2) - 2.0 * c4_c_mpower(chartInstance, c4_x1) * c4_x2
     * c4_y1 * c4_y2) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_c_mpower(chartInstance,
    c4_y3);
  c4_d139 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d138 - c4_d128) - c4_d127 * c4_y3) - c4_d126 *
    c4_y1 * c4_y3) - c4_d125 * c4_x4 * c4_y1 * c4_c_mpower(chartInstance, c4_y4))
    - 2.0 * c4_x1 * c4_x4 * c4_c_mpower(chartInstance, c4_y1) * c4_y4) - 2.0 *
    c4_x1 * c4_c_mpower(chartInstance, c4_x4) * c4_y1 * c4_y4) - 2.0 * c4_x2 *
    c4_x3 * c4_y2 * c4_c_mpower(chartInstance, c4_y3)) - 2.0 * c4_x2 * c4_x3 *
    c4_c_mpower(chartInstance, c4_y2) * c4_y3) - 2.0 * c4_x2 * c4_c_mpower
    (chartInstance, c4_x3) * c4_y2 * c4_y3) - 2.0 * c4_c_mpower(chartInstance,
    c4_x1) * c4_x4 * c4_y1 * c4_y4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) *
    c4_x3 * c4_y2 * c4_y3) - 2.0 * c4_x2 * c4_x4 * c4_y2 * c4_c_mpower
    (chartInstance, c4_y4)) - 2.0 * c4_x2 * c4_x4 * c4_c_mpower(chartInstance,
    c4_y2) * c4_y4) - 2.0 * c4_x2 * c4_c_mpower(chartInstance, c4_x4) * c4_y2 *
    c4_y4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) * c4_x4 * c4_y2 * c4_y4) -
    2.0 * c4_x3 * c4_x4 * c4_y3 * c4_c_mpower(chartInstance, c4_y4)) - 2.0 *
    c4_x3 * c4_x4 * c4_c_mpower(chartInstance, c4_y3) * c4_y4) - 2.0 * c4_x3 *
    c4_c_mpower(chartInstance, c4_x4) * c4_y3 * c4_y4) - 2.0 * c4_c_mpower
    (chartInstance, c4_x3) * c4_x4 * c4_y3 * c4_y4) - 2.0 * c4_x1 * c4_x2 *
    c4_z1 * c4_c_mpower(chartInstance, c4_z2)) - 2.0 * c4_x1 * c4_x2 *
    c4_c_mpower(chartInstance, c4_z1) * c4_z2) - 2.0 * c4_x1 * c4_c_mpower
    (chartInstance, c4_x2) * c4_z1 * c4_z2) - 2.0 * c4_c_mpower(chartInstance,
    c4_x1) * c4_x2 * c4_z1 * c4_z2) - 2.0 * c4_x1 * c4_x3 * c4_z1 * c4_c_mpower
    (chartInstance, c4_z3)) - 2.0 * c4_x1 * c4_x3 * c4_c_mpower(chartInstance,
    c4_z1) * c4_z3) - 2.0 * c4_x1 * c4_c_mpower(chartInstance, c4_x3) * c4_z1 *
    c4_z3) - 2.0 * c4_c_mpower(chartInstance, c4_x1) * c4_x3 * c4_z1 * c4_z3) -
    2.0 * c4_x1 * c4_x4 * c4_z1 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x1 * c4_x4 * c4_c_mpower(chartInstance, c4_z1) * c4_z4) - 2.0 * c4_x1 *
    c4_c_mpower(chartInstance, c4_x4) * c4_z1 * c4_z4) - 2.0 * c4_x2 * c4_x3 *
    c4_z2 * c4_c_mpower(chartInstance, c4_z3)) - 2.0 * c4_x2 * c4_x3 *
    c4_c_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 * c4_x2 * c4_c_mpower
    (chartInstance, c4_x3) * c4_z2 * c4_z3) - 2.0 * c4_c_mpower(chartInstance,
    c4_x1) * c4_x4 * c4_z1 * c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) *
    c4_x3 * c4_z2 * c4_z3) - 2.0 * c4_x2 * c4_x4 * c4_z2 * c4_c_mpower
    (chartInstance, c4_z4)) - 2.0 * c4_x2 * c4_x4 * c4_c_mpower(chartInstance,
    c4_z2) * c4_z4) - 2.0 * c4_x2 * c4_c_mpower(chartInstance, c4_x4) * c4_z2 *
    c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) * c4_x4 * c4_z2 * c4_z4) -
    2.0 * c4_x3 * c4_x4 * c4_z3 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x3 * c4_x4 * c4_c_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_x3 *
    c4_c_mpower(chartInstance, c4_x4) * c4_z3 * c4_z4) - 2.0 * c4_c_mpower
    (chartInstance, c4_x3) * c4_x4 * c4_z3 * c4_z4) - 2.0 * c4_y1 * c4_y2 *
    c4_z1 * c4_c_mpower(chartInstance, c4_z2)) - 2.0 * c4_y1 * c4_y2 *
    c4_c_mpower(chartInstance, c4_z1) * c4_z2) - 2.0 * c4_y1 * c4_c_mpower
    (chartInstance, c4_y2) * c4_z1 * c4_z2) - 2.0 * c4_c_mpower(chartInstance,
    c4_y1) * c4_y2 * c4_z1 * c4_z2) - 2.0 * c4_y1 * c4_y3 * c4_z1 * c4_c_mpower
    (chartInstance, c4_z3)) - 2.0 * c4_y1 * c4_y3 * c4_c_mpower(chartInstance,
    c4_z1) * c4_z3) - 2.0 * c4_y1 * c4_c_mpower(chartInstance, c4_y3) * c4_z1 *
    c4_z3) - 2.0 * c4_c_mpower(chartInstance, c4_y1) * c4_y3 * c4_z1 * c4_z3) -
    2.0 * c4_y1 * c4_y4 * c4_z1 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_y1 * c4_y4 * c4_c_mpower(chartInstance, c4_z1) * c4_z4) - 2.0 * c4_y1 *
    c4_c_mpower(chartInstance, c4_y4) * c4_z1 * c4_z4) - 2.0 * c4_y2 * c4_y3 *
    c4_z2 * c4_c_mpower(chartInstance, c4_z3)) - 2.0 * c4_y2 * c4_y3 *
    c4_c_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 * c4_y2 * c4_c_mpower
    (chartInstance, c4_y3) * c4_z2 * c4_z3) - 2.0 * c4_c_mpower(chartInstance,
    c4_y1) * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_y2) *
    c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_y2 * c4_y4 * c4_z2 * c4_c_mpower
    (chartInstance, c4_z4)) - 2.0 * c4_y2 * c4_y4 * c4_c_mpower(chartInstance,
    c4_z2) * c4_z4) - 2.0 * c4_y2 * c4_c_mpower(chartInstance, c4_y4) * c4_z2 *
    c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_y2) * c4_y4 * c4_z2 * c4_z4) -
    2.0 * c4_y3 * c4_y4 * c4_z3 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_y3 * c4_y4 * c4_c_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_y3 *
    c4_c_mpower(chartInstance, c4_y4) * c4_z3 * c4_z4) - 2.0 * c4_c_mpower
    (chartInstance, c4_y3) * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x2 *
    c4_mpower(chartInstance, c4_x3) * c4_y1 * c4_y2) - 2.0 * c4_x1 * c4_x2 *
    c4_mpower(chartInstance, c4_x4) * c4_y1 * c4_y2) - 2.0 * c4_x1 * c4_mpower
    (chartInstance, c4_x2) * c4_x3 * c4_y1 * c4_y3) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x2 * c4_x3 * c4_y2 * c4_y3) - 2.0 * c4_x1 *
    c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_y1 * c4_y3) - 2.0 * c4_x1 *
    c4_mpower(chartInstance, c4_x2) * c4_x4 * c4_y1 * c4_y4) - 2.0 * c4_x1 *
    c4_mpower(chartInstance, c4_x3) * c4_x4 * c4_y1 * c4_y4) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x2 * c4_x4 * c4_y2 * c4_y4) - 2.0 * c4_x2 *
    c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_y2 * c4_y3) - 2.0 * c4_x2 *
    c4_mpower(chartInstance, c4_x3) * c4_x4 * c4_y2 * c4_y4) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x3 * c4_x4 * c4_y3 * c4_y4) - 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_x3 * c4_x4 * c4_y3 * c4_y4) - 2.0 * c4_x1 *
    c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_y3)) - 2.0 * c4_x1 *
                       c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_y4))
                      - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_mpower(chartInstance,
    c4_y2) * c4_y3) - 2.0 * c4_x2 * c4_x3 * c4_mpower(chartInstance, c4_y1) *
                     c4_y2 * c4_y3) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3 *
                    c4_mpower(chartInstance, c4_y4)) - 2.0 * c4_x1 * c4_x4 *
                   c4_y1 * c4_mpower(chartInstance, c4_y2) * c4_y4) - 2.0 *
                  c4_x1 * c4_x4 * c4_y1 * c4_mpower(chartInstance, c4_y3) *
                  c4_y4) - 2.0 * c4_x2 * c4_x4 * c4_mpower(chartInstance, c4_y1)
                 * c4_y2 * c4_y4) - 2.0 * c4_x2 * c4_x3 * c4_y2 * c4_y3 *
                c4_mpower(chartInstance, c4_y4)) - 2.0 * c4_x2 * c4_x4 * c4_y2 *
               c4_mpower(chartInstance, c4_y3) * c4_y4) - 2.0 * c4_x3 * c4_x4 *
              c4_mpower(chartInstance, c4_y1) * c4_y3 * c4_y4) - 2.0 * c4_x3 *
             c4_x4 * c4_mpower(chartInstance, c4_y2) * c4_y3 * c4_y4) - 2.0 *
            c4_x1 * c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_z1)) -
           2.0 * c4_x1 * c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_z2))
          - 2.0 * c4_x1 * c4_x2 * c4_mpower(chartInstance, c4_x3) * c4_z1 *
          c4_z2) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3 * c4_mpower(chartInstance,
          c4_z1)) - 2.0 * c4_x1 * c4_x2 * c4_mpower(chartInstance, c4_x4) *
        c4_z1 * c4_z2) - 2.0 * c4_x1 * c4_mpower(chartInstance, c4_x2) * c4_x3 *
       c4_z1 * c4_z3) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3 * c4_mpower
      (chartInstance, c4_z3)) - 2.0 * c4_x1 * c4_x4 * c4_y1 * c4_y4 * c4_mpower
     (chartInstance, c4_z1)) - 2.0 * c4_mpower(chartInstance, c4_x1) * c4_x2 *
    c4_x3 * c4_z2 * c4_z3;
  c4_g_B =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d139 - c4_d124) - c4_d123 * c4_z4) - c4_d122 *
    c4_y3 * c4_mpower(chartInstance, c4_z2)) - c4_d121 * c4_x4 * c4_z1 * c4_z4)
    - c4_d120 * c4_x3 * c4_y2 * c4_y3 * c4_mpower(chartInstance, c4_z3)) - 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_x2 * c4_x4 * c4_z2 * c4_z4) - 2.0 *
    c4_x1 * c4_x4 * c4_y1 * c4_y4 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x2 * c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_z2 * c4_z3) - 2.0 *
    c4_x2 * c4_x4 * c4_y2 * c4_y4 * c4_mpower(chartInstance, c4_z2)) - 2.0 *
    c4_x2 * c4_mpower(chartInstance, c4_x3) * c4_x4 * c4_z2 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_x3 * c4_x4 * c4_z3 * c4_z4) - 2.0 *
    c4_x2 * c4_x4 * c4_y2 * c4_y4 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_x3 * c4_x4 * c4_z3 * c4_z4) - 2.0 *
    c4_x3 * c4_x4 * c4_y3 * c4_y4 * c4_mpower(chartInstance, c4_z3)) - 2.0 *
    c4_x3 * c4_x4 * c4_y3 * c4_y4 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x1 * c4_x2 * c4_mpower(chartInstance, c4_y1) * c4_z1 * c4_z2) - 2.0 *
    c4_x1 * c4_x2 * c4_mpower(chartInstance, c4_y2) * c4_z1 * c4_z2) - 2.0 *
    c4_x1 * c4_x3 * c4_mpower(chartInstance, c4_y1) * c4_z1 * c4_z3) - 2.0 *
    c4_x1 * c4_x3 * c4_mpower(chartInstance, c4_y3) * c4_z1 * c4_z3) - 2.0 *
    c4_x1 * c4_x4 * c4_mpower(chartInstance, c4_y1) * c4_z1 * c4_z4) - 2.0 *
    c4_x2 * c4_x3 * c4_mpower(chartInstance, c4_y2) * c4_z2 * c4_z3) - 2.0 *
    c4_x2 * c4_x3 * c4_mpower(chartInstance, c4_y3) * c4_z2 * c4_z3) - 2.0 *
    c4_x1 * c4_x4 * c4_mpower(chartInstance, c4_y4) * c4_z1 * c4_z4) - 2.0 *
    c4_x2 * c4_x4 * c4_mpower(chartInstance, c4_y2) * c4_z2 * c4_z4) - 2.0 *
    c4_x2 * c4_x4 * c4_mpower(chartInstance, c4_y4) * c4_z2 * c4_z4) - 2.0 *
    c4_x3 * c4_x4 * c4_mpower(chartInstance, c4_y3) * c4_z3 * c4_z4) - 2.0 *
    c4_x3 * c4_x4 * c4_mpower(chartInstance, c4_y4) * c4_z3 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_y1 * c4_y2 * c4_z1 * c4_z2) - 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_y1 * c4_y2 * c4_z1 * c4_z2) - 2.0 *
    c4_x1 * c4_x2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z3)) - 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_y1 * c4_y3 * c4_z1 * c4_z3) - 2.0 *
    c4_x1 * c4_x2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x1 * c4_x3 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 *
    c4_x2 * c4_x3 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z3) - 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_y1 * c4_y4 * c4_z1 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_y1 * c4_y3 * c4_z1 * c4_z3) - 2.0 *
    c4_x1 * c4_x3 * c4_z1 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x1 * c4_x4 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 2.0 *
    c4_x1 * c4_x4 * c4_z1 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 *
    c4_x2 * c4_x4 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 2.0 *
    c4_x2 * c4_x3 * c4_z2 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_y1 * c4_y4 * c4_z1 * c4_z4) - 2.0 *
    c4_x2 * c4_x4 * c4_z2 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 *
    c4_x3 * c4_x4 * c4_mpower(chartInstance, c4_z1) * c4_z3 * c4_z4) - 2.0 *
    c4_x3 * c4_x4 * c4_mpower(chartInstance, c4_z2) * c4_z3 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 *
    c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_y3) * c4_z1 * c4_z2) - 2.0 *
    c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_y4) * c4_z1 * c4_z2) - 2.0 *
    c4_y1 * c4_mpower(chartInstance, c4_y2) * c4_y3 * c4_z1 * c4_z3) - 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 2.0 *
    c4_y1 * c4_y3 * c4_mpower(chartInstance, c4_y4) * c4_z1 * c4_z3) - 2.0 *
    c4_y1 * c4_mpower(chartInstance, c4_y2) * c4_y4 * c4_z1 * c4_z4) - 2.0 *
    c4_y1 * c4_mpower(chartInstance, c4_y3) * c4_y4 * c4_z1 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 2.0 *
    c4_y2 * c4_y3 * c4_mpower(chartInstance, c4_y4) * c4_z2 * c4_z3) - 2.0 *
    c4_y2 * c4_mpower(chartInstance, c4_y3) * c4_y4 * c4_z2 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_y2) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 *
    c4_y1 * c4_y2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z3)) - 2.0 *
    c4_y1 * c4_y2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_y1 * c4_y3 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 *
    c4_y2 * c4_y3 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z3) - 2.0 *
    c4_y1 * c4_y3 * c4_z1 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_y1 * c4_y4 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z4) - 2.0 *
    c4_y1 * c4_y4 * c4_z1 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 *
    c4_y2 * c4_y4 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z4) - 2.0 *
    c4_y2 * c4_y3 * c4_z2 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_y2 * c4_y4 * c4_z2 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 *
    c4_y3 * c4_y4 * c4_mpower(chartInstance, c4_z1) * c4_z3 * c4_z4) - 2.0 *
    c4_y3 * c4_y4 * c4_mpower(chartInstance, c4_z2) * c4_z3 * c4_z4) - 2.0 *
    c4_x1 * c4_x2 * c4_y1 * c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_x1 * c4_x2 * c4_y2
    * c4_y3 * c4_z1 * c4_z3) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y2 * c4_z2 *
    c4_z3) - 2.0 * c4_x1 * c4_x3 * c4_y2 * c4_y3 * c4_z1 * c4_z2) - 2.0 * c4_x2 *
    c4_x3 * c4_y1 * c4_y2 * c4_z1 * c4_z3) - 2.0 * c4_x2 * c4_x3 * c4_y1 * c4_y3
                       * c4_z1 * c4_z2) - 2.0 * c4_x1 * c4_x2 * c4_y1 * c4_y4 *
                      c4_z2 * c4_z4) - 2.0 * c4_x1 * c4_x2 * c4_y2 * c4_y4 *
                     c4_z1 * c4_z4) - 2.0 * c4_x1 * c4_x4 * c4_y1 * c4_y2 *
                    c4_z2 * c4_z4) - 2.0 * c4_x1 * c4_x4 * c4_y2 * c4_y4 * c4_z1
                   * c4_z2) - 2.0 * c4_x2 * c4_x4 * c4_y1 * c4_y2 * c4_z1 *
                  c4_z4) - 2.0 * c4_x2 * c4_x4 * c4_y1 * c4_y4 * c4_z1 * c4_z2)
                - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y4 * c4_z3 * c4_z4) - 2.0 *
               c4_x1 * c4_x3 * c4_y3 * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_x1 *
              c4_x4 * c4_y1 * c4_y3 * c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x4 *
             c4_y3 * c4_y4 * c4_z1 * c4_z3) - 2.0 * c4_x3 * c4_x4 * c4_y1 *
            c4_y3 * c4_z1 * c4_z4) - 2.0 * c4_x3 * c4_x4 * c4_y1 * c4_y4 * c4_z1
           * c4_z3) - 2.0 * c4_x2 * c4_x3 * c4_y2 * c4_y4 * c4_z3 * c4_z4) - 2.0
         * c4_x2 * c4_x3 * c4_y3 * c4_y4 * c4_z2 * c4_z4) - 2.0 * c4_x2 * c4_x4 *
        c4_y2 * c4_y3 * c4_z3 * c4_z4) - 2.0 * c4_x2 * c4_x4 * c4_y3 * c4_y4 *
       c4_z2 * c4_z3) - 2.0 * c4_x3 * c4_x4 * c4_y2 * c4_y3 * c4_z2 * c4_z4) -
     2.0 * c4_x3 * c4_x4 * c4_y2 * c4_y4 * c4_z2 * c4_z3) + 64.0;
  c4_y_x = c4_g_A;
  c4_y_y = c4_g_B;
  c4_ab_x = c4_y_x;
  c4_ab_y = c4_y_y;
  c4_bb_x = c4_ab_x;
  c4_bb_y = c4_ab_y;
  c4_cb_y = c4_bb_x / c4_bb_y;
  c4_h_A = 4.0 * (((((((((((((((((((((((((((((((((((((((((((((((((((4.0 * c4_y1 *
    c4_z1 + 4.0 * c4_y2 * c4_z2) + 4.0 * c4_y3 * c4_z3) + 4.0 * c4_y4 * c4_z4) +
    c4_y1 * c4_c_mpower(chartInstance, c4_z1)) + c4_c_mpower(chartInstance,
    c4_y1) * c4_z1) + c4_y2 * c4_c_mpower(chartInstance, c4_z2)) + c4_c_mpower
    (chartInstance, c4_y2) * c4_z2) + c4_y3 * c4_c_mpower(chartInstance, c4_z3))
    + c4_c_mpower(chartInstance, c4_y3) * c4_z3) + c4_y4 * c4_c_mpower
    (chartInstance, c4_z4)) + c4_c_mpower(chartInstance, c4_y4) * c4_z4) +
    c4_mpower(chartInstance, c4_x1) * c4_y1 * c4_z1) + c4_mpower(chartInstance,
    c4_x2) * c4_y2 * c4_z2) + c4_mpower(chartInstance, c4_x3) * c4_y3 * c4_z3) +
    c4_mpower(chartInstance, c4_x4) * c4_y4 * c4_z4) + c4_y1 * c4_mpower
    (chartInstance, c4_y2) * c4_z1) + c4_y1 * c4_mpower(chartInstance, c4_y3) *
    c4_z1) + c4_mpower(chartInstance, c4_y1) * c4_y2 * c4_z2) + c4_y1 *
    c4_mpower(chartInstance, c4_y4) * c4_z1) + c4_y2 * c4_mpower(chartInstance,
    c4_y3) * c4_z2) + c4_mpower(chartInstance, c4_y1) * c4_y3 * c4_z3) + c4_y2 *
    c4_mpower(chartInstance, c4_y4) * c4_z2) + c4_mpower(chartInstance, c4_y2) *
    c4_y3 * c4_z3) + c4_mpower(chartInstance, c4_y1) * c4_y4 * c4_z4) + c4_y3 *
    c4_mpower(chartInstance, c4_y4) * c4_z3) + c4_mpower(chartInstance, c4_y2) *
    c4_y4 * c4_z4) + c4_mpower(chartInstance, c4_y3) * c4_y4 * c4_z4) + c4_y1 *
    c4_z1 * c4_mpower(chartInstance, c4_z2)) + c4_y1 * c4_z1 * c4_mpower
    (chartInstance, c4_z3)) + c4_y2 * c4_mpower(chartInstance, c4_z1) * c4_z2) +
    c4_y1 * c4_z1 * c4_mpower(chartInstance, c4_z4)) + c4_y2 * c4_z2 * c4_mpower
    (chartInstance, c4_z3)) + c4_y3 * c4_mpower(chartInstance, c4_z1) * c4_z3) +
    c4_y2 * c4_z2 * c4_mpower(chartInstance, c4_z4)) + c4_y3 * c4_mpower
    (chartInstance, c4_z2) * c4_z3) + c4_y4 * c4_mpower(chartInstance, c4_z1) *
    c4_z4) + c4_y3 * c4_z3 * c4_mpower(chartInstance, c4_z4)) + c4_y4 *
    c4_mpower(chartInstance, c4_z2) * c4_z4) + c4_y4 * c4_mpower(chartInstance,
    c4_z3) * c4_z4) + c4_x1 * c4_x2 * c4_y1 * c4_z2) + c4_x1 * c4_x2 * c4_y2 *
    c4_z1) + c4_x1 * c4_x3 * c4_y1 * c4_z3) + c4_x1 * c4_x3 * c4_y3 * c4_z1) +
    c4_x1 * c4_x4 * c4_y1 * c4_z4) + c4_x1 * c4_x4 * c4_y4 * c4_z1) + c4_x2 *
                       c4_x3 * c4_y2 * c4_z3) + c4_x2 * c4_x3 * c4_y3 * c4_z2) +
                     c4_x2 * c4_x4 * c4_y2 * c4_z4) + c4_x2 * c4_x4 * c4_y4 *
                    c4_z2) + c4_x3 * c4_x4 * c4_y3 * c4_z4) + c4_x3 * c4_x4 *
                  c4_y4 * c4_z3);
  c4_d140 = 2.0 * c4_x2;
  c4_d141 = 2.0 * c4_x1 * c4_mpower(chartInstance, c4_x3);
  c4_d142 = 2.0 * c4_x2 * c4_x3 * c4_y2;
  c4_d143 = 2.0 * c4_x1 * c4_mpower(chartInstance, c4_x2) * c4_x4 * c4_z1;
  c4_d144 = 2.0 * c4_x1 * c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_z1 *
    c4_z3;
  c4_d145 = 2.0 * c4_x1;
  c4_d146 = 2.0 * c4_c_mpower(chartInstance, c4_x1) * c4_x3;
  c4_d147 = 2.0 * c4_x1 * c4_c_mpower(chartInstance, c4_x3) * c4_y1;
  c4_d148 = 2.0 * c4_x1 * c4_x3 * c4_c_mpower(chartInstance, c4_y1) * c4_y3;
  c4_d149 = 2.0 * c4_mpower(chartInstance, c4_x3);
  c4_d150 = 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y4);
  c4_d151 = 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z3);
  c4_d152 = c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1);
  c4_d153 = c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z1);
  c4_d154 = c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_z3);
  c4_d155 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x2) + 8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x3)) + 8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x4)) + 8.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_x3)) + 8.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_x4)) + 8.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
    c4_x4)) + 8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_y1)) + 12.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_y2)) + 12.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y1)) + 12.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_y3)) + 8.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y2)) + 12.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
    c4_y1)) + c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_y2))
    + 12.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y4))
    + c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_y1)) +
    12.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_y3)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_y1)) + 8.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y3)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2)) +
    c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_y2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_y1)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2)) +
    c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) +
    c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_y2)) + 8.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3)) + 8.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z1)) + 12.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2)) + 12.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z3)) + 8.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_z1)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z3)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z2)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4)) + 8.0 *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_z3)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z4)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z3)) + 12.0 *
                       c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_z2)) + c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1))
                     + 8.0 * c4_mpower(chartInstance, c4_y2) * c4_mpower
                     (chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x1) *
                    c4_b_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance,
    c4_x2) * c4_b_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance,
    c4_x1) * c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x3) *
                 c4_b_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower
                (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z4)) +
               c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_z3)) + c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_z1))
             + 12.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
              c4_z3)) + c4_b_mpower(chartInstance, c4_x3) * c4_mpower
            (chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_x4) *
           c4_mpower(chartInstance, c4_z1)) + 8.0 * c4_mpower(chartInstance,
           c4_y3) * c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance,
          c4_x2) * c4_b_mpower(chartInstance, c4_z4)) + c4_b_mpower
        (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
       (chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_z2)) + 8.0 *
      c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) +
     c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_z4);
  c4_d156 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d155 + c4_d154) + c4_b_mpower(chartInstance, c4_x3)
    * c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y1) *
    c4_b_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) *
    c4_b_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y1) *
    c4_b_mpower(chartInstance, c4_z3)) + 12.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y3) *
    c4_b_mpower(chartInstance, c4_z1)) + 8.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 12.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y1) *
    c4_b_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) *
    c4_b_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y3) *
    c4_b_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y4) *
    c4_b_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y2) *
    c4_b_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) *
    c4_b_mpower(chartInstance, c4_z2)) + 8.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y3) *
    c4_b_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) *
    c4_b_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + 8.0 * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + 8.0 * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z4)) + 8.0 * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + 32.0 * c4_mpower(chartInstance, c4_x1)) +
    32.0 * c4_mpower(chartInstance, c4_x2)) + 4.0 * c4_b_mpower(chartInstance,
    c4_x1)) + 32.0 * c4_mpower(chartInstance, c4_x3)) + 4.0 * c4_b_mpower
    (chartInstance, c4_x2)) + 32.0 * c4_mpower(chartInstance, c4_x4)) + 4.0 *
    c4_b_mpower(chartInstance, c4_x3)) + 4.0 * c4_b_mpower(chartInstance, c4_x4))
    + 32.0 * c4_mpower(chartInstance, c4_y1)) + 32.0 * c4_mpower(chartInstance,
    c4_y2)) + 4.0 * c4_b_mpower(chartInstance, c4_y1)) + 32.0 * c4_mpower
    (chartInstance, c4_y3)) + 4.0 * c4_b_mpower(chartInstance, c4_y2)) + 32.0 *
    c4_mpower(chartInstance, c4_y4)) + 4.0 * c4_b_mpower(chartInstance, c4_y3))
    + 4.0 * c4_b_mpower(chartInstance, c4_y4)) + 32.0 * c4_mpower(chartInstance,
    c4_z1)) + 32.0 * c4_mpower(chartInstance, c4_z2)) + 4.0 * c4_b_mpower
    (chartInstance, c4_z1)) + 32.0 * c4_mpower(chartInstance, c4_z3)) + 4.0 *
    c4_b_mpower(chartInstance, c4_z2)) + 32.0 * c4_mpower(chartInstance, c4_z4))
    + 4.0 * c4_b_mpower(chartInstance, c4_z3)) + 4.0 * c4_b_mpower(chartInstance,
    c4_z4)) + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
                       c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y4)) + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
                      c4_mpower(chartInstance, c4_y3)) + 2.0 * c4_mpower
                     (chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x4) *
                     c4_mpower(chartInstance, c4_y2)) + c4_mpower(chartInstance,
    c4_x2) * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2))
                   + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower
                   (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) +
                  2.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower
                  (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4)) +
                 2.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x4) * c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x2) *
                c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y3))
               + c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_x4) * c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance,
    c4_x3) * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1))
             + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x4)
             * c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance,
             c4_x2) * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
             c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower
           (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
          c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_x4) *
          c4_mpower(chartInstance, c4_y2)) + c4_mpower(chartInstance, c4_x2) *
         c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4)) +
        c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_x4) *
        c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x3) *
       c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4)) +
      c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x2) *
      c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_x1) *
     c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_z2);
  c4_d157 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d156 + c4_d153) + c4_d152 * c4_mpower(chartInstance,
    c4_y3)) + c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
                       c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
    c4_y1) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance,
    c4_x3) * c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3))
                     + 2.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower
                     (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z2)) +
                    2.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower
                    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) +
                   2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
                   (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z3)) +
                  2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
                  (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) +
                 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance,
    c4_x1) * c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z4))
               + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance,
    c4_x2) * c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3))
             + 2.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
              c4_y2) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
            (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4) * c4_mpower
            (chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
           c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z4)) +
          2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2)
          * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance,
          c4_x4) * c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance,
          c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
        (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
       c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y4) *
       c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
      c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
     c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4) *
     c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4);
  c4_d158 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d157 + c4_d151) + c4_d150 * c4_mpower(chartInstance,
    c4_z2)) + c4_d149 * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
    (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x1) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) + c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_x1) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) + c4_mpower
    (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) + c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_x1) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower
    (chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x2) * c4_mpower
    (chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) + c4_mpower
    (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower
    (chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3)) + c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower
    (chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
    (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x4) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
    (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_x3) * c4_mpower
    (chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x4) * c4_mpower
    (chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) + c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) + c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) + c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z3) * c4_mpower
    (chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3) * c4_mpower
    (chartInstance, c4_z4)) - 8.0 * c4_x1 * c4_x2 * c4_y1 * c4_y2) - 8.0 * c4_x1
    * c4_x3 * c4_y1 * c4_y3) - 8.0 * c4_x1 * c4_x4 * c4_y1 * c4_y4) - 8.0 *
                       c4_x2 * c4_x3 * c4_y2 * c4_y3) - 8.0 * c4_x2 * c4_x4 *
                      c4_y2 * c4_y4) - 8.0 * c4_x3 * c4_x4 * c4_y3 * c4_y4) -
                    8.0 * c4_x1 * c4_x2 * c4_z1 * c4_z2) - 8.0 * c4_x1 * c4_x3 *
                   c4_z1 * c4_z3) - 8.0 * c4_x1 * c4_x4 * c4_z1 * c4_z4) - 8.0 *
                 c4_x2 * c4_x3 * c4_z2 * c4_z3) - 8.0 * c4_x2 * c4_x4 * c4_z2 *
                c4_z4) - 8.0 * c4_x3 * c4_x4 * c4_z3 * c4_z4) - 8.0 * c4_y1 *
              c4_y2 * c4_z1 * c4_z2) - 8.0 * c4_y1 * c4_y3 * c4_z1 * c4_z3) -
            8.0 * c4_y1 * c4_y4 * c4_z1 * c4_z4) - 8.0 * c4_y2 * c4_y3 * c4_z2 *
           c4_z3) - 8.0 * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 8.0 * c4_y3 * c4_y4 *
         c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x2 * c4_y1 * c4_c_mpower
        (chartInstance, c4_y2)) - 2.0 * c4_x1 * c4_x2 * c4_c_mpower
       (chartInstance, c4_y1) * c4_y2) - 2.0 * c4_x1 * c4_c_mpower(chartInstance,
       c4_x2) * c4_y1 * c4_y2) - 2.0 * c4_c_mpower(chartInstance, c4_x1) * c4_x2
     * c4_y1 * c4_y2) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_c_mpower(chartInstance,
    c4_y3);
  c4_d159 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d158 - c4_d148) - c4_d147 * c4_y3) - c4_d146 *
    c4_y1 * c4_y3) - c4_d145 * c4_x4 * c4_y1 * c4_c_mpower(chartInstance, c4_y4))
    - 2.0 * c4_x1 * c4_x4 * c4_c_mpower(chartInstance, c4_y1) * c4_y4) - 2.0 *
    c4_x1 * c4_c_mpower(chartInstance, c4_x4) * c4_y1 * c4_y4) - 2.0 * c4_x2 *
    c4_x3 * c4_y2 * c4_c_mpower(chartInstance, c4_y3)) - 2.0 * c4_x2 * c4_x3 *
    c4_c_mpower(chartInstance, c4_y2) * c4_y3) - 2.0 * c4_x2 * c4_c_mpower
    (chartInstance, c4_x3) * c4_y2 * c4_y3) - 2.0 * c4_c_mpower(chartInstance,
    c4_x1) * c4_x4 * c4_y1 * c4_y4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) *
    c4_x3 * c4_y2 * c4_y3) - 2.0 * c4_x2 * c4_x4 * c4_y2 * c4_c_mpower
    (chartInstance, c4_y4)) - 2.0 * c4_x2 * c4_x4 * c4_c_mpower(chartInstance,
    c4_y2) * c4_y4) - 2.0 * c4_x2 * c4_c_mpower(chartInstance, c4_x4) * c4_y2 *
    c4_y4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) * c4_x4 * c4_y2 * c4_y4) -
    2.0 * c4_x3 * c4_x4 * c4_y3 * c4_c_mpower(chartInstance, c4_y4)) - 2.0 *
    c4_x3 * c4_x4 * c4_c_mpower(chartInstance, c4_y3) * c4_y4) - 2.0 * c4_x3 *
    c4_c_mpower(chartInstance, c4_x4) * c4_y3 * c4_y4) - 2.0 * c4_c_mpower
    (chartInstance, c4_x3) * c4_x4 * c4_y3 * c4_y4) - 2.0 * c4_x1 * c4_x2 *
    c4_z1 * c4_c_mpower(chartInstance, c4_z2)) - 2.0 * c4_x1 * c4_x2 *
    c4_c_mpower(chartInstance, c4_z1) * c4_z2) - 2.0 * c4_x1 * c4_c_mpower
    (chartInstance, c4_x2) * c4_z1 * c4_z2) - 2.0 * c4_c_mpower(chartInstance,
    c4_x1) * c4_x2 * c4_z1 * c4_z2) - 2.0 * c4_x1 * c4_x3 * c4_z1 * c4_c_mpower
    (chartInstance, c4_z3)) - 2.0 * c4_x1 * c4_x3 * c4_c_mpower(chartInstance,
    c4_z1) * c4_z3) - 2.0 * c4_x1 * c4_c_mpower(chartInstance, c4_x3) * c4_z1 *
    c4_z3) - 2.0 * c4_c_mpower(chartInstance, c4_x1) * c4_x3 * c4_z1 * c4_z3) -
    2.0 * c4_x1 * c4_x4 * c4_z1 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x1 * c4_x4 * c4_c_mpower(chartInstance, c4_z1) * c4_z4) - 2.0 * c4_x1 *
    c4_c_mpower(chartInstance, c4_x4) * c4_z1 * c4_z4) - 2.0 * c4_x2 * c4_x3 *
    c4_z2 * c4_c_mpower(chartInstance, c4_z3)) - 2.0 * c4_x2 * c4_x3 *
    c4_c_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 * c4_x2 * c4_c_mpower
    (chartInstance, c4_x3) * c4_z2 * c4_z3) - 2.0 * c4_c_mpower(chartInstance,
    c4_x1) * c4_x4 * c4_z1 * c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) *
    c4_x3 * c4_z2 * c4_z3) - 2.0 * c4_x2 * c4_x4 * c4_z2 * c4_c_mpower
    (chartInstance, c4_z4)) - 2.0 * c4_x2 * c4_x4 * c4_c_mpower(chartInstance,
    c4_z2) * c4_z4) - 2.0 * c4_x2 * c4_c_mpower(chartInstance, c4_x4) * c4_z2 *
    c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) * c4_x4 * c4_z2 * c4_z4) -
    2.0 * c4_x3 * c4_x4 * c4_z3 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x3 * c4_x4 * c4_c_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_x3 *
    c4_c_mpower(chartInstance, c4_x4) * c4_z3 * c4_z4) - 2.0 * c4_c_mpower
    (chartInstance, c4_x3) * c4_x4 * c4_z3 * c4_z4) - 2.0 * c4_y1 * c4_y2 *
    c4_z1 * c4_c_mpower(chartInstance, c4_z2)) - 2.0 * c4_y1 * c4_y2 *
    c4_c_mpower(chartInstance, c4_z1) * c4_z2) - 2.0 * c4_y1 * c4_c_mpower
    (chartInstance, c4_y2) * c4_z1 * c4_z2) - 2.0 * c4_c_mpower(chartInstance,
    c4_y1) * c4_y2 * c4_z1 * c4_z2) - 2.0 * c4_y1 * c4_y3 * c4_z1 * c4_c_mpower
    (chartInstance, c4_z3)) - 2.0 * c4_y1 * c4_y3 * c4_c_mpower(chartInstance,
    c4_z1) * c4_z3) - 2.0 * c4_y1 * c4_c_mpower(chartInstance, c4_y3) * c4_z1 *
    c4_z3) - 2.0 * c4_c_mpower(chartInstance, c4_y1) * c4_y3 * c4_z1 * c4_z3) -
    2.0 * c4_y1 * c4_y4 * c4_z1 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_y1 * c4_y4 * c4_c_mpower(chartInstance, c4_z1) * c4_z4) - 2.0 * c4_y1 *
    c4_c_mpower(chartInstance, c4_y4) * c4_z1 * c4_z4) - 2.0 * c4_y2 * c4_y3 *
    c4_z2 * c4_c_mpower(chartInstance, c4_z3)) - 2.0 * c4_y2 * c4_y3 *
    c4_c_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 * c4_y2 * c4_c_mpower
    (chartInstance, c4_y3) * c4_z2 * c4_z3) - 2.0 * c4_c_mpower(chartInstance,
    c4_y1) * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_y2) *
    c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_y2 * c4_y4 * c4_z2 * c4_c_mpower
    (chartInstance, c4_z4)) - 2.0 * c4_y2 * c4_y4 * c4_c_mpower(chartInstance,
    c4_z2) * c4_z4) - 2.0 * c4_y2 * c4_c_mpower(chartInstance, c4_y4) * c4_z2 *
    c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_y2) * c4_y4 * c4_z2 * c4_z4) -
    2.0 * c4_y3 * c4_y4 * c4_z3 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_y3 * c4_y4 * c4_c_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_y3 *
    c4_c_mpower(chartInstance, c4_y4) * c4_z3 * c4_z4) - 2.0 * c4_c_mpower
    (chartInstance, c4_y3) * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x2 *
    c4_mpower(chartInstance, c4_x3) * c4_y1 * c4_y2) - 2.0 * c4_x1 * c4_x2 *
    c4_mpower(chartInstance, c4_x4) * c4_y1 * c4_y2) - 2.0 * c4_x1 * c4_mpower
    (chartInstance, c4_x2) * c4_x3 * c4_y1 * c4_y3) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x2 * c4_x3 * c4_y2 * c4_y3) - 2.0 * c4_x1 *
    c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_y1 * c4_y3) - 2.0 * c4_x1 *
    c4_mpower(chartInstance, c4_x2) * c4_x4 * c4_y1 * c4_y4) - 2.0 * c4_x1 *
    c4_mpower(chartInstance, c4_x3) * c4_x4 * c4_y1 * c4_y4) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x2 * c4_x4 * c4_y2 * c4_y4) - 2.0 * c4_x2 *
    c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_y2 * c4_y3) - 2.0 * c4_x2 *
    c4_mpower(chartInstance, c4_x3) * c4_x4 * c4_y2 * c4_y4) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x3 * c4_x4 * c4_y3 * c4_y4) - 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_x3 * c4_x4 * c4_y3 * c4_y4) - 2.0 * c4_x1 *
    c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_y3)) - 2.0 * c4_x1 *
                       c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_y4))
                      - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_mpower(chartInstance,
    c4_y2) * c4_y3) - 2.0 * c4_x2 * c4_x3 * c4_mpower(chartInstance, c4_y1) *
                     c4_y2 * c4_y3) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3 *
                    c4_mpower(chartInstance, c4_y4)) - 2.0 * c4_x1 * c4_x4 *
                   c4_y1 * c4_mpower(chartInstance, c4_y2) * c4_y4) - 2.0 *
                  c4_x1 * c4_x4 * c4_y1 * c4_mpower(chartInstance, c4_y3) *
                  c4_y4) - 2.0 * c4_x2 * c4_x4 * c4_mpower(chartInstance, c4_y1)
                 * c4_y2 * c4_y4) - 2.0 * c4_x2 * c4_x3 * c4_y2 * c4_y3 *
                c4_mpower(chartInstance, c4_y4)) - 2.0 * c4_x2 * c4_x4 * c4_y2 *
               c4_mpower(chartInstance, c4_y3) * c4_y4) - 2.0 * c4_x3 * c4_x4 *
              c4_mpower(chartInstance, c4_y1) * c4_y3 * c4_y4) - 2.0 * c4_x3 *
             c4_x4 * c4_mpower(chartInstance, c4_y2) * c4_y3 * c4_y4) - 2.0 *
            c4_x1 * c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_z1)) -
           2.0 * c4_x1 * c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_z2))
          - 2.0 * c4_x1 * c4_x2 * c4_mpower(chartInstance, c4_x3) * c4_z1 *
          c4_z2) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3 * c4_mpower(chartInstance,
          c4_z1)) - 2.0 * c4_x1 * c4_x2 * c4_mpower(chartInstance, c4_x4) *
        c4_z1 * c4_z2) - 2.0 * c4_x1 * c4_mpower(chartInstance, c4_x2) * c4_x3 *
       c4_z1 * c4_z3) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3 * c4_mpower
      (chartInstance, c4_z3)) - 2.0 * c4_x1 * c4_x4 * c4_y1 * c4_y4 * c4_mpower
     (chartInstance, c4_z1)) - 2.0 * c4_mpower(chartInstance, c4_x1) * c4_x2 *
    c4_x3 * c4_z2 * c4_z3;
  c4_h_B =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d159 - c4_d144) - c4_d143 * c4_z4) - c4_d142 *
    c4_y3 * c4_mpower(chartInstance, c4_z2)) - c4_d141 * c4_x4 * c4_z1 * c4_z4)
    - c4_d140 * c4_x3 * c4_y2 * c4_y3 * c4_mpower(chartInstance, c4_z3)) - 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_x2 * c4_x4 * c4_z2 * c4_z4) - 2.0 *
    c4_x1 * c4_x4 * c4_y1 * c4_y4 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x2 * c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_z2 * c4_z3) - 2.0 *
    c4_x2 * c4_x4 * c4_y2 * c4_y4 * c4_mpower(chartInstance, c4_z2)) - 2.0 *
    c4_x2 * c4_mpower(chartInstance, c4_x3) * c4_x4 * c4_z2 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_x3 * c4_x4 * c4_z3 * c4_z4) - 2.0 *
    c4_x2 * c4_x4 * c4_y2 * c4_y4 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_x3 * c4_x4 * c4_z3 * c4_z4) - 2.0 *
    c4_x3 * c4_x4 * c4_y3 * c4_y4 * c4_mpower(chartInstance, c4_z3)) - 2.0 *
    c4_x3 * c4_x4 * c4_y3 * c4_y4 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x1 * c4_x2 * c4_mpower(chartInstance, c4_y1) * c4_z1 * c4_z2) - 2.0 *
    c4_x1 * c4_x2 * c4_mpower(chartInstance, c4_y2) * c4_z1 * c4_z2) - 2.0 *
    c4_x1 * c4_x3 * c4_mpower(chartInstance, c4_y1) * c4_z1 * c4_z3) - 2.0 *
    c4_x1 * c4_x3 * c4_mpower(chartInstance, c4_y3) * c4_z1 * c4_z3) - 2.0 *
    c4_x1 * c4_x4 * c4_mpower(chartInstance, c4_y1) * c4_z1 * c4_z4) - 2.0 *
    c4_x2 * c4_x3 * c4_mpower(chartInstance, c4_y2) * c4_z2 * c4_z3) - 2.0 *
    c4_x2 * c4_x3 * c4_mpower(chartInstance, c4_y3) * c4_z2 * c4_z3) - 2.0 *
    c4_x1 * c4_x4 * c4_mpower(chartInstance, c4_y4) * c4_z1 * c4_z4) - 2.0 *
    c4_x2 * c4_x4 * c4_mpower(chartInstance, c4_y2) * c4_z2 * c4_z4) - 2.0 *
    c4_x2 * c4_x4 * c4_mpower(chartInstance, c4_y4) * c4_z2 * c4_z4) - 2.0 *
    c4_x3 * c4_x4 * c4_mpower(chartInstance, c4_y3) * c4_z3 * c4_z4) - 2.0 *
    c4_x3 * c4_x4 * c4_mpower(chartInstance, c4_y4) * c4_z3 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_y1 * c4_y2 * c4_z1 * c4_z2) - 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_y1 * c4_y2 * c4_z1 * c4_z2) - 2.0 *
    c4_x1 * c4_x2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z3)) - 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_y1 * c4_y3 * c4_z1 * c4_z3) - 2.0 *
    c4_x1 * c4_x2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x1 * c4_x3 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 *
    c4_x2 * c4_x3 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z3) - 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_y1 * c4_y4 * c4_z1 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_y1 * c4_y3 * c4_z1 * c4_z3) - 2.0 *
    c4_x1 * c4_x3 * c4_z1 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x1 * c4_x4 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 2.0 *
    c4_x1 * c4_x4 * c4_z1 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 *
    c4_x2 * c4_x4 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 2.0 *
    c4_x2 * c4_x3 * c4_z2 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_y1 * c4_y4 * c4_z1 * c4_z4) - 2.0 *
    c4_x2 * c4_x4 * c4_z2 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 *
    c4_x3 * c4_x4 * c4_mpower(chartInstance, c4_z1) * c4_z3 * c4_z4) - 2.0 *
    c4_x3 * c4_x4 * c4_mpower(chartInstance, c4_z2) * c4_z3 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 *
    c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_y3) * c4_z1 * c4_z2) - 2.0 *
    c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_y4) * c4_z1 * c4_z2) - 2.0 *
    c4_y1 * c4_mpower(chartInstance, c4_y2) * c4_y3 * c4_z1 * c4_z3) - 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 2.0 *
    c4_y1 * c4_y3 * c4_mpower(chartInstance, c4_y4) * c4_z1 * c4_z3) - 2.0 *
    c4_y1 * c4_mpower(chartInstance, c4_y2) * c4_y4 * c4_z1 * c4_z4) - 2.0 *
    c4_y1 * c4_mpower(chartInstance, c4_y3) * c4_y4 * c4_z1 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 2.0 *
    c4_y2 * c4_y3 * c4_mpower(chartInstance, c4_y4) * c4_z2 * c4_z3) - 2.0 *
    c4_y2 * c4_mpower(chartInstance, c4_y3) * c4_y4 * c4_z2 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_y2) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 *
    c4_y1 * c4_y2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z3)) - 2.0 *
    c4_y1 * c4_y2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_y1 * c4_y3 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 *
    c4_y2 * c4_y3 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z3) - 2.0 *
    c4_y1 * c4_y3 * c4_z1 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_y1 * c4_y4 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z4) - 2.0 *
    c4_y1 * c4_y4 * c4_z1 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 *
    c4_y2 * c4_y4 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z4) - 2.0 *
    c4_y2 * c4_y3 * c4_z2 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_y2 * c4_y4 * c4_z2 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 *
    c4_y3 * c4_y4 * c4_mpower(chartInstance, c4_z1) * c4_z3 * c4_z4) - 2.0 *
    c4_y3 * c4_y4 * c4_mpower(chartInstance, c4_z2) * c4_z3 * c4_z4) - 2.0 *
    c4_x1 * c4_x2 * c4_y1 * c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_x1 * c4_x2 * c4_y2
    * c4_y3 * c4_z1 * c4_z3) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y2 * c4_z2 *
    c4_z3) - 2.0 * c4_x1 * c4_x3 * c4_y2 * c4_y3 * c4_z1 * c4_z2) - 2.0 * c4_x2 *
    c4_x3 * c4_y1 * c4_y2 * c4_z1 * c4_z3) - 2.0 * c4_x2 * c4_x3 * c4_y1 * c4_y3
                       * c4_z1 * c4_z2) - 2.0 * c4_x1 * c4_x2 * c4_y1 * c4_y4 *
                      c4_z2 * c4_z4) - 2.0 * c4_x1 * c4_x2 * c4_y2 * c4_y4 *
                     c4_z1 * c4_z4) - 2.0 * c4_x1 * c4_x4 * c4_y1 * c4_y2 *
                    c4_z2 * c4_z4) - 2.0 * c4_x1 * c4_x4 * c4_y2 * c4_y4 * c4_z1
                   * c4_z2) - 2.0 * c4_x2 * c4_x4 * c4_y1 * c4_y2 * c4_z1 *
                  c4_z4) - 2.0 * c4_x2 * c4_x4 * c4_y1 * c4_y4 * c4_z1 * c4_z2)
                - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y4 * c4_z3 * c4_z4) - 2.0 *
               c4_x1 * c4_x3 * c4_y3 * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_x1 *
              c4_x4 * c4_y1 * c4_y3 * c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x4 *
             c4_y3 * c4_y4 * c4_z1 * c4_z3) - 2.0 * c4_x3 * c4_x4 * c4_y1 *
            c4_y3 * c4_z1 * c4_z4) - 2.0 * c4_x3 * c4_x4 * c4_y1 * c4_y4 * c4_z1
           * c4_z3) - 2.0 * c4_x2 * c4_x3 * c4_y2 * c4_y4 * c4_z3 * c4_z4) - 2.0
         * c4_x2 * c4_x3 * c4_y3 * c4_y4 * c4_z2 * c4_z4) - 2.0 * c4_x2 * c4_x4 *
        c4_y2 * c4_y3 * c4_z3 * c4_z4) - 2.0 * c4_x2 * c4_x4 * c4_y3 * c4_y4 *
       c4_z2 * c4_z3) - 2.0 * c4_x3 * c4_x4 * c4_y2 * c4_y3 * c4_z2 * c4_z4) -
     2.0 * c4_x3 * c4_x4 * c4_y2 * c4_y4 * c4_z2 * c4_z3) + 64.0;
  c4_cb_x = c4_h_A;
  c4_db_y = c4_h_B;
  c4_db_x = c4_cb_x;
  c4_eb_y = c4_db_y;
  c4_eb_x = c4_db_x;
  c4_fb_y = c4_eb_y;
  c4_gb_y = c4_eb_x / c4_fb_y;
  c4_i_A = 4.0 *
    ((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((c4_mpower
    (chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y2) + c4_mpower
    (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1)) + c4_mpower
    (chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3)) + c4_mpower
    (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1)) + c4_mpower
    (chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y4)) + c4_mpower
    (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3)) + c4_mpower
    (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2)) + c4_mpower
    (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) + c4_mpower
    (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y4)) + c4_mpower
    (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2)) + c4_mpower
    (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4)) + c4_mpower
    (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3)) + c4_mpower
    (chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z1)) + c4_mpower
    (chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z2)) + c4_mpower
    (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1)) + c4_mpower
    (chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z3)) + c4_mpower
    (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z2)) + c4_mpower
    (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1)) + c4_mpower
    (chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z3)) + c4_mpower
    (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z2)) + c4_mpower
    (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1)) + c4_mpower
    (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z3)) + c4_mpower
    (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) + c4_mpower
    (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z3)) + c4_mpower
    (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1)) + c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2)) + c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z1)) + c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z3)) + c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) + c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1)) + c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3)) + c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z2)) + c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z3)) + c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) + c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3)) + c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
    (chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
    (chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) + 4.0 * c4_mpower
    (chartInstance, c4_x1)) + 4.0 * c4_mpower(chartInstance, c4_x2)) + 4.0 *
    c4_mpower(chartInstance, c4_x3)) + 4.0 * c4_mpower(chartInstance, c4_x4)) +
                       4.0 * c4_mpower(chartInstance, c4_y1)) + 4.0 * c4_mpower
                      (chartInstance, c4_y2)) + 4.0 * c4_mpower(chartInstance,
    c4_y3)) + 4.0 * c4_mpower(chartInstance, c4_y4)) + 8.0 * c4_mpower
                   (chartInstance, c4_z1)) + 8.0 * c4_mpower(chartInstance,
    c4_z2)) + c4_b_mpower(chartInstance, c4_z1)) + 8.0 * c4_mpower(chartInstance,
    c4_z3)) + c4_b_mpower(chartInstance, c4_z2)) + 8.0 * c4_mpower(chartInstance,
    c4_z4)) + c4_b_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance,
             c4_z4)) - 2.0 * c4_x1 * c4_x2 * c4_y1 * c4_y2) - 2.0 * c4_x1 *
          c4_x3 * c4_y1 * c4_y3) - 2.0 * c4_x1 * c4_x4 * c4_y1 * c4_y4) - 2.0 *
        c4_x2 * c4_x3 * c4_y2 * c4_y3) - 2.0 * c4_x2 * c4_x4 * c4_y2 * c4_y4) -
      2.0 * c4_x3 * c4_x4 * c4_y3 * c4_y4) + 16.0);
  c4_d160 = 2.0 * c4_x2;
  c4_d161 = 2.0 * c4_x1 * c4_mpower(chartInstance, c4_x3);
  c4_d162 = 2.0 * c4_x2 * c4_x3 * c4_y2;
  c4_d163 = 2.0 * c4_x1 * c4_mpower(chartInstance, c4_x2) * c4_x4 * c4_z1;
  c4_d164 = 2.0 * c4_x1 * c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_z1 *
    c4_z3;
  c4_d165 = 2.0 * c4_x1;
  c4_d166 = 2.0 * c4_c_mpower(chartInstance, c4_x1) * c4_x3;
  c4_d167 = 2.0 * c4_x1 * c4_c_mpower(chartInstance, c4_x3) * c4_y1;
  c4_d168 = 2.0 * c4_x1 * c4_x3 * c4_c_mpower(chartInstance, c4_y1) * c4_y3;
  c4_d169 = 2.0 * c4_mpower(chartInstance, c4_x3);
  c4_d170 = 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y4);
  c4_d171 = 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z3);
  c4_d172 = c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1);
  c4_d173 = c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z1);
  c4_d174 = c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_z3);
  c4_d175 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x2) + 8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x3)) + 8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x4)) + 8.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_x3)) + 8.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_x4)) + 8.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
    c4_x4)) + 8.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_y1)) + 12.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_y2)) + 12.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y1)) + 12.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_y3)) + 8.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y2)) + 12.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
    c4_y1)) + c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_y2))
    + 12.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y4))
    + c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_y1)) +
    12.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_y3)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_y1)) + 8.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y3)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2)) +
    c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_y2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_y1)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2)) +
    c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) +
    c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_y2)) + 8.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_y3)) +
    c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4)) +
    c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3)) + 8.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z1)) + 12.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2)) + 12.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z3)) + 8.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x2) * c4_b_mpower(chartInstance, c4_z1)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z3)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z2)) + 12.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z2)) +
    c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1)) + 12.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4)) + 8.0 *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3)) +
    c4_mpower(chartInstance, c4_x1) * c4_b_mpower(chartInstance, c4_z3)) + 12.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z4)) +
    c4_b_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z3)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_z1)) + 8.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z3)) + 12.0 *
                       c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_z2)) + c4_b_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1))
                     + 8.0 * c4_mpower(chartInstance, c4_y2) * c4_mpower
                     (chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x1) *
                    c4_b_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance,
    c4_x2) * c4_b_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance,
    c4_x1) * c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x3) *
                 c4_b_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower
                (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z4)) +
               c4_b_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_z3)) + c4_mpower(chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_z1))
             + 12.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
              c4_z3)) + c4_b_mpower(chartInstance, c4_x3) * c4_mpower
            (chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_x4) *
           c4_mpower(chartInstance, c4_z1)) + 8.0 * c4_mpower(chartInstance,
           c4_y3) * c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance,
          c4_x2) * c4_b_mpower(chartInstance, c4_z4)) + c4_b_mpower
        (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
       (chartInstance, c4_x4) * c4_b_mpower(chartInstance, c4_z2)) + 8.0 *
      c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) +
     c4_b_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_x3) * c4_b_mpower(chartInstance, c4_z4);
  c4_d176 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d175 + c4_d174) + c4_b_mpower(chartInstance, c4_x3)
    * c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y1) *
    c4_b_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) *
    c4_b_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y1) *
    c4_b_mpower(chartInstance, c4_z3)) + 12.0 * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y3) *
    c4_b_mpower(chartInstance, c4_z1)) + 8.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 12.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y1) *
    c4_b_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) *
    c4_b_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y3) *
    c4_b_mpower(chartInstance, c4_z2)) + 12.0 * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y4) *
    c4_b_mpower(chartInstance, c4_z1)) + 12.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + c4_b_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_y2) *
    c4_b_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) *
    c4_b_mpower(chartInstance, c4_z2)) + 8.0 * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y3) *
    c4_b_mpower(chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) *
    c4_b_mpower(chartInstance, c4_z3)) + c4_b_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z4)) + c4_b_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z2)) + 8.0 * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_z1) *
    c4_mpower(chartInstance, c4_z4)) + 8.0 * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z3)) + 8.0 * c4_mpower(chartInstance, c4_z2) *
    c4_mpower(chartInstance, c4_z4)) + 8.0 * c4_mpower(chartInstance, c4_z3) *
    c4_mpower(chartInstance, c4_z4)) + 32.0 * c4_mpower(chartInstance, c4_x1)) +
    32.0 * c4_mpower(chartInstance, c4_x2)) + 4.0 * c4_b_mpower(chartInstance,
    c4_x1)) + 32.0 * c4_mpower(chartInstance, c4_x3)) + 4.0 * c4_b_mpower
    (chartInstance, c4_x2)) + 32.0 * c4_mpower(chartInstance, c4_x4)) + 4.0 *
    c4_b_mpower(chartInstance, c4_x3)) + 4.0 * c4_b_mpower(chartInstance, c4_x4))
    + 32.0 * c4_mpower(chartInstance, c4_y1)) + 32.0 * c4_mpower(chartInstance,
    c4_y2)) + 4.0 * c4_b_mpower(chartInstance, c4_y1)) + 32.0 * c4_mpower
    (chartInstance, c4_y3)) + 4.0 * c4_b_mpower(chartInstance, c4_y2)) + 32.0 *
    c4_mpower(chartInstance, c4_y4)) + 4.0 * c4_b_mpower(chartInstance, c4_y3))
    + 4.0 * c4_b_mpower(chartInstance, c4_y4)) + 32.0 * c4_mpower(chartInstance,
    c4_z1)) + 32.0 * c4_mpower(chartInstance, c4_z2)) + 4.0 * c4_b_mpower
    (chartInstance, c4_z1)) + 32.0 * c4_mpower(chartInstance, c4_z3)) + 4.0 *
    c4_b_mpower(chartInstance, c4_z2)) + 32.0 * c4_mpower(chartInstance, c4_z4))
    + 4.0 * c4_b_mpower(chartInstance, c4_z3)) + 4.0 * c4_b_mpower(chartInstance,
    c4_z4)) + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
                       c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y4)) + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
                      c4_mpower(chartInstance, c4_y3)) + 2.0 * c4_mpower
                     (chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x4) *
                     c4_mpower(chartInstance, c4_y2)) + c4_mpower(chartInstance,
    c4_x2) * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2))
                   + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower
                   (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1)) +
                  2.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower
                  (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4)) +
                 2.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance,
    c4_x4) * c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x2) *
                c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y3))
               + c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_x4) * c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance,
    c4_x3) * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1))
             + c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x4)
             * c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance,
             c4_x2) * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
             c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower
           (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
          c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_x4) *
          c4_mpower(chartInstance, c4_y2)) + c4_mpower(chartInstance, c4_x2) *
         c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4)) +
        c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_x4) *
        c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x3) *
       c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4)) +
      c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x2) *
      c4_mpower(chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_x1) *
     c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_z2);
  c4_d177 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d176 + c4_d173) + c4_d172 * c4_mpower(chartInstance,
    c4_y3)) + c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) +
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y3)) + c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_y4)) + c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z4)) +
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_y4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y1) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2) *
    c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x1) *
    c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_mpower(chartInstance, c4_y4) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y3) *
    c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x2) *
    c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) + 2.0 *
                       c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
    c4_y1) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance,
    c4_x3) * c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3))
                     + 2.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower
                     (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z2)) +
                    2.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower
                    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) +
                   2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
                   (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z3)) +
                  2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
                  (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) +
                 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance,
    c4_x1) * c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z4))
               + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance,
    c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance,
    c4_x2) * c4_mpower(chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3))
             + 2.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance,
              c4_y2) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
            (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4) * c4_mpower
            (chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
           c4_mpower(chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z4)) +
          2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y2)
          * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance,
          c4_x4) * c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance,
          c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
        (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 *
       c4_mpower(chartInstance, c4_x2) * c4_mpower(chartInstance, c4_y4) *
       c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x3) *
      c4_mpower(chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 *
     c4_mpower(chartInstance, c4_x3) * c4_mpower(chartInstance, c4_y4) *
     c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x4) *
    c4_mpower(chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z4);
  c4_d178 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d177 + c4_d171) + c4_d170 * c4_mpower(chartInstance,
    c4_z2)) + c4_d169 * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
    (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x1) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) + c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_x1) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) + c4_mpower
    (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2)) + c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z1)) + c4_mpower(chartInstance, c4_x1) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1)) + 2.0 * c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower
    (chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x2) * c4_mpower
    (chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) + c4_mpower
    (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x1) * c4_mpower
    (chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_x2) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_x3) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_x4) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3)) + c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z1)) + 2.0 * c4_mpower(chartInstance, c4_x2) * c4_mpower
    (chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
    (chartInstance, c4_x3) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_x4) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
    (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z4)) + 2.0 * c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z2)) + c4_mpower(chartInstance, c4_x3) * c4_mpower
    (chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_x4) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_x4) * c4_mpower
    (chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) + c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) + c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z2)) + 2.0 * c4_mpower
    (chartInstance, c4_y1) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y2) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z3)) + c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z2)) + 2.0 * c4_mpower(chartInstance, c4_y1) * c4_mpower
    (chartInstance, c4_z3) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z2) * c4_mpower
    (chartInstance, c4_z3)) + 2.0 * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z1) * c4_mpower(chartInstance, c4_z3)) + 2.0 * c4_mpower
    (chartInstance, c4_y2) * c4_mpower(chartInstance, c4_z3) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y3) * c4_mpower
    (chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z1) * c4_mpower
    (chartInstance, c4_z4)) + 2.0 * c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z3)) + c4_mpower
    (chartInstance, c4_y3) * c4_mpower(chartInstance, c4_z3) * c4_mpower
    (chartInstance, c4_z4)) + c4_mpower(chartInstance, c4_y4) * c4_mpower
    (chartInstance, c4_z2) * c4_mpower(chartInstance, c4_z4)) + c4_mpower
    (chartInstance, c4_y4) * c4_mpower(chartInstance, c4_z3) * c4_mpower
    (chartInstance, c4_z4)) - 8.0 * c4_x1 * c4_x2 * c4_y1 * c4_y2) - 8.0 * c4_x1
    * c4_x3 * c4_y1 * c4_y3) - 8.0 * c4_x1 * c4_x4 * c4_y1 * c4_y4) - 8.0 *
                       c4_x2 * c4_x3 * c4_y2 * c4_y3) - 8.0 * c4_x2 * c4_x4 *
                      c4_y2 * c4_y4) - 8.0 * c4_x3 * c4_x4 * c4_y3 * c4_y4) -
                    8.0 * c4_x1 * c4_x2 * c4_z1 * c4_z2) - 8.0 * c4_x1 * c4_x3 *
                   c4_z1 * c4_z3) - 8.0 * c4_x1 * c4_x4 * c4_z1 * c4_z4) - 8.0 *
                 c4_x2 * c4_x3 * c4_z2 * c4_z3) - 8.0 * c4_x2 * c4_x4 * c4_z2 *
                c4_z4) - 8.0 * c4_x3 * c4_x4 * c4_z3 * c4_z4) - 8.0 * c4_y1 *
              c4_y2 * c4_z1 * c4_z2) - 8.0 * c4_y1 * c4_y3 * c4_z1 * c4_z3) -
            8.0 * c4_y1 * c4_y4 * c4_z1 * c4_z4) - 8.0 * c4_y2 * c4_y3 * c4_z2 *
           c4_z3) - 8.0 * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 8.0 * c4_y3 * c4_y4 *
         c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x2 * c4_y1 * c4_c_mpower
        (chartInstance, c4_y2)) - 2.0 * c4_x1 * c4_x2 * c4_c_mpower
       (chartInstance, c4_y1) * c4_y2) - 2.0 * c4_x1 * c4_c_mpower(chartInstance,
       c4_x2) * c4_y1 * c4_y2) - 2.0 * c4_c_mpower(chartInstance, c4_x1) * c4_x2
     * c4_y1 * c4_y2) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_c_mpower(chartInstance,
    c4_y3);
  c4_d179 =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d178 - c4_d168) - c4_d167 * c4_y3) - c4_d166 *
    c4_y1 * c4_y3) - c4_d165 * c4_x4 * c4_y1 * c4_c_mpower(chartInstance, c4_y4))
    - 2.0 * c4_x1 * c4_x4 * c4_c_mpower(chartInstance, c4_y1) * c4_y4) - 2.0 *
    c4_x1 * c4_c_mpower(chartInstance, c4_x4) * c4_y1 * c4_y4) - 2.0 * c4_x2 *
    c4_x3 * c4_y2 * c4_c_mpower(chartInstance, c4_y3)) - 2.0 * c4_x2 * c4_x3 *
    c4_c_mpower(chartInstance, c4_y2) * c4_y3) - 2.0 * c4_x2 * c4_c_mpower
    (chartInstance, c4_x3) * c4_y2 * c4_y3) - 2.0 * c4_c_mpower(chartInstance,
    c4_x1) * c4_x4 * c4_y1 * c4_y4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) *
    c4_x3 * c4_y2 * c4_y3) - 2.0 * c4_x2 * c4_x4 * c4_y2 * c4_c_mpower
    (chartInstance, c4_y4)) - 2.0 * c4_x2 * c4_x4 * c4_c_mpower(chartInstance,
    c4_y2) * c4_y4) - 2.0 * c4_x2 * c4_c_mpower(chartInstance, c4_x4) * c4_y2 *
    c4_y4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) * c4_x4 * c4_y2 * c4_y4) -
    2.0 * c4_x3 * c4_x4 * c4_y3 * c4_c_mpower(chartInstance, c4_y4)) - 2.0 *
    c4_x3 * c4_x4 * c4_c_mpower(chartInstance, c4_y3) * c4_y4) - 2.0 * c4_x3 *
    c4_c_mpower(chartInstance, c4_x4) * c4_y3 * c4_y4) - 2.0 * c4_c_mpower
    (chartInstance, c4_x3) * c4_x4 * c4_y3 * c4_y4) - 2.0 * c4_x1 * c4_x2 *
    c4_z1 * c4_c_mpower(chartInstance, c4_z2)) - 2.0 * c4_x1 * c4_x2 *
    c4_c_mpower(chartInstance, c4_z1) * c4_z2) - 2.0 * c4_x1 * c4_c_mpower
    (chartInstance, c4_x2) * c4_z1 * c4_z2) - 2.0 * c4_c_mpower(chartInstance,
    c4_x1) * c4_x2 * c4_z1 * c4_z2) - 2.0 * c4_x1 * c4_x3 * c4_z1 * c4_c_mpower
    (chartInstance, c4_z3)) - 2.0 * c4_x1 * c4_x3 * c4_c_mpower(chartInstance,
    c4_z1) * c4_z3) - 2.0 * c4_x1 * c4_c_mpower(chartInstance, c4_x3) * c4_z1 *
    c4_z3) - 2.0 * c4_c_mpower(chartInstance, c4_x1) * c4_x3 * c4_z1 * c4_z3) -
    2.0 * c4_x1 * c4_x4 * c4_z1 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x1 * c4_x4 * c4_c_mpower(chartInstance, c4_z1) * c4_z4) - 2.0 * c4_x1 *
    c4_c_mpower(chartInstance, c4_x4) * c4_z1 * c4_z4) - 2.0 * c4_x2 * c4_x3 *
    c4_z2 * c4_c_mpower(chartInstance, c4_z3)) - 2.0 * c4_x2 * c4_x3 *
    c4_c_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 * c4_x2 * c4_c_mpower
    (chartInstance, c4_x3) * c4_z2 * c4_z3) - 2.0 * c4_c_mpower(chartInstance,
    c4_x1) * c4_x4 * c4_z1 * c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) *
    c4_x3 * c4_z2 * c4_z3) - 2.0 * c4_x2 * c4_x4 * c4_z2 * c4_c_mpower
    (chartInstance, c4_z4)) - 2.0 * c4_x2 * c4_x4 * c4_c_mpower(chartInstance,
    c4_z2) * c4_z4) - 2.0 * c4_x2 * c4_c_mpower(chartInstance, c4_x4) * c4_z2 *
    c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_x2) * c4_x4 * c4_z2 * c4_z4) -
    2.0 * c4_x3 * c4_x4 * c4_z3 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x3 * c4_x4 * c4_c_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_x3 *
    c4_c_mpower(chartInstance, c4_x4) * c4_z3 * c4_z4) - 2.0 * c4_c_mpower
    (chartInstance, c4_x3) * c4_x4 * c4_z3 * c4_z4) - 2.0 * c4_y1 * c4_y2 *
    c4_z1 * c4_c_mpower(chartInstance, c4_z2)) - 2.0 * c4_y1 * c4_y2 *
    c4_c_mpower(chartInstance, c4_z1) * c4_z2) - 2.0 * c4_y1 * c4_c_mpower
    (chartInstance, c4_y2) * c4_z1 * c4_z2) - 2.0 * c4_c_mpower(chartInstance,
    c4_y1) * c4_y2 * c4_z1 * c4_z2) - 2.0 * c4_y1 * c4_y3 * c4_z1 * c4_c_mpower
    (chartInstance, c4_z3)) - 2.0 * c4_y1 * c4_y3 * c4_c_mpower(chartInstance,
    c4_z1) * c4_z3) - 2.0 * c4_y1 * c4_c_mpower(chartInstance, c4_y3) * c4_z1 *
    c4_z3) - 2.0 * c4_c_mpower(chartInstance, c4_y1) * c4_y3 * c4_z1 * c4_z3) -
    2.0 * c4_y1 * c4_y4 * c4_z1 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_y1 * c4_y4 * c4_c_mpower(chartInstance, c4_z1) * c4_z4) - 2.0 * c4_y1 *
    c4_c_mpower(chartInstance, c4_y4) * c4_z1 * c4_z4) - 2.0 * c4_y2 * c4_y3 *
    c4_z2 * c4_c_mpower(chartInstance, c4_z3)) - 2.0 * c4_y2 * c4_y3 *
    c4_c_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 * c4_y2 * c4_c_mpower
    (chartInstance, c4_y3) * c4_z2 * c4_z3) - 2.0 * c4_c_mpower(chartInstance,
    c4_y1) * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_y2) *
    c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_y2 * c4_y4 * c4_z2 * c4_c_mpower
    (chartInstance, c4_z4)) - 2.0 * c4_y2 * c4_y4 * c4_c_mpower(chartInstance,
    c4_z2) * c4_z4) - 2.0 * c4_y2 * c4_c_mpower(chartInstance, c4_y4) * c4_z2 *
    c4_z4) - 2.0 * c4_c_mpower(chartInstance, c4_y2) * c4_y4 * c4_z2 * c4_z4) -
    2.0 * c4_y3 * c4_y4 * c4_z3 * c4_c_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_y3 * c4_y4 * c4_c_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 * c4_y3 *
    c4_c_mpower(chartInstance, c4_y4) * c4_z3 * c4_z4) - 2.0 * c4_c_mpower
    (chartInstance, c4_y3) * c4_y4 * c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x2 *
    c4_mpower(chartInstance, c4_x3) * c4_y1 * c4_y2) - 2.0 * c4_x1 * c4_x2 *
    c4_mpower(chartInstance, c4_x4) * c4_y1 * c4_y2) - 2.0 * c4_x1 * c4_mpower
    (chartInstance, c4_x2) * c4_x3 * c4_y1 * c4_y3) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x2 * c4_x3 * c4_y2 * c4_y3) - 2.0 * c4_x1 *
    c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_y1 * c4_y3) - 2.0 * c4_x1 *
    c4_mpower(chartInstance, c4_x2) * c4_x4 * c4_y1 * c4_y4) - 2.0 * c4_x1 *
    c4_mpower(chartInstance, c4_x3) * c4_x4 * c4_y1 * c4_y4) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x2 * c4_x4 * c4_y2 * c4_y4) - 2.0 * c4_x2 *
    c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_y2 * c4_y3) - 2.0 * c4_x2 *
    c4_mpower(chartInstance, c4_x3) * c4_x4 * c4_y2 * c4_y4) - 2.0 * c4_mpower
    (chartInstance, c4_x1) * c4_x3 * c4_x4 * c4_y3 * c4_y4) - 2.0 * c4_mpower
    (chartInstance, c4_x2) * c4_x3 * c4_x4 * c4_y3 * c4_y4) - 2.0 * c4_x1 *
    c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_y3)) - 2.0 * c4_x1 *
                       c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_y4))
                      - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_mpower(chartInstance,
    c4_y2) * c4_y3) - 2.0 * c4_x2 * c4_x3 * c4_mpower(chartInstance, c4_y1) *
                     c4_y2 * c4_y3) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3 *
                    c4_mpower(chartInstance, c4_y4)) - 2.0 * c4_x1 * c4_x4 *
                   c4_y1 * c4_mpower(chartInstance, c4_y2) * c4_y4) - 2.0 *
                  c4_x1 * c4_x4 * c4_y1 * c4_mpower(chartInstance, c4_y3) *
                  c4_y4) - 2.0 * c4_x2 * c4_x4 * c4_mpower(chartInstance, c4_y1)
                 * c4_y2 * c4_y4) - 2.0 * c4_x2 * c4_x3 * c4_y2 * c4_y3 *
                c4_mpower(chartInstance, c4_y4)) - 2.0 * c4_x2 * c4_x4 * c4_y2 *
               c4_mpower(chartInstance, c4_y3) * c4_y4) - 2.0 * c4_x3 * c4_x4 *
              c4_mpower(chartInstance, c4_y1) * c4_y3 * c4_y4) - 2.0 * c4_x3 *
             c4_x4 * c4_mpower(chartInstance, c4_y2) * c4_y3 * c4_y4) - 2.0 *
            c4_x1 * c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_z1)) -
           2.0 * c4_x1 * c4_x2 * c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_z2))
          - 2.0 * c4_x1 * c4_x2 * c4_mpower(chartInstance, c4_x3) * c4_z1 *
          c4_z2) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3 * c4_mpower(chartInstance,
          c4_z1)) - 2.0 * c4_x1 * c4_x2 * c4_mpower(chartInstance, c4_x4) *
        c4_z1 * c4_z2) - 2.0 * c4_x1 * c4_mpower(chartInstance, c4_x2) * c4_x3 *
       c4_z1 * c4_z3) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y3 * c4_mpower
      (chartInstance, c4_z3)) - 2.0 * c4_x1 * c4_x4 * c4_y1 * c4_y4 * c4_mpower
     (chartInstance, c4_z1)) - 2.0 * c4_mpower(chartInstance, c4_x1) * c4_x2 *
    c4_x3 * c4_z2 * c4_z3;
  c4_i_B =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((((((((((((((((((((((c4_d179 - c4_d164) - c4_d163 * c4_z4) - c4_d162 *
    c4_y3 * c4_mpower(chartInstance, c4_z2)) - c4_d161 * c4_x4 * c4_z1 * c4_z4)
    - c4_d160 * c4_x3 * c4_y2 * c4_y3 * c4_mpower(chartInstance, c4_z3)) - 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_x2 * c4_x4 * c4_z2 * c4_z4) - 2.0 *
    c4_x1 * c4_x4 * c4_y1 * c4_y4 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x2 * c4_x3 * c4_mpower(chartInstance, c4_x4) * c4_z2 * c4_z3) - 2.0 *
    c4_x2 * c4_x4 * c4_y2 * c4_y4 * c4_mpower(chartInstance, c4_z2)) - 2.0 *
    c4_x2 * c4_mpower(chartInstance, c4_x3) * c4_x4 * c4_z2 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_x3 * c4_x4 * c4_z3 * c4_z4) - 2.0 *
    c4_x2 * c4_x4 * c4_y2 * c4_y4 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_x3 * c4_x4 * c4_z3 * c4_z4) - 2.0 *
    c4_x3 * c4_x4 * c4_y3 * c4_y4 * c4_mpower(chartInstance, c4_z3)) - 2.0 *
    c4_x3 * c4_x4 * c4_y3 * c4_y4 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x1 * c4_x2 * c4_mpower(chartInstance, c4_y1) * c4_z1 * c4_z2) - 2.0 *
    c4_x1 * c4_x2 * c4_mpower(chartInstance, c4_y2) * c4_z1 * c4_z2) - 2.0 *
    c4_x1 * c4_x3 * c4_mpower(chartInstance, c4_y1) * c4_z1 * c4_z3) - 2.0 *
    c4_x1 * c4_x3 * c4_mpower(chartInstance, c4_y3) * c4_z1 * c4_z3) - 2.0 *
    c4_x1 * c4_x4 * c4_mpower(chartInstance, c4_y1) * c4_z1 * c4_z4) - 2.0 *
    c4_x2 * c4_x3 * c4_mpower(chartInstance, c4_y2) * c4_z2 * c4_z3) - 2.0 *
    c4_x2 * c4_x3 * c4_mpower(chartInstance, c4_y3) * c4_z2 * c4_z3) - 2.0 *
    c4_x1 * c4_x4 * c4_mpower(chartInstance, c4_y4) * c4_z1 * c4_z4) - 2.0 *
    c4_x2 * c4_x4 * c4_mpower(chartInstance, c4_y2) * c4_z2 * c4_z4) - 2.0 *
    c4_x2 * c4_x4 * c4_mpower(chartInstance, c4_y4) * c4_z2 * c4_z4) - 2.0 *
    c4_x3 * c4_x4 * c4_mpower(chartInstance, c4_y3) * c4_z3 * c4_z4) - 2.0 *
    c4_x3 * c4_x4 * c4_mpower(chartInstance, c4_y4) * c4_z3 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_y1 * c4_y2 * c4_z1 * c4_z2) - 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_y1 * c4_y2 * c4_z1 * c4_z2) - 2.0 *
    c4_x1 * c4_x2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z3)) - 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_y1 * c4_y3 * c4_z1 * c4_z3) - 2.0 *
    c4_x1 * c4_x2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x1 * c4_x3 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 *
    c4_x2 * c4_x3 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z3) - 2.0 *
    c4_mpower(chartInstance, c4_x1) * c4_y1 * c4_y4 * c4_z1 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_y1 * c4_y3 * c4_z1 * c4_z3) - 2.0 *
    c4_x1 * c4_x3 * c4_z1 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_x1 * c4_x4 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 2.0 *
    c4_x1 * c4_x4 * c4_z1 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 *
    c4_x2 * c4_x4 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 2.0 *
    c4_x2 * c4_x3 * c4_z2 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_mpower(chartInstance, c4_x2) * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_y1 * c4_y4 * c4_z1 * c4_z4) - 2.0 *
    c4_x2 * c4_x4 * c4_z2 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 *
    c4_x3 * c4_x4 * c4_mpower(chartInstance, c4_z1) * c4_z3 * c4_z4) - 2.0 *
    c4_x3 * c4_x4 * c4_mpower(chartInstance, c4_z2) * c4_z3 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x3) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_x4) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 *
    c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_y3) * c4_z1 * c4_z2) - 2.0 *
    c4_y1 * c4_y2 * c4_mpower(chartInstance, c4_y4) * c4_z1 * c4_z2) - 2.0 *
    c4_y1 * c4_mpower(chartInstance, c4_y2) * c4_y3 * c4_z1 * c4_z3) - 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_y2 * c4_y3 * c4_z2 * c4_z3) - 2.0 *
    c4_y1 * c4_y3 * c4_mpower(chartInstance, c4_y4) * c4_z1 * c4_z3) - 2.0 *
    c4_y1 * c4_mpower(chartInstance, c4_y2) * c4_y4 * c4_z1 * c4_z4) - 2.0 *
    c4_y1 * c4_mpower(chartInstance, c4_y3) * c4_y4 * c4_z1 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_y2 * c4_y4 * c4_z2 * c4_z4) - 2.0 *
    c4_y2 * c4_y3 * c4_mpower(chartInstance, c4_y4) * c4_z2 * c4_z3) - 2.0 *
    c4_y2 * c4_mpower(chartInstance, c4_y3) * c4_y4 * c4_z2 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_y1) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 *
    c4_mpower(chartInstance, c4_y2) * c4_y3 * c4_y4 * c4_z3 * c4_z4) - 2.0 *
    c4_y1 * c4_y2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z3)) - 2.0 *
    c4_y1 * c4_y2 * c4_z1 * c4_z2 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_y1 * c4_y3 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z3) - 2.0 *
    c4_y2 * c4_y3 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z3) - 2.0 *
    c4_y1 * c4_y3 * c4_z1 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_y1 * c4_y4 * c4_z1 * c4_mpower(chartInstance, c4_z2) * c4_z4) - 2.0 *
    c4_y1 * c4_y4 * c4_z1 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 *
    c4_y2 * c4_y4 * c4_mpower(chartInstance, c4_z1) * c4_z2 * c4_z4) - 2.0 *
    c4_y2 * c4_y3 * c4_z2 * c4_z3 * c4_mpower(chartInstance, c4_z4)) - 2.0 *
    c4_y2 * c4_y4 * c4_z2 * c4_mpower(chartInstance, c4_z3) * c4_z4) - 2.0 *
    c4_y3 * c4_y4 * c4_mpower(chartInstance, c4_z1) * c4_z3 * c4_z4) - 2.0 *
    c4_y3 * c4_y4 * c4_mpower(chartInstance, c4_z2) * c4_z3 * c4_z4) - 2.0 *
    c4_x1 * c4_x2 * c4_y1 * c4_y3 * c4_z2 * c4_z3) - 2.0 * c4_x1 * c4_x2 * c4_y2
    * c4_y3 * c4_z1 * c4_z3) - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y2 * c4_z2 *
    c4_z3) - 2.0 * c4_x1 * c4_x3 * c4_y2 * c4_y3 * c4_z1 * c4_z2) - 2.0 * c4_x2 *
    c4_x3 * c4_y1 * c4_y2 * c4_z1 * c4_z3) - 2.0 * c4_x2 * c4_x3 * c4_y1 * c4_y3
                       * c4_z1 * c4_z2) - 2.0 * c4_x1 * c4_x2 * c4_y1 * c4_y4 *
                      c4_z2 * c4_z4) - 2.0 * c4_x1 * c4_x2 * c4_y2 * c4_y4 *
                     c4_z1 * c4_z4) - 2.0 * c4_x1 * c4_x4 * c4_y1 * c4_y2 *
                    c4_z2 * c4_z4) - 2.0 * c4_x1 * c4_x4 * c4_y2 * c4_y4 * c4_z1
                   * c4_z2) - 2.0 * c4_x2 * c4_x4 * c4_y1 * c4_y2 * c4_z1 *
                  c4_z4) - 2.0 * c4_x2 * c4_x4 * c4_y1 * c4_y4 * c4_z1 * c4_z2)
                - 2.0 * c4_x1 * c4_x3 * c4_y1 * c4_y4 * c4_z3 * c4_z4) - 2.0 *
               c4_x1 * c4_x3 * c4_y3 * c4_y4 * c4_z1 * c4_z4) - 2.0 * c4_x1 *
              c4_x4 * c4_y1 * c4_y3 * c4_z3 * c4_z4) - 2.0 * c4_x1 * c4_x4 *
             c4_y3 * c4_y4 * c4_z1 * c4_z3) - 2.0 * c4_x3 * c4_x4 * c4_y1 *
            c4_y3 * c4_z1 * c4_z4) - 2.0 * c4_x3 * c4_x4 * c4_y1 * c4_y4 * c4_z1
           * c4_z3) - 2.0 * c4_x2 * c4_x3 * c4_y2 * c4_y4 * c4_z3 * c4_z4) - 2.0
         * c4_x2 * c4_x3 * c4_y3 * c4_y4 * c4_z2 * c4_z4) - 2.0 * c4_x2 * c4_x4 *
        c4_y2 * c4_y3 * c4_z3 * c4_z4) - 2.0 * c4_x2 * c4_x4 * c4_y3 * c4_y4 *
       c4_z2 * c4_z3) - 2.0 * c4_x3 * c4_x4 * c4_y2 * c4_y3 * c4_z2 * c4_z4) -
     2.0 * c4_x3 * c4_x4 * c4_y2 * c4_y4 * c4_z2 * c4_z3) + 64.0;
  c4_fb_x = c4_i_A;
  c4_hb_y = c4_i_B;
  c4_gb_x = c4_fb_x;
  c4_ib_y = c4_hb_y;
  c4_hb_x = c4_gb_x;
  c4_jb_y = c4_ib_y;
  c4_kb_y = c4_hb_x / c4_jb_y;
  c4_J4inv[0] = c4_d_y;
  c4_J4inv[3] = c4_h_y;
  c4_J4inv[6] = c4_l_y;
  c4_J4inv[1] = c4_p_y;
  c4_J4inv[4] = c4_t_y;
  c4_J4inv[7] = c4_x_y;
  c4_J4inv[2] = c4_cb_y;
  c4_J4inv[5] = c4_gb_y;
  c4_J4inv[8] = c4_kb_y;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 32);
  for (c4_i20 = 0; c4_i20 < 4; c4_i20++) {
    c4_ib_x[c4_i20] = c4_b_x[c4_i20 + 3];
  }

  for (c4_i21 = 0; c4_i21 < 3; c4_i21++) {
    c4_g_r[c4_i21] = c4_b_r[c4_i21];
  }

  c4_quatrot(chartInstance, c4_ib_x, c4_g_r, c4_dv6);
  for (c4_i22 = 0; c4_i22 < 3; c4_i22++) {
    c4_jb_x[c4_i22] = c4_dv6[c4_i22];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c4_c_debug_family_names,
    c4_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_jb_x, 2U, c4_f_sf_marshallOut,
    c4_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_X, 3U, c4_e_sf_marshallOut,
    c4_d_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, 3);
  c4_X[0] = 0.0;
  c4_X[3] = -c4_jb_x[2];
  c4_X[6] = c4_jb_x[1];
  c4_X[1] = c4_jb_x[2];
  c4_X[4] = 0.0;
  c4_X[7] = -c4_jb_x[0];
  c4_X[2] = -c4_jb_x[1];
  c4_X[5] = c4_jb_x[0];
  c4_X[8] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c4_i23 = 0; c4_i23 < 9; c4_i23++) {
    c4_a[c4_i23] = c4_J4inv[c4_i23];
  }

  c4_i24 = 0;
  for (c4_i25 = 0; c4_i25 < 3; c4_i25++) {
    c4_i26 = 0;
    for (c4_i27 = 0; c4_i27 < 3; c4_i27++) {
      c4_b[c4_i27 + c4_i24] = c4_X[c4_i26 + c4_i25];
      c4_i26 += 3;
    }

    c4_i24 += 3;
  }

  c4_b_eml_scalar_eg(chartInstance);
  c4_b_eml_scalar_eg(chartInstance);
  for (c4_i28 = 0; c4_i28 < 9; c4_i28++) {
    c4_lb_y[c4_i28] = 0.0;
  }

  for (c4_i29 = 0; c4_i29 < 9; c4_i29++) {
    c4_b_a[c4_i29] = c4_a[c4_i29];
  }

  for (c4_i30 = 0; c4_i30 < 9; c4_i30++) {
    c4_b_b[c4_i30] = c4_b[c4_i30];
  }

  c4_b_eml_xgemm(chartInstance, c4_b_a, c4_b_b, c4_lb_y);
  for (c4_i31 = 0; c4_i31 < 4; c4_i31++) {
    c4_kb_x[c4_i31] = c4_b_x[c4_i31 + 3];
  }

  for (c4_i32 = 0; c4_i32 < 3; c4_i32++) {
    c4_h_r[c4_i32] = c4_b_r[c4_i32 + 3];
  }

  c4_quatrot(chartInstance, c4_kb_x, c4_h_r, c4_dv7);
  for (c4_i33 = 0; c4_i33 < 3; c4_i33++) {
    c4_lb_x[c4_i33] = c4_dv7[c4_i33];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c4_c_debug_family_names,
    c4_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_lb_x, 2U, c4_f_sf_marshallOut,
    c4_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_b_X, 3U, c4_e_sf_marshallOut,
    c4_d_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, 3);
  c4_b_X[0] = 0.0;
  c4_b_X[3] = -c4_lb_x[2];
  c4_b_X[6] = c4_lb_x[1];
  c4_b_X[1] = c4_lb_x[2];
  c4_b_X[4] = 0.0;
  c4_b_X[7] = -c4_lb_x[0];
  c4_b_X[2] = -c4_lb_x[1];
  c4_b_X[5] = c4_lb_x[0];
  c4_b_X[8] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c4_i34 = 0; c4_i34 < 9; c4_i34++) {
    c4_a[c4_i34] = c4_J4inv[c4_i34];
  }

  c4_i35 = 0;
  for (c4_i36 = 0; c4_i36 < 3; c4_i36++) {
    c4_i37 = 0;
    for (c4_i38 = 0; c4_i38 < 3; c4_i38++) {
      c4_b[c4_i38 + c4_i35] = c4_b_X[c4_i37 + c4_i36];
      c4_i37 += 3;
    }

    c4_i35 += 3;
  }

  c4_b_eml_scalar_eg(chartInstance);
  c4_b_eml_scalar_eg(chartInstance);
  for (c4_i39 = 0; c4_i39 < 9; c4_i39++) {
    c4_mb_y[c4_i39] = 0.0;
  }

  for (c4_i40 = 0; c4_i40 < 9; c4_i40++) {
    c4_c_a[c4_i40] = c4_a[c4_i40];
  }

  for (c4_i41 = 0; c4_i41 < 9; c4_i41++) {
    c4_c_b[c4_i41] = c4_b[c4_i41];
  }

  c4_b_eml_xgemm(chartInstance, c4_c_a, c4_c_b, c4_mb_y);
  for (c4_i42 = 0; c4_i42 < 4; c4_i42++) {
    c4_mb_x[c4_i42] = c4_b_x[c4_i42 + 3];
  }

  for (c4_i43 = 0; c4_i43 < 3; c4_i43++) {
    c4_i_r[c4_i43] = c4_b_r[c4_i43 + 6];
  }

  c4_quatrot(chartInstance, c4_mb_x, c4_i_r, c4_dv8);
  for (c4_i44 = 0; c4_i44 < 3; c4_i44++) {
    c4_nb_x[c4_i44] = c4_dv8[c4_i44];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c4_c_debug_family_names,
    c4_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargin, 0U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargout, 1U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_nb_x, 2U, c4_f_sf_marshallOut,
    c4_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_c_X, 3U, c4_e_sf_marshallOut,
    c4_d_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, 3);
  c4_c_X[0] = 0.0;
  c4_c_X[3] = -c4_nb_x[2];
  c4_c_X[6] = c4_nb_x[1];
  c4_c_X[1] = c4_nb_x[2];
  c4_c_X[4] = 0.0;
  c4_c_X[7] = -c4_nb_x[0];
  c4_c_X[2] = -c4_nb_x[1];
  c4_c_X[5] = c4_nb_x[0];
  c4_c_X[8] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c4_i45 = 0; c4_i45 < 9; c4_i45++) {
    c4_a[c4_i45] = c4_J4inv[c4_i45];
  }

  c4_i46 = 0;
  for (c4_i47 = 0; c4_i47 < 3; c4_i47++) {
    c4_i48 = 0;
    for (c4_i49 = 0; c4_i49 < 3; c4_i49++) {
      c4_b[c4_i49 + c4_i46] = c4_c_X[c4_i48 + c4_i47];
      c4_i48 += 3;
    }

    c4_i46 += 3;
  }

  c4_b_eml_scalar_eg(chartInstance);
  c4_b_eml_scalar_eg(chartInstance);
  for (c4_i50 = 0; c4_i50 < 9; c4_i50++) {
    c4_nb_y[c4_i50] = 0.0;
  }

  for (c4_i51 = 0; c4_i51 < 9; c4_i51++) {
    c4_d_a[c4_i51] = c4_a[c4_i51];
  }

  for (c4_i52 = 0; c4_i52 < 9; c4_i52++) {
    c4_d_b[c4_i52] = c4_b[c4_i52];
  }

  c4_b_eml_xgemm(chartInstance, c4_d_a, c4_d_b, c4_nb_y);
  for (c4_i53 = 0; c4_i53 < 4; c4_i53++) {
    c4_ob_x[c4_i53] = c4_b_x[c4_i53 + 3];
  }

  for (c4_i54 = 0; c4_i54 < 3; c4_i54++) {
    c4_j_r[c4_i54] = c4_b_r[c4_i54 + 9];
  }

  c4_quatrot(chartInstance, c4_ob_x, c4_j_r, c4_dv9);
  for (c4_i55 = 0; c4_i55 < 3; c4_i55++) {
    c4_pb_x[c4_i55] = c4_dv9[c4_i55];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c4_c_debug_family_names,
    c4_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargin, 0U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargout, 1U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_pb_x, 2U, c4_f_sf_marshallOut,
    c4_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_d_X, 3U, c4_e_sf_marshallOut,
    c4_d_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, 3);
  c4_d_X[0] = 0.0;
  c4_d_X[3] = -c4_pb_x[2];
  c4_d_X[6] = c4_pb_x[1];
  c4_d_X[1] = c4_pb_x[2];
  c4_d_X[4] = 0.0;
  c4_d_X[7] = -c4_pb_x[0];
  c4_d_X[2] = -c4_pb_x[1];
  c4_d_X[5] = c4_pb_x[0];
  c4_d_X[8] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c4_i56 = 0; c4_i56 < 9; c4_i56++) {
    c4_a[c4_i56] = c4_J4inv[c4_i56];
  }

  c4_i57 = 0;
  for (c4_i58 = 0; c4_i58 < 3; c4_i58++) {
    c4_i59 = 0;
    for (c4_i60 = 0; c4_i60 < 3; c4_i60++) {
      c4_b[c4_i60 + c4_i57] = c4_d_X[c4_i59 + c4_i58];
      c4_i59 += 3;
    }

    c4_i57 += 3;
  }

  c4_b_eml_scalar_eg(chartInstance);
  c4_b_eml_scalar_eg(chartInstance);
  for (c4_i61 = 0; c4_i61 < 9; c4_i61++) {
    c4_ob_y[c4_i61] = 0.0;
  }

  for (c4_i62 = 0; c4_i62 < 9; c4_i62++) {
    c4_e_a[c4_i62] = c4_a[c4_i62];
  }

  for (c4_i63 = 0; c4_i63 < 9; c4_i63++) {
    c4_e_b[c4_i63] = c4_b[c4_i63];
  }

  c4_b_eml_xgemm(chartInstance, c4_e_a, c4_e_b, c4_ob_y);
  c4_eye(chartInstance, c4_a);
  c4_eye(chartInstance, c4_b);
  c4_eye(chartInstance, c4_dv10);
  c4_eye(chartInstance, c4_dv11);
  c4_i64 = 0;
  c4_i65 = 0;
  for (c4_i66 = 0; c4_i66 < 3; c4_i66++) {
    for (c4_i67 = 0; c4_i67 < 3; c4_i67++) {
      c4_f_b[c4_i67 + c4_i64] = c4_a[c4_i67 + c4_i65];
    }

    c4_i64 += 24;
    c4_i65 += 3;
  }

  c4_i68 = 0;
  c4_i69 = 0;
  for (c4_i70 = 0; c4_i70 < 3; c4_i70++) {
    for (c4_i71 = 0; c4_i71 < 3; c4_i71++) {
      c4_f_b[(c4_i71 + c4_i68) + 72] = c4_lb_y[c4_i71 + c4_i69];
    }

    c4_i68 += 24;
    c4_i69 += 3;
  }

  c4_i72 = 0;
  for (c4_i73 = 0; c4_i73 < 3; c4_i73++) {
    for (c4_i74 = 0; c4_i74 < 3; c4_i74++) {
      c4_f_b[(c4_i74 + c4_i72) + 3] = 0.0;
    }

    c4_i72 += 24;
  }

  c4_i75 = 0;
  c4_i76 = 0;
  for (c4_i77 = 0; c4_i77 < 3; c4_i77++) {
    for (c4_i78 = 0; c4_i78 < 3; c4_i78++) {
      c4_f_b[(c4_i78 + c4_i75) + 75] = c4_J4inv[c4_i78 + c4_i76];
    }

    c4_i75 += 24;
    c4_i76 += 3;
  }

  c4_i79 = 0;
  c4_i80 = 0;
  for (c4_i81 = 0; c4_i81 < 3; c4_i81++) {
    for (c4_i82 = 0; c4_i82 < 3; c4_i82++) {
      c4_f_b[(c4_i82 + c4_i79) + 6] = c4_b[c4_i82 + c4_i80];
    }

    c4_i79 += 24;
    c4_i80 += 3;
  }

  c4_i83 = 0;
  c4_i84 = 0;
  for (c4_i85 = 0; c4_i85 < 3; c4_i85++) {
    for (c4_i86 = 0; c4_i86 < 3; c4_i86++) {
      c4_f_b[(c4_i86 + c4_i83) + 78] = c4_mb_y[c4_i86 + c4_i84];
    }

    c4_i83 += 24;
    c4_i84 += 3;
  }

  c4_i87 = 0;
  for (c4_i88 = 0; c4_i88 < 3; c4_i88++) {
    for (c4_i89 = 0; c4_i89 < 3; c4_i89++) {
      c4_f_b[(c4_i89 + c4_i87) + 9] = 0.0;
    }

    c4_i87 += 24;
  }

  c4_i90 = 0;
  c4_i91 = 0;
  for (c4_i92 = 0; c4_i92 < 3; c4_i92++) {
    for (c4_i93 = 0; c4_i93 < 3; c4_i93++) {
      c4_f_b[(c4_i93 + c4_i90) + 81] = c4_J4inv[c4_i93 + c4_i91];
    }

    c4_i90 += 24;
    c4_i91 += 3;
  }

  c4_i94 = 0;
  c4_i95 = 0;
  for (c4_i96 = 0; c4_i96 < 3; c4_i96++) {
    for (c4_i97 = 0; c4_i97 < 3; c4_i97++) {
      c4_f_b[(c4_i97 + c4_i94) + 12] = c4_dv10[c4_i97 + c4_i95];
    }

    c4_i94 += 24;
    c4_i95 += 3;
  }

  c4_i98 = 0;
  c4_i99 = 0;
  for (c4_i100 = 0; c4_i100 < 3; c4_i100++) {
    for (c4_i101 = 0; c4_i101 < 3; c4_i101++) {
      c4_f_b[(c4_i101 + c4_i98) + 84] = c4_nb_y[c4_i101 + c4_i99];
    }

    c4_i98 += 24;
    c4_i99 += 3;
  }

  c4_i102 = 0;
  for (c4_i103 = 0; c4_i103 < 3; c4_i103++) {
    for (c4_i104 = 0; c4_i104 < 3; c4_i104++) {
      c4_f_b[(c4_i104 + c4_i102) + 15] = 0.0;
    }

    c4_i102 += 24;
  }

  c4_i105 = 0;
  c4_i106 = 0;
  for (c4_i107 = 0; c4_i107 < 3; c4_i107++) {
    for (c4_i108 = 0; c4_i108 < 3; c4_i108++) {
      c4_f_b[(c4_i108 + c4_i105) + 87] = c4_J4inv[c4_i108 + c4_i106];
    }

    c4_i105 += 24;
    c4_i106 += 3;
  }

  c4_i109 = 0;
  c4_i110 = 0;
  for (c4_i111 = 0; c4_i111 < 3; c4_i111++) {
    for (c4_i112 = 0; c4_i112 < 3; c4_i112++) {
      c4_f_b[(c4_i112 + c4_i109) + 18] = c4_dv11[c4_i112 + c4_i110];
    }

    c4_i109 += 24;
    c4_i110 += 3;
  }

  c4_i113 = 0;
  c4_i114 = 0;
  for (c4_i115 = 0; c4_i115 < 3; c4_i115++) {
    for (c4_i116 = 0; c4_i116 < 3; c4_i116++) {
      c4_f_b[(c4_i116 + c4_i113) + 90] = c4_ob_y[c4_i116 + c4_i114];
    }

    c4_i113 += 24;
    c4_i114 += 3;
  }

  c4_i117 = 0;
  for (c4_i118 = 0; c4_i118 < 3; c4_i118++) {
    for (c4_i119 = 0; c4_i119 < 3; c4_i119++) {
      c4_f_b[(c4_i119 + c4_i117) + 21] = 0.0;
    }

    c4_i117 += 24;
  }

  c4_i120 = 0;
  c4_i121 = 0;
  for (c4_i122 = 0; c4_i122 < 3; c4_i122++) {
    for (c4_i123 = 0; c4_i123 < 3; c4_i123++) {
      c4_f_b[(c4_i123 + c4_i120) + 93] = c4_J4inv[c4_i123 + c4_i121];
    }

    c4_i120 += 24;
    c4_i121 += 3;
  }

  for (c4_i124 = 0; c4_i124 < 144; c4_i124++) {
    c4_b_Ginv[c4_i124] = 0.25 * c4_f_b[c4_i124];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -32);
  _SFD_SYMBOL_SCOPE_POP();
  for (c4_i125 = 0; c4_i125 < 144; c4_i125++) {
    (*chartInstance->c4_Ginv)[c4_i125] = c4_b_Ginv[c4_i125];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
}

static void initSimStructsc4_DePascali4M(SFc4_DePascali4MInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c4_quatrot(SFc4_DePascali4MInstanceStruct *chartInstance, real_T
  c4_q[4], real_T c4_b_r[3], real_T c4_rw[3])
{
  uint32_T c4_debug_family_var_map[6];
  real_T c4_rwq[4];
  real_T c4_nargin = 2.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i126;
  real_T c4_b_q[4];
  int32_T c4_k;
  real_T c4_b_k;
  real_T c4_dv12[4];
  int32_T c4_i127;
  int32_T c4_i128;
  real_T c4_c_q[4];
  real_T c4_dv13[4];
  int32_T c4_i129;
  real_T c4_d_q[4];
  int32_T c4_i130;
  real_T c4_dv14[4];
  int32_T c4_i131;
  int32_T c4_i132;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c4_b_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_rwq, 0U, c4_g_sf_marshallOut,
    c4_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 1U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 2U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_q, 3U, c4_g_sf_marshallOut,
    c4_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_b_r, 4U, c4_f_sf_marshallOut,
    c4_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_rw, 5U, c4_f_sf_marshallOut,
    c4_e_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  for (c4_i126 = 0; c4_i126 < 4; c4_i126++) {
    c4_b_q[c4_i126] = c4_q[c4_i126];
  }

  for (c4_k = 0; c4_k < 3; c4_k++) {
    c4_b_k = 2.0 + (real_T)c4_k;
    c4_b_q[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c4_b_k), 1, 4, 1, 0) - 1] = -c4_b_q[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", c4_b_k), 1, 4, 1, 0) - 1];
  }

  c4_dv12[0] = 0.0;
  for (c4_i127 = 0; c4_i127 < 3; c4_i127++) {
    c4_dv12[c4_i127 + 1] = c4_b_r[c4_i127];
  }

  for (c4_i128 = 0; c4_i128 < 4; c4_i128++) {
    c4_c_q[c4_i128] = c4_b_q[c4_i128];
  }

  c4_quatmultiply(chartInstance, c4_dv12, c4_c_q, c4_dv13);
  for (c4_i129 = 0; c4_i129 < 4; c4_i129++) {
    c4_d_q[c4_i129] = c4_q[c4_i129];
  }

  for (c4_i130 = 0; c4_i130 < 4; c4_i130++) {
    c4_dv14[c4_i130] = c4_dv13[c4_i130];
  }

  c4_quatmultiply(chartInstance, c4_d_q, c4_dv14, c4_b_q);
  for (c4_i131 = 0; c4_i131 < 4; c4_i131++) {
    c4_rwq[c4_i131] = c4_b_q[c4_i131];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 5);
  for (c4_i132 = 0; c4_i132 < 3; c4_i132++) {
    c4_rw[c4_i132] = c4_rwq[c4_i132 + 1];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -5);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber)
{
  (void)c4_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c4_chartNumber, c4_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Martin\\Documents\\Git\\Simulink\\DePascaliErhart\\quatrot.m"));
  _SFD_SCRIPT_TRANSLATION(c4_chartNumber, c4_instanceNumber, 1U,
    sf_debug_get_script_id(
    "C:\\Users\\Martin\\Documents\\Git\\Simulink\\DePascaliErhart\\skew_sm.m"));
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i133;
  int32_T c4_i134;
  int32_T c4_i135;
  real_T c4_b_inData[144];
  int32_T c4_i136;
  int32_T c4_i137;
  int32_T c4_i138;
  real_T c4_u[144];
  const mxArray *c4_y = NULL;
  SFc4_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc4_DePascali4MInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_i133 = 0;
  for (c4_i134 = 0; c4_i134 < 6; c4_i134++) {
    for (c4_i135 = 0; c4_i135 < 24; c4_i135++) {
      c4_b_inData[c4_i135 + c4_i133] = (*(real_T (*)[144])c4_inData)[c4_i135 +
        c4_i133];
    }

    c4_i133 += 24;
  }

  c4_i136 = 0;
  for (c4_i137 = 0; c4_i137 < 6; c4_i137++) {
    for (c4_i138 = 0; c4_i138 < 24; c4_i138++) {
      c4_u[c4_i138 + c4_i136] = c4_b_inData[c4_i138 + c4_i136];
    }

    c4_i136 += 24;
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 24, 6), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_emlrt_marshallIn(SFc4_DePascali4MInstanceStruct *chartInstance,
  const mxArray *c4_b_Ginv, const char_T *c4_identifier, real_T c4_y[144])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_Ginv), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_b_Ginv);
}

static void c4_b_emlrt_marshallIn(SFc4_DePascali4MInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[144])
{
  real_T c4_dv15[144];
  int32_T c4_i139;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv15, 1, 0, 0U, 1, 0U, 2, 24,
                6);
  for (c4_i139 = 0; c4_i139 < 144; c4_i139++) {
    c4_y[c4_i139] = c4_dv15[c4_i139];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_Ginv;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[144];
  int32_T c4_i140;
  int32_T c4_i141;
  int32_T c4_i142;
  SFc4_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc4_DePascali4MInstanceStruct *)chartInstanceVoid;
  c4_b_Ginv = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_Ginv), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_b_Ginv);
  c4_i140 = 0;
  for (c4_i141 = 0; c4_i141 < 6; c4_i141++) {
    for (c4_i142 = 0; c4_i142 < 24; c4_i142++) {
      (*(real_T (*)[144])c4_outData)[c4_i142 + c4_i140] = c4_y[c4_i142 + c4_i140];
    }

    c4_i140 += 24;
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i143;
  real_T c4_b_inData[12];
  int32_T c4_i144;
  real_T c4_u[12];
  const mxArray *c4_y = NULL;
  SFc4_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc4_DePascali4MInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i143 = 0; c4_i143 < 12; c4_i143++) {
    c4_b_inData[c4_i143] = (*(real_T (*)[12])c4_inData)[c4_i143];
  }

  for (c4_i144 = 0; c4_i144 < 12; c4_i144++) {
    c4_u[c4_i144] = c4_b_inData[c4_i144];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 12), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_c_emlrt_marshallIn(SFc4_DePascali4MInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[12])
{
  real_T c4_dv16[12];
  int32_T c4_i145;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv16, 1, 0, 0U, 1, 0U, 1, 12);
  for (c4_i145 = 0; c4_i145 < 12; c4_i145++) {
    c4_y[c4_i145] = c4_dv16[c4_i145];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_r;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[12];
  int32_T c4_i146;
  SFc4_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc4_DePascali4MInstanceStruct *)chartInstanceVoid;
  c4_b_r = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_r), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_b_r);
  for (c4_i146 = 0; c4_i146 < 12; c4_i146++) {
    (*(real_T (*)[12])c4_outData)[c4_i146] = c4_y[c4_i146];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i147;
  real_T c4_b_inData[28];
  int32_T c4_i148;
  real_T c4_u[28];
  const mxArray *c4_y = NULL;
  SFc4_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc4_DePascali4MInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i147 = 0; c4_i147 < 28; c4_i147++) {
    c4_b_inData[c4_i147] = (*(real_T (*)[28])c4_inData)[c4_i147];
  }

  for (c4_i148 = 0; c4_i148 < 28; c4_i148++) {
    c4_u[c4_i148] = c4_b_inData[c4_i148];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 28), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc4_DePascali4MInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_d_emlrt_marshallIn(SFc4_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d180;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d180, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d180;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_nargout;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc4_DePascali4MInstanceStruct *)chartInstanceVoid;
  c4_nargout = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nargout), &c4_thisId);
  sf_mex_destroy(&c4_nargout);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i149;
  int32_T c4_i150;
  int32_T c4_i151;
  real_T c4_b_inData[9];
  int32_T c4_i152;
  int32_T c4_i153;
  int32_T c4_i154;
  real_T c4_u[9];
  const mxArray *c4_y = NULL;
  SFc4_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc4_DePascali4MInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_i149 = 0;
  for (c4_i150 = 0; c4_i150 < 3; c4_i150++) {
    for (c4_i151 = 0; c4_i151 < 3; c4_i151++) {
      c4_b_inData[c4_i151 + c4_i149] = (*(real_T (*)[9])c4_inData)[c4_i151 +
        c4_i149];
    }

    c4_i149 += 3;
  }

  c4_i152 = 0;
  for (c4_i153 = 0; c4_i153 < 3; c4_i153++) {
    for (c4_i154 = 0; c4_i154 < 3; c4_i154++) {
      c4_u[c4_i154 + c4_i152] = c4_b_inData[c4_i154 + c4_i152];
    }

    c4_i152 += 3;
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_e_emlrt_marshallIn(SFc4_DePascali4MInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[9])
{
  real_T c4_dv17[9];
  int32_T c4_i155;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv17, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c4_i155 = 0; c4_i155 < 9; c4_i155++) {
    c4_y[c4_i155] = c4_dv17[c4_i155];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_J4inv;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[9];
  int32_T c4_i156;
  int32_T c4_i157;
  int32_T c4_i158;
  SFc4_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc4_DePascali4MInstanceStruct *)chartInstanceVoid;
  c4_J4inv = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_J4inv), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_J4inv);
  c4_i156 = 0;
  for (c4_i157 = 0; c4_i157 < 3; c4_i157++) {
    for (c4_i158 = 0; c4_i158 < 3; c4_i158++) {
      (*(real_T (*)[9])c4_outData)[c4_i158 + c4_i156] = c4_y[c4_i158 + c4_i156];
    }

    c4_i156 += 3;
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i159;
  real_T c4_b_inData[3];
  int32_T c4_i160;
  real_T c4_u[3];
  const mxArray *c4_y = NULL;
  SFc4_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc4_DePascali4MInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i159 = 0; c4_i159 < 3; c4_i159++) {
    c4_b_inData[c4_i159] = (*(real_T (*)[3])c4_inData)[c4_i159];
  }

  for (c4_i160 = 0; c4_i160 < 3; c4_i160++) {
    c4_u[c4_i160] = c4_b_inData[c4_i160];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_f_emlrt_marshallIn(SFc4_DePascali4MInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[3])
{
  real_T c4_dv18[3];
  int32_T c4_i161;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv18, 1, 0, 0U, 1, 0U, 1, 3);
  for (c4_i161 = 0; c4_i161 < 3; c4_i161++) {
    c4_y[c4_i161] = c4_dv18[c4_i161];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_r4;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[3];
  int32_T c4_i162;
  SFc4_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc4_DePascali4MInstanceStruct *)chartInstanceVoid;
  c4_r4 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_r4), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_r4);
  for (c4_i162 = 0; c4_i162 < 3; c4_i162++) {
    (*(real_T (*)[3])c4_outData)[c4_i162] = c4_y[c4_i162];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_g_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i163;
  real_T c4_b_inData[4];
  int32_T c4_i164;
  real_T c4_u[4];
  const mxArray *c4_y = NULL;
  SFc4_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc4_DePascali4MInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i163 = 0; c4_i163 < 4; c4_i163++) {
    c4_b_inData[c4_i163] = (*(real_T (*)[4])c4_inData)[c4_i163];
  }

  for (c4_i164 = 0; c4_i164 < 4; c4_i164++) {
    c4_u[c4_i164] = c4_b_inData[c4_i164];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_g_emlrt_marshallIn(SFc4_DePascali4MInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[4])
{
  real_T c4_dv19[4];
  int32_T c4_i165;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv19, 1, 0, 0U, 1, 0U, 1, 4);
  for (c4_i165 = 0; c4_i165 < 4; c4_i165++) {
    c4_y[c4_i165] = c4_dv19[c4_i165];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_q;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[4];
  int32_T c4_i166;
  SFc4_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc4_DePascali4MInstanceStruct *)chartInstanceVoid;
  c4_q = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_q), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_q);
  for (c4_i166 = 0; c4_i166 < 4; c4_i166++) {
    (*(real_T (*)[4])c4_outData)[c4_i166] = c4_y[c4_i166];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_DePascali4M_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_createstruct("structure", 2, 64, 1),
                false);
  c4_info_helper(&c4_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c4_nameCaptureInfo);
  return c4_nameCaptureInfo;
}

static void c4_info_helper(const mxArray **c4_info)
{
  const mxArray *c4_rhs0 = NULL;
  const mxArray *c4_lhs0 = NULL;
  const mxArray *c4_rhs1 = NULL;
  const mxArray *c4_lhs1 = NULL;
  const mxArray *c4_rhs2 = NULL;
  const mxArray *c4_lhs2 = NULL;
  const mxArray *c4_rhs3 = NULL;
  const mxArray *c4_lhs3 = NULL;
  const mxArray *c4_rhs4 = NULL;
  const mxArray *c4_lhs4 = NULL;
  const mxArray *c4_rhs5 = NULL;
  const mxArray *c4_lhs5 = NULL;
  const mxArray *c4_rhs6 = NULL;
  const mxArray *c4_lhs6 = NULL;
  const mxArray *c4_rhs7 = NULL;
  const mxArray *c4_lhs7 = NULL;
  const mxArray *c4_rhs8 = NULL;
  const mxArray *c4_lhs8 = NULL;
  const mxArray *c4_rhs9 = NULL;
  const mxArray *c4_lhs9 = NULL;
  const mxArray *c4_rhs10 = NULL;
  const mxArray *c4_lhs10 = NULL;
  const mxArray *c4_rhs11 = NULL;
  const mxArray *c4_lhs11 = NULL;
  const mxArray *c4_rhs12 = NULL;
  const mxArray *c4_lhs12 = NULL;
  const mxArray *c4_rhs13 = NULL;
  const mxArray *c4_lhs13 = NULL;
  const mxArray *c4_rhs14 = NULL;
  const mxArray *c4_lhs14 = NULL;
  const mxArray *c4_rhs15 = NULL;
  const mxArray *c4_lhs15 = NULL;
  const mxArray *c4_rhs16 = NULL;
  const mxArray *c4_lhs16 = NULL;
  const mxArray *c4_rhs17 = NULL;
  const mxArray *c4_lhs17 = NULL;
  const mxArray *c4_rhs18 = NULL;
  const mxArray *c4_lhs18 = NULL;
  const mxArray *c4_rhs19 = NULL;
  const mxArray *c4_lhs19 = NULL;
  const mxArray *c4_rhs20 = NULL;
  const mxArray *c4_lhs20 = NULL;
  const mxArray *c4_rhs21 = NULL;
  const mxArray *c4_lhs21 = NULL;
  const mxArray *c4_rhs22 = NULL;
  const mxArray *c4_lhs22 = NULL;
  const mxArray *c4_rhs23 = NULL;
  const mxArray *c4_lhs23 = NULL;
  const mxArray *c4_rhs24 = NULL;
  const mxArray *c4_lhs24 = NULL;
  const mxArray *c4_rhs25 = NULL;
  const mxArray *c4_lhs25 = NULL;
  const mxArray *c4_rhs26 = NULL;
  const mxArray *c4_lhs26 = NULL;
  const mxArray *c4_rhs27 = NULL;
  const mxArray *c4_lhs27 = NULL;
  const mxArray *c4_rhs28 = NULL;
  const mxArray *c4_lhs28 = NULL;
  const mxArray *c4_rhs29 = NULL;
  const mxArray *c4_lhs29 = NULL;
  const mxArray *c4_rhs30 = NULL;
  const mxArray *c4_lhs30 = NULL;
  const mxArray *c4_rhs31 = NULL;
  const mxArray *c4_lhs31 = NULL;
  const mxArray *c4_rhs32 = NULL;
  const mxArray *c4_lhs32 = NULL;
  const mxArray *c4_rhs33 = NULL;
  const mxArray *c4_lhs33 = NULL;
  const mxArray *c4_rhs34 = NULL;
  const mxArray *c4_lhs34 = NULL;
  const mxArray *c4_rhs35 = NULL;
  const mxArray *c4_lhs35 = NULL;
  const mxArray *c4_rhs36 = NULL;
  const mxArray *c4_lhs36 = NULL;
  const mxArray *c4_rhs37 = NULL;
  const mxArray *c4_lhs37 = NULL;
  const mxArray *c4_rhs38 = NULL;
  const mxArray *c4_lhs38 = NULL;
  const mxArray *c4_rhs39 = NULL;
  const mxArray *c4_lhs39 = NULL;
  const mxArray *c4_rhs40 = NULL;
  const mxArray *c4_lhs40 = NULL;
  const mxArray *c4_rhs41 = NULL;
  const mxArray *c4_lhs41 = NULL;
  const mxArray *c4_rhs42 = NULL;
  const mxArray *c4_lhs42 = NULL;
  const mxArray *c4_rhs43 = NULL;
  const mxArray *c4_lhs43 = NULL;
  const mxArray *c4_rhs44 = NULL;
  const mxArray *c4_lhs44 = NULL;
  const mxArray *c4_rhs45 = NULL;
  const mxArray *c4_lhs45 = NULL;
  const mxArray *c4_rhs46 = NULL;
  const mxArray *c4_lhs46 = NULL;
  const mxArray *c4_rhs47 = NULL;
  const mxArray *c4_lhs47 = NULL;
  const mxArray *c4_rhs48 = NULL;
  const mxArray *c4_lhs48 = NULL;
  const mxArray *c4_rhs49 = NULL;
  const mxArray *c4_lhs49 = NULL;
  const mxArray *c4_rhs50 = NULL;
  const mxArray *c4_lhs50 = NULL;
  const mxArray *c4_rhs51 = NULL;
  const mxArray *c4_lhs51 = NULL;
  const mxArray *c4_rhs52 = NULL;
  const mxArray *c4_lhs52 = NULL;
  const mxArray *c4_rhs53 = NULL;
  const mxArray *c4_lhs53 = NULL;
  const mxArray *c4_rhs54 = NULL;
  const mxArray *c4_lhs54 = NULL;
  const mxArray *c4_rhs55 = NULL;
  const mxArray *c4_lhs55 = NULL;
  const mxArray *c4_rhs56 = NULL;
  const mxArray *c4_lhs56 = NULL;
  const mxArray *c4_rhs57 = NULL;
  const mxArray *c4_lhs57 = NULL;
  const mxArray *c4_rhs58 = NULL;
  const mxArray *c4_lhs58 = NULL;
  const mxArray *c4_rhs59 = NULL;
  const mxArray *c4_lhs59 = NULL;
  const mxArray *c4_rhs60 = NULL;
  const mxArray *c4_lhs60 = NULL;
  const mxArray *c4_rhs61 = NULL;
  const mxArray *c4_lhs61 = NULL;
  const mxArray *c4_rhs62 = NULL;
  const mxArray *c4_lhs62 = NULL;
  const mxArray *c4_rhs63 = NULL;
  const mxArray *c4_lhs63 = NULL;
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("quatrot"), "name", "name", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DePascaliErhart/quatrot.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1446631716U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c4_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DePascaliErhart/quatrot.m"),
                  "context", "context", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("quatconj"), "name", "name", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatconj.p"), "resolved", "resolved",
                  1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1410808258U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c4_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DePascaliErhart/quatrot.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("quatmultiply"), "name", "name",
                  2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatmultiply.p"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1410808258U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c4_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatmultiply.p"), "context",
                  "context", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("max"), "name", "name", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1311280516U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c4_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1378321184U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c4_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c4_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c4_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c4_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c4_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c4_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c4_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 11);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 11);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c4_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 12);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("mpower"), "name", "name", 12);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363739078U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c4_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 13);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c4_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("ismatrix"), "name", "name", 14);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1331330058U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c4_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("power"), "name", "name", 15);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1395353706U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c4_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 16);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c4_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 17);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 17);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c4_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 18);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 18);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c4_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 19);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("floor"), "name", "name", 19);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363739054U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c4_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 20);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c4_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 21);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286843926U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c4_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 22);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 22);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c4_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 23);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("mrdivide"), "name", "name", 23);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1410832848U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1370035086U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c4_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 24);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 24);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1389742974U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c4_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 25);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("rdivide"), "name", "name", 25);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363739080U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c4_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 26);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c4_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 27);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286843996U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c4_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_div"), "name", "name", 28);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1386449152U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c4_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 29);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c4_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 30);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eye"), "name", "name", 30);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1406838348U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c4_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 31);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1368208230U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c4_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 32);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 32);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c4_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral"),
                  "context", "context", 33);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("isinf"), "name", "name", 33);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363739056U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c4_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 34);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c4_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 35);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_is_integer_class"), "name",
                  "name", 35);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286843982U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c4_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 36);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("intmax"), "name", "name", 36);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c4_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 37);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c4_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 38);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("intmin"), "name", "name", 38);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c4_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 39);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 39);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c4_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 40);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.indexIntRelop"),
                  "name", "name", 40);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1326753522U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c4_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!apply_float_relop"),
                  "context", "context", 41);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 41);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c4_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass"),
                  "context", "context", 42);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 42);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1326753196U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c4_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass"),
                  "context", "context", 43);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("intmin"), "name", "name", 43);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 43);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c4_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 44);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 44);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c4_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 45);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("intmax"), "name", "name", 45);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 45);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c4_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "context",
                  "context", 46);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 46);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1397282622U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c4_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 47);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("isfi"), "name", "name", 47);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 47);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 47);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1346535558U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c4_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 48);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 48);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 48);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1398900798U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c4_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 49);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("intmax"), "name", "name", 49);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 49);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c4_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 50);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("intmin"), "name", "name", 50);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 50);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1362287082U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c4_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 51);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("skew_sm"), "name", "name", 51);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DePascaliErhart/skew_sm.m"),
                  "resolved", "resolved", 51);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1445505143U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c4_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 52);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 52);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 52);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1383902494U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c4_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 53);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 53);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 53);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c4_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 54);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 54);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 54);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c4_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 55);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 55);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 55);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c4_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 56);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  56);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 56);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1376005890U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c4_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 57);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 57);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 57);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c4_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 58);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 58);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 58);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c4_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 59);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 59);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 59);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c4_rhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 60);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.blas.threshold"),
                  "name", "name", 60);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 60);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 60);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c4_rhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs60), "lhs", "lhs",
                  60);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 61);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 61);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 61);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 61);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1393356058U), "fileTimeLo",
                  "fileTimeLo", 61);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 61);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 61);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 61);
  sf_mex_assign(&c4_rhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs61), "rhs", "rhs",
                  61);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs61), "lhs", "lhs",
                  61);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 62);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 62);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 62);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 62);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 62);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 62);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 62);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 62);
  sf_mex_assign(&c4_rhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs62), "rhs", "rhs",
                  62);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs62), "lhs", "lhs",
                  62);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 63);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.refblas.xgemm"),
                  "name", "name", 63);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 63);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 63);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1410832972U), "fileTimeLo",
                  "fileTimeLo", 63);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 63);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 63);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 63);
  sf_mex_assign(&c4_rhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs63), "rhs", "rhs",
                  63);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs63), "lhs", "lhs",
                  63);
  sf_mex_destroy(&c4_rhs0);
  sf_mex_destroy(&c4_lhs0);
  sf_mex_destroy(&c4_rhs1);
  sf_mex_destroy(&c4_lhs1);
  sf_mex_destroy(&c4_rhs2);
  sf_mex_destroy(&c4_lhs2);
  sf_mex_destroy(&c4_rhs3);
  sf_mex_destroy(&c4_lhs3);
  sf_mex_destroy(&c4_rhs4);
  sf_mex_destroy(&c4_lhs4);
  sf_mex_destroy(&c4_rhs5);
  sf_mex_destroy(&c4_lhs5);
  sf_mex_destroy(&c4_rhs6);
  sf_mex_destroy(&c4_lhs6);
  sf_mex_destroy(&c4_rhs7);
  sf_mex_destroy(&c4_lhs7);
  sf_mex_destroy(&c4_rhs8);
  sf_mex_destroy(&c4_lhs8);
  sf_mex_destroy(&c4_rhs9);
  sf_mex_destroy(&c4_lhs9);
  sf_mex_destroy(&c4_rhs10);
  sf_mex_destroy(&c4_lhs10);
  sf_mex_destroy(&c4_rhs11);
  sf_mex_destroy(&c4_lhs11);
  sf_mex_destroy(&c4_rhs12);
  sf_mex_destroy(&c4_lhs12);
  sf_mex_destroy(&c4_rhs13);
  sf_mex_destroy(&c4_lhs13);
  sf_mex_destroy(&c4_rhs14);
  sf_mex_destroy(&c4_lhs14);
  sf_mex_destroy(&c4_rhs15);
  sf_mex_destroy(&c4_lhs15);
  sf_mex_destroy(&c4_rhs16);
  sf_mex_destroy(&c4_lhs16);
  sf_mex_destroy(&c4_rhs17);
  sf_mex_destroy(&c4_lhs17);
  sf_mex_destroy(&c4_rhs18);
  sf_mex_destroy(&c4_lhs18);
  sf_mex_destroy(&c4_rhs19);
  sf_mex_destroy(&c4_lhs19);
  sf_mex_destroy(&c4_rhs20);
  sf_mex_destroy(&c4_lhs20);
  sf_mex_destroy(&c4_rhs21);
  sf_mex_destroy(&c4_lhs21);
  sf_mex_destroy(&c4_rhs22);
  sf_mex_destroy(&c4_lhs22);
  sf_mex_destroy(&c4_rhs23);
  sf_mex_destroy(&c4_lhs23);
  sf_mex_destroy(&c4_rhs24);
  sf_mex_destroy(&c4_lhs24);
  sf_mex_destroy(&c4_rhs25);
  sf_mex_destroy(&c4_lhs25);
  sf_mex_destroy(&c4_rhs26);
  sf_mex_destroy(&c4_lhs26);
  sf_mex_destroy(&c4_rhs27);
  sf_mex_destroy(&c4_lhs27);
  sf_mex_destroy(&c4_rhs28);
  sf_mex_destroy(&c4_lhs28);
  sf_mex_destroy(&c4_rhs29);
  sf_mex_destroy(&c4_lhs29);
  sf_mex_destroy(&c4_rhs30);
  sf_mex_destroy(&c4_lhs30);
  sf_mex_destroy(&c4_rhs31);
  sf_mex_destroy(&c4_lhs31);
  sf_mex_destroy(&c4_rhs32);
  sf_mex_destroy(&c4_lhs32);
  sf_mex_destroy(&c4_rhs33);
  sf_mex_destroy(&c4_lhs33);
  sf_mex_destroy(&c4_rhs34);
  sf_mex_destroy(&c4_lhs34);
  sf_mex_destroy(&c4_rhs35);
  sf_mex_destroy(&c4_lhs35);
  sf_mex_destroy(&c4_rhs36);
  sf_mex_destroy(&c4_lhs36);
  sf_mex_destroy(&c4_rhs37);
  sf_mex_destroy(&c4_lhs37);
  sf_mex_destroy(&c4_rhs38);
  sf_mex_destroy(&c4_lhs38);
  sf_mex_destroy(&c4_rhs39);
  sf_mex_destroy(&c4_lhs39);
  sf_mex_destroy(&c4_rhs40);
  sf_mex_destroy(&c4_lhs40);
  sf_mex_destroy(&c4_rhs41);
  sf_mex_destroy(&c4_lhs41);
  sf_mex_destroy(&c4_rhs42);
  sf_mex_destroy(&c4_lhs42);
  sf_mex_destroy(&c4_rhs43);
  sf_mex_destroy(&c4_lhs43);
  sf_mex_destroy(&c4_rhs44);
  sf_mex_destroy(&c4_lhs44);
  sf_mex_destroy(&c4_rhs45);
  sf_mex_destroy(&c4_lhs45);
  sf_mex_destroy(&c4_rhs46);
  sf_mex_destroy(&c4_lhs46);
  sf_mex_destroy(&c4_rhs47);
  sf_mex_destroy(&c4_lhs47);
  sf_mex_destroy(&c4_rhs48);
  sf_mex_destroy(&c4_lhs48);
  sf_mex_destroy(&c4_rhs49);
  sf_mex_destroy(&c4_lhs49);
  sf_mex_destroy(&c4_rhs50);
  sf_mex_destroy(&c4_lhs50);
  sf_mex_destroy(&c4_rhs51);
  sf_mex_destroy(&c4_lhs51);
  sf_mex_destroy(&c4_rhs52);
  sf_mex_destroy(&c4_lhs52);
  sf_mex_destroy(&c4_rhs53);
  sf_mex_destroy(&c4_lhs53);
  sf_mex_destroy(&c4_rhs54);
  sf_mex_destroy(&c4_lhs54);
  sf_mex_destroy(&c4_rhs55);
  sf_mex_destroy(&c4_lhs55);
  sf_mex_destroy(&c4_rhs56);
  sf_mex_destroy(&c4_lhs56);
  sf_mex_destroy(&c4_rhs57);
  sf_mex_destroy(&c4_lhs57);
  sf_mex_destroy(&c4_rhs58);
  sf_mex_destroy(&c4_lhs58);
  sf_mex_destroy(&c4_rhs59);
  sf_mex_destroy(&c4_lhs59);
  sf_mex_destroy(&c4_rhs60);
  sf_mex_destroy(&c4_lhs60);
  sf_mex_destroy(&c4_rhs61);
  sf_mex_destroy(&c4_lhs61);
  sf_mex_destroy(&c4_rhs62);
  sf_mex_destroy(&c4_lhs62);
  sf_mex_destroy(&c4_rhs63);
  sf_mex_destroy(&c4_lhs63);
}

static const mxArray *c4_emlrt_marshallOut(const char * c4_u)
{
  const mxArray *c4_y = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c4_u)), false);
  return c4_y;
}

static const mxArray *c4_b_emlrt_marshallOut(const uint32_T c4_u)
{
  const mxArray *c4_y = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 7, 0U, 0U, 0U, 0), false);
  return c4_y;
}

static void c4_quatmultiply(SFc4_DePascali4MInstanceStruct *chartInstance,
  real_T c4_q[4], real_T c4_b_r[4], real_T c4_qout[4])
{
  real_T c4_q1;
  real_T c4_q2;
  real_T c4_q3;
  real_T c4_q4;
  real_T c4_r1;
  real_T c4_r2;
  real_T c4_r3;
  real_T c4_r4;
  (void)chartInstance;
  c4_q1 = c4_q[0];
  c4_q2 = c4_q[1];
  c4_q3 = c4_q[2];
  c4_q4 = c4_q[3];
  c4_r1 = c4_b_r[0];
  c4_r2 = c4_b_r[1];
  c4_r3 = c4_b_r[2];
  c4_r4 = c4_b_r[3];
  c4_qout[0] = ((c4_q1 * c4_r1 - c4_q2 * c4_r2) - c4_q3 * c4_r3) - c4_q4 * c4_r4;
  c4_qout[1] = (c4_q1 * c4_r2 + c4_r1 * c4_q2) + (c4_q3 * c4_r4 - c4_q4 * c4_r3);
  c4_qout[2] = (c4_q1 * c4_r3 + c4_r1 * c4_q3) + (c4_q4 * c4_r2 - c4_q2 * c4_r4);
  c4_qout[3] = (c4_q1 * c4_r4 + c4_r1 * c4_q4) + (c4_q2 * c4_r3 - c4_q3 * c4_r2);
}

static void c4_eml_scalar_eg(SFc4_DePascali4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c4_mpower(SFc4_DePascali4MInstanceStruct *chartInstance, real_T
  c4_a)
{
  real_T c4_b_a;
  real_T c4_c_a;
  real_T c4_ak;
  real_T c4_d_a;
  c4_b_a = c4_a;
  c4_c_a = c4_b_a;
  c4_eml_scalar_eg(chartInstance);
  c4_ak = c4_c_a;
  c4_d_a = c4_ak;
  c4_eml_scalar_eg(chartInstance);
  return c4_d_a * c4_d_a;
}

static real_T c4_b_mpower(SFc4_DePascali4MInstanceStruct *chartInstance, real_T
  c4_a)
{
  real_T c4_b_a;
  real_T c4_c_a;
  real_T c4_ak;
  real_T c4_d_a;
  real_T c4_ar;
  c4_b_a = c4_a;
  c4_c_a = c4_b_a;
  c4_eml_scalar_eg(chartInstance);
  c4_ak = c4_c_a;
  c4_d_a = c4_ak;
  c4_eml_scalar_eg(chartInstance);
  c4_ar = c4_d_a;
  return muDoubleScalarPower(c4_ar, 4.0);
}

static real_T c4_c_mpower(SFc4_DePascali4MInstanceStruct *chartInstance, real_T
  c4_a)
{
  real_T c4_b_a;
  real_T c4_c_a;
  real_T c4_ak;
  real_T c4_d_a;
  real_T c4_ar;
  c4_b_a = c4_a;
  c4_c_a = c4_b_a;
  c4_eml_scalar_eg(chartInstance);
  c4_ak = c4_c_a;
  c4_d_a = c4_ak;
  c4_eml_scalar_eg(chartInstance);
  c4_ar = c4_d_a;
  return muDoubleScalarPower(c4_ar, 3.0);
}

static void c4_eye(SFc4_DePascali4MInstanceStruct *chartInstance, real_T c4_I[9])
{
  int32_T c4_i167;
  int32_T c4_k;
  int32_T c4_b_k;
  (void)chartInstance;
  for (c4_i167 = 0; c4_i167 < 9; c4_i167++) {
    c4_I[c4_i167] = 0.0;
  }

  for (c4_k = 1; c4_k < 4; c4_k++) {
    c4_b_k = c4_k;
    c4_I[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c4_b_k), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", (real_T)c4_b_k), 1, 3, 2, 0) - 1)) -
      1] = 1.0;
  }
}

static void c4_b_eml_scalar_eg(SFc4_DePascali4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c4_eml_xgemm(SFc4_DePascali4MInstanceStruct *chartInstance, real_T
  c4_A[9], real_T c4_B[9], real_T c4_C[9], real_T c4_b_C[9])
{
  int32_T c4_i168;
  int32_T c4_i169;
  real_T c4_b_A[9];
  int32_T c4_i170;
  real_T c4_b_B[9];
  for (c4_i168 = 0; c4_i168 < 9; c4_i168++) {
    c4_b_C[c4_i168] = c4_C[c4_i168];
  }

  for (c4_i169 = 0; c4_i169 < 9; c4_i169++) {
    c4_b_A[c4_i169] = c4_A[c4_i169];
  }

  for (c4_i170 = 0; c4_i170 < 9; c4_i170++) {
    c4_b_B[c4_i170] = c4_B[c4_i170];
  }

  c4_b_eml_xgemm(chartInstance, c4_b_A, c4_b_B, c4_b_C);
}

static const mxArray *c4_h_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc4_DePascali4MInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static int32_T c4_h_emlrt_marshallIn(SFc4_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i171;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i171, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i171;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_DePascali4MInstanceStruct *chartInstance;
  chartInstance = (SFc4_DePascali4MInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_i_emlrt_marshallIn(SFc4_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_DePascali4M, const char_T
  *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_DePascali4M), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_DePascali4M);
  return c4_y;
}

static uint8_T c4_j_emlrt_marshallIn(SFc4_DePascali4MInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_eml_xgemm(SFc4_DePascali4MInstanceStruct *chartInstance, real_T
  c4_A[9], real_T c4_B[9], real_T c4_C[9])
{
  int32_T c4_i172;
  int32_T c4_i173;
  int32_T c4_i174;
  int32_T c4_i175;
  int32_T c4_i176;
  (void)chartInstance;
  for (c4_i172 = 0; c4_i172 < 3; c4_i172++) {
    c4_i173 = 0;
    for (c4_i174 = 0; c4_i174 < 3; c4_i174++) {
      c4_C[c4_i173 + c4_i172] = 0.0;
      c4_i175 = 0;
      for (c4_i176 = 0; c4_i176 < 3; c4_i176++) {
        c4_C[c4_i173 + c4_i172] += c4_A[c4_i175 + c4_i172] * c4_B[c4_i176 +
          c4_i173];
        c4_i175 += 3;
      }

      c4_i173 += 3;
    }
  }
}

static void init_dsm_address_info(SFc4_DePascali4MInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc4_DePascali4MInstanceStruct
  *chartInstance)
{
  chartInstance->c4_x = (real_T (*)[28])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c4_Ginv = (real_T (*)[144])ssGetOutputPortSignal_wrapper
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

void sf_c4_DePascali4M_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1854340884U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(739156495U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2877586674U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4023641332U);
}

mxArray* sf_c4_DePascali4M_get_post_codegen_info(void);
mxArray *sf_c4_DePascali4M_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("A0QwzvzXoJwZPIs1YTaSYE");
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
      pr[0] = (double)(24);
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
    mxArray* mxPostCodegenInfo = sf_c4_DePascali4M_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c4_DePascali4M_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_DePascali4M_jit_fallback_info(void)
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

mxArray *sf_c4_DePascali4M_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c4_DePascali4M_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c4_DePascali4M(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Ginv\",},{M[8],M[0],T\"is_active_c4_DePascali4M\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_DePascali4M_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_DePascali4MInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc4_DePascali4MInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DePascali4MMachineNumber_,
           4,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"x");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Ginv");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,98777);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"quatrot",0,-1,191);
        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"skew_sm",0,-1,127);

        {
          unsigned int dimVector[1];
          dimVector[0]= 28;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 24;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)
            c4_b_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c4_x);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c4_Ginv);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c4_r);
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
  return "raSxi4CTnTmwsASm4liXMH";
}

static void sf_opaque_initialize_c4_DePascali4M(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_DePascali4MInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c4_DePascali4M((SFc4_DePascali4MInstanceStruct*)
    chartInstanceVar);
  initialize_c4_DePascali4M((SFc4_DePascali4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_DePascali4M(void *chartInstanceVar)
{
  enable_c4_DePascali4M((SFc4_DePascali4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_DePascali4M(void *chartInstanceVar)
{
  disable_c4_DePascali4M((SFc4_DePascali4MInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_DePascali4M(void *chartInstanceVar)
{
  sf_gateway_c4_DePascali4M((SFc4_DePascali4MInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c4_DePascali4M(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c4_DePascali4M((SFc4_DePascali4MInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c4_DePascali4M(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c4_DePascali4M((SFc4_DePascali4MInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c4_DePascali4M(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_DePascali4MInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DePascali4M_optimization_info();
    }

    finalize_c4_DePascali4M((SFc4_DePascali4MInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_DePascali4M((SFc4_DePascali4MInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_DePascali4M(SimStruct *S)
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
    initialize_params_c4_DePascali4M((SFc4_DePascali4MInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_DePascali4M(SimStruct *S)
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
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,4,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1780260983U));
  ssSetChecksum1(S,(1481024654U));
  ssSetChecksum2(S,(3755572605U));
  ssSetChecksum3(S,(1341504910U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_DePascali4M(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_DePascali4M(SimStruct *S)
{
  SFc4_DePascali4MInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc4_DePascali4MInstanceStruct *)utMalloc(sizeof
    (SFc4_DePascali4MInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_DePascali4MInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_DePascali4M;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c4_DePascali4M;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c4_DePascali4M;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_DePascali4M;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_DePascali4M;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c4_DePascali4M;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c4_DePascali4M;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_DePascali4M;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_DePascali4M;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_DePascali4M;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_DePascali4M;
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

void c4_DePascali4M_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_DePascali4M(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_DePascali4M(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_DePascali4M(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_DePascali4M_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

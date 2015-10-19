/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Model1angular_sfun.h"
#include "c15_Model1angular.h"
#include "mwmathutil.h"
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
static const char * c15_debug_family_names[4] = { "nargin", "nargout", "x",
  "A_xyz" };

/* Function Declarations */
static void initialize_c15_Model1angular(SFc15_Model1angularInstanceStruct
  *chartInstance);
static void initialize_params_c15_Model1angular
  (SFc15_Model1angularInstanceStruct *chartInstance);
static void enable_c15_Model1angular(SFc15_Model1angularInstanceStruct
  *chartInstance);
static void disable_c15_Model1angular(SFc15_Model1angularInstanceStruct
  *chartInstance);
static void c15_update_debugger_state_c15_Model1angular
  (SFc15_Model1angularInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c15_Model1angular
  (SFc15_Model1angularInstanceStruct *chartInstance);
static void set_sim_state_c15_Model1angular(SFc15_Model1angularInstanceStruct
  *chartInstance, const mxArray *c15_st);
static void finalize_c15_Model1angular(SFc15_Model1angularInstanceStruct
  *chartInstance);
static void sf_gateway_c15_Model1angular(SFc15_Model1angularInstanceStruct
  *chartInstance);
static void mdl_start_c15_Model1angular(SFc15_Model1angularInstanceStruct
  *chartInstance);
static void initSimStructsc15_Model1angular(SFc15_Model1angularInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber, uint32_T c15_instanceNumber);
static const mxArray *c15_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static void c15_emlrt_marshallIn(SFc15_Model1angularInstanceStruct
  *chartInstance, const mxArray *c15_b_A_xyz, const char_T *c15_identifier,
  real_T c15_y[9]);
static void c15_b_emlrt_marshallIn(SFc15_Model1angularInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[9]);
static void c15_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_b_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static const mxArray *c15_c_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static real_T c15_c_emlrt_marshallIn(SFc15_Model1angularInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static void c15_info_helper(const mxArray **c15_info);
static const mxArray *c15_emlrt_marshallOut(const char * c15_u);
static const mxArray *c15_b_emlrt_marshallOut(const uint32_T c15_u);
static const mxArray *c15_d_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static int32_T c15_d_emlrt_marshallIn(SFc15_Model1angularInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static uint8_T c15_e_emlrt_marshallIn(SFc15_Model1angularInstanceStruct
  *chartInstance, const mxArray *c15_b_is_active_c15_Model1angular, const char_T
  *c15_identifier);
static uint8_T c15_f_emlrt_marshallIn(SFc15_Model1angularInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void init_dsm_address_info(SFc15_Model1angularInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc15_Model1angularInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c15_Model1angular(SFc15_Model1angularInstanceStruct
  *chartInstance)
{
  chartInstance->c15_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c15_is_active_c15_Model1angular = 0U;
}

static void initialize_params_c15_Model1angular
  (SFc15_Model1angularInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c15_Model1angular(SFc15_Model1angularInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c15_Model1angular(SFc15_Model1angularInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c15_update_debugger_state_c15_Model1angular
  (SFc15_Model1angularInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c15_Model1angular
  (SFc15_Model1angularInstanceStruct *chartInstance)
{
  const mxArray *c15_st;
  const mxArray *c15_y = NULL;
  int32_T c15_i0;
  real_T c15_u[9];
  const mxArray *c15_b_y = NULL;
  uint8_T c15_hoistedGlobal;
  uint8_T c15_b_u;
  const mxArray *c15_c_y = NULL;
  c15_st = NULL;
  c15_st = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_createcellmatrix(2, 1), false);
  for (c15_i0 = 0; c15_i0 < 9; c15_i0++) {
    c15_u[c15_i0] = (*chartInstance->c15_A_xyz)[c15_i0];
  }

  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 2, 3, 3),
                false);
  sf_mex_setcell(c15_y, 0, c15_b_y);
  c15_hoistedGlobal = chartInstance->c15_is_active_c15_Model1angular;
  c15_b_u = c15_hoistedGlobal;
  c15_c_y = NULL;
  sf_mex_assign(&c15_c_y, sf_mex_create("y", &c15_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c15_y, 1, c15_c_y);
  sf_mex_assign(&c15_st, c15_y, false);
  return c15_st;
}

static void set_sim_state_c15_Model1angular(SFc15_Model1angularInstanceStruct
  *chartInstance, const mxArray *c15_st)
{
  const mxArray *c15_u;
  real_T c15_dv0[9];
  int32_T c15_i1;
  chartInstance->c15_doneDoubleBufferReInit = true;
  c15_u = sf_mex_dup(c15_st);
  c15_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 0)),
                       "A_xyz", c15_dv0);
  for (c15_i1 = 0; c15_i1 < 9; c15_i1++) {
    (*chartInstance->c15_A_xyz)[c15_i1] = c15_dv0[c15_i1];
  }

  chartInstance->c15_is_active_c15_Model1angular = c15_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 1)),
     "is_active_c15_Model1angular");
  sf_mex_destroy(&c15_u);
  c15_update_debugger_state_c15_Model1angular(chartInstance);
  sf_mex_destroy(&c15_st);
}

static void finalize_c15_Model1angular(SFc15_Model1angularInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c15_Model1angular(SFc15_Model1angularInstanceStruct
  *chartInstance)
{
  int32_T c15_i2;
  int32_T c15_i3;
  real_T c15_b_x[18];
  uint32_T c15_debug_family_var_map[4];
  real_T c15_nargin = 1.0;
  real_T c15_nargout = 1.0;
  real_T c15_b_A_xyz[9];
  real_T c15_c_x;
  real_T c15_d_x;
  real_T c15_e_x;
  real_T c15_f_x;
  real_T c15_g_x;
  real_T c15_h_x;
  real_T c15_i_x;
  real_T c15_j_x;
  real_T c15_k_x;
  real_T c15_l_x;
  real_T c15_m_x;
  real_T c15_n_x;
  real_T c15_o_x;
  real_T c15_p_x;
  real_T c15_q_x;
  real_T c15_r_x;
  real_T c15_s_x;
  real_T c15_t_x;
  real_T c15_u_x;
  real_T c15_v_x;
  real_T c15_w_x;
  real_T c15_x_x;
  real_T c15_y_x;
  real_T c15_ab_x;
  real_T c15_bb_x;
  real_T c15_cb_x;
  real_T c15_db_x;
  real_T c15_eb_x;
  real_T c15_fb_x;
  real_T c15_gb_x;
  real_T c15_hb_x;
  real_T c15_ib_x;
  real_T c15_jb_x;
  real_T c15_kb_x;
  real_T c15_lb_x;
  real_T c15_mb_x;
  real_T c15_nb_x;
  real_T c15_ob_x;
  real_T c15_pb_x;
  real_T c15_qb_x;
  real_T c15_rb_x;
  real_T c15_sb_x;
  real_T c15_tb_x;
  real_T c15_ub_x;
  real_T c15_vb_x;
  real_T c15_wb_x;
  real_T c15_xb_x;
  real_T c15_yb_x;
  real_T c15_ac_x;
  real_T c15_bc_x;
  real_T c15_cc_x;
  real_T c15_dc_x;
  real_T c15_ec_x;
  real_T c15_fc_x;
  real_T c15_gc_x;
  real_T c15_hc_x;
  real_T c15_ic_x;
  real_T c15_jc_x;
  int32_T c15_i4;
  int32_T c15_i5;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 14U, chartInstance->c15_sfEvent);
  for (c15_i2 = 0; c15_i2 < 18; c15_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c15_x)[c15_i2], 0U);
  }

  chartInstance->c15_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 14U, chartInstance->c15_sfEvent);
  for (c15_i3 = 0; c15_i3 < 18; c15_i3++) {
    c15_b_x[c15_i3] = (*chartInstance->c15_x)[c15_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c15_debug_family_names,
    c15_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargin, 0U, c15_c_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargout, 1U, c15_c_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c15_b_x, 2U, c15_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c15_b_A_xyz, 3U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 2);
  c15_c_x = c15_b_x[4];
  c15_d_x = c15_c_x;
  c15_d_x = muDoubleScalarCos(c15_d_x);
  c15_e_x = c15_b_x[5];
  c15_f_x = c15_e_x;
  c15_f_x = muDoubleScalarCos(c15_f_x);
  c15_g_x = c15_b_x[3];
  c15_h_x = c15_g_x;
  c15_h_x = muDoubleScalarCos(c15_h_x);
  c15_i_x = c15_b_x[5];
  c15_j_x = c15_i_x;
  c15_j_x = muDoubleScalarSin(c15_j_x);
  c15_k_x = c15_b_x[3];
  c15_l_x = c15_k_x;
  c15_l_x = muDoubleScalarSin(c15_l_x);
  c15_m_x = c15_b_x[4];
  c15_n_x = c15_m_x;
  c15_n_x = muDoubleScalarSin(c15_n_x);
  c15_o_x = c15_b_x[5];
  c15_p_x = c15_o_x;
  c15_p_x = muDoubleScalarCos(c15_p_x);
  c15_q_x = c15_b_x[3];
  c15_r_x = c15_q_x;
  c15_r_x = muDoubleScalarSin(c15_r_x);
  c15_s_x = c15_b_x[5];
  c15_t_x = c15_s_x;
  c15_t_x = muDoubleScalarSin(c15_t_x);
  c15_u_x = c15_b_x[3];
  c15_v_x = c15_u_x;
  c15_v_x = muDoubleScalarCos(c15_v_x);
  c15_w_x = c15_b_x[4];
  c15_x_x = c15_w_x;
  c15_x_x = muDoubleScalarSin(c15_x_x);
  c15_y_x = c15_b_x[5];
  c15_ab_x = c15_y_x;
  c15_ab_x = muDoubleScalarCos(c15_ab_x);
  c15_bb_x = c15_b_x[4];
  c15_cb_x = c15_bb_x;
  c15_cb_x = muDoubleScalarCos(c15_cb_x);
  c15_db_x = c15_b_x[5];
  c15_eb_x = c15_db_x;
  c15_eb_x = muDoubleScalarSin(c15_eb_x);
  c15_fb_x = c15_b_x[3];
  c15_gb_x = c15_fb_x;
  c15_gb_x = muDoubleScalarCos(c15_gb_x);
  c15_hb_x = c15_b_x[5];
  c15_ib_x = c15_hb_x;
  c15_ib_x = muDoubleScalarCos(c15_ib_x);
  c15_jb_x = c15_b_x[3];
  c15_kb_x = c15_jb_x;
  c15_kb_x = muDoubleScalarSin(c15_kb_x);
  c15_lb_x = c15_b_x[4];
  c15_mb_x = c15_lb_x;
  c15_mb_x = muDoubleScalarSin(c15_mb_x);
  c15_nb_x = c15_b_x[5];
  c15_ob_x = c15_nb_x;
  c15_ob_x = muDoubleScalarSin(c15_ob_x);
  c15_pb_x = c15_b_x[3];
  c15_qb_x = c15_pb_x;
  c15_qb_x = muDoubleScalarSin(c15_qb_x);
  c15_rb_x = c15_b_x[5];
  c15_sb_x = c15_rb_x;
  c15_sb_x = muDoubleScalarCos(c15_sb_x);
  c15_tb_x = c15_b_x[3];
  c15_ub_x = c15_tb_x;
  c15_ub_x = muDoubleScalarCos(c15_ub_x);
  c15_vb_x = c15_b_x[4];
  c15_wb_x = c15_vb_x;
  c15_wb_x = muDoubleScalarSin(c15_wb_x);
  c15_xb_x = c15_b_x[5];
  c15_yb_x = c15_xb_x;
  c15_yb_x = muDoubleScalarSin(c15_yb_x);
  c15_ac_x = c15_b_x[3];
  c15_bc_x = c15_ac_x;
  c15_bc_x = muDoubleScalarSin(c15_bc_x);
  c15_cc_x = c15_b_x[3];
  c15_dc_x = c15_cc_x;
  c15_dc_x = muDoubleScalarSin(c15_dc_x);
  c15_ec_x = c15_b_x[4];
  c15_fc_x = c15_ec_x;
  c15_fc_x = muDoubleScalarCos(c15_fc_x);
  c15_gc_x = c15_b_x[3];
  c15_hc_x = c15_gc_x;
  c15_hc_x = muDoubleScalarCos(c15_hc_x);
  c15_ic_x = c15_b_x[4];
  c15_jc_x = c15_ic_x;
  c15_jc_x = muDoubleScalarCos(c15_jc_x);
  c15_b_A_xyz[0] = c15_d_x * c15_f_x;
  c15_b_A_xyz[3] = c15_h_x * c15_j_x + c15_l_x * c15_n_x * c15_p_x;
  c15_b_A_xyz[6] = c15_r_x * c15_t_x - c15_v_x * c15_x_x * c15_ab_x;
  c15_b_A_xyz[1] = -c15_cb_x * c15_eb_x;
  c15_b_A_xyz[4] = c15_gb_x * c15_ib_x - c15_kb_x * c15_mb_x * c15_ob_x;
  c15_b_A_xyz[7] = c15_qb_x * c15_sb_x + c15_ub_x * c15_wb_x * c15_yb_x;
  c15_b_A_xyz[2] = -c15_bc_x;
  c15_b_A_xyz[5] = -c15_dc_x * c15_fc_x;
  c15_b_A_xyz[8] = c15_hc_x * c15_jc_x;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, -2);
  _SFD_SYMBOL_SCOPE_POP();
  for (c15_i4 = 0; c15_i4 < 9; c15_i4++) {
    (*chartInstance->c15_A_xyz)[c15_i4] = c15_b_A_xyz[c15_i4];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c15_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Model1angularMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c15_i5 = 0; c15_i5 < 9; c15_i5++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c15_A_xyz)[c15_i5], 1U);
  }
}

static void mdl_start_c15_Model1angular(SFc15_Model1angularInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc15_Model1angular(SFc15_Model1angularInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber, uint32_T c15_instanceNumber)
{
  (void)c15_machineNumber;
  (void)c15_chartNumber;
  (void)c15_instanceNumber;
}

static const mxArray *c15_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i6;
  int32_T c15_i7;
  int32_T c15_i8;
  real_T c15_b_inData[9];
  int32_T c15_i9;
  int32_T c15_i10;
  int32_T c15_i11;
  real_T c15_u[9];
  const mxArray *c15_y = NULL;
  SFc15_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc15_Model1angularInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_i6 = 0;
  for (c15_i7 = 0; c15_i7 < 3; c15_i7++) {
    for (c15_i8 = 0; c15_i8 < 3; c15_i8++) {
      c15_b_inData[c15_i8 + c15_i6] = (*(real_T (*)[9])c15_inData)[c15_i8 +
        c15_i6];
    }

    c15_i6 += 3;
  }

  c15_i9 = 0;
  for (c15_i10 = 0; c15_i10 < 3; c15_i10++) {
    for (c15_i11 = 0; c15_i11 < 3; c15_i11++) {
      c15_u[c15_i11 + c15_i9] = c15_b_inData[c15_i11 + c15_i9];
    }

    c15_i9 += 3;
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static void c15_emlrt_marshallIn(SFc15_Model1angularInstanceStruct
  *chartInstance, const mxArray *c15_b_A_xyz, const char_T *c15_identifier,
  real_T c15_y[9])
{
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_A_xyz), &c15_thisId,
    c15_y);
  sf_mex_destroy(&c15_b_A_xyz);
}

static void c15_b_emlrt_marshallIn(SFc15_Model1angularInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[9])
{
  real_T c15_dv1[9];
  int32_T c15_i12;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv1, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c15_i12 = 0; c15_i12 < 9; c15_i12++) {
    c15_y[c15_i12] = c15_dv1[c15_i12];
  }

  sf_mex_destroy(&c15_u);
}

static void c15_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_b_A_xyz;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y[9];
  int32_T c15_i13;
  int32_T c15_i14;
  int32_T c15_i15;
  SFc15_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc15_Model1angularInstanceStruct *)chartInstanceVoid;
  c15_b_A_xyz = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_A_xyz), &c15_thisId,
    c15_y);
  sf_mex_destroy(&c15_b_A_xyz);
  c15_i13 = 0;
  for (c15_i14 = 0; c15_i14 < 3; c15_i14++) {
    for (c15_i15 = 0; c15_i15 < 3; c15_i15++) {
      (*(real_T (*)[9])c15_outData)[c15_i15 + c15_i13] = c15_y[c15_i15 + c15_i13];
    }

    c15_i13 += 3;
  }

  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_b_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i16;
  real_T c15_b_inData[18];
  int32_T c15_i17;
  real_T c15_u[18];
  const mxArray *c15_y = NULL;
  SFc15_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc15_Model1angularInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  for (c15_i16 = 0; c15_i16 < 18; c15_i16++) {
    c15_b_inData[c15_i16] = (*(real_T (*)[18])c15_inData)[c15_i16];
  }

  for (c15_i17 = 0; c15_i17 < 18; c15_i17++) {
    c15_u[c15_i17] = c15_b_inData[c15_i17];
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 1, 18), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static const mxArray *c15_c_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  real_T c15_u;
  const mxArray *c15_y = NULL;
  SFc15_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc15_Model1angularInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(real_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static real_T c15_c_emlrt_marshallIn(SFc15_Model1angularInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  real_T c15_y;
  real_T c15_d0;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_d0, 1, 0, 0U, 0, 0U, 0);
  c15_y = c15_d0;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_nargout;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y;
  SFc15_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc15_Model1angularInstanceStruct *)chartInstanceVoid;
  c15_nargout = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_nargout),
    &c15_thisId);
  sf_mex_destroy(&c15_nargout);
  *(real_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

const mxArray *sf_c15_Model1angular_get_eml_resolved_functions_info(void)
{
  const mxArray *c15_nameCaptureInfo = NULL;
  c15_nameCaptureInfo = NULL;
  sf_mex_assign(&c15_nameCaptureInfo, sf_mex_createstruct("structure", 2, 4, 1),
                false);
  c15_info_helper(&c15_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c15_nameCaptureInfo);
  return c15_nameCaptureInfo;
}

static void c15_info_helper(const mxArray **c15_info)
{
  const mxArray *c15_rhs0 = NULL;
  const mxArray *c15_lhs0 = NULL;
  const mxArray *c15_rhs1 = NULL;
  const mxArray *c15_lhs1 = NULL;
  const mxArray *c15_rhs2 = NULL;
  const mxArray *c15_lhs2 = NULL;
  const mxArray *c15_rhs3 = NULL;
  const mxArray *c15_lhs3 = NULL;
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("cos"), "name", "name", 0);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1395353696U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c15_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 1);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1286843922U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c15_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("sin"), "name", "name", 2);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1395353704U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c15_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 3);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1286843936U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c15_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs3), "lhs", "lhs",
                  3);
  sf_mex_destroy(&c15_rhs0);
  sf_mex_destroy(&c15_lhs0);
  sf_mex_destroy(&c15_rhs1);
  sf_mex_destroy(&c15_lhs1);
  sf_mex_destroy(&c15_rhs2);
  sf_mex_destroy(&c15_lhs2);
  sf_mex_destroy(&c15_rhs3);
  sf_mex_destroy(&c15_lhs3);
}

static const mxArray *c15_emlrt_marshallOut(const char * c15_u)
{
  const mxArray *c15_y = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c15_u)), false);
  return c15_y;
}

static const mxArray *c15_b_emlrt_marshallOut(const uint32_T c15_u)
{
  const mxArray *c15_y = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 7, 0U, 0U, 0U, 0), false);
  return c15_y;
}

static const mxArray *c15_d_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_u;
  const mxArray *c15_y = NULL;
  SFc15_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc15_Model1angularInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(int32_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static int32_T c15_d_emlrt_marshallIn(SFc15_Model1angularInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  int32_T c15_y;
  int32_T c15_i18;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_i18, 1, 6, 0U, 0, 0U, 0);
  c15_y = c15_i18;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_b_sfEvent;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  int32_T c15_y;
  SFc15_Model1angularInstanceStruct *chartInstance;
  chartInstance = (SFc15_Model1angularInstanceStruct *)chartInstanceVoid;
  c15_b_sfEvent = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_sfEvent),
    &c15_thisId);
  sf_mex_destroy(&c15_b_sfEvent);
  *(int32_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static uint8_T c15_e_emlrt_marshallIn(SFc15_Model1angularInstanceStruct
  *chartInstance, const mxArray *c15_b_is_active_c15_Model1angular, const char_T
  *c15_identifier)
{
  uint8_T c15_y;
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c15_b_is_active_c15_Model1angular), &c15_thisId);
  sf_mex_destroy(&c15_b_is_active_c15_Model1angular);
  return c15_y;
}

static uint8_T c15_f_emlrt_marshallIn(SFc15_Model1angularInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  uint8_T c15_y;
  uint8_T c15_u0;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_u0, 1, 3, 0U, 0, 0U, 0);
  c15_y = c15_u0;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void init_dsm_address_info(SFc15_Model1angularInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc15_Model1angularInstanceStruct
  *chartInstance)
{
  chartInstance->c15_x = (real_T (*)[18])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c15_A_xyz = (real_T (*)[9])ssGetOutputPortSignal_wrapper
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

void sf_c15_Model1angular_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4169045765U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2035474839U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1235347496U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2659053687U);
}

mxArray* sf_c15_Model1angular_get_post_codegen_info(void);
mxArray *sf_c15_Model1angular_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("A3MPTNcoSDNPKeamiJ1pVD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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
    mxArray* mxPostCodegenInfo = sf_c15_Model1angular_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c15_Model1angular_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c15_Model1angular_jit_fallback_info(void)
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

mxArray *sf_c15_Model1angular_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c15_Model1angular_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c15_Model1angular(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"A_xyz\",},{M[8],M[0],T\"is_active_c15_Model1angular\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c15_Model1angular_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc15_Model1angularInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc15_Model1angularInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Model1angularMachineNumber_,
           15,
           1,
           1,
           0,
           2,
           0,
           0,
           0,
           0,
           0,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"x");
          _SFD_SET_DATA_PROPS(1,2,0,1,"A_xyz");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,358);

        {
          unsigned int dimVector[1];
          dimVector[0]= 18;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c15_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)
            c15_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c15_x);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c15_A_xyz);
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
  return "blSJtnn3wEz7YP12eUHsp";
}

static void sf_opaque_initialize_c15_Model1angular(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc15_Model1angularInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c15_Model1angular((SFc15_Model1angularInstanceStruct*)
    chartInstanceVar);
  initialize_c15_Model1angular((SFc15_Model1angularInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c15_Model1angular(void *chartInstanceVar)
{
  enable_c15_Model1angular((SFc15_Model1angularInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c15_Model1angular(void *chartInstanceVar)
{
  disable_c15_Model1angular((SFc15_Model1angularInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c15_Model1angular(void *chartInstanceVar)
{
  sf_gateway_c15_Model1angular((SFc15_Model1angularInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c15_Model1angular(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c15_Model1angular((SFc15_Model1angularInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c15_Model1angular(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c15_Model1angular((SFc15_Model1angularInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c15_Model1angular(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc15_Model1angularInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Model1angular_optimization_info();
    }

    finalize_c15_Model1angular((SFc15_Model1angularInstanceStruct*)
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
  initSimStructsc15_Model1angular((SFc15_Model1angularInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c15_Model1angular(SimStruct *S)
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
    initialize_params_c15_Model1angular((SFc15_Model1angularInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c15_Model1angular(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Model1angular_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      15);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,15,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,15,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,15);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,15,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,15,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,15);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(96277264U));
  ssSetChecksum1(S,(3540917451U));
  ssSetChecksum2(S,(3411925545U));
  ssSetChecksum3(S,(3797589295U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c15_Model1angular(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c15_Model1angular(SimStruct *S)
{
  SFc15_Model1angularInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc15_Model1angularInstanceStruct *)utMalloc(sizeof
    (SFc15_Model1angularInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc15_Model1angularInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c15_Model1angular;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c15_Model1angular;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c15_Model1angular;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c15_Model1angular;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c15_Model1angular;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c15_Model1angular;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c15_Model1angular;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c15_Model1angular;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c15_Model1angular;
  chartInstance->chartInfo.mdlStart = mdlStart_c15_Model1angular;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c15_Model1angular;
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

void c15_Model1angular_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c15_Model1angular(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c15_Model1angular(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c15_Model1angular(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c15_Model1angular_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

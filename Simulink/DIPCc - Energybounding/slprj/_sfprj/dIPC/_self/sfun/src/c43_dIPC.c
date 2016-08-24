/* Include files */

#include <stddef.h>
#include "blas.h"
#include "dIPC_sfun.h"
#include "c43_dIPC.h"
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
static const char * c43_debug_family_names[5] = { "nargin", "nargout", "hw", "x",
  "h_int" };

static const char * c43_b_debug_family_names[6] = { "rwq", "nargin", "nargout",
  "q", "r", "rw" };

/* Function Declarations */
static void initialize_c43_dIPC(SFc43_dIPCInstanceStruct *chartInstance);
static void initialize_params_c43_dIPC(SFc43_dIPCInstanceStruct *chartInstance);
static void enable_c43_dIPC(SFc43_dIPCInstanceStruct *chartInstance);
static void disable_c43_dIPC(SFc43_dIPCInstanceStruct *chartInstance);
static void c43_update_debugger_state_c43_dIPC(SFc43_dIPCInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c43_dIPC(SFc43_dIPCInstanceStruct
  *chartInstance);
static void set_sim_state_c43_dIPC(SFc43_dIPCInstanceStruct *chartInstance,
  const mxArray *c43_st);
static void finalize_c43_dIPC(SFc43_dIPCInstanceStruct *chartInstance);
static void sf_gateway_c43_dIPC(SFc43_dIPCInstanceStruct *chartInstance);
static void mdl_start_c43_dIPC(SFc43_dIPCInstanceStruct *chartInstance);
static void initSimStructsc43_dIPC(SFc43_dIPCInstanceStruct *chartInstance);
static void c43_quatrot(SFc43_dIPCInstanceStruct *chartInstance, real_T c43_q[4],
  real_T c43_r[3], real_T c43_rw[3]);
static void init_script_number_translation(uint32_T c43_machineNumber, uint32_T
  c43_chartNumber, uint32_T c43_instanceNumber);
static const mxArray *c43_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData);
static void c43_emlrt_marshallIn(SFc43_dIPCInstanceStruct *chartInstance, const
  mxArray *c43_b_h_int, const char_T *c43_identifier, real_T c43_y[12]);
static void c43_b_emlrt_marshallIn(SFc43_dIPCInstanceStruct *chartInstance,
  const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId, real_T c43_y[12]);
static void c43_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData);
static const mxArray *c43_b_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData);
static const mxArray *c43_c_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData);
static real_T c43_c_emlrt_marshallIn(SFc43_dIPCInstanceStruct *chartInstance,
  const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId);
static void c43_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData);
static const mxArray *c43_d_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData);
static void c43_d_emlrt_marshallIn(SFc43_dIPCInstanceStruct *chartInstance,
  const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId, real_T c43_y[3]);
static void c43_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData);
static const mxArray *c43_e_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData);
static void c43_e_emlrt_marshallIn(SFc43_dIPCInstanceStruct *chartInstance,
  const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId, real_T c43_y[4]);
static void c43_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData);
static void c43_info_helper(const mxArray **c43_info);
static const mxArray *c43_emlrt_marshallOut(const char * c43_u);
static const mxArray *c43_b_emlrt_marshallOut(const uint32_T c43_u);
static void c43_quatmultiply(SFc43_dIPCInstanceStruct *chartInstance, real_T
  c43_q[4], real_T c43_r[4], real_T c43_qout[4]);
static const mxArray *c43_f_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData);
static int32_T c43_f_emlrt_marshallIn(SFc43_dIPCInstanceStruct *chartInstance,
  const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId);
static void c43_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData);
static uint8_T c43_g_emlrt_marshallIn(SFc43_dIPCInstanceStruct *chartInstance,
  const mxArray *c43_b_is_active_c43_dIPC, const char_T *c43_identifier);
static uint8_T c43_h_emlrt_marshallIn(SFc43_dIPCInstanceStruct *chartInstance,
  const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId);
static void init_dsm_address_info(SFc43_dIPCInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc43_dIPCInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c43_dIPC(SFc43_dIPCInstanceStruct *chartInstance)
{
  chartInstance->c43_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c43_is_active_c43_dIPC = 0U;
}

static void initialize_params_c43_dIPC(SFc43_dIPCInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c43_dIPC(SFc43_dIPCInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c43_dIPC(SFc43_dIPCInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c43_update_debugger_state_c43_dIPC(SFc43_dIPCInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c43_dIPC(SFc43_dIPCInstanceStruct
  *chartInstance)
{
  const mxArray *c43_st;
  const mxArray *c43_y = NULL;
  int32_T c43_i0;
  real_T c43_u[12];
  const mxArray *c43_b_y = NULL;
  uint8_T c43_hoistedGlobal;
  uint8_T c43_b_u;
  const mxArray *c43_c_y = NULL;
  c43_st = NULL;
  c43_st = NULL;
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_createcellmatrix(2, 1), false);
  for (c43_i0 = 0; c43_i0 < 12; c43_i0++) {
    c43_u[c43_i0] = (*chartInstance->c43_h_int)[c43_i0];
  }

  c43_b_y = NULL;
  sf_mex_assign(&c43_b_y, sf_mex_create("y", c43_u, 0, 0U, 1U, 0U, 1, 12), false);
  sf_mex_setcell(c43_y, 0, c43_b_y);
  c43_hoistedGlobal = chartInstance->c43_is_active_c43_dIPC;
  c43_b_u = c43_hoistedGlobal;
  c43_c_y = NULL;
  sf_mex_assign(&c43_c_y, sf_mex_create("y", &c43_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c43_y, 1, c43_c_y);
  sf_mex_assign(&c43_st, c43_y, false);
  return c43_st;
}

static void set_sim_state_c43_dIPC(SFc43_dIPCInstanceStruct *chartInstance,
  const mxArray *c43_st)
{
  const mxArray *c43_u;
  real_T c43_dv0[12];
  int32_T c43_i1;
  chartInstance->c43_doneDoubleBufferReInit = true;
  c43_u = sf_mex_dup(c43_st);
  c43_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c43_u, 0)),
                       "h_int", c43_dv0);
  for (c43_i1 = 0; c43_i1 < 12; c43_i1++) {
    (*chartInstance->c43_h_int)[c43_i1] = c43_dv0[c43_i1];
  }

  chartInstance->c43_is_active_c43_dIPC = c43_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c43_u, 1)), "is_active_c43_dIPC");
  sf_mex_destroy(&c43_u);
  c43_update_debugger_state_c43_dIPC(chartInstance);
  sf_mex_destroy(&c43_st);
}

static void finalize_c43_dIPC(SFc43_dIPCInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c43_dIPC(SFc43_dIPCInstanceStruct *chartInstance)
{
  int32_T c43_i2;
  int32_T c43_i3;
  int32_T c43_i4;
  real_T c43_b_hw[12];
  int32_T c43_i5;
  real_T c43_b_x[14];
  uint32_T c43_debug_family_var_map[5];
  real_T c43_nargin = 2.0;
  real_T c43_nargout = 1.0;
  real_T c43_b_h_int[12];
  int32_T c43_i6;
  real_T c43_q[4];
  int32_T c43_k;
  real_T c43_b_k;
  int32_T c43_i7;
  real_T c43_b_q[4];
  int32_T c43_c_k;
  real_T c43_d_k;
  int32_T c43_i8;
  real_T c43_c_q[4];
  int32_T c43_i9;
  real_T c43_c_hw[3];
  real_T c43_dv1[3];
  int32_T c43_i10;
  real_T c43_d_q[4];
  int32_T c43_i11;
  real_T c43_d_hw[3];
  real_T c43_dv2[3];
  int32_T c43_i12;
  int32_T c43_i13;
  int32_T c43_i14;
  int32_T c43_i15;
  int32_T c43_i16;
  int32_T c43_i17;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 17U, chartInstance->c43_sfEvent);
  for (c43_i2 = 0; c43_i2 < 12; c43_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c43_hw)[c43_i2], 0U);
  }

  for (c43_i3 = 0; c43_i3 < 14; c43_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c43_x)[c43_i3], 1U);
  }

  chartInstance->c43_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 17U, chartInstance->c43_sfEvent);
  for (c43_i4 = 0; c43_i4 < 12; c43_i4++) {
    c43_b_hw[c43_i4] = (*chartInstance->c43_hw)[c43_i4];
  }

  for (c43_i5 = 0; c43_i5 < 14; c43_i5++) {
    c43_b_x[c43_i5] = (*chartInstance->c43_x)[c43_i5];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c43_debug_family_names,
    c43_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_nargin, 0U, c43_c_sf_marshallOut,
    c43_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_nargout, 1U, c43_c_sf_marshallOut,
    c43_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c43_b_hw, 2U, c43_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c43_b_x, 3U, c43_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c43_b_h_int, 4U, c43_sf_marshallOut,
    c43_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 3);
  for (c43_i6 = 0; c43_i6 < 4; c43_i6++) {
    c43_q[c43_i6] = c43_b_x[c43_i6 + 3];
  }

  for (c43_k = 0; c43_k < 3; c43_k++) {
    c43_b_k = 2.0 + (real_T)c43_k;
    c43_q[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c43_b_k), 1, 4, 1, 0) - 1] = -c43_q[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", c43_b_k), 1, 4, 1, 0) - 1];
  }

  for (c43_i7 = 0; c43_i7 < 4; c43_i7++) {
    c43_b_q[c43_i7] = c43_b_x[c43_i7 + 3];
  }

  for (c43_c_k = 0; c43_c_k < 3; c43_c_k++) {
    c43_d_k = 2.0 + (real_T)c43_c_k;
    c43_b_q[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c43_d_k), 1, 4, 1, 0) - 1] = -c43_b_q[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", c43_d_k), 1, 4, 1, 0) - 1];
  }

  for (c43_i8 = 0; c43_i8 < 4; c43_i8++) {
    c43_c_q[c43_i8] = c43_q[c43_i8];
  }

  for (c43_i9 = 0; c43_i9 < 3; c43_i9++) {
    c43_c_hw[c43_i9] = c43_b_hw[c43_i9];
  }

  c43_quatrot(chartInstance, c43_c_q, c43_c_hw, c43_dv1);
  for (c43_i10 = 0; c43_i10 < 4; c43_i10++) {
    c43_d_q[c43_i10] = c43_b_q[c43_i10];
  }

  for (c43_i11 = 0; c43_i11 < 3; c43_i11++) {
    c43_d_hw[c43_i11] = c43_b_hw[c43_i11 + 6];
  }

  c43_quatrot(chartInstance, c43_d_q, c43_d_hw, c43_dv2);
  for (c43_i12 = 0; c43_i12 < 3; c43_i12++) {
    c43_b_h_int[c43_i12] = c43_dv1[c43_i12];
  }

  for (c43_i13 = 0; c43_i13 < 3; c43_i13++) {
    c43_b_h_int[c43_i13 + 3] = c43_b_hw[c43_i13 + 3];
  }

  for (c43_i14 = 0; c43_i14 < 3; c43_i14++) {
    c43_b_h_int[c43_i14 + 6] = c43_dv2[c43_i14];
  }

  for (c43_i15 = 0; c43_i15 < 3; c43_i15++) {
    c43_b_h_int[c43_i15 + 9] = c43_b_hw[c43_i15 + 9];
  }

  _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c43_i16 = 0; c43_i16 < 12; c43_i16++) {
    (*chartInstance->c43_h_int)[c43_i16] = c43_b_h_int[c43_i16];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c43_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_dIPCMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c43_i17 = 0; c43_i17 < 12; c43_i17++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c43_h_int)[c43_i17], 2U);
  }
}

static void mdl_start_c43_dIPC(SFc43_dIPCInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc43_dIPC(SFc43_dIPCInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c43_quatrot(SFc43_dIPCInstanceStruct *chartInstance, real_T c43_q[4],
  real_T c43_r[3], real_T c43_rw[3])
{
  uint32_T c43_debug_family_var_map[6];
  real_T c43_rwq[4];
  real_T c43_nargin = 2.0;
  real_T c43_nargout = 1.0;
  int32_T c43_i18;
  real_T c43_b_q[4];
  int32_T c43_k;
  real_T c43_b_k;
  real_T c43_dv3[4];
  int32_T c43_i19;
  int32_T c43_i20;
  real_T c43_c_q[4];
  real_T c43_dv4[4];
  int32_T c43_i21;
  real_T c43_d_q[4];
  int32_T c43_i22;
  real_T c43_dv5[4];
  int32_T c43_i23;
  int32_T c43_i24;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c43_b_debug_family_names,
    c43_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c43_rwq, 0U, c43_e_sf_marshallOut,
    c43_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_nargin, 1U, c43_c_sf_marshallOut,
    c43_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_nargout, 2U, c43_c_sf_marshallOut,
    c43_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c43_q, 3U, c43_e_sf_marshallOut,
    c43_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c43_r, 4U, c43_d_sf_marshallOut,
    c43_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c43_rw, 5U, c43_d_sf_marshallOut,
    c43_c_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c43_sfEvent, 4);
  for (c43_i18 = 0; c43_i18 < 4; c43_i18++) {
    c43_b_q[c43_i18] = c43_q[c43_i18];
  }

  for (c43_k = 0; c43_k < 3; c43_k++) {
    c43_b_k = 2.0 + (real_T)c43_k;
    c43_b_q[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c43_b_k), 1, 4, 1, 0) - 1] = -c43_b_q[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", c43_b_k), 1, 4, 1, 0) - 1];
  }

  c43_dv3[0] = 0.0;
  for (c43_i19 = 0; c43_i19 < 3; c43_i19++) {
    c43_dv3[c43_i19 + 1] = c43_r[c43_i19];
  }

  for (c43_i20 = 0; c43_i20 < 4; c43_i20++) {
    c43_c_q[c43_i20] = c43_b_q[c43_i20];
  }

  c43_quatmultiply(chartInstance, c43_dv3, c43_c_q, c43_dv4);
  for (c43_i21 = 0; c43_i21 < 4; c43_i21++) {
    c43_d_q[c43_i21] = c43_q[c43_i21];
  }

  for (c43_i22 = 0; c43_i22 < 4; c43_i22++) {
    c43_dv5[c43_i22] = c43_dv4[c43_i22];
  }

  c43_quatmultiply(chartInstance, c43_d_q, c43_dv5, c43_b_q);
  for (c43_i23 = 0; c43_i23 < 4; c43_i23++) {
    c43_rwq[c43_i23] = c43_b_q[c43_i23];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c43_sfEvent, 5);
  for (c43_i24 = 0; c43_i24 < 3; c43_i24++) {
    c43_rw[c43_i24] = c43_rwq[c43_i24 + 1];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c43_sfEvent, -5);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c43_machineNumber, uint32_T
  c43_chartNumber, uint32_T c43_instanceNumber)
{
  (void)c43_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c43_chartNumber, c43_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Martin\\Documents\\Git\\Simulink\\DIPCc - Energybounding\\quatrot.m"));
}

static const mxArray *c43_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData)
{
  const mxArray *c43_mxArrayOutData = NULL;
  int32_T c43_i25;
  real_T c43_b_inData[12];
  int32_T c43_i26;
  real_T c43_u[12];
  const mxArray *c43_y = NULL;
  SFc43_dIPCInstanceStruct *chartInstance;
  chartInstance = (SFc43_dIPCInstanceStruct *)chartInstanceVoid;
  c43_mxArrayOutData = NULL;
  for (c43_i25 = 0; c43_i25 < 12; c43_i25++) {
    c43_b_inData[c43_i25] = (*(real_T (*)[12])c43_inData)[c43_i25];
  }

  for (c43_i26 = 0; c43_i26 < 12; c43_i26++) {
    c43_u[c43_i26] = c43_b_inData[c43_i26];
  }

  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", c43_u, 0, 0U, 1U, 0U, 1, 12), false);
  sf_mex_assign(&c43_mxArrayOutData, c43_y, false);
  return c43_mxArrayOutData;
}

static void c43_emlrt_marshallIn(SFc43_dIPCInstanceStruct *chartInstance, const
  mxArray *c43_b_h_int, const char_T *c43_identifier, real_T c43_y[12])
{
  emlrtMsgIdentifier c43_thisId;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c43_b_h_int), &c43_thisId,
    c43_y);
  sf_mex_destroy(&c43_b_h_int);
}

static void c43_b_emlrt_marshallIn(SFc43_dIPCInstanceStruct *chartInstance,
  const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId, real_T c43_y[12])
{
  real_T c43_dv6[12];
  int32_T c43_i27;
  (void)chartInstance;
  sf_mex_import(c43_parentId, sf_mex_dup(c43_u), c43_dv6, 1, 0, 0U, 1, 0U, 1, 12);
  for (c43_i27 = 0; c43_i27 < 12; c43_i27++) {
    c43_y[c43_i27] = c43_dv6[c43_i27];
  }

  sf_mex_destroy(&c43_u);
}

static void c43_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData)
{
  const mxArray *c43_b_h_int;
  const char_T *c43_identifier;
  emlrtMsgIdentifier c43_thisId;
  real_T c43_y[12];
  int32_T c43_i28;
  SFc43_dIPCInstanceStruct *chartInstance;
  chartInstance = (SFc43_dIPCInstanceStruct *)chartInstanceVoid;
  c43_b_h_int = sf_mex_dup(c43_mxArrayInData);
  c43_identifier = c43_varName;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c43_b_h_int), &c43_thisId,
    c43_y);
  sf_mex_destroy(&c43_b_h_int);
  for (c43_i28 = 0; c43_i28 < 12; c43_i28++) {
    (*(real_T (*)[12])c43_outData)[c43_i28] = c43_y[c43_i28];
  }

  sf_mex_destroy(&c43_mxArrayInData);
}

static const mxArray *c43_b_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData)
{
  const mxArray *c43_mxArrayOutData = NULL;
  int32_T c43_i29;
  real_T c43_b_inData[14];
  int32_T c43_i30;
  real_T c43_u[14];
  const mxArray *c43_y = NULL;
  SFc43_dIPCInstanceStruct *chartInstance;
  chartInstance = (SFc43_dIPCInstanceStruct *)chartInstanceVoid;
  c43_mxArrayOutData = NULL;
  for (c43_i29 = 0; c43_i29 < 14; c43_i29++) {
    c43_b_inData[c43_i29] = (*(real_T (*)[14])c43_inData)[c43_i29];
  }

  for (c43_i30 = 0; c43_i30 < 14; c43_i30++) {
    c43_u[c43_i30] = c43_b_inData[c43_i30];
  }

  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", c43_u, 0, 0U, 1U, 0U, 1, 14), false);
  sf_mex_assign(&c43_mxArrayOutData, c43_y, false);
  return c43_mxArrayOutData;
}

static const mxArray *c43_c_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData)
{
  const mxArray *c43_mxArrayOutData = NULL;
  real_T c43_u;
  const mxArray *c43_y = NULL;
  SFc43_dIPCInstanceStruct *chartInstance;
  chartInstance = (SFc43_dIPCInstanceStruct *)chartInstanceVoid;
  c43_mxArrayOutData = NULL;
  c43_u = *(real_T *)c43_inData;
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", &c43_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c43_mxArrayOutData, c43_y, false);
  return c43_mxArrayOutData;
}

static real_T c43_c_emlrt_marshallIn(SFc43_dIPCInstanceStruct *chartInstance,
  const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId)
{
  real_T c43_y;
  real_T c43_d0;
  (void)chartInstance;
  sf_mex_import(c43_parentId, sf_mex_dup(c43_u), &c43_d0, 1, 0, 0U, 0, 0U, 0);
  c43_y = c43_d0;
  sf_mex_destroy(&c43_u);
  return c43_y;
}

static void c43_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData)
{
  const mxArray *c43_nargout;
  const char_T *c43_identifier;
  emlrtMsgIdentifier c43_thisId;
  real_T c43_y;
  SFc43_dIPCInstanceStruct *chartInstance;
  chartInstance = (SFc43_dIPCInstanceStruct *)chartInstanceVoid;
  c43_nargout = sf_mex_dup(c43_mxArrayInData);
  c43_identifier = c43_varName;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_y = c43_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c43_nargout),
    &c43_thisId);
  sf_mex_destroy(&c43_nargout);
  *(real_T *)c43_outData = c43_y;
  sf_mex_destroy(&c43_mxArrayInData);
}

static const mxArray *c43_d_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData)
{
  const mxArray *c43_mxArrayOutData = NULL;
  int32_T c43_i31;
  real_T c43_b_inData[3];
  int32_T c43_i32;
  real_T c43_u[3];
  const mxArray *c43_y = NULL;
  SFc43_dIPCInstanceStruct *chartInstance;
  chartInstance = (SFc43_dIPCInstanceStruct *)chartInstanceVoid;
  c43_mxArrayOutData = NULL;
  for (c43_i31 = 0; c43_i31 < 3; c43_i31++) {
    c43_b_inData[c43_i31] = (*(real_T (*)[3])c43_inData)[c43_i31];
  }

  for (c43_i32 = 0; c43_i32 < 3; c43_i32++) {
    c43_u[c43_i32] = c43_b_inData[c43_i32];
  }

  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", c43_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c43_mxArrayOutData, c43_y, false);
  return c43_mxArrayOutData;
}

static void c43_d_emlrt_marshallIn(SFc43_dIPCInstanceStruct *chartInstance,
  const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId, real_T c43_y[3])
{
  real_T c43_dv7[3];
  int32_T c43_i33;
  (void)chartInstance;
  sf_mex_import(c43_parentId, sf_mex_dup(c43_u), c43_dv7, 1, 0, 0U, 1, 0U, 1, 3);
  for (c43_i33 = 0; c43_i33 < 3; c43_i33++) {
    c43_y[c43_i33] = c43_dv7[c43_i33];
  }

  sf_mex_destroy(&c43_u);
}

static void c43_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData)
{
  const mxArray *c43_rw;
  const char_T *c43_identifier;
  emlrtMsgIdentifier c43_thisId;
  real_T c43_y[3];
  int32_T c43_i34;
  SFc43_dIPCInstanceStruct *chartInstance;
  chartInstance = (SFc43_dIPCInstanceStruct *)chartInstanceVoid;
  c43_rw = sf_mex_dup(c43_mxArrayInData);
  c43_identifier = c43_varName;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c43_rw), &c43_thisId, c43_y);
  sf_mex_destroy(&c43_rw);
  for (c43_i34 = 0; c43_i34 < 3; c43_i34++) {
    (*(real_T (*)[3])c43_outData)[c43_i34] = c43_y[c43_i34];
  }

  sf_mex_destroy(&c43_mxArrayInData);
}

static const mxArray *c43_e_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData)
{
  const mxArray *c43_mxArrayOutData = NULL;
  int32_T c43_i35;
  real_T c43_b_inData[4];
  int32_T c43_i36;
  real_T c43_u[4];
  const mxArray *c43_y = NULL;
  SFc43_dIPCInstanceStruct *chartInstance;
  chartInstance = (SFc43_dIPCInstanceStruct *)chartInstanceVoid;
  c43_mxArrayOutData = NULL;
  for (c43_i35 = 0; c43_i35 < 4; c43_i35++) {
    c43_b_inData[c43_i35] = (*(real_T (*)[4])c43_inData)[c43_i35];
  }

  for (c43_i36 = 0; c43_i36 < 4; c43_i36++) {
    c43_u[c43_i36] = c43_b_inData[c43_i36];
  }

  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", c43_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c43_mxArrayOutData, c43_y, false);
  return c43_mxArrayOutData;
}

static void c43_e_emlrt_marshallIn(SFc43_dIPCInstanceStruct *chartInstance,
  const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId, real_T c43_y[4])
{
  real_T c43_dv8[4];
  int32_T c43_i37;
  (void)chartInstance;
  sf_mex_import(c43_parentId, sf_mex_dup(c43_u), c43_dv8, 1, 0, 0U, 1, 0U, 1, 4);
  for (c43_i37 = 0; c43_i37 < 4; c43_i37++) {
    c43_y[c43_i37] = c43_dv8[c43_i37];
  }

  sf_mex_destroy(&c43_u);
}

static void c43_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData)
{
  const mxArray *c43_q;
  const char_T *c43_identifier;
  emlrtMsgIdentifier c43_thisId;
  real_T c43_y[4];
  int32_T c43_i38;
  SFc43_dIPCInstanceStruct *chartInstance;
  chartInstance = (SFc43_dIPCInstanceStruct *)chartInstanceVoid;
  c43_q = sf_mex_dup(c43_mxArrayInData);
  c43_identifier = c43_varName;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c43_q), &c43_thisId, c43_y);
  sf_mex_destroy(&c43_q);
  for (c43_i38 = 0; c43_i38 < 4; c43_i38++) {
    (*(real_T (*)[4])c43_outData)[c43_i38] = c43_y[c43_i38];
  }

  sf_mex_destroy(&c43_mxArrayInData);
}

const mxArray *sf_c43_dIPC_get_eml_resolved_functions_info(void)
{
  const mxArray *c43_nameCaptureInfo = NULL;
  c43_nameCaptureInfo = NULL;
  sf_mex_assign(&c43_nameCaptureInfo, sf_mex_createstruct("structure", 2, 13, 1),
                false);
  c43_info_helper(&c43_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c43_nameCaptureInfo);
  return c43_nameCaptureInfo;
}

static void c43_info_helper(const mxArray **c43_info)
{
  const mxArray *c43_rhs0 = NULL;
  const mxArray *c43_lhs0 = NULL;
  const mxArray *c43_rhs1 = NULL;
  const mxArray *c43_lhs1 = NULL;
  const mxArray *c43_rhs2 = NULL;
  const mxArray *c43_lhs2 = NULL;
  const mxArray *c43_rhs3 = NULL;
  const mxArray *c43_lhs3 = NULL;
  const mxArray *c43_rhs4 = NULL;
  const mxArray *c43_lhs4 = NULL;
  const mxArray *c43_rhs5 = NULL;
  const mxArray *c43_lhs5 = NULL;
  const mxArray *c43_rhs6 = NULL;
  const mxArray *c43_lhs6 = NULL;
  const mxArray *c43_rhs7 = NULL;
  const mxArray *c43_lhs7 = NULL;
  const mxArray *c43_rhs8 = NULL;
  const mxArray *c43_lhs8 = NULL;
  const mxArray *c43_rhs9 = NULL;
  const mxArray *c43_lhs9 = NULL;
  const mxArray *c43_rhs10 = NULL;
  const mxArray *c43_lhs10 = NULL;
  const mxArray *c43_rhs11 = NULL;
  const mxArray *c43_lhs11 = NULL;
  const mxArray *c43_rhs12 = NULL;
  const mxArray *c43_lhs12 = NULL;
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("quatconj"), "name", "name",
                  0);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatconj.p"), "resolved", "resolved",
                  0);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1410808258U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c43_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c43_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("quatrot"), "name", "name", 1);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DIPCc - Energybounding/quatrot.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1462213506U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c43_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c43_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DIPCc - Energybounding/quatrot.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("quatconj"), "name", "name",
                  2);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatconj.p"), "resolved", "resolved",
                  2);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1410808258U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c43_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c43_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[E]C:/Users/Martin/Documents/Git/Simulink/DIPCc - Energybounding/quatrot.m"),
                  "context", "context", 3);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("quatmultiply"), "name",
                  "name", 3);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatmultiply.p"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1410808258U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c43_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c43_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/aeroblks/eml/quatmultiply.p"), "context",
                  "context", 4);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("max"), "name", "name", 4);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1311280516U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c43_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c43_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 5);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1378321184U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c43_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c43_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 6);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 6);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c43_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c43_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 7);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c43_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c43_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 8);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 8);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c43_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c43_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 9);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1410832970U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c43_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c43_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 10);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 10);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1323195778U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c43_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c43_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 11);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 11);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1376005888U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c43_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c43_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 12);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 12);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1395957056U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c43_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c43_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs12), "lhs", "lhs",
                  12);
  sf_mex_destroy(&c43_rhs0);
  sf_mex_destroy(&c43_lhs0);
  sf_mex_destroy(&c43_rhs1);
  sf_mex_destroy(&c43_lhs1);
  sf_mex_destroy(&c43_rhs2);
  sf_mex_destroy(&c43_lhs2);
  sf_mex_destroy(&c43_rhs3);
  sf_mex_destroy(&c43_lhs3);
  sf_mex_destroy(&c43_rhs4);
  sf_mex_destroy(&c43_lhs4);
  sf_mex_destroy(&c43_rhs5);
  sf_mex_destroy(&c43_lhs5);
  sf_mex_destroy(&c43_rhs6);
  sf_mex_destroy(&c43_lhs6);
  sf_mex_destroy(&c43_rhs7);
  sf_mex_destroy(&c43_lhs7);
  sf_mex_destroy(&c43_rhs8);
  sf_mex_destroy(&c43_lhs8);
  sf_mex_destroy(&c43_rhs9);
  sf_mex_destroy(&c43_lhs9);
  sf_mex_destroy(&c43_rhs10);
  sf_mex_destroy(&c43_lhs10);
  sf_mex_destroy(&c43_rhs11);
  sf_mex_destroy(&c43_lhs11);
  sf_mex_destroy(&c43_rhs12);
  sf_mex_destroy(&c43_lhs12);
}

static const mxArray *c43_emlrt_marshallOut(const char * c43_u)
{
  const mxArray *c43_y = NULL;
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", c43_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c43_u)), false);
  return c43_y;
}

static const mxArray *c43_b_emlrt_marshallOut(const uint32_T c43_u)
{
  const mxArray *c43_y = NULL;
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", &c43_u, 7, 0U, 0U, 0U, 0), false);
  return c43_y;
}

static void c43_quatmultiply(SFc43_dIPCInstanceStruct *chartInstance, real_T
  c43_q[4], real_T c43_r[4], real_T c43_qout[4])
{
  real_T c43_q1;
  real_T c43_q2;
  real_T c43_q3;
  real_T c43_q4;
  real_T c43_r1;
  real_T c43_r2;
  real_T c43_r3;
  real_T c43_r4;
  (void)chartInstance;
  c43_q1 = c43_q[0];
  c43_q2 = c43_q[1];
  c43_q3 = c43_q[2];
  c43_q4 = c43_q[3];
  c43_r1 = c43_r[0];
  c43_r2 = c43_r[1];
  c43_r3 = c43_r[2];
  c43_r4 = c43_r[3];
  c43_qout[0] = ((c43_q1 * c43_r1 - c43_q2 * c43_r2) - c43_q3 * c43_r3) - c43_q4
    * c43_r4;
  c43_qout[1] = (c43_q1 * c43_r2 + c43_r1 * c43_q2) + (c43_q3 * c43_r4 - c43_q4 *
    c43_r3);
  c43_qout[2] = (c43_q1 * c43_r3 + c43_r1 * c43_q3) + (c43_q4 * c43_r2 - c43_q2 *
    c43_r4);
  c43_qout[3] = (c43_q1 * c43_r4 + c43_r1 * c43_q4) + (c43_q2 * c43_r3 - c43_q3 *
    c43_r2);
}

static const mxArray *c43_f_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData)
{
  const mxArray *c43_mxArrayOutData = NULL;
  int32_T c43_u;
  const mxArray *c43_y = NULL;
  SFc43_dIPCInstanceStruct *chartInstance;
  chartInstance = (SFc43_dIPCInstanceStruct *)chartInstanceVoid;
  c43_mxArrayOutData = NULL;
  c43_u = *(int32_T *)c43_inData;
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", &c43_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c43_mxArrayOutData, c43_y, false);
  return c43_mxArrayOutData;
}

static int32_T c43_f_emlrt_marshallIn(SFc43_dIPCInstanceStruct *chartInstance,
  const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId)
{
  int32_T c43_y;
  int32_T c43_i39;
  (void)chartInstance;
  sf_mex_import(c43_parentId, sf_mex_dup(c43_u), &c43_i39, 1, 6, 0U, 0, 0U, 0);
  c43_y = c43_i39;
  sf_mex_destroy(&c43_u);
  return c43_y;
}

static void c43_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData)
{
  const mxArray *c43_b_sfEvent;
  const char_T *c43_identifier;
  emlrtMsgIdentifier c43_thisId;
  int32_T c43_y;
  SFc43_dIPCInstanceStruct *chartInstance;
  chartInstance = (SFc43_dIPCInstanceStruct *)chartInstanceVoid;
  c43_b_sfEvent = sf_mex_dup(c43_mxArrayInData);
  c43_identifier = c43_varName;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_y = c43_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c43_b_sfEvent),
    &c43_thisId);
  sf_mex_destroy(&c43_b_sfEvent);
  *(int32_T *)c43_outData = c43_y;
  sf_mex_destroy(&c43_mxArrayInData);
}

static uint8_T c43_g_emlrt_marshallIn(SFc43_dIPCInstanceStruct *chartInstance,
  const mxArray *c43_b_is_active_c43_dIPC, const char_T *c43_identifier)
{
  uint8_T c43_y;
  emlrtMsgIdentifier c43_thisId;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_y = c43_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c43_b_is_active_c43_dIPC), &c43_thisId);
  sf_mex_destroy(&c43_b_is_active_c43_dIPC);
  return c43_y;
}

static uint8_T c43_h_emlrt_marshallIn(SFc43_dIPCInstanceStruct *chartInstance,
  const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId)
{
  uint8_T c43_y;
  uint8_T c43_u0;
  (void)chartInstance;
  sf_mex_import(c43_parentId, sf_mex_dup(c43_u), &c43_u0, 1, 3, 0U, 0, 0U, 0);
  c43_y = c43_u0;
  sf_mex_destroy(&c43_u);
  return c43_y;
}

static void init_dsm_address_info(SFc43_dIPCInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc43_dIPCInstanceStruct *chartInstance)
{
  chartInstance->c43_hw = (real_T (*)[12])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c43_x = (real_T (*)[14])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c43_h_int = (real_T (*)[12])ssGetOutputPortSignal_wrapper
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

void sf_c43_dIPC_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1151334514U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3379999566U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1701969767U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3276930954U);
}

mxArray* sf_c43_dIPC_get_post_codegen_info(void);
mxArray *sf_c43_dIPC_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("PX7bkxEV86Pni3SUF1aQMH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(14);
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c43_dIPC_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c43_dIPC_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c43_dIPC_jit_fallback_info(void)
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

mxArray *sf_c43_dIPC_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c43_dIPC_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c43_dIPC(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"h_int\",},{M[8],M[0],T\"is_active_c43_dIPC\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c43_dIPC_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc43_dIPCInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc43_dIPCInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _dIPCMachineNumber_,
           43,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"hw");
          _SFD_SET_DATA_PROPS(1,1,1,0,"x");
          _SFD_SET_DATA_PROPS(2,2,0,1,"h_int");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,262);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"quatrot",0,-1,191);

        {
          unsigned int dimVector[1];
          dimVector[0]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 14;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c43_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)
            c43_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c43_hw);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c43_x);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c43_h_int);
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
  return "rwDDIRRJuizrd2lg0McQcG";
}

static void sf_opaque_initialize_c43_dIPC(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc43_dIPCInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c43_dIPC((SFc43_dIPCInstanceStruct*) chartInstanceVar);
  initialize_c43_dIPC((SFc43_dIPCInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c43_dIPC(void *chartInstanceVar)
{
  enable_c43_dIPC((SFc43_dIPCInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c43_dIPC(void *chartInstanceVar)
{
  disable_c43_dIPC((SFc43_dIPCInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c43_dIPC(void *chartInstanceVar)
{
  sf_gateway_c43_dIPC((SFc43_dIPCInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c43_dIPC(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c43_dIPC((SFc43_dIPCInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c43_dIPC(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c43_dIPC((SFc43_dIPCInstanceStruct*)chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c43_dIPC(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc43_dIPCInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_dIPC_optimization_info();
    }

    finalize_c43_dIPC((SFc43_dIPCInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc43_dIPC((SFc43_dIPCInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c43_dIPC(SimStruct *S)
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
    initialize_params_c43_dIPC((SFc43_dIPCInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c43_dIPC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_dIPC_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      43);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,43,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,43,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,43);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,43,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,43,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,43);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2074529041U));
  ssSetChecksum1(S,(2245930086U));
  ssSetChecksum2(S,(618142672U));
  ssSetChecksum3(S,(1417630288U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c43_dIPC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c43_dIPC(SimStruct *S)
{
  SFc43_dIPCInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc43_dIPCInstanceStruct *)utMalloc(sizeof
    (SFc43_dIPCInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc43_dIPCInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c43_dIPC;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c43_dIPC;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c43_dIPC;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c43_dIPC;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c43_dIPC;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c43_dIPC;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c43_dIPC;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c43_dIPC;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c43_dIPC;
  chartInstance->chartInfo.mdlStart = mdlStart_c43_dIPC;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c43_dIPC;
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

void c43_dIPC_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c43_dIPC(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c43_dIPC(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c43_dIPC(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c43_dIPC_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

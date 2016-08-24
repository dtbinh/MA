/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DIPCalt_sfun.h"
#include "c19_DIPCalt.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DIPCalt_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c19_debug_family_names[6] = { "nargin", "nargout", "energy",
  "reference", "dxb", "dxv" };

/* Function Declarations */
static void initialize_c19_DIPCalt(SFc19_DIPCaltInstanceStruct *chartInstance);
static void initialize_params_c19_DIPCalt(SFc19_DIPCaltInstanceStruct
  *chartInstance);
static void enable_c19_DIPCalt(SFc19_DIPCaltInstanceStruct *chartInstance);
static void disable_c19_DIPCalt(SFc19_DIPCaltInstanceStruct *chartInstance);
static void c19_update_debugger_state_c19_DIPCalt(SFc19_DIPCaltInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c19_DIPCalt(SFc19_DIPCaltInstanceStruct
  *chartInstance);
static void set_sim_state_c19_DIPCalt(SFc19_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c19_st);
static void finalize_c19_DIPCalt(SFc19_DIPCaltInstanceStruct *chartInstance);
static void sf_gateway_c19_DIPCalt(SFc19_DIPCaltInstanceStruct *chartInstance);
static void mdl_start_c19_DIPCalt(SFc19_DIPCaltInstanceStruct *chartInstance);
static void initSimStructsc19_DIPCalt(SFc19_DIPCaltInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber, uint32_T c19_instanceNumber);
static const mxArray *c19_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static void c19_emlrt_marshallIn(SFc19_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c19_b_dxv, const char_T *c19_identifier, real_T c19_y[6]);
static void c19_b_emlrt_marshallIn(SFc19_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId, real_T c19_y[6]);
static void c19_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_b_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static real_T c19_c_emlrt_marshallIn(SFc19_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_c_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static int32_T c19_d_emlrt_marshallIn(SFc19_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static uint8_T c19_e_emlrt_marshallIn(SFc19_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c19_b_is_active_c19_DIPCalt, const char_T *c19_identifier);
static uint8_T c19_f_emlrt_marshallIn(SFc19_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void init_dsm_address_info(SFc19_DIPCaltInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc19_DIPCaltInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c19_DIPCalt(SFc19_DIPCaltInstanceStruct *chartInstance)
{
  chartInstance->c19_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c19_is_active_c19_DIPCalt = 0U;
}

static void initialize_params_c19_DIPCalt(SFc19_DIPCaltInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c19_DIPCalt(SFc19_DIPCaltInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c19_DIPCalt(SFc19_DIPCaltInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c19_update_debugger_state_c19_DIPCalt(SFc19_DIPCaltInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c19_DIPCalt(SFc19_DIPCaltInstanceStruct
  *chartInstance)
{
  const mxArray *c19_st;
  const mxArray *c19_y = NULL;
  int32_T c19_i0;
  real_T c19_u[6];
  const mxArray *c19_b_y = NULL;
  uint8_T c19_hoistedGlobal;
  uint8_T c19_b_u;
  const mxArray *c19_c_y = NULL;
  c19_st = NULL;
  c19_st = NULL;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_createcellmatrix(2, 1), false);
  for (c19_i0 = 0; c19_i0 < 6; c19_i0++) {
    c19_u[c19_i0] = (*chartInstance->c19_dxv)[c19_i0];
  }

  c19_b_y = NULL;
  sf_mex_assign(&c19_b_y, sf_mex_create("y", c19_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_setcell(c19_y, 0, c19_b_y);
  c19_hoistedGlobal = chartInstance->c19_is_active_c19_DIPCalt;
  c19_b_u = c19_hoistedGlobal;
  c19_c_y = NULL;
  sf_mex_assign(&c19_c_y, sf_mex_create("y", &c19_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c19_y, 1, c19_c_y);
  sf_mex_assign(&c19_st, c19_y, false);
  return c19_st;
}

static void set_sim_state_c19_DIPCalt(SFc19_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c19_st)
{
  const mxArray *c19_u;
  real_T c19_dv0[6];
  int32_T c19_i1;
  chartInstance->c19_doneDoubleBufferReInit = true;
  c19_u = sf_mex_dup(c19_st);
  c19_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c19_u, 0)),
                       "dxv", c19_dv0);
  for (c19_i1 = 0; c19_i1 < 6; c19_i1++) {
    (*chartInstance->c19_dxv)[c19_i1] = c19_dv0[c19_i1];
  }

  chartInstance->c19_is_active_c19_DIPCalt = c19_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c19_u, 1)),
     "is_active_c19_DIPCalt");
  sf_mex_destroy(&c19_u);
  c19_update_debugger_state_c19_DIPCalt(chartInstance);
  sf_mex_destroy(&c19_st);
}

static void finalize_c19_DIPCalt(SFc19_DIPCaltInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c19_DIPCalt(SFc19_DIPCaltInstanceStruct *chartInstance)
{
  real_T c19_hoistedGlobal;
  real_T c19_b_energy;
  int32_T c19_i2;
  real_T c19_b_reference[6];
  int32_T c19_i3;
  real_T c19_b_dxb[6];
  uint32_T c19_debug_family_var_map[6];
  real_T c19_nargin = 3.0;
  real_T c19_nargout = 1.0;
  real_T c19_b_dxv[6];
  int32_T c19_i4;
  int32_T c19_i5;
  int32_T c19_i6;
  int32_T c19_i7;
  int32_T c19_i8;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 8U, chartInstance->c19_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c19_energy, 0U);
  chartInstance->c19_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c19_sfEvent);
  c19_hoistedGlobal = *chartInstance->c19_energy;
  c19_b_energy = c19_hoistedGlobal;
  for (c19_i2 = 0; c19_i2 < 6; c19_i2++) {
    c19_b_reference[c19_i2] = (*chartInstance->c19_reference)[c19_i2];
  }

  for (c19_i3 = 0; c19_i3 < 6; c19_i3++) {
    c19_b_dxb[c19_i3] = (*chartInstance->c19_dxb)[c19_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c19_debug_family_names,
    c19_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_nargin, 0U, c19_b_sf_marshallOut,
    c19_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_nargout, 1U, c19_b_sf_marshallOut,
    c19_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c19_b_energy, 2U, c19_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c19_b_reference, 3U, c19_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c19_b_dxb, 4U, c19_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c19_b_dxv, 5U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 2);
  for (c19_i4 = 0; c19_i4 < 6; c19_i4++) {
    c19_b_dxv[c19_i4] = c19_b_reference[c19_i4];
  }

  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, -2);
  _SFD_SYMBOL_SCOPE_POP();
  for (c19_i5 = 0; c19_i5 < 6; c19_i5++) {
    (*chartInstance->c19_dxv)[c19_i5] = c19_b_dxv[c19_i5];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c19_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DIPCaltMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c19_i6 = 0; c19_i6 < 6; c19_i6++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c19_dxv)[c19_i6], 1U);
  }

  for (c19_i7 = 0; c19_i7 < 6; c19_i7++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c19_reference)[c19_i7], 2U);
  }

  for (c19_i8 = 0; c19_i8 < 6; c19_i8++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c19_dxb)[c19_i8], 3U);
  }
}

static void mdl_start_c19_DIPCalt(SFc19_DIPCaltInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc19_DIPCalt(SFc19_DIPCaltInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber, uint32_T c19_instanceNumber)
{
  (void)c19_machineNumber;
  (void)c19_chartNumber;
  (void)c19_instanceNumber;
}

static const mxArray *c19_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  int32_T c19_i9;
  real_T c19_b_inData[6];
  int32_T c19_i10;
  real_T c19_u[6];
  const mxArray *c19_y = NULL;
  SFc19_DIPCaltInstanceStruct *chartInstance;
  chartInstance = (SFc19_DIPCaltInstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  for (c19_i9 = 0; c19_i9 < 6; c19_i9++) {
    c19_b_inData[c19_i9] = (*(real_T (*)[6])c19_inData)[c19_i9];
  }

  for (c19_i10 = 0; c19_i10 < 6; c19_i10++) {
    c19_u[c19_i10] = c19_b_inData[c19_i10];
  }

  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", c19_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static void c19_emlrt_marshallIn(SFc19_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c19_b_dxv, const char_T *c19_identifier, real_T c19_y[6])
{
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_dxv), &c19_thisId,
    c19_y);
  sf_mex_destroy(&c19_b_dxv);
}

static void c19_b_emlrt_marshallIn(SFc19_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId, real_T c19_y[6])
{
  real_T c19_dv1[6];
  int32_T c19_i11;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), c19_dv1, 1, 0, 0U, 1, 0U, 1, 6);
  for (c19_i11 = 0; c19_i11 < 6; c19_i11++) {
    c19_y[c19_i11] = c19_dv1[c19_i11];
  }

  sf_mex_destroy(&c19_u);
}

static void c19_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_b_dxv;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  real_T c19_y[6];
  int32_T c19_i12;
  SFc19_DIPCaltInstanceStruct *chartInstance;
  chartInstance = (SFc19_DIPCaltInstanceStruct *)chartInstanceVoid;
  c19_b_dxv = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_dxv), &c19_thisId,
    c19_y);
  sf_mex_destroy(&c19_b_dxv);
  for (c19_i12 = 0; c19_i12 < 6; c19_i12++) {
    (*(real_T (*)[6])c19_outData)[c19_i12] = c19_y[c19_i12];
  }

  sf_mex_destroy(&c19_mxArrayInData);
}

static const mxArray *c19_b_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  real_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_DIPCaltInstanceStruct *chartInstance;
  chartInstance = (SFc19_DIPCaltInstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(real_T *)c19_inData;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static real_T c19_c_emlrt_marshallIn(SFc19_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  real_T c19_y;
  real_T c19_d0;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_d0, 1, 0, 0U, 0, 0U, 0);
  c19_y = c19_d0;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_nargout;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  real_T c19_y;
  SFc19_DIPCaltInstanceStruct *chartInstance;
  chartInstance = (SFc19_DIPCaltInstanceStruct *)chartInstanceVoid;
  c19_nargout = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_nargout),
    &c19_thisId);
  sf_mex_destroy(&c19_nargout);
  *(real_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

const mxArray *sf_c19_DIPCalt_get_eml_resolved_functions_info(void)
{
  const mxArray *c19_nameCaptureInfo = NULL;
  c19_nameCaptureInfo = NULL;
  sf_mex_assign(&c19_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c19_nameCaptureInfo;
}

static const mxArray *c19_c_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  int32_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_DIPCaltInstanceStruct *chartInstance;
  chartInstance = (SFc19_DIPCaltInstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(int32_T *)c19_inData;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static int32_T c19_d_emlrt_marshallIn(SFc19_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  int32_T c19_y;
  int32_T c19_i13;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_i13, 1, 6, 0U, 0, 0U, 0);
  c19_y = c19_i13;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_b_sfEvent;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  int32_T c19_y;
  SFc19_DIPCaltInstanceStruct *chartInstance;
  chartInstance = (SFc19_DIPCaltInstanceStruct *)chartInstanceVoid;
  c19_b_sfEvent = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_sfEvent),
    &c19_thisId);
  sf_mex_destroy(&c19_b_sfEvent);
  *(int32_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

static uint8_T c19_e_emlrt_marshallIn(SFc19_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c19_b_is_active_c19_DIPCalt, const char_T *c19_identifier)
{
  uint8_T c19_y;
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c19_b_is_active_c19_DIPCalt), &c19_thisId);
  sf_mex_destroy(&c19_b_is_active_c19_DIPCalt);
  return c19_y;
}

static uint8_T c19_f_emlrt_marshallIn(SFc19_DIPCaltInstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  uint8_T c19_y;
  uint8_T c19_u0;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_u0, 1, 3, 0U, 0, 0U, 0);
  c19_y = c19_u0;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void init_dsm_address_info(SFc19_DIPCaltInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc19_DIPCaltInstanceStruct *chartInstance)
{
  chartInstance->c19_energy = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c19_dxv = (real_T (*)[6])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c19_reference = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c19_dxb = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
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

void sf_c19_DIPCalt_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4093476292U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3360817505U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3375352855U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(445001840U);
}

mxArray* sf_c19_DIPCalt_get_post_codegen_info(void);
mxArray *sf_c19_DIPCalt_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("mKrm0rWkZUhU8f8K3WT8XE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
      pr[0] = (double)(6);
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
      pr[0] = (double)(6);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c19_DIPCalt_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c19_DIPCalt_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c19_DIPCalt_jit_fallback_info(void)
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

mxArray *sf_c19_DIPCalt_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c19_DIPCalt_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c19_DIPCalt(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"dxv\",},{M[8],M[0],T\"is_active_c19_DIPCalt\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c19_DIPCalt_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc19_DIPCaltInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc19_DIPCaltInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DIPCaltMachineNumber_,
           19,
           1,
           1,
           0,
           4,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_DIPCaltMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_DIPCaltMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _DIPCaltMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"energy");
          _SFD_SET_DATA_PROPS(1,2,0,1,"dxv");
          _SFD_SET_DATA_PROPS(2,1,1,0,"reference");
          _SFD_SET_DATA_PROPS(3,1,1,0,"dxb");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,201);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c19_sf_marshallOut,(MexInFcnForType)
            c19_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c19_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c19_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c19_energy);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c19_dxv);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c19_reference);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c19_dxb);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _DIPCaltMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "Z5Mg4g1VRqg6poKwiFXtoF";
}

static void sf_opaque_initialize_c19_DIPCalt(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc19_DIPCaltInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c19_DIPCalt((SFc19_DIPCaltInstanceStruct*) chartInstanceVar);
  initialize_c19_DIPCalt((SFc19_DIPCaltInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c19_DIPCalt(void *chartInstanceVar)
{
  enable_c19_DIPCalt((SFc19_DIPCaltInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c19_DIPCalt(void *chartInstanceVar)
{
  disable_c19_DIPCalt((SFc19_DIPCaltInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c19_DIPCalt(void *chartInstanceVar)
{
  sf_gateway_c19_DIPCalt((SFc19_DIPCaltInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c19_DIPCalt(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c19_DIPCalt((SFc19_DIPCaltInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c19_DIPCalt(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c19_DIPCalt((SFc19_DIPCaltInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c19_DIPCalt(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc19_DIPCaltInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DIPCalt_optimization_info();
    }

    finalize_c19_DIPCalt((SFc19_DIPCaltInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc19_DIPCalt((SFc19_DIPCaltInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c19_DIPCalt(SimStruct *S)
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
    initialize_params_c19_DIPCalt((SFc19_DIPCaltInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c19_DIPCalt(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DIPCalt_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      19);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,19,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,19,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,19);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,19,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,19,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,19);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(847270539U));
  ssSetChecksum1(S,(1946503487U));
  ssSetChecksum2(S,(364031622U));
  ssSetChecksum3(S,(698887048U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c19_DIPCalt(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c19_DIPCalt(SimStruct *S)
{
  SFc19_DIPCaltInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc19_DIPCaltInstanceStruct *)utMalloc(sizeof
    (SFc19_DIPCaltInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc19_DIPCaltInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c19_DIPCalt;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c19_DIPCalt;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c19_DIPCalt;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c19_DIPCalt;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c19_DIPCalt;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c19_DIPCalt;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c19_DIPCalt;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c19_DIPCalt;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c19_DIPCalt;
  chartInstance->chartInfo.mdlStart = mdlStart_c19_DIPCalt;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c19_DIPCalt;
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

void c19_DIPCalt_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c19_DIPCalt(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c19_DIPCalt(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c19_DIPCalt(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c19_DIPCalt_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

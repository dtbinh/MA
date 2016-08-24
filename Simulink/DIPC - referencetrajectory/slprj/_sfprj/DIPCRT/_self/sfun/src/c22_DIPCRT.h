#ifndef __c22_DIPCRT_h__
#define __c22_DIPCRT_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc22_DIPCRTInstanceStruct
#define typedef_SFc22_DIPCRTInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c22_sfEvent;
  boolean_T c22_isStable;
  boolean_T c22_doneDoubleBufferReInit;
  uint8_T c22_is_active_c22_DIPCRT;
  real_T c22_j1;
  real_T c22_m1;
  real_T (*c22_dx)[6];
  real_T (*c22_hcoriolis)[6];
} SFc22_DIPCRTInstanceStruct;

#endif                                 /*typedef_SFc22_DIPCRTInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c22_DIPCRT_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c22_DIPCRT_get_check_sum(mxArray *plhs[]);
extern void c22_DIPCRT_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

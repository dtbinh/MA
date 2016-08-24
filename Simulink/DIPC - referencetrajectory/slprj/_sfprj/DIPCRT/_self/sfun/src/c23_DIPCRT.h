#ifndef __c23_DIPCRT_h__
#define __c23_DIPCRT_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc23_DIPCRTInstanceStruct
#define typedef_SFc23_DIPCRTInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c23_sfEvent;
  boolean_T c23_isStable;
  boolean_T c23_doneDoubleBufferReInit;
  uint8_T c23_is_active_c23_DIPCRT;
  real_T c23_j1;
  real_T c23_m1;
  real_T (*c23_dx)[6];
  real_T (*c23_hcoriolis)[6];
} SFc23_DIPCRTInstanceStruct;

#endif                                 /*typedef_SFc23_DIPCRTInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c23_DIPCRT_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c23_DIPCRT_get_check_sum(mxArray *plhs[]);
extern void c23_DIPCRT_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

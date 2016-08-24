#ifndef __c28_DIPCRT_h__
#define __c28_DIPCRT_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc28_DIPCRTInstanceStruct
#define typedef_SFc28_DIPCRTInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c28_sfEvent;
  boolean_T c28_isStable;
  boolean_T c28_doneDoubleBufferReInit;
  uint8_T c28_is_active_c28_DIPCRT;
  real_T c28_kpt;
  real_T c28_kpr;
  real_T *c28_eta3;
  real_T (*c28_K)[36];
} SFc28_DIPCRTInstanceStruct;

#endif                                 /*typedef_SFc28_DIPCRTInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c28_DIPCRT_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c28_DIPCRT_get_check_sum(mxArray *plhs[]);
extern void c28_DIPCRT_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

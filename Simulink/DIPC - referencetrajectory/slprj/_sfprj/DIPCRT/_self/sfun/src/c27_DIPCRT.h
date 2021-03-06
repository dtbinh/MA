#ifndef __c27_DIPCRT_h__
#define __c27_DIPCRT_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc27_DIPCRTInstanceStruct
#define typedef_SFc27_DIPCRTInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c27_sfEvent;
  boolean_T c27_isStable;
  boolean_T c27_doneDoubleBufferReInit;
  uint8_T c27_is_active_c27_DIPCRT;
  real_T c27_kv;
  real_T c27_kappav;
  real_T *c27_eta;
  real_T (*c27_K)[36];
} SFc27_DIPCRTInstanceStruct;

#endif                                 /*typedef_SFc27_DIPCRTInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c27_DIPCRT_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c27_DIPCRT_get_check_sum(mxArray *plhs[]);
extern void c27_DIPCRT_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

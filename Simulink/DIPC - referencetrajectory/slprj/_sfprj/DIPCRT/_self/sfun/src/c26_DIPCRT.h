#ifndef __c26_DIPCRT_h__
#define __c26_DIPCRT_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc26_DIPCRTInstanceStruct
#define typedef_SFc26_DIPCRTInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c26_sfEvent;
  boolean_T c26_isStable;
  boolean_T c26_doneDoubleBufferReInit;
  uint8_T c26_is_active_c26_DIPCRT;
  real_T c26_kpt;
  real_T c26_kpr;
  real_T *c26_eta2;
  real_T (*c26_K)[36];
} SFc26_DIPCRTInstanceStruct;

#endif                                 /*typedef_SFc26_DIPCRTInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c26_DIPCRT_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c26_DIPCRT_get_check_sum(mxArray *plhs[]);
extern void c26_DIPCRT_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

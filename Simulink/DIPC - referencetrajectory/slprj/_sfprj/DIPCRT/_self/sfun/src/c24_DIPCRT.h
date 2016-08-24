#ifndef __c24_DIPCRT_h__
#define __c24_DIPCRT_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc24_DIPCRTInstanceStruct
#define typedef_SFc24_DIPCRTInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c24_sfEvent;
  boolean_T c24_isStable;
  boolean_T c24_doneDoubleBufferReInit;
  uint8_T c24_is_active_c24_DIPCRT;
  real_T c24_j1;
  real_T c24_m1;
  real_T (*c24_dx)[6];
  real_T (*c24_hcoriolis)[6];
} SFc24_DIPCRTInstanceStruct;

#endif                                 /*typedef_SFc24_DIPCRTInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c24_DIPCRT_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c24_DIPCRT_get_check_sum(mxArray *plhs[]);
extern void c24_DIPCRT_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

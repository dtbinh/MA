#ifndef __c25_DIPCRT_h__
#define __c25_DIPCRT_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc25_DIPCRTInstanceStruct
#define typedef_SFc25_DIPCRTInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c25_sfEvent;
  boolean_T c25_isStable;
  boolean_T c25_doneDoubleBufferReInit;
  uint8_T c25_is_active_c25_DIPCRT;
  real_T c25_kpt;
  real_T c25_kpr;
  real_T *c25_eta1;
  real_T (*c25_K)[36];
} SFc25_DIPCRTInstanceStruct;

#endif                                 /*typedef_SFc25_DIPCRTInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c25_DIPCRT_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c25_DIPCRT_get_check_sum(mxArray *plhs[]);
extern void c25_DIPCRT_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

#ifndef __c8_DIPC_h__
#define __c8_DIPC_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc8_DIPCInstanceStruct
#define typedef_SFc8_DIPCInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c8_sfEvent;
  boolean_T c8_isStable;
  boolean_T c8_doneDoubleBufferReInit;
  uint8_T c8_is_active_c8_DIPC;
  real_T c8_ks;
  real_T c8_kappas;
  real_T *c8_eta;
  real_T (*c8_K)[36];
} SFc8_DIPCInstanceStruct;

#endif                                 /*typedef_SFc8_DIPCInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c8_DIPC_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c8_DIPC_get_check_sum(mxArray *plhs[]);
extern void c8_DIPC_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

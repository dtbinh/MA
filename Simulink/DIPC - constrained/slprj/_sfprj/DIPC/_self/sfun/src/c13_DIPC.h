#ifndef __c13_DIPC_h__
#define __c13_DIPC_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc13_DIPCInstanceStruct
#define typedef_SFc13_DIPCInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c13_sfEvent;
  boolean_T c13_isStable;
  boolean_T c13_doneDoubleBufferReInit;
  uint8_T c13_is_active_c13_DIPC;
  real_T c13_j0;
  real_T c13_m0;
  real_T (*c13_dx)[6];
  real_T (*c13_hcoriolis)[6];
} SFc13_DIPCInstanceStruct;

#endif                                 /*typedef_SFc13_DIPCInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c13_DIPC_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c13_DIPC_get_check_sum(mxArray *plhs[]);
extern void c13_DIPC_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

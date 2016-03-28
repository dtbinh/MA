#ifndef __c19_DIPC_h__
#define __c19_DIPC_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc19_DIPCInstanceStruct
#define typedef_SFc19_DIPCInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c19_sfEvent;
  boolean_T c19_isStable;
  boolean_T c19_doneDoubleBufferReInit;
  uint8_T c19_is_active_c19_DIPC;
  real_T c19_mv;
  real_T c19_jv;
  real_T c19_m1;
  real_T c19_j1;
  real_T c19_rv[12];
  real_T (*c19_x)[7];
  real_T (*c19_M)[36];
} SFc19_DIPCInstanceStruct;

#endif                                 /*typedef_SFc19_DIPCInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c19_DIPC_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c19_DIPC_get_check_sum(mxArray *plhs[]);
extern void c19_DIPC_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

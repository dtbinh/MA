#ifndef __c27_dIPC_h__
#define __c27_dIPC_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc27_dIPCInstanceStruct
#define typedef_SFc27_dIPCInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c27_sfEvent;
  boolean_T c27_isStable;
  boolean_T c27_doneDoubleBufferReInit;
  uint8_T c27_is_active_c27_dIPC;
  real_T c27_kv;
  real_T c27_kappav;
  real_T *c27_eta;
  real_T (*c27_K)[36];
} SFc27_dIPCInstanceStruct;

#endif                                 /*typedef_SFc27_dIPCInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c27_dIPC_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c27_dIPC_get_check_sum(mxArray *plhs[]);
extern void c27_dIPC_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

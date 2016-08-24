#ifndef __c20_dIPC_h__
#define __c20_dIPC_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc20_dIPCInstanceStruct
#define typedef_SFc20_dIPCInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c20_sfEvent;
  boolean_T c20_isStable;
  boolean_T c20_doneDoubleBufferReInit;
  uint8_T c20_is_active_c20_dIPC;
  real_T c20_kv;
  real_T c20_kappav;
  real_T (*c20_K)[36];
  real_T *c20_energy;
} SFc20_dIPCInstanceStruct;

#endif                                 /*typedef_SFc20_dIPCInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c20_dIPC_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c20_dIPC_get_check_sum(mxArray *plhs[]);
extern void c20_dIPC_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

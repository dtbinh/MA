#ifndef __c13_StramigioliIPC_h__
#define __c13_StramigioliIPC_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc13_StramigioliIPCInstanceStruct
#define typedef_SFc13_StramigioliIPCInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c13_sfEvent;
  boolean_T c13_isStable;
  boolean_T c13_doneDoubleBufferReInit;
  uint8_T c13_is_active_c13_StramigioliIPC;
  real_T c13_j0;
  real_T c13_m0;
  real_T (*c13_dx)[6];
  real_T (*c13_hcoriolis)[6];
} SFc13_StramigioliIPCInstanceStruct;

#endif                                 /*typedef_SFc13_StramigioliIPCInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c13_StramigioliIPC_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c13_StramigioliIPC_get_check_sum(mxArray *plhs[]);
extern void c13_StramigioliIPC_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif

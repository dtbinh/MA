#ifndef __c4_StramigioliIPC_h__
#define __c4_StramigioliIPC_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc4_StramigioliIPCInstanceStruct
#define typedef_SFc4_StramigioliIPCInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  boolean_T c4_isStable;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_StramigioliIPC;
  real_T c4_rv[12];
  real_T (*c4_pb)[3];
  real_T (*c4_qb)[4];
  real_T (*c4_pb4)[3];
  real_T (*c4_qb4)[4];
} SFc4_StramigioliIPCInstanceStruct;

#endif                                 /*typedef_SFc4_StramigioliIPCInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_StramigioliIPC_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_StramigioliIPC_get_check_sum(mxArray *plhs[]);
extern void c4_StramigioliIPC_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif

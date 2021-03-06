#ifndef __c1_dIPC_h__
#define __c1_dIPC_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_dIPCInstanceStruct
#define typedef_SFc1_dIPCInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_isStable;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_dIPC;
  real_T (*c1_pb)[3];
  real_T (*c1_qb)[4];
  real_T (*c1_pb1)[3];
  real_T (*c1_rv)[6];
  real_T (*c1_qb1)[4];
} SFc1_dIPCInstanceStruct;

#endif                                 /*typedef_SFc1_dIPCInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_dIPC_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_dIPC_get_check_sum(mxArray *plhs[]);
extern void c1_dIPC_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

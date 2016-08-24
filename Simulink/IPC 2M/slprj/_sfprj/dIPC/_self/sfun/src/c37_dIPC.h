#ifndef __c37_dIPC_h__
#define __c37_dIPC_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc37_dIPCInstanceStruct
#define typedef_SFc37_dIPCInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c37_sfEvent;
  boolean_T c37_isStable;
  boolean_T c37_doneDoubleBufferReInit;
  uint8_T c37_is_active_c37_dIPC;
  real_T (*c37_p_o)[3];
  real_T (*c37_q_o)[4];
  real_T (*c37_x)[14];
  real_T (*c37_r)[6];
} SFc37_dIPCInstanceStruct;

#endif                                 /*typedef_SFc37_dIPCInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c37_dIPC_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c37_dIPC_get_check_sum(mxArray *plhs[]);
extern void c37_dIPC_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

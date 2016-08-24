#ifndef __c31_dIPC_h__
#define __c31_dIPC_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc31_dIPCInstanceStruct
#define typedef_SFc31_dIPCInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c31_sfEvent;
  boolean_T c31_isStable;
  boolean_T c31_doneDoubleBufferReInit;
  uint8_T c31_is_active_c31_dIPC;
  real_T c31_r[6];
  real_T (*c31_x)[14];
  real_T (*c31_bred)[6];
  real_T (*c31_dx)[12];
} SFc31_dIPCInstanceStruct;

#endif                                 /*typedef_SFc31_dIPCInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c31_dIPC_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c31_dIPC_get_check_sum(mxArray *plhs[]);
extern void c31_dIPC_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

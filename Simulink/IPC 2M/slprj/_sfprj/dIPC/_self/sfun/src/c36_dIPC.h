#ifndef __c36_dIPC_h__
#define __c36_dIPC_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc36_dIPCInstanceStruct
#define typedef_SFc36_dIPCInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c36_sfEvent;
  boolean_T c36_isStable;
  boolean_T c36_doneDoubleBufferReInit;
  uint8_T c36_is_active_c36_dIPC;
  real_T (*c36_G)[72];
  real_T (*c36_x)[14];
  real_T (*c36_r)[6];
} SFc36_dIPCInstanceStruct;

#endif                                 /*typedef_SFc36_dIPCInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c36_dIPC_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c36_dIPC_get_check_sum(mxArray *plhs[]);
extern void c36_dIPC_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

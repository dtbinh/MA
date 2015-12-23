#ifndef __c1_IPC4M_h__
#define __c1_IPC4M_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_IPC4MInstanceStruct
#define typedef_SFc1_IPC4MInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_isStable;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_IPC4M;
  real_T (*c1_x_o)[7];
  real_T (*c1_x)[28];
} SFc1_IPC4MInstanceStruct;

#endif                                 /*typedef_SFc1_IPC4MInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_IPC4M_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_IPC4M_get_check_sum(mxArray *plhs[]);
extern void c1_IPC4M_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

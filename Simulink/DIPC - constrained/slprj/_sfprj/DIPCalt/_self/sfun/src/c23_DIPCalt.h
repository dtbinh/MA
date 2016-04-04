#ifndef __c23_DIPCalt_h__
#define __c23_DIPCalt_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc23_DIPCaltInstanceStruct
#define typedef_SFc23_DIPCaltInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c23_sfEvent;
  boolean_T c23_isStable;
  boolean_T c23_doneDoubleBufferReInit;
  uint8_T c23_is_active_c23_DIPCalt;
  real_T c23_j1;
  real_T c23_m1;
  real_T (*c23_dx)[6];
  real_T (*c23_hcoriolis)[6];
} SFc23_DIPCaltInstanceStruct;

#endif                                 /*typedef_SFc23_DIPCaltInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c23_DIPCalt_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c23_DIPCalt_get_check_sum(mxArray *plhs[]);
extern void c23_DIPCalt_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

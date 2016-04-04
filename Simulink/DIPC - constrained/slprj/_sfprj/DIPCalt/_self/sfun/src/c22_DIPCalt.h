#ifndef __c22_DIPCalt_h__
#define __c22_DIPCalt_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc22_DIPCaltInstanceStruct
#define typedef_SFc22_DIPCaltInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c22_sfEvent;
  boolean_T c22_isStable;
  boolean_T c22_doneDoubleBufferReInit;
  uint8_T c22_is_active_c22_DIPCalt;
  real_T c22_j2;
  real_T c22_m2;
  real_T (*c22_dx)[6];
  real_T (*c22_hcoriolis)[6];
} SFc22_DIPCaltInstanceStruct;

#endif                                 /*typedef_SFc22_DIPCaltInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c22_DIPCalt_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c22_DIPCalt_get_check_sum(mxArray *plhs[]);
extern void c22_DIPCalt_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

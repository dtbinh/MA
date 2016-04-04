#ifndef __c24_DIPCalt_h__
#define __c24_DIPCalt_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc24_DIPCaltInstanceStruct
#define typedef_SFc24_DIPCaltInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c24_sfEvent;
  boolean_T c24_isStable;
  boolean_T c24_doneDoubleBufferReInit;
  uint8_T c24_is_active_c24_DIPCalt;
  real_T c24_j3;
  real_T c24_m3;
  real_T (*c24_dx)[6];
  real_T (*c24_hcoriolis)[6];
} SFc24_DIPCaltInstanceStruct;

#endif                                 /*typedef_SFc24_DIPCaltInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c24_DIPCalt_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c24_DIPCalt_get_check_sum(mxArray *plhs[]);
extern void c24_DIPCalt_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

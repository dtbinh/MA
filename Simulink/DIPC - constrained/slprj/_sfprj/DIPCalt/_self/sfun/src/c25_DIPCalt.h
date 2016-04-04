#ifndef __c25_DIPCalt_h__
#define __c25_DIPCalt_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc25_DIPCaltInstanceStruct
#define typedef_SFc25_DIPCaltInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c25_sfEvent;
  boolean_T c25_isStable;
  boolean_T c25_doneDoubleBufferReInit;
  uint8_T c25_is_active_c25_DIPCalt;
  real_T c25_j4;
  real_T c25_m4;
  real_T (*c25_dx)[6];
  real_T (*c25_hcoriolis)[6];
} SFc25_DIPCaltInstanceStruct;

#endif                                 /*typedef_SFc25_DIPCaltInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c25_DIPCalt_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c25_DIPCalt_get_check_sum(mxArray *plhs[]);
extern void c25_DIPCalt_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

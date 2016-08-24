#ifndef __c9_cdIPCbounding_h__
#define __c9_cdIPCbounding_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc9_cdIPCboundingInstanceStruct
#define typedef_SFc9_cdIPCboundingInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c9_sfEvent;
  boolean_T c9_isStable;
  boolean_T c9_doneDoubleBufferReInit;
  uint8_T c9_is_active_c9_cdIPCbounding;
  real_T c9_ks;
  real_T c9_kappas;
  real_T *c9_eta;
  real_T (*c9_K)[36];
} SFc9_cdIPCboundingInstanceStruct;

#endif                                 /*typedef_SFc9_cdIPCboundingInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c9_cdIPCbounding_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c9_cdIPCbounding_get_check_sum(mxArray *plhs[]);
extern void c9_cdIPCbounding_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif

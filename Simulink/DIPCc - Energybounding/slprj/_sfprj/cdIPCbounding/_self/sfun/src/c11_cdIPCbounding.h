#ifndef __c11_cdIPCbounding_h__
#define __c11_cdIPCbounding_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc11_cdIPCboundingInstanceStruct
#define typedef_SFc11_cdIPCboundingInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c11_sfEvent;
  boolean_T c11_isStable;
  boolean_T c11_doneDoubleBufferReInit;
  uint8_T c11_is_active_c11_cdIPCbounding;
  real_T c11_ks;
  real_T c11_kappas;
  real_T *c11_eta;
  real_T (*c11_K)[36];
} SFc11_cdIPCboundingInstanceStruct;

#endif                                 /*typedef_SFc11_cdIPCboundingInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c11_cdIPCbounding_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c11_cdIPCbounding_get_check_sum(mxArray *plhs[]);
extern void c11_cdIPCbounding_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif

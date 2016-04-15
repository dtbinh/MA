#ifndef __c9_CaccavaleVillani_h__
#define __c9_CaccavaleVillani_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc9_CaccavaleVillaniInstanceStruct
#define typedef_SFc9_CaccavaleVillaniInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c9_sfEvent;
  boolean_T c9_isStable;
  boolean_T c9_doneDoubleBufferReInit;
  uint8_T c9_is_active_c9_CaccavaleVillani;
  real_T c9_k1;
  real_T c9_kappa1;
  real_T *c9_eta1;
  real_T (*c9_K)[36];
} SFc9_CaccavaleVillaniInstanceStruct;

#endif                                 /*typedef_SFc9_CaccavaleVillaniInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c9_CaccavaleVillani_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c9_CaccavaleVillani_get_check_sum(mxArray *plhs[]);
extern void c9_CaccavaleVillani_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif

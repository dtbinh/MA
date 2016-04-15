#ifndef __c8_CaccavaleVillani_h__
#define __c8_CaccavaleVillani_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc8_CaccavaleVillaniInstanceStruct
#define typedef_SFc8_CaccavaleVillaniInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c8_sfEvent;
  boolean_T c8_isStable;
  boolean_T c8_doneDoubleBufferReInit;
  uint8_T c8_is_active_c8_CaccavaleVillani;
  real_T c8_k1;
  real_T c8_kappa1;
  real_T *c8_eta1;
  real_T (*c8_K)[36];
} SFc8_CaccavaleVillaniInstanceStruct;

#endif                                 /*typedef_SFc8_CaccavaleVillaniInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c8_CaccavaleVillani_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c8_CaccavaleVillani_get_check_sum(mxArray *plhs[]);
extern void c8_CaccavaleVillani_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif

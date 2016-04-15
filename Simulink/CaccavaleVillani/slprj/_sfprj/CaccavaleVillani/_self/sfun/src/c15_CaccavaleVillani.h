#ifndef __c15_CaccavaleVillani_h__
#define __c15_CaccavaleVillani_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc15_CaccavaleVillaniInstanceStruct
#define typedef_SFc15_CaccavaleVillaniInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c15_sfEvent;
  boolean_T c15_isStable;
  boolean_T c15_doneDoubleBufferReInit;
  uint8_T c15_is_active_c15_CaccavaleVillani;
  real_T c15_kpt;
  real_T c15_kpr;
  real_T *c15_eta4;
  real_T (*c15_K)[36];
} SFc15_CaccavaleVillaniInstanceStruct;

#endif                                 /*typedef_SFc15_CaccavaleVillaniInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c15_CaccavaleVillani_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c15_CaccavaleVillani_get_check_sum(mxArray *plhs[]);
extern void c15_CaccavaleVillani_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif

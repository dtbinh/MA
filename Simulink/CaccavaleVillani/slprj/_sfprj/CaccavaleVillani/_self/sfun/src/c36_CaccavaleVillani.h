#ifndef __c36_CaccavaleVillani_h__
#define __c36_CaccavaleVillani_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc36_CaccavaleVillaniInstanceStruct
#define typedef_SFc36_CaccavaleVillaniInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c36_sfEvent;
  boolean_T c36_isStable;
  boolean_T c36_doneDoubleBufferReInit;
  uint8_T c36_is_active_c36_CaccavaleVillani;
  real_T c36_r[12];
  real_T (*c36_G)[144];
  real_T (*c36_x)[28];
} SFc36_CaccavaleVillaniInstanceStruct;

#endif                                 /*typedef_SFc36_CaccavaleVillaniInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c36_CaccavaleVillani_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c36_CaccavaleVillani_get_check_sum(mxArray *plhs[]);
extern void c36_CaccavaleVillani_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif

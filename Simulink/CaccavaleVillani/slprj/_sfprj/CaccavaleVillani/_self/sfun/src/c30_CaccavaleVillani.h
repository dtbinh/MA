#ifndef __c30_CaccavaleVillani_h__
#define __c30_CaccavaleVillani_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc30_CaccavaleVillaniInstanceStruct
#define typedef_SFc30_CaccavaleVillaniInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c30_sfEvent;
  boolean_T c30_isStable;
  boolean_T c30_doneDoubleBufferReInit;
  uint8_T c30_is_active_c30_CaccavaleVillani;
  real_T c30_r[12];
  real_T (*c30_Ared)[432];
  real_T (*c30_x)[28];
} SFc30_CaccavaleVillaniInstanceStruct;

#endif                                 /*typedef_SFc30_CaccavaleVillaniInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c30_CaccavaleVillani_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c30_CaccavaleVillani_get_check_sum(mxArray *plhs[]);
extern void c30_CaccavaleVillani_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif

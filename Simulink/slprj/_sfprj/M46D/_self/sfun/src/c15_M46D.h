#ifndef __c15_M46D_h__
#define __c15_M46D_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc15_M46DInstanceStruct
#define typedef_SFc15_M46DInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c15_sfEvent;
  boolean_T c15_isStable;
  boolean_T c15_doneDoubleBufferReInit;
  uint8_T c15_is_active_c15_M46D;
  real_T (*c15_x)[30];
  real_T (*c15_A_xyz)[9];
} SFc15_M46DInstanceStruct;

#endif                                 /*typedef_SFc15_M46DInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c15_M46D_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c15_M46D_get_check_sum(mxArray *plhs[]);
extern void c15_M46D_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

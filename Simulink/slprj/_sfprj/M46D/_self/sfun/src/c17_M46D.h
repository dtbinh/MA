#ifndef __c17_M46D_h__
#define __c17_M46D_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc17_M46DInstanceStruct
#define typedef_SFc17_M46DInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c17_sfEvent;
  boolean_T c17_isStable;
  boolean_T c17_doneDoubleBufferReInit;
  uint8_T c17_is_active_c17_M46D;
  real_T c17_r[12];
  real_T (*c17_dx)[6];
  real_T (*c17_rot)[6];
} SFc17_M46DInstanceStruct;

#endif                                 /*typedef_SFc17_M46DInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c17_M46D_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c17_M46D_get_check_sum(mxArray *plhs[]);
extern void c17_M46D_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

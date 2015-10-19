#ifndef __c4_M46D_h__
#define __c4_M46D_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc4_M46DInstanceStruct
#define typedef_SFc4_M46DInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  boolean_T c4_isStable;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_M46D;
  real_T c4_r[12];
  real_T (*c4_G)[144];
} SFc4_M46DInstanceStruct;

#endif                                 /*typedef_SFc4_M46DInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_M46D_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_M46D_get_check_sum(mxArray *plhs[]);
extern void c4_M46D_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

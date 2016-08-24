#ifndef __c6_DIPCRT_h__
#define __c6_DIPCRT_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc6_DIPCRTInstanceStruct
#define typedef_SFc6_DIPCRTInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c6_sfEvent;
  boolean_T c6_isStable;
  boolean_T c6_doneDoubleBufferReInit;
  uint8_T c6_is_active_c6_DIPCRT;
  real_T c6_r[12];
  real_T (*c6_dx)[24];
  real_T (*c6_b)[24];
  real_T (*c6_x)[28];
} SFc6_DIPCRTInstanceStruct;

#endif                                 /*typedef_SFc6_DIPCRTInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c6_DIPCRT_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c6_DIPCRT_get_check_sum(mxArray *plhs[]);
extern void c6_DIPCRT_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

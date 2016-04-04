#ifndef __c32_DIPCalt_h__
#define __c32_DIPCalt_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc32_DIPCaltInstanceStruct
#define typedef_SFc32_DIPCaltInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c32_sfEvent;
  boolean_T c32_isStable;
  boolean_T c32_doneDoubleBufferReInit;
  uint8_T c32_is_active_c32_DIPCalt;
  real_T c32_rv[12];
  real_T (*c32_dx)[6];
  real_T (*c32_b)[24];
  real_T (*c32_x)[7];
} SFc32_DIPCaltInstanceStruct;

#endif                                 /*typedef_SFc32_DIPCaltInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c32_DIPCalt_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c32_DIPCalt_get_check_sum(mxArray *plhs[]);
extern void c32_DIPCalt_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

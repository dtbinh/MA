#ifndef __c29_DIPCalt_h__
#define __c29_DIPCalt_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc29_DIPCaltInstanceStruct
#define typedef_SFc29_DIPCaltInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c29_sfEvent;
  boolean_T c29_isStable;
  boolean_T c29_doneDoubleBufferReInit;
  uint8_T c29_is_active_c29_DIPCalt;
  real_T c29_rv[12];
  real_T (*c29_A)[720];
  real_T (*c29_x)[7];
} SFc29_DIPCaltInstanceStruct;

#endif                                 /*typedef_SFc29_DIPCaltInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c29_DIPCalt_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c29_DIPCalt_get_check_sum(mxArray *plhs[]);
extern void c29_DIPCalt_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

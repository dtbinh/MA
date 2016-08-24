#ifndef __c31_cdIPCbounding_h__
#define __c31_cdIPCbounding_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc31_cdIPCboundingInstanceStruct
#define typedef_SFc31_cdIPCboundingInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c31_sfEvent;
  boolean_T c31_isStable;
  boolean_T c31_doneDoubleBufferReInit;
  uint8_T c31_is_active_c31_cdIPCbounding;
  real_T c31_r[12];
  real_T (*c31_x)[28];
  real_T (*c31_bred)[18];
  real_T (*c31_dx)[24];
} SFc31_cdIPCboundingInstanceStruct;

#endif                                 /*typedef_SFc31_cdIPCboundingInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c31_cdIPCbounding_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c31_cdIPCbounding_get_check_sum(mxArray *plhs[]);
extern void c31_cdIPCbounding_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif

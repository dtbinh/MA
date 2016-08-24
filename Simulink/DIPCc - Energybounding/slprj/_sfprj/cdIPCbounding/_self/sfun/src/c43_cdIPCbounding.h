#ifndef __c43_cdIPCbounding_h__
#define __c43_cdIPCbounding_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc43_cdIPCboundingInstanceStruct
#define typedef_SFc43_cdIPCboundingInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c43_sfEvent;
  boolean_T c43_isStable;
  boolean_T c43_doneDoubleBufferReInit;
  uint8_T c43_is_active_c43_cdIPCbounding;
  real_T (*c43_hw)[24];
  real_T (*c43_x)[28];
  real_T (*c43_h_int)[24];
} SFc43_cdIPCboundingInstanceStruct;

#endif                                 /*typedef_SFc43_cdIPCboundingInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c43_cdIPCbounding_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c43_cdIPCbounding_get_check_sum(mxArray *plhs[]);
extern void c43_cdIPCbounding_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif

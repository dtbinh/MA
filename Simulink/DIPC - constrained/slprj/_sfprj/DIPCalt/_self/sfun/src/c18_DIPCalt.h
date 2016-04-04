#ifndef __c18_DIPCalt_h__
#define __c18_DIPCalt_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc18_DIPCaltInstanceStruct
#define typedef_SFc18_DIPCaltInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c18_sfEvent;
  boolean_T c18_isStable;
  boolean_T c18_doneDoubleBufferReInit;
  uint8_T c18_is_active_c18_DIPCalt;
  real_T c18_rv[12];
  real_T (*c18_xb)[7];
  real_T (*c18_dxb)[6];
  real_T (*c18_b)[24];
} SFc18_DIPCaltInstanceStruct;

#endif                                 /*typedef_SFc18_DIPCaltInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c18_DIPCalt_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c18_DIPCalt_get_check_sum(mxArray *plhs[]);
extern void c18_DIPCalt_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

#ifndef __c37_DIPCalt_h__
#define __c37_DIPCalt_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc37_DIPCaltInstanceStruct
#define typedef_SFc37_DIPCaltInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c37_sfEvent;
  boolean_T c37_isStable;
  boolean_T c37_doneDoubleBufferReInit;
  uint8_T c37_is_active_c37_DIPCalt;
  real_T c37_r[12];
  real_T (*c37_p_o)[3];
  real_T (*c37_q_o)[4];
  real_T (*c37_x)[28];
} SFc37_DIPCaltInstanceStruct;

#endif                                 /*typedef_SFc37_DIPCaltInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c37_DIPCalt_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c37_DIPCalt_get_check_sum(mxArray *plhs[]);
extern void c37_DIPCalt_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

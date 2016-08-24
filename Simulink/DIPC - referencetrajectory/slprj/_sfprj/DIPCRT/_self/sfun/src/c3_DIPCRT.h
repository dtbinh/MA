#ifndef __c3_DIPCRT_h__
#define __c3_DIPCRT_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_DIPCRTInstanceStruct
#define typedef_SFc3_DIPCRTInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  boolean_T c3_isStable;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_DIPCRT;
  real_T c3_rv[12];
  real_T (*c3_pb)[3];
  real_T (*c3_qb)[4];
  real_T (*c3_pb3)[3];
  real_T (*c3_qb3)[4];
} SFc3_DIPCRTInstanceStruct;

#endif                                 /*typedef_SFc3_DIPCRTInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_DIPCRT_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_DIPCRT_get_check_sum(mxArray *plhs[]);
extern void c3_DIPCRT_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

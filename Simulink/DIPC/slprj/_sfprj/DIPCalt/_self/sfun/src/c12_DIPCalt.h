#ifndef __c12_DIPCalt_h__
#define __c12_DIPCalt_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc12_DIPCaltInstanceStruct
#define typedef_SFc12_DIPCaltInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c12_sfEvent;
  boolean_T c12_isStable;
  boolean_T c12_doneDoubleBufferReInit;
  uint8_T c12_is_active_c12_DIPCalt;
  real_T c12_rv[12];
  real_T (*c12_G)[144];
  real_T (*c12_x)[7];
} SFc12_DIPCaltInstanceStruct;

#endif                                 /*typedef_SFc12_DIPCaltInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c12_DIPCalt_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c12_DIPCalt_get_check_sum(mxArray *plhs[]);
extern void c12_DIPCalt_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

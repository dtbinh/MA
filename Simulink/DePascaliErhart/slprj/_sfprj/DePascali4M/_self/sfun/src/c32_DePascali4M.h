#ifndef __c32_DePascali4M_h__
#define __c32_DePascali4M_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc32_DePascali4MInstanceStruct
#define typedef_SFc32_DePascali4MInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c32_sfEvent;
  boolean_T c32_isStable;
  boolean_T c32_doneDoubleBufferReInit;
  uint8_T c32_is_active_c32_DePascali4M;
  real_T c32_m0;
  real_T c32_j0;
  real_T (*c32_G)[144];
  real_T (*c32_Mapp)[36];
  real_T (*c32_M)[576];
} SFc32_DePascali4MInstanceStruct;

#endif                                 /*typedef_SFc32_DePascali4MInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c32_DePascali4M_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c32_DePascali4M_get_check_sum(mxArray *plhs[]);
extern void c32_DePascali4M_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif

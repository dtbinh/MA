#ifndef __c34_DePascali4M_h__
#define __c34_DePascali4M_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc34_DePascali4MInstanceStruct
#define typedef_SFc34_DePascali4MInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c34_sfEvent;
  boolean_T c34_isStable;
  boolean_T c34_doneDoubleBufferReInit;
  uint8_T c34_is_active_c34_DePascali4M;
  real_T c34_j0;
  real_T c34_m0;
  real_T (*c34_dx)[24];
  real_T (*c34_hcoriolis)[6];
} SFc34_DePascali4MInstanceStruct;

#endif                                 /*typedef_SFc34_DePascali4MInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c34_DePascali4M_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c34_DePascali4M_get_check_sum(mxArray *plhs[]);
extern void c34_DePascali4M_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif

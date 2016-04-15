#ifndef __c7_DePascali4M_h__
#define __c7_DePascali4M_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc7_DePascali4MInstanceStruct
#define typedef_SFc7_DePascali4MInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c7_sfEvent;
  boolean_T c7_isStable;
  boolean_T c7_doneDoubleBufferReInit;
  uint8_T c7_is_active_c7_DePascali4M;
  real_T c7_j0;
  real_T c7_m0;
  real_T (*c7_dx)[24];
  real_T (*c7_hcoriolis)[6];
} SFc7_DePascali4MInstanceStruct;

#endif                                 /*typedef_SFc7_DePascali4MInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c7_DePascali4M_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c7_DePascali4M_get_check_sum(mxArray *plhs[]);
extern void c7_DePascali4M_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif

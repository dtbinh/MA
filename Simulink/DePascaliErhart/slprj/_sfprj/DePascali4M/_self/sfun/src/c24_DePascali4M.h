#ifndef __c24_DePascali4M_h__
#define __c24_DePascali4M_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc24_DePascali4MInstanceStruct
#define typedef_SFc24_DePascali4MInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c24_sfEvent;
  boolean_T c24_isStable;
  boolean_T c24_doneDoubleBufferReInit;
  uint8_T c24_is_active_c24_DePascali4M;
  real_T c24_j0;
  real_T (*c24_dx_do)[6];
  real_T (*c24_C_o)[36];
} SFc24_DePascali4MInstanceStruct;

#endif                                 /*typedef_SFc24_DePascali4MInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c24_DePascali4M_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c24_DePascali4M_get_check_sum(mxArray *plhs[]);
extern void c24_DePascali4M_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif

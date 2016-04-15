#ifndef __c39_DePascali4M_h__
#define __c39_DePascali4M_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc39_DePascali4MInstanceStruct
#define typedef_SFc39_DePascali4MInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c39_sfEvent;
  boolean_T c39_isStable;
  boolean_T c39_doneDoubleBufferReInit;
  uint8_T c39_is_active_c39_DePascali4M;
  real_T c39_r[12];
  real_T (*c39_bred)[18];
  real_T (*c39_dx)[24];
  real_T (*c39_x)[28];
} SFc39_DePascali4MInstanceStruct;

#endif                                 /*typedef_SFc39_DePascali4MInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c39_DePascali4M_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c39_DePascali4M_get_check_sum(mxArray *plhs[]);
extern void c39_DePascali4M_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif

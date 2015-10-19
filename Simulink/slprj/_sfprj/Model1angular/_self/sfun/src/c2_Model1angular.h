#ifndef __c2_Model1angular_h__
#define __c2_Model1angular_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc2_Model1angularInstanceStruct
#define typedef_SFc2_Model1angularInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_isStable;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_Model1angular;
  real_T c2_k1;
  real_T c2_kappa1;
  real_T *c2_u;
  real_T (*c2_K)[36];
} SFc2_Model1angularInstanceStruct;

#endif                                 /*typedef_SFc2_Model1angularInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_Model1angular_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_Model1angular_get_check_sum(mxArray *plhs[]);
extern void c2_Model1angular_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif

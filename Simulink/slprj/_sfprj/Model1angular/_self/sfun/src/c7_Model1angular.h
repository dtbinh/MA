#ifndef __c7_Model1angular_h__
#define __c7_Model1angular_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc7_Model1angularInstanceStruct
#define typedef_SFc7_Model1angularInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c7_sfEvent;
  boolean_T c7_isStable;
  boolean_T c7_doneDoubleBufferReInit;
  uint8_T c7_is_active_c7_Model1angular;
  real_T c7_r[6];
  real_T (*c7_dx)[18];
  real_T (*c7_rot)[18];
} SFc7_Model1angularInstanceStruct;

#endif                                 /*typedef_SFc7_Model1angularInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c7_Model1angular_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c7_Model1angular_get_check_sum(mxArray *plhs[]);
extern void c7_Model1angular_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif

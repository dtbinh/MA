#ifndef __c15_Model1angular_h__
#define __c15_Model1angular_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc15_Model1angularInstanceStruct
#define typedef_SFc15_Model1angularInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c15_sfEvent;
  boolean_T c15_isStable;
  boolean_T c15_doneDoubleBufferReInit;
  uint8_T c15_is_active_c15_Model1angular;
  real_T (*c15_x)[18];
  real_T (*c15_A_xyz)[9];
} SFc15_Model1angularInstanceStruct;

#endif                                 /*typedef_SFc15_Model1angularInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c15_Model1angular_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c15_Model1angular_get_check_sum(mxArray *plhs[]);
extern void c15_Model1angular_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif

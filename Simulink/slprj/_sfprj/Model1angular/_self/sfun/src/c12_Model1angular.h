#ifndef __c12_Model1angular_h__
#define __c12_Model1angular_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc12_Model1angularInstanceStruct
#define typedef_SFc12_Model1angularInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c12_sfEvent;
  boolean_T c12_isStable;
  boolean_T c12_doneDoubleBufferReInit;
  uint8_T c12_is_active_c12_Model1angular;
  real_T c12_r[6];
  real_T (*c12_dx)[6];
  real_T (*c12_rot)[6];
} SFc12_Model1angularInstanceStruct;

#endif                                 /*typedef_SFc12_Model1angularInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c12_Model1angular_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c12_Model1angular_get_check_sum(mxArray *plhs[]);
extern void c12_Model1angular_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif

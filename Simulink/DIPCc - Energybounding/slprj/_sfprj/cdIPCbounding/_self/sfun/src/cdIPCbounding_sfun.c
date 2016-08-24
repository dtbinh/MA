/* Include files */

#include "cdIPCbounding_sfun.h"
#include "cdIPCbounding_sfun_debug_macros.h"
#include "c1_cdIPCbounding.h"
#include "c5_cdIPCbounding.h"
#include "c6_cdIPCbounding.h"
#include "c7_cdIPCbounding.h"
#include "c8_cdIPCbounding.h"
#include "c9_cdIPCbounding.h"
#include "c10_cdIPCbounding.h"
#include "c11_cdIPCbounding.h"
#include "c20_cdIPCbounding.h"
#include "c21_cdIPCbounding.h"
#include "c27_cdIPCbounding.h"
#include "c29_cdIPCbounding.h"
#include "c30_cdIPCbounding.h"
#include "c31_cdIPCbounding.h"
#include "c36_cdIPCbounding.h"
#include "c37_cdIPCbounding.h"
#include "c43_cdIPCbounding.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _cdIPCboundingMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void cdIPCbounding_initializer(void)
{
}

void cdIPCbounding_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_cdIPCbounding_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_cdIPCbounding_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_cdIPCbounding_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_cdIPCbounding_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_cdIPCbounding_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_cdIPCbounding_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_cdIPCbounding_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_cdIPCbounding_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_cdIPCbounding_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==20) {
    c20_cdIPCbounding_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==21) {
    c21_cdIPCbounding_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==27) {
    c27_cdIPCbounding_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==29) {
    c29_cdIPCbounding_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==30) {
    c30_cdIPCbounding_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==31) {
    c31_cdIPCbounding_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==36) {
    c36_cdIPCbounding_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==37) {
    c37_cdIPCbounding_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==43) {
    c43_cdIPCbounding_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

extern void sf_cdIPCbounding_uses_exported_functions(int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[])
{
  plhs[0] = mxCreateLogicalScalar(0);
}

unsigned int sf_cdIPCbounding_process_check_sum_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3789395277U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(551907493U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4149512778U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2825514934U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3849347516U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4289657705U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3130741309U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(906424376U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_cdIPCbounding_get_check_sum(mxArray *plhs[]);
          sf_c1_cdIPCbounding_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_cdIPCbounding_get_check_sum(mxArray *plhs[]);
          sf_c5_cdIPCbounding_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_cdIPCbounding_get_check_sum(mxArray *plhs[]);
          sf_c6_cdIPCbounding_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_cdIPCbounding_get_check_sum(mxArray *plhs[]);
          sf_c7_cdIPCbounding_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_cdIPCbounding_get_check_sum(mxArray *plhs[]);
          sf_c8_cdIPCbounding_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_cdIPCbounding_get_check_sum(mxArray *plhs[]);
          sf_c9_cdIPCbounding_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_cdIPCbounding_get_check_sum(mxArray *plhs[]);
          sf_c10_cdIPCbounding_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_cdIPCbounding_get_check_sum(mxArray *plhs[]);
          sf_c11_cdIPCbounding_get_check_sum(plhs);
          break;
        }

       case 20:
        {
          extern void sf_c20_cdIPCbounding_get_check_sum(mxArray *plhs[]);
          sf_c20_cdIPCbounding_get_check_sum(plhs);
          break;
        }

       case 21:
        {
          extern void sf_c21_cdIPCbounding_get_check_sum(mxArray *plhs[]);
          sf_c21_cdIPCbounding_get_check_sum(plhs);
          break;
        }

       case 27:
        {
          extern void sf_c27_cdIPCbounding_get_check_sum(mxArray *plhs[]);
          sf_c27_cdIPCbounding_get_check_sum(plhs);
          break;
        }

       case 29:
        {
          extern void sf_c29_cdIPCbounding_get_check_sum(mxArray *plhs[]);
          sf_c29_cdIPCbounding_get_check_sum(plhs);
          break;
        }

       case 30:
        {
          extern void sf_c30_cdIPCbounding_get_check_sum(mxArray *plhs[]);
          sf_c30_cdIPCbounding_get_check_sum(plhs);
          break;
        }

       case 31:
        {
          extern void sf_c31_cdIPCbounding_get_check_sum(mxArray *plhs[]);
          sf_c31_cdIPCbounding_get_check_sum(plhs);
          break;
        }

       case 36:
        {
          extern void sf_c36_cdIPCbounding_get_check_sum(mxArray *plhs[]);
          sf_c36_cdIPCbounding_get_check_sum(plhs);
          break;
        }

       case 37:
        {
          extern void sf_c37_cdIPCbounding_get_check_sum(mxArray *plhs[]);
          sf_c37_cdIPCbounding_get_check_sum(plhs);
          break;
        }

       case 43:
        {
          extern void sf_c43_cdIPCbounding_get_check_sum(mxArray *plhs[]);
          sf_c43_cdIPCbounding_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3061339410U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1991824845U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3599338742U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2357874978U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2754269466U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1722128615U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1700183099U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1488475885U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_cdIPCbounding_autoinheritance_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "Dn6SdSNVFnUGEvF7qDlrPD") == 0) {
          extern mxArray *sf_c1_cdIPCbounding_get_autoinheritance_info(void);
          plhs[0] = sf_c1_cdIPCbounding_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "tna1BcwMvoe2fRwT2pfL9E") == 0) {
          extern mxArray *sf_c5_cdIPCbounding_get_autoinheritance_info(void);
          plhs[0] = sf_c5_cdIPCbounding_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "MNIWBbuNFTZjpPbKWaFHcH") == 0) {
          extern mxArray *sf_c6_cdIPCbounding_get_autoinheritance_info(void);
          plhs[0] = sf_c6_cdIPCbounding_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "tYATzzCrS6feeZiFtybCl") == 0) {
          extern mxArray *sf_c7_cdIPCbounding_get_autoinheritance_info(void);
          plhs[0] = sf_c7_cdIPCbounding_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "LWhmDXPo0xLTSwbSzLYEnF") == 0) {
          extern mxArray *sf_c8_cdIPCbounding_get_autoinheritance_info(void);
          plhs[0] = sf_c8_cdIPCbounding_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "LWhmDXPo0xLTSwbSzLYEnF") == 0) {
          extern mxArray *sf_c9_cdIPCbounding_get_autoinheritance_info(void);
          plhs[0] = sf_c9_cdIPCbounding_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "LWhmDXPo0xLTSwbSzLYEnF") == 0) {
          extern mxArray *sf_c10_cdIPCbounding_get_autoinheritance_info(void);
          plhs[0] = sf_c10_cdIPCbounding_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "LWhmDXPo0xLTSwbSzLYEnF") == 0) {
          extern mxArray *sf_c11_cdIPCbounding_get_autoinheritance_info(void);
          plhs[0] = sf_c11_cdIPCbounding_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 20:
      {
        if (strcmp(aiChksum, "DKRH3B7QmNi49nBUEhDB6B") == 0) {
          extern mxArray *sf_c20_cdIPCbounding_get_autoinheritance_info(void);
          plhs[0] = sf_c20_cdIPCbounding_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 21:
      {
        if (strcmp(aiChksum, "LZhiaMxS9IJg7wYHjXeTrD") == 0) {
          extern mxArray *sf_c21_cdIPCbounding_get_autoinheritance_info(void);
          plhs[0] = sf_c21_cdIPCbounding_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 27:
      {
        if (strcmp(aiChksum, "1pmCPoNLGv6SESUuWS7WFF") == 0) {
          extern mxArray *sf_c27_cdIPCbounding_get_autoinheritance_info(void);
          plhs[0] = sf_c27_cdIPCbounding_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 29:
      {
        if (strcmp(aiChksum, "yMDaBA1W276qX2OfTSAkKH") == 0) {
          extern mxArray *sf_c29_cdIPCbounding_get_autoinheritance_info(void);
          plhs[0] = sf_c29_cdIPCbounding_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 30:
      {
        if (strcmp(aiChksum, "2DzyioPLwtmX08rJePnILC") == 0) {
          extern mxArray *sf_c30_cdIPCbounding_get_autoinheritance_info(void);
          plhs[0] = sf_c30_cdIPCbounding_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 31:
      {
        if (strcmp(aiChksum, "L4cHfneDxO6L1Btml4R76") == 0) {
          extern mxArray *sf_c31_cdIPCbounding_get_autoinheritance_info(void);
          plhs[0] = sf_c31_cdIPCbounding_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 36:
      {
        if (strcmp(aiChksum, "DD1R3ViA8FSKbVm79jLUZ") == 0) {
          extern mxArray *sf_c36_cdIPCbounding_get_autoinheritance_info(void);
          plhs[0] = sf_c36_cdIPCbounding_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 37:
      {
        if (strcmp(aiChksum, "HH5Q7NBdD7VBwfWldwVT5F") == 0) {
          extern mxArray *sf_c37_cdIPCbounding_get_autoinheritance_info(void);
          plhs[0] = sf_c37_cdIPCbounding_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 43:
      {
        if (strcmp(aiChksum, "aBAN3OqxekCRqIEyfPDBXC") == 0) {
          extern mxArray *sf_c43_cdIPCbounding_get_autoinheritance_info(void);
          plhs[0] = sf_c43_cdIPCbounding_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_cdIPCbounding_get_eml_resolved_functions_info( int nlhs, mxArray
  * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_cdIPCbounding_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_cdIPCbounding_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_cdIPCbounding_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_cdIPCbounding_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_cdIPCbounding_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_cdIPCbounding_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_cdIPCbounding_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_cdIPCbounding_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_cdIPCbounding_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_cdIPCbounding_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_cdIPCbounding_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_cdIPCbounding_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_cdIPCbounding_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_cdIPCbounding_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_cdIPCbounding_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_cdIPCbounding_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 20:
      {
        extern const mxArray
          *sf_c20_cdIPCbounding_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_cdIPCbounding_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 21:
      {
        extern const mxArray
          *sf_c21_cdIPCbounding_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c21_cdIPCbounding_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 27:
      {
        extern const mxArray
          *sf_c27_cdIPCbounding_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c27_cdIPCbounding_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 29:
      {
        extern const mxArray
          *sf_c29_cdIPCbounding_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c29_cdIPCbounding_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 30:
      {
        extern const mxArray
          *sf_c30_cdIPCbounding_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c30_cdIPCbounding_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 31:
      {
        extern const mxArray
          *sf_c31_cdIPCbounding_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c31_cdIPCbounding_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 36:
      {
        extern const mxArray
          *sf_c36_cdIPCbounding_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c36_cdIPCbounding_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 37:
      {
        extern const mxArray
          *sf_c37_cdIPCbounding_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c37_cdIPCbounding_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 43:
      {
        extern const mxArray
          *sf_c43_cdIPCbounding_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c43_cdIPCbounding_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_cdIPCbounding_third_party_uses_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "7OJks0cz0UacyDKRTMxzPH") == 0) {
          extern mxArray *sf_c1_cdIPCbounding_third_party_uses_info(void);
          plhs[0] = sf_c1_cdIPCbounding_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "wKjgDzYGh0AKSV9oCDZhuB") == 0) {
          extern mxArray *sf_c5_cdIPCbounding_third_party_uses_info(void);
          plhs[0] = sf_c5_cdIPCbounding_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "vEneZyO80AXkO3fgcTZVhD") == 0) {
          extern mxArray *sf_c6_cdIPCbounding_third_party_uses_info(void);
          plhs[0] = sf_c6_cdIPCbounding_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "TMlGanmzJMEGBnqyVVJ86E") == 0) {
          extern mxArray *sf_c7_cdIPCbounding_third_party_uses_info(void);
          plhs[0] = sf_c7_cdIPCbounding_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c8_cdIPCbounding_third_party_uses_info(void);
          plhs[0] = sf_c8_cdIPCbounding_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c9_cdIPCbounding_third_party_uses_info(void);
          plhs[0] = sf_c9_cdIPCbounding_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c10_cdIPCbounding_third_party_uses_info(void);
          plhs[0] = sf_c10_cdIPCbounding_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c11_cdIPCbounding_third_party_uses_info(void);
          plhs[0] = sf_c11_cdIPCbounding_third_party_uses_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "fhybwQwSsVrhCKGPRmFotE") == 0) {
          extern mxArray *sf_c20_cdIPCbounding_third_party_uses_info(void);
          plhs[0] = sf_c20_cdIPCbounding_third_party_uses_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "pyIGamOjptGW80ll0iGLaC") == 0) {
          extern mxArray *sf_c21_cdIPCbounding_third_party_uses_info(void);
          plhs[0] = sf_c21_cdIPCbounding_third_party_uses_info();
          break;
        }
      }

     case 27:
      {
        if (strcmp(tpChksum, "hC2vU5Voyv1xod92AC4KJC") == 0) {
          extern mxArray *sf_c27_cdIPCbounding_third_party_uses_info(void);
          plhs[0] = sf_c27_cdIPCbounding_third_party_uses_info();
          break;
        }
      }

     case 29:
      {
        if (strcmp(tpChksum, "bebCeimQRLUNrJCuUBUPo") == 0) {
          extern mxArray *sf_c29_cdIPCbounding_third_party_uses_info(void);
          plhs[0] = sf_c29_cdIPCbounding_third_party_uses_info();
          break;
        }
      }

     case 30:
      {
        if (strcmp(tpChksum, "KoBjyPLZLMM3KD77IWLpFB") == 0) {
          extern mxArray *sf_c30_cdIPCbounding_third_party_uses_info(void);
          plhs[0] = sf_c30_cdIPCbounding_third_party_uses_info();
          break;
        }
      }

     case 31:
      {
        if (strcmp(tpChksum, "WuMhkbnscSKHTcaYGq7t0C") == 0) {
          extern mxArray *sf_c31_cdIPCbounding_third_party_uses_info(void);
          plhs[0] = sf_c31_cdIPCbounding_third_party_uses_info();
          break;
        }
      }

     case 36:
      {
        if (strcmp(tpChksum, "R5fJ5cX5KyORqPmZdJfjYC") == 0) {
          extern mxArray *sf_c36_cdIPCbounding_third_party_uses_info(void);
          plhs[0] = sf_c36_cdIPCbounding_third_party_uses_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "1i3LZAfIaHjMJtsqqRFjjF") == 0) {
          extern mxArray *sf_c37_cdIPCbounding_third_party_uses_info(void);
          plhs[0] = sf_c37_cdIPCbounding_third_party_uses_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "IgmYsTd7hWQzxdq1sf59GB") == 0) {
          extern mxArray *sf_c43_cdIPCbounding_third_party_uses_info(void);
          plhs[0] = sf_c43_cdIPCbounding_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_cdIPCbounding_jit_fallback_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the jit_fallback_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_jit_fallback_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "7OJks0cz0UacyDKRTMxzPH") == 0) {
          extern mxArray *sf_c1_cdIPCbounding_jit_fallback_info(void);
          plhs[0] = sf_c1_cdIPCbounding_jit_fallback_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "wKjgDzYGh0AKSV9oCDZhuB") == 0) {
          extern mxArray *sf_c5_cdIPCbounding_jit_fallback_info(void);
          plhs[0] = sf_c5_cdIPCbounding_jit_fallback_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "vEneZyO80AXkO3fgcTZVhD") == 0) {
          extern mxArray *sf_c6_cdIPCbounding_jit_fallback_info(void);
          plhs[0] = sf_c6_cdIPCbounding_jit_fallback_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "TMlGanmzJMEGBnqyVVJ86E") == 0) {
          extern mxArray *sf_c7_cdIPCbounding_jit_fallback_info(void);
          plhs[0] = sf_c7_cdIPCbounding_jit_fallback_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c8_cdIPCbounding_jit_fallback_info(void);
          plhs[0] = sf_c8_cdIPCbounding_jit_fallback_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c9_cdIPCbounding_jit_fallback_info(void);
          plhs[0] = sf_c9_cdIPCbounding_jit_fallback_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c10_cdIPCbounding_jit_fallback_info(void);
          plhs[0] = sf_c10_cdIPCbounding_jit_fallback_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c11_cdIPCbounding_jit_fallback_info(void);
          plhs[0] = sf_c11_cdIPCbounding_jit_fallback_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "fhybwQwSsVrhCKGPRmFotE") == 0) {
          extern mxArray *sf_c20_cdIPCbounding_jit_fallback_info(void);
          plhs[0] = sf_c20_cdIPCbounding_jit_fallback_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "pyIGamOjptGW80ll0iGLaC") == 0) {
          extern mxArray *sf_c21_cdIPCbounding_jit_fallback_info(void);
          plhs[0] = sf_c21_cdIPCbounding_jit_fallback_info();
          break;
        }
      }

     case 27:
      {
        if (strcmp(tpChksum, "hC2vU5Voyv1xod92AC4KJC") == 0) {
          extern mxArray *sf_c27_cdIPCbounding_jit_fallback_info(void);
          plhs[0] = sf_c27_cdIPCbounding_jit_fallback_info();
          break;
        }
      }

     case 29:
      {
        if (strcmp(tpChksum, "bebCeimQRLUNrJCuUBUPo") == 0) {
          extern mxArray *sf_c29_cdIPCbounding_jit_fallback_info(void);
          plhs[0] = sf_c29_cdIPCbounding_jit_fallback_info();
          break;
        }
      }

     case 30:
      {
        if (strcmp(tpChksum, "KoBjyPLZLMM3KD77IWLpFB") == 0) {
          extern mxArray *sf_c30_cdIPCbounding_jit_fallback_info(void);
          plhs[0] = sf_c30_cdIPCbounding_jit_fallback_info();
          break;
        }
      }

     case 31:
      {
        if (strcmp(tpChksum, "WuMhkbnscSKHTcaYGq7t0C") == 0) {
          extern mxArray *sf_c31_cdIPCbounding_jit_fallback_info(void);
          plhs[0] = sf_c31_cdIPCbounding_jit_fallback_info();
          break;
        }
      }

     case 36:
      {
        if (strcmp(tpChksum, "R5fJ5cX5KyORqPmZdJfjYC") == 0) {
          extern mxArray *sf_c36_cdIPCbounding_jit_fallback_info(void);
          plhs[0] = sf_c36_cdIPCbounding_jit_fallback_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "1i3LZAfIaHjMJtsqqRFjjF") == 0) {
          extern mxArray *sf_c37_cdIPCbounding_jit_fallback_info(void);
          plhs[0] = sf_c37_cdIPCbounding_jit_fallback_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "IgmYsTd7hWQzxdq1sf59GB") == 0) {
          extern mxArray *sf_c43_cdIPCbounding_jit_fallback_info(void);
          plhs[0] = sf_c43_cdIPCbounding_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_cdIPCbounding_updateBuildInfo_args_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "7OJks0cz0UacyDKRTMxzPH") == 0) {
          extern mxArray *sf_c1_cdIPCbounding_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_cdIPCbounding_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "wKjgDzYGh0AKSV9oCDZhuB") == 0) {
          extern mxArray *sf_c5_cdIPCbounding_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_cdIPCbounding_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "vEneZyO80AXkO3fgcTZVhD") == 0) {
          extern mxArray *sf_c6_cdIPCbounding_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_cdIPCbounding_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "TMlGanmzJMEGBnqyVVJ86E") == 0) {
          extern mxArray *sf_c7_cdIPCbounding_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_cdIPCbounding_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c8_cdIPCbounding_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_cdIPCbounding_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c9_cdIPCbounding_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_cdIPCbounding_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c10_cdIPCbounding_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_cdIPCbounding_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c11_cdIPCbounding_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_cdIPCbounding_updateBuildInfo_args_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "fhybwQwSsVrhCKGPRmFotE") == 0) {
          extern mxArray *sf_c20_cdIPCbounding_updateBuildInfo_args_info(void);
          plhs[0] = sf_c20_cdIPCbounding_updateBuildInfo_args_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "pyIGamOjptGW80ll0iGLaC") == 0) {
          extern mxArray *sf_c21_cdIPCbounding_updateBuildInfo_args_info(void);
          plhs[0] = sf_c21_cdIPCbounding_updateBuildInfo_args_info();
          break;
        }
      }

     case 27:
      {
        if (strcmp(tpChksum, "hC2vU5Voyv1xod92AC4KJC") == 0) {
          extern mxArray *sf_c27_cdIPCbounding_updateBuildInfo_args_info(void);
          plhs[0] = sf_c27_cdIPCbounding_updateBuildInfo_args_info();
          break;
        }
      }

     case 29:
      {
        if (strcmp(tpChksum, "bebCeimQRLUNrJCuUBUPo") == 0) {
          extern mxArray *sf_c29_cdIPCbounding_updateBuildInfo_args_info(void);
          plhs[0] = sf_c29_cdIPCbounding_updateBuildInfo_args_info();
          break;
        }
      }

     case 30:
      {
        if (strcmp(tpChksum, "KoBjyPLZLMM3KD77IWLpFB") == 0) {
          extern mxArray *sf_c30_cdIPCbounding_updateBuildInfo_args_info(void);
          plhs[0] = sf_c30_cdIPCbounding_updateBuildInfo_args_info();
          break;
        }
      }

     case 31:
      {
        if (strcmp(tpChksum, "WuMhkbnscSKHTcaYGq7t0C") == 0) {
          extern mxArray *sf_c31_cdIPCbounding_updateBuildInfo_args_info(void);
          plhs[0] = sf_c31_cdIPCbounding_updateBuildInfo_args_info();
          break;
        }
      }

     case 36:
      {
        if (strcmp(tpChksum, "R5fJ5cX5KyORqPmZdJfjYC") == 0) {
          extern mxArray *sf_c36_cdIPCbounding_updateBuildInfo_args_info(void);
          plhs[0] = sf_c36_cdIPCbounding_updateBuildInfo_args_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "1i3LZAfIaHjMJtsqqRFjjF") == 0) {
          extern mxArray *sf_c37_cdIPCbounding_updateBuildInfo_args_info(void);
          plhs[0] = sf_c37_cdIPCbounding_updateBuildInfo_args_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "IgmYsTd7hWQzxdq1sf59GB") == 0) {
          extern mxArray *sf_c43_cdIPCbounding_updateBuildInfo_args_info(void);
          plhs[0] = sf_c43_cdIPCbounding_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void sf_cdIPCbounding_get_post_codegen_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  unsigned int chartFileNumber = (unsigned int) mxGetScalar(prhs[0]);
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  switch (chartFileNumber) {
   case 1:
    {
      if (strcmp(tpChksum, "7OJks0cz0UacyDKRTMxzPH") == 0) {
        extern mxArray *sf_c1_cdIPCbounding_get_post_codegen_info(void);
        plhs[0] = sf_c1_cdIPCbounding_get_post_codegen_info();
        return;
      }
    }
    break;

   case 5:
    {
      if (strcmp(tpChksum, "wKjgDzYGh0AKSV9oCDZhuB") == 0) {
        extern mxArray *sf_c5_cdIPCbounding_get_post_codegen_info(void);
        plhs[0] = sf_c5_cdIPCbounding_get_post_codegen_info();
        return;
      }
    }
    break;

   case 6:
    {
      if (strcmp(tpChksum, "vEneZyO80AXkO3fgcTZVhD") == 0) {
        extern mxArray *sf_c6_cdIPCbounding_get_post_codegen_info(void);
        plhs[0] = sf_c6_cdIPCbounding_get_post_codegen_info();
        return;
      }
    }
    break;

   case 7:
    {
      if (strcmp(tpChksum, "TMlGanmzJMEGBnqyVVJ86E") == 0) {
        extern mxArray *sf_c7_cdIPCbounding_get_post_codegen_info(void);
        plhs[0] = sf_c7_cdIPCbounding_get_post_codegen_info();
        return;
      }
    }
    break;

   case 8:
    {
      if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
        extern mxArray *sf_c8_cdIPCbounding_get_post_codegen_info(void);
        plhs[0] = sf_c8_cdIPCbounding_get_post_codegen_info();
        return;
      }
    }
    break;

   case 9:
    {
      if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
        extern mxArray *sf_c9_cdIPCbounding_get_post_codegen_info(void);
        plhs[0] = sf_c9_cdIPCbounding_get_post_codegen_info();
        return;
      }
    }
    break;

   case 10:
    {
      if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
        extern mxArray *sf_c10_cdIPCbounding_get_post_codegen_info(void);
        plhs[0] = sf_c10_cdIPCbounding_get_post_codegen_info();
        return;
      }
    }
    break;

   case 11:
    {
      if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
        extern mxArray *sf_c11_cdIPCbounding_get_post_codegen_info(void);
        plhs[0] = sf_c11_cdIPCbounding_get_post_codegen_info();
        return;
      }
    }
    break;

   case 20:
    {
      if (strcmp(tpChksum, "fhybwQwSsVrhCKGPRmFotE") == 0) {
        extern mxArray *sf_c20_cdIPCbounding_get_post_codegen_info(void);
        plhs[0] = sf_c20_cdIPCbounding_get_post_codegen_info();
        return;
      }
    }
    break;

   case 21:
    {
      if (strcmp(tpChksum, "pyIGamOjptGW80ll0iGLaC") == 0) {
        extern mxArray *sf_c21_cdIPCbounding_get_post_codegen_info(void);
        plhs[0] = sf_c21_cdIPCbounding_get_post_codegen_info();
        return;
      }
    }
    break;

   case 27:
    {
      if (strcmp(tpChksum, "hC2vU5Voyv1xod92AC4KJC") == 0) {
        extern mxArray *sf_c27_cdIPCbounding_get_post_codegen_info(void);
        plhs[0] = sf_c27_cdIPCbounding_get_post_codegen_info();
        return;
      }
    }
    break;

   case 29:
    {
      if (strcmp(tpChksum, "bebCeimQRLUNrJCuUBUPo") == 0) {
        extern mxArray *sf_c29_cdIPCbounding_get_post_codegen_info(void);
        plhs[0] = sf_c29_cdIPCbounding_get_post_codegen_info();
        return;
      }
    }
    break;

   case 30:
    {
      if (strcmp(tpChksum, "KoBjyPLZLMM3KD77IWLpFB") == 0) {
        extern mxArray *sf_c30_cdIPCbounding_get_post_codegen_info(void);
        plhs[0] = sf_c30_cdIPCbounding_get_post_codegen_info();
        return;
      }
    }
    break;

   case 31:
    {
      if (strcmp(tpChksum, "WuMhkbnscSKHTcaYGq7t0C") == 0) {
        extern mxArray *sf_c31_cdIPCbounding_get_post_codegen_info(void);
        plhs[0] = sf_c31_cdIPCbounding_get_post_codegen_info();
        return;
      }
    }
    break;

   case 36:
    {
      if (strcmp(tpChksum, "R5fJ5cX5KyORqPmZdJfjYC") == 0) {
        extern mxArray *sf_c36_cdIPCbounding_get_post_codegen_info(void);
        plhs[0] = sf_c36_cdIPCbounding_get_post_codegen_info();
        return;
      }
    }
    break;

   case 37:
    {
      if (strcmp(tpChksum, "1i3LZAfIaHjMJtsqqRFjjF") == 0) {
        extern mxArray *sf_c37_cdIPCbounding_get_post_codegen_info(void);
        plhs[0] = sf_c37_cdIPCbounding_get_post_codegen_info();
        return;
      }
    }
    break;

   case 43:
    {
      if (strcmp(tpChksum, "IgmYsTd7hWQzxdq1sf59GB") == 0) {
        extern mxArray *sf_c43_cdIPCbounding_get_post_codegen_info(void);
        plhs[0] = sf_c43_cdIPCbounding_get_post_codegen_info();
        return;
      }
    }
    break;

   default:
    break;
  }

  plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
}

void cdIPCbounding_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _cdIPCboundingMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "cdIPCbounding","sfun",0,17,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _cdIPCboundingMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _cdIPCboundingMachineNumber_,0);
}

void cdIPCbounding_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_cdIPCbounding_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("cdIPCbounding",
      "cdIPCbounding");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_cdIPCbounding_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}

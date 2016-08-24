/* Include files */

#include "dIPC_sfun.h"
#include "dIPC_sfun_debug_macros.h"
#include "c1_dIPC.h"
#include "c2_dIPC.h"
#include "c3_dIPC.h"
#include "c5_dIPC.h"
#include "c6_dIPC.h"
#include "c7_dIPC.h"
#include "c8_dIPC.h"
#include "c9_dIPC.h"
#include "c12_dIPC.h"
#include "c13_dIPC.h"
#include "c17_dIPC.h"
#include "c20_dIPC.h"
#include "c21_dIPC.h"
#include "c30_dIPC.h"
#include "c31_dIPC.h"
#include "c36_dIPC.h"
#include "c37_dIPC.h"
#include "c43_dIPC.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _dIPCMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void dIPC_initializer(void)
{
}

void dIPC_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_dIPC_method_dispatcher(SimStruct *simstructPtr, unsigned int
  chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_dIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_dIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_dIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_dIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_dIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_dIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_dIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_dIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_dIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_dIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_dIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==20) {
    c20_dIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==21) {
    c21_dIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==30) {
    c30_dIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==31) {
    c31_dIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==36) {
    c36_dIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==37) {
    c37_dIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==43) {
    c43_dIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

extern void sf_dIPC_uses_exported_functions(int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[])
{
  plhs[0] = mxCreateLogicalScalar(0);
}

unsigned int sf_dIPC_process_check_sum_call( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1336992578U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2657664642U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(337448773U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3889014870U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2071321192U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(130952499U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1264823653U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1398178225U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_dIPC_get_check_sum(mxArray *plhs[]);
          sf_c1_dIPC_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_dIPC_get_check_sum(mxArray *plhs[]);
          sf_c2_dIPC_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_dIPC_get_check_sum(mxArray *plhs[]);
          sf_c3_dIPC_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_dIPC_get_check_sum(mxArray *plhs[]);
          sf_c5_dIPC_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_dIPC_get_check_sum(mxArray *plhs[]);
          sf_c6_dIPC_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_dIPC_get_check_sum(mxArray *plhs[]);
          sf_c7_dIPC_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_dIPC_get_check_sum(mxArray *plhs[]);
          sf_c8_dIPC_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_dIPC_get_check_sum(mxArray *plhs[]);
          sf_c9_dIPC_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_dIPC_get_check_sum(mxArray *plhs[]);
          sf_c12_dIPC_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_dIPC_get_check_sum(mxArray *plhs[]);
          sf_c13_dIPC_get_check_sum(plhs);
          break;
        }

       case 17:
        {
          extern void sf_c17_dIPC_get_check_sum(mxArray *plhs[]);
          sf_c17_dIPC_get_check_sum(plhs);
          break;
        }

       case 20:
        {
          extern void sf_c20_dIPC_get_check_sum(mxArray *plhs[]);
          sf_c20_dIPC_get_check_sum(plhs);
          break;
        }

       case 21:
        {
          extern void sf_c21_dIPC_get_check_sum(mxArray *plhs[]);
          sf_c21_dIPC_get_check_sum(plhs);
          break;
        }

       case 30:
        {
          extern void sf_c30_dIPC_get_check_sum(mxArray *plhs[]);
          sf_c30_dIPC_get_check_sum(plhs);
          break;
        }

       case 31:
        {
          extern void sf_c31_dIPC_get_check_sum(mxArray *plhs[]);
          sf_c31_dIPC_get_check_sum(plhs);
          break;
        }

       case 36:
        {
          extern void sf_c36_dIPC_get_check_sum(mxArray *plhs[]);
          sf_c36_dIPC_get_check_sum(plhs);
          break;
        }

       case 37:
        {
          extern void sf_c37_dIPC_get_check_sum(mxArray *plhs[]);
          sf_c37_dIPC_get_check_sum(plhs);
          break;
        }

       case 43:
        {
          extern void sf_c43_dIPC_get_check_sum(mxArray *plhs[]);
          sf_c43_dIPC_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2839509406U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4216808746U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1602677179U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(19151121U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_dIPC_autoinheritance_info( int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[] )
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
        if (strcmp(aiChksum, "OtYd65R6LYgkiYyz2jnNnB") == 0) {
          extern mxArray *sf_c1_dIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c1_dIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "HdvsC8dOgiqL3YcerOwDt") == 0) {
          extern mxArray *sf_c2_dIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c2_dIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "1pmCPoNLGv6SESUuWS7WFF") == 0) {
          extern mxArray *sf_c3_dIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c3_dIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "X3KorS1qWDtfCqv7dwuoMB") == 0) {
          extern mxArray *sf_c5_dIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c5_dIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "Z8mAHuTnGf7zF0Va8oxzZG") == 0) {
          extern mxArray *sf_c6_dIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c6_dIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "1oJUcgcUIKhUxwRnIGnvQH") == 0) {
          extern mxArray *sf_c7_dIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c7_dIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "LWhmDXPo0xLTSwbSzLYEnF") == 0) {
          extern mxArray *sf_c8_dIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c8_dIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "LWhmDXPo0xLTSwbSzLYEnF") == 0) {
          extern mxArray *sf_c9_dIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c9_dIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "p2O1SaE1Hpnlwt2aYl0oZB") == 0) {
          extern mxArray *sf_c12_dIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c12_dIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "ijqtv2mNvl0Y6ThidN2s5C") == 0) {
          extern mxArray *sf_c13_dIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c13_dIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 17:
      {
        if (strcmp(aiChksum, "p2O1SaE1Hpnlwt2aYl0oZB") == 0) {
          extern mxArray *sf_c17_dIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c17_dIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 20:
      {
        if (strcmp(aiChksum, "DKRH3B7QmNi49nBUEhDB6B") == 0) {
          extern mxArray *sf_c20_dIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c20_dIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 21:
      {
        if (strcmp(aiChksum, "LZhiaMxS9IJg7wYHjXeTrD") == 0) {
          extern mxArray *sf_c21_dIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c21_dIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 30:
      {
        if (strcmp(aiChksum, "fONrs1U73NGtX6JxQXVWgB") == 0) {
          extern mxArray *sf_c30_dIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c30_dIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 31:
      {
        if (strcmp(aiChksum, "asyZ5s3s4TN5xDIuT1NnhC") == 0) {
          extern mxArray *sf_c31_dIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c31_dIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 36:
      {
        if (strcmp(aiChksum, "NclAjU358XfMasIaGBRAIE") == 0) {
          extern mxArray *sf_c36_dIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c36_dIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 37:
      {
        if (strcmp(aiChksum, "UHZaAEoMdoRDINBr92iwhG") == 0) {
          extern mxArray *sf_c37_dIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c37_dIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 43:
      {
        if (strcmp(aiChksum, "PX7bkxEV86Pni3SUF1aQMH") == 0) {
          extern mxArray *sf_c43_dIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c43_dIPC_get_autoinheritance_info();
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

unsigned int sf_dIPC_get_eml_resolved_functions_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
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
        extern const mxArray *sf_c1_dIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_dIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_dIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_dIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_dIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_dIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_dIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_dIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray *sf_c6_dIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_dIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray *sf_c7_dIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_dIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray *sf_c8_dIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_dIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray *sf_c9_dIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_dIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray *sf_c12_dIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_dIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray *sf_c13_dIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_dIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray *sf_c17_dIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_dIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 20:
      {
        extern const mxArray *sf_c20_dIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_dIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 21:
      {
        extern const mxArray *sf_c21_dIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c21_dIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 30:
      {
        extern const mxArray *sf_c30_dIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c30_dIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 31:
      {
        extern const mxArray *sf_c31_dIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c31_dIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 36:
      {
        extern const mxArray *sf_c36_dIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c36_dIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 37:
      {
        extern const mxArray *sf_c37_dIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c37_dIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 43:
      {
        extern const mxArray *sf_c43_dIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c43_dIPC_get_eml_resolved_functions_info();
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

unsigned int sf_dIPC_third_party_uses_info( int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[] )
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
        if (strcmp(tpChksum, "rbakr2UGMEFWaVRs09t4z") == 0) {
          extern mxArray *sf_c1_dIPC_third_party_uses_info(void);
          plhs[0] = sf_c1_dIPC_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "ymfZgNAqAy649UuAw11l7G") == 0) {
          extern mxArray *sf_c2_dIPC_third_party_uses_info(void);
          plhs[0] = sf_c2_dIPC_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "hC2vU5Voyv1xod92AC4KJC") == 0) {
          extern mxArray *sf_c3_dIPC_third_party_uses_info(void);
          plhs[0] = sf_c3_dIPC_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "V1EcXOhER1tAnz7i7AOPFD") == 0) {
          extern mxArray *sf_c5_dIPC_third_party_uses_info(void);
          plhs[0] = sf_c5_dIPC_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "SrOoGRh7InWyrJCxRUIUR") == 0) {
          extern mxArray *sf_c6_dIPC_third_party_uses_info(void);
          plhs[0] = sf_c6_dIPC_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "TKL2llps5o6zAZ1RJMPzTD") == 0) {
          extern mxArray *sf_c7_dIPC_third_party_uses_info(void);
          plhs[0] = sf_c7_dIPC_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c8_dIPC_third_party_uses_info(void);
          plhs[0] = sf_c8_dIPC_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c9_dIPC_third_party_uses_info(void);
          plhs[0] = sf_c9_dIPC_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "UzhGFBdHbOXpC0jz9AA65G") == 0) {
          extern mxArray *sf_c12_dIPC_third_party_uses_info(void);
          plhs[0] = sf_c12_dIPC_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "j952PgPqb5o1eVDTxUT2GD") == 0) {
          extern mxArray *sf_c13_dIPC_third_party_uses_info(void);
          plhs[0] = sf_c13_dIPC_third_party_uses_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "UzhGFBdHbOXpC0jz9AA65G") == 0) {
          extern mxArray *sf_c17_dIPC_third_party_uses_info(void);
          plhs[0] = sf_c17_dIPC_third_party_uses_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "fhybwQwSsVrhCKGPRmFotE") == 0) {
          extern mxArray *sf_c20_dIPC_third_party_uses_info(void);
          plhs[0] = sf_c20_dIPC_third_party_uses_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "pyIGamOjptGW80ll0iGLaC") == 0) {
          extern mxArray *sf_c21_dIPC_third_party_uses_info(void);
          plhs[0] = sf_c21_dIPC_third_party_uses_info();
          break;
        }
      }

     case 30:
      {
        if (strcmp(tpChksum, "DpUrirqwOxBzIZrXtRfa1F") == 0) {
          extern mxArray *sf_c30_dIPC_third_party_uses_info(void);
          plhs[0] = sf_c30_dIPC_third_party_uses_info();
          break;
        }
      }

     case 31:
      {
        if (strcmp(tpChksum, "EhY1h2kKw0COsfRhBPLiQD") == 0) {
          extern mxArray *sf_c31_dIPC_third_party_uses_info(void);
          plhs[0] = sf_c31_dIPC_third_party_uses_info();
          break;
        }
      }

     case 36:
      {
        if (strcmp(tpChksum, "0zwG4pQUZPlmlLKPpVhTOE") == 0) {
          extern mxArray *sf_c36_dIPC_third_party_uses_info(void);
          plhs[0] = sf_c36_dIPC_third_party_uses_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "pSNEEkjeAkWPSqP39MSdmC") == 0) {
          extern mxArray *sf_c37_dIPC_third_party_uses_info(void);
          plhs[0] = sf_c37_dIPC_third_party_uses_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "rwDDIRRJuizrd2lg0McQcG") == 0) {
          extern mxArray *sf_c43_dIPC_third_party_uses_info(void);
          plhs[0] = sf_c43_dIPC_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_dIPC_jit_fallback_info( int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[] )
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
        if (strcmp(tpChksum, "rbakr2UGMEFWaVRs09t4z") == 0) {
          extern mxArray *sf_c1_dIPC_jit_fallback_info(void);
          plhs[0] = sf_c1_dIPC_jit_fallback_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "ymfZgNAqAy649UuAw11l7G") == 0) {
          extern mxArray *sf_c2_dIPC_jit_fallback_info(void);
          plhs[0] = sf_c2_dIPC_jit_fallback_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "hC2vU5Voyv1xod92AC4KJC") == 0) {
          extern mxArray *sf_c3_dIPC_jit_fallback_info(void);
          plhs[0] = sf_c3_dIPC_jit_fallback_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "V1EcXOhER1tAnz7i7AOPFD") == 0) {
          extern mxArray *sf_c5_dIPC_jit_fallback_info(void);
          plhs[0] = sf_c5_dIPC_jit_fallback_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "SrOoGRh7InWyrJCxRUIUR") == 0) {
          extern mxArray *sf_c6_dIPC_jit_fallback_info(void);
          plhs[0] = sf_c6_dIPC_jit_fallback_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "TKL2llps5o6zAZ1RJMPzTD") == 0) {
          extern mxArray *sf_c7_dIPC_jit_fallback_info(void);
          plhs[0] = sf_c7_dIPC_jit_fallback_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c8_dIPC_jit_fallback_info(void);
          plhs[0] = sf_c8_dIPC_jit_fallback_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c9_dIPC_jit_fallback_info(void);
          plhs[0] = sf_c9_dIPC_jit_fallback_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "UzhGFBdHbOXpC0jz9AA65G") == 0) {
          extern mxArray *sf_c12_dIPC_jit_fallback_info(void);
          plhs[0] = sf_c12_dIPC_jit_fallback_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "j952PgPqb5o1eVDTxUT2GD") == 0) {
          extern mxArray *sf_c13_dIPC_jit_fallback_info(void);
          plhs[0] = sf_c13_dIPC_jit_fallback_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "UzhGFBdHbOXpC0jz9AA65G") == 0) {
          extern mxArray *sf_c17_dIPC_jit_fallback_info(void);
          plhs[0] = sf_c17_dIPC_jit_fallback_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "fhybwQwSsVrhCKGPRmFotE") == 0) {
          extern mxArray *sf_c20_dIPC_jit_fallback_info(void);
          plhs[0] = sf_c20_dIPC_jit_fallback_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "pyIGamOjptGW80ll0iGLaC") == 0) {
          extern mxArray *sf_c21_dIPC_jit_fallback_info(void);
          plhs[0] = sf_c21_dIPC_jit_fallback_info();
          break;
        }
      }

     case 30:
      {
        if (strcmp(tpChksum, "DpUrirqwOxBzIZrXtRfa1F") == 0) {
          extern mxArray *sf_c30_dIPC_jit_fallback_info(void);
          plhs[0] = sf_c30_dIPC_jit_fallback_info();
          break;
        }
      }

     case 31:
      {
        if (strcmp(tpChksum, "EhY1h2kKw0COsfRhBPLiQD") == 0) {
          extern mxArray *sf_c31_dIPC_jit_fallback_info(void);
          plhs[0] = sf_c31_dIPC_jit_fallback_info();
          break;
        }
      }

     case 36:
      {
        if (strcmp(tpChksum, "0zwG4pQUZPlmlLKPpVhTOE") == 0) {
          extern mxArray *sf_c36_dIPC_jit_fallback_info(void);
          plhs[0] = sf_c36_dIPC_jit_fallback_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "pSNEEkjeAkWPSqP39MSdmC") == 0) {
          extern mxArray *sf_c37_dIPC_jit_fallback_info(void);
          plhs[0] = sf_c37_dIPC_jit_fallback_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "rwDDIRRJuizrd2lg0McQcG") == 0) {
          extern mxArray *sf_c43_dIPC_jit_fallback_info(void);
          plhs[0] = sf_c43_dIPC_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_dIPC_updateBuildInfo_args_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
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
        if (strcmp(tpChksum, "rbakr2UGMEFWaVRs09t4z") == 0) {
          extern mxArray *sf_c1_dIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_dIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "ymfZgNAqAy649UuAw11l7G") == 0) {
          extern mxArray *sf_c2_dIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_dIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "hC2vU5Voyv1xod92AC4KJC") == 0) {
          extern mxArray *sf_c3_dIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_dIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "V1EcXOhER1tAnz7i7AOPFD") == 0) {
          extern mxArray *sf_c5_dIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_dIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "SrOoGRh7InWyrJCxRUIUR") == 0) {
          extern mxArray *sf_c6_dIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_dIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "TKL2llps5o6zAZ1RJMPzTD") == 0) {
          extern mxArray *sf_c7_dIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_dIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c8_dIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_dIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c9_dIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_dIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "UzhGFBdHbOXpC0jz9AA65G") == 0) {
          extern mxArray *sf_c12_dIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c12_dIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "j952PgPqb5o1eVDTxUT2GD") == 0) {
          extern mxArray *sf_c13_dIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c13_dIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "UzhGFBdHbOXpC0jz9AA65G") == 0) {
          extern mxArray *sf_c17_dIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c17_dIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "fhybwQwSsVrhCKGPRmFotE") == 0) {
          extern mxArray *sf_c20_dIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c20_dIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "pyIGamOjptGW80ll0iGLaC") == 0) {
          extern mxArray *sf_c21_dIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c21_dIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 30:
      {
        if (strcmp(tpChksum, "DpUrirqwOxBzIZrXtRfa1F") == 0) {
          extern mxArray *sf_c30_dIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c30_dIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 31:
      {
        if (strcmp(tpChksum, "EhY1h2kKw0COsfRhBPLiQD") == 0) {
          extern mxArray *sf_c31_dIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c31_dIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 36:
      {
        if (strcmp(tpChksum, "0zwG4pQUZPlmlLKPpVhTOE") == 0) {
          extern mxArray *sf_c36_dIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c36_dIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "pSNEEkjeAkWPSqP39MSdmC") == 0) {
          extern mxArray *sf_c37_dIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c37_dIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "rwDDIRRJuizrd2lg0McQcG") == 0) {
          extern mxArray *sf_c43_dIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c43_dIPC_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void sf_dIPC_get_post_codegen_info( int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[] )
{
  unsigned int chartFileNumber = (unsigned int) mxGetScalar(prhs[0]);
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  switch (chartFileNumber) {
   case 1:
    {
      if (strcmp(tpChksum, "rbakr2UGMEFWaVRs09t4z") == 0) {
        extern mxArray *sf_c1_dIPC_get_post_codegen_info(void);
        plhs[0] = sf_c1_dIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 2:
    {
      if (strcmp(tpChksum, "ymfZgNAqAy649UuAw11l7G") == 0) {
        extern mxArray *sf_c2_dIPC_get_post_codegen_info(void);
        plhs[0] = sf_c2_dIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 3:
    {
      if (strcmp(tpChksum, "hC2vU5Voyv1xod92AC4KJC") == 0) {
        extern mxArray *sf_c3_dIPC_get_post_codegen_info(void);
        plhs[0] = sf_c3_dIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 5:
    {
      if (strcmp(tpChksum, "V1EcXOhER1tAnz7i7AOPFD") == 0) {
        extern mxArray *sf_c5_dIPC_get_post_codegen_info(void);
        plhs[0] = sf_c5_dIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 6:
    {
      if (strcmp(tpChksum, "SrOoGRh7InWyrJCxRUIUR") == 0) {
        extern mxArray *sf_c6_dIPC_get_post_codegen_info(void);
        plhs[0] = sf_c6_dIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 7:
    {
      if (strcmp(tpChksum, "TKL2llps5o6zAZ1RJMPzTD") == 0) {
        extern mxArray *sf_c7_dIPC_get_post_codegen_info(void);
        plhs[0] = sf_c7_dIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 8:
    {
      if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
        extern mxArray *sf_c8_dIPC_get_post_codegen_info(void);
        plhs[0] = sf_c8_dIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 9:
    {
      if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
        extern mxArray *sf_c9_dIPC_get_post_codegen_info(void);
        plhs[0] = sf_c9_dIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 12:
    {
      if (strcmp(tpChksum, "UzhGFBdHbOXpC0jz9AA65G") == 0) {
        extern mxArray *sf_c12_dIPC_get_post_codegen_info(void);
        plhs[0] = sf_c12_dIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 13:
    {
      if (strcmp(tpChksum, "j952PgPqb5o1eVDTxUT2GD") == 0) {
        extern mxArray *sf_c13_dIPC_get_post_codegen_info(void);
        plhs[0] = sf_c13_dIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 17:
    {
      if (strcmp(tpChksum, "UzhGFBdHbOXpC0jz9AA65G") == 0) {
        extern mxArray *sf_c17_dIPC_get_post_codegen_info(void);
        plhs[0] = sf_c17_dIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 20:
    {
      if (strcmp(tpChksum, "fhybwQwSsVrhCKGPRmFotE") == 0) {
        extern mxArray *sf_c20_dIPC_get_post_codegen_info(void);
        plhs[0] = sf_c20_dIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 21:
    {
      if (strcmp(tpChksum, "pyIGamOjptGW80ll0iGLaC") == 0) {
        extern mxArray *sf_c21_dIPC_get_post_codegen_info(void);
        plhs[0] = sf_c21_dIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 30:
    {
      if (strcmp(tpChksum, "DpUrirqwOxBzIZrXtRfa1F") == 0) {
        extern mxArray *sf_c30_dIPC_get_post_codegen_info(void);
        plhs[0] = sf_c30_dIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 31:
    {
      if (strcmp(tpChksum, "EhY1h2kKw0COsfRhBPLiQD") == 0) {
        extern mxArray *sf_c31_dIPC_get_post_codegen_info(void);
        plhs[0] = sf_c31_dIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 36:
    {
      if (strcmp(tpChksum, "0zwG4pQUZPlmlLKPpVhTOE") == 0) {
        extern mxArray *sf_c36_dIPC_get_post_codegen_info(void);
        plhs[0] = sf_c36_dIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 37:
    {
      if (strcmp(tpChksum, "pSNEEkjeAkWPSqP39MSdmC") == 0) {
        extern mxArray *sf_c37_dIPC_get_post_codegen_info(void);
        plhs[0] = sf_c37_dIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 43:
    {
      if (strcmp(tpChksum, "rwDDIRRJuizrd2lg0McQcG") == 0) {
        extern mxArray *sf_c43_dIPC_get_post_codegen_info(void);
        plhs[0] = sf_c43_dIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   default:
    break;
  }

  plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
}

void dIPC_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _dIPCMachineNumber_ = sf_debug_initialize_machine(debugInstance,"dIPC","sfun",
    0,18,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,_dIPCMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,_dIPCMachineNumber_,0);
}

void dIPC_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_dIPC_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("dIPC", "dIPC");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_dIPC_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}

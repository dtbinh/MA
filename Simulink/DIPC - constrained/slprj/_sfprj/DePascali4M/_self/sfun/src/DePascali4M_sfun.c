/* Include files */

#include "DePascali4M_sfun.h"
#include "DePascali4M_sfun_debug_macros.h"
#include "c1_DePascali4M.h"
#include "c5_DePascali4M.h"
#include "c6_DePascali4M.h"
#include "c7_DePascali4M.h"
#include "c21_DePascali4M.h"
#include "c22_DePascali4M.h"
#include "c23_DePascali4M.h"
#include "c25_DePascali4M.h"
#include "c26_DePascali4M.h"
#include "c27_DePascali4M.h"
#include "c28_DePascali4M.h"
#include "c29_DePascali4M.h"
#include "c30_DePascali4M.h"
#include "c31_DePascali4M.h"
#include "c36_DePascali4M.h"
#include "c37_DePascali4M.h"
#include "c38_DePascali4M.h"
#include "c39_DePascali4M.h"
#include "c40_DePascali4M.h"
#include "c41_DePascali4M.h"
#include "c43_DePascali4M.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _DePascali4MMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void DePascali4M_initializer(void)
{
}

void DePascali4M_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_DePascali4M_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_DePascali4M_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_DePascali4M_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_DePascali4M_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_DePascali4M_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==21) {
    c21_DePascali4M_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==22) {
    c22_DePascali4M_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==23) {
    c23_DePascali4M_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==25) {
    c25_DePascali4M_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==26) {
    c26_DePascali4M_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==27) {
    c27_DePascali4M_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==28) {
    c28_DePascali4M_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==29) {
    c29_DePascali4M_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==30) {
    c30_DePascali4M_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==31) {
    c31_DePascali4M_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==36) {
    c36_DePascali4M_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==37) {
    c37_DePascali4M_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==38) {
    c38_DePascali4M_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==39) {
    c39_DePascali4M_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==40) {
    c40_DePascali4M_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==41) {
    c41_DePascali4M_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==43) {
    c43_DePascali4M_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

extern void sf_DePascali4M_uses_exported_functions(int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[])
{
  plhs[0] = mxCreateLogicalScalar(0);
}

unsigned int sf_DePascali4M_process_check_sum_call( int nlhs, mxArray * plhs[],
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3880815088U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2454153721U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2784112633U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(520466806U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2216444870U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(201538812U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3530967261U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2677428111U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_DePascali4M_get_check_sum(mxArray *plhs[]);
          sf_c1_DePascali4M_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_DePascali4M_get_check_sum(mxArray *plhs[]);
          sf_c5_DePascali4M_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_DePascali4M_get_check_sum(mxArray *plhs[]);
          sf_c6_DePascali4M_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_DePascali4M_get_check_sum(mxArray *plhs[]);
          sf_c7_DePascali4M_get_check_sum(plhs);
          break;
        }

       case 21:
        {
          extern void sf_c21_DePascali4M_get_check_sum(mxArray *plhs[]);
          sf_c21_DePascali4M_get_check_sum(plhs);
          break;
        }

       case 22:
        {
          extern void sf_c22_DePascali4M_get_check_sum(mxArray *plhs[]);
          sf_c22_DePascali4M_get_check_sum(plhs);
          break;
        }

       case 23:
        {
          extern void sf_c23_DePascali4M_get_check_sum(mxArray *plhs[]);
          sf_c23_DePascali4M_get_check_sum(plhs);
          break;
        }

       case 25:
        {
          extern void sf_c25_DePascali4M_get_check_sum(mxArray *plhs[]);
          sf_c25_DePascali4M_get_check_sum(plhs);
          break;
        }

       case 26:
        {
          extern void sf_c26_DePascali4M_get_check_sum(mxArray *plhs[]);
          sf_c26_DePascali4M_get_check_sum(plhs);
          break;
        }

       case 27:
        {
          extern void sf_c27_DePascali4M_get_check_sum(mxArray *plhs[]);
          sf_c27_DePascali4M_get_check_sum(plhs);
          break;
        }

       case 28:
        {
          extern void sf_c28_DePascali4M_get_check_sum(mxArray *plhs[]);
          sf_c28_DePascali4M_get_check_sum(plhs);
          break;
        }

       case 29:
        {
          extern void sf_c29_DePascali4M_get_check_sum(mxArray *plhs[]);
          sf_c29_DePascali4M_get_check_sum(plhs);
          break;
        }

       case 30:
        {
          extern void sf_c30_DePascali4M_get_check_sum(mxArray *plhs[]);
          sf_c30_DePascali4M_get_check_sum(plhs);
          break;
        }

       case 31:
        {
          extern void sf_c31_DePascali4M_get_check_sum(mxArray *plhs[]);
          sf_c31_DePascali4M_get_check_sum(plhs);
          break;
        }

       case 36:
        {
          extern void sf_c36_DePascali4M_get_check_sum(mxArray *plhs[]);
          sf_c36_DePascali4M_get_check_sum(plhs);
          break;
        }

       case 37:
        {
          extern void sf_c37_DePascali4M_get_check_sum(mxArray *plhs[]);
          sf_c37_DePascali4M_get_check_sum(plhs);
          break;
        }

       case 38:
        {
          extern void sf_c38_DePascali4M_get_check_sum(mxArray *plhs[]);
          sf_c38_DePascali4M_get_check_sum(plhs);
          break;
        }

       case 39:
        {
          extern void sf_c39_DePascali4M_get_check_sum(mxArray *plhs[]);
          sf_c39_DePascali4M_get_check_sum(plhs);
          break;
        }

       case 40:
        {
          extern void sf_c40_DePascali4M_get_check_sum(mxArray *plhs[]);
          sf_c40_DePascali4M_get_check_sum(plhs);
          break;
        }

       case 41:
        {
          extern void sf_c41_DePascali4M_get_check_sum(mxArray *plhs[]);
          sf_c41_DePascali4M_get_check_sum(plhs);
          break;
        }

       case 43:
        {
          extern void sf_c43_DePascali4M_get_check_sum(mxArray *plhs[]);
          sf_c43_DePascali4M_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3658815968U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(949786967U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3528826244U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(794631169U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_DePascali4M_autoinheritance_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(aiChksum, "a9eZw9WaZcxJ1wV8vE3r6F") == 0) {
          extern mxArray *sf_c1_DePascali4M_get_autoinheritance_info(void);
          plhs[0] = sf_c1_DePascali4M_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "tna1BcwMvoe2fRwT2pfL9E") == 0) {
          extern mxArray *sf_c5_DePascali4M_get_autoinheritance_info(void);
          plhs[0] = sf_c5_DePascali4M_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "MNIWBbuNFTZjpPbKWaFHcH") == 0) {
          extern mxArray *sf_c6_DePascali4M_get_autoinheritance_info(void);
          plhs[0] = sf_c6_DePascali4M_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "tYATzzCrS6feeZiFtybCl") == 0) {
          extern mxArray *sf_c7_DePascali4M_get_autoinheritance_info(void);
          plhs[0] = sf_c7_DePascali4M_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 21:
      {
        if (strcmp(aiChksum, "DD1R3ViA8FSKbVm79jLUZ") == 0) {
          extern mxArray *sf_c21_DePascali4M_get_autoinheritance_info(void);
          plhs[0] = sf_c21_DePascali4M_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 22:
      {
        if (strcmp(aiChksum, "j9maIqGCXDgdd4rsMwtlXF") == 0) {
          extern mxArray *sf_c22_DePascali4M_get_autoinheritance_info(void);
          plhs[0] = sf_c22_DePascali4M_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 23:
      {
        if (strcmp(aiChksum, "GlfztGmXSk9HxHD4f6bw8") == 0) {
          extern mxArray *sf_c23_DePascali4M_get_autoinheritance_info(void);
          plhs[0] = sf_c23_DePascali4M_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 25:
      {
        if (strcmp(aiChksum, "DD1R3ViA8FSKbVm79jLUZ") == 0) {
          extern mxArray *sf_c25_DePascali4M_get_autoinheritance_info(void);
          plhs[0] = sf_c25_DePascali4M_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 26:
      {
        if (strcmp(aiChksum, "PZUjTVaGjUj6LwtPaOJE7D") == 0) {
          extern mxArray *sf_c26_DePascali4M_get_autoinheritance_info(void);
          plhs[0] = sf_c26_DePascali4M_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 27:
      {
        if (strcmp(aiChksum, "QFSGo4CAULCs4RwVEn83bD") == 0) {
          extern mxArray *sf_c27_DePascali4M_get_autoinheritance_info(void);
          plhs[0] = sf_c27_DePascali4M_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 28:
      {
        if (strcmp(aiChksum, "sLHGNKXSj83cDKtOezOigD") == 0) {
          extern mxArray *sf_c28_DePascali4M_get_autoinheritance_info(void);
          plhs[0] = sf_c28_DePascali4M_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 29:
      {
        if (strcmp(aiChksum, "Ks9ao3qCZLidlXCFBRsQjF") == 0) {
          extern mxArray *sf_c29_DePascali4M_get_autoinheritance_info(void);
          plhs[0] = sf_c29_DePascali4M_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 30:
      {
        if (strcmp(aiChksum, "2DzyioPLwtmX08rJePnILC") == 0) {
          extern mxArray *sf_c30_DePascali4M_get_autoinheritance_info(void);
          plhs[0] = sf_c30_DePascali4M_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 31:
      {
        if (strcmp(aiChksum, "L4cHfneDxO6L1Btml4R76") == 0) {
          extern mxArray *sf_c31_DePascali4M_get_autoinheritance_info(void);
          plhs[0] = sf_c31_DePascali4M_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 36:
      {
        if (strcmp(aiChksum, "DD1R3ViA8FSKbVm79jLUZ") == 0) {
          extern mxArray *sf_c36_DePascali4M_get_autoinheritance_info(void);
          plhs[0] = sf_c36_DePascali4M_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 37:
      {
        if (strcmp(aiChksum, "HH5Q7NBdD7VBwfWldwVT5F") == 0) {
          extern mxArray *sf_c37_DePascali4M_get_autoinheritance_info(void);
          plhs[0] = sf_c37_DePascali4M_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 38:
      {
        if (strcmp(aiChksum, "2DzyioPLwtmX08rJePnILC") == 0) {
          extern mxArray *sf_c38_DePascali4M_get_autoinheritance_info(void);
          plhs[0] = sf_c38_DePascali4M_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 39:
      {
        if (strcmp(aiChksum, "Dn40gMbbdn1iNeu4BDMiFH") == 0) {
          extern mxArray *sf_c39_DePascali4M_get_autoinheritance_info(void);
          plhs[0] = sf_c39_DePascali4M_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 40:
      {
        if (strcmp(aiChksum, "2DzyioPLwtmX08rJePnILC") == 0) {
          extern mxArray *sf_c40_DePascali4M_get_autoinheritance_info(void);
          plhs[0] = sf_c40_DePascali4M_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 41:
      {
        if (strcmp(aiChksum, "ohjSsRrin3v7xGDfF8zJEB") == 0) {
          extern mxArray *sf_c41_DePascali4M_get_autoinheritance_info(void);
          plhs[0] = sf_c41_DePascali4M_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 43:
      {
        if (strcmp(aiChksum, "aBAN3OqxekCRqIEyfPDBXC") == 0) {
          extern mxArray *sf_c43_DePascali4M_get_autoinheritance_info(void);
          plhs[0] = sf_c43_DePascali4M_get_autoinheritance_info();
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

unsigned int sf_DePascali4M_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
        extern const mxArray *sf_c1_DePascali4M_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_DePascali4M_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_DePascali4M_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_DePascali4M_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray *sf_c6_DePascali4M_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_DePascali4M_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray *sf_c7_DePascali4M_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_DePascali4M_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 21:
      {
        extern const mxArray *sf_c21_DePascali4M_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c21_DePascali4M_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 22:
      {
        extern const mxArray *sf_c22_DePascali4M_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c22_DePascali4M_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 23:
      {
        extern const mxArray *sf_c23_DePascali4M_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c23_DePascali4M_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 25:
      {
        extern const mxArray *sf_c25_DePascali4M_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c25_DePascali4M_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 26:
      {
        extern const mxArray *sf_c26_DePascali4M_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c26_DePascali4M_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 27:
      {
        extern const mxArray *sf_c27_DePascali4M_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c27_DePascali4M_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 28:
      {
        extern const mxArray *sf_c28_DePascali4M_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c28_DePascali4M_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 29:
      {
        extern const mxArray *sf_c29_DePascali4M_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c29_DePascali4M_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 30:
      {
        extern const mxArray *sf_c30_DePascali4M_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c30_DePascali4M_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 31:
      {
        extern const mxArray *sf_c31_DePascali4M_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c31_DePascali4M_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 36:
      {
        extern const mxArray *sf_c36_DePascali4M_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c36_DePascali4M_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 37:
      {
        extern const mxArray *sf_c37_DePascali4M_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c37_DePascali4M_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 38:
      {
        extern const mxArray *sf_c38_DePascali4M_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c38_DePascali4M_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 39:
      {
        extern const mxArray *sf_c39_DePascali4M_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c39_DePascali4M_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 40:
      {
        extern const mxArray *sf_c40_DePascali4M_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c40_DePascali4M_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 41:
      {
        extern const mxArray *sf_c41_DePascali4M_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c41_DePascali4M_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 43:
      {
        extern const mxArray *sf_c43_DePascali4M_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c43_DePascali4M_get_eml_resolved_functions_info();
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

unsigned int sf_DePascali4M_third_party_uses_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(tpChksum, "nhzpxLEEBZdUjFWNKEZizD") == 0) {
          extern mxArray *sf_c1_DePascali4M_third_party_uses_info(void);
          plhs[0] = sf_c1_DePascali4M_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "wKjgDzYGh0AKSV9oCDZhuB") == 0) {
          extern mxArray *sf_c5_DePascali4M_third_party_uses_info(void);
          plhs[0] = sf_c5_DePascali4M_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "vEneZyO80AXkO3fgcTZVhD") == 0) {
          extern mxArray *sf_c6_DePascali4M_third_party_uses_info(void);
          plhs[0] = sf_c6_DePascali4M_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "TMlGanmzJMEGBnqyVVJ86E") == 0) {
          extern mxArray *sf_c7_DePascali4M_third_party_uses_info(void);
          plhs[0] = sf_c7_DePascali4M_third_party_uses_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "R5fJ5cX5KyORqPmZdJfjYC") == 0) {
          extern mxArray *sf_c21_DePascali4M_third_party_uses_info(void);
          plhs[0] = sf_c21_DePascali4M_third_party_uses_info();
          break;
        }
      }

     case 22:
      {
        if (strcmp(tpChksum, "DpTkc1bOHKC86DQmcFu5WB") == 0) {
          extern mxArray *sf_c22_DePascali4M_third_party_uses_info(void);
          plhs[0] = sf_c22_DePascali4M_third_party_uses_info();
          break;
        }
      }

     case 23:
      {
        if (strcmp(tpChksum, "CDeSXRTFuIUIKFya1XyhUB") == 0) {
          extern mxArray *sf_c23_DePascali4M_third_party_uses_info(void);
          plhs[0] = sf_c23_DePascali4M_third_party_uses_info();
          break;
        }
      }

     case 25:
      {
        if (strcmp(tpChksum, "R5fJ5cX5KyORqPmZdJfjYC") == 0) {
          extern mxArray *sf_c25_DePascali4M_third_party_uses_info(void);
          plhs[0] = sf_c25_DePascali4M_third_party_uses_info();
          break;
        }
      }

     case 26:
      {
        if (strcmp(tpChksum, "4pxzcfVpVz6mRboTpKMvmB") == 0) {
          extern mxArray *sf_c26_DePascali4M_third_party_uses_info(void);
          plhs[0] = sf_c26_DePascali4M_third_party_uses_info();
          break;
        }
      }

     case 27:
      {
        if (strcmp(tpChksum, "LN2iW8M8wmvPzLYPfigRzC") == 0) {
          extern mxArray *sf_c27_DePascali4M_third_party_uses_info(void);
          plhs[0] = sf_c27_DePascali4M_third_party_uses_info();
          break;
        }
      }

     case 28:
      {
        if (strcmp(tpChksum, "kcdYQPfxjOTPB1CZTYjNeH") == 0) {
          extern mxArray *sf_c28_DePascali4M_third_party_uses_info(void);
          plhs[0] = sf_c28_DePascali4M_third_party_uses_info();
          break;
        }
      }

     case 29:
      {
        if (strcmp(tpChksum, "q11Ba5KCd8L9zyVYwVd0zB") == 0) {
          extern mxArray *sf_c29_DePascali4M_third_party_uses_info(void);
          plhs[0] = sf_c29_DePascali4M_third_party_uses_info();
          break;
        }
      }

     case 30:
      {
        if (strcmp(tpChksum, "KoBjyPLZLMM3KD77IWLpFB") == 0) {
          extern mxArray *sf_c30_DePascali4M_third_party_uses_info(void);
          plhs[0] = sf_c30_DePascali4M_third_party_uses_info();
          break;
        }
      }

     case 31:
      {
        if (strcmp(tpChksum, "WuMhkbnscSKHTcaYGq7t0C") == 0) {
          extern mxArray *sf_c31_DePascali4M_third_party_uses_info(void);
          plhs[0] = sf_c31_DePascali4M_third_party_uses_info();
          break;
        }
      }

     case 36:
      {
        if (strcmp(tpChksum, "R5fJ5cX5KyORqPmZdJfjYC") == 0) {
          extern mxArray *sf_c36_DePascali4M_third_party_uses_info(void);
          plhs[0] = sf_c36_DePascali4M_third_party_uses_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "1i3LZAfIaHjMJtsqqRFjjF") == 0) {
          extern mxArray *sf_c37_DePascali4M_third_party_uses_info(void);
          plhs[0] = sf_c37_DePascali4M_third_party_uses_info();
          break;
        }
      }

     case 38:
      {
        if (strcmp(tpChksum, "KoBjyPLZLMM3KD77IWLpFB") == 0) {
          extern mxArray *sf_c38_DePascali4M_third_party_uses_info(void);
          plhs[0] = sf_c38_DePascali4M_third_party_uses_info();
          break;
        }
      }

     case 39:
      {
        if (strcmp(tpChksum, "uSoQvWIR50U87qasuuatqH") == 0) {
          extern mxArray *sf_c39_DePascali4M_third_party_uses_info(void);
          plhs[0] = sf_c39_DePascali4M_third_party_uses_info();
          break;
        }
      }

     case 40:
      {
        if (strcmp(tpChksum, "KoBjyPLZLMM3KD77IWLpFB") == 0) {
          extern mxArray *sf_c40_DePascali4M_third_party_uses_info(void);
          plhs[0] = sf_c40_DePascali4M_third_party_uses_info();
          break;
        }
      }

     case 41:
      {
        if (strcmp(tpChksum, "n3HQL5BUZGjOWC5ir8NIcH") == 0) {
          extern mxArray *sf_c41_DePascali4M_third_party_uses_info(void);
          plhs[0] = sf_c41_DePascali4M_third_party_uses_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "IgmYsTd7hWQzxdq1sf59GB") == 0) {
          extern mxArray *sf_c43_DePascali4M_third_party_uses_info(void);
          plhs[0] = sf_c43_DePascali4M_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_DePascali4M_jit_fallback_info( int nlhs, mxArray * plhs[], int
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
        if (strcmp(tpChksum, "nhzpxLEEBZdUjFWNKEZizD") == 0) {
          extern mxArray *sf_c1_DePascali4M_jit_fallback_info(void);
          plhs[0] = sf_c1_DePascali4M_jit_fallback_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "wKjgDzYGh0AKSV9oCDZhuB") == 0) {
          extern mxArray *sf_c5_DePascali4M_jit_fallback_info(void);
          plhs[0] = sf_c5_DePascali4M_jit_fallback_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "vEneZyO80AXkO3fgcTZVhD") == 0) {
          extern mxArray *sf_c6_DePascali4M_jit_fallback_info(void);
          plhs[0] = sf_c6_DePascali4M_jit_fallback_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "TMlGanmzJMEGBnqyVVJ86E") == 0) {
          extern mxArray *sf_c7_DePascali4M_jit_fallback_info(void);
          plhs[0] = sf_c7_DePascali4M_jit_fallback_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "R5fJ5cX5KyORqPmZdJfjYC") == 0) {
          extern mxArray *sf_c21_DePascali4M_jit_fallback_info(void);
          plhs[0] = sf_c21_DePascali4M_jit_fallback_info();
          break;
        }
      }

     case 22:
      {
        if (strcmp(tpChksum, "DpTkc1bOHKC86DQmcFu5WB") == 0) {
          extern mxArray *sf_c22_DePascali4M_jit_fallback_info(void);
          plhs[0] = sf_c22_DePascali4M_jit_fallback_info();
          break;
        }
      }

     case 23:
      {
        if (strcmp(tpChksum, "CDeSXRTFuIUIKFya1XyhUB") == 0) {
          extern mxArray *sf_c23_DePascali4M_jit_fallback_info(void);
          plhs[0] = sf_c23_DePascali4M_jit_fallback_info();
          break;
        }
      }

     case 25:
      {
        if (strcmp(tpChksum, "R5fJ5cX5KyORqPmZdJfjYC") == 0) {
          extern mxArray *sf_c25_DePascali4M_jit_fallback_info(void);
          plhs[0] = sf_c25_DePascali4M_jit_fallback_info();
          break;
        }
      }

     case 26:
      {
        if (strcmp(tpChksum, "4pxzcfVpVz6mRboTpKMvmB") == 0) {
          extern mxArray *sf_c26_DePascali4M_jit_fallback_info(void);
          plhs[0] = sf_c26_DePascali4M_jit_fallback_info();
          break;
        }
      }

     case 27:
      {
        if (strcmp(tpChksum, "LN2iW8M8wmvPzLYPfigRzC") == 0) {
          extern mxArray *sf_c27_DePascali4M_jit_fallback_info(void);
          plhs[0] = sf_c27_DePascali4M_jit_fallback_info();
          break;
        }
      }

     case 28:
      {
        if (strcmp(tpChksum, "kcdYQPfxjOTPB1CZTYjNeH") == 0) {
          extern mxArray *sf_c28_DePascali4M_jit_fallback_info(void);
          plhs[0] = sf_c28_DePascali4M_jit_fallback_info();
          break;
        }
      }

     case 29:
      {
        if (strcmp(tpChksum, "q11Ba5KCd8L9zyVYwVd0zB") == 0) {
          extern mxArray *sf_c29_DePascali4M_jit_fallback_info(void);
          plhs[0] = sf_c29_DePascali4M_jit_fallback_info();
          break;
        }
      }

     case 30:
      {
        if (strcmp(tpChksum, "KoBjyPLZLMM3KD77IWLpFB") == 0) {
          extern mxArray *sf_c30_DePascali4M_jit_fallback_info(void);
          plhs[0] = sf_c30_DePascali4M_jit_fallback_info();
          break;
        }
      }

     case 31:
      {
        if (strcmp(tpChksum, "WuMhkbnscSKHTcaYGq7t0C") == 0) {
          extern mxArray *sf_c31_DePascali4M_jit_fallback_info(void);
          plhs[0] = sf_c31_DePascali4M_jit_fallback_info();
          break;
        }
      }

     case 36:
      {
        if (strcmp(tpChksum, "R5fJ5cX5KyORqPmZdJfjYC") == 0) {
          extern mxArray *sf_c36_DePascali4M_jit_fallback_info(void);
          plhs[0] = sf_c36_DePascali4M_jit_fallback_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "1i3LZAfIaHjMJtsqqRFjjF") == 0) {
          extern mxArray *sf_c37_DePascali4M_jit_fallback_info(void);
          plhs[0] = sf_c37_DePascali4M_jit_fallback_info();
          break;
        }
      }

     case 38:
      {
        if (strcmp(tpChksum, "KoBjyPLZLMM3KD77IWLpFB") == 0) {
          extern mxArray *sf_c38_DePascali4M_jit_fallback_info(void);
          plhs[0] = sf_c38_DePascali4M_jit_fallback_info();
          break;
        }
      }

     case 39:
      {
        if (strcmp(tpChksum, "uSoQvWIR50U87qasuuatqH") == 0) {
          extern mxArray *sf_c39_DePascali4M_jit_fallback_info(void);
          plhs[0] = sf_c39_DePascali4M_jit_fallback_info();
          break;
        }
      }

     case 40:
      {
        if (strcmp(tpChksum, "KoBjyPLZLMM3KD77IWLpFB") == 0) {
          extern mxArray *sf_c40_DePascali4M_jit_fallback_info(void);
          plhs[0] = sf_c40_DePascali4M_jit_fallback_info();
          break;
        }
      }

     case 41:
      {
        if (strcmp(tpChksum, "n3HQL5BUZGjOWC5ir8NIcH") == 0) {
          extern mxArray *sf_c41_DePascali4M_jit_fallback_info(void);
          plhs[0] = sf_c41_DePascali4M_jit_fallback_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "IgmYsTd7hWQzxdq1sf59GB") == 0) {
          extern mxArray *sf_c43_DePascali4M_jit_fallback_info(void);
          plhs[0] = sf_c43_DePascali4M_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_DePascali4M_updateBuildInfo_args_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
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
        if (strcmp(tpChksum, "nhzpxLEEBZdUjFWNKEZizD") == 0) {
          extern mxArray *sf_c1_DePascali4M_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_DePascali4M_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "wKjgDzYGh0AKSV9oCDZhuB") == 0) {
          extern mxArray *sf_c5_DePascali4M_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_DePascali4M_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "vEneZyO80AXkO3fgcTZVhD") == 0) {
          extern mxArray *sf_c6_DePascali4M_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_DePascali4M_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "TMlGanmzJMEGBnqyVVJ86E") == 0) {
          extern mxArray *sf_c7_DePascali4M_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_DePascali4M_updateBuildInfo_args_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "R5fJ5cX5KyORqPmZdJfjYC") == 0) {
          extern mxArray *sf_c21_DePascali4M_updateBuildInfo_args_info(void);
          plhs[0] = sf_c21_DePascali4M_updateBuildInfo_args_info();
          break;
        }
      }

     case 22:
      {
        if (strcmp(tpChksum, "DpTkc1bOHKC86DQmcFu5WB") == 0) {
          extern mxArray *sf_c22_DePascali4M_updateBuildInfo_args_info(void);
          plhs[0] = sf_c22_DePascali4M_updateBuildInfo_args_info();
          break;
        }
      }

     case 23:
      {
        if (strcmp(tpChksum, "CDeSXRTFuIUIKFya1XyhUB") == 0) {
          extern mxArray *sf_c23_DePascali4M_updateBuildInfo_args_info(void);
          plhs[0] = sf_c23_DePascali4M_updateBuildInfo_args_info();
          break;
        }
      }

     case 25:
      {
        if (strcmp(tpChksum, "R5fJ5cX5KyORqPmZdJfjYC") == 0) {
          extern mxArray *sf_c25_DePascali4M_updateBuildInfo_args_info(void);
          plhs[0] = sf_c25_DePascali4M_updateBuildInfo_args_info();
          break;
        }
      }

     case 26:
      {
        if (strcmp(tpChksum, "4pxzcfVpVz6mRboTpKMvmB") == 0) {
          extern mxArray *sf_c26_DePascali4M_updateBuildInfo_args_info(void);
          plhs[0] = sf_c26_DePascali4M_updateBuildInfo_args_info();
          break;
        }
      }

     case 27:
      {
        if (strcmp(tpChksum, "LN2iW8M8wmvPzLYPfigRzC") == 0) {
          extern mxArray *sf_c27_DePascali4M_updateBuildInfo_args_info(void);
          plhs[0] = sf_c27_DePascali4M_updateBuildInfo_args_info();
          break;
        }
      }

     case 28:
      {
        if (strcmp(tpChksum, "kcdYQPfxjOTPB1CZTYjNeH") == 0) {
          extern mxArray *sf_c28_DePascali4M_updateBuildInfo_args_info(void);
          plhs[0] = sf_c28_DePascali4M_updateBuildInfo_args_info();
          break;
        }
      }

     case 29:
      {
        if (strcmp(tpChksum, "q11Ba5KCd8L9zyVYwVd0zB") == 0) {
          extern mxArray *sf_c29_DePascali4M_updateBuildInfo_args_info(void);
          plhs[0] = sf_c29_DePascali4M_updateBuildInfo_args_info();
          break;
        }
      }

     case 30:
      {
        if (strcmp(tpChksum, "KoBjyPLZLMM3KD77IWLpFB") == 0) {
          extern mxArray *sf_c30_DePascali4M_updateBuildInfo_args_info(void);
          plhs[0] = sf_c30_DePascali4M_updateBuildInfo_args_info();
          break;
        }
      }

     case 31:
      {
        if (strcmp(tpChksum, "WuMhkbnscSKHTcaYGq7t0C") == 0) {
          extern mxArray *sf_c31_DePascali4M_updateBuildInfo_args_info(void);
          plhs[0] = sf_c31_DePascali4M_updateBuildInfo_args_info();
          break;
        }
      }

     case 36:
      {
        if (strcmp(tpChksum, "R5fJ5cX5KyORqPmZdJfjYC") == 0) {
          extern mxArray *sf_c36_DePascali4M_updateBuildInfo_args_info(void);
          plhs[0] = sf_c36_DePascali4M_updateBuildInfo_args_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "1i3LZAfIaHjMJtsqqRFjjF") == 0) {
          extern mxArray *sf_c37_DePascali4M_updateBuildInfo_args_info(void);
          plhs[0] = sf_c37_DePascali4M_updateBuildInfo_args_info();
          break;
        }
      }

     case 38:
      {
        if (strcmp(tpChksum, "KoBjyPLZLMM3KD77IWLpFB") == 0) {
          extern mxArray *sf_c38_DePascali4M_updateBuildInfo_args_info(void);
          plhs[0] = sf_c38_DePascali4M_updateBuildInfo_args_info();
          break;
        }
      }

     case 39:
      {
        if (strcmp(tpChksum, "uSoQvWIR50U87qasuuatqH") == 0) {
          extern mxArray *sf_c39_DePascali4M_updateBuildInfo_args_info(void);
          plhs[0] = sf_c39_DePascali4M_updateBuildInfo_args_info();
          break;
        }
      }

     case 40:
      {
        if (strcmp(tpChksum, "KoBjyPLZLMM3KD77IWLpFB") == 0) {
          extern mxArray *sf_c40_DePascali4M_updateBuildInfo_args_info(void);
          plhs[0] = sf_c40_DePascali4M_updateBuildInfo_args_info();
          break;
        }
      }

     case 41:
      {
        if (strcmp(tpChksum, "n3HQL5BUZGjOWC5ir8NIcH") == 0) {
          extern mxArray *sf_c41_DePascali4M_updateBuildInfo_args_info(void);
          plhs[0] = sf_c41_DePascali4M_updateBuildInfo_args_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "IgmYsTd7hWQzxdq1sf59GB") == 0) {
          extern mxArray *sf_c43_DePascali4M_updateBuildInfo_args_info(void);
          plhs[0] = sf_c43_DePascali4M_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void sf_DePascali4M_get_post_codegen_info( int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[] )
{
  unsigned int chartFileNumber = (unsigned int) mxGetScalar(prhs[0]);
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  switch (chartFileNumber) {
   case 1:
    {
      if (strcmp(tpChksum, "nhzpxLEEBZdUjFWNKEZizD") == 0) {
        extern mxArray *sf_c1_DePascali4M_get_post_codegen_info(void);
        plhs[0] = sf_c1_DePascali4M_get_post_codegen_info();
        return;
      }
    }
    break;

   case 5:
    {
      if (strcmp(tpChksum, "wKjgDzYGh0AKSV9oCDZhuB") == 0) {
        extern mxArray *sf_c5_DePascali4M_get_post_codegen_info(void);
        plhs[0] = sf_c5_DePascali4M_get_post_codegen_info();
        return;
      }
    }
    break;

   case 6:
    {
      if (strcmp(tpChksum, "vEneZyO80AXkO3fgcTZVhD") == 0) {
        extern mxArray *sf_c6_DePascali4M_get_post_codegen_info(void);
        plhs[0] = sf_c6_DePascali4M_get_post_codegen_info();
        return;
      }
    }
    break;

   case 7:
    {
      if (strcmp(tpChksum, "TMlGanmzJMEGBnqyVVJ86E") == 0) {
        extern mxArray *sf_c7_DePascali4M_get_post_codegen_info(void);
        plhs[0] = sf_c7_DePascali4M_get_post_codegen_info();
        return;
      }
    }
    break;

   case 21:
    {
      if (strcmp(tpChksum, "R5fJ5cX5KyORqPmZdJfjYC") == 0) {
        extern mxArray *sf_c21_DePascali4M_get_post_codegen_info(void);
        plhs[0] = sf_c21_DePascali4M_get_post_codegen_info();
        return;
      }
    }
    break;

   case 22:
    {
      if (strcmp(tpChksum, "DpTkc1bOHKC86DQmcFu5WB") == 0) {
        extern mxArray *sf_c22_DePascali4M_get_post_codegen_info(void);
        plhs[0] = sf_c22_DePascali4M_get_post_codegen_info();
        return;
      }
    }
    break;

   case 23:
    {
      if (strcmp(tpChksum, "CDeSXRTFuIUIKFya1XyhUB") == 0) {
        extern mxArray *sf_c23_DePascali4M_get_post_codegen_info(void);
        plhs[0] = sf_c23_DePascali4M_get_post_codegen_info();
        return;
      }
    }
    break;

   case 25:
    {
      if (strcmp(tpChksum, "R5fJ5cX5KyORqPmZdJfjYC") == 0) {
        extern mxArray *sf_c25_DePascali4M_get_post_codegen_info(void);
        plhs[0] = sf_c25_DePascali4M_get_post_codegen_info();
        return;
      }
    }
    break;

   case 26:
    {
      if (strcmp(tpChksum, "4pxzcfVpVz6mRboTpKMvmB") == 0) {
        extern mxArray *sf_c26_DePascali4M_get_post_codegen_info(void);
        plhs[0] = sf_c26_DePascali4M_get_post_codegen_info();
        return;
      }
    }
    break;

   case 27:
    {
      if (strcmp(tpChksum, "LN2iW8M8wmvPzLYPfigRzC") == 0) {
        extern mxArray *sf_c27_DePascali4M_get_post_codegen_info(void);
        plhs[0] = sf_c27_DePascali4M_get_post_codegen_info();
        return;
      }
    }
    break;

   case 28:
    {
      if (strcmp(tpChksum, "kcdYQPfxjOTPB1CZTYjNeH") == 0) {
        extern mxArray *sf_c28_DePascali4M_get_post_codegen_info(void);
        plhs[0] = sf_c28_DePascali4M_get_post_codegen_info();
        return;
      }
    }
    break;

   case 29:
    {
      if (strcmp(tpChksum, "q11Ba5KCd8L9zyVYwVd0zB") == 0) {
        extern mxArray *sf_c29_DePascali4M_get_post_codegen_info(void);
        plhs[0] = sf_c29_DePascali4M_get_post_codegen_info();
        return;
      }
    }
    break;

   case 30:
    {
      if (strcmp(tpChksum, "KoBjyPLZLMM3KD77IWLpFB") == 0) {
        extern mxArray *sf_c30_DePascali4M_get_post_codegen_info(void);
        plhs[0] = sf_c30_DePascali4M_get_post_codegen_info();
        return;
      }
    }
    break;

   case 31:
    {
      if (strcmp(tpChksum, "WuMhkbnscSKHTcaYGq7t0C") == 0) {
        extern mxArray *sf_c31_DePascali4M_get_post_codegen_info(void);
        plhs[0] = sf_c31_DePascali4M_get_post_codegen_info();
        return;
      }
    }
    break;

   case 36:
    {
      if (strcmp(tpChksum, "R5fJ5cX5KyORqPmZdJfjYC") == 0) {
        extern mxArray *sf_c36_DePascali4M_get_post_codegen_info(void);
        plhs[0] = sf_c36_DePascali4M_get_post_codegen_info();
        return;
      }
    }
    break;

   case 37:
    {
      if (strcmp(tpChksum, "1i3LZAfIaHjMJtsqqRFjjF") == 0) {
        extern mxArray *sf_c37_DePascali4M_get_post_codegen_info(void);
        plhs[0] = sf_c37_DePascali4M_get_post_codegen_info();
        return;
      }
    }
    break;

   case 38:
    {
      if (strcmp(tpChksum, "KoBjyPLZLMM3KD77IWLpFB") == 0) {
        extern mxArray *sf_c38_DePascali4M_get_post_codegen_info(void);
        plhs[0] = sf_c38_DePascali4M_get_post_codegen_info();
        return;
      }
    }
    break;

   case 39:
    {
      if (strcmp(tpChksum, "uSoQvWIR50U87qasuuatqH") == 0) {
        extern mxArray *sf_c39_DePascali4M_get_post_codegen_info(void);
        plhs[0] = sf_c39_DePascali4M_get_post_codegen_info();
        return;
      }
    }
    break;

   case 40:
    {
      if (strcmp(tpChksum, "KoBjyPLZLMM3KD77IWLpFB") == 0) {
        extern mxArray *sf_c40_DePascali4M_get_post_codegen_info(void);
        plhs[0] = sf_c40_DePascali4M_get_post_codegen_info();
        return;
      }
    }
    break;

   case 41:
    {
      if (strcmp(tpChksum, "n3HQL5BUZGjOWC5ir8NIcH") == 0) {
        extern mxArray *sf_c41_DePascali4M_get_post_codegen_info(void);
        plhs[0] = sf_c41_DePascali4M_get_post_codegen_info();
        return;
      }
    }
    break;

   case 43:
    {
      if (strcmp(tpChksum, "IgmYsTd7hWQzxdq1sf59GB") == 0) {
        extern mxArray *sf_c43_DePascali4M_get_post_codegen_info(void);
        plhs[0] = sf_c43_DePascali4M_get_post_codegen_info();
        return;
      }
    }
    break;

   default:
    break;
  }

  plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
}

void DePascali4M_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _DePascali4MMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "DePascali4M","sfun",0,21,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,_DePascali4MMachineNumber_,
    0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,_DePascali4MMachineNumber_,
    0);
}

void DePascali4M_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_DePascali4M_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("DePascali4M",
      "DePascali4M");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_DePascali4M_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}

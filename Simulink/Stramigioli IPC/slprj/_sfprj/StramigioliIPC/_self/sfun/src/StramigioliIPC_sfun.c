/* Include files */

#include "StramigioliIPC_sfun.h"
#include "StramigioliIPC_sfun_debug_macros.h"
#include "c1_StramigioliIPC.h"
#include "c2_StramigioliIPC.h"
#include "c3_StramigioliIPC.h"
#include "c4_StramigioliIPC.h"
#include "c5_StramigioliIPC.h"
#include "c6_StramigioliIPC.h"
#include "c7_StramigioliIPC.h"
#include "c8_StramigioliIPC.h"
#include "c9_StramigioliIPC.h"
#include "c10_StramigioliIPC.h"
#include "c11_StramigioliIPC.h"
#include "c12_StramigioliIPC.h"
#include "c13_StramigioliIPC.h"
#include "c17_StramigioliIPC.h"
#include "c27_StramigioliIPC.h"
#include "c30_StramigioliIPC.h"
#include "c31_StramigioliIPC.h"
#include "c36_StramigioliIPC.h"
#include "c37_StramigioliIPC.h"
#include "c43_StramigioliIPC.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _StramigioliIPCMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void StramigioliIPC_initializer(void)
{
}

void StramigioliIPC_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_StramigioliIPC_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_StramigioliIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_StramigioliIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_StramigioliIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_StramigioliIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_StramigioliIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_StramigioliIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_StramigioliIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_StramigioliIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_StramigioliIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_StramigioliIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_StramigioliIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_StramigioliIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_StramigioliIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_StramigioliIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==27) {
    c27_StramigioliIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==30) {
    c30_StramigioliIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==31) {
    c31_StramigioliIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==36) {
    c36_StramigioliIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==37) {
    c37_StramigioliIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==43) {
    c43_StramigioliIPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

extern void sf_StramigioliIPC_uses_exported_functions(int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[])
{
  plhs[0] = mxCreateLogicalScalar(0);
}

unsigned int sf_StramigioliIPC_process_check_sum_call( int nlhs, mxArray * plhs[],
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(100120693U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(205871649U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1945512416U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(470739052U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(964310012U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(568617099U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2586783781U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3031650752U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_StramigioliIPC_get_check_sum(mxArray *plhs[]);
          sf_c1_StramigioliIPC_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_StramigioliIPC_get_check_sum(mxArray *plhs[]);
          sf_c2_StramigioliIPC_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_StramigioliIPC_get_check_sum(mxArray *plhs[]);
          sf_c3_StramigioliIPC_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_StramigioliIPC_get_check_sum(mxArray *plhs[]);
          sf_c4_StramigioliIPC_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_StramigioliIPC_get_check_sum(mxArray *plhs[]);
          sf_c5_StramigioliIPC_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_StramigioliIPC_get_check_sum(mxArray *plhs[]);
          sf_c6_StramigioliIPC_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_StramigioliIPC_get_check_sum(mxArray *plhs[]);
          sf_c7_StramigioliIPC_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_StramigioliIPC_get_check_sum(mxArray *plhs[]);
          sf_c8_StramigioliIPC_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_StramigioliIPC_get_check_sum(mxArray *plhs[]);
          sf_c9_StramigioliIPC_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_StramigioliIPC_get_check_sum(mxArray *plhs[]);
          sf_c10_StramigioliIPC_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_StramigioliIPC_get_check_sum(mxArray *plhs[]);
          sf_c11_StramigioliIPC_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_StramigioliIPC_get_check_sum(mxArray *plhs[]);
          sf_c12_StramigioliIPC_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_StramigioliIPC_get_check_sum(mxArray *plhs[]);
          sf_c13_StramigioliIPC_get_check_sum(plhs);
          break;
        }

       case 17:
        {
          extern void sf_c17_StramigioliIPC_get_check_sum(mxArray *plhs[]);
          sf_c17_StramigioliIPC_get_check_sum(plhs);
          break;
        }

       case 27:
        {
          extern void sf_c27_StramigioliIPC_get_check_sum(mxArray *plhs[]);
          sf_c27_StramigioliIPC_get_check_sum(plhs);
          break;
        }

       case 30:
        {
          extern void sf_c30_StramigioliIPC_get_check_sum(mxArray *plhs[]);
          sf_c30_StramigioliIPC_get_check_sum(plhs);
          break;
        }

       case 31:
        {
          extern void sf_c31_StramigioliIPC_get_check_sum(mxArray *plhs[]);
          sf_c31_StramigioliIPC_get_check_sum(plhs);
          break;
        }

       case 36:
        {
          extern void sf_c36_StramigioliIPC_get_check_sum(mxArray *plhs[]);
          sf_c36_StramigioliIPC_get_check_sum(plhs);
          break;
        }

       case 37:
        {
          extern void sf_c37_StramigioliIPC_get_check_sum(mxArray *plhs[]);
          sf_c37_StramigioliIPC_get_check_sum(plhs);
          break;
        }

       case 43:
        {
          extern void sf_c43_StramigioliIPC_get_check_sum(mxArray *plhs[]);
          sf_c43_StramigioliIPC_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1622748782U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4017662424U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(295504089U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3001081132U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_StramigioliIPC_autoinheritance_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(aiChksum, "IQv82vVfmNWymTo4hERJ8B") == 0) {
          extern mxArray *sf_c1_StramigioliIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c1_StramigioliIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "IKgEH3YBIvmBXqNqj7qGeD") == 0) {
          extern mxArray *sf_c2_StramigioliIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c2_StramigioliIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "OxC09uHp2jeVWFyASf5sME") == 0) {
          extern mxArray *sf_c3_StramigioliIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c3_StramigioliIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "YaK5Cx0RcGvZaWkkbFhJVF") == 0) {
          extern mxArray *sf_c4_StramigioliIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c4_StramigioliIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "tna1BcwMvoe2fRwT2pfL9E") == 0) {
          extern mxArray *sf_c5_StramigioliIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c5_StramigioliIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "MNIWBbuNFTZjpPbKWaFHcH") == 0) {
          extern mxArray *sf_c6_StramigioliIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c6_StramigioliIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "tYATzzCrS6feeZiFtybCl") == 0) {
          extern mxArray *sf_c7_StramigioliIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c7_StramigioliIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "LWhmDXPo0xLTSwbSzLYEnF") == 0) {
          extern mxArray *sf_c8_StramigioliIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c8_StramigioliIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "LWhmDXPo0xLTSwbSzLYEnF") == 0) {
          extern mxArray *sf_c9_StramigioliIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c9_StramigioliIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "LWhmDXPo0xLTSwbSzLYEnF") == 0) {
          extern mxArray *sf_c10_StramigioliIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c10_StramigioliIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "LWhmDXPo0xLTSwbSzLYEnF") == 0) {
          extern mxArray *sf_c11_StramigioliIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c11_StramigioliIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "s0FCkwXv4QS0JA2QU7CCuB") == 0) {
          extern mxArray *sf_c12_StramigioliIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c12_StramigioliIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "ijqtv2mNvl0Y6ThidN2s5C") == 0) {
          extern mxArray *sf_c13_StramigioliIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c13_StramigioliIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 17:
      {
        if (strcmp(aiChksum, "s0FCkwXv4QS0JA2QU7CCuB") == 0) {
          extern mxArray *sf_c17_StramigioliIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c17_StramigioliIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 27:
      {
        if (strcmp(aiChksum, "ptbitHloXGK4EEovvS7a8C") == 0) {
          extern mxArray *sf_c27_StramigioliIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c27_StramigioliIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 30:
      {
        if (strcmp(aiChksum, "2DzyioPLwtmX08rJePnILC") == 0) {
          extern mxArray *sf_c30_StramigioliIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c30_StramigioliIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 31:
      {
        if (strcmp(aiChksum, "L4cHfneDxO6L1Btml4R76") == 0) {
          extern mxArray *sf_c31_StramigioliIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c31_StramigioliIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 36:
      {
        if (strcmp(aiChksum, "DD1R3ViA8FSKbVm79jLUZ") == 0) {
          extern mxArray *sf_c36_StramigioliIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c36_StramigioliIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 37:
      {
        if (strcmp(aiChksum, "HH5Q7NBdD7VBwfWldwVT5F") == 0) {
          extern mxArray *sf_c37_StramigioliIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c37_StramigioliIPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 43:
      {
        if (strcmp(aiChksum, "aBAN3OqxekCRqIEyfPDBXC") == 0) {
          extern mxArray *sf_c43_StramigioliIPC_get_autoinheritance_info(void);
          plhs[0] = sf_c43_StramigioliIPC_get_autoinheritance_info();
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

unsigned int sf_StramigioliIPC_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
          *sf_c1_StramigioliIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_StramigioliIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_StramigioliIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_StramigioliIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_StramigioliIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_StramigioliIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_StramigioliIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_StramigioliIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_StramigioliIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_StramigioliIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_StramigioliIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_StramigioliIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_StramigioliIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_StramigioliIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_StramigioliIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_StramigioliIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_StramigioliIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_StramigioliIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_StramigioliIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_StramigioliIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_StramigioliIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_StramigioliIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_StramigioliIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_StramigioliIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_StramigioliIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_StramigioliIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray
          *sf_c17_StramigioliIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_StramigioliIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 27:
      {
        extern const mxArray
          *sf_c27_StramigioliIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c27_StramigioliIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 30:
      {
        extern const mxArray
          *sf_c30_StramigioliIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c30_StramigioliIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 31:
      {
        extern const mxArray
          *sf_c31_StramigioliIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c31_StramigioliIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 36:
      {
        extern const mxArray
          *sf_c36_StramigioliIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c36_StramigioliIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 37:
      {
        extern const mxArray
          *sf_c37_StramigioliIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c37_StramigioliIPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 43:
      {
        extern const mxArray
          *sf_c43_StramigioliIPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c43_StramigioliIPC_get_eml_resolved_functions_info();
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

unsigned int sf_StramigioliIPC_third_party_uses_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(tpChksum, "bUPsLjjCvipU5rTFlLYueG") == 0) {
          extern mxArray *sf_c1_StramigioliIPC_third_party_uses_info(void);
          plhs[0] = sf_c1_StramigioliIPC_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "nPwsrD05flQdXSPejpr77C") == 0) {
          extern mxArray *sf_c2_StramigioliIPC_third_party_uses_info(void);
          plhs[0] = sf_c2_StramigioliIPC_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "ReLHav6fyDQEmFb2xQ9aqG") == 0) {
          extern mxArray *sf_c3_StramigioliIPC_third_party_uses_info(void);
          plhs[0] = sf_c3_StramigioliIPC_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "Jhsw2VGRgNZzMUENcX5tkG") == 0) {
          extern mxArray *sf_c4_StramigioliIPC_third_party_uses_info(void);
          plhs[0] = sf_c4_StramigioliIPC_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "wKjgDzYGh0AKSV9oCDZhuB") == 0) {
          extern mxArray *sf_c5_StramigioliIPC_third_party_uses_info(void);
          plhs[0] = sf_c5_StramigioliIPC_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "vEneZyO80AXkO3fgcTZVhD") == 0) {
          extern mxArray *sf_c6_StramigioliIPC_third_party_uses_info(void);
          plhs[0] = sf_c6_StramigioliIPC_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "TMlGanmzJMEGBnqyVVJ86E") == 0) {
          extern mxArray *sf_c7_StramigioliIPC_third_party_uses_info(void);
          plhs[0] = sf_c7_StramigioliIPC_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c8_StramigioliIPC_third_party_uses_info(void);
          plhs[0] = sf_c8_StramigioliIPC_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c9_StramigioliIPC_third_party_uses_info(void);
          plhs[0] = sf_c9_StramigioliIPC_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c10_StramigioliIPC_third_party_uses_info(void);
          plhs[0] = sf_c10_StramigioliIPC_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c11_StramigioliIPC_third_party_uses_info(void);
          plhs[0] = sf_c11_StramigioliIPC_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "lvwD6XFKaAPm7OPPKfJroF") == 0) {
          extern mxArray *sf_c12_StramigioliIPC_third_party_uses_info(void);
          plhs[0] = sf_c12_StramigioliIPC_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "j952PgPqb5o1eVDTxUT2GD") == 0) {
          extern mxArray *sf_c13_StramigioliIPC_third_party_uses_info(void);
          plhs[0] = sf_c13_StramigioliIPC_third_party_uses_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "lvwD6XFKaAPm7OPPKfJroF") == 0) {
          extern mxArray *sf_c17_StramigioliIPC_third_party_uses_info(void);
          plhs[0] = sf_c17_StramigioliIPC_third_party_uses_info();
          break;
        }
      }

     case 27:
      {
        if (strcmp(tpChksum, "lB2d7yfjcanR8gAvZoHiGF") == 0) {
          extern mxArray *sf_c27_StramigioliIPC_third_party_uses_info(void);
          plhs[0] = sf_c27_StramigioliIPC_third_party_uses_info();
          break;
        }
      }

     case 30:
      {
        if (strcmp(tpChksum, "KoBjyPLZLMM3KD77IWLpFB") == 0) {
          extern mxArray *sf_c30_StramigioliIPC_third_party_uses_info(void);
          plhs[0] = sf_c30_StramigioliIPC_third_party_uses_info();
          break;
        }
      }

     case 31:
      {
        if (strcmp(tpChksum, "WuMhkbnscSKHTcaYGq7t0C") == 0) {
          extern mxArray *sf_c31_StramigioliIPC_third_party_uses_info(void);
          plhs[0] = sf_c31_StramigioliIPC_third_party_uses_info();
          break;
        }
      }

     case 36:
      {
        if (strcmp(tpChksum, "R5fJ5cX5KyORqPmZdJfjYC") == 0) {
          extern mxArray *sf_c36_StramigioliIPC_third_party_uses_info(void);
          plhs[0] = sf_c36_StramigioliIPC_third_party_uses_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "1i3LZAfIaHjMJtsqqRFjjF") == 0) {
          extern mxArray *sf_c37_StramigioliIPC_third_party_uses_info(void);
          plhs[0] = sf_c37_StramigioliIPC_third_party_uses_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "IgmYsTd7hWQzxdq1sf59GB") == 0) {
          extern mxArray *sf_c43_StramigioliIPC_third_party_uses_info(void);
          plhs[0] = sf_c43_StramigioliIPC_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_StramigioliIPC_jit_fallback_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
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
        if (strcmp(tpChksum, "bUPsLjjCvipU5rTFlLYueG") == 0) {
          extern mxArray *sf_c1_StramigioliIPC_jit_fallback_info(void);
          plhs[0] = sf_c1_StramigioliIPC_jit_fallback_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "nPwsrD05flQdXSPejpr77C") == 0) {
          extern mxArray *sf_c2_StramigioliIPC_jit_fallback_info(void);
          plhs[0] = sf_c2_StramigioliIPC_jit_fallback_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "ReLHav6fyDQEmFb2xQ9aqG") == 0) {
          extern mxArray *sf_c3_StramigioliIPC_jit_fallback_info(void);
          plhs[0] = sf_c3_StramigioliIPC_jit_fallback_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "Jhsw2VGRgNZzMUENcX5tkG") == 0) {
          extern mxArray *sf_c4_StramigioliIPC_jit_fallback_info(void);
          plhs[0] = sf_c4_StramigioliIPC_jit_fallback_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "wKjgDzYGh0AKSV9oCDZhuB") == 0) {
          extern mxArray *sf_c5_StramigioliIPC_jit_fallback_info(void);
          plhs[0] = sf_c5_StramigioliIPC_jit_fallback_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "vEneZyO80AXkO3fgcTZVhD") == 0) {
          extern mxArray *sf_c6_StramigioliIPC_jit_fallback_info(void);
          plhs[0] = sf_c6_StramigioliIPC_jit_fallback_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "TMlGanmzJMEGBnqyVVJ86E") == 0) {
          extern mxArray *sf_c7_StramigioliIPC_jit_fallback_info(void);
          plhs[0] = sf_c7_StramigioliIPC_jit_fallback_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c8_StramigioliIPC_jit_fallback_info(void);
          plhs[0] = sf_c8_StramigioliIPC_jit_fallback_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c9_StramigioliIPC_jit_fallback_info(void);
          plhs[0] = sf_c9_StramigioliIPC_jit_fallback_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c10_StramigioliIPC_jit_fallback_info(void);
          plhs[0] = sf_c10_StramigioliIPC_jit_fallback_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c11_StramigioliIPC_jit_fallback_info(void);
          plhs[0] = sf_c11_StramigioliIPC_jit_fallback_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "lvwD6XFKaAPm7OPPKfJroF") == 0) {
          extern mxArray *sf_c12_StramigioliIPC_jit_fallback_info(void);
          plhs[0] = sf_c12_StramigioliIPC_jit_fallback_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "j952PgPqb5o1eVDTxUT2GD") == 0) {
          extern mxArray *sf_c13_StramigioliIPC_jit_fallback_info(void);
          plhs[0] = sf_c13_StramigioliIPC_jit_fallback_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "lvwD6XFKaAPm7OPPKfJroF") == 0) {
          extern mxArray *sf_c17_StramigioliIPC_jit_fallback_info(void);
          plhs[0] = sf_c17_StramigioliIPC_jit_fallback_info();
          break;
        }
      }

     case 27:
      {
        if (strcmp(tpChksum, "lB2d7yfjcanR8gAvZoHiGF") == 0) {
          extern mxArray *sf_c27_StramigioliIPC_jit_fallback_info(void);
          plhs[0] = sf_c27_StramigioliIPC_jit_fallback_info();
          break;
        }
      }

     case 30:
      {
        if (strcmp(tpChksum, "KoBjyPLZLMM3KD77IWLpFB") == 0) {
          extern mxArray *sf_c30_StramigioliIPC_jit_fallback_info(void);
          plhs[0] = sf_c30_StramigioliIPC_jit_fallback_info();
          break;
        }
      }

     case 31:
      {
        if (strcmp(tpChksum, "WuMhkbnscSKHTcaYGq7t0C") == 0) {
          extern mxArray *sf_c31_StramigioliIPC_jit_fallback_info(void);
          plhs[0] = sf_c31_StramigioliIPC_jit_fallback_info();
          break;
        }
      }

     case 36:
      {
        if (strcmp(tpChksum, "R5fJ5cX5KyORqPmZdJfjYC") == 0) {
          extern mxArray *sf_c36_StramigioliIPC_jit_fallback_info(void);
          plhs[0] = sf_c36_StramigioliIPC_jit_fallback_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "1i3LZAfIaHjMJtsqqRFjjF") == 0) {
          extern mxArray *sf_c37_StramigioliIPC_jit_fallback_info(void);
          plhs[0] = sf_c37_StramigioliIPC_jit_fallback_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "IgmYsTd7hWQzxdq1sf59GB") == 0) {
          extern mxArray *sf_c43_StramigioliIPC_jit_fallback_info(void);
          plhs[0] = sf_c43_StramigioliIPC_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_StramigioliIPC_updateBuildInfo_args_info( int nlhs, mxArray *
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
        if (strcmp(tpChksum, "bUPsLjjCvipU5rTFlLYueG") == 0) {
          extern mxArray *sf_c1_StramigioliIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_StramigioliIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "nPwsrD05flQdXSPejpr77C") == 0) {
          extern mxArray *sf_c2_StramigioliIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_StramigioliIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "ReLHav6fyDQEmFb2xQ9aqG") == 0) {
          extern mxArray *sf_c3_StramigioliIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_StramigioliIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "Jhsw2VGRgNZzMUENcX5tkG") == 0) {
          extern mxArray *sf_c4_StramigioliIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_StramigioliIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "wKjgDzYGh0AKSV9oCDZhuB") == 0) {
          extern mxArray *sf_c5_StramigioliIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_StramigioliIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "vEneZyO80AXkO3fgcTZVhD") == 0) {
          extern mxArray *sf_c6_StramigioliIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_StramigioliIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "TMlGanmzJMEGBnqyVVJ86E") == 0) {
          extern mxArray *sf_c7_StramigioliIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_StramigioliIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c8_StramigioliIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_StramigioliIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c9_StramigioliIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_StramigioliIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c10_StramigioliIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_StramigioliIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c11_StramigioliIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_StramigioliIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "lvwD6XFKaAPm7OPPKfJroF") == 0) {
          extern mxArray *sf_c12_StramigioliIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c12_StramigioliIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "j952PgPqb5o1eVDTxUT2GD") == 0) {
          extern mxArray *sf_c13_StramigioliIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c13_StramigioliIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "lvwD6XFKaAPm7OPPKfJroF") == 0) {
          extern mxArray *sf_c17_StramigioliIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c17_StramigioliIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 27:
      {
        if (strcmp(tpChksum, "lB2d7yfjcanR8gAvZoHiGF") == 0) {
          extern mxArray *sf_c27_StramigioliIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c27_StramigioliIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 30:
      {
        if (strcmp(tpChksum, "KoBjyPLZLMM3KD77IWLpFB") == 0) {
          extern mxArray *sf_c30_StramigioliIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c30_StramigioliIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 31:
      {
        if (strcmp(tpChksum, "WuMhkbnscSKHTcaYGq7t0C") == 0) {
          extern mxArray *sf_c31_StramigioliIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c31_StramigioliIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 36:
      {
        if (strcmp(tpChksum, "R5fJ5cX5KyORqPmZdJfjYC") == 0) {
          extern mxArray *sf_c36_StramigioliIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c36_StramigioliIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "1i3LZAfIaHjMJtsqqRFjjF") == 0) {
          extern mxArray *sf_c37_StramigioliIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c37_StramigioliIPC_updateBuildInfo_args_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "IgmYsTd7hWQzxdq1sf59GB") == 0) {
          extern mxArray *sf_c43_StramigioliIPC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c43_StramigioliIPC_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void sf_StramigioliIPC_get_post_codegen_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  unsigned int chartFileNumber = (unsigned int) mxGetScalar(prhs[0]);
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  switch (chartFileNumber) {
   case 1:
    {
      if (strcmp(tpChksum, "bUPsLjjCvipU5rTFlLYueG") == 0) {
        extern mxArray *sf_c1_StramigioliIPC_get_post_codegen_info(void);
        plhs[0] = sf_c1_StramigioliIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 2:
    {
      if (strcmp(tpChksum, "nPwsrD05flQdXSPejpr77C") == 0) {
        extern mxArray *sf_c2_StramigioliIPC_get_post_codegen_info(void);
        plhs[0] = sf_c2_StramigioliIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 3:
    {
      if (strcmp(tpChksum, "ReLHav6fyDQEmFb2xQ9aqG") == 0) {
        extern mxArray *sf_c3_StramigioliIPC_get_post_codegen_info(void);
        plhs[0] = sf_c3_StramigioliIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 4:
    {
      if (strcmp(tpChksum, "Jhsw2VGRgNZzMUENcX5tkG") == 0) {
        extern mxArray *sf_c4_StramigioliIPC_get_post_codegen_info(void);
        plhs[0] = sf_c4_StramigioliIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 5:
    {
      if (strcmp(tpChksum, "wKjgDzYGh0AKSV9oCDZhuB") == 0) {
        extern mxArray *sf_c5_StramigioliIPC_get_post_codegen_info(void);
        plhs[0] = sf_c5_StramigioliIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 6:
    {
      if (strcmp(tpChksum, "vEneZyO80AXkO3fgcTZVhD") == 0) {
        extern mxArray *sf_c6_StramigioliIPC_get_post_codegen_info(void);
        plhs[0] = sf_c6_StramigioliIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 7:
    {
      if (strcmp(tpChksum, "TMlGanmzJMEGBnqyVVJ86E") == 0) {
        extern mxArray *sf_c7_StramigioliIPC_get_post_codegen_info(void);
        plhs[0] = sf_c7_StramigioliIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 8:
    {
      if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
        extern mxArray *sf_c8_StramigioliIPC_get_post_codegen_info(void);
        plhs[0] = sf_c8_StramigioliIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 9:
    {
      if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
        extern mxArray *sf_c9_StramigioliIPC_get_post_codegen_info(void);
        plhs[0] = sf_c9_StramigioliIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 10:
    {
      if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
        extern mxArray *sf_c10_StramigioliIPC_get_post_codegen_info(void);
        plhs[0] = sf_c10_StramigioliIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 11:
    {
      if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
        extern mxArray *sf_c11_StramigioliIPC_get_post_codegen_info(void);
        plhs[0] = sf_c11_StramigioliIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 12:
    {
      if (strcmp(tpChksum, "lvwD6XFKaAPm7OPPKfJroF") == 0) {
        extern mxArray *sf_c12_StramigioliIPC_get_post_codegen_info(void);
        plhs[0] = sf_c12_StramigioliIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 13:
    {
      if (strcmp(tpChksum, "j952PgPqb5o1eVDTxUT2GD") == 0) {
        extern mxArray *sf_c13_StramigioliIPC_get_post_codegen_info(void);
        plhs[0] = sf_c13_StramigioliIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 17:
    {
      if (strcmp(tpChksum, "lvwD6XFKaAPm7OPPKfJroF") == 0) {
        extern mxArray *sf_c17_StramigioliIPC_get_post_codegen_info(void);
        plhs[0] = sf_c17_StramigioliIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 27:
    {
      if (strcmp(tpChksum, "lB2d7yfjcanR8gAvZoHiGF") == 0) {
        extern mxArray *sf_c27_StramigioliIPC_get_post_codegen_info(void);
        plhs[0] = sf_c27_StramigioliIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 30:
    {
      if (strcmp(tpChksum, "KoBjyPLZLMM3KD77IWLpFB") == 0) {
        extern mxArray *sf_c30_StramigioliIPC_get_post_codegen_info(void);
        plhs[0] = sf_c30_StramigioliIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 31:
    {
      if (strcmp(tpChksum, "WuMhkbnscSKHTcaYGq7t0C") == 0) {
        extern mxArray *sf_c31_StramigioliIPC_get_post_codegen_info(void);
        plhs[0] = sf_c31_StramigioliIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 36:
    {
      if (strcmp(tpChksum, "R5fJ5cX5KyORqPmZdJfjYC") == 0) {
        extern mxArray *sf_c36_StramigioliIPC_get_post_codegen_info(void);
        plhs[0] = sf_c36_StramigioliIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 37:
    {
      if (strcmp(tpChksum, "1i3LZAfIaHjMJtsqqRFjjF") == 0) {
        extern mxArray *sf_c37_StramigioliIPC_get_post_codegen_info(void);
        plhs[0] = sf_c37_StramigioliIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   case 43:
    {
      if (strcmp(tpChksum, "IgmYsTd7hWQzxdq1sf59GB") == 0) {
        extern mxArray *sf_c43_StramigioliIPC_get_post_codegen_info(void);
        plhs[0] = sf_c43_StramigioliIPC_get_post_codegen_info();
        return;
      }
    }
    break;

   default:
    break;
  }

  plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
}

void StramigioliIPC_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _StramigioliIPCMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "StramigioliIPC","sfun",0,20,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _StramigioliIPCMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _StramigioliIPCMachineNumber_,0);
}

void StramigioliIPC_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_StramigioliIPC_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("StramigioliIPC",
      "StramigioliIPC");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_StramigioliIPC_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}

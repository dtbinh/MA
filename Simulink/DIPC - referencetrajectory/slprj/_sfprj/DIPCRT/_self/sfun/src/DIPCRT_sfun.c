/* Include files */

#include "DIPCRT_sfun.h"
#include "DIPCRT_sfun_debug_macros.h"
#include "c1_DIPCRT.h"
#include "c2_DIPCRT.h"
#include "c3_DIPCRT.h"
#include "c4_DIPCRT.h"
#include "c5_DIPCRT.h"
#include "c6_DIPCRT.h"
#include "c7_DIPCRT.h"
#include "c8_DIPCRT.h"
#include "c9_DIPCRT.h"
#include "c10_DIPCRT.h"
#include "c11_DIPCRT.h"
#include "c12_DIPCRT.h"
#include "c13_DIPCRT.h"
#include "c17_DIPCRT.h"
#include "c18_DIPCRT.h"
#include "c22_DIPCRT.h"
#include "c23_DIPCRT.h"
#include "c24_DIPCRT.h"
#include "c25_DIPCRT.h"
#include "c26_DIPCRT.h"
#include "c27_DIPCRT.h"
#include "c28_DIPCRT.h"
#include "c29_DIPCRT.h"
#include "c30_DIPCRT.h"
#include "c31_DIPCRT.h"
#include "c36_DIPCRT.h"
#include "c37_DIPCRT.h"
#include "c43_DIPCRT.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _DIPCRTMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void DIPCRT_initializer(void)
{
}

void DIPCRT_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_DIPCRT_method_dispatcher(SimStruct *simstructPtr, unsigned int
  chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_DIPCRT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_DIPCRT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_DIPCRT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_DIPCRT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_DIPCRT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_DIPCRT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_DIPCRT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_DIPCRT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_DIPCRT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_DIPCRT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_DIPCRT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_DIPCRT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_DIPCRT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_DIPCRT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==18) {
    c18_DIPCRT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==22) {
    c22_DIPCRT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==23) {
    c23_DIPCRT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==24) {
    c24_DIPCRT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==25) {
    c25_DIPCRT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==26) {
    c26_DIPCRT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==27) {
    c27_DIPCRT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==28) {
    c28_DIPCRT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==29) {
    c29_DIPCRT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==30) {
    c30_DIPCRT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==31) {
    c31_DIPCRT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==36) {
    c36_DIPCRT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==37) {
    c37_DIPCRT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==43) {
    c43_DIPCRT_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

extern void sf_DIPCRT_uses_exported_functions(int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[])
{
  plhs[0] = mxCreateLogicalScalar(0);
}

unsigned int sf_DIPCRT_process_check_sum_call( int nlhs, mxArray * plhs[], int
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(385800354U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1497568197U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1495077822U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(331581678U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1286624021U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2809036119U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(798260042U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1213244730U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_DIPCRT_get_check_sum(mxArray *plhs[]);
          sf_c1_DIPCRT_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_DIPCRT_get_check_sum(mxArray *plhs[]);
          sf_c2_DIPCRT_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_DIPCRT_get_check_sum(mxArray *plhs[]);
          sf_c3_DIPCRT_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_DIPCRT_get_check_sum(mxArray *plhs[]);
          sf_c4_DIPCRT_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_DIPCRT_get_check_sum(mxArray *plhs[]);
          sf_c5_DIPCRT_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_DIPCRT_get_check_sum(mxArray *plhs[]);
          sf_c6_DIPCRT_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_DIPCRT_get_check_sum(mxArray *plhs[]);
          sf_c7_DIPCRT_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_DIPCRT_get_check_sum(mxArray *plhs[]);
          sf_c8_DIPCRT_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_DIPCRT_get_check_sum(mxArray *plhs[]);
          sf_c9_DIPCRT_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_DIPCRT_get_check_sum(mxArray *plhs[]);
          sf_c10_DIPCRT_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_DIPCRT_get_check_sum(mxArray *plhs[]);
          sf_c11_DIPCRT_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_DIPCRT_get_check_sum(mxArray *plhs[]);
          sf_c12_DIPCRT_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_DIPCRT_get_check_sum(mxArray *plhs[]);
          sf_c13_DIPCRT_get_check_sum(plhs);
          break;
        }

       case 17:
        {
          extern void sf_c17_DIPCRT_get_check_sum(mxArray *plhs[]);
          sf_c17_DIPCRT_get_check_sum(plhs);
          break;
        }

       case 18:
        {
          extern void sf_c18_DIPCRT_get_check_sum(mxArray *plhs[]);
          sf_c18_DIPCRT_get_check_sum(plhs);
          break;
        }

       case 22:
        {
          extern void sf_c22_DIPCRT_get_check_sum(mxArray *plhs[]);
          sf_c22_DIPCRT_get_check_sum(plhs);
          break;
        }

       case 23:
        {
          extern void sf_c23_DIPCRT_get_check_sum(mxArray *plhs[]);
          sf_c23_DIPCRT_get_check_sum(plhs);
          break;
        }

       case 24:
        {
          extern void sf_c24_DIPCRT_get_check_sum(mxArray *plhs[]);
          sf_c24_DIPCRT_get_check_sum(plhs);
          break;
        }

       case 25:
        {
          extern void sf_c25_DIPCRT_get_check_sum(mxArray *plhs[]);
          sf_c25_DIPCRT_get_check_sum(plhs);
          break;
        }

       case 26:
        {
          extern void sf_c26_DIPCRT_get_check_sum(mxArray *plhs[]);
          sf_c26_DIPCRT_get_check_sum(plhs);
          break;
        }

       case 27:
        {
          extern void sf_c27_DIPCRT_get_check_sum(mxArray *plhs[]);
          sf_c27_DIPCRT_get_check_sum(plhs);
          break;
        }

       case 28:
        {
          extern void sf_c28_DIPCRT_get_check_sum(mxArray *plhs[]);
          sf_c28_DIPCRT_get_check_sum(plhs);
          break;
        }

       case 29:
        {
          extern void sf_c29_DIPCRT_get_check_sum(mxArray *plhs[]);
          sf_c29_DIPCRT_get_check_sum(plhs);
          break;
        }

       case 30:
        {
          extern void sf_c30_DIPCRT_get_check_sum(mxArray *plhs[]);
          sf_c30_DIPCRT_get_check_sum(plhs);
          break;
        }

       case 31:
        {
          extern void sf_c31_DIPCRT_get_check_sum(mxArray *plhs[]);
          sf_c31_DIPCRT_get_check_sum(plhs);
          break;
        }

       case 36:
        {
          extern void sf_c36_DIPCRT_get_check_sum(mxArray *plhs[]);
          sf_c36_DIPCRT_get_check_sum(plhs);
          break;
        }

       case 37:
        {
          extern void sf_c37_DIPCRT_get_check_sum(mxArray *plhs[]);
          sf_c37_DIPCRT_get_check_sum(plhs);
          break;
        }

       case 43:
        {
          extern void sf_c43_DIPCRT_get_check_sum(mxArray *plhs[]);
          sf_c43_DIPCRT_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3994466587U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(329371957U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(102002576U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4131847397U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_DIPCRT_autoinheritance_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
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
          extern mxArray *sf_c1_DIPCRT_get_autoinheritance_info(void);
          plhs[0] = sf_c1_DIPCRT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "IKgEH3YBIvmBXqNqj7qGeD") == 0) {
          extern mxArray *sf_c2_DIPCRT_get_autoinheritance_info(void);
          plhs[0] = sf_c2_DIPCRT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "OxC09uHp2jeVWFyASf5sME") == 0) {
          extern mxArray *sf_c3_DIPCRT_get_autoinheritance_info(void);
          plhs[0] = sf_c3_DIPCRT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "YaK5Cx0RcGvZaWkkbFhJVF") == 0) {
          extern mxArray *sf_c4_DIPCRT_get_autoinheritance_info(void);
          plhs[0] = sf_c4_DIPCRT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "tna1BcwMvoe2fRwT2pfL9E") == 0) {
          extern mxArray *sf_c5_DIPCRT_get_autoinheritance_info(void);
          plhs[0] = sf_c5_DIPCRT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "MNIWBbuNFTZjpPbKWaFHcH") == 0) {
          extern mxArray *sf_c6_DIPCRT_get_autoinheritance_info(void);
          plhs[0] = sf_c6_DIPCRT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "tYATzzCrS6feeZiFtybCl") == 0) {
          extern mxArray *sf_c7_DIPCRT_get_autoinheritance_info(void);
          plhs[0] = sf_c7_DIPCRT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "LWhmDXPo0xLTSwbSzLYEnF") == 0) {
          extern mxArray *sf_c8_DIPCRT_get_autoinheritance_info(void);
          plhs[0] = sf_c8_DIPCRT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "LWhmDXPo0xLTSwbSzLYEnF") == 0) {
          extern mxArray *sf_c9_DIPCRT_get_autoinheritance_info(void);
          plhs[0] = sf_c9_DIPCRT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "LWhmDXPo0xLTSwbSzLYEnF") == 0) {
          extern mxArray *sf_c10_DIPCRT_get_autoinheritance_info(void);
          plhs[0] = sf_c10_DIPCRT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "LWhmDXPo0xLTSwbSzLYEnF") == 0) {
          extern mxArray *sf_c11_DIPCRT_get_autoinheritance_info(void);
          plhs[0] = sf_c11_DIPCRT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "s0FCkwXv4QS0JA2QU7CCuB") == 0) {
          extern mxArray *sf_c12_DIPCRT_get_autoinheritance_info(void);
          plhs[0] = sf_c12_DIPCRT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "ijqtv2mNvl0Y6ThidN2s5C") == 0) {
          extern mxArray *sf_c13_DIPCRT_get_autoinheritance_info(void);
          plhs[0] = sf_c13_DIPCRT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 17:
      {
        if (strcmp(aiChksum, "s0FCkwXv4QS0JA2QU7CCuB") == 0) {
          extern mxArray *sf_c17_DIPCRT_get_autoinheritance_info(void);
          plhs[0] = sf_c17_DIPCRT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 18:
      {
        if (strcmp(aiChksum, "2pAN8XqKE50gbCmGGn0nmB") == 0) {
          extern mxArray *sf_c18_DIPCRT_get_autoinheritance_info(void);
          plhs[0] = sf_c18_DIPCRT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 22:
      {
        if (strcmp(aiChksum, "2pAN8XqKE50gbCmGGn0nmB") == 0) {
          extern mxArray *sf_c22_DIPCRT_get_autoinheritance_info(void);
          plhs[0] = sf_c22_DIPCRT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 23:
      {
        if (strcmp(aiChksum, "2pAN8XqKE50gbCmGGn0nmB") == 0) {
          extern mxArray *sf_c23_DIPCRT_get_autoinheritance_info(void);
          plhs[0] = sf_c23_DIPCRT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 24:
      {
        if (strcmp(aiChksum, "2pAN8XqKE50gbCmGGn0nmB") == 0) {
          extern mxArray *sf_c24_DIPCRT_get_autoinheritance_info(void);
          plhs[0] = sf_c24_DIPCRT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 25:
      {
        if (strcmp(aiChksum, "PydXxTZ25DlHqcdKniJvGH") == 0) {
          extern mxArray *sf_c25_DIPCRT_get_autoinheritance_info(void);
          plhs[0] = sf_c25_DIPCRT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 26:
      {
        if (strcmp(aiChksum, "NZGt4hui16RErDsZaLrtMD") == 0) {
          extern mxArray *sf_c26_DIPCRT_get_autoinheritance_info(void);
          plhs[0] = sf_c26_DIPCRT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 27:
      {
        if (strcmp(aiChksum, "ViawJUeHbDwUTtbMbDvX0B") == 0) {
          extern mxArray *sf_c27_DIPCRT_get_autoinheritance_info(void);
          plhs[0] = sf_c27_DIPCRT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 28:
      {
        if (strcmp(aiChksum, "lpDXXC9dMqzlo3kVn9HLWB") == 0) {
          extern mxArray *sf_c28_DIPCRT_get_autoinheritance_info(void);
          plhs[0] = sf_c28_DIPCRT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 29:
      {
        if (strcmp(aiChksum, "j0bVmXlZXPFmEhVmxG8dUF") == 0) {
          extern mxArray *sf_c29_DIPCRT_get_autoinheritance_info(void);
          plhs[0] = sf_c29_DIPCRT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 30:
      {
        if (strcmp(aiChksum, "2DzyioPLwtmX08rJePnILC") == 0) {
          extern mxArray *sf_c30_DIPCRT_get_autoinheritance_info(void);
          plhs[0] = sf_c30_DIPCRT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 31:
      {
        if (strcmp(aiChksum, "L4cHfneDxO6L1Btml4R76") == 0) {
          extern mxArray *sf_c31_DIPCRT_get_autoinheritance_info(void);
          plhs[0] = sf_c31_DIPCRT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 36:
      {
        if (strcmp(aiChksum, "DD1R3ViA8FSKbVm79jLUZ") == 0) {
          extern mxArray *sf_c36_DIPCRT_get_autoinheritance_info(void);
          plhs[0] = sf_c36_DIPCRT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 37:
      {
        if (strcmp(aiChksum, "HH5Q7NBdD7VBwfWldwVT5F") == 0) {
          extern mxArray *sf_c37_DIPCRT_get_autoinheritance_info(void);
          plhs[0] = sf_c37_DIPCRT_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 43:
      {
        if (strcmp(aiChksum, "aBAN3OqxekCRqIEyfPDBXC") == 0) {
          extern mxArray *sf_c43_DIPCRT_get_autoinheritance_info(void);
          plhs[0] = sf_c43_DIPCRT_get_autoinheritance_info();
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

unsigned int sf_DIPCRT_get_eml_resolved_functions_info( int nlhs, mxArray *
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
        extern const mxArray *sf_c1_DIPCRT_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_DIPCRT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_DIPCRT_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_DIPCRT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_DIPCRT_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_DIPCRT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_DIPCRT_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_DIPCRT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_DIPCRT_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_DIPCRT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray *sf_c6_DIPCRT_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_DIPCRT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray *sf_c7_DIPCRT_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_DIPCRT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray *sf_c8_DIPCRT_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_DIPCRT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray *sf_c9_DIPCRT_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_DIPCRT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray *sf_c10_DIPCRT_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_DIPCRT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray *sf_c11_DIPCRT_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_DIPCRT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray *sf_c12_DIPCRT_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_DIPCRT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray *sf_c13_DIPCRT_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_DIPCRT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray *sf_c17_DIPCRT_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_DIPCRT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 18:
      {
        extern const mxArray *sf_c18_DIPCRT_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c18_DIPCRT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 22:
      {
        extern const mxArray *sf_c22_DIPCRT_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c22_DIPCRT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 23:
      {
        extern const mxArray *sf_c23_DIPCRT_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c23_DIPCRT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 24:
      {
        extern const mxArray *sf_c24_DIPCRT_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c24_DIPCRT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 25:
      {
        extern const mxArray *sf_c25_DIPCRT_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c25_DIPCRT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 26:
      {
        extern const mxArray *sf_c26_DIPCRT_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c26_DIPCRT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 27:
      {
        extern const mxArray *sf_c27_DIPCRT_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c27_DIPCRT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 28:
      {
        extern const mxArray *sf_c28_DIPCRT_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c28_DIPCRT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 29:
      {
        extern const mxArray *sf_c29_DIPCRT_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c29_DIPCRT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 30:
      {
        extern const mxArray *sf_c30_DIPCRT_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c30_DIPCRT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 31:
      {
        extern const mxArray *sf_c31_DIPCRT_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c31_DIPCRT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 36:
      {
        extern const mxArray *sf_c36_DIPCRT_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c36_DIPCRT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 37:
      {
        extern const mxArray *sf_c37_DIPCRT_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c37_DIPCRT_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 43:
      {
        extern const mxArray *sf_c43_DIPCRT_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c43_DIPCRT_get_eml_resolved_functions_info();
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

unsigned int sf_DIPCRT_third_party_uses_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
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
          extern mxArray *sf_c1_DIPCRT_third_party_uses_info(void);
          plhs[0] = sf_c1_DIPCRT_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "nPwsrD05flQdXSPejpr77C") == 0) {
          extern mxArray *sf_c2_DIPCRT_third_party_uses_info(void);
          plhs[0] = sf_c2_DIPCRT_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "ReLHav6fyDQEmFb2xQ9aqG") == 0) {
          extern mxArray *sf_c3_DIPCRT_third_party_uses_info(void);
          plhs[0] = sf_c3_DIPCRT_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "Jhsw2VGRgNZzMUENcX5tkG") == 0) {
          extern mxArray *sf_c4_DIPCRT_third_party_uses_info(void);
          plhs[0] = sf_c4_DIPCRT_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "wKjgDzYGh0AKSV9oCDZhuB") == 0) {
          extern mxArray *sf_c5_DIPCRT_third_party_uses_info(void);
          plhs[0] = sf_c5_DIPCRT_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "vEneZyO80AXkO3fgcTZVhD") == 0) {
          extern mxArray *sf_c6_DIPCRT_third_party_uses_info(void);
          plhs[0] = sf_c6_DIPCRT_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "TMlGanmzJMEGBnqyVVJ86E") == 0) {
          extern mxArray *sf_c7_DIPCRT_third_party_uses_info(void);
          plhs[0] = sf_c7_DIPCRT_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c8_DIPCRT_third_party_uses_info(void);
          plhs[0] = sf_c8_DIPCRT_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c9_DIPCRT_third_party_uses_info(void);
          plhs[0] = sf_c9_DIPCRT_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c10_DIPCRT_third_party_uses_info(void);
          plhs[0] = sf_c10_DIPCRT_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c11_DIPCRT_third_party_uses_info(void);
          plhs[0] = sf_c11_DIPCRT_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "lvwD6XFKaAPm7OPPKfJroF") == 0) {
          extern mxArray *sf_c12_DIPCRT_third_party_uses_info(void);
          plhs[0] = sf_c12_DIPCRT_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "j952PgPqb5o1eVDTxUT2GD") == 0) {
          extern mxArray *sf_c13_DIPCRT_third_party_uses_info(void);
          plhs[0] = sf_c13_DIPCRT_third_party_uses_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "lvwD6XFKaAPm7OPPKfJroF") == 0) {
          extern mxArray *sf_c17_DIPCRT_third_party_uses_info(void);
          plhs[0] = sf_c17_DIPCRT_third_party_uses_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "39vboBrh4eZBpQB8o12LJ") == 0) {
          extern mxArray *sf_c18_DIPCRT_third_party_uses_info(void);
          plhs[0] = sf_c18_DIPCRT_third_party_uses_info();
          break;
        }
      }

     case 22:
      {
        if (strcmp(tpChksum, "39vboBrh4eZBpQB8o12LJ") == 0) {
          extern mxArray *sf_c22_DIPCRT_third_party_uses_info(void);
          plhs[0] = sf_c22_DIPCRT_third_party_uses_info();
          break;
        }
      }

     case 23:
      {
        if (strcmp(tpChksum, "39vboBrh4eZBpQB8o12LJ") == 0) {
          extern mxArray *sf_c23_DIPCRT_third_party_uses_info(void);
          plhs[0] = sf_c23_DIPCRT_third_party_uses_info();
          break;
        }
      }

     case 24:
      {
        if (strcmp(tpChksum, "39vboBrh4eZBpQB8o12LJ") == 0) {
          extern mxArray *sf_c24_DIPCRT_third_party_uses_info(void);
          plhs[0] = sf_c24_DIPCRT_third_party_uses_info();
          break;
        }
      }

     case 25:
      {
        if (strcmp(tpChksum, "bgMo300tpt2nma5SeDP5eG") == 0) {
          extern mxArray *sf_c25_DIPCRT_third_party_uses_info(void);
          plhs[0] = sf_c25_DIPCRT_third_party_uses_info();
          break;
        }
      }

     case 26:
      {
        if (strcmp(tpChksum, "Pn0NwQgA7VHB90aenRX2KE") == 0) {
          extern mxArray *sf_c26_DIPCRT_third_party_uses_info(void);
          plhs[0] = sf_c26_DIPCRT_third_party_uses_info();
          break;
        }
      }

     case 27:
      {
        if (strcmp(tpChksum, "OIGfYsR6yVO0itJB6eck0F") == 0) {
          extern mxArray *sf_c27_DIPCRT_third_party_uses_info(void);
          plhs[0] = sf_c27_DIPCRT_third_party_uses_info();
          break;
        }
      }

     case 28:
      {
        if (strcmp(tpChksum, "ezyyAnTcKjd7cyr3PGBSJ") == 0) {
          extern mxArray *sf_c28_DIPCRT_third_party_uses_info(void);
          plhs[0] = sf_c28_DIPCRT_third_party_uses_info();
          break;
        }
      }

     case 29:
      {
        if (strcmp(tpChksum, "F9NaUoFsluwUCMezsgpn1D") == 0) {
          extern mxArray *sf_c29_DIPCRT_third_party_uses_info(void);
          plhs[0] = sf_c29_DIPCRT_third_party_uses_info();
          break;
        }
      }

     case 30:
      {
        if (strcmp(tpChksum, "KoBjyPLZLMM3KD77IWLpFB") == 0) {
          extern mxArray *sf_c30_DIPCRT_third_party_uses_info(void);
          plhs[0] = sf_c30_DIPCRT_third_party_uses_info();
          break;
        }
      }

     case 31:
      {
        if (strcmp(tpChksum, "WuMhkbnscSKHTcaYGq7t0C") == 0) {
          extern mxArray *sf_c31_DIPCRT_third_party_uses_info(void);
          plhs[0] = sf_c31_DIPCRT_third_party_uses_info();
          break;
        }
      }

     case 36:
      {
        if (strcmp(tpChksum, "R5fJ5cX5KyORqPmZdJfjYC") == 0) {
          extern mxArray *sf_c36_DIPCRT_third_party_uses_info(void);
          plhs[0] = sf_c36_DIPCRT_third_party_uses_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "1i3LZAfIaHjMJtsqqRFjjF") == 0) {
          extern mxArray *sf_c37_DIPCRT_third_party_uses_info(void);
          plhs[0] = sf_c37_DIPCRT_third_party_uses_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "IgmYsTd7hWQzxdq1sf59GB") == 0) {
          extern mxArray *sf_c43_DIPCRT_third_party_uses_info(void);
          plhs[0] = sf_c43_DIPCRT_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_DIPCRT_jit_fallback_info( int nlhs, mxArray * plhs[], int nrhs,
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
        if (strcmp(tpChksum, "bUPsLjjCvipU5rTFlLYueG") == 0) {
          extern mxArray *sf_c1_DIPCRT_jit_fallback_info(void);
          plhs[0] = sf_c1_DIPCRT_jit_fallback_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "nPwsrD05flQdXSPejpr77C") == 0) {
          extern mxArray *sf_c2_DIPCRT_jit_fallback_info(void);
          plhs[0] = sf_c2_DIPCRT_jit_fallback_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "ReLHav6fyDQEmFb2xQ9aqG") == 0) {
          extern mxArray *sf_c3_DIPCRT_jit_fallback_info(void);
          plhs[0] = sf_c3_DIPCRT_jit_fallback_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "Jhsw2VGRgNZzMUENcX5tkG") == 0) {
          extern mxArray *sf_c4_DIPCRT_jit_fallback_info(void);
          plhs[0] = sf_c4_DIPCRT_jit_fallback_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "wKjgDzYGh0AKSV9oCDZhuB") == 0) {
          extern mxArray *sf_c5_DIPCRT_jit_fallback_info(void);
          plhs[0] = sf_c5_DIPCRT_jit_fallback_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "vEneZyO80AXkO3fgcTZVhD") == 0) {
          extern mxArray *sf_c6_DIPCRT_jit_fallback_info(void);
          plhs[0] = sf_c6_DIPCRT_jit_fallback_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "TMlGanmzJMEGBnqyVVJ86E") == 0) {
          extern mxArray *sf_c7_DIPCRT_jit_fallback_info(void);
          plhs[0] = sf_c7_DIPCRT_jit_fallback_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c8_DIPCRT_jit_fallback_info(void);
          plhs[0] = sf_c8_DIPCRT_jit_fallback_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c9_DIPCRT_jit_fallback_info(void);
          plhs[0] = sf_c9_DIPCRT_jit_fallback_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c10_DIPCRT_jit_fallback_info(void);
          plhs[0] = sf_c10_DIPCRT_jit_fallback_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c11_DIPCRT_jit_fallback_info(void);
          plhs[0] = sf_c11_DIPCRT_jit_fallback_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "lvwD6XFKaAPm7OPPKfJroF") == 0) {
          extern mxArray *sf_c12_DIPCRT_jit_fallback_info(void);
          plhs[0] = sf_c12_DIPCRT_jit_fallback_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "j952PgPqb5o1eVDTxUT2GD") == 0) {
          extern mxArray *sf_c13_DIPCRT_jit_fallback_info(void);
          plhs[0] = sf_c13_DIPCRT_jit_fallback_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "lvwD6XFKaAPm7OPPKfJroF") == 0) {
          extern mxArray *sf_c17_DIPCRT_jit_fallback_info(void);
          plhs[0] = sf_c17_DIPCRT_jit_fallback_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "39vboBrh4eZBpQB8o12LJ") == 0) {
          extern mxArray *sf_c18_DIPCRT_jit_fallback_info(void);
          plhs[0] = sf_c18_DIPCRT_jit_fallback_info();
          break;
        }
      }

     case 22:
      {
        if (strcmp(tpChksum, "39vboBrh4eZBpQB8o12LJ") == 0) {
          extern mxArray *sf_c22_DIPCRT_jit_fallback_info(void);
          plhs[0] = sf_c22_DIPCRT_jit_fallback_info();
          break;
        }
      }

     case 23:
      {
        if (strcmp(tpChksum, "39vboBrh4eZBpQB8o12LJ") == 0) {
          extern mxArray *sf_c23_DIPCRT_jit_fallback_info(void);
          plhs[0] = sf_c23_DIPCRT_jit_fallback_info();
          break;
        }
      }

     case 24:
      {
        if (strcmp(tpChksum, "39vboBrh4eZBpQB8o12LJ") == 0) {
          extern mxArray *sf_c24_DIPCRT_jit_fallback_info(void);
          plhs[0] = sf_c24_DIPCRT_jit_fallback_info();
          break;
        }
      }

     case 25:
      {
        if (strcmp(tpChksum, "bgMo300tpt2nma5SeDP5eG") == 0) {
          extern mxArray *sf_c25_DIPCRT_jit_fallback_info(void);
          plhs[0] = sf_c25_DIPCRT_jit_fallback_info();
          break;
        }
      }

     case 26:
      {
        if (strcmp(tpChksum, "Pn0NwQgA7VHB90aenRX2KE") == 0) {
          extern mxArray *sf_c26_DIPCRT_jit_fallback_info(void);
          plhs[0] = sf_c26_DIPCRT_jit_fallback_info();
          break;
        }
      }

     case 27:
      {
        if (strcmp(tpChksum, "OIGfYsR6yVO0itJB6eck0F") == 0) {
          extern mxArray *sf_c27_DIPCRT_jit_fallback_info(void);
          plhs[0] = sf_c27_DIPCRT_jit_fallback_info();
          break;
        }
      }

     case 28:
      {
        if (strcmp(tpChksum, "ezyyAnTcKjd7cyr3PGBSJ") == 0) {
          extern mxArray *sf_c28_DIPCRT_jit_fallback_info(void);
          plhs[0] = sf_c28_DIPCRT_jit_fallback_info();
          break;
        }
      }

     case 29:
      {
        if (strcmp(tpChksum, "F9NaUoFsluwUCMezsgpn1D") == 0) {
          extern mxArray *sf_c29_DIPCRT_jit_fallback_info(void);
          plhs[0] = sf_c29_DIPCRT_jit_fallback_info();
          break;
        }
      }

     case 30:
      {
        if (strcmp(tpChksum, "KoBjyPLZLMM3KD77IWLpFB") == 0) {
          extern mxArray *sf_c30_DIPCRT_jit_fallback_info(void);
          plhs[0] = sf_c30_DIPCRT_jit_fallback_info();
          break;
        }
      }

     case 31:
      {
        if (strcmp(tpChksum, "WuMhkbnscSKHTcaYGq7t0C") == 0) {
          extern mxArray *sf_c31_DIPCRT_jit_fallback_info(void);
          plhs[0] = sf_c31_DIPCRT_jit_fallback_info();
          break;
        }
      }

     case 36:
      {
        if (strcmp(tpChksum, "R5fJ5cX5KyORqPmZdJfjYC") == 0) {
          extern mxArray *sf_c36_DIPCRT_jit_fallback_info(void);
          plhs[0] = sf_c36_DIPCRT_jit_fallback_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "1i3LZAfIaHjMJtsqqRFjjF") == 0) {
          extern mxArray *sf_c37_DIPCRT_jit_fallback_info(void);
          plhs[0] = sf_c37_DIPCRT_jit_fallback_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "IgmYsTd7hWQzxdq1sf59GB") == 0) {
          extern mxArray *sf_c43_DIPCRT_jit_fallback_info(void);
          plhs[0] = sf_c43_DIPCRT_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_DIPCRT_updateBuildInfo_args_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(tpChksum, "bUPsLjjCvipU5rTFlLYueG") == 0) {
          extern mxArray *sf_c1_DIPCRT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_DIPCRT_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "nPwsrD05flQdXSPejpr77C") == 0) {
          extern mxArray *sf_c2_DIPCRT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_DIPCRT_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "ReLHav6fyDQEmFb2xQ9aqG") == 0) {
          extern mxArray *sf_c3_DIPCRT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_DIPCRT_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "Jhsw2VGRgNZzMUENcX5tkG") == 0) {
          extern mxArray *sf_c4_DIPCRT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_DIPCRT_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "wKjgDzYGh0AKSV9oCDZhuB") == 0) {
          extern mxArray *sf_c5_DIPCRT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_DIPCRT_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "vEneZyO80AXkO3fgcTZVhD") == 0) {
          extern mxArray *sf_c6_DIPCRT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_DIPCRT_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "TMlGanmzJMEGBnqyVVJ86E") == 0) {
          extern mxArray *sf_c7_DIPCRT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_DIPCRT_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c8_DIPCRT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_DIPCRT_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c9_DIPCRT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_DIPCRT_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c10_DIPCRT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_DIPCRT_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
          extern mxArray *sf_c11_DIPCRT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_DIPCRT_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "lvwD6XFKaAPm7OPPKfJroF") == 0) {
          extern mxArray *sf_c12_DIPCRT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c12_DIPCRT_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "j952PgPqb5o1eVDTxUT2GD") == 0) {
          extern mxArray *sf_c13_DIPCRT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c13_DIPCRT_updateBuildInfo_args_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "lvwD6XFKaAPm7OPPKfJroF") == 0) {
          extern mxArray *sf_c17_DIPCRT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c17_DIPCRT_updateBuildInfo_args_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "39vboBrh4eZBpQB8o12LJ") == 0) {
          extern mxArray *sf_c18_DIPCRT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c18_DIPCRT_updateBuildInfo_args_info();
          break;
        }
      }

     case 22:
      {
        if (strcmp(tpChksum, "39vboBrh4eZBpQB8o12LJ") == 0) {
          extern mxArray *sf_c22_DIPCRT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c22_DIPCRT_updateBuildInfo_args_info();
          break;
        }
      }

     case 23:
      {
        if (strcmp(tpChksum, "39vboBrh4eZBpQB8o12LJ") == 0) {
          extern mxArray *sf_c23_DIPCRT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c23_DIPCRT_updateBuildInfo_args_info();
          break;
        }
      }

     case 24:
      {
        if (strcmp(tpChksum, "39vboBrh4eZBpQB8o12LJ") == 0) {
          extern mxArray *sf_c24_DIPCRT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c24_DIPCRT_updateBuildInfo_args_info();
          break;
        }
      }

     case 25:
      {
        if (strcmp(tpChksum, "bgMo300tpt2nma5SeDP5eG") == 0) {
          extern mxArray *sf_c25_DIPCRT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c25_DIPCRT_updateBuildInfo_args_info();
          break;
        }
      }

     case 26:
      {
        if (strcmp(tpChksum, "Pn0NwQgA7VHB90aenRX2KE") == 0) {
          extern mxArray *sf_c26_DIPCRT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c26_DIPCRT_updateBuildInfo_args_info();
          break;
        }
      }

     case 27:
      {
        if (strcmp(tpChksum, "OIGfYsR6yVO0itJB6eck0F") == 0) {
          extern mxArray *sf_c27_DIPCRT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c27_DIPCRT_updateBuildInfo_args_info();
          break;
        }
      }

     case 28:
      {
        if (strcmp(tpChksum, "ezyyAnTcKjd7cyr3PGBSJ") == 0) {
          extern mxArray *sf_c28_DIPCRT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c28_DIPCRT_updateBuildInfo_args_info();
          break;
        }
      }

     case 29:
      {
        if (strcmp(tpChksum, "F9NaUoFsluwUCMezsgpn1D") == 0) {
          extern mxArray *sf_c29_DIPCRT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c29_DIPCRT_updateBuildInfo_args_info();
          break;
        }
      }

     case 30:
      {
        if (strcmp(tpChksum, "KoBjyPLZLMM3KD77IWLpFB") == 0) {
          extern mxArray *sf_c30_DIPCRT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c30_DIPCRT_updateBuildInfo_args_info();
          break;
        }
      }

     case 31:
      {
        if (strcmp(tpChksum, "WuMhkbnscSKHTcaYGq7t0C") == 0) {
          extern mxArray *sf_c31_DIPCRT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c31_DIPCRT_updateBuildInfo_args_info();
          break;
        }
      }

     case 36:
      {
        if (strcmp(tpChksum, "R5fJ5cX5KyORqPmZdJfjYC") == 0) {
          extern mxArray *sf_c36_DIPCRT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c36_DIPCRT_updateBuildInfo_args_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "1i3LZAfIaHjMJtsqqRFjjF") == 0) {
          extern mxArray *sf_c37_DIPCRT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c37_DIPCRT_updateBuildInfo_args_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "IgmYsTd7hWQzxdq1sf59GB") == 0) {
          extern mxArray *sf_c43_DIPCRT_updateBuildInfo_args_info(void);
          plhs[0] = sf_c43_DIPCRT_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void sf_DIPCRT_get_post_codegen_info( int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[] )
{
  unsigned int chartFileNumber = (unsigned int) mxGetScalar(prhs[0]);
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  switch (chartFileNumber) {
   case 1:
    {
      if (strcmp(tpChksum, "bUPsLjjCvipU5rTFlLYueG") == 0) {
        extern mxArray *sf_c1_DIPCRT_get_post_codegen_info(void);
        plhs[0] = sf_c1_DIPCRT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 2:
    {
      if (strcmp(tpChksum, "nPwsrD05flQdXSPejpr77C") == 0) {
        extern mxArray *sf_c2_DIPCRT_get_post_codegen_info(void);
        plhs[0] = sf_c2_DIPCRT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 3:
    {
      if (strcmp(tpChksum, "ReLHav6fyDQEmFb2xQ9aqG") == 0) {
        extern mxArray *sf_c3_DIPCRT_get_post_codegen_info(void);
        plhs[0] = sf_c3_DIPCRT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 4:
    {
      if (strcmp(tpChksum, "Jhsw2VGRgNZzMUENcX5tkG") == 0) {
        extern mxArray *sf_c4_DIPCRT_get_post_codegen_info(void);
        plhs[0] = sf_c4_DIPCRT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 5:
    {
      if (strcmp(tpChksum, "wKjgDzYGh0AKSV9oCDZhuB") == 0) {
        extern mxArray *sf_c5_DIPCRT_get_post_codegen_info(void);
        plhs[0] = sf_c5_DIPCRT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 6:
    {
      if (strcmp(tpChksum, "vEneZyO80AXkO3fgcTZVhD") == 0) {
        extern mxArray *sf_c6_DIPCRT_get_post_codegen_info(void);
        plhs[0] = sf_c6_DIPCRT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 7:
    {
      if (strcmp(tpChksum, "TMlGanmzJMEGBnqyVVJ86E") == 0) {
        extern mxArray *sf_c7_DIPCRT_get_post_codegen_info(void);
        plhs[0] = sf_c7_DIPCRT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 8:
    {
      if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
        extern mxArray *sf_c8_DIPCRT_get_post_codegen_info(void);
        plhs[0] = sf_c8_DIPCRT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 9:
    {
      if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
        extern mxArray *sf_c9_DIPCRT_get_post_codegen_info(void);
        plhs[0] = sf_c9_DIPCRT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 10:
    {
      if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
        extern mxArray *sf_c10_DIPCRT_get_post_codegen_info(void);
        plhs[0] = sf_c10_DIPCRT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 11:
    {
      if (strcmp(tpChksum, "7jouFwfpcV1KQiNWYMQy7G") == 0) {
        extern mxArray *sf_c11_DIPCRT_get_post_codegen_info(void);
        plhs[0] = sf_c11_DIPCRT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 12:
    {
      if (strcmp(tpChksum, "lvwD6XFKaAPm7OPPKfJroF") == 0) {
        extern mxArray *sf_c12_DIPCRT_get_post_codegen_info(void);
        plhs[0] = sf_c12_DIPCRT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 13:
    {
      if (strcmp(tpChksum, "j952PgPqb5o1eVDTxUT2GD") == 0) {
        extern mxArray *sf_c13_DIPCRT_get_post_codegen_info(void);
        plhs[0] = sf_c13_DIPCRT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 17:
    {
      if (strcmp(tpChksum, "lvwD6XFKaAPm7OPPKfJroF") == 0) {
        extern mxArray *sf_c17_DIPCRT_get_post_codegen_info(void);
        plhs[0] = sf_c17_DIPCRT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 18:
    {
      if (strcmp(tpChksum, "39vboBrh4eZBpQB8o12LJ") == 0) {
        extern mxArray *sf_c18_DIPCRT_get_post_codegen_info(void);
        plhs[0] = sf_c18_DIPCRT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 22:
    {
      if (strcmp(tpChksum, "39vboBrh4eZBpQB8o12LJ") == 0) {
        extern mxArray *sf_c22_DIPCRT_get_post_codegen_info(void);
        plhs[0] = sf_c22_DIPCRT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 23:
    {
      if (strcmp(tpChksum, "39vboBrh4eZBpQB8o12LJ") == 0) {
        extern mxArray *sf_c23_DIPCRT_get_post_codegen_info(void);
        plhs[0] = sf_c23_DIPCRT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 24:
    {
      if (strcmp(tpChksum, "39vboBrh4eZBpQB8o12LJ") == 0) {
        extern mxArray *sf_c24_DIPCRT_get_post_codegen_info(void);
        plhs[0] = sf_c24_DIPCRT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 25:
    {
      if (strcmp(tpChksum, "bgMo300tpt2nma5SeDP5eG") == 0) {
        extern mxArray *sf_c25_DIPCRT_get_post_codegen_info(void);
        plhs[0] = sf_c25_DIPCRT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 26:
    {
      if (strcmp(tpChksum, "Pn0NwQgA7VHB90aenRX2KE") == 0) {
        extern mxArray *sf_c26_DIPCRT_get_post_codegen_info(void);
        plhs[0] = sf_c26_DIPCRT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 27:
    {
      if (strcmp(tpChksum, "OIGfYsR6yVO0itJB6eck0F") == 0) {
        extern mxArray *sf_c27_DIPCRT_get_post_codegen_info(void);
        plhs[0] = sf_c27_DIPCRT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 28:
    {
      if (strcmp(tpChksum, "ezyyAnTcKjd7cyr3PGBSJ") == 0) {
        extern mxArray *sf_c28_DIPCRT_get_post_codegen_info(void);
        plhs[0] = sf_c28_DIPCRT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 29:
    {
      if (strcmp(tpChksum, "F9NaUoFsluwUCMezsgpn1D") == 0) {
        extern mxArray *sf_c29_DIPCRT_get_post_codegen_info(void);
        plhs[0] = sf_c29_DIPCRT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 30:
    {
      if (strcmp(tpChksum, "KoBjyPLZLMM3KD77IWLpFB") == 0) {
        extern mxArray *sf_c30_DIPCRT_get_post_codegen_info(void);
        plhs[0] = sf_c30_DIPCRT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 31:
    {
      if (strcmp(tpChksum, "WuMhkbnscSKHTcaYGq7t0C") == 0) {
        extern mxArray *sf_c31_DIPCRT_get_post_codegen_info(void);
        plhs[0] = sf_c31_DIPCRT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 36:
    {
      if (strcmp(tpChksum, "R5fJ5cX5KyORqPmZdJfjYC") == 0) {
        extern mxArray *sf_c36_DIPCRT_get_post_codegen_info(void);
        plhs[0] = sf_c36_DIPCRT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 37:
    {
      if (strcmp(tpChksum, "1i3LZAfIaHjMJtsqqRFjjF") == 0) {
        extern mxArray *sf_c37_DIPCRT_get_post_codegen_info(void);
        plhs[0] = sf_c37_DIPCRT_get_post_codegen_info();
        return;
      }
    }
    break;

   case 43:
    {
      if (strcmp(tpChksum, "IgmYsTd7hWQzxdq1sf59GB") == 0) {
        extern mxArray *sf_c43_DIPCRT_get_post_codegen_info(void);
        plhs[0] = sf_c43_DIPCRT_get_post_codegen_info();
        return;
      }
    }
    break;

   default:
    break;
  }

  plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
}

void DIPCRT_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _DIPCRTMachineNumber_ = sf_debug_initialize_machine(debugInstance,"DIPCRT",
    "sfun",0,28,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,_DIPCRTMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,_DIPCRTMachineNumber_,0);
}

void DIPCRT_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_DIPCRT_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("DIPCRT",
      "DIPCRT");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_DIPCRT_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}

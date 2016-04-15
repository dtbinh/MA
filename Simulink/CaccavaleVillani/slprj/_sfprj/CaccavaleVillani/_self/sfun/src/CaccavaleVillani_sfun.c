/* Include files */

#include "CaccavaleVillani_sfun.h"
#include "CaccavaleVillani_sfun_debug_macros.h"
#include "c1_CaccavaleVillani.h"
#include "c2_CaccavaleVillani.h"
#include "c3_CaccavaleVillani.h"
#include "c4_CaccavaleVillani.h"
#include "c5_CaccavaleVillani.h"
#include "c6_CaccavaleVillani.h"
#include "c7_CaccavaleVillani.h"
#include "c8_CaccavaleVillani.h"
#include "c9_CaccavaleVillani.h"
#include "c10_CaccavaleVillani.h"
#include "c12_CaccavaleVillani.h"
#include "c13_CaccavaleVillani.h"
#include "c14_CaccavaleVillani.h"
#include "c15_CaccavaleVillani.h"
#include "c21_CaccavaleVillani.h"
#include "c22_CaccavaleVillani.h"
#include "c23_CaccavaleVillani.h"
#include "c26_CaccavaleVillani.h"
#include "c30_CaccavaleVillani.h"
#include "c31_CaccavaleVillani.h"
#include "c36_CaccavaleVillani.h"
#include "c37_CaccavaleVillani.h"
#include "c43_CaccavaleVillani.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _CaccavaleVillaniMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void CaccavaleVillani_initializer(void)
{
}

void CaccavaleVillani_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_CaccavaleVillani_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_CaccavaleVillani_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_CaccavaleVillani_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_CaccavaleVillani_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_CaccavaleVillani_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_CaccavaleVillani_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_CaccavaleVillani_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_CaccavaleVillani_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_CaccavaleVillani_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_CaccavaleVillani_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_CaccavaleVillani_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_CaccavaleVillani_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_CaccavaleVillani_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_CaccavaleVillani_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_CaccavaleVillani_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==21) {
    c21_CaccavaleVillani_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==22) {
    c22_CaccavaleVillani_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==23) {
    c23_CaccavaleVillani_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==26) {
    c26_CaccavaleVillani_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==30) {
    c30_CaccavaleVillani_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==31) {
    c31_CaccavaleVillani_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==36) {
    c36_CaccavaleVillani_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==37) {
    c37_CaccavaleVillani_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==43) {
    c43_CaccavaleVillani_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

extern void sf_CaccavaleVillani_uses_exported_functions(int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[])
{
  plhs[0] = mxCreateLogicalScalar(0);
}

unsigned int sf_CaccavaleVillani_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1822056976U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4054071164U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(938026193U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4066706818U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2319694829U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2442040751U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(691316859U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1681354839U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_CaccavaleVillani_get_check_sum(mxArray *plhs[]);
          sf_c1_CaccavaleVillani_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_CaccavaleVillani_get_check_sum(mxArray *plhs[]);
          sf_c2_CaccavaleVillani_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_CaccavaleVillani_get_check_sum(mxArray *plhs[]);
          sf_c3_CaccavaleVillani_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_CaccavaleVillani_get_check_sum(mxArray *plhs[]);
          sf_c4_CaccavaleVillani_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_CaccavaleVillani_get_check_sum(mxArray *plhs[]);
          sf_c5_CaccavaleVillani_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_CaccavaleVillani_get_check_sum(mxArray *plhs[]);
          sf_c6_CaccavaleVillani_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_CaccavaleVillani_get_check_sum(mxArray *plhs[]);
          sf_c7_CaccavaleVillani_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_CaccavaleVillani_get_check_sum(mxArray *plhs[]);
          sf_c8_CaccavaleVillani_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_CaccavaleVillani_get_check_sum(mxArray *plhs[]);
          sf_c9_CaccavaleVillani_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_CaccavaleVillani_get_check_sum(mxArray *plhs[]);
          sf_c10_CaccavaleVillani_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_CaccavaleVillani_get_check_sum(mxArray *plhs[]);
          sf_c12_CaccavaleVillani_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_CaccavaleVillani_get_check_sum(mxArray *plhs[]);
          sf_c13_CaccavaleVillani_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_CaccavaleVillani_get_check_sum(mxArray *plhs[]);
          sf_c14_CaccavaleVillani_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_CaccavaleVillani_get_check_sum(mxArray *plhs[]);
          sf_c15_CaccavaleVillani_get_check_sum(plhs);
          break;
        }

       case 21:
        {
          extern void sf_c21_CaccavaleVillani_get_check_sum(mxArray *plhs[]);
          sf_c21_CaccavaleVillani_get_check_sum(plhs);
          break;
        }

       case 22:
        {
          extern void sf_c22_CaccavaleVillani_get_check_sum(mxArray *plhs[]);
          sf_c22_CaccavaleVillani_get_check_sum(plhs);
          break;
        }

       case 23:
        {
          extern void sf_c23_CaccavaleVillani_get_check_sum(mxArray *plhs[]);
          sf_c23_CaccavaleVillani_get_check_sum(plhs);
          break;
        }

       case 26:
        {
          extern void sf_c26_CaccavaleVillani_get_check_sum(mxArray *plhs[]);
          sf_c26_CaccavaleVillani_get_check_sum(plhs);
          break;
        }

       case 30:
        {
          extern void sf_c30_CaccavaleVillani_get_check_sum(mxArray *plhs[]);
          sf_c30_CaccavaleVillani_get_check_sum(plhs);
          break;
        }

       case 31:
        {
          extern void sf_c31_CaccavaleVillani_get_check_sum(mxArray *plhs[]);
          sf_c31_CaccavaleVillani_get_check_sum(plhs);
          break;
        }

       case 36:
        {
          extern void sf_c36_CaccavaleVillani_get_check_sum(mxArray *plhs[]);
          sf_c36_CaccavaleVillani_get_check_sum(plhs);
          break;
        }

       case 37:
        {
          extern void sf_c37_CaccavaleVillani_get_check_sum(mxArray *plhs[]);
          sf_c37_CaccavaleVillani_get_check_sum(plhs);
          break;
        }

       case 43:
        {
          extern void sf_c43_CaccavaleVillani_get_check_sum(mxArray *plhs[]);
          sf_c43_CaccavaleVillani_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3917959082U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(363334786U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1778137462U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(636796729U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_CaccavaleVillani_autoinheritance_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(aiChksum, "UeXOmgO59tnOMk5OEUHxjC") == 0) {
          extern mxArray *sf_c1_CaccavaleVillani_get_autoinheritance_info(void);
          plhs[0] = sf_c1_CaccavaleVillani_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "AnHgEYn4GqN58Ou45jAlm") == 0) {
          extern mxArray *sf_c2_CaccavaleVillani_get_autoinheritance_info(void);
          plhs[0] = sf_c2_CaccavaleVillani_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "a9eZw9WaZcxJ1wV8vE3r6F") == 0) {
          extern mxArray *sf_c3_CaccavaleVillani_get_autoinheritance_info(void);
          plhs[0] = sf_c3_CaccavaleVillani_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "6IoyVO9gMvpmuJbt757thD") == 0) {
          extern mxArray *sf_c4_CaccavaleVillani_get_autoinheritance_info(void);
          plhs[0] = sf_c4_CaccavaleVillani_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "tna1BcwMvoe2fRwT2pfL9E") == 0) {
          extern mxArray *sf_c5_CaccavaleVillani_get_autoinheritance_info(void);
          plhs[0] = sf_c5_CaccavaleVillani_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "MNIWBbuNFTZjpPbKWaFHcH") == 0) {
          extern mxArray *sf_c6_CaccavaleVillani_get_autoinheritance_info(void);
          plhs[0] = sf_c6_CaccavaleVillani_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "tYATzzCrS6feeZiFtybCl") == 0) {
          extern mxArray *sf_c7_CaccavaleVillani_get_autoinheritance_info(void);
          plhs[0] = sf_c7_CaccavaleVillani_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "PZUjTVaGjUj6LwtPaOJE7D") == 0) {
          extern mxArray *sf_c8_CaccavaleVillani_get_autoinheritance_info(void);
          plhs[0] = sf_c8_CaccavaleVillani_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "PZUjTVaGjUj6LwtPaOJE7D") == 0) {
          extern mxArray *sf_c9_CaccavaleVillani_get_autoinheritance_info(void);
          plhs[0] = sf_c9_CaccavaleVillani_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "PZUjTVaGjUj6LwtPaOJE7D") == 0) {
          extern mxArray *sf_c10_CaccavaleVillani_get_autoinheritance_info(void);
          plhs[0] = sf_c10_CaccavaleVillani_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "PydXxTZ25DlHqcdKniJvGH") == 0) {
          extern mxArray *sf_c12_CaccavaleVillani_get_autoinheritance_info(void);
          plhs[0] = sf_c12_CaccavaleVillani_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "NZGt4hui16RErDsZaLrtMD") == 0) {
          extern mxArray *sf_c13_CaccavaleVillani_get_autoinheritance_info(void);
          plhs[0] = sf_c13_CaccavaleVillani_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 14:
      {
        if (strcmp(aiChksum, "lpDXXC9dMqzlo3kVn9HLWB") == 0) {
          extern mxArray *sf_c14_CaccavaleVillani_get_autoinheritance_info(void);
          plhs[0] = sf_c14_CaccavaleVillani_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "j0bVmXlZXPFmEhVmxG8dUF") == 0) {
          extern mxArray *sf_c15_CaccavaleVillani_get_autoinheritance_info(void);
          plhs[0] = sf_c15_CaccavaleVillani_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 21:
      {
        if (strcmp(aiChksum, "AnHgEYn4GqN58Ou45jAlm") == 0) {
          extern mxArray *sf_c21_CaccavaleVillani_get_autoinheritance_info(void);
          plhs[0] = sf_c21_CaccavaleVillani_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 22:
      {
        if (strcmp(aiChksum, "j9maIqGCXDgdd4rsMwtlXF") == 0) {
          extern mxArray *sf_c22_CaccavaleVillani_get_autoinheritance_info(void);
          plhs[0] = sf_c22_CaccavaleVillani_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 23:
      {
        if (strcmp(aiChksum, "80WuLHrBhd7ls727YHiC3D") == 0) {
          extern mxArray *sf_c23_CaccavaleVillani_get_autoinheritance_info(void);
          plhs[0] = sf_c23_CaccavaleVillani_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 26:
      {
        if (strcmp(aiChksum, "PZUjTVaGjUj6LwtPaOJE7D") == 0) {
          extern mxArray *sf_c26_CaccavaleVillani_get_autoinheritance_info(void);
          plhs[0] = sf_c26_CaccavaleVillani_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 30:
      {
        if (strcmp(aiChksum, "6IoyVO9gMvpmuJbt757thD") == 0) {
          extern mxArray *sf_c30_CaccavaleVillani_get_autoinheritance_info(void);
          plhs[0] = sf_c30_CaccavaleVillani_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 31:
      {
        if (strcmp(aiChksum, "hsoK28yDSgt1aAj8beAQjG") == 0) {
          extern mxArray *sf_c31_CaccavaleVillani_get_autoinheritance_info(void);
          plhs[0] = sf_c31_CaccavaleVillani_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 36:
      {
        if (strcmp(aiChksum, "DD1R3ViA8FSKbVm79jLUZ") == 0) {
          extern mxArray *sf_c36_CaccavaleVillani_get_autoinheritance_info(void);
          plhs[0] = sf_c36_CaccavaleVillani_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 37:
      {
        if (strcmp(aiChksum, "HH5Q7NBdD7VBwfWldwVT5F") == 0) {
          extern mxArray *sf_c37_CaccavaleVillani_get_autoinheritance_info(void);
          plhs[0] = sf_c37_CaccavaleVillani_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 43:
      {
        if (strcmp(aiChksum, "aBAN3OqxekCRqIEyfPDBXC") == 0) {
          extern mxArray *sf_c43_CaccavaleVillani_get_autoinheritance_info(void);
          plhs[0] = sf_c43_CaccavaleVillani_get_autoinheritance_info();
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

unsigned int sf_CaccavaleVillani_get_eml_resolved_functions_info( int nlhs,
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
          *sf_c1_CaccavaleVillani_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_CaccavaleVillani_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_CaccavaleVillani_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_CaccavaleVillani_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_CaccavaleVillani_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_CaccavaleVillani_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_CaccavaleVillani_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_CaccavaleVillani_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_CaccavaleVillani_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_CaccavaleVillani_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_CaccavaleVillani_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_CaccavaleVillani_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_CaccavaleVillani_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_CaccavaleVillani_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_CaccavaleVillani_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_CaccavaleVillani_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_CaccavaleVillani_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_CaccavaleVillani_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_CaccavaleVillani_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_CaccavaleVillani_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_CaccavaleVillani_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_CaccavaleVillani_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_CaccavaleVillani_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_CaccavaleVillani_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray
          *sf_c14_CaccavaleVillani_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_CaccavaleVillani_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray
          *sf_c15_CaccavaleVillani_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_CaccavaleVillani_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 21:
      {
        extern const mxArray
          *sf_c21_CaccavaleVillani_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c21_CaccavaleVillani_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 22:
      {
        extern const mxArray
          *sf_c22_CaccavaleVillani_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c22_CaccavaleVillani_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 23:
      {
        extern const mxArray
          *sf_c23_CaccavaleVillani_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c23_CaccavaleVillani_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 26:
      {
        extern const mxArray
          *sf_c26_CaccavaleVillani_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c26_CaccavaleVillani_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 30:
      {
        extern const mxArray
          *sf_c30_CaccavaleVillani_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c30_CaccavaleVillani_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 31:
      {
        extern const mxArray
          *sf_c31_CaccavaleVillani_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c31_CaccavaleVillani_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 36:
      {
        extern const mxArray
          *sf_c36_CaccavaleVillani_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c36_CaccavaleVillani_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 37:
      {
        extern const mxArray
          *sf_c37_CaccavaleVillani_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c37_CaccavaleVillani_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 43:
      {
        extern const mxArray
          *sf_c43_CaccavaleVillani_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c43_CaccavaleVillani_get_eml_resolved_functions_info();
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

unsigned int sf_CaccavaleVillani_third_party_uses_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
        if (strcmp(tpChksum, "LcJGH7EzT1bzyUNbKdlgO") == 0) {
          extern mxArray *sf_c1_CaccavaleVillani_third_party_uses_info(void);
          plhs[0] = sf_c1_CaccavaleVillani_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "MHUdxILrigSlPOTxkOrUKB") == 0) {
          extern mxArray *sf_c2_CaccavaleVillani_third_party_uses_info(void);
          plhs[0] = sf_c2_CaccavaleVillani_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "nhzpxLEEBZdUjFWNKEZizD") == 0) {
          extern mxArray *sf_c3_CaccavaleVillani_third_party_uses_info(void);
          plhs[0] = sf_c3_CaccavaleVillani_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "036YtO1VMUEZiQPGl0NGXG") == 0) {
          extern mxArray *sf_c4_CaccavaleVillani_third_party_uses_info(void);
          plhs[0] = sf_c4_CaccavaleVillani_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "wKjgDzYGh0AKSV9oCDZhuB") == 0) {
          extern mxArray *sf_c5_CaccavaleVillani_third_party_uses_info(void);
          plhs[0] = sf_c5_CaccavaleVillani_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "vEneZyO80AXkO3fgcTZVhD") == 0) {
          extern mxArray *sf_c6_CaccavaleVillani_third_party_uses_info(void);
          plhs[0] = sf_c6_CaccavaleVillani_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "TMlGanmzJMEGBnqyVVJ86E") == 0) {
          extern mxArray *sf_c7_CaccavaleVillani_third_party_uses_info(void);
          plhs[0] = sf_c7_CaccavaleVillani_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "4pxzcfVpVz6mRboTpKMvmB") == 0) {
          extern mxArray *sf_c8_CaccavaleVillani_third_party_uses_info(void);
          plhs[0] = sf_c8_CaccavaleVillani_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "4pxzcfVpVz6mRboTpKMvmB") == 0) {
          extern mxArray *sf_c9_CaccavaleVillani_third_party_uses_info(void);
          plhs[0] = sf_c9_CaccavaleVillani_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "4pxzcfVpVz6mRboTpKMvmB") == 0) {
          extern mxArray *sf_c10_CaccavaleVillani_third_party_uses_info(void);
          plhs[0] = sf_c10_CaccavaleVillani_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "bgMo300tpt2nma5SeDP5eG") == 0) {
          extern mxArray *sf_c12_CaccavaleVillani_third_party_uses_info(void);
          plhs[0] = sf_c12_CaccavaleVillani_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "Pn0NwQgA7VHB90aenRX2KE") == 0) {
          extern mxArray *sf_c13_CaccavaleVillani_third_party_uses_info(void);
          plhs[0] = sf_c13_CaccavaleVillani_third_party_uses_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "ezyyAnTcKjd7cyr3PGBSJ") == 0) {
          extern mxArray *sf_c14_CaccavaleVillani_third_party_uses_info(void);
          plhs[0] = sf_c14_CaccavaleVillani_third_party_uses_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "F9NaUoFsluwUCMezsgpn1D") == 0) {
          extern mxArray *sf_c15_CaccavaleVillani_third_party_uses_info(void);
          plhs[0] = sf_c15_CaccavaleVillani_third_party_uses_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "MHUdxILrigSlPOTxkOrUKB") == 0) {
          extern mxArray *sf_c21_CaccavaleVillani_third_party_uses_info(void);
          plhs[0] = sf_c21_CaccavaleVillani_third_party_uses_info();
          break;
        }
      }

     case 22:
      {
        if (strcmp(tpChksum, "DpTkc1bOHKC86DQmcFu5WB") == 0) {
          extern mxArray *sf_c22_CaccavaleVillani_third_party_uses_info(void);
          plhs[0] = sf_c22_CaccavaleVillani_third_party_uses_info();
          break;
        }
      }

     case 23:
      {
        if (strcmp(tpChksum, "IL1sQQ4H503LMjzcboLygF") == 0) {
          extern mxArray *sf_c23_CaccavaleVillani_third_party_uses_info(void);
          plhs[0] = sf_c23_CaccavaleVillani_third_party_uses_info();
          break;
        }
      }

     case 26:
      {
        if (strcmp(tpChksum, "4pxzcfVpVz6mRboTpKMvmB") == 0) {
          extern mxArray *sf_c26_CaccavaleVillani_third_party_uses_info(void);
          plhs[0] = sf_c26_CaccavaleVillani_third_party_uses_info();
          break;
        }
      }

     case 30:
      {
        if (strcmp(tpChksum, "036YtO1VMUEZiQPGl0NGXG") == 0) {
          extern mxArray *sf_c30_CaccavaleVillani_third_party_uses_info(void);
          plhs[0] = sf_c30_CaccavaleVillani_third_party_uses_info();
          break;
        }
      }

     case 31:
      {
        if (strcmp(tpChksum, "dZWQ3fDfJ3SbBdRH1PhKx") == 0) {
          extern mxArray *sf_c31_CaccavaleVillani_third_party_uses_info(void);
          plhs[0] = sf_c31_CaccavaleVillani_third_party_uses_info();
          break;
        }
      }

     case 36:
      {
        if (strcmp(tpChksum, "R5fJ5cX5KyORqPmZdJfjYC") == 0) {
          extern mxArray *sf_c36_CaccavaleVillani_third_party_uses_info(void);
          plhs[0] = sf_c36_CaccavaleVillani_third_party_uses_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "1i3LZAfIaHjMJtsqqRFjjF") == 0) {
          extern mxArray *sf_c37_CaccavaleVillani_third_party_uses_info(void);
          plhs[0] = sf_c37_CaccavaleVillani_third_party_uses_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "IgmYsTd7hWQzxdq1sf59GB") == 0) {
          extern mxArray *sf_c43_CaccavaleVillani_third_party_uses_info(void);
          plhs[0] = sf_c43_CaccavaleVillani_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_CaccavaleVillani_jit_fallback_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(tpChksum, "LcJGH7EzT1bzyUNbKdlgO") == 0) {
          extern mxArray *sf_c1_CaccavaleVillani_jit_fallback_info(void);
          plhs[0] = sf_c1_CaccavaleVillani_jit_fallback_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "MHUdxILrigSlPOTxkOrUKB") == 0) {
          extern mxArray *sf_c2_CaccavaleVillani_jit_fallback_info(void);
          plhs[0] = sf_c2_CaccavaleVillani_jit_fallback_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "nhzpxLEEBZdUjFWNKEZizD") == 0) {
          extern mxArray *sf_c3_CaccavaleVillani_jit_fallback_info(void);
          plhs[0] = sf_c3_CaccavaleVillani_jit_fallback_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "036YtO1VMUEZiQPGl0NGXG") == 0) {
          extern mxArray *sf_c4_CaccavaleVillani_jit_fallback_info(void);
          plhs[0] = sf_c4_CaccavaleVillani_jit_fallback_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "wKjgDzYGh0AKSV9oCDZhuB") == 0) {
          extern mxArray *sf_c5_CaccavaleVillani_jit_fallback_info(void);
          plhs[0] = sf_c5_CaccavaleVillani_jit_fallback_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "vEneZyO80AXkO3fgcTZVhD") == 0) {
          extern mxArray *sf_c6_CaccavaleVillani_jit_fallback_info(void);
          plhs[0] = sf_c6_CaccavaleVillani_jit_fallback_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "TMlGanmzJMEGBnqyVVJ86E") == 0) {
          extern mxArray *sf_c7_CaccavaleVillani_jit_fallback_info(void);
          plhs[0] = sf_c7_CaccavaleVillani_jit_fallback_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "4pxzcfVpVz6mRboTpKMvmB") == 0) {
          extern mxArray *sf_c8_CaccavaleVillani_jit_fallback_info(void);
          plhs[0] = sf_c8_CaccavaleVillani_jit_fallback_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "4pxzcfVpVz6mRboTpKMvmB") == 0) {
          extern mxArray *sf_c9_CaccavaleVillani_jit_fallback_info(void);
          plhs[0] = sf_c9_CaccavaleVillani_jit_fallback_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "4pxzcfVpVz6mRboTpKMvmB") == 0) {
          extern mxArray *sf_c10_CaccavaleVillani_jit_fallback_info(void);
          plhs[0] = sf_c10_CaccavaleVillani_jit_fallback_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "bgMo300tpt2nma5SeDP5eG") == 0) {
          extern mxArray *sf_c12_CaccavaleVillani_jit_fallback_info(void);
          plhs[0] = sf_c12_CaccavaleVillani_jit_fallback_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "Pn0NwQgA7VHB90aenRX2KE") == 0) {
          extern mxArray *sf_c13_CaccavaleVillani_jit_fallback_info(void);
          plhs[0] = sf_c13_CaccavaleVillani_jit_fallback_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "ezyyAnTcKjd7cyr3PGBSJ") == 0) {
          extern mxArray *sf_c14_CaccavaleVillani_jit_fallback_info(void);
          plhs[0] = sf_c14_CaccavaleVillani_jit_fallback_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "F9NaUoFsluwUCMezsgpn1D") == 0) {
          extern mxArray *sf_c15_CaccavaleVillani_jit_fallback_info(void);
          plhs[0] = sf_c15_CaccavaleVillani_jit_fallback_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "MHUdxILrigSlPOTxkOrUKB") == 0) {
          extern mxArray *sf_c21_CaccavaleVillani_jit_fallback_info(void);
          plhs[0] = sf_c21_CaccavaleVillani_jit_fallback_info();
          break;
        }
      }

     case 22:
      {
        if (strcmp(tpChksum, "DpTkc1bOHKC86DQmcFu5WB") == 0) {
          extern mxArray *sf_c22_CaccavaleVillani_jit_fallback_info(void);
          plhs[0] = sf_c22_CaccavaleVillani_jit_fallback_info();
          break;
        }
      }

     case 23:
      {
        if (strcmp(tpChksum, "IL1sQQ4H503LMjzcboLygF") == 0) {
          extern mxArray *sf_c23_CaccavaleVillani_jit_fallback_info(void);
          plhs[0] = sf_c23_CaccavaleVillani_jit_fallback_info();
          break;
        }
      }

     case 26:
      {
        if (strcmp(tpChksum, "4pxzcfVpVz6mRboTpKMvmB") == 0) {
          extern mxArray *sf_c26_CaccavaleVillani_jit_fallback_info(void);
          plhs[0] = sf_c26_CaccavaleVillani_jit_fallback_info();
          break;
        }
      }

     case 30:
      {
        if (strcmp(tpChksum, "036YtO1VMUEZiQPGl0NGXG") == 0) {
          extern mxArray *sf_c30_CaccavaleVillani_jit_fallback_info(void);
          plhs[0] = sf_c30_CaccavaleVillani_jit_fallback_info();
          break;
        }
      }

     case 31:
      {
        if (strcmp(tpChksum, "dZWQ3fDfJ3SbBdRH1PhKx") == 0) {
          extern mxArray *sf_c31_CaccavaleVillani_jit_fallback_info(void);
          plhs[0] = sf_c31_CaccavaleVillani_jit_fallback_info();
          break;
        }
      }

     case 36:
      {
        if (strcmp(tpChksum, "R5fJ5cX5KyORqPmZdJfjYC") == 0) {
          extern mxArray *sf_c36_CaccavaleVillani_jit_fallback_info(void);
          plhs[0] = sf_c36_CaccavaleVillani_jit_fallback_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "1i3LZAfIaHjMJtsqqRFjjF") == 0) {
          extern mxArray *sf_c37_CaccavaleVillani_jit_fallback_info(void);
          plhs[0] = sf_c37_CaccavaleVillani_jit_fallback_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "IgmYsTd7hWQzxdq1sf59GB") == 0) {
          extern mxArray *sf_c43_CaccavaleVillani_jit_fallback_info(void);
          plhs[0] = sf_c43_CaccavaleVillani_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_CaccavaleVillani_updateBuildInfo_args_info( int nlhs, mxArray *
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
        if (strcmp(tpChksum, "LcJGH7EzT1bzyUNbKdlgO") == 0) {
          extern mxArray *sf_c1_CaccavaleVillani_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_CaccavaleVillani_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "MHUdxILrigSlPOTxkOrUKB") == 0) {
          extern mxArray *sf_c2_CaccavaleVillani_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_CaccavaleVillani_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "nhzpxLEEBZdUjFWNKEZizD") == 0) {
          extern mxArray *sf_c3_CaccavaleVillani_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_CaccavaleVillani_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "036YtO1VMUEZiQPGl0NGXG") == 0) {
          extern mxArray *sf_c4_CaccavaleVillani_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_CaccavaleVillani_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "wKjgDzYGh0AKSV9oCDZhuB") == 0) {
          extern mxArray *sf_c5_CaccavaleVillani_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_CaccavaleVillani_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "vEneZyO80AXkO3fgcTZVhD") == 0) {
          extern mxArray *sf_c6_CaccavaleVillani_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_CaccavaleVillani_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "TMlGanmzJMEGBnqyVVJ86E") == 0) {
          extern mxArray *sf_c7_CaccavaleVillani_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_CaccavaleVillani_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "4pxzcfVpVz6mRboTpKMvmB") == 0) {
          extern mxArray *sf_c8_CaccavaleVillani_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_CaccavaleVillani_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "4pxzcfVpVz6mRboTpKMvmB") == 0) {
          extern mxArray *sf_c9_CaccavaleVillani_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_CaccavaleVillani_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "4pxzcfVpVz6mRboTpKMvmB") == 0) {
          extern mxArray *sf_c10_CaccavaleVillani_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_CaccavaleVillani_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "bgMo300tpt2nma5SeDP5eG") == 0) {
          extern mxArray *sf_c12_CaccavaleVillani_updateBuildInfo_args_info(void);
          plhs[0] = sf_c12_CaccavaleVillani_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "Pn0NwQgA7VHB90aenRX2KE") == 0) {
          extern mxArray *sf_c13_CaccavaleVillani_updateBuildInfo_args_info(void);
          plhs[0] = sf_c13_CaccavaleVillani_updateBuildInfo_args_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "ezyyAnTcKjd7cyr3PGBSJ") == 0) {
          extern mxArray *sf_c14_CaccavaleVillani_updateBuildInfo_args_info(void);
          plhs[0] = sf_c14_CaccavaleVillani_updateBuildInfo_args_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "F9NaUoFsluwUCMezsgpn1D") == 0) {
          extern mxArray *sf_c15_CaccavaleVillani_updateBuildInfo_args_info(void);
          plhs[0] = sf_c15_CaccavaleVillani_updateBuildInfo_args_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "MHUdxILrigSlPOTxkOrUKB") == 0) {
          extern mxArray *sf_c21_CaccavaleVillani_updateBuildInfo_args_info(void);
          plhs[0] = sf_c21_CaccavaleVillani_updateBuildInfo_args_info();
          break;
        }
      }

     case 22:
      {
        if (strcmp(tpChksum, "DpTkc1bOHKC86DQmcFu5WB") == 0) {
          extern mxArray *sf_c22_CaccavaleVillani_updateBuildInfo_args_info(void);
          plhs[0] = sf_c22_CaccavaleVillani_updateBuildInfo_args_info();
          break;
        }
      }

     case 23:
      {
        if (strcmp(tpChksum, "IL1sQQ4H503LMjzcboLygF") == 0) {
          extern mxArray *sf_c23_CaccavaleVillani_updateBuildInfo_args_info(void);
          plhs[0] = sf_c23_CaccavaleVillani_updateBuildInfo_args_info();
          break;
        }
      }

     case 26:
      {
        if (strcmp(tpChksum, "4pxzcfVpVz6mRboTpKMvmB") == 0) {
          extern mxArray *sf_c26_CaccavaleVillani_updateBuildInfo_args_info(void);
          plhs[0] = sf_c26_CaccavaleVillani_updateBuildInfo_args_info();
          break;
        }
      }

     case 30:
      {
        if (strcmp(tpChksum, "036YtO1VMUEZiQPGl0NGXG") == 0) {
          extern mxArray *sf_c30_CaccavaleVillani_updateBuildInfo_args_info(void);
          plhs[0] = sf_c30_CaccavaleVillani_updateBuildInfo_args_info();
          break;
        }
      }

     case 31:
      {
        if (strcmp(tpChksum, "dZWQ3fDfJ3SbBdRH1PhKx") == 0) {
          extern mxArray *sf_c31_CaccavaleVillani_updateBuildInfo_args_info(void);
          plhs[0] = sf_c31_CaccavaleVillani_updateBuildInfo_args_info();
          break;
        }
      }

     case 36:
      {
        if (strcmp(tpChksum, "R5fJ5cX5KyORqPmZdJfjYC") == 0) {
          extern mxArray *sf_c36_CaccavaleVillani_updateBuildInfo_args_info(void);
          plhs[0] = sf_c36_CaccavaleVillani_updateBuildInfo_args_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "1i3LZAfIaHjMJtsqqRFjjF") == 0) {
          extern mxArray *sf_c37_CaccavaleVillani_updateBuildInfo_args_info(void);
          plhs[0] = sf_c37_CaccavaleVillani_updateBuildInfo_args_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "IgmYsTd7hWQzxdq1sf59GB") == 0) {
          extern mxArray *sf_c43_CaccavaleVillani_updateBuildInfo_args_info(void);
          plhs[0] = sf_c43_CaccavaleVillani_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void sf_CaccavaleVillani_get_post_codegen_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  unsigned int chartFileNumber = (unsigned int) mxGetScalar(prhs[0]);
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  switch (chartFileNumber) {
   case 1:
    {
      if (strcmp(tpChksum, "LcJGH7EzT1bzyUNbKdlgO") == 0) {
        extern mxArray *sf_c1_CaccavaleVillani_get_post_codegen_info(void);
        plhs[0] = sf_c1_CaccavaleVillani_get_post_codegen_info();
        return;
      }
    }
    break;

   case 2:
    {
      if (strcmp(tpChksum, "MHUdxILrigSlPOTxkOrUKB") == 0) {
        extern mxArray *sf_c2_CaccavaleVillani_get_post_codegen_info(void);
        plhs[0] = sf_c2_CaccavaleVillani_get_post_codegen_info();
        return;
      }
    }
    break;

   case 3:
    {
      if (strcmp(tpChksum, "nhzpxLEEBZdUjFWNKEZizD") == 0) {
        extern mxArray *sf_c3_CaccavaleVillani_get_post_codegen_info(void);
        plhs[0] = sf_c3_CaccavaleVillani_get_post_codegen_info();
        return;
      }
    }
    break;

   case 4:
    {
      if (strcmp(tpChksum, "036YtO1VMUEZiQPGl0NGXG") == 0) {
        extern mxArray *sf_c4_CaccavaleVillani_get_post_codegen_info(void);
        plhs[0] = sf_c4_CaccavaleVillani_get_post_codegen_info();
        return;
      }
    }
    break;

   case 5:
    {
      if (strcmp(tpChksum, "wKjgDzYGh0AKSV9oCDZhuB") == 0) {
        extern mxArray *sf_c5_CaccavaleVillani_get_post_codegen_info(void);
        plhs[0] = sf_c5_CaccavaleVillani_get_post_codegen_info();
        return;
      }
    }
    break;

   case 6:
    {
      if (strcmp(tpChksum, "vEneZyO80AXkO3fgcTZVhD") == 0) {
        extern mxArray *sf_c6_CaccavaleVillani_get_post_codegen_info(void);
        plhs[0] = sf_c6_CaccavaleVillani_get_post_codegen_info();
        return;
      }
    }
    break;

   case 7:
    {
      if (strcmp(tpChksum, "TMlGanmzJMEGBnqyVVJ86E") == 0) {
        extern mxArray *sf_c7_CaccavaleVillani_get_post_codegen_info(void);
        plhs[0] = sf_c7_CaccavaleVillani_get_post_codegen_info();
        return;
      }
    }
    break;

   case 8:
    {
      if (strcmp(tpChksum, "4pxzcfVpVz6mRboTpKMvmB") == 0) {
        extern mxArray *sf_c8_CaccavaleVillani_get_post_codegen_info(void);
        plhs[0] = sf_c8_CaccavaleVillani_get_post_codegen_info();
        return;
      }
    }
    break;

   case 9:
    {
      if (strcmp(tpChksum, "4pxzcfVpVz6mRboTpKMvmB") == 0) {
        extern mxArray *sf_c9_CaccavaleVillani_get_post_codegen_info(void);
        plhs[0] = sf_c9_CaccavaleVillani_get_post_codegen_info();
        return;
      }
    }
    break;

   case 10:
    {
      if (strcmp(tpChksum, "4pxzcfVpVz6mRboTpKMvmB") == 0) {
        extern mxArray *sf_c10_CaccavaleVillani_get_post_codegen_info(void);
        plhs[0] = sf_c10_CaccavaleVillani_get_post_codegen_info();
        return;
      }
    }
    break;

   case 12:
    {
      if (strcmp(tpChksum, "bgMo300tpt2nma5SeDP5eG") == 0) {
        extern mxArray *sf_c12_CaccavaleVillani_get_post_codegen_info(void);
        plhs[0] = sf_c12_CaccavaleVillani_get_post_codegen_info();
        return;
      }
    }
    break;

   case 13:
    {
      if (strcmp(tpChksum, "Pn0NwQgA7VHB90aenRX2KE") == 0) {
        extern mxArray *sf_c13_CaccavaleVillani_get_post_codegen_info(void);
        plhs[0] = sf_c13_CaccavaleVillani_get_post_codegen_info();
        return;
      }
    }
    break;

   case 14:
    {
      if (strcmp(tpChksum, "ezyyAnTcKjd7cyr3PGBSJ") == 0) {
        extern mxArray *sf_c14_CaccavaleVillani_get_post_codegen_info(void);
        plhs[0] = sf_c14_CaccavaleVillani_get_post_codegen_info();
        return;
      }
    }
    break;

   case 15:
    {
      if (strcmp(tpChksum, "F9NaUoFsluwUCMezsgpn1D") == 0) {
        extern mxArray *sf_c15_CaccavaleVillani_get_post_codegen_info(void);
        plhs[0] = sf_c15_CaccavaleVillani_get_post_codegen_info();
        return;
      }
    }
    break;

   case 21:
    {
      if (strcmp(tpChksum, "MHUdxILrigSlPOTxkOrUKB") == 0) {
        extern mxArray *sf_c21_CaccavaleVillani_get_post_codegen_info(void);
        plhs[0] = sf_c21_CaccavaleVillani_get_post_codegen_info();
        return;
      }
    }
    break;

   case 22:
    {
      if (strcmp(tpChksum, "DpTkc1bOHKC86DQmcFu5WB") == 0) {
        extern mxArray *sf_c22_CaccavaleVillani_get_post_codegen_info(void);
        plhs[0] = sf_c22_CaccavaleVillani_get_post_codegen_info();
        return;
      }
    }
    break;

   case 23:
    {
      if (strcmp(tpChksum, "IL1sQQ4H503LMjzcboLygF") == 0) {
        extern mxArray *sf_c23_CaccavaleVillani_get_post_codegen_info(void);
        plhs[0] = sf_c23_CaccavaleVillani_get_post_codegen_info();
        return;
      }
    }
    break;

   case 26:
    {
      if (strcmp(tpChksum, "4pxzcfVpVz6mRboTpKMvmB") == 0) {
        extern mxArray *sf_c26_CaccavaleVillani_get_post_codegen_info(void);
        plhs[0] = sf_c26_CaccavaleVillani_get_post_codegen_info();
        return;
      }
    }
    break;

   case 30:
    {
      if (strcmp(tpChksum, "036YtO1VMUEZiQPGl0NGXG") == 0) {
        extern mxArray *sf_c30_CaccavaleVillani_get_post_codegen_info(void);
        plhs[0] = sf_c30_CaccavaleVillani_get_post_codegen_info();
        return;
      }
    }
    break;

   case 31:
    {
      if (strcmp(tpChksum, "dZWQ3fDfJ3SbBdRH1PhKx") == 0) {
        extern mxArray *sf_c31_CaccavaleVillani_get_post_codegen_info(void);
        plhs[0] = sf_c31_CaccavaleVillani_get_post_codegen_info();
        return;
      }
    }
    break;

   case 36:
    {
      if (strcmp(tpChksum, "R5fJ5cX5KyORqPmZdJfjYC") == 0) {
        extern mxArray *sf_c36_CaccavaleVillani_get_post_codegen_info(void);
        plhs[0] = sf_c36_CaccavaleVillani_get_post_codegen_info();
        return;
      }
    }
    break;

   case 37:
    {
      if (strcmp(tpChksum, "1i3LZAfIaHjMJtsqqRFjjF") == 0) {
        extern mxArray *sf_c37_CaccavaleVillani_get_post_codegen_info(void);
        plhs[0] = sf_c37_CaccavaleVillani_get_post_codegen_info();
        return;
      }
    }
    break;

   case 43:
    {
      if (strcmp(tpChksum, "IgmYsTd7hWQzxdq1sf59GB") == 0) {
        extern mxArray *sf_c43_CaccavaleVillani_get_post_codegen_info(void);
        plhs[0] = sf_c43_CaccavaleVillani_get_post_codegen_info();
        return;
      }
    }
    break;

   default:
    break;
  }

  plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
}

void CaccavaleVillani_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _CaccavaleVillaniMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "CaccavaleVillani","sfun",0,23,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _CaccavaleVillaniMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _CaccavaleVillaniMachineNumber_,0);
}

void CaccavaleVillani_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_CaccavaleVillani_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "CaccavaleVillani", "CaccavaleVillani");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_CaccavaleVillani_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}

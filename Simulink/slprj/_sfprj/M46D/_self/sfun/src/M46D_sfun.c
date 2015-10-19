/* Include files */

#include "M46D_sfun.h"
#include "M46D_sfun_debug_macros.h"
#include "c1_M46D.h"
#include "c2_M46D.h"
#include "c3_M46D.h"
#include "c4_M46D.h"
#include "c5_M46D.h"
#include "c7_M46D.h"
#include "c8_M46D.h"
#include "c9_M46D.h"
#include "c10_M46D.h"
#include "c11_M46D.h"
#include "c12_M46D.h"
#include "c13_M46D.h"
#include "c14_M46D.h"
#include "c15_M46D.h"
#include "c16_M46D.h"
#include "c17_M46D.h"
#include "c18_M46D.h"
#include "c19_M46D.h"
#include "c20_M46D.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _M46DMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void M46D_initializer(void)
{
}

void M46D_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_M46D_method_dispatcher(SimStruct *simstructPtr, unsigned int
  chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_M46D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_M46D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_M46D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_M46D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_M46D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_M46D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_M46D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_M46D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_M46D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_M46D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_M46D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_M46D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_M46D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_M46D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==16) {
    c16_M46D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_M46D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==18) {
    c18_M46D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==19) {
    c19_M46D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==20) {
    c20_M46D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

extern void sf_M46D_uses_exported_functions(int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[])
{
  plhs[0] = mxCreateLogicalScalar(0);
}

unsigned int sf_M46D_process_check_sum_call( int nlhs, mxArray * plhs[], int
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2341135625U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3074005875U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1860575848U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(906147226U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3286208684U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(278213064U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3624672488U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1957952004U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_M46D_get_check_sum(mxArray *plhs[]);
          sf_c1_M46D_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_M46D_get_check_sum(mxArray *plhs[]);
          sf_c2_M46D_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_M46D_get_check_sum(mxArray *plhs[]);
          sf_c3_M46D_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_M46D_get_check_sum(mxArray *plhs[]);
          sf_c4_M46D_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_M46D_get_check_sum(mxArray *plhs[]);
          sf_c5_M46D_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_M46D_get_check_sum(mxArray *plhs[]);
          sf_c7_M46D_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_M46D_get_check_sum(mxArray *plhs[]);
          sf_c8_M46D_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_M46D_get_check_sum(mxArray *plhs[]);
          sf_c9_M46D_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_M46D_get_check_sum(mxArray *plhs[]);
          sf_c10_M46D_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_M46D_get_check_sum(mxArray *plhs[]);
          sf_c11_M46D_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_M46D_get_check_sum(mxArray *plhs[]);
          sf_c12_M46D_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_M46D_get_check_sum(mxArray *plhs[]);
          sf_c13_M46D_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_M46D_get_check_sum(mxArray *plhs[]);
          sf_c14_M46D_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_M46D_get_check_sum(mxArray *plhs[]);
          sf_c15_M46D_get_check_sum(plhs);
          break;
        }

       case 16:
        {
          extern void sf_c16_M46D_get_check_sum(mxArray *plhs[]);
          sf_c16_M46D_get_check_sum(plhs);
          break;
        }

       case 17:
        {
          extern void sf_c17_M46D_get_check_sum(mxArray *plhs[]);
          sf_c17_M46D_get_check_sum(plhs);
          break;
        }

       case 18:
        {
          extern void sf_c18_M46D_get_check_sum(mxArray *plhs[]);
          sf_c18_M46D_get_check_sum(plhs);
          break;
        }

       case 19:
        {
          extern void sf_c19_M46D_get_check_sum(mxArray *plhs[]);
          sf_c19_M46D_get_check_sum(plhs);
          break;
        }

       case 20:
        {
          extern void sf_c20_M46D_get_check_sum(mxArray *plhs[]);
          sf_c20_M46D_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(497961314U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(780454920U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1016475106U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4184495584U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_M46D_autoinheritance_info( int nlhs, mxArray * plhs[], int nrhs,
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
        if (strcmp(aiChksum, "uBizxnGVcFquRQisSA7OXF") == 0) {
          extern mxArray *sf_c1_M46D_get_autoinheritance_info(void);
          plhs[0] = sf_c1_M46D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "VE4YjxqImrW9RILskA2YwC") == 0) {
          extern mxArray *sf_c2_M46D_get_autoinheritance_info(void);
          plhs[0] = sf_c2_M46D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "ZnW7Iaxfmu6nhUDGmHNjTG") == 0) {
          extern mxArray *sf_c3_M46D_get_autoinheritance_info(void);
          plhs[0] = sf_c3_M46D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "G6E3hZxHRWN4WaiZftKGPE") == 0) {
          extern mxArray *sf_c4_M46D_get_autoinheritance_info(void);
          plhs[0] = sf_c4_M46D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "7j3v2SKnvw9hbdx22tzmw") == 0) {
          extern mxArray *sf_c5_M46D_get_autoinheritance_info(void);
          plhs[0] = sf_c5_M46D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "1pbh7rb7UMl7ER9bMXh8iF") == 0) {
          extern mxArray *sf_c7_M46D_get_autoinheritance_info(void);
          plhs[0] = sf_c7_M46D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "4Cb1TPEEQGYA0sRdmTiE0G") == 0) {
          extern mxArray *sf_c8_M46D_get_autoinheritance_info(void);
          plhs[0] = sf_c8_M46D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "JNamLrj25eG5XEOAUIcbrC") == 0) {
          extern mxArray *sf_c9_M46D_get_autoinheritance_info(void);
          plhs[0] = sf_c9_M46D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "Z3TMwZHwjxBjlmwxRpOan") == 0) {
          extern mxArray *sf_c10_M46D_get_autoinheritance_info(void);
          plhs[0] = sf_c10_M46D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "Jzu1MuGkanwfJKqP9wZdtG") == 0) {
          extern mxArray *sf_c11_M46D_get_autoinheritance_info(void);
          plhs[0] = sf_c11_M46D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "ZbEniWmXW14iOQh3XT1FIH") == 0) {
          extern mxArray *sf_c12_M46D_get_autoinheritance_info(void);
          plhs[0] = sf_c12_M46D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "bLGGqJly3dR2x79Fe91MeF") == 0) {
          extern mxArray *sf_c13_M46D_get_autoinheritance_info(void);
          plhs[0] = sf_c13_M46D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 14:
      {
        if (strcmp(aiChksum, "DJJCaLU0SvEvnPXUVY7mkC") == 0) {
          extern mxArray *sf_c14_M46D_get_autoinheritance_info(void);
          plhs[0] = sf_c14_M46D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "hxYH2HpMzReiFcRppUJnHC") == 0) {
          extern mxArray *sf_c15_M46D_get_autoinheritance_info(void);
          plhs[0] = sf_c15_M46D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 16:
      {
        if (strcmp(aiChksum, "2H3XJ76gZOZ7oEkIvvljvE") == 0) {
          extern mxArray *sf_c16_M46D_get_autoinheritance_info(void);
          plhs[0] = sf_c16_M46D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 17:
      {
        if (strcmp(aiChksum, "Y6dkn0vu8Kfqi8yRTztzyD") == 0) {
          extern mxArray *sf_c17_M46D_get_autoinheritance_info(void);
          plhs[0] = sf_c17_M46D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 18:
      {
        if (strcmp(aiChksum, "etmyfvtCaJTG11mPKFY9H") == 0) {
          extern mxArray *sf_c18_M46D_get_autoinheritance_info(void);
          plhs[0] = sf_c18_M46D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 19:
      {
        if (strcmp(aiChksum, "V5imeNNhX9kgxKSYh5F4ED") == 0) {
          extern mxArray *sf_c19_M46D_get_autoinheritance_info(void);
          plhs[0] = sf_c19_M46D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 20:
      {
        if (strcmp(aiChksum, "Wmbfw5SMBcEw16dh6FQ3SE") == 0) {
          extern mxArray *sf_c20_M46D_get_autoinheritance_info(void);
          plhs[0] = sf_c20_M46D_get_autoinheritance_info();
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

unsigned int sf_M46D_get_eml_resolved_functions_info( int nlhs, mxArray * plhs[],
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
        extern const mxArray *sf_c1_M46D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_M46D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_M46D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_M46D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_M46D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_M46D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_M46D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_M46D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_M46D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_M46D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray *sf_c7_M46D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_M46D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray *sf_c8_M46D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_M46D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray *sf_c9_M46D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_M46D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray *sf_c10_M46D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_M46D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray *sf_c11_M46D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_M46D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray *sf_c12_M46D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_M46D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray *sf_c13_M46D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_M46D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray *sf_c14_M46D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_M46D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray *sf_c15_M46D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_M46D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 16:
      {
        extern const mxArray *sf_c16_M46D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c16_M46D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray *sf_c17_M46D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_M46D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 18:
      {
        extern const mxArray *sf_c18_M46D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c18_M46D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 19:
      {
        extern const mxArray *sf_c19_M46D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c19_M46D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 20:
      {
        extern const mxArray *sf_c20_M46D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_M46D_get_eml_resolved_functions_info();
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

unsigned int sf_M46D_third_party_uses_info( int nlhs, mxArray * plhs[], int nrhs,
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
        if (strcmp(tpChksum, "P1dYCZx9rGqBcCx1mQc6lB") == 0) {
          extern mxArray *sf_c1_M46D_third_party_uses_info(void);
          plhs[0] = sf_c1_M46D_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "q2jVn1cah8Bq9NT7sS3xoD") == 0) {
          extern mxArray *sf_c2_M46D_third_party_uses_info(void);
          plhs[0] = sf_c2_M46D_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "5bkpRahYMKSxpLQchC9tP") == 0) {
          extern mxArray *sf_c3_M46D_third_party_uses_info(void);
          plhs[0] = sf_c3_M46D_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "7qm7WTA63SONw1BLeqAXUB") == 0) {
          extern mxArray *sf_c4_M46D_third_party_uses_info(void);
          plhs[0] = sf_c4_M46D_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "3JCMA9nkSvMtfjdtSbo1DE") == 0) {
          extern mxArray *sf_c5_M46D_third_party_uses_info(void);
          plhs[0] = sf_c5_M46D_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "WFdkRj7uzauAK0vgKbQzJE") == 0) {
          extern mxArray *sf_c7_M46D_third_party_uses_info(void);
          plhs[0] = sf_c7_M46D_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "BQBP4dIyN6TCcgjthns89E") == 0) {
          extern mxArray *sf_c8_M46D_third_party_uses_info(void);
          plhs[0] = sf_c8_M46D_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "aK7Siq5SYExraHCRc0PsiC") == 0) {
          extern mxArray *sf_c9_M46D_third_party_uses_info(void);
          plhs[0] = sf_c9_M46D_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "r3xjw1VeSki3xWsidfZqED") == 0) {
          extern mxArray *sf_c10_M46D_third_party_uses_info(void);
          plhs[0] = sf_c10_M46D_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "tHZzbfZzBsj79h9J54rg1B") == 0) {
          extern mxArray *sf_c11_M46D_third_party_uses_info(void);
          plhs[0] = sf_c11_M46D_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "hloo5bdHNXjM2XOXPPhjrC") == 0) {
          extern mxArray *sf_c12_M46D_third_party_uses_info(void);
          plhs[0] = sf_c12_M46D_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "o016e5JUlUdLICaI65MJtE") == 0) {
          extern mxArray *sf_c13_M46D_third_party_uses_info(void);
          plhs[0] = sf_c13_M46D_third_party_uses_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "CFfR7IDOYNgkLnS83MnnrB") == 0) {
          extern mxArray *sf_c14_M46D_third_party_uses_info(void);
          plhs[0] = sf_c14_M46D_third_party_uses_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "kF44pbzj5xngxdAOg4oL6C") == 0) {
          extern mxArray *sf_c15_M46D_third_party_uses_info(void);
          plhs[0] = sf_c15_M46D_third_party_uses_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "XQJm4S9eAZ5fGqR0CQD1OE") == 0) {
          extern mxArray *sf_c16_M46D_third_party_uses_info(void);
          plhs[0] = sf_c16_M46D_third_party_uses_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "az7l7RdE1rHqSDukqaeCWG") == 0) {
          extern mxArray *sf_c17_M46D_third_party_uses_info(void);
          plhs[0] = sf_c17_M46D_third_party_uses_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "e8x4g7nNOt2S4IWSHnB5CH") == 0) {
          extern mxArray *sf_c18_M46D_third_party_uses_info(void);
          plhs[0] = sf_c18_M46D_third_party_uses_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "lL4A590OcsEbKAjq1rJDQB") == 0) {
          extern mxArray *sf_c19_M46D_third_party_uses_info(void);
          plhs[0] = sf_c19_M46D_third_party_uses_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "VkKwN8kCVkRlou36wCBdx") == 0) {
          extern mxArray *sf_c20_M46D_third_party_uses_info(void);
          plhs[0] = sf_c20_M46D_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_M46D_jit_fallback_info( int nlhs, mxArray * plhs[], int nrhs,
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
        if (strcmp(tpChksum, "P1dYCZx9rGqBcCx1mQc6lB") == 0) {
          extern mxArray *sf_c1_M46D_jit_fallback_info(void);
          plhs[0] = sf_c1_M46D_jit_fallback_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "q2jVn1cah8Bq9NT7sS3xoD") == 0) {
          extern mxArray *sf_c2_M46D_jit_fallback_info(void);
          plhs[0] = sf_c2_M46D_jit_fallback_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "5bkpRahYMKSxpLQchC9tP") == 0) {
          extern mxArray *sf_c3_M46D_jit_fallback_info(void);
          plhs[0] = sf_c3_M46D_jit_fallback_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "7qm7WTA63SONw1BLeqAXUB") == 0) {
          extern mxArray *sf_c4_M46D_jit_fallback_info(void);
          plhs[0] = sf_c4_M46D_jit_fallback_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "3JCMA9nkSvMtfjdtSbo1DE") == 0) {
          extern mxArray *sf_c5_M46D_jit_fallback_info(void);
          plhs[0] = sf_c5_M46D_jit_fallback_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "WFdkRj7uzauAK0vgKbQzJE") == 0) {
          extern mxArray *sf_c7_M46D_jit_fallback_info(void);
          plhs[0] = sf_c7_M46D_jit_fallback_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "BQBP4dIyN6TCcgjthns89E") == 0) {
          extern mxArray *sf_c8_M46D_jit_fallback_info(void);
          plhs[0] = sf_c8_M46D_jit_fallback_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "aK7Siq5SYExraHCRc0PsiC") == 0) {
          extern mxArray *sf_c9_M46D_jit_fallback_info(void);
          plhs[0] = sf_c9_M46D_jit_fallback_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "r3xjw1VeSki3xWsidfZqED") == 0) {
          extern mxArray *sf_c10_M46D_jit_fallback_info(void);
          plhs[0] = sf_c10_M46D_jit_fallback_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "tHZzbfZzBsj79h9J54rg1B") == 0) {
          extern mxArray *sf_c11_M46D_jit_fallback_info(void);
          plhs[0] = sf_c11_M46D_jit_fallback_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "hloo5bdHNXjM2XOXPPhjrC") == 0) {
          extern mxArray *sf_c12_M46D_jit_fallback_info(void);
          plhs[0] = sf_c12_M46D_jit_fallback_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "o016e5JUlUdLICaI65MJtE") == 0) {
          extern mxArray *sf_c13_M46D_jit_fallback_info(void);
          plhs[0] = sf_c13_M46D_jit_fallback_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "CFfR7IDOYNgkLnS83MnnrB") == 0) {
          extern mxArray *sf_c14_M46D_jit_fallback_info(void);
          plhs[0] = sf_c14_M46D_jit_fallback_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "kF44pbzj5xngxdAOg4oL6C") == 0) {
          extern mxArray *sf_c15_M46D_jit_fallback_info(void);
          plhs[0] = sf_c15_M46D_jit_fallback_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "XQJm4S9eAZ5fGqR0CQD1OE") == 0) {
          extern mxArray *sf_c16_M46D_jit_fallback_info(void);
          plhs[0] = sf_c16_M46D_jit_fallback_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "az7l7RdE1rHqSDukqaeCWG") == 0) {
          extern mxArray *sf_c17_M46D_jit_fallback_info(void);
          plhs[0] = sf_c17_M46D_jit_fallback_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "e8x4g7nNOt2S4IWSHnB5CH") == 0) {
          extern mxArray *sf_c18_M46D_jit_fallback_info(void);
          plhs[0] = sf_c18_M46D_jit_fallback_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "lL4A590OcsEbKAjq1rJDQB") == 0) {
          extern mxArray *sf_c19_M46D_jit_fallback_info(void);
          plhs[0] = sf_c19_M46D_jit_fallback_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "VkKwN8kCVkRlou36wCBdx") == 0) {
          extern mxArray *sf_c20_M46D_jit_fallback_info(void);
          plhs[0] = sf_c20_M46D_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_M46D_updateBuildInfo_args_info( int nlhs, mxArray * plhs[], int
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
        if (strcmp(tpChksum, "P1dYCZx9rGqBcCx1mQc6lB") == 0) {
          extern mxArray *sf_c1_M46D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_M46D_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "q2jVn1cah8Bq9NT7sS3xoD") == 0) {
          extern mxArray *sf_c2_M46D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_M46D_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "5bkpRahYMKSxpLQchC9tP") == 0) {
          extern mxArray *sf_c3_M46D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_M46D_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "7qm7WTA63SONw1BLeqAXUB") == 0) {
          extern mxArray *sf_c4_M46D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_M46D_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "3JCMA9nkSvMtfjdtSbo1DE") == 0) {
          extern mxArray *sf_c5_M46D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_M46D_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "WFdkRj7uzauAK0vgKbQzJE") == 0) {
          extern mxArray *sf_c7_M46D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_M46D_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "BQBP4dIyN6TCcgjthns89E") == 0) {
          extern mxArray *sf_c8_M46D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_M46D_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "aK7Siq5SYExraHCRc0PsiC") == 0) {
          extern mxArray *sf_c9_M46D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_M46D_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "r3xjw1VeSki3xWsidfZqED") == 0) {
          extern mxArray *sf_c10_M46D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_M46D_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "tHZzbfZzBsj79h9J54rg1B") == 0) {
          extern mxArray *sf_c11_M46D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_M46D_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "hloo5bdHNXjM2XOXPPhjrC") == 0) {
          extern mxArray *sf_c12_M46D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c12_M46D_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "o016e5JUlUdLICaI65MJtE") == 0) {
          extern mxArray *sf_c13_M46D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c13_M46D_updateBuildInfo_args_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "CFfR7IDOYNgkLnS83MnnrB") == 0) {
          extern mxArray *sf_c14_M46D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c14_M46D_updateBuildInfo_args_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "kF44pbzj5xngxdAOg4oL6C") == 0) {
          extern mxArray *sf_c15_M46D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c15_M46D_updateBuildInfo_args_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "XQJm4S9eAZ5fGqR0CQD1OE") == 0) {
          extern mxArray *sf_c16_M46D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c16_M46D_updateBuildInfo_args_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "az7l7RdE1rHqSDukqaeCWG") == 0) {
          extern mxArray *sf_c17_M46D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c17_M46D_updateBuildInfo_args_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "e8x4g7nNOt2S4IWSHnB5CH") == 0) {
          extern mxArray *sf_c18_M46D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c18_M46D_updateBuildInfo_args_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "lL4A590OcsEbKAjq1rJDQB") == 0) {
          extern mxArray *sf_c19_M46D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c19_M46D_updateBuildInfo_args_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "VkKwN8kCVkRlou36wCBdx") == 0) {
          extern mxArray *sf_c20_M46D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c20_M46D_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void sf_M46D_get_post_codegen_info( int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[] )
{
  unsigned int chartFileNumber = (unsigned int) mxGetScalar(prhs[0]);
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  switch (chartFileNumber) {
   case 1:
    {
      if (strcmp(tpChksum, "P1dYCZx9rGqBcCx1mQc6lB") == 0) {
        extern mxArray *sf_c1_M46D_get_post_codegen_info(void);
        plhs[0] = sf_c1_M46D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 2:
    {
      if (strcmp(tpChksum, "q2jVn1cah8Bq9NT7sS3xoD") == 0) {
        extern mxArray *sf_c2_M46D_get_post_codegen_info(void);
        plhs[0] = sf_c2_M46D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 3:
    {
      if (strcmp(tpChksum, "5bkpRahYMKSxpLQchC9tP") == 0) {
        extern mxArray *sf_c3_M46D_get_post_codegen_info(void);
        plhs[0] = sf_c3_M46D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 4:
    {
      if (strcmp(tpChksum, "7qm7WTA63SONw1BLeqAXUB") == 0) {
        extern mxArray *sf_c4_M46D_get_post_codegen_info(void);
        plhs[0] = sf_c4_M46D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 5:
    {
      if (strcmp(tpChksum, "3JCMA9nkSvMtfjdtSbo1DE") == 0) {
        extern mxArray *sf_c5_M46D_get_post_codegen_info(void);
        plhs[0] = sf_c5_M46D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 7:
    {
      if (strcmp(tpChksum, "WFdkRj7uzauAK0vgKbQzJE") == 0) {
        extern mxArray *sf_c7_M46D_get_post_codegen_info(void);
        plhs[0] = sf_c7_M46D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 8:
    {
      if (strcmp(tpChksum, "BQBP4dIyN6TCcgjthns89E") == 0) {
        extern mxArray *sf_c8_M46D_get_post_codegen_info(void);
        plhs[0] = sf_c8_M46D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 9:
    {
      if (strcmp(tpChksum, "aK7Siq5SYExraHCRc0PsiC") == 0) {
        extern mxArray *sf_c9_M46D_get_post_codegen_info(void);
        plhs[0] = sf_c9_M46D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 10:
    {
      if (strcmp(tpChksum, "r3xjw1VeSki3xWsidfZqED") == 0) {
        extern mxArray *sf_c10_M46D_get_post_codegen_info(void);
        plhs[0] = sf_c10_M46D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 11:
    {
      if (strcmp(tpChksum, "tHZzbfZzBsj79h9J54rg1B") == 0) {
        extern mxArray *sf_c11_M46D_get_post_codegen_info(void);
        plhs[0] = sf_c11_M46D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 12:
    {
      if (strcmp(tpChksum, "hloo5bdHNXjM2XOXPPhjrC") == 0) {
        extern mxArray *sf_c12_M46D_get_post_codegen_info(void);
        plhs[0] = sf_c12_M46D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 13:
    {
      if (strcmp(tpChksum, "o016e5JUlUdLICaI65MJtE") == 0) {
        extern mxArray *sf_c13_M46D_get_post_codegen_info(void);
        plhs[0] = sf_c13_M46D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 14:
    {
      if (strcmp(tpChksum, "CFfR7IDOYNgkLnS83MnnrB") == 0) {
        extern mxArray *sf_c14_M46D_get_post_codegen_info(void);
        plhs[0] = sf_c14_M46D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 15:
    {
      if (strcmp(tpChksum, "kF44pbzj5xngxdAOg4oL6C") == 0) {
        extern mxArray *sf_c15_M46D_get_post_codegen_info(void);
        plhs[0] = sf_c15_M46D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 16:
    {
      if (strcmp(tpChksum, "XQJm4S9eAZ5fGqR0CQD1OE") == 0) {
        extern mxArray *sf_c16_M46D_get_post_codegen_info(void);
        plhs[0] = sf_c16_M46D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 17:
    {
      if (strcmp(tpChksum, "az7l7RdE1rHqSDukqaeCWG") == 0) {
        extern mxArray *sf_c17_M46D_get_post_codegen_info(void);
        plhs[0] = sf_c17_M46D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 18:
    {
      if (strcmp(tpChksum, "e8x4g7nNOt2S4IWSHnB5CH") == 0) {
        extern mxArray *sf_c18_M46D_get_post_codegen_info(void);
        plhs[0] = sf_c18_M46D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 19:
    {
      if (strcmp(tpChksum, "lL4A590OcsEbKAjq1rJDQB") == 0) {
        extern mxArray *sf_c19_M46D_get_post_codegen_info(void);
        plhs[0] = sf_c19_M46D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 20:
    {
      if (strcmp(tpChksum, "VkKwN8kCVkRlou36wCBdx") == 0) {
        extern mxArray *sf_c20_M46D_get_post_codegen_info(void);
        plhs[0] = sf_c20_M46D_get_post_codegen_info();
        return;
      }
    }
    break;

   default:
    break;
  }

  plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
}

void M46D_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _M46DMachineNumber_ = sf_debug_initialize_machine(debugInstance,"M46D","sfun",
    0,19,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,_M46DMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,_M46DMachineNumber_,0);
}

void M46D_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_M46D_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("M46D", "M46D");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_M46D_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}

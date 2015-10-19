/* Include files */

#include "Model1angular_sfun.h"
#include "Model1angular_sfun_debug_macros.h"
#include "c1_Model1angular.h"
#include "c2_Model1angular.h"
#include "c3_Model1angular.h"
#include "c4_Model1angular.h"
#include "c5_Model1angular.h"
#include "c7_Model1angular.h"
#include "c8_Model1angular.h"
#include "c9_Model1angular.h"
#include "c10_Model1angular.h"
#include "c11_Model1angular.h"
#include "c12_Model1angular.h"
#include "c13_Model1angular.h"
#include "c14_Model1angular.h"
#include "c15_Model1angular.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _Model1angularMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void Model1angular_initializer(void)
{
}

void Model1angular_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Model1angular_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_Model1angular_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_Model1angular_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_Model1angular_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_Model1angular_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_Model1angular_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_Model1angular_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_Model1angular_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_Model1angular_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_Model1angular_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_Model1angular_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_Model1angular_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_Model1angular_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_Model1angular_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_Model1angular_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

extern void sf_Model1angular_uses_exported_functions(int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[])
{
  plhs[0] = mxCreateLogicalScalar(0);
}

unsigned int sf_Model1angular_process_check_sum_call( int nlhs, mxArray * plhs[],
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1814502144U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2675984672U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2208601420U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(116173455U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2012304078U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(496778176U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3413132049U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3897289417U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_Model1angular_get_check_sum(mxArray *plhs[]);
          sf_c1_Model1angular_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_Model1angular_get_check_sum(mxArray *plhs[]);
          sf_c2_Model1angular_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_Model1angular_get_check_sum(mxArray *plhs[]);
          sf_c3_Model1angular_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_Model1angular_get_check_sum(mxArray *plhs[]);
          sf_c4_Model1angular_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_Model1angular_get_check_sum(mxArray *plhs[]);
          sf_c5_Model1angular_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_Model1angular_get_check_sum(mxArray *plhs[]);
          sf_c7_Model1angular_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_Model1angular_get_check_sum(mxArray *plhs[]);
          sf_c8_Model1angular_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_Model1angular_get_check_sum(mxArray *plhs[]);
          sf_c9_Model1angular_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_Model1angular_get_check_sum(mxArray *plhs[]);
          sf_c10_Model1angular_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_Model1angular_get_check_sum(mxArray *plhs[]);
          sf_c11_Model1angular_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_Model1angular_get_check_sum(mxArray *plhs[]);
          sf_c12_Model1angular_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_Model1angular_get_check_sum(mxArray *plhs[]);
          sf_c13_Model1angular_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_Model1angular_get_check_sum(mxArray *plhs[]);
          sf_c14_Model1angular_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_Model1angular_get_check_sum(mxArray *plhs[]);
          sf_c15_Model1angular_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(57745726U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3472304192U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1010732543U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1304848822U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Model1angular_autoinheritance_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(aiChksum, "uBizxnGVcFquRQisSA7OXF") == 0) {
          extern mxArray *sf_c1_Model1angular_get_autoinheritance_info(void);
          plhs[0] = sf_c1_Model1angular_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "VE4YjxqImrW9RILskA2YwC") == 0) {
          extern mxArray *sf_c2_Model1angular_get_autoinheritance_info(void);
          plhs[0] = sf_c2_Model1angular_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "vzVEzOXfN8gfQjq5xGHwZF") == 0) {
          extern mxArray *sf_c3_Model1angular_get_autoinheritance_info(void);
          plhs[0] = sf_c3_Model1angular_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "Ke3wUK11n7IeMZ7qxmNaeD") == 0) {
          extern mxArray *sf_c4_Model1angular_get_autoinheritance_info(void);
          plhs[0] = sf_c4_Model1angular_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "g9CpnQGlw1LAp4q1zWADiF") == 0) {
          extern mxArray *sf_c5_Model1angular_get_autoinheritance_info(void);
          plhs[0] = sf_c5_Model1angular_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "YyaVaEi6zTDZCDNhO3aBpH") == 0) {
          extern mxArray *sf_c7_Model1angular_get_autoinheritance_info(void);
          plhs[0] = sf_c7_Model1angular_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "0C2538fjPgzadLvMsTFv8B") == 0) {
          extern mxArray *sf_c8_Model1angular_get_autoinheritance_info(void);
          plhs[0] = sf_c8_Model1angular_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "0H1Q5hpNAgvimh5kSePMoG") == 0) {
          extern mxArray *sf_c9_Model1angular_get_autoinheritance_info(void);
          plhs[0] = sf_c9_Model1angular_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "YWawQFBGs3iUZv2YJ6diED") == 0) {
          extern mxArray *sf_c10_Model1angular_get_autoinheritance_info(void);
          plhs[0] = sf_c10_Model1angular_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "N8YcdXH4fedAd7EzRyYysH") == 0) {
          extern mxArray *sf_c11_Model1angular_get_autoinheritance_info(void);
          plhs[0] = sf_c11_Model1angular_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "xAvIFbCwSTnTUWxeTFCN3E") == 0) {
          extern mxArray *sf_c12_Model1angular_get_autoinheritance_info(void);
          plhs[0] = sf_c12_Model1angular_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "TpJYDlqnZAksw2imsglcJH") == 0) {
          extern mxArray *sf_c13_Model1angular_get_autoinheritance_info(void);
          plhs[0] = sf_c13_Model1angular_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 14:
      {
        if (strcmp(aiChksum, "F75ftBpB2IevM8bKtVJV4G") == 0) {
          extern mxArray *sf_c14_Model1angular_get_autoinheritance_info(void);
          plhs[0] = sf_c14_Model1angular_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "A3MPTNcoSDNPKeamiJ1pVD") == 0) {
          extern mxArray *sf_c15_Model1angular_get_autoinheritance_info(void);
          plhs[0] = sf_c15_Model1angular_get_autoinheritance_info();
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

unsigned int sf_Model1angular_get_eml_resolved_functions_info( int nlhs, mxArray
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
          *sf_c1_Model1angular_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_Model1angular_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_Model1angular_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_Model1angular_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_Model1angular_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_Model1angular_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_Model1angular_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_Model1angular_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_Model1angular_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_Model1angular_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_Model1angular_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_Model1angular_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_Model1angular_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_Model1angular_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_Model1angular_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_Model1angular_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_Model1angular_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_Model1angular_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_Model1angular_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_Model1angular_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_Model1angular_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_Model1angular_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_Model1angular_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_Model1angular_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray
          *sf_c14_Model1angular_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_Model1angular_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray
          *sf_c15_Model1angular_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_Model1angular_get_eml_resolved_functions_info();
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

unsigned int sf_Model1angular_third_party_uses_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(tpChksum, "P1dYCZx9rGqBcCx1mQc6lB") == 0) {
          extern mxArray *sf_c1_Model1angular_third_party_uses_info(void);
          plhs[0] = sf_c1_Model1angular_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "q2jVn1cah8Bq9NT7sS3xoD") == 0) {
          extern mxArray *sf_c2_Model1angular_third_party_uses_info(void);
          plhs[0] = sf_c2_Model1angular_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "YSYjhN9Bdi4ZskpaslZJZH") == 0) {
          extern mxArray *sf_c3_Model1angular_third_party_uses_info(void);
          plhs[0] = sf_c3_Model1angular_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "7nuwuG0iPxITiDbjvx8viB") == 0) {
          extern mxArray *sf_c4_Model1angular_third_party_uses_info(void);
          plhs[0] = sf_c4_Model1angular_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "5m49HvbqLxSHC3gaxvNOFE") == 0) {
          extern mxArray *sf_c5_Model1angular_third_party_uses_info(void);
          plhs[0] = sf_c5_Model1angular_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "ibOSl01g2LPaZv5XAoV85") == 0) {
          extern mxArray *sf_c7_Model1angular_third_party_uses_info(void);
          plhs[0] = sf_c7_Model1angular_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "G7MbDKDUKcNv6S6WZQzlYC") == 0) {
          extern mxArray *sf_c8_Model1angular_third_party_uses_info(void);
          plhs[0] = sf_c8_Model1angular_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "z4BPNgk5OZMSp1i2ZiCQAH") == 0) {
          extern mxArray *sf_c9_Model1angular_third_party_uses_info(void);
          plhs[0] = sf_c9_Model1angular_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "SyMMPbImyp5DSf4al94PfG") == 0) {
          extern mxArray *sf_c10_Model1angular_third_party_uses_info(void);
          plhs[0] = sf_c10_Model1angular_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "btha56Bn9yFTbSB1RQmCG") == 0) {
          extern mxArray *sf_c11_Model1angular_third_party_uses_info(void);
          plhs[0] = sf_c11_Model1angular_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "ThNgAJCG0BraiZarLo5kWG") == 0) {
          extern mxArray *sf_c12_Model1angular_third_party_uses_info(void);
          plhs[0] = sf_c12_Model1angular_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "IMcJtTOCVxop0MIpJrKp1D") == 0) {
          extern mxArray *sf_c13_Model1angular_third_party_uses_info(void);
          plhs[0] = sf_c13_Model1angular_third_party_uses_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "l1iTpMTMq75htSBX6uzriE") == 0) {
          extern mxArray *sf_c14_Model1angular_third_party_uses_info(void);
          plhs[0] = sf_c14_Model1angular_third_party_uses_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "blSJtnn3wEz7YP12eUHsp") == 0) {
          extern mxArray *sf_c15_Model1angular_third_party_uses_info(void);
          plhs[0] = sf_c15_Model1angular_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Model1angular_jit_fallback_info( int nlhs, mxArray * plhs[], int
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
        if (strcmp(tpChksum, "P1dYCZx9rGqBcCx1mQc6lB") == 0) {
          extern mxArray *sf_c1_Model1angular_jit_fallback_info(void);
          plhs[0] = sf_c1_Model1angular_jit_fallback_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "q2jVn1cah8Bq9NT7sS3xoD") == 0) {
          extern mxArray *sf_c2_Model1angular_jit_fallback_info(void);
          plhs[0] = sf_c2_Model1angular_jit_fallback_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "YSYjhN9Bdi4ZskpaslZJZH") == 0) {
          extern mxArray *sf_c3_Model1angular_jit_fallback_info(void);
          plhs[0] = sf_c3_Model1angular_jit_fallback_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "7nuwuG0iPxITiDbjvx8viB") == 0) {
          extern mxArray *sf_c4_Model1angular_jit_fallback_info(void);
          plhs[0] = sf_c4_Model1angular_jit_fallback_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "5m49HvbqLxSHC3gaxvNOFE") == 0) {
          extern mxArray *sf_c5_Model1angular_jit_fallback_info(void);
          plhs[0] = sf_c5_Model1angular_jit_fallback_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "ibOSl01g2LPaZv5XAoV85") == 0) {
          extern mxArray *sf_c7_Model1angular_jit_fallback_info(void);
          plhs[0] = sf_c7_Model1angular_jit_fallback_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "G7MbDKDUKcNv6S6WZQzlYC") == 0) {
          extern mxArray *sf_c8_Model1angular_jit_fallback_info(void);
          plhs[0] = sf_c8_Model1angular_jit_fallback_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "z4BPNgk5OZMSp1i2ZiCQAH") == 0) {
          extern mxArray *sf_c9_Model1angular_jit_fallback_info(void);
          plhs[0] = sf_c9_Model1angular_jit_fallback_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "SyMMPbImyp5DSf4al94PfG") == 0) {
          extern mxArray *sf_c10_Model1angular_jit_fallback_info(void);
          plhs[0] = sf_c10_Model1angular_jit_fallback_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "btha56Bn9yFTbSB1RQmCG") == 0) {
          extern mxArray *sf_c11_Model1angular_jit_fallback_info(void);
          plhs[0] = sf_c11_Model1angular_jit_fallback_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "ThNgAJCG0BraiZarLo5kWG") == 0) {
          extern mxArray *sf_c12_Model1angular_jit_fallback_info(void);
          plhs[0] = sf_c12_Model1angular_jit_fallback_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "IMcJtTOCVxop0MIpJrKp1D") == 0) {
          extern mxArray *sf_c13_Model1angular_jit_fallback_info(void);
          plhs[0] = sf_c13_Model1angular_jit_fallback_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "l1iTpMTMq75htSBX6uzriE") == 0) {
          extern mxArray *sf_c14_Model1angular_jit_fallback_info(void);
          plhs[0] = sf_c14_Model1angular_jit_fallback_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "blSJtnn3wEz7YP12eUHsp") == 0) {
          extern mxArray *sf_c15_Model1angular_jit_fallback_info(void);
          plhs[0] = sf_c15_Model1angular_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Model1angular_updateBuildInfo_args_info( int nlhs, mxArray *
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
        if (strcmp(tpChksum, "P1dYCZx9rGqBcCx1mQc6lB") == 0) {
          extern mxArray *sf_c1_Model1angular_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_Model1angular_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "q2jVn1cah8Bq9NT7sS3xoD") == 0) {
          extern mxArray *sf_c2_Model1angular_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_Model1angular_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "YSYjhN9Bdi4ZskpaslZJZH") == 0) {
          extern mxArray *sf_c3_Model1angular_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_Model1angular_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "7nuwuG0iPxITiDbjvx8viB") == 0) {
          extern mxArray *sf_c4_Model1angular_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_Model1angular_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "5m49HvbqLxSHC3gaxvNOFE") == 0) {
          extern mxArray *sf_c5_Model1angular_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_Model1angular_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "ibOSl01g2LPaZv5XAoV85") == 0) {
          extern mxArray *sf_c7_Model1angular_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_Model1angular_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "G7MbDKDUKcNv6S6WZQzlYC") == 0) {
          extern mxArray *sf_c8_Model1angular_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_Model1angular_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "z4BPNgk5OZMSp1i2ZiCQAH") == 0) {
          extern mxArray *sf_c9_Model1angular_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_Model1angular_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "SyMMPbImyp5DSf4al94PfG") == 0) {
          extern mxArray *sf_c10_Model1angular_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_Model1angular_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "btha56Bn9yFTbSB1RQmCG") == 0) {
          extern mxArray *sf_c11_Model1angular_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_Model1angular_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "ThNgAJCG0BraiZarLo5kWG") == 0) {
          extern mxArray *sf_c12_Model1angular_updateBuildInfo_args_info(void);
          plhs[0] = sf_c12_Model1angular_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "IMcJtTOCVxop0MIpJrKp1D") == 0) {
          extern mxArray *sf_c13_Model1angular_updateBuildInfo_args_info(void);
          plhs[0] = sf_c13_Model1angular_updateBuildInfo_args_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "l1iTpMTMq75htSBX6uzriE") == 0) {
          extern mxArray *sf_c14_Model1angular_updateBuildInfo_args_info(void);
          plhs[0] = sf_c14_Model1angular_updateBuildInfo_args_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "blSJtnn3wEz7YP12eUHsp") == 0) {
          extern mxArray *sf_c15_Model1angular_updateBuildInfo_args_info(void);
          plhs[0] = sf_c15_Model1angular_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void sf_Model1angular_get_post_codegen_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  unsigned int chartFileNumber = (unsigned int) mxGetScalar(prhs[0]);
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  switch (chartFileNumber) {
   case 1:
    {
      if (strcmp(tpChksum, "P1dYCZx9rGqBcCx1mQc6lB") == 0) {
        extern mxArray *sf_c1_Model1angular_get_post_codegen_info(void);
        plhs[0] = sf_c1_Model1angular_get_post_codegen_info();
        return;
      }
    }
    break;

   case 2:
    {
      if (strcmp(tpChksum, "q2jVn1cah8Bq9NT7sS3xoD") == 0) {
        extern mxArray *sf_c2_Model1angular_get_post_codegen_info(void);
        plhs[0] = sf_c2_Model1angular_get_post_codegen_info();
        return;
      }
    }
    break;

   case 3:
    {
      if (strcmp(tpChksum, "YSYjhN9Bdi4ZskpaslZJZH") == 0) {
        extern mxArray *sf_c3_Model1angular_get_post_codegen_info(void);
        plhs[0] = sf_c3_Model1angular_get_post_codegen_info();
        return;
      }
    }
    break;

   case 4:
    {
      if (strcmp(tpChksum, "7nuwuG0iPxITiDbjvx8viB") == 0) {
        extern mxArray *sf_c4_Model1angular_get_post_codegen_info(void);
        plhs[0] = sf_c4_Model1angular_get_post_codegen_info();
        return;
      }
    }
    break;

   case 5:
    {
      if (strcmp(tpChksum, "5m49HvbqLxSHC3gaxvNOFE") == 0) {
        extern mxArray *sf_c5_Model1angular_get_post_codegen_info(void);
        plhs[0] = sf_c5_Model1angular_get_post_codegen_info();
        return;
      }
    }
    break;

   case 7:
    {
      if (strcmp(tpChksum, "ibOSl01g2LPaZv5XAoV85") == 0) {
        extern mxArray *sf_c7_Model1angular_get_post_codegen_info(void);
        plhs[0] = sf_c7_Model1angular_get_post_codegen_info();
        return;
      }
    }
    break;

   case 8:
    {
      if (strcmp(tpChksum, "G7MbDKDUKcNv6S6WZQzlYC") == 0) {
        extern mxArray *sf_c8_Model1angular_get_post_codegen_info(void);
        plhs[0] = sf_c8_Model1angular_get_post_codegen_info();
        return;
      }
    }
    break;

   case 9:
    {
      if (strcmp(tpChksum, "z4BPNgk5OZMSp1i2ZiCQAH") == 0) {
        extern mxArray *sf_c9_Model1angular_get_post_codegen_info(void);
        plhs[0] = sf_c9_Model1angular_get_post_codegen_info();
        return;
      }
    }
    break;

   case 10:
    {
      if (strcmp(tpChksum, "SyMMPbImyp5DSf4al94PfG") == 0) {
        extern mxArray *sf_c10_Model1angular_get_post_codegen_info(void);
        plhs[0] = sf_c10_Model1angular_get_post_codegen_info();
        return;
      }
    }
    break;

   case 11:
    {
      if (strcmp(tpChksum, "btha56Bn9yFTbSB1RQmCG") == 0) {
        extern mxArray *sf_c11_Model1angular_get_post_codegen_info(void);
        plhs[0] = sf_c11_Model1angular_get_post_codegen_info();
        return;
      }
    }
    break;

   case 12:
    {
      if (strcmp(tpChksum, "ThNgAJCG0BraiZarLo5kWG") == 0) {
        extern mxArray *sf_c12_Model1angular_get_post_codegen_info(void);
        plhs[0] = sf_c12_Model1angular_get_post_codegen_info();
        return;
      }
    }
    break;

   case 13:
    {
      if (strcmp(tpChksum, "IMcJtTOCVxop0MIpJrKp1D") == 0) {
        extern mxArray *sf_c13_Model1angular_get_post_codegen_info(void);
        plhs[0] = sf_c13_Model1angular_get_post_codegen_info();
        return;
      }
    }
    break;

   case 14:
    {
      if (strcmp(tpChksum, "l1iTpMTMq75htSBX6uzriE") == 0) {
        extern mxArray *sf_c14_Model1angular_get_post_codegen_info(void);
        plhs[0] = sf_c14_Model1angular_get_post_codegen_info();
        return;
      }
    }
    break;

   case 15:
    {
      if (strcmp(tpChksum, "blSJtnn3wEz7YP12eUHsp") == 0) {
        extern mxArray *sf_c15_Model1angular_get_post_codegen_info(void);
        plhs[0] = sf_c15_Model1angular_get_post_codegen_info();
        return;
      }
    }
    break;

   default:
    break;
  }

  plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
}

void Model1angular_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _Model1angularMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "Model1angular","sfun",0,14,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _Model1angularMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _Model1angularMachineNumber_,0);
}

void Model1angular_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_Model1angular_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("Model1angular",
      "Model1angular");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_Model1angular_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}

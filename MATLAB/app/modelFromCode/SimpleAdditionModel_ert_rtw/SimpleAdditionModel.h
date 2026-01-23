/*
 * File: SimpleAdditionModel.h
 *
 * Code generated for Simulink model 'SimpleAdditionModel'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Jan 22 17:22:47 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef SimpleAdditionModel_h_
#define SimpleAdditionModel_h_
#ifndef SimpleAdditionModel_COMMON_INCLUDES_
#define SimpleAdditionModel_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                /* SimpleAdditionModel_COMMON_INCLUDES_ */

#include "SimpleAdditionModel_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Output;                       /* '<Root>/Output' */
} ExtY_SimpleAdditionModel_T;

/* Real-time Model Data Structure */
struct tag_RTM_SimpleAdditionModel_T {
  const char_T * volatile errorStatus;
};

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_SimpleAdditionModel_T SimpleAdditionModel_Y;

/* Model entry point functions */
extern void SimpleAdditionModel_initialize(void);
extern void SimpleAdditionModel_step(void);
extern void SimpleAdditionModel_terminate(void);

/* Real-time Model object */
extern RT_MODEL_SimpleAdditionModel_T *const SimpleAdditionModel_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SimpleAdditionModel'
 */
#endif                                 /* SimpleAdditionModel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

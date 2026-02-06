/*
 * File: basic_add_subtract.h
 *
 * Code generated for Simulink model 'basic_add_subtract'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed Jan 28 11:26:06 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef basic_add_subtract_h_
#define basic_add_subtract_h_
#ifndef basic_add_subtract_COMMON_INCLUDES_
#define basic_add_subtract_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* basic_add_subtract_COMMON_INCLUDES_ */

#include "basic_add_subtract_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T input1;                       /* '<Root>/input1' */
  real_T control;                      /* '<Root>/control' */
  real_T input2;                       /* '<Root>/input2' */
} ExtU_basic_add_subtract_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T output;                       /* '<Root>/output' */
} ExtY_basic_add_subtract_T;

/* Real-time Model Data Structure */
struct tag_RTM_basic_add_subtract_T {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with default storage) */
extern ExtU_basic_add_subtract_T basic_add_subtract_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_basic_add_subtract_T basic_add_subtract_Y;

/* Model entry point functions */
extern void basic_add_subtract_initialize(void);
extern void basic_add_subtract_step(void);
extern void basic_add_subtract_terminate(void);

/* Real-time Model object */
extern RT_MODEL_basic_add_subtract_T *const basic_add_subtract_M;

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
 * '<Root>' : 'basic_add_subtract'
 */
#endif                                 /* basic_add_subtract_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

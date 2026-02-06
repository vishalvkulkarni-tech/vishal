/*
 * File: basic_add_subtract.c
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

#include "basic_add_subtract.h"

/* External inputs (root inport signals with default storage) */
ExtU_basic_add_subtract_T basic_add_subtract_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_basic_add_subtract_T basic_add_subtract_Y;

/* Real-time model */
static RT_MODEL_basic_add_subtract_T basic_add_subtract_M_;
RT_MODEL_basic_add_subtract_T *const basic_add_subtract_M =
  &basic_add_subtract_M_;

/* Model step function */
void basic_add_subtract_step(void)
{
  /* Switch: '<Root>/Switch' incorporates:
   *  Inport: '<Root>/control'
   */
  if (basic_add_subtract_U.control != 0.0) {
    /* Outport: '<Root>/output' incorporates:
     *  Inport: '<Root>/input1'
     *  Inport: '<Root>/input2'
     *  Sum: '<Root>/Add'
     */
    basic_add_subtract_Y.output = basic_add_subtract_U.input1 +
      basic_add_subtract_U.input2;
  } else {
    /* Outport: '<Root>/output' incorporates:
     *  Inport: '<Root>/input1'
     *  Inport: '<Root>/input2'
     *  Sum: '<Root>/Add1'
     */
    basic_add_subtract_Y.output = basic_add_subtract_U.input1 -
      basic_add_subtract_U.input2;
  }

  /* End of Switch: '<Root>/Switch' */
}

/* Model initialize function */
void basic_add_subtract_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void basic_add_subtract_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

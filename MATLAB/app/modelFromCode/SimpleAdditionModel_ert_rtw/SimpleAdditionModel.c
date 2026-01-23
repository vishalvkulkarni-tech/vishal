/*
 * File: SimpleAdditionModel.c
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

#include "SimpleAdditionModel.h"

/* External outputs (root outports fed by signals with default storage) */
ExtY_SimpleAdditionModel_T SimpleAdditionModel_Y;

/* Real-time model */
static RT_MODEL_SimpleAdditionModel_T SimpleAdditionModel_M_;
RT_MODEL_SimpleAdditionModel_T *const SimpleAdditionModel_M =
  &SimpleAdditionModel_M_;

/* Model step function */
void SimpleAdditionModel_step(void)
{
  /* Outport: '<Root>/Output' incorporates:
   *  Constant: '<Root>/Param1'
   *  Constant: '<Root>/Param2'
   *  Sum: '<Root>/Add'
   */
  SimpleAdditionModel_Y.Output = 30.0;
}

/* Model initialize function */
void SimpleAdditionModel_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void SimpleAdditionModel_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

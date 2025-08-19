/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * File: model1_normal.c
 *
 * Code generated for Simulink model 'model1_normal'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Mon Jan 27 16:17:24 2025
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "model1_normal.h"

/* Model step function */
void model1_normal_Step(void)
{
  /* Outport: '<Root>/Out1' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   *  Sum: '<Root>/Sum'
   */
  Rte_IWrite_model1_normal_Step_Out1_Out1(Rte_IRead_model1_normal_Step_In1_In1()
    + Rte_IRead_model1_normal_Step_In2_In2());
}

/* Model initialize function */
void model1_normal_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

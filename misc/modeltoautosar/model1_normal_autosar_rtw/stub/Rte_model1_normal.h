/* This file contains stub implementations of the AUTOSAR RTE functions.
   The stub implementations can be used for testing the generated code in
   Simulink, for example, in SIL/PIL simulations of the component under
   test. Note that this file should be replaced with an appropriate RTE
   file when deploying the generated code outside of Simulink.

   This file is generated for:
   Atomic software component:  "model1_normal"
   ARXML schema: "R23-11"
   File generated on: "Mon Jan 27 16:17:37 2025"  */

#ifndef Rte_model1_normal_h
#define Rte_model1_normal_h
#include "Rte_Type.h"
#include "Compiler.h"

/* Data access functions */
#define Rte_IRead_model1_normal_Step_In1_In1 Rte_IRead_model1_normal_model1_normal_Step_In1_In1

float64 Rte_IRead_model1_normal_Step_In1_In1(void);

#define Rte_IRead_model1_normal_Step_In2_In2 Rte_IRead_model1_normal_model1_normal_Step_In2_In2

float64 Rte_IRead_model1_normal_Step_In2_In2(void);

#define Rte_IWrite_model1_normal_Step_Out1_Out1 Rte_IWrite_model1_normal_model1_normal_Step_Out1_Out1

void Rte_IWrite_model1_normal_Step_Out1_Out1(float64 u);

#define Rte_IWriteRef_model1_normal_Step_Out1_Out1 Rte_IWriteRef_model1_normal_model1_normal_Step_Out1_Out1

float64* Rte_IWriteRef_model1_normal_Step_Out1_Out1(void);

/* Entry point functions */
extern FUNC(void, model1_normal_CODE) model1_normal_Init(void);
extern FUNC(void, model1_normal_CODE) model1_normal_Step(void);

#endif

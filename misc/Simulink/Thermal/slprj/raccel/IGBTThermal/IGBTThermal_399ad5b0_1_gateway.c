#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif
#include "nesl_rtw.h"
#include "IGBTThermal_399ad5b0_1.h"
#include "IGBTThermal_399ad5b0_1_gateway.h"
void IGBTThermal_399ad5b0_1_gateway ( void ) { NeModelParameters modelparams
= { ( NeSolverType ) 0 , 0.001 , 0.001 , 0.001 , 1 , 0 , ( NeModifyAbsTol ) 0
, 0.001 , 0 , 0 , 0 , 0 , ( SscLoggingSetting ) 1 , 629723842 , 0 , 0 , 0 , }
; NeSolverParameters solverparams = { 0 , 0 , 1 , 0 , 0 , 0.001 , 1e-06 ,
1e-09 , 0 , 0 , 100 , 0 , 1 , ( NeConsistencySolver ) 0 , (
NeIndexReductionMethod ) 1 , 0 , 1e-09 , ( NeToleranceSource ) 1 , 0.001 ,
0.001 , 0.001 , 0 , ( NeLocalSolverChoice ) 0 , 1 , 1 , 5e-07 , 0 , 3 , 2 , 0
, 2 , ( NeLinearAlgebraChoice ) 0 , 0 , ( NeEquationFormulationChoice ) 0 ,
1024 , 1 , 0.001 , ( NePartitionStorageMethod ) 0 , 1024 , (
NePartitionMethod ) 1 , 0 , ( NeMultibodyLocalSolverChoice ) 0 , 0.001 , } ;
const NeOutputParameters * outputparameters = NULL ; NeDae * dae ; size_t
numOutputs = 0 ; int rtpDaes [ 1 ] = { 0 } ; int rtwLogDaes [ 1 ] = { 0 } ;
int * solverHitDaes = NULL ; IGBTThermal_399ad5b0_1_dae ( & dae , &
modelparams , & solverparams ) ; nesl_register_simulator_group (
"IGBTThermal/Solver Configuration1_1" , 1 , & dae , & solverparams , &
modelparams , numOutputs , outputparameters , 1 , rtpDaes , 1 , rtwLogDaes ,
0 , solverHitDaes ) ; }

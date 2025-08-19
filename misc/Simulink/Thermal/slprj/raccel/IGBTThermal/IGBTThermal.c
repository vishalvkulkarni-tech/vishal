#include "IGBTThermal.h"
#include <stdlib.h>
#include "rtwtypes.h"
#include <stddef.h>
#include "IGBTThermal_types.h"
#include "mwmathutil.h"
#include <string.h>
#include <float.h>
#include "IGBTThermal_private.h"
#include "rt_logging_mmi.h"
#include "IGBTThermal_capi.h"
#include "IGBTThermal_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; extern ssExecutionInfo gblExecutionInfo ; RTWExtModeInfo *
gblRTWExtModeInfo = NULL ; void raccelForceExtModeShutdown ( boolean_T
extModeStartPktReceived ) { if ( ! extModeStartPktReceived ) { boolean_T
stopRequested = false ; rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 4 , &
stopRequested ) ; } rtExtModeShutdown ( 4 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 5 ; const char_T
* gbl_raccel_Version = "23.2 (R2023b) 01-Aug-2023" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; int_T enableFcnCallFlag [ ] = { 1 , 1 , 1 , 1 , 1 }
; const char * raccelLoadInputsAndAperiodicHitTimes ( SimStruct * S , const
char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
const real_T IGBTThermal_RGND = 0.0 ; B rtB ; X rtX ; DW rtDW ; PrevZCX
rtPrevZCX ; MassMatrix rtMassMatrix ; static SimStruct model_S ; SimStruct *
const rtS = & model_S ; void MdlInitialize ( void ) { int_T tmp_e ; int_T
tmp_f ; int_T tmp_g ; int_T tmp_i ; int_T tmp_j ; int_T tmp_m ; boolean_T tmp
; boolean_T tmp_p ; SimStruct * S ; void * diag ; tmp = false ; tmp_p = false
; if ( tmp_p || tmp ) { tmp_e = strcmp ( ssGetSolverName ( rtS ) , "daessc" )
; tmp_i = strcmp ( ssGetSolverName ( rtS ) , "ode14x" ) ; tmp_m = strcmp (
ssGetSolverName ( rtS ) , "ode15s" ) ; tmp_g = strcmp ( ssGetSolverName ( rtS
) , "ode1be" ) ; tmp_j = strcmp ( ssGetSolverName ( rtS ) , "ode23t" ) ;
tmp_f = strcmp ( ssGetSolverName ( rtS ) , "odeN" ) ; if ( ( boolean_T ) ( (
tmp_e != 0 ) & ( tmp_i != 0 ) & ( tmp_m != 0 ) & ( tmp_g != 0 ) & ( tmp_j !=
0 ) & ( tmp_f != 0 ) ) ) { S = rtS ; diag = CreateDiagnosticAsVoidPtr (
 "physmod:simscape:engine:sli:SimscapeExecutionBlock:InconsistentSolversInModelRef"
, 2 , 3 , "ode23t" , 3 , "{daessc, ode14x, ode15s, ode1be, ode23t, odeN}" ) ;
rt_ssSet_slErrMsg ( S , diag ) ; } } { static int_T modelMassMatrixIr [ 39 ]
= { 0 , 1 , 2 , 3 , 4 , 19 , 20 , 24 , 25 , 5 , 19 , 20 , 24 , 25 , 6 , 19 ,
20 , 24 , 25 , 7 , 19 , 20 , 24 , 25 , 9 , 21 , 10 , 11 , 12 , 19 , 20 , 24 ,
25 , 8 , 19 , 20 , 21 , 24 , 25 } ; static int_T modelMassMatrixJc [ 27 ] = {
0 , 1 , 2 , 3 , 4 , 9 , 14 , 19 , 24 , 26 , 27 , 28 , 33 , 39 , 39 , 39 , 39
, 39 , 39 , 39 , 39 , 39 , 39 , 39 , 39 , 39 , 39 } ; static real_T
modelMassMatrixPr [ 39 ] = { 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 ,
1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 ,
1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 ,
1.0 , 1.0 , 1.0 , 1.0 , 1.0 } ; ( void ) memcpy ( rtMassMatrix . ir ,
modelMassMatrixIr , 39 * sizeof ( int_T ) ) ; ( void ) memcpy ( rtMassMatrix
. jc , modelMassMatrixJc , 27 * sizeof ( int_T ) ) ; ( void ) memcpy (
rtMassMatrix . pr , modelMassMatrixPr , 39 * sizeof ( real_T ) ) ; } } void
MdlEnable ( void ) { rtDW . npc3xna3zg = 1 ; _ssSetSampleHit ( rtS , 2 , 1 )
; _ssSetTaskTime ( rtS , 2 , ssGetT ( rtS ) ) ; _ssSetVarNextHitTime ( rtS ,
0 , ssGetT ( rtS ) ) ; ; rtDW . po350bcjbl = 1 ; _ssSetSampleHit ( rtS , 3 ,
1 ) ; _ssSetTaskTime ( rtS , 3 , ssGetT ( rtS ) ) ; _ssSetVarNextHitTime (
rtS , 1 , ssGetT ( rtS ) ) ; ; } void MdlStart ( void ) { CXPtMax *
_rtXPerturbMax ; CXPtMin * _rtXPerturbMin ; NeModelParameters modelParameters
; NeslRtpManager * manager ; NeslRtpManager * manager_p ; NeslSimulationData
* simulationData ; NeslSimulator * tmp_p ; NeuDiagnosticManager *
diagnosticManager ; NeuDiagnosticTree * diagnosticTree ; NeuDiagnosticTree *
diagnosticTree_p ; SscRTWLogFcnManager * rtwLogManager ; SscRTWLogFcnManager
* rtwLogManager_p ; SscRTWLogging * tmp_j ; char * msg ; char * msg_p ;
real_T tmp_m [ 4 ] ; real_T time ; real_T tmp_e ; int32_T tmp_i ; int_T tmp_g
[ 2 ] ; boolean_T directFeedThrough [ 2 ] ; boolean_T tmp ; boolean_T val ; {
bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} _rtXPerturbMax = ( ( CXPtMax * ) ssGetJacobianPerturbationBoundsMaxVec (
rtS ) ) ; _rtXPerturbMin = ( ( CXPtMin * )
ssGetJacobianPerturbationBoundsMinVec ( rtS ) ) ; { RTWLogSignalInfo
rt_ScopeSignalInfo ; static int_T rt_ScopeSignalWidths [ ] = { 1 } ; static
int_T rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 1 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 1 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] = "IGBTThermal/Scope" ;
static int_T rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . md305jkrjz . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Scope1Data" , 1 , 50000 , 1 , rtInf , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . md305jkrjz .
LoggedData == ( NULL ) ) return ; } manager_p = nesl_lease_rtp_manager (
"IGBTThermal/Solver Configuration1_1" , 0 ) ; manager = manager_p ; tmp =
pointer_is_null ( manager_p ) ; if ( tmp ) { IGBTThermal_399ad5b0_1_gateway (
) ; manager = nesl_lease_rtp_manager ( "IGBTThermal/Solver Configuration1_1"
, 0 ) ; } rtDW . o3b342cdix = ( void * ) manager ; rtDW . dmisypodkz = true ;
tmp_p = nesl_lease_simulator ( "IGBTThermal/Solver Configuration1_1" , 0 , 0
) ; rtDW . neueknlloj = ( void * ) tmp_p ; tmp = pointer_is_null ( rtDW .
neueknlloj ) ; if ( tmp ) { IGBTThermal_399ad5b0_1_gateway ( ) ; tmp_p =
nesl_lease_simulator ( "IGBTThermal/Solver Configuration1_1" , 0 , 0 ) ; rtDW
. neueknlloj = ( void * ) tmp_p ; } slsaSaveRawMemoryForSimTargetOP ( rtS ,
"IGBTThermal/Solver Configuration1_100" , ( void * * ) ( & rtDW . neueknlloj
) , 0U * sizeof ( real_T ) , nesl_save_simdata , nesl_restore_simdata ) ;
simulationData = nesl_create_simulation_data ( ) ; rtDW . fmv0dg0a4q = ( void
* ) simulationData ; diagnosticManager = rtw_create_diagnostics ( ) ; rtDW .
ovgmafyfkv = ( void * ) diagnosticManager ; modelParameters . mSolverType =
NE_SOLVER_TYPE_DAE ; modelParameters . mSolverAbsTol = 0.001 ;
modelParameters . mSolverRelTol = 0.001 ; modelParameters .
mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO ; modelParameters . mStartTime =
0.0 ; modelParameters . mLoadInitialState = false ; modelParameters .
mUseSimState = false ; modelParameters . mLinTrimCompile = false ;
modelParameters . mLoggingMode = SSC_LOGGING_ON ; modelParameters .
mRTWModifiedTimeStamp = 6.29723842E+8 ; modelParameters . mZcDisabled = false
; modelParameters . mUseModelRefSolver = false ; modelParameters .
mTargetFPGAHIL = false ; tmp_e = 0.001 ; modelParameters . mSolverTolerance =
tmp_e ; tmp_e = 0.0 ; modelParameters . mFixedStepSize = tmp_e ; tmp = true ;
modelParameters . mVariableStepSolver = tmp ; tmp = false ; modelParameters .
mIsUsingODEN = tmp ; tmp = slIsRapidAcceleratorSimulating ( ) ; val =
ssGetGlobalInitialStatesAvailable ( rtS ) ; if ( tmp ) { val = ( val &&
ssIsFirstInitCond ( rtS ) ) ; } modelParameters . mLoadInitialState = val ;
modelParameters . mZcDisabled = false ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . ovgmafyfkv ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp_i =
nesl_initialize_simulator ( ( NeslSimulator * ) rtDW . neueknlloj , &
modelParameters , diagnosticManager ) ; if ( tmp_i != 0 ) { tmp =
error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulationData = ( NeslSimulationData * ) rtDW . fmv0dg0a4q ; time = ssGetT (
rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time ; simulationData -> mData -> mContStates . mN = 26 ;
simulationData -> mData -> mContStates . mX = & rtX . ivwbjv4zes [ 0 ] ;
simulationData -> mData -> mDiscStates . mN = 81 ; simulationData -> mData ->
mDiscStates . mX = & rtDW . dabkhrlstr [ 0 ] ; simulationData -> mData ->
mModeVector . mN = 58 ; simulationData -> mData -> mModeVector . mX = & rtDW
. oooz0jah34 [ 0 ] ; tmp = ( ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo
( rtS ) -> foundContZcEvents ) ; simulationData -> mData -> mFoundZcEvents =
tmp ; simulationData -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS )
; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; tmp =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp ; tmp = ssIsSolverComputingJacobian ( rtS ) ;
simulationData -> mData -> mIsComputingJacobian = tmp ; simulationData ->
mData -> mIsEvaluatingF0 = ( ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ;
tmp = ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData ->
mIsSolverRequestingReset = tmp ; simulationData -> mData ->
mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep ( rtS ) ; tmp_g [ 0 ] = 0 ;
tmp_m [ 0 ] = rtB . asbpxve2fe [ 0 ] ; tmp_m [ 1 ] = rtB . asbpxve2fe [ 1 ] ;
tmp_m [ 2 ] = rtB . asbpxve2fe [ 2 ] ; tmp_m [ 3 ] = rtB . asbpxve2fe [ 3 ] ;
tmp_g [ 1 ] = 4 ; simulationData -> mData -> mInputValues . mN = 4 ;
simulationData -> mData -> mInputValues . mX = & tmp_m [ 0 ] ; simulationData
-> mData -> mInputOffsets . mN = 2 ; simulationData -> mData -> mInputOffsets
. mX = & tmp_g [ 0 ] ; simulationData -> mData -> mNumjacDxLo . mN = 26 ;
simulationData -> mData -> mNumjacDxLo . mX = & _rtXPerturbMin -> ivwbjv4zes
[ 0 ] ; simulationData -> mData -> mNumjacDxHi . mN = 26 ; simulationData ->
mData -> mNumjacDxHi . mX = & _rtXPerturbMax -> ivwbjv4zes [ 0 ] ;
diagnosticManager = ( NeuDiagnosticManager * ) rtDW . ovgmafyfkv ;
diagnosticTree_p = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_i = ne_simulator_method ( ( NeslSimulator * ) rtDW
. neueknlloj , NESL_SIM_NUMJAC_DX_BOUNDS , simulationData , diagnosticManager
) ; if ( tmp_i != 0 ) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS
) ) ; if ( tmp ) { msg_p = rtw_diagnostics_msg ( diagnosticTree_p ) ;
ssSetErrorStatus ( rtS , msg_p ) ; } } tmp_j = ssc_rtw_make_logging_struct (
"IGBTThermal" , "Solver Configuration1/EVAL_KEY/SINK_1" , 147U ) ; rtDW .
js4kj4cuzy = ( void * ) tmp_j ; rtDW . bfynxmcvmi = calloc ( 147U , 8U ) ;
directFeedThrough [ 0 ] = true ; directFeedThrough [ 1 ] = true ;
rtwLogManager_p = ssc_lease_rtw_log_fcn_manager (
"IGBTThermal/Solver Configuration1_1" , 0 , 2U , directFeedThrough , 4U ,
147U ) ; rtwLogManager = rtwLogManager_p ; tmp = pointer_is_null (
rtwLogManager_p ) ; if ( tmp ) { IGBTThermal_399ad5b0_1_gateway ( ) ;
rtwLogManager = ssc_lease_rtw_log_fcn_manager (
"IGBTThermal/Solver Configuration1_1" , 0 , 2U , directFeedThrough , 4U ,
147U ) ; } rtDW . edlibngn3n = ( void * ) rtwLogManager ; if ( rtDW .
edlibngn3n != NULL ) { ssc_rtw_setup_log_fcn ( rtDW . edlibngn3n ) ; }
ssc_logger_start ( rtDW . js4kj4cuzy ) ; MdlInitialize ( ) ; MdlEnable ( ) ;
} void MdlOutputs ( int_T tid ) { NeParameterBundle expl_temp ;
NeslSimulationData * simulationData ; NeuDiagnosticManager * diag ;
NeuDiagnosticTree * diagTree ; NeuDiagnosticTree * diagnosticTree ; char *
msg ; char * msg_p ; real_T tmp_i [ 105 ] ; real_T tmp [ 6 ] ; real_T tmp_p [
4 ] ; real_T ratio ; real_T taskTimeV ; real_T time ; real_T time_p ; real_T
* parameterBundle_mRealParameters_mX ; int_T tmp_e [ 2 ] ; int_T j ; uint32_T
numCycles ; boolean_T ok ; if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { taskTimeV =
ssGetTaskTime ( rtS , 2 ) ; if ( ssGetTNextWasAdjusted ( rtS , 2 ) ) { rtDW .
l0gf3i5n0p = _ssGetVarNextHitTime ( rtS , 0 ) ; } if ( rtDW . npc3xna3zg != 0
) { rtDW . npc3xna3zg = 0 ; if ( taskTimeV >= rtP .
GateDriveatFreq1_PhaseDelay ) { ratio = ( taskTimeV - rtP .
GateDriveatFreq1_PhaseDelay ) / rtP . GateDriveatFreq1_Period ; numCycles = (
uint32_T ) muDoubleScalarFloor ( ratio ) ; if ( muDoubleScalarAbs ( ( real_T
) ( numCycles + 1U ) - ratio ) < DBL_EPSILON * ratio ) { numCycles ++ ; }
rtDW . mtoyvs1lsx = numCycles ; ratio = ( ( real_T ) numCycles * rtP .
GateDriveatFreq1_Period + rtP . GateDriveatFreq1_PhaseDelay ) + rtP .
GateDriveatFreq1_Duty * rtP . GateDriveatFreq1_Period / 100.0 ; if (
taskTimeV < ratio ) { rtDW . bwzok3eybt = 1 ; rtDW . l0gf3i5n0p = ratio ; }
else { rtDW . bwzok3eybt = 0 ; rtDW . l0gf3i5n0p = ( real_T ) ( numCycles +
1U ) * rtP . GateDriveatFreq1_Period + rtP . GateDriveatFreq1_PhaseDelay ; }
} else { if ( rtP . GateDriveatFreq1_PhaseDelay != 0.0 ) { rtDW . mtoyvs1lsx
= - 1LL ; } else { rtDW . mtoyvs1lsx = 0LL ; } rtDW . bwzok3eybt = 0 ; rtDW .
l0gf3i5n0p = rtP . GateDriveatFreq1_PhaseDelay ; } } else if ( rtDW .
l0gf3i5n0p <= taskTimeV ) { if ( rtDW . bwzok3eybt == 1 ) { rtDW . bwzok3eybt
= 0 ; rtDW . l0gf3i5n0p = ( real_T ) ( rtDW . mtoyvs1lsx + 1LL ) * rtP .
GateDriveatFreq1_Period + rtP . GateDriveatFreq1_PhaseDelay ; } else { rtDW .
mtoyvs1lsx ++ ; rtDW . bwzok3eybt = 1 ; rtDW . l0gf3i5n0p = ( rtP .
GateDriveatFreq1_Duty * rtP . GateDriveatFreq1_Period * 0.01 + ( real_T )
rtDW . mtoyvs1lsx * rtP . GateDriveatFreq1_Period ) + rtP .
GateDriveatFreq1_PhaseDelay ; } } _ssSetVarNextHitTime ( rtS , 0 , rtDW .
l0gf3i5n0p ) ; if ( rtDW . bwzok3eybt == 1 ) { rtB . mtl5fmzosb = rtP .
GateDriveatFreq1_Amp ; } else { rtB . mtl5fmzosb = 0.0 ; } } if (
ssIsSampleHit ( rtS , 3 , 0 ) ) { taskTimeV = ssGetTaskTime ( rtS , 3 ) ; if
( ssGetTNextWasAdjusted ( rtS , 3 ) ) { rtDW . netor1vfyv =
_ssGetVarNextHitTime ( rtS , 1 ) ; } if ( rtDW . po350bcjbl != 0 ) { rtDW .
po350bcjbl = 0 ; if ( taskTimeV >= rtP . GateDriveatFreq2_PhaseDelay ) {
ratio = ( taskTimeV - rtP . GateDriveatFreq2_PhaseDelay ) / rtP .
GateDriveatFreq2_Period ; numCycles = ( uint32_T ) muDoubleScalarFloor (
ratio ) ; if ( muDoubleScalarAbs ( ( real_T ) ( numCycles + 1U ) - ratio ) <
DBL_EPSILON * ratio ) { numCycles ++ ; } rtDW . bthvtfhgxh = numCycles ;
ratio = ( ( real_T ) numCycles * rtP . GateDriveatFreq2_Period + rtP .
GateDriveatFreq2_PhaseDelay ) + rtP . GateDriveatFreq2_Duty * rtP .
GateDriveatFreq2_Period / 100.0 ; if ( taskTimeV < ratio ) { rtDW .
klvwjtvlp5 = 1 ; rtDW . netor1vfyv = ratio ; } else { rtDW . klvwjtvlp5 = 0 ;
rtDW . netor1vfyv = ( real_T ) ( numCycles + 1U ) * rtP .
GateDriveatFreq2_Period + rtP . GateDriveatFreq2_PhaseDelay ; } } else { if (
rtP . GateDriveatFreq2_PhaseDelay != 0.0 ) { rtDW . bthvtfhgxh = - 1LL ; }
else { rtDW . bthvtfhgxh = 0LL ; } rtDW . klvwjtvlp5 = 0 ; rtDW . netor1vfyv
= rtP . GateDriveatFreq2_PhaseDelay ; } } else if ( rtDW . netor1vfyv <=
taskTimeV ) { if ( rtDW . klvwjtvlp5 == 1 ) { rtDW . klvwjtvlp5 = 0 ; rtDW .
netor1vfyv = ( real_T ) ( rtDW . bthvtfhgxh + 1LL ) * rtP .
GateDriveatFreq2_Period + rtP . GateDriveatFreq2_PhaseDelay ; } else { rtDW .
bthvtfhgxh ++ ; rtDW . klvwjtvlp5 = 1 ; rtDW . netor1vfyv = ( rtP .
GateDriveatFreq2_Duty * rtP . GateDriveatFreq2_Period * 0.01 + ( real_T )
rtDW . bthvtfhgxh * rtP . GateDriveatFreq2_Period ) + rtP .
GateDriveatFreq2_PhaseDelay ; } } _ssSetVarNextHitTime ( rtS , 1 , rtDW .
netor1vfyv ) ; if ( rtDW . klvwjtvlp5 == 1 ) { rtB . exyxnjbkxi = rtP .
GateDriveatFreq2_Amp ; } else { rtB . exyxnjbkxi = 0.0 ; } } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW . lqjazq4u1m = ( ssGetTaskTime ( rtS ,
1 ) >= rtP . Step_Time ) ; if ( rtDW . lqjazq4u1m == 1 ) { taskTimeV = rtP .
Step_YFinal ; } else { taskTimeV = rtP . Step_Y0 ; } if ( taskTimeV > rtP .
SwitchtoChangeDriveFrequency_Threshold ) { rtB . pjyzlfsjbp = rtB .
mtl5fmzosb ; } else { rtB . pjyzlfsjbp = rtB . exyxnjbkxi ; } if ( rtDW .
dmisypodkz ) { tmp [ 0 ] = rtP . RTP_56B3C423_vc_Value ; tmp [ 1 ] = rtP .
RTP_21B4F4B5_i_L_Value ; tmp [ 2 ] = rtP . RTP_E3A2801C_vc_Value ; tmp [ 3 ]
= rtP . RTP_ECBB6219_i_L_Value ; tmp [ 4 ] = rtP .
RTP_946ABF09_junction_temperature_Value ; tmp [ 5 ] = rtP .
RTP_E56942F7_junction_temperature_Value ; parameterBundle_mRealParameters_mX
= & tmp [ 0 ] ; diag = rtw_create_diagnostics ( ) ; diagTree =
neu_diagnostic_manager_get_initial_tree ( diag ) ; expl_temp .
mRealParameters . mN = 6 ; expl_temp . mRealParameters . mX =
parameterBundle_mRealParameters_mX ; expl_temp . mLogicalParameters . mN = 0
; expl_temp . mLogicalParameters . mX = NULL ; expl_temp . mIntegerParameters
. mN = 0 ; expl_temp . mIntegerParameters . mX = NULL ; expl_temp .
mIndexParameters . mN = 0 ; expl_temp . mIndexParameters . mX = NULL ; ok =
nesl_rtp_manager_set_rtps ( ( NeslRtpManager * ) rtDW . o3b342cdix , ssGetT (
rtS ) , expl_temp , diag ) ; if ( ! ok ) { ok = error_buffer_is_empty (
ssGetErrorStatus ( rtS ) ) ; if ( ok ) { msg = rtw_diagnostics_msg ( diagTree
) ; ssSetErrorStatus ( rtS , msg ) ; } } } rtDW . dmisypodkz = false ; } rtB
. asbpxve2fe [ 0 ] = rtB . pjyzlfsjbp ; rtB . asbpxve2fe [ 1 ] = 0.0 ; rtB .
asbpxve2fe [ 2 ] = 0.0 ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . noegxjaqfo
[ 0 ] = ! ( rtB . asbpxve2fe [ 0 ] == rtDW . noegxjaqfo [ 1 ] ) ; rtDW .
noegxjaqfo [ 1 ] = rtB . asbpxve2fe [ 0 ] ; } rtB . asbpxve2fe [ 0 ] = rtDW .
noegxjaqfo [ 1 ] ; rtB . asbpxve2fe [ 3 ] = rtDW . noegxjaqfo [ 0 ] ;
simulationData = ( NeslSimulationData * ) rtDW . fmv0dg0a4q ; time = ssGetT (
rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time ; simulationData -> mData -> mContStates . mN = 26 ;
simulationData -> mData -> mContStates . mX = & rtX . ivwbjv4zes [ 0 ] ;
simulationData -> mData -> mDiscStates . mN = 81 ; simulationData -> mData ->
mDiscStates . mX = & rtDW . dabkhrlstr [ 0 ] ; simulationData -> mData ->
mModeVector . mN = 58 ; simulationData -> mData -> mModeVector . mX = & rtDW
. oooz0jah34 [ 0 ] ; ok = ( ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo (
rtS ) -> foundContZcEvents ) ; simulationData -> mData -> mFoundZcEvents = ok
; simulationData -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ;
ok = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = ok ; ok =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = ok ; ok = ssIsSolverComputingJacobian ( rtS ) ;
simulationData -> mData -> mIsComputingJacobian = ok ; simulationData ->
mData -> mIsEvaluatingF0 = ( ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ; ok
= ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData ->
mIsSolverRequestingReset = ok ; simulationData -> mData ->
mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep ( rtS ) ; tmp_e [ 0 ] = 0 ;
tmp_p [ 0 ] = rtB . asbpxve2fe [ 0 ] ; tmp_p [ 1 ] = rtB . asbpxve2fe [ 1 ] ;
tmp_p [ 2 ] = rtB . asbpxve2fe [ 2 ] ; tmp_p [ 3 ] = rtB . asbpxve2fe [ 3 ] ;
tmp_e [ 1 ] = 4 ; simulationData -> mData -> mInputValues . mN = 4 ;
simulationData -> mData -> mInputValues . mX = & tmp_p [ 0 ] ; simulationData
-> mData -> mInputOffsets . mN = 2 ; simulationData -> mData -> mInputOffsets
. mX = & tmp_e [ 0 ] ; simulationData -> mData -> mOutputs . mN = 101 ;
simulationData -> mData -> mOutputs . mX = & rtB . fz5khlwt30 [ 0 ] ;
simulationData -> mData -> mTolerances . mN = 0 ; simulationData -> mData ->
mTolerances . mX = NULL ; simulationData -> mData -> mCstateHasChanged =
false ; time_p = ssGetTaskTime ( rtS , 0 ) ; simulationData -> mData -> mTime
. mN = 1 ; simulationData -> mData -> mTime . mX = & time_p ; simulationData
-> mData -> mSampleHits . mN = 0 ; simulationData -> mData -> mSampleHits .
mX = NULL ; simulationData -> mData -> mIsFundamentalSampleHit = false ; diag
= ( NeuDiagnosticManager * ) rtDW . ovgmafyfkv ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diag ) ; j = ne_simulator_method (
( NeslSimulator * ) rtDW . neueknlloj , NESL_SIM_OUTPUTS , simulationData ,
diag ) ; if ( j != 0 ) { ok = error_buffer_is_empty ( ssGetErrorStatus ( rtS
) ) ; if ( ok ) { msg_p = rtw_diagnostics_msg ( diagnosticTree ) ;
ssSetErrorStatus ( rtS , msg_p ) ; } } if ( ssIsMajorTimeStep ( rtS ) &&
simulationData -> mData -> mCstateHasChanged ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } if ( ( rtDW .
edlibngn3n != NULL ) && ssGetLogOutput ( rtS ) ) { tmp_i [ 0 ] = rtB .
asbpxve2fe [ 0 ] ; tmp_i [ 1 ] = rtB . asbpxve2fe [ 1 ] ; tmp_i [ 2 ] = rtB .
asbpxve2fe [ 2 ] ; tmp_i [ 3 ] = rtB . asbpxve2fe [ 3 ] ; memcpy ( & tmp_i [
4 ] , & rtB . fz5khlwt30 [ 0 ] , 101U * sizeof ( real_T ) ) ; ssc_rtw_log_fcn
( rtDW . edlibngn3n , ssGetT ( rtS ) , & tmp_i [ 0 ] , rtDW . bfynxmcvmi ) ;
} if ( ( rtDW . edlibngn3n != NULL ) && ssGetLogOutput ( rtS ) ) {
ssc_logger_log ( rtDW . js4kj4cuzy , ssGetT ( rtS ) , rtDW . bfynxmcvmi ) ; }
UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID4 ( int_T tid ) { if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
md305jkrjz . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 4 ) ; rt_UpdateLogVar ( ( LogVar * ) svar ->
time , & locTime , 0 ) ; } { real_T up0 [ 1 ] ; up0 [ 0 ] = 0.0 ;
rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; } } UNUSED_PARAMETER ( tid )
; } void MdlUpdate ( int_T tid ) { NeslSimulationData * simulationData ;
NeuDiagnosticManager * diagnosticManager ; NeuDiagnosticTree * diagnosticTree
; char * msg ; real_T tmp_p [ 4 ] ; real_T time ; int32_T tmp_i ; int_T tmp_e
[ 2 ] ; boolean_T tmp ; simulationData = ( NeslSimulationData * ) rtDW .
fmv0dg0a4q ; time = ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN =
1 ; simulationData -> mData -> mTime . mX = & time ; simulationData -> mData
-> mContStates . mN = 26 ; simulationData -> mData -> mContStates . mX = &
rtX . ivwbjv4zes [ 0 ] ; simulationData -> mData -> mDiscStates . mN = 81 ;
simulationData -> mData -> mDiscStates . mX = & rtDW . dabkhrlstr [ 0 ] ;
simulationData -> mData -> mModeVector . mN = 58 ; simulationData -> mData ->
mModeVector . mX = & rtDW . oooz0jah34 [ 0 ] ; tmp = ( ssIsMajorTimeStep (
rtS ) && ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents ) ; simulationData
-> mData -> mFoundZcEvents = tmp ; simulationData -> mData ->
mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp = ( ssGetMdlInfoPtr ( rtS
) -> mdlFlags . solverAssertCheck == 1U ) ; simulationData -> mData ->
mIsSolverAssertCheck = tmp ; tmp = ssIsSolverCheckingCIC ( rtS ) ;
simulationData -> mData -> mIsSolverCheckingCIC = tmp ; tmp =
ssIsSolverComputingJacobian ( rtS ) ; simulationData -> mData ->
mIsComputingJacobian = tmp ; simulationData -> mData -> mIsEvaluatingF0 = (
ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ; tmp = ssIsSolverRequestingReset
( rtS ) ; simulationData -> mData -> mIsSolverRequestingReset = tmp ;
simulationData -> mData -> mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep (
rtS ) ; tmp_e [ 0 ] = 0 ; tmp_p [ 0 ] = rtB . asbpxve2fe [ 0 ] ; tmp_p [ 1 ]
= rtB . asbpxve2fe [ 1 ] ; tmp_p [ 2 ] = rtB . asbpxve2fe [ 2 ] ; tmp_p [ 3 ]
= rtB . asbpxve2fe [ 3 ] ; tmp_e [ 1 ] = 4 ; simulationData -> mData ->
mInputValues . mN = 4 ; simulationData -> mData -> mInputValues . mX = &
tmp_p [ 0 ] ; simulationData -> mData -> mInputOffsets . mN = 2 ;
simulationData -> mData -> mInputOffsets . mX = & tmp_e [ 0 ] ;
diagnosticManager = ( NeuDiagnosticManager * ) rtDW . ovgmafyfkv ;
diagnosticTree = neu_diagnostic_manager_get_initial_tree ( diagnosticManager
) ; tmp_i = ne_simulator_method ( ( NeslSimulator * ) rtDW . neueknlloj ,
NESL_SIM_UPDATE , simulationData , diagnosticManager ) ; if ( tmp_i != 0 ) {
tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID4 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) {
NeslSimulationData * simulationData ; NeuDiagnosticManager *
diagnosticManager ; NeuDiagnosticTree * diagnosticTree ; XDot * _rtXdot ;
char * msg ; real_T tmp_p [ 4 ] ; real_T time ; int32_T tmp_i ; int_T tmp_e [
2 ] ; boolean_T tmp ; _rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ;
simulationData = ( NeslSimulationData * ) rtDW . fmv0dg0a4q ; time = ssGetT (
rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time ; simulationData -> mData -> mContStates . mN = 26 ;
simulationData -> mData -> mContStates . mX = & rtX . ivwbjv4zes [ 0 ] ;
simulationData -> mData -> mDiscStates . mN = 81 ; simulationData -> mData ->
mDiscStates . mX = & rtDW . dabkhrlstr [ 0 ] ; simulationData -> mData ->
mModeVector . mN = 58 ; simulationData -> mData -> mModeVector . mX = & rtDW
. oooz0jah34 [ 0 ] ; tmp = ( ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo
( rtS ) -> foundContZcEvents ) ; simulationData -> mData -> mFoundZcEvents =
tmp ; simulationData -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS )
; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; tmp =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp ; tmp = ssIsSolverComputingJacobian ( rtS ) ;
simulationData -> mData -> mIsComputingJacobian = tmp ; simulationData ->
mData -> mIsEvaluatingF0 = ( ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ;
tmp = ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData ->
mIsSolverRequestingReset = tmp ; simulationData -> mData ->
mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep ( rtS ) ; tmp_e [ 0 ] = 0 ;
tmp_p [ 0 ] = rtB . asbpxve2fe [ 0 ] ; tmp_p [ 1 ] = rtB . asbpxve2fe [ 1 ] ;
tmp_p [ 2 ] = rtB . asbpxve2fe [ 2 ] ; tmp_p [ 3 ] = rtB . asbpxve2fe [ 3 ] ;
tmp_e [ 1 ] = 4 ; simulationData -> mData -> mInputValues . mN = 4 ;
simulationData -> mData -> mInputValues . mX = & tmp_p [ 0 ] ; simulationData
-> mData -> mInputOffsets . mN = 2 ; simulationData -> mData -> mInputOffsets
. mX = & tmp_e [ 0 ] ; simulationData -> mData -> mDx . mN = 26 ;
simulationData -> mData -> mDx . mX = & _rtXdot -> ivwbjv4zes [ 0 ] ;
diagnosticManager = ( NeuDiagnosticManager * ) rtDW . ovgmafyfkv ;
diagnosticTree = neu_diagnostic_manager_get_initial_tree ( diagnosticManager
) ; tmp_i = ne_simulator_method ( ( NeslSimulator * ) rtDW . neueknlloj ,
NESL_SIM_DERIVATIVES , simulationData , diagnosticManager ) ; if ( tmp_i != 0
) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) {
msg = rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg )
; } } } void MdlProjection ( void ) { NeslSimulationData * simulationData ;
NeuDiagnosticManager * diagnosticManager ; NeuDiagnosticTree * diagnosticTree
; char * msg ; real_T tmp_p [ 4 ] ; real_T time ; int32_T tmp_i ; int_T tmp_e
[ 2 ] ; boolean_T tmp ; simulationData = ( NeslSimulationData * ) rtDW .
fmv0dg0a4q ; time = ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN =
1 ; simulationData -> mData -> mTime . mX = & time ; simulationData -> mData
-> mContStates . mN = 26 ; simulationData -> mData -> mContStates . mX = &
rtX . ivwbjv4zes [ 0 ] ; simulationData -> mData -> mDiscStates . mN = 81 ;
simulationData -> mData -> mDiscStates . mX = & rtDW . dabkhrlstr [ 0 ] ;
simulationData -> mData -> mModeVector . mN = 58 ; simulationData -> mData ->
mModeVector . mX = & rtDW . oooz0jah34 [ 0 ] ; tmp = ( ssIsMajorTimeStep (
rtS ) && ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents ) ; simulationData
-> mData -> mFoundZcEvents = tmp ; simulationData -> mData ->
mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp = ( ssGetMdlInfoPtr ( rtS
) -> mdlFlags . solverAssertCheck == 1U ) ; simulationData -> mData ->
mIsSolverAssertCheck = tmp ; tmp = ssIsSolverCheckingCIC ( rtS ) ;
simulationData -> mData -> mIsSolverCheckingCIC = tmp ; tmp =
ssIsSolverComputingJacobian ( rtS ) ; simulationData -> mData ->
mIsComputingJacobian = tmp ; simulationData -> mData -> mIsEvaluatingF0 = (
ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ; tmp = ssIsSolverRequestingReset
( rtS ) ; simulationData -> mData -> mIsSolverRequestingReset = tmp ;
simulationData -> mData -> mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep (
rtS ) ; tmp_e [ 0 ] = 0 ; tmp_p [ 0 ] = rtB . asbpxve2fe [ 0 ] ; tmp_p [ 1 ]
= rtB . asbpxve2fe [ 1 ] ; tmp_p [ 2 ] = rtB . asbpxve2fe [ 2 ] ; tmp_p [ 3 ]
= rtB . asbpxve2fe [ 3 ] ; tmp_e [ 1 ] = 4 ; simulationData -> mData ->
mInputValues . mN = 4 ; simulationData -> mData -> mInputValues . mX = &
tmp_p [ 0 ] ; simulationData -> mData -> mInputOffsets . mN = 2 ;
simulationData -> mData -> mInputOffsets . mX = & tmp_e [ 0 ] ;
diagnosticManager = ( NeuDiagnosticManager * ) rtDW . ovgmafyfkv ;
diagnosticTree = neu_diagnostic_manager_get_initial_tree ( diagnosticManager
) ; tmp_i = ne_simulator_method ( ( NeslSimulator * ) rtDW . neueknlloj ,
NESL_SIM_PROJECTION , simulationData , diagnosticManager ) ; if ( tmp_i != 0
) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) {
msg = rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg )
; } } } void MdlForcingFunction ( void ) { NeslSimulationData *
simulationData ; NeuDiagnosticManager * diagnosticManager ; NeuDiagnosticTree
* diagnosticTree ; XDot * _rtXdot ; char * msg ; real_T tmp_p [ 4 ] ; real_T
time ; int32_T tmp_i ; int_T tmp_e [ 2 ] ; boolean_T tmp ; _rtXdot = ( ( XDot
* ) ssGetdX ( rtS ) ) ; simulationData = ( NeslSimulationData * ) rtDW .
fmv0dg0a4q ; time = ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN =
1 ; simulationData -> mData -> mTime . mX = & time ; simulationData -> mData
-> mContStates . mN = 26 ; simulationData -> mData -> mContStates . mX = &
rtX . ivwbjv4zes [ 0 ] ; simulationData -> mData -> mDiscStates . mN = 81 ;
simulationData -> mData -> mDiscStates . mX = & rtDW . dabkhrlstr [ 0 ] ;
simulationData -> mData -> mModeVector . mN = 58 ; simulationData -> mData ->
mModeVector . mX = & rtDW . oooz0jah34 [ 0 ] ; tmp = ( ssIsMajorTimeStep (
rtS ) && ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents ) ; simulationData
-> mData -> mFoundZcEvents = tmp ; simulationData -> mData ->
mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp = ( ssGetMdlInfoPtr ( rtS
) -> mdlFlags . solverAssertCheck == 1U ) ; simulationData -> mData ->
mIsSolverAssertCheck = tmp ; tmp = ssIsSolverCheckingCIC ( rtS ) ;
simulationData -> mData -> mIsSolverCheckingCIC = tmp ; tmp =
ssIsSolverComputingJacobian ( rtS ) ; simulationData -> mData ->
mIsComputingJacobian = tmp ; simulationData -> mData -> mIsEvaluatingF0 = (
ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ; tmp = ssIsSolverRequestingReset
( rtS ) ; simulationData -> mData -> mIsSolverRequestingReset = tmp ;
simulationData -> mData -> mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep (
rtS ) ; tmp_e [ 0 ] = 0 ; tmp_p [ 0 ] = rtB . asbpxve2fe [ 0 ] ; tmp_p [ 1 ]
= rtB . asbpxve2fe [ 1 ] ; tmp_p [ 2 ] = rtB . asbpxve2fe [ 2 ] ; tmp_p [ 3 ]
= rtB . asbpxve2fe [ 3 ] ; tmp_e [ 1 ] = 4 ; simulationData -> mData ->
mInputValues . mN = 4 ; simulationData -> mData -> mInputValues . mX = &
tmp_p [ 0 ] ; simulationData -> mData -> mInputOffsets . mN = 2 ;
simulationData -> mData -> mInputOffsets . mX = & tmp_e [ 0 ] ;
simulationData -> mData -> mDx . mN = 26 ; simulationData -> mData -> mDx .
mX = & _rtXdot -> ivwbjv4zes [ 0 ] ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . ovgmafyfkv ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp_i =
ne_simulator_method ( ( NeslSimulator * ) rtDW . neueknlloj ,
NESL_SIM_FORCINGFUNCTION , simulationData , diagnosticManager ) ; if ( tmp_i
!= 0 ) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp
) { msg = rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS ,
msg ) ; } } } void MdlMassMatrix ( void ) { NeslSimulationData *
simulationData ; NeuDiagnosticManager * diagnosticManager ; NeuDiagnosticTree
* diagnosticTree ; char * msg ; real_T tmp_p [ 4 ] ; real_T time ; real_T *
tmp_i ; real_T * tmp_m ; int32_T tmp_g ; int_T tmp_e [ 2 ] ; boolean_T tmp ;
simulationData = ( NeslSimulationData * ) rtDW . fmv0dg0a4q ; time = ssGetT (
rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time ; simulationData -> mData -> mContStates . mN = 26 ;
simulationData -> mData -> mContStates . mX = & rtX . ivwbjv4zes [ 0 ] ;
simulationData -> mData -> mDiscStates . mN = 81 ; simulationData -> mData ->
mDiscStates . mX = & rtDW . dabkhrlstr [ 0 ] ; simulationData -> mData ->
mModeVector . mN = 58 ; simulationData -> mData -> mModeVector . mX = & rtDW
. oooz0jah34 [ 0 ] ; tmp = ( ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo
( rtS ) -> foundContZcEvents ) ; simulationData -> mData -> mFoundZcEvents =
tmp ; simulationData -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS )
; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; tmp =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp ; tmp = ssIsSolverComputingJacobian ( rtS ) ;
simulationData -> mData -> mIsComputingJacobian = tmp ; simulationData ->
mData -> mIsEvaluatingF0 = ( ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ;
tmp = ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData ->
mIsSolverRequestingReset = tmp ; simulationData -> mData ->
mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep ( rtS ) ; tmp_e [ 0 ] = 0 ;
tmp_p [ 0 ] = rtB . asbpxve2fe [ 0 ] ; tmp_p [ 1 ] = rtB . asbpxve2fe [ 1 ] ;
tmp_p [ 2 ] = rtB . asbpxve2fe [ 2 ] ; tmp_p [ 3 ] = rtB . asbpxve2fe [ 3 ] ;
tmp_e [ 1 ] = 4 ; simulationData -> mData -> mInputValues . mN = 4 ;
simulationData -> mData -> mInputValues . mX = & tmp_p [ 0 ] ; simulationData
-> mData -> mInputOffsets . mN = 2 ; simulationData -> mData -> mInputOffsets
. mX = & tmp_e [ 0 ] ; tmp_i = ssGetMassMatrixPr ( rtS ) ; tmp_m =
double_pointer_shift ( tmp_i , rtDW . hhrpqbjqvn ) ; simulationData -> mData
-> mMassMatrixPr . mN = 39 ; simulationData -> mData -> mMassMatrixPr . mX =
tmp_m ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW . ovgmafyfkv ;
diagnosticTree = neu_diagnostic_manager_get_initial_tree ( diagnosticManager
) ; tmp_g = ne_simulator_method ( ( NeslSimulator * ) rtDW . neueknlloj ,
NESL_SIM_MASSMATRIX , simulationData , diagnosticManager ) ; if ( tmp_g != 0
) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) {
msg = rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg )
; } } } void MdlZeroCrossings ( void ) { NeslSimulationData * simulationData
; NeuDiagnosticManager * diagnosticManager ; NeuDiagnosticTree *
diagnosticTree ; ZCV * _rtZCSV ; char * msg ; real_T tmp_p [ 4 ] ; real_T
time ; int32_T tmp_i ; int_T tmp_e [ 2 ] ; boolean_T tmp ; _rtZCSV = ( ( ZCV
* ) ssGetSolverZcSignalVector ( rtS ) ) ; _rtZCSV -> datgzkb1oj = ssGetT (
rtS ) - rtP . Step_Time ; simulationData = ( NeslSimulationData * ) rtDW .
fmv0dg0a4q ; time = ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN =
1 ; simulationData -> mData -> mTime . mX = & time ; simulationData -> mData
-> mContStates . mN = 26 ; simulationData -> mData -> mContStates . mX = &
rtX . ivwbjv4zes [ 0 ] ; simulationData -> mData -> mDiscStates . mN = 81 ;
simulationData -> mData -> mDiscStates . mX = & rtDW . dabkhrlstr [ 0 ] ;
simulationData -> mData -> mModeVector . mN = 58 ; simulationData -> mData ->
mModeVector . mX = & rtDW . oooz0jah34 [ 0 ] ; tmp = ( ssIsMajorTimeStep (
rtS ) && ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents ) ; simulationData
-> mData -> mFoundZcEvents = tmp ; simulationData -> mData ->
mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp = ( ssGetMdlInfoPtr ( rtS
) -> mdlFlags . solverAssertCheck == 1U ) ; simulationData -> mData ->
mIsSolverAssertCheck = tmp ; tmp = ssIsSolverCheckingCIC ( rtS ) ;
simulationData -> mData -> mIsSolverCheckingCIC = tmp ; tmp =
ssIsSolverComputingJacobian ( rtS ) ; simulationData -> mData ->
mIsComputingJacobian = tmp ; simulationData -> mData -> mIsEvaluatingF0 = (
ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ; tmp = ssIsSolverRequestingReset
( rtS ) ; simulationData -> mData -> mIsSolverRequestingReset = tmp ;
simulationData -> mData -> mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep (
rtS ) ; tmp_e [ 0 ] = 0 ; tmp_p [ 0 ] = rtB . asbpxve2fe [ 0 ] ; tmp_p [ 1 ]
= rtB . asbpxve2fe [ 1 ] ; tmp_p [ 2 ] = rtB . asbpxve2fe [ 2 ] ; tmp_p [ 3 ]
= rtB . asbpxve2fe [ 3 ] ; tmp_e [ 1 ] = 4 ; simulationData -> mData ->
mInputValues . mN = 4 ; simulationData -> mData -> mInputValues . mX = &
tmp_p [ 0 ] ; simulationData -> mData -> mInputOffsets . mN = 2 ;
simulationData -> mData -> mInputOffsets . mX = & tmp_e [ 0 ] ;
simulationData -> mData -> mNonSampledZCs . mN = 50 ; simulationData -> mData
-> mNonSampledZCs . mX = & _rtZCSV -> npqmchkgek ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . ovgmafyfkv ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp_i =
ne_simulator_method ( ( NeslSimulator * ) rtDW . neueknlloj ,
NESL_SIM_ZEROCROSSINGS , simulationData , diagnosticManager ) ; if ( tmp_i !=
0 ) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) {
msg = rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg )
; } } } void MdlTerminate ( void ) { neu_destroy_diagnostic_manager ( (
NeuDiagnosticManager * ) rtDW . ovgmafyfkv ) ; nesl_destroy_simulation_data (
( NeslSimulationData * ) rtDW . fmv0dg0a4q ) ; nesl_erase_simulator (
"IGBTThermal/Solver Configuration1_1" ) ; nesl_destroy_registry ( ) ;
ssc_logger_terminate ( rtDW . js4kj4cuzy ) ; free ( rtDW . bfynxmcvmi ) ;
ssc_logger_destroy ( rtDW . js4kj4cuzy ) ; } static void
mr_IGBTThermal_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) ; static void
mr_IGBTThermal_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_IGBTThermal_restoreDataFromMxArray ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static
void mr_IGBTThermal_restoreDataFromMxArray ( void * destData , const mxArray
* srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * )
destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i
, j ) ) , numBytes ) ; } static void mr_IGBTThermal_cacheBitFieldToMxArray (
mxArray * destArray , mwIndex i , int j , uint_T bitVal ) ; static void
mr_IGBTThermal_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int
j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( real_T ) bitVal ) ) ; } static uint_T
mr_IGBTThermal_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) ; static uint_T
mr_IGBTThermal_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T )
mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( (
1u << numBits ) - 1u ) ; } static void
mr_IGBTThermal_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i
, int j , mwIndex offset , const void * srcData , size_t numBytes ) ; static
void mr_IGBTThermal_cacheDataToMxArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , const void * srcData , size_t numBytes )
{ uint8_T * varData = ( uint8_T * ) mxGetData ( mxGetFieldByNumber (
destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData [ offset * numBytes
] , ( const uint8_T * ) srcData , numBytes ) ; } static void
mr_IGBTThermal_restoreDataFromMxArrayWithOffset ( void * destData , const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ;
static void mr_IGBTThermal_restoreDataFromMxArrayWithOffset ( void * destData
, const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_IGBTThermal_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray
, mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static void
mr_IGBTThermal_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , uint_T fieldVal ) { mxSetCell (
mxGetFieldByNumber ( destArray , i , j ) , offset , mxCreateDoubleScalar ( (
real_T ) fieldVal ) ) ; } static uint_T
mr_IGBTThermal_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_IGBTThermal_extractBitFieldFromCellArrayWithOffset ( const mxArray
* srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) { const
uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber (
srcArray , i , j ) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u
) ; } mxArray * mr_IGBTThermal_GetDWork ( ) { static const char_T *
ssDWFieldNames [ 3 ] = { "rtB" , "rtDW" , "rtPrevZCX" , } ; mxArray * ssDW =
mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_IGBTThermal_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & ( rtB )
, sizeof ( rtB ) ) ; { static const char_T * rtdwDataFieldNames [ 14 ] = {
"rtDW.noegxjaqfo" , "rtDW.dabkhrlstr" , "rtDW.l0gf3i5n0p" , "rtDW.netor1vfyv"
, "rtDW.mtoyvs1lsx" , "rtDW.bthvtfhgxh" , "rtDW.npc3xna3zg" ,
"rtDW.bwzok3eybt" , "rtDW.po350bcjbl" , "rtDW.klvwjtvlp5" , "rtDW.oooz0jah34"
, "rtDW.lqjazq4u1m" , "rtDW.hhrpqbjqvn" , "rtDW.ofsbfnuf4a" , } ; mxArray *
rtdwData = mxCreateStructMatrix ( 1 , 1 , 14 , rtdwDataFieldNames ) ;
mr_IGBTThermal_cacheDataAsMxArray ( rtdwData , 0 , 0 , ( const void * ) & (
rtDW . noegxjaqfo ) , sizeof ( rtDW . noegxjaqfo ) ) ;
mr_IGBTThermal_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void * ) & (
rtDW . dabkhrlstr ) , sizeof ( rtDW . dabkhrlstr ) ) ;
mr_IGBTThermal_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * ) & (
rtDW . l0gf3i5n0p ) , sizeof ( rtDW . l0gf3i5n0p ) ) ;
mr_IGBTThermal_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void * ) & (
rtDW . netor1vfyv ) , sizeof ( rtDW . netor1vfyv ) ) ;
mr_IGBTThermal_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void * ) & (
rtDW . mtoyvs1lsx ) , sizeof ( rtDW . mtoyvs1lsx ) ) ;
mr_IGBTThermal_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void * ) & (
rtDW . bthvtfhgxh ) , sizeof ( rtDW . bthvtfhgxh ) ) ;
mr_IGBTThermal_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const void * ) & (
rtDW . npc3xna3zg ) , sizeof ( rtDW . npc3xna3zg ) ) ;
mr_IGBTThermal_cacheDataAsMxArray ( rtdwData , 0 , 7 , ( const void * ) & (
rtDW . bwzok3eybt ) , sizeof ( rtDW . bwzok3eybt ) ) ;
mr_IGBTThermal_cacheDataAsMxArray ( rtdwData , 0 , 8 , ( const void * ) & (
rtDW . po350bcjbl ) , sizeof ( rtDW . po350bcjbl ) ) ;
mr_IGBTThermal_cacheDataAsMxArray ( rtdwData , 0 , 9 , ( const void * ) & (
rtDW . klvwjtvlp5 ) , sizeof ( rtDW . klvwjtvlp5 ) ) ;
mr_IGBTThermal_cacheDataAsMxArray ( rtdwData , 0 , 10 , ( const void * ) & (
rtDW . oooz0jah34 ) , sizeof ( rtDW . oooz0jah34 ) ) ;
mr_IGBTThermal_cacheDataAsMxArray ( rtdwData , 0 , 11 , ( const void * ) & (
rtDW . lqjazq4u1m ) , sizeof ( rtDW . lqjazq4u1m ) ) ;
mr_IGBTThermal_cacheDataAsMxArray ( rtdwData , 0 , 12 , ( const void * ) & (
rtDW . hhrpqbjqvn ) , sizeof ( rtDW . hhrpqbjqvn ) ) ;
mr_IGBTThermal_cacheDataAsMxArray ( rtdwData , 0 , 13 , ( const void * ) & (
rtDW . ofsbfnuf4a ) , sizeof ( rtDW . ofsbfnuf4a ) ) ; mxSetFieldByNumber (
ssDW , 0 , 1 , rtdwData ) ; } mr_IGBTThermal_cacheDataAsMxArray ( ssDW , 0 ,
2 , ( const void * ) & ( rtPrevZCX ) , sizeof ( rtPrevZCX ) ) ; return ssDW ;
} void mr_IGBTThermal_SetDWork ( const mxArray * ssDW ) { ( void ) ssDW ;
mr_IGBTThermal_restoreDataFromMxArray ( ( void * ) & ( rtB ) , ssDW , 0 , 0 ,
sizeof ( rtB ) ) ; { const mxArray * rtdwData = mxGetFieldByNumber ( ssDW , 0
, 1 ) ; mr_IGBTThermal_restoreDataFromMxArray ( ( void * ) & ( rtDW .
noegxjaqfo ) , rtdwData , 0 , 0 , sizeof ( rtDW . noegxjaqfo ) ) ;
mr_IGBTThermal_restoreDataFromMxArray ( ( void * ) & ( rtDW . dabkhrlstr ) ,
rtdwData , 0 , 1 , sizeof ( rtDW . dabkhrlstr ) ) ;
mr_IGBTThermal_restoreDataFromMxArray ( ( void * ) & ( rtDW . l0gf3i5n0p ) ,
rtdwData , 0 , 2 , sizeof ( rtDW . l0gf3i5n0p ) ) ;
mr_IGBTThermal_restoreDataFromMxArray ( ( void * ) & ( rtDW . netor1vfyv ) ,
rtdwData , 0 , 3 , sizeof ( rtDW . netor1vfyv ) ) ;
mr_IGBTThermal_restoreDataFromMxArray ( ( void * ) & ( rtDW . mtoyvs1lsx ) ,
rtdwData , 0 , 4 , sizeof ( rtDW . mtoyvs1lsx ) ) ;
mr_IGBTThermal_restoreDataFromMxArray ( ( void * ) & ( rtDW . bthvtfhgxh ) ,
rtdwData , 0 , 5 , sizeof ( rtDW . bthvtfhgxh ) ) ;
mr_IGBTThermal_restoreDataFromMxArray ( ( void * ) & ( rtDW . npc3xna3zg ) ,
rtdwData , 0 , 6 , sizeof ( rtDW . npc3xna3zg ) ) ;
mr_IGBTThermal_restoreDataFromMxArray ( ( void * ) & ( rtDW . bwzok3eybt ) ,
rtdwData , 0 , 7 , sizeof ( rtDW . bwzok3eybt ) ) ;
mr_IGBTThermal_restoreDataFromMxArray ( ( void * ) & ( rtDW . po350bcjbl ) ,
rtdwData , 0 , 8 , sizeof ( rtDW . po350bcjbl ) ) ;
mr_IGBTThermal_restoreDataFromMxArray ( ( void * ) & ( rtDW . klvwjtvlp5 ) ,
rtdwData , 0 , 9 , sizeof ( rtDW . klvwjtvlp5 ) ) ;
mr_IGBTThermal_restoreDataFromMxArray ( ( void * ) & ( rtDW . oooz0jah34 ) ,
rtdwData , 0 , 10 , sizeof ( rtDW . oooz0jah34 ) ) ;
mr_IGBTThermal_restoreDataFromMxArray ( ( void * ) & ( rtDW . lqjazq4u1m ) ,
rtdwData , 0 , 11 , sizeof ( rtDW . lqjazq4u1m ) ) ;
mr_IGBTThermal_restoreDataFromMxArray ( ( void * ) & ( rtDW . hhrpqbjqvn ) ,
rtdwData , 0 , 12 , sizeof ( rtDW . hhrpqbjqvn ) ) ;
mr_IGBTThermal_restoreDataFromMxArray ( ( void * ) & ( rtDW . ofsbfnuf4a ) ,
rtdwData , 0 , 13 , sizeof ( rtDW . ofsbfnuf4a ) ) ; }
mr_IGBTThermal_restoreDataFromMxArray ( ( void * ) & ( rtPrevZCX ) , ssDW , 0
, 2 , sizeof ( rtPrevZCX ) ) ; } mxArray *
mr_IGBTThermal_GetSimStateDisallowedBlocks ( ) { mxArray * data =
mxCreateCellMatrix ( 4 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const
char_T * blockType [ 4 ] = { "SimscapeRtp" , "SimscapeExecutionBlock" ,
"SimscapeSinkBlock" , "Scope" , } ; static const char_T * blockPath [ 4 ] = {
"IGBTThermal/Solver Configuration1/RTP_1" ,
"IGBTThermal/Solver Configuration1/EVAL_KEY/STATE_1" ,
"IGBTThermal/Solver Configuration1/EVAL_KEY/SINK_1" , "IGBTThermal/Scope" , }
; static const int reason [ 4 ] = { 0 , 0 , 0 , 0 , } ; for ( subs [ 0 ] = 0
; subs [ 0 ] < 4 ; ++ ( subs [ 0 ] ) ) { subs [ 1 ] = 0 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateString ( blockType [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 1 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 2 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateDoubleScalar ( ( real_T ) reason [ subs [ 0 ] ] ) ) ; } } return data
; } void MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 26 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
4 ) ; ssSetNumBlocks ( rtS , 53 ) ; ssSetNumBlockIO ( rtS , 6 ) ;
ssSetNumBlockParams ( rtS , 18 ) ; } void MdlInitializeSampleTimes ( void ) {
ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetSampleTime ( rtS , 2 , - 2.0 ) ; ssSetSampleTime ( rtS , 3 , - 2.0 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 1.0 ) ;
ssSetOffsetTime ( rtS , 2 , 0.0 ) ; ssSetOffsetTime ( rtS , 3 , 1.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 258682035U ) ;
ssSetChecksumVal ( rtS , 1 , 4189584627U ) ; ssSetChecksumVal ( rtS , 2 ,
2541426687U ) ; ssSetChecksumVal ( rtS , 3 , 3138470284U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; executionInfo -> gblObjects_ . numToFiles = 0 ;
executionInfo -> gblObjects_ . numFrFiles = 0 ; executionInfo -> gblObjects_
. numFrWksBlocks = 0 ; executionInfo -> gblObjects_ . numModelInputs = 0 ;
executionInfo -> gblObjects_ . numRootInportBlks = 0 ; executionInfo ->
gblObjects_ . inportDataTypeIdx = NULL ; executionInfo -> gblObjects_ .
inportDims = NULL ; executionInfo -> gblObjects_ . inportComplex = NULL ;
executionInfo -> gblObjects_ . inportInterpoFlag = NULL ; executionInfo ->
gblObjects_ . inportContinuous = NULL ; ( void ) memset ( ( char_T * ) rtS ,
0 , sizeof ( SimStruct ) ) ; ( void ) memset ( ( char_T * ) & mdlInfo , 0 ,
sizeof ( struct _ssMdlInfo ) ) ; ( void ) memset ( ( char_T * ) & blkInfo2 ,
0 , sizeof ( struct _ssBlkInfo2 ) ) ; ( void ) memset ( ( char_T * ) &
blkInfoSLSize , 0 , sizeof ( struct _ssBlkInfoSLSize ) ) ; ssSetBlkInfo2Ptr (
rtS , & blkInfo2 ) ; ssSetBlkInfoSLSizePtr ( rtS , & blkInfoSLSize ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; ssSetExecutionInfo ( rtS ,
executionInfo ) ; slsaAllocOPModelData ( rtS ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { rtDW . hhrpqbjqvn = 0 ; } { static
DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) & dtInfo , 0 ,
sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo .
numDataTypes = 23 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo
. dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; dtInfo .
dataTypeInfoTable = rtDataTypeInfoTable ; } IGBTThermal_InitializeDataMapInfo
( ) ; ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS
) ; ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"IGBTThermal" ) ; ssSetPath ( rtS , "IGBTThermal" ) ; ssSetTStart ( rtS , 0.0
) ; ssSetTFinal ( rtS , 0.1 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 1 , 1
, 1 , 1 , 3 , 1 , 3 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
1 , 2 , 81 } ; static int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1
, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
1 } ; static int_T rt_LoggedStateDimensions [ ] = { 1 , 1 , 1 , 1 , 3 , 1 , 3
, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 2 , 81 } ;
static boolean_T rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static
BuiltInDTypeId rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static
RTWPreprocessingFcnPtr rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) } ; static const char_T * rt_LoggedStateLabels [ ] = {
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "Discrete" , "Discrete" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = { "IGBTThermal/Buck circuit 1/Capacitor" ,
"IGBTThermal/Buck circuit 1/Inductor" ,
"IGBTThermal/Buck circuit 2/Capacitor" ,
"IGBTThermal/Buck circuit 2/Inductor" , "IGBTThermal/IGBT_C" ,
"IGBTThermal/IGBT_C" , "IGBTThermal/IGBT_F" , "IGBTThermal/IGBT_F" ,
"IGBTThermal/IGBT_F" , "IGBTThermal/IGBT_F" , "IGBTThermal/IGBT_F" ,
"IGBTThermal/Buck circuit 1/Diode" , "IGBTThermal/IGBT_C" ,
"IGBTThermal/IGBT_C" , "IGBTThermal/Buck circuit 2/Diode" ,
"IGBTThermal/IGBT_C" , "IGBTThermal/IGBT_C" , "IGBTThermal/IGBT_C" ,
"IGBTThermal/IGBT_F" , "IGBTThermal/IGBT_F" , "IGBTThermal/IGBT_F" ,
"IGBTThermal/IGBT_F" ,
"IGBTThermal/Solver\nConfiguration1/EVAL_KEY/INPUT_1_1_1" ,
"IGBTThermal/Solver\nConfiguration1/EVAL_KEY/STATE_1" } ; static const char_T
* rt_LoggedStateNames [ ] = { "IGBTThermal.Buck_circuit_1.Capacitor.vc" ,
"IGBTThermal.Buck_circuit_1.Inductor.i_L" ,
"IGBTThermal.Buck_circuit_2.Capacitor.vc" ,
"IGBTThermal.Buck_circuit_2.Inductor.i_L" ,
"IGBTThermal.IGBT_C.thermal_port.Tvec" , "IGBTThermal.IGBT_C.Tdelta" ,
"IGBTThermal.IGBT_F.thermal_port.Tvec" , "IGBTThermal.IGBT_F.Tdelta" ,
"IGBTThermal.IGBT_F.parasitic_thermal_mass.Tj" , "IGBTThermal.IGBT_F.v" ,
"IGBTThermal.IGBT_F.i" , "IGBTThermal.Buck_circuit_1.Diode.private.threshold"
, "IGBTThermal.IGBT_C.v" , "IGBTThermal.IGBT_C.i" ,
"IGBTThermal.Buck_circuit_2.Diode.private.threshold" ,
"IGBTThermal.IGBT_C.Qdelta" ,
"IGBTThermal.IGBT_C.thermal_port.Q_AR_vec.Q_AR_vec_retained_variable_entry0"
, "IGBTThermal.IGBT_C.RHS" , "IGBTThermal.IGBT_F.Qdelta" ,
"IGBTThermal.IGBT_F.parasitic_thermal_mass.Qj" ,
"IGBTThermal.IGBT_F.thermal_port.Q_AR_vec.Q_AR_vec_retained_variable_entry1"
, "IGBTThermal.IGBT_F.RHS" , "Discrete" , "Discrete" } ; static boolean_T
rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static
RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static
int_T rt_LoggedStateIdxList [ ] = { 0 , 0 , 1 } ; static RTWLogSignalInfo
rt_LoggedStateSignalInfo = { 24 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 24 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . ivwbjv4zes [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . ivwbjv4zes [ 1 ] ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . ivwbjv4zes [ 2 ] ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . ivwbjv4zes [ 3 ] ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . ivwbjv4zes [ 4 ] ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . ivwbjv4zes [ 7 ] ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtX . ivwbjv4zes [ 8 ] ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) & rtX . ivwbjv4zes [ 11 ] ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) & rtX . ivwbjv4zes [ 12 ] ;
rt_LoggedStateSignalPtrs [ 9 ] = ( void * ) & rtX . ivwbjv4zes [ 13 ] ;
rt_LoggedStateSignalPtrs [ 10 ] = ( void * ) & rtX . ivwbjv4zes [ 14 ] ;
rt_LoggedStateSignalPtrs [ 11 ] = ( void * ) & rtX . ivwbjv4zes [ 15 ] ;
rt_LoggedStateSignalPtrs [ 12 ] = ( void * ) & rtX . ivwbjv4zes [ 16 ] ;
rt_LoggedStateSignalPtrs [ 13 ] = ( void * ) & rtX . ivwbjv4zes [ 17 ] ;
rt_LoggedStateSignalPtrs [ 14 ] = ( void * ) & rtX . ivwbjv4zes [ 18 ] ;
rt_LoggedStateSignalPtrs [ 15 ] = ( void * ) & rtX . ivwbjv4zes [ 19 ] ;
rt_LoggedStateSignalPtrs [ 16 ] = ( void * ) & rtX . ivwbjv4zes [ 20 ] ;
rt_LoggedStateSignalPtrs [ 17 ] = ( void * ) & rtX . ivwbjv4zes [ 21 ] ;
rt_LoggedStateSignalPtrs [ 18 ] = ( void * ) & rtX . ivwbjv4zes [ 22 ] ;
rt_LoggedStateSignalPtrs [ 19 ] = ( void * ) & rtX . ivwbjv4zes [ 23 ] ;
rt_LoggedStateSignalPtrs [ 20 ] = ( void * ) & rtX . ivwbjv4zes [ 24 ] ;
rt_LoggedStateSignalPtrs [ 21 ] = ( void * ) & rtX . ivwbjv4zes [ 25 ] ;
rt_LoggedStateSignalPtrs [ 22 ] = ( void * ) rtDW . noegxjaqfo ;
rt_LoggedStateSignalPtrs [ 23 ] = ( void * ) rtDW . dabkhrlstr ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"xFinal" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 50000 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo (
rtS ) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static struct _ssSFcnModelMethods3 mdlMethods3
; static struct _ssSFcnModelMethods2 mdlMethods2 ; static boolean_T
contStatesDisabled [ 26 ] ; static real_T absTol [ 26 ] = { 0.001 , 0.001 ,
0.001 , 0.001 , 0.001 , 0.001 , 0.001 , 0.001 , 0.001 , 0.001 , 0.001 , 0.001
, 0.001 , 0.001 , 0.001 , 0.001 , 0.001 , 0.001 , 0.001 , 0.001 , 0.001 ,
0.001 , 0.001 , 0.001 , 0.001 , 0.001 } ; static uint8_T absTolControl [ 26 ]
= { 2U , 2U , 2U , 2U , 2U , 2U , 2U , 2U , 2U , 2U , 2U , 2U , 2U , 2U , 2U
, 2U , 2U , 2U , 2U , 2U , 2U , 2U , 2U , 2U , 2U , 2U } ; static real_T
contStateJacPerturbBoundMinVec [ 26 ] ; static real_T
contStateJacPerturbBoundMaxVec [ 26 ] ; static uint8_T zcAttributes [ 51 ] =
{ ( ZC_EVENT_ALL_UP ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_Z2N | ZC_EVENT_P2N | ZC_EVENT_N2Z |
ZC_EVENT_N2P ) , ( 0x80 | ZC_EVENT_Z2N | ZC_EVENT_P2N | ZC_EVENT_N2Z |
ZC_EVENT_N2P ) } ; static ssNonContDerivSigInfo nonContDerivSigInfo [ 2 ] = {
{ 1 * sizeof ( real_T ) , ( char * ) ( & rtB . g3zz2ydtyn ) , ( NULL ) } , {
1 * sizeof ( real_T ) , ( char * ) ( & rtB . pjyzlfsjbp ) , ( NULL ) } } ; {
int i ; for ( i = 0 ; i < 26 ; ++ i ) { contStateJacPerturbBoundMinVec [ i ]
= 0 ; contStateJacPerturbBoundMaxVec [ i ] = rtGetInf ( ) ; } }
ssSetSolverRelTol ( rtS , 0.001 ) ; ssSetStepSize ( rtS , 0.0 ) ;
ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ;
ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 0.002 ) ;
ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 1 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 2 ) ; ssSetNonContDerivSigInfos ( rtS ,
nonContDerivSigInfo ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "ode23t" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ;
_ssSetSolverUpdateJacobianAtReset ( rtS , true ) ; ssSetAbsTolVector ( rtS ,
absTol ) ; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetJacobianPerturbationBoundsMinVec ( rtS , contStateJacPerturbBoundMinVec
) ; ssSetJacobianPerturbationBoundsMaxVec ( rtS ,
contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 1 ) ; (
void ) memset ( ( void * ) & mdlMethods2 , 0 , sizeof ( mdlMethods2 ) ) ;
ssSetModelMethods2 ( rtS , & mdlMethods2 ) ; ( void ) memset ( ( void * ) &
mdlMethods3 , 0 , sizeof ( mdlMethods3 ) ) ; ssSetModelMethods3 ( rtS , &
mdlMethods3 ) ; ssSetModelProjection ( rtS , MdlProjection ) ;
ssSetMassMatrixType ( rtS , ( ssMatrixType ) 3 ) ; ssSetMassMatrixNzMax ( rtS
, 39 ) ; ssSetModelMassMatrix ( rtS , MdlMassMatrix ) ;
ssSetModelForcingFunction ( rtS , MdlForcingFunction ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 3 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 39 ) ; ssSetModelOutputs ( rtS ,
MdlOutputs ) ; ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives (
rtS , MdlDerivatives ) ; ssSetSolverZcSignalAttrib ( rtS , zcAttributes ) ;
ssSetSolverNumZcSignals ( rtS , 51 ) ; ssSetModelZeroCrossings ( rtS ,
MdlZeroCrossings ) ; ssSetSolverConsecutiveZCsStepRelTol ( rtS ,
2.8421709430404007E-13 ) ; ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ;
ssSetSolverConsecutiveZCsError ( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic (
rtS , 1 ) ; ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ;
ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 51 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; { int_T
* ir = rtMassMatrix . ir ; int_T * jc = rtMassMatrix . jc ; real_T * pr =
rtMassMatrix . pr ; ssSetMassMatrixIr ( rtS , ir ) ; ssSetMassMatrixJc ( rtS
, jc ) ; ssSetMassMatrixPr ( rtS , pr ) ; ( void ) memset ( ( void * ) ir , 0
, 39 * sizeof ( int_T ) ) ; ( void ) memset ( ( void * ) jc , 0 , ( 26 + 1 )
* sizeof ( int_T ) ) ; ( void ) memset ( ( void * ) pr , 0 , 39 * sizeof (
real_T ) ) ; } } { ZCSigState * zc = ( ZCSigState * ) & rtPrevZCX ;
ssSetPrevZCSigState ( rtS , zc ) ; } { rtPrevZCX . iyhnoaqvfy =
UNINITIALIZED_ZCSIG ; rtPrevZCX . k3zwkmzd4h = UNINITIALIZED_ZCSIG ;
rtPrevZCX . ione2unr3o = UNINITIALIZED_ZCSIG ; rtPrevZCX . dtbi5h4dzo =
UNINITIALIZED_ZCSIG ; rtPrevZCX . kh4c5mvssu = UNINITIALIZED_ZCSIG ;
rtPrevZCX . gray30kr4i = UNINITIALIZED_ZCSIG ; rtPrevZCX . ah2ikpnlcq =
UNINITIALIZED_ZCSIG ; rtPrevZCX . pkvyjeskme = UNINITIALIZED_ZCSIG ;
rtPrevZCX . lkffzqx44l = UNINITIALIZED_ZCSIG ; rtPrevZCX . phhmw4nyfi =
UNINITIALIZED_ZCSIG ; rtPrevZCX . bnvccxeb4z = UNINITIALIZED_ZCSIG ;
rtPrevZCX . f4dtbisug0 = UNINITIALIZED_ZCSIG ; rtPrevZCX . kgn5gvwv5w =
UNINITIALIZED_ZCSIG ; rtPrevZCX . jnve2shjqy = UNINITIALIZED_ZCSIG ;
rtPrevZCX . cr14zhlt1h = UNINITIALIZED_ZCSIG ; rtPrevZCX . l0aat4arr5 =
UNINITIALIZED_ZCSIG ; rtPrevZCX . ljmgdnnjob = UNINITIALIZED_ZCSIG ;
rtPrevZCX . lmuvbde52o = UNINITIALIZED_ZCSIG ; rtPrevZCX . mjyg0bovqo =
UNINITIALIZED_ZCSIG ; rtPrevZCX . bytvymqvxw = UNINITIALIZED_ZCSIG ;
rtPrevZCX . pi2bwxu0lj = UNINITIALIZED_ZCSIG ; rtPrevZCX . jx4nurkcqa =
UNINITIALIZED_ZCSIG ; rtPrevZCX . nzej4c0ese = UNINITIALIZED_ZCSIG ;
rtPrevZCX . dh3dve443d = UNINITIALIZED_ZCSIG ; rtPrevZCX . olzmhab3ou =
UNINITIALIZED_ZCSIG ; rtPrevZCX . jtybie1tf1 = UNINITIALIZED_ZCSIG ;
rtPrevZCX . cm3cpdk5iw = UNINITIALIZED_ZCSIG ; rtPrevZCX . lwcbqbw5gf =
UNINITIALIZED_ZCSIG ; rtPrevZCX . eoribhfge2 = UNINITIALIZED_ZCSIG ;
rtPrevZCX . lcoedbcecj = UNINITIALIZED_ZCSIG ; rtPrevZCX . c2c0pupgz5 =
UNINITIALIZED_ZCSIG ; rtPrevZCX . m5ledqzuue = UNINITIALIZED_ZCSIG ;
rtPrevZCX . jnsqnbahd1 = UNINITIALIZED_ZCSIG ; rtPrevZCX . gbw3qukkxo =
UNINITIALIZED_ZCSIG ; rtPrevZCX . ptm0mjwcn2 = UNINITIALIZED_ZCSIG ;
rtPrevZCX . j4m1ilahzc = UNINITIALIZED_ZCSIG ; rtPrevZCX . mnw1n31qs3 =
UNINITIALIZED_ZCSIG ; rtPrevZCX . lbhsjcxi42 = UNINITIALIZED_ZCSIG ;
rtPrevZCX . ewxypzm3zn = UNINITIALIZED_ZCSIG ; rtPrevZCX . fxuys4bad5 =
UNINITIALIZED_ZCSIG ; rtPrevZCX . biyjkdwqbw = UNINITIALIZED_ZCSIG ;
rtPrevZCX . i3ewbsg25r = UNINITIALIZED_ZCSIG ; rtPrevZCX . hfr1gluplx =
UNINITIALIZED_ZCSIG ; rtPrevZCX . bbidofqoix = UNINITIALIZED_ZCSIG ;
rtPrevZCX . gseert0nr2 = UNINITIALIZED_ZCSIG ; rtPrevZCX . cwfdsmndpz =
UNINITIALIZED_ZCSIG ; rtPrevZCX . mf0wyfofqu = UNINITIALIZED_ZCSIG ;
rtPrevZCX . pjfnezhmyf = UNINITIALIZED_ZCSIG ; rtPrevZCX . dybc4pfzcn =
UNINITIALIZED_ZCSIG ; rtPrevZCX . fupdf2ubg0 = UNINITIALIZED_ZCSIG ; }
ssSetChecksumVal ( rtS , 0 , 258682035U ) ; ssSetChecksumVal ( rtS , 1 ,
4189584627U ) ; ssSetChecksumVal ( rtS , 2 , 2541426687U ) ; ssSetChecksumVal
( rtS , 3 , 3138470284U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 1 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; }
slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_IGBTThermal_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP (
rtS , mr_IGBTThermal_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS ,
mr_IGBTThermal_SetDWork ) ; rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if (
ssGetErrorStatus ( rtS ) ) { return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
void MdlOutputsParameterSampleTime ( int_T tid ) { MdlOutputsTID4 ( tid ) ; }

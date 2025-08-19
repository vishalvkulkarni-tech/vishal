#include "Rectifier.h"
#include "rtwtypes.h"
#include "mwmathutil.h"
#include "Rectifier_private.h"
#include "rt_logging_mmi.h"
#include "Rectifier_capi.h"
#include "Rectifier_dt.h"
#include "sfcn_loader_c_api.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; extern ssExecutionInfo gblExecutionInfo ; RTWExtModeInfo *
gblRTWExtModeInfo = NULL ; void raccelForceExtModeShutdown ( boolean_T
extModeStartPktReceived ) { if ( ! extModeStartPktReceived ) { boolean_T
stopRequested = false ; rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , &
stopRequested ) ; } rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 3 ; const char_T
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
rt_dataMapInfo . mmi ) ; int_T enableFcnCallFlag [ ] = { 1 , 1 , 1 } ; const
char * raccelLoadInputsAndAperiodicHitTimes ( SimStruct * S , const char *
inportFileName , int * matFileFormat ) { return rt_RAccelReadInportsMatFile (
S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; void MdlInitialize ( void ) { { SimStruct * rts = ssGetSFunction
( rtS , 0 ) ; sfcnInitializeConditions ( rts ) ; if ( ssGetErrorStatus ( rts
) != ( NULL ) ) return ; } } void MdlStart ( void ) { { bool
externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T rt_ScopeSignalWidths [
] = { 1 , 1 , 2 , 1 } ; static int_T rt_ScopeSignalNumDimensions [ ] = { 1 ,
1 , 1 , 1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 1 , 1 , 2 , 1 } ;
static void * rt_ScopeCurrSigDims [ ] = { ( NULL ) , ( NULL ) , ( NULL ) , (
NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 , 4 , 4 , 4 } ;
static const char_T * rt_ScopeSignalLabels [ ] = { "Vd" , "Id" ,
"I diodes 2 & 3" , "<Diode voltage>" } ; static char_T rt_ScopeSignalTitles [
] = "VdIdI diodes 2 & 3<Diode voltage>" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 2 , 2 , 14 , 15 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 , 0 , 0 , 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 , 0 , 0 , 0 } ; BuiltInDTypeId dTypes
[ 4 ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static char_T
rt_ScopeBlockName [ ] = "Rectifier/Scope" ; static int_T rt_ScopeFrameData [
] = { 0 , 0 , 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) , (
NULL ) , ( NULL ) } ; rt_ScopeSignalInfo . numSignals = 4 ;
rt_ScopeSignalInfo . numCols = rt_ScopeSignalWidths ; rt_ScopeSignalInfo .
numDims = rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
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
rtDW . oeybejg1lp . LoggedData [ 0 ] = rt_CreateStructLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "Scope1Data" , 1 , 50000 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . oeybejg1lp .
LoggedData [ 0 ] == ( NULL ) ) return ; } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "<Diode voltage>" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "<Diode voltage>" ) ; sdiLabelU propName
= sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"Rectifier/Bus Selector1" ) ; sdiLabelU blockSID = sdiGetLabelFromChars ( ""
) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ;
sdiLabelU sigName = sdiGetLabelFromChars ( "<Diode voltage>" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 1 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . dtwh04wcp2 . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "53d0557b-2008-4e44-8751-3e14b3f36f1d" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . dtwh04wcp2 . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . dtwh04wcp2 . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . dtwh04wcp2 . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . dtwh04wcp2 .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . dtwh04wcp2 . AQHandles ,
ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
dtwh04wcp2 . AQHandles , 1 , 50000 ) ; sdiAsyncRepoSetSignalExportName ( rtDW
. dtwh04wcp2 . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Id" ) ; sdiLabelU origSigName
= sdiGetLabelFromChars ( "Id" ) ; sdiLabelU propName = sdiGetLabelFromChars (
"" ) ; sdiLabelU blockPath = sdiGetLabelFromChars ( "Rectifier/Id" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "Id" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. cyx1kfcdlz . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"8ada301c-db1d-4104-b009-a27bbe6320bd" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . cyx1kfcdlz . AQHandles , hDT , & srcInfo ) ; if ( rtDW . cyx1kfcdlz .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . cyx1kfcdlz . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
cyx1kfcdlz . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . cyx1kfcdlz .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . cyx1kfcdlz . AQHandles , 1 , 50000 ) ;
sdiAsyncRepoSetSignalExportName ( rtDW . cyx1kfcdlz . AQHandles , loggedName
, origSigName , propName ) ; } sdiFreeLabel ( sigName ) ; sdiFreeLabel (
loggedName ) ; sdiFreeLabel ( origSigName ) ; sdiFreeLabel ( propName ) ;
sdiFreeLabel ( blockPath ) ; sdiFreeLabel ( blockSID ) ; sdiFreeLabel (
subPath ) ; } } if ( ! isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "I diodes 2 & 3" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "I diodes 2 & 3" ) ; sdiLabelU propName
= sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"Rectifier/Mux" ) ; sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ;
sdiLabelU subPath = sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU
sigName = sdiGetLabelFromChars ( "I diodes 2 & 3" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 2 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . htww4gle3c . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "8780120f-d71c-4e8a-bbd7-55917df2d170" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . htww4gle3c . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . htww4gle3c . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . htww4gle3c . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . htww4gle3c .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . htww4gle3c . AQHandles ,
ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
htww4gle3c . AQHandles , 1 , 50000 ) ; sdiAsyncRepoSetSignalExportName ( rtDW
. htww4gle3c . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Vd" ) ; sdiLabelU origSigName
= sdiGetLabelFromChars ( "Vd" ) ; sdiLabelU propName = sdiGetLabelFromChars (
"" ) ; sdiLabelU blockPath = sdiGetLabelFromChars ( "Rectifier/Vd" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "Vd" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. gc3hjjbgux . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"d7ceae45-7ffd-49ec-93e1-86b923122da5" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . gc3hjjbgux . AQHandles , hDT , & srcInfo ) ; if ( rtDW . gc3hjjbgux .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . gc3hjjbgux . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
gc3hjjbgux . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . gc3hjjbgux .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . gc3hjjbgux . AQHandles , 1 , 50000 ) ;
sdiAsyncRepoSetSignalExportName ( rtDW . gc3hjjbgux . AQHandles , loggedName
, origSigName , propName ) ; } sdiFreeLabel ( sigName ) ; sdiFreeLabel (
loggedName ) ; sdiFreeLabel ( origSigName ) ; sdiFreeLabel ( propName ) ;
sdiFreeLabel ( blockPath ) ; sdiFreeLabel ( blockSID ) ; sdiFreeLabel (
subPath ) ; } } if ( ! isStreamoutAlreadyRegistered ) { } } } } {
RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T rt_ScopeSignalWidths [ ] =
{ 2 } ; static int_T rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 2 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] = "Rectifier/Scope1" ;
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
rtDW . hybnqng5i0 . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "Scope2Data" , 1 , 50000 , 1 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . hybnqng5i0 .
LoggedData == ( NULL ) ) return ; } { { { bool isStreamoutAlreadyRegistered =
false ; { sdiSignalSourceInfoU srcInfo ; sdiLabelU sigName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"Rectifier/Diode1" ) ; sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ;
sdiLabelU subPath = sdiGetLabelFromChars ( "" ) ; const char_T * leafUnits [
2 ] = { "" , "" } ; sdiVirtualBusLeafElementInfoU leafElInfo [ 2 ] ; int_T
childDimsArray0 [ 1 ] = { 1 } ; int_T childDimsArray1 [ 1 ] = { 1 } ; {
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; leafElInfo [ 0 ] . hDataType = hDT ; leafElInfo [ 0 ] .
signalName = sdiGetLabelFromChars ( ".Diode_current" ) ; leafElInfo [ 0 ] .
dims . nDims = 1 ; leafElInfo [ 0 ] . dims . dimensions = childDimsArray0 ;
leafElInfo [ 0 ] . dimsMode = DIMENSIONS_MODE_FIXED ; leafElInfo [ 0 ] .
complexity = REAL ; leafElInfo [ 0 ] . isLinearInterp = 1 ; leafElInfo [ 0 ]
. units = leafUnits [ 0 ] ; } { sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; leafElInfo [ 1 ]
. hDataType = hDT ; leafElInfo [ 1 ] . signalName = sdiGetLabelFromChars (
".Diode_voltage" ) ; leafElInfo [ 1 ] . dims . nDims = 1 ; leafElInfo [ 1 ] .
dims . dimensions = childDimsArray1 ; leafElInfo [ 1 ] . dimsMode =
DIMENSIONS_MODE_FIXED ; leafElInfo [ 1 ] . complexity = REAL ; leafElInfo [ 1
] . isLinearInterp = 1 ; leafElInfo [ 1 ] . units = leafUnits [ 1 ] ; }
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ;
sdiCreateAsyncQueuesForVirtualBusWithExportSettings ( & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"c56bcb1d-d08f-41d3-95dc-be592119ce84" , 2 , leafElInfo , & rtDW . aebfs1h4gh
. AQHandles [ 0 ] , 1 , 50000 , "" , "" , "" ) ;
slsaCacheDWorkDataForSimTargetOP ( rtS , & rtDW . aebfs1h4gh . AQHandles [ 0
] , 2 * sizeof ( & rtDW . aebfs1h4gh . AQHandles [ 0 ] ) ) ; if ( rtDW .
aebfs1h4gh . AQHandles [ 0 ] ) { sdiLabelU loggedName = sdiGetLabelFromChars
( "" ) ; sdiLabelU origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU
propName = sdiGetLabelFromChars ( "" ) ; sdiSetSignalSampleTimeString ( rtDW
. aebfs1h4gh . AQHandles [ 0 ] , "Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ;
sdiSetSignalRefRate ( rtDW . aebfs1h4gh . AQHandles [ 0 ] , 0.0 ) ;
sdiSetRunStartTime ( rtDW . aebfs1h4gh . AQHandles [ 0 ] , ssGetTaskTime (
rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW . aebfs1h4gh .
AQHandles [ 0 ] , 1 , 50000 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
aebfs1h4gh . AQHandles [ 0 ] , loggedName , origSigName , propName ) ;
sdiSetSignalSampleTimeString ( rtDW . aebfs1h4gh . AQHandles [ 1 ] ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
aebfs1h4gh . AQHandles [ 1 ] , 0.0 ) ; sdiSetRunStartTime ( rtDW . aebfs1h4gh
. AQHandles [ 1 ] , ssGetTaskTime ( rtS , 1 ) ) ;
sdiAsyncRepoSetSignalExportSettings ( rtDW . aebfs1h4gh . AQHandles [ 1 ] , 1
, 50000 ) ; sdiAsyncRepoSetSignalExportName ( rtDW . aebfs1h4gh . AQHandles [
1 ] , loggedName , origSigName , propName ) ; sdiFreeLabel ( loggedName ) ;
sdiFreeLabel ( origSigName ) ; sdiFreeLabel ( propName ) ; } sdiFreeLabel (
sigName ) ; sdiFreeLabel ( blockPath ) ; sdiFreeLabel ( blockSID ) ;
sdiFreeLabel ( subPath ) ; sdiFreeName ( leafElInfo [ 0 ] . signalName ) ;
sdiFreeName ( leafElInfo [ 1 ] . signalName ) ; } if ( !
isStreamoutAlreadyRegistered ) { } } } } rtB . pbtg1zqog4 = rtP . gate_Value
; rtB . d0jsj1vn54 = rtP . gate_Value_a1aaq4xqpt ; rtB . pmio0r0doy = rtP .
gate_Value_graafvp4kv ; { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ;
sfcnStart ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; }
MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { real_T nbdosjpmlx ;
real_T jhsuyjlbco [ 2 ] ; rtB . cnnmnegtoe = muDoubleScalarSin (
6.2831853071795862 * rtP . frequency_voltage1 * ssGetTaskTime ( rtS , 0 ) +
rtP . phaseInDegree_voltage1 * 3.1415926535897931 / 180.0 ) * rtP .
peakAmplitude_voltage1 + rtP . AC_Bias ; rtB . otx4h10gqp = muDoubleScalarSin
( 6.2831853071795862 * rtP . frequency_voltage2 * ssGetTaskTime ( rtS , 0 ) +
rtP . phaseInDegree_voltage2 * 3.1415926535897931 / 180.0 ) * rtP .
peakAmplitude_voltage2 + rtP . AC_Bias_ckphr0qig4 ; rtB . otltz4tihg =
muDoubleScalarSin ( 6.2831853071795862 * rtP . frequency_voltage3 *
ssGetTaskTime ( rtS , 0 ) + rtP . phaseInDegree_voltage3 * 3.1415926535897931
/ 180.0 ) * rtP . peakAmplitude_voltage3 + rtP . AC_Bias_eyfr42ua5t ; {
SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; sfcnOutputs ( rts , 0 ) ; }
rtB . ocbbvf4ln3 = rtP . donotdeletethisgain_Gain * rtB . llymjhndln [ 0 ] ;
rtB . out0qpal0x = rtP . donotdeletethisgain_Gain_hsnae3wadg * rtB .
llymjhndln [ 1 ] ; rtB . nz02ivetdb = ( rtP . Ron_Gain * rtB . mwvowazfto [ 5
] + rtB . mwvowazfto [ 4 ] ) + rtB . iho2fxkxre ; if ( ssGetLogOutput ( rtS )
) { StructLogVar * svar = ( StructLogVar * ) rtDW . oeybejg1lp . LoggedData [
0 ] ; LogVar * var = svar -> signals . values ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , &
locTime , 0 ) ; } { real_T up0 [ 1 ] ; up0 [ 0 ] = rtB . ocbbvf4ln3 ;
rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; var = var -> next ; } {
real_T up1 [ 1 ] ; up1 [ 0 ] = rtB . out0qpal0x ; rt_UpdateLogVar ( ( LogVar
* ) var , up1 , 0 ) ; var = var -> next ; } { real_T up2 [ 2 ] ; up2 [ 0 ] =
rtB . mwvowazfto [ 3 ] ; up2 [ 1 ] = rtB . mwvowazfto [ 5 ] ; rt_UpdateLogVar
( ( LogVar * ) var , up2 , 0 ) ; var = var -> next ; } { real_T up3 [ 1 ] ;
up3 [ 0 ] = rtB . nz02ivetdb ; rt_UpdateLogVar ( ( LogVar * ) var , up3 , 0 )
; } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { { if ( rtDW . dtwh04wcp2 .
AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . dtwh04wcp2 .
AQHandles , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . nz02ivetdb + 0 ) ;
} } { if ( rtDW . cyx1kfcdlz . AQHandles && ssGetLogOutput ( rtS ) ) {
sdiWriteSignal ( rtDW . cyx1kfcdlz . AQHandles , ssGetTaskTime ( rtS , 1 ) ,
( char * ) & rtB . out0qpal0x + 0 ) ; } } jhsuyjlbco [ 0 ] = rtB . mwvowazfto
[ 3 ] ; jhsuyjlbco [ 1 ] = rtB . mwvowazfto [ 5 ] ; { if ( rtDW . htww4gle3c
. AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . htww4gle3c
. AQHandles , ssGetTaskTime ( rtS , 1 ) , ( char * ) & jhsuyjlbco [ 0 ] + 0 )
; } } { if ( rtDW . gc3hjjbgux . AQHandles && ssGetLogOutput ( rtS ) ) {
sdiWriteSignal ( rtDW . gc3hjjbgux . AQHandles , ssGetTaskTime ( rtS , 1 ) ,
( char * ) & rtB . ocbbvf4ln3 + 0 ) ; } } } nbdosjpmlx = ( rtP .
Ron_Gain_gisotimrpi * rtB . mwvowazfto [ 3 ] + rtB . mwvowazfto [ 2 ] ) + rtB
. a44meuoh25 ; rtB . cx12fc0yyz = ( rtP . Ron_Gain_heqalhhamz * rtB .
mwvowazfto [ 1 ] + rtB . mwvowazfto [ 0 ] ) + rtB . ou0uwhuegx ; if (
ssGetLogOutput ( rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW .
hybnqng5i0 . LoggedData ; LogVar * var = svar -> signals . values ; { double
locTime = ssGetTaskTime ( rtS , 0 ) ; rt_UpdateLogVar ( ( LogVar * ) svar ->
time , & locTime , 0 ) ; } { real_T up0 [ 2 ] ; up0 [ 0 ] = rtB . mwvowazfto
[ 1 ] ; up0 [ 1 ] = rtB . cx12fc0yyz ; rt_UpdateLogVar ( ( LogVar * ) var ,
up0 , 0 ) ; } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { { if ( rtDW .
aebfs1h4gh . AQHandles [ 0 ] && ssGetLogOutput ( rtS ) ) { sdiWriteSignal (
rtDW . aebfs1h4gh . AQHandles [ 0 ] , ssGetTaskTime ( rtS , 1 ) , ( char * )
& rtB . mwvowazfto [ 1 ] + 0 ) ; sdiWriteSignal ( rtDW . aebfs1h4gh .
AQHandles [ 1 ] , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . cx12fc0yyz +
0 ) ; } } } UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID2 ( int_T tid ) {
rtB . a44meuoh25 = rtP . eee_Value ; rtB . pbtg1zqog4 = rtP . gate_Value ;
rtB . iho2fxkxre = rtP . eee_Value_ezp1ppxfvo ; rtB . d0jsj1vn54 = rtP .
gate_Value_a1aaq4xqpt ; rtB . ou0uwhuegx = rtP . eee_Value_ltt5dvhgzf ; rtB .
pmio0r0doy = rtP . gate_Value_graafvp4kv ; UNUSED_PARAMETER ( tid ) ; } void
MdlUpdate ( int_T tid ) { { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ;
sfcnUpdate ( rts , 0 ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ;
} UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID2 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { { SimStruct * rts
= ssGetSFunction ( rtS , 0 ) ; real_T * sfcndX_fx = ( real_T * ) & ( ( XDot *
) ssGetdX ( rtS ) ) -> ldtzkz5puq [ 0 ] ; ssSetdX ( rts , sfcndX_fx ) ;
sfcnDerivatives ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return
; } } void MdlProjection ( void ) { { SimStruct * rts = ssGetSFunction ( rtS
, 0 ) ; sfcnProjection ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) )
return ; } } void MdlZeroCrossings ( void ) { { SimStruct * rts =
ssGetSFunction ( rtS , 0 ) ; ssSetNonsampledZCs ( rts , & ( ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> babq5df4pt [ 0 ] ) ) ;
sfcnZeroCrossings ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) )
return ; } } void MdlTerminate ( void ) { { SimStruct * rts = ssGetSFunction
( rtS , 0 ) ; sfcnTerminate ( rts ) ; } { if ( rtDW . dtwh04wcp2 . AQHandles
) { sdiTerminateStreaming ( & rtDW . dtwh04wcp2 . AQHandles ) ; } } { if (
rtDW . cyx1kfcdlz . AQHandles ) { sdiTerminateStreaming ( & rtDW . cyx1kfcdlz
. AQHandles ) ; } } { if ( rtDW . htww4gle3c . AQHandles ) {
sdiTerminateStreaming ( & rtDW . htww4gle3c . AQHandles ) ; } } { if ( rtDW .
gc3hjjbgux . AQHandles ) { sdiTerminateStreaming ( & rtDW . gc3hjjbgux .
AQHandles ) ; } } { if ( rtDW . aebfs1h4gh . AQHandles [ 0 ] ) {
sdiTerminateStreaming ( & rtDW . aebfs1h4gh . AQHandles [ 0 ] ) ; } if ( rtDW
. aebfs1h4gh . AQHandles [ 1 ] ) { sdiTerminateStreaming ( & rtDW .
aebfs1h4gh . AQHandles [ 1 ] ) ; } } } static void
mr_Rectifier_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) ; static void
mr_Rectifier_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_Rectifier_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static void
mr_Rectifier_restoreDataFromMxArray ( void * destData , const mxArray *
srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * )
destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i
, j ) ) , numBytes ) ; } static void mr_Rectifier_cacheBitFieldToMxArray (
mxArray * destArray , mwIndex i , int j , uint_T bitVal ) ; static void
mr_Rectifier_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int j
, uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( real_T ) bitVal ) ) ; } static uint_T
mr_Rectifier_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex
i , int j , uint_T numBits ) ; static uint_T
mr_Rectifier_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex
i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T ) mxGetScalar (
mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( ( 1u << numBits
) - 1u ) ; } static void mr_Rectifier_cacheDataToMxArrayWithOffset ( mxArray
* destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) ; static void mr_Rectifier_cacheDataToMxArrayWithOffset (
mxArray * destArray , mwIndex i , int j , mwIndex offset , const void *
srcData , size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_Rectifier_restoreDataFromMxArrayWithOffset ( void * destData , const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ;
static void mr_Rectifier_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_Rectifier_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static void
mr_Rectifier_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , uint_T fieldVal ) { mxSetCell (
mxGetFieldByNumber ( destArray , i , j ) , offset , mxCreateDoubleScalar ( (
real_T ) fieldVal ) ) ; } static uint_T
mr_Rectifier_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_Rectifier_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) { const
uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber (
srcArray , i , j ) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u
) ; } mxArray * mr_Rectifier_GetDWork ( ) { static const char_T *
ssDWFieldNames [ 3 ] = { "rtB" , "rtDW" , "NULL_PrevZCX" , } ; mxArray * ssDW
= mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_Rectifier_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & ( rtB ) ,
sizeof ( rtB ) ) ; { static const char_T * rtdwDataFieldNames [ 3 ] = {
"rtDW.awq4jr4str" , "rtDW.elswe02dqw" , "rtDW.n5ib1rg2mq" , } ; mxArray *
rtdwData = mxCreateStructMatrix ( 1 , 1 , 3 , rtdwDataFieldNames ) ;
mr_Rectifier_cacheDataAsMxArray ( rtdwData , 0 , 0 , ( const void * ) & (
rtDW . awq4jr4str ) , sizeof ( rtDW . awq4jr4str ) ) ;
mr_Rectifier_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void * ) & (
rtDW . elswe02dqw ) , sizeof ( rtDW . elswe02dqw ) ) ;
mr_Rectifier_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * ) & (
rtDW . n5ib1rg2mq ) , sizeof ( rtDW . n5ib1rg2mq ) ) ; mxSetFieldByNumber (
ssDW , 0 , 1 , rtdwData ) ; } return ssDW ; } void mr_Rectifier_SetDWork (
const mxArray * ssDW ) { ( void ) ssDW ; mr_Rectifier_restoreDataFromMxArray
( ( void * ) & ( rtB ) , ssDW , 0 , 0 , sizeof ( rtB ) ) ; { const mxArray *
rtdwData = mxGetFieldByNumber ( ssDW , 0 , 1 ) ;
mr_Rectifier_restoreDataFromMxArray ( ( void * ) & ( rtDW . awq4jr4str ) ,
rtdwData , 0 , 0 , sizeof ( rtDW . awq4jr4str ) ) ;
mr_Rectifier_restoreDataFromMxArray ( ( void * ) & ( rtDW . elswe02dqw ) ,
rtdwData , 0 , 1 , sizeof ( rtDW . elswe02dqw ) ) ;
mr_Rectifier_restoreDataFromMxArray ( ( void * ) & ( rtDW . n5ib1rg2mq ) ,
rtdwData , 0 , 2 , sizeof ( rtDW . n5ib1rg2mq ) ) ; } } mxArray *
mr_Rectifier_GetSimStateDisallowedBlocks ( ) { mxArray * data =
mxCreateCellMatrix ( 4 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const
char_T * blockType [ 4 ] = { "S-Function" , "Scope" , "Scope" , "S-Function"
, } ; static const char_T * blockPath [ 4 ] = {
"Rectifier/powergui/EquivalentModel1/State-Space" , "Rectifier/Scope" ,
"Rectifier/Scope1" , "Rectifier/powergui/EquivalentModel1/State-Space" , } ;
static const int reason [ 4 ] = { 0 , 0 , 0 , 2 , } ; for ( subs [ 0 ] = 0 ;
subs [ 0 ] < 4 ; ++ ( subs [ 0 ] ) ) { subs [ 1 ] = 0 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateString ( blockType [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 1 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 2 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateDoubleScalar ( ( real_T ) reason [ subs [ 0 ] ] ) ) ; } } return data
; } void MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 7 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
2 ) ; ssSetNumBlocks ( rtS , 60 ) ; ssSetNumBlockIO ( rtS , 15 ) ;
ssSetNumBlockParams ( rtS , 1156 ) ; } void MdlInitializeSampleTimes ( void )
{ ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 1.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 892092326U ) ;
ssSetChecksumVal ( rtS , 1 , 2020949463U ) ; ssSetChecksumVal ( rtS , 2 ,
2295649570U ) ; ssSetChecksumVal ( rtS , 3 , 3430351693U ) ; }
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
( ( void * ) & rtB ) ) ; { int32_T i ; for ( i = 0 ; i < 6 ; i ++ ) { rtB .
mwvowazfto [ i ] = 0.0 ; } rtB . cnnmnegtoe = 0.0 ; rtB . otx4h10gqp = 0.0 ;
rtB . otltz4tihg = 0.0 ; rtB . llymjhndln [ 0 ] = 0.0 ; rtB . llymjhndln [ 1
] = 0.0 ; rtB . ocbbvf4ln3 = 0.0 ; rtB . out0qpal0x = 0.0 ; rtB . nz02ivetdb
= 0.0 ; rtB . cx12fc0yyz = 0.0 ; rtB . a44meuoh25 = 0.0 ; rtB . pbtg1zqog4 =
0.0 ; rtB . iho2fxkxre = 0.0 ; rtB . d0jsj1vn54 = 0.0 ; rtB . ou0uwhuegx =
0.0 ; rtB . pmio0r0doy = 0.0 ; } } { real_T * x = ( real_T * ) & rtX ;
ssSetContStates ( rtS , x ) ; ( void ) memset ( ( void * ) x , 0 , sizeof ( X
) ) ; } { void * dwork = ( void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ;
( void ) memset ( dwork , 0 , sizeof ( DW ) ) ; rtDW . awq4jr4str [ 0 ] = 0.0
; rtDW . awq4jr4str [ 1 ] = 0.0 ; } { static DataTypeTransInfo dtInfo ; (
void ) memset ( ( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ;
ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo . numDataTypes = 23 ;
dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = &
rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = & rtBTransTable ; dtInfo .
PTransTable = & rtPTransTable ; dtInfo . dataTypeInfoTable =
rtDataTypeInfoTable ; } Rectifier_InitializeDataMapInfo ( ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"Rectifier" ) ; ssSetPath ( rtS , "Rectifier" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 1.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 7 } ;
static int_T rt_LoggedStateNumDimensions [ ] = { 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 7 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) } ; static const char_T
* rt_LoggedStateLabels [ ] = { "CSTATE" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = {
"Rectifier/powergui/EquivalentModel1/State-Space" } ; static const char_T *
rt_LoggedStateNames [ ] = { "" } ; static boolean_T rt_LoggedStateCrossMdlRef
[ ] = { 0 } ; static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { {
0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static int_T
rt_LoggedStateIdxList [ ] = { 0 } ; static RTWLogSignalInfo
rt_LoggedStateSignalInfo = { 1 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 1 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . ldtzkz5puq [ 0 ] ; }
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
contStatesDisabled [ 7 ] ; static real_T absTol [ 7 ] = {
1.0000000000000001E-7 , 1.0000000000000001E-7 , 1.0000000000000001E-7 ,
1.0000000000000001E-7 , 1.0000000000000001E-7 , 1.0000000000000001E-7 ,
1.0000000000000001E-7 } ; static uint8_T absTolControl [ 7 ] = { 0U , 0U , 0U
, 0U , 0U , 0U , 0U } ; static real_T contStateJacPerturbBoundMinVec [ 7 ] ;
static real_T contStateJacPerturbBoundMaxVec [ 7 ] ; static uint8_T
zcAttributes [ 4 ] = { ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL )
, ( ZC_EVENT_ALL ) } ; { int i ; for ( i = 0 ; i < 7 ; ++ i ) {
contStateJacPerturbBoundMinVec [ i ] = 0 ; contStateJacPerturbBoundMaxVec [ i
] = rtGetInf ( ) ; } } ssSetSolverRelTol ( rtS , 0.0001 ) ; ssSetStepSize (
rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , -
1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 0.0001
) ; ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 0 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 0 ) ; ssSetNonContDerivSigInfos ( rtS ,
( NULL ) ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS ,
"ode23tb" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector (
rtS , absTol ) ; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetJacobianPerturbationBoundsMinVec ( rtS , contStateJacPerturbBoundMinVec
) ; ssSetJacobianPerturbationBoundsMaxVec ( rtS ,
contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 1 ) ; (
void ) memset ( ( void * ) & mdlMethods2 , 0 , sizeof ( mdlMethods2 ) ) ;
ssSetModelMethods2 ( rtS , & mdlMethods2 ) ; ( void ) memset ( ( void * ) &
mdlMethods3 , 0 , sizeof ( mdlMethods3 ) ) ; ssSetModelMethods3 ( rtS , &
mdlMethods3 ) ; ssSetModelProjection ( rtS , MdlProjection ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverZcSignalAttrib ( rtS , zcAttributes ) ;
ssSetSolverNumZcSignals ( rtS , 4 ) ; ssSetModelZeroCrossings ( rtS ,
MdlZeroCrossings ) ; ssSetSolverConsecutiveZCsStepRelTol ( rtS ,
2.8421709430404007E-13 ) ; ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ;
ssSetSolverConsecutiveZCsError ( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic (
rtS , 1 ) ; ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ;
ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 4 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 892092326U ) ; ssSetChecksumVal ( rtS , 1 ,
2020949463U ) ; ssSetChecksumVal ( rtS , 2 , 2295649570U ) ; ssSetChecksumVal
( rtS , 3 , 3430351693U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 1 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; }
slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_Rectifier_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP (
rtS , mr_Rectifier_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS ,
mr_Rectifier_SetDWork ) ; rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if (
ssGetErrorStatus ( rtS ) ) { return rtS ; } ssSetNumSFunctions ( rtS , 1 ) ;
{ static SimStruct childSFunctions [ 1 ] ; static SimStruct *
childSFunctionPtrs [ 1 ] ; ( void ) memset ( ( void * ) & childSFunctions [ 0
] , 0 , sizeof ( childSFunctions ) ) ; ssSetSFunctions ( rtS , &
childSFunctionPtrs [ 0 ] ) ; ssSetSFunction ( rtS , 0 , & childSFunctions [ 0
] ) ; { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; static time_T
sfcnPeriod [ 1 ] ; static time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [
1 ] ; ( void ) memset ( ( void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ;
( void ) memset ( ( void * ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ;
ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts ,
& sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; {
static struct _ssBlkInfo2 _blkInfo2 ; struct _ssBlkInfo2 * blkInfo2 = &
_blkInfo2 ; ssSetBlkInfo2Ptr ( rts , blkInfo2 ) ; } { static struct
_ssPortInfo2 _portInfo2 ; struct _ssPortInfo2 * portInfo2 = & _portInfo2 ;
_ssSetBlkInfo2PortInfo2Ptr ( rts , portInfo2 ) ; } ssSetMdlInfoPtr ( rts ,
ssGetMdlInfoPtr ( rtS ) ) ; { static struct _ssSFcnModelMethods2 methods2 ;
ssSetModelMethods2 ( rts , & methods2 ) ; } { static struct
_ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , & methods3 ) ; } {
static struct _ssSFcnModelMethods4 methods4 ; ssSetModelMethods4 ( rts , &
methods4 ) ; } { static struct _ssStatesInfo2 statesInfo2 ; static
ssPeriodicStatesInfo periodicStatesInfo ; static ssJacobianPerturbationBounds
jacPerturbationBounds ; ssSetStatesInfo2 ( rts , & statesInfo2 ) ;
ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ;
ssSetJacobianPerturbationBounds ( rts , & jacPerturbationBounds ) ;
ssSetAbsTolVector ( rts , ssGetAbsTolVector ( rtS ) + 0 ) ;
ssSetAbsTolControlVector ( rts , ssGetAbsTolControlVector ( rtS ) + 0 ) ; } {
_ssSetNumInputPorts ( rts , 2 ) ; static struct _ssPortInputs inputPortInfo [
2 ] ; ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; { static
struct _ssInPortUnit inputPortUnits [ 2 ] ; _ssSetPortInfo2ForInputUnits (
rts , & inputPortUnits [ 0 ] ) ; } ssSetInputPortUnit ( rts , 0 , 0 ) ;
ssSetInputPortUnit ( rts , 1 , 0 ) ; { static struct _ssInPortCoSimAttribute
inputPortCoSimAttribute [ 2 ] ; _ssSetPortInfo2ForInputCoSimAttribute ( rts ,
& inputPortCoSimAttribute [ 0 ] ) ; } ssSetInputPortIsContinuousQuantity (
rts , 0 , 0 ) ; ssSetInputPortIsContinuousQuantity ( rts , 1 , 0 ) ; { static
real_T const * sfcnUPtrs [ 6 ] ; sfcnUPtrs [ 0 ] = & rtB . cnnmnegtoe ;
sfcnUPtrs [ 1 ] = & rtB . otx4h10gqp ; sfcnUPtrs [ 2 ] = & rtB . otltz4tihg ;
sfcnUPtrs [ 3 ] = & rtB . ou0uwhuegx ; sfcnUPtrs [ 4 ] = & rtB . a44meuoh25 ;
sfcnUPtrs [ 5 ] = & rtB . iho2fxkxre ; ssSetInputPortSignalPtrs ( rts , 0 , (
InputPtrsType ) & sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 0
, 1 ) ; ssSetInputPortWidthAsInt ( rts , 0 , 6 ) ; } { static real_T const *
sfcnUPtrs [ 3 ] ; sfcnUPtrs [ 0 ] = & rtB . pmio0r0doy ; sfcnUPtrs [ 1 ] = &
rtB . pbtg1zqog4 ; sfcnUPtrs [ 2 ] = & rtB . d0jsj1vn54 ;
ssSetInputPortSignalPtrs ( rts , 1 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 1 , 1 ) ; ssSetInputPortWidthAsInt ( rts
, 1 , 3 ) ; } } { static struct _ssPortOutputs outputPortInfo [ 2 ] ;
ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ] ) ;
_ssSetNumOutputPorts ( rts , 2 ) ; { static struct _ssOutPortUnit
outputPortUnits [ 2 ] ; _ssSetPortInfo2ForOutputUnits ( rts , &
outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ;
ssSetOutputPortUnit ( rts , 1 , 0 ) ; { static struct
_ssOutPortCoSimAttribute outputPortCoSimAttribute [ 2 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ;
ssSetOutputPortIsContinuousQuantity ( rts , 1 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidthAsInt (
rts , 0 , 2 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) rtB .
llymjhndln ) ) ; } { _ssSetOutputPortNumDimensions ( rts , 1 , 1 ) ;
ssSetOutputPortWidthAsInt ( rts , 1 , 6 ) ; ssSetOutputPortSignal ( rts , 1 ,
( ( real_T * ) rtB . mwvowazfto ) ) ; } } ssSetContStates ( rts , & rtX .
ldtzkz5puq [ 0 ] ) ; ssSetContStateDisabled ( rts , & ( ( XDis * )
ssGetContStateDisabled ( rtS ) ) -> ldtzkz5puq [ 0 ] ) ; { real_T * minVec =
& ( ( CXPtMin * ) ssGetJacobianPerturbationBoundsMinVec ( rtS ) ) ->
ldtzkz5puq [ 0 ] ; real_T * maxVec = & ( ( CXPtMax * )
ssGetJacobianPerturbationBoundsMaxVec ( rtS ) ) -> ldtzkz5puq [ 0 ] ;
ssSetJacobianPerturbationBoundsMinVec ( rts , minVec ) ;
ssSetJacobianPerturbationBoundsMaxVec ( rts , maxVec ) ; } ssSetModelName (
rts , "State-Space" ) ; ssSetPath ( rts ,
"Rectifier/powergui/EquivalentModel1/State-Space" ) ; if ( ssGetRTModel ( rtS
) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ; ssSetRootSS ( rts ,
ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts , ssGetRTModel ( rtS ) )
; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts , rts ) ; }
ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static mxArray *
sfcnParams [ 10 ] ; ssSetSFcnParamsCount ( rts , 10 ) ; ssSetSFcnParamsPtr (
rts , & sfcnParams [ 0 ] ) ; ssSetSFcnParam ( rts , 0 , ( mxArray * ) rtP .
StateSpace_P1_Size ) ; ssSetSFcnParam ( rts , 1 , ( mxArray * ) rtP .
StateSpace_P2_Size ) ; ssSetSFcnParam ( rts , 2 , ( mxArray * ) rtP .
StateSpace_P3_Size ) ; ssSetSFcnParam ( rts , 3 , ( mxArray * ) rtP .
StateSpace_P4_Size ) ; ssSetSFcnParam ( rts , 4 , ( mxArray * ) rtP .
StateSpace_P5_Size ) ; ssSetSFcnParam ( rts , 5 , ( mxArray * ) rtP .
StateSpace_P6_Size ) ; ssSetSFcnParam ( rts , 6 , ( mxArray * ) rtP .
StateSpace_P7_Size ) ; ssSetSFcnParam ( rts , 7 , ( mxArray * ) rtP .
StateSpace_P8_Size ) ; ssSetSFcnParam ( rts , 8 , ( mxArray * ) rtP .
StateSpace_P9_Size ) ; ssSetSFcnParam ( rts , 9 , ( mxArray * ) rtP .
StateSpace_P10_Size ) ; } ssSetRWork ( rts , ( real_T * ) & rtDW . awq4jr4str
[ 0 ] ) ; ssSetIWork ( rts , ( int_T * ) & rtDW . elswe02dqw [ 0 ] ) ;
ssSetPWork ( rts , ( void * * ) & rtDW . hmqbqk2szw [ 0 ] ) ; { static struct
_ssDWorkRecord dWorkRecord [ 4 ] ; static struct _ssDWorkAuxRecord
dWorkAuxRecord [ 4 ] ; ssSetSFcnDWork ( rts , dWorkRecord ) ;
ssSetSFcnDWorkAux ( rts , dWorkAuxRecord ) ; ssSetNumDWorkAsInt ( rts , 4 ) ;
ssSetDWorkWidthAsInt ( rts , 0 , 4 ) ; ssSetDWorkDataType ( rts , 0 ,
SS_INTEGER ) ; ssSetDWorkComplexSignal ( rts , 0 , 0 ) ; ssSetDWork ( rts , 0
, & rtDW . n5ib1rg2mq [ 0 ] ) ; ssSetDWorkWidthAsInt ( rts , 1 , 2 ) ;
ssSetDWorkDataType ( rts , 1 , SS_DOUBLE ) ; ssSetDWorkComplexSignal ( rts ,
1 , 0 ) ; ssSetDWork ( rts , 1 , & rtDW . awq4jr4str [ 0 ] ) ;
ssSetDWorkWidthAsInt ( rts , 2 , 23 ) ; ssSetDWorkDataType ( rts , 2 ,
SS_INTEGER ) ; ssSetDWorkComplexSignal ( rts , 2 , 0 ) ; ssSetDWork ( rts , 2
, & rtDW . elswe02dqw [ 0 ] ) ; ssSetDWorkWidthAsInt ( rts , 3 , 22 ) ;
ssSetDWorkDataType ( rts , 3 , SS_POINTER ) ; ssSetDWorkComplexSignal ( rts ,
3 , 0 ) ; ssSetDWork ( rts , 3 , & rtDW . hmqbqk2szw [ 0 ] ) ; }
ssSetModeVector ( rts , ( int_T * ) & rtDW . n5ib1rg2mq [ 0 ] ) ;
sfun_spid_contc ( rts ) ; sfcnInitializeSizes ( rts ) ;
sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 0.0 ) ;
ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 0 ;
ssSetNumNonsampledZCsAsInt ( rts , 4 ) ; _ssSetInputPortConnected ( rts , 0 ,
1 ) ; _ssSetInputPortConnected ( rts , 1 , 1 ) ; _ssSetOutputPortConnected (
rts , 0 , 1 ) ; _ssSetOutputPortConnected ( rts , 1 , 1 ) ;
_ssSetOutputPortBeingMerged ( rts , 0 , 0 ) ; _ssSetOutputPortBeingMerged (
rts , 1 , 0 ) ; ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ;
ssSetInputPortBufferDstPort ( rts , 1 , - 1 ) ; } } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
void MdlOutputsParameterSampleTime ( int_T tid ) { MdlOutputsTID2 ( tid ) ; }

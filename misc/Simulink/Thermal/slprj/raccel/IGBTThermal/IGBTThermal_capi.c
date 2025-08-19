#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "IGBTThermal_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 17
#endif
#ifndef SS_INT64
#define SS_INT64 18
#endif
#else
#include "builtin_typeid_types.h"
#include "IGBTThermal.h"
#include "IGBTThermal_capi.h"
#include "IGBTThermal_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"IGBTThermal/Pulse generator/Gate Drive at Freq1" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 1 , 0 , TARGET_STRING (
"IGBTThermal/Pulse generator/Gate Drive at Freq2" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 2 , 0 , TARGET_STRING (
"IGBTThermal/Pulse generator/Switch to Change Drive Frequency" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 3 , 0 , TARGET_STRING (
"IGBTThermal/Solver Configuration1/RTP_1" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 2 } , { 4 , 0 , TARGET_STRING (
"IGBTThermal/Solver Configuration1/EVAL_KEY/INPUT_1_1_1" ) , TARGET_STRING (
"" ) , 0 , 0 , 1 , 0 , 3 } , { 5 , 0 , TARGET_STRING (
"IGBTThermal/Solver Configuration1/EVAL_KEY/STATE_1" ) , TARGET_STRING ( "" )
, 0 , 0 , 2 , 0 , 3 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } }
; static const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 6 ,
TARGET_STRING ( "IGBTThermal/Step" ) , TARGET_STRING ( "Time" ) , 0 , 0 , 0 }
, { 7 , TARGET_STRING ( "IGBTThermal/Step" ) , TARGET_STRING ( "Before" ) , 0
, 0 , 0 } , { 8 , TARGET_STRING ( "IGBTThermal/Step" ) , TARGET_STRING (
"After" ) , 0 , 0 , 0 } , { 9 , TARGET_STRING (
"IGBTThermal/Pulse generator/Gate Drive at Freq1" ) , TARGET_STRING (
"Amplitude" ) , 0 , 0 , 0 } , { 10 , TARGET_STRING (
"IGBTThermal/Pulse generator/Gate Drive at Freq1" ) , TARGET_STRING (
"Period" ) , 0 , 0 , 0 } , { 11 , TARGET_STRING (
"IGBTThermal/Pulse generator/Gate Drive at Freq1" ) , TARGET_STRING (
"PulseWidth" ) , 0 , 0 , 0 } , { 12 , TARGET_STRING (
"IGBTThermal/Pulse generator/Gate Drive at Freq1" ) , TARGET_STRING (
"PhaseDelay" ) , 0 , 0 , 0 } , { 13 , TARGET_STRING (
"IGBTThermal/Pulse generator/Gate Drive at Freq2" ) , TARGET_STRING (
"Amplitude" ) , 0 , 0 , 0 } , { 14 , TARGET_STRING (
"IGBTThermal/Pulse generator/Gate Drive at Freq2" ) , TARGET_STRING (
"Period" ) , 0 , 0 , 0 } , { 15 , TARGET_STRING (
"IGBTThermal/Pulse generator/Gate Drive at Freq2" ) , TARGET_STRING (
"PulseWidth" ) , 0 , 0 , 0 } , { 16 , TARGET_STRING (
"IGBTThermal/Pulse generator/Gate Drive at Freq2" ) , TARGET_STRING (
"PhaseDelay" ) , 0 , 0 , 0 } , { 17 , TARGET_STRING (
"IGBTThermal/Pulse generator/Switch to Change Drive Frequency" ) ,
TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 18 , TARGET_STRING (
 "IGBTThermal/Subsystem_around_RTP_946ABF09_junction_temperature/Subsystem_around_RTP_946ABF09_junction_temperature"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 19 , TARGET_STRING (
 "IGBTThermal/Subsystem_around_RTP_E56942F7_junction_temperature/Subsystem_around_RTP_E56942F7_junction_temperature"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 20 , TARGET_STRING (
 "IGBTThermal/Buck circuit 1/Subsystem_around_RTP_21B4F4B5_i_L/Subsystem_around_RTP_21B4F4B5_i_L"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 21 , TARGET_STRING (
 "IGBTThermal/Buck circuit 1/Subsystem_around_RTP_56B3C423_vc/Subsystem_around_RTP_56B3C423_vc"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 22 , TARGET_STRING (
 "IGBTThermal/Buck circuit 2/Subsystem_around_RTP_E3A2801C_vc/Subsystem_around_RTP_E3A2801C_vc"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 23 , TARGET_STRING (
 "IGBTThermal/Buck circuit 2/Subsystem_around_RTP_ECBB6219_i_L/Subsystem_around_RTP_ECBB6219_i_L"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 ,
0 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static const
rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 ,
( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0 , ( NULL ) , 0 , 0 , 0
} } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . mtl5fmzosb , & rtB . exyxnjbkxi ,
& rtB . pjyzlfsjbp , & rtB . g3zz2ydtyn , & rtB . asbpxve2fe [ 0 ] , & rtB .
fz5khlwt30 [ 0 ] , & rtP . Step_Time , & rtP . Step_Y0 , & rtP . Step_YFinal
, & rtP . GateDriveatFreq1_Amp , & rtP . GateDriveatFreq1_Period , & rtP .
GateDriveatFreq1_Duty , & rtP . GateDriveatFreq1_PhaseDelay , & rtP .
GateDriveatFreq2_Amp , & rtP . GateDriveatFreq2_Period , & rtP .
GateDriveatFreq2_Duty , & rtP . GateDriveatFreq2_PhaseDelay , & rtP .
SwitchtoChangeDriveFrequency_Threshold , & rtP .
RTP_946ABF09_junction_temperature_Value , & rtP .
RTP_E56942F7_junction_temperature_Value , & rtP . RTP_21B4F4B5_i_L_Value , &
rtP . RTP_56B3C423_vc_Value , & rtP . RTP_E3A2801C_vc_Value , & rtP .
RTP_ECBB6219_i_L_Value , } ; static int32_T * rtVarDimsAddrMap [ ] = { ( NULL
) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } }
;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] = {
1 , 1 , 4 , 1 , 101 , 1 } ; static const real_T rtcapiStoredFloats [ ] = { -
2.0 , 0.0 , 1.0 } ; static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL
) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ; static
const rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , (
int8_T ) 2 , ( uint8_T ) 0 } , { ( const void * ) & rtcapiStoredFloats [ 0 ]
, ( const void * ) & rtcapiStoredFloats [ 2 ] , ( int8_T ) 3 , ( uint8_T ) 0
} , { ( const void * ) & rtcapiStoredFloats [ 1 ] , ( const void * ) &
rtcapiStoredFloats [ 2 ] , ( int8_T ) 1 , ( uint8_T ) 0 } , { ( const void *
) & rtcapiStoredFloats [ 1 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] ,
( int8_T ) 0 , ( uint8_T ) 0 } } ; static rtwCAPI_ModelMappingStaticInfo
mmiStatic = { { rtBlockSignals , 6 , rtRootInputs , 0 , rtRootOutputs , 0 } ,
{ rtBlockParameters , 18 , rtModelParameters , 0 } , { ( NULL ) , 0 } , {
rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap
, rtDimensionArray } , "float" , { 258682035U , 4189584627U , 2541426687U ,
3138470284U } , ( NULL ) , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ;
const rtwCAPI_ModelMappingStaticInfo * IGBTThermal_GetCAPIStaticMap ( void )
{ return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void IGBTThermal_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void IGBTThermal_host_InitializeDataMapInfo ( IGBTThermal_host_DataMapInfo_T
* dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ; rtwCAPI_SetPath
( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif

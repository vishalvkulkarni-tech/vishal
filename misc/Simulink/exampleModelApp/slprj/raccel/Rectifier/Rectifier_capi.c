#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "Rectifier_capi_host.h"
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
#include "Rectifier.h"
#include "Rectifier_capi.h"
#include "Rectifier_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"Rectifier/Id/do not delete this gain" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 0 } , { 1 , 0 , TARGET_STRING ( "Rectifier/Vd/do not delete this gain" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING (
"Rectifier/Diode1/Model/(gate)" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1
} , { 3 , 0 , TARGET_STRING ( "Rectifier/Diode1/Model/eee" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 1 } , { 4 , 0 , TARGET_STRING (
"Rectifier/Diode1/Model/Sum" ) , TARGET_STRING ( "v" ) , 0 , 0 , 0 , 0 , 0 }
, { 5 , 0 , TARGET_STRING ( "Rectifier/Diode2/Model/(gate)" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 1 } , { 6 , 0 , TARGET_STRING (
"Rectifier/Diode2/Model/eee" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } ,
{ 7 , 0 , TARGET_STRING ( "Rectifier/Diode3/Model/(gate)" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 8 , 0 , TARGET_STRING (
"Rectifier/Diode3/Model/eee" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } ,
{ 9 , 0 , TARGET_STRING ( "Rectifier/Diode3/Model/Sum" ) , TARGET_STRING (
"v" ) , 0 , 0 , 0 , 0 , 0 } , { 10 , 0 , TARGET_STRING (
"Rectifier/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "" ) ,
0 , 0 , 1 , 0 , 0 } , { 11 , 0 , TARGET_STRING (
"Rectifier/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "" ) ,
1 , 0 , 2 , 0 , 0 } , { 12 , 0 , TARGET_STRING ( "Rectifier/v1/Model/AC" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 13 , 0 , TARGET_STRING (
"Rectifier/v2/Model/AC" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 14
, 0 , TARGET_STRING ( "Rectifier/v3/Model/AC" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ;
static const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 15 ,
TARGET_STRING ( "Rectifier/Id/do not delete this gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 16 , TARGET_STRING (
"Rectifier/Vd/do not delete this gain" ) , TARGET_STRING ( "Gain" ) , 0 , 0 ,
0 } , { 17 , TARGET_STRING ( "Rectifier/Diode1/Model/(gate)" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 18 , TARGET_STRING (
"Rectifier/Diode1/Model/eee" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , {
19 , TARGET_STRING ( "Rectifier/Diode1/Model/Ron" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 20 , TARGET_STRING ( "Rectifier/Diode2/Model/(gate)" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 21 , TARGET_STRING (
"Rectifier/Diode2/Model/eee" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , {
22 , TARGET_STRING ( "Rectifier/Diode2/Model/Ron" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 23 , TARGET_STRING ( "Rectifier/Diode3/Model/(gate)" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 24 , TARGET_STRING (
"Rectifier/Diode3/Model/eee" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , {
25 , TARGET_STRING ( "Rectifier/Diode3/Model/Ron" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 26 , TARGET_STRING (
"Rectifier/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P1" )
, 0 , 3 , 0 } , { 27 , TARGET_STRING (
"Rectifier/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P2" )
, 0 , 4 , 0 } , { 28 , TARGET_STRING (
"Rectifier/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P3" )
, 0 , 5 , 0 } , { 29 , TARGET_STRING (
"Rectifier/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P4" )
, 0 , 6 , 0 } , { 30 , TARGET_STRING (
"Rectifier/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P5" )
, 0 , 7 , 0 } , { 31 , TARGET_STRING (
"Rectifier/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P6" )
, 0 , 8 , 0 } , { 32 , TARGET_STRING (
"Rectifier/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P7" )
, 0 , 9 , 0 } , { 33 , TARGET_STRING (
"Rectifier/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P8" )
, 0 , 8 , 0 } , { 34 , TARGET_STRING (
"Rectifier/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P9" )
, 0 , 0 , 0 } , { 35 , TARGET_STRING (
"Rectifier/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P10" )
, 0 , 0 , 0 } , { 36 , TARGET_STRING ( "Rectifier/v1/Model/AC" ) ,
TARGET_STRING ( "Bias" ) , 0 , 0 , 0 } , { 37 , TARGET_STRING (
"Rectifier/v2/Model/AC" ) , TARGET_STRING ( "Bias" ) , 0 , 0 , 0 } , { 38 ,
TARGET_STRING ( "Rectifier/v3/Model/AC" ) , TARGET_STRING ( "Bias" ) , 0 , 0
, 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 } } ; static int_T
rt_LoggedStateIdxList [ ] = { - 1 } ; static const rtwCAPI_Signals
rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ;
static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 , ( NULL ) , (
NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_ModelParameters
rtModelParameters [ ] = { { 39 , TARGET_STRING ( "frequency_voltage1" ) , 0 ,
0 , 0 } , { 40 , TARGET_STRING ( "frequency_voltage2" ) , 0 , 0 , 0 } , { 41
, TARGET_STRING ( "frequency_voltage3" ) , 0 , 0 , 0 } , { 42 , TARGET_STRING
( "peakAmplitude_voltage1" ) , 0 , 0 , 0 } , { 43 , TARGET_STRING (
"peakAmplitude_voltage2" ) , 0 , 0 , 0 } , { 44 , TARGET_STRING (
"peakAmplitude_voltage3" ) , 0 , 0 , 0 } , { 45 , TARGET_STRING (
"phaseInDegree_voltage1" ) , 0 , 0 , 0 } , { 46 , TARGET_STRING (
"phaseInDegree_voltage2" ) , 0 , 0 , 0 } , { 47 , TARGET_STRING (
"phaseInDegree_voltage3" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . out0qpal0x , & rtB . ocbbvf4ln3 ,
& rtB . pmio0r0doy , & rtB . ou0uwhuegx , & rtB . cx12fc0yyz , & rtB .
pbtg1zqog4 , & rtB . a44meuoh25 , & rtB . d0jsj1vn54 , & rtB . iho2fxkxre , &
rtB . nz02ivetdb , & rtB . llymjhndln [ 0 ] , & rtB . mwvowazfto [ 0 ] , &
rtB . cnnmnegtoe , & rtB . otx4h10gqp , & rtB . otltz4tihg , & rtP .
donotdeletethisgain_Gain_hsnae3wadg , & rtP . donotdeletethisgain_Gain , &
rtP . gate_Value_graafvp4kv , & rtP . eee_Value_ltt5dvhgzf , & rtP .
Ron_Gain_heqalhhamz , & rtP . gate_Value , & rtP . eee_Value , & rtP .
Ron_Gain_gisotimrpi , & rtP . gate_Value_a1aaq4xqpt , & rtP .
eee_Value_ezp1ppxfvo , & rtP . Ron_Gain , & rtP . StateSpace_P1 [ 0 ] , & rtP
. StateSpace_P2 [ 0 ] , & rtP . StateSpace_P3 [ 0 ] , & rtP . StateSpace_P4 [
0 ] , & rtP . StateSpace_P5 [ 0 ] , & rtP . StateSpace_P6 [ 0 ] , & rtP .
StateSpace_P7 [ 0 ] , & rtP . StateSpace_P8 [ 0 ] , & rtP . StateSpace_P9 , &
rtP . StateSpace_P10 , & rtP . AC_Bias , & rtP . AC_Bias_ckphr0qig4 , & rtP .
AC_Bias_eyfr42ua5t , & rtP . frequency_voltage1 , & rtP . frequency_voltage2
, & rtP . frequency_voltage3 , & rtP . peakAmplitude_voltage1 , & rtP .
peakAmplitude_voltage2 , & rtP . peakAmplitude_voltage3 , & rtP .
phaseInDegree_voltage1 , & rtP . phaseInDegree_voltage2 , & rtP .
phaseInDegree_voltage3 , } ; static int32_T * rtVarDimsAddrMap [ ] = { ( NULL
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
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 6 , 2 , 0 } , {
rtwCAPI_VECTOR , 8 , 2 , 0 } , { rtwCAPI_VECTOR , 10 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 12 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 14 , 2
, 0 } , { rtwCAPI_VECTOR , 16 , 2 , 0 } , { rtwCAPI_VECTOR , 18 , 2 , 0 } } ;
static const uint_T rtDimensionArray [ ] = { 1 , 1 , 2 , 1 , 6 , 1 , 35 , 12
, 1 , 4 , 7 , 1 , 35 , 19 , 2 , 3 , 1 , 3 , 3 , 1 } ; static const real_T
rtcapiStoredFloats [ ] = { 0.0 } ; static const rtwCAPI_FixPtMap rtFixPtMap [
] = { { ( NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0
} , } ; static const rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const
void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [
0 ] , ( int8_T ) 0 , ( uint8_T ) 0 } , { ( NULL ) , ( NULL ) , 2 , 0 } } ;
static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 15 ,
rtRootInputs , 0 , rtRootOutputs , 0 } , { rtBlockParameters , 24 ,
rtModelParameters , 9 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 892092326U , 2020949463U , 2295649570U , 3430351693U } , ( NULL ) , 0 , (
boolean_T ) 0 , rt_LoggedStateIdxList } ; const
rtwCAPI_ModelMappingStaticInfo * Rectifier_GetCAPIStaticMap ( void ) { return
& mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void Rectifier_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
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
void Rectifier_host_InitializeDataMapInfo ( Rectifier_host_DataMapInfo_T *
dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
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

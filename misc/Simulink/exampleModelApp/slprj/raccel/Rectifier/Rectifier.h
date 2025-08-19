#ifndef RTW_HEADER_Rectifier_h_
#define RTW_HEADER_Rectifier_h_
#ifndef Rectifier_COMMON_INCLUDES_
#define Rectifier_COMMON_INCLUDES_
#include <stdlib.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "Rectifier_types.h"
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME Rectifier
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (15) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (7)   
#elif NCSTATES != 7
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T cnnmnegtoe ; real_T otx4h10gqp ; real_T otltz4tihg ;
real_T llymjhndln [ 2 ] ; real_T mwvowazfto [ 6 ] ; real_T ocbbvf4ln3 ;
real_T out0qpal0x ; real_T nz02ivetdb ; real_T cx12fc0yyz ; real_T a44meuoh25
; real_T pbtg1zqog4 ; real_T iho2fxkxre ; real_T d0jsj1vn54 ; real_T
ou0uwhuegx ; real_T pmio0r0doy ; } B ; typedef struct { real_T awq4jr4str [ 2
] ; void * hmqbqk2szw [ 22 ] ; struct { void * LoggedData [ 4 ] ; }
oeybejg1lp ; struct { void * AQHandles ; } dtwh04wcp2 ; struct { void *
AQHandles ; } cyx1kfcdlz ; struct { void * AQHandles ; } htww4gle3c ; struct
{ void * AQHandles ; } gc3hjjbgux ; struct { void * LoggedData ; } hybnqng5i0
; struct { void * AQHandles [ 2 ] ; } aebfs1h4gh ; int_T elswe02dqw [ 23 ] ;
int_T n5ib1rg2mq [ 4 ] ; } DW ; typedef struct { real_T ldtzkz5puq [ 7 ] ; }
X ; typedef struct { real_T ldtzkz5puq [ 7 ] ; } XDot ; typedef struct {
boolean_T ldtzkz5puq [ 7 ] ; } XDis ; typedef struct { real_T ldtzkz5puq [ 7
] ; } CStateAbsTol ; typedef struct { real_T ldtzkz5puq [ 7 ] ; } CXPtMin ;
typedef struct { real_T ldtzkz5puq [ 7 ] ; } CXPtMax ; typedef struct {
real_T babq5df4pt [ 4 ] ; } ZCV ; typedef struct { rtwCAPI_ModelMappingInfo
mmi ; } DataMapInfo ; struct P_ { real_T frequency_voltage1 ; real_T
frequency_voltage2 ; real_T frequency_voltage3 ; real_T
peakAmplitude_voltage1 ; real_T peakAmplitude_voltage2 ; real_T
peakAmplitude_voltage3 ; real_T phaseInDegree_voltage1 ; real_T
phaseInDegree_voltage2 ; real_T phaseInDegree_voltage3 ; real_T AC_Bias ;
real_T AC_Bias_ckphr0qig4 ; real_T AC_Bias_eyfr42ua5t ; real_T
StateSpace_P1_Size [ 2 ] ; real_T StateSpace_P1 [ 420 ] ; real_T
StateSpace_P2_Size [ 2 ] ; real_T StateSpace_P2 [ 4 ] ; real_T
StateSpace_P3_Size [ 2 ] ; real_T StateSpace_P3 [ 7 ] ; real_T
StateSpace_P4_Size [ 2 ] ; real_T StateSpace_P4 [ 665 ] ; real_T
StateSpace_P5_Size [ 2 ] ; real_T StateSpace_P5 [ 6 ] ; real_T
StateSpace_P6_Size [ 2 ] ; real_T StateSpace_P6 [ 3 ] ; real_T
StateSpace_P7_Size [ 2 ] ; real_T StateSpace_P7 [ 3 ] ; real_T
StateSpace_P8_Size [ 2 ] ; real_T StateSpace_P8 [ 3 ] ; real_T
StateSpace_P9_Size [ 2 ] ; real_T StateSpace_P9 ; real_T StateSpace_P10_Size
[ 2 ] ; real_T StateSpace_P10 ; real_T donotdeletethisgain_Gain ; real_T
donotdeletethisgain_Gain_hsnae3wadg ; real_T Ron_Gain ; real_T
Ron_Gain_gisotimrpi ; real_T Ron_Gain_heqalhhamz ; real_T eee_Value ; real_T
gate_Value ; real_T eee_Value_ezp1ppxfvo ; real_T gate_Value_a1aaq4xqpt ;
real_T eee_Value_ltt5dvhgzf ; real_T gate_Value_graafvp4kv ; } ; extern const
char_T * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW
rtDW ; extern P rtP ; extern mxArray * mr_Rectifier_GetDWork ( ) ; extern
void mr_Rectifier_SetDWork ( const mxArray * ssDW ) ; extern mxArray *
mr_Rectifier_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * Rectifier_GetCAPIStaticMap ( void ) ; extern
SimStruct * const rtS ; extern DataMapInfo * rt_dataMapInfoPtr ; extern
rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid )
; void MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T
tid ) ; void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model (
ssExecutionInfo * executionInfo ) ;
#endif

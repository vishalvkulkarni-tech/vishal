#ifndef RTW_HEADER_IGBTThermal_h_
#define RTW_HEADER_IGBTThermal_h_
#ifndef IGBTThermal_COMMON_INCLUDES_
#define IGBTThermal_COMMON_INCLUDES_
#include <stdlib.h>
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
#include "nesl_rtw_rtp.h"
#include "IGBTThermal_399ad5b0_1_gateway.h"
#include "nesl_rtw.h"
#include "physmod/common/logging2/core/rtw/SscRTWLogging.h"
#include "stdlib.h"
#include "ssc_rtw_logging.h"
#include "physmod/common/logging2/core/rtw/rtw_log_fcn_manager.h"
#endif
#include "IGBTThermal_types.h"
#include <string.h>
#include <stddef.h>
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "zero_crossing_types.h"
#define MODEL_NAME IGBTThermal
#define NSAMPLE_TIMES (5) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (6) 
#define NUM_ZC_EVENTS (50) 
#ifndef NCSTATES
#define NCSTATES (26)   
#elif NCSTATES != 26
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
typedef struct { real_T mtl5fmzosb ; real_T exyxnjbkxi ; real_T pjyzlfsjbp ;
real_T g3zz2ydtyn ; real_T asbpxve2fe [ 4 ] ; real_T fz5khlwt30 [ 101 ] ; } B
; typedef struct { real_T noegxjaqfo [ 2 ] ; real_T dabkhrlstr [ 81 ] ;
real_T l0gf3i5n0p ; real_T netor1vfyv ; int64_T mtoyvs1lsx ; int64_T
bthvtfhgxh ; void * o3b342cdix ; void * neueknlloj ; void * fmv0dg0a4q ; void
* ovgmafyfkv ; void * k2tzkal333 ; void * jlzetobres ; void * js4kj4cuzy ;
void * bfynxmcvmi ; void * edlibngn3n ; struct { void * LoggedData ; }
md305jkrjz ; int32_T npc3xna3zg ; int32_T bwzok3eybt ; int32_T po350bcjbl ;
int32_T klvwjtvlp5 ; int_T oooz0jah34 [ 58 ] ; int_T lqjazq4u1m ; int32_T
hhrpqbjqvn ; boolean_T dmisypodkz ; boolean_T ofsbfnuf4a ; } DW ; typedef
struct { real_T ivwbjv4zes [ 26 ] ; } X ; typedef struct { real_T ivwbjv4zes
[ 26 ] ; } XDot ; typedef struct { boolean_T ivwbjv4zes [ 26 ] ; } XDis ;
typedef struct { real_T ivwbjv4zes [ 26 ] ; } CStateAbsTol ; typedef struct {
real_T ivwbjv4zes [ 26 ] ; } CXPtMin ; typedef struct { real_T ivwbjv4zes [
26 ] ; } CXPtMax ; typedef struct { real_T datgzkb1oj ; real_T npqmchkgek ;
real_T dtczxwtard ; real_T kmswmssukz ; real_T fluzk3lsqw ; real_T bup0wkvidi
; real_T pqu2m3h2qv ; real_T nxrxhnrftk ; real_T hyjnaj3y0d ; real_T
cqlplu1kqo ; real_T aw5eew4htl ; real_T n04v4akbvx ; real_T kpao5ynu0g ;
real_T ftexoulafw ; real_T pkgvlvw5iw ; real_T knyn0ca1m4 ; real_T jyg0sd2qjs
; real_T ajzcz2q4yf ; real_T kvkzatve5h ; real_T axcqtckpdx ; real_T
pks1whtsyd ; real_T g0g0t2dm52 ; real_T hzeuf1tlfv ; real_T efqpbg5ygw ;
real_T fu4ilrbk1g ; real_T avbo3bbiaz ; real_T hg4xzgkum2 ; real_T fg2atst0wk
; real_T jnsqaqellf ; real_T ponhxszbop ; real_T jbfh5hh4dp ; real_T
jjop0rwfh1 ; real_T egjsv3ycgg ; real_T macqg5tmxl ; real_T hyhajt1hqd ;
real_T kfg1uccpcb ; real_T alqj5sx5el ; real_T ci3huinrmh ; real_T lthjiz1orm
; real_T eobl3i5r2n ; real_T drm2t01uwy ; real_T i0yehtkcsh ; real_T
fgwgi33qc2 ; real_T kutlpfyh25 ; real_T haynaxcesz ; real_T d3u0tohqdf ;
real_T fby3nlveez ; real_T o4tktnqly4 ; real_T eoyrvlbs0p ; real_T ixeueqsbju
; real_T motywvktly ; } ZCV ; typedef struct { ZCSigState iyhnoaqvfy ;
ZCSigState k3zwkmzd4h ; ZCSigState ione2unr3o ; ZCSigState dtbi5h4dzo ;
ZCSigState kh4c5mvssu ; ZCSigState gray30kr4i ; ZCSigState ah2ikpnlcq ;
ZCSigState pkvyjeskme ; ZCSigState lkffzqx44l ; ZCSigState phhmw4nyfi ;
ZCSigState bnvccxeb4z ; ZCSigState f4dtbisug0 ; ZCSigState kgn5gvwv5w ;
ZCSigState jnve2shjqy ; ZCSigState cr14zhlt1h ; ZCSigState l0aat4arr5 ;
ZCSigState ljmgdnnjob ; ZCSigState lmuvbde52o ; ZCSigState mjyg0bovqo ;
ZCSigState bytvymqvxw ; ZCSigState pi2bwxu0lj ; ZCSigState jx4nurkcqa ;
ZCSigState nzej4c0ese ; ZCSigState dh3dve443d ; ZCSigState olzmhab3ou ;
ZCSigState jtybie1tf1 ; ZCSigState cm3cpdk5iw ; ZCSigState lwcbqbw5gf ;
ZCSigState eoribhfge2 ; ZCSigState lcoedbcecj ; ZCSigState c2c0pupgz5 ;
ZCSigState m5ledqzuue ; ZCSigState jnsqnbahd1 ; ZCSigState gbw3qukkxo ;
ZCSigState ptm0mjwcn2 ; ZCSigState j4m1ilahzc ; ZCSigState mnw1n31qs3 ;
ZCSigState lbhsjcxi42 ; ZCSigState ewxypzm3zn ; ZCSigState fxuys4bad5 ;
ZCSigState biyjkdwqbw ; ZCSigState i3ewbsg25r ; ZCSigState hfr1gluplx ;
ZCSigState bbidofqoix ; ZCSigState gseert0nr2 ; ZCSigState cwfdsmndpz ;
ZCSigState mf0wyfofqu ; ZCSigState pjfnezhmyf ; ZCSigState dybc4pfzcn ;
ZCSigState fupdf2ubg0 ; } PrevZCX ; typedef struct { int_T ir [ 39 ] ; int_T
jc [ 27 ] ; real_T pr [ 39 ] ; } MassMatrix ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T
GateDriveatFreq1_Amp ; real_T GateDriveatFreq1_Period ; real_T
GateDriveatFreq1_Duty ; real_T GateDriveatFreq1_PhaseDelay ; real_T
GateDriveatFreq2_Amp ; real_T GateDriveatFreq2_Period ; real_T
GateDriveatFreq2_Duty ; real_T GateDriveatFreq2_PhaseDelay ; real_T Step_Time
; real_T Step_Y0 ; real_T Step_YFinal ; real_T
SwitchtoChangeDriveFrequency_Threshold ; real_T RTP_21B4F4B5_i_L_Value ;
real_T RTP_56B3C423_vc_Value ; real_T RTP_E3A2801C_vc_Value ; real_T
RTP_ECBB6219_i_L_Value ; real_T RTP_946ABF09_junction_temperature_Value ;
real_T RTP_E56942F7_junction_temperature_Value ; } ; extern const real_T
IGBTThermal_RGND ; extern const char_T * RT_MEMORY_ALLOCATION_ERROR ; extern
B rtB ; extern X rtX ; extern DW rtDW ; extern PrevZCX rtPrevZCX ; extern
MassMatrix rtMassMatrix ; extern P rtP ; extern mxArray *
mr_IGBTThermal_GetDWork ( ) ; extern void mr_IGBTThermal_SetDWork ( const
mxArray * ssDW ) ; extern mxArray *
mr_IGBTThermal_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * IGBTThermal_GetCAPIStaticMap ( void ) ;
extern SimStruct * const rtS ; extern DataMapInfo * rt_dataMapInfoPtr ;
extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ; void MdlOutputs (
int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T tid ) ; void
MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) ;
#endif

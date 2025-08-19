#include "ne_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_sys_struct.h"
#include "IGBTThermal_399ad5b0_1_ds_ic.h"
#include "IGBTThermal_399ad5b0_1_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_externals.h"
#include "IGBTThermal_399ad5b0_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T IGBTThermal_399ad5b0_1_ds_ic ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t4 , NeDsMethodOutput * t5 ) { PmRealVector out ;
real_T P_R_idx_0 ; real_T P_R_idx_1 ; real_T P_R_idx_2 ; real_T P_R_idx_3 ; (
void ) LC ; P_R_idx_0 = t4 -> mP_R . mX [ 0 ] ; P_R_idx_1 = t4 -> mP_R . mX [
1 ] ; P_R_idx_2 = t4 -> mP_R . mX [ 2 ] ; P_R_idx_3 = t4 -> mP_R . mX [ 3 ] ;
out = t5 -> mIC ; out . mX [ 0 ] = P_R_idx_0 ; out . mX [ 1 ] = P_R_idx_1 ;
out . mX [ 2 ] = P_R_idx_2 ; out . mX [ 3 ] = P_R_idx_3 ; out . mX [ 4 ] =
298.15 ; out . mX [ 5 ] = 298.15 ; out . mX [ 6 ] = 298.15 ; out . mX [ 7 ] =
300.0 ; out . mX [ 8 ] = 298.15 ; out . mX [ 9 ] = 298.15 ; out . mX [ 10 ] =
298.15 ; out . mX [ 11 ] = 300.0 ; out . mX [ 12 ] = 300.0 ; out . mX [ 13 ]
= 0.0 ; out . mX [ 14 ] = 0.0 ; out . mX [ 15 ] = 0.0 ; out . mX [ 16 ] = 0.0
; out . mX [ 17 ] = 0.0 ; out . mX [ 18 ] = 0.0 ; out . mX [ 19 ] = 0.0 ; out
. mX [ 20 ] = 0.0 ; out . mX [ 21 ] = 0.0 ; out . mX [ 22 ] = 0.0 ; out . mX
[ 23 ] = 0.0 ; out . mX [ 24 ] = 0.0 ; out . mX [ 25 ] = 0.0 ; ( void ) LC ;
( void ) t5 ; return 0 ; }

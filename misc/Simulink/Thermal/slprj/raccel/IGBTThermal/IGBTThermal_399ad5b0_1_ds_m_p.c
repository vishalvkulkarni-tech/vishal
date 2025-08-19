#include "ne_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_sys_struct.h"
#include "IGBTThermal_399ad5b0_1_ds_m_p.h"
#include "IGBTThermal_399ad5b0_1_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_externals.h"
#include "IGBTThermal_399ad5b0_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T IGBTThermal_399ad5b0_1_ds_m_p ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern out ;
( void ) t1 ; ( void ) LC ; out = t2 -> mM_P ; out . mNumCol = 26ULL ; out .
mNumRow = 26ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 1 ; out . mJc [ 2 ]
= 2 ; out . mJc [ 3 ] = 3 ; out . mJc [ 4 ] = 4 ; out . mJc [ 5 ] = 7 ; out .
mJc [ 6 ] = 10 ; out . mJc [ 7 ] = 13 ; out . mJc [ 8 ] = 14 ; out . mJc [ 9
] = 17 ; out . mJc [ 10 ] = 20 ; out . mJc [ 11 ] = 23 ; out . mJc [ 12 ] =
24 ; out . mJc [ 13 ] = 25 ; out . mJc [ 14 ] = 25 ; out . mJc [ 15 ] = 25 ;
out . mJc [ 16 ] = 25 ; out . mJc [ 17 ] = 25 ; out . mJc [ 18 ] = 25 ; out .
mJc [ 19 ] = 25 ; out . mJc [ 20 ] = 25 ; out . mJc [ 21 ] = 25 ; out . mJc [
22 ] = 25 ; out . mJc [ 23 ] = 25 ; out . mJc [ 24 ] = 25 ; out . mJc [ 25 ]
= 25 ; out . mJc [ 26 ] = 25 ; out . mIr [ 0 ] = 0 ; out . mIr [ 1 ] = 1 ;
out . mIr [ 2 ] = 2 ; out . mIr [ 3 ] = 3 ; out . mIr [ 4 ] = 4 ; out . mIr [
5 ] = 5 ; out . mIr [ 6 ] = 6 ; out . mIr [ 7 ] = 4 ; out . mIr [ 8 ] = 5 ;
out . mIr [ 9 ] = 6 ; out . mIr [ 10 ] = 4 ; out . mIr [ 11 ] = 5 ; out . mIr
[ 12 ] = 6 ; out . mIr [ 13 ] = 7 ; out . mIr [ 14 ] = 9 ; out . mIr [ 15 ] =
10 ; out . mIr [ 16 ] = 11 ; out . mIr [ 17 ] = 9 ; out . mIr [ 18 ] = 10 ;
out . mIr [ 19 ] = 11 ; out . mIr [ 20 ] = 9 ; out . mIr [ 21 ] = 10 ; out .
mIr [ 22 ] = 11 ; out . mIr [ 23 ] = 12 ; out . mIr [ 24 ] = 8 ; ( void ) LC
; ( void ) t2 ; return 0 ; }

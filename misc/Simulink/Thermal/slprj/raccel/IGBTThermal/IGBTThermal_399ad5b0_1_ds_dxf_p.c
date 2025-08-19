#include "ne_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_sys_struct.h"
#include "IGBTThermal_399ad5b0_1_ds_dxf_p.h"
#include "IGBTThermal_399ad5b0_1_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_externals.h"
#include "IGBTThermal_399ad5b0_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T IGBTThermal_399ad5b0_1_ds_dxf_p ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern out ;
( void ) t1 ; ( void ) LC ; out = t2 -> mDXF_P ; out . mNumCol = 26ULL ; out
. mNumRow = 26ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 0 ; out . mJc [ 2
] = 1 ; out . mJc [ 3 ] = 1 ; out . mJc [ 4 ] = 2 ; out . mJc [ 5 ] = 4 ; out
. mJc [ 6 ] = 6 ; out . mJc [ 7 ] = 8 ; out . mJc [ 8 ] = 9 ; out . mJc [ 9 ]
= 9 ; out . mJc [ 10 ] = 9 ; out . mJc [ 11 ] = 9 ; out . mJc [ 12 ] = 10 ;
out . mJc [ 13 ] = 12 ; out . mJc [ 14 ] = 15 ; out . mJc [ 15 ] = 18 ; out .
mJc [ 16 ] = 20 ; out . mJc [ 17 ] = 23 ; out . mJc [ 18 ] = 26 ; out . mJc [
19 ] = 28 ; out . mJc [ 20 ] = 30 ; out . mJc [ 21 ] = 30 ; out . mJc [ 22 ]
= 32 ; out . mJc [ 23 ] = 34 ; out . mJc [ 24 ] = 34 ; out . mJc [ 25 ] = 34
; out . mJc [ 26 ] = 36 ; out . mIr [ 0 ] = 14 ; out . mIr [ 1 ] = 16 ; out .
mIr [ 2 ] = 18 ; out . mIr [ 3 ] = 20 ; out . mIr [ 4 ] = 18 ; out . mIr [ 5
] = 20 ; out . mIr [ 6 ] = 18 ; out . mIr [ 7 ] = 20 ; out . mIr [ 8 ] = 20 ;
out . mIr [ 9 ] = 25 ; out . mIr [ 10 ] = 23 ; out . mIr [ 11 ] = 25 ; out .
mIr [ 12 ] = 13 ; out . mIr [ 13 ] = 22 ; out . mIr [ 14 ] = 23 ; out . mIr [
15 ] = 14 ; out . mIr [ 16 ] = 22 ; out . mIr [ 17 ] = 23 ; out . mIr [ 18 ]
= 13 ; out . mIr [ 19 ] = 14 ; out . mIr [ 20 ] = 15 ; out . mIr [ 21 ] = 17
; out . mIr [ 22 ] = 18 ; out . mIr [ 23 ] = 16 ; out . mIr [ 24 ] = 17 ; out
. mIr [ 25 ] = 18 ; out . mIr [ 26 ] = 15 ; out . mIr [ 27 ] = 16 ; out . mIr
[ 28 ] = 19 ; out . mIr [ 29 ] = 20 ; out . mIr [ 30 ] = 19 ; out . mIr [ 31
] = 20 ; out . mIr [ 32 ] = 24 ; out . mIr [ 33 ] = 25 ; out . mIr [ 34 ] =
24 ; out . mIr [ 35 ] = 25 ; ( void ) LC ; ( void ) t2 ; return 0 ; }

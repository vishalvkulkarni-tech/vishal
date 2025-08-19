#include "ne_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_sys_struct.h"
#include "IGBTThermal_399ad5b0_1_ds_tdxf_p.h"
#include "IGBTThermal_399ad5b0_1_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_externals.h"
#include "IGBTThermal_399ad5b0_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T IGBTThermal_399ad5b0_1_ds_tdxf_p ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern out ;
( void ) t1 ; ( void ) LC ; out = t2 -> mTDXF_P ; out . mNumCol = 26ULL ; out
. mNumRow = 26ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 2 ; out . mJc [ 2
] = 5 ; out . mJc [ 3 ] = 7 ; out . mJc [ 4 ] = 10 ; out . mJc [ 5 ] = 16 ;
out . mJc [ 6 ] = 22 ; out . mJc [ 7 ] = 28 ; out . mJc [ 8 ] = 29 ; out .
mJc [ 9 ] = 34 ; out . mJc [ 10 ] = 39 ; out . mJc [ 11 ] = 44 ; out . mJc [
12 ] = 45 ; out . mJc [ 13 ] = 48 ; out . mJc [ 14 ] = 52 ; out . mJc [ 15 ]
= 55 ; out . mJc [ 16 ] = 57 ; out . mJc [ 17 ] = 61 ; out . mJc [ 18 ] = 64
; out . mJc [ 19 ] = 66 ; out . mJc [ 20 ] = 69 ; out . mJc [ 21 ] = 73 ; out
. mJc [ 22 ] = 76 ; out . mJc [ 23 ] = 79 ; out . mJc [ 24 ] = 81 ; out . mJc
[ 25 ] = 85 ; out . mJc [ 26 ] = 88 ; out . mIr [ 0 ] = 0 ; out . mIr [ 1 ] =
1 ; out . mIr [ 2 ] = 0 ; out . mIr [ 3 ] = 1 ; out . mIr [ 4 ] = 14 ; out .
mIr [ 5 ] = 2 ; out . mIr [ 6 ] = 3 ; out . mIr [ 7 ] = 2 ; out . mIr [ 8 ] =
3 ; out . mIr [ 9 ] = 16 ; out . mIr [ 10 ] = 4 ; out . mIr [ 11 ] = 5 ; out
. mIr [ 12 ] = 6 ; out . mIr [ 13 ] = 17 ; out . mIr [ 14 ] = 18 ; out . mIr
[ 15 ] = 20 ; out . mIr [ 16 ] = 4 ; out . mIr [ 17 ] = 5 ; out . mIr [ 18 ]
= 6 ; out . mIr [ 19 ] = 17 ; out . mIr [ 20 ] = 18 ; out . mIr [ 21 ] = 20 ;
out . mIr [ 22 ] = 4 ; out . mIr [ 23 ] = 5 ; out . mIr [ 24 ] = 6 ; out .
mIr [ 25 ] = 17 ; out . mIr [ 26 ] = 18 ; out . mIr [ 27 ] = 20 ; out . mIr [
28 ] = 20 ; out . mIr [ 29 ] = 9 ; out . mIr [ 30 ] = 10 ; out . mIr [ 31 ] =
11 ; out . mIr [ 32 ] = 21 ; out . mIr [ 33 ] = 22 ; out . mIr [ 34 ] = 9 ;
out . mIr [ 35 ] = 10 ; out . mIr [ 36 ] = 11 ; out . mIr [ 37 ] = 21 ; out .
mIr [ 38 ] = 22 ; out . mIr [ 39 ] = 9 ; out . mIr [ 40 ] = 10 ; out . mIr [
41 ] = 11 ; out . mIr [ 42 ] = 21 ; out . mIr [ 43 ] = 22 ; out . mIr [ 44 ]
= 25 ; out . mIr [ 45 ] = 21 ; out . mIr [ 46 ] = 23 ; out . mIr [ 47 ] = 25
; out . mIr [ 48 ] = 1 ; out . mIr [ 49 ] = 13 ; out . mIr [ 50 ] = 22 ; out
. mIr [ 51 ] = 23 ; out . mIr [ 52 ] = 14 ; out . mIr [ 53 ] = 22 ; out . mIr
[ 54 ] = 23 ; out . mIr [ 55 ] = 13 ; out . mIr [ 56 ] = 14 ; out . mIr [ 57
] = 3 ; out . mIr [ 58 ] = 15 ; out . mIr [ 59 ] = 17 ; out . mIr [ 60 ] = 18
; out . mIr [ 61 ] = 16 ; out . mIr [ 62 ] = 17 ; out . mIr [ 63 ] = 18 ; out
. mIr [ 64 ] = 15 ; out . mIr [ 65 ] = 16 ; out . mIr [ 66 ] = 17 ; out . mIr
[ 67 ] = 19 ; out . mIr [ 68 ] = 20 ; out . mIr [ 69 ] = 4 ; out . mIr [ 70 ]
= 5 ; out . mIr [ 71 ] = 6 ; out . mIr [ 72 ] = 17 ; out . mIr [ 73 ] = 7 ;
out . mIr [ 74 ] = 19 ; out . mIr [ 75 ] = 20 ; out . mIr [ 76 ] = 22 ; out .
mIr [ 77 ] = 24 ; out . mIr [ 78 ] = 25 ; out . mIr [ 79 ] = 8 ; out . mIr [
80 ] = 22 ; out . mIr [ 81 ] = 9 ; out . mIr [ 82 ] = 10 ; out . mIr [ 83 ] =
11 ; out . mIr [ 84 ] = 22 ; out . mIr [ 85 ] = 12 ; out . mIr [ 86 ] = 24 ;
out . mIr [ 87 ] = 25 ; ( void ) LC ; ( void ) t2 ; return 0 ; }

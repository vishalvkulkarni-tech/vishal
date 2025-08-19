#include "ne_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_sys_struct.h"
#include "IGBTThermal_399ad5b0_1_ds_a_p.h"
#include "IGBTThermal_399ad5b0_1_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_externals.h"
#include "IGBTThermal_399ad5b0_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T IGBTThermal_399ad5b0_1_ds_a_p ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern out ;
( void ) t1 ; ( void ) LC ; out = t2 -> mA_P ; out . mNumCol = 26ULL ; out .
mNumRow = 26ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 2 ; out . mJc [ 2 ]
= 4 ; out . mJc [ 3 ] = 6 ; out . mJc [ 4 ] = 8 ; out . mJc [ 5 ] = 12 ; out
. mJc [ 6 ] = 16 ; out . mJc [ 7 ] = 20 ; out . mJc [ 8 ] = 20 ; out . mJc [
9 ] = 25 ; out . mJc [ 10 ] = 30 ; out . mJc [ 11 ] = 35 ; out . mJc [ 12 ] =
35 ; out . mJc [ 13 ] = 36 ; out . mJc [ 14 ] = 37 ; out . mJc [ 15 ] = 37 ;
out . mJc [ 16 ] = 37 ; out . mJc [ 17 ] = 38 ; out . mJc [ 18 ] = 38 ; out .
mJc [ 19 ] = 38 ; out . mJc [ 20 ] = 39 ; out . mJc [ 21 ] = 43 ; out . mJc [
22 ] = 44 ; out . mJc [ 23 ] = 45 ; out . mJc [ 24 ] = 47 ; out . mJc [ 25 ]
= 51 ; out . mJc [ 26 ] = 52 ; out . mIr [ 0 ] = 0 ; out . mIr [ 1 ] = 1 ;
out . mIr [ 2 ] = 0 ; out . mIr [ 3 ] = 1 ; out . mIr [ 4 ] = 2 ; out . mIr [
5 ] = 3 ; out . mIr [ 6 ] = 2 ; out . mIr [ 7 ] = 3 ; out . mIr [ 8 ] = 4 ;
out . mIr [ 9 ] = 5 ; out . mIr [ 10 ] = 6 ; out . mIr [ 11 ] = 17 ; out .
mIr [ 12 ] = 4 ; out . mIr [ 13 ] = 5 ; out . mIr [ 14 ] = 6 ; out . mIr [ 15
] = 17 ; out . mIr [ 16 ] = 4 ; out . mIr [ 17 ] = 5 ; out . mIr [ 18 ] = 6 ;
out . mIr [ 19 ] = 17 ; out . mIr [ 20 ] = 9 ; out . mIr [ 21 ] = 10 ; out .
mIr [ 22 ] = 11 ; out . mIr [ 23 ] = 21 ; out . mIr [ 24 ] = 22 ; out . mIr [
25 ] = 9 ; out . mIr [ 26 ] = 10 ; out . mIr [ 27 ] = 11 ; out . mIr [ 28 ] =
21 ; out . mIr [ 29 ] = 22 ; out . mIr [ 30 ] = 9 ; out . mIr [ 31 ] = 10 ;
out . mIr [ 32 ] = 11 ; out . mIr [ 33 ] = 21 ; out . mIr [ 34 ] = 22 ; out .
mIr [ 35 ] = 21 ; out . mIr [ 36 ] = 1 ; out . mIr [ 37 ] = 3 ; out . mIr [
38 ] = 17 ; out . mIr [ 39 ] = 4 ; out . mIr [ 40 ] = 5 ; out . mIr [ 41 ] =
6 ; out . mIr [ 42 ] = 17 ; out . mIr [ 43 ] = 7 ; out . mIr [ 44 ] = 22 ;
out . mIr [ 45 ] = 8 ; out . mIr [ 46 ] = 22 ; out . mIr [ 47 ] = 9 ; out .
mIr [ 48 ] = 10 ; out . mIr [ 49 ] = 11 ; out . mIr [ 50 ] = 22 ; out . mIr [
51 ] = 12 ; ( void ) LC ; ( void ) t2 ; return 0 ; }

#include "ne_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_sys_struct.h"
#include "IGBTThermal_399ad5b0_1_ds_zc.h"
#include "IGBTThermal_399ad5b0_1_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_externals.h"
#include "IGBTThermal_399ad5b0_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T IGBTThermal_399ad5b0_1_ds_zc ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t9 , NeDsMethodOutput * t10 ) { PmRealVector out ;
real_T U_idx_0 ; real_T X_idx_10 ; real_T X_idx_12 ; real_T X_idx_15 ; real_T
X_idx_18 ; real_T X_idx_4 ; real_T X_idx_5 ; real_T X_idx_6 ; real_T X_idx_8
; real_T X_idx_9 ; real_T t7 ; int32_T Q_idx_0 ; int32_T Q_idx_1 ; ( void )
LC ; Q_idx_0 = t9 -> mQ . mX [ 0 ] ; Q_idx_1 = t9 -> mQ . mX [ 1 ] ; U_idx_0
= t9 -> mU . mX [ 0 ] ; X_idx_4 = t9 -> mX . mX [ 4 ] ; X_idx_5 = t9 -> mX .
mX [ 5 ] ; X_idx_6 = t9 -> mX . mX [ 6 ] ; X_idx_8 = t9 -> mX . mX [ 8 ] ;
X_idx_9 = t9 -> mX . mX [ 9 ] ; X_idx_10 = t9 -> mX . mX [ 10 ] ; X_idx_12 =
t9 -> mX . mX [ 12 ] ; X_idx_15 = t9 -> mX . mX [ 15 ] ; X_idx_18 = t9 -> mX
. mX [ 18 ] ; out = t10 -> mZC ; t7 = X_idx_4 > X_idx_5 ? X_idx_5 : X_idx_4 ;
X_idx_5 = t7 > X_idx_6 ? X_idx_6 : t7 ; t7 = X_idx_8 > X_idx_9 ? X_idx_9 :
X_idx_8 ; out . mX [ 0 ] = ( real_T ) ( X_idx_15 < 0.0 ) ; out . mX [ 1 ] = (
real_T ) ( X_idx_18 < 0.0 ) ; out . mX [ 2 ] = X_idx_4 ; out . mX [ 3 ] = 1.0
; out . mX [ 4 ] = 1.0 ; out . mX [ 5 ] = 1.0 ; out . mX [ 6 ] = 1.0 ; out .
mX [ 7 ] = 1.0 ; out . mX [ 8 ] = 1.0 ; out . mX [ 9 ] = ( real_T ) ( (
U_idx_0 < 6.0 ) && ( ( size_t ) Q_idx_0 == 4ULL ) ) ; out . mX [ 10 ] = (
real_T ) ( ( U_idx_0 < 6.0 ) && ( ( size_t ) Q_idx_0 == 5ULL ) ) ; out . mX [
11 ] = ( real_T ) ( ( U_idx_0 < 6.0 ) && ( ( size_t ) Q_idx_0 == 6ULL ) ) ;
out . mX [ 12 ] = ( real_T ) ( ( U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_0 ==
7ULL ) ) ; out . mX [ 13 ] = ( real_T ) ( ( U_idx_0 > 6.0 ) && ( ( size_t )
Q_idx_0 == 8ULL ) ) ; out . mX [ 14 ] = ( real_T ) ( ( U_idx_0 > 6.0 ) && ( (
size_t ) Q_idx_0 == 9ULL ) ) ; out . mX [ 15 ] = ( real_T ) ( ( U_idx_0 < 6.0
) && ( ( size_t ) Q_idx_0 == 1ULL ) ) ; out . mX [ 16 ] = ( real_T ) ( (
U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_0 == 1ULL ) ) ; out . mX [ 17 ] = (
real_T ) ( ( U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_0 == 2ULL ) ) ; out . mX [
18 ] = ( real_T ) ( ( U_idx_0 >= 6.0 ) && ( ( size_t ) Q_idx_0 == 4ULL ) ) ;
out . mX [ 19 ] = ( real_T ) ( ( U_idx_0 >= 6.0 ) && ( ( size_t ) Q_idx_0 ==
5ULL ) ) ; out . mX [ 20 ] = ( real_T ) ( ( U_idx_0 >= 6.0 ) && ( ( size_t )
Q_idx_0 == 6ULL ) ) ; out . mX [ 21 ] = ( real_T ) ( ( U_idx_0 < 6.0 ) && ( (
size_t ) Q_idx_0 == 3ULL ) ) ; out . mX [ 22 ] = ( real_T ) ( ( U_idx_0 <=
6.0 ) && ( ( size_t ) Q_idx_0 == 7ULL ) ) ; out . mX [ 23 ] = ( real_T ) ( (
U_idx_0 <= 6.0 ) && ( ( size_t ) Q_idx_0 == 8ULL ) ) ; out . mX [ 24 ] = (
real_T ) ( ( U_idx_0 <= 6.0 ) && ( ( size_t ) Q_idx_0 == 9ULL ) ) ; out . mX
[ 25 ] = X_idx_12 ; out . mX [ 26 ] = 1.0 ; out . mX [ 27 ] = 1.0 ; out . mX
[ 28 ] = 1.0 ; out . mX [ 29 ] = 1.0 ; out . mX [ 30 ] = 1.0 ; out . mX [ 31
] = 1.0 ; out . mX [ 32 ] = ( real_T ) ( ( U_idx_0 < 6.0 ) && ( ( size_t )
Q_idx_1 == 4ULL ) ) ; out . mX [ 33 ] = ( real_T ) ( ( U_idx_0 < 6.0 ) && ( (
size_t ) Q_idx_1 == 5ULL ) ) ; out . mX [ 34 ] = ( real_T ) ( ( U_idx_0 < 6.0
) && ( ( size_t ) Q_idx_1 == 6ULL ) ) ; out . mX [ 35 ] = ( real_T ) ( (
U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_1 == 7ULL ) ) ; out . mX [ 36 ] = (
real_T ) ( ( U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_1 == 8ULL ) ) ; out . mX [
37 ] = ( real_T ) ( ( U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_1 == 9ULL ) ) ;
out . mX [ 38 ] = ( real_T ) ( ( U_idx_0 < 6.0 ) && ( ( size_t ) Q_idx_1 ==
1ULL ) ) ; out . mX [ 39 ] = ( real_T ) ( ( U_idx_0 > 6.0 ) && ( ( size_t )
Q_idx_1 == 1ULL ) ) ; out . mX [ 40 ] = ( real_T ) ( ( U_idx_0 > 6.0 ) && ( (
size_t ) Q_idx_1 == 2ULL ) ) ; out . mX [ 41 ] = ( real_T ) ( ( U_idx_0 >=
6.0 ) && ( ( size_t ) Q_idx_1 == 4ULL ) ) ; out . mX [ 42 ] = ( real_T ) ( (
U_idx_0 >= 6.0 ) && ( ( size_t ) Q_idx_1 == 5ULL ) ) ; out . mX [ 43 ] = (
real_T ) ( ( U_idx_0 >= 6.0 ) && ( ( size_t ) Q_idx_1 == 6ULL ) ) ; out . mX
[ 44 ] = ( real_T ) ( ( U_idx_0 < 6.0 ) && ( ( size_t ) Q_idx_1 == 3ULL ) ) ;
out . mX [ 45 ] = ( real_T ) ( ( U_idx_0 <= 6.0 ) && ( ( size_t ) Q_idx_1 ==
7ULL ) ) ; out . mX [ 46 ] = ( real_T ) ( ( U_idx_0 <= 6.0 ) && ( ( size_t )
Q_idx_1 == 8ULL ) ) ; out . mX [ 47 ] = ( real_T ) ( ( U_idx_0 <= 6.0 ) && (
( size_t ) Q_idx_1 == 9ULL ) ) ; out . mX [ 48 ] = X_idx_5 ; out . mX [ 49 ]
= t7 > X_idx_10 ? X_idx_10 : t7 ; ( void ) LC ; ( void ) t10 ; return 0 ; }

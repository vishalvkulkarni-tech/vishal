#include "ne_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_sys_struct.h"
#include "IGBTThermal_399ad5b0_1_ds_mode.h"
#include "IGBTThermal_399ad5b0_1_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_externals.h"
#include "IGBTThermal_399ad5b0_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T IGBTThermal_399ad5b0_1_ds_mode ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmIntVector out ;
real_T U_idx_0 ; real_T X_idx_10 ; real_T X_idx_12 ; real_T X_idx_15 ; real_T
X_idx_18 ; real_T X_idx_4 ; real_T X_idx_5 ; real_T X_idx_6 ; real_T X_idx_8
; real_T X_idx_9 ; int32_T Q_idx_0 ; int32_T Q_idx_1 ; ( void ) LC ; Q_idx_0
= t1 -> mQ . mX [ 0 ] ; Q_idx_1 = t1 -> mQ . mX [ 1 ] ; U_idx_0 = t1 -> mU .
mX [ 0 ] ; X_idx_4 = t1 -> mX . mX [ 4 ] ; X_idx_5 = t1 -> mX . mX [ 5 ] ;
X_idx_6 = t1 -> mX . mX [ 6 ] ; X_idx_8 = t1 -> mX . mX [ 8 ] ; X_idx_9 = t1
-> mX . mX [ 9 ] ; X_idx_10 = t1 -> mX . mX [ 10 ] ; X_idx_12 = t1 -> mX . mX
[ 12 ] ; X_idx_15 = t1 -> mX . mX [ 15 ] ; X_idx_18 = t1 -> mX . mX [ 18 ] ;
out = t2 -> mMODE ; out . mX [ 0 ] = ( int32_T ) ( ( U_idx_0 <= 6.0 ) && ( (
size_t ) Q_idx_0 == 9ULL ) ) ; out . mX [ 1 ] = ( int32_T ) ( ( U_idx_0 <=
6.0 ) && ( ( size_t ) Q_idx_0 == 8ULL ) ) ; out . mX [ 2 ] = ( int32_T ) ( (
U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_0 == 9ULL ) ) ; out . mX [ 3 ] = (
int32_T ) ( ( U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_0 == 8ULL ) ) ; out . mX
[ 4 ] = ( int32_T ) ( ( U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_0 == 7ULL ) ) ;
out . mX [ 5 ] = ( int32_T ) ( ( U_idx_0 < 6.0 ) && ( ( size_t ) Q_idx_0 ==
6ULL ) ) ; out . mX [ 6 ] = ( int32_T ) ( ( U_idx_0 < 6.0 ) && ( ( size_t )
Q_idx_0 == 5ULL ) ) ; out . mX [ 7 ] = ( int32_T ) ( ( U_idx_0 < 6.0 ) && ( (
size_t ) Q_idx_0 == 4ULL ) ) ; out . mX [ 8 ] = ( int32_T ) ( ( U_idx_0 <=
6.0 ) && ( ( size_t ) Q_idx_1 == 9ULL ) ) ; out . mX [ 9 ] = ( int32_T ) ( (
U_idx_0 <= 6.0 ) && ( ( size_t ) Q_idx_1 == 8ULL ) ) ; out . mX [ 10 ] = (
int32_T ) ( ( U_idx_0 <= 6.0 ) && ( ( size_t ) Q_idx_1 == 7ULL ) ) ; out . mX
[ 11 ] = ( int32_T ) ( ( U_idx_0 < 6.0 ) && ( ( size_t ) Q_idx_1 == 3ULL ) )
; out . mX [ 12 ] = ( int32_T ) ( ( U_idx_0 <= 6.0 ) && ( ( size_t ) Q_idx_0
== 7ULL ) ) ; out . mX [ 13 ] = ( int32_T ) ( ( U_idx_0 >= 6.0 ) && ( (
size_t ) Q_idx_1 == 6ULL ) ) ; out . mX [ 14 ] = ( int32_T ) ( ( U_idx_0 >=
6.0 ) && ( ( size_t ) Q_idx_1 == 5ULL ) ) ; out . mX [ 15 ] = ( int32_T ) ( (
U_idx_0 >= 6.0 ) && ( ( size_t ) Q_idx_1 == 4ULL ) ) ; out . mX [ 16 ] = (
int32_T ) ( ( U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_1 == 2ULL ) ) ; out . mX
[ 17 ] = ( int32_T ) ( ( U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_1 == 1ULL ) )
; out . mX [ 18 ] = ( int32_T ) ( ( U_idx_0 < 6.0 ) && ( ( size_t ) Q_idx_1
== 1ULL ) ) ; out . mX [ 19 ] = ( int32_T ) ( ( U_idx_0 > 6.0 ) && ( ( size_t
) Q_idx_1 == 9ULL ) ) ; out . mX [ 20 ] = ( int32_T ) ( ( U_idx_0 > 6.0 ) &&
( ( size_t ) Q_idx_1 == 8ULL ) ) ; out . mX [ 21 ] = ( int32_T ) ( ( U_idx_0
> 6.0 ) && ( ( size_t ) Q_idx_1 == 7ULL ) ) ; out . mX [ 22 ] = ( int32_T ) (
( U_idx_0 < 6.0 ) && ( ( size_t ) Q_idx_1 == 6ULL ) ) ; out . mX [ 23 ] = (
int32_T ) ( ( U_idx_0 < 6.0 ) && ( ( size_t ) Q_idx_0 == 3ULL ) ) ; out . mX
[ 24 ] = ( int32_T ) ( ( U_idx_0 < 6.0 ) && ( ( size_t ) Q_idx_1 == 5ULL ) )
; out . mX [ 25 ] = ( int32_T ) ( ( U_idx_0 < 6.0 ) && ( ( size_t ) Q_idx_1
== 4ULL ) ) ; out . mX [ 26 ] = ( int32_T ) ( ( U_idx_0 >= 6.0 ) && ( (
size_t ) Q_idx_0 == 6ULL ) ) ; out . mX [ 27 ] = ( int32_T ) ( ( U_idx_0 >=
6.0 ) && ( ( size_t ) Q_idx_0 == 5ULL ) ) ; out . mX [ 28 ] = ( int32_T ) ( (
U_idx_0 >= 6.0 ) && ( ( size_t ) Q_idx_0 == 4ULL ) ) ; out . mX [ 29 ] = (
int32_T ) ( ( U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_0 == 2ULL ) ) ; out . mX
[ 30 ] = ( int32_T ) ( ( U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_0 == 1ULL ) )
; out . mX [ 31 ] = ( int32_T ) ( ( U_idx_0 < 6.0 ) && ( ( size_t ) Q_idx_0
== 1ULL ) ) ; out . mX [ 32 ] = ( int32_T ) ( X_idx_15 < 0.0 ) ; out . mX [
33 ] = ( int32_T ) ( X_idx_18 < 0.0 ) ; out . mX [ 34 ] = 1 ; out . mX [ 35 ]
= 1 ; out . mX [ 36 ] = 1 ; out . mX [ 37 ] = 1 ; out . mX [ 38 ] = 1 ; out .
mX [ 39 ] = 1 ; out . mX [ 40 ] = 1 ; out . mX [ 41 ] = 1 ; out . mX [ 42 ] =
1 ; out . mX [ 43 ] = 1 ; out . mX [ 44 ] = 1 ; out . mX [ 45 ] = 1 ; out .
mX [ 46 ] = 1 ; out . mX [ 47 ] = 1 ; out . mX [ 48 ] = 1 ; out . mX [ 49 ] =
1 ; out . mX [ 50 ] = 1 ; out . mX [ 51 ] = 1 ; out . mX [ 52 ] = 1 ; out .
mX [ 53 ] = 1 ; out . mX [ 54 ] = ( int32_T ) ( ( X_idx_4 >= 0.0 ) && (
X_idx_5 >= 0.0 ) && ( X_idx_6 >= 0.0 ) ) ; out . mX [ 55 ] = ( int32_T ) (
X_idx_4 > 0.0 ) ; out . mX [ 56 ] = ( int32_T ) ( ( X_idx_8 >= 0.0 ) && (
X_idx_9 >= 0.0 ) && ( X_idx_10 >= 0.0 ) ) ; out . mX [ 57 ] = ( int32_T ) (
X_idx_12 > 0.0 ) ; ( void ) LC ; ( void ) t2 ; return 0 ; }

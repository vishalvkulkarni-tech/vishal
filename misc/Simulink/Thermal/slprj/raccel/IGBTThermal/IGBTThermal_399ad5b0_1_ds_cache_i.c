#include "ne_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_sys_struct.h"
#include "IGBTThermal_399ad5b0_1_ds_cache_i.h"
#include "IGBTThermal_399ad5b0_1_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_externals.h"
#include "IGBTThermal_399ad5b0_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T IGBTThermal_399ad5b0_1_ds_cache_i ( const NeDynamicSystem * LC ,
const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmIntVector out ;
real_T U_idx_0 ; int32_T M_idx_0 ; int32_T M_idx_1 ; int32_T M_idx_10 ;
int32_T M_idx_11 ; int32_T M_idx_12 ; int32_T M_idx_13 ; int32_T M_idx_14 ;
int32_T M_idx_15 ; int32_T M_idx_16 ; int32_T M_idx_17 ; int32_T M_idx_18 ;
int32_T M_idx_19 ; int32_T M_idx_2 ; int32_T M_idx_20 ; int32_T M_idx_21 ;
int32_T M_idx_22 ; int32_T M_idx_23 ; int32_T M_idx_24 ; int32_T M_idx_25 ;
int32_T M_idx_26 ; int32_T M_idx_27 ; int32_T M_idx_28 ; int32_T M_idx_29 ;
int32_T M_idx_3 ; int32_T M_idx_30 ; int32_T M_idx_31 ; int32_T M_idx_4 ;
int32_T M_idx_5 ; int32_T M_idx_6 ; int32_T M_idx_7 ; int32_T M_idx_8 ;
int32_T M_idx_9 ; int32_T Q_idx_0 ; int32_T Q_idx_1 ; ( void ) LC ; Q_idx_0 =
t1 -> mQ . mX [ 0 ] ; Q_idx_1 = t1 -> mQ . mX [ 1 ] ; M_idx_0 = t1 -> mM . mX
[ 0 ] ; M_idx_1 = t1 -> mM . mX [ 1 ] ; M_idx_2 = t1 -> mM . mX [ 2 ] ;
M_idx_3 = t1 -> mM . mX [ 3 ] ; M_idx_4 = t1 -> mM . mX [ 4 ] ; M_idx_5 = t1
-> mM . mX [ 5 ] ; M_idx_6 = t1 -> mM . mX [ 6 ] ; M_idx_7 = t1 -> mM . mX [
7 ] ; M_idx_8 = t1 -> mM . mX [ 8 ] ; M_idx_9 = t1 -> mM . mX [ 9 ] ;
M_idx_10 = t1 -> mM . mX [ 10 ] ; M_idx_11 = t1 -> mM . mX [ 11 ] ; M_idx_12
= t1 -> mM . mX [ 12 ] ; M_idx_13 = t1 -> mM . mX [ 13 ] ; M_idx_14 = t1 ->
mM . mX [ 14 ] ; M_idx_15 = t1 -> mM . mX [ 15 ] ; M_idx_16 = t1 -> mM . mX [
16 ] ; M_idx_17 = t1 -> mM . mX [ 17 ] ; M_idx_18 = t1 -> mM . mX [ 18 ] ;
M_idx_19 = t1 -> mM . mX [ 19 ] ; M_idx_20 = t1 -> mM . mX [ 20 ] ; M_idx_21
= t1 -> mM . mX [ 21 ] ; M_idx_22 = t1 -> mM . mX [ 22 ] ; M_idx_23 = t1 ->
mM . mX [ 23 ] ; M_idx_24 = t1 -> mM . mX [ 24 ] ; M_idx_25 = t1 -> mM . mX [
25 ] ; M_idx_26 = t1 -> mM . mX [ 26 ] ; M_idx_27 = t1 -> mM . mX [ 27 ] ;
M_idx_28 = t1 -> mM . mX [ 28 ] ; M_idx_29 = t1 -> mM . mX [ 29 ] ; M_idx_30
= t1 -> mM . mX [ 30 ] ; M_idx_31 = t1 -> mM . mX [ 31 ] ; U_idx_0 = t1 -> mU
. mX [ 0 ] ; out = t2 -> mCACHE_I ; out . mX [ 0 ] = ( int32_T ) ( M_idx_0 !=
0 ) ; out . mX [ 1 ] = ( int32_T ) ( M_idx_1 != 0 ) ; out . mX [ 2 ] = (
int32_T ) ( M_idx_2 != 0 ) ; out . mX [ 3 ] = ( int32_T ) ( M_idx_3 != 0 ) ;
out . mX [ 4 ] = ( int32_T ) ( M_idx_4 != 0 ) ; out . mX [ 5 ] = ( int32_T )
( M_idx_5 != 0 ) ; out . mX [ 6 ] = ( int32_T ) ( M_idx_6 != 0 ) ; out . mX [
7 ] = ( int32_T ) ( M_idx_7 != 0 ) ; out . mX [ 8 ] = ( int32_T ) ( M_idx_8
!= 0 ) ; out . mX [ 9 ] = ( int32_T ) ( M_idx_9 != 0 ) ; out . mX [ 10 ] = (
int32_T ) ( M_idx_10 != 0 ) ; out . mX [ 11 ] = ( int32_T ) ( M_idx_11 != 0 )
; out . mX [ 12 ] = ( int32_T ) ( M_idx_12 != 0 ) ; out . mX [ 13 ] = (
int32_T ) ( M_idx_13 != 0 ) ; out . mX [ 14 ] = ( int32_T ) ( M_idx_14 != 0 )
; out . mX [ 15 ] = ( int32_T ) ( M_idx_15 != 0 ) ; out . mX [ 16 ] = (
int32_T ) ( M_idx_16 != 0 ) ; out . mX [ 17 ] = ( int32_T ) ( M_idx_17 != 0 )
; out . mX [ 18 ] = ( int32_T ) ( M_idx_18 != 0 ) ; out . mX [ 19 ] = (
int32_T ) ( M_idx_19 != 0 ) ; out . mX [ 20 ] = ( int32_T ) ( M_idx_20 != 0 )
; out . mX [ 21 ] = ( int32_T ) ( M_idx_21 != 0 ) ; out . mX [ 22 ] = (
int32_T ) ( M_idx_22 != 0 ) ; out . mX [ 23 ] = ( int32_T ) ( M_idx_23 != 0 )
; out . mX [ 24 ] = ( int32_T ) ( M_idx_24 != 0 ) ; out . mX [ 25 ] = (
int32_T ) ( M_idx_25 != 0 ) ; out . mX [ 26 ] = ( int32_T ) ( ( U_idx_0 <=
6.0 ) && ( ( size_t ) Q_idx_0 == 9ULL ) ) ; out . mX [ 27 ] = ( int32_T ) ( (
U_idx_0 <= 6.0 ) && ( ( size_t ) Q_idx_0 == 8ULL ) ) ; out . mX [ 28 ] = (
int32_T ) ( ( U_idx_0 <= 6.0 ) && ( ( size_t ) Q_idx_0 == 7ULL ) ) ; out . mX
[ 29 ] = ( int32_T ) ( ( U_idx_0 < 6.0 ) && ( ( size_t ) Q_idx_0 == 3ULL ) )
; out . mX [ 30 ] = ( int32_T ) ( ( U_idx_0 >= 6.0 ) && ( ( size_t ) Q_idx_0
== 6ULL ) ) ; out . mX [ 31 ] = ( int32_T ) ( ( U_idx_0 >= 6.0 ) && ( (
size_t ) Q_idx_0 == 5ULL ) ) ; out . mX [ 32 ] = ( int32_T ) ( ( U_idx_0 >=
6.0 ) && ( ( size_t ) Q_idx_0 == 4ULL ) ) ; out . mX [ 33 ] = ( int32_T ) ( (
U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_0 == 2ULL ) ) ; out . mX [ 34 ] = (
int32_T ) ( M_idx_26 != 0 ) ; out . mX [ 35 ] = ( int32_T ) ( ( U_idx_0 > 6.0
) && ( ( size_t ) Q_idx_0 == 1ULL ) ) ; out . mX [ 36 ] = ( int32_T ) ( (
U_idx_0 < 6.0 ) && ( ( size_t ) Q_idx_0 == 1ULL ) ) ; out . mX [ 37 ] = (
int32_T ) ( ( U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_0 == 9ULL ) ) ; out . mX
[ 38 ] = ( int32_T ) ( ( U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_0 == 8ULL ) )
; out . mX [ 39 ] = ( int32_T ) ( ( U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_0
== 7ULL ) ) ; out . mX [ 40 ] = ( int32_T ) ( ( U_idx_0 < 6.0 ) && ( ( size_t
) Q_idx_0 == 6ULL ) ) ; out . mX [ 41 ] = ( int32_T ) ( ( U_idx_0 < 6.0 ) &&
( ( size_t ) Q_idx_0 == 5ULL ) ) ; out . mX [ 42 ] = ( int32_T ) ( ( U_idx_0
< 6.0 ) && ( ( size_t ) Q_idx_0 == 4ULL ) ) ; out . mX [ 43 ] = ( int32_T ) (
( U_idx_0 <= 6.0 ) && ( ( size_t ) Q_idx_1 == 9ULL ) ) ; out . mX [ 44 ] = (
int32_T ) ( ( U_idx_0 <= 6.0 ) && ( ( size_t ) Q_idx_1 == 8ULL ) ) ; out . mX
[ 45 ] = ( int32_T ) ( M_idx_27 != 0 ) ; out . mX [ 46 ] = ( int32_T ) ( (
U_idx_0 <= 6.0 ) && ( ( size_t ) Q_idx_1 == 7ULL ) ) ; out . mX [ 47 ] = (
int32_T ) ( ( U_idx_0 < 6.0 ) && ( ( size_t ) Q_idx_1 == 3ULL ) ) ; out . mX
[ 48 ] = ( int32_T ) ( ( U_idx_0 >= 6.0 ) && ( ( size_t ) Q_idx_1 == 6ULL ) )
; out . mX [ 49 ] = ( int32_T ) ( ( U_idx_0 >= 6.0 ) && ( ( size_t ) Q_idx_1
== 5ULL ) ) ; out . mX [ 50 ] = ( int32_T ) ( ( U_idx_0 >= 6.0 ) && ( (
size_t ) Q_idx_1 == 4ULL ) ) ; out . mX [ 51 ] = ( int32_T ) ( ( U_idx_0 >
6.0 ) && ( ( size_t ) Q_idx_1 == 2ULL ) ) ; out . mX [ 52 ] = ( int32_T ) ( (
U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_1 == 1ULL ) ) ; out . mX [ 53 ] = (
int32_T ) ( ( U_idx_0 < 6.0 ) && ( ( size_t ) Q_idx_1 == 1ULL ) ) ; out . mX
[ 54 ] = ( int32_T ) ( ( U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_1 == 9ULL ) )
; out . mX [ 55 ] = ( int32_T ) ( ( U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_1
== 8ULL ) ) ; out . mX [ 56 ] = ( int32_T ) ( M_idx_28 != 0 ) ; out . mX [ 57
] = ( int32_T ) ( ( U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_1 == 7ULL ) ) ; out
. mX [ 58 ] = ( int32_T ) ( ( U_idx_0 < 6.0 ) && ( ( size_t ) Q_idx_1 == 6ULL
) ) ; out . mX [ 59 ] = ( int32_T ) ( ( U_idx_0 < 6.0 ) && ( ( size_t )
Q_idx_1 == 5ULL ) ) ; out . mX [ 60 ] = ( int32_T ) ( ( U_idx_0 < 6.0 ) && (
( size_t ) Q_idx_1 == 4ULL ) ) ; out . mX [ 61 ] = ( int32_T ) ( M_idx_29 !=
0 ) ; out . mX [ 62 ] = ( int32_T ) ( M_idx_30 != 0 ) ; out . mX [ 63 ] = (
int32_T ) ( M_idx_31 != 0 ) ; ( void ) LC ; ( void ) t2 ; return 0 ; }

#include "ne_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_sys_struct.h"
#include "IGBTThermal_399ad5b0_1_ds_a.h"
#include "IGBTThermal_399ad5b0_1_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_externals.h"
#include "IGBTThermal_399ad5b0_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T IGBTThermal_399ad5b0_1_ds_a ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t69 , NeDsMethodOutput * t70 ) { PmRealVector out ;
real_T t1 [ 52 ] ; real_T t8 [ 15 ] ; real_T t6 [ 12 ] ; real_T t11 [ 4 ] ;
real_T t9 [ 4 ] ; size_t t29 ; ( void ) t69 ; ( void ) LC ; out = t70 -> mA ;
t6 [ 0ULL ] = - 0.0 ; t6 [ 4ULL ] = - 0.0 ; t6 [ 8ULL ] = - 0.0 ; t6 [ 1ULL ]
= - 0.0035971223021582731 ; t6 [ 5ULL ] = 0.022717581193171656 ; t6 [ 9ULL ]
= - 0.019120458891013385 ; t6 [ 2ULL ] = - 0.0 ; t6 [ 6ULL ] = -
0.019120458891013385 ; t6 [ 10ULL ] = 0.070933930393604058 ; t6 [ 3ULL ] =
0.0035971223021582731 ; t6 [ 7ULL ] = - 0.0035971223021582731 ; t6 [ 11ULL ]
= 0.0 ; t8 [ 0ULL ] = - 0.0 ; t8 [ 5ULL ] = - 0.0 ; t8 [ 10ULL ] = - 0.0 ; t8
[ 1ULL ] = - 0.0035916824196597346 ; t8 [ 6ULL ] = 0.022723626864104181 ; t8
[ 11ULL ] = - 0.019131944444444448 ; t8 [ 2ULL ] = - 0.0 ; t8 [ 7ULL ] = -
0.019131944444444448 ; t8 [ 12ULL ] = 0.070917658730158858 ; t8 [ 3ULL ] = -
1.0 ; t8 [ 8ULL ] = 0.0 ; t8 [ 13ULL ] = 0.0 ; t8 [ 4ULL ] =
0.0035916824196597346 ; t8 [ 9ULL ] = - 0.0035916824196597346 ; t8 [ 14ULL ]
= 0.0 ; t9 [ 0ULL ] = - 1.0 ; t9 [ 1ULL ] = - 0.0 ; t9 [ 2ULL ] = - 0.0 ; t9
[ 3ULL ] = 1.0 ; t11 [ 0ULL ] = - 1.0 ; t11 [ 1ULL ] = - 0.0 ; t11 [ 2ULL ] =
- 0.0 ; t11 [ 3ULL ] = 1.0 ; t1 [ 0ULL ] = 0.083333333333333329 ; t1 [ 1ULL ]
= - 1.0 ; t1 [ 2ULL ] = 1.0 ; t1 [ 3ULL ] = 0.0 ; t1 [ 4ULL ] =
0.083333333333333329 ; t1 [ 5ULL ] = - 1.0 ; t1 [ 6ULL ] = 1.0 ; t1 [ 7ULL ]
= 0.0 ; for ( t29 = 0ULL ; t29 < 12ULL ; t29 ++ ) { t1 [ t29 + 8ULL ] = t6 [
t29 ] ; } for ( t29 = 0ULL ; t29 < 15ULL ; t29 ++ ) { t1 [ t29 + 20ULL ] = t8
[ t29 ] ; } t1 [ 35ULL ] = 1.0 ; t1 [ 36ULL ] = - 1.0 ; t1 [ 37ULL ] = - 1.0
; t1 [ 38ULL ] = 1.0 ; for ( t29 = 0ULL ; t29 < 4ULL ; t29 ++ ) { t1 [ t29 +
39ULL ] = t9 [ t29 ] ; } t1 [ 43ULL ] = 1.0 ; t1 [ 44ULL ] = 1.0 ; t1 [ 45ULL
] = 1.0 ; t1 [ 46ULL ] = 1.0 ; for ( t29 = 0ULL ; t29 < 4ULL ; t29 ++ ) { t1
[ t29 + 47ULL ] = t11 [ t29 ] ; } out . mX [ 0 ] = t1 [ 0 ] ; out . mX [ 1 ]
= t1 [ 1 ] ; out . mX [ 2 ] = t1 [ 2 ] ; out . mX [ 3 ] = t1 [ 3 ] ; out . mX
[ 4 ] = t1 [ 4 ] ; out . mX [ 5 ] = t1 [ 5 ] ; out . mX [ 6 ] = t1 [ 6 ] ;
out . mX [ 7 ] = t1 [ 7 ] ; out . mX [ 8 ] = t1 [ 8 ] ; out . mX [ 9 ] = t1 [
9 ] ; out . mX [ 10 ] = t1 [ 10 ] ; out . mX [ 11 ] = t1 [ 11 ] ; out . mX [
12 ] = t1 [ 12 ] ; out . mX [ 13 ] = t1 [ 13 ] ; out . mX [ 14 ] = t1 [ 14 ]
; out . mX [ 15 ] = t1 [ 15 ] ; out . mX [ 16 ] = t1 [ 16 ] ; out . mX [ 17 ]
= t1 [ 17 ] ; out . mX [ 18 ] = t1 [ 18 ] ; out . mX [ 19 ] = t1 [ 19 ] ; out
. mX [ 20 ] = t1 [ 20 ] ; out . mX [ 21 ] = t1 [ 21 ] ; out . mX [ 22 ] = t1
[ 22 ] ; out . mX [ 23 ] = t1 [ 23 ] ; out . mX [ 24 ] = t1 [ 24 ] ; out . mX
[ 25 ] = t1 [ 25 ] ; out . mX [ 26 ] = t1 [ 26 ] ; out . mX [ 27 ] = t1 [ 27
] ; out . mX [ 28 ] = t1 [ 28 ] ; out . mX [ 29 ] = t1 [ 29 ] ; out . mX [ 30
] = t1 [ 30 ] ; out . mX [ 31 ] = t1 [ 31 ] ; out . mX [ 32 ] = t1 [ 32 ] ;
out . mX [ 33 ] = t1 [ 33 ] ; out . mX [ 34 ] = t1 [ 34 ] ; out . mX [ 35 ] =
t1 [ 35 ] ; out . mX [ 36 ] = t1 [ 36 ] ; out . mX [ 37 ] = t1 [ 37 ] ; out .
mX [ 38 ] = t1 [ 38 ] ; out . mX [ 39 ] = t1 [ 39 ] ; out . mX [ 40 ] = t1 [
40 ] ; out . mX [ 41 ] = t1 [ 41 ] ; out . mX [ 42 ] = t1 [ 42 ] ; out . mX [
43 ] = t1 [ 43 ] ; out . mX [ 44 ] = t1 [ 44 ] ; out . mX [ 45 ] = t1 [ 45 ]
; out . mX [ 46 ] = t1 [ 46 ] ; out . mX [ 47 ] = t1 [ 47 ] ; out . mX [ 48 ]
= t1 [ 48 ] ; out . mX [ 49 ] = t1 [ 49 ] ; out . mX [ 50 ] = t1 [ 50 ] ; out
. mX [ 51 ] = 1.0 ; ( void ) LC ; ( void ) t70 ; return 0 ; }

#include "ne_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_sys_struct.h"
#include "IGBTThermal_399ad5b0_1_ds_m.h"
#include "IGBTThermal_399ad5b0_1_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_externals.h"
#include "IGBTThermal_399ad5b0_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T IGBTThermal_399ad5b0_1_ds_m ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t13 , NeDsMethodOutput * t14 ) { PmRealVector out ;
real_T t2 [ 25 ] ; real_T t0 [ 9 ] ; real_T t1 [ 9 ] ; real_T nonscalar1 [ 3
] ; real_T nonscalar6 [ 3 ] ; size_t t4 ; size_t t6 ; ( void ) t13 ; ( void )
LC ; out = t14 -> mM ; t1 [ 0 ] = 0.001 ; t1 [ 1 ] = 0.0 ; t1 [ 2 ] = 0.0 ;
t1 [ 3 ] = 0.0 ; t1 [ 4 ] = 0.001 ; t1 [ 5 ] = 0.0 ; t1 [ 6 ] = 0.0 ; t1 [ 7
] = 0.0 ; t1 [ 8 ] = 0.001 ; t0 [ 0 ] = 1.0 ; t0 [ 1 ] = 1.0 ; t0 [ 2 ] = 1.0
; t0 [ 3 ] = 1.0 ; t0 [ 4 ] = 1.0 ; t0 [ 5 ] = 1.0 ; t0 [ 6 ] = 1.0 ; t0 [ 7
] = 1.0 ; t0 [ 8 ] = 1.0 ; nonscalar1 [ 0 ] = 0.0026115107913669061 ;
nonscalar1 [ 1 ] = 0.016347992351816443 ; nonscalar1 [ 2 ] =
0.12538860103626942 ; nonscalar6 [ 0 ] = 0.0026086956521739132 ; nonscalar6 [
1 ] = 0.0163496376811594 ; nonscalar6 [ 2 ] = 0.12514880952380994 ; t2 [ 0ULL
] = - 1.0E-6 ; t2 [ 1ULL ] = - 0.005 ; t2 [ 2ULL ] = - 1.0E-6 ; t2 [ 3ULL ] =
- 0.005 ; for ( t4 = 0ULL ; t4 < 9ULL ; t4 ++ ) { t6 = ( t4 - t4 / 3ULL *
3ULL ) % 3ULL ; t2 [ t4 + 4ULL ] = - ( t1 [ t4 ] * nonscalar1 [ t6 > 2ULL ?
2ULL : t6 ] ) / ( t0 [ t4 ] == 0.0 ? 1.0E-16 : t0 [ t4 ] ) ; } t2 [ 13ULL ] =
2.6115107913669059E-10 ; for ( t4 = 0ULL ; t4 < 9ULL ; t4 ++ ) { t6 = ( t4 -
t4 / 3ULL * 3ULL ) % 3ULL ; t2 [ t4 + 14ULL ] = - ( t1 [ t4 ] * nonscalar6 [
t6 > 2ULL ? 2ULL : t6 ] ) / ( t0 [ t4 ] == 0.0 ? 1.0E-16 : t0 [ t4 ] ) ; }
out . mX [ 0 ] = t2 [ 0 ] ; out . mX [ 1 ] = t2 [ 1 ] ; out . mX [ 2 ] = t2 [
2 ] ; out . mX [ 3 ] = t2 [ 3 ] ; out . mX [ 4 ] = t2 [ 4 ] ; out . mX [ 5 ]
= t2 [ 5 ] ; out . mX [ 6 ] = t2 [ 6 ] ; out . mX [ 7 ] = t2 [ 7 ] ; out . mX
[ 8 ] = t2 [ 8 ] ; out . mX [ 9 ] = t2 [ 9 ] ; out . mX [ 10 ] = t2 [ 10 ] ;
out . mX [ 11 ] = t2 [ 11 ] ; out . mX [ 12 ] = t2 [ 12 ] ; out . mX [ 13 ] =
t2 [ 13 ] ; out . mX [ 14 ] = t2 [ 14 ] ; out . mX [ 15 ] = t2 [ 15 ] ; out .
mX [ 16 ] = t2 [ 16 ] ; out . mX [ 17 ] = t2 [ 17 ] ; out . mX [ 18 ] = t2 [
18 ] ; out . mX [ 19 ] = t2 [ 19 ] ; out . mX [ 20 ] = t2 [ 20 ] ; out . mX [
21 ] = t2 [ 21 ] ; out . mX [ 22 ] = t2 [ 22 ] ; out . mX [ 23 ] = 6.25E-10 ;
out . mX [ 24 ] = 6.25E-10 ; ( void ) LC ; ( void ) t14 ; return 0 ; }

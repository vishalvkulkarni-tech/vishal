#include "ne_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_sys_struct.h"
#include "IGBTThermal_399ad5b0_1_ds_assert.h"
#include "IGBTThermal_399ad5b0_1_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_externals.h"
#include "IGBTThermal_399ad5b0_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T IGBTThermal_399ad5b0_1_ds_assert ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t3 , NeDsMethodOutput * t4 ) { PmIntVector out ;
int32_T t2 [ 126 ] ; int32_T M_idx_34 ; int32_T M_idx_35 ; int32_T M_idx_36 ;
int32_T M_idx_37 ; int32_T M_idx_38 ; int32_T M_idx_39 ; int32_T M_idx_40 ;
int32_T M_idx_41 ; int32_T M_idx_42 ; int32_T M_idx_43 ; int32_T M_idx_44 ;
int32_T M_idx_45 ; int32_T M_idx_46 ; int32_T M_idx_47 ; int32_T M_idx_48 ;
int32_T M_idx_49 ; int32_T M_idx_50 ; int32_T M_idx_51 ; int32_T M_idx_52 ;
int32_T M_idx_53 ; int32_T M_idx_54 ; int32_T M_idx_55 ; int32_T M_idx_56 ;
int32_T M_idx_57 ; int32_T Q_idx_0 ; int32_T Q_idx_1 ; boolean_T t0 ;
boolean_T t1 ; ( void ) LC ; Q_idx_0 = t3 -> mQ . mX [ 0 ] ; Q_idx_1 = t3 ->
mQ . mX [ 1 ] ; M_idx_34 = t3 -> mM . mX [ 34 ] ; M_idx_35 = t3 -> mM . mX [
35 ] ; M_idx_36 = t3 -> mM . mX [ 36 ] ; M_idx_37 = t3 -> mM . mX [ 37 ] ;
M_idx_38 = t3 -> mM . mX [ 38 ] ; M_idx_39 = t3 -> mM . mX [ 39 ] ; M_idx_40
= t3 -> mM . mX [ 40 ] ; M_idx_41 = t3 -> mM . mX [ 41 ] ; M_idx_42 = t3 ->
mM . mX [ 42 ] ; M_idx_43 = t3 -> mM . mX [ 43 ] ; M_idx_44 = t3 -> mM . mX [
44 ] ; M_idx_45 = t3 -> mM . mX [ 45 ] ; M_idx_46 = t3 -> mM . mX [ 46 ] ;
M_idx_47 = t3 -> mM . mX [ 47 ] ; M_idx_48 = t3 -> mM . mX [ 48 ] ; M_idx_49
= t3 -> mM . mX [ 49 ] ; M_idx_50 = t3 -> mM . mX [ 50 ] ; M_idx_51 = t3 ->
mM . mX [ 51 ] ; M_idx_52 = t3 -> mM . mX [ 52 ] ; M_idx_53 = t3 -> mM . mX [
53 ] ; M_idx_54 = t3 -> mM . mX [ 54 ] ; M_idx_55 = t3 -> mM . mX [ 55 ] ;
M_idx_56 = t3 -> mM . mX [ 56 ] ; M_idx_57 = t3 -> mM . mX [ 57 ] ; out = t4
-> mASSERT ; if ( ( size_t ) Q_idx_0 >= 1ULL ) { t0 = ( ( size_t ) Q_idx_0 <=
9ULL ) ; } else { t0 = false ; } if ( ( size_t ) Q_idx_1 >= 1ULL ) { t1 = ( (
size_t ) Q_idx_1 <= 9ULL ) ; } else { t1 = false ; } t2 [ 0ULL ] = ( int32_T
) ( M_idx_34 != 0 ) ; t2 [ 1ULL ] = ( int32_T ) ( M_idx_35 != 0 ) ; t2 [ 2ULL
] = ( int32_T ) ( M_idx_34 != 0 ) ; t2 [ 3ULL ] = ( int32_T ) ( M_idx_35 != 0
) ; t2 [ 4ULL ] = ( int32_T ) ( M_idx_36 != 0 ) ; t2 [ 5ULL ] = ( int32_T ) (
M_idx_37 != 0 ) ; t2 [ 6ULL ] = ( int32_T ) ( M_idx_38 != 0 ) ; t2 [ 7ULL ] =
( int32_T ) ( M_idx_39 != 0 ) ; t2 [ 8ULL ] = ( int32_T ) ( M_idx_40 != 0 ) ;
t2 [ 9ULL ] = ( int32_T ) ( M_idx_39 != 0 ) ; t2 [ 10ULL ] = ( int32_T ) (
M_idx_40 != 0 ) ; t2 [ 11ULL ] = ( int32_T ) ( M_idx_41 != 0 ) ; t2 [ 12ULL ]
= ( int32_T ) ( M_idx_42 != 0 ) ; t2 [ 13ULL ] = ( int32_T ) ( M_idx_43 != 0
) ; t2 [ 14ULL ] = ( int32_T ) ( M_idx_44 != 0 ) ; t2 [ 15ULL ] = ( int32_T )
( M_idx_45 != 0 ) ; t2 [ 16ULL ] = ( int32_T ) ( M_idx_44 != 0 ) ; t2 [ 17ULL
] = ( int32_T ) ( M_idx_45 != 0 ) ; t2 [ 18ULL ] = ( int32_T ) ( M_idx_46 !=
0 ) ; t2 [ 19ULL ] = ( int32_T ) ( M_idx_47 != 0 ) ; t2 [ 20ULL ] = ( int32_T
) ( M_idx_48 != 0 ) ; t2 [ 21ULL ] = ( int32_T ) ( M_idx_49 != 0 ) ; t2 [
22ULL ] = ( int32_T ) ( M_idx_50 != 0 ) ; t2 [ 23ULL ] = ( int32_T ) (
M_idx_49 != 0 ) ; t2 [ 24ULL ] = ( int32_T ) ( M_idx_50 != 0 ) ; t2 [ 25ULL ]
= ( int32_T ) ( M_idx_51 != 0 ) ; t2 [ 26ULL ] = ( int32_T ) ( M_idx_52 != 0
) ; t2 [ 27ULL ] = ( int32_T ) ( M_idx_53 != 0 ) ; t2 [ 28ULL ] = ( int32_T )
( M_idx_54 != 0 ) ; t2 [ 29ULL ] = ( int32_T ) ( M_idx_55 != 0 ) ; t2 [ 30ULL
] = ( int32_T ) t0 ; t2 [ 31ULL ] = 1 ; t2 [ 32ULL ] = 1 ; t2 [ 33ULL ] = 1 ;
t2 [ 34ULL ] = 1 ; t2 [ 35ULL ] = 1 ; t2 [ 36ULL ] = 1 ; t2 [ 37ULL ] = 1 ;
t2 [ 38ULL ] = 1 ; t2 [ 39ULL ] = 1 ; t2 [ 40ULL ] = 1 ; t2 [ 41ULL ] = 1 ;
t2 [ 42ULL ] = 1 ; t2 [ 43ULL ] = 1 ; t2 [ 44ULL ] = 1 ; t2 [ 45ULL ] = 1 ;
t2 [ 46ULL ] = 1 ; t2 [ 47ULL ] = 1 ; t2 [ 48ULL ] = 1 ; t2 [ 49ULL ] = 1 ;
t2 [ 50ULL ] = 1 ; t2 [ 51ULL ] = 1 ; t2 [ 52ULL ] = 1 ; t2 [ 53ULL ] = 1 ;
t2 [ 54ULL ] = 1 ; t2 [ 55ULL ] = 1 ; t2 [ 56ULL ] = 1 ; t2 [ 57ULL ] = 1 ;
t2 [ 58ULL ] = 1 ; t2 [ 59ULL ] = ( int32_T ) ( M_idx_56 != 0 ) ; t2 [ 60ULL
] = ( int32_T ) ( M_idx_57 != 0 ) ; t2 [ 61ULL ] = ( int32_T ) t1 ; t2 [
62ULL ] = 1 ; t2 [ 63ULL ] = 1 ; t2 [ 64ULL ] = 1 ; t2 [ 65ULL ] = 1 ; t2 [
66ULL ] = 1 ; t2 [ 67ULL ] = 1 ; t2 [ 68ULL ] = 1 ; t2 [ 69ULL ] = 1 ; t2 [
70ULL ] = 1 ; t2 [ 71ULL ] = 1 ; t2 [ 72ULL ] = 1 ; t2 [ 73ULL ] = 1 ; t2 [
74ULL ] = 1 ; t2 [ 75ULL ] = 1 ; t2 [ 76ULL ] = 1 ; t2 [ 77ULL ] = 1 ; t2 [
78ULL ] = 1 ; t2 [ 79ULL ] = 1 ; t2 [ 80ULL ] = 1 ; t2 [ 81ULL ] = 1 ; t2 [
82ULL ] = 1 ; t2 [ 83ULL ] = 1 ; t2 [ 84ULL ] = 1 ; t2 [ 85ULL ] = 1 ; t2 [
86ULL ] = 1 ; t2 [ 87ULL ] = 1 ; t2 [ 88ULL ] = 1 ; t2 [ 89ULL ] = 1 ; t2 [
90ULL ] = 1 ; t2 [ 91ULL ] = 1 ; t2 [ 92ULL ] = 1 ; t2 [ 93ULL ] = 1 ; t2 [
94ULL ] = 1 ; t2 [ 95ULL ] = 1 ; t2 [ 96ULL ] = 1 ; t2 [ 97ULL ] = 1 ; t2 [
98ULL ] = 1 ; t2 [ 99ULL ] = 1 ; t2 [ 100ULL ] = 1 ; t2 [ 101ULL ] = 1 ; t2 [
102ULL ] = 1 ; t2 [ 103ULL ] = 1 ; t2 [ 104ULL ] = 1 ; t2 [ 105ULL ] = 1 ; t2
[ 106ULL ] = 1 ; t2 [ 107ULL ] = 1 ; t2 [ 108ULL ] = 1 ; t2 [ 109ULL ] = 1 ;
t2 [ 110ULL ] = 1 ; t2 [ 111ULL ] = 1 ; t2 [ 112ULL ] = 1 ; t2 [ 113ULL ] = 1
; t2 [ 114ULL ] = 1 ; t2 [ 115ULL ] = 1 ; t2 [ 116ULL ] = 1 ; t2 [ 117ULL ] =
1 ; t2 [ 118ULL ] = 1 ; t2 [ 119ULL ] = 1 ; t2 [ 120ULL ] = 1 ; t2 [ 121ULL ]
= 1 ; t2 [ 122ULL ] = 1 ; t2 [ 123ULL ] = 1 ; t2 [ 124ULL ] = 1 ; t2 [ 125ULL
] = 1 ; for ( Q_idx_0 = 0 ; Q_idx_0 < 126 ; Q_idx_0 ++ ) { out . mX [ Q_idx_0
] = t2 [ Q_idx_0 ] ; } ( void ) LC ; ( void ) t4 ; return 0 ; }

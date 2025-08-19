#include "ne_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_sys_struct.h"
#include "IGBTThermal_399ad5b0_1_ds_update2_i.h"
#include "IGBTThermal_399ad5b0_1_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_externals.h"
#include "IGBTThermal_399ad5b0_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T IGBTThermal_399ad5b0_1_ds_update2_i ( const NeDynamicSystem * LC ,
const NeDynamicSystemInput * t3 , NeDsMethodOutput * t4 ) { PmIntVector out ;
real_T U_idx_0 ; size_t t0 ; size_t t1 ; int32_T CI_idx_26 ; int32_T
CI_idx_27 ; int32_T CI_idx_28 ; int32_T CI_idx_29 ; int32_T CI_idx_30 ;
int32_T CI_idx_31 ; int32_T CI_idx_32 ; int32_T CI_idx_33 ; int32_T CI_idx_35
; int32_T CI_idx_36 ; int32_T CI_idx_37 ; int32_T CI_idx_38 ; int32_T
CI_idx_39 ; int32_T CI_idx_40 ; int32_T CI_idx_41 ; int32_T CI_idx_42 ;
int32_T CI_idx_43 ; int32_T CI_idx_44 ; int32_T CI_idx_46 ; int32_T CI_idx_47
; int32_T CI_idx_48 ; int32_T CI_idx_49 ; int32_T CI_idx_50 ; int32_T
CI_idx_51 ; int32_T CI_idx_52 ; int32_T CI_idx_53 ; int32_T CI_idx_54 ;
int32_T CI_idx_55 ; int32_T CI_idx_57 ; int32_T CI_idx_58 ; int32_T CI_idx_59
; int32_T CI_idx_60 ; int32_T Q_idx_0 ; int32_T Q_idx_1 ; int32_T Q_idx_2 ; (
void ) LC ; Q_idx_0 = t3 -> mQ . mX [ 0 ] ; Q_idx_1 = t3 -> mQ . mX [ 1 ] ;
Q_idx_2 = t3 -> mQ . mX [ 2 ] ; U_idx_0 = t3 -> mU . mX [ 0 ] ; CI_idx_26 =
t3 -> mCI . mX [ 26 ] ; CI_idx_27 = t3 -> mCI . mX [ 27 ] ; CI_idx_28 = t3 ->
mCI . mX [ 28 ] ; CI_idx_29 = t3 -> mCI . mX [ 29 ] ; CI_idx_30 = t3 -> mCI .
mX [ 30 ] ; CI_idx_31 = t3 -> mCI . mX [ 31 ] ; CI_idx_32 = t3 -> mCI . mX [
32 ] ; CI_idx_33 = t3 -> mCI . mX [ 33 ] ; CI_idx_35 = t3 -> mCI . mX [ 35 ]
; CI_idx_36 = t3 -> mCI . mX [ 36 ] ; CI_idx_37 = t3 -> mCI . mX [ 37 ] ;
CI_idx_38 = t3 -> mCI . mX [ 38 ] ; CI_idx_39 = t3 -> mCI . mX [ 39 ] ;
CI_idx_40 = t3 -> mCI . mX [ 40 ] ; CI_idx_41 = t3 -> mCI . mX [ 41 ] ;
CI_idx_42 = t3 -> mCI . mX [ 42 ] ; CI_idx_43 = t3 -> mCI . mX [ 43 ] ;
CI_idx_44 = t3 -> mCI . mX [ 44 ] ; CI_idx_46 = t3 -> mCI . mX [ 46 ] ;
CI_idx_47 = t3 -> mCI . mX [ 47 ] ; CI_idx_48 = t3 -> mCI . mX [ 48 ] ;
CI_idx_49 = t3 -> mCI . mX [ 49 ] ; CI_idx_50 = t3 -> mCI . mX [ 50 ] ;
CI_idx_51 = t3 -> mCI . mX [ 51 ] ; CI_idx_52 = t3 -> mCI . mX [ 52 ] ;
CI_idx_53 = t3 -> mCI . mX [ 53 ] ; CI_idx_54 = t3 -> mCI . mX [ 54 ] ;
CI_idx_55 = t3 -> mCI . mX [ 55 ] ; CI_idx_57 = t3 -> mCI . mX [ 57 ] ;
CI_idx_58 = t3 -> mCI . mX [ 58 ] ; CI_idx_59 = t3 -> mCI . mX [ 59 ] ;
CI_idx_60 = t3 -> mCI . mX [ 60 ] ; out = t4 -> mUPDATE2_I ; if ( ( CI_idx_42
== 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_0 == 4ULL ) ) { t0 = 7ULL ;
} else if ( ( CI_idx_41 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_0
== 5ULL ) ) { t0 = 7ULL ; } else if ( ( CI_idx_40 == 0 ) && ( U_idx_0 < 0.0 )
&& ( ( size_t ) Q_idx_0 == 6ULL ) ) { t0 = 7ULL ; } else if ( ( CI_idx_39 ==
0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_0 == 7ULL ) ) { t0 = 4ULL ; }
else if ( ( CI_idx_38 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_0 ==
8ULL ) ) { t0 = 4ULL ; } else if ( ( CI_idx_37 == 0 ) && ( U_idx_0 > 0.0 ) &&
( ( size_t ) Q_idx_0 == 9ULL ) ) { t0 = 4ULL ; } else if ( ( CI_idx_36 == 0 )
&& ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_0 == 1ULL ) ) { t0 = 2ULL ; } else
if ( ( CI_idx_35 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_0 == 1ULL
) ) { t0 = 3ULL ; } else if ( ( CI_idx_33 == 0 ) && ( U_idx_0 > 0.0 ) && ( (
size_t ) Q_idx_0 == 2ULL ) ) { t0 = 4ULL ; } else if ( ( CI_idx_32 == 0 ) &&
( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_0 == 4ULL ) ) { t0 = 5ULL ; } else if
( ( CI_idx_31 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_0 == 5ULL ) )
{ t0 = 6ULL ; } else if ( ( CI_idx_30 == 0 ) && ( U_idx_0 > 0.0 ) && ( (
size_t ) Q_idx_0 == 6ULL ) ) { t0 = 3ULL ; } else if ( ( CI_idx_29 == 0 ) &&
( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_0 == 3ULL ) ) { t0 = 7ULL ; } else if
( ( CI_idx_28 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_0 == 7ULL ) )
{ t0 = 8ULL ; } else if ( ( CI_idx_27 == 0 ) && ( U_idx_0 < 0.0 ) && ( (
size_t ) Q_idx_0 == 8ULL ) ) { t0 = 9ULL ; } else if ( ( CI_idx_26 == 0 ) &&
( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_0 == 9ULL ) ) { t0 = 2ULL ; } else {
t0 = ( size_t ) Q_idx_0 ; } if ( ( CI_idx_60 == 0 ) && ( U_idx_0 < 0.0 ) && (
( size_t ) Q_idx_1 == 4ULL ) ) { t1 = 7ULL ; } else if ( ( CI_idx_59 == 0 )
&& ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_1 == 5ULL ) ) { t1 = 7ULL ; } else
if ( ( CI_idx_58 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_1 == 6ULL
) ) { t1 = 7ULL ; } else if ( ( CI_idx_57 == 0 ) && ( U_idx_0 > 0.0 ) && ( (
size_t ) Q_idx_1 == 7ULL ) ) { t1 = 4ULL ; } else if ( ( CI_idx_55 == 0 ) &&
( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 8ULL ) ) { t1 = 4ULL ; } else if
( ( CI_idx_54 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 9ULL ) )
{ t1 = 4ULL ; } else if ( ( CI_idx_53 == 0 ) && ( U_idx_0 < 0.0 ) && ( (
size_t ) Q_idx_1 == 1ULL ) ) { t1 = 2ULL ; } else if ( ( CI_idx_52 == 0 ) &&
( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 1ULL ) ) { t1 = 3ULL ; } else if
( ( CI_idx_51 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 2ULL ) )
{ t1 = 4ULL ; } else if ( ( CI_idx_50 == 0 ) && ( U_idx_0 > 0.0 ) && ( (
size_t ) Q_idx_1 == 4ULL ) ) { t1 = 5ULL ; } else if ( ( CI_idx_49 == 0 ) &&
( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 5ULL ) ) { t1 = 6ULL ; } else if
( ( CI_idx_48 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 6ULL ) )
{ t1 = 3ULL ; } else if ( ( CI_idx_47 == 0 ) && ( U_idx_0 < 0.0 ) && ( (
size_t ) Q_idx_1 == 3ULL ) ) { t1 = 7ULL ; } else if ( ( CI_idx_46 == 0 ) &&
( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_1 == 7ULL ) ) { t1 = 8ULL ; } else if
( ( CI_idx_44 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_1 == 8ULL ) )
{ t1 = 9ULL ; } else if ( ( CI_idx_43 == 0 ) && ( U_idx_0 < 0.0 ) && ( (
size_t ) Q_idx_1 == 9ULL ) ) { t1 = 2ULL ; } else { t1 = ( size_t ) Q_idx_1 ;
} out . mX [ 0 ] = ( int32_T ) t0 ; out . mX [ 1 ] = ( int32_T ) t1 ; out .
mX [ 2 ] = ( int32_T ) ( Q_idx_2 != 0 ) ; ( void ) LC ; ( void ) t4 ; return
0 ; }

#include "ne_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_sys_struct.h"
#include "IGBTThermal_399ad5b0_1_ds_update_i.h"
#include "IGBTThermal_399ad5b0_1_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_externals.h"
#include "IGBTThermal_399ad5b0_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T IGBTThermal_399ad5b0_1_ds_update_i ( const NeDynamicSystem * LC ,
const NeDynamicSystemInput * t3 , NeDsMethodOutput * t4 ) { PmIntVector out ;
real_T U_idx_0 ; size_t t0 ; size_t t1 ; int32_T CI_idx_0 ; int32_T CI_idx_1
; int32_T CI_idx_10 ; int32_T CI_idx_11 ; int32_T CI_idx_12 ; int32_T
CI_idx_13 ; int32_T CI_idx_14 ; int32_T CI_idx_15 ; int32_T CI_idx_16 ;
int32_T CI_idx_17 ; int32_T CI_idx_18 ; int32_T CI_idx_19 ; int32_T CI_idx_2
; int32_T CI_idx_20 ; int32_T CI_idx_21 ; int32_T CI_idx_22 ; int32_T
CI_idx_23 ; int32_T CI_idx_24 ; int32_T CI_idx_25 ; int32_T CI_idx_3 ;
int32_T CI_idx_34 ; int32_T CI_idx_4 ; int32_T CI_idx_45 ; int32_T CI_idx_5 ;
int32_T CI_idx_56 ; int32_T CI_idx_6 ; int32_T CI_idx_61 ; int32_T CI_idx_62
; int32_T CI_idx_63 ; int32_T CI_idx_7 ; int32_T CI_idx_8 ; int32_T CI_idx_9
; int32_T Q_idx_0 ; int32_T Q_idx_1 ; int32_T Q_idx_2 ; ( void ) LC ; Q_idx_0
= t3 -> mQ . mX [ 0 ] ; Q_idx_1 = t3 -> mQ . mX [ 1 ] ; Q_idx_2 = t3 -> mQ .
mX [ 2 ] ; U_idx_0 = t3 -> mU . mX [ 0 ] ; CI_idx_0 = t3 -> mCI . mX [ 0 ] ;
CI_idx_1 = t3 -> mCI . mX [ 1 ] ; CI_idx_2 = t3 -> mCI . mX [ 2 ] ; CI_idx_3
= t3 -> mCI . mX [ 3 ] ; CI_idx_4 = t3 -> mCI . mX [ 4 ] ; CI_idx_5 = t3 ->
mCI . mX [ 5 ] ; CI_idx_6 = t3 -> mCI . mX [ 6 ] ; CI_idx_7 = t3 -> mCI . mX
[ 7 ] ; CI_idx_8 = t3 -> mCI . mX [ 8 ] ; CI_idx_9 = t3 -> mCI . mX [ 9 ] ;
CI_idx_10 = t3 -> mCI . mX [ 10 ] ; CI_idx_11 = t3 -> mCI . mX [ 11 ] ;
CI_idx_12 = t3 -> mCI . mX [ 12 ] ; CI_idx_13 = t3 -> mCI . mX [ 13 ] ;
CI_idx_14 = t3 -> mCI . mX [ 14 ] ; CI_idx_15 = t3 -> mCI . mX [ 15 ] ;
CI_idx_16 = t3 -> mCI . mX [ 16 ] ; CI_idx_17 = t3 -> mCI . mX [ 17 ] ;
CI_idx_18 = t3 -> mCI . mX [ 18 ] ; CI_idx_19 = t3 -> mCI . mX [ 19 ] ;
CI_idx_20 = t3 -> mCI . mX [ 20 ] ; CI_idx_21 = t3 -> mCI . mX [ 21 ] ;
CI_idx_22 = t3 -> mCI . mX [ 22 ] ; CI_idx_23 = t3 -> mCI . mX [ 23 ] ;
CI_idx_24 = t3 -> mCI . mX [ 24 ] ; CI_idx_25 = t3 -> mCI . mX [ 25 ] ;
CI_idx_34 = t3 -> mCI . mX [ 34 ] ; CI_idx_45 = t3 -> mCI . mX [ 45 ] ;
CI_idx_56 = t3 -> mCI . mX [ 56 ] ; CI_idx_61 = t3 -> mCI . mX [ 61 ] ;
CI_idx_62 = t3 -> mCI . mX [ 62 ] ; CI_idx_63 = t3 -> mCI . mX [ 63 ] ; out =
t4 -> mUPDATE_I ; if ( ( ( CI_idx_7 == 0 ) && ( U_idx_0 < 6.0 ) && ( ( size_t
) Q_idx_0 == 4ULL ) ) || ( ( U_idx_0 < 6.0 ) && ( ( size_t ) Q_idx_0 == 4ULL
) && ( Q_idx_2 != 0 ) ) ) { t0 = 7ULL ; } else if ( ( ( CI_idx_6 == 0 ) && (
U_idx_0 < 6.0 ) && ( ( size_t ) Q_idx_0 == 5ULL ) ) || ( ( U_idx_0 < 6.0 ) &&
( ( size_t ) Q_idx_0 == 5ULL ) && ( Q_idx_2 != 0 ) ) ) { t0 = 7ULL ; } else
if ( ( ( CI_idx_5 == 0 ) && ( U_idx_0 < 6.0 ) && ( ( size_t ) Q_idx_0 == 6ULL
) ) || ( ( U_idx_0 < 6.0 ) && ( ( size_t ) Q_idx_0 == 6ULL ) && ( Q_idx_2 !=
0 ) ) ) { t0 = 7ULL ; } else if ( ( ( CI_idx_4 == 0 ) && ( U_idx_0 > 6.0 ) &&
( ( size_t ) Q_idx_0 == 7ULL ) ) || ( ( U_idx_0 > 6.0 ) && ( ( size_t )
Q_idx_0 == 7ULL ) && ( Q_idx_2 != 0 ) ) ) { t0 = 4ULL ; } else if ( ( (
CI_idx_3 == 0 ) && ( U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_0 == 8ULL ) ) || (
( U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_0 == 8ULL ) && ( Q_idx_2 != 0 ) ) ) {
t0 = 4ULL ; } else if ( ( ( CI_idx_2 == 0 ) && ( U_idx_0 > 6.0 ) && ( (
size_t ) Q_idx_0 == 9ULL ) ) || ( ( U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_0
== 9ULL ) && ( Q_idx_2 != 0 ) ) ) { t0 = 4ULL ; } else if ( ( ( CI_idx_63 ==
0 ) && ( U_idx_0 < 6.0 ) && ( ( size_t ) Q_idx_0 == 1ULL ) ) || ( ( U_idx_0 <
6.0 ) && ( ( size_t ) Q_idx_0 == 1ULL ) && ( Q_idx_2 != 0 ) ) ) { t0 = 2ULL ;
} else if ( ( ( CI_idx_62 == 0 ) && ( U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_0
== 1ULL ) ) || ( ( U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_0 == 1ULL ) && (
Q_idx_2 != 0 ) ) ) { t0 = 3ULL ; } else if ( ( ( CI_idx_61 == 0 ) && (
U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_0 == 2ULL ) ) || ( ( U_idx_0 > 6.0 ) &&
( ( size_t ) Q_idx_0 == 2ULL ) && ( Q_idx_2 != 0 ) ) ) { t0 = 4ULL ; } else
if ( ( ( CI_idx_56 == 0 ) && ( U_idx_0 >= 6.0 ) && ( ( size_t ) Q_idx_0 ==
4ULL ) ) || ( ( U_idx_0 >= 6.0 ) && ( ( size_t ) Q_idx_0 == 4ULL ) && (
Q_idx_2 != 0 ) ) ) { t0 = 5ULL ; } else if ( ( ( CI_idx_45 == 0 ) && (
U_idx_0 >= 6.0 ) && ( ( size_t ) Q_idx_0 == 5ULL ) ) || ( ( U_idx_0 >= 6.0 )
&& ( ( size_t ) Q_idx_0 == 5ULL ) && ( Q_idx_2 != 0 ) ) ) { t0 = 6ULL ; }
else if ( ( ( CI_idx_34 == 0 ) && ( U_idx_0 >= 6.0 ) && ( ( size_t ) Q_idx_0
== 6ULL ) ) || ( ( U_idx_0 >= 6.0 ) && ( ( size_t ) Q_idx_0 == 6ULL ) && (
Q_idx_2 != 0 ) ) ) { t0 = 3ULL ; } else if ( ( ( CI_idx_23 == 0 ) && (
U_idx_0 < 6.0 ) && ( ( size_t ) Q_idx_0 == 3ULL ) ) || ( ( U_idx_0 < 6.0 ) &&
( ( size_t ) Q_idx_0 == 3ULL ) && ( Q_idx_2 != 0 ) ) ) { t0 = 7ULL ; } else
if ( ( ( CI_idx_12 == 0 ) && ( U_idx_0 <= 6.0 ) && ( ( size_t ) Q_idx_0 ==
7ULL ) ) || ( ( U_idx_0 <= 6.0 ) && ( ( size_t ) Q_idx_0 == 7ULL ) && (
Q_idx_2 != 0 ) ) ) { t0 = 8ULL ; } else if ( ( ( CI_idx_1 == 0 ) && ( U_idx_0
<= 6.0 ) && ( ( size_t ) Q_idx_0 == 8ULL ) ) || ( ( U_idx_0 <= 6.0 ) && ( (
size_t ) Q_idx_0 == 8ULL ) && ( Q_idx_2 != 0 ) ) ) { t0 = 9ULL ; } else if (
( ( CI_idx_0 == 0 ) && ( U_idx_0 <= 6.0 ) && ( ( size_t ) Q_idx_0 == 9ULL ) )
|| ( ( U_idx_0 <= 6.0 ) && ( ( size_t ) Q_idx_0 == 9ULL ) && ( Q_idx_2 != 0 )
) ) { t0 = 2ULL ; } else { t0 = ( size_t ) Q_idx_0 ; } if ( ( ( CI_idx_25 ==
0 ) && ( U_idx_0 < 6.0 ) && ( ( size_t ) Q_idx_1 == 4ULL ) ) || ( ( U_idx_0 <
6.0 ) && ( ( size_t ) Q_idx_1 == 4ULL ) && ( Q_idx_2 != 0 ) ) ) { t1 = 7ULL ;
} else if ( ( ( CI_idx_24 == 0 ) && ( U_idx_0 < 6.0 ) && ( ( size_t ) Q_idx_1
== 5ULL ) ) || ( ( U_idx_0 < 6.0 ) && ( ( size_t ) Q_idx_1 == 5ULL ) && (
Q_idx_2 != 0 ) ) ) { t1 = 7ULL ; } else if ( ( ( CI_idx_22 == 0 ) && (
U_idx_0 < 6.0 ) && ( ( size_t ) Q_idx_1 == 6ULL ) ) || ( ( U_idx_0 < 6.0 ) &&
( ( size_t ) Q_idx_1 == 6ULL ) && ( Q_idx_2 != 0 ) ) ) { t1 = 7ULL ; } else
if ( ( ( CI_idx_21 == 0 ) && ( U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_1 ==
7ULL ) ) || ( ( U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_1 == 7ULL ) && (
Q_idx_2 != 0 ) ) ) { t1 = 4ULL ; } else if ( ( ( CI_idx_20 == 0 ) && (
U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_1 == 8ULL ) ) || ( ( U_idx_0 > 6.0 ) &&
( ( size_t ) Q_idx_1 == 8ULL ) && ( Q_idx_2 != 0 ) ) ) { t1 = 4ULL ; } else
if ( ( ( CI_idx_19 == 0 ) && ( U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_1 ==
9ULL ) ) || ( ( U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_1 == 9ULL ) && (
Q_idx_2 != 0 ) ) ) { t1 = 4ULL ; } else if ( ( ( CI_idx_18 == 0 ) && (
U_idx_0 < 6.0 ) && ( ( size_t ) Q_idx_1 == 1ULL ) ) || ( ( U_idx_0 < 6.0 ) &&
( ( size_t ) Q_idx_1 == 1ULL ) && ( Q_idx_2 != 0 ) ) ) { t1 = 2ULL ; } else
if ( ( ( CI_idx_17 == 0 ) && ( U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_1 ==
1ULL ) ) || ( ( U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_1 == 1ULL ) && (
Q_idx_2 != 0 ) ) ) { t1 = 3ULL ; } else if ( ( ( CI_idx_16 == 0 ) && (
U_idx_0 > 6.0 ) && ( ( size_t ) Q_idx_1 == 2ULL ) ) || ( ( U_idx_0 > 6.0 ) &&
( ( size_t ) Q_idx_1 == 2ULL ) && ( Q_idx_2 != 0 ) ) ) { t1 = 4ULL ; } else
if ( ( ( CI_idx_15 == 0 ) && ( U_idx_0 >= 6.0 ) && ( ( size_t ) Q_idx_1 ==
4ULL ) ) || ( ( U_idx_0 >= 6.0 ) && ( ( size_t ) Q_idx_1 == 4ULL ) && (
Q_idx_2 != 0 ) ) ) { t1 = 5ULL ; } else if ( ( ( CI_idx_14 == 0 ) && (
U_idx_0 >= 6.0 ) && ( ( size_t ) Q_idx_1 == 5ULL ) ) || ( ( U_idx_0 >= 6.0 )
&& ( ( size_t ) Q_idx_1 == 5ULL ) && ( Q_idx_2 != 0 ) ) ) { t1 = 6ULL ; }
else if ( ( ( CI_idx_13 == 0 ) && ( U_idx_0 >= 6.0 ) && ( ( size_t ) Q_idx_1
== 6ULL ) ) || ( ( U_idx_0 >= 6.0 ) && ( ( size_t ) Q_idx_1 == 6ULL ) && (
Q_idx_2 != 0 ) ) ) { t1 = 3ULL ; } else if ( ( ( CI_idx_11 == 0 ) && (
U_idx_0 < 6.0 ) && ( ( size_t ) Q_idx_1 == 3ULL ) ) || ( ( U_idx_0 < 6.0 ) &&
( ( size_t ) Q_idx_1 == 3ULL ) && ( Q_idx_2 != 0 ) ) ) { t1 = 7ULL ; } else
if ( ( ( CI_idx_10 == 0 ) && ( U_idx_0 <= 6.0 ) && ( ( size_t ) Q_idx_1 ==
7ULL ) ) || ( ( U_idx_0 <= 6.0 ) && ( ( size_t ) Q_idx_1 == 7ULL ) && (
Q_idx_2 != 0 ) ) ) { t1 = 8ULL ; } else if ( ( ( CI_idx_9 == 0 ) && ( U_idx_0
<= 6.0 ) && ( ( size_t ) Q_idx_1 == 8ULL ) ) || ( ( U_idx_0 <= 6.0 ) && ( (
size_t ) Q_idx_1 == 8ULL ) && ( Q_idx_2 != 0 ) ) ) { t1 = 9ULL ; } else if (
( ( CI_idx_8 == 0 ) && ( U_idx_0 <= 6.0 ) && ( ( size_t ) Q_idx_1 == 9ULL ) )
|| ( ( U_idx_0 <= 6.0 ) && ( ( size_t ) Q_idx_1 == 9ULL ) && ( Q_idx_2 != 0 )
) ) { t1 = 2ULL ; } else { t1 = ( size_t ) Q_idx_1 ; } out . mX [ 0 ] = (
int32_T ) t0 ; out . mX [ 1 ] = ( int32_T ) t1 ; out . mX [ 2 ] = 0 ; ( void
) LC ; ( void ) t4 ; return 0 ; }

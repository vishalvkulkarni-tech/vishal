#include "ne_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_sys_struct.h"
#include "IGBTThermal_399ad5b0_1_ds_update2_r.h"
#include "IGBTThermal_399ad5b0_1_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_externals.h"
#include "IGBTThermal_399ad5b0_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T IGBTThermal_399ad5b0_1_ds_update2_r ( const NeDynamicSystem * LC ,
const NeDynamicSystemInput * t59 , NeDsMethodOutput * t60 ) { ETTSf3049b48
b_efOut ; ETTSf3049b48 c_efOut ; ETTSf3049b48 d_efOut ; ETTSf3049b48 e_efOut
; ETTSf3049b48 efOut ; ETTSf3049b48 f_efOut ; ETTSf3049b48 t0 ; ETTSf3049b48
t1 ; ETTSf3049b48 t2 ; ETTSf3049b48 t3 ; ETTSf3049b48 t4 ; ETTSf3049b48 t5 ;
PmRealVector out ; real_T nonscalar10 [ 7 ] ; real_T nonscalar9 [ 2 ] ;
real_T g_efOut [ 1 ] ; real_T h_efOut [ 1 ] ; real_T i_efOut [ 1 ] ; real_T
j_efOut [ 1 ] ; real_T t53 [ 1 ] ; real_T D_idx_0 ; real_T D_idx_1 ; real_T
D_idx_10 ; real_T D_idx_11 ; real_T D_idx_12 ; real_T D_idx_13 ; real_T
D_idx_2 ; real_T D_idx_3 ; real_T D_idx_4 ; real_T D_idx_5 ; real_T D_idx_6 ;
real_T D_idx_7 ; real_T D_idx_8 ; real_T D_idx_9 ; real_T U_idx_0 ; real_T
X_idx_12 ; real_T X_idx_13 ; real_T X_idx_14 ; real_T X_idx_16 ; real_T
X_idx_17 ; real_T X_idx_4 ; size_t t47 [ 1 ] ; size_t t48 [ 1 ] ; size_t t49
[ 1 ] ; int32_T CI_idx_27 ; int32_T CI_idx_28 ; int32_T CI_idx_29 ; int32_T
CI_idx_30 ; int32_T CI_idx_31 ; int32_T CI_idx_32 ; int32_T CI_idx_33 ;
int32_T CI_idx_35 ; int32_T CI_idx_36 ; int32_T CI_idx_37 ; int32_T CI_idx_38
; int32_T CI_idx_39 ; int32_T CI_idx_40 ; int32_T CI_idx_41 ; int32_T
CI_idx_42 ; int32_T CI_idx_44 ; int32_T CI_idx_46 ; int32_T CI_idx_47 ;
int32_T CI_idx_48 ; int32_T CI_idx_49 ; int32_T CI_idx_50 ; int32_T CI_idx_51
; int32_T CI_idx_52 ; int32_T CI_idx_53 ; int32_T CI_idx_54 ; int32_T
CI_idx_55 ; int32_T CI_idx_57 ; int32_T CI_idx_58 ; int32_T CI_idx_59 ;
int32_T CI_idx_60 ; int32_T Q_idx_0 ; int32_T Q_idx_1 ; Q_idx_0 = t59 -> mQ .
mX [ 0 ] ; Q_idx_1 = t59 -> mQ . mX [ 1 ] ; U_idx_0 = t59 -> mU . mX [ 0 ] ;
X_idx_4 = t59 -> mX . mX [ 4 ] ; X_idx_12 = t59 -> mX . mX [ 12 ] ; X_idx_13
= t59 -> mX . mX [ 13 ] ; X_idx_14 = t59 -> mX . mX [ 14 ] ; X_idx_16 = t59
-> mX . mX [ 16 ] ; X_idx_17 = t59 -> mX . mX [ 17 ] ; D_idx_0 = t59 -> mD .
mX [ 0 ] ; D_idx_1 = t59 -> mD . mX [ 1 ] ; D_idx_2 = t59 -> mD . mX [ 2 ] ;
D_idx_3 = t59 -> mD . mX [ 3 ] ; D_idx_4 = t59 -> mD . mX [ 4 ] ; D_idx_5 =
t59 -> mD . mX [ 5 ] ; D_idx_6 = t59 -> mD . mX [ 6 ] ; D_idx_7 = t59 -> mD .
mX [ 7 ] ; D_idx_8 = t59 -> mD . mX [ 8 ] ; D_idx_9 = t59 -> mD . mX [ 9 ] ;
D_idx_10 = t59 -> mD . mX [ 10 ] ; D_idx_11 = t59 -> mD . mX [ 11 ] ;
D_idx_12 = t59 -> mD . mX [ 12 ] ; D_idx_13 = t59 -> mD . mX [ 13 ] ;
CI_idx_27 = t59 -> mCI . mX [ 27 ] ; CI_idx_28 = t59 -> mCI . mX [ 28 ] ;
CI_idx_29 = t59 -> mCI . mX [ 29 ] ; CI_idx_30 = t59 -> mCI . mX [ 30 ] ;
CI_idx_31 = t59 -> mCI . mX [ 31 ] ; CI_idx_32 = t59 -> mCI . mX [ 32 ] ;
CI_idx_33 = t59 -> mCI . mX [ 33 ] ; CI_idx_35 = t59 -> mCI . mX [ 35 ] ;
CI_idx_36 = t59 -> mCI . mX [ 36 ] ; CI_idx_37 = t59 -> mCI . mX [ 37 ] ;
CI_idx_38 = t59 -> mCI . mX [ 38 ] ; CI_idx_39 = t59 -> mCI . mX [ 39 ] ;
CI_idx_40 = t59 -> mCI . mX [ 40 ] ; CI_idx_41 = t59 -> mCI . mX [ 41 ] ;
CI_idx_42 = t59 -> mCI . mX [ 42 ] ; CI_idx_44 = t59 -> mCI . mX [ 44 ] ;
CI_idx_46 = t59 -> mCI . mX [ 46 ] ; CI_idx_47 = t59 -> mCI . mX [ 47 ] ;
CI_idx_48 = t59 -> mCI . mX [ 48 ] ; CI_idx_49 = t59 -> mCI . mX [ 49 ] ;
CI_idx_50 = t59 -> mCI . mX [ 50 ] ; CI_idx_51 = t59 -> mCI . mX [ 51 ] ;
CI_idx_52 = t59 -> mCI . mX [ 52 ] ; CI_idx_53 = t59 -> mCI . mX [ 53 ] ;
CI_idx_54 = t59 -> mCI . mX [ 54 ] ; CI_idx_55 = t59 -> mCI . mX [ 55 ] ;
CI_idx_57 = t59 -> mCI . mX [ 57 ] ; CI_idx_58 = t59 -> mCI . mX [ 58 ] ;
CI_idx_59 = t59 -> mCI . mX [ 59 ] ; CI_idx_60 = t59 -> mCI . mX [ 60 ] ; out
= t60 -> mUPDATE2_R ; nonscalar10 [ 0 ] = 0.0 ; nonscalar10 [ 1 ] = 10.0 ;
nonscalar10 [ 2 ] = 50.0 ; nonscalar10 [ 3 ] = 100.0 ; nonscalar10 [ 4 ] =
200.0 ; nonscalar10 [ 5 ] = 400.0 ; nonscalar10 [ 6 ] = 600.0 ; nonscalar9 [
0 ] = 298.15 ; nonscalar9 [ 1 ] = 398.15 ; t53 [ 0ULL ] = X_idx_4 ; t47 [ 0 ]
= 2ULL ; t48 [ 0 ] = 1ULL ; tlu2_linear_linear_prelookup ( & efOut . mField0
[ 0ULL ] , & efOut . mField1 [ 0ULL ] , & efOut . mField2 [ 0ULL ] , &
nonscalar9 [ 0ULL ] , & t53 [ 0ULL ] , & t47 [ 0ULL ] , & t48 [ 0ULL ] ) ; t5
= efOut ; t53 [ 0ULL ] = ( real_T ) ( D_idx_3 >= 0.0 ) * D_idx_3 ; t49 [ 0 ]
= 7ULL ; tlu2_linear_linear_prelookup ( & b_efOut . mField0 [ 0ULL ] , &
b_efOut . mField1 [ 0ULL ] , & b_efOut . mField2 [ 0ULL ] , & nonscalar10 [
0ULL ] , & t53 [ 0ULL ] , & t49 [ 0ULL ] , & t48 [ 0ULL ] ) ; t4 = b_efOut ;
t53 [ 0ULL ] = ( X_idx_17 * 0.0 + D_idx_3 ) * ( real_T ) ( X_idx_17 >= 0.0 )
; tlu2_linear_linear_prelookup ( & c_efOut . mField0 [ 0ULL ] , & c_efOut .
mField1 [ 0ULL ] , & c_efOut . mField2 [ 0ULL ] , & nonscalar10 [ 0ULL ] , &
t53 [ 0ULL ] , & t49 [ 0ULL ] , & t48 [ 0ULL ] ) ; t3 = c_efOut ; t53 [ 0ULL
] = X_idx_12 ; tlu2_linear_linear_prelookup ( & d_efOut . mField0 [ 0ULL ] ,
& d_efOut . mField1 [ 0ULL ] , & d_efOut . mField2 [ 0ULL ] , & nonscalar9 [
0ULL ] , & t53 [ 0ULL ] , & t47 [ 0ULL ] , & t48 [ 0ULL ] ) ; t2 = d_efOut ;
t53 [ 0ULL ] = ( real_T ) ( D_idx_10 >= 0.0 ) * D_idx_10 ;
tlu2_linear_linear_prelookup ( & e_efOut . mField0 [ 0ULL ] , & e_efOut .
mField1 [ 0ULL ] , & e_efOut . mField2 [ 0ULL ] , & nonscalar10 [ 0ULL ] , &
t53 [ 0ULL ] , & t49 [ 0ULL ] , & t48 [ 0ULL ] ) ; t1 = e_efOut ; t53 [ 0ULL
] = ( X_idx_14 * 0.0 + D_idx_10 ) * ( real_T ) ( X_idx_14 >= 0.0 ) ;
tlu2_linear_linear_prelookup ( & f_efOut . mField0 [ 0ULL ] , & f_efOut .
mField1 [ 0ULL ] , & f_efOut . mField2 [ 0ULL ] , & nonscalar10 [ 0ULL ] , &
t53 [ 0ULL ] , & t49 [ 0ULL ] , & t48 [ 0ULL ] ) ; t0 = f_efOut ; if ( ( (
CI_idx_42 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_0 == 4ULL ) ) ||
( ( CI_idx_41 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_0 == 5ULL ) )
|| ( ( CI_idx_40 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_0 == 6ULL
) ) || ( ( CI_idx_39 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_0 ==
7ULL ) ) || ( ( CI_idx_38 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_0
== 8ULL ) ) || ( ( CI_idx_37 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t )
Q_idx_0 == 9ULL ) ) || ( ( CI_idx_36 == 0 ) && ( U_idx_0 < 0.0 ) && ( (
size_t ) Q_idx_0 == 1ULL ) ) || ( ( CI_idx_35 == 0 ) && ( U_idx_0 > 0.0 ) &&
( ( size_t ) Q_idx_0 == 1ULL ) ) || ( ( CI_idx_33 == 0 ) && ( U_idx_0 > 0.0 )
&& ( ( size_t ) Q_idx_0 == 2ULL ) ) || ( ( CI_idx_32 == 0 ) && ( U_idx_0 >
0.0 ) && ( ( size_t ) Q_idx_0 == 4ULL ) ) ) { } else if ( ( CI_idx_31 == 0 )
&& ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_0 == 5ULL ) ) { D_idx_0 += D_idx_2
; } else if ( ( ( CI_idx_30 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t )
Q_idx_0 == 6ULL ) ) || ( ( CI_idx_29 == 0 ) && ( U_idx_0 < 0.0 ) && ( (
size_t ) Q_idx_0 == 3ULL ) ) || ( ( CI_idx_28 == 0 ) && ( U_idx_0 < 0.0 ) &&
( ( size_t ) Q_idx_0 == 7ULL ) ) || ( ! ( ( CI_idx_27 == 0 ) && ( U_idx_0 <
0.0 ) && ( ( size_t ) Q_idx_0 == 8ULL ) ) ) ) { } else { D_idx_0 += D_idx_1 ;
} if ( ( ( CI_idx_42 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_0 ==
4ULL ) ) || ( ( CI_idx_41 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_0
== 5ULL ) ) || ( ( CI_idx_40 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t )
Q_idx_0 == 6ULL ) ) ) { } else if ( ( CI_idx_39 == 0 ) && ( U_idx_0 > 0.0 )
&& ( ( size_t ) Q_idx_0 == 7ULL ) ) { D_idx_1 = 0.0 ; } else if ( ( CI_idx_38
== 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_0 == 8ULL ) ) { D_idx_1 =
0.0 ; } else if ( ( CI_idx_37 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t )
Q_idx_0 == 9ULL ) ) { D_idx_1 = 0.0 ; } else if ( ( ( CI_idx_36 == 0 ) && (
U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_0 == 1ULL ) ) || ( ( CI_idx_35 == 0 )
&& ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_0 == 1ULL ) ) ) { } else if ( (
CI_idx_33 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_0 == 2ULL ) ) {
D_idx_1 = 0.0 ; } else if ( ( ( CI_idx_32 == 0 ) && ( U_idx_0 > 0.0 ) && ( (
size_t ) Q_idx_0 == 4ULL ) ) || ( ( CI_idx_31 == 0 ) && ( U_idx_0 > 0.0 ) &&
( ( size_t ) Q_idx_0 == 5ULL ) ) || ( ( CI_idx_30 == 0 ) && ( U_idx_0 > 0.0 )
&& ( ( size_t ) Q_idx_0 == 6ULL ) ) || ( ( CI_idx_29 == 0 ) && ( U_idx_0 <
0.0 ) && ( ( size_t ) Q_idx_0 == 3ULL ) ) || ( ! ( ( CI_idx_28 == 0 ) && (
U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_0 == 7ULL ) ) ) ) { } else { t47 [ 0 ]
= 2ULL ; t48 [ 0 ] = 7ULL ; t49 [ 0 ] = 1ULL ; tlu2_2d_linear_linear_value (
& g_efOut [ 0ULL ] , & t5 . mField0 [ 0ULL ] , & t5 . mField2 [ 0ULL ] , & t4
. mField0 [ 0ULL ] , & t4 . mField2 [ 0ULL ] , ( ( _NeDynamicSystem * ) ( LC
) ) -> mField0 , & t47 [ 0ULL ] , & t48 [ 0ULL ] , & t49 [ 0ULL ] ) ; t53 [ 0
] = g_efOut [ 0 ] ; D_idx_1 = ( real_T ) ( X_idx_16 >= 0.0 ) * D_idx_6 /
300.0 * t53 [ 0ULL ] ; } if ( ( CI_idx_42 == 0 ) && ( U_idx_0 < 0.0 ) && ( (
size_t ) Q_idx_0 == 4ULL ) ) { D_idx_2 = 0.0 ; } else if ( ( CI_idx_41 == 0 )
&& ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_0 == 5ULL ) ) { D_idx_2 = 0.0 ; }
else if ( ( CI_idx_40 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_0 ==
6ULL ) ) { D_idx_2 = 0.0 ; } else if ( ( ( CI_idx_39 == 0 ) && ( U_idx_0 >
0.0 ) && ( ( size_t ) Q_idx_0 == 7ULL ) ) || ( ( CI_idx_38 == 0 ) && (
U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_0 == 8ULL ) ) || ( ( CI_idx_37 == 0 )
&& ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_0 == 9ULL ) ) || ( ( CI_idx_36 ==
0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_0 == 1ULL ) ) || ( ( CI_idx_35
== 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_0 == 1ULL ) ) || ( (
CI_idx_33 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_0 == 2ULL ) ) ) {
} else if ( ( CI_idx_32 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_0
== 4ULL ) ) { t47 [ 0 ] = 2ULL ; t48 [ 0 ] = 7ULL ; t49 [ 0 ] = 1ULL ;
tlu2_2d_linear_linear_value ( & h_efOut [ 0ULL ] , & t5 . mField0 [ 0ULL ] ,
& t5 . mField2 [ 0ULL ] , & t3 . mField0 [ 0ULL ] , & t3 . mField2 [ 0ULL ] ,
( ( _NeDynamicSystem * ) ( LC ) ) -> mField2 , & t47 [ 0ULL ] , & t48 [ 0ULL
] , & t49 [ 0ULL ] ) ; t53 [ 0 ] = h_efOut [ 0 ] ; D_idx_2 = ( real_T ) (
X_idx_17 > 0.0 ) * D_idx_6 / 300.0 * t53 [ 0ULL ] ; } else if ( ( ( CI_idx_31
== 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_0 == 5ULL ) ) || ( (
CI_idx_30 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_0 == 6ULL ) ) ) {
} else { D_idx_2 = ( CI_idx_29 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t )
Q_idx_0 == 3ULL ) ? 0.0 : D_idx_2 ; } if ( ( CI_idx_42 == 0 ) && ( U_idx_0 <
0.0 ) && ( ( size_t ) Q_idx_0 == 4ULL ) ) { D_idx_3 = X_idx_17 ; } else if (
( CI_idx_41 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_0 == 5ULL ) ) {
D_idx_3 = X_idx_17 ; } else if ( ( CI_idx_40 == 0 ) && ( U_idx_0 < 0.0 ) && (
( size_t ) Q_idx_0 == 6ULL ) ) { D_idx_3 = X_idx_17 ; } else if ( ( (
CI_idx_39 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_0 == 7ULL ) ) ||
( ( CI_idx_38 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_0 == 8ULL ) )
|| ( ( CI_idx_37 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_0 == 9ULL
) ) || ( ( CI_idx_36 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_0 ==
1ULL ) ) || ( ( CI_idx_35 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_0
== 1ULL ) ) || ( ( CI_idx_33 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t )
Q_idx_0 == 2ULL ) ) || ( ( CI_idx_32 == 0 ) && ( U_idx_0 > 0.0 ) && ( (
size_t ) Q_idx_0 == 4ULL ) ) || ( ( CI_idx_31 == 0 ) && ( U_idx_0 > 0.0 ) &&
( ( size_t ) Q_idx_0 == 5ULL ) ) || ( ( CI_idx_30 == 0 ) && ( U_idx_0 > 0.0 )
&& ( ( size_t ) Q_idx_0 == 6ULL ) ) ) { } else { D_idx_3 = ( CI_idx_29 == 0 )
&& ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_0 == 3ULL ) ? X_idx_17 : D_idx_3 ;
} if ( ( ( CI_idx_42 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_0 ==
4ULL ) ) || ( ( CI_idx_41 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_0
== 5ULL ) ) || ( ( CI_idx_40 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t )
Q_idx_0 == 6ULL ) ) || ( ( CI_idx_39 == 0 ) && ( U_idx_0 > 0.0 ) && ( (
size_t ) Q_idx_0 == 7ULL ) ) || ( ( CI_idx_38 == 0 ) && ( U_idx_0 > 0.0 ) &&
( ( size_t ) Q_idx_0 == 8ULL ) ) || ( ( CI_idx_37 == 0 ) && ( U_idx_0 > 0.0 )
&& ( ( size_t ) Q_idx_0 == 9ULL ) ) || ( ( CI_idx_36 == 0 ) && ( U_idx_0 <
0.0 ) && ( ( size_t ) Q_idx_0 == 1ULL ) ) || ( ( CI_idx_35 == 0 ) && (
U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_0 == 1ULL ) ) || ( ( CI_idx_33 == 0 )
&& ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_0 == 2ULL ) ) || ( ! ( ( CI_idx_32
== 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_0 == 4ULL ) ) ) ) { } else
{ D_idx_4 = ( real_T ) ( X_idx_17 >= 0.0 ) * X_idx_17 ; } if ( ( ( CI_idx_42
== 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_0 == 4ULL ) ) || ( (
CI_idx_41 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_0 == 5ULL ) ) ||
( ( CI_idx_40 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_0 == 6ULL ) )
|| ( ( CI_idx_39 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_0 == 7ULL
) ) || ( ( CI_idx_38 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_0 ==
8ULL ) ) || ( ( CI_idx_37 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_0
== 9ULL ) ) || ( ( CI_idx_36 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t )
Q_idx_0 == 1ULL ) ) || ( ( CI_idx_35 == 0 ) && ( U_idx_0 > 0.0 ) && ( (
size_t ) Q_idx_0 == 1ULL ) ) || ( ( CI_idx_33 == 0 ) && ( U_idx_0 > 0.0 ) &&
( ( size_t ) Q_idx_0 == 2ULL ) ) || ( ( CI_idx_32 == 0 ) && ( U_idx_0 > 0.0 )
&& ( ( size_t ) Q_idx_0 == 4ULL ) ) || ( ( CI_idx_31 == 0 ) && ( U_idx_0 >
0.0 ) && ( ( size_t ) Q_idx_0 == 5ULL ) ) || ( ( CI_idx_30 == 0 ) && (
U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_0 == 6ULL ) ) || ( ( CI_idx_29 == 0 )
&& ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_0 == 3ULL ) ) ) { } else { D_idx_5
= ( CI_idx_28 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_0 == 7ULL ) ?
X_idx_16 : D_idx_5 ; } if ( ( ( CI_idx_42 == 0 ) && ( U_idx_0 < 0.0 ) && ( (
size_t ) Q_idx_0 == 4ULL ) ) || ( ( CI_idx_41 == 0 ) && ( U_idx_0 < 0.0 ) &&
( ( size_t ) Q_idx_0 == 5ULL ) ) || ( ( CI_idx_40 == 0 ) && ( U_idx_0 < 0.0 )
&& ( ( size_t ) Q_idx_0 == 6ULL ) ) ) { } else if ( ( CI_idx_39 == 0 ) && (
U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_0 == 7ULL ) ) { D_idx_6 = ( real_T ) (
X_idx_16 >= 0.0 ) * X_idx_16 ; } else if ( ( CI_idx_38 == 0 ) && ( U_idx_0 >
0.0 ) && ( ( size_t ) Q_idx_0 == 8ULL ) ) { D_idx_6 = ( real_T ) ( X_idx_16
>= 0.0 ) * X_idx_16 ; } else if ( ( CI_idx_37 == 0 ) && ( U_idx_0 > 0.0 ) &&
( ( size_t ) Q_idx_0 == 9ULL ) ) { D_idx_6 = ( real_T ) ( X_idx_16 >= 0.0 ) *
X_idx_16 ; } else if ( ( ( CI_idx_36 == 0 ) && ( U_idx_0 < 0.0 ) && ( (
size_t ) Q_idx_0 == 1ULL ) ) || ( ( CI_idx_35 == 0 ) && ( U_idx_0 > 0.0 ) &&
( ( size_t ) Q_idx_0 == 1ULL ) ) || ( ! ( ( CI_idx_33 == 0 ) && ( U_idx_0 >
0.0 ) && ( ( size_t ) Q_idx_0 == 2ULL ) ) ) ) { } else { D_idx_6 = ( real_T )
( X_idx_16 >= 0.0 ) * X_idx_16 ; } if ( ( ( CI_idx_60 == 0 ) && ( U_idx_0 <
0.0 ) && ( ( size_t ) Q_idx_1 == 4ULL ) ) || ( ( CI_idx_59 == 0 ) && (
U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_1 == 5ULL ) ) || ( ( CI_idx_58 == 0 )
&& ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_1 == 6ULL ) ) || ( ( CI_idx_57 ==
0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 7ULL ) ) || ( ( CI_idx_55
== 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 8ULL ) ) || ( (
CI_idx_54 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 9ULL ) ) ||
( ( CI_idx_53 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_1 == 1ULL ) )
|| ( ( CI_idx_52 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 1ULL
) ) || ( ( CI_idx_51 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 ==
2ULL ) ) || ( ( CI_idx_50 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1
== 4ULL ) ) ) { } else if ( ( CI_idx_49 == 0 ) && ( U_idx_0 > 0.0 ) && ( (
size_t ) Q_idx_1 == 5ULL ) ) { D_idx_7 += D_idx_9 ; } else if ( ( ( CI_idx_48
== 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 6ULL ) ) || ( (
CI_idx_47 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_1 == 3ULL ) ) ||
( ( CI_idx_46 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_1 == 7ULL ) )
|| ( ! ( ( CI_idx_44 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_1 ==
8ULL ) ) ) ) { } else { D_idx_7 += D_idx_8 ; } if ( ( ( CI_idx_60 == 0 ) && (
U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_1 == 4ULL ) ) || ( ( CI_idx_59 == 0 )
&& ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_1 == 5ULL ) ) || ( ( CI_idx_58 ==
0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_1 == 6ULL ) ) ) { } else if (
( CI_idx_57 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 7ULL ) ) {
D_idx_8 = 0.0 ; } else if ( ( CI_idx_55 == 0 ) && ( U_idx_0 > 0.0 ) && ( (
size_t ) Q_idx_1 == 8ULL ) ) { D_idx_8 = 0.0 ; } else if ( ( CI_idx_54 == 0 )
&& ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 9ULL ) ) { D_idx_8 = 0.0 ; }
else if ( ( ( CI_idx_53 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_1
== 1ULL ) ) || ( ( CI_idx_52 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t )
Q_idx_1 == 1ULL ) ) ) { } else if ( ( CI_idx_51 == 0 ) && ( U_idx_0 > 0.0 )
&& ( ( size_t ) Q_idx_1 == 2ULL ) ) { D_idx_8 = 0.0 ; } else if ( ( (
CI_idx_50 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 4ULL ) ) ||
( ( CI_idx_49 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 5ULL ) )
|| ( ( CI_idx_48 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 6ULL
) ) || ( ( CI_idx_47 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_1 ==
3ULL ) ) || ( ! ( ( CI_idx_46 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t )
Q_idx_1 == 7ULL ) ) ) ) { } else { t47 [ 0 ] = 2ULL ; t48 [ 0 ] = 7ULL ; t49
[ 0 ] = 1ULL ; tlu2_2d_linear_linear_value ( & i_efOut [ 0ULL ] , & t2 .
mField0 [ 0ULL ] , & t2 . mField2 [ 0ULL ] , & t1 . mField0 [ 0ULL ] , & t1 .
mField2 [ 0ULL ] , ( ( _NeDynamicSystem * ) ( LC ) ) -> mField0 , & t47 [
0ULL ] , & t48 [ 0ULL ] , & t49 [ 0ULL ] ) ; t53 [ 0 ] = i_efOut [ 0 ] ;
D_idx_8 = ( real_T ) ( X_idx_13 >= 0.0 ) * D_idx_13 / 300.0 * t53 [ 0ULL ] ;
} if ( ( CI_idx_60 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_1 ==
4ULL ) ) { D_idx_9 = 0.0 ; } else if ( ( CI_idx_59 == 0 ) && ( U_idx_0 < 0.0
) && ( ( size_t ) Q_idx_1 == 5ULL ) ) { D_idx_9 = 0.0 ; } else if ( (
CI_idx_58 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_1 == 6ULL ) ) {
D_idx_9 = 0.0 ; } else if ( ( ( CI_idx_57 == 0 ) && ( U_idx_0 > 0.0 ) && ( (
size_t ) Q_idx_1 == 7ULL ) ) || ( ( CI_idx_55 == 0 ) && ( U_idx_0 > 0.0 ) &&
( ( size_t ) Q_idx_1 == 8ULL ) ) || ( ( CI_idx_54 == 0 ) && ( U_idx_0 > 0.0 )
&& ( ( size_t ) Q_idx_1 == 9ULL ) ) || ( ( CI_idx_53 == 0 ) && ( U_idx_0 <
0.0 ) && ( ( size_t ) Q_idx_1 == 1ULL ) ) || ( ( CI_idx_52 == 0 ) && (
U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 1ULL ) ) || ( ( CI_idx_51 == 0 )
&& ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 2ULL ) ) ) { } else if ( (
CI_idx_50 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 4ULL ) ) {
t47 [ 0 ] = 2ULL ; t48 [ 0 ] = 7ULL ; t49 [ 0 ] = 1ULL ;
tlu2_2d_linear_linear_value ( & j_efOut [ 0ULL ] , & t2 . mField0 [ 0ULL ] ,
& t2 . mField2 [ 0ULL ] , & t0 . mField0 [ 0ULL ] , & t0 . mField2 [ 0ULL ] ,
( ( _NeDynamicSystem * ) ( LC ) ) -> mField2 , & t47 [ 0ULL ] , & t48 [ 0ULL
] , & t49 [ 0ULL ] ) ; t53 [ 0 ] = j_efOut [ 0 ] ; D_idx_9 = ( real_T ) (
X_idx_14 > 0.0 ) * D_idx_13 / 300.0 * t53 [ 0ULL ] ; } else if ( ( (
CI_idx_49 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 5ULL ) ) ||
( ( CI_idx_48 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 6ULL ) )
) { } else { D_idx_9 = ( CI_idx_47 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t
) Q_idx_1 == 3ULL ) ? 0.0 : D_idx_9 ; } if ( ( CI_idx_60 == 0 ) && ( U_idx_0
< 0.0 ) && ( ( size_t ) Q_idx_1 == 4ULL ) ) { D_idx_10 = X_idx_14 ; } else if
( ( CI_idx_59 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_1 == 5ULL ) )
{ D_idx_10 = X_idx_14 ; } else if ( ( CI_idx_58 == 0 ) && ( U_idx_0 < 0.0 )
&& ( ( size_t ) Q_idx_1 == 6ULL ) ) { D_idx_10 = X_idx_14 ; } else if ( ( (
CI_idx_57 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 7ULL ) ) ||
( ( CI_idx_55 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 8ULL ) )
|| ( ( CI_idx_54 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 9ULL
) ) || ( ( CI_idx_53 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_1 ==
1ULL ) ) || ( ( CI_idx_52 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1
== 1ULL ) ) || ( ( CI_idx_51 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t )
Q_idx_1 == 2ULL ) ) || ( ( CI_idx_50 == 0 ) && ( U_idx_0 > 0.0 ) && ( (
size_t ) Q_idx_1 == 4ULL ) ) || ( ( CI_idx_49 == 0 ) && ( U_idx_0 > 0.0 ) &&
( ( size_t ) Q_idx_1 == 5ULL ) ) || ( ( CI_idx_48 == 0 ) && ( U_idx_0 > 0.0 )
&& ( ( size_t ) Q_idx_1 == 6ULL ) ) ) { } else { D_idx_10 = ( CI_idx_47 == 0
) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_1 == 3ULL ) ? X_idx_14 :
D_idx_10 ; } if ( ( ( CI_idx_60 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t )
Q_idx_1 == 4ULL ) ) || ( ( CI_idx_59 == 0 ) && ( U_idx_0 < 0.0 ) && ( (
size_t ) Q_idx_1 == 5ULL ) ) || ( ( CI_idx_58 == 0 ) && ( U_idx_0 < 0.0 ) &&
( ( size_t ) Q_idx_1 == 6ULL ) ) || ( ( CI_idx_57 == 0 ) && ( U_idx_0 > 0.0 )
&& ( ( size_t ) Q_idx_1 == 7ULL ) ) || ( ( CI_idx_55 == 0 ) && ( U_idx_0 >
0.0 ) && ( ( size_t ) Q_idx_1 == 8ULL ) ) || ( ( CI_idx_54 == 0 ) && (
U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 9ULL ) ) || ( ( CI_idx_53 == 0 )
&& ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_1 == 1ULL ) ) || ( ( CI_idx_52 ==
0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 1ULL ) ) || ( ( CI_idx_51
== 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 2ULL ) ) || ( ! ( (
CI_idx_50 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 4ULL ) ) ) )
{ } else { D_idx_11 = ( real_T ) ( X_idx_14 >= 0.0 ) * X_idx_14 ; } if ( ( (
CI_idx_60 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_1 == 4ULL ) ) ||
( ( CI_idx_59 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_1 == 5ULL ) )
|| ( ( CI_idx_58 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_1 == 6ULL
) ) || ( ( CI_idx_57 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 ==
7ULL ) ) || ( ( CI_idx_55 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1
== 8ULL ) ) || ( ( CI_idx_54 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t )
Q_idx_1 == 9ULL ) ) || ( ( CI_idx_53 == 0 ) && ( U_idx_0 < 0.0 ) && ( (
size_t ) Q_idx_1 == 1ULL ) ) || ( ( CI_idx_52 == 0 ) && ( U_idx_0 > 0.0 ) &&
( ( size_t ) Q_idx_1 == 1ULL ) ) || ( ( CI_idx_51 == 0 ) && ( U_idx_0 > 0.0 )
&& ( ( size_t ) Q_idx_1 == 2ULL ) ) || ( ( CI_idx_50 == 0 ) && ( U_idx_0 >
0.0 ) && ( ( size_t ) Q_idx_1 == 4ULL ) ) || ( ( CI_idx_49 == 0 ) && (
U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 5ULL ) ) || ( ( CI_idx_48 == 0 )
&& ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 6ULL ) ) || ( ( CI_idx_47 ==
0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_1 == 3ULL ) ) ) { } else {
D_idx_12 = ( CI_idx_46 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_1 ==
7ULL ) ? X_idx_13 : D_idx_12 ; } if ( ( ( CI_idx_60 == 0 ) && ( U_idx_0 < 0.0
) && ( ( size_t ) Q_idx_1 == 4ULL ) ) || ( ( CI_idx_59 == 0 ) && ( U_idx_0 <
0.0 ) && ( ( size_t ) Q_idx_1 == 5ULL ) ) || ( ( CI_idx_58 == 0 ) && (
U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_1 == 6ULL ) ) ) { } else if ( (
CI_idx_57 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 7ULL ) ) {
D_idx_13 = ( real_T ) ( X_idx_13 >= 0.0 ) * X_idx_13 ; } else if ( (
CI_idx_55 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 8ULL ) ) {
D_idx_13 = ( real_T ) ( X_idx_13 >= 0.0 ) * X_idx_13 ; } else if ( (
CI_idx_54 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 9ULL ) ) {
D_idx_13 = ( real_T ) ( X_idx_13 >= 0.0 ) * X_idx_13 ; } else if ( ( (
CI_idx_53 == 0 ) && ( U_idx_0 < 0.0 ) && ( ( size_t ) Q_idx_1 == 1ULL ) ) ||
( ( CI_idx_52 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 == 1ULL ) )
|| ( ! ( ( CI_idx_51 == 0 ) && ( U_idx_0 > 0.0 ) && ( ( size_t ) Q_idx_1 ==
2ULL ) ) ) ) { } else { D_idx_13 = ( real_T ) ( X_idx_13 >= 0.0 ) * X_idx_13
; } out . mX [ 0 ] = D_idx_0 ; out . mX [ 1 ] = D_idx_1 ; out . mX [ 2 ] =
D_idx_2 ; out . mX [ 3 ] = D_idx_3 ; out . mX [ 4 ] = D_idx_4 ; out . mX [ 5
] = D_idx_5 ; out . mX [ 6 ] = D_idx_6 ; out . mX [ 7 ] = D_idx_7 ; out . mX
[ 8 ] = D_idx_8 ; out . mX [ 9 ] = D_idx_9 ; out . mX [ 10 ] = D_idx_10 ; out
. mX [ 11 ] = D_idx_11 ; out . mX [ 12 ] = D_idx_12 ; out . mX [ 13 ] =
D_idx_13 ; ( void ) LC ; ( void ) t60 ; return 0 ; }

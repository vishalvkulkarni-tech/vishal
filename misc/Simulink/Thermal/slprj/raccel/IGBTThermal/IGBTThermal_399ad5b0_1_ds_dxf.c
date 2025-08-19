#include "ne_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_sys_struct.h"
#include "IGBTThermal_399ad5b0_1_ds_dxf.h"
#include "IGBTThermal_399ad5b0_1_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_externals.h"
#include "IGBTThermal_399ad5b0_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T IGBTThermal_399ad5b0_1_ds_dxf ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t199 , NeDsMethodOutput * t200 ) { ETTS8eaf4aba
b_efOut ; ETTS8eaf4aba d_efOut ; ETTS8eaf4aba e_efOut ; ETTS8eaf4aba efOut ;
ETTS8eaf4aba g_efOut ; ETTS8eaf4aba h_efOut ; ETTS8eaf4aba j_efOut ;
ETTS8eaf4aba k_efOut ; ETTS8eaf4aba t18 ; ETTS8eaf4aba t20 ; PmRealVector out
; real_T t71 [ 36 ] ; real_T t1 [ 12 ] ; real_T nonscalar5 [ 9 ] ; real_T t80
[ 6 ] ; real_T nonscalar4 [ 3 ] ; real_T c_efOut [ 1 ] ; real_T f_efOut [ 1 ]
; real_T i_efOut [ 1 ] ; real_T l_efOut [ 1 ] ; real_T t28 [ 1 ] ; real_T t32
[ 1 ] ; real_T t39 [ 1 ] ; real_T t61 [ 1 ] ; real_T X_idx_12 ; real_T
X_idx_13 ; real_T X_idx_14 ; real_T X_idx_16 ; real_T X_idx_17 ; real_T
X_idx_4 ; real_T t138 ; real_T t13_idx_0 ; real_T t149 ; real_T t174 ; real_T
t176 ; real_T t182 ; real_T t24 ; size_t t0 [ 14 ] ; size_t t27 [ 1 ] ;
size_t t29 [ 1 ] ; size_t t31 [ 1 ] ; size_t t33 [ 1 ] ; size_t t110 ;
int32_T M_idx_32 ; int32_T M_idx_33 ; int32_T Q_idx_0 ; int32_T Q_idx_1 ;
boolean_T intrm_sf_mf_10 ; boolean_T intrm_sf_mf_11 ; boolean_T
intrm_sf_mf_12 ; boolean_T intrm_sf_mf_13 ; boolean_T intrm_sf_mf_14 ;
boolean_T intrm_sf_mf_15 ; boolean_T intrm_sf_mf_16 ; boolean_T
intrm_sf_mf_17 ; boolean_T intrm_sf_mf_18 ; boolean_T intrm_sf_mf_19 ;
boolean_T intrm_sf_mf_20 ; boolean_T intrm_sf_mf_21 ; boolean_T intrm_sf_mf_6
; boolean_T intrm_sf_mf_7 ; boolean_T intrm_sf_mf_8 ; boolean_T intrm_sf_mf_9
; Q_idx_0 = t199 -> mQ . mX [ 0 ] ; Q_idx_1 = t199 -> mQ . mX [ 1 ] ;
M_idx_32 = t199 -> mM . mX [ 32 ] ; M_idx_33 = t199 -> mM . mX [ 33 ] ;
X_idx_4 = t199 -> mX . mX [ 4 ] ; X_idx_12 = t199 -> mX . mX [ 12 ] ;
X_idx_13 = t199 -> mX . mX [ 13 ] ; X_idx_14 = t199 -> mX . mX [ 14 ] ;
X_idx_16 = t199 -> mX . mX [ 16 ] ; X_idx_17 = t199 -> mX . mX [ 17 ] ; out =
t200 -> mDXF ; t1 [ 0 ] = 0.0 ; t1 [ 1 ] = 0.0 ; t1 [ 2 ] = 0.0 ; t1 [ 3 ] =
0.0 ; t1 [ 4 ] = 0.0 ; t1 [ 5 ] = 0.0 ; t1 [ 6 ] = 0.0 ; t1 [ 7 ] = 0.0 ; t1
[ 8 ] = 0.0 ; t1 [ 9 ] = 0.0 ; t1 [ 10 ] = 0.0 ; t1 [ 11 ] = 0.0 ; t0 [ 0 ] =
0ULL ; t0 [ 1 ] = 0ULL ; t0 [ 2 ] = 0ULL ; t0 [ 3 ] = 0ULL ; t0 [ 4 ] = 0ULL
; t0 [ 5 ] = 0ULL ; t0 [ 6 ] = 0ULL ; t0 [ 7 ] = 0ULL ; t0 [ 8 ] = 0ULL ; t0
[ 9 ] = 0ULL ; t0 [ 10 ] = 0ULL ; t0 [ 11 ] = 0ULL ; t0 [ 12 ] = 0ULL ; t0 [
13 ] = 0ULL ; nonscalar4 [ 0 ] = 298.15 ; nonscalar4 [ 1 ] = 348.15 ;
nonscalar4 [ 2 ] = 398.15 ; nonscalar5 [ 0 ] = - 0.2 ; nonscalar5 [ 1 ] = -
0.1 ; nonscalar5 [ 2 ] = 0.0 ; nonscalar5 [ 3 ] = 10.0 ; nonscalar5 [ 4 ] =
50.0 ; nonscalar5 [ 5 ] = 100.0 ; nonscalar5 [ 6 ] = 200.0 ; nonscalar5 [ 7 ]
= 400.0 ; nonscalar5 [ 8 ] = 600.0 ; intrm_sf_mf_10 = ( ( size_t ) Q_idx_0 ==
4ULL ) ; intrm_sf_mf_11 = ( ( size_t ) Q_idx_0 == 3ULL ) ; intrm_sf_mf_12 = (
( size_t ) Q_idx_0 == 2ULL ) ; intrm_sf_mf_13 = ( ( size_t ) Q_idx_0 == 1ULL
) ; intrm_sf_mf_14 = ( ( size_t ) Q_idx_1 == 8ULL ) ; intrm_sf_mf_15 = ( (
size_t ) Q_idx_1 == 7ULL ) ; intrm_sf_mf_16 = ( ( size_t ) Q_idx_1 == 6ULL )
; intrm_sf_mf_17 = ( ( size_t ) Q_idx_1 == 5ULL ) ; intrm_sf_mf_18 = ( (
size_t ) Q_idx_1 == 4ULL ) ; intrm_sf_mf_19 = ( ( size_t ) Q_idx_1 == 3ULL )
; intrm_sf_mf_20 = ( ( size_t ) Q_idx_1 == 2ULL ) ; intrm_sf_mf_21 = ( (
size_t ) Q_idx_1 == 1ULL ) ; intrm_sf_mf_6 = ( ( size_t ) Q_idx_0 == 8ULL ) ;
intrm_sf_mf_7 = ( ( size_t ) Q_idx_0 == 7ULL ) ; intrm_sf_mf_8 = ( ( size_t )
Q_idx_0 == 6ULL ) ; intrm_sf_mf_9 = ( ( size_t ) Q_idx_0 == 5ULL ) ; t27 [ 0
] = 1ULL ; t28 [ 0ULL ] = X_idx_4 ; t29 [ 0 ] = 3ULL ;
tlu2_akima_linear_prelookup ( & efOut . mField0 [ 0ULL ] , & efOut . mField1
[ 0ULL ] , & t27 [ 0ULL ] , & nonscalar4 [ 0ULL ] , & t28 [ 0ULL ] , & t29 [
0ULL ] , & t27 [ 0ULL ] ) ; t18 = efOut ; t31 [ 0 ] = 0ULL ; t32 [ 0ULL ] =
X_idx_17 ; t33 [ 0 ] = 9ULL ; tlu2_akima_linear_prelookup ( & b_efOut .
mField0 [ 0ULL ] , & b_efOut . mField1 [ 0ULL ] , & t31 [ 0ULL ] , &
nonscalar5 [ 0ULL ] , & t32 [ 0ULL ] , & t33 [ 0ULL ] , & t27 [ 0ULL ] ) ;
t20 = b_efOut ; tlu2_2d_akima_linear_value ( & c_efOut [ 0ULL ] , & t18 .
mField0 [ 0ULL ] , & t18 . mField1 [ 0ULL ] , & t20 . mField0 [ 0ULL ] , &
t20 . mField1 [ 0ULL ] , ( ( _NeDynamicSystem * ) ( LC ) ) -> mField1 , & t29
[ 0ULL ] , & t33 [ 0ULL ] , & t1 [ 0ULL ] , & t0 [ 0ULL ] , & t27 [ 0ULL ] )
; t13_idx_0 = c_efOut [ 0 ] ; t39 [ 0ULL ] = X_idx_12 ;
tlu2_akima_linear_prelookup ( & d_efOut . mField0 [ 0ULL ] , & d_efOut .
mField1 [ 0ULL ] , & t27 [ 0ULL ] , & nonscalar4 [ 0ULL ] , & t39 [ 0ULL ] ,
& t29 [ 0ULL ] , & t27 [ 0ULL ] ) ; t18 = d_efOut ; t61 [ 0ULL ] = X_idx_14 ;
tlu2_akima_linear_prelookup ( & e_efOut . mField0 [ 0ULL ] , & e_efOut .
mField1 [ 0ULL ] , & t31 [ 0ULL ] , & nonscalar5 [ 0ULL ] , & t61 [ 0ULL ] ,
& t33 [ 0ULL ] , & t27 [ 0ULL ] ) ; t20 = e_efOut ;
tlu2_2d_akima_linear_value ( & f_efOut [ 0ULL ] , & t18 . mField0 [ 0ULL ] ,
& t18 . mField1 [ 0ULL ] , & t20 . mField0 [ 0ULL ] , & t20 . mField1 [ 0ULL
] , ( ( _NeDynamicSystem * ) ( LC ) ) -> mField1 , & t29 [ 0ULL ] , & t33 [
0ULL ] , & t1 [ 0ULL ] , & t0 [ 0ULL ] , & t27 [ 0ULL ] ) ; t39 [ 0 ] =
f_efOut [ 0 ] ; t61 [ 0ULL ] = X_idx_12 ; tlu2_akima_linear_prelookup ( &
g_efOut . mField0 [ 0ULL ] , & g_efOut . mField1 [ 0ULL ] , & t31 [ 0ULL ] ,
& nonscalar4 [ 0ULL ] , & t61 [ 0ULL ] , & t29 [ 0ULL ] , & t27 [ 0ULL ] ) ;
t18 = g_efOut ; t61 [ 0ULL ] = X_idx_14 ; tlu2_akima_linear_prelookup ( &
h_efOut . mField0 [ 0ULL ] , & h_efOut . mField1 [ 0ULL ] , & t27 [ 0ULL ] ,
& nonscalar5 [ 0ULL ] , & t61 [ 0ULL ] , & t33 [ 0ULL ] , & t27 [ 0ULL ] ) ;
t20 = h_efOut ; tlu2_2d_akima_linear_value ( & i_efOut [ 0ULL ] , & t18 .
mField0 [ 0ULL ] , & t18 . mField1 [ 0ULL ] , & t20 . mField0 [ 0ULL ] , &
t20 . mField1 [ 0ULL ] , ( ( _NeDynamicSystem * ) ( LC ) ) -> mField1 , & t29
[ 0ULL ] , & t33 [ 0ULL ] , & t1 [ 0ULL ] , & t0 [ 0ULL ] , & t27 [ 0ULL ] )
; t32 [ 0 ] = i_efOut [ 0 ] ; t61 [ 0ULL ] = X_idx_4 ;
tlu2_akima_linear_prelookup ( & j_efOut . mField0 [ 0ULL ] , & j_efOut .
mField1 [ 0ULL ] , & t31 [ 0ULL ] , & nonscalar4 [ 0ULL ] , & t61 [ 0ULL ] ,
& t29 [ 0ULL ] , & t27 [ 0ULL ] ) ; t20 = j_efOut ; t61 [ 0ULL ] = X_idx_17 ;
tlu2_akima_linear_prelookup ( & k_efOut . mField0 [ 0ULL ] , & k_efOut .
mField1 [ 0ULL ] , & t27 [ 0ULL ] , & nonscalar5 [ 0ULL ] , & t61 [ 0ULL ] ,
& t33 [ 0ULL ] , & t27 [ 0ULL ] ) ; t18 = k_efOut ;
tlu2_2d_akima_linear_value ( & l_efOut [ 0ULL ] , & t20 . mField0 [ 0ULL ] ,
& t20 . mField1 [ 0ULL ] , & t18 . mField0 [ 0ULL ] , & t18 . mField1 [ 0ULL
] , ( ( _NeDynamicSystem * ) ( LC ) ) -> mField1 , & t29 [ 0ULL ] , & t33 [
0ULL ] , & t1 [ 0ULL ] , & t0 [ 0ULL ] , & t27 [ 0ULL ] ) ; t28 [ 0 ] =
l_efOut [ 0 ] ; if ( intrm_sf_mf_13 ) { t174 = 0.0 ; t176 = 0.0 ; X_idx_4 =
0.0 ; } else if ( intrm_sf_mf_12 ) { t174 = 0.0 ; t176 = 0.0 ; X_idx_4 = 0.0
; } else if ( intrm_sf_mf_11 ) { t174 = - t13_idx_0 ; t176 = - ( t13_idx_0 *
0.0 ) ; X_idx_4 = - ( t13_idx_0 * 0.0 ) ; } else if ( intrm_sf_mf_10 ) { t174
= - t13_idx_0 ; t176 = - ( t13_idx_0 * 0.0 ) ; X_idx_4 = - ( t13_idx_0 * 0.0
) ; } else if ( intrm_sf_mf_9 ) { t174 = - t13_idx_0 ; t176 = - ( t13_idx_0 *
0.0 ) ; X_idx_4 = - ( t13_idx_0 * 0.0 ) ; } else if ( intrm_sf_mf_8 ) { t174
= - t13_idx_0 ; t176 = - ( t13_idx_0 * 0.0 ) ; X_idx_4 = - ( t13_idx_0 * 0.0
) ; } else { t174 = 0.0 ; t176 = 0.0 ; X_idx_4 = 0.0 ; } if ( intrm_sf_mf_13
) { X_idx_12 = 0.0 ; t13_idx_0 = 0.0 ; t182 = 0.0 ; } else if (
intrm_sf_mf_12 ) { X_idx_12 = 0.0 ; t13_idx_0 = 0.0 ; t182 = 0.0 ; } else if
( intrm_sf_mf_11 ) { X_idx_12 = 0.0 ; t13_idx_0 = 0.0 ; t182 = 0.0 ; } else
if ( intrm_sf_mf_10 ) { X_idx_12 = 0.0 ; t13_idx_0 = 0.0 ; t182 = 0.0 ; }
else if ( intrm_sf_mf_9 ) { X_idx_12 = - 1.0 ; t13_idx_0 = 0.0 ; t182 = 0.0 ;
} else if ( intrm_sf_mf_8 ) { X_idx_12 = - 1.0 ; t13_idx_0 = 0.0 ; t182 = 0.0
; } else if ( intrm_sf_mf_7 ) { X_idx_12 = 0.0 ; t13_idx_0 = 0.0 ; t182 = 0.0
; } else { X_idx_12 = - 1.0 ; t13_idx_0 = 0.0 ; t182 = 0.0 ; } if (
intrm_sf_mf_21 ) { t24 = 0.0 ; } else if ( intrm_sf_mf_20 ) { t24 = 0.0 ; }
else if ( intrm_sf_mf_19 ) { t24 = - t39 [ 0ULL ] ; } else if (
intrm_sf_mf_18 ) { t24 = - t39 [ 0ULL ] ; } else if ( intrm_sf_mf_17 ) { t24
= - t39 [ 0ULL ] ; } else if ( intrm_sf_mf_16 ) { t24 = - t39 [ 0ULL ] ; }
else { t24 = 0.0 ; } if ( intrm_sf_mf_21 ) { t138 = 1.0 ; } else if (
intrm_sf_mf_20 ) { t138 = 1.0 ; } else if ( intrm_sf_mf_19 ) { t138 = - t32 [
0ULL ] ; } else if ( intrm_sf_mf_18 ) { t138 = - t32 [ 0ULL ] ; } else if (
intrm_sf_mf_17 ) { t138 = - t32 [ 0ULL ] ; } else if ( intrm_sf_mf_16 ) {
t138 = - t32 [ 0ULL ] ; } else { t138 = 1.0 ; } if ( intrm_sf_mf_13 ) { t149
= 1.0 ; } else if ( intrm_sf_mf_12 ) { t149 = 1.0 ; } else if (
intrm_sf_mf_11 ) { t149 = - t28 [ 0ULL ] ; } else if ( intrm_sf_mf_10 ) {
t149 = - t28 [ 0ULL ] ; } else if ( intrm_sf_mf_9 ) { t149 = - t28 [ 0ULL ] ;
} else if ( intrm_sf_mf_8 ) { t149 = - t28 [ 0ULL ] ; } else { t149 = 1.0 ; }
t80 [ 0ULL ] = t174 ; t80 [ 2ULL ] = t176 ; t80 [ 4ULL ] = X_idx_4 ; t80 [
1ULL ] = X_idx_12 ; t80 [ 3ULL ] = t13_idx_0 ; t80 [ 5ULL ] = t182 ; t71 [
0ULL ] = - 1.0 ; t71 [ 1ULL ] = - 1.0 ; for ( t110 = 0ULL ; t110 < 6ULL ;
t110 ++ ) { t71 [ t110 + 2ULL ] = t80 [ t110 ] ; } out . mX [ 0 ] = t71 [ 0 ]
; out . mX [ 1 ] = t71 [ 1 ] ; out . mX [ 2 ] = t71 [ 2 ] ; out . mX [ 3 ] =
t71 [ 3 ] ; out . mX [ 4 ] = t71 [ 4 ] ; out . mX [ 5 ] = t71 [ 5 ] ; out .
mX [ 6 ] = t71 [ 6 ] ; out . mX [ 7 ] = t71 [ 7 ] ; out . mX [ 8 ] =
intrm_sf_mf_13 ? 0.0 : intrm_sf_mf_12 ? 0.0 : intrm_sf_mf_11 ? 0.0 :
intrm_sf_mf_10 ? 0.0 : intrm_sf_mf_9 ? 1.0 : intrm_sf_mf_8 ? 1.0 : ( real_T )
! intrm_sf_mf_7 ; out . mX [ 9 ] = intrm_sf_mf_21 ? 0.0 : intrm_sf_mf_20 ?
0.0 : intrm_sf_mf_19 ? 0.0 : intrm_sf_mf_18 ? 0.0 : intrm_sf_mf_17 ? 1.0 :
intrm_sf_mf_16 ? 1.0 : ( real_T ) ! intrm_sf_mf_15 ; out . mX [ 10 ] = t24 ;
out . mX [ 11 ] = intrm_sf_mf_21 ? 0.0 : intrm_sf_mf_20 ? 0.0 :
intrm_sf_mf_19 ? 0.0 : intrm_sf_mf_18 ? 0.0 : intrm_sf_mf_17 ? - 1.0 :
intrm_sf_mf_16 ? - 1.0 : intrm_sf_mf_15 ? 0.0 : - 1.0 ; out . mX [ 12 ] = 1.0
; out . mX [ 13 ] = - ( X_idx_14 * 0.001 ) ; out . mX [ 14 ] = intrm_sf_mf_21
? - 1.0E-5 : intrm_sf_mf_20 ? - 1.0E-5 : intrm_sf_mf_19 ? 1.0 :
intrm_sf_mf_18 ? 1.0 : intrm_sf_mf_17 ? 1.0 : intrm_sf_mf_16 ? 1.0 : - 1.0E-5
; out . mX [ 15 ] = - 1.0 ; out . mX [ 16 ] = - ( X_idx_13 * 0.001 ) ; out .
mX [ 17 ] = t138 ; out . mX [ 18 ] = M_idx_32 != 0 ? - 1.0 : - 0.001 ; out .
mX [ 19 ] = M_idx_32 != 0 ? - 1.0E-5 : - 1.0 ; out . mX [ 20 ] = 1.0 ; out .
mX [ 21 ] = - ( X_idx_17 * 0.001 ) ; out . mX [ 22 ] = intrm_sf_mf_13 ? -
1.0E-5 : intrm_sf_mf_12 ? - 1.0E-5 : intrm_sf_mf_11 ? 1.0 : intrm_sf_mf_10 ?
1.0 : intrm_sf_mf_9 ? 1.0 : intrm_sf_mf_8 ? 1.0 : - 1.0E-5 ; out . mX [ 23 ]
= - 1.0 ; out . mX [ 24 ] = - ( X_idx_16 * 0.001 ) ; out . mX [ 25 ] = t149 ;
out . mX [ 26 ] = M_idx_33 != 0 ? - 1.0 : - 0.001 ; out . mX [ 27 ] =
M_idx_33 != 0 ? - 1.0E-5 : - 1.0 ; out . mX [ 28 ] = intrm_sf_mf_13 ? 1.0 :
intrm_sf_mf_12 ? 1.0 : intrm_sf_mf_11 ? 1.0 : intrm_sf_mf_10 ? 1.0 :
intrm_sf_mf_9 ? 1.0 : intrm_sf_mf_8 ? - 1.0 : intrm_sf_mf_7 ? 1.0 :
intrm_sf_mf_6 ? 1.0 : - 1.0 ; out . mX [ 29 ] = intrm_sf_mf_13 ? - 1.0 :
intrm_sf_mf_12 ? - 1.0 : intrm_sf_mf_11 ? - 1.0 : intrm_sf_mf_10 ? - 1.0 :
intrm_sf_mf_9 ? 0.0 : intrm_sf_mf_8 ? 0.0 : intrm_sf_mf_7 ? - 1.0 : 0.0 ; out
. mX [ 30 ] = intrm_sf_mf_13 ? 0.0 : intrm_sf_mf_12 ? 0.0 : intrm_sf_mf_11 ?
0.0 : intrm_sf_mf_10 ? 0.0 : intrm_sf_mf_9 ? 0.0 : intrm_sf_mf_8 ? 1.0 :
intrm_sf_mf_7 ? 0.0 : ( real_T ) ! intrm_sf_mf_6 ; out . mX [ 31 ] =
intrm_sf_mf_13 ? 1.0 : intrm_sf_mf_12 ? 1.0 : intrm_sf_mf_11 ? 1.0 :
intrm_sf_mf_10 ? 1.0 : intrm_sf_mf_9 ? 0.0 : intrm_sf_mf_8 ? 0.0 : ( real_T )
intrm_sf_mf_7 ; out . mX [ 32 ] = intrm_sf_mf_21 ? 1.0 : intrm_sf_mf_20 ? 1.0
: intrm_sf_mf_19 ? 1.0 : intrm_sf_mf_18 ? 1.0 : intrm_sf_mf_17 ? 1.0 :
intrm_sf_mf_16 ? - 1.0 : intrm_sf_mf_15 ? 1.0 : intrm_sf_mf_14 ? 1.0 : - 1.0
; out . mX [ 33 ] = intrm_sf_mf_21 ? - 1.0 : intrm_sf_mf_20 ? - 1.0 :
intrm_sf_mf_19 ? - 1.0 : intrm_sf_mf_18 ? - 1.0 : intrm_sf_mf_17 ? 0.0 :
intrm_sf_mf_16 ? 0.0 : intrm_sf_mf_15 ? - 1.0 : 0.0 ; out . mX [ 34 ] =
intrm_sf_mf_21 ? 0.0 : intrm_sf_mf_20 ? 0.0 : intrm_sf_mf_19 ? 0.0 :
intrm_sf_mf_18 ? 0.0 : intrm_sf_mf_17 ? 0.0 : intrm_sf_mf_16 ? 1.0 :
intrm_sf_mf_15 ? 0.0 : ( real_T ) ! intrm_sf_mf_14 ; out . mX [ 35 ] =
intrm_sf_mf_21 ? 1.0 : intrm_sf_mf_20 ? 1.0 : intrm_sf_mf_19 ? 1.0 :
intrm_sf_mf_18 ? 1.0 : intrm_sf_mf_17 ? 0.0 : intrm_sf_mf_16 ? 0.0 : ( real_T
) intrm_sf_mf_15 ; ( void ) LC ; ( void ) t200 ; return 0 ; }

#include "ne_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_sys_struct.h"
#include "IGBTThermal_399ad5b0_1_ds_f.h"
#include "IGBTThermal_399ad5b0_1_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_externals.h"
#include "IGBTThermal_399ad5b0_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T IGBTThermal_399ad5b0_1_ds_f ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t65 , NeDsMethodOutput * t66 ) { ETTS8eaf4aba b_efOut
; ETTS8eaf4aba d_efOut ; ETTS8eaf4aba e_efOut ; ETTS8eaf4aba efOut ;
ETTS8eaf4aba t10 ; ETTS8eaf4aba t9 ; PmRealVector out ; real_T t1 [ 12 ] ;
real_T nonscalar5 [ 9 ] ; real_T nonscalar4 [ 3 ] ; real_T c_efOut [ 1 ] ;
real_T f_efOut [ 1 ] ; real_T t23 [ 1 ] ; real_T t27 [ 1 ] ; real_T t38 [ 1 ]
; real_T D_idx_1 ; real_T D_idx_2 ; real_T D_idx_8 ; real_T D_idx_9 ; real_T
X_idx_1 ; real_T X_idx_11 ; real_T X_idx_12 ; real_T X_idx_13 ; real_T
X_idx_14 ; real_T X_idx_15 ; real_T X_idx_16 ; real_T X_idx_17 ; real_T
X_idx_18 ; real_T X_idx_19 ; real_T X_idx_21 ; real_T X_idx_22 ; real_T
X_idx_25 ; real_T X_idx_3 ; real_T X_idx_4 ; real_T X_idx_7 ; real_T t14 ;
real_T t16 ; real_T t19 ; real_T t55 ; size_t t0 [ 14 ] ; size_t t22 [ 1 ] ;
size_t t24 [ 1 ] ; size_t t25 [ 1 ] ; size_t t28 [ 1 ] ; int32_T M_idx_32 ;
int32_T M_idx_33 ; int32_T Q_idx_0 ; int32_T Q_idx_1 ; boolean_T
intrm_sf_mf_10 ; boolean_T intrm_sf_mf_11 ; boolean_T intrm_sf_mf_12 ;
boolean_T intrm_sf_mf_13 ; boolean_T intrm_sf_mf_14 ; boolean_T
intrm_sf_mf_15 ; boolean_T intrm_sf_mf_16 ; boolean_T intrm_sf_mf_17 ;
boolean_T intrm_sf_mf_18 ; boolean_T intrm_sf_mf_19 ; boolean_T
intrm_sf_mf_20 ; boolean_T intrm_sf_mf_21 ; boolean_T intrm_sf_mf_6 ;
boolean_T intrm_sf_mf_7 ; boolean_T intrm_sf_mf_8 ; boolean_T intrm_sf_mf_9 ;
Q_idx_0 = t65 -> mQ . mX [ 0 ] ; Q_idx_1 = t65 -> mQ . mX [ 1 ] ; M_idx_32 =
t65 -> mM . mX [ 32 ] ; M_idx_33 = t65 -> mM . mX [ 33 ] ; X_idx_1 = t65 ->
mX . mX [ 1 ] ; X_idx_3 = t65 -> mX . mX [ 3 ] ; X_idx_4 = t65 -> mX . mX [ 4
] ; X_idx_7 = t65 -> mX . mX [ 7 ] ; X_idx_11 = t65 -> mX . mX [ 11 ] ;
X_idx_12 = t65 -> mX . mX [ 12 ] ; X_idx_13 = t65 -> mX . mX [ 13 ] ;
X_idx_14 = t65 -> mX . mX [ 14 ] ; X_idx_15 = t65 -> mX . mX [ 15 ] ;
X_idx_16 = t65 -> mX . mX [ 16 ] ; X_idx_17 = t65 -> mX . mX [ 17 ] ;
X_idx_18 = t65 -> mX . mX [ 18 ] ; X_idx_19 = t65 -> mX . mX [ 19 ] ;
X_idx_21 = t65 -> mX . mX [ 21 ] ; X_idx_22 = t65 -> mX . mX [ 22 ] ;
X_idx_25 = t65 -> mX . mX [ 25 ] ; D_idx_1 = t65 -> mD . mX [ 1 ] ; D_idx_2 =
t65 -> mD . mX [ 2 ] ; D_idx_8 = t65 -> mD . mX [ 8 ] ; D_idx_9 = t65 -> mD .
mX [ 9 ] ; out = t66 -> mF ; t1 [ 0 ] = 0.0 ; t1 [ 1 ] = 0.0 ; t1 [ 2 ] = 0.0
; t1 [ 3 ] = 0.0 ; t1 [ 4 ] = 0.0 ; t1 [ 5 ] = 0.0 ; t1 [ 6 ] = 0.0 ; t1 [ 7
] = 0.0 ; t1 [ 8 ] = 0.0 ; t1 [ 9 ] = 0.0 ; t1 [ 10 ] = 0.0 ; t1 [ 11 ] = 0.0
; t0 [ 0 ] = 0ULL ; t0 [ 1 ] = 0ULL ; t0 [ 2 ] = 0ULL ; t0 [ 3 ] = 0ULL ; t0
[ 4 ] = 0ULL ; t0 [ 5 ] = 0ULL ; t0 [ 6 ] = 0ULL ; t0 [ 7 ] = 0ULL ; t0 [ 8 ]
= 0ULL ; t0 [ 9 ] = 0ULL ; t0 [ 10 ] = 0ULL ; t0 [ 11 ] = 0ULL ; t0 [ 12 ] =
0ULL ; t0 [ 13 ] = 0ULL ; nonscalar4 [ 0 ] = 298.15 ; nonscalar4 [ 1 ] =
348.15 ; nonscalar4 [ 2 ] = 398.15 ; nonscalar5 [ 0 ] = - 0.2 ; nonscalar5 [
1 ] = - 0.1 ; nonscalar5 [ 2 ] = 0.0 ; nonscalar5 [ 3 ] = 10.0 ; nonscalar5 [
4 ] = 50.0 ; nonscalar5 [ 5 ] = 100.0 ; nonscalar5 [ 6 ] = 200.0 ; nonscalar5
[ 7 ] = 400.0 ; nonscalar5 [ 8 ] = 600.0 ; t14 = - X_idx_1 - X_idx_14 ; t16 =
- X_idx_3 - X_idx_17 ; t19 = - X_idx_4 + X_idx_7 ; t55 = - X_idx_12 +
X_idx_11 ; intrm_sf_mf_10 = ( ( size_t ) Q_idx_0 == 4ULL ) ; intrm_sf_mf_11 =
( ( size_t ) Q_idx_0 == 3ULL ) ; intrm_sf_mf_12 = ( ( size_t ) Q_idx_0 ==
2ULL ) ; intrm_sf_mf_13 = ( ( size_t ) Q_idx_0 == 1ULL ) ; intrm_sf_mf_14 = (
( size_t ) Q_idx_1 == 8ULL ) ; intrm_sf_mf_15 = ( ( size_t ) Q_idx_1 == 7ULL
) ; intrm_sf_mf_16 = ( ( size_t ) Q_idx_1 == 6ULL ) ; intrm_sf_mf_17 = ( (
size_t ) Q_idx_1 == 5ULL ) ; intrm_sf_mf_18 = ( ( size_t ) Q_idx_1 == 4ULL )
; intrm_sf_mf_19 = ( ( size_t ) Q_idx_1 == 3ULL ) ; intrm_sf_mf_20 = ( (
size_t ) Q_idx_1 == 2ULL ) ; intrm_sf_mf_21 = ( ( size_t ) Q_idx_1 == 1ULL )
; intrm_sf_mf_6 = ( ( size_t ) Q_idx_0 == 8ULL ) ; intrm_sf_mf_7 = ( ( size_t
) Q_idx_0 == 7ULL ) ; intrm_sf_mf_8 = ( ( size_t ) Q_idx_0 == 6ULL ) ;
intrm_sf_mf_9 = ( ( size_t ) Q_idx_0 == 5ULL ) ; t22 [ 0 ] = 0ULL ; t23 [
0ULL ] = X_idx_4 ; t24 [ 0 ] = 3ULL ; t25 [ 0 ] = 1ULL ;
tlu2_akima_linear_prelookup ( & efOut . mField0 [ 0ULL ] , & efOut . mField1
[ 0ULL ] , & t22 [ 0ULL ] , & nonscalar4 [ 0ULL ] , & t23 [ 0ULL ] , & t24 [
0ULL ] , & t25 [ 0ULL ] ) ; t10 = efOut ; t27 [ 0ULL ] = X_idx_17 ; t28 [ 0 ]
= 9ULL ; tlu2_akima_linear_prelookup ( & b_efOut . mField0 [ 0ULL ] , &
b_efOut . mField1 [ 0ULL ] , & t22 [ 0ULL ] , & nonscalar5 [ 0ULL ] , & t27 [
0ULL ] , & t28 [ 0ULL ] , & t25 [ 0ULL ] ) ; t9 = b_efOut ;
tlu2_2d_akima_linear_value ( & c_efOut [ 0ULL ] , & t10 . mField0 [ 0ULL ] ,
& t10 . mField1 [ 0ULL ] , & t9 . mField0 [ 0ULL ] , & t9 . mField1 [ 0ULL ]
, ( ( _NeDynamicSystem * ) ( LC ) ) -> mField1 , & t24 [ 0ULL ] , & t28 [
0ULL ] , & t1 [ 0ULL ] , & t0 [ 0ULL ] , & t25 [ 0ULL ] ) ; t27 [ 0 ] =
c_efOut [ 0 ] ; t38 [ 0ULL ] = X_idx_12 ; tlu2_akima_linear_prelookup ( &
d_efOut . mField0 [ 0ULL ] , & d_efOut . mField1 [ 0ULL ] , & t22 [ 0ULL ] ,
& nonscalar4 [ 0ULL ] , & t38 [ 0ULL ] , & t24 [ 0ULL ] , & t25 [ 0ULL ] ) ;
t10 = d_efOut ; t38 [ 0ULL ] = X_idx_14 ; tlu2_akima_linear_prelookup ( &
e_efOut . mField0 [ 0ULL ] , & e_efOut . mField1 [ 0ULL ] , & t22 [ 0ULL ] ,
& nonscalar5 [ 0ULL ] , & t38 [ 0ULL ] , & t28 [ 0ULL ] , & t25 [ 0ULL ] ) ;
t9 = e_efOut ; tlu2_2d_akima_linear_value ( & f_efOut [ 0ULL ] , & t10 .
mField0 [ 0ULL ] , & t10 . mField1 [ 0ULL ] , & t9 . mField0 [ 0ULL ] , & t9
. mField1 [ 0ULL ] , ( ( _NeDynamicSystem * ) ( LC ) ) -> mField1 , & t24 [
0ULL ] , & t28 [ 0ULL ] , & t1 [ 0ULL ] , & t0 [ 0ULL ] , & t25 [ 0ULL ] ) ;
t23 [ 0 ] = f_efOut [ 0 ] ; if ( M_idx_32 != 0 ) { X_idx_12 = ( X_idx_13 -
600.0 ) - ( X_idx_15 + 0.8 ) ; } else { X_idx_12 = ( X_idx_13 - 600.0 ) - (
X_idx_15 * 0.001 + 0.8 ) ; } if ( M_idx_32 != 0 ) { X_idx_4 = t14 - (
X_idx_15 * 1.0E-5 + 8.0000000000000013E-6 ) ; } else { X_idx_4 = t14 - (
X_idx_15 + 8.0000000000000013E-6 ) ; } if ( M_idx_33 != 0 ) { t14 = (
X_idx_16 - 600.0 ) - ( X_idx_18 + 0.8 ) ; } else { t14 = ( X_idx_16 - 600.0 )
- ( X_idx_18 * 0.001 + 0.8 ) ; } if ( M_idx_33 != 0 ) { X_idx_7 = t16 - (
X_idx_18 * 1.0E-5 + 8.0000000000000013E-6 ) ; } else { X_idx_7 = t16 - (
X_idx_18 + 8.0000000000000013E-6 ) ; } if ( intrm_sf_mf_13 ) { t16 = X_idx_17
- X_idx_16 * 1.0E-5 ; } else if ( intrm_sf_mf_12 ) { t16 = X_idx_17 -
X_idx_16 * 1.0E-5 ; } else if ( intrm_sf_mf_11 ) { t16 = X_idx_16 - t27 [
0ULL ] ; } else if ( intrm_sf_mf_10 ) { t16 = X_idx_16 - t27 [ 0ULL ] ; }
else if ( intrm_sf_mf_9 ) { t16 = X_idx_16 - t27 [ 0ULL ] ; } else if (
intrm_sf_mf_8 ) { t16 = X_idx_16 - t27 [ 0ULL ] ; } else { t16 = X_idx_17 -
X_idx_16 * 1.0E-5 ; } if ( intrm_sf_mf_13 ) { X_idx_11 = X_idx_19 ; } else if
( intrm_sf_mf_12 ) { X_idx_11 = X_idx_19 ; } else if ( intrm_sf_mf_11 ) {
X_idx_11 = X_idx_19 ; } else if ( intrm_sf_mf_10 ) { X_idx_11 = X_idx_19 ; }
else if ( intrm_sf_mf_9 ) { X_idx_11 = X_idx_19 ; } else if ( intrm_sf_mf_8 )
{ X_idx_11 = X_idx_21 - X_idx_19 ; } else if ( intrm_sf_mf_7 ) { X_idx_11 =
X_idx_19 ; } else if ( intrm_sf_mf_6 ) { X_idx_11 = X_idx_19 ; } else {
X_idx_11 = X_idx_21 - X_idx_19 ; } if ( intrm_sf_mf_13 ) { X_idx_1 = X_idx_21
- X_idx_19 ; } else if ( intrm_sf_mf_12 ) { X_idx_1 = X_idx_21 - X_idx_19 ; }
else if ( intrm_sf_mf_11 ) { X_idx_1 = X_idx_21 - X_idx_19 ; } else if (
intrm_sf_mf_10 ) { X_idx_1 = X_idx_21 - X_idx_19 ; } else if ( intrm_sf_mf_9
) { X_idx_1 = t19 - D_idx_2 / 2.6115107913669061E-7 ; } else if (
intrm_sf_mf_8 ) { X_idx_1 = t19 ; } else if ( intrm_sf_mf_7 ) { X_idx_1 =
X_idx_21 - X_idx_19 ; } else if ( intrm_sf_mf_6 ) { X_idx_1 = t19 - D_idx_1 /
2.6115107913669061E-7 ; } else { X_idx_1 = t19 ; } if ( intrm_sf_mf_21 ) {
t19 = X_idx_14 - X_idx_13 * 1.0E-5 ; } else if ( intrm_sf_mf_20 ) { t19 =
X_idx_14 - X_idx_13 * 1.0E-5 ; } else if ( intrm_sf_mf_19 ) { t19 = X_idx_13
- t23 [ 0ULL ] ; } else if ( intrm_sf_mf_18 ) { t19 = X_idx_13 - t23 [ 0ULL ]
; } else if ( intrm_sf_mf_17 ) { t19 = X_idx_13 - t23 [ 0ULL ] ; } else if (
intrm_sf_mf_16 ) { t19 = X_idx_13 - t23 [ 0ULL ] ; } else { t19 = X_idx_14 -
X_idx_13 * 1.0E-5 ; } if ( intrm_sf_mf_21 ) { X_idx_3 = X_idx_22 ; } else if
( intrm_sf_mf_20 ) { X_idx_3 = X_idx_22 ; } else if ( intrm_sf_mf_19 ) {
X_idx_3 = X_idx_22 ; } else if ( intrm_sf_mf_18 ) { X_idx_3 = X_idx_22 ; }
else if ( intrm_sf_mf_17 ) { X_idx_3 = X_idx_22 ; } else if ( intrm_sf_mf_16
) { X_idx_3 = X_idx_25 - X_idx_22 ; } else if ( intrm_sf_mf_15 ) { X_idx_3 =
X_idx_22 ; } else if ( intrm_sf_mf_14 ) { X_idx_3 = X_idx_22 ; } else {
X_idx_3 = X_idx_25 - X_idx_22 ; } if ( intrm_sf_mf_21 ) { t55 = X_idx_25 -
X_idx_22 ; } else if ( intrm_sf_mf_20 ) { t55 = X_idx_25 - X_idx_22 ; } else
if ( intrm_sf_mf_19 ) { t55 = X_idx_25 - X_idx_22 ; } else if (
intrm_sf_mf_18 ) { t55 = X_idx_25 - X_idx_22 ; } else if ( intrm_sf_mf_17 ) {
t55 -= D_idx_9 / 6.25E-7 ; } else if ( intrm_sf_mf_16 ) { } else if (
intrm_sf_mf_15 ) { t55 = X_idx_25 - X_idx_22 ; } else if ( intrm_sf_mf_14 ) {
t55 -= D_idx_8 / 6.25E-7 ; } out . mX [ 0 ] = - 0.0 ; out . mX [ 1 ] = 600.0
; out . mX [ 2 ] = - 0.0 ; out . mX [ 3 ] = 600.0 ; out . mX [ 4 ] = - 0.0 ;
out . mX [ 5 ] = - 0.0 ; out . mX [ 6 ] = - 36.269430051813472 ; out . mX [ 7
] = - 0.0 ; out . mX [ 8 ] = - 0.0 ; out . mX [ 9 ] = - 0.0 ; out . mX [ 10 ]
= - 0.0 ; out . mX [ 11 ] = - 36.250000000000085 ; out . mX [ 12 ] = - 0.0 ;
out . mX [ 13 ] = X_idx_12 ; out . mX [ 14 ] = X_idx_4 ; out . mX [ 15 ] =
t14 ; out . mX [ 16 ] = X_idx_7 ; out . mX [ 17 ] = - ( X_idx_16 * X_idx_17 *
0.001 ) ; out . mX [ 18 ] = t16 ; out . mX [ 19 ] = X_idx_11 ; out . mX [ 20
] = X_idx_1 ; out . mX [ 21 ] = 0.0 ; out . mX [ 22 ] = - ( X_idx_13 *
X_idx_14 * 0.001 ) ; out . mX [ 23 ] = t19 ; out . mX [ 24 ] = X_idx_3 ; out
. mX [ 25 ] = t55 ; ( void ) LC ; ( void ) t66 ; return 0 ; }

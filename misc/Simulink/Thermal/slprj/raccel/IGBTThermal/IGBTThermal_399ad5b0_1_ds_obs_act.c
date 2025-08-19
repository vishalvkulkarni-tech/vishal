#include "ne_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_sys_struct.h"
#include "IGBTThermal_399ad5b0_1_ds_obs_act.h"
#include "IGBTThermal_399ad5b0_1_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_externals.h"
#include "IGBTThermal_399ad5b0_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T IGBTThermal_399ad5b0_1_ds_obs_act ( const NeDynamicSystem * LC ,
const NeDynamicSystemInput * t26 , NeDsMethodOutput * t27 ) { PmRealVector
out ; real_T t0 [ 201 ] ; real_T Buck_circuit_1_Diode_i_diode ; real_T
Buck_circuit_1_Load_i ; real_T Buck_circuit_2_Diode_i_diode ; real_T
Buck_circuit_2_Load_i ; real_T D_idx_0 ; real_T D_idx_1 ; real_T D_idx_10 ;
real_T D_idx_11 ; real_T D_idx_12 ; real_T D_idx_13 ; real_T D_idx_2 ; real_T
D_idx_3 ; real_T D_idx_4 ; real_T D_idx_5 ; real_T D_idx_6 ; real_T D_idx_7 ;
real_T D_idx_8 ; real_T D_idx_9 ; real_T IGBT_C_Qj ; real_T U_idx_0 ; real_T
X_idx_0 ; real_T X_idx_1 ; real_T X_idx_10 ; real_T X_idx_11 ; real_T
X_idx_12 ; real_T X_idx_13 ; real_T X_idx_14 ; real_T X_idx_15 ; real_T
X_idx_16 ; real_T X_idx_17 ; real_T X_idx_18 ; real_T X_idx_19 ; real_T
X_idx_2 ; real_T X_idx_20 ; real_T X_idx_21 ; real_T X_idx_22 ; real_T
X_idx_23 ; real_T X_idx_24 ; real_T X_idx_25 ; real_T X_idx_3 ; real_T
X_idx_4 ; real_T X_idx_5 ; real_T X_idx_6 ; real_T X_idx_7 ; real_T X_idx_8 ;
real_T X_idx_9 ; real_T piece11 ; real_T piece9 ; real_T t25 ; int32_T
Q_idx_0 ; int32_T Q_idx_1 ; ( void ) LC ; Q_idx_0 = t26 -> mQ . mX [ 0 ] ;
Q_idx_1 = t26 -> mQ . mX [ 1 ] ; U_idx_0 = t26 -> mU . mX [ 0 ] ; X_idx_0 =
t26 -> mX . mX [ 0 ] ; X_idx_1 = t26 -> mX . mX [ 1 ] ; X_idx_2 = t26 -> mX .
mX [ 2 ] ; X_idx_3 = t26 -> mX . mX [ 3 ] ; X_idx_4 = t26 -> mX . mX [ 4 ] ;
X_idx_5 = t26 -> mX . mX [ 5 ] ; X_idx_6 = t26 -> mX . mX [ 6 ] ; X_idx_7 =
t26 -> mX . mX [ 7 ] ; X_idx_8 = t26 -> mX . mX [ 8 ] ; X_idx_9 = t26 -> mX .
mX [ 9 ] ; X_idx_10 = t26 -> mX . mX [ 10 ] ; X_idx_11 = t26 -> mX . mX [ 11
] ; X_idx_12 = t26 -> mX . mX [ 12 ] ; X_idx_13 = t26 -> mX . mX [ 13 ] ;
X_idx_14 = t26 -> mX . mX [ 14 ] ; X_idx_15 = t26 -> mX . mX [ 15 ] ;
X_idx_16 = t26 -> mX . mX [ 16 ] ; X_idx_17 = t26 -> mX . mX [ 17 ] ;
X_idx_18 = t26 -> mX . mX [ 18 ] ; X_idx_19 = t26 -> mX . mX [ 19 ] ;
X_idx_20 = t26 -> mX . mX [ 20 ] ; X_idx_21 = t26 -> mX . mX [ 21 ] ;
X_idx_22 = t26 -> mX . mX [ 22 ] ; X_idx_23 = t26 -> mX . mX [ 23 ] ;
X_idx_24 = t26 -> mX . mX [ 24 ] ; X_idx_25 = t26 -> mX . mX [ 25 ] ; D_idx_0
= t26 -> mD . mX [ 0 ] ; D_idx_1 = t26 -> mD . mX [ 1 ] ; D_idx_2 = t26 -> mD
. mX [ 2 ] ; D_idx_3 = t26 -> mD . mX [ 3 ] ; D_idx_4 = t26 -> mD . mX [ 4 ]
; D_idx_5 = t26 -> mD . mX [ 5 ] ; D_idx_6 = t26 -> mD . mX [ 6 ] ; D_idx_7 =
t26 -> mD . mX [ 7 ] ; D_idx_8 = t26 -> mD . mX [ 8 ] ; D_idx_9 = t26 -> mD .
mX [ 9 ] ; D_idx_10 = t26 -> mD . mX [ 10 ] ; D_idx_11 = t26 -> mD . mX [ 11
] ; D_idx_12 = t26 -> mD . mX [ 12 ] ; D_idx_13 = t26 -> mD . mX [ 13 ] ; out
= t27 -> mOBS_ACT ; Buck_circuit_1_Diode_i_diode = - X_idx_1 - X_idx_14 ;
Buck_circuit_1_Load_i = X_idx_0 * 0.083333333333333329 ;
Buck_circuit_2_Diode_i_diode = - X_idx_3 - X_idx_17 ; Buck_circuit_2_Load_i =
X_idx_2 * 0.083333333333333329 ; IGBT_C_Qj = ( ( X_idx_4 *
0.0035971223021582731 + X_idx_5 * - 0.0035971223021582731 ) + X_idx_19 ) +
X_idx_20 ; t25 = ( ( ( X_idx_8 * 0.0035916824196597346 + X_idx_9 * -
0.0035916824196597346 ) + X_idx_22 ) + X_idx_23 ) + X_idx_24 ; piece9 =
X_idx_6 * - 0.051813471502590677 ; piece11 = X_idx_10 * -
0.051785714285714407 ; t0 [ 0ULL ] = X_idx_0 * - 0.083333333333333329 -
X_idx_1 ; t0 [ 1ULL ] = - X_idx_0 + 600.0 ; t0 [ 2ULL ] = 600.0 ; t0 [ 3ULL ]
= X_idx_0 ; t0 [ 4ULL ] = X_idx_0 ; t0 [ 5ULL ] = X_idx_13 ; t0 [ 6ULL ] = -
1.0 ; t0 [ 7ULL ] = 600.0 ; t0 [ 8ULL ] = 298.15 ; t0 [ 9ULL ] = 298.15 ; t0
[ 10ULL ] = 0.0 ; t0 [ 11ULL ] = 0.0 ; t0 [ 12ULL ] =
Buck_circuit_1_Diode_i_diode ; t0 [ 13ULL ] = 0.0 ; t0 [ 14ULL ] =
Buck_circuit_1_Diode_i_diode ; t0 [ 15ULL ] = Buck_circuit_1_Diode_i_diode ;
t0 [ 16ULL ] = X_idx_13 - 600.0 ; t0 [ 17ULL ] = 600.0 ; t0 [ 18ULL ] =
X_idx_13 ; t0 [ 19ULL ] = Buck_circuit_1_Diode_i_diode * ( X_idx_13 - 600.0 )
* 0.001 * 1000.0 ; t0 [ 20ULL ] = X_idx_15 ; t0 [ 21ULL ] = X_idx_13 - 600.0
; t0 [ 22ULL ] = 0.0 ; t0 [ 23ULL ] = U_idx_0 ; t0 [ 24ULL ] = U_idx_0 ; t0 [
25ULL ] = 0.0 ; t0 [ 26ULL ] = X_idx_1 ; t0 [ 27ULL ] = - X_idx_0 + 600.0 ;
t0 [ 28ULL ] = X_idx_13 ; t0 [ 29ULL ] = ( X_idx_0 + X_idx_13 ) - 600.0 ; t0
[ 30ULL ] = X_idx_1 ; t0 [ 31ULL ] = Buck_circuit_1_Load_i ; t0 [ 32ULL ] = -
X_idx_0 + 600.0 ; t0 [ 33ULL ] = 600.0 ; t0 [ 34ULL ] = Buck_circuit_1_Load_i
* 12.0 ; t0 [ 35ULL ] = 0.0 ; t0 [ 36ULL ] = 0.0 ; t0 [ 37ULL ] = U_idx_0 ;
t0 [ 38ULL ] = U_idx_0 ; t0 [ 39ULL ] = U_idx_0 ; t0 [ 40ULL ] = - X_idx_14 ;
t0 [ 41ULL ] = 0.0 ; t0 [ 42ULL ] = 600.0 ; t0 [ 43ULL ] = 600.0 ; t0 [ 44ULL
] = X_idx_2 * - 0.083333333333333329 - X_idx_3 ; t0 [ 45ULL ] = - X_idx_2 +
600.0 ; t0 [ 46ULL ] = 600.0 ; t0 [ 47ULL ] = X_idx_2 ; t0 [ 48ULL ] =
X_idx_2 ; t0 [ 49ULL ] = X_idx_16 ; t0 [ 50ULL ] = - 1.0 ; t0 [ 51ULL ] =
600.0 ; t0 [ 52ULL ] = 298.15 ; t0 [ 53ULL ] = 298.15 ; t0 [ 54ULL ] = 0.0 ;
t0 [ 55ULL ] = 0.0 ; t0 [ 56ULL ] = Buck_circuit_2_Diode_i_diode ; t0 [ 57ULL
] = 0.0 ; t0 [ 58ULL ] = Buck_circuit_2_Diode_i_diode ; t0 [ 59ULL ] =
Buck_circuit_2_Diode_i_diode ; t0 [ 60ULL ] = X_idx_16 - 600.0 ; t0 [ 61ULL ]
= 600.0 ; t0 [ 62ULL ] = X_idx_16 ; t0 [ 63ULL ] =
Buck_circuit_2_Diode_i_diode * ( X_idx_16 - 600.0 ) * 0.001 * 1000.0 ; t0 [
64ULL ] = X_idx_18 ; t0 [ 65ULL ] = X_idx_16 - 600.0 ; t0 [ 66ULL ] = 0.0 ;
t0 [ 67ULL ] = U_idx_0 ; t0 [ 68ULL ] = U_idx_0 ; t0 [ 69ULL ] = 0.0 ; t0 [
70ULL ] = X_idx_3 ; t0 [ 71ULL ] = - X_idx_2 + 600.0 ; t0 [ 72ULL ] =
X_idx_16 ; t0 [ 73ULL ] = ( X_idx_2 + X_idx_16 ) - 600.0 ; t0 [ 74ULL ] =
X_idx_3 ; t0 [ 75ULL ] = Buck_circuit_2_Load_i ; t0 [ 76ULL ] = - X_idx_2 +
600.0 ; t0 [ 77ULL ] = 600.0 ; t0 [ 78ULL ] = Buck_circuit_2_Load_i * 12.0 ;
t0 [ 79ULL ] = 0.0 ; t0 [ 80ULL ] = 0.0 ; t0 [ 81ULL ] = U_idx_0 ; t0 [ 82ULL
] = U_idx_0 ; t0 [ 83ULL ] = U_idx_0 ; t0 [ 84ULL ] = - X_idx_17 ; t0 [ 85ULL
] = 0.0 ; t0 [ 86ULL ] = 600.0 ; t0 [ 87ULL ] = 600.0 ; t0 [ 88ULL ] = 0.0 ;
t0 [ 89ULL ] = 0.0 ; t0 [ 90ULL ] = X_idx_16 ; t0 [ 91ULL ] = 0.0 ; t0 [
92ULL ] = 0.0 ; t0 [ 93ULL ] = U_idx_0 ; t0 [ 94ULL ] = 700.0 ; t0 [ 95ULL ]
= X_idx_4 ; t0 [ 96ULL ] = X_idx_4 ; t0 [ 97ULL ] = X_idx_19 * 1000.0 ; t0 [
98ULL ] = IGBT_C_Qj * 1000.0 ; t0 [ 99ULL ] = X_idx_21 * 1000.0 ; t0 [ 100ULL
] = X_idx_7 ; t0 [ 101ULL ] = D_idx_0 ; t0 [ 102ULL ] = - X_idx_4 + X_idx_7 ;
t0 [ 103ULL ] = X_idx_17 ; t0 [ 104ULL ] = X_idx_17 ; t0 [ 105ULL ] = X_idx_4
- 273.15 ; t0 [ 106ULL ] = D_idx_1 ; t0 [ 107ULL ] = D_idx_2 ; t0 [ 108ULL ]
= IGBT_C_Qj * 1000.0 ; t0 [ 109ULL ] = X_idx_4 ; t0 [ 110ULL ] = 700.0 ; t0 [
111ULL ] = ( ( X_idx_4 * 0.0035971223021582731 + X_idx_5 * -
0.0035971223021582731 ) + X_idx_20 ) * 1000.0 ; t0 [ 112ULL ] = ( X_idx_4 *
0.0035971223021582731 + X_idx_5 * - 0.0035971223021582731 ) * 1000.0 ; t0 [
113ULL ] = ( X_idx_5 * 0.019120458891013385 + X_idx_6 * -
0.019120458891013385 ) * 1000.0 ; t0 [ 114ULL ] = ( X_idx_6 *
0.051813471502590677 - 36.269430051813472 ) * 1000.0 ; t0 [ 115ULL ] =
X_idx_20 * 1000.0 ; t0 [ 116ULL ] = ( ( X_idx_4 * 0.0035971223021582731 +
X_idx_5 * - 0.022717581193171656 ) + X_idx_6 * 0.019120458891013385 ) *
1000.0 ; t0 [ 117ULL ] = ( ( X_idx_5 * 0.019120458891013385 + X_idx_6 * -
0.070933930393604058 ) + 36.269430051813472 ) * 1000.0 ; t0 [ 118ULL ] =
36269.43005181347 + piece9 * 1000.0 ; t0 [ 119ULL ] = X_idx_4 ; t0 [ 120ULL ]
= X_idx_5 ; t0 [ 121ULL ] = X_idx_6 ; t0 [ 122ULL ] = X_idx_16 ; t0 [ 123ULL
] = U_idx_0 ; t0 [ 124ULL ] = X_idx_16 ; t0 [ 125ULL ] = U_idx_0 ; t0 [
126ULL ] = D_idx_3 ; t0 [ 127ULL ] = D_idx_4 ; t0 [ 128ULL ] = D_idx_5 ; t0 [
129ULL ] = D_idx_6 ; t0 [ 130ULL ] = ( real_T ) ( size_t ) Q_idx_0 ; t0 [
131ULL ] = X_idx_13 ; t0 [ 132ULL ] = 0.0 ; t0 [ 133ULL ] = 0.0 ; t0 [ 134ULL
] = U_idx_0 ; t0 [ 135ULL ] = 700.0 ; t0 [ 136ULL ] = X_idx_12 ; t0 [ 137ULL
] = X_idx_12 ; t0 [ 138ULL ] = X_idx_22 * 1000.0 ; t0 [ 139ULL ] = t25 *
1000.0 ; t0 [ 140ULL ] = X_idx_25 * 1000.0 ; t0 [ 141ULL ] = X_idx_11 ; t0 [
142ULL ] = D_idx_7 ; t0 [ 143ULL ] = - X_idx_12 + X_idx_11 ; t0 [ 144ULL ] =
X_idx_14 ; t0 [ 145ULL ] = X_idx_14 ; t0 [ 146ULL ] = X_idx_12 - 273.15 ; t0
[ 147ULL ] = D_idx_8 ; t0 [ 148ULL ] = D_idx_9 ; t0 [ 149ULL ] = X_idx_12 ;
t0 [ 150ULL ] = X_idx_23 * 1000.0 ; t0 [ 151ULL ] = X_idx_12 ; t0 [ 152ULL ]
= t25 * 1000.0 ; t0 [ 153ULL ] = X_idx_12 ; t0 [ 154ULL ] = 700.0 ; t0 [
155ULL ] = ( ( X_idx_8 * 0.0035916824196597346 + X_idx_9 * -
0.0035916824196597346 ) + X_idx_24 ) * 1000.0 ; t0 [ 156ULL ] = ( X_idx_8 *
0.0035916824196597346 + X_idx_9 * - 0.0035916824196597346 ) * 1000.0 ; t0 [
157ULL ] = ( X_idx_9 * 0.019131944444444448 + X_idx_10 * -
0.019131944444444448 ) * 1000.0 ; t0 [ 158ULL ] = ( X_idx_10 *
0.051785714285714407 - 36.250000000000085 ) * 1000.0 ; t0 [ 159ULL ] =
X_idx_24 * 1000.0 ; t0 [ 160ULL ] = ( ( X_idx_8 * 0.0035916824196597346 +
X_idx_9 * - 0.022723626864104181 ) + X_idx_10 * 0.019131944444444448 ) *
1000.0 ; t0 [ 161ULL ] = ( ( X_idx_9 * 0.019131944444444448 + X_idx_10 * -
0.070917658730158858 ) + 36.250000000000085 ) * 1000.0 ; t0 [ 162ULL ] =
36250.000000000087 + piece11 * 1000.0 ; t0 [ 163ULL ] = X_idx_8 ; t0 [ 164ULL
] = X_idx_9 ; t0 [ 165ULL ] = X_idx_10 ; t0 [ 166ULL ] = X_idx_13 ; t0 [
167ULL ] = U_idx_0 ; t0 [ 168ULL ] = X_idx_13 ; t0 [ 169ULL ] = U_idx_0 ; t0
[ 170ULL ] = D_idx_10 ; t0 [ 171ULL ] = D_idx_11 ; t0 [ 172ULL ] = D_idx_12 ;
t0 [ 173ULL ] = D_idx_13 ; t0 [ 174ULL ] = ( real_T ) ( size_t ) Q_idx_1 ; t0
[ 175ULL ] = U_idx_0 ; t0 [ 176ULL ] = U_idx_0 ; t0 [ 177ULL ] = 0.0 ; t0 [
178ULL ] = U_idx_0 ; t0 [ 179ULL ] = U_idx_0 ; t0 [ 180ULL ] = 0.0 ; t0 [
181ULL ] = 0.0 ; t0 [ 182ULL ] = U_idx_0 ; t0 [ 183ULL ] = U_idx_0 ; t0 [
184ULL ] = 0.0 ; t0 [ 185ULL ] = 700.0 ; t0 [ 186ULL ] = 0.0 ; t0 [ 187ULL ]
= 700.0 ; t0 [ 188ULL ] = - 36269.43005181347 + piece9 * - 1000.0 ; t0 [
189ULL ] = 700.0 ; t0 [ 190ULL ] = 700.0 ; t0 [ 191ULL ] = 700.0 ; t0 [
192ULL ] = 0.0 ; t0 [ 193ULL ] = 700.0 ; t0 [ 194ULL ] = 0.0 ; t0 [ 195ULL ]
= 700.0 ; t0 [ 196ULL ] = - 36250.000000000087 + piece11 * - 1000.0 ; t0 [
197ULL ] = 700.0 ; t0 [ 198ULL ] = 700.0 ; t0 [ 199ULL ] = 700.0 ; t0 [
200ULL ] = 0.0 ; for ( Q_idx_0 = 0 ; Q_idx_0 < 201 ; Q_idx_0 ++ ) { out . mX
[ Q_idx_0 ] = t0 [ Q_idx_0 ] ; } ( void ) LC ; ( void ) t27 ; return 0 ; }

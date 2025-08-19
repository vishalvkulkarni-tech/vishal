#include "ne_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_sys_struct.h"
#include "IGBTThermal_399ad5b0_1_ds_obs_exp.h"
#include "IGBTThermal_399ad5b0_1_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_externals.h"
#include "IGBTThermal_399ad5b0_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T IGBTThermal_399ad5b0_1_ds_obs_exp ( const NeDynamicSystem * LC ,
const NeDynamicSystemInput * t8 , NeDsMethodOutput * t9 ) { PmRealVector out
; real_T t0 [ 201 ] ; real_T P_R_idx_0 ; real_T P_R_idx_1 ; real_T P_R_idx_2
; real_T P_R_idx_3 ; real_T P_R_idx_4 ; real_T P_R_idx_5 ; int32_T b ; ( void
) LC ; P_R_idx_0 = t8 -> mP_R . mX [ 0 ] ; P_R_idx_1 = t8 -> mP_R . mX [ 1 ]
; P_R_idx_2 = t8 -> mP_R . mX [ 2 ] ; P_R_idx_3 = t8 -> mP_R . mX [ 3 ] ;
P_R_idx_4 = t8 -> mP_R . mX [ 4 ] ; P_R_idx_5 = t8 -> mP_R . mX [ 5 ] ; out =
t9 -> mOBS_EXP ; t0 [ 0ULL ] = 0.0 ; t0 [ 1ULL ] = 0.0 ; t0 [ 2ULL ] = 0.0 ;
t0 [ 3ULL ] = 0.0 ; t0 [ 4ULL ] = P_R_idx_0 ; t0 [ 5ULL ] = 0.0 ; t0 [ 6ULL ]
= 1.0 ; t0 [ 7ULL ] = 0.0 ; t0 [ 8ULL ] = 298.15 ; t0 [ 9ULL ] = 298.15 ; t0
[ 10ULL ] = 0.0 ; t0 [ 11ULL ] = 0.0 ; t0 [ 12ULL ] = 0.0 ; t0 [ 13ULL ] =
0.0 ; t0 [ 14ULL ] = 0.0 ; t0 [ 15ULL ] = 0.0 ; t0 [ 16ULL ] = 0.0 ; t0 [
17ULL ] = 0.0 ; t0 [ 18ULL ] = 0.0 ; t0 [ 19ULL ] = 0.0 ; t0 [ 20ULL ] = 0.0
; t0 [ 21ULL ] = 0.0 ; t0 [ 22ULL ] = 0.0 ; t0 [ 23ULL ] = 0.0 ; t0 [ 24ULL ]
= 0.0 ; t0 [ 25ULL ] = 0.0 ; t0 [ 26ULL ] = 0.0 ; t0 [ 27ULL ] = 0.0 ; t0 [
28ULL ] = 0.0 ; t0 [ 29ULL ] = 0.0 ; t0 [ 30ULL ] = P_R_idx_1 ; t0 [ 31ULL ]
= 0.0 ; t0 [ 32ULL ] = 0.0 ; t0 [ 33ULL ] = 0.0 ; t0 [ 34ULL ] = 0.0 ; t0 [
35ULL ] = 0.0 ; t0 [ 36ULL ] = 0.0 ; t0 [ 37ULL ] = 0.0 ; t0 [ 38ULL ] = 0.0
; t0 [ 39ULL ] = 0.0 ; t0 [ 40ULL ] = 0.0 ; t0 [ 41ULL ] = 0.0 ; t0 [ 42ULL ]
= 0.0 ; t0 [ 43ULL ] = 0.0 ; t0 [ 44ULL ] = 0.0 ; t0 [ 45ULL ] = 0.0 ; t0 [
46ULL ] = 0.0 ; t0 [ 47ULL ] = 0.0 ; t0 [ 48ULL ] = P_R_idx_2 ; t0 [ 49ULL ]
= 0.0 ; t0 [ 50ULL ] = 1.0 ; t0 [ 51ULL ] = 0.0 ; t0 [ 52ULL ] = 298.15 ; t0
[ 53ULL ] = 298.15 ; t0 [ 54ULL ] = 0.0 ; t0 [ 55ULL ] = 0.0 ; t0 [ 56ULL ] =
0.0 ; t0 [ 57ULL ] = 0.0 ; t0 [ 58ULL ] = 0.0 ; t0 [ 59ULL ] = 0.0 ; t0 [
60ULL ] = 0.0 ; t0 [ 61ULL ] = 0.0 ; t0 [ 62ULL ] = 0.0 ; t0 [ 63ULL ] = 0.0
; t0 [ 64ULL ] = 0.0 ; t0 [ 65ULL ] = 0.0 ; t0 [ 66ULL ] = 0.0 ; t0 [ 67ULL ]
= 0.0 ; t0 [ 68ULL ] = 0.0 ; t0 [ 69ULL ] = 0.0 ; t0 [ 70ULL ] = 0.0 ; t0 [
71ULL ] = 0.0 ; t0 [ 72ULL ] = 0.0 ; t0 [ 73ULL ] = 0.0 ; t0 [ 74ULL ] =
P_R_idx_3 ; t0 [ 75ULL ] = 0.0 ; t0 [ 76ULL ] = 0.0 ; t0 [ 77ULL ] = 0.0 ; t0
[ 78ULL ] = 0.0 ; t0 [ 79ULL ] = 0.0 ; t0 [ 80ULL ] = 0.0 ; t0 [ 81ULL ] =
0.0 ; t0 [ 82ULL ] = 0.0 ; t0 [ 83ULL ] = 0.0 ; t0 [ 84ULL ] = 0.0 ; t0 [
85ULL ] = 0.0 ; t0 [ 86ULL ] = 0.0 ; t0 [ 87ULL ] = 0.0 ; t0 [ 88ULL ] = 0.0
; t0 [ 89ULL ] = 0.0 ; t0 [ 90ULL ] = 0.0 ; t0 [ 91ULL ] = 0.0 ; t0 [ 92ULL ]
= 0.0 ; t0 [ 93ULL ] = 0.0 ; t0 [ 94ULL ] = 293.15 ; t0 [ 95ULL ] = 293.15 ;
t0 [ 96ULL ] = 293.15 ; t0 [ 97ULL ] = 0.0 ; t0 [ 98ULL ] = 0.0 ; t0 [ 99ULL
] = 0.0 ; t0 [ 100ULL ] = 300.0 ; t0 [ 101ULL ] = 0.0 ; t0 [ 102ULL ] = 0.0 ;
t0 [ 103ULL ] = 0.0 ; t0 [ 104ULL ] = 0.0 ; t0 [ 105ULL ] = P_R_idx_5 ; t0 [
106ULL ] = 0.0 ; t0 [ 107ULL ] = 0.0 ; t0 [ 108ULL ] = 0.0 ; t0 [ 109ULL ] =
293.15 ; t0 [ 110ULL ] = 293.15 ; t0 [ 111ULL ] = 0.0 ; t0 [ 112ULL ] = 0.0 ;
t0 [ 113ULL ] = 0.0 ; t0 [ 114ULL ] = 0.0 ; t0 [ 115ULL ] = 0.0 ; t0 [ 116ULL
] = 0.0 ; t0 [ 117ULL ] = 0.0 ; t0 [ 118ULL ] = 0.0 ; t0 [ 119ULL ] = 298.15
; t0 [ 120ULL ] = 298.15 ; t0 [ 121ULL ] = 298.15 ; t0 [ 122ULL ] = 0.0 ; t0
[ 123ULL ] = 0.0 ; t0 [ 124ULL ] = 0.0 ; t0 [ 125ULL ] = 0.0 ; t0 [ 126ULL ]
= 0.0 ; t0 [ 127ULL ] = 0.0 ; t0 [ 128ULL ] = 0.0 ; t0 [ 129ULL ] = 0.0 ; t0
[ 130ULL ] = 1.0 ; t0 [ 131ULL ] = 0.0 ; t0 [ 132ULL ] = 0.0 ; t0 [ 133ULL ]
= 0.0 ; t0 [ 134ULL ] = 0.0 ; t0 [ 135ULL ] = 293.15 ; t0 [ 136ULL ] = 293.15
; t0 [ 137ULL ] = 293.15 ; t0 [ 138ULL ] = 0.0 ; t0 [ 139ULL ] = 0.0 ; t0 [
140ULL ] = 0.0 ; t0 [ 141ULL ] = 300.0 ; t0 [ 142ULL ] = 0.0 ; t0 [ 143ULL ]
= 0.0 ; t0 [ 144ULL ] = 0.0 ; t0 [ 145ULL ] = 0.0 ; t0 [ 146ULL ] = P_R_idx_4
; t0 [ 147ULL ] = 0.0 ; t0 [ 148ULL ] = 0.0 ; t0 [ 149ULL ] = 293.15 ; t0 [
150ULL ] = 0.0 ; t0 [ 151ULL ] = 300.0 ; t0 [ 152ULL ] = 0.0 ; t0 [ 153ULL ]
= 293.15 ; t0 [ 154ULL ] = 293.15 ; t0 [ 155ULL ] = 0.0 ; t0 [ 156ULL ] = 0.0
; t0 [ 157ULL ] = 0.0 ; t0 [ 158ULL ] = 0.0 ; t0 [ 159ULL ] = 0.0 ; t0 [
160ULL ] = 0.0 ; t0 [ 161ULL ] = 0.0 ; t0 [ 162ULL ] = 0.0 ; t0 [ 163ULL ] =
298.15 ; t0 [ 164ULL ] = 298.15 ; t0 [ 165ULL ] = 298.15 ; t0 [ 166ULL ] =
0.0 ; t0 [ 167ULL ] = 0.0 ; t0 [ 168ULL ] = 0.0 ; t0 [ 169ULL ] = 0.0 ; t0 [
170ULL ] = 0.0 ; t0 [ 171ULL ] = 0.0 ; t0 [ 172ULL ] = 0.0 ; t0 [ 173ULL ] =
0.0 ; t0 [ 174ULL ] = 1.0 ; t0 [ 175ULL ] = 0.0 ; t0 [ 176ULL ] = 0.0 ; t0 [
177ULL ] = 0.0 ; t0 [ 178ULL ] = 0.0 ; t0 [ 179ULL ] = 0.0 ; t0 [ 180ULL ] =
0.0 ; t0 [ 181ULL ] = 0.0 ; t0 [ 182ULL ] = 0.0 ; t0 [ 183ULL ] = 0.0 ; t0 [
184ULL ] = 0.0 ; t0 [ 185ULL ] = 293.15 ; t0 [ 186ULL ] = 293.15 ; t0 [
187ULL ] = 293.15 ; t0 [ 188ULL ] = 0.0 ; t0 [ 189ULL ] = 293.15 ; t0 [
190ULL ] = 0.0 ; t0 [ 191ULL ] = 0.0 ; t0 [ 192ULL ] = 293.15 ; t0 [ 193ULL ]
= 293.15 ; t0 [ 194ULL ] = 293.15 ; t0 [ 195ULL ] = 293.15 ; t0 [ 196ULL ] =
0.0 ; t0 [ 197ULL ] = 293.15 ; t0 [ 198ULL ] = 0.0 ; t0 [ 199ULL ] = 0.0 ; t0
[ 200ULL ] = 293.15 ; for ( b = 0 ; b < 201 ; b ++ ) { out . mX [ b ] = t0 [
b ] ; } ( void ) LC ; ( void ) t9 ; return 0 ; }

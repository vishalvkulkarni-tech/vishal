#include "ne_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_sys_struct.h"
#include "IGBTThermal_399ad5b0_1_ds_ddf.h"
#include "IGBTThermal_399ad5b0_1_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_externals.h"
#include "IGBTThermal_399ad5b0_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T IGBTThermal_399ad5b0_1_ds_ddf ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmRealVector out ;
int32_T Q_idx_0 ; int32_T Q_idx_1 ; boolean_T intrm_sf_mf_10 ; boolean_T
intrm_sf_mf_11 ; boolean_T intrm_sf_mf_12 ; boolean_T intrm_sf_mf_13 ;
boolean_T intrm_sf_mf_17 ; boolean_T intrm_sf_mf_18 ; boolean_T
intrm_sf_mf_19 ; boolean_T intrm_sf_mf_20 ; boolean_T intrm_sf_mf_21 ;
boolean_T intrm_sf_mf_9 ; ( void ) LC ; Q_idx_0 = t1 -> mQ . mX [ 0 ] ;
Q_idx_1 = t1 -> mQ . mX [ 1 ] ; out = t2 -> mDDF ; intrm_sf_mf_10 = ( (
size_t ) Q_idx_0 == 4ULL ) ; intrm_sf_mf_11 = ( ( size_t ) Q_idx_0 == 3ULL )
; intrm_sf_mf_12 = ( ( size_t ) Q_idx_0 == 2ULL ) ; intrm_sf_mf_13 = ( (
size_t ) Q_idx_0 == 1ULL ) ; intrm_sf_mf_17 = ( ( size_t ) Q_idx_1 == 5ULL )
; intrm_sf_mf_18 = ( ( size_t ) Q_idx_1 == 4ULL ) ; intrm_sf_mf_19 = ( (
size_t ) Q_idx_1 == 3ULL ) ; intrm_sf_mf_20 = ( ( size_t ) Q_idx_1 == 2ULL )
; intrm_sf_mf_21 = ( ( size_t ) Q_idx_1 == 1ULL ) ; intrm_sf_mf_9 = ( (
size_t ) Q_idx_0 == 5ULL ) ; out . mX [ 0 ] = intrm_sf_mf_13 ? 0.0 :
intrm_sf_mf_12 ? 0.0 : intrm_sf_mf_11 ? 0.0 : intrm_sf_mf_10 ? 0.0 :
intrm_sf_mf_9 ? 0.0 : ( size_t ) Q_idx_0 == 6ULL ? 0.0 : ( size_t ) Q_idx_0
== 7ULL ? 0.0 : ( size_t ) Q_idx_0 == 8ULL ? - 3.8292011019283752E+6 : 0.0 ;
out . mX [ 1 ] = intrm_sf_mf_13 ? 0.0 : intrm_sf_mf_12 ? 0.0 : intrm_sf_mf_11
? 0.0 : intrm_sf_mf_10 ? 0.0 : intrm_sf_mf_9 ? - 3.8292011019283752E+6 : 0.0
; out . mX [ 2 ] = intrm_sf_mf_21 ? 0.0 : intrm_sf_mf_20 ? 0.0 :
intrm_sf_mf_19 ? 0.0 : intrm_sf_mf_18 ? 0.0 : intrm_sf_mf_17 ? 0.0 : ( size_t
) Q_idx_1 == 6ULL ? 0.0 : ( size_t ) Q_idx_1 == 7ULL ? 0.0 : ( size_t )
Q_idx_1 == 8ULL ? - 1.5999999999999998E+6 : 0.0 ; out . mX [ 3 ] =
intrm_sf_mf_21 ? 0.0 : intrm_sf_mf_20 ? 0.0 : intrm_sf_mf_19 ? 0.0 :
intrm_sf_mf_18 ? 0.0 : intrm_sf_mf_17 ? - 1.5999999999999998E+6 : 0.0 ; (
void ) LC ; ( void ) t2 ; return 0 ; }

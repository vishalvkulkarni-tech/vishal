#include "ne_ds.h"
#include "IGBTThermal_399ad5b0_1_ds_obs_il.h"
#include "IGBTThermal_399ad5b0_1_ds_obs_all.h"
#include "IGBTThermal_399ad5b0_1_ds_mode.h"
#include "IGBTThermal_399ad5b0_1_ds_m_p.h"
#include "IGBTThermal_399ad5b0_1_ds_m.h"
#include "IGBTThermal_399ad5b0_1_ds_log.h"
#include "IGBTThermal_399ad5b0_1_ds_obs_act.h"
#include "IGBTThermal_399ad5b0_1_ds_imax.h"
#include "IGBTThermal_399ad5b0_1_ds_imin.h"
#include "IGBTThermal_399ad5b0_1_ds_tdxf_p.h"
#include "IGBTThermal_399ad5b0_1_ds_a_p.h"
#include "IGBTThermal_399ad5b0_1_ds_a.h"
#include "IGBTThermal_399ad5b0_1_ds_ddf.h"
#include "IGBTThermal_399ad5b0_1_ds_ic.h"
#include "IGBTThermal_399ad5b0_1_ds_dxf_p.h"
#include "IGBTThermal_399ad5b0_1_ds_qx.h"
#include "IGBTThermal_399ad5b0_1_ds_dxf.h"
#include "IGBTThermal_399ad5b0_1_ds_qx_p.h"
#include "IGBTThermal_399ad5b0_1_ds_lock2_i.h"
#include "IGBTThermal_399ad5b0_1_ds_zc.h"
#include "IGBTThermal_399ad5b0_1_ds_lock2_r.h"
#include "IGBTThermal_399ad5b0_1_ds_update_i.h"
#include "IGBTThermal_399ad5b0_1_ds_f.h"
#include "IGBTThermal_399ad5b0_1_ds_cache_i.h"
#include "IGBTThermal_399ad5b0_1_ds_update2_i.h"
#include "IGBTThermal_399ad5b0_1_ds_update2_r.h"
#include "IGBTThermal_399ad5b0_1_ds_update_r.h"
#include "IGBTThermal_399ad5b0_1_ds_lock_i.h"
#include "IGBTThermal_399ad5b0_1_ds_obs_exp.h"
#include "IGBTThermal_399ad5b0_1_ds_lock_r.h"
#include "IGBTThermal_399ad5b0_1_ds_assert.h"
#include "IGBTThermal_399ad5b0_1_ds.h"
#include "ssc_ml_fun.h"
#include "IGBTThermal_399ad5b0_1_ds_external_struct.h"
#include "IGBTThermal_399ad5b0_1_ds_externals.h"
#include "IGBTThermal_399ad5b0_1_ds_sys_struct.h"
static int32_T ds_vmm ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_dxm_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_dxm ( const NeDynamicSystem * ds
, const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_ddm_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_ddm ( const NeDynamicSystem * ds
, const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_dum_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_dum ( const NeDynamicSystem * ds
, const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_dtm_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_dtm ( const NeDynamicSystem * ds
, const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_dpm_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_dpm ( const NeDynamicSystem * ds
, const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_b_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_b ( const NeDynamicSystem * ds ,
const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_c_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_c ( const NeDynamicSystem * ds ,
const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_vmf ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_vpf ( const NeDynamicSystem * ds
, const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_vsf ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_slf ( const NeDynamicSystem * ds
, const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_slf0 ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_duf_p ( const NeDynamicSystem *
ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_duf ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in
, NeDsMethodOutput * out ) ; static int32_T ds_dtf_p ( const NeDynamicSystem
* ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_dtf ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in
, NeDsMethodOutput * out ) ; static int32_T ds_ddf_p ( const NeDynamicSystem
* ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_dpdxf_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput
* in , NeDsMethodOutput * out ) ; static int32_T ds_dpdxf ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out ) ; static int32_T ds_dwf_p ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T ds_dwf
( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_tduf_p ( const NeDynamicSystem *
ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_dnf_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput *
in , NeDsMethodOutput * out ) ; static int32_T ds_dnf ( const NeDynamicSystem
* ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_dnf_v_x ( const NeDynamicSystem * ds , const NeDynamicSystemInput
* in , NeDsMethodOutput * out ) ; static int32_T ds_cer ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out ) ; static int32_T ds_dxcer ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_dxcer_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_ddcer ( const NeDynamicSystem *
ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_ddcer_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput
* in , NeDsMethodOutput * out ) ; static int32_T ds_icr ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out ) ; static int32_T ds_icr_im ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_icr_id ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_icr_il ( const NeDynamicSystem *
ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_dxicr ( const NeDynamicSystem * ds , const NeDynamicSystemInput *
in , NeDsMethodOutput * out ) ; static int32_T ds_dxicr_p ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out ) ; static int32_T ds_ddicr ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_ddicr_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_tduicr_p ( const NeDynamicSystem
* ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_icrm_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput *
in , NeDsMethodOutput * out ) ; static int32_T ds_icrm ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out ) ; static int32_T ds_dxicrm_p ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_dxicrm ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_ddicrm_p ( const NeDynamicSystem
* ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_ddicrm ( const NeDynamicSystem * ds , const NeDynamicSystemInput *
in , NeDsMethodOutput * out ) ; static int32_T ds_freqs ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out ) ; static int32_T ds_solverhits ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_mduy_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_mdxy_p ( const NeDynamicSystem *
ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_tduy_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput *
in , NeDsMethodOutput * out ) ; static int32_T ds_tdxy_p ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out ) ; static int32_T ds_y ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_dxy_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_dxy ( const NeDynamicSystem * ds
, const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_duy_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_duy ( const NeDynamicSystem * ds
, const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_dty_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_dty ( const NeDynamicSystem * ds
, const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_cache_r ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_sfo ( const NeDynamicSystem * ds
, const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_sfp ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_init_r ( const NeDynamicSystem *
ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_init_i ( const NeDynamicSystem * ds , const NeDynamicSystemInput *
in , NeDsMethodOutput * out ) ; static int32_T ds_passert ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out ) ; static int32_T ds_iassert ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_del_t ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_del_v ( const NeDynamicSystem *
ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_del_v0 ( const NeDynamicSystem * ds , const NeDynamicSystemInput *
in , NeDsMethodOutput * out ) ; static int32_T ds_del_tmax ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out ) ; static int32_T ds_dxdelt_p ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_dxdelt ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_dudelt_p ( const NeDynamicSystem
* ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_dudelt ( const NeDynamicSystem * ds , const NeDynamicSystemInput *
in , NeDsMethodOutput * out ) ; static int32_T ds_dtdelt_p ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out ) ; static int32_T ds_dtdelt ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T ds_dp_l
( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_dp_i ( const NeDynamicSystem *
ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_dp_j ( const NeDynamicSystem * ds , const NeDynamicSystemInput *
in , NeDsMethodOutput * out ) ; static int32_T ds_dp_r ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out ) ; static int32_T ds_qu ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T ds_qt (
const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_q1 ( const NeDynamicSystem * ds
, const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_qu_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_qt_p ( const NeDynamicSystem *
ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_q1_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput *
in , NeDsMethodOutput * out ) ; static int32_T ds_var_tol ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out ) ; static int32_T ds_eq_tol ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T ds_lv (
const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_slv ( const NeDynamicSystem * ds
, const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_nldv ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_sclv ( const NeDynamicSystem *
ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_dimin ( const NeDynamicSystem * ds , const NeDynamicSystemInput *
in , NeDsMethodOutput * out ) ; static int32_T ds_dimax ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out ) ; static NeDsMethodOutput * ds_output_m_p ( const NeDynamicSystem * ds
, PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_m ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_vmm ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_dxm_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_dxm ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_ddm_p ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_ddm ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_dum_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_dum ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_dtm_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_dtm ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_dpm_p ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_dpm ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_a_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_a ( const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_b_p ( const NeDynamicSystem * ds , PmAllocator *
allocator ) ; static NeDsMethodOutput * ds_output_b ( const NeDynamicSystem *
ds , PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_c_p (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_c ( const NeDynamicSystem * ds , PmAllocator *
allocator ) ; static NeDsMethodOutput * ds_output_f ( const NeDynamicSystem *
ds , PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_vmf (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_vpf ( const NeDynamicSystem * ds , PmAllocator *
allocator ) ; static NeDsMethodOutput * ds_output_vsf ( const NeDynamicSystem
* ds , PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_slf (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_slf0 ( const NeDynamicSystem * ds , PmAllocator
* allocator ) ; static NeDsMethodOutput * ds_output_dxf_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_dxf ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_duf_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_duf ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_dtf_p ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_dtf ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_ddf_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_ddf ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_dpdxf_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_dpdxf ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_dwf_p ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_dwf ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_tduf_p (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_tdxf_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_dnf_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_dnf ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_dnf_v_x ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_cer ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_dxcer ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_dxcer_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_ddcer ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_ddcer_p ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_ic ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_icr ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_icr_im ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_icr_id ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_icr_il (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_dxicr ( const NeDynamicSystem * ds , PmAllocator
* allocator ) ; static NeDsMethodOutput * ds_output_dxicr_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_ddicr ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_ddicr_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_tduicr_p (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_icrm_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_icrm ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_dxicrm_p ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_dxicrm ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_ddicrm_p (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_ddicrm ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_freqs ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_solverhits ( const NeDynamicSystem * ds , PmAllocator * allocator )
; static NeDsMethodOutput * ds_output_mduy_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_mdxy_p (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_tduy_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_tdxy_p (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_y ( const NeDynamicSystem * ds , PmAllocator *
allocator ) ; static NeDsMethodOutput * ds_output_dxy_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_dxy ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_duy_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_duy ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_dty_p ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_dty ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_mode ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_zc ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_cache_r ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_cache_i (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_update_r ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_update_i (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_update2_r ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_update2_i (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_lock_r ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_lock_i (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_lock2_r ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_lock2_i (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_sfo ( const NeDynamicSystem * ds , PmAllocator *
allocator ) ; static NeDsMethodOutput * ds_output_sfp ( const NeDynamicSystem
* ds , PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_init_r
( const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_init_i ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_log ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_assert ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_passert ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_iassert (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_del_t ( const NeDynamicSystem * ds , PmAllocator
* allocator ) ; static NeDsMethodOutput * ds_output_del_v ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_del_v0 ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_del_tmax ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_dxdelt_p (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_dxdelt ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_dudelt_p (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_dudelt ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_dtdelt_p (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_dtdelt ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_obs_exp (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_obs_act ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_obs_all (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_obs_il ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_dp_l ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_dp_i ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_dp_j ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_dp_r ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_qx ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_qu ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_qt ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_q1 ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_qx_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_qu_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_qt_p ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_q1_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_var_tol (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_eq_tol ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_lv ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_slv ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_nldv ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_sclv ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_imin ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_imax ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_dimin ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_dimax ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static void release_reference ( NeDynamicSystem * ds ) ; static void
get_reference ( NeDynamicSystem * ds ) ; static NeDynamicSystem * diagnostics
( NeDynamicSystem * ds , boolean_T ) ; static void expand ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , PmRealVector * out ,
boolean_T kp ) ; static void rtpmap ( const NeDynamicSystem * ds , const
PmIntVector * inl , const PmIntVector * ini , const PmIntVector * inj , const
PmRealVector * inr , PmIntVector * outl , PmIntVector * outi , PmIntVector *
outj , PmRealVector * outr ) ; static NeEquationData s_equation_data [ 26 ] =
{ { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"IGBTThermal/Buck circuit 1/Capacitor" , 1U , 0U , TRUE , 1.0 , "1" , } , {
"" , 0U , 8 , NE_EQUATION_DOMAIN_TIME , "IGBTThermal/Buck circuit 1/Inductor"
, 2U , 1U , TRUE , 1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"IGBTThermal/Buck circuit 2/Capacitor" , 1U , 3U , TRUE , 1.0 , "1" , } , {
"" , 0U , 8 , NE_EQUATION_DOMAIN_TIME , "IGBTThermal/Buck circuit 2/Inductor"
, 2U , 4U , TRUE , 1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"IGBTThermal/IGBT_C" , 1U , 6U , TRUE , 1.0 , "1" , } , { "" , 1U , 8 ,
NE_EQUATION_DOMAIN_TIME , "IGBTThermal/IGBT_C" , 1U , 6U , TRUE , 1.0 , "1" ,
} , { "" , 2U , 8 , NE_EQUATION_DOMAIN_TIME , "IGBTThermal/IGBT_C" , 1U , 6U
, TRUE , 1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"IGBTThermal/IGBT_C" , 1U , 7U , TRUE , 1.0 , "1" , } , { "" , 0U , 8 ,
NE_EQUATION_DOMAIN_TIME , "IGBTThermal/IGBT_F" , 1U , 8U , TRUE , 1.0 , "1" ,
} , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME , "IGBTThermal/IGBT_F" , 1U , 9U
, TRUE , 1.0 , "1" , } , { "" , 1U , 8 , NE_EQUATION_DOMAIN_TIME ,
"IGBTThermal/IGBT_F" , 1U , 9U , TRUE , 1.0 , "1" , } , { "" , 2U , 8 ,
NE_EQUATION_DOMAIN_TIME , "IGBTThermal/IGBT_F" , 1U , 9U , TRUE , 1.0 , "1" ,
} , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME , "IGBTThermal/IGBT_F" , 1U , 10U
, TRUE , 1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"IGBTThermal/Buck circuit 1/Diode" , 3U , 11U , TRUE , 1.0 , "1" , } , { "" ,
0U , 8 , NE_EQUATION_DOMAIN_TIME , "IGBTThermal/Buck circuit 1/Diode" , 3U ,
14U , TRUE , 1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"IGBTThermal/Buck circuit 2/Diode" , 3U , 17U , TRUE , 1.0 , "1" , } , { "" ,
0U , 8 , NE_EQUATION_DOMAIN_TIME , "IGBTThermal/Buck circuit 2/Diode" , 3U ,
20U , TRUE , 1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"IGBTThermal/IGBT_C" , 1U , 23U , FALSE , 1.0 , "1" , } , { "" , 0U , 8 ,
NE_EQUATION_DOMAIN_TIME , "IGBTThermal/IGBT_C" , 8U , 24U , FALSE , 1.0 , "1"
, } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME , "IGBTThermal/IGBT_C" , 10U ,
32U , TRUE , 1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"IGBTThermal/IGBT_C" , 10U , 42U , TRUE , 1.0 , "1" , } , { "" , 0U , 8 ,
NE_EQUATION_DOMAIN_TIME , "IGBTThermal/IGBT_F" , 1U , 52U , TRUE , 1.0 , "1"
, } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME , "IGBTThermal/IGBT_F" , 1U ,
53U , FALSE , 1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"IGBTThermal/IGBT_F" , 8U , 54U , FALSE , 1.0 , "1" , } , { "" , 0U , 8 ,
NE_EQUATION_DOMAIN_TIME , "IGBTThermal/IGBT_F" , 10U , 62U , TRUE , 1.0 , "1"
, } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME , "IGBTThermal/IGBT_F" , 10U ,
72U , TRUE , 1.0 , "1" , } } ; static NeCERData * s_cer_data = NULL ; static
NeICRData s_icr_data [ 2 ] = { { "" , 0U , 1 , "IGBTThermal/IGBT_C" , 1U , 0U
, } , { "" , 0U , 1 , "IGBTThermal/IGBT_F" , 1U , 1U , } } ; static
NeVariableData s_variable_data [ 26 ] = { { "Buck_circuit_1.Capacitor.vc" ,
0U , 0 , "IGBTThermal/Buck circuit 1/Capacitor" , 1.0 , "1" , 0.0 , TRUE ,
FALSE , { { 1 , 1 } } , NE_INIT_MODE_MANDATORY , "Capacitor voltage" , } , {
"Buck_circuit_1.Inductor.i_L" , 0U , 0 ,
"IGBTThermal/Buck circuit 1/Inductor" , 1.0 , "1" , 0.0 , TRUE , FALSE , { {
1 , 1 } } , NE_INIT_MODE_MANDATORY , "Inductor current" , } , {
"Buck_circuit_2.Capacitor.vc" , 0U , 0 ,
"IGBTThermal/Buck circuit 2/Capacitor" , 1.0 , "1" , 0.0 , TRUE , FALSE , { {
1 , 1 } } , NE_INIT_MODE_MANDATORY , "Capacitor voltage" , } , {
"Buck_circuit_2.Inductor.i_L" , 0U , 0 ,
"IGBTThermal/Buck circuit 2/Inductor" , 1.0 , "1" , 0.0 , TRUE , FALSE , { {
1 , 1 } } , NE_INIT_MODE_MANDATORY , "Inductor current" , } , {
"IGBT_C.thermal_port.Tvec" , 0U , 0 , "IGBTThermal/IGBT_C" , 1.0 , "1" , 0.0
, TRUE , FALSE , { { 1 , 3 } } , NE_INIT_MODE_MANDATORY ,
"Vector of thermal mass temperatures" , } , { "IGBT_C.thermal_port.Tvec" , 1U
, 0 , "IGBTThermal/IGBT_C" , 1.0 , "1" , 0.0 , TRUE , FALSE , { { 1 , 3 } } ,
NE_INIT_MODE_MANDATORY , "Vector of thermal mass temperatures" , } , {
"IGBT_C.thermal_port.Tvec" , 2U , 0 , "IGBTThermal/IGBT_C" , 1.0 , "1" , 0.0
, TRUE , FALSE , { { 1 , 3 } } , NE_INIT_MODE_MANDATORY ,
"Vector of thermal mass temperatures" , } , { "IGBT_C.Tdelta" , 0U , 0 ,
"IGBTThermal/IGBT_C" , 1.0 , "1" , 0.0 , TRUE , FALSE , { { 1 , 1 } } ,
NE_INIT_MODE_NONE , "Small mass temperature" , } , {
"IGBT_F.thermal_port.Tvec" , 0U , 0 , "IGBTThermal/IGBT_F" , 1.0 , "1" , 0.0
, TRUE , FALSE , { { 1 , 3 } } , NE_INIT_MODE_OPTIONAL ,
"Vector of thermal mass temperatures" , } , { "IGBT_F.thermal_port.Tvec" , 1U
, 0 , "IGBTThermal/IGBT_F" , 1.0 , "1" , 0.0 , TRUE , FALSE , { { 1 , 3 } } ,
NE_INIT_MODE_OPTIONAL , "Vector of thermal mass temperatures" , } , {
"IGBT_F.thermal_port.Tvec" , 2U , 0 , "IGBTThermal/IGBT_F" , 1.0 , "1" , 0.0
, TRUE , FALSE , { { 1 , 3 } } , NE_INIT_MODE_OPTIONAL ,
"Vector of thermal mass temperatures" , } , { "IGBT_F.Tdelta" , 0U , 0 ,
"IGBTThermal/IGBT_F" , 1.0 , "1" , 0.0 , TRUE , FALSE , { { 1 , 1 } } ,
NE_INIT_MODE_NONE , "Small mass temperature" , } , {
"IGBT_F.parasitic_thermal_mass.Tj" , 0U , 0 , "IGBTThermal/IGBT_F" , 1.0 ,
"1" , 0.0 , TRUE , FALSE , { { 1 , 1 } } , NE_INIT_MODE_NONE ,
"Junction temperature" , } , { "IGBT_F.v" , 0U , 0 , "IGBTThermal/IGBT_F" ,
1.0 , "1" , 0.0 , FALSE , FALSE , { { 1 , 1 } } , NE_INIT_MODE_NONE ,
"Collector-emitter voltage" , } , { "IGBT_F.i" , 0U , 0 ,
"IGBTThermal/IGBT_F" , 1.0 , "1" , 0.0 , FALSE , FALSE , { { 1 , 1 } } ,
NE_INIT_MODE_NONE , "IGBT current (excludes diode current)" , } , {
"Buck_circuit_1.Diode.private.threshold" , 0U , 0 ,
"IGBTThermal/Buck circuit 1/Diode" , 1.0 , "1" , 0.0 , FALSE , FALSE , { { 1
, 1 } } , NE_INIT_MODE_NONE , "threshold" , } , { "IGBT_C.v" , 0U , 0 ,
"IGBTThermal/IGBT_C" , 1.0 , "1" , 0.0 , FALSE , FALSE , { { 1 , 1 } } ,
NE_INIT_MODE_NONE , "Collector-emitter voltage" , } , { "IGBT_C.i" , 0U , 0 ,
"IGBTThermal/IGBT_C" , 1.0 , "1" , 0.0 , FALSE , FALSE , { { 1 , 1 } } ,
NE_INIT_MODE_NONE , "IGBT current (excludes diode current)" , } , {
"Buck_circuit_2.Diode.private.threshold" , 0U , 0 ,
"IGBTThermal/Buck circuit 2/Diode" , 1.0 , "1" , 0.0 , FALSE , FALSE , { { 1
, 1 } } , NE_INIT_MODE_NONE , "threshold" , } , { "IGBT_C.Qdelta" , 0U , 0 ,
"IGBTThermal/IGBT_C" , 1.0 , "1" , 0.0 , FALSE , FALSE , { { 1 , 1 } } ,
NE_INIT_MODE_NONE , "Heat flow into the small mass" , } , {
"IGBT_C.thermal_port.Q_AR_vec.Q_AR_vec_retained_variable_entry0" , 0U , 0 ,
"IGBTThermal/IGBT_C" , 1.0 , "1" , 0.0 , FALSE , FALSE , { { 1 , 1 } } ,
NE_INIT_MODE_NONE ,
"Secondary variable representing one of the elements of Q_AR_vec." , } , {
"IGBT_C.RHS" , 0U , 0 , "IGBTThermal/IGBT_C" , 1.0 , "1" , 0.0 , FALSE ,
FALSE , { { 1 , 1 } } , NE_INIT_MODE_NONE , "Integrand for Tdelta.der" , } ,
{ "IGBT_F.Qdelta" , 0U , 0 , "IGBTThermal/IGBT_F" , 1.0 , "1" , 0.0 , FALSE ,
FALSE , { { 1 , 1 } } , NE_INIT_MODE_NONE , "Heat flow into the small mass" ,
} , { "IGBT_F.parasitic_thermal_mass.Qj" , 0U , 0 , "IGBTThermal/IGBT_F" ,
1.0 , "1" , 0.0 , FALSE , FALSE , { { 1 , 1 } } , NE_INIT_MODE_NONE ,
"Heat flow into port J" , } , {
"IGBT_F.thermal_port.Q_AR_vec.Q_AR_vec_retained_variable_entry1" , 0U , 0 ,
"IGBTThermal/IGBT_F" , 1.0 , "1" , 0.0 , FALSE , FALSE , { { 1 , 1 } } ,
NE_INIT_MODE_NONE ,
"Secondary variable representing one of the elements of Q_AR_vec." , } , {
"IGBT_F.RHS" , 0U , 0 , "IGBTThermal/IGBT_F" , 1.0 , "1" , 0.0 , FALSE ,
FALSE , { { 1 , 1 } } , NE_INIT_MODE_NONE , "Integrand for Tdelta.der" , } }
; static NeVariableData s_discrete_data [ 14 ] = { {
"IGBT_C.accumulatedSwitchingLosses" , 0U , 0 , "IGBTThermal/IGBT_C" , 1.0 ,
"1" , 0.0 , FALSE , FALSE , { { 1 , 1 } } , NE_INIT_MODE_NONE ,
"accumulatedSwitchingLosses" , } , { "IGBT_C.lastTurnOffLoss" , 0U , 0 ,
"IGBTThermal/IGBT_C" , 1.0 , "1" , 0.0 , FALSE , FALSE , { { 1 , 1 } } ,
NE_INIT_MODE_NONE , "lastTurnOffLoss" , } , { "IGBT_C.lastTurnOnLoss" , 0U ,
0 , "IGBTThermal/IGBT_C" , 1.0 , "1" , 0.0 , FALSE , FALSE , { { 1 , 1 } } ,
NE_INIT_MODE_NONE , "lastTurnOnLoss" , } , { "IGBT_C.ziOff" , 0U , 0 ,
"IGBTThermal/IGBT_C" , 1.0 , "1" , 0.0 , FALSE , FALSE , { { 1 , 1 } } ,
NE_INIT_MODE_NONE , "Captured current for switch-off loss" , } , {
"IGBT_C.ziOn" , 0U , 0 , "IGBTThermal/IGBT_C" , 1.0 , "1" , 0.0 , FALSE ,
FALSE , { { 1 , 1 } } , NE_INIT_MODE_NONE ,
"Captured current for switch-on loss" , } , { "IGBT_C.zvOff" , 0U , 0 ,
"IGBTThermal/IGBT_C" , 1.0 , "1" , 0.0 , FALSE , FALSE , { { 1 , 1 } } ,
NE_INIT_MODE_NONE , "Captured voltage for switch-off loss" , } , {
"IGBT_C.zvOn" , 0U , 0 , "IGBTThermal/IGBT_C" , 1.0 , "1" , 0.0 , FALSE ,
FALSE , { { 1 , 1 } } , NE_INIT_MODE_NONE ,
"Captured voltage for switch-on loss" , } , {
"IGBT_F.accumulatedSwitchingLosses" , 0U , 0 , "IGBTThermal/IGBT_F" , 1.0 ,
"1" , 0.0 , FALSE , FALSE , { { 1 , 1 } } , NE_INIT_MODE_NONE ,
"accumulatedSwitchingLosses" , } , { "IGBT_F.lastTurnOffLoss" , 0U , 0 ,
"IGBTThermal/IGBT_F" , 1.0 , "1" , 0.0 , FALSE , FALSE , { { 1 , 1 } } ,
NE_INIT_MODE_NONE , "lastTurnOffLoss" , } , { "IGBT_F.lastTurnOnLoss" , 0U ,
0 , "IGBTThermal/IGBT_F" , 1.0 , "1" , 0.0 , FALSE , FALSE , { { 1 , 1 } } ,
NE_INIT_MODE_NONE , "lastTurnOnLoss" , } , { "IGBT_F.ziOff" , 0U , 0 ,
"IGBTThermal/IGBT_F" , 1.0 , "1" , 0.0 , FALSE , FALSE , { { 1 , 1 } } ,
NE_INIT_MODE_NONE , "Captured current for switch-off loss" , } , {
"IGBT_F.ziOn" , 0U , 0 , "IGBTThermal/IGBT_F" , 1.0 , "1" , 0.0 , FALSE ,
FALSE , { { 1 , 1 } } , NE_INIT_MODE_NONE ,
"Captured current for switch-on loss" , } , { "IGBT_F.zvOff" , 0U , 0 ,
"IGBTThermal/IGBT_F" , 1.0 , "1" , 0.0 , FALSE , FALSE , { { 1 , 1 } } ,
NE_INIT_MODE_NONE , "Captured voltage for switch-off loss" , } , {
"IGBT_F.zvOn" , 0U , 0 , "IGBTThermal/IGBT_F" , 1.0 , "1" , 0.0 , FALSE ,
FALSE , { { 1 , 1 } } , NE_INIT_MODE_NONE ,
"Captured voltage for switch-on loss" , } } ; static NeObservableData
s_observable_data [ 197 ] = { { "Buck_circuit_1.Capacitor.i" ,
"IGBTThermal/Buck circuit 1/Capacitor" , { { 1 , 1 } } , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Current" , } , {
"Buck_circuit_1.Capacitor.n.v" , "IGBTThermal/Buck circuit 1/Capacitor" , { {
1 , 1 } } , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_1.Capacitor.p.v" , "IGBTThermal/Buck circuit 1/Capacitor" , { {
1 , 1 } } , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
TRUE , FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_1.Capacitor.v" , "IGBTThermal/Buck circuit 1/Capacitor" , { { 1
, 1 } } , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_1.Capacitor.vc" , "IGBTThermal/Buck circuit 1/Capacitor" , { {
1 , 1 } } , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL ,
NE_INIT_MODE_MANDATORY , FALSE , TRUE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE ,
"Capacitor voltage" , } , { "Buck_circuit_1.Capacitor.power_dissipated" ,
"IGBTThermal/Buck circuit 1/Capacitor" , { { 1 , 1 } } , "kW" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_NONE , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , FALSE , "Dissipated power" , } , {
"Buck_circuit_1.Collector.v" , "IGBTThermal/Buck circuit 1" , { { 1 , 1 } } ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Voltage" , } , {
"Buck_circuit_1.Diode.private.BV_threshold" ,
"IGBTThermal/Buck circuit 1/Diode" , { { 1 , 1 } } , "1" , 1.0 , "1" ,
NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "BV_threshold" , } , {
"Buck_circuit_1.Diode.n.v" , "IGBTThermal/Buck circuit 1/Diode" , { { 1 , 1 }
} , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE ,
FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_1.Diode.TJ" , "IGBTThermal/Buck circuit 1/Diode" , { { 1 , 1 }
} , "K" , 1.0 , "K" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , TRUE ,
FALSE , NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Junction temperature" , } , {
"Buck_circuit_1.Diode.Tsim" , "IGBTThermal/Buck circuit 1/Diode" , { { 1 , 1
} } , "K" , 1.0 , "K" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , TRUE
, FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE ,
"Simulation temperature on the IV characteristics" , } , {
"Buck_circuit_1.Diode.fault_input" , "IGBTThermal/Buck circuit 1/Diode" , { {
1 , 1 } } , "1" , 1.0 , "1" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE ,
TRUE , FALSE , NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Input fault trigger" ,
} , { "Buck_circuit_1.Diode.faulted" , "IGBTThermal/Buck circuit 1/Diode" , {
{ 1 , 1 } } , "1" , 1.0 , "1" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE
, TRUE , FALSE , NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Fault flag" , } , {
"Buck_circuit_1.Diode.i" , "IGBTThermal/Buck circuit 1/Diode" , { { 1 , 1 } }
, "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Current" , } , {
"Buck_circuit_1.Diode.i_capacitor" , "IGBTThermal/Buck circuit 1/Diode" , { {
1 , 1 } } , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
TRUE , FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE ,
"Junction capacitance current" , } , { "Buck_circuit_1.Diode.i_diode" ,
"IGBTThermal/Buck circuit 1/Diode" , { { 1 , 1 } } , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Intrinsic diode current" , } , {
"Buck_circuit_1.Diode.i_out" , "IGBTThermal/Buck circuit 1/Diode" , { { 1 , 1
} } , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Diode current output" , } , {
"Buck_circuit_1.Diode.v_diode" , "IGBTThermal/Buck circuit 1/Diode" , { { 1 ,
1 } } , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE
, FALSE , NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Intrinsic diode voltage" ,
} , { "Buck_circuit_1.Diode.ni.v" , "IGBTThermal/Buck circuit 1/Diode" , { {
1 , 1 } } , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
TRUE , FALSE , NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Voltage" , } , {
"Buck_circuit_1.Diode.p.v" , "IGBTThermal/Buck circuit 1/Diode" , { { 1 , 1 }
} , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_1.Diode.power_dissipated" , "IGBTThermal/Buck circuit 1/Diode"
, { { 1 , 1 } } , "W" , 1.0 , "kW" , NE_NOMINAL_SOURCE_MODEL ,
NE_INIT_MODE_NONE , FALSE , FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE ,
"power_dissipated" , } , { "Buck_circuit_1.Diode.private.threshold" ,
"IGBTThermal/Buck circuit 1/Diode" , { { 1 , 1 } } , "1" , 1.0 , "1" ,
NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "threshold" , } , {
"Buck_circuit_1.Diode.v" , "IGBTThermal/Buck circuit 1/Diode" , { { 1 , 1 } }
, "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_1.Diode.v_capacitor" , "IGBTThermal/Buck circuit 1/Diode" , { {
1 , 1 } } , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
TRUE , FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE ,
"Junction capacitance voltage" , } , { "Buck_circuit_1.Gate.v" ,
"IGBTThermal/Buck circuit 1" , { { 1 , 1 } } , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Voltage" , } , {
"Buck_circuit_1.Gate_Drive" , "IGBTThermal/Buck circuit 1" , { { 1 , 1 } } ,
"1" , 1.0 , "1" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , FALSE ,
FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Gate_Drive" , } , {
"Buck_circuit_1.Ground.v" , "IGBTThermal/Buck circuit 1" , { { 1 , 1 } } ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE
, NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Voltage" , } , {
"Buck_circuit_1.Inductor.i" , "IGBTThermal/Buck circuit 1/Inductor" , { { 1 ,
1 } } , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE
, FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Current" , } , {
"Buck_circuit_1.Inductor.n.v" , "IGBTThermal/Buck circuit 1/Inductor" , { { 1
, 1 } } , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_1.Inductor.p.v" , "IGBTThermal/Buck circuit 1/Inductor" , { { 1
, 1 } } , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_1.Inductor.v" , "IGBTThermal/Buck circuit 1/Inductor" , { { 1 ,
1 } } , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE
, FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_1.Inductor.i_L" , "IGBTThermal/Buck circuit 1/Inductor" , { { 1
, 1 } } , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY
, FALSE , TRUE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Inductor current" , }
, { "Buck_circuit_1.Inductor.power_dissipated" ,
"IGBTThermal/Buck circuit 1/Inductor" , { { 1 , 1 } } , "kW" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_NONE , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , FALSE , "Dissipated power" , } , {
"Buck_circuit_1.Load.i" , "IGBTThermal/Buck circuit 1/Load" , { { 1 , 1 } } ,
"A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Current" , } , {
"Buck_circuit_1.Load.n.v" , "IGBTThermal/Buck circuit 1/Load" , { { 1 , 1 } }
, "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_1.Load.p.v" , "IGBTThermal/Buck circuit 1/Load" , { { 1 , 1 } }
, "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE ,
FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_1.Load.v" , "IGBTThermal/Buck circuit 1/Load" , { { 1 , 1 } } ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_1.Load.power_dissipated" , "IGBTThermal/Buck circuit 1/Load" ,
{ { 1 , 1 } } , "A^2*Ohm" , 1.0 , "A^2*Ohm" , NE_NOMINAL_SOURCE_NONE ,
NE_INIT_MODE_NONE , FALSE , FALSE , NE_FREQTIME_TYPE_TIME , TRUE , FALSE ,
"Dissipated power" , } , { "Buck_circuit_1.Vgate.i" ,
"IGBTThermal/Buck circuit 1/Vgate" , { { 1 , 1 } } , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "i" , } , { "Buck_circuit_1.Vgate.n.v"
, "IGBTThermal/Buck circuit 1/Vgate" , { { 1 , 1 } } , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_1.Vgate.p.v" , "IGBTThermal/Buck circuit 1/Vgate" , { { 1 , 1 }
} , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_1.Vgate.v" , "IGBTThermal/Buck circuit 1/Vgate" , { { 1 , 1 } }
, "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "v" , } , {
"Buck_circuit_1.Vgate.vT" , "IGBTThermal/Buck circuit 1/Vgate" , { { 1 , 1 }
} , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "vT" , } , {
"Buck_circuit_1.Vin.i" , "IGBTThermal/Buck circuit 1/Vin" , { { 1 , 1 } } ,
"A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Current" , } , {
"Buck_circuit_1.Vin.n.v" , "IGBTThermal/Buck circuit 1/Vin" , { { 1 , 1 } } ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE
, NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_1.Vin.p.v" , "IGBTThermal/Buck circuit 1/Vin" , { { 1 , 1 } } ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE
, NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_1.Vin.v" , "IGBTThermal/Buck circuit 1/Vin" , { { 1 , 1 } } ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE
, NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_2.Capacitor.i" , "IGBTThermal/Buck circuit 2/Capacitor" , { { 1
, 1 } } , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Current" , } , {
"Buck_circuit_2.Capacitor.n.v" , "IGBTThermal/Buck circuit 2/Capacitor" , { {
1 , 1 } } , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_2.Capacitor.p.v" , "IGBTThermal/Buck circuit 2/Capacitor" , { {
1 , 1 } } , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
TRUE , FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_2.Capacitor.v" , "IGBTThermal/Buck circuit 2/Capacitor" , { { 1
, 1 } } , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_2.Capacitor.vc" , "IGBTThermal/Buck circuit 2/Capacitor" , { {
1 , 1 } } , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL ,
NE_INIT_MODE_MANDATORY , FALSE , TRUE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE ,
"Capacitor voltage" , } , { "Buck_circuit_2.Capacitor.power_dissipated" ,
"IGBTThermal/Buck circuit 2/Capacitor" , { { 1 , 1 } } , "kW" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_NONE , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , FALSE , "Dissipated power" , } , {
"Buck_circuit_2.Collector.v" , "IGBTThermal/Buck circuit 2" , { { 1 , 1 } } ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Voltage" , } , {
"Buck_circuit_2.Diode.private.BV_threshold" ,
"IGBTThermal/Buck circuit 2/Diode" , { { 1 , 1 } } , "1" , 1.0 , "1" ,
NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "BV_threshold" , } , {
"Buck_circuit_2.Diode.n.v" , "IGBTThermal/Buck circuit 2/Diode" , { { 1 , 1 }
} , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE ,
FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_2.Diode.TJ" , "IGBTThermal/Buck circuit 2/Diode" , { { 1 , 1 }
} , "K" , 1.0 , "K" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , TRUE ,
FALSE , NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Junction temperature" , } , {
"Buck_circuit_2.Diode.Tsim" , "IGBTThermal/Buck circuit 2/Diode" , { { 1 , 1
} } , "K" , 1.0 , "K" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , TRUE
, FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE ,
"Simulation temperature on the IV characteristics" , } , {
"Buck_circuit_2.Diode.fault_input" , "IGBTThermal/Buck circuit 2/Diode" , { {
1 , 1 } } , "1" , 1.0 , "1" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE ,
TRUE , FALSE , NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Input fault trigger" ,
} , { "Buck_circuit_2.Diode.faulted" , "IGBTThermal/Buck circuit 2/Diode" , {
{ 1 , 1 } } , "1" , 1.0 , "1" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE
, TRUE , FALSE , NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Fault flag" , } , {
"Buck_circuit_2.Diode.i" , "IGBTThermal/Buck circuit 2/Diode" , { { 1 , 1 } }
, "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Current" , } , {
"Buck_circuit_2.Diode.i_capacitor" , "IGBTThermal/Buck circuit 2/Diode" , { {
1 , 1 } } , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
TRUE , FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE ,
"Junction capacitance current" , } , { "Buck_circuit_2.Diode.i_diode" ,
"IGBTThermal/Buck circuit 2/Diode" , { { 1 , 1 } } , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Intrinsic diode current" , } , {
"Buck_circuit_2.Diode.i_out" , "IGBTThermal/Buck circuit 2/Diode" , { { 1 , 1
} } , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Diode current output" , } , {
"Buck_circuit_2.Diode.v_diode" , "IGBTThermal/Buck circuit 2/Diode" , { { 1 ,
1 } } , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE
, FALSE , NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Intrinsic diode voltage" ,
} , { "Buck_circuit_2.Diode.ni.v" , "IGBTThermal/Buck circuit 2/Diode" , { {
1 , 1 } } , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
TRUE , FALSE , NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Voltage" , } , {
"Buck_circuit_2.Diode.p.v" , "IGBTThermal/Buck circuit 2/Diode" , { { 1 , 1 }
} , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_2.Diode.power_dissipated" , "IGBTThermal/Buck circuit 2/Diode"
, { { 1 , 1 } } , "W" , 1.0 , "kW" , NE_NOMINAL_SOURCE_MODEL ,
NE_INIT_MODE_NONE , FALSE , FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE ,
"power_dissipated" , } , { "Buck_circuit_2.Diode.private.threshold" ,
"IGBTThermal/Buck circuit 2/Diode" , { { 1 , 1 } } , "1" , 1.0 , "1" ,
NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "threshold" , } , {
"Buck_circuit_2.Diode.v" , "IGBTThermal/Buck circuit 2/Diode" , { { 1 , 1 } }
, "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_2.Diode.v_capacitor" , "IGBTThermal/Buck circuit 2/Diode" , { {
1 , 1 } } , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
TRUE , FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE ,
"Junction capacitance voltage" , } , { "Buck_circuit_2.Gate.v" ,
"IGBTThermal/Buck circuit 2" , { { 1 , 1 } } , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Voltage" , } , {
"Buck_circuit_2.Gate_Drive" , "IGBTThermal/Buck circuit 2" , { { 1 , 1 } } ,
"1" , 1.0 , "1" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , FALSE ,
FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Gate_Drive" , } , {
"Buck_circuit_2.Ground.v" , "IGBTThermal/Buck circuit 2" , { { 1 , 1 } } ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE
, NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Voltage" , } , {
"Buck_circuit_2.Inductor.i" , "IGBTThermal/Buck circuit 2/Inductor" , { { 1 ,
1 } } , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE
, FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Current" , } , {
"Buck_circuit_2.Inductor.n.v" , "IGBTThermal/Buck circuit 2/Inductor" , { { 1
, 1 } } , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_2.Inductor.p.v" , "IGBTThermal/Buck circuit 2/Inductor" , { { 1
, 1 } } , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_2.Inductor.v" , "IGBTThermal/Buck circuit 2/Inductor" , { { 1 ,
1 } } , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE
, FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_2.Inductor.i_L" , "IGBTThermal/Buck circuit 2/Inductor" , { { 1
, 1 } } , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY
, FALSE , TRUE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Inductor current" , }
, { "Buck_circuit_2.Inductor.power_dissipated" ,
"IGBTThermal/Buck circuit 2/Inductor" , { { 1 , 1 } } , "kW" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_NONE , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , FALSE , "Dissipated power" , } , {
"Buck_circuit_2.Load.i" , "IGBTThermal/Buck circuit 2/Load" , { { 1 , 1 } } ,
"A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Current" , } , {
"Buck_circuit_2.Load.n.v" , "IGBTThermal/Buck circuit 2/Load" , { { 1 , 1 } }
, "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_2.Load.p.v" , "IGBTThermal/Buck circuit 2/Load" , { { 1 , 1 } }
, "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE ,
FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_2.Load.v" , "IGBTThermal/Buck circuit 2/Load" , { { 1 , 1 } } ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_2.Load.power_dissipated" , "IGBTThermal/Buck circuit 2/Load" ,
{ { 1 , 1 } } , "A^2*Ohm" , 1.0 , "A^2*Ohm" , NE_NOMINAL_SOURCE_NONE ,
NE_INIT_MODE_NONE , FALSE , FALSE , NE_FREQTIME_TYPE_TIME , TRUE , FALSE ,
"Dissipated power" , } , { "Buck_circuit_2.Vgate.i" ,
"IGBTThermal/Buck circuit 2/Vgate" , { { 1 , 1 } } , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "i" , } , { "Buck_circuit_2.Vgate.n.v"
, "IGBTThermal/Buck circuit 2/Vgate" , { { 1 , 1 } } , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_2.Vgate.p.v" , "IGBTThermal/Buck circuit 2/Vgate" , { { 1 , 1 }
} , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_2.Vgate.v" , "IGBTThermal/Buck circuit 2/Vgate" , { { 1 , 1 } }
, "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "v" , } , {
"Buck_circuit_2.Vgate.vT" , "IGBTThermal/Buck circuit 2/Vgate" , { { 1 , 1 }
} , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "vT" , } , {
"Buck_circuit_2.Vin.i" , "IGBTThermal/Buck circuit 2/Vin" , { { 1 , 1 } } ,
"A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Current" , } , {
"Buck_circuit_2.Vin.n.v" , "IGBTThermal/Buck circuit 2/Vin" , { { 1 , 1 } } ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE
, NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_2.Vin.p.v" , "IGBTThermal/Buck circuit 2/Vin" , { { 1 , 1 } } ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE
, NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Buck_circuit_2.Vin.v" , "IGBTThermal/Buck circuit 2/Vin" , { { 1 , 1 } } ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE
, NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Electrical_Reference.V.v" , "IGBTThermal/Electrical Reference" , { { 1 , 1 }
} , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE ,
FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Electrical_Reference1.V.v" , "IGBTThermal/Electrical Reference1" , { { 1 , 1
} } , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE ,
FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , { "IGBT_C.C.v"
, "IGBTThermal/IGBT_C" , { { 1 , 1 } } , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , { "IGBT_C.E.v" ,
"IGBTThermal/IGBT_C" , { { 1 , 1 } } , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , { "IGBT_C.G" ,
"IGBTThermal/IGBT_C" , { { 1 , 1 } } , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "G" , } , { "IGBT_C.G_elec.v" ,
"IGBTThermal/IGBT_C" , { { 1 , 1 } } , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , { "IGBT_C.H.T" ,
"IGBTThermal/IGBT_C" , { { 1 , 1 } } , "K" , 1.0 , "K" ,
NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Temperature" , } , { "IGBT_C.J.T" ,
"IGBTThermal/IGBT_C" , { { 1 , 1 } } , "K" , 1.0 , "K" ,
NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Temperature" , } , {
"IGBT_C.Jdelta.T" , "IGBTThermal/IGBT_C" , { { 1 , 1 } } , "K" , 1.0 , "K" ,
NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Temperature" , } , { "IGBT_C.Qdelta"
, "IGBTThermal/IGBT_C" , { { 1 , 1 } } , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Heat flow into the small mass" , } ,
{ "IGBT_C.Qj" , "IGBTThermal/IGBT_C" , { { 1 , 1 } } , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Heat flow into junction" , } , {
"IGBT_C.RHS" , "IGBTThermal/IGBT_C" , { { 1 , 1 } } , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Integrand for Tdelta.der" , } , {
"IGBT_C.Tdelta" , "IGBTThermal/IGBT_C" , { { 1 , 1 } } , "K" , 1.0 , "K" ,
NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , FALSE , TRUE ,
NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Small mass temperature" , } , {
"IGBT_C.accumulatedSwitchingLosses" , "IGBTThermal/IGBT_C" , { { 1 , 1 } } ,
"J" , 1.0 , "J" , NE_NOMINAL_SOURCE_FIXED , NE_INIT_MODE_NONE , TRUE , FALSE
, NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "accumulatedSwitchingLosses" , } , {
"IGBT_C.dT" , "IGBTThermal/IGBT_C" , { { 1 , 1 } } , "K" , 1.0 , "K" ,
NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , FALSE , TRUE ,
"Temperature difference between small mass and the junction" , } , {
"IGBT_C.i" , "IGBTThermal/IGBT_C" , { { 1 , 1 } } , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "IGBT current (excludes diode current)"
, } , { "IGBT_C.ice" , "IGBTThermal/IGBT_C" , { { 1 , 1 } } , "A" , 1.0 , "A"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE ,
"Collector-emitter current (at terminals)" , } , {
"IGBT_C.junction_temperature" , "IGBTThermal/IGBT_C" , { { 1 , 1 } } , "degC"
, 1.0 , "K" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Junction temperature" , } , {
"IGBT_C.lastTurnOffLoss" , "IGBTThermal/IGBT_C" , { { 1 , 1 } } , "J" , 1.0 ,
"J" , NE_NOMINAL_SOURCE_FIXED , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "lastTurnOffLoss" , } , {
"IGBT_C.lastTurnOnLoss" , "IGBTThermal/IGBT_C" , { { 1 , 1 } } , "J" , 1.0 ,
"J" , NE_NOMINAL_SOURCE_FIXED , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "lastTurnOnLoss" , } , {
"IGBT_C.power_dissipated" , "IGBTThermal/IGBT_C" , { { 1 , 1 } } , "W" , 1.0
, "kW" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "power_dissipated" , } , {
"IGBT_C.thermal_port.A.T" , "IGBTThermal/IGBT_C" , { { 1 , 1 } } , "K" , 1.0
, "K" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Temperature" , } , {
"IGBT_C.thermal_port.B.T" , "IGBTThermal/IGBT_C" , { { 1 , 1 } } , "K" , 1.0
, "K" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Temperature" , } , {
"IGBT_C.thermal_port.Q_A" , "IGBTThermal/IGBT_C" , { { 1 , 1 } } , "W" , 1.0
, "kW" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Heat flow rate into port A" , } , {
"IGBT_C.thermal_port.Q_AB_vec" , "IGBTThermal/IGBT_C" , { { 3 , 1 } } , "W" ,
1.0 , "kW" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE ,
"Heat flow through thermal resistor for each element" , } , {
"IGBT_C.thermal_port.Q_AR_vec" , "IGBTThermal/IGBT_C" , { { 3 , 1 } } , "W" ,
1.0 , "kW" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE ,
"Heat flow through thermal capacitance for each element" , } , {
"IGBT_C.thermal_port.Q_B" , "IGBTThermal/IGBT_C" , { { 1 , 1 } } , "W" , 1.0
, "kW" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Heat flow rate into port B" , } , {
"IGBT_C.thermal_port.Tvec" , "IGBTThermal/IGBT_C" , { { 1 , 3 } } , "K" , 1.0
, "K" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_MANDATORY , FALSE , TRUE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Vector of thermal mass temperatures" ,
} , { "IGBT_C.v" , "IGBTThermal/IGBT_C" , { { 1 , 1 } } , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Collector-emitter voltage" , } , {
"IGBT_C.vT" , "IGBTThermal/IGBT_C" , { { 1 , 1 } } , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "vT" , } , { "IGBT_C.vce" ,
"IGBTThermal/IGBT_C" , { { 1 , 1 } } , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Collector-emitter voltage" , } , {
"IGBT_C.vge" , "IGBTThermal/IGBT_C" , { { 1 , 1 } } , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Gate-emitter voltage" , } , {
"IGBT_C.ziOff" , "IGBTThermal/IGBT_C" , { { 1 , 1 } } , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_FIXED , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Captured current for switch-off loss"
, } , { "IGBT_C.ziOn" , "IGBTThermal/IGBT_C" , { { 1 , 1 } } , "A" , 1.0 ,
"A" , NE_NOMINAL_SOURCE_FIXED , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Captured current for switch-on loss" ,
} , { "IGBT_C.zvOff" , "IGBTThermal/IGBT_C" , { { 1 , 1 } } , "V" , 1.0 , "V"
, NE_NOMINAL_SOURCE_FIXED , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Captured voltage for switch-off loss"
, } , { "IGBT_C.zvOn" , "IGBTThermal/IGBT_C" , { { 1 , 1 } } , "V" , 1.0 ,
"V" , NE_NOMINAL_SOURCE_FIXED , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Captured voltage for switch-on loss" ,
} , { "IGBT_C.internal_mode_var_m__" , "IGBTThermal/IGBT_C" , { { 1 , 1 } } ,
"1" , 1.0 , "1" , NE_NOMINAL_SOURCE_FIXED , NE_INIT_MODE_MANDATORY , TRUE ,
FALSE , NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "internal_mode_var_m__" , } ,
{ "IGBT_F.C.v" , "IGBTThermal/IGBT_F" , { { 1 , 1 } } , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , { "IGBT_F.E.v" ,
"IGBTThermal/IGBT_F" , { { 1 , 1 } } , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , { "IGBT_F.G" ,
"IGBTThermal/IGBT_F" , { { 1 , 1 } } , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "G" , } , { "IGBT_F.G_elec.v" ,
"IGBTThermal/IGBT_F" , { { 1 , 1 } } , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , { "IGBT_F.H.T" ,
"IGBTThermal/IGBT_F" , { { 1 , 1 } } , "K" , 1.0 , "K" ,
NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Temperature" , } , { "IGBT_F.J.T" ,
"IGBTThermal/IGBT_F" , { { 1 , 1 } } , "K" , 1.0 , "K" ,
NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Temperature" , } , {
"IGBT_F.Jdelta.T" , "IGBTThermal/IGBT_F" , { { 1 , 1 } } , "K" , 1.0 , "K" ,
NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Temperature" , } , { "IGBT_F.Qdelta"
, "IGBTThermal/IGBT_F" , { { 1 , 1 } } , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Heat flow into the small mass" , } ,
{ "IGBT_F.Qj" , "IGBTThermal/IGBT_F" , { { 1 , 1 } } , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Heat flow into junction" , } , {
"IGBT_F.RHS" , "IGBTThermal/IGBT_F" , { { 1 , 1 } } , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Integrand for Tdelta.der" , } , {
"IGBT_F.Tdelta" , "IGBTThermal/IGBT_F" , { { 1 , 1 } } , "K" , 1.0 , "K" ,
NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , FALSE , TRUE ,
NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Small mass temperature" , } , {
"IGBT_F.accumulatedSwitchingLosses" , "IGBTThermal/IGBT_F" , { { 1 , 1 } } ,
"J" , 1.0 , "J" , NE_NOMINAL_SOURCE_FIXED , NE_INIT_MODE_NONE , TRUE , FALSE
, NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "accumulatedSwitchingLosses" , } , {
"IGBT_F.dT" , "IGBTThermal/IGBT_F" , { { 1 , 1 } } , "K" , 1.0 , "K" ,
NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , FALSE , TRUE ,
"Temperature difference between small mass and the junction" , } , {
"IGBT_F.i" , "IGBTThermal/IGBT_F" , { { 1 , 1 } } , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "IGBT current (excludes diode current)"
, } , { "IGBT_F.ice" , "IGBTThermal/IGBT_F" , { { 1 , 1 } } , "A" , 1.0 , "A"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE ,
"Collector-emitter current (at terminals)" , } , {
"IGBT_F.junction_temperature" , "IGBTThermal/IGBT_F" , { { 1 , 1 } } , "degC"
, 1.0 , "K" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Junction temperature" , } , {
"IGBT_F.lastTurnOffLoss" , "IGBTThermal/IGBT_F" , { { 1 , 1 } } , "J" , 1.0 ,
"J" , NE_NOMINAL_SOURCE_FIXED , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "lastTurnOffLoss" , } , {
"IGBT_F.lastTurnOnLoss" , "IGBTThermal/IGBT_F" , { { 1 , 1 } } , "J" , 1.0 ,
"J" , NE_NOMINAL_SOURCE_FIXED , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "lastTurnOnLoss" , } , {
"IGBT_F.parasitic_thermal_mass.J.T" , "IGBTThermal/IGBT_F" , { { 1 , 1 } } ,
"K" , 1.0 , "K" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , FALSE ,
FALSE , NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Temperature" , } , {
"IGBT_F.parasitic_thermal_mass.Qj" , "IGBTThermal/IGBT_F" , { { 1 , 1 } } ,
"J/s" , 1.0 , "kW" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Heat flow into port J" , } ,
{ "IGBT_F.parasitic_thermal_mass.Tj" , "IGBTThermal/IGBT_F" , { { 1 , 1 } } ,
"K" , 1.0 , "K" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , FALSE ,
TRUE , NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Junction temperature" , } , {
"IGBT_F.power_dissipated" , "IGBTThermal/IGBT_F" , { { 1 , 1 } } , "W" , 1.0
, "kW" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "power_dissipated" , } , {
"IGBT_F.thermal_port.A.T" , "IGBTThermal/IGBT_F" , { { 1 , 1 } } , "K" , 1.0
, "K" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Temperature" , } , {
"IGBT_F.thermal_port.B.T" , "IGBTThermal/IGBT_F" , { { 1 , 1 } } , "K" , 1.0
, "K" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Temperature" , } , {
"IGBT_F.thermal_port.Q_A" , "IGBTThermal/IGBT_F" , { { 1 , 1 } } , "W" , 1.0
, "kW" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Heat flow rate into port A" , } , {
"IGBT_F.thermal_port.Q_AB_vec" , "IGBTThermal/IGBT_F" , { { 3 , 1 } } , "W" ,
1.0 , "kW" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE ,
"Heat flow through thermal resistor for each element" , } , {
"IGBT_F.thermal_port.Q_AR_vec" , "IGBTThermal/IGBT_F" , { { 3 , 1 } } , "W" ,
1.0 , "kW" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE ,
"Heat flow through thermal capacitance for each element" , } , {
"IGBT_F.thermal_port.Q_B" , "IGBTThermal/IGBT_F" , { { 1 , 1 } } , "W" , 1.0
, "kW" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Heat flow rate into port B" , } , {
"IGBT_F.thermal_port.Tvec" , "IGBTThermal/IGBT_F" , { { 1 , 3 } } , "K" , 1.0
, "K" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_OPTIONAL , FALSE , TRUE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Vector of thermal mass temperatures" ,
} , { "IGBT_F.v" , "IGBTThermal/IGBT_F" , { { 1 , 1 } } , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Collector-emitter voltage" , } , {
"IGBT_F.vT" , "IGBTThermal/IGBT_F" , { { 1 , 1 } } , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "vT" , } , { "IGBT_F.vce" ,
"IGBTThermal/IGBT_F" , { { 1 , 1 } } , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Collector-emitter voltage" , } , {
"IGBT_F.vge" , "IGBTThermal/IGBT_F" , { { 1 , 1 } } , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Gate-emitter voltage" , } , {
"IGBT_F.ziOff" , "IGBTThermal/IGBT_F" , { { 1 , 1 } } , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_FIXED , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Captured current for switch-off loss"
, } , { "IGBT_F.ziOn" , "IGBTThermal/IGBT_F" , { { 1 , 1 } } , "A" , 1.0 ,
"A" , NE_NOMINAL_SOURCE_FIXED , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Captured current for switch-on loss" ,
} , { "IGBT_F.zvOff" , "IGBTThermal/IGBT_F" , { { 1 , 1 } } , "V" , 1.0 , "V"
, NE_NOMINAL_SOURCE_FIXED , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Captured voltage for switch-off loss"
, } , { "IGBT_F.zvOn" , "IGBTThermal/IGBT_F" , { { 1 , 1 } } , "V" , 1.0 ,
"V" , NE_NOMINAL_SOURCE_FIXED , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Captured voltage for switch-on loss" ,
} , { "IGBT_F.internal_mode_var_m__" , "IGBTThermal/IGBT_F" , { { 1 , 1 } } ,
"1" , 1.0 , "1" , NE_NOMINAL_SOURCE_FIXED , NE_INIT_MODE_MANDATORY , TRUE ,
FALSE , NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "internal_mode_var_m__" , } ,
{ "Pulse_generator.Gate_Drive" , "IGBTThermal/Pulse generator" , { { 1 , 1 }
} , "1" , 1.0 , "1" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , FALSE ,
FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Gate_Drive" , } , {
"Pulse_generator.Simulink_PS_Converter_output0" ,
"IGBTThermal/Pulse generator/Simulink-PS\nConverter" , { { 1 , 1 } } , "1" ,
1.0 , "1" , NE_NOMINAL_SOURCE_FIXED , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Simulink_PS_Converter_output0" , } ,
{ "Rgate_C.i" , "IGBTThermal/Rgate_C" , { { 1 , 1 } } , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Current" , } , { "Rgate_C.n.v" ,
"IGBTThermal/Rgate_C" , { { 1 , 1 } } , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , { "Rgate_C.p.v" ,
"IGBTThermal/Rgate_C" , { { 1 , 1 } } , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , { "Rgate_C.v" ,
"IGBTThermal/Rgate_C" , { { 1 , 1 } } , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Rgate_C.power_dissipated" , "IGBTThermal/Rgate_C" , { { 1 , 1 } } ,
"A^2*Ohm" , 1.0 , "A^2*Ohm" , NE_NOMINAL_SOURCE_NONE , NE_INIT_MODE_NONE ,
TRUE , FALSE , NE_FREQTIME_TYPE_TIME , TRUE , FALSE , "Dissipated power" , }
, { "Rgate_F.i" , "IGBTThermal/Rgate_F" , { { 1 , 1 } } , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Current" , } , { "Rgate_F.n.v" ,
"IGBTThermal/Rgate_F" , { { 1 , 1 } } , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , { "Rgate_F.p.v" ,
"IGBTThermal/Rgate_F" , { { 1 , 1 } } , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , { "Rgate_F.v" ,
"IGBTThermal/Rgate_F" , { { 1 , 1 } } , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Voltage" , } , {
"Rgate_F.power_dissipated" , "IGBTThermal/Rgate_F" , { { 1 , 1 } } ,
"A^2*Ohm" , 1.0 , "A^2*Ohm" , NE_NOMINAL_SOURCE_NONE , NE_INIT_MODE_NONE ,
TRUE , FALSE , NE_FREQTIME_TYPE_TIME , TRUE , FALSE , "Dissipated power" , }
, { "Tcase_C.A.T" , "IGBTThermal/Tcase_C" , { { 1 , 1 } } , "K" , 1.0 , "K" ,
NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Temperature" , } , {
"Tcase_C.Ideal_Temperature_Source.A.T" ,
"IGBTThermal/Tcase_C/Ideal Temperature Source" , { { 1 , 1 } } , "K" , 1.0 ,
"K" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Temperature" , } , {
"Tcase_C.Ideal_Temperature_Source.B.T" ,
"IGBTThermal/Tcase_C/Ideal Temperature Source" , { { 1 , 1 } } , "K" , 1.0 ,
"K" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Temperature" , } , {
"Tcase_C.Ideal_Temperature_Source.Q" ,
"IGBTThermal/Tcase_C/Ideal Temperature Source" , { { 1 , 1 } } , "W" , 1.0 ,
"kW" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Heat flow rate" , } , {
"Tcase_C.Ideal_Temperature_Source.S" ,
"IGBTThermal/Tcase_C/Ideal Temperature Source" , { { 1 , 1 } } , "K" , 1.0 ,
"K" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "S" , } , {
"Tcase_C.Ideal_Temperature_Source.T" ,
"IGBTThermal/Tcase_C/Ideal Temperature Source" , { { 1 , 1 } } , "K" , 1.0 ,
"K" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Temperature difference" , } , {
"Tcase_C.Tcase.O" , "IGBTThermal/Tcase_C/Tcase" , { { 1 , 1 } } , "K" , 1.0 ,
"K" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "O" , } , {
"Tcase_C.Thermal_Reference2.H.T" , "IGBTThermal/Tcase_C/Thermal Reference2" ,
{ { 1 , 1 } } , "K" , 1.0 , "K" , NE_NOMINAL_SOURCE_DERIVED ,
NE_INIT_MODE_NONE , TRUE , FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE ,
"Temperature" , } , { "Tcase_F.A.T" , "IGBTThermal/Tcase_F" , { { 1 , 1 } } ,
"K" , 1.0 , "K" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , TRUE ,
FALSE , NE_FREQTIME_TYPE_TIME , FALSE , TRUE , "Temperature" , } , {
"Tcase_F.Ideal_Temperature_Source.A.T" ,
"IGBTThermal/Tcase_F/Ideal Temperature Source" , { { 1 , 1 } } , "K" , 1.0 ,
"K" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Temperature" , } , {
"Tcase_F.Ideal_Temperature_Source.B.T" ,
"IGBTThermal/Tcase_F/Ideal Temperature Source" , { { 1 , 1 } } , "K" , 1.0 ,
"K" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Temperature" , } , {
"Tcase_F.Ideal_Temperature_Source.Q" ,
"IGBTThermal/Tcase_F/Ideal Temperature Source" , { { 1 , 1 } } , "W" , 1.0 ,
"kW" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Heat flow rate" , } , {
"Tcase_F.Ideal_Temperature_Source.S" ,
"IGBTThermal/Tcase_F/Ideal Temperature Source" , { { 1 , 1 } } , "K" , 1.0 ,
"K" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "S" , } , {
"Tcase_F.Ideal_Temperature_Source.T" ,
"IGBTThermal/Tcase_F/Ideal Temperature Source" , { { 1 , 1 } } , "K" , 1.0 ,
"K" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "Temperature difference" , } , {
"Tcase_F.Tcase.O" , "IGBTThermal/Tcase_F/Tcase" , { { 1 , 1 } } , "K" , 1.0 ,
"K" , NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , TRUE , FALSE ,
NE_FREQTIME_TYPE_TIME , TRUE , TRUE , "O" , } , {
"Tcase_F.Thermal_Reference2.H.T" , "IGBTThermal/Tcase_F/Thermal Reference2" ,
{ { 1 , 1 } } , "K" , 1.0 , "K" , NE_NOMINAL_SOURCE_DERIVED ,
NE_INIT_MODE_NONE , TRUE , FALSE , NE_FREQTIME_TYPE_TIME , TRUE , TRUE ,
"Temperature" , } } ; static NeModeData s_major_mode_data [ 3 ] = { {
"IGBT_C.internal_mode_var_m__" , 0U , "IGBTThermal/IGBT_C" , 0 ,
"internal_mode_var_m__" , } , { "IGBT_F.internal_mode_var_m__" , 0U ,
"IGBTThermal/IGBT_F" , 0 , "internal_mode_var_m__" , } , { "ie0" , 0U , "" ,
0 , "" , } } ; static NeZCData s_zc_data [ 50 ] = { {
"IGBTThermal/Buck circuit 1/Diode" , 1U , 0U , "Buck_circuit_1.Diode" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/Buck circuit 2/Diode" , 1U , 1U ,
"Buck_circuit_2.Diode" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_C" , 1U , 2U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_C" , 1U , 3U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_C" , 3U , 4U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_C" , 1U , 7U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_C" , 1U , 8U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_C" , 3U , 9U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_C" , 1U , 12U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_C" , 1U , 13U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_C" , 1U , 14U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_C" , 1U , 15U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_C" , 1U , 16U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_C" , 1U , 17U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_C" , 1U , 18U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_C" , 1U , 19U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_C" , 1U , 20U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_C" , 1U , 21U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_C" , 1U , 22U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_C" , 1U , 23U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_C" , 1U , 24U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_C" , 1U , 25U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_C" , 1U , 26U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_C" , 1U , 27U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_C" , 1U , 28U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_F" , 1U , 29U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_F" , 1U , 30U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_F" , 3U , 31U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_F" , 1U , 34U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_F" , 1U , 35U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_F" , 3U , 36U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_F" , 1U , 39U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_F" , 1U , 40U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_F" , 1U , 41U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_F" , 1U , 42U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_F" , 1U , 43U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_F" , 1U , 44U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_F" , 1U , 45U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_F" , 1U , 46U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_F" , 1U , 47U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_F" , 1U , 48U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_F" , 1U , 49U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_F" , 1U , 50U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_F" , 1U , 51U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_F" , 1U , 52U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_F" , 1U , 53U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_F" , 1U , 54U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_F" , 1U , 55U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, NE_ZC_TYPE_FALSE , } , { "IGBTThermal/IGBT_C" , 1U , 56U ,
"IGBT_C.thermal_port" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+passive/+thermal/cauer_model.sscp"
, NE_ZC_TYPE_TRUE , } , { "IGBTThermal/IGBT_F" , 1U , 57U ,
"IGBT_F.thermal_port" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+passive/+thermal/cauer_model.sscp"
, NE_ZC_TYPE_TRUE , } } ; static NeRange s_range [ 58 ] = { {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+passive/+thermal/cauer_model.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+passive/+thermal/cauer_model.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } } ; static NeAssertData
s_assert_data [ 126 ] = { { "IGBTThermal/IGBT_C" , 1U , 0U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table grid vector are not strictly monotonic" ,
"physmod:common:data2:library:tlu:Nonmotonic" , } , { "IGBTThermal/IGBT_C" ,
1U , 1U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table grid vector are not strictly monotonic" ,
"physmod:common:data2:library:tlu:Nonmotonic" , } , { "IGBTThermal/IGBT_C" ,
1U , 2U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_C" ,
1U , 3U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_C" ,
1U , 4U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_C" ,
1U , 5U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "Require at least two data points in the table" ,
"physmod:common:data2:library:tlu:RequireTwoOrMoreDataPoint" , } , {
"IGBTThermal/IGBT_C" , 1U , 6U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "Require at least two data points in the table" ,
"physmod:common:data2:library:tlu:RequireTwoOrMoreDataPoint" , } , {
"IGBTThermal/IGBT_C" , 1U , 7U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table grid vector are not strictly monotonic" ,
"physmod:common:data2:library:tlu:Nonmotonic" , } , { "IGBTThermal/IGBT_C" ,
1U , 8U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table grid vector are not strictly monotonic" ,
"physmod:common:data2:library:tlu:Nonmotonic" , } , { "IGBTThermal/IGBT_C" ,
1U , 9U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_C" ,
1U , 10U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_C" ,
1U , 11U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_C" ,
1U , 12U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "Require at least two data points in the table" ,
"physmod:common:data2:library:tlu:RequireTwoOrMoreDataPoint" , } , {
"IGBTThermal/IGBT_C" , 1U , 13U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "Require at least two data points in the table" ,
"physmod:common:data2:library:tlu:RequireTwoOrMoreDataPoint" , } , {
"IGBTThermal/IGBT_F" , 1U , 14U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table grid vector are not strictly monotonic" ,
"physmod:common:data2:library:tlu:Nonmotonic" , } , { "IGBTThermal/IGBT_F" ,
1U , 15U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table grid vector are not strictly monotonic" ,
"physmod:common:data2:library:tlu:Nonmotonic" , } , { "IGBTThermal/IGBT_F" ,
1U , 16U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_F" ,
1U , 17U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_F" ,
1U , 18U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_F" ,
1U , 19U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "Require at least two data points in the table" ,
"physmod:common:data2:library:tlu:RequireTwoOrMoreDataPoint" , } , {
"IGBTThermal/IGBT_F" , 1U , 20U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "Require at least two data points in the table" ,
"physmod:common:data2:library:tlu:RequireTwoOrMoreDataPoint" , } , {
"IGBTThermal/IGBT_F" , 1U , 21U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table grid vector are not strictly monotonic" ,
"physmod:common:data2:library:tlu:Nonmotonic" , } , { "IGBTThermal/IGBT_F" ,
1U , 22U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table grid vector are not strictly monotonic" ,
"physmod:common:data2:library:tlu:Nonmotonic" , } , { "IGBTThermal/IGBT_F" ,
1U , 23U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_F" ,
1U , 24U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_F" ,
1U , 25U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_F" ,
1U , 26U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "Require at least two data points in the table" ,
"physmod:common:data2:library:tlu:RequireTwoOrMoreDataPoint" , } , {
"IGBTThermal/IGBT_F" , 1U , 27U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "Require at least two data points in the table" ,
"physmod:common:data2:library:tlu:RequireTwoOrMoreDataPoint" , } , {
"IGBTThermal/IGBT_C" , 2U , 28U , "IGBT_C.thermal_port" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE ,
 "Elements of Vector of thermal mass temperatures must be greater than or equal to {0, 'K'}."
, "physmod:simscape:compiler:patterns:checks:ArrayGreaterThanOrEqual" , } , {
"IGBTThermal/IGBT_C" , 1U , 30U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "Temperature must be greater than absolute zero." ,
"physmod:ee:library:TemperatureGreaterThanZero" , } , { "IGBTThermal/IGBT_C"
, 1U , 31U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE ,
 "Mode value is out of range for 'internal_mode_var_m__'.  Mode must be between 1 and 9."
, "physmod:simscape:compiler:core:sf_xform:ModeValueOutOfRange" , } , {
"IGBTThermal/IGBT_C" , 1U , 32U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table grid vector are not strictly monotonic" ,
"physmod:common:data2:library:tlu:Nonmotonic" , } , { "IGBTThermal/IGBT_C" ,
1U , 33U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table grid vector are not strictly monotonic" ,
"physmod:common:data2:library:tlu:Nonmotonic" , } , { "IGBTThermal/IGBT_C" ,
1U , 34U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_C" ,
1U , 35U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_C" ,
1U , 36U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_C" ,
1U , 37U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "Require at least three data points in the table" ,
"physmod:common:data2:library:tlu:RequireThreeOrMoreDataPoint" , } , {
"IGBTThermal/IGBT_C" , 1U , 38U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "Require at least three data points in the table" ,
"physmod:common:data2:library:tlu:RequireThreeOrMoreDataPoint" , } , {
"IGBTThermal/IGBT_C" , 1U , 39U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table grid vector are not strictly monotonic" ,
"physmod:common:data2:library:tlu:Nonmotonic" , } , { "IGBTThermal/IGBT_C" ,
1U , 40U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table grid vector are not strictly monotonic" ,
"physmod:common:data2:library:tlu:Nonmotonic" , } , { "IGBTThermal/IGBT_C" ,
1U , 41U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_C" ,
1U , 42U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_C" ,
1U , 43U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_C" ,
1U , 44U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "Require at least three data points in the table" ,
"physmod:common:data2:library:tlu:RequireThreeOrMoreDataPoint" , } , {
"IGBTThermal/IGBT_C" , 1U , 45U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "Require at least three data points in the table" ,
"physmod:common:data2:library:tlu:RequireThreeOrMoreDataPoint" , } , {
"IGBTThermal/IGBT_C" , 1U , 46U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table grid vector are not strictly monotonic" ,
"physmod:common:data2:library:tlu:Nonmotonic" , } , { "IGBTThermal/IGBT_C" ,
1U , 47U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table grid vector are not strictly monotonic" ,
"physmod:common:data2:library:tlu:Nonmotonic" , } , { "IGBTThermal/IGBT_C" ,
1U , 48U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_C" ,
1U , 49U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_C" ,
1U , 50U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_C" ,
1U , 51U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "Require at least three data points in the table" ,
"physmod:common:data2:library:tlu:RequireThreeOrMoreDataPoint" , } , {
"IGBTThermal/IGBT_C" , 1U , 52U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "Require at least three data points in the table" ,
"physmod:common:data2:library:tlu:RequireThreeOrMoreDataPoint" , } , {
"IGBTThermal/IGBT_C" , 1U , 53U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table grid vector are not strictly monotonic" ,
"physmod:common:data2:library:tlu:Nonmotonic" , } , { "IGBTThermal/IGBT_C" ,
1U , 54U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table grid vector are not strictly monotonic" ,
"physmod:common:data2:library:tlu:Nonmotonic" , } , { "IGBTThermal/IGBT_C" ,
1U , 55U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_C" ,
1U , 56U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_C" ,
1U , 57U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_C" ,
1U , 58U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "Require at least three data points in the table" ,
"physmod:common:data2:library:tlu:RequireThreeOrMoreDataPoint" , } , {
"IGBTThermal/IGBT_C" , 1U , 59U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "Require at least three data points in the table" ,
"physmod:common:data2:library:tlu:RequireThreeOrMoreDataPoint" , } , {
"IGBTThermal/IGBT_F" , 2U , 60U , "IGBT_F.thermal_port" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE ,
 "Elements of Vector of thermal mass temperatures must be greater than or equal to {0, 'K'}."
, "physmod:simscape:compiler:patterns:checks:ArrayGreaterThanOrEqual" , } , {
"IGBTThermal/IGBT_F" , 1U , 62U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "Temperature must be greater than absolute zero." ,
"physmod:ee:library:TemperatureGreaterThanZero" , } , { "IGBTThermal/IGBT_F"
, 1U , 63U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE ,
 "Mode value is out of range for 'internal_mode_var_m__'.  Mode must be between 1 and 9."
, "physmod:simscape:compiler:core:sf_xform:ModeValueOutOfRange" , } , {
"IGBTThermal/IGBT_F" , 1U , 64U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table grid vector are not strictly monotonic" ,
"physmod:common:data2:library:tlu:Nonmotonic" , } , { "IGBTThermal/IGBT_F" ,
1U , 65U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table grid vector are not strictly monotonic" ,
"physmod:common:data2:library:tlu:Nonmotonic" , } , { "IGBTThermal/IGBT_F" ,
1U , 66U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_F" ,
1U , 67U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_F" ,
1U , 68U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_F" ,
1U , 69U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "Require at least three data points in the table" ,
"physmod:common:data2:library:tlu:RequireThreeOrMoreDataPoint" , } , {
"IGBTThermal/IGBT_F" , 1U , 70U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "Require at least three data points in the table" ,
"physmod:common:data2:library:tlu:RequireThreeOrMoreDataPoint" , } , {
"IGBTThermal/IGBT_F" , 1U , 71U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table grid vector are not strictly monotonic" ,
"physmod:common:data2:library:tlu:Nonmotonic" , } , { "IGBTThermal/IGBT_F" ,
1U , 72U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table grid vector are not strictly monotonic" ,
"physmod:common:data2:library:tlu:Nonmotonic" , } , { "IGBTThermal/IGBT_F" ,
1U , 73U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_F" ,
1U , 74U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_F" ,
1U , 75U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_F" ,
1U , 76U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "Require at least three data points in the table" ,
"physmod:common:data2:library:tlu:RequireThreeOrMoreDataPoint" , } , {
"IGBTThermal/IGBT_F" , 1U , 77U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "Require at least three data points in the table" ,
"physmod:common:data2:library:tlu:RequireThreeOrMoreDataPoint" , } , {
"IGBTThermal/IGBT_F" , 1U , 78U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table grid vector are not strictly monotonic" ,
"physmod:common:data2:library:tlu:Nonmotonic" , } , { "IGBTThermal/IGBT_F" ,
1U , 79U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table grid vector are not strictly monotonic" ,
"physmod:common:data2:library:tlu:Nonmotonic" , } , { "IGBTThermal/IGBT_F" ,
1U , 80U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_F" ,
1U , 81U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_F" ,
1U , 82U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_F" ,
1U , 83U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "Require at least three data points in the table" ,
"physmod:common:data2:library:tlu:RequireThreeOrMoreDataPoint" , } , {
"IGBTThermal/IGBT_F" , 1U , 84U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "Require at least three data points in the table" ,
"physmod:common:data2:library:tlu:RequireThreeOrMoreDataPoint" , } , {
"IGBTThermal/IGBT_F" , 1U , 85U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table grid vector are not strictly monotonic" ,
"physmod:common:data2:library:tlu:Nonmotonic" , } , { "IGBTThermal/IGBT_F" ,
1U , 86U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table grid vector are not strictly monotonic" ,
"physmod:common:data2:library:tlu:Nonmotonic" , } , { "IGBTThermal/IGBT_F" ,
1U , 87U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_F" ,
1U , 88U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_F" ,
1U , 89U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "The values in the table must be finite( no nan or inf allowed )" ,
"physmod:common:data2:library:tlu:Nonfinite" , } , { "IGBTThermal/IGBT_F" ,
1U , 90U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "Require at least three data points in the table" ,
"physmod:common:data2:library:tlu:RequireThreeOrMoreDataPoint" , } , {
"IGBTThermal/IGBT_F" , 1U , 91U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "Require at least three data points in the table" ,
"physmod:common:data2:library:tlu:RequireThreeOrMoreDataPoint" , } , {
"IGBTThermal/Buck circuit 1/Capacitor" , 1U , 92U ,
"Buck_circuit_1.Capacitor.power_dissipated" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, FALSE ,
"In power, the exponent must be positive when the base is equal to zero." ,
"physmod:common:mf:expr:analyze:RequireExponentPositive" , } , {
"IGBTThermal/Buck circuit 1/Capacitor" , 1U , 93U ,
"Buck_circuit_1.Capacitor.power_dissipated" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, FALSE ,
"In power, the base must be nonnegative when the exponent is not an integer."
, "physmod:common:mf:expr:analyze:RequireBaseNonnegative" , } , {
"IGBTThermal/Buck circuit 1/Capacitor" , 1U , 94U ,
"Buck_circuit_1.Capacitor.power_dissipated" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, FALSE ,
"In power, the exponent must be positive when the base is equal to zero." ,
"physmod:common:mf:expr:analyze:RequireExponentPositive" , } , {
"IGBTThermal/Buck circuit 1/Capacitor" , 1U , 95U ,
"Buck_circuit_1.Capacitor.power_dissipated" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, FALSE ,
"In power, the base must be nonnegative when the exponent is not an integer."
, "physmod:common:mf:expr:analyze:RequireBaseNonnegative" , } , {
"IGBTThermal/Buck circuit 1/Inductor" , 1U , 96U ,
"Buck_circuit_1.Inductor.power_dissipated" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/inductor.ssc"
, FALSE ,
"In power, the exponent must be positive when the base is equal to zero." ,
"physmod:common:mf:expr:analyze:RequireExponentPositive" , } , {
"IGBTThermal/Buck circuit 1/Inductor" , 1U , 97U ,
"Buck_circuit_1.Inductor.power_dissipated" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/inductor.ssc"
, FALSE ,
"In power, the base must be nonnegative when the exponent is not an integer."
, "physmod:common:mf:expr:analyze:RequireBaseNonnegative" , } , {
"IGBTThermal/Buck circuit 1/Inductor" , 1U , 98U ,
"Buck_circuit_1.Inductor.power_dissipated" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/inductor.ssc"
, FALSE ,
"In power, the exponent must be positive when the base is equal to zero." ,
"physmod:common:mf:expr:analyze:RequireExponentPositive" , } , {
"IGBTThermal/Buck circuit 1/Inductor" , 1U , 99U ,
"Buck_circuit_1.Inductor.power_dissipated" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/inductor.ssc"
, FALSE ,
"In power, the base must be nonnegative when the exponent is not an integer."
, "physmod:common:mf:expr:analyze:RequireBaseNonnegative" , } , {
"IGBTThermal/Buck circuit 1/Load" , 1U , 100U ,
"Buck_circuit_1.Load.power_dissipated" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/resistor.ssc"
, FALSE ,
"In power, the exponent must be positive when the base is equal to zero." ,
"physmod:common:mf:expr:analyze:RequireExponentPositive" , } , {
"IGBTThermal/Buck circuit 1/Load" , 1U , 101U ,
"Buck_circuit_1.Load.power_dissipated" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/resistor.ssc"
, FALSE ,
"In power, the base must be nonnegative when the exponent is not an integer."
, "physmod:common:mf:expr:analyze:RequireBaseNonnegative" , } , {
"IGBTThermal/Buck circuit 2/Capacitor" , 1U , 102U ,
"Buck_circuit_2.Capacitor.power_dissipated" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, FALSE ,
"In power, the exponent must be positive when the base is equal to zero." ,
"physmod:common:mf:expr:analyze:RequireExponentPositive" , } , {
"IGBTThermal/Buck circuit 2/Capacitor" , 1U , 103U ,
"Buck_circuit_2.Capacitor.power_dissipated" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, FALSE ,
"In power, the base must be nonnegative when the exponent is not an integer."
, "physmod:common:mf:expr:analyze:RequireBaseNonnegative" , } , {
"IGBTThermal/Buck circuit 2/Capacitor" , 1U , 104U ,
"Buck_circuit_2.Capacitor.power_dissipated" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, FALSE ,
"In power, the exponent must be positive when the base is equal to zero." ,
"physmod:common:mf:expr:analyze:RequireExponentPositive" , } , {
"IGBTThermal/Buck circuit 2/Capacitor" , 1U , 105U ,
"Buck_circuit_2.Capacitor.power_dissipated" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, FALSE ,
"In power, the base must be nonnegative when the exponent is not an integer."
, "physmod:common:mf:expr:analyze:RequireBaseNonnegative" , } , {
"IGBTThermal/Buck circuit 2/Inductor" , 1U , 106U ,
"Buck_circuit_2.Inductor.power_dissipated" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/inductor.ssc"
, FALSE ,
"In power, the exponent must be positive when the base is equal to zero." ,
"physmod:common:mf:expr:analyze:RequireExponentPositive" , } , {
"IGBTThermal/Buck circuit 2/Inductor" , 1U , 107U ,
"Buck_circuit_2.Inductor.power_dissipated" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/inductor.ssc"
, FALSE ,
"In power, the base must be nonnegative when the exponent is not an integer."
, "physmod:common:mf:expr:analyze:RequireBaseNonnegative" , } , {
"IGBTThermal/Buck circuit 2/Inductor" , 1U , 108U ,
"Buck_circuit_2.Inductor.power_dissipated" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/inductor.ssc"
, FALSE ,
"In power, the exponent must be positive when the base is equal to zero." ,
"physmod:common:mf:expr:analyze:RequireExponentPositive" , } , {
"IGBTThermal/Buck circuit 2/Inductor" , 1U , 109U ,
"Buck_circuit_2.Inductor.power_dissipated" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/inductor.ssc"
, FALSE ,
"In power, the base must be nonnegative when the exponent is not an integer."
, "physmod:common:mf:expr:analyze:RequireBaseNonnegative" , } , {
"IGBTThermal/Buck circuit 2/Load" , 1U , 110U ,
"Buck_circuit_2.Load.power_dissipated" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/resistor.ssc"
, FALSE ,
"In power, the exponent must be positive when the base is equal to zero." ,
"physmod:common:mf:expr:analyze:RequireExponentPositive" , } , {
"IGBTThermal/Buck circuit 2/Load" , 1U , 111U ,
"Buck_circuit_2.Load.power_dissipated" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/resistor.ssc"
, FALSE ,
"In power, the base must be nonnegative when the exponent is not an integer."
, "physmod:common:mf:expr:analyze:RequireBaseNonnegative" , } , {
"IGBTThermal/IGBT_C" , 1U , 112U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "In divide, the denominator must be nonzero." ,
"physmod:common:mf:expr:analyze:RequireDenominatorNonzero" , } , {
"IGBTThermal/IGBT_C" , 1U , 113U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "In divide, the denominator must be nonzero." ,
"physmod:common:mf:expr:analyze:RequireDenominatorNonzero" , } , {
"IGBTThermal/IGBT_F" , 1U , 114U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "In divide, the denominator must be nonzero." ,
"physmod:common:mf:expr:analyze:RequireDenominatorNonzero" , } , {
"IGBTThermal/IGBT_F" , 1U , 115U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "In divide, the denominator must be nonzero." ,
"physmod:common:mf:expr:analyze:RequireDenominatorNonzero" , } , {
"IGBTThermal/Buck circuit 1/Diode" , 1U , 116U , "Buck_circuit_1.Diode" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, FALSE , "In divide, the denominator must be nonzero." ,
"physmod:common:mf:expr:analyze:RequireDenominatorNonzero" , } , {
"IGBTThermal/Buck circuit 1/Diode" , 1U , 117U , "Buck_circuit_1.Diode" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, FALSE , "In divide, the denominator must be nonzero." ,
"physmod:common:mf:expr:analyze:RequireDenominatorNonzero" , } , {
"IGBTThermal/Buck circuit 1/Diode" , 1U , 118U , "Buck_circuit_1.Diode" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, FALSE , "In divide, the denominator must be nonzero." ,
"physmod:common:mf:expr:analyze:RequireDenominatorNonzero" , } , {
"IGBTThermal/Buck circuit 1/Diode" , 1U , 119U , "Buck_circuit_1.Diode" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, FALSE , "In divide, the denominator must be nonzero." ,
"physmod:common:mf:expr:analyze:RequireDenominatorNonzero" , } , {
"IGBTThermal/Buck circuit 2/Diode" , 1U , 120U , "Buck_circuit_2.Diode" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, FALSE , "In divide, the denominator must be nonzero." ,
"physmod:common:mf:expr:analyze:RequireDenominatorNonzero" , } , {
"IGBTThermal/Buck circuit 2/Diode" , 1U , 121U , "Buck_circuit_2.Diode" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, FALSE , "In divide, the denominator must be nonzero." ,
"physmod:common:mf:expr:analyze:RequireDenominatorNonzero" , } , {
"IGBTThermal/Buck circuit 2/Diode" , 1U , 122U , "Buck_circuit_2.Diode" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, FALSE , "In divide, the denominator must be nonzero." ,
"physmod:common:mf:expr:analyze:RequireDenominatorNonzero" , } , {
"IGBTThermal/Buck circuit 2/Diode" , 1U , 123U , "Buck_circuit_2.Diode" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, FALSE , "In divide, the denominator must be nonzero." ,
"physmod:common:mf:expr:analyze:RequireDenominatorNonzero" , } , {
"IGBTThermal/IGBT_C" , 1U , 124U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "In divide, the denominator must be nonzero." ,
"physmod:common:mf:expr:analyze:RequireDenominatorNonzero" , } , {
"IGBTThermal/IGBT_C" , 1U , 125U , "IGBT_C" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "In divide, the denominator must be nonzero." ,
"physmod:common:mf:expr:analyze:RequireDenominatorNonzero" , } , {
"IGBTThermal/IGBT_F" , 1U , 126U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "In divide, the denominator must be nonzero." ,
"physmod:common:mf:expr:analyze:RequireDenominatorNonzero" , } , {
"IGBTThermal/IGBT_F" , 1U , 127U , "IGBT_F" ,
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, FALSE , "In divide, the denominator must be nonzero." ,
"physmod:common:mf:expr:analyze:RequireDenominatorNonzero" , } } ; static
NeRange s_assert_range [ 128 ] = { {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+passive/+thermal/cauer_model.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+passive/+thermal/cauer_model.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 26U , 29U , 26U , 30U , NE_RANGE_TYPE_NORMAL , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 26U , 27U , 26U , 28U , NE_RANGE_TYPE_NORMAL , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 26U , 36U , 26U , 37U , NE_RANGE_TYPE_NORMAL , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 26U , 33U , 26U , 35U , NE_RANGE_TYPE_NORMAL , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/inductor.ssc"
, 25U , 31U , 25U , 32U , NE_RANGE_TYPE_NORMAL , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/inductor.ssc"
, 25U , 27U , 25U , 30U , NE_RANGE_TYPE_NORMAL , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/inductor.ssc"
, 25U , 39U , 25U , 40U , NE_RANGE_TYPE_NORMAL , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/inductor.ssc"
, 25U , 37U , 25U , 38U , NE_RANGE_TYPE_NORMAL , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/resistor.ssc"
, 20U , 29U , 20U , 30U , NE_RANGE_TYPE_NORMAL , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/resistor.ssc"
, 20U , 27U , 20U , 28U , NE_RANGE_TYPE_NORMAL , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 26U , 29U , 26U , 30U , NE_RANGE_TYPE_NORMAL , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 26U , 27U , 26U , 28U , NE_RANGE_TYPE_NORMAL , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 26U , 36U , 26U , 37U , NE_RANGE_TYPE_NORMAL , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 26U , 33U , 26U , 35U , NE_RANGE_TYPE_NORMAL , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/inductor.ssc"
, 25U , 31U , 25U , 32U , NE_RANGE_TYPE_NORMAL , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/inductor.ssc"
, 25U , 27U , 25U , 30U , NE_RANGE_TYPE_NORMAL , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/inductor.ssc"
, 25U , 39U , 25U , 40U , NE_RANGE_TYPE_NORMAL , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/inductor.ssc"
, 25U , 37U , 25U , 38U , NE_RANGE_TYPE_NORMAL , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/resistor.ssc"
, 20U , 29U , 20U , 30U , NE_RANGE_TYPE_NORMAL , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/resistor.ssc"
, 20U , 27U , 20U , 28U , NE_RANGE_TYPE_NORMAL , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } } ; static NeAssertData *
s_param_assert_data = NULL ; static NeRange * s_param_assert_range = NULL ;
static NeAssertData * s_initial_assert_data = NULL ; static NeRange *
s_initial_assert_range = NULL ; static NeRange s_equation_range [ 82 ] = { {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 36U , 5U , 36U , 25U , NE_RANGE_TYPE_NORMAL , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/inductor.ssc"
, 34U , 5U , 34U , 23U , NE_RANGE_TYPE_NORMAL , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/inductor.ssc"
, 34U , 20U , 34U , 27U , NE_RANGE_TYPE_NORMAL , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 36U , 5U , 36U , 25U , NE_RANGE_TYPE_NORMAL , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/inductor.ssc"
, 34U , 5U , 34U , 23U , NE_RANGE_TYPE_NORMAL , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/inductor.ssc"
, 34U , 20U , 34U , 27U , NE_RANGE_TYPE_NORMAL , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+passive/+thermal/cauer_model.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/junction_thermal_mass.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+passive/+thermal/cauer_model.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/diode_base.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+passive/+thermal/cauer_model.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } } ; static NeRange *
s_cer_range = NULL ; static NeRange s_icr_range [ 2 ] = { {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "D:/Vishal/Mathworks/MATLAB/R2023b/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/igbt_thermal.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } } ; static NeParameterData
* s_logical_parameter_data = NULL ; static NeParameterData *
s_integer_parameter_data = NULL ; static NeParameterData *
s_index_parameter_data = NULL ; static NeParameterData s_real_parameter_data
[ 6 ] = { { "RTP_56B3C423_vc" , "IGBTThermal/Buck circuit 1/Capacitor" , "" ,
0U , 1U , TRUE , } , { "RTP_21B4F4B5_i_L" ,
"IGBTThermal/Buck circuit 1/Inductor" , "" , 0U , 1U , TRUE , } , {
"RTP_E3A2801C_vc" , "IGBTThermal/Buck circuit 2/Capacitor" , "" , 0U , 1U ,
TRUE , } , { "RTP_ECBB6219_i_L" , "IGBTThermal/Buck circuit 2/Inductor" , ""
, 0U , 1U , TRUE , } , { "RTP_946ABF09_junction_temperature" ,
"IGBTThermal/IGBT_F" , "" , 0U , 1U , TRUE , } , {
"RTP_E56942F7_junction_temperature" , "IGBTThermal/IGBT_C" , "" , 0U , 1U ,
TRUE , } } ; static real_T s_constant_table0 [ 14 ] = { 0.0 , 0.0 , 0.00021 ,
0.00043 , 0.00107 , 0.00197 , 0.00214 , 0.00386 , 0.00429 , 0.00771 ,
0.009859999999999999 , 0.01543 , 0.01714 , 0.02271 } ; static real_T
s_constant_table1 [ 108 ] = { - 20000.0 , - 20000.0 , - 20000.0 , - 10000.0 ,
- 10000.0 , - 10000.0 , 0.0 , 0.0 , 0.0 , 1.1 , 1.05 , 1.0 , 1.3 , 1.225 ,
1.15 , 1.45 , 1.4 , 1.35 , 1.75 , 1.725 , 1.7 , 2.25 , 2.3 , 2.35 , 2.7 ,
2.85 , 3.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , -
0.0010000000000000009 , - 0.0010000000000000009 , - 0.0010000000000000009 , -
0.001499999999999997 , - 0.0015000000000000013 , - 0.0015000000000000057 , -
0.0010000000000000031 , - 0.00099999999999999872 , - 0.00099999999999999438 ,
- 0.00049999999999999611 , - 0.00050000000000000044 , -
0.00050000000000000478 , 0.00099999999999999221 , 0.0010000000000000009 ,
0.0010000000000000096 , 0.0029999999999999983 , 0.0029999999999999983 ,
0.0029999999999999983 , 100000.0 , 100000.0 , 100000.0 , 100000.0 , 100000.0
, 100000.0 , 0.27249955718821961 , 0.26031209570277636 , 0.24812463246538818
, 0.0050000042000013711 , 0.004375003228386444 , 0.0037500026468758069 ,
0.0030362537764350439 , 0.0035199567440031428 , 0.0039930270713699791 , 0.003
, 0.0033541666666666663 , 0.0037338709677419354 , 0.0027333333333333333 ,
0.0030428571428571427 , 0.003358333333333333 , 0.002355555555555556 ,
0.00280625 , 0.00325 , 0.0021118421052631589 , 0.0026847222222222246 ,
0.0032499999999999985 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
- 1.2500003500001045e-5 , - 1.250000280729257e-5 , - 1.2500002406250855e-5 ,
9.592145015105622e-6 , 9.4868265827763011e-6 , 9.3724364232980022e-6 ,
6.7567567567567592e-6 , 7.0833333333333457e-6 , 7.3387096774194016e-6 ,
6.3333333333333342e-6 , 6.3809523809523759e-6 , 6.4166666666666631e-6 ,
8.9444444444444358e-6 , 8.8749999999999972e-6 , 8.8181818181818237e-6 ,
1.13815789473685e-5 , 1.1305555555555533e-5 , 1.124999999999988e-5 } ; static
real_T s_constant_table2 [ 14 ] = { 0.0 , 0.0 , 0.00029 , 0.00057 , 0.00143 ,
0.00263 , 0.00286 , 0.00514 , 0.00571 , 0.01029 , 0.01314 , 0.02057 , 0.02286
, 0.03029 } ; static NeDsMethodOutput * ds_output_m_p ( const NeDynamicSystem
* ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out
= ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mM_P . mNumCol = 26 ; out -> mM_P . mNumRow
= 26 ; out -> mM_P . mJc = ( int32_T * ) allocator -> mCallocFcn ( allocator
, sizeof ( int32_T ) , 27 ) ; out -> mM_P . mIr = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 25 ) ; return out ; } static
NeDsMethodOutput * ds_output_m ( const NeDynamicSystem * ds , PmAllocator *
allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput
* ) allocator -> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ;
out -> mM . mN = 25 ; out -> mM . mX = ( real_T * ) allocator -> mCallocFcn (
allocator , sizeof ( real_T ) , 25 ) ; return out ; } static NeDsMethodOutput
* ds_output_vmm ( const NeDynamicSystem * ds , PmAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mVMM .
mN = 25 ; out -> mVMM . mX = ( boolean_T * ) allocator -> mCallocFcn (
allocator , sizeof ( boolean_T ) , 25 ) ; return out ; } static
NeDsMethodOutput * ds_output_dxm_p ( const NeDynamicSystem * ds , PmAllocator
* allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDXM_P . mNumCol = 26 ; out -> mDXM_P .
mNumRow = 25 ; out -> mDXM_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 27 ) ; out -> mDXM_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ; return out ;
} static NeDsMethodOutput * ds_output_dxm ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDXM . mN = 0 ; out -> mDXM . mX = ( real_T
* ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 ) ; return
out ; } static NeDsMethodOutput * ds_output_ddm_p ( const NeDynamicSystem *
ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out =
( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDDM_P . mNumCol = 14 ; out -> mDDM_P .
mNumRow = 25 ; out -> mDDM_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 15 ) ; out -> mDDM_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ; return out ;
} static NeDsMethodOutput * ds_output_ddm ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDDM . mN = 0 ; out -> mDDM . mX = ( real_T
* ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 ) ; return
out ; } static NeDsMethodOutput * ds_output_dum_p ( const NeDynamicSystem *
ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out =
( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDUM_P . mNumCol = 1 ; out -> mDUM_P .
mNumRow = 25 ; out -> mDUM_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 2 ) ; out -> mDUM_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ; return out ;
} static NeDsMethodOutput * ds_output_dum ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDUM . mN = 0 ; out -> mDUM . mX = ( real_T
* ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 ) ; return
out ; } static NeDsMethodOutput * ds_output_dtm_p ( const NeDynamicSystem *
ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out =
( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDTM_P . mNumCol = 1 ; out -> mDTM_P .
mNumRow = 25 ; out -> mDTM_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 2 ) ; out -> mDTM_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ; return out ;
} static NeDsMethodOutput * ds_output_dtm ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDTM . mN = 0 ; out -> mDTM . mX = ( real_T
* ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 ) ; return
out ; } static NeDsMethodOutput * ds_output_dpm_p ( const NeDynamicSystem *
ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out =
( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDPM_P . mNumCol = 6 ; out -> mDPM_P .
mNumRow = 25 ; out -> mDPM_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 7 ) ; out -> mDPM_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ; return out ;
} static NeDsMethodOutput * ds_output_dpm ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDPM . mN = 0 ; out -> mDPM . mX = ( real_T
* ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 ) ; return
out ; } static NeDsMethodOutput * ds_output_a_p ( const NeDynamicSystem * ds
, PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mA_P . mNumCol = 26 ; out -> mA_P . mNumRow
= 26 ; out -> mA_P . mJc = ( int32_T * ) allocator -> mCallocFcn ( allocator
, sizeof ( int32_T ) , 27 ) ; out -> mA_P . mIr = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 52 ) ; return out ; } static
NeDsMethodOutput * ds_output_a ( const NeDynamicSystem * ds , PmAllocator *
allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput
* ) allocator -> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ;
out -> mA . mN = 52 ; out -> mA . mX = ( real_T * ) allocator -> mCallocFcn (
allocator , sizeof ( real_T ) , 52 ) ; return out ; } static NeDsMethodOutput
* ds_output_b_p ( const NeDynamicSystem * ds , PmAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mB_P .
mNumCol = 1 ; out -> mB_P . mNumRow = 26 ; out -> mB_P . mJc = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 2 ) ; out -> mB_P
. mIr = ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T
) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_b ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mB . mN = 0 ; out -> mB . mX = (
real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_c_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mC_P . mNumCol = 1 ; out -> mC_P
. mNumRow = 26 ; out -> mC_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 2 ) ; out -> mC_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ; return out ;
} static NeDsMethodOutput * ds_output_c ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mC . mN = 0 ; out -> mC . mX = ( real_T * )
allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 ) ; return out ;
} static NeDsMethodOutput * ds_output_f ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mF . mN = 26 ; out -> mF . mX = ( real_T *
) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 26 ) ; return out
; } static NeDsMethodOutput * ds_output_vmf ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mVMF . mN = 26 ; out -> mVMF . mX = (
boolean_T * ) allocator -> mCallocFcn ( allocator , sizeof ( boolean_T ) , 26
) ; return out ; } static NeDsMethodOutput * ds_output_vpf ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mVPF . mN = 26 ; out -> mVPF .
mX = ( boolean_T * ) allocator -> mCallocFcn ( allocator , sizeof ( boolean_T
) , 26 ) ; return out ; } static NeDsMethodOutput * ds_output_vsf ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mVSF . mN = 26 ; out -> mVSF .
mX = ( boolean_T * ) allocator -> mCallocFcn ( allocator , sizeof ( boolean_T
) , 26 ) ; return out ; } static NeDsMethodOutput * ds_output_slf ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mSLF . mN = 26 ; out -> mSLF .
mX = ( boolean_T * ) allocator -> mCallocFcn ( allocator , sizeof ( boolean_T
) , 26 ) ; return out ; } static NeDsMethodOutput * ds_output_slf0 ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mSLF0 . mN = 26 ; out -> mSLF0 .
mX = ( boolean_T * ) allocator -> mCallocFcn ( allocator , sizeof ( boolean_T
) , 26 ) ; return out ; } static NeDsMethodOutput * ds_output_dxf_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDXF_P . mNumCol = 26 ; out ->
mDXF_P . mNumRow = 26 ; out -> mDXF_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 27 ) ; out -> mDXF_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 36 ) ;
return out ; } static NeDsMethodOutput * ds_output_dxf ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDXF . mN = 36 ; out -> mDXF .
mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) ,
36 ) ; return out ; } static NeDsMethodOutput * ds_output_duf_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDUF_P . mNumCol = 1 ; out ->
mDUF_P . mNumRow = 26 ; out -> mDUF_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 2 ) ; out -> mDUF_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_duf ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDUF . mN = 0 ; out -> mDUF . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_dtf_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDTF_P . mNumCol = 1 ; out ->
mDTF_P . mNumRow = 26 ; out -> mDTF_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 2 ) ; out -> mDTF_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_dtf ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDTF . mN = 0 ; out -> mDTF . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_ddf_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDDF_P . mNumCol = 14 ; out ->
mDDF_P . mNumRow = 26 ; out -> mDDF_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 15 ) ; out -> mDDF_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 4 ) ;
return out ; } static NeDsMethodOutput * ds_output_ddf ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDDF . mN = 4 ; out -> mDDF . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 4 )
; return out ; } static NeDsMethodOutput * ds_output_dpdxf_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDPDXF_P . mNumCol = 6 ; out ->
mDPDXF_P . mNumRow = 36 ; out -> mDPDXF_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 7 ) ; out -> mDPDXF_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_dpdxf ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDPDXF . mN = 0 ; out -> mDPDXF
. mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) ,
0 ) ; return out ; } static NeDsMethodOutput * ds_output_dwf_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDWF_P . mNumCol = 0 ; out ->
mDWF_P . mNumRow = 26 ; out -> mDWF_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 1 ) ; out -> mDWF_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_dwf ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDWF . mN = 0 ; out -> mDWF . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_tduf_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mTDUF_P . mNumCol = 1 ; out ->
mTDUF_P . mNumRow = 26 ; out -> mTDUF_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 2 ) ; out -> mTDUF_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_tdxf_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mTDXF_P . mNumCol = 26 ; out ->
mTDXF_P . mNumRow = 26 ; out -> mTDXF_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 27 ) ; out -> mTDXF_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 88 ) ;
return out ; } static NeDsMethodOutput * ds_output_dnf_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDNF_P . mNumCol = 8 ; out ->
mDNF_P . mNumRow = 26 ; out -> mDNF_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 9 ) ; out -> mDNF_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_dnf ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDNF . mN = 0 ; out -> mDNF . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_dnf_v_x ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDNF_V_X . mN = 26 ; out ->
mDNF_V_X . mX = ( boolean_T * ) allocator -> mCallocFcn ( allocator , sizeof
( boolean_T ) , 26 ) ; return out ; } static NeDsMethodOutput * ds_output_cer
( const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mCER . mN = 0 ; out ->
mCER . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof (
real_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_dxcer (
const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDXCER . mN = 0 ; out
-> mDXCER . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof (
real_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_dxcer_p (
const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDXCER_P . mNumCol =
26 ; out -> mDXCER_P . mNumRow = 0 ; out -> mDXCER_P . mJc = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 27 ) ; out ->
mDXCER_P . mIr = ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof (
int32_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_ddcer (
const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDDCER . mN = 0 ; out
-> mDDCER . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof (
real_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_ddcer_p (
const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDDCER_P . mNumCol =
14 ; out -> mDDCER_P . mNumRow = 0 ; out -> mDDCER_P . mJc = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 15 ) ; out ->
mDDCER_P . mIr = ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof (
int32_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_ic (
const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mIC . mN = 26 ; out ->
mIC . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T
) , 26 ) ; return out ; } static NeDsMethodOutput * ds_output_icr ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mICR . mN = 2 ; out -> mICR . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 2 )
; return out ; } static NeDsMethodOutput * ds_output_icr_im ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mICR_IM . mN = 2 ; out ->
mICR_IM . mX = ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof (
int32_T ) , 2 ) ; return out ; } static NeDsMethodOutput * ds_output_icr_id (
const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mICR_ID . mN = 2 ; out
-> mICR_ID . mX = ( boolean_T * ) allocator -> mCallocFcn ( allocator ,
sizeof ( boolean_T ) , 2 ) ; return out ; } static NeDsMethodOutput *
ds_output_icr_il ( const NeDynamicSystem * ds , PmAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out ->
mICR_IL . mN = 2 ; out -> mICR_IL . mX = ( boolean_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( boolean_T ) , 2 ) ; return out ; } static
NeDsMethodOutput * ds_output_dxicr ( const NeDynamicSystem * ds , PmAllocator
* allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDXICR . mN = 6 ; out -> mDXICR . mX = (
real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 6 ) ;
return out ; } static NeDsMethodOutput * ds_output_dxicr_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDXICR_P . mNumCol = 26 ; out ->
mDXICR_P . mNumRow = 2 ; out -> mDXICR_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 27 ) ; out -> mDXICR_P . mIr =
( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 6 )
; return out ; } static NeDsMethodOutput * ds_output_ddicr ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDDICR . mN = 0 ; out -> mDDICR
. mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) ,
0 ) ; return out ; } static NeDsMethodOutput * ds_output_ddicr_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDDICR_P . mNumCol = 14 ; out ->
mDDICR_P . mNumRow = 2 ; out -> mDDICR_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 15 ) ; out -> mDDICR_P . mIr =
( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_tduicr_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mTDUICR_P . mNumCol = 1 ; out ->
mTDUICR_P . mNumRow = 2 ; out -> mTDUICR_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 2 ) ; out -> mTDUICR_P . mIr =
( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_icrm_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mICRM_P . mNumCol = 26 ; out ->
mICRM_P . mNumRow = 2 ; out -> mICRM_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 27 ) ; out -> mICRM_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_icrm ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mICRM . mN = 0 ; out -> mICRM .
mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0
) ; return out ; } static NeDsMethodOutput * ds_output_dxicrm_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDXICRM_P . mNumCol = 26 ; out
-> mDXICRM_P . mNumRow = 0 ; out -> mDXICRM_P . mJc = ( int32_T * ) allocator
-> mCallocFcn ( allocator , sizeof ( int32_T ) , 27 ) ; out -> mDXICRM_P .
mIr = ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T )
, 0 ) ; return out ; } static NeDsMethodOutput * ds_output_dxicrm ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDXICRM . mN = 0 ; out ->
mDXICRM . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof (
real_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_ddicrm_p
( const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDDICRM_P . mNumCol =
14 ; out -> mDDICRM_P . mNumRow = 0 ; out -> mDDICRM_P . mJc = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 15 ) ; out ->
mDDICRM_P . mIr = ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof
( int32_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_ddicrm
( const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDDICRM . mN = 0 ; out
-> mDDICRM . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof (
real_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_freqs (
const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mFREQS . mN = 0 ; out
-> mFREQS . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof (
real_T ) , 0 ) ; return out ; } static NeDsMethodOutput *
ds_output_solverhits ( const NeDynamicSystem * ds , PmAllocator * allocator )
{ NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * )
allocator -> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out
-> mSOLVERHITS . mN = 0 ; out -> mSOLVERHITS . mX = ( real_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( real_T ) , 0 ) ; return out ; } static
NeDsMethodOutput * ds_output_mduy_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mMDUY_P . mNumCol = 1 ; out -> mMDUY_P .
mNumRow = 0 ; out -> mMDUY_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 2 ) ; out -> mMDUY_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ; return out ;
} static NeDsMethodOutput * ds_output_mdxy_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mMDXY_P . mNumCol = 26 ; out -> mMDXY_P .
mNumRow = 0 ; out -> mMDXY_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 27 ) ; out -> mMDXY_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ; return out ;
} static NeDsMethodOutput * ds_output_tduy_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mTDUY_P . mNumCol = 1 ; out -> mTDUY_P .
mNumRow = 0 ; out -> mTDUY_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 2 ) ; out -> mTDUY_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ; return out ;
} static NeDsMethodOutput * ds_output_tdxy_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mTDXY_P . mNumCol = 26 ; out -> mTDXY_P .
mNumRow = 0 ; out -> mTDXY_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 27 ) ; out -> mTDXY_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ; return out ;
} static NeDsMethodOutput * ds_output_y ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mY . mN = 0 ; out -> mY . mX = ( real_T * )
allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 ) ; return out ;
} static NeDsMethodOutput * ds_output_dxy_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDXY_P . mNumCol = 26 ; out -> mDXY_P .
mNumRow = 0 ; out -> mDXY_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 27 ) ; out -> mDXY_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ; return out ;
} static NeDsMethodOutput * ds_output_dxy ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDXY . mN = 0 ; out -> mDXY . mX = ( real_T
* ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 ) ; return
out ; } static NeDsMethodOutput * ds_output_duy_p ( const NeDynamicSystem *
ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out =
( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDUY_P . mNumCol = 1 ; out -> mDUY_P .
mNumRow = 0 ; out -> mDUY_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 2 ) ; out -> mDUY_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ; return out ;
} static NeDsMethodOutput * ds_output_duy ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDUY . mN = 0 ; out -> mDUY . mX = ( real_T
* ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 ) ; return
out ; } static NeDsMethodOutput * ds_output_dty_p ( const NeDynamicSystem *
ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out =
( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDTY_P . mNumCol = 1 ; out -> mDTY_P .
mNumRow = 0 ; out -> mDTY_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 2 ) ; out -> mDTY_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ; return out ;
} static NeDsMethodOutput * ds_output_dty ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDTY . mN = 0 ; out -> mDTY . mX = ( real_T
* ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 ) ; return
out ; } static NeDsMethodOutput * ds_output_mode ( const NeDynamicSystem * ds
, PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mMODE . mN = 58 ; out -> mMODE . mX = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 58 ) ;
return out ; } static NeDsMethodOutput * ds_output_zc ( const NeDynamicSystem
* ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out
= ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mZC . mN = 50 ; out -> mZC . mX = ( real_T
* ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 50 ) ; return
out ; } static NeDsMethodOutput * ds_output_cache_r ( const NeDynamicSystem *
ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out =
( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mCACHE_R . mN = 0 ; out -> mCACHE_R . mX =
( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_cache_i ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mCACHE_I . mN = 64 ; out ->
mCACHE_I . mX = ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof (
int32_T ) , 64 ) ; return out ; } static NeDsMethodOutput *
ds_output_update_r ( const NeDynamicSystem * ds , PmAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out ->
mUPDATE_R . mN = 14 ; out -> mUPDATE_R . mX = ( real_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( real_T ) , 14 ) ; return out ; } static
NeDsMethodOutput * ds_output_update_i ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mUPDATE_I . mN = 3 ; out -> mUPDATE_I . mX
= ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 3
) ; return out ; } static NeDsMethodOutput * ds_output_update2_r ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mUPDATE2_R . mN = 14 ; out ->
mUPDATE2_R . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof (
real_T ) , 14 ) ; return out ; } static NeDsMethodOutput *
ds_output_update2_i ( const NeDynamicSystem * ds , PmAllocator * allocator )
{ NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * )
allocator -> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out
-> mUPDATE2_I . mN = 3 ; out -> mUPDATE2_I . mX = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 3 ) ; return out ; } static
NeDsMethodOutput * ds_output_lock_r ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mLOCK_R . mN = 14 ; out -> mLOCK_R . mX = (
boolean_T * ) allocator -> mCallocFcn ( allocator , sizeof ( boolean_T ) , 14
) ; return out ; } static NeDsMethodOutput * ds_output_lock_i ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mLOCK_I . mN = 3 ; out ->
mLOCK_I . mX = ( boolean_T * ) allocator -> mCallocFcn ( allocator , sizeof (
boolean_T ) , 3 ) ; return out ; } static NeDsMethodOutput *
ds_output_lock2_r ( const NeDynamicSystem * ds , PmAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out ->
mLOCK2_R . mN = 14 ; out -> mLOCK2_R . mX = ( boolean_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( boolean_T ) , 14 ) ; return out ; } static
NeDsMethodOutput * ds_output_lock2_i ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mLOCK2_I . mN = 3 ; out -> mLOCK2_I . mX =
( boolean_T * ) allocator -> mCallocFcn ( allocator , sizeof ( boolean_T ) ,
3 ) ; return out ; } static NeDsMethodOutput * ds_output_sfo ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mSFO . mN = 0 ; out -> mSFO . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_sfp ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mSFP . mN = 0 ; out -> mSFP . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_init_r ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mINIT_R . mN = 14 ; out ->
mINIT_R . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof (
real_T ) , 14 ) ; return out ; } static NeDsMethodOutput * ds_output_init_i (
const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mINIT_I . mN = 3 ; out
-> mINIT_I . mX = ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof
( int32_T ) , 3 ) ; return out ; } static NeDsMethodOutput * ds_output_log (
const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mLOG . mN = 147 ; out
-> mLOG . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof (
real_T ) , 147 ) ; return out ; } static NeDsMethodOutput * ds_output_assert
( const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mASSERT . mN = 126 ;
out -> mASSERT . mX = ( int32_T * ) allocator -> mCallocFcn ( allocator ,
sizeof ( int32_T ) , 126 ) ; return out ; } static NeDsMethodOutput *
ds_output_passert ( const NeDynamicSystem * ds , PmAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out ->
mPASSERT . mN = 0 ; out -> mPASSERT . mX = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ; return out ; } static
NeDsMethodOutput * ds_output_iassert ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mIASSERT . mN = 0 ; out -> mIASSERT . mX =
( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_del_t ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDEL_T . mN = 0 ; out -> mDEL_T
. mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) ,
0 ) ; return out ; } static NeDsMethodOutput * ds_output_del_v ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDEL_V . mN = 0 ; out -> mDEL_V
. mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) ,
0 ) ; return out ; } static NeDsMethodOutput * ds_output_del_v0 ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDEL_V0 . mN = 0 ; out ->
mDEL_V0 . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof (
real_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_del_tmax
( const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDEL_TMAX . mN = 0 ;
out -> mDEL_TMAX . mX = ( real_T * ) allocator -> mCallocFcn ( allocator ,
sizeof ( real_T ) , 0 ) ; return out ; } static NeDsMethodOutput *
ds_output_dxdelt_p ( const NeDynamicSystem * ds , PmAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out ->
mDXDELT_P . mNumCol = 26 ; out -> mDXDELT_P . mNumRow = 0 ; out -> mDXDELT_P
. mJc = ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T
) , 27 ) ; out -> mDXDELT_P . mIr = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 0 ) ; return out ; } static NeDsMethodOutput
* ds_output_dxdelt ( const NeDynamicSystem * ds , PmAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out ->
mDXDELT . mN = 0 ; out -> mDXDELT . mX = ( real_T * ) allocator -> mCallocFcn
( allocator , sizeof ( real_T ) , 0 ) ; return out ; } static
NeDsMethodOutput * ds_output_dudelt_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDUDELT_P . mNumCol = 1 ; out -> mDUDELT_P
. mNumRow = 0 ; out -> mDUDELT_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 2 ) ; out -> mDUDELT_P . mIr =
( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_dudelt ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDUDELT . mN = 0 ; out ->
mDUDELT . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof (
real_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_dtdelt_p
( const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDTDELT_P . mNumCol =
1 ; out -> mDTDELT_P . mNumRow = 0 ; out -> mDTDELT_P . mJc = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 2 ) ; out ->
mDTDELT_P . mIr = ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof
( int32_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_dtdelt
( const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDTDELT . mN = 0 ; out
-> mDTDELT . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof (
real_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_obs_exp (
const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mOBS_EXP . mN = 201 ;
out -> mOBS_EXP . mX = ( real_T * ) allocator -> mCallocFcn ( allocator ,
sizeof ( real_T ) , 201 ) ; return out ; } static NeDsMethodOutput *
ds_output_obs_act ( const NeDynamicSystem * ds , PmAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out ->
mOBS_ACT . mN = 201 ; out -> mOBS_ACT . mX = ( real_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( real_T ) , 201 ) ; return out ; } static
NeDsMethodOutput * ds_output_obs_all ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mOBS_ALL . mN = 201 ; out -> mOBS_ALL . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 201
) ; return out ; } static NeDsMethodOutput * ds_output_obs_il ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mOBS_IL . mN = 201 ; out ->
mOBS_IL . mX = ( boolean_T * ) allocator -> mCallocFcn ( allocator , sizeof (
boolean_T ) , 201 ) ; return out ; } static NeDsMethodOutput * ds_output_dp_l
( const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDP_L . mN = 0 ; out
-> mDP_L . mX = ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof (
int32_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_dp_i (
const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDP_I . mN = 0 ; out
-> mDP_I . mX = ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof (
int32_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_dp_j (
const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDP_J . mN = 0 ; out
-> mDP_J . mX = ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof (
int32_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_dp_r (
const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDP_R . mN = 0 ; out
-> mDP_R . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof (
real_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_qx (
const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mQX . mN = 75 ; out ->
mQX . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T
) , 75 ) ; return out ; } static NeDsMethodOutput * ds_output_qu ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mQU . mN = 0 ; out -> mQU . mX =
( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_qt ( const NeDynamicSystem
* ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out
= ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mQT . mN = 0 ; out -> mQT . mX = ( real_T *
) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 ) ; return out
; } static NeDsMethodOutput * ds_output_q1 ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mQ1 . mN = 17 ; out -> mQ1 . mX = ( real_T
* ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 17 ) ; return
out ; } static NeDsMethodOutput * ds_output_qx_p ( const NeDynamicSystem * ds
, PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mQX_P . mNumCol = 26 ; out -> mQX_P .
mNumRow = 26 ; out -> mQX_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 27 ) ; out -> mQX_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 75 ) ; return out
; } static NeDsMethodOutput * ds_output_qu_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mQU_P . mNumCol = 1 ; out -> mQU_P .
mNumRow = 26 ; out -> mQU_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 2 ) ; out -> mQU_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ; return out ;
} static NeDsMethodOutput * ds_output_qt_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mQT_P . mNumCol = 1 ; out -> mQT_P .
mNumRow = 26 ; out -> mQT_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 2 ) ; out -> mQT_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ; return out ;
} static NeDsMethodOutput * ds_output_q1_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mQ1_P . mNumCol = 1 ; out -> mQ1_P .
mNumRow = 26 ; out -> mQ1_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 2 ) ; out -> mQ1_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 17 ) ; return out
; } static NeDsMethodOutput * ds_output_var_tol ( const NeDynamicSystem * ds
, PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mVAR_TOL . mN = 26 ; out -> mVAR_TOL . mX =
( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 26 ) ;
return out ; } static NeDsMethodOutput * ds_output_eq_tol ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mEQ_TOL . mN = 26 ; out ->
mEQ_TOL . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof (
real_T ) , 26 ) ; return out ; } static NeDsMethodOutput * ds_output_lv (
const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mLV . mN = 26 ; out ->
mLV . mX = ( boolean_T * ) allocator -> mCallocFcn ( allocator , sizeof (
boolean_T ) , 26 ) ; return out ; } static NeDsMethodOutput * ds_output_slv (
const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mSLV . mN = 26 ; out
-> mSLV . mX = ( boolean_T * ) allocator -> mCallocFcn ( allocator , sizeof (
boolean_T ) , 26 ) ; return out ; } static NeDsMethodOutput * ds_output_nldv
( const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mNLDV . mN = 26 ; out
-> mNLDV . mX = ( boolean_T * ) allocator -> mCallocFcn ( allocator , sizeof
( boolean_T ) , 26 ) ; return out ; } static NeDsMethodOutput *
ds_output_sclv ( const NeDynamicSystem * ds , PmAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mSCLV
. mN = 26 ; out -> mSCLV . mX = ( boolean_T * ) allocator -> mCallocFcn (
allocator , sizeof ( boolean_T ) , 26 ) ; return out ; } static
NeDsMethodOutput * ds_output_imin ( const NeDynamicSystem * ds , PmAllocator
* allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mIMIN . mN = 26 ; out -> mIMIN . mX = (
real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 26 ) ;
return out ; } static NeDsMethodOutput * ds_output_imax ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mIMAX . mN = 26 ; out -> mIMAX .
mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) ,
26 ) ; return out ; } static NeDsMethodOutput * ds_output_dimin ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDIMIN . mN = 14 ; out -> mDIMIN
. mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) ,
14 ) ; return out ; } static NeDsMethodOutput * ds_output_dimax ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDIMAX . mN = 14 ; out -> mDIMAX
. mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) ,
14 ) ; return out ; } static void release_reference ( NeDynamicSystem * ds )
{ _NeDynamicSystem * _ds ; _ds = ( _NeDynamicSystem * ) ds ; if ( -- _ds ->
mRefCnt == 0 ) { _ds -> mAlloc . mFreeFcn ( & _ds -> mAlloc , _ds ) ; } }
static void get_reference ( NeDynamicSystem * ds ) { _NeDynamicSystem * _ds ;
_ds = ( _NeDynamicSystem * ) ds ; ++ _ds -> mRefCnt ; } static
NeDynamicSystem * diagnostics ( NeDynamicSystem * ds , boolean_T kp ) {
_NeDynamicSystem * _ds = ( _NeDynamicSystem * ) ds ; ( void ) kp ;
ne_ds_get_reference ( & _ds -> mBase ) ; return & _ds -> mBase ; } static
void expand ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
PmRealVector * out , boolean_T kp ) { ( void ) ds ; ( void ) kp ; memcpy (
out -> mX , in -> mX . mX , sizeof ( real_T ) * out -> mN ) ; } static void
rtpmap ( const NeDynamicSystem * ds , const PmIntVector * inl , const
PmIntVector * ini , const PmIntVector * inj , const PmRealVector * inr ,
PmIntVector * outl , PmIntVector * outi , PmIntVector * outj , PmRealVector *
outr ) { ( void ) ds ; memcpy ( outl -> mX , inl -> mX , sizeof ( int32_T ) *
inl -> mN ) ; memcpy ( outi -> mX , ini -> mX , sizeof ( int32_T ) * ini ->
mN ) ; memcpy ( outj -> mX , inj -> mX , sizeof ( int32_T ) * inj -> mN ) ;
memcpy ( outr -> mX , inr -> mX , sizeof ( real_T ) * inr -> mN ) ; }
NeDynamicSystem * IGBTThermal_399ad5b0_1_dae_ds ( PmAllocator * allocator ) {
NeDynamicSystem * ds ; _NeDynamicSystem * _ds ; static SscIoInfo input_info [
1 ] ; _ds = ( _NeDynamicSystem * ) allocator -> mCallocFcn ( allocator ,
sizeof ( _NeDynamicSystem ) , 1 ) ; _ds -> mAlloc = * allocator ; _ds ->
mRefCnt = 1 ; ds = & _ds -> mBase ; ds -> mNumVariables = 26 ; ds ->
mNumDiscreteRealVariables = 14 ; ds -> mNumDifferentialVariables = 13 ; ds ->
mNumEquations = 26 ; ds -> mNumCEResiduals = 0 ; ds -> mNumICResiduals = 2 ;
ds -> mNumFreqs = 0 ; ds -> mNumSolverHits = 0 ; ds -> mNumModes = 58 ; ds ->
mNumMajorModes = 3 ; ds -> mNumRealCache = 0 ; ds -> mNumIntCache = 64 ; ds
-> mNumObservables = 197 ; ds -> mNumObservableElements = 201 ; ds -> mNumZcs
= 50 ; ds -> mNumAsserts = 126 ; ds -> mNumAssertRanges = 128 ; ds ->
mNumParamAsserts = 0 ; ds -> mNumParamAssertRanges = 0 ; ds ->
mNumInitialAsserts = 0 ; ds -> mNumInitialAssertRanges = 0 ; ds -> mNumRanges
= 58 ; ds -> mNumEquationRanges = 82 ; ds -> mNumCERRanges = 0 ; ds ->
mNumICRRanges = 2 ; ds -> mNumFundamentalSamples = 0 ; ds -> mNumDelays = 0 ;
ds -> mNumLogicalParameters = 0 ; ds -> mNumIntegerParameters = 0 ; ds ->
mNumIndexParameters = 0 ; ds -> mNumRealParameters = 6 ; ds ->
mNumLogicalDerivedParameters = 0 ; ds -> mNumIntegerDerivedParameters = 0 ;
ds -> mNumIndexDerivedParameters = 0 ; ds -> mNumRealDerivedParameters = 0 ;
ds -> mIsOutputLinear = TRUE ; ds -> mIsOutputSwitchedLinear = TRUE ; ds ->
mIsScalable = FALSE ; ds -> mNumIo [ SSC_INPUT_IO_TYPE ] = 1 ; input_info [ 0
] . mIdentifier = "Pulse_generator.Simulink_PS_Converter_output0" ;
input_info [ 0 ] . mSize = ssc_make_scalar_array_size ( ) ;
ssc_array_size_set_dim ( & input_info [ 0 ] . mSize , 0 , 1 ) ;
ssc_array_size_set_dim ( & input_info [ 0 ] . mSize , 1 , 1 ) ; input_info [
0 ] . mName = "Pulse_generator.Simulink_PS_Converter_output0" ; input_info [
0 ] . mUnit = "1" ; ds -> mIo [ SSC_INPUT_IO_TYPE ] = input_info ; ds ->
mNumIo [ SSC_OUTPUT_IO_TYPE ] = 0 ; ds -> mReleaseReference =
release_reference ; ds -> mGetReference = get_reference ; ds ->
mDiagnosticsDsFcn = diagnostics ; ds -> mExpandFcn = expand ; ds ->
mRtpMapFcn = rtpmap ; ds -> mMethods [ NE_DS_METHOD_M_P ] =
IGBTThermal_399ad5b0_1_ds_m_p ; ds -> mMakeOutput [ NE_DS_METHOD_M_P ] =
ds_output_m_p ; ds -> mMethods [ NE_DS_METHOD_M ] =
IGBTThermal_399ad5b0_1_ds_m ; ds -> mMakeOutput [ NE_DS_METHOD_M ] =
ds_output_m ; ds -> mMethods [ NE_DS_METHOD_VMM ] = ds_vmm ; ds ->
mMakeOutput [ NE_DS_METHOD_VMM ] = ds_output_vmm ; ds -> mMethods [
NE_DS_METHOD_DXM_P ] = ds_dxm_p ; ds -> mMakeOutput [ NE_DS_METHOD_DXM_P ] =
ds_output_dxm_p ; ds -> mMethods [ NE_DS_METHOD_DXM ] = ds_dxm ; ds ->
mMakeOutput [ NE_DS_METHOD_DXM ] = ds_output_dxm ; ds -> mMethods [
NE_DS_METHOD_DDM_P ] = ds_ddm_p ; ds -> mMakeOutput [ NE_DS_METHOD_DDM_P ] =
ds_output_ddm_p ; ds -> mMethods [ NE_DS_METHOD_DDM ] = ds_ddm ; ds ->
mMakeOutput [ NE_DS_METHOD_DDM ] = ds_output_ddm ; ds -> mMethods [
NE_DS_METHOD_DUM_P ] = ds_dum_p ; ds -> mMakeOutput [ NE_DS_METHOD_DUM_P ] =
ds_output_dum_p ; ds -> mMethods [ NE_DS_METHOD_DUM ] = ds_dum ; ds ->
mMakeOutput [ NE_DS_METHOD_DUM ] = ds_output_dum ; ds -> mMethods [
NE_DS_METHOD_DTM_P ] = ds_dtm_p ; ds -> mMakeOutput [ NE_DS_METHOD_DTM_P ] =
ds_output_dtm_p ; ds -> mMethods [ NE_DS_METHOD_DTM ] = ds_dtm ; ds ->
mMakeOutput [ NE_DS_METHOD_DTM ] = ds_output_dtm ; ds -> mMethods [
NE_DS_METHOD_DPM_P ] = ds_dpm_p ; ds -> mMakeOutput [ NE_DS_METHOD_DPM_P ] =
ds_output_dpm_p ; ds -> mMethods [ NE_DS_METHOD_DPM ] = ds_dpm ; ds ->
mMakeOutput [ NE_DS_METHOD_DPM ] = ds_output_dpm ; ds -> mMethods [
NE_DS_METHOD_A_P ] = IGBTThermal_399ad5b0_1_ds_a_p ; ds -> mMakeOutput [
NE_DS_METHOD_A_P ] = ds_output_a_p ; ds -> mMethods [ NE_DS_METHOD_A ] =
IGBTThermal_399ad5b0_1_ds_a ; ds -> mMakeOutput [ NE_DS_METHOD_A ] =
ds_output_a ; ds -> mMethods [ NE_DS_METHOD_B_P ] = ds_b_p ; ds ->
mMakeOutput [ NE_DS_METHOD_B_P ] = ds_output_b_p ; ds -> mMethods [
NE_DS_METHOD_B ] = ds_b ; ds -> mMakeOutput [ NE_DS_METHOD_B ] = ds_output_b
; ds -> mMethods [ NE_DS_METHOD_C_P ] = ds_c_p ; ds -> mMakeOutput [
NE_DS_METHOD_C_P ] = ds_output_c_p ; ds -> mMethods [ NE_DS_METHOD_C ] = ds_c
; ds -> mMakeOutput [ NE_DS_METHOD_C ] = ds_output_c ; ds -> mMethods [
NE_DS_METHOD_F ] = IGBTThermal_399ad5b0_1_ds_f ; ds -> mMakeOutput [
NE_DS_METHOD_F ] = ds_output_f ; ds -> mMethods [ NE_DS_METHOD_VMF ] = ds_vmf
; ds -> mMakeOutput [ NE_DS_METHOD_VMF ] = ds_output_vmf ; ds -> mMethods [
NE_DS_METHOD_VPF ] = ds_vpf ; ds -> mMakeOutput [ NE_DS_METHOD_VPF ] =
ds_output_vpf ; ds -> mMethods [ NE_DS_METHOD_VSF ] = ds_vsf ; ds ->
mMakeOutput [ NE_DS_METHOD_VSF ] = ds_output_vsf ; ds -> mMethods [
NE_DS_METHOD_SLF ] = ds_slf ; ds -> mMakeOutput [ NE_DS_METHOD_SLF ] =
ds_output_slf ; ds -> mMethods [ NE_DS_METHOD_SLF0 ] = ds_slf0 ; ds ->
mMakeOutput [ NE_DS_METHOD_SLF0 ] = ds_output_slf0 ; ds -> mMethods [
NE_DS_METHOD_DXF_P ] = IGBTThermal_399ad5b0_1_ds_dxf_p ; ds -> mMakeOutput [
NE_DS_METHOD_DXF_P ] = ds_output_dxf_p ; ds -> mMethods [ NE_DS_METHOD_DXF ]
= IGBTThermal_399ad5b0_1_ds_dxf ; ds -> mMakeOutput [ NE_DS_METHOD_DXF ] =
ds_output_dxf ; ds -> mMethods [ NE_DS_METHOD_DUF_P ] = ds_duf_p ; ds ->
mMakeOutput [ NE_DS_METHOD_DUF_P ] = ds_output_duf_p ; ds -> mMethods [
NE_DS_METHOD_DUF ] = ds_duf ; ds -> mMakeOutput [ NE_DS_METHOD_DUF ] =
ds_output_duf ; ds -> mMethods [ NE_DS_METHOD_DTF_P ] = ds_dtf_p ; ds ->
mMakeOutput [ NE_DS_METHOD_DTF_P ] = ds_output_dtf_p ; ds -> mMethods [
NE_DS_METHOD_DTF ] = ds_dtf ; ds -> mMakeOutput [ NE_DS_METHOD_DTF ] =
ds_output_dtf ; ds -> mMethods [ NE_DS_METHOD_DDF_P ] = ds_ddf_p ; ds ->
mMakeOutput [ NE_DS_METHOD_DDF_P ] = ds_output_ddf_p ; ds -> mMethods [
NE_DS_METHOD_DDF ] = IGBTThermal_399ad5b0_1_ds_ddf ; ds -> mMakeOutput [
NE_DS_METHOD_DDF ] = ds_output_ddf ; ds -> mMethods [ NE_DS_METHOD_DPDXF_P ]
= ds_dpdxf_p ; ds -> mMakeOutput [ NE_DS_METHOD_DPDXF_P ] = ds_output_dpdxf_p
; ds -> mMethods [ NE_DS_METHOD_DPDXF ] = ds_dpdxf ; ds -> mMakeOutput [
NE_DS_METHOD_DPDXF ] = ds_output_dpdxf ; ds -> mMethods [ NE_DS_METHOD_DWF_P
] = ds_dwf_p ; ds -> mMakeOutput [ NE_DS_METHOD_DWF_P ] = ds_output_dwf_p ;
ds -> mMethods [ NE_DS_METHOD_DWF ] = ds_dwf ; ds -> mMakeOutput [
NE_DS_METHOD_DWF ] = ds_output_dwf ; ds -> mMethods [ NE_DS_METHOD_TDUF_P ] =
ds_tduf_p ; ds -> mMakeOutput [ NE_DS_METHOD_TDUF_P ] = ds_output_tduf_p ; ds
-> mMethods [ NE_DS_METHOD_TDXF_P ] = IGBTThermal_399ad5b0_1_ds_tdxf_p ; ds
-> mMakeOutput [ NE_DS_METHOD_TDXF_P ] = ds_output_tdxf_p ; ds -> mMethods [
NE_DS_METHOD_DNF_P ] = ds_dnf_p ; ds -> mMakeOutput [ NE_DS_METHOD_DNF_P ] =
ds_output_dnf_p ; ds -> mMethods [ NE_DS_METHOD_DNF ] = ds_dnf ; ds ->
mMakeOutput [ NE_DS_METHOD_DNF ] = ds_output_dnf ; ds -> mMethods [
NE_DS_METHOD_DNF_V_X ] = ds_dnf_v_x ; ds -> mMakeOutput [
NE_DS_METHOD_DNF_V_X ] = ds_output_dnf_v_x ; ds -> mMethods [
NE_DS_METHOD_CER ] = ds_cer ; ds -> mMakeOutput [ NE_DS_METHOD_CER ] =
ds_output_cer ; ds -> mMethods [ NE_DS_METHOD_DXCER ] = ds_dxcer ; ds ->
mMakeOutput [ NE_DS_METHOD_DXCER ] = ds_output_dxcer ; ds -> mMethods [
NE_DS_METHOD_DXCER_P ] = ds_dxcer_p ; ds -> mMakeOutput [
NE_DS_METHOD_DXCER_P ] = ds_output_dxcer_p ; ds -> mMethods [
NE_DS_METHOD_DDCER ] = ds_ddcer ; ds -> mMakeOutput [ NE_DS_METHOD_DDCER ] =
ds_output_ddcer ; ds -> mMethods [ NE_DS_METHOD_DDCER_P ] = ds_ddcer_p ; ds
-> mMakeOutput [ NE_DS_METHOD_DDCER_P ] = ds_output_ddcer_p ; ds -> mMethods
[ NE_DS_METHOD_IC ] = IGBTThermal_399ad5b0_1_ds_ic ; ds -> mMakeOutput [
NE_DS_METHOD_IC ] = ds_output_ic ; ds -> mMethods [ NE_DS_METHOD_ICR ] =
ds_icr ; ds -> mMakeOutput [ NE_DS_METHOD_ICR ] = ds_output_icr ; ds ->
mMethods [ NE_DS_METHOD_ICR_IM ] = ds_icr_im ; ds -> mMakeOutput [
NE_DS_METHOD_ICR_IM ] = ds_output_icr_im ; ds -> mMethods [
NE_DS_METHOD_ICR_ID ] = ds_icr_id ; ds -> mMakeOutput [ NE_DS_METHOD_ICR_ID ]
= ds_output_icr_id ; ds -> mMethods [ NE_DS_METHOD_ICR_IL ] = ds_icr_il ; ds
-> mMakeOutput [ NE_DS_METHOD_ICR_IL ] = ds_output_icr_il ; ds -> mMethods [
NE_DS_METHOD_DXICR ] = ds_dxicr ; ds -> mMakeOutput [ NE_DS_METHOD_DXICR ] =
ds_output_dxicr ; ds -> mMethods [ NE_DS_METHOD_DXICR_P ] = ds_dxicr_p ; ds
-> mMakeOutput [ NE_DS_METHOD_DXICR_P ] = ds_output_dxicr_p ; ds -> mMethods
[ NE_DS_METHOD_DDICR ] = ds_ddicr ; ds -> mMakeOutput [ NE_DS_METHOD_DDICR ]
= ds_output_ddicr ; ds -> mMethods [ NE_DS_METHOD_DDICR_P ] = ds_ddicr_p ; ds
-> mMakeOutput [ NE_DS_METHOD_DDICR_P ] = ds_output_ddicr_p ; ds -> mMethods
[ NE_DS_METHOD_TDUICR_P ] = ds_tduicr_p ; ds -> mMakeOutput [
NE_DS_METHOD_TDUICR_P ] = ds_output_tduicr_p ; ds -> mMethods [
NE_DS_METHOD_ICRM_P ] = ds_icrm_p ; ds -> mMakeOutput [ NE_DS_METHOD_ICRM_P ]
= ds_output_icrm_p ; ds -> mMethods [ NE_DS_METHOD_ICRM ] = ds_icrm ; ds ->
mMakeOutput [ NE_DS_METHOD_ICRM ] = ds_output_icrm ; ds -> mMethods [
NE_DS_METHOD_DXICRM_P ] = ds_dxicrm_p ; ds -> mMakeOutput [
NE_DS_METHOD_DXICRM_P ] = ds_output_dxicrm_p ; ds -> mMethods [
NE_DS_METHOD_DXICRM ] = ds_dxicrm ; ds -> mMakeOutput [ NE_DS_METHOD_DXICRM ]
= ds_output_dxicrm ; ds -> mMethods [ NE_DS_METHOD_DDICRM_P ] = ds_ddicrm_p ;
ds -> mMakeOutput [ NE_DS_METHOD_DDICRM_P ] = ds_output_ddicrm_p ; ds ->
mMethods [ NE_DS_METHOD_DDICRM ] = ds_ddicrm ; ds -> mMakeOutput [
NE_DS_METHOD_DDICRM ] = ds_output_ddicrm ; ds -> mMethods [
NE_DS_METHOD_FREQS ] = ds_freqs ; ds -> mMakeOutput [ NE_DS_METHOD_FREQS ] =
ds_output_freqs ; ds -> mMethods [ NE_DS_METHOD_SOLVERHITS ] = ds_solverhits
; ds -> mMakeOutput [ NE_DS_METHOD_SOLVERHITS ] = ds_output_solverhits ; ds
-> mMethods [ NE_DS_METHOD_MDUY_P ] = ds_mduy_p ; ds -> mMakeOutput [
NE_DS_METHOD_MDUY_P ] = ds_output_mduy_p ; ds -> mMethods [
NE_DS_METHOD_MDXY_P ] = ds_mdxy_p ; ds -> mMakeOutput [ NE_DS_METHOD_MDXY_P ]
= ds_output_mdxy_p ; ds -> mMethods [ NE_DS_METHOD_TDUY_P ] = ds_tduy_p ; ds
-> mMakeOutput [ NE_DS_METHOD_TDUY_P ] = ds_output_tduy_p ; ds -> mMethods [
NE_DS_METHOD_TDXY_P ] = ds_tdxy_p ; ds -> mMakeOutput [ NE_DS_METHOD_TDXY_P ]
= ds_output_tdxy_p ; ds -> mMethods [ NE_DS_METHOD_Y ] = ds_y ; ds ->
mMakeOutput [ NE_DS_METHOD_Y ] = ds_output_y ; ds -> mMethods [
NE_DS_METHOD_DXY_P ] = ds_dxy_p ; ds -> mMakeOutput [ NE_DS_METHOD_DXY_P ] =
ds_output_dxy_p ; ds -> mMethods [ NE_DS_METHOD_DXY ] = ds_dxy ; ds ->
mMakeOutput [ NE_DS_METHOD_DXY ] = ds_output_dxy ; ds -> mMethods [
NE_DS_METHOD_DUY_P ] = ds_duy_p ; ds -> mMakeOutput [ NE_DS_METHOD_DUY_P ] =
ds_output_duy_p ; ds -> mMethods [ NE_DS_METHOD_DUY ] = ds_duy ; ds ->
mMakeOutput [ NE_DS_METHOD_DUY ] = ds_output_duy ; ds -> mMethods [
NE_DS_METHOD_DTY_P ] = ds_dty_p ; ds -> mMakeOutput [ NE_DS_METHOD_DTY_P ] =
ds_output_dty_p ; ds -> mMethods [ NE_DS_METHOD_DTY ] = ds_dty ; ds ->
mMakeOutput [ NE_DS_METHOD_DTY ] = ds_output_dty ; ds -> mMethods [
NE_DS_METHOD_MODE ] = IGBTThermal_399ad5b0_1_ds_mode ; ds -> mMakeOutput [
NE_DS_METHOD_MODE ] = ds_output_mode ; ds -> mMethods [ NE_DS_METHOD_ZC ] =
IGBTThermal_399ad5b0_1_ds_zc ; ds -> mMakeOutput [ NE_DS_METHOD_ZC ] =
ds_output_zc ; ds -> mMethods [ NE_DS_METHOD_CACHE_R ] = ds_cache_r ; ds ->
mMakeOutput [ NE_DS_METHOD_CACHE_R ] = ds_output_cache_r ; ds -> mMethods [
NE_DS_METHOD_CACHE_I ] = IGBTThermal_399ad5b0_1_ds_cache_i ; ds ->
mMakeOutput [ NE_DS_METHOD_CACHE_I ] = ds_output_cache_i ; ds -> mMethods [
NE_DS_METHOD_UPDATE_R ] = IGBTThermal_399ad5b0_1_ds_update_r ; ds ->
mMakeOutput [ NE_DS_METHOD_UPDATE_R ] = ds_output_update_r ; ds -> mMethods [
NE_DS_METHOD_UPDATE_I ] = IGBTThermal_399ad5b0_1_ds_update_i ; ds ->
mMakeOutput [ NE_DS_METHOD_UPDATE_I ] = ds_output_update_i ; ds -> mMethods [
NE_DS_METHOD_UPDATE2_R ] = IGBTThermal_399ad5b0_1_ds_update2_r ; ds ->
mMakeOutput [ NE_DS_METHOD_UPDATE2_R ] = ds_output_update2_r ; ds -> mMethods
[ NE_DS_METHOD_UPDATE2_I ] = IGBTThermal_399ad5b0_1_ds_update2_i ; ds ->
mMakeOutput [ NE_DS_METHOD_UPDATE2_I ] = ds_output_update2_i ; ds -> mMethods
[ NE_DS_METHOD_LOCK_R ] = IGBTThermal_399ad5b0_1_ds_lock_r ; ds ->
mMakeOutput [ NE_DS_METHOD_LOCK_R ] = ds_output_lock_r ; ds -> mMethods [
NE_DS_METHOD_LOCK_I ] = IGBTThermal_399ad5b0_1_ds_lock_i ; ds -> mMakeOutput
[ NE_DS_METHOD_LOCK_I ] = ds_output_lock_i ; ds -> mMethods [
NE_DS_METHOD_LOCK2_R ] = IGBTThermal_399ad5b0_1_ds_lock2_r ; ds ->
mMakeOutput [ NE_DS_METHOD_LOCK2_R ] = ds_output_lock2_r ; ds -> mMethods [
NE_DS_METHOD_LOCK2_I ] = IGBTThermal_399ad5b0_1_ds_lock2_i ; ds ->
mMakeOutput [ NE_DS_METHOD_LOCK2_I ] = ds_output_lock2_i ; ds -> mMethods [
NE_DS_METHOD_SFO ] = ds_sfo ; ds -> mMakeOutput [ NE_DS_METHOD_SFO ] =
ds_output_sfo ; ds -> mMethods [ NE_DS_METHOD_SFP ] = ds_sfp ; ds ->
mMakeOutput [ NE_DS_METHOD_SFP ] = ds_output_sfp ; ds -> mMethods [
NE_DS_METHOD_INIT_R ] = ds_init_r ; ds -> mMakeOutput [ NE_DS_METHOD_INIT_R ]
= ds_output_init_r ; ds -> mMethods [ NE_DS_METHOD_INIT_I ] = ds_init_i ; ds
-> mMakeOutput [ NE_DS_METHOD_INIT_I ] = ds_output_init_i ; ds -> mMethods [
NE_DS_METHOD_LOG ] = IGBTThermal_399ad5b0_1_ds_log ; ds -> mMakeOutput [
NE_DS_METHOD_LOG ] = ds_output_log ; ds -> mMethods [ NE_DS_METHOD_ASSERT ] =
IGBTThermal_399ad5b0_1_ds_assert ; ds -> mMakeOutput [ NE_DS_METHOD_ASSERT ]
= ds_output_assert ; ds -> mMethods [ NE_DS_METHOD_PASSERT ] = ds_passert ;
ds -> mMakeOutput [ NE_DS_METHOD_PASSERT ] = ds_output_passert ; ds ->
mMethods [ NE_DS_METHOD_IASSERT ] = ds_iassert ; ds -> mMakeOutput [
NE_DS_METHOD_IASSERT ] = ds_output_iassert ; ds -> mMethods [
NE_DS_METHOD_DEL_T ] = ds_del_t ; ds -> mMakeOutput [ NE_DS_METHOD_DEL_T ] =
ds_output_del_t ; ds -> mMethods [ NE_DS_METHOD_DEL_V ] = ds_del_v ; ds ->
mMakeOutput [ NE_DS_METHOD_DEL_V ] = ds_output_del_v ; ds -> mMethods [
NE_DS_METHOD_DEL_V0 ] = ds_del_v0 ; ds -> mMakeOutput [ NE_DS_METHOD_DEL_V0 ]
= ds_output_del_v0 ; ds -> mMethods [ NE_DS_METHOD_DEL_TMAX ] = ds_del_tmax ;
ds -> mMakeOutput [ NE_DS_METHOD_DEL_TMAX ] = ds_output_del_tmax ; ds ->
mMethods [ NE_DS_METHOD_DXDELT_P ] = ds_dxdelt_p ; ds -> mMakeOutput [
NE_DS_METHOD_DXDELT_P ] = ds_output_dxdelt_p ; ds -> mMethods [
NE_DS_METHOD_DXDELT ] = ds_dxdelt ; ds -> mMakeOutput [ NE_DS_METHOD_DXDELT ]
= ds_output_dxdelt ; ds -> mMethods [ NE_DS_METHOD_DUDELT_P ] = ds_dudelt_p ;
ds -> mMakeOutput [ NE_DS_METHOD_DUDELT_P ] = ds_output_dudelt_p ; ds ->
mMethods [ NE_DS_METHOD_DUDELT ] = ds_dudelt ; ds -> mMakeOutput [
NE_DS_METHOD_DUDELT ] = ds_output_dudelt ; ds -> mMethods [
NE_DS_METHOD_DTDELT_P ] = ds_dtdelt_p ; ds -> mMakeOutput [
NE_DS_METHOD_DTDELT_P ] = ds_output_dtdelt_p ; ds -> mMethods [
NE_DS_METHOD_DTDELT ] = ds_dtdelt ; ds -> mMakeOutput [ NE_DS_METHOD_DTDELT ]
= ds_output_dtdelt ; ds -> mMethods [ NE_DS_METHOD_OBS_EXP ] =
IGBTThermal_399ad5b0_1_ds_obs_exp ; ds -> mMakeOutput [ NE_DS_METHOD_OBS_EXP
] = ds_output_obs_exp ; ds -> mMethods [ NE_DS_METHOD_OBS_ACT ] =
IGBTThermal_399ad5b0_1_ds_obs_act ; ds -> mMakeOutput [ NE_DS_METHOD_OBS_ACT
] = ds_output_obs_act ; ds -> mMethods [ NE_DS_METHOD_OBS_ALL ] =
IGBTThermal_399ad5b0_1_ds_obs_all ; ds -> mMakeOutput [ NE_DS_METHOD_OBS_ALL
] = ds_output_obs_all ; ds -> mMethods [ NE_DS_METHOD_OBS_IL ] =
IGBTThermal_399ad5b0_1_ds_obs_il ; ds -> mMakeOutput [ NE_DS_METHOD_OBS_IL ]
= ds_output_obs_il ; ds -> mMethods [ NE_DS_METHOD_DP_L ] = ds_dp_l ; ds ->
mMakeOutput [ NE_DS_METHOD_DP_L ] = ds_output_dp_l ; ds -> mMethods [
NE_DS_METHOD_DP_I ] = ds_dp_i ; ds -> mMakeOutput [ NE_DS_METHOD_DP_I ] =
ds_output_dp_i ; ds -> mMethods [ NE_DS_METHOD_DP_J ] = ds_dp_j ; ds ->
mMakeOutput [ NE_DS_METHOD_DP_J ] = ds_output_dp_j ; ds -> mMethods [
NE_DS_METHOD_DP_R ] = ds_dp_r ; ds -> mMakeOutput [ NE_DS_METHOD_DP_R ] =
ds_output_dp_r ; ds -> mMethods [ NE_DS_METHOD_QX ] =
IGBTThermal_399ad5b0_1_ds_qx ; ds -> mMakeOutput [ NE_DS_METHOD_QX ] =
ds_output_qx ; ds -> mMethods [ NE_DS_METHOD_QU ] = ds_qu ; ds -> mMakeOutput
[ NE_DS_METHOD_QU ] = ds_output_qu ; ds -> mMethods [ NE_DS_METHOD_QT ] =
ds_qt ; ds -> mMakeOutput [ NE_DS_METHOD_QT ] = ds_output_qt ; ds -> mMethods
[ NE_DS_METHOD_Q1 ] = ds_q1 ; ds -> mMakeOutput [ NE_DS_METHOD_Q1 ] =
ds_output_q1 ; ds -> mMethods [ NE_DS_METHOD_QX_P ] =
IGBTThermal_399ad5b0_1_ds_qx_p ; ds -> mMakeOutput [ NE_DS_METHOD_QX_P ] =
ds_output_qx_p ; ds -> mMethods [ NE_DS_METHOD_QU_P ] = ds_qu_p ; ds ->
mMakeOutput [ NE_DS_METHOD_QU_P ] = ds_output_qu_p ; ds -> mMethods [
NE_DS_METHOD_QT_P ] = ds_qt_p ; ds -> mMakeOutput [ NE_DS_METHOD_QT_P ] =
ds_output_qt_p ; ds -> mMethods [ NE_DS_METHOD_Q1_P ] = ds_q1_p ; ds ->
mMakeOutput [ NE_DS_METHOD_Q1_P ] = ds_output_q1_p ; ds -> mMethods [
NE_DS_METHOD_VAR_TOL ] = ds_var_tol ; ds -> mMakeOutput [
NE_DS_METHOD_VAR_TOL ] = ds_output_var_tol ; ds -> mMethods [
NE_DS_METHOD_EQ_TOL ] = ds_eq_tol ; ds -> mMakeOutput [ NE_DS_METHOD_EQ_TOL ]
= ds_output_eq_tol ; ds -> mMethods [ NE_DS_METHOD_LV ] = ds_lv ; ds ->
mMakeOutput [ NE_DS_METHOD_LV ] = ds_output_lv ; ds -> mMethods [
NE_DS_METHOD_SLV ] = ds_slv ; ds -> mMakeOutput [ NE_DS_METHOD_SLV ] =
ds_output_slv ; ds -> mMethods [ NE_DS_METHOD_NLDV ] = ds_nldv ; ds ->
mMakeOutput [ NE_DS_METHOD_NLDV ] = ds_output_nldv ; ds -> mMethods [
NE_DS_METHOD_SCLV ] = ds_sclv ; ds -> mMakeOutput [ NE_DS_METHOD_SCLV ] =
ds_output_sclv ; ds -> mMethods [ NE_DS_METHOD_IMIN ] =
IGBTThermal_399ad5b0_1_ds_imin ; ds -> mMakeOutput [ NE_DS_METHOD_IMIN ] =
ds_output_imin ; ds -> mMethods [ NE_DS_METHOD_IMAX ] =
IGBTThermal_399ad5b0_1_ds_imax ; ds -> mMakeOutput [ NE_DS_METHOD_IMAX ] =
ds_output_imax ; ds -> mMethods [ NE_DS_METHOD_DIMIN ] = ds_dimin ; ds ->
mMakeOutput [ NE_DS_METHOD_DIMIN ] = ds_output_dimin ; ds -> mMethods [
NE_DS_METHOD_DIMAX ] = ds_dimax ; ds -> mMakeOutput [ NE_DS_METHOD_DIMAX ] =
ds_output_dimax ; ds -> mEquationData = s_equation_data ; ds -> mCERData =
s_cer_data ; ds -> mICRData = s_icr_data ; ds -> mVariableData =
s_variable_data ; ds -> mDiscreteData = s_discrete_data ; ds ->
mObservableData = s_observable_data ; ds -> mMajorModeData =
s_major_mode_data ; ds -> mZCData = s_zc_data ; ds -> mRanges = s_range ; ds
-> mAssertData = s_assert_data ; ds -> mAssertRanges = s_assert_range ; ds ->
mParamAssertData = s_param_assert_data ; ds -> mParamAssertRanges =
s_param_assert_range ; ds -> mInitialAssertData = s_initial_assert_data ; ds
-> mInitialAssertRanges = s_initial_assert_range ; ds -> mEquationRanges =
s_equation_range ; ds -> mCERRanges = s_cer_range ; ds -> mICRRanges =
s_icr_range ; ds -> mLogicalParameters = s_logical_parameter_data ; ds ->
mIntegerParameters = s_integer_parameter_data ; ds -> mIndexParameters =
s_index_parameter_data ; ds -> mRealParameters = s_real_parameter_data ; _ds
-> mField0 = s_constant_table0 ; _ds -> mField1 = s_constant_table1 ; _ds ->
mField2 = s_constant_table2 ; ds -> mNumLargeArray = 3 ; return (
NeDynamicSystem * ) _ds ; } static int32_T ds_passert ( const NeDynamicSystem
* LC , const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void )
t1 ; ( void ) LC ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T
ds_iassert ( const NeDynamicSystem * LC , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void ) LC ; ( void ) LC ; ( void )
t2 ; return 0 ; } static int32_T ds_cer ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void )
LC ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T ds_dxcer ( const
NeDynamicSystem * LC , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { ( void ) t1 ; ( void ) LC ; ( void ) LC ; ( void ) t2 ; return 0 ; }
static int32_T ds_dxcer_p ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern out ;
( void ) t1 ; ( void ) LC ; out = t2 -> mDXCER_P ; out . mNumCol = 26ULL ;
out . mNumRow = 0ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 0 ; out . mJc
[ 2 ] = 0 ; out . mJc [ 3 ] = 0 ; out . mJc [ 4 ] = 0 ; out . mJc [ 5 ] = 0 ;
out . mJc [ 6 ] = 0 ; out . mJc [ 7 ] = 0 ; out . mJc [ 8 ] = 0 ; out . mJc [
9 ] = 0 ; out . mJc [ 10 ] = 0 ; out . mJc [ 11 ] = 0 ; out . mJc [ 12 ] = 0
; out . mJc [ 13 ] = 0 ; out . mJc [ 14 ] = 0 ; out . mJc [ 15 ] = 0 ; out .
mJc [ 16 ] = 0 ; out . mJc [ 17 ] = 0 ; out . mJc [ 18 ] = 0 ; out . mJc [ 19
] = 0 ; out . mJc [ 20 ] = 0 ; out . mJc [ 21 ] = 0 ; out . mJc [ 22 ] = 0 ;
out . mJc [ 23 ] = 0 ; out . mJc [ 24 ] = 0 ; out . mJc [ 25 ] = 0 ; out .
mJc [ 26 ] = 0 ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T
ds_ddcer ( const NeDynamicSystem * LC , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void ) LC ; ( void ) LC ; ( void )
t2 ; return 0 ; } static int32_T ds_ddcer_p ( const NeDynamicSystem * LC ,
const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern
out ; ( void ) t1 ; ( void ) LC ; out = t2 -> mDDCER_P ; out . mNumCol =
14ULL ; out . mNumRow = 0ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 0 ;
out . mJc [ 2 ] = 0 ; out . mJc [ 3 ] = 0 ; out . mJc [ 4 ] = 0 ; out . mJc [
5 ] = 0 ; out . mJc [ 6 ] = 0 ; out . mJc [ 7 ] = 0 ; out . mJc [ 8 ] = 0 ;
out . mJc [ 9 ] = 0 ; out . mJc [ 10 ] = 0 ; out . mJc [ 11 ] = 0 ; out . mJc
[ 12 ] = 0 ; out . mJc [ 13 ] = 0 ; out . mJc [ 14 ] = 0 ; ( void ) LC ; (
void ) t2 ; return 0 ; } static int32_T ds_del_v ( const NeDynamicSystem * LC
, const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; (
void ) LC ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T ds_del_v0
( const NeDynamicSystem * LC , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void ) LC ; ( void ) LC ; ( void )
t2 ; return 0 ; } static int32_T ds_del_tmax ( const NeDynamicSystem * LC ,
const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; (
void ) LC ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T ds_del_t
( const NeDynamicSystem * LC , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void ) LC ; ( void ) LC ; ( void )
t2 ; return 0 ; } static int32_T ds_dxdelt ( const NeDynamicSystem * LC ,
const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; (
void ) LC ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T
ds_dxdelt_p ( const NeDynamicSystem * LC , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { PmSparsityPattern out ; ( void ) t1 ; ( void ) LC ;
out = t2 -> mDXDELT_P ; out . mNumCol = 26ULL ; out . mNumRow = 0ULL ; out .
mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 0 ; out . mJc [ 2 ] = 0 ; out . mJc [ 3 ] =
0 ; out . mJc [ 4 ] = 0 ; out . mJc [ 5 ] = 0 ; out . mJc [ 6 ] = 0 ; out .
mJc [ 7 ] = 0 ; out . mJc [ 8 ] = 0 ; out . mJc [ 9 ] = 0 ; out . mJc [ 10 ]
= 0 ; out . mJc [ 11 ] = 0 ; out . mJc [ 12 ] = 0 ; out . mJc [ 13 ] = 0 ;
out . mJc [ 14 ] = 0 ; out . mJc [ 15 ] = 0 ; out . mJc [ 16 ] = 0 ; out .
mJc [ 17 ] = 0 ; out . mJc [ 18 ] = 0 ; out . mJc [ 19 ] = 0 ; out . mJc [ 20
] = 0 ; out . mJc [ 21 ] = 0 ; out . mJc [ 22 ] = 0 ; out . mJc [ 23 ] = 0 ;
out . mJc [ 24 ] = 0 ; out . mJc [ 25 ] = 0 ; out . mJc [ 26 ] = 0 ; ( void )
LC ; ( void ) t2 ; return 0 ; } static int32_T ds_dudelt ( const
NeDynamicSystem * LC , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { ( void ) t1 ; ( void ) LC ; ( void ) LC ; ( void ) t2 ; return 0 ; }
static int32_T ds_dudelt_p ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern out ;
( void ) t1 ; ( void ) LC ; out = t2 -> mDUDELT_P ; out . mNumCol = 1ULL ;
out . mNumRow = 0ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 0 ; ( void )
LC ; ( void ) t2 ; return 0 ; } static int32_T ds_dtdelt ( const
NeDynamicSystem * LC , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { ( void ) t1 ; ( void ) LC ; ( void ) LC ; ( void ) t2 ; return 0 ; }
static int32_T ds_dtdelt_p ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern out ;
( void ) t1 ; ( void ) LC ; out = t2 -> mDTDELT_P ; out . mNumCol = 1ULL ;
out . mNumRow = 0ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 0 ; ( void )
LC ; ( void ) t2 ; return 0 ; } static int32_T ds_cache_r ( const
NeDynamicSystem * LC , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { ( void ) t1 ; ( void ) LC ; ( void ) LC ; ( void ) t2 ; return 0 ; }
static int32_T ds_init_r ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmRealVector out ; (
void ) t1 ; ( void ) LC ; out = t2 -> mINIT_R ; out . mX [ 0 ] = 0.0 ; out .
mX [ 1 ] = 0.0 ; out . mX [ 2 ] = 0.0 ; out . mX [ 3 ] = 0.0 ; out . mX [ 4 ]
= 0.0 ; out . mX [ 5 ] = 0.0 ; out . mX [ 6 ] = 0.0 ; out . mX [ 7 ] = 0.0 ;
out . mX [ 8 ] = 0.0 ; out . mX [ 9 ] = 0.0 ; out . mX [ 10 ] = 0.0 ; out .
mX [ 11 ] = 0.0 ; out . mX [ 12 ] = 0.0 ; out . mX [ 13 ] = 0.0 ; ( void ) LC
; ( void ) t2 ; return 0 ; } static int32_T ds_init_i ( const NeDynamicSystem
* LC , const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) {
PmIntVector out ; ( void ) t1 ; ( void ) LC ; out = t2 -> mINIT_I ; out . mX
[ 0 ] = 1 ; out . mX [ 1 ] = 1 ; out . mX [ 2 ] = 1 ; ( void ) LC ; ( void )
t2 ; return 0 ; } static int32_T ds_sfp ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void )
LC ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T ds_sfo ( const
NeDynamicSystem * LC , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { ( void ) t1 ; ( void ) LC ; ( void ) LC ; ( void ) t2 ; return 0 ; }
static int32_T ds_duf ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void )
LC ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T ds_duf_p ( const
NeDynamicSystem * LC , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { PmSparsityPattern out ; ( void ) t1 ; ( void ) LC ; out = t2 -> mDUF_P
; out . mNumCol = 1ULL ; out . mNumRow = 26ULL ; out . mJc [ 0 ] = 0 ; out .
mJc [ 1 ] = 0 ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T
ds_dtf ( const NeDynamicSystem * LC , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void ) LC ; ( void ) LC ; ( void )
t2 ; return 0 ; } static int32_T ds_dtf_p ( const NeDynamicSystem * LC ,
const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern
out ; ( void ) t1 ; ( void ) LC ; out = t2 -> mDTF_P ; out . mNumCol = 1ULL ;
out . mNumRow = 26ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 0 ; ( void )
LC ; ( void ) t2 ; return 0 ; } static int32_T ds_ddf_p ( const
NeDynamicSystem * LC , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { PmSparsityPattern out ; ( void ) t1 ; ( void ) LC ; out = t2 -> mDDF_P
; out . mNumCol = 14ULL ; out . mNumRow = 26ULL ; out . mJc [ 0 ] = 0 ; out .
mJc [ 1 ] = 0 ; out . mJc [ 2 ] = 1 ; out . mJc [ 3 ] = 2 ; out . mJc [ 4 ] =
2 ; out . mJc [ 5 ] = 2 ; out . mJc [ 6 ] = 2 ; out . mJc [ 7 ] = 2 ; out .
mJc [ 8 ] = 2 ; out . mJc [ 9 ] = 3 ; out . mJc [ 10 ] = 4 ; out . mJc [ 11 ]
= 4 ; out . mJc [ 12 ] = 4 ; out . mJc [ 13 ] = 4 ; out . mJc [ 14 ] = 4 ;
out . mIr [ 0 ] = 20 ; out . mIr [ 1 ] = 20 ; out . mIr [ 2 ] = 25 ; out .
mIr [ 3 ] = 25 ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T ds_b
( const NeDynamicSystem * LC , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void ) LC ; ( void ) LC ; ( void )
t2 ; return 0 ; } static int32_T ds_b_p ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern out ;
( void ) t1 ; ( void ) LC ; out = t2 -> mB_P ; out . mNumCol = 1ULL ; out .
mNumRow = 26ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 0 ; ( void ) LC ; (
void ) t2 ; return 0 ; } static int32_T ds_c ( const NeDynamicSystem * LC ,
const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; (
void ) LC ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T ds_c_p (
const NeDynamicSystem * LC , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { PmSparsityPattern out ; ( void ) t1 ; ( void ) LC ;
out = t2 -> mC_P ; out . mNumCol = 1ULL ; out . mNumRow = 26ULL ; out . mJc [
0 ] = 0 ; out . mJc [ 1 ] = 0 ; ( void ) LC ; ( void ) t2 ; return 0 ; }
static int32_T ds_tduf_p ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern out ;
( void ) t1 ; ( void ) LC ; out = t2 -> mTDUF_P ; out . mNumCol = 1ULL ; out
. mNumRow = 26ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 0 ; ( void ) LC ;
( void ) t2 ; return 0 ; } static int32_T ds_dwf ( const NeDynamicSystem * LC
, const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; (
void ) LC ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T ds_dwf_p
( const NeDynamicSystem * LC , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { PmSparsityPattern out ; ( void ) t1 ; ( void ) LC ;
out = t2 -> mDWF_P ; out . mNumCol = 0ULL ; out . mNumRow = 26ULL ; out . mJc
[ 0 ] = 0 ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T ds_dpdxf
( const NeDynamicSystem * LC , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void ) LC ; ( void ) LC ; ( void )
t2 ; return 0 ; } static int32_T ds_dpdxf_p ( const NeDynamicSystem * LC ,
const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern
out ; ( void ) t1 ; ( void ) LC ; out = t2 -> mDPDXF_P ; out . mNumCol = 6ULL
; out . mNumRow = 36ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 0 ; out .
mJc [ 2 ] = 0 ; out . mJc [ 3 ] = 0 ; out . mJc [ 4 ] = 0 ; out . mJc [ 5 ] =
0 ; out . mJc [ 6 ] = 0 ; ( void ) LC ; ( void ) t2 ; return 0 ; } static
int32_T ds_vmf ( const NeDynamicSystem * LC , const NeDynamicSystemInput * t1
, NeDsMethodOutput * t2 ) { PmBoolVector out ; ( void ) t1 ; ( void ) LC ;
out = t2 -> mVMF ; out . mX [ 0 ] = false ; out . mX [ 1 ] = false ; out . mX
[ 2 ] = false ; out . mX [ 3 ] = false ; out . mX [ 4 ] = false ; out . mX [
5 ] = false ; out . mX [ 6 ] = false ; out . mX [ 7 ] = false ; out . mX [ 8
] = false ; out . mX [ 9 ] = false ; out . mX [ 10 ] = false ; out . mX [ 11
] = false ; out . mX [ 12 ] = false ; out . mX [ 13 ] = true ; out . mX [ 14
] = true ; out . mX [ 15 ] = true ; out . mX [ 16 ] = true ; out . mX [ 17 ]
= true ; out . mX [ 18 ] = true ; out . mX [ 19 ] = true ; out . mX [ 20 ] =
true ; out . mX [ 21 ] = false ; out . mX [ 22 ] = true ; out . mX [ 23 ] =
true ; out . mX [ 24 ] = true ; out . mX [ 25 ] = true ; ( void ) LC ; ( void
) t2 ; return 0 ; } static int32_T ds_slf ( const NeDynamicSystem * LC ,
const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmBoolVector out
; ( void ) t1 ; ( void ) LC ; out = t2 -> mSLF ; out . mX [ 0 ] = false ; out
. mX [ 1 ] = false ; out . mX [ 2 ] = false ; out . mX [ 3 ] = false ; out .
mX [ 4 ] = false ; out . mX [ 5 ] = false ; out . mX [ 6 ] = false ; out . mX
[ 7 ] = false ; out . mX [ 8 ] = false ; out . mX [ 9 ] = false ; out . mX [
10 ] = false ; out . mX [ 11 ] = false ; out . mX [ 12 ] = false ; out . mX [
13 ] = false ; out . mX [ 14 ] = false ; out . mX [ 15 ] = false ; out . mX [
16 ] = false ; out . mX [ 17 ] = false ; out . mX [ 18 ] = false ; out . mX [
19 ] = true ; out . mX [ 20 ] = true ; out . mX [ 21 ] = false ; out . mX [
22 ] = false ; out . mX [ 23 ] = false ; out . mX [ 24 ] = true ; out . mX [
25 ] = true ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T ds_dnf
( const NeDynamicSystem * LC , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void ) LC ; ( void ) LC ; ( void )
t2 ; return 0 ; } static int32_T ds_dnf_p ( const NeDynamicSystem * LC ,
const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern
out ; ( void ) t1 ; ( void ) LC ; out = t2 -> mDNF_P ; out . mNumCol = 8ULL ;
out . mNumRow = 26ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 0 ; out . mJc
[ 2 ] = 0 ; out . mJc [ 3 ] = 0 ; out . mJc [ 4 ] = 0 ; out . mJc [ 5 ] = 0 ;
out . mJc [ 6 ] = 0 ; out . mJc [ 7 ] = 0 ; out . mJc [ 8 ] = 0 ; ( void ) LC
; ( void ) t2 ; return 0 ; } static int32_T ds_dnf_v_x ( const
NeDynamicSystem * LC , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { PmBoolVector out ; ( void ) t1 ; ( void ) LC ; out = t2 -> mDNF_V_X ;
out . mX [ 0 ] = true ; out . mX [ 1 ] = true ; out . mX [ 2 ] = true ; out .
mX [ 3 ] = true ; out . mX [ 4 ] = true ; out . mX [ 5 ] = true ; out . mX [
6 ] = true ; out . mX [ 7 ] = true ; out . mX [ 8 ] = true ; out . mX [ 9 ] =
true ; out . mX [ 10 ] = true ; out . mX [ 11 ] = true ; out . mX [ 12 ] =
true ; out . mX [ 13 ] = true ; out . mX [ 14 ] = true ; out . mX [ 15 ] =
true ; out . mX [ 16 ] = true ; out . mX [ 17 ] = true ; out . mX [ 18 ] =
true ; out . mX [ 19 ] = true ; out . mX [ 20 ] = true ; out . mX [ 21 ] =
false ; out . mX [ 22 ] = true ; out . mX [ 23 ] = true ; out . mX [ 24 ] =
true ; out . mX [ 25 ] = true ; ( void ) LC ; ( void ) t2 ; return 0 ; }
static int32_T ds_slf0 ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmBoolVector out ; (
void ) t1 ; ( void ) LC ; out = t2 -> mSLF0 ; out . mX [ 0 ] = false ; out .
mX [ 1 ] = false ; out . mX [ 2 ] = false ; out . mX [ 3 ] = false ; out . mX
[ 4 ] = false ; out . mX [ 5 ] = false ; out . mX [ 6 ] = false ; out . mX [
7 ] = false ; out . mX [ 8 ] = false ; out . mX [ 9 ] = false ; out . mX [ 10
] = false ; out . mX [ 11 ] = false ; out . mX [ 12 ] = false ; out . mX [ 13
] = false ; out . mX [ 14 ] = false ; out . mX [ 15 ] = false ; out . mX [ 16
] = false ; out . mX [ 17 ] = false ; out . mX [ 18 ] = false ; out . mX [ 19
] = true ; out . mX [ 20 ] = true ; out . mX [ 21 ] = false ; out . mX [ 22 ]
= false ; out . mX [ 23 ] = false ; out . mX [ 24 ] = true ; out . mX [ 25 ]
= true ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T ds_vpf (
const NeDynamicSystem * LC , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { PmBoolVector out ; ( void ) t1 ; ( void ) LC ; out
= t2 -> mVPF ; out . mX [ 0 ] = false ; out . mX [ 1 ] = false ; out . mX [ 2
] = false ; out . mX [ 3 ] = false ; out . mX [ 4 ] = false ; out . mX [ 5 ]
= false ; out . mX [ 6 ] = false ; out . mX [ 7 ] = false ; out . mX [ 8 ] =
false ; out . mX [ 9 ] = false ; out . mX [ 10 ] = false ; out . mX [ 11 ] =
false ; out . mX [ 12 ] = false ; out . mX [ 13 ] = false ; out . mX [ 14 ] =
false ; out . mX [ 15 ] = false ; out . mX [ 16 ] = false ; out . mX [ 17 ] =
false ; out . mX [ 18 ] = false ; out . mX [ 19 ] = false ; out . mX [ 20 ] =
false ; out . mX [ 21 ] = false ; out . mX [ 22 ] = false ; out . mX [ 23 ] =
false ; out . mX [ 24 ] = false ; out . mX [ 25 ] = false ; ( void ) LC ; (
void ) t2 ; return 0 ; } static int32_T ds_vsf ( const NeDynamicSystem * LC ,
const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmBoolVector out
; ( void ) t1 ; ( void ) LC ; out = t2 -> mVSF ; out . mX [ 0 ] = false ; out
. mX [ 1 ] = false ; out . mX [ 2 ] = false ; out . mX [ 3 ] = false ; out .
mX [ 4 ] = false ; out . mX [ 5 ] = false ; out . mX [ 6 ] = false ; out . mX
[ 7 ] = false ; out . mX [ 8 ] = false ; out . mX [ 9 ] = false ; out . mX [
10 ] = false ; out . mX [ 11 ] = false ; out . mX [ 12 ] = false ; out . mX [
13 ] = false ; out . mX [ 14 ] = false ; out . mX [ 15 ] = false ; out . mX [
16 ] = false ; out . mX [ 17 ] = false ; out . mX [ 18 ] = false ; out . mX [
19 ] = false ; out . mX [ 20 ] = false ; out . mX [ 21 ] = false ; out . mX [
22 ] = false ; out . mX [ 23 ] = false ; out . mX [ 24 ] = false ; out . mX [
25 ] = false ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T
ds_freqs ( const NeDynamicSystem * LC , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void ) LC ; ( void ) LC ; ( void )
t2 ; return 0 ; } static int32_T ds_icr ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmRealVector out ;
real_T X_idx_11 ; real_T X_idx_12 ; real_T X_idx_4 ; real_T X_idx_7 ; ( void
) LC ; X_idx_4 = t1 -> mX . mX [ 4 ] ; X_idx_7 = t1 -> mX . mX [ 7 ] ;
X_idx_11 = t1 -> mX . mX [ 11 ] ; X_idx_12 = t1 -> mX . mX [ 12 ] ; out = t2
-> mICR ; out . mX [ 0 ] = X_idx_7 - X_idx_4 ; out . mX [ 1 ] = X_idx_11 -
X_idx_12 ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T ds_icr_im
( const NeDynamicSystem * LC , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { PmIntVector out ; ( void ) t1 ; ( void ) LC ; out =
t2 -> mICR_IM ; out . mX [ 0 ] = 3 ; out . mX [ 1 ] = 3 ; ( void ) LC ; (
void ) t2 ; return 0 ; } static int32_T ds_icr_id ( const NeDynamicSystem *
LC , const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmBoolVector
out ; ( void ) t1 ; ( void ) LC ; out = t2 -> mICR_ID ; out . mX [ 0 ] =
false ; out . mX [ 1 ] = false ; ( void ) LC ; ( void ) t2 ; return 0 ; }
static int32_T ds_icr_il ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmBoolVector out ; (
void ) t1 ; ( void ) LC ; out = t2 -> mICR_IL ; out . mX [ 0 ] = true ; out .
mX [ 1 ] = true ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T
ds_dxicr ( const NeDynamicSystem * LC , const NeDynamicSystemInput * t4 ,
NeDsMethodOutput * t5 ) { PmRealVector out ; ( void ) t4 ; ( void ) LC ; out
= t5 -> mDXICR ; out . mX [ 0 ] = - 1.0 ; out . mX [ 1 ] = - 0.0 ; out . mX [
2 ] = - 0.0 ; out . mX [ 3 ] = 1.0 ; out . mX [ 4 ] = 1.0 ; out . mX [ 5 ] =
- 1.0 ; ( void ) LC ; ( void ) t5 ; return 0 ; } static int32_T ds_dxicr_p (
const NeDynamicSystem * LC , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { PmSparsityPattern out ; ( void ) t1 ; ( void ) LC ;
out = t2 -> mDXICR_P ; out . mNumCol = 26ULL ; out . mNumRow = 2ULL ; out .
mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 0 ; out . mJc [ 2 ] = 0 ; out . mJc [ 3 ] =
0 ; out . mJc [ 4 ] = 0 ; out . mJc [ 5 ] = 1 ; out . mJc [ 6 ] = 2 ; out .
mJc [ 7 ] = 3 ; out . mJc [ 8 ] = 4 ; out . mJc [ 9 ] = 4 ; out . mJc [ 10 ]
= 4 ; out . mJc [ 11 ] = 4 ; out . mJc [ 12 ] = 5 ; out . mJc [ 13 ] = 6 ;
out . mJc [ 14 ] = 6 ; out . mJc [ 15 ] = 6 ; out . mJc [ 16 ] = 6 ; out .
mJc [ 17 ] = 6 ; out . mJc [ 18 ] = 6 ; out . mJc [ 19 ] = 6 ; out . mJc [ 20
] = 6 ; out . mJc [ 21 ] = 6 ; out . mJc [ 22 ] = 6 ; out . mJc [ 23 ] = 6 ;
out . mJc [ 24 ] = 6 ; out . mJc [ 25 ] = 6 ; out . mJc [ 26 ] = 6 ; out .
mIr [ 0 ] = 0 ; out . mIr [ 1 ] = 0 ; out . mIr [ 2 ] = 0 ; out . mIr [ 3 ] =
0 ; out . mIr [ 4 ] = 1 ; out . mIr [ 5 ] = 1 ; ( void ) LC ; ( void ) t2 ;
return 0 ; } static int32_T ds_ddicr ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void )
LC ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T ds_ddicr_p (
const NeDynamicSystem * LC , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { PmSparsityPattern out ; ( void ) t1 ; ( void ) LC ;
out = t2 -> mDDICR_P ; out . mNumCol = 14ULL ; out . mNumRow = 2ULL ; out .
mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 0 ; out . mJc [ 2 ] = 0 ; out . mJc [ 3 ] =
0 ; out . mJc [ 4 ] = 0 ; out . mJc [ 5 ] = 0 ; out . mJc [ 6 ] = 0 ; out .
mJc [ 7 ] = 0 ; out . mJc [ 8 ] = 0 ; out . mJc [ 9 ] = 0 ; out . mJc [ 10 ]
= 0 ; out . mJc [ 11 ] = 0 ; out . mJc [ 12 ] = 0 ; out . mJc [ 13 ] = 0 ;
out . mJc [ 14 ] = 0 ; ( void ) LC ; ( void ) t2 ; return 0 ; } static
int32_T ds_tduicr_p ( const NeDynamicSystem * LC , const NeDynamicSystemInput
* t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern out ; ( void ) t1 ; ( void
) LC ; out = t2 -> mTDUICR_P ; out . mNumCol = 1ULL ; out . mNumRow = 2ULL ;
out . mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 0 ; ( void ) LC ; ( void ) t2 ;
return 0 ; } static int32_T ds_icrm ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void )
LC ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T ds_icrm_p (
const NeDynamicSystem * LC , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { PmSparsityPattern out ; ( void ) t1 ; ( void ) LC ;
out = t2 -> mICRM_P ; out . mNumCol = 26ULL ; out . mNumRow = 2ULL ; out .
mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 0 ; out . mJc [ 2 ] = 0 ; out . mJc [ 3 ] =
0 ; out . mJc [ 4 ] = 0 ; out . mJc [ 5 ] = 0 ; out . mJc [ 6 ] = 0 ; out .
mJc [ 7 ] = 0 ; out . mJc [ 8 ] = 0 ; out . mJc [ 9 ] = 0 ; out . mJc [ 10 ]
= 0 ; out . mJc [ 11 ] = 0 ; out . mJc [ 12 ] = 0 ; out . mJc [ 13 ] = 0 ;
out . mJc [ 14 ] = 0 ; out . mJc [ 15 ] = 0 ; out . mJc [ 16 ] = 0 ; out .
mJc [ 17 ] = 0 ; out . mJc [ 18 ] = 0 ; out . mJc [ 19 ] = 0 ; out . mJc [ 20
] = 0 ; out . mJc [ 21 ] = 0 ; out . mJc [ 22 ] = 0 ; out . mJc [ 23 ] = 0 ;
out . mJc [ 24 ] = 0 ; out . mJc [ 25 ] = 0 ; out . mJc [ 26 ] = 0 ; ( void )
LC ; ( void ) t2 ; return 0 ; } static int32_T ds_dxicrm ( const
NeDynamicSystem * LC , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { ( void ) t1 ; ( void ) LC ; ( void ) LC ; ( void ) t2 ; return 0 ; }
static int32_T ds_dxicrm_p ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern out ;
( void ) t1 ; ( void ) LC ; out = t2 -> mDXICRM_P ; out . mNumCol = 26ULL ;
out . mNumRow = 0ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 0 ; out . mJc
[ 2 ] = 0 ; out . mJc [ 3 ] = 0 ; out . mJc [ 4 ] = 0 ; out . mJc [ 5 ] = 0 ;
out . mJc [ 6 ] = 0 ; out . mJc [ 7 ] = 0 ; out . mJc [ 8 ] = 0 ; out . mJc [
9 ] = 0 ; out . mJc [ 10 ] = 0 ; out . mJc [ 11 ] = 0 ; out . mJc [ 12 ] = 0
; out . mJc [ 13 ] = 0 ; out . mJc [ 14 ] = 0 ; out . mJc [ 15 ] = 0 ; out .
mJc [ 16 ] = 0 ; out . mJc [ 17 ] = 0 ; out . mJc [ 18 ] = 0 ; out . mJc [ 19
] = 0 ; out . mJc [ 20 ] = 0 ; out . mJc [ 21 ] = 0 ; out . mJc [ 22 ] = 0 ;
out . mJc [ 23 ] = 0 ; out . mJc [ 24 ] = 0 ; out . mJc [ 25 ] = 0 ; out .
mJc [ 26 ] = 0 ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T
ds_ddicrm ( const NeDynamicSystem * LC , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void ) LC ; ( void ) LC ; ( void )
t2 ; return 0 ; } static int32_T ds_ddicrm_p ( const NeDynamicSystem * LC ,
const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern
out ; ( void ) t1 ; ( void ) LC ; out = t2 -> mDDICRM_P ; out . mNumCol =
14ULL ; out . mNumRow = 0ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 0 ;
out . mJc [ 2 ] = 0 ; out . mJc [ 3 ] = 0 ; out . mJc [ 4 ] = 0 ; out . mJc [
5 ] = 0 ; out . mJc [ 6 ] = 0 ; out . mJc [ 7 ] = 0 ; out . mJc [ 8 ] = 0 ;
out . mJc [ 9 ] = 0 ; out . mJc [ 10 ] = 0 ; out . mJc [ 11 ] = 0 ; out . mJc
[ 12 ] = 0 ; out . mJc [ 13 ] = 0 ; out . mJc [ 14 ] = 0 ; ( void ) LC ; (
void ) t2 ; return 0 ; } static int32_T ds_dimin ( const NeDynamicSystem * LC
, const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmRealVector
out ; ( void ) t1 ; ( void ) LC ; out = t2 -> mDIMIN ; out . mX [ 0 ] = -
pmf_get_inf ( ) ; out . mX [ 1 ] = - pmf_get_inf ( ) ; out . mX [ 2 ] = -
pmf_get_inf ( ) ; out . mX [ 3 ] = - pmf_get_inf ( ) ; out . mX [ 4 ] = -
pmf_get_inf ( ) ; out . mX [ 5 ] = - pmf_get_inf ( ) ; out . mX [ 6 ] = -
pmf_get_inf ( ) ; out . mX [ 7 ] = - pmf_get_inf ( ) ; out . mX [ 8 ] = -
pmf_get_inf ( ) ; out . mX [ 9 ] = - pmf_get_inf ( ) ; out . mX [ 10 ] = -
pmf_get_inf ( ) ; out . mX [ 11 ] = - pmf_get_inf ( ) ; out . mX [ 12 ] = -
pmf_get_inf ( ) ; out . mX [ 13 ] = - pmf_get_inf ( ) ; ( void ) LC ; ( void
) t2 ; return 0 ; } static int32_T ds_dimax ( const NeDynamicSystem * LC ,
const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmRealVector out
; ( void ) t1 ; ( void ) LC ; out = t2 -> mDIMAX ; out . mX [ 0 ] =
pmf_get_inf ( ) ; out . mX [ 1 ] = pmf_get_inf ( ) ; out . mX [ 2 ] =
pmf_get_inf ( ) ; out . mX [ 3 ] = pmf_get_inf ( ) ; out . mX [ 4 ] =
pmf_get_inf ( ) ; out . mX [ 5 ] = pmf_get_inf ( ) ; out . mX [ 6 ] =
pmf_get_inf ( ) ; out . mX [ 7 ] = pmf_get_inf ( ) ; out . mX [ 8 ] =
pmf_get_inf ( ) ; out . mX [ 9 ] = pmf_get_inf ( ) ; out . mX [ 10 ] =
pmf_get_inf ( ) ; out . mX [ 11 ] = pmf_get_inf ( ) ; out . mX [ 12 ] =
pmf_get_inf ( ) ; out . mX [ 13 ] = pmf_get_inf ( ) ; ( void ) LC ; ( void )
t2 ; return 0 ; } static int32_T ds_dxm ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void )
LC ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T ds_dxm_p ( const
NeDynamicSystem * LC , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { PmSparsityPattern out ; ( void ) t1 ; ( void ) LC ; out = t2 -> mDXM_P
; out . mNumCol = 26ULL ; out . mNumRow = 25ULL ; out . mJc [ 0 ] = 0 ; out .
mJc [ 1 ] = 0 ; out . mJc [ 2 ] = 0 ; out . mJc [ 3 ] = 0 ; out . mJc [ 4 ] =
0 ; out . mJc [ 5 ] = 0 ; out . mJc [ 6 ] = 0 ; out . mJc [ 7 ] = 0 ; out .
mJc [ 8 ] = 0 ; out . mJc [ 9 ] = 0 ; out . mJc [ 10 ] = 0 ; out . mJc [ 11 ]
= 0 ; out . mJc [ 12 ] = 0 ; out . mJc [ 13 ] = 0 ; out . mJc [ 14 ] = 0 ;
out . mJc [ 15 ] = 0 ; out . mJc [ 16 ] = 0 ; out . mJc [ 17 ] = 0 ; out .
mJc [ 18 ] = 0 ; out . mJc [ 19 ] = 0 ; out . mJc [ 20 ] = 0 ; out . mJc [ 21
] = 0 ; out . mJc [ 22 ] = 0 ; out . mJc [ 23 ] = 0 ; out . mJc [ 24 ] = 0 ;
out . mJc [ 25 ] = 0 ; out . mJc [ 26 ] = 0 ; ( void ) LC ; ( void ) t2 ;
return 0 ; } static int32_T ds_ddm ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void )
LC ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T ds_ddm_p ( const
NeDynamicSystem * LC , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { PmSparsityPattern out ; ( void ) t1 ; ( void ) LC ; out = t2 -> mDDM_P
; out . mNumCol = 14ULL ; out . mNumRow = 25ULL ; out . mJc [ 0 ] = 0 ; out .
mJc [ 1 ] = 0 ; out . mJc [ 2 ] = 0 ; out . mJc [ 3 ] = 0 ; out . mJc [ 4 ] =
0 ; out . mJc [ 5 ] = 0 ; out . mJc [ 6 ] = 0 ; out . mJc [ 7 ] = 0 ; out .
mJc [ 8 ] = 0 ; out . mJc [ 9 ] = 0 ; out . mJc [ 10 ] = 0 ; out . mJc [ 11 ]
= 0 ; out . mJc [ 12 ] = 0 ; out . mJc [ 13 ] = 0 ; out . mJc [ 14 ] = 0 ; (
void ) LC ; ( void ) t2 ; return 0 ; } static int32_T ds_dum ( const
NeDynamicSystem * LC , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { ( void ) t1 ; ( void ) LC ; ( void ) LC ; ( void ) t2 ; return 0 ; }
static int32_T ds_dum_p ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern out ;
( void ) t1 ; ( void ) LC ; out = t2 -> mDUM_P ; out . mNumCol = 1ULL ; out .
mNumRow = 25ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 0 ; ( void ) LC ; (
void ) t2 ; return 0 ; } static int32_T ds_dtm ( const NeDynamicSystem * LC ,
const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; (
void ) LC ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T ds_dtm_p
( const NeDynamicSystem * LC , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { PmSparsityPattern out ; ( void ) t1 ; ( void ) LC ;
out = t2 -> mDTM_P ; out . mNumCol = 1ULL ; out . mNumRow = 25ULL ; out . mJc
[ 0 ] = 0 ; out . mJc [ 1 ] = 0 ; ( void ) LC ; ( void ) t2 ; return 0 ; }
static int32_T ds_dpm ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void )
LC ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T ds_dpm_p ( const
NeDynamicSystem * LC , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { PmSparsityPattern out ; ( void ) t1 ; ( void ) LC ; out = t2 -> mDPM_P
; out . mNumCol = 6ULL ; out . mNumRow = 25ULL ; out . mJc [ 0 ] = 0 ; out .
mJc [ 1 ] = 0 ; out . mJc [ 2 ] = 0 ; out . mJc [ 3 ] = 0 ; out . mJc [ 4 ] =
0 ; out . mJc [ 5 ] = 0 ; out . mJc [ 6 ] = 0 ; ( void ) LC ; ( void ) t2 ;
return 0 ; } static int32_T ds_vmm ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmBoolVector out ; (
void ) t1 ; ( void ) LC ; out = t2 -> mVMM ; out . mX [ 0 ] = false ; out .
mX [ 1 ] = false ; out . mX [ 2 ] = false ; out . mX [ 3 ] = false ; out . mX
[ 4 ] = false ; out . mX [ 5 ] = false ; out . mX [ 6 ] = false ; out . mX [
7 ] = false ; out . mX [ 8 ] = false ; out . mX [ 9 ] = false ; out . mX [ 10
] = false ; out . mX [ 11 ] = false ; out . mX [ 12 ] = false ; out . mX [ 13
] = false ; out . mX [ 14 ] = false ; out . mX [ 15 ] = false ; out . mX [ 16
] = false ; out . mX [ 17 ] = false ; out . mX [ 18 ] = false ; out . mX [ 19
] = false ; out . mX [ 20 ] = false ; out . mX [ 21 ] = false ; out . mX [ 22
] = false ; out . mX [ 23 ] = false ; out . mX [ 24 ] = false ; ( void ) LC ;
( void ) t2 ; return 0 ; } static int32_T ds_dp_l ( const NeDynamicSystem *
LC , const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1
; ( void ) LC ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T
ds_dp_i ( const NeDynamicSystem * LC , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void ) LC ; ( void ) LC ; ( void )
t2 ; return 0 ; } static int32_T ds_dp_j ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void )
LC ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T ds_dp_r ( const
NeDynamicSystem * LC , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { ( void ) t1 ; ( void ) LC ; ( void ) LC ; ( void ) t2 ; return 0 ; }
static int32_T ds_qu ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void )
LC ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T ds_qt ( const
NeDynamicSystem * LC , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { ( void ) t1 ; ( void ) LC ; ( void ) LC ; ( void ) t2 ; return 0 ; }
static int32_T ds_q1 ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmRealVector out ; (
void ) t1 ; ( void ) LC ; out = t2 -> mQ1 ; out . mX [ 0 ] = 0.0 ; out . mX [
1 ] = 0.0 ; out . mX [ 2 ] = 0.0 ; out . mX [ 3 ] = 0.0 ; out . mX [ 4 ] =
0.0 ; out . mX [ 5 ] = 0.0 ; out . mX [ 6 ] = - 3.7584901608096864E+6 ; out .
mX [ 7 ] = 0.0 ; out . mX [ 8 ] = 0.0 ; out . mX [ 9 ] = -
3.7544642857143036E+6 ; out . mX [ 10 ] = 0.0 ; out . mX [ 11 ] = 0.0 ; out .
mX [ 12 ] = 0.0 ; out . mX [ 13 ] = 0.0 ; out . mX [ 14 ] = 0.0 ; out . mX [
15 ] = 0.0 ; out . mX [ 16 ] = 0.0 ; ( void ) LC ; ( void ) t2 ; return 0 ; }
static int32_T ds_qu_p ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern out ;
( void ) t1 ; ( void ) LC ; out = t2 -> mQU_P ; out . mNumCol = 1ULL ; out .
mNumRow = 26ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 0 ; ( void ) LC ; (
void ) t2 ; return 0 ; } static int32_T ds_qt_p ( const NeDynamicSystem * LC
, const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) {
PmSparsityPattern out ; ( void ) t1 ; ( void ) LC ; out = t2 -> mQT_P ; out .
mNumCol = 1ULL ; out . mNumRow = 26ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1
] = 0 ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T ds_q1_p (
const NeDynamicSystem * LC , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { PmSparsityPattern out ; ( void ) t1 ; ( void ) LC ;
out = t2 -> mQ1_P ; out . mNumCol = 1ULL ; out . mNumRow = 26ULL ; out . mJc
[ 0 ] = 0 ; out . mJc [ 1 ] = 17 ; out . mIr [ 0 ] = 0 ; out . mIr [ 1 ] = 1
; out . mIr [ 2 ] = 2 ; out . mIr [ 3 ] = 3 ; out . mIr [ 4 ] = 4 ; out . mIr
[ 5 ] = 5 ; out . mIr [ 6 ] = 6 ; out . mIr [ 7 ] = 8 ; out . mIr [ 8 ] = 9 ;
out . mIr [ 9 ] = 10 ; out . mIr [ 10 ] = 14 ; out . mIr [ 11 ] = 17 ; out .
mIr [ 12 ] = 19 ; out . mIr [ 13 ] = 20 ; out . mIr [ 14 ] = 22 ; out . mIr [
15 ] = 23 ; out . mIr [ 16 ] = 24 ; ( void ) LC ; ( void ) t2 ; return 0 ; }
static int32_T ds_solverhits ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void )
LC ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T ds_var_tol (
const NeDynamicSystem * LC , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { PmRealVector out ; ( void ) t1 ; ( void ) LC ; out
= t2 -> mVAR_TOL ; out . mX [ 0 ] = 1.0E-9 ; out . mX [ 1 ] = 1.0E-9 ; out .
mX [ 2 ] = 1.0E-9 ; out . mX [ 3 ] = 1.0E-9 ; out . mX [ 4 ] = 1.0E-9 ; out .
mX [ 5 ] = 1.0E-9 ; out . mX [ 6 ] = 1.0E-9 ; out . mX [ 7 ] = 1.0E-9 ; out .
mX [ 8 ] = 1.0E-9 ; out . mX [ 9 ] = 1.0E-9 ; out . mX [ 10 ] = 1.0E-9 ; out
. mX [ 11 ] = 1.0E-9 ; out . mX [ 12 ] = 1.0E-9 ; out . mX [ 13 ] = 1.0E-9 ;
out . mX [ 14 ] = 1.0E-9 ; out . mX [ 15 ] = 1.0E-9 ; out . mX [ 16 ] =
1.0E-9 ; out . mX [ 17 ] = 1.0E-9 ; out . mX [ 18 ] = 1.0E-9 ; out . mX [ 19
] = 1.0E-9 ; out . mX [ 20 ] = 1.0E-9 ; out . mX [ 21 ] = 1.0E-9 ; out . mX [
22 ] = 1.0E-9 ; out . mX [ 23 ] = 1.0E-9 ; out . mX [ 24 ] = 1.0E-9 ; out .
mX [ 25 ] = 1.0E-9 ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T
ds_eq_tol ( const NeDynamicSystem * LC , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { PmRealVector out ; ( void ) t1 ; ( void ) LC ; out
= t2 -> mEQ_TOL ; out . mX [ 0 ] = 1.0E-9 ; out . mX [ 1 ] = 1.0E-9 ; out .
mX [ 2 ] = 1.0E-9 ; out . mX [ 3 ] = 1.0E-9 ; out . mX [ 4 ] = 1.0E-9 ; out .
mX [ 5 ] = 1.0E-9 ; out . mX [ 6 ] = 1.0E-9 ; out . mX [ 7 ] = 1.0E-9 ; out .
mX [ 8 ] = 1.0E-9 ; out . mX [ 9 ] = 1.0E-9 ; out . mX [ 10 ] = 1.0E-9 ; out
. mX [ 11 ] = 1.0E-9 ; out . mX [ 12 ] = 1.0E-9 ; out . mX [ 13 ] = 1.0E-9 ;
out . mX [ 14 ] = 1.0E-9 ; out . mX [ 15 ] = 1.0E-9 ; out . mX [ 16 ] =
1.0E-9 ; out . mX [ 17 ] = 1.0E-9 ; out . mX [ 18 ] = 1.0E-9 ; out . mX [ 19
] = 1.0E-9 ; out . mX [ 20 ] = 1.0E-9 ; out . mX [ 21 ] = 1.0E-9 ; out . mX [
22 ] = 1.0E-9 ; out . mX [ 23 ] = 1.0E-9 ; out . mX [ 24 ] = 1.0E-9 ; out .
mX [ 25 ] = 1.0E-9 ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T
ds_lv ( const NeDynamicSystem * LC , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { PmBoolVector out ; ( void ) t1 ; ( void ) LC ; out
= t2 -> mLV ; out . mX [ 0 ] = false ; out . mX [ 1 ] = false ; out . mX [ 2
] = false ; out . mX [ 3 ] = false ; out . mX [ 4 ] = false ; out . mX [ 5 ]
= false ; out . mX [ 6 ] = false ; out . mX [ 7 ] = false ; out . mX [ 8 ] =
false ; out . mX [ 9 ] = false ; out . mX [ 10 ] = false ; out . mX [ 11 ] =
false ; out . mX [ 12 ] = false ; out . mX [ 13 ] = false ; out . mX [ 14 ] =
false ; out . mX [ 15 ] = false ; out . mX [ 16 ] = false ; out . mX [ 17 ] =
false ; out . mX [ 18 ] = false ; out . mX [ 19 ] = false ; out . mX [ 20 ] =
false ; out . mX [ 21 ] = false ; out . mX [ 22 ] = false ; out . mX [ 23 ] =
false ; out . mX [ 24 ] = false ; out . mX [ 25 ] = false ; ( void ) LC ; (
void ) t2 ; return 0 ; } static int32_T ds_slv ( const NeDynamicSystem * LC ,
const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmBoolVector out
; ( void ) t1 ; ( void ) LC ; out = t2 -> mSLV ; out . mX [ 0 ] = false ; out
. mX [ 1 ] = false ; out . mX [ 2 ] = false ; out . mX [ 3 ] = false ; out .
mX [ 4 ] = false ; out . mX [ 5 ] = false ; out . mX [ 6 ] = false ; out . mX
[ 7 ] = false ; out . mX [ 8 ] = false ; out . mX [ 9 ] = false ; out . mX [
10 ] = false ; out . mX [ 11 ] = false ; out . mX [ 12 ] = false ; out . mX [
13 ] = false ; out . mX [ 14 ] = false ; out . mX [ 15 ] = false ; out . mX [
16 ] = false ; out . mX [ 17 ] = false ; out . mX [ 18 ] = false ; out . mX [
19 ] = false ; out . mX [ 20 ] = false ; out . mX [ 21 ] = true ; out . mX [
22 ] = false ; out . mX [ 23 ] = false ; out . mX [ 24 ] = false ; out . mX [
25 ] = true ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T ds_nldv
( const NeDynamicSystem * LC , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { PmBoolVector out ; ( void ) t1 ; ( void ) LC ; out
= t2 -> mNLDV ; out . mX [ 0 ] = false ; out . mX [ 1 ] = false ; out . mX [
2 ] = false ; out . mX [ 3 ] = false ; out . mX [ 4 ] = false ; out . mX [ 5
] = false ; out . mX [ 6 ] = false ; out . mX [ 7 ] = false ; out . mX [ 8 ]
= false ; out . mX [ 9 ] = false ; out . mX [ 10 ] = false ; out . mX [ 11 ]
= false ; out . mX [ 12 ] = false ; out . mX [ 13 ] = false ; out . mX [ 14 ]
= false ; out . mX [ 15 ] = false ; out . mX [ 16 ] = false ; out . mX [ 17 ]
= false ; out . mX [ 18 ] = false ; out . mX [ 19 ] = false ; out . mX [ 20 ]
= false ; out . mX [ 21 ] = false ; out . mX [ 22 ] = false ; out . mX [ 23 ]
= false ; out . mX [ 24 ] = false ; out . mX [ 25 ] = false ; ( void ) LC ; (
void ) t2 ; return 0 ; } static int32_T ds_sclv ( const NeDynamicSystem * LC
, const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmBoolVector
out ; ( void ) t1 ; ( void ) LC ; out = t2 -> mSCLV ; out . mX [ 0 ] = false
; out . mX [ 1 ] = false ; out . mX [ 2 ] = false ; out . mX [ 3 ] = false ;
out . mX [ 4 ] = false ; out . mX [ 5 ] = false ; out . mX [ 6 ] = false ;
out . mX [ 7 ] = false ; out . mX [ 8 ] = false ; out . mX [ 9 ] = false ;
out . mX [ 10 ] = false ; out . mX [ 11 ] = false ; out . mX [ 12 ] = false ;
out . mX [ 13 ] = false ; out . mX [ 14 ] = false ; out . mX [ 15 ] = false ;
out . mX [ 16 ] = false ; out . mX [ 17 ] = false ; out . mX [ 18 ] = false ;
out . mX [ 19 ] = false ; out . mX [ 20 ] = false ; out . mX [ 21 ] = false ;
out . mX [ 22 ] = false ; out . mX [ 23 ] = false ; out . mX [ 24 ] = false ;
out . mX [ 25 ] = false ; ( void ) LC ; ( void ) t2 ; return 0 ; } static
int32_T ds_y ( const NeDynamicSystem * LC , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void ) LC ; ( void ) LC ; ( void )
t2 ; return 0 ; } static int32_T ds_dxy ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void )
LC ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T ds_dxy_p ( const
NeDynamicSystem * LC , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { PmSparsityPattern out ; ( void ) t1 ; ( void ) LC ; out = t2 -> mDXY_P
; out . mNumCol = 26ULL ; out . mNumRow = 0ULL ; out . mJc [ 0 ] = 0 ; out .
mJc [ 1 ] = 0 ; out . mJc [ 2 ] = 0 ; out . mJc [ 3 ] = 0 ; out . mJc [ 4 ] =
0 ; out . mJc [ 5 ] = 0 ; out . mJc [ 6 ] = 0 ; out . mJc [ 7 ] = 0 ; out .
mJc [ 8 ] = 0 ; out . mJc [ 9 ] = 0 ; out . mJc [ 10 ] = 0 ; out . mJc [ 11 ]
= 0 ; out . mJc [ 12 ] = 0 ; out . mJc [ 13 ] = 0 ; out . mJc [ 14 ] = 0 ;
out . mJc [ 15 ] = 0 ; out . mJc [ 16 ] = 0 ; out . mJc [ 17 ] = 0 ; out .
mJc [ 18 ] = 0 ; out . mJc [ 19 ] = 0 ; out . mJc [ 20 ] = 0 ; out . mJc [ 21
] = 0 ; out . mJc [ 22 ] = 0 ; out . mJc [ 23 ] = 0 ; out . mJc [ 24 ] = 0 ;
out . mJc [ 25 ] = 0 ; out . mJc [ 26 ] = 0 ; ( void ) LC ; ( void ) t2 ;
return 0 ; } static int32_T ds_duy ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void )
LC ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T ds_duy_p ( const
NeDynamicSystem * LC , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { PmSparsityPattern out ; ( void ) t1 ; ( void ) LC ; out = t2 -> mDUY_P
; out . mNumCol = 1ULL ; out . mNumRow = 0ULL ; out . mJc [ 0 ] = 0 ; out .
mJc [ 1 ] = 0 ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T
ds_mduy_p ( const NeDynamicSystem * LC , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { PmSparsityPattern out ; ( void ) t1 ; ( void ) LC ;
out = t2 -> mMDUY_P ; out . mNumCol = 1ULL ; out . mNumRow = 0ULL ; out . mJc
[ 0 ] = 0 ; out . mJc [ 1 ] = 0 ; ( void ) LC ; ( void ) t2 ; return 0 ; }
static int32_T ds_mdxy_p ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern out ;
( void ) t1 ; ( void ) LC ; out = t2 -> mMDXY_P ; out . mNumCol = 26ULL ; out
. mNumRow = 0ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 0 ; out . mJc [ 2
] = 0 ; out . mJc [ 3 ] = 0 ; out . mJc [ 4 ] = 0 ; out . mJc [ 5 ] = 0 ; out
. mJc [ 6 ] = 0 ; out . mJc [ 7 ] = 0 ; out . mJc [ 8 ] = 0 ; out . mJc [ 9 ]
= 0 ; out . mJc [ 10 ] = 0 ; out . mJc [ 11 ] = 0 ; out . mJc [ 12 ] = 0 ;
out . mJc [ 13 ] = 0 ; out . mJc [ 14 ] = 0 ; out . mJc [ 15 ] = 0 ; out .
mJc [ 16 ] = 0 ; out . mJc [ 17 ] = 0 ; out . mJc [ 18 ] = 0 ; out . mJc [ 19
] = 0 ; out . mJc [ 20 ] = 0 ; out . mJc [ 21 ] = 0 ; out . mJc [ 22 ] = 0 ;
out . mJc [ 23 ] = 0 ; out . mJc [ 24 ] = 0 ; out . mJc [ 25 ] = 0 ; out .
mJc [ 26 ] = 0 ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T
ds_tduy_p ( const NeDynamicSystem * LC , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { PmSparsityPattern out ; ( void ) t1 ; ( void ) LC ;
out = t2 -> mTDUY_P ; out . mNumCol = 1ULL ; out . mNumRow = 0ULL ; out . mJc
[ 0 ] = 0 ; out . mJc [ 1 ] = 0 ; ( void ) LC ; ( void ) t2 ; return 0 ; }
static int32_T ds_tdxy_p ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern out ;
( void ) t1 ; ( void ) LC ; out = t2 -> mTDXY_P ; out . mNumCol = 26ULL ; out
. mNumRow = 0ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 0 ; out . mJc [ 2
] = 0 ; out . mJc [ 3 ] = 0 ; out . mJc [ 4 ] = 0 ; out . mJc [ 5 ] = 0 ; out
. mJc [ 6 ] = 0 ; out . mJc [ 7 ] = 0 ; out . mJc [ 8 ] = 0 ; out . mJc [ 9 ]
= 0 ; out . mJc [ 10 ] = 0 ; out . mJc [ 11 ] = 0 ; out . mJc [ 12 ] = 0 ;
out . mJc [ 13 ] = 0 ; out . mJc [ 14 ] = 0 ; out . mJc [ 15 ] = 0 ; out .
mJc [ 16 ] = 0 ; out . mJc [ 17 ] = 0 ; out . mJc [ 18 ] = 0 ; out . mJc [ 19
] = 0 ; out . mJc [ 20 ] = 0 ; out . mJc [ 21 ] = 0 ; out . mJc [ 22 ] = 0 ;
out . mJc [ 23 ] = 0 ; out . mJc [ 24 ] = 0 ; out . mJc [ 25 ] = 0 ; out .
mJc [ 26 ] = 0 ; ( void ) LC ; ( void ) t2 ; return 0 ; } static int32_T
ds_dty ( const NeDynamicSystem * LC , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void ) LC ; ( void ) LC ; ( void )
t2 ; return 0 ; } static int32_T ds_dty_p ( const NeDynamicSystem * LC ,
const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern
out ; ( void ) t1 ; ( void ) LC ; out = t2 -> mDTY_P ; out . mNumCol = 1ULL ;
out . mNumRow = 0ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 0 ; ( void )
LC ; ( void ) t2 ; return 0 ; }

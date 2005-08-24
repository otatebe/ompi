/*
 * Copyright (c) 2004-2005 The Trustees of Indiana University.
 *                         All rights reserved.
 * Copyright (c) 2004-2005 The Trustees of the University of Tennessee.
 *                         All rights reserved.
 * Copyright (c) 2004-2005 High Performance Computing Center Stuttgart, 
 *                         University of Stuttgart.  All rights reserved.
 * Copyright (c) 2004-2005 The Regents of the University of California.
 *                         All rights reserved.
 * $COPYRIGHT$
 * 
 * Additional copyrights may follow
 * 
 * $HEADER$
 */
/**
 * @file
 *
 * BML Management Layer (BML)
 *
 */

#include "mca/mca.h"
#include "mca/btl/btl.h"

#ifndef MCA_BML_R2_H
#define MCA_BML_R2_H

#include "include/types.h"
#include "class/ompi_free_list.h"
#include "mca/bml/bml.h"



typedef mca_bml_base_module_recv_cb_fn_t mca_bml_r2_recv_reg_t;  

void mca_bml_r2_recv_callback(
                              mca_btl_base_module_t* btl, 
                              mca_btl_base_tag_t tag, 
                              mca_btl_base_descriptor_t *des, 
                              void* cbdata); 

/**
 * BML module interface functions and attributes.
 */
struct mca_bml_r2_module_t {
    mca_bml_base_module_t super; 
    size_t num_btl_modules;
    mca_btl_base_module_t** btl_modules; 
    size_t num_btl_progress; 
    mca_btl_base_component_progress_fn_t * btl_progress; 
    mca_bml_r2_recv_reg_t r2_reg[256]; 
    bool btls_added; 
};

typedef struct mca_bml_r2_module_t mca_bml_r2_module_t;

extern mca_bml_r2_module_t mca_bml_r2; 

extern int mca_bml_r2_component_open(void); 
extern int mca_bml_r2_component_close(void); 

extern mca_bml_base_module_t* mca_bml_r2_component_init( 
                                                        int* priority,
                                                        bool enable_progress_threads, 
                                                        bool enable_mpi_threads
                                                        ); 

extern int mca_bml_r2_progress(void); 


int mca_bml_r2_add_procs(
                         size_t nprocs, 
                         struct ompi_proc_t** procs, 
                         struct mca_bml_base_endpoint_t** bml_endpoints, 
                         struct ompi_bitmap_t* reachable
                         ); 

int mca_bml_r2_del_procs(
                         size_t nprocs, 
                         struct ompi_proc_t** procs
                         ); 

int mca_bml_r2_register( 
                        mca_btl_base_tag_t tag, 
                        mca_bml_base_module_recv_cb_fn_t cbfunc, 
                        void* data
                        ); 


int mca_bml_r2_finalize( void ); 

int mca_bml_r2_component_fini(void);

#endif /* OMPI_MCA_BML_R2_H */

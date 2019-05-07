#ifndef CONSTANTS_H
#define CONSTANTS_H

//ECALL codes for SM-calls

// SM CALLS FROM ENCLAVE (from U-mode, within an enclave)
#define UBI_SM_ENCLAVE_BLOCK_DRAM_REGION      1000

#define UBI_SM_ENCLAVE_CHECK_OWNERSHIP        1001

#define UBI_SM_ENCLAVE_ACCEPT_THREAD          1002

#define UBI_SM_ENCLAVE_EXIT_ENCLAVE           1003

#define UBI_SM_ENCLAVE_GET_ATTESTATION_KEY    1004

#define UBI_SM_ENCLAVE_ACCEPT_MESSAGE         1005
#define UBI_SM_ENCLAVE_READ_MESSAGE           1006
#define UBI_SM_ENCLAVE_SEND_MESSAGE           1007

// SM CALLS FROM OS (these come from S-mode)
#define SBI_SM_OS_BLOCK_DRAM_REGION           2000

#define SBI_SM_OS_SET_DMA_RANGE               2001

#define SBI_SM_OS_DRAM_REGION_STATE           2002
#define SBI_SM_OS_DRAM_REGION_OWNER           2003
#define SBI_SM_OS_ASSIGN_DRAM_REGION          2004
#define SBI_SM_OS_FREE_DRAM_REGION            2005
#define SBI_SM_OS_FLUSH_CACHED_DRAM_REGIONS   2006

#define SBI_SM_OS_CREATE_METADATA_REGION      2007
#define SBI_SM_OS_METADATA_REGION_PAGES       2008
#define SBI_SM_OS_METADATA_REGION_START       2009
#define SBI_SM_OS_THREAD_METADATA_PAGES       2010
#define SBI_SM_OS_ENCLAVE_METADATA_PAGES      2011

#define SBI_SM_OS_CREATE_ENCLAVE              2012
#define SBI_SM_OS_LOAD_TRAP_HANDLER           2013
#define SBI_SM_OS_LOAD_PAGE_TABLE             2014
#define SBI_SM_OS_LOAD_PAGE                   2015
#define SBI_SM_OS_LOAD_THREAD                 2016
#define SBI_SM_OS_ASSIGN_THREAD               2017
#define SBI_SM_OS_INIT_ENCLAVE                2018

#define SBI_SM_OS_ENTER_ENCLAVE               2019

#define SBI_SM_OS_DELETE_THREAD               2020

#define SBI_SM_OS_DELETE_ENCLAVE              2021

#define SBI_SM_OS_COPY_DEBUG_ENCLAVE_PAGE     2022

#define SBI_SM_ENCLAVE_FETCH_FIELD            2023

// ARCHI CONSTANTS

#define XLENINT uint64_t
#define SIZE_DRAM 0x80000000
#define SIZE_PAGE 0x1000
#define SIZE_KEY 0x20 // TODO
#define SHIFT_PAGE 12
#define NUM_CORES 2
#define NUM_REGIONS 64
#define MAILBOX_SIZE 128
#define PN_OFFSET 9
#define PPN2_OFFSET 26
#define PAGE_ENTRY_ACL_OFFSET 10
#define DRAM_START 0x80000000

// CSR SPECIALS
#define REGBYTES 8

#define MIE_MEIE 0x800
#define MIP_MSIP 0x8
#define MIP_MTIP 0x80 
#define MIP_STIP 0x20
#define MIP_SSIP 0x2 

#define INTEGER_CONTEXT_SIZE 256 // TODO: is sp byte aligned?

// HACKS

#define MENTRY_IPI_OFFSET 0
#define MENTRY_IPI_PENDING_OFFSET 0
#define IPI_SOFT 0
#define IPI_FENCE_I 0
#define IPI_SFENCE_VMA 0

#endif // CONSTANTS_H

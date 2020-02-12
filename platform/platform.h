#ifndef SM_PLATFORM_H
#define SM_PLATFORM_H

#include "platform_types.h"
#include "platform_assert.h"
#include "ftd/ftd.h"
#include <csr/csr.h>
#include <sm_types.h>

// Lock
// ----
#define platform_lock_acquire(lock) ({ unsigned long __tmp; \
      asm volatile ("amoswap.w.aq %[result], %[value], (%[address]) \n": [result] "=r"(__tmp) : [value] "r"(1), [address] "r"(&((lock)->lock_flag))); \
      ~__tmp; })

#define platform_lock_release(lock) ({ \
      asm volatile ("amoswap.w.rl x0, x0, (%[address]) \n" :: [address] "r"(&((lock)->lock_flag))); })

static inline bool platform_lock_state(platform_lock_t *lock) {
  return ((lock->lock_flag) != 0);
}

// mtime device
extern volatile uint64_t* mtime;

// Core state
// ----------
//void platform_save_core( platform_core_state_t * core_state );
//void platform_load_core( const platform_core_state_t * core_state );
void platform_clean_core(void); // arch state only
void platform_purge_core (void); // uarch state only

// Platform control and utilities
// ------------------------------
#define platform_get_core_id() read_csr(mhartid)

#define clean_reg(reg) ({ \
  asm volatile ("li " #reg ", 0"); })

#define write_reg(reg, val) ({ \
  asm volatile ("ld " #reg ", %0" :: "rK"(val)); })

void platform_init (void);
void platform_core_init (void);

#define platform_get_device_tree_addr() ((uintptr_t) (((uint64_t) UNTRUSTED_ENTRY) + ((uint64_t) PAYLOAD_MAXLEN)))
void platform_filter_and_copy_device_tree(void);

void platform_interrupt_other_cores (void);
void platform_wait_for_interrupt (void);

void platform_delegate_to_untrusted ( uint64_t virtual_pc, uint64_t  ) __attribute__((noreturn));
void platform_jump_to_untrusted ( uint64_t virtual_pc, uint64_t virtual_sp, uint64_t core_id, uintptr_t dt_addr) __attribute__((noreturn));

void platform_initialize_memory_protection(sm_state_t *sm);

void platform_set_enclave_page_table(enclave_metadata_t *enclave_metadata);
void platfrom_restore_untrusted_page_table(enclave_metadata_t *enclave_metadata);

void platform_protect_enclave_sm_handler(enclave_metadata_t *enclave_metadata, uintptr_t phys_addr);

void platform_update_untrusted_regions(sm_state_t* sm, uint64_t index_id, bool flag);
void platform_update_enclave_regions(enclave_metadata_t *enclave_metadata, uint64_t index_id, bool flag);

void platform_hack_enclave_memory_protection(void); // TODO get rid of this
void platform_hack_exit_enclave_memory_protection(void);

void platform_memory_protection_enter_enclave(enclave_metadata_t *enclave_metadata);
void platform_memory_protection_exit_enclave(enclave_metadata_t *enclave_metadata);

void platform_panic(void) __attribute__((noreturn));

// Platform helpers

uint64_t regions_to_bitmap(region_map_t *regions);

#endif // SM_PLATFORM_H

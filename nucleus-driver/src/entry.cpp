#include <ntddk.h>
#include "data_types.h"
#include "nucleus/impl/assembly.h"


typedef struct {
	void*	StartAddress;
	u32		loader_process_id;
	Winver	winver;
}custom_entry;



NTSTATUS driver_entry(custom_entry* info) {
	if (!info || !info->StartAddress || !info->loader_process_id || !!info->winver) return STATUS_FAILED_DRIVER_ENTRY;
	
	u64 pointer1 = 827123;
	u64 pointer2 = 827122;

	nucleus::masm::interlocked_exchange_pointer((void**)pointer1, (void*)pointer2);

	return STATUS_SUCCESS;
}
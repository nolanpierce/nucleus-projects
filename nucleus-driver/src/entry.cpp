#include <ntddk.h>
#include "data_types.h"
#include "nucleus/impl/assembly.h"
#include "nucleus/eac/eac.h"

typedef struct {
	void*	StartAddress;
	u32		loader_process_id;
	Winver	winver;
}custom_entry;


// Entry Point
NTSTATUS driver_entry(custom_entry* info) {
	if (!info || !info->StartAddress || !info->loader_process_id || !!info->winver) return STATUS_FAILED_DRIVER_ENTRY;
	
	
	nucleus::easyanticheat::initialize();

	//do our comms thread then we restore
	// 
	// 
	// 
	//restore after
	nucleus::easyanticheat::cleanup();
	return STATUS_SUCCESS;
}
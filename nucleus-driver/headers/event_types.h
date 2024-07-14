#pragma on
#include "data_types.h"

typedef enum : u32 {
	connected,
	waiting_for_host,
	waiting_for_kernel,
	terminate,
	disconnect,
}event_status;

typedef enum : u32 {
	event_failed,
	event_success,
	event_params_invalid,
	event_buffer_empty,
}event_response;

typedef enum : u32 {
	read,
	write,
	block_module_handle,
	block_module_peb,
	block_module_dtb,
	query_mem,
	allocate_mem,
	protect_mem,
	free_mem,
	apc_inject,
	mod_map_inject,
	secret_key = 0x420
}event_codes;

typedef enum : u32 {
	physical_mem,
	virtual_mem
}memory_operation_type;

typedef struct  _read_event{
	u32						host_pid;
	memory_operation_type	type_of_mem; //physical or virtual
	void*					buffer;
	u64						address;
	u32						target_pid;
}read_event, *pread_event;

typedef struct _event_data {
	void*					buffer;
	size_t					size;
	event_response			msg;
}event_data, * pevent_data;

typedef struct _event_packet {
	u32						host_pid;
	u64						host_eproc;
	event_data				data;
	size_t					size;
	event_codes				type;
	event_status			status;
}event_packet, * pevent_packet;

//if we cant map the driver and pass this info in the entry point params we use file
typedef struct _event_setup_file {
	u32						loader_pid;
	Winver					winver;
	void*					buffer_va;
	size_t					size_va;
	event_codes				secret_key;
}event_setup_file, *pevent_setup_file;


#pragma once
#include <ntddk.h>
#include "data_types.h"
#include "event_types.h"
#include "nucleus/impl/crt/crt.h"

typedef struct Kernel {
	unsigned long long u;
};

namespace nucleus {


	namespace communication {
		extern NTSTATUS dispatch_event(event_packet* packet);
		extern NTSTATUS fetch_setup_file(event_setup_file* file);
	}

	namespace setup {
		extern NTSTATUS communication(Kernel* kernel);
	}

}
#pragma once
#include <ntddk.h>
#include "data_types.h"
#include "event_types.h"

namespace nucleus {
	namespace filesystem {
		NTSTATUS fetch_nucleus_setup_file(event_setup_file* buffer);
	}
}
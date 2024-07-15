#pragma once
#include <ntddk.h>
#include "data_types.h"
#include "event_types.h"

namespace nucleus {
	namespace filesystem {
		NTSTATUS retreive_file(PCWSTR file_path, void* buffer);
	}
}
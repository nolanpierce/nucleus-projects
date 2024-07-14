#pragma once
#include <ntddk.h>
#include "data_types.h"
#include "nucleus/impl/crt/crt.h"
#include "nmi_bypass.h"

namespace nucleus {
	namespace easyanticheat {
		extern NTSTATUS initialize();
		extern void cleanup();

	}
}
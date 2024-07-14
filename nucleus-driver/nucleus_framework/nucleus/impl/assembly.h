#pragma once


namespace nucleus {
	namespace masm {
		extern "C" {
			void* interlocked_exchange_pointer(void** target, void* value);
		}
	}
}



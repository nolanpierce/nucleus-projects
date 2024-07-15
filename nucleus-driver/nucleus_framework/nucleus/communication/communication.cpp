#include "communication.h"


namespace nucleus {


	namespace communication {
		NTSTATUS dispatch_event(event_packet* packet)
		{
			if(!packet) return STATUS_INVALID_PARAMETER;

			NTSTATUS status{ 0 };
			event_packet _event{ 0 };

			if (!crt::memcpy(&_event, &packet, sizeof(event_packet))) return STATUS_UNSUCCESSFUL;

			switch (_event.type) {
				case read: {
					
					if (!_event.host_pid || !_event.data.buffer || _event.data.size == 0) {
						status = STATUS_UNSUCCESSFUL;
						_event.data.msg = event_failed;
						break;
					}

					//lookuptheprocess by its id
					//if()

					read_event rpm{ 0 };
					if (!crt::memcpy(&rpm, &_event.data.buffer, sizeof(_event.data.buffer))){
						status = STATUS_UNSUCCESSFUL;
						_event.data.msg = event_failed;
						break;
					}
					
					switch (rpm.type_of_mem) {
						case physical_mem: {
							//here we will be doing the operations for the 
							break;
						}

						case virtual_mem: {

							break;
						}

					default: {
						status = STATUS_UNSUCCESSFUL;
						_event.data.msg = event_failed;
						break;
					}
					}


					break;
				}
			}

			return status;
		}
		

		// havent decided if i am going to map the setup info with the driver or not
		//if not fetch it from our file
		NTSTATUS fetch_setup_file(event_setup_file* file)
		{
			return STATUS_SUCCESS;
		}
	}

	//need to do
	namespace setup {
		
		NTSTATUS communication(Kernel* kernel) {

			return NTSTATUS();
		}
	}

}
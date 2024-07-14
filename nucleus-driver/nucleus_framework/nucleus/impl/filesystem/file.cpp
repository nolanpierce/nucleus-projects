#include "file.h"

namespace nucleus {
	namespace filesystem {
		
		NTSTATUS retreive_file(PCWSTR file_path, void* buffer) {
			if (!file_path) return STATUS_INVALID_PARAMETER;

			UNICODE_STRING		file_path_unicode{};
			OBJECT_ATTRIBUTES	obj_attributes{};
			HANDLE				handle{};
			IO_STATUS_BLOCK		io_status_block{};
			KEVENT				k_event{};

			KeInitializeEvent(&k_event, NotificationEvent, FALSE);
			RtlInitUnicodeString(&file_path_unicode, L"\\SystemRoot\\dhuie2gh876t19ikds.smd");
			InitializeObjectAttributes(&obj_attributes, &file_path_unicode, OBJ_CASE_INSENSITIVE | OBJ_KERNEL_HANDLE, NULL, NULL);

			if (KeGetCurrentIrql() != PASSIVE_LEVEL) return STATUS_INVALID_DEVICE_STATE;

			NTSTATUS status = ZwCreateFile(&handle, GENERIC_READ, &obj_attributes, &io_status_block, NULL, FILE_ATTRIBUTE_NORMAL, NULL, FILE_OPEN, FILE_SYNCHRONOUS_IO_NONALERT, NULL, NULL);

			if (!NT_SUCCESS(status)) return STATUS_UNSUCCESSFUL;

			status = ZwReadFile(handle, NULL, NULL, NULL, &io_status_block, &buffer, sizeof(buffer), NULL, NULL);

			ZwClose(handle);
			//ZwDeleteFile(&obj_attributes);

			return STATUS_SUCCESS;
		}

	}
}
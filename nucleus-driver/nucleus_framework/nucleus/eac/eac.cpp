#include "eac.h"


namespace nucleus {
    namespace easyanticheat {
        
        NTSTATUS initialize() {
            if (!NT_SUCCESS(load_custom_idt())) return STATUS_ABANDONED; //failed to setup idt and nmi bypass
            //need to maybe add driver start address spoofing all the 9 yards

            return STATUS_SUCCESS;
        }

        void cleanup() {
            restore_idt();// going to add more here
            return;
        }
    }
}




#include "nmi_bypass.h"

static IDT_ENTRY* constructed_idt_table = nullptr;
static IDT_DESCRIPTOR constructed_idt_ptr;
static IDT_DESCRIPTOR original_idt_descriptor;
static bool _idt_loaded = false;

// Function to load the IDT
extern "C"  void load_idt(IDT_DESCRIPTOR* idtDescriptor) {
    __lidt(idtDescriptor);
}

static void  iretq_nmi_handler() {
    return;
}

IDT_ENTRY create_interupt_gate(void (*handler)()) {
    IDT_ENTRY entry = { 0 };
    ULONG_PTR handlerAddress = (ULONG_PTR)handler;

    entry.OffsetLow = (USHORT)(handlerAddress & 0xFFFF);
    entry.Selector = 0x08; // Kernel code segment
    entry.IstIndex = 0;
    entry.TypesAttr = 0x8E; // Interrupt gate
    entry.OffsetMiddle = (USHORT)((handlerAddress >> 16) & 0xFFFF);
    entry.OffsetHigh = (ULONG)((handlerAddress >> 32) & 0xFFFFFFFF);

    return entry;
}


//swapping the idt table to our custome one so we can swap the eac nmi handler with ireqt
NTSTATUS init_interrupts() {
    PHYSICAL_ADDRESS maxAddr = { 0 };
    maxAddr.QuadPart = MAXULONG64;

    constructed_idt_table = (IDT_ENTRY*)ExAllocatePoolWithTag(NonPagedPool, sizeof(IDT_ENTRY) * IDT_SIZE, POOLTAG_NUKE);
    if (!constructed_idt_table) return STATUS_INSUFFICIENT_RESOURCES;

    nucleus::crt::memset(constructed_idt_table, 0, sizeof(IDT_ENTRY) * IDT_SIZE);

    constructed_idt_table[NMI_VECTOR] = create_interupt_gate(iretq_nmi_handler);

    constructed_idt_ptr.Base = (ULONG64)constructed_idt_table;
    constructed_idt_ptr.Limit = (sizeof(IDT_ENTRY) * IDT_SIZE) - 1;

    _idt_loaded = true;
    return STATUS_SUCCESS;
}

namespace nucleus {
    namespace easyanticheat {
        
        NTSTATUS load_custom_idt() {
            if (!_idt_loaded) {
                __sidt(&original_idt_descriptor); //load the current idt

                // Set up the new IDT with our custom NMI handler
                if (NT_SUCCESS(init_interrupts())) {
                    load_idt(&constructed_idt_ptr);
                }

                return STATUS_SUCCESS;
            }
            return STATUS_UNSUCCESSFUL;
        }

        void restore_idt() {
            if (_idt_loaded) {
                load_idt(&original_idt_descriptor);
                ExFreePoolWithTag(constructed_idt_table, POOLTAG_NUKE);
                _idt_loaded = false;
            }

            return;
        }
    }
}



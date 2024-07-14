#pragma once
#include <ntddk.h>
#include <intrin.h>
#include "data_types.h"
#include "nucleus/impl/crt/crt.h"
// DEFINITIONS FOR OWN NMI

typedef struct _IDT_ENTRY {
    USHORT OffsetLow;
    USHORT Selector;
    UCHAR IstIndex;
    UCHAR TypesAttr;
    USHORT OffsetMiddle;
    ULONG OffsetHigh;
    ULONG Reserved;
} IDT_ENTRY, * PIDT_ENTRY;

typedef struct _IDT_DESCRIPTOR {
    USHORT Limit;
    ULONG64 Base;
} IDT_DESCRIPTOR, * PIDT_DESCRIPTOR;

#define NMI_VECTOR 2
#define IDT_SIZE 256


namespace nucleus {
    namespace easyanticheat {
        extern NTSTATUS load_custom_idt();
        extern void restore_idt();
    }
}



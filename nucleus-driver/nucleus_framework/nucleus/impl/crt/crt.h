#pragma once

#include "data_types.h"

namespace nucleus {
    namespace crt {

        // Memory Copy
        extern void* memcpy(void* dest, const void* src, size_t n);

        // Memory Set
        extern void* memset(void* s, int c, size_t n);

        // String Copy
        extern char* strcpy(char* dest, const char* src);

        // Wide String Copy
        extern wchar_t* wcscpy(wchar_t* dest, const wchar_t* src);

        // String Compare
        extern int strcmp(const char* s1, const char* s2);

    }
}



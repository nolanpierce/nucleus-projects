#include "nucleus/impl/crt/crt.h"

namespace nucleus {
    namespace crt {

        void* memcpy(void* dest, const void* src, size_t n)
        {
            u8* d = static_cast<u8*>(dest);
            const u8* s = static_cast<const u8*>(src);
            while (n--) {
                *d++ = *s++;
            }
            return dest;
        }

        void* memset(void* s, int c, size_t n)
        {
            u8* p = static_cast<u8*>(s);
            while (n--) {
                *p++ = static_cast<u8>(c);
            }
            return s;
        }

        char* strcpy(char* dest, const char* src)
        {
            char* d = dest;
            while ((*d++ = *src++));
            return dest;
        }

        wchar_t* wcscpy(wchar_t* dest, const wchar_t* src)
        {
            wchar_t* d = dest;
            while ((*d++ = *src++));
            return dest;
        }

        int strcmp(const char* s1, const char* s2)
        {
            while (*s1 && (*s1 == *s2)) {
                s1++;
                s2++;
            }
            return *(unsigned char*)s1 - *(unsigned char*)s2;
        }

    }
}

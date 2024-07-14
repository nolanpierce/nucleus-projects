.code

; Function definition for InterlockedExchangePointer
; void* interlocked_exchange_pointer(void** target, void* value)
interlocked_exchange_pointer PROC
    ; Load the parameters
    mov rax, rcx        ; rcx contains the address of target
    mov rdx, rdx        ; rdx contains the value to exchange

    ; Perform the atomic exchange
    lock xchg [rax], rdx

    ; Return the old value
    mov rax, rdx
    ret
interlocked_exchange_pointer ENDP

END

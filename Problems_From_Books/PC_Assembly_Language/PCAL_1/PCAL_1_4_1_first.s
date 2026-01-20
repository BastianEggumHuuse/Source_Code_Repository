; An assembly file is separated into segments that have different purposes
; the .data segment is used to store data that we initialize
segment .data

outmsg db "Hello world!", 0 ; Creating 12 bytes containing characters, along with a 0 to cap it off (Like in C)

; The bss segment stores data we don't initialize
segment .bss
; We do nothing in this program :)

; The .text segment is the "text" of the program, all of the actual code.
segment .text

    extern _printf    ; Getting printf from C

    global _asm_main ; Declaring the function we will write as global, so that the compiler can see it

_asm_main:
    enter 0,0         ; Creating stack frame (I don't know what this means yet I think it reserves space on the stack)
    pusha             ; Pushing the values of all general registers to the stack (preservation)

    ; Here comes the actual function haha (most of it is just preservation)
    push outmsg  ; Pushing the message to the machine stack
    call _printf ; Calling the function, which reads the message from the machine stack 
    add esp, 8   ; Restoring the stack.

    popa              ; Popping all general registers back (preservation)
    mov eax, 0        ; C uses eax as the returning adress (C will read eax once this function returns)
                      ; According to the C calling convention, It's up to the calling function to preserve eax,
                      ; which is why we can put another value in it after popping!!! (so cool btw)
    ret               ; Returning
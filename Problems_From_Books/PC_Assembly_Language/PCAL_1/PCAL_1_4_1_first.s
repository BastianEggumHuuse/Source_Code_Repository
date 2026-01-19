; Including some C I/O macros
%include "asm_io.inc"

; An assembly file is separated into segments that have different purposes
; the .data segment is used to store data that we initialize
segment .data

outmsg db "Hello world!" 0 ; Creating 12 bytes containing characters, along with a 0 to cap it off (Like in C)

; The bss segment stores data we don't initialize
segment .bss
; We do nothing in this program :)

; The .text segment is the "text" of the program, all of the actual code.
segment .text

    global _asm_main ; Declaring the function we will write as global, so that the compiler can see it

_asm_main:
    enter 0,0         ; Creating stack frame (I don't know what this means yet I think it reserves space on the stack)
    pusha             ; Pushing the values of all general registers to the stack (preservation)

    ; Here comes the actual function haha (most of it is just preservation)
    mov eax, outmsg   ; Moving the address of outmsg into eax. Note that like in C, outmsg is the adress of the first char in the string
    call print_string ; Calling from C library. This prints from eax (i assume)

    popa              ; Popping all general registers back (preservation)
    mov eax, 0        ; C uses eax as the returning adress (C will read eax once this function returns)
                      ; According to the C calling convention, It's up to the calling function to preserve eax,
                      ; which is why we can put another value in it after popping!!! (so cool btw)
    ret               ; Returning
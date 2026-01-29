; Chapter 2: Basic assembly language


; 2.1: Working with integers

; 2.1.2: Sign extension

; The assembler can only work with number of the same size (byte, word, etc.)
; We must therefore edit the sizes to allow this.
; Decreasing is easy: Simply lop off the irrelevant bits:
mov ax 0010h  ; 16 in hex, represented with a word
mov bl al     ; moving the 16 into bl, now represented as a byte
mov cl ah     ; moving the higher bits of ax, which are all 0
; Note that this can lose data if the value is greater than the size decreased to:
mov ax 0100h  ; 16^2 in hex represented with a word (greater than a byte)
mov bl al     ; Moving the lower bits of ax into bl, losing the entire value (00h is put into bl)

; Increasing is a little more difficult, since signed and unsigned integers work differently:
; Unsigned
mov al 15h    ; 21 in hex, as a byte
mov ah 00h    ; The value stays the same, but we can now use ax
; Signed
mov al FFh    ; -1 in hex (two's complement) as a byte
cbw           ; Extends al into ax (keeping two's complement notation)
; Note that this instruction always acts on ax (as most instructions do)


; 2.2: Control structures

; 2.2.1: Comparisons:
; The cmp instruction allows us to compare two values.
mov al 10h ; 16 in hex
mov bl 10h ; 16 in hex
mov cl 11h ; 17 in hex
mov dl 0Fh ; 15 in hex

; The cmp instruction affects two of the FLAGS bits; The zero bit (ZF) and the carry bit (CF)
; We take the difference between the first and second operand. If they are zero, ZF is 1,
; and if a carry has occured, CF is 1
cmp al bl ; al == bl, ZF = 1, CF = 0
cmp al cl ; al <  cl, ZF = 0, CF = 1 (we have to borrow since cl > al)
cmp al dl ; al >  cl, ZF = 0, CF = 0

; 2.2.2: Branching
; There are two types of branch instruction, unconditional and conditional.
; They both do the same thing, move the instruction pointer to another line of code, but one is conditional

; the jump makes an unconditioonal branch
jmp then
add al 1; Trying to add 1 to al, but it's skipped by the jmp
then:

; There are several variants of jmp:
jz then; Jumps only if ZF is 1
jnz then; Complement of jz
jc then; Jumps only if CF is 1
jnc then; Complement of jc
; Others exist for the other flags.

; There are way easier, shorter instructions to do actual tests, like
je then; Jumps if the previous cmp was between two equal numbers
; Some of these differ between signed and unsigned:
jge then; >= (signed)
jae then; >= (unsigned)
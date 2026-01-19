; This is an assembly comment!!
; We have to do them every line :D

; Chapter 1: Introduction


; 1.2: Computer organization:
; Let's begin with the 8086 CPU, which is what we will emulate eventually.

; 1.2.4: Registers:

; The general purpose registers:
; The 8086 provided 4 16-bit registers: AX, BX, CX, and DX. Each of these
; can be decomposed into 2 8-bit registers. AX becomes AH and AL, where AH
; are the 8 upper (high) bits of AX, and AL the lower. Changing one changes
; the other.
; These registers are used for data movement and arithmetic.

; The index registers:
; There are two 16-bit index registers, SI and DI. These work the same as
; the other 4, but cannot be decomposed, and are often used to store pointers.

; The base pointer and stack pointer:
; We have two registers, BP and SP, that point to data in the machine language stack

; The segment registers:
; 16-bit registers that denote what memory is used for which programs. We have
; CS, DS, SS, ES

; The instruction pointer:
; A register that keeps track of the address of the next instruction for the cpu.

; FLAGS:
; The flags register stores important information about the previous instruction.


; 1.2.5: 32 bit registers:

; Later processors expanded the size of these registers. For backwards compatibility
; The registers AX, BX, and so on still refer to the same 16 bits. If we want the full
; 32 bits, we ask for EAX, EBX, etc. (that's so cool)

; The segment registers are still 16-bit, but there are two new ones: FS and GS


; 1.2.9: Interrupts:

; Interrupt handlers are commands (I think) within the CPU that stop whatever
; the CPU is doing, and makes it do something else for a while. Once this thing
; is done happening, it reverts all registers to their previous state, and 
; business returns to normal. Many I/O services use Interrupts.
; (For example, INT 0x16 is the one that gives us keyboard input!!)



; 1.3: Assembly language:


; 1.3.1: Machine language

; All CPUs use a machine language. This language is comprised exclusively of numbers stored in memory.
; This is pretty much unreadable to humans, so we use the assembler, which compiles to machine language.


; 1.3.2: Assembly language

; Each assembly instruction represents exactly one machine instruction. A common one would be something like this:
ADD EAX,EBX
; This adds the value in EBX to the value in EAX. This new value is stored in EAX (think of EBX being added to EAX)
; ADD is a mnemonic for the addition instruction. I've written all caps here, but caps is irrelevant.
add eax,ebx ; also works :)


; 1.3.3: Instruction operands

; Assembly instructions have varying numbers of operands, but they usually have 0-3. These are fixed for each instruction.
; There are 4 types of operands that can be passed to an instruction:

; Registers: referring directly to a register
; Memory:    referring to data stored in memory
; Immediate: operands that are baked into the instruction
; Implied:   operands you cannot see (the increment instruction contains a 1, for example)


; 1.3.4: Basic Instructions:

; The most basic instruction is MOV. It copies data from one location to another.
MOV EAX, 3   ; Moving 3 into EAX. 3 is here an immediate operand.
MOV EBX, EAX ; Moving the data from EAX into EBX
MOV CX,AX    ; Moving the data from AX into CX (note that two operands must be the same size)
; This final operation might lose some data if the value stored in EAX is greater than 16 bits (because we only copy the lower 16 bits)

; We have some basic arithmatic instructions:
ADD EAX, 5   ; Adding 5 to the value in EAX
ADD EAX, EBX ; Adding the value in EBX to EAX
SUB EBX, 2   ; Subtracting 2 from the value in EBX
; Note that we operate on integers only here, and this is equivalent to += and -=
; We have shorthands for incrementing and decrementing
INC EAX; Adding 1 to EAX
DEC ECX; Subtracting 1 from ECX

; 1.3.5: Directives
; More specifically data directives

; We can reserve space for memory!
L1 db 0; L1 is the label, which we use to refer to this address. db decides how much space to allocate, in this case a byte. Finally, we initialize the value stored in L1 to be 0.
; The different sizes of data we can allocate for are:
LB db 0; one byte
LW dw 0; one "word" (two bytes)
LD dd 0; one "double word" (four bytes)
LQ dq 0; one "quad word" (8 bytes)
LT dt 0; ten bytes (boring)
L2 times 100 db 0; Allocating 100 bytes, all initialized to 0

; When adressing these labels, we can do this in two ways, analogous to C pointers
MOV EAX L1   ; moves the address L1 into EAX
MOV EAX [L1] ; moves the value located at the adress L1 into EAX (think *L1)


; 1.4: Creating a program (finally)

; Much of this subchapter will be written into separate files :)


; 1.4.1: First program

; Se the file PCAL_1_4_1_first.s
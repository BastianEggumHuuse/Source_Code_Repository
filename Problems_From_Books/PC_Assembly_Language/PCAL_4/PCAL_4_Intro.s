; Chapter 4: Subprograms

; A subprogram is the assembly variant of a high level function.
; They allow us to reuse code, and more importantly for our use,
; create functions that can be run in C!

; 4.4 CALL and RET

; We enter a subprogram by using the CALL instruction. This 
; 1) Moves the instruction pointer to the beginning of the subprogram,
; 2) pushes the adress of the instruction right after CALL to the stack.
; The RET instruction is put at the end of the subprogram, and pops
; the adress back off the stack, and moves to it. This is why 
; managing the stack is so important!!!

call function ; Calling the function
; Once function is finished executing, we return here

push ax       ; Pushing ax to the stack 
call printf   ; printing ax. (assume we have this)

function:

    mov ax 10
    add ax 5

    ret

; 4.5 Calling conventions

; C has certain calling conventions, that make sure that our functions run safe


; 4.5.1 Passing parameters

; Parameters are passed by pushing them to the stack before running CALL.
; This means they are located under the adress on the stack, meaning we can't pop them off.
; Since we probably want to use them multiple times anyway, this is unnneccesary.
; Instead we get them at their adress!!

function_2:
    ; Assume that this function has one parameter

    ; The stack pointer ESP gives us the point of the stack.
    ; The current point is of course the adress of the instruction we return to
    ; We want the element "under" it.

    ; Note that the machine stack is "upside down", meaning that adding to the pointer moves us down the stack.
    ; Here we move the first parameter (which is 4 spots lower on the stack) into eax. Note that we want the value, not the adress, which is what's on the stack (usually)
    mov eax [esp + 4]

    ; Why add exactly 4? every byte in memory is stored using one number. If we add 1,
    ; We would move to the next (or rather previous) byte, but we are working with 32-bit (4 byte) values.
    ; Therefore we add 4 instead.

    ; If we now push something else onto the stack, we get an issue. the number of adresses we have to offset to find our parameter has changed!
    ; There's a quite elegant solution. We have an entire register to keep track of the "base" of the current stack!

    ; The C calling convention requires us to restore the value of esp before returning from this subprogram
    ; Other functions that call this function might be using it after all!
    push ebp ; Pushing the "base stack pointer" to the stack
    mov ebp esp; Moving the current stack pointer into the base stack pointer
    mov eax [ebp + 8] ; Now we can get values from the stack!! (note that since we push ebp to the stack, the first parameter is now at ebp+8)

    ; Long function goes here

    pop ebp ; Popping the original ebp value back.

    ; The first part of the program where we establish the base stack pointer is called the prologue of the subprogram, 
    ; and the part where we restore ebp is the epilogue of the subprogram

    ; The C calling convention gives the calling function the responsibility of removing the parameters from the stack.
    ; This means we don't have to do it here!!

    ; Since we popped ebp off the stack, the current stack pointer now points to our return adress.
    ret

; Note that we don't have to send the value anywhere to clear the stack
add esp 4; Removing a parameter from the stack (Technically it's still there, but it will be overwritten)


; 4.5.2: Local variables on the stack

; We use the stack for local variables. This is very nice, since it allows us to save memory,
; and recurse, since we don't have to specify registers or memory adresses (We won't use the same space multiple times)
; For everything to work correctly, we don't actually push to the stack. Instead we allocate some stack space,
; and access it via ebp:

function_3:

    ; Prologue
    push ebp
    mov ebp esp
    sub esp 4 ; Allocating 4 bytes of space

    ; esp is now at ebp - 4. This adress is free for the taking:
    mov [ebp - 4] 10 ; Storing a local variable
    ; If we wanted more, we would have simply subtracted more. We shouldn't do so in practise,
    ; but it can in theory be done here:

    sub esp 8 ; Allocating 8 more bytes.
    mov [ebp - 8] 5  ; Accessing these adresses
    mov [ebp - 12] 3 ; Accessing these adresses

    ; Epilogue
    add esp 12 ; Deallocating our stack frame
    pop ebp    ; Restoring the base stack pointer
    ret        ; Returning

; To show how this works in detail, here is a subprogram that produces the sum of two unsigned integers:
func_add:

    ; defining our stack base
    push ebp
    mov ebp esp
    ; Allocating memory for sum
    sub esp 4

    ; We have two parameters
    mov [ebp - 4] [ebp + 8]  ; Collecting our first variable (They're always sent as pointers) into our local variable
    add [ebp - 4] [ebp + 12] ; Adding our second parameter to our local variable

    ; Prepping return (C reads eax for return)
    mov eax [ebp - 4]

    ; Deallocating local stack memory
    add esp 4
    ; Restoring ebp
    pop ebp
    ; Returning
    ret
    
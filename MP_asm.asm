section .data
    scalar_255 dq 255.0        ; Define the constant 255.0 in memory
    scalar_0_5 dq 0.5          ; Define the constant 0.5 in memory

section .text
global imgCvtGrayDoubleToInt
imgCvtGrayDoubleToInt:
    ; rcx = input array (double*)
    ; rdx = output array (int*)
    ; r8  = width
    ; r9  = height

    ; Save registers
    push rbx
    push rdi
    push rsi

    mov rdi, r9        ; rdi = height
    imul rdi, r8       ; rdi = width * height (total number of pixels)
    xor rsi, rsi       ; rsi = index = 0

    movsd xmm1, [scalar_255]    ; Load 255.0 into xmm1
    movsd xmm2, [scalar_0_5]    ; Load 0.5 into xmm2

L1:            
    cmp rsi, rdi               ; If index == total_pixels, exit loop
    jge exit

    ; Load double value into xmm0
    movsd xmm0, [rcx + rsi * 8]

    ; Multiply by 255.0 (convert to integer range)
    mulsd xmm0, xmm1

    ; Get the integer part in xmm3
    roundsd xmm3, xmm0, 1       ; Round down (truncate to integer part)

    ; Compute fractional part
    subsd xmm0, xmm3            ; xmm0 = original - integer part

    ; Compare fractional part to 0.5
    ucomisd xmm0, xmm2
    jb round_down       ; If fractional part < 0.5, round down

    ; Round up
    mov eax, 1                  ; eax = 1 (add 1 to the integer part)
    cvttsd2si ebx, xmm3         ; Convert truncated integer to int
    add eax, ebx                ; eax = truncated integer + 1
    jmp round_up

round_down:         
    ; Store rounded down result
    cvttsd2si eax, xmm3         ; Convert truncated integer to int

round_up:             
    ; Store result
    mov [rdx + rsi * 4], eax

    ; Increment index
    inc rsi
    jmp L1         ; Jump back to the start of the loop

exit:          
    ; Restore registers
    pop rsi
    pop rdi
    pop rbx
    ret

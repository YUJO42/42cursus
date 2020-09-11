section .text
    extern ___error
    global _ft_write

_ft_write :
        mov rax, 0x2000004
        syscall
        jc error
        ret

error :
        mov rbx, rax
        push rdi
        push rsi
        push rdx
        call ___error
        pop rdx
        pop rsi
        pop rdi
        mov [rax], rbx
        mov rax, -1
        ret
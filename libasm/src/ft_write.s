section .text
    extern ___error
    global _ft_write

_ft_write:
        mov rax, 0x2000004
        syscall
        jc error
        ret

error:
        push rax
        call ___error
        pop rbx
        mov [rax], rbx
        mov rax, -1
        ret
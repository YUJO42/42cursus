section .text
    global _ft_read
    extern ___error

_ft_read:
    mov rax, 0x2000003
    syscall
    cmp rax, 0
    jl error
    ret

error:
    push rax
    call ___error
    pop rbx
    mov [rax], rbx
    mov rax, -1
    ret
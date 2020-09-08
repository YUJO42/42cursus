section .text
extern __error
global _ft_write

_ft_write:
    mov rax. 0x2000004
    syscall
    jc error
    ret

error:
    push rax
    call __error
    pop qword [rax]
    mov rax, -1
    ret
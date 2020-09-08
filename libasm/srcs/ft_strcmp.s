section .text
global _ft_strcmp

_ft_strcmp:
    xor rbx, rbx
    xor rcx, rcx
    xor rdx, rdx
    start_loop:
        mov bl, byte[rdi + rdx]
        mov cl, byte[rsi + rdx]
        cmp bl, cl
        jne end_loop
        cmp bl, 0
        je end_loop
        cmp cl, 0
        je end_loop
        inc rdx
        jmp start_loop
    end_loop:
        sub rbx, rcx
        mov rax, rbx
        ret
section .text
    global _ft_strlen

_ft_strlen:
        mov rax, 0
repeat:
        cmp BYTE[rdi + rax], 0
        jne increase
        ret
increase:
        inc rax
        jmp repeat
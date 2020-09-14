section .text
    global _ft_strlen

_ft_strlen:
        mov rax, 0
        cmp rdi, 0
        je done
        jmp repeat

repeat:
        cmp BYTE[rdi + rax], 0
        jne increase

increase:
        inc rax

done:
        ret
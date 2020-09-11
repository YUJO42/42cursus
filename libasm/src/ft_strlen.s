section .text
    extern increase
    extern repeat
    extern done
    global _ft_strlen

_ft_strlen :
        mov rax, 0
        cmp rdi, 0
        je done
        jmp repeat

increase :
        inc rax

repeat :
        cmp BYTE[rdi + rax], 0
        jne increase

done :
        ret
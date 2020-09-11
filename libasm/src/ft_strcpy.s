section .text
    global _ft_strcpy

_ft_strcpy :
        mov rbx, 0
        cmp rsi, 0
        je  done
        jmp repeat

increase :
        inc rbx

repeat :
        mov dl, BYTE[rsi + rbx]
        mov BYTE[rdi + rbx], dl
        cmp dl, 0
        je  done
        jmp increase

done :
        mov rax, rdi
        ret
    
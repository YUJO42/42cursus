section .text
    global _ft_strcmp

_ft_strcmp :
                mov rbx, 0
                cmp rsi, 0
                je  do_null
                cmp rdi, 0
                je  do_null
                jmp repeat
do_null :
                cmp rdi, rsi
                jg  sup
                je  eq
                jmp inf
compare1 :
                cmp BYTE[rsi + rbx], 0
                je done
compare2 :
                cmp BYTE[rdi + rbx], 0
                je done
increase : 
                inc rbx

repeat :
                mov dl, BYTE[rdi + rbx]
                mov cl, BYTE[rsi + rbx]
                cmp dl, cl
                je compare1

done :
                movzx rdx, dl
                movzx rcx, cl
                sub rdx, rcx
                mov rax, rdx
                ret

sup :
        mov rax, 1
        ret
inf :
        mov rax, -1
        ret
eq  :
        mov rax, 0
        ret
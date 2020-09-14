section .text
    global _ft_strcmp

_ft_strcmp:
        mov rax, 0
	    mov rbx, 0
	    mov rcx, 0

continue:
	    mov cl, byte[rsi+rax]
        mov bl, byte[rdi+rax]
        cmp cl, 0
        je break
        inc rax
        cmp bl, cl
        je continue

break:
        sub rbx, rcx
        mov rax, rbx
        ret
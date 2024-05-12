    global ft_strlen

    section .text
;; size_t strlen(const char *s);
;; Calculate the lenght of s
;; Return the number of bytes in s
;; rdi = s

ft_strlen:
    mov rax, 0
loop:
    cmp byte [rdi+rax], 0
    je return
    inc rax
    jmp loop
return:
    ret

    global ft_strcpy
    
    section .text
;; char *ft_strcpy(char *dest, const char *src);
;; Copies the string pointed to by src to the buffer pointed to by dest
;; Return dest
;; rdi = dest
;; rsi = src

ft_strcpy:
    mov rdx, rdi ;; Save dst value to return it later
loop: 
    lodsb ;; Load one byte from rsi into al (current source character) and increment rsi
    stosb ;; Load one byte from al into rdi and increment rdi
    cmp al, 0
    jne loop
    mov rax, rdx
    ret

    extern malloc
    extern ft_strlen
    extern ft_strcpy

    global ft_strdup
    
    section .text
;; char *ft_strdup(const char *s);
;; Returns a pointer to a new string which is a duplicate of the string s
;; rdi = s

ft_strdup:
    push rdi ;; Save s value in the stack
    call ft_strlen
    mov rdi, rax
    inc rdi ;; Include null character
    call malloc
    cmp rax, 0 ;; check malloc errors
    je return
    mov rdi, rax ;; Set args for ft_strcpy call
    pop rsi
    call ft_strcpy
return:
    ret

    global ft_strcmp

    section .text
;; int strcmp(const char *s1, const char *s2);
;; ompares the two strings s1 and s2
;; Return 0 if are equal, negative value if s1 is less than s2, positive value if s2 is less than s1
;; rdi = s1
;; rsi = s2

ft_strcmp:
    cld ;; set direction flag to 0
loop:
    cmp byte [rdi], 0
    je return
    cmpsb
    je loop

    ;; If loops end because cmpsb set ZF to false, dec both strings pointers
    dec rdi
    dec rsi
return:
    ;; Calculate difference between the first non-equal characters
    movzx eax, byte [rdi]
    movzx esi, byte [rsi] 
    sub eax, esi 
    ret

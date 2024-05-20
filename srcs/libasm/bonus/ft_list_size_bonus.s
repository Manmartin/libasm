    global ft_list_size

    section .text

%define begin_list rdi

;; int ft_list_size(t_list *begin_list);
ft_list_size:
    xor eax, eax
loop:
    cmp begin_list, 0
    je end
    inc eax
    mov begin_list, [begin_list+8]
    jmp loop

end:
    ret
    global ft_list_push_front
    extern malloc
    section .text

%define begin_list rdi
%define data rsi

%macro create_node 0
    push begin_list
    push data
    mov rdi, 16
    call malloc
    pop data
    pop begin_list
%endmacro


;; void   ft_list_push_front(t_list **begin_list, void *data);
ft_list_push_front:
    create_node ;; Reserve node in memory
    cmp rax, 0 ;; If malloc return null, end function
    je end

    mov [rax], data ;; Move data into new node
    mov rdx, [begin_list]
    mov [rax+8], rdx ;; Move pointer fo first node into new_node next param
    mov [begin_list], rax

end:
    ret

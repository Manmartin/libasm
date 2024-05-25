    global ft_list_remove_if
    extern free

    section .text
;; Utility macros
%macro prologue 1
    push rbp
    mov rbp, rsp
    sub rsp, %1
%endmacro

%macro epilogue 0
    mov rsp, rbp
    pop rbp
%endmacro

%define NULL 0


;; t_list fields
%define data 0
%define next 8

;; ft_list_remove_if local variables
%define begin_list -0x8
%define data_ref -0x10
%define comp -0x18
%define free_fct -0x20
%define aux_list -0x28
%define current_node rbx


;; Aux macro
%macro insert_node 0
        cmp qword [rbp+aux_list], NULL
        jne skip_init_list
        mov qword [current_node+next], NULL
        mov [rbp+aux_list], current_node
        jmp insert_node_end

    skip_init_list:
        mov rdi, [rbp+aux_list]
        mov rsi, [rdi+next]

    insert_node_loop:
        cmp rsi, NULL
        jne skip_insert_node
        mov qword [current_node+next], NULL
        mov [rdi+next], current_node
        jmp insert_node_end
    skip_insert_node:
        mov rdi, rsi
        mov rsi, [rdi+next]
        jmp insert_node_loop
insert_node_end:
%endmacro

;; void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
;; removes from the list, all elements whose data compared to data_ref using cmp, makes cmp return 0.
;; The data from an element to be erased should be freed using free_fct
ft_list_remove_if:
        ;; Save rbx in stack
        push rbx
        ;; Save local variables into stack
        prologue 0x28
        mov [rbp+begin_list], rdi
        mov [rbp+data_ref], rsi
        mov [rbp+comp], rdx
        mov [rbp+free_fct], rcx
        mov qword [rbp+aux_list], NULL
        mov current_node, [rdi]

    loop:
        ;; If current node is null, end loop
        cmp current_node, NULL
        je end

        ;; Compare data_ref with current node with comp function
        mov rdi, [current_node+data]
        mov rsi, [rbp+data_ref]
        call [rbp+comp]

        ;; If function return 0, free current node
        cmp eax, 0
        je free_node
        mov rdx, [current_node+next]
        insert_node
        mov current_node, rdx
        jmp loop
    free_node:
        mov rdi, [current_node+data]
        call [rbp+free_fct]
        mov rdi, current_node
        mov current_node, [current_node+next]
        call free
        jmp loop

    end:
        ;; Move aux list into original list
        mov rdi, [rbp+aux_list]
        mov rsi, [rbp+begin_list]
        mov [rsi], rdi
        epilogue
        ;; Restore rbx value
        pop rbx
        ret

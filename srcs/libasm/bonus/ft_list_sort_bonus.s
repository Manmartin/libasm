    global ft_list_sort

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

;; ft_list_sort local variables
%define begin_list -8
%define comp -16
%define aux_list -24
%define current_node -32
%define next_node -40

;; insert_node local variables
%define list -8
%define comp -16
%define new_node -24
%define last_node -32
%define next_node -40


;; void insert_node(t_list **list, int (*cmp)(), t_list *new_node);
insert_node:
        prologue 40             ;; reserve space for local variables
        mov [rbp+list], rdi     ;; t_list **list
        mov [rbp+comp], rsi     ;; int (*cmp)()
        mov [rbp+new_node], rdx ;; t_list *new_node
                                
        ;; If list is empty, set new_node->next to NULL and save it
        cmp qword [rdi], NULL
        jne skip_start_list
        mov qword [rdx+next], NULL
        mov [rdi], rdx
        jmp insert_node_end
    skip_start_list:

        ;; save current node pointed by list
        mov rcx, [rbp+list]
        mov rcx, [rcx]
        mov [rbp+last_node], rcx

        ;; compare first element's content with new node's content
        mov rdi, [rdi]
        mov rdi, [rdi+data]
        mov rsi, [rdx+data]
        call [rbp+comp]
        
        cmp eax, 0
        jle skip_insert_first_element

        ;; Insert new_node at the start of the list
        mov rdi, [rbp+new_node]
        mov rsi, [rbp+last_node]
        mov [rdi+next], rsi
        mov rsi, [rbp+list]
        mov [rsi], rdi
        jmp insert_node_end
    skip_insert_first_element:
        
    insert_node_loop:
        ;; If next_node is null, insert node at end of list
        mov rdi, [rbp+last_node]
        mov rsi, [rdi+next]
        mov [rbp+next_node], rsi

        cmp rsi, NULL
        jne skip_insert_last_element
        
        ;; Insert new_node at the end of the list
        mov rdx, [rbp+new_node]
        mov qword [rdx+next], NULL
        mov [rdi+next], rdx
        jmp insert_node_end
    skip_insert_last_element:
        ;; compare next element's content with new node's content
        mov rdi, [rbp+next_node]
        mov rdi, [rdi+data]
        mov rsi, [rbp+new_node]
        mov rsi, [rsi+data]
        call [rbp+comp]

        cmp eax, 0
        jle skip_insert_after_current_element

        mov rdi, [rbp+last_node]
        mov rsi, [rbp+new_node]
        mov rdx, [rbp+next_node]
        mov [rsi+next], rdx
        mov [rdi+next], rsi
        jmp insert_node_end
    skip_insert_after_current_element:
        mov rdi, [rbp+next_node]
        mov [rbp+last_node], rdi
        jmp insert_node_loop

    insert_node_end:
        epilogue
        ret

;; void ft_list_sort(t_list **begin_list, int (*cmp)());
ft_list_sort:
        prologue 40                     ;; reserve space for local variables
        mov [rbp+begin_list], rdi       ;; t_list **begin_list
        mov [rbp+comp], rsi             ;; int (*cmp)()
        mov qword [rbp+aux_list], NULL  ;; t_list * aux_list
        mov rdi, [rdi]
        mov [rbp+current_node], rdi     ;; current_node
                                        ;; next_node is reserved but not initialiced

    loop:
        ;; If current_node == NULL then end loop
        mov rdx, [rbp+current_node] 
        cmp rdx, NULL
        je end

        ;; save next_node
        mov rdi, [rdx+next]
        mov [rbp+next_node], rdi

        ;; Load args and call insert_node
        ;; new_node is already being stored in rdx
        lea rdi, [rbp+aux_list] ;; t_list **list
        mov rsi, [rbp+comp]      ;; int (*cmp)()
        call insert_node

        ;; move next_node to current node and jump to loop
        mov rdi, [rbp+next_node]
        mov [rbp+current_node], rdi
        jmp loop

    end:
        ;; Move aux_list into *begin_list
        mov rdi, [rbp+aux_list]
        mov rsi, [rbp+begin_list]
        mov [rsi], rdi
        epilogue
        ret

    global ft_atoi_base

    section .text

;; Iterate base string and search for non-valid or repeated characters
;; Also check if base string len is more than 1
%macro validate_base 0
    xor rdx, rdx
validate_base_loop:
    ;; Load current character in rcx registry (cl) and check if is end of string
    lea r8, [rsi+rdx]
    mov cl, [r8]
    cmp cl, 0
    je validate_base_return

    ;; Check if character is '+', '-' or ' '
    cmp cl, '+'
    je error
    cmp cl, '-'
    je error
    cmp cl, ' '
    je error

    ;; Search for repeated character
validate_base_strchr_loop: 
    inc r8
    cmp [r8], cl
    je error
    cmp byte [r8], 0
    jne validate_base_strchr_loop

    ;; Check if character is space (man isspace)
    sub cl, 9 ;; Transform original range ('\t'-'\r' or 9-13) into (0-4)
    cmp cl, 4
    jbe error ;; Unsigned comparison
 
    inc rdx
    jmp validate_base_loop

validate_base_return:
    cmp rdx, 2
    jl error
%endmacro

ft_atoi_base:
    validate_base
    xor rax, rax
    ret

error:
    xor rax, rax
    ret

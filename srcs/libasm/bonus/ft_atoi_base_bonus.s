    global ft_atoi_base

    section .text

%define nstr rdi
%define base rsi

;; Iterate base string and search for non-valid or repeated characters
;; Also check if base string len is more than 1
%macro validate_base 0
    xor rdx, rdx
validate_base_loop:
    ;; Load current character in rcx registry (cl) and check if is '\0'
    lea r8, [base+rdx]
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

;; Remove all spaces (as defined in isspace) in nstr
%macro clean_spaces 0
clean_spaces_loop:
    mov cl, [nstr]
    cmp cl, ' '
    sete r8b
    sub cl, 9
    cmp cl, 4
    setbe cl
    or r8b, cl
    cmp r8b, 0
    je clean_spaces_end
    inc nstr
    jmp clean_spaces_loop
clean_spaces_end:
%endmacro

;; Get sign value (1 or -1)
%macro get_sign 0
    mov ecx, 1
get_sign_loop:
    mov r9b, [nstr]
    cmp r9b, '+'
    sete r8b
    cmp r9b, '-'
    sete r9b
    or r8b, r9b ;; Check if current character is '+' or '-' and store result in cl

    ;; If '-' found, negate sign
    cmp r9b, 0
    je get_sign_if_neg
    neg ecx
get_sign_if_neg:

    cmp r8b, 0 ;; If sign found, increase nstr pointer by one
    je get_sign_end
    inc nstr
    jmp get_sign_loop
get_sign_end:
%endmacro


;; Get numeric value of character stored in r8b and return it in r9
%macro get_char_value 0
    mov r9, base
get_char_value_loop:
    cmp byte [r9], 0
    je get_char_value_end
    cmp r8b, [r9]
    je get_char_value_end
    inc r9
    jmp get_char_value_loop
get_char_value_end:
    sub r9, base
%endmacro

;; int ft_atoi_base(char *nstr, char *base)
ft_atoi_base:
    xor eax, eax ;; Set return value to 0

    validate_base ;; Check if base is valid and set edx to base's len
    clean_spaces ;; remove all spaces at the start of nstr
    get_sign ;; Get sign value and, if found, remove one '+' or '-' from nstr

ft_atoi_base_loop:
    movzx r8d, byte [nstr]

    get_char_value ;; Get value of character in base
    cmp r9d, edx ;; If character is not in base, end function
    je ft_atoi_base_end

    imul eax, edx
    add eax, r9d
    inc nstr
    jmp ft_atoi_base_loop

ft_atoi_base_end:
    imul eax, ecx ;; multiply result by sign
error:
    ret

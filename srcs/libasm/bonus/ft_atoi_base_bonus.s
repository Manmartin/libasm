    global ft_atoi_base

    section .text


%macro validate_base 0

    xor rax, rax
validate_loop:
    cmp byte [rsi+rax], 0
    je validate_return
    inc rax
    jmp validate_loop
validate_return:
    cmp rax, 2
    jl error
%endmacro

ft_atoi_base:
    validate_base

    ret

error:
    xor rax, rax
    ret

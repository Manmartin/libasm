    ;; Aux function from errno.h to obtain errno location
    extern __errno_location
    global ft_read
    
    section .text

;; ssize_t read(int fd, void *buf, size_t count);
;; Read up to count bytes from buf into fd
;; Return the number of bytes read. On error, -1 is returned and errno is set
;; rax = syscall number && return value
;; rdi = fd
;; rsi = buf
;; rdx = count
ft_read:
    mov rax, SYSCALL_READ
    syscall
    mov rdi, rax
    call __errno_location
    cmp rdi, 0
    jl error
    mov qword [rax], 0
    mov rax, rdi
    ret

error:
    ;; If read syscall returns a negative value, errno is set to that value (in positive) and -1 is returned
    ;; rdi is used to store return value of read syscall    
    neg rdi
    mov [rax], rdi
    mov rax, -1
    ret

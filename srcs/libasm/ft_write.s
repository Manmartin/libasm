    ;; Aux function from errno.h to obtain errno location
    extern __errno_location
    global ft_write

    section .text
;; ssize_t ft_write(int fd, const void *buf, size_t count)
;; Write up to count bytes from buf into fd
;; Return the number of bytes written. On error, -1 is returned and errno is set
;; rax = syscall number && return value
;; rdi = fd
;; rsi = buf
;; rdx = count
ft_write:
    mov rax, SYSCALL_WRITE
    syscall
    cmp rax, 0
    jge return
    ;; If write syscall returns a negative value, errno is set to that value and -1 is returned
    ;; rdi is used to store return value of write syscall
    mov rdi, rax
    neg rdi
    call __errno_location
    mov [rax], rdi
    mov rax, -1
return:
    ret

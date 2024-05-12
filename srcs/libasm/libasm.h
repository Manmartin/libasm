#ifndef LIBASM_H
# define LIBASM_H

# include <errno.h> // Used inside ft_write and ft_read
# include <sys/types.h>

ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
size_t  ft_strlen(const char *s);

#endif

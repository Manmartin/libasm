#ifndef LIBASM_H
# define LIBASM_H

# include <errno.h> // Used inside ft_write and ft_read
# include <sys/types.h>

ssize_t ft_write(int fd, const void *buf, size_t count);


#endif

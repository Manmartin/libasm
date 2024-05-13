#ifndef TESTS_H
# define TESTS_H

# include <sys/types.h>

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"

# ifndef test_path
#  define test_path "./srcs/tests/logs"
# endif

// Aux functions
void put_str(int fd, const char *s);

// Tests
void test_strlen(const char *function_name, size_t local_strlen(const char *s));
void test_strcpy(const char *function_name, char* local_strcpy(char *dest, const char *src));
void test_write(const char *function_name, ssize_t local_write(int, const void *, size_t));
void test_read(const char *function_name, ssize_t local_read(int fd, void *buf, size_t count));

#endif

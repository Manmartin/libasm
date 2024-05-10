#ifndef TESTS_H
# define TESTS_H

# include <sys/types.h>

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"

void test_write(const char *function_name, ssize_t local_write(int, const void *, size_t));


#endif

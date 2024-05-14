#ifndef TESTS_BONUS_H
# define TESTS_BONUS_H

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"

// Aux functions
void put_str(int fd, const char *s);

// Tests
void test_atoi_base(void);

#endif

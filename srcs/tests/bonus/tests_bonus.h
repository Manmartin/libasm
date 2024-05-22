#ifndef TESTS_BONUS_H
# define TESTS_BONUS_H

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"

# include <libasm_bonus.h>

// Aux functions
void put_str(int fd, const char *s);
void free_list(t_list *list);

// Tests
void test_atoi_base(void);
void test_list_push_front(void);
void test_list_size(void);
void test_list_sort(void);

#endif

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <libasm.h>
#include "tests_bonus.h"

int main(void)
{
    puts(YELLOW"-----  BONUS PART  -----\n"RESET);
    // FT_ATOI_BASE TEST
    puts(BLUE"TEST: ft_atoi_base" RESET);
    test_atoi_base();
    puts("");

    // FT_LIST_PUSH_FRONT TEST
    puts(BLUE"TEST: ft_list_push_front" RESET);
    test_list_push_front();
    puts("");

    // FT_LIST_SIZE
    puts(BLUE"TEST: ft_list_size" RESET);
    test_list_size();
    puts("");

    // FT_LIST_SORT
    puts(BLUE"TEST: ft_list_sort" RESET);
    test_list_sort();
    puts("");

}

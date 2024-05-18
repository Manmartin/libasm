#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <libasm_bonus.h>
#include "tests_bonus.h"

int main(void)
{
    puts(YELLOW"-----  BONUS PART  -----\n"RESET);
    // FT_ATOI_BASE TEST
    puts(BLUE"TEST: ft_atoi_base" RESET);
    test_atoi_base();
    puts("");
}

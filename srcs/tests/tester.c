#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#include <libasm.h>
#include "tests.h"

int main(void)
{
    // FT_STRLEN TEST
    puts(BLUE"TEST: ft_strlen"RESET);
    test_strlen("strlen", strlen);
    test_strlen("ft_strlen", ft_strlen);
    puts("");

    // FT_WRITE TEST
    puts(BLUE"TEST: ft_write"RESET);
    test_write("write", write);
    test_write("ft_write", ft_write);
    puts("");

    // FT_READ TEST
    puts(BLUE"TEST: ft_read"RESET);
    test_read("read", read);
    test_read("ft_read", ft_read);
    puts("");

    return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#include <libasm.h>
#include "tests.h"

int main(void)
{
    // FT_WRITE TEST
    puts(BLUE"TEST: ft_write"RESET);
    test_write("write", write);
    test_write("ft_write", ft_write);

    return 0;
}

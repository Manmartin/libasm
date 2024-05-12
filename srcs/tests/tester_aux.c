#include <unistd.h>
#include "tests.h"

void put_str(int fd, const char *s)
{
    while (*s)
        write(fd, s++, 1);
}

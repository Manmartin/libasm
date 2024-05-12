#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <fcntl.h>
#include <unistd.h>
#include "tests.h"

void test_read(const char *function_name, ssize_t local_read(int fd, void *buf, size_t count))
{
    ssize_t return_value;

    put_str(1, function_name);
    put_str(1, ": ");

    char file_path[100];
    char buffer[20];

    memset(buffer, 0, 20);

    sprintf(file_path, "%sgood_permission_read", test_path);
    int fd = open(file_path, O_RDONLY);
    assert(fd >= 0);

    return_value = local_read(fd, buffer, 6);
    assert(return_value == 6);
    assert(strcmp("Works!", buffer) == 0);
    put_str(2, "Test 1 -> ");
    perror(function_name);
    put_str(1, GREEN"✔️"RESET);
    close(fd);
    
    put_str(1, "\n");
    put_str(2, "\n");
}

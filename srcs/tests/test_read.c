#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
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


    // Tests with valid fd
    return_value = local_read(fd, buffer, 20);
    put_str(2, "Test 1 -> ");
    perror(function_name);
    put_str(1, return_value == 7 && strcmp("Works!\n", buffer) == 0 ? GREEN" OK"RESET : RED" KO"RESET);
    errno = 0;

    return_value = local_read(fd, buffer, 10);
    assert(return_value == 0);
    put_str(2, "Test 2 -> ");
    perror(function_name);
    put_str(1, return_value == 0 ? GREEN" OK"RESET : RED" KO"RESET);
    close(fd);
    errno = 0;

    // Tests with invalid parameters
    sprintf(file_path, "%sbad_permission_read", test_path);
    fd = open(file_path, O_WRONLY);
    assert(fd >= 0);
    errno = 0;

    return_value = local_read(fd, buffer, 10);
    put_str(2, "Test 3 -> ");
    perror(function_name);
    put_str(1, return_value == -1 ? GREEN" OK"RESET : RED" KO"RESET);
    close(fd);
    errno = 0;

    return_value = local_read(-1, buffer, 10);
    put_str(2, "Test 4 -> ");
    perror(function_name);
    put_str(1, return_value == -1 ? GREEN" OK"RESET : RED" KO"RESET);
    errno = 0;

    return_value = local_read(-1, buffer, 10);
    put_str(2, "Test 5 -> ");
    perror(function_name);
    put_str(1, return_value == -1 ? GREEN" OK"RESET : RED" KO"RESET);
    errno = 0;

    put_str(1, "\n");
    put_str(2, "\n");
}

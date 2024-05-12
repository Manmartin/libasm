#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include "tests.h"

void test_write(const char *function_name, ssize_t local_write(int, const void *, size_t))
{
    ssize_t return_value;

    put_str(1, function_name);
    put_str(1, ": ");

    return_value = local_write(2, "Hello, World!\n", 14);
    assert(return_value == 14);
    put_str(2, "Test 1 -> ");
    perror(function_name);
    put_str(1, GREEN"✔️"RESET);
    errno = 0;

    return_value = local_write(1, NULL, 80);
    assert(return_value == -1);
    put_str(2, "Test 2 -> ");
    perror(function_name);
    put_str(1, GREEN"✔️"RESET);
    errno = 0;

    return_value = local_write(8, "wrong", 2);
    assert(return_value == -1);
    put_str(2, "Test 3 -> ");
    perror(function_name);
    put_str(1, GREEN"✔️"RESET);
    errno = 0;

    return_value = local_write(1, "wrong", -1);
    assert(return_value == -1);
    put_str(2, "Test 4 -> ");
    perror(function_name);
    put_str(1, GREEN"✔️"RESET);
    errno = 0;

    return_value = local_write(2, "Hello, World!\n", 0);
    assert(return_value == 0);
    put_str(2, "Test 5 -> ");
    perror(function_name);
    put_str(1, GREEN"✔️"RESET);
    errno = 0;
    
    put_str(1, "\n");
    put_str(2, "\n");
}

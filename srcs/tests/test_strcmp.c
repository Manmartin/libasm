#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include "tests.h"

void test_strcmp(const char *function_name, int local_strcmp(const char *s1, const char *s2))
{
    int return_value;

    put_str(1, function_name);
    put_str(1, ":");

    return_value = local_strcmp("", "");
    put_str(2, "Test 1 -> ");
    perror(function_name);
    put_str(1, return_value == 0 ? GREEN" OK"RESET : RED" KO"RESET);
    errno = 0;

    return_value = local_strcmp("test", "");
    put_str(2, "Test 2 -> ");
    perror(function_name);
    put_str(1, return_value > 0 ? GREEN" OK"RESET : RED" KO"RESET);
    errno = 0;

    return_value = local_strcmp("", "test");
    put_str(2, "Test 3 -> ");
    perror(function_name);
    put_str(1, return_value < 0 ? GREEN" OK"RESET : RED" KO"RESET);
    errno = 0;

    return_value = local_strcmp("testtesttest", "testtesttest");
    put_str(2, "Test 4 -> ");
    perror(function_name);
    put_str(1, return_value == 0 ? GREEN" OK"RESET : RED" KO"RESET);
    errno = 0;

    return_value = local_strcmp("testtesttest", "testtesttost");
    put_str(2, "Test 5 -> ");
    perror(function_name);
    put_str(1, return_value < 0 ? GREEN" OK"RESET : RED" KO"RESET);
    errno = 0;

    put_str(1, "\n");
    put_str(2, "\n");
}

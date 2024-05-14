#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include "tests.h"

void test_strdup(const char *function_name, char *local_strdup(const char *s1))
{
    char *return_value;
    put_str(1, function_name);
    put_str(1, ":");

    return_value = local_strdup("");
    put_str(2, "Test 1 -> ");
    perror(function_name);
    put_str(1, strcmp(return_value, "") == 0 ? GREEN" OK"RESET : RED" KO"RESET);
    free(return_value);
    errno = 0;

    return_value = local_strdup("test");
    put_str(2, "Test 2 -> ");
    perror(function_name);
    put_str(1, strcmp(return_value, "test") == 0 ? GREEN" OK"RESET : RED" KO"RESET);
    free(return_value);
    errno = 0;

    return_value = local_strdup("testtesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttest");
    put_str(2, "Test 3 -> ");
    perror(function_name);
    put_str(1, strcmp(return_value, "testtesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttest") == 0 ? GREEN" OK"RESET : RED" KO"RESET);
    free(return_value);
    errno = 0;

    return_value = local_strdup("There's no much more to test");
    put_str(2, "Test 4 -> ");
    perror(function_name);
    put_str(1, strcmp(return_value, "There's no much more to test") == 0 ? GREEN" OK"RESET : RED" KO"RESET);
    free(return_value);
    errno = 0;

    return_value = local_strdup("\0");
    put_str(2, "Test 5 -> ");
    perror(function_name);
    put_str(1, strcmp(return_value, "") == 0 ? GREEN" OK"RESET : RED" KO"RESET);
    free(return_value);
    errno = 0;

    put_str(1, "\n");
    put_str(2, "\n");
}

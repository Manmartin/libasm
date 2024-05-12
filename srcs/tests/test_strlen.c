#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include "tests.h"

void test_strlen(const char *function_name, size_t local_strlen(const char *s))
{
    ssize_t return_value;

    put_str(1, function_name);
    put_str(1, ": ");

    return_value = local_strlen("Hello!");
    assert(return_value == 6);
    put_str(2, "Test 1 -> ");
    perror(function_name);
    put_str(1, GREEN"✔️"RESET);
    errno = 0;

    return_value = local_strlen("C");
    assert(return_value == 1);
    put_str(2, "Test 2 -> ");
    perror(function_name);
    put_str(1, GREEN"✔️"RESET);
    errno = 0;

    return_value = local_strlen("");
    assert(return_value == 0);
    put_str(2, "Test 3 -> ");
    perror(function_name);
    put_str(1, GREEN"✔️"RESET);
    errno = 0;

    return_value = local_strlen("18657710093073411361408806052415");
    assert(return_value == 32);
    put_str(2, "Test 4 -> ");
    perror(function_name);
    put_str(1, GREEN"✔️"RESET);
    errno = 0;

    return_value = local_strlen("1167591119016088066105425238057431785454036646709131879052390500");
    assert(return_value == 64);
    put_str(2, "Test 4 -> ");
    perror(function_name);
    put_str(1, GREEN"✔️"RESET);
    errno = 0;

    put_str(1, "\n");
    put_str(2, "\n");
}

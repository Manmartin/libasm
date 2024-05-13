#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include "tests.h"

void test_strcpy(const char *function_name, char* local_strcpy(char *dest, const char *src))
{
    char *return_value;
    char s1[100] = "test";
    char s2[100];

    put_str(1, function_name);
    put_str(1, ": ");

    return_value = local_strcpy(s2, s1);
    assert(return_value == s2);
    assert(strcmp(s1, s2) == 0);
    put_str(2, "Test 1 -> ");
    perror(function_name);
    put_str(1, GREEN"✔️"RESET);
    errno = 0;

    return_value = local_strcpy(s1, "");
    assert(return_value == s1);
    assert(strcmp(s1, "") == 0);
    put_str(2, "Test 2 -> ");
    perror(function_name);
    put_str(1, GREEN"✔️"RESET);
    errno = 0;

    return_value = local_strcpy(s2, s1);
    assert(return_value == s2);
    assert(strcmp(s2, "") == 0);
    put_str(2, "Test 3 -> ");
    perror(function_name);
    put_str(1, GREEN"✔️"RESET);
    errno = 0;

    return_value = local_strcpy(s1, "1167591119016088066105425238057431785454036646709131879052390500");
    assert(return_value == s1);
    assert(strcmp(s1, "1167591119016088066105425238057431785454036646709131879052390500") == 0);
    put_str(2, "Test 4 -> ");
    perror(function_name);
    put_str(1, GREEN"✔️"RESET);
    errno = 0;

    return_value = local_strcpy(s2, s1);
    assert(return_value == s2);
    assert(strcmp(s2, s1) == 0);
    put_str(2, "Test 5 -> ");
    perror(function_name);
    put_str(1, GREEN"✔️"RESET);
    errno = 0;

    put_str(1, "\n");
    put_str(2, "\n");
}

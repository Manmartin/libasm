#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

void test_write(const char *function_name, ssize_t local_write(int, const void *, size_t))
{
    ssize_t return_value;
    (void)function_name;
    //char file_path[100];
    //sprintf(file_path, "%s%s", test_path, function_name);


    // Test 1 write 
    return_value = local_write(1, "Hello, World!\n", 14);
    assert(return_value == 14);

    // Test 2
    return_value = local_write(8, "wrong", 2);
    assert(return_value == -1);

}

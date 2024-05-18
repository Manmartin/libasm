#include "tests_bonus.h"
#include <libasm_bonus.h>
void test_atoi_base(void)
{
    char *str = "aba";
    char *base = "";
    int return_value;

    put_str(1, "ft_atoi_base");
    put_str(1, ":");
    
    // Test bad base
    return_value = ft_atoi_base(str, base);
    put_str(1, return_value == 0 ? GREEN" OK"RESET : RED" KO"RESET);
    
    base = "a";
    return_value = ft_atoi_base(str, base);
    put_str(1, return_value == 0 ? GREEN" OK"RESET : RED" KO"RESET);

    base = "ab";
    return_value = ft_atoi_base(str, base);
    put_str(1, return_value == 2 ? GREEN" OK"RESET : RED" KO"RESET);
    
    put_str(1, "\n");
}

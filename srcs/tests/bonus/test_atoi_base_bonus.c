#include "tests_bonus.h"
#include <libasm_bonus.h>
void test_atoi_base(void)
{
    char *str = "";
    char *base;
    int return_value;

    put_str(1, "ft_atoi_base");
    put_str(1, ":");
    
    // ### Test invalid base ###

    // Invalid len
    base = "";
    return_value = ft_atoi_base(str, base);
    put_str(1, return_value == 0 ? GREEN" OK"RESET : RED" KO"RESET);
    
    base = "a";
    return_value = ft_atoi_base(str, base);
    put_str(1, return_value == 0 ? GREEN" OK"RESET : RED" KO"RESET);
    
    // Invalid characters 
    base = "123+";
    return_value = ft_atoi_base(str, base);
    put_str(1, return_value == 0 ? GREEN" OK"RESET : RED" KO"RESET);

    base = "123-";
    return_value = ft_atoi_base(str, base);
    put_str(1, return_value == 0 ? GREEN" OK"RESET : RED" KO"RESET);

    base = "123 ";
    return_value = ft_atoi_base(str, base);
    put_str(1, return_value == 0 ? GREEN" OK"RESET : RED" KO"RESET);

    base = "\t\n\v\f\r";
    return_value = ft_atoi_base(str, base);
    put_str(1, return_value == 0 ? GREEN" OK"RESET : RED" KO"RESET);

    // Duplicated characters
    base = "aba";
    return_value = ft_atoi_base(str, base);
    put_str(1, return_value == 0 ? GREEN" OK"RESET : RED" KO"RESET);
    
    base = "aab";
    return_value = ft_atoi_base(str, base);
    put_str(1, return_value == 0 ? GREEN" OK"RESET : RED" KO"RESET);
    
    base = "baa";
    return_value = ft_atoi_base(str, base);
    put_str(1, return_value == 0 ? GREEN" OK"RESET : RED" KO"RESET);
    
    base = "ab";
    return_value = ft_atoi_base(str, base);
    put_str(1, return_value == 2 ? GREEN" OK"RESET : RED" KO"RESET);
    
    put_str(1, "\n");
}

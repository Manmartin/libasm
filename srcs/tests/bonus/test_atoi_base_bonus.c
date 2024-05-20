#include "tests_bonus.h"
#include <libasm_bonus.h>
#include <stdio.h>
void test_atoi_base(void)
{
    char *str = "";
    char *base = "";
    int return_value;
    put_str(1, "Invalid base:");

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

    put_str(1, "\n");

    // ### Test invalid str ###
    put_str(1, "Invalid str: ");
    base = "ab";
    str = "        \t\r\n\v\f -cddda";
    return_value = ft_atoi_base(str, base);
    put_str(1, return_value == 0 ? GREEN" OK"RESET : RED" KO"RESET);

    base = "ab";
    str = "        \t\r\n\v\f -";
    return_value = ft_atoi_base(str, base);
    put_str(1, return_value == 0 ? GREEN" OK"RESET : RED" KO"RESET);

    base = "ab";
    str = "+1234";
    return_value = ft_atoi_base(str, base);
    put_str(1, return_value == 0 ? GREEN" OK"RESET : RED" KO"RESET);

    put_str(1, "\n");

    // ### Test valid cases ###
    put_str(1, "Valid cases: ");
    base = "abc";
    str = "";
    return_value = ft_atoi_base(str, base);
    put_str(1, return_value == 0 ? GREEN" OK"RESET : RED" KO"RESET);

    base = "abc";
    str = "-aaaaaaab";
    return_value = ft_atoi_base(str, base);
    put_str(1, return_value == -1 ? GREEN" OK"RESET : RED" KO"RESET);

    base = "0123456789";
    str = "        \t\r\n\v\f +---+--+--+2147483648";
    return_value = ft_atoi_base(str, base);
    put_str(1, return_value == -2147483648 ? GREEN" OK"RESET : RED" KO"RESET);
    
    base = "0123456789";
    str = "        \t\r\n\v\f --+--+--2147483647";
    return_value = ft_atoi_base(str, base);
    put_str(1, return_value == 2147483647 ? GREEN" OK"RESET : RED" KO"RESET);

    base = "0123456789ABCDEF";
    str = "2A";
    return_value = ft_atoi_base(str, base);
    put_str(1, return_value == 42 ? GREEN" OK"RESET : RED" KO"RESET);

    base = "0123456789ABCDEF";
    str = "       \t\r\n\v\f --+--+--0";
    return_value = ft_atoi_base(str, base);
    put_str(1, return_value == 0 ? GREEN" OK"RESET : RED" KO"RESET);

    put_str(1, "\n");
}

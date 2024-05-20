#include "tests_bonus.h"
#include <libasm_bonus.h>
#include <stdlib.h>

void test_list_size(void)
{
    t_list *list = NULL;
    int content[5] = { 42, 22, 56, 2, 5};
    int return_value;

    put_str(1, "Valid cases");
    put_str(1, ":");
    
    return_value = ft_list_size(list);
    put_str(1, return_value == 0 ? GREEN" OK"RESET : RED" KO"RESET);

    
    ft_list_push_front(&list, &(content[0]));
    return_value = ft_list_size(list);
    put_str(1, return_value == 1 ? GREEN" OK"RESET : RED" KO"RESET);

    ft_list_push_front(&list, &(content[1]));
    return_value = ft_list_size(list);
    put_str(1, return_value == 2 ? GREEN" OK"RESET : RED" KO"RESET);

    ft_list_push_front(&list, &(content[2]));
    return_value = ft_list_size(list);
    put_str(1, return_value == 3 ? GREEN" OK"RESET : RED" KO"RESET);

    ft_list_push_front(&list, &(content[3]));
    return_value = ft_list_size(list);
    put_str(1, return_value == 4 ? GREEN" OK"RESET : RED" KO"RESET);

    ft_list_push_front(&list, &(content[4]));
    return_value = ft_list_size(list);
    put_str(1, return_value == 5 ? GREEN" OK"RESET : RED" KO"RESET);

    free_list(list);
    put_str(1, "\n");
}
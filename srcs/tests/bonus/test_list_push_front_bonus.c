#include "tests_bonus.h"
#include <libasm_bonus.h>
#include <stdlib.h>

static void check_list(t_list *list, int *numbers)
{
    int *content;
    while (list != NULL)
    {
        content = list->data;
        if (*content != *numbers)
        {
            put_str(1, RED" KO"RESET);
            return;
        }
        list = list->next;
        --numbers;
    }
    put_str(1, GREEN" OK"RESET);
}

void test_list_push_front(void)
{
    t_list *list = NULL;
    int content[5] = { 42, 22, 56, 2, 5};
    int content2[5] = { 42, 22, 56, 2, 5};

    put_str(1, "Valid cases");
    put_str(1, ":");

    ft_list_push_front(&list, &(content[0]));
    check_list(list, &(content2[0]));

    ft_list_push_front(&list, &(content[1]));
    check_list(list, &(content2[1]));

    ft_list_push_front(&list, &(content[2]));
    check_list(list, &(content2[2]));

    ft_list_push_front(&list, &(content[3]));
    check_list(list, &(content2[3]));

    ft_list_push_front(&list, &(content[4]));
    check_list(list, &(content2[4]));

    free_list(list);

    put_str(1, "\n");
}
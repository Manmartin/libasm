#include "tests_bonus.h"
#include <libasm.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void check_list_ints(t_list *list, int *numbers, int len)
{
    int content;
    int i = 0;

    while (list != NULL)
    {
        content = *((int *)list->data);
        if (content != *numbers)
        {
            put_str(1, RED" KO"RESET);
            return;
        }
        list = list->next;
        ++numbers;
        i++;
    }
    if (i != len)
        put_str(1, RED" KO"RESET);
    else 
        put_str(1, GREEN" OK"RESET);
}

static void check_list_strings(t_list *list, char **strings, int len)
{
    char *content;
    int i = 0;

    while (list != NULL)
    {
        content = list->data;
        if (strcmp(content, *strings) != 0)
        {
            put_str(1, RED" KO"RESET);
            return;
        }
        list = list->next;
        ++strings;
        i++;
    }
    if (i != len)
        put_str(1, RED" KO"RESET);
    else 
        put_str(1, GREEN" OK"RESET);
}

static void free_numb(void *n) { (void)n; }
static int cmp_number(int *n1, int *n2) { return *n1 - *n2; }
int cmp_number_less(int *n1, int *n2) { return *n1 < *n2 ? 0 : 1; }

void print_list(t_list *list)
{
    while (list) {
        printf("%i\n", (*(int *)list->data));
        list = list->next;
    }
}

void test_list_remove_if(void)
{
    t_list *list = NULL;
    int n, m;
    
    put_str(1, "Valid cases:");

    // Test 1
    ft_list_remove_if(&list, &n, cmp_number, free_numb);
    check_list_ints(list, NULL, 0);

    // Test 2
    n = 42;
    ft_list_push_front(&list, &n);
    ft_list_remove_if(&list, &n, cmp_number, free_numb);
    check_list_ints(list, NULL, 0);

    // Test 3
    n = 42;
    m = 24;
    ft_list_push_front(&list, &n);
    ft_list_remove_if(&list, &m, cmp_number, free_numb);
    check_list_ints(list, &n, 1);
    free_list(list);
    list = NULL;

    // Test 4
    n = 24;
    int input[10] = {41, 24, 42, 24, 43, 24, 44, 24, 45, 24};
    int output[5] = {41, 42, 43, 44, 45};


    for (int i = 9; i >= 0; --i) {
        ft_list_push_front(&list, &(input[i]));
    }
    ft_list_remove_if(&list, &n, cmp_number, free_numb);
    check_list_ints(list, output, 5);

    // Test 5
    n = 50;
    ft_list_remove_if(&list, &n, cmp_number_less, free_numb);
    check_list_ints(list, NULL, 0);
    list = NULL;

    // Test 6
    char *string_result[] = {"good", "good", "good", "good", "good", "good", "good", "good", "good", "good"};
    char *wrong_string = "wrong";
    for (int i = 0; i < 20; ++i) {
        ft_list_push_front(&list, i % 2 == 0 ? strdup("good") : strdup("wrong"));
    }
    ft_list_remove_if(&list, wrong_string, strcmp, free);
    check_list_strings(list, string_result, 10);

    // Test 7
    char *good_string = "good";
    ft_list_remove_if(&list, good_string, strcmp, free);
    check_list_strings(list, NULL, 0);

    put_str(1, "\n");
}

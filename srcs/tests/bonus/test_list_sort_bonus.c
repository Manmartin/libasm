#include "tests_bonus.h"
#include <libasm.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void check_list_string(t_list *list, char **strings, int len, t_list *smallest)
{
    char *content;
    int i = 0;
    if (list != smallest) {
        put_str(1, RED" KO"RESET);
        return;
    }
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

static void check_list_chars(t_list *list, char *string, int len)
{
    char content;
    int i = 0;

    while (list != NULL)
    {
        content = *((char *)list->data);
        if (content != *string)
        {
            put_str(1, RED" KO"RESET);
            return;
        }
        list = list->next;
        ++string;
        i++;
    }
    if (i != len)
        put_str(1, RED" KO"RESET);
    else 
        put_str(1, GREEN" OK"RESET);
}

static void check_list_ints(t_list *list, int *numbers, int len)
{
    char content;
    int i = 0;

    while (list != NULL)
    {
        content = *((int *)list->data);
        if (content != *numbers)
        {
            put_str(1, RED" KOs"RESET);
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

int my_strcmp(char *s1, char *s2)
{
    printf("s1 = %s\n", s1);
    printf("s2 = %s\n", s2);
    int r = strcmp(s1, s2);
    printf("%i\n", r);
    return r;
}

int cmp_chars(char *s1, char *s2) { return (unsigned char)*s1 - (unsigned char )*s2; }

int cmp_ints(int *n1, int *n2)
{
    if (*n1 == *n2)
        return 0;
    return *n1 < *n2 ? -1 : 1;
}

void test_list_sort(void)
{
    t_list *list = NULL, *aux = NULL;


    put_str(1, "Valid cases:");

    // Test 1
    ft_list_sort(&list, strcmp);
    put_str(1, list == NULL ? GREEN" OK"RESET : RED" KO"RESET);

    // Test 2
    char *string = "test";
    ft_list_push_front(&list, string);
    aux = list;
    check_list_string(list, &string, 1, aux);
    free_list(list);
    list = NULL;

    // Test 3
    char *original_strings[10] = { "nice!", "assembly", "is" };
    char *sorted_strings[10]   = { "assembly", "is", "nice!" };
    ft_list_push_front(&list, original_strings[2]);
    ft_list_push_front(&list, original_strings[1]);
    aux = list;
    ft_list_push_front(&list, original_strings[0]);

    ft_list_sort(&list, strcmp);
    check_list_string(list, sorted_strings, 3, aux);
    free_list(list);
    list = NULL;

    // Test 4
    char *shuffled_alph = "thoklbyxgepnfusaizdmjvcqwr";
    char *alph = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < 26; ++i) {
        ft_list_push_front(&list, &(shuffled_alph[i]));
    }
    ft_list_sort(&list, cmp_chars);
    check_list_chars(list, alph, 26);
    free_list(list);
    list = NULL;

    // Test 5
    int shuffled_numbers[53] = {15,1,45,34,41,8,32,9,2,35,30,23,18,42,48,12,20,42,29,7,21,25,26,37,49,5,22,40,10,4,28,27,17,11,2,14,46,31,39,47,19,33,16,36,44,43,3,38,50,24,6,13,1};
    int nums[53] = {1,1,2,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,42,43,44,45,46,47,48,49,50};
    for (int i = 0; i < 53; ++i) {
        ft_list_push_front(&list, &(shuffled_numbers[i]));
    }
    ft_list_sort(&list, cmp_ints);
    check_list_ints(list, nums, 53);
    free_list(list);

    put_str(1, "\n");
}

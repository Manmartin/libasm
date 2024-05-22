#include <unistd.h>
#include <stdlib.h>
#include <libasm.h>

void put_str(int fd, const char *s)
{
    while (*s)
        write(fd, s++, 1);
}

void free_list(t_list *list)
{
    t_list *aux;
    while (list != NULL)
    {
        aux = list;
        list = list->next;
        free(aux);
    }
}

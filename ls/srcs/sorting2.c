#include "../includes/ft_ls.h"

//This function retuns an alphabetically sorted list
int     default_compare(void *a, void *b)
{
    files   *file_a;
    files   *file_b;

    file_a = (files *)a;
    file_b = (files *)b;
    return(ft_strcmp(file_a->name, file_b->name));
}

//This function returns a reversed alphabetically sorted list
int     reverse_compare(void *a, void *b)
{
    files *file_a;
    files *file_b;

    file_a = (files *)a;
    file_b = (files *)b;
    return(ft_strcmp(file_b->name, file_a->name));
}

//This function returns a list sorted by last modified
int     time_compare(void *a, void *b)
{
    files   *file_a;
    files   *file_b;

    file_a = (files *)a;
    file_b = (files *)b;
    return(file_b->mtime - file_a->mtime);
}

comparefunc     determine_comparison(unsigned char flags)
{
    (void)flags;
    return default_compare;
}

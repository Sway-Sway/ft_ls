#include "libft.h"

void    ft_lstiter_data(t_list *lst, void(*f)(t_list *elem, void *data), void *data)
{
    t_list *n_lst;

    n_lst = lst;
    while(n_lst)
    {
        (*f)(n_lst, data);
        n_lst = n_lst->next;
    }
}
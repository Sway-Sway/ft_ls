#include "libft.h"

void    ft_lstiter(t_list *lst, void(*f)(t_list *elem))
{
    t_list  *n_lst;

    n_lst = lst;
    while (n_lst)
    {
        (*f)(n_lst);
        n_lst = n_lst->next;
    }
}

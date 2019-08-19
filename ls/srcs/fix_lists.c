/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwayiba <jkwayiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:19:55 by jkwayiba          #+#    #+#             */
/*   Updated: 2019/08/19 17:58:50 by jkwayiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

files    *lstnew(files *new)
{
    new = (files *)malloc(sizeof(files));
    new->next = NULL;
    return (new);
}
void    lstadd(files **first, files *new)
{
    new->next = *first;
}
void    ft_lstcr(files **first, char *path)
{
    files *node = NULL;
    
    if (!first)
    {
        *first = lstnew(*first);
        longformat(path, *first);
        return; 
    }
    else
    {
        node = lstnew(*first);
        longformat(path, node);
        lstadd(first, node);
    }
    
}
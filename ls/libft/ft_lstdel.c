/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwayiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 12:31:18 by jkwayiba          #+#    #+#             */
/*   Updated: 2019/08/12 13:28:52 by jkwayiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
// {
// 	t_list *cnt;
// 	t_list *nxt;

// 	cnt = *alst;
// 	while (cnt)
// 	{
// 		nxt = cnt->next;
// 		del((cnt->content), (cnt->content_size));
// 		free(cnt);
// 		cnt = nxt;
// 	}
// 	*alst = NULL;
// }

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *n_lst;
	t_list *temp;

	n_lst = *alst;
	while (n_lst)
	{
		if (*del)
			(*del)(n_lst->content, n_lst->content_size);
		temp = n_lst->next;
		free(n_lst);
		n_lst = temp;
	}
	*alst = NULL;
}

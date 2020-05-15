/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwayiba <jkwayiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:03:54 by jkwayiba          #+#    #+#             */
/*   Updated: 2020/05/11 10:55:00 by groovyswa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	FrontBackSplit(t_list *source, t_list **front_ref, t_list **back_ref)
{
	t_list *fast;
	t_list *slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front_ref = source;
	*back_ref = slow->next;
	slow->next = NULL;
}


 t_list	*SortedMerge(t_list *a, t_list *b, int(*compare)(void *a, void *b))
 {
 	t_list *result;
	int	comparison;

 	result = NULL;
 	if (a == NULL)
 		return (b);
 	else if (b == NULL)
 		return (a);
	comparison = (*compare)(a->content, b->content);
 	if (comparison <= 0)
 	{
 		result = a;
 		result->next = SortedMerge(a->next, b, compare);
 	}
 	else 
 	{
		result = b;
		result->next = SortedMerge(a, b->next, compare);
	}
	return (result);
 }


 void	ft_lstmergesort(t_list **head_ref, int (*compare)(void *a, void *b))
 {
 	t_list *head;
 	t_list *a;
 	t_list *b;

 	head = *head_ref;
 	if ((head == NULL) || (head->next == NULL))
 		return ;
 	FrontBackSplit(head, &a, &b);
 	ft_lstmergesort(&a, compare);
 	ft_lstmergesort(&b, compare);
	*head_ref = SortedMerge(a, b, compare);
 }


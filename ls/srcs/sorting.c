/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwayiba <jkwayiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:03:54 by jkwayiba          #+#    #+#             */
/*   Updated: 2019/09/16 14:43:11 by jkwayiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	merge_sort(files **head_ref)
{
	files *head;
	files *a;
	files *b;

	head = *head_ref; 
	if ((head == NULL) || (head->next == NULL))
		return ;
	FrontBackSplit(head, &a, &b);
	merge_sort(&a);
	merge_sort(&b);
	*head_ref = SortedMerge(a, b);
}

files	*SortedMerge(files *a, files *b)
{
	files *result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (ft_strcmp(a->name, b->name) <= 0)
	{
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else 
	{
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return (result);
}

void	FrontBackSplit(files *source, files **front_ref, files **back_ref)
{
	files *fast;
	files *slow;

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

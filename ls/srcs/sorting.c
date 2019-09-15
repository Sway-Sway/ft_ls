/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwayiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:03:54 by jkwayiba          #+#    #+#             */
/*   Updated: 2019/09/16 00:11:32 by jkwayiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	merge_sort(files **head_ref)
{
	files *head;
	files *a;
	files *b;

	if ((head == NULL) || (head->next == NULL))
		return ;
	FrontBackSplit(head, &a, &b);
	MergeSort(&a);
	MergeSort(&b);
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
	if (ft_strcmp(a->name, b->next) < 0)
	{
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else if (ft_strcmp(a->name, b->name) > 0)
	{
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else 
	{
		result = b;
		result->next = SortedMerge(a, b->next)
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
	slow->next; = NULL;
}

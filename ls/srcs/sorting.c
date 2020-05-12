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

void	merge_sort(files **head_ref, unsigned char flags)
{
	files *head;
	files *a;
	files *b;

	head = *head_ref;
	if ((head == NULL) || (head->next == NULL))
		return ;
	FrontBackSplit(head, &a, &b);
	merge_sort(&a, flags);
	merge_sort(&b, flags);
	if (flags & 16)
		*head_ref = SortedMerge_time(a, b, flags);
	else
		*head_ref = SortedMerge(a, b, flags);
}

files	*SortedMerge(files *a, files *b, unsigned char flags)
{
	files *result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (!(flags & 8) && ((ft_strcmp(a->name, b->name)) < 0))
	{
		result = a;
		result->next = SortedMerge(a->next, b, flags);
	}
	else if ((flags & 8) && ((ft_strcmp(a->name, b->name)) > 0))
	{
		result = a;
		result->next = SortedMerge(a->next, b, flags);
	}
	else 
	{
		result = b;
		result->next = SortedMerge(a, b->next, flags);
	}
	return (result);
}

files	*SortedMerge_time(files *a, files *b, unsigned int flags)
{
	files	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (!(flags & 8) && (a->mtime > b->mtime))
	{
		result = a;
		result->next = SortedMerge_time(a->next, b, flags);
	}
	else if ((flags & 8) && (a->mtime < b->mtime))
	{
		result = a;
		result->next = SortedMerge_time(a->next, b, flags);
	}
	else
	{
		result = b;
		result->next = SortedMerge_time(a, b->next, flags);
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

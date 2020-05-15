/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwayiba <jkwayiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:08:44 by jkwayiba          #+#    #+#             */
/*   Updated: 2020/05/12 03:51:08 by groovyswa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	longformat(files *list)
{
	if ((S_ISLNK(list->mode)))
		ft_putstr("l");
	else
		ft_putstr(list->permissions);
	ft_putchar(' ');
	ft_putnbr(list->links);
	ft_putchar('\t');
	ft_putstr(list->user);
	ft_putchar(' ');
	ft_putstr(list->group);
	ft_putchar(' ');
	ft_putnbr(list->filesize);
	ft_putchar('\t');
	ft_putstr(list->date);
	ft_putchar(' ');
	ft_putendl(list->name);
}

// void	file_print(t_list *data)
// {
// 	files *file;

// 	file = (files *)data->content;
	
// 	if(flag & 2)
// 		longformat(file);
// 	else if (ft_strncmp(file->name, ".", 1) != 0)
// 		longformat(file);
// }

// void	print_list(files *list, unsigned char flags)
// {
// 	files	*ptr;
// 	files	*ptr2;

// 	ptr = list;
// 	ptr2 = list;
// 	if (flags & 1)
// 		display_blocks(ptr2, flags);
// 	while (ptr != NULL)
// 	{
// 		if (flags & 2)
// 			longformat(ptr);
// 		else if (ft_strncmp(ptr->name, ".", 1) != 0)
// 			longformat(ptr);
// 		//ptr = ptr->next;
// 	}
//}

void	print_normal(files *list, unsigned char flags)
{
	files *ptr;

	ptr = list;
	while (ptr != NULL)
	{
		if (flags & 2 || flags & 16)
		{
			ft_putendl(ptr->name);
		}
		else
		{
			if (ptr->name[0] != '.')
			{
				ft_putendl(ptr->name);
			}
		//	ptr = ptr->next;
		}
	}
}


// void	print_output(files *list, unsigned char flags)
// {
// 	if (flags & 1)
// 		print_list(list, flags);
// 	else
// 		print_normal(list, flags);
// }

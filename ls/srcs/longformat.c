/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwayiba <jkwayiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:08:44 by jkwayiba          #+#    #+#             */
/*   Updated: 2019/09/08 10:08:05 by jkwayiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	longformat(char *path)
{
	files	*node;
	DIR	*dir;
	
	dir = opendir(path);
	if (!dir)
	{
		ft_putendl("Error! Unable to open directory.\n");
		exit(1);
	}
	while ((dp = readdir(dir)))
	{
		if (!node)
		node = items_lst(dp, path);
		else
		add_list(&node, dp, path);
		ft_putstr(node->permissions);
		ft_putchar(' ');
		ft_putnbr(node->links);
		ft_putchar(' ');
		ft_putstr(node->user);
		ft_putchar(' ');
		ft_putstr(node->group);
		ft_putchar(' ');
		ft_putnbr(node->filesize);
		ft_putchar('\t');
		ft_putstr(node->date);
		ft_putchar(' ');
		ft_putendl(node->name);
		//longformat(node->path);
		//free(node);
		
	}
	closedir(dir);
}
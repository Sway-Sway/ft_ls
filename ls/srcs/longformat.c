/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwayiba <jkwayiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:08:44 by jkwayiba          #+#    #+#             */
/*   Updated: 2019/09/03 15:06:06 by jkwayiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ft_ls.h"

struct stat     filestat;
struct passwd   *pass;
struct group    *grpss;

void	longformat(char *path)
{
	struct	dirent	*dp;
	files	*node;
	char	*fullpath; //this might be an issue
	char	*temp;
	DIR		*dir;

	dp = NULL;
	dir = opendir(path);
	if (!dir)
	{
		ft_putendl("Error! Unable to open directory.\n");
		exit(1);
	}
	//ft_putstr("total ");
	//total_blocks(node);
	//ft_putchar('\n');
	print_blocks(node);
	while ((dp = readdir(dir)))
	{		
			if (!node)
			 	node = items_lst(dp, temp);
			else
			 	add_list(&node, dp, path);
			//ft_putendl(ft_strjoin("total ", ft_itoa(node->blocks)));
			//total_blocks(node);
			
			node->permissions[0] = (S_ISDIR(filestat.st_mode) ? 'd' : '-');
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
			free(node);
}
//clear_list(node);
closedir(dir);
}

int main(int ac, char **av)
{
	struct files *new;
	struct dirent *dp;

	new = NULL;
	longformat(av[1]);
	return (0);
}	

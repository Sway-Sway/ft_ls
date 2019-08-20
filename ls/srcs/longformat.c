/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwayiba <jkwayiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:08:44 by jkwayiba          #+#    #+#             */
/*   Updated: 2019/08/20 14:51:14 by jkwayiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ft_ls.h"

struct stat     filestat;
struct passwd   *pass;
struct group    *grpss;

void	longformat(char *path)
{
	struct	dirent	*dp;
	struct	stat	filestat;
	files	*node;
	char	*fullpath; //this might be an issue
	char	*temp;
	DIR		*dir;

	dir = opendir(path);
	if (!dir)
	{
		ft_putendl("Error! Unable to open directory.\n");
		exit(1);
	}
	while ((dp = readdir(dir)))
	{	
		// ft_str(fullpath, path);
		temp = ft_strdup(path);
		ft_strcat(temp, "/");
		fullpath = ft_strjoin(temp, dp->d_name);
		free(temp);
		if (!stat(fullpath, &filestat))
		{				
			node = items_lst(filestat, dp);
			node->permissions[0] = (S_ISDIR(filestat.st_mode) ? 'd' : '-');
			ft_putstr(node->permissions);
			ft_putchar(' ');
			ft_putstr(node->user);
			ft_putchar(' ');
			ft_putstr(node->group);
		 	ft_putchar(' ');
			 ft_putnbr(node->filesize);
		 	ft_putchar(' ');
			ft_putendl(node->name);	 
		// 	ft_putstr(ft_itoa(filestat.st_size));
		// 	ft_putchar(' ');
		// 	ft_putstr((ft_strsub((ctime(&filestat.st_mtime)),4,12)));
		// 	ft_putchar(' ');
		// }
		// ft_putstr(dp->d_name);
		//ft_putchar('\n');
	}
}
free(fullpath);
closedir(dir);
}

int main(void)
{
	struct files *new;
	struct dirent *dp;

	new = NULL;
	longformat(".");
	//ft_lstcr(&new, ".");
	// ft_putchar(' ');
	// ft_putstr(new->user);
	// ft_putchar(' ');
	// ft_putstr(new->group);
	// ft_putchar(' ');
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwayiba <jkwayiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:08:44 by jkwayiba          #+#    #+#             */
/*   Updated: 2019/08/19 17:55:43 by jkwayiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ft_ls.h"

struct stat     filestat;
struct passwd   *pass;
struct group    *grpss;

void	longformat(char *path, files *node)
{
	struct	dirent	*dp;
	struct	stat	filestat;
	char	fullpath[1000];
	DIR		*dir;

	dir = opendir(path);
	if (!dir)
	{
		ft_putendl("Error! Unable to open directory.\n");
		exit(1);
	}
	while ((dp = readdir(dir)) != NULL)
	{
		ft_strcpy(fullpath, path);
		ft_strcat(fullpath, "/");
		ft_strcat(fullpath, dp->d_name);

		if (!stat(fullpath, &filestat))
		{
			get_uid(filestat, node);
			get_guid(filestat, node);
			node->permissions[0] = (S_ISDIR(filestat.st_mode) ? 'd' : '-');
			get_perms(filestat, node);
		// 	ft_putchar(' ');
		// 	ft_putstr(ft_itoa(filestat.st_nlink));
		// 	ft_putchar(' ');
		// 	ft_putstr(pass->pw_name);
		// 	ft_putchar(' ');
		// 	ft_putstr(grpss->gr_name);
		// 	ft_putchar(' ');
		// 	ft_putstr(ft_itoa(filestat.st_size));
		// 	ft_putchar(' ');
		// 	ft_putstr((ft_strsub((ctime(&filestat.st_mtime)),4,12)));
		// 	ft_putchar(' ');
		// }
		// ft_putstr(dp->d_name);
		//ft_putchar('\n');
	}
	closedir(dir);
}
}

int main(void)
{
	struct files *new;
	
	new = NULL;
	ft_lstcr(&new, ".");
	 ft_putstr(new->permissions);
	// ft_putchar(' ');
	// ft_putstr(new->user);
	// ft_putchar(' ');
	// ft_putstr(new->group);
	// ft_putchar(' ');
	return (0);
}
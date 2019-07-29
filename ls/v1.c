/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwayiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 11:02:04 by jkwayiba          #+#    #+#             */
/*   Updated: 2019/07/29 15:26:28 by jkwayiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	DIR *dir;
	struct	dirent	*sd;
	struct	stat	fileStat;
	struct 	passwd	*pass;
	struct	group	*grpss;
	char	fullpath[256];


	dir = opendir(av[1]);
	if(dir == NULL)
	{
		printf("Error! Unable to open directory.\n");
		exit(1);
	}
	while((sd=readdir(dir)) != NULL)
	{
		strcpy (fullpath, av[1]);
		strcat (fullpath, "/");
		strcat (fullpath, sd->d_name);
		if(!stat(fullpath, &fileStat))
		{
			pass = getpwuid(fileStat.st_uid);
			grpss = getgrgid(fileStat.st_gid);
			ft_putstr((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
			ft_putstr((fileStat.st_mode & S_IRUSR) ? "r" : "-");
			ft_putstr((fileStat.st_mode & S_IWUSR) ? "w" : "-");
			ft_putstr((fileStat.st_mode & S_IXUSR) ? "x" : "-");
			ft_putstr((fileStat.st_mode & S_IRGRP) ? "r" : "-");
			ft_putstr((fileStat.st_mode & S_IWGRP) ? "w" : "-");
			ft_putstr((fileStat.st_mode & S_IXGRP) ? "x" : "-");
			ft_putstr((fileStat.st_mode & S_IROTH) ? "r" : "-");
			ft_putstr((fileStat.st_mode & S_IWOTH) ? "w" : "-");
			ft_putstr((fileStat.st_mode & S_IXOTH) ? "x" : "-");
			ft_putchar(' ');
			ft_putstr(ft_itoa(fileStat.st_nlink));
			ft_putchar(' ');
			ft_putstr(pass->pw_name);
			ft_putchar(' ');
			ft_putstr(grpss->gr_name);
			ft_putchar(' ');
			ft_putstr(ft_itoa(fileStat.st_size));
			ft_putchar(' ');
			ft_putstr((ft_strsub((ctime(&fileStat.st_mtime)),4,12)));
			ft_putchar(' ');
		}
		ft_putstr(sd->d_name);
		ft_putchar('\n');
	}
	closedir(dir);
	return (0);
}

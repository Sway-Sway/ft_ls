/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwayiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 11:02:04 by jkwayiba          #+#    #+#             */
/*   Updated: 2019/07/29 14:08:17 by jkwayiba         ###   ########.fr       */
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
			printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
			printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
			printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
			printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
			printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
			printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
			printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
			printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
			printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
			printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
			printf(" %s", pass->pw_name);
			printf(" %s", grpss->gr_name);
		}
		printf(" %s\n", sd->d_name);
	}
	closedir(dir);
	return (0);
}

#include "ft_ls.h"

void	longformat(char *path)
{
	struct	dirent	*dp;
	struct	stat	filestat;
	struct	passwd	*pass;
	struct	group	*grpss;
	char	fullpath[1000];
	DIR	*dir;

	dir = opendir(path);
	if (!dir)
	{
		ft_putendl("Error! Unable to open directory.\n");
		exit(1);
	}
	while ((sd = readir(dir)) != NULL)
	{
		ft_strcpy(fullpath, path);
		ft_strcat(fullpath, "/");
		ft_strcat(fullpath, dp->d_name);

		if (!stat(fullpath, &filestat))
		{
			pass = getpwuid(filestat.st_uid);
			grpss = getgrgid(filestat.st_gid);
			ft_putstr((S_ISDIR(filestat.st_mode)) ? "d" : "-");
			ft_putstr((filestat.st_mode & S_IRUSR) ? "r" : "-");
			ft_putstr((filestat.st_mode & S_IWUSR) ? "w" : "-");
			ft_putstr((filestat.st_mode & S_IXUSR) ? "x" : "-");
			ft_putstr((filestat.st_mode & S_IRGRP) ? "r" : "-");
			ft_putstr((filestat.st_mode & S_IWGRP) ? "w" : "-");
			ft_putstr((filestat.st_mode & S_IXGRP) ? "x" : "-");
			ft_putstr((filestat.st_mode & S_IROTH) ? "r" : "-");
			ft_putstr((filestat.st_mode & S_IWOTH) ? "w" : "-");
			ft_putstr((filestat.st_mode & S_IXOTH) ? "x" : "-");
			ft_putchar(' ');
			ft_putstr(ft_itoa(filestat.st_nlink));
			ft_putchar(' ');
			ft_putstr(pass->pw_name);
			ft_putchar(' ');
			ft_putstr(grpss->gr_name);
			ft_putchar(' ');
			ft_putstr(ft_itoa(filestat.st_size));
			ft_putchar(' ');
			ft_putstr((ft_strsub((ctime(&filestat.st_mtime)),4,12)));
			ft_putchar(' ');
		}
		ft_putstr(dp->d_name);
		ft_putchar('\n');
	}
	closedir(dir);
}

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
	if (!(new = (files *)malloc(sizeof(files))))
		return (0);
	new->next = NULL;
	longformat(".", new);
	ft_putendl(new->permissions);
	ft_putendl(new->user);
	ft_putendl(new->group);
	return (0);
}
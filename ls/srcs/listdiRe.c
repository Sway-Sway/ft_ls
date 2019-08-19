#include "../includes/ft_ls.h"

void	listfilesrecursively(char *basepath)
{
	char path[1000]; //char *path;
	struct dirent *dp;
	DIR *dir = opendir(basepath);

	if (!dir)
		return ;
	while ((dp = readdir(dir)) != NULL)
	{
		if (ft_strcmp(dp->d_name, ".") != 0 && ft_strcmp(dp->d_name, "..") != 0)
		{
			ft_putendl(dp->d_name);
			ft_strcpy(path, basepath);
			ft_strcat(path, "/");
			ft_strcat(path, dp->d_name);
			listfilesrecursively(path);
		}
	}
	closedir(dir);
}


int		main(int ac, char **av)
{
	if (ac == 3)
	{
		if (ft_strcmp(av[1], "-R") == 0)
		{
			listfilesrecursively(av[2]);
		}
		else if (ft_strcmp(av[1], "l") == 0)
		{
			listfiles(av[2]);
		}
	} 
	return (0);
}
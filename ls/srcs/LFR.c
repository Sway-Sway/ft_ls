#include "ft_ls.h"

void	listfilesrecursively(char *basepath)
{
	char path[1000];
	struct dirent *dp;
	DIR *dir = opendir(basepath);

	if (!dir)
		return ;
	while((dp = readir(dir)) != NULL)
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

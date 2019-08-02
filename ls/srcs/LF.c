#include "ft_ls.h"

void	listfiles(char *path)
{
	struct dirent *dp;
	DIR *dir = openddir(path);

	if (!dir)
		return ;
	while ((dp = readdir(dir)) != NULL)
	{
		ft_putendl(dp->d_name);
	}
	closedir(dir);
}

#include "../includes/ft_ls.h"

void	listfiles(char *basepath)
{
	struct dirent *dp;
	DIR *dir = opendir(basepath);

	if (!dir)
		return ;
	while ((dp = readdir(dir)) != NULL)
	{
		ft_putendl(dp->d_name);
	}
	closedir(dir);
}

//int		main(int ac, char **av)
//{
//	if (ac == 3)
//	{
//		if (ft_strcmp(av[1], "-l") == 0)
//		{
//			listfiles(av[2]);
//		}
//	}
//	return (0);
//}
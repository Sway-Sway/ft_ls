#include "../includes/ft_ls.h"

void	listfilesrecursively(char *basepath)
{
	files *node;
	struct dirent *dp;
	DIR *dir = opendir(basepath);

	if (!dir)
		return ;
	while ((dp = readdir(dir)) != NULL)
	{
		node = items_lst(dp, basepath);
		if (dp->d_type == DT_DIR && ft_strcmp(node->name, ".") != 0 && ft_strcmp(node->name, "..") != 0)
		{
			add_list(&node, dp, basepath);
			ft_putendl(node->path);
			longformat(node->path);
			ft_putchar('\n');
			listfilesrecursively(node->path);
		}
	}
	clear_list(node);
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
			longformat(av[2]);
		}
		else if (ft_strcmp(av[1], "  ") == 0)
		{
			listfiles(av[2]);
		}
	} 
	return (0);
}
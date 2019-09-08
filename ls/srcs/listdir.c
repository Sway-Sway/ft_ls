#include "../includes/ft_ls.h"

void	listfiles(char *basepath)
{
	files *node;
	DIR *dir = opendir(basepath);

	if (!dir)
		return ;
	while ((dp = readdir(dir)) != NULL)
	{
		node = items_lst(dp, basepath);
		if (ft_strcmp(node->name, ".") != 0 && ft_strcmp(node->name, "..") != 0)
		{
			add_list(&node, dp, basepath);
			ft_putendl(node->name);
		}
	}
	clear_list(node);
	closedir(dir);
}
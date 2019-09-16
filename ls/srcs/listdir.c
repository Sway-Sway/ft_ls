#include "../includes/ft_ls.h"

void	listfiles(char *basepath)
{
	files *node;
	DIR *dir = opendir(basepath);
	
	node = NULL;
	if (!dir)
		return ;
	while ((dp = readdir(dir)) != NULL)
	{
		if (ft_strcmp(dp->d_name, ".") != 0 && ft_strcmp(dp->d_name, "..") != 0)
		{	
			if (node == NULL)
			{
				node = items_lst(dp, basepath);
			}
			else {
				add_list(&node, dp, basepath);
			}
		}
	}
	closedir(dir);
	merge_sort(&node);
	reverse_list(&node);
	print_dir(node);
	clear_list(node);
}
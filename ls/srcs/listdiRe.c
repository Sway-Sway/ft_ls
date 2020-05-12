#include "../includes/ft_ls.h"

void	listfilesrecursively(files *list, char *basepath, unsigned char flags)
{
	files 	*node;
	char	*s1;
	char	*s2;


	node = list;
	if (flags & 4)
		while (node != NULL)
	{
		if ((node->type == 4) && (ft_strcmp(node->name, ".") != 0) &&
		 (ft_strcmp(node->name, "..") != 0))
		{
			if (!(flags & 2) && (node->name[0] == '.'))
			{
				node = node->next;
				continue ;
			}
			s1 = ft_strjoin("/", node->name);
			s2 = ft_strjoin(basepath, s1);
			free(s1);
			ft_ls(s2, flags);
			free(s2);
		}
		node = node->next;

	}
}

void	ft_ls(char *path, unsigned char flags)
{
	files			*initial;
	DIR				*dr;

	initial = NULL;
	dp = NULL;
	dr = opendir(path);
	if (error_handler(path, dr, errno, flags) == 1)
		return ;
	while ((dp = readdir(dr)))
	{
		if (!initial)
			initial = items_lst(dp, path);
		else
			add_list(&initial, dp, path);
	}
	closedir(dr);
	if (!(flags & 16))
		merge_sort(&initial, flags);
	else
		reverse_list(&initial);
	print_output(initial, flags);
	listfilesrecursively(initial, path, flags);
	clear_list(&initial);
}

int		options_execute(int ac, char **av, unsigned char flags)
{
	int		i;
	int		check;

	i = 1;
	check = 0;
	while (i < ac)
	{
		if (av[i][0] != '-')
		{
			ft_ls(av[i], flags);
			check = 1;
		}
		if (av[i][0] == '-' && av[i][1] == '\0')
			check = 2;
		i++;
	}
	return (check);
}


int		main(int ac, char **av)
{
	unsigned char	flags;
	int				check;

	check = 0;
	flags = option_parser(ac, av);
	if (ac == 1)
		ft_ls(".", flags);
	else
	{
		check = options_execute(ac, av, flags);
		if (check == 0)
			ft_ls(".", flags);
	} 
	return (0);
}

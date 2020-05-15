#include "../includes/ft_ls.h"

// void	listfilesrecursively(t_list *list, void *basepath)
// {
// 	files 	*node;
// 	char	*pathdata;
// 	char	*s1;
// 	char	*s2;


// 	node = (files *)list->content;
// 	pathdata = (char *)basepath;
// 	// if (flags & 4)
// 	// 	while (node != NULL)
// 	// {
// 	if ((node->type == 4) && (ft_strcmp(node->name, ".") != 0) &&
// 		(ft_strcmp(node->name, "..") != 0))
// 	{
// 		if (!(flags & 2) && (node->name[0] == '.'))
// 		{
// 			// node = node->next;
// 			// continue ;
// 			return ;
// 		}
// 		s1 = ft_strjoin("/", node->name);
// 		s2 = ft_strjoin(basepath, s1);
// 		free(s1);
// 		ft_ls(s2, flags);
// 		free(s2);
// 		}
// 		node = node->next;
// 	}
// }
unsigned char flags;

void	recurse(t_list *data, void *pathdata)
{
	char	*s1;
	char	*s2;
	char	*basepath;
	files	*file;

	file = (files *)data->content;
	basepath = (char *)pathdata;

	if ((file->type == 4) && (ft_strcmp(file->name, ".") != 0)
	&& (ft_strcmp(file->name, "..") != 0))
	{
		if (!(flags & 2) && (file->name[0] == '.'))
		{
			return ;
		}
		s1 = ft_strjoin("/", file->name);
		s2 = ft_strjoin(basepath, s1);
		free(s1);
		ft_ls(s2, flags);
		free(s2);
	}
}

void	file_del(void *data, size_t structsize)
{
	files *file;

	file = (files *)data;
	(void)structsize;
	ft_strdel(&file->name);
	ft_strdel(&file->user);
	ft_strdel(&file->group);
	ft_strdel(&file->date);
	ft_memdel(&data);
}

void	file_print(t_list *data)
{
	files *file;

	file = (files *)data->content;
	
	if(flags & 2)
		longformat(file);
	else if (ft_strncmp(file->name, ".", 1) != 0)
		longformat(file);
}

void	ft_ls(char *path, unsigned char flags)
{
	t_list			*initial;
	DIR				*dr;
	files			file;

	initial = NULL;
	dp = NULL;
	dr = opendir(path);
	if (error_handler(path, dr, errno, flags) == 1)
		return ;
	while ((dp = readdir(dr)))
	{
		items_lst(&file, dp, path);
		ft_lstadd(&initial, ft_lstnew(&file, sizeof(files)));
		// if (!initial)
		// 	initial = items_lst(dp, path);
		// else
		// 	add_list(&initial, dp, path);
	}
	closedir(dr);
	ft_lstmergesort(&initial, determine_comparison(flags));
	ft_lstiter(initial, file_print);
	if (flags & 4)
		ft_lstiter_data(initial, recurse, path);
	ft_lstdel(&initial, file_del);	
	// if (!(flags & 16))
	// 	merge_sort(&initial, flags);
	// else
	// 	reverse_list(&initial);
	// print_output(initial, flags);
	// listfilesrecursively(initial, path, flags);
	// clear_list(&initial);
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
		//if (av[i][0] == '-' && av[i][1] == '\0')
		//	check = 2;
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

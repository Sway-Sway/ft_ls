/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwayiba <jkwayiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:59:12 by jkwayiba          #+#    #+#             */
/*   Updated: 2020/05/11 10:41:45 by groovyswa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	error_handler2(char *path)
{
	if (ft_strcmp(path, ".") != 0)
	{
		ft_putstr("\n");
		ft_putstr(path);
		ft_putstr(":\n");
	}
}

void	error_handler_permission(char *path)
{
	ft_putstr("ft_ls: ");
	if (path[ft_strlen(path) - 1] != '/')
		ft_putstr(path);
	ft_putstr(": Permission denied\n");
}

void	error_file(char *path)
{
	ft_putstr("ft_ls: ");
	ft_putstr(path);
	ft_putstr(": No such file or directory\n");
}

int		error_handler(char *path, DIR *dp, int ierrno, unsigned int flag)
{
	if (ierrno == 20)
	{
		ft_putstr(path);
		return (1);
	}
	else if (!dp)
	{
		if (ierrno == 13)
		{
			error_handler_permission(path);
			return (1);
		}
		error_file(path);
		return (1);
	}
	if (flag & 4)
	{
		error_handler2(path);
	}
	return (0);
}

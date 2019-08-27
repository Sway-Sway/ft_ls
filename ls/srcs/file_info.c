/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwayiba <jkwayiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:08:28 by jkwayiba          #+#    #+#             */
/*   Updated: 2019/08/27 17:52:36 by jkwayiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/ft_ls.h"


void    get_uid(struct stat filestat, files *node)
{
    struct passwd *pass;

    pass = getpwuid(filestat.st_uid);
    if (pass)
        node->user = ft_strdup(pass->pw_name);
    //else
     //   node->user = ft_itoa(pass->pw_name);    
}

void   get_guid(struct stat filestat, files *node)
{
    struct group *grpss;

    grpss = getgrgid(filestat.st_gid);
    if (grpss)
        node->group = ft_strdup(grpss->gr_name);
    //else
    //  node->group = ft_itoa(grpss->gr_name);
}

void    get_perms(struct stat filestat, files *node)
{
            node->permissions[1] = (filestat.st_mode & S_IRUSR) ? 'r' : '-';
			node->permissions[2] = (filestat.st_mode & S_IWUSR) ? 'w' : '-';
			node->permissions[3] = (filestat.st_mode & S_IXUSR) ? 'x' : '-';
			node->permissions[4] = (filestat.st_mode & S_IRGRP) ? 'r' : '-';
			node->permissions[5] = (filestat.st_mode & S_IWGRP) ? 'w' : '-';
			node->permissions[6] = (filestat.st_mode & S_IXGRP) ? 'x' : '-';
			node->permissions[7] = (filestat.st_mode & S_IROTH) ? 'r' : '-';
			node->permissions[8] = (filestat.st_mode & S_IWOTH) ? 'w' : '-';
			node->permissions[9] = (filestat.st_mode & S_IXOTH) ? 'x' : '-';
            node->permissions[10] = '\0';
}


void    total_blocks(struct stat filestat, files *node)
{
        node->blocks += filestat.st_blocks;
}
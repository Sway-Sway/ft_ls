/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwayiba <jkwayiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:08:28 by jkwayiba          #+#    #+#             */
/*   Updated: 2019/09/08 04:20:44 by jkwayiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/ft_ls.h"


void    get_uid(struct stat filestat, files *node)
{
    pass = getpwuid(filestat.st_uid);
    if (pass)
        node->user = ft_strdup(pass->pw_name);
    //else
     //   node->user = ft_itoa(pass->pw_name);    
}

void   get_guid(struct stat filestat, files *node)
{  
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

/*void    total_blocks(files *node)
{
    int i;
    files   *ptr;

    i = 0;
    ptr = node;
    while (ptr)
    {
        i += ptr->blocks;
        ptr = ptr->next;
    }
    ft_putnbr(i); 
}*/

void  print_blocks(files *node)
{
    files   *num;
    struct stat filestat;
    unsigned long block;

    //node->blocks = filestat.st_blocks;
    block = 0;
    while (num)
    {
        if (!lstat(node->name, &filestat))
            return ;
        block = block + (filestat.st_blocks);
        num = num->next;
    }
    ft_putstr("total ");
    ft_putnbr(block);
    ft_putchar('\n');
}

/*void    total_blocks(struct stat filestat, files *node)
{
    int i;

    i = 0;
    while (node)
    {
        if (node->name[0] != '.')
        i += node->blocks;
        node = node->next;
    }
    //return (i);
    ft_putnbr(i);
    ft_putchar('\n');
}*/
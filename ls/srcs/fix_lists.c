/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwayiba <jkwayiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:19:55 by jkwayiba          #+#    #+#             */
/*   Updated: 2020/05/12 02:30:05 by groovyswa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"


void   items_lst(files *new, struct dirent *dp, char *path)
{
    char        *fullpath;
    char        *path2;
    
    path2 = ft_strjoin(path, "/");
    fullpath = ft_strjoin(path2 , dp->d_name);
    lstat(fullpath, &filestat);
    new->name = ft_strdup(dp->d_name);
    new->links = filestat.st_nlink;
    new->user = get_uid(filestat);
    new->group = get_guid(filestat);
    get_perms(filestat, new);
    new->type = dp->d_type;
    new->mode = filestat.st_mode;
    new->filesize = filestat.st_size;
    new->date = ft_strsub((ctime(&filestat.st_mtime)), 4, 12);
    new->mtime = filestat.st_mtime;
    new->blocks = filestat.st_blocks;
    free(path2);
    free(fullpath);
}

// void    add_list(files **list, struct dirent *dp, char *path)
// {
//     files *new;

//     new = items_lst(dp, path);
//     new->next = *list;
//     *list = new;
// }

// void    clear_list(files **list)
// {
//     files *current;
//     files *next;

// 	current = *list;
//     while (current)
//     {
//         next = current->next;
//         // free(current->name);
//         ft_strdel(&current->name);
//         ft_strdel(&current->date);

//         // free(current->date);
//         // free(current);
//         current = next;
//     }
//     *list = NULL;
// }

// void	reverse_list(files **head)
// {
// 	files *current;
// 	files *previous;
// 	files *next;

// 	next = NULL;
// 	previous = NULL;
// 	current = *head;
// 	while (current != NULL)
// 	{

// 		next = current->next;
// 		current->next = previous;
// 		previous = current;
// 		current = next;
// 	}
// 	*head = previous;
// }

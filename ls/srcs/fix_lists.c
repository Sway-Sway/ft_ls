/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwayiba <jkwayiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:19:55 by jkwayiba          #+#    #+#             */
/*   Updated: 2019/09/03 15:51:39 by jkwayiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"


files   *items_lst(struct dirent *dp, char *path)
{
    files       *new;
    char        *fullpath;
    char        *path2;
    struct stat filestat;
    
    if (!(new = malloc(sizeof(files))))
        return (NULL);
    path2 = ft_strjoin(path, "/"); //maybe use strjoin
    fullpath = ft_strcat(path2 , dp->d_name);
    stat(path2, &filestat);
    new->name = ft_strdup(dp->d_name);
    new->links = filestat.st_nlink;
    get_uid(filestat, new);
    get_guid(filestat, new);
    get_perms(filestat, new);
    new->filesize = filestat.st_size;
    new->date = ft_strsub((ctime(&filestat.st_mtime)), 4, 12);
    //total_blocks(new);
    new->blocks = filestat.st_blocks;
    new->next = NULL;
    free(path2);
    //free(fullpath);
    return (new);
}

void    add_list(files **list, struct dirent *dp, char *path)
{
    files *new;

    new = items_lst(dp, path);
    new->next = *list;
    *list = new;
}

void    clear_list(files *list)
{
    files *head;

    while (list != NULL)
    {
        head = list;
        list = list->next;
        free(head->name);
        free(head->user);        
        free(head);
    }
}
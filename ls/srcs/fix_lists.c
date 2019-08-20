/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwayiba <jkwayiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:19:55 by jkwayiba          #+#    #+#             */
/*   Updated: 2019/08/20 14:33:35 by jkwayiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"


files   *items_lst(struct stat filestat, struct dirent *dp)
{
    files *new;
    struct group *grpss;
    struct passwd *pass;
    
    new = malloc(sizeof(files));
    new->name = ft_strdup(dp->d_name);
    get_uid(filestat, new);
    get_guid(filestat, new);
    get_perms(filestat, new);
    new->filesize = filestat.st_size;
    // new->date = 
    new->next = NULL;
    return (new);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwayiba <jkwayiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 11:01:24 by jkwayiba          #+#    #+#             */
/*   Updated: 2019/09/16 12:46:52 by jkwayiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include "../libft/libft.h"
# include <time.h>
# include <pwd.h>
# include <grp.h>


struct dirent   *dp;
struct stat     filestat;
struct passwd   *pass;
struct group    *grpss;

 typedef struct      files {
    char    *name;
    int     links;
    char    *path;
    char    *user;
    char    *group;
    char    permissions[11];
    int     filesize;
    char    *date;
    int     blocks;
    struct     files   *next;
}   files;


void	listfiles(char *path);
void	listfilesrecursively(char *basepath);
void	longformat(char *path);
void    get_uid(struct stat filestat, files *node);
void    get_guid(struct stat filestat, files *group);
void    get_perms(struct stat filestat, files *files);
void    ft_lstcr(files **first, char *path);
//void    total_blocks(files *node);
void    print_blocks(files *node);
files   *items_lst(struct dirent *dp, char *path);
void    add_list(files **list, struct dirent *dp, char *path);
void    reverse_list(files **head);
void    clear_list(files *list);
void    merge_sort(files **head_ref);
files   *SortedMerge(files *a, files *b);
void    FrontBackSplit(files *source, files **front_ref, files **back_ref);
void    print_dir(files *node);

#endif

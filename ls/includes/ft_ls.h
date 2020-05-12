/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwayiba <jkwayiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 11:01:24 by jkwayiba          #+#    #+#             */
/*   Updated: 2020/05/12 03:55:06 by groovyswa        ###   ########.fr       */
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
# include <errno.h>


struct dirent   *dp;
struct stat     filestat;
struct passwd   *pass;
struct group    *grpss;

typedef struct      files {
    char    *name;
    nlink_t     links;
    char    *path;
    char    *user;
    char    *group;
    char    permissions[11];
    off_t     filesize;
    char    *date;
    time_t	mtime;
    int		type;
    mode_t	mode;
    int     blocks;
    struct     files   *next;
}   files;

void			listfilesrecursively(files *list, char *basepath, unsigned char flags);
void			ft_ls(char *path, unsigned char flags);
void			longformat(files *list);
void			print_list(files *list, unsigned char flags);
void			print_normal(files *list, unsigned char flags);
void			print_output(files *list, unsigned char flags);
int				option_execute(int ac, char **av, unsigned char flags);
char    		*get_uid(struct stat filestat, files *node);
char    		*get_guid(struct stat filestat, files *node);
void    		get_perms(struct stat filestat, files *node);
void			display_blocks(files *ptr, unsigned char flags);
files   		*items_lst(struct dirent *dp, char *path);
void    		add_list(files **list, struct dirent *dp, char *path);
void    		reverse_list(files **head);
void    		clear_list(files **list);
void    		merge_sort(files **head_ref, unsigned char flags);
files   		*SortedMerge(files *a, files *b, unsigned char flags);
files			*SortedMerge_time(files *a, files *b, unsigned int flags);
void    		FrontBackSplit(files *source, files **front_ref, files **back_ref);
int				check_flags(char c);
unsigned char	get_flags2(unsigned char flags);
void			illegal_option(char c);
int				check_if(char c);
unsigned char	option_parser(int ac, char **av);
void			error_handler2(char *path);
void			error_handler_permission(char *path);
void			error_file(char *path);
int				error_handler(char *path, DIR *dp, int ierrno, unsigned int flag);


#endif

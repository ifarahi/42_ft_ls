/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifarahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 10:00:46 by ifarahi           #+#    #+#             */
/*   Updated: 2019/04/25 19:54:42 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include "libft/libft.h"

typedef	struct		s_flags
{
	int				l;
	int				R;
	int				a;
	int				r;
	int				t;
}					t_flags;

typedef struct		s_fileinfo
{
	char			*file_name;
	char			rights[12];
	char			*user_name;
	char			*group_name;
	int				size;
	int				links;
	int				st_time;
	char			*time;
	int				nblock;
	struct	s_fileinfo	*next;
}					t_fileinfo;

char				gettype(const char *path);
int					getperm(const char *path, char *perms);
int					getuser(const char *path, char **user);
int					getgroup(const char *path, char **group);
int					gettime(const char *path, char **time);
int					getsize(const char *path);
int					getnlink(const char *path);
int					getnblock(const char *path);
char				getsetuid(const char *path);
char				getsetgid(const char *path);
char				getsticky(const char *path);
int					stockinfo(const char *path, t_fileinfo **list, char *name);
int					scanforflags(char **av, t_flags *list);					
void				init(t_flags *list);
#endif

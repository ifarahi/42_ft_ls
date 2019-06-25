/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifarahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:33:36 by ifarahi           #+#    #+#             */
/*   Updated: 2019/04/25 16:18:03 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		gettype(const char *path)
{
	struct	stat	statstruct;
	char			type;

	if((stat(path, &statstruct)) < 0)
		return (0);
	if ((statstruct.st_mode & S_IFMT) == S_IFREG)
		type = '-';
	else if ((statstruct.st_mode & S_IFMT) == S_IFIFO)
		type = 'p';
	else if ((statstruct.st_mode & S_IFMT) == S_IFCHR)
		type = 'c';
	else if ((statstruct.st_mode & S_IFMT) == S_IFDIR)
		type = 'd';
	else if ((statstruct.st_mode & S_IFMT) == S_IFBLK)
		type = 'b';
	else if ((statstruct.st_mode & S_IFMT) == S_IFWHT)
		type = '?';
	else if ((statstruct.st_mode & S_IFMT) == S_IFLNK)
		type = 'l';
	else if ((statstruct.st_mode & S_IFMT) == S_IFSOCK)
		type = 's';
	return (type);
}

int			getperm(const char *path, char *perms)
{
	struct	stat	statstruct;

	if ((stat(path, &statstruct)) < 0)
		return (0);
	perms[0] = gettype(path);
	perms[1] = ((statstruct.st_mode & S_IRUSR) ? 'r' : '-');
	perms[2] = ((statstruct.st_mode & S_IWUSR) ? 'w' : '-');
	perms[3] = getsetuid(path);
	perms[4] = ((statstruct.st_mode & S_IRGRP) ? 'r' : '-');
	perms[5] = ((statstruct.st_mode & S_IWGRP) ? 'w' : '-');
	perms[6] = getsetgid(path);
	perms[7] = ((statstruct.st_mode & S_IROTH) ? 'r' : '-');
	perms[8] = ((statstruct.st_mode & S_IWOTH) ? 'w' : '-');
	perms[9] = getsticky(path);
	perms[10] = '\0';
	return (1);
}

int			getuser(const char *path, char **user_name)
{
	struct stat		statstruct;
	struct passwd	*passwdstruct;

	if ((stat(path, &statstruct)) < 0)
		return (0);
	passwdstruct = getpwuid(statstruct.st_uid);
	*user_name = ft_strdup(passwdstruct->pw_name);
	return (1);
}

int			getgroup(const char *path, char **group_name)
{
	struct stat		statstruct;
	struct group	*groupstruct;

	if ((stat(path, &statstruct)) < 0)
		return (0);
	groupstruct = getgrgid(statstruct.st_gid);
	*group_name = ft_strdup(groupstruct->gr_name);
	return (1);
}

int			gettime(const char *path, char **_time)
{
	struct stat		statstruct;
	time_t			secondes;
	char			*tims;
	char			*subptr;

	secondes = time(NULL);
	if ((stat(path, &statstruct)) < 0)
		return (0);
	tims = ctime(&statstruct.st_mtime);
	if ((secondes - statstruct.st_mtime) < 15768000)
	{
		subptr = ft_strsub(tims, 4, 12);
	}
	else
	{
		subptr = ft_strsub(tims, 4, 7);
		ft_strcat(subptr, ft_strsub(tims, 20, 4));
	}
	*_time = ft_strdup(subptr);
	free(subptr);
	return (statstruct.st_mtime);
}

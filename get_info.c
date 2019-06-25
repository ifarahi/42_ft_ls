/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifarahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:33:36 by ifarahi           #+#    #+#             */
/*   Updated: 2019/04/17 12:29:44 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		GetType(const char *path)
{
		struct	stat	statStruct;

		stat(path, &statStruct);
		if (statStruct.st_mode & S_IFMT)
			return ('F');
		else if (statStruct.st_mode & S_IFIFO)
			return ('P');
		else if (statStruct.st_mode & S_IFCHR)
			return ('C');
		else if (statStruct.st_mode & S_IFDIR)
			return ('D');
		else if (statStruct.st_mode & S_IFBLK)
			return ('B');
		else if (statStruct.st_mode & S_IFREG)
			return ('R');
		else if (statStruct.st_mode & S_IFLNK)
			return ('L');
		else if (statStruct.st_mode & S_IFSOCK)
			return ('S');
		else if (statStruct.st_mode & S_IFWHT)
			return ('W');
}

char		*GetPerm(const char *path, char *perms)
{
		struct	stat	statstruct;

		stat(path, &statSruct);
		perms[1] = ((statStruct.st_mode & S_IRUSR) ? 'r' : '-');
		perms[2] = ((statStruct.st_mode & S_IWUSR) ? 'w' : '-');
		perms[3] = ((statStruct.st_mode & S_IXUSR) ? 'x' : '-');
		perms[4] = ((statStruct.st_mode & S_IRGRP) ? 'r' : '-');
		perms[5] = ((statStruct.st_mode & S_IWGRP) ? 'w' : '-');
		perms[6] = ((statStruct.st_mode & S_IXGRP) ? 'x' : '-');
		perms[7] = ((statStruct.st_mode & S_IROTH) ? 'r' : '-');
		perms[8] = ((statStruct.st_mode & S_IWOTH) ? 'w' : '-');
		perms[9] = ((statStruct.st_mode & S_IXOTH) ? 'x' : '-');
		perms[10] = '\0';

		return (perms);
}

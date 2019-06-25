/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifarahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:56:42 by ifarahi           #+#    #+#             */
/*   Updated: 2019/04/22 16:31:50 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				getsize(const char *path)
{
	struct stat		statstruct;

	if ((stat(path, &statstruct)) < 0)
			return (0);
	return (statstruct.st_size);
}

int				getnlink(const char *path)
{
	struct stat		statstruct;

	if ((stat(path, &statstruct)) < 0)
		return (0);
	return (statstruct.st_nlink);
}

int				getnblock(const char *path)
{
	struct stat		statstruct;

	if ((stat(path, &statstruct)) < 0)
		return (0);
	return (statstruct.st_blocks);
}

char			getsetuid(const char *path)
{
	struct stat		statstruct;

	if ((stat(path, &statstruct)) < 0)
		return (0);
	if ((statstruct.st_mode & S_IXUSR) && (statstruct.st_mode & S_ISUID))
		return ('s');
	else if (!(statstruct.st_mode & S_IXUSR) && (statstruct.st_mode & S_ISUID))
		return ('S');
	else if ((statstruct.st_mode & S_IXUSR) && !(statstruct.st_mode & S_ISUID))
		return ('x');
	else
		return ('-');
}

char			getsetgid(const char *path)
{
	struct stat		statstruct;

	if ((stat(path, &statstruct)) < 0)
		return (0);
	if ((statstruct.st_mode & S_IXGRP) && (statstruct.st_mode & S_ISGID))
		return ('s');
	else if (!(statstruct.st_mode & S_IXGRP) && (statstruct.st_mode & S_ISGID))
		return ('S');
	else if ((statstruct.st_mode & S_IXGRP) && !(statstruct.st_mode & S_ISGID))
		return ('x');
	else
		return ('-');
}

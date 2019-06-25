/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifarahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:09:42 by ifarahi           #+#    #+#             */
/*   Updated: 2019/04/25 16:22:09 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			getsticky(const char *path)
{
	struct stat		statstruct;

	if ((stat(path, &statstruct)) < 0)
		return (0);
	if ((statstruct.st_mode & S_IXOTH) && (statstruct.st_mode & S_ISVTX))
		return ('t');
	else if (!(statstruct.st_mode & S_IXOTH) && (statstruct.st_mode & S_ISVTX))
		return ('T');
	else if ((statstruct.st_mode & S_IXOTH) && !(statstruct.st_mode & S_ISVTX))
		return ('x');
	else
		return ('-');
}

int				stockinfo(const char *path, t_fileinfo **list, char *name)
{
	t_fileinfo		*ptr;
	t_fileinfo		*tmp;

	if (!(tmp = (t_fileinfo*)malloc(sizeof(t_fileinfo))))
		return (0);
	getperm(path, tmp->rights);
	tmp->links = getnlink(path);
	getuser(path, &tmp->user_name);
	getgroup(path, &tmp->group_name);
	tmp->size = getsize(path);
	tmp->st_time = gettime(path, &tmp->time);
	tmp->file_name = ft_strdup(name);
	tmp->next = NULL;
	if (*list == NULL)
		*list = tmp;
	else
	{
		ptr = *list;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = tmp;
	}
	return (1);
}

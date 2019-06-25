/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifarahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 10:11:56 by ifarahi           #+#    #+#             */
/*   Updated: 2019/04/25 19:56:47 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
void	create_node(const char *path, t_fileinfo **list, char *name)
{
		t_fileinfo		*ptr;
		t_fileinfo		*tmp;

		tmp = (t_fileinfo*)malloc(sizeof(t_fileinfo));
		getperm(path, tmp->rights);
		tmp->links = getnlink(path);
		getuser(path, tmp->user_name);
		getgroup(path, tmp->group_name);
		tmp->size = getsize(path);
		tmp->st_time = gettime(path, tmp->time);
		ft_strcpy(tmp->file_name,name);
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
}
*/
int			main(int	argc, char	**argv)
{
//	DIR					*dir;
//	struct dirent		*dirstruct;
//	t_fileinfo			*f_info;
//	t_fileinfo			*tmp;
//	char				*path;
//	int					total;
//	t_fileinfo			*p_f_info;
	t_flags				f;
/*
	f_info = NULL;
	dir = opendir(argv[1]);
	while ((dirstruct = readdir(dir)) != NULL)
	{
		ft_strclr(path);
		path = argv[1];
		path = ft_strjoin(argv[1], dirstruct->d_name);
		stockinfo(path, &f_info, dirstruct->d_name);
		total += getnblock(path);
	}
*/
/*	p_f_info = f_info;
	while (p_f_info != NULL)
	{
			printf("%s   %d ", p_f_info->rights, p_f_info->links);
			printf("%s   %s  %d  ", p_f_info->user_name, p_f_info->group_name, p_f_info->size);
			printf("%s  %s  -- %d\n", p_f_info->time, p_f_info->file_name, p_f_info->st_time);
			p_f_info = p_f_info->next;
	}
	*/
	if ((scanforflags(argv, &f)))
		printf("l=%d R=%d a=%d r=%d t=%d", f.l, f.R, f.a, f.r, f.t);

	return 0;	
}

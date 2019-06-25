/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifarahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:32:31 by ifarahi           #+#    #+#             */
/*   Updated: 2019/04/25 19:56:49 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			init(t_flags *list)
{
	list->l = 0;
	list->R = 0;
	list->a = 0;
	list->r = 0;
	list->t = 0;
}

int			scanforflags(char **av, t_flags *list)
{
	int		i;
	int		j;

	init(list);
	i = 1;
	j = 1;
	if (av[1][0] != '-')
		return (0);
	while (av[i])
	{
		while (av[i][j] != '\0' && av[i][0] == '-')
		{
			if (av[i][j] == 'l')
				list->l = 1;
			else if (av[i][j] == 'R')
				list->R = 1;
			else if (av[i][j] == 'a')
				list->a = 1;
			else if (av[i][j] == 'r')
				list->r = 1;
			else if (av[i][j] == 't')
				list->t = 1;
			else
				return (-1);
			j++;
		}
		i++;
	}
	if (j > 1)
		return (1);
	return (0);
}

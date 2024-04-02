/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:07:22 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/04/01 00:35:01 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checking(t_data *st)
{
	int	i;

	close (st->fd);
	i = 0;
	if (!st->res || st->res[ft_strlen(st->res) - 1] == '\n')
		error(st, 2);
	st->s = ft_split(st->res, '\n');
	free ((char *)st->res);
	if (!st->s)
		error(st, 98);
	check_all_map(st);
	check_the_form(st);
	check_f_wall(st);
	check_shape(st);
	initialize(st);
}

void	check_f_wall(t_data *st)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (st->s[i][j])
	{
		if (st->s[i][j++] != '1')
			error(st, 3);
	}
	j = 0;
	while (st->s[i])
		i++;
	i--;
	while (st->s[i][j])
	{
		if (st->s[i][j++] != '1')
			error(st, 3);
	}
}

void	check_all_map(t_data *st)
{
	int	i;
	int	j;

	i = 0;
	while (st->s[i])
	{
		while (st->s[i][j])
		{
			if (st->s[i][j] != '1' && st->s[i][j] != '0' && st->s[i][j] != 'P'
				&& st->s[i][j] != 'E' && st->s[i][j] != 'C')
				error(st, 3);
			j++;
		}
		j = 0;
		i++;
	}
	check_things(st);
}

void	check_the_form(t_data *st)
{
	int	i;
	int	lenght;

	i = 0;
	lenght = ft_strlen(st->s[i++]);
	while (st->s[i])
	{
		if (lenght != ft_strlen(st->s[i++]))
			error(st, 3);
	}
	if (lenght > 40)
		error(st, 7);
	i = 0;
	while (st->s[i])
		i++;
	if (--i > 21)
		error(st, 7);
}

void	check_shape(t_data *st)
{
	int	i;

	i = 1;
	while (st->s[i])
	{
		if (st->s[i][0] != '1' || st->s[i][ft_strlen(st->s[i]) - 1] != '1')
			error(st, 3);
		i++;
	}
}

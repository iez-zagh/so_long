/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 02:04:45 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/31 02:42:10 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_coins(char **s)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	can_reach_all(t_data *st, int x, int y)
{
	if (y < 0 || x < 0 || y >= st->wi || x >= st->hi
		|| st->s2[x][y] == 'X' || st->s2[x][y] == 'E' || st->s2[x][y] == '1')
		return ;
	st->s2[x][y] = 'X';
	can_reach_all(st, x - 1, y);
	can_reach_all(st, x + 1, y);
	can_reach_all(st, x, y - 1);
	can_reach_all(st, x, y + 1);
}

void	initialize(t_data *st)
{
	int		i;
	int		j;

	i = 0;
	while (st->s[i])
	{
		j = 0;
		while (st->s[i][j])
		{
			if (st->s[i][j] == 'P')
			{
				st->player_x = i;
				st->player_y = j;
			}
			else if (st->s[i][j] == 'E')
			{
				st->door_x = i;
				st->door_y = j;
			}
			j++;
		}
		i++;
	}
	create_window(st);
}

void	copying_map(t_data *st)
{
	char	**s2;
	int		i;
	int		j;

	i = 0;
	s2 = malloc((sizeof(char *) * st->hi) + 1);
	if (!s2)
		return ;
	while (st->s[i])
	{
		j = 0;
		s2[i] = malloc(st->wi + 1);
		if (!s2[i])
			error(st, 9);
		while (st->s[i][j])
		{
			s2[i][j] = st->s[i][j];
			j++;
		}
		s2[i][j] = '\0';
		i++;
	}
	s2[i] = NULL;
	st->s2 = s2;
}

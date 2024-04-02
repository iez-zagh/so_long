/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:40:17 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/31 23:15:47 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_things(t_data *st)
{
	int	i;
	int	j;
	int	c;
	int	e;
	int	p;

	i = 0;
	c = 0;
	e = 0;
	p = 0;
	while (st->s[i])
	{
		j = 0;
		while (st->s[i][j])
		{
			if (st->s[i][j] == 'C')
				c++;
			if (st->s[i][j] == 'E')
				e++;
			if (st->s[i][j++] == 'P')
				p++;
		}
		i++;
	}
	check_things2(st, c, e, p);
}

void	check_things2(t_data *st, int c, int e, int p)
{
	if (c == 0 || e == 0 || p == 0 || p > 1 || e > 1)
		error(st, 3);
}

void	ft_free_map(const char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free((char *)s[i]);
		i++;
	}
}

void	create_window(t_data *st)
{
	int	i;

	i = 0;
	st->coins = count_coins((char **)st->s);
	st->wi = ft_strlen((st->s)[0]);
	st->length = st->wi;
	while ((st->s)[i])
		i++;
	st->length = i;
	st->hi = i--;
	copying_map(st);
	can_reach_all(st, st->player_x, st->player_y);
	checking_2(st);
	st->mlx = mlx_init();
	if (!st->mlx)
		error (st, 9);
	st->mlx_win = mlx_new_window(st->mlx, 64 * st->wi, 64 * st->hi, "so_long");
	if (!st->mlx_win)
		error (st, 9);
	create_images(st);
	built_window(st, (const char **)st->s);
}

void	built_window(t_data *st, const char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			put_to_image(st, st->floor, i, j);
			if (s[i][j] == '1')
				put_to_image(st, st->wall, i, j);
			else if (s[i][j] == 'C')
				put_to_image(st, st->coin, i, j);
			else if (s[i][j] == 'P')
				put_to_image(st, st->player1, i, j);
			else if (s[i][j] == 'E')
				put_to_image(st, st->door, i, j);
			j++;
		}
		i++;
	}
	write(1, "[0]\n", 4);
	take_updates(st);
	mlx_loop(st->mlx);
}

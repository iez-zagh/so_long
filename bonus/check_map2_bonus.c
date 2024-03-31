/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:40:17 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/31 01:52:03 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_things(t_data *st)
{
	int	c;
	int	e;
	int	p;

	c = 0;
	e = 0;
	p = 0;
	counting(st, c, e, p);
}

void	check_things2(t_data *st, int c, int e, int p)
{
	if (c == 0 || e == 0 || p == 0 || p > 1 || e > 1)
		error(st, 3);
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
	get_frames(st);
	built_window(st);
	mlx_loop(st->mlx);
}

void	built_window(t_data *st)
{
	put_images(st);
	take_updates(st);
	mlx_loop_hook(st->mlx, &idle, st);
}

void	put_images(t_data *st)
{
	int	i;
	int	j;

	i = 0;
	while (st->s[i])
	{
		j = 0;
		while (st->s[i][j])
		{
			put_to_image(st, st->floor, i, j);
			if (st->s[i][j] == '1')
				put_to_image(st, st->wall, i, j);
			else if (st->s[i][j] == 'P')
				put_to_image(st, st->player1, i, j);
			else if (st->s[i][j] == 'C')
				put_to_image(st, st->coin, i, j);
			else if (st->s[i][j] == 'E')
				put_to_image(st, st->door, i, j);
			else if (st->s[i][j] == 'N')
				put_to_image(st, st->enemy, i, j);
			j++;
		}
		i++;
	}
	put_banner(st);
}

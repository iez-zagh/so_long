/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:55:53 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/31 03:22:48 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	go_right_e(t_data *st, int *i, int *j)
{
	if (st->s[*i][*j + 1] == '1' || st->s[*i][*j + 1] == 'C'
		|| st->s[*i][*j + 1] == 'E' || st->s[*i][*j + 1] == 'N')
	{
		st->flag_move = false;
		return ;
	}
	if (st->s[*i][*j + 1] == 'P')
		error(st, 8);
	put_to_image(st, st->floor, *i, *j);
	st->s[*i][*j] = '0';
	(*j)++;
	st->s[*i][*j] = 'N';
	put_to_image(st, st->floor, *i, *j);
	put_to_image(st, st->enemy, *i, *j);
}

void	go_left_e(t_data *st, int *i, int *j)
{
	if (st->s[*i][*j - 1] == '1' || st->s[*i][*j - 1] == 'C'
		|| st->s[*i][*j - 1] == 'E' || st->s[*i][*j - 1] == 'N')
	{
		st->flag_move = true;
		return ;
	}
	if (st->s[*i][*j - 1] == 'P')
		error(st, 8);
	put_to_image(st, st->floor, *i, *j);
	st->s[*i][*j] = '0';
	(*j)--;
	st->s[*i][*j] = 'N';
	put_to_image(st, st->floor, *i, *j);
	put_to_image(st, st->enemy2, *i, *j);
}

int	right_idle(t_data *st)
{
	static int	i = 0;
	static int	g = 0;

	if (g == 700)
	{
		if (i == 10)
			i = 0;
		st->h = i + 48;
		st->d_[10] = st->h;
		st->d_[16] = '\0';
		i++;
		put_to_image(st, st->floor, st->player_x, st->player_y);
		st->image = mlx_xpm_file_to_image(st->mlx, st->d_, &(st->k), &(st->k));
		if (!st->image)
			error(st, 5);
		put_to_image(st, st->image, st->player_x, st->player_y);
		g = 0;
	}
	g++;
	return (0);
}

void	put_banner(t_data *st)
{
	mlx_put_image_to_window(st->mlx, st->mlx_win, st->cadre, 0, 0);
	mlx_string_put(st->mlx, st->mlx_win, 64, 24, 0x0A1FD1, "0");
}

void	error2(t_data *st, int y)
{
	if (y == 8)
	{
		write(1, "GAME OVER !\n", 12);
		destroy_images(st);
	}
	else if (y == 9)
	{
		write(1, "malloc or mlx failure\n", 15);
		destroy_images(st);
	}
}

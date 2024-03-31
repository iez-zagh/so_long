/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idle_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 02:33:57 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/30 15:06:48 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	left_idle(t_data *st)
{
	static int	g = 0;
	static int	i = 0;

	if (g == 700)
	{
		if (i == 10)
			i = 0;
		st->h = i + 48;
		st->d2_[12] = st->h;
		st->d2_[18] = '\0';
		i++;
		put_to_image(st, st->floor, st->player_x, st->player_y);
		st->image = mlx_xpm_file_to_image(st->mlx, st->d2_, &(st->k), &(st->k));
		if (!st->image)
			error(st, 5);
		put_to_image(st, st->image, st->player_x, st->player_y);
		g = 0;
	}
	g++;
	return (0);
}

int	check_c_e(t_data *st, int i, int j)
{
	if (st->s[i][j] == 'N')
	{
		write(1, "GAME OVER !\n", 12);
		destroy_images(st);
		exit (1);
	}
	if (st->s[i][j] == 'C')
	{
		st->s[i][j] = '0';
		st->coins--;
	}
	if ((st->s[i][(j)] == 'E' && st->coins)
		|| st->s[i][(j)] == '1')
	{
		return (1);
	}
	return (0);
}

void	get_enemy(t_data *st)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = 0;
	while (st->s[i])
	{
		j = 0;
		while (st->s[i][j])
		{
			if (st->s[i][j] == 'N')
			{
				st->tab_x[k] = i;
				st->tab_y[k] = j;
				k++;
			}
			j++;
		}
		i++;
	}
	st->tab_x[k] = 0;
	st->tab_y[k] = 0;
}

int	move_enemy(t_data *st)
{
	int			i;
	static int	j = 0;

	i = 0;
	if (j == 5000)
	{
		while (st->tab_x[i])
		{
			if (st->flag_move)
				go_right_e(st, &st->tab_x[i], &st->tab_y[i]);
			else
				go_left_e(st, &st->tab_x[i], &st->tab_y[i]);
			i++;
		}
		j = 0;
	}
	j++;
	return (0);
}

void	idle2(t_data *st)
{
	static int	g = 0;

	if (!st->flag2)
	{
		if (g == 1700)
		{
			st->flag2 = true;
			g = 0;
		}
		g++;
		return ;
	}
	if (!st->flag)
		left_idle(st);
	else
		right_idle(st);
}

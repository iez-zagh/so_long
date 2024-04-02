/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:52:45 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/31 18:11:34 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	go_down(t_data *st)
{
	if (check_c_e(st, st->player_x + 1, st->player_y))
		return ;
	put_to_image(st, st->floor, st->player_x, st->player_y);
	st->s[st->player_x][st->player_y] = '0';
	st->player_x++;
	check_end(st);
	st->s[st->player_x][st->player_y] = 'P';
	put_to_image(st, st->floor, st->player_x, st->player_y);
	put_to_image(st, st->player1, st->player_x, st->player_y);
	inst(st);
}

void	go_up(t_data *st)
{
	if (check_c_e(st, st->player_x - 1, st->player_y))
		return ;
	put_to_image(st, st->floor, st->player_x, st->player_y);
	st->s[st->player_x][st->player_y] = '0';
	st->player_x--;
	check_end(st);
	st->s[st->player_x][st->player_y] = 'P';
	put_to_image(st, st->floor, st->player_x, st->player_y);
	put_to_image(st, st->player1, st->player_x, st->player_y);
	inst(st);
}

void	go_right(t_data *st)
{
	static int	i = 1;

	if (check_c_e(st, st->player_x, st->player_y + 1))
		return ;
	st->n = i + 48;
	i++;
	if (i == 8)
		i = 1;
	st->d[9] = st->n;
	st->player1 = mlx_xpm_file_to_image(st->mlx, st->d, &(st->k), &(st->k));
	if (!st->player1)
		error(st, 5);
	st->s[st->player_x][st->player_y] = '0';
	put_to_image(st, st->floor, st->player_x, st->player_y);
	st->player_y++;
	check_end(st);
	st->s[st->player_x][st->player_y] = 'P';
	put_to_image(st, st->floor, st->player_x, st->player_y);
	put_to_image(st, st->player1, st->player_x, st->player_y);
	st->flag = true;
	st->player1 = mlx_xpm_file_to_image(st->mlx,
			"./tex/idle0.xpm", &(st->k), &(st->k));
	if (!st->player1)
		error(st, 5);
	inst(st);
}

void	checking_2(t_data *st)
{
	int	i;
	int	j;

	i = 0;
	while (st->s2[i])
	{
		j = 0;
		while (st->s2[i][j])
		{
			if (st->s2[i][j] == 'C')
				error(st, 4);
			j++;
		}
		i++;
	}
	i = st->door_x;
	j = st->door_y;
	if (st->s2[i + 1][j] != 'X' && st->s2[i - 1][j] != 'X'
		&& st->s2[i][j + 1] != 'X' && st->s2[i][j - 1] != 'X')
		error(st, 4);
}

void	get_frames(t_data *st)
{
	static char	d[14] = "./tex/run0.xpm";
	static char	d2[17] = "./tex/run_l0.xpm";
	static char	d_[17] = "./tex/idle0.xpm";
	static char	d2_[19] = "./tex/idle_l0.xpm";

	st->tab_x = malloc (sizeof(int) * st->enemy_c + 1);
	st->tab_y = malloc (sizeof(int) * st->enemy_c + 1);
	if (!st->tab_x || !st->tab_y)
		error(st, 9);
	get_enemy(st);
	st->d = d;
	st->d2 = d2;
	st->d_ = d_;
	st->d2_ = d2_;
	st->flag = true;
	st->flag_move = true;
}

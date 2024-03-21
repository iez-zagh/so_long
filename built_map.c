/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 00:59:27 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/21 01:13:02 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_to_image(t_data *st, void *image, int i, int j)
{
	mlx_put_image_to_window(st->mlx, st->mlx_win, image, j * 64, i * 64);
}

int	key_hook(int keycode, t_data *st)
{
	if (keycode == 53)
	{
		mlx_destroy_window(st->mlx, st->mlx_win);
		exit (0);
	}
	else if (keycode == 0 || keycode == 123)
		go_left(st);
	else if (keycode == 1 || keycode == 125)
		go_down(st);
	else if (keycode == 2 || keycode == 124)
		go_right(st);
	else if (keycode == 13 || keycode == 126)
		go_up(st);
	if (st->coins == 0)
		put_to_image(st, st->door2, st->door_x, st->door_y);
	return (0);
}

int	exit_program(void *st)
{
	st = (t_data *)st;
	free (st);
	exit (0);
}

void	take_updates(t_data *st)
{
	mlx_hook(st->mlx_win, 17, 0, exit_program, st);
	mlx_hook(st->mlx_win, 2, 0, &key_hook, st);
}

void	go_left(t_data *st)
{
	int	k;

	k = 1;
	if (st->s[st->player_x][st->player_y - 1] == 'C')
	{
		st->s[st->player_x][st->player_y - 1] = '0';
		st->coins--;
	}
	if ((st->s[st->player_x][(st->player_y - 1)] == 'E' && st->coins)
		|| st->s[st->player_x][(st->player_y - 1)] == '1')
		return ;
	put_to_image(st, st->floor, st->player_x, st->player_y);
	st->player_y--;
	put_to_image(st, st->player2, st->player_x, st->player_y);
	st->player1 = mlx_xpm_file_to_image(st->mlx, "./tex/ghost22.xpm", &k, &k);
	if (st->coins == 0 && st->s[st->player_x][st->player_y] == 'E')
		exit(0);
}

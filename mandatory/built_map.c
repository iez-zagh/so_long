/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 00:59:27 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/31 02:50:42 by iez-zagh         ###   ########.fr       */
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
		exit_(st);
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

void	take_updates(t_data *st)
{
	mlx_hook(st->mlx_win, 17, 0, &exit_, st);
	mlx_hook(st->mlx_win, 2, 0, &key_hook, st);
}

int	exit_(t_data *st)
{
	destroy_images(st);
	write(1, "program terminated\n", 19);
	exit(0);
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
	inst();
	st->player1 = mlx_xpm_file_to_image(st->mlx, "./tex/idle_l0.xpm", &k, &k);
	put_to_image(st, st->floor, st->player_x, st->player_y);
	st->player_y--;
	put_to_image(st, st->floor, st->player_x, st->player_y);
	put_to_image(st, st->player2, st->player_x, st->player_y);
	if (st->coins == 0 && st->s[st->player_x][st->player_y] == 'E')
	{
		destroy_images(st);
		write(1, "CONGRATS YOU WON!!\n", 20);
		exit(0);
	}
}

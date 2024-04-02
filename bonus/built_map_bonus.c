/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 00:59:27 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/31 23:12:25 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_to_image(t_data *st, void *image, int i, int j)
{
	if ((mlx_put_image_to_window(st->mlx,
				st->mlx_win, image, j * 64, i * 64) == 1))
		error(st, 5);
}

int	key_hook(int keycode, t_data *st)
{
	int	i;

	i = 0;
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
	while (i < 20900000)
		i++;
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
	static int	i = 1;

	if (check_c_e(st, st->player_x, st->player_y - 1))
		return ;
	st->n = i + 48;
	i++;
	if (i == 8)
		i = 1;
	st->d2[11] = st->n;
	st->player1 = mlx_xpm_file_to_image(st->mlx, st->d2, &(st->k), &(st->k));
	if (!st->player1)
		error(st, 5);
	put_to_image(st, st->floor, st->player_x, st->player_y);
	st->s[st->player_x][st->player_y] = '0';
	st->player_y--;
	check_end(st);
	st->s[st->player_x][st->player_y] = 'P';
	put_to_image(st, st->floor, st->player_x, st->player_y);
	put_to_image(st, st->player1, st->player_x, st->player_y);
	st->flag = false;
	st->player1 = mlx_xpm_file_to_image(st->mlx,
			"./tex/idle_l0.xpm", &(st->k), &(st->k));
	if (!st->player1)
		error(st, 5);
	inst(st);
}

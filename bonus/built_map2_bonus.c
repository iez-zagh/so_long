/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_map2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:21:04 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/04/01 00:37:47 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	create_images(t_data *st)
{
	int	k;

	k = 1;
	st->wall = mlx_xpm_file_to_image(st->mlx, "./tex/tiles.xpm", &k, &k);
	st->cadre = mlx_xpm_file_to_image(st->mlx, "./tex/cadre.xpm", &k, &k);
	st->floor = mlx_xpm_file_to_image(st->mlx, "./tex/floor5.xpm", &k, &k);
	st->coin = mlx_xpm_file_to_image(st->mlx, "./tex/heart000.xpm", &k, &k);
	st->player1 = mlx_xpm_file_to_image(st->mlx, "./tex/idle0.xpm", &k, &k);
	st->player2 = mlx_xpm_file_to_image(st->mlx, "./tex/idle_l0.xpm", &k, &k);
	st->door = mlx_xpm_file_to_image(st->mlx, "./tex/door.xpm", &k, &k);
	st->door2 = mlx_xpm_file_to_image(st->mlx, "./tex/door5.xpm", &k, &k);
	st->enemy = mlx_xpm_file_to_image(st->mlx, "./tex/e_idle0.xpm", &k, &k);
	st->enemy2 = mlx_xpm_file_to_image(st->mlx, "./tex/e_idle_l0.xpm", &k, &k);
	if (!st->wall || !st->floor || !st->coin || !st->player1 || !st->player2
		|| !st->door || !st->door2 || !st->enemy || !st->enemy2 || !st->cadre)
		error(st, 5);
}

void	destroy_images(t_data *st)
{
	if (st->wall)
		mlx_destroy_image(st->mlx, st->wall);
	if (st->coin)
		mlx_destroy_image(st->mlx, st->coin);
	if (st->floor)
		mlx_destroy_image(st->mlx, st->floor);
	if (st->player1)
		mlx_destroy_image(st->mlx, st->player1);
	if (st->player2)
		mlx_destroy_image(st->mlx, st->player2);
	if (st->door)
		mlx_destroy_image(st->mlx, st->door);
	if (st->door2)
		mlx_destroy_image(st->mlx, st->door2);
	if (st->enemy)
		mlx_destroy_image(st->mlx, st->enemy);
	if (st->enemy2)
		mlx_destroy_image(st->mlx, st->enemy2);
	if (st->cadre)
		mlx_destroy_image(st->mlx, st->cadre);
	mlx_destroy_window(st->mlx, st->mlx_win);
}

void	check_end(t_data *st)
{
	if (!st->coins && st->s[st->player_x][st->player_y] == 'E')
	{
		destroy_images(st);
		write(1, "CONGRATS YOU WON!!\n", 20);
		exit(0);
	}
	st->flag2 = false;
}

int	idle(t_data *st)
{
	idle2(st);
	move_enemy(st);
	return (0);
}

void	check_ext2(char *s)
{
	int	i;
	int	flag;

	i = ft_strlen(s);
	flag = 0;
	i--;
	if (s[i] != 'r')
		flag++;
	i--;
	if (s[i] != 'e')
		flag++;
	i--;
	if (s[i] != 'b')
		flag++;
	i--;
	if (s[i] != '.')
		flag++;
	if (flag)
	{
		write (2, "wrong extention\n", 16);
		exit (1);
	}
}

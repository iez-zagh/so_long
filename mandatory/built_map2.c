/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:21:04 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/31 02:52:33 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_images(t_data *st)
{
	int	k;

	k = 1;
	st->wall = mlx_xpm_file_to_image(st->mlx, "./tex/tiles.xpm", &k, &k);
	st->floor = mlx_xpm_file_to_image(st->mlx, "./tex/floor5.xpm", &k, &k);
	st->coin = mlx_xpm_file_to_image(st->mlx, "./tex/heart000.xpm", &k, &k);
	st->player1 = mlx_xpm_file_to_image(st->mlx, "./tex/idle0.xpm", &k, &k);
	st->player2 = mlx_xpm_file_to_image(st->mlx, "./tex/idle_l0.xpm", &k, &k);
	st->door = mlx_xpm_file_to_image(st->mlx, "./tex/door.xpm", &k, &k);
	st->door2 = mlx_xpm_file_to_image(st->mlx, "./tex/door5.xpm", &k, &k);
	if (!st->wall || !st->floor || !st->coin || !st->player1
		|| !st->player2 || !st->door || !st->door2)
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
	mlx_destroy_window(st->mlx, st->mlx_win);
}

void	ft_putnbr(unsigned long long n)
{
	if (n < 10)
	{
		n = n + '0';
		write(1, &n, 1);
	}
	else
	{
		ft_putnbr((n / 10));
		ft_putnbr((n % 10));
	}
}

void	inst(void)
{
	static size_t	i = 0;

	write(1, "[", 1);
	ft_putnbr(++i);
	write(1, "]\n", 2);
}

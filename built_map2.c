/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:21:04 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/21 22:50:48 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_images(t_data *st)
{
	int	k;

	k = 1;
	st->wall = mlx_xpm_file_to_image(st->mlx, "./tex/tiles.xpm", &k, &k);
	st->floor = mlx_xpm_file_to_image(st->mlx, "./tex/floor5.xpm", &k, &k);
	st->coin = mlx_xpm_file_to_image(st->mlx, "./tex/good_heart.xpm", &k, &k);
	st->player1 = mlx_xpm_file_to_image(st->mlx, "./tex/ghost1.xpm", &k, &k);
	st->player2 = mlx_xpm_file_to_image(st->mlx, "./tex/ghost22.xpm", &k, &k);
	st->door = mlx_xpm_file_to_image(st->mlx, "./tex/door.xpm", &k, &k);
	st->door2 = mlx_xpm_file_to_image(st->mlx, "./tex/door5.xpm", &k, &k);
	if (!st->wall || !st->floor || !st->coin || st->player1 || !st->player2
		|| !st->door || !st->door2)
		error (st, 5);
}
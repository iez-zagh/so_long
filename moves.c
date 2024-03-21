/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:52:45 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/21 15:12:33 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	go_down(t_data *st)
{
	if (st->s[st->player_x + 1][st->player_y] == 'C')
	{
		st->s[st->player_x + 1][st->player_y] = '0';
		st->coins--;
	}
	if ((st->s[st->player_x + 1][(st->player_y)] == 'E' && st->coins)
		|| st->s[st->player_x + 1][(st->player_y)] == '1')
		return ;
	put_to_image(st, st->floor, st->player_x, st->player_y);
	st->player_x++;
	put_to_image(st, st->player1, st->player_x, st->player_y);
	if (st->coins == 0 && st->s[st->player_x][st->player_y] == 'E')
		exit(0);
}

void	go_up(t_data *st)
{
	if (st->s[st->player_x - 1][st->player_y] == 'C')
	{
		st->s[st->player_x - 1][st->player_y] = '0';
		st->coins--;
	}
	if ((st->s[st->player_x - 1][(st->player_y)] == 'E' && st->coins)
		|| st->s[st->player_x - 1][(st->player_y)] == '1')
		return ;
	put_to_image(st, st->floor, st->player_x, st->player_y);
	st->player_x--;
	put_to_image(st, st->player1, st->player_x, st->player_y);
	if (st->coins == 0 && st->s[st->player_x][st->player_y] == 'E')
		exit(0);
}

void	go_right(t_data *st)
{
	int	k;

	k = 1;
	if (st->s[st->player_x][st->player_y + 1] == 'C')
	{
		st->s[st->player_x][st->player_y + 1] = '0';
		st->coins--;
	}
	if ((st->s[st->player_x][(st->player_y + 1)] == 'E' && st->coins)
		|| st->s[st->player_x][(st->player_y + 1)] == '1')
		return ;
	st->player1 = mlx_xpm_file_to_image(st->mlx, "./tex/ghost1.xpm", &k, &k);
	put_to_image(st, st->floor, st->player_x, st->player_y);
	st->player_y++;
	put_to_image(st, st->player1, st->player_x, st->player_y);
	if (st->coins == 0 && st->s[st->player_x][st->player_y] == 'E')
		exit(0);
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

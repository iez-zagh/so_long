/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:45:00 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/21 22:52:36 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	f(void)
{
	system ("leaks so_long");
}

int	main(int ac, char **av)
{
	t_data	*st;

	st = malloc(sizeof(t_data));
	if (!st)
		return (1);
	st->res = NULL;
	if (ac == 1)
		exit(0);
	if (ac > 2)
		exit(1);
	st->fd = open(av[1], O_RDONLY);
	if (st->fd == -1)
		error(st, 1);
	while (1)
	{
		st->line = get_next_line(st->fd);
		if (!st->line)
			break ;
		if (st->line[0] == '\n')
			error(st, 2);
		st->res = ft_strjoin(st->res, st->line);
		free (st->line);
	}
	checking(st);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	error(t_data *st, int y)
{
	if (y == 3 || y == 2)
		write(2, "there is some thing wrong in the map file!!\n", 44);
	if (y == 1)
		write(2, "can't reach the map file !!\n", 28);
	else if (y == 2)
	{
		free(st->line);
		free ((char *)st->res);
	}
	else if (y == 3)
	{
		free_splited(st->s);
		// free ((char *)st->s);
	}
	else if (y == 4)
	{
		free(st->s2);
	}
	else if (y == 5)
	{
		write (1, "there an issue in creating textures !!", 38);
		free_splited(st->s);
		free_splited(st->s2);
	}
	free (st);
	while (1);
	// exit (1);
}

void	free_splited(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free (s);
}
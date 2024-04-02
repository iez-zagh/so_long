/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:45:00 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/04/01 00:34:52 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	check_ext(av[1]);
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

void	error(t_data *st, int y)
{
	if (y == 1)
		write (2, "can't found the map file !!\n", 28);
	if (y == 3 || y == 2)
		write(2, "there is some thing wrong in the map file!!\n", 44);
	else if (y == 4)
		write (2, "there is some thing not reachable in the map !!\n", 48);
	else if (y == 5)
	{
		write (1, "there is an issue in creating textures !!\n", 42);
		destroy_images(st);
	}
	else if (y == 7)
		write (2, "the map it's too big for this screen", 37);
	exit (1);
}

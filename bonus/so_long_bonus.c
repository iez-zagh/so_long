/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:45:00 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/04/01 00:38:16 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	t_data	*st;

	st = malloc(sizeof(t_data));
	if (!st)
		error(st, 9);
	st->res = NULL;
	if (ac == 1)
		exit(0);
	if (ac > 2)
		exit(1);
	check_ext2(av[1]);
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
		free(st->line);
	}
	checking(st);
}

void	error(t_data *st, int y)
{
	if (y == 1)
		write(1, "can't found the map file !!\n", 28);
	if (y == 3 || y == 2)
		write(2, "there is some thing wrong in the map file!!\n", 44);
	else if (y == 4)
		write(1, "there is some thing not reachable in the map !!\n", 48);
	else if (y == 5)
	{
		write(1, "there is an issue in creating textures !!\n", 42);
		destroy_images(st);
	}
	else if (y == 7)
		write(1, "the map it's too big for this screen", 37);
	else
		error2(st, y);
	exit(1);
}

void	counting(t_data *st, int c, int e, int p)
{
	int	i;
	int	j;

	i = 0;
	st->enemy_c = 0;
	while (st->s[i])
	{
		j = 0;
		while (st->s[i][j])
		{
			if (st->s[i][j] == 'C')
				c++;
			if (st->s[i][j] == 'E')
				e++;
			if (st->s[i][j] == 'P')
				p++;
			if (st->s[i][j++] == 'N')
				st->enemy_c++;
		}
		i++;
	}
	check_things2(st, c, e, p);
}

void	inst(t_data *st)
{
	static size_t	i = 0;
	char			*n;

	n = ft_itoa(++i, st);
	put_to_image(st, st->wall, 0, 0);
	if ((mlx_put_image_to_window(st->mlx, st->mlx_win, st->cadre, 0, 0) == -1))
		error(st, 5);
	if ((mlx_string_put(st->mlx, st->mlx_win, 64, 24, 0x0A1FD1, n) == -1))
		error(st, 5);
	free(n);
}

char	*ft_itoa(size_t i, t_data *st)
{
	int		counter;
	size_t	nbr;
	char	*str;

	nbr = i;
	counter = 0;
	while (nbr)
	{
		nbr /= 10;
		counter++;
	}
	str = malloc(counter + 1);
	if (!str)
		error(st, 9);
	str[counter] = '\0';
	while (counter)
	{
		str[--counter] = i % 10 + '0';
		i /= 10;
	}
	return (str);
}

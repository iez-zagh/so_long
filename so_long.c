/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:45:00 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/14 13:47:24 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	int		fd;
	// char	*res;

	if (ac == 1)
		exit (0);
	if (ac > 2)
		exit (1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("can't reach the map file !!\n");
		exit (1);
	}
	// res = get_next_line(fd);
	// printf("%s\n", res);
}
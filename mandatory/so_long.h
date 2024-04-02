/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:45:27 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/04/01 00:31:53 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <mlx.h>

typedef struct s_data
{
	int		fd;
	char	*line;
	char	*res;
	int		door_x;
	int		door_y;
	int		coins;
	char	**s;
	char	**s2;
	int		player_x;
	int		player_y;
	void	*floor;
	void	*wall;
	void	*player1;
	void	*player2;
	void	*coin;
	void	*door;
	void	*door2;
	int		wi;
	int		hi;
	int		length;
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
}				t_data;

void	check_the_form(t_data *st);
void	check_f_wall(t_data *st);
char	**ft_split(char *s, char c);
char	**fill(char *str, char **p, char c, int num_words);
char	**ft_free(char **p, int j);
void	ft_int(int *a, int *b, int *c);
int		count_count(char *str, char c);
void	checking(t_data *st);
char	*ft_one_line(char *str, int j);
char	*check(char **buffer, int j);
char	*end_or_inv(int u, char **buffer);
char	*ft_read(int fd, char **buffer, char *str);
char	*get_next_line(int fd);
int		ft_strlen(const char *str);
int		ft_strchr(char *str, char c);
char	*ft_strjoin(const char *s1, char *s2);
char	*ft_substr(const char *s, int start, int len);
char	*ft_strdup(char *str);
void	check_all_map(t_data *st);
void	check_shape(t_data *st);
void	check_things(t_data *st);
void	check_things2(t_data *st, int c, int e, int p);
void	ft_free_map(const char **s);
void	create_window(t_data *st);
void	built_window(t_data *my_struct, const char **s);
void	put_to_image(t_data *st, void *image, int i, int j);
int		key_hook(int keycode, t_data *st);
void	take_updates(t_data *st);
void	go_left(t_data *st);
void	go_down(t_data *st);
void	go_right(t_data *st);
void	go_up(t_data *st);
int		exit_(t_data *st);
int		count_coins(char **s);
void	can_reach_all(t_data *st, int y, int x);
void	initialize(t_data *st);
void	copying_map(t_data *st);
void	checking_2(t_data *st);
void	error(t_data *st, int y);
void	create_images(t_data *st);
void	destroy_images(t_data *st);
void	ft_putnbr(size_t n);
void	inst(void);
void	check_ext(char *s);

#endif

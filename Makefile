NAME = so_long
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
CC = cc

M_SOURCES = so_long.c get_next_line_utils.c get_next_line.c ft_split.c check_map.c check_map2.c \
			built_map.c moves.c helper_function.c built_map2.c

M_OBJECTS = ${M_SOURCES:.c=.o}

%.o : %.c so_long.h
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(M_OBJECTS)
	@$(CC) $(M_OBJECTS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	@rm -rf $(M_OBJECTS)
fclean : clean
	@rm -rf $(NAME)
re : fclean all
.PHONY : clean
NAME = so_long
BONUS = so_long_bonus
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -fsanitize=address #here
CC = cc
MANDATORY_DIR = mandatory
BONUS_DIR = bonus

M_SOURCES = $(wildcard $(MANDATORY_DIR)/*.c)
B_SOURCES = $(wildcard $(BONUS_DIR)/*_bonus.c)

M_OBJECTS = ${M_SOURCES:.c=.o}
B_OBJECTS = ${B_SOURCES:.c=.o}

%.o : %.c $(MANDATORY_DIR)/so_long.h
	@$(CC) $(CFLAGS) -c $< -o $@

%.o : %.c $(BONUS_DIR)/so_long_bonus.h
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(M_OBJECTS)
	@$(CC) $(M_OBJECTS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus : $(BONUS)

$(BONUS) : $(B_OBJECTS)
	@$(CC) $(B_OBJECTS) -lmlx -framework OpenGL -framework AppKit -o $(BONUS)

clean :
	@rm -rf $(M_OBJECTS)
	@rm -rf $(B_OBJECTS)
fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(BONUS)

re : fclean all
.PHONY : clean

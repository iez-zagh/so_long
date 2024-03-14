NAME = so_long
CFLAGS = -Wall -Wextra -Werror
CC = cc

M_SOURCES = so_long.c get_next_line_utils.c get_next_line.c

M_OBJECTS = ${M_SOURCES:.c=.o}

%.o : %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(M_OBJECTS)
	$(CC) $(CFLAGS) $(M_OBJECTS) -o $(NAME)
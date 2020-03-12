# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blorin <blorin@student.le-101.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/05 20:57:52 by blorin            #+#    #+#              #
#    Updated: 2020/03/06 18:46:12 by blorin           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRC = src/bmp.c\
	src/check_color.c\
	src/check_cub.c\
	src/check_cub2.c\
	src/dda_door.c\
	src/draw.c\
	src/fct.c\
	src/get_next_line.c\
	src/key_gnl.c\
	src/load.c\
	src/main.c\
	src/minimap.c\
	src/move.c\
	src/ray_casting.c\
	src/set_variables.c\
	src/sprite.c\
	src/fct2.c\
	src/tab.c\

LIBFT = libft/libft.a
LIBFT_SRC := $(wildcard libft/*.c)
LIBFT_OBJ := $(patsubst libft/%.c, libft/%.o, $(LIBFT_SRC))

OBJS = ${SRC:.c=.o}

OBJBS = ${SRCB:.c=.o} ${SRC:.c=.o}

NAME = Cub3d

RM = rm -f

CC = gcc

HEADERS = cub3d.h get_next_line.h

CFLAGS = -o -Wall -Wextra -Werror

MLX =  -lmlx -framework OpenGL -framework AppKit -L mlx/

all:	${NAME}

$(LIBFT): $(LIBFT_OBJ)
	ar rcs $(LIBFT) $(LIBFT_OBJ)

libft/%.o: libft/%.c
	gcc -c $< -o $@

$(OBJS): ${HEADERS}

$(OBJBS): ${HEADERS}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) : $(LIBFT) $(OBJS)
		rm -rf Cub3D
		${CC} $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

fclean:		clean
	${RM} ${NAME}
	${RM} save.bmp

clean:
	${RM} src/*.o

re: fclean all

.PHONY:		all clean fclean re
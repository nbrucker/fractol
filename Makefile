#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/20 16:32:28 by nbrucker          #+#    #+#              #
#    Updated: 2018/03/20 16:32:28 by nbrucker         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

LIBFTDIR = libft/

INCSDIR = includes/

SRCSDIR = srcs/

OBJSDIR = objs/

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
		color.c \
		fractol.c \
		init.c \
		lib.c \
		mouse.c

MINILIBXDIR = minilibx/

OBJS = $(addprefix $(OBJSDIR),$(SRCS:.c=.o))

$(OBJSDIR)%.o: $(SRCSDIR)%.c
	@mkdir -p $(OBJSDIR)
	$(CC) $(CFLAGS) -I $(INCSDIR) -I $(LIBFTDIR)$(INCSDIR) -I $(MINILIBXDIR) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	make -C $(MINILIBXDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./libft -lft -L./minilibx -lmlx -framework OpenGL -framework AppKit

clean:
	rm -rf $(OBJSDIR)
	make -C $(LIBFTDIR) clean
	make -C $(MINILIBXDIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFTDIR) fclean
	make -C $(MINILIBXDIR) fclean

re: fclean all

.PHONY: all clean fclean re

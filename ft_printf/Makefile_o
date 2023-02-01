# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgluck <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 18:18:46 by sgluck            #+#    #+#              #
#    Updated: 2023/01/30 15:46:01 by sgluck           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libprintf.a
CFLAGS = -Wall -Wextra -Werror -c -I./libft -L./libft -lft
CC = cc
FLAGS = -I libft -L libft -lft

SRCS	= ft_printf.c formats.c
OBJS	= $(SRCS:.c=.o)

RM = rm -f


all:	$(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	$(CC) ($CFLAGS) $(SRCS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)
	make fclean -C ./libft

re:	fclean $(NAME)



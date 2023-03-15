# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgluck <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 09:31:57 by sgluck            #+#    #+#              #
#    Updated: 2023/02/09 09:32:00 by sgluck           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c \
      formats.c \
      hex.c \
      pointer.c \
      unsigned.c \
      write_ft.c 

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

RM = rm -f

CC = cc
CFLAGS = -Wall -Wextra -Werror  -I. -c

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) 
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

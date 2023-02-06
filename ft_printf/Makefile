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

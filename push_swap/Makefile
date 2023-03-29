# Variables

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRCDIR = src
OBJDIR = obj
BINDIR = bin
TARGET = push_swap

# Source Files
SRC = $(wildcard $(SRCDIR)/*.c)
HDRS = push_swap.h
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Targets
all: $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(BINDIR)/$(TARGET)

re: fclean all

.PHONY: all clean re fclean

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node 
{
	int	data;
	struct	node *next;
	struct	node *prev;
} node;


node *create_node(int data);
void begin_insert(node **head, int data);
void end_insert(node **head, int data);
void print_list(node *head);
int count_numbers(char *string);
int ft_atoi(const char *str);
char *ft_strtok(char *str, char delim);


#endif
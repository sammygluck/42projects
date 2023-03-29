#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct node 
{
	int	data;
	struct	node *next;
	struct	node *prev;
} node;

node *create_node(int data);
node *stack_a_init(char *string, node **head);
void begin_insert(node **head, int data);
void end_insert(node **head, int data);
void print_list(node *head);
void free_list(node *head);
void swap(node **stack);
void sa(node **stack_a);
void sb(node **stack_b);
void ss(node **stack_a, node **stack_b);
void rotate(node **stack);
void ra(node **stack);
void rb(node **stack);
void rr(node **stack_a, node **stack_b);
void reverse_rotate(node **stack);
void rra(node **stack);
void rrb(node **stack);
void rrr(node **stack_a, node **stack_b);
void push(node **stack_a, node **stack_b);
void pa(node **stack_a, node **stack_b);
void pb(node **stack_b, node **stack_a);
int count_numbers(char *string);
int ft_atoi(const char *str);
int	is_sorted(node *head);
char *ft_strtok(char *str, char delim);
int find_min(node *head, int *min_idx);
void move_to_top(node **head, int idx);
int list_size(node *head);
void push_swap_algorithm(node **stack_a, node **stack_b);


#endif

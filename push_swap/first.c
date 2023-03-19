/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:05:18 by sgluck            #+#    #+#             */
/*   Updated: 2023/03/15 18:20:19 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(node **stack)
{
	node	*first;
	node	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void rotate(node **stack)
{
	node	*first;
	node	*second;
	node	*last;

    if (!*stack || !(*stack)->next) 
		return;
    first = *stack;
    second = first->next;
    last = second;
    while (last->next) 
		last = last->next;
    first->next = NULL;
    last->next = first;
    *stack = second;
}

void reverse_rotate(node **stack)
{
	node *prev;
	node *last;

    if (!*stack || !(*stack)->next) return;
    prev = NULL;
    last = *stack;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *stack;
    *stack = last;
}

void push(node **stack_a, node **stack_b)
{
	node *first;

	if (!*stack_a)
		return ;
	first = *stack_a;
	*stack_a = first->next;
	first->next = *stack_b;
	*stack_b = first;
	
	
}

void free_list(node *head)
{
    node *current = head;
    node *next_node;
    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}


node *create_node(int data)
{
	node *new_node = (node *)malloc(sizeof(node));
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void begin_insert(node **head, int data)
{
	node *new_node = create_node(data);
	new_node->next = *head;
	*head = new_node;
}

void end_insert(node **head, int data)
{	
    node *new_node = create_node(data);
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    node *current = *head;
    while (current->next != NULL)
    {    
        current = current->next;
    }
    current->next = new_node;
    
}

void print_list(node *head)
{
    node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int	count_numbers(char *string)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!string)
		return (0);
	while (string[i])
	{
		if (string[i] == 32)
			count++;
		i++;
	}
	count++;
	return (count);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	number;
	int	sign;

	i = 0;
	number = 0;
	sign = 1;
	while ((str[i] > 8 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + str[i] - '0';
		i++;
	}
	return (number * sign);
}


char *ft_strtok(char *str, char delim)
{
    static char *start;
    char *token;

    if (str != NULL)
        start = str;
	if (start == NULL || *start == '\0')
        return (NULL);
	while (*start == delim)
        start++;
	if (*start == '\0')
    {
        start = NULL;
        return (NULL);
    }
	token = start;
	while (*start != '\0' && *start != delim)
        start++;
	if (*start != '\0')
    {
        *start = '\0';
        start++;
    }
    else
        start = NULL;
	return (token);
}

node *stack_a_init(char *string, node **head)
{
	char	*chars;
	int		data;

	*head = NULL;
	chars = ft_strtok(string, ' ');
	while (chars)
	{
		//printf("%s\n", stack1);
		data = ft_atoi(chars);
		end_insert(head, data);
		chars = ft_strtok(NULL, ' ');
	}
	return (*head);
}


int	main(int argc, char **argv)
{
	int		count;
	node	*stack_a;
	node	*stack_b;

	if (argc < 2)
		printf("USAGE: %s <\" string of numbers \">\n", argv[0]);
	count = count_numbers(argv[1]);
	stack_a = stack_a_init(argv[1], &stack_a);
	stack_b = NULL;
	print_list(stack_a);
	print_list(stack_b);
	reverse_rotate(&stack_a);
	print_list(stack_a);
	push(&stack_a, &stack_b);
	print_list(stack_a);
	print_list(stack_b);
	free_list(stack_a);
	free_list(stack_b);

	return (0);
}

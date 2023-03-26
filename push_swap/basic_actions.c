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
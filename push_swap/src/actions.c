#include "push_swap.h"

void sa(node **stack_a)
{
	printf("sa\n");
	swap(stack_a);
	
}

void sb(node **stack_b)
{
	printf("sb\n");
	swap(stack_b);
}

void ss(node **stack_a, node **stack_b)
{
    sa(stack_a);
    sb(stack_b);
}

void pa(node **stack_a, node **stack_b)
{
    printf("pa\n");
    push(stack_b, stack_a);
}

void pb(node **stack_a, node **stack_b)
{
    printf("pb\n");
    push(stack_a, stack_b);
}

void ra(node **stack)
{
    printf("ra\n");
    rotate(stack);
}

void rb(node **stack)
{
    printf("rb\n");
    rotate(stack);
}

void rr(node **stack_a, node **stack_b)
{
    ra(stack_a);
    rb(stack_b);
}

void rra(node **stack)
{
    printf("rra\n");
    reverse_rotate(stack);
}

void rrb(node **stack)
{
    printf("rrb\n");
    reverse_rotate(stack);
}

void rrr(node **stack_a, node **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}


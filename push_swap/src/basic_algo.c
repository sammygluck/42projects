#include "push_swap.h"

int find_min(node *head, int *min_idx)
{
    int min = INT_MAX;
    //int idx = 0;
    int current_idx = 0;
    node *current = head;

    while (current != NULL)
    {
        if (current->data < min)
        {
            min = current->data;
            *min_idx = current_idx;
        }
        current_idx++;
        current = current->next;
    }
    return min;
}

void move_to_top(node **head, int idx)
{
    int size = list_size(*head);

    if (idx <= size / 2)
    {
        for (int i = 0; i < idx; i++)
        {
            ra(head);
        }
    }
    else
    {
        for (int i = 0; i < size - idx; i++)
        {
            rra(head);
        }
    }
}

int list_size(node *head)
{
    int size = 0;
    node *current = head;

    while (current != NULL)
    {
        size++;
        current = current->next;
    }
    return size;
}

void push_swap_algorithm(node **stack_a, node **stack_b)
{
    int min_idx;
    int stack_a_size = list_size(*stack_a);

    while (!is_sorted(*stack_a) || *stack_b != NULL)
    {
        while (*stack_a != NULL)
        {
            find_min(*stack_a, &min_idx);
            move_to_top(stack_a, min_idx);
            pb(stack_a, stack_b);
        }

        for (int i = 0; i < stack_a_size; i++)
        {
            pa(stack_a, stack_b);
        }
    }
}

#include "push_swap.h"

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

int is_sorted(node *head)
{
    node    *current;
    node    *next_node;
    if (head == NULL || head->next == NULL)
        return (1);
    current = head;
    while(current != NULL)
    {
        next_node = current->next;
        if (next_node != NULL && current->data > next_node->data)
            return (0);
        current = next_node;
    }
    return (1);
}
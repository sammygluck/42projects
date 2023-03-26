
#include "push_swap.h"

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
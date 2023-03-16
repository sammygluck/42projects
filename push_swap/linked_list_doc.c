#include <stdio.h>
#include <stdlib.h>
/*We use typedef in the beginning to make sure that we don't need to use the word 'struct' every time we
use anything of that type (struct node *new_node -> node *new_node)*/

typedef struct node {
    int data;
    struct node *next;
} node;

node *create_node(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node; 
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

void delete_node(node **head, int key)
{
    node *current = *head;
    node *prev = NULL;

    if (current != NULL && current->data == key)
    {
        *head = current->next;
        free(current);
        return;
    }
    while (current != NULL && current->data != key)
    {
        prev = current;
        current = current->next;
    }
    if (current == NULL)
        return;
    prev->next = current->next;
    free(current);
}

node *search_node(node *head, int key)
{
    node *current = head;
    while (current != NULL)
    {
        if (current->data == key)
        {
            return (current);
        }
        current = current->next;
    }
    return (NULL);
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

void insert_at_position(node **head, int data, int position)
{
    node *new_node = create_node(data);
    
    if (position == 1)
    {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    node *current = *head;
    node *prev = NULL;
    int current_position = 1;

    while (current != NULL && current_position < position)
    {
        prev = current;
        current = current->next;
        current_position++;
    }
    prev->next = new_node;
    new_node->next = current;
}

int main(void)
{
    node *head = NULL;

    begin_insert(&head, 5);
    begin_insert(&head, 4);
    begin_insert(&head, 3);

    int insert_value = 2;
    int position = 3; 
    printf("Ïnserting %d at position %d.\n", insert_value, position);
    insert_at_position(&head, insert_value, position);
    print_list(head);

    end_insert(&head, 7);
    end_insert(&head, 9);

    printf("Linked list: ");

    int search_value = 5;

    node *found_node = search_node(head, search_value);
    if (found_node)
    {
        printf("Node with value %d found. \n", search_value); 
    }
    else
    {
        printf("Node with value %d not found. \n", search_value);
    }

    int delete_value = 5;
    delete_node(&head, delete_value);
    printf("Linked list after deleting %d: ", delete_value);
    print_list(head);

    free_list(head);

    return(0);
}
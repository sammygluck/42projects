/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:19:17 by sgluck            #+#    #+#             */
/*   Updated: 2023/03/19 14:24:38 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct node 
{
	int	data;
	struct	node *next;
	struct	node *prev;
} node;

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

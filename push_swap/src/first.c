/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:05:18 by sgluck            #+#    #+#             */
/*   Updated: 2023/03/26 12:00:49 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	//int		count;
	node	*stack_a;
	node	*stack_b;

	if (argc < 2)
		printf("USAGE: %s <\" string of numbers \">\n", argv[0]);
	//count = count_numbers(argv[1]);
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

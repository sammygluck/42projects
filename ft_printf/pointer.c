/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:47:31 by sgluck            #+#    #+#             */
/*   Updated: 2023/02/06 15:28:05 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer(unsigned long nbr, int *retn)

{
	if (nbr > 15)
	{
		print_pointer(nbr / 16, retn);
		nbr = nbr % 16;
	}
	write(1, &"0123456789abcdef"[nbr % 16], 1);
	*retn += 1;
}

void	pointer(void *ptr, int *retn)
{
	unsigned long	n;

	if (!ptr)
		ft_putstr("(nil)", retn);
	else
	{
		n = (unsigned long)ptr;
		write(1, "0x", 2);
		*retn += 2;
		print_pointer(n, retn);
	}
}

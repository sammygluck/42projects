/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:47:31 by sgluck            #+#    #+#             */
/*   Updated: 2023/01/30 16:24:09 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	print_hex(size_t nbr)
{	
	if (nbr > 15)
	{
		print_hex(nbr / 16);
		nbr = nbr % 16;
	}
	write(1, &"0123456789abcdef"[nbr % 16], 1);
}

void	pointer(void *ptr)
{
	size_t	n;

	n = (size_t)ptr;
	write(1, "0x", 2);
	print_hex(n);
}

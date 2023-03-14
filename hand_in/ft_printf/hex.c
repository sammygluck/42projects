/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:12:18 by sgluck            #+#    #+#             */
/*   Updated: 2023/02/02 13:11:44 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(unsigned int nbr, int *retn)

{
	if (nbr > 15)
	{
		print_hex(nbr / 16, retn);
		nbr = nbr % 16;
	}
	write(1, &"0123456789abcdef"[nbr % 16], 1);
	*retn += 1;
}

void	print_uhex(unsigned int nbr, int *retn)
{
	if (nbr > 15)
	{
		print_uhex(nbr / 16, retn);
		nbr = nbr % 16;
	}
	write(1, &"0123456789ABCDEF"[nbr % 16], 1);
	*retn += 1;
}

void	ft_hex(unsigned int nbr, char c, int *retn)
{
	unsigned int	n;

	n = nbr;
	if (c == 'x')
		print_hex(n, retn);
	if (c == 'X')
		print_uhex(n, retn);
}

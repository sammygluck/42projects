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

#include "libprintf.h"

void	print_hex(size_t nbr, int *retn)
{
	if (nbr > 15)
	{
		print_hex(nbr / 16);
		nbr = nbr % 16;
	}
	write(1, &"0123456789abcdef"[nbr % 16], 1);
	*retn += 1;
}

void	print_uhex(size_t nbr, int *retn)
{
	if (nbr > 15)
	{
		print_uhex(nbr / 16);
		nbr = nbr % 16;
	}
	write(1, &"0123456789ABCDEF"[nbr % 16], 1);
	*retn += 1;
}

void	ft_hex(int nbr, char c, int *retn)
{
	size_t	n;

	n = (size_t)nbr;
	if (c == 'x')
		print_hex(n, retn);
	if (c == 'X')
		print_uhex(n, retn);
}

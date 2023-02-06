/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:44:33 by sgluck            #+#    #+#             */
/*   Updated: 2023/01/30 16:46:56 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	character(char c, int *retn)
{
	ft_putchar(c, retn);
}

void	string(char *str, int *retn)
{
	ft_putstr(str, retn);
}

void	decimal(int n, int *retn)
{
	ft_putnbr(n, retn);
}

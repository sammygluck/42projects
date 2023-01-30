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

#include <stdio.h>
#include "libprintf.h"

void	character(char c)
{
	ft_putchar_fd(c, 1);
}

void	string(char *str)
{
	ft_putstr_fd(str, 1);
}

void	decimal(int n)
{
	ft_putnbr_fd(n, 1);
}

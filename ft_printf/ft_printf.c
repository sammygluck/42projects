/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 10:57:17 by sgluck            #+#    #+#             */
/*   Updated: 2023/01/30 17:42:55 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"
#include <stdio.h>

void	formats(va_list args, char c)
{
	if (c == 'c')
	{
		character(va_arg(args, int));
	}
	if (c == 's')
	{
		string(va_arg(args, char *));
	}
	if (c == 'p')
	{
		pointer(va_arg(args, void *));
	}
	if (c == 'i' || c == 'd')
	{
		decimal(va_arg(args, int));
	}
	if (c == 'u')
	{
		u_int(var_arg(args, unsigned int));
	}
}

void	ft_printf(int n, char *str, ...)
{
	int		i;
	va_list	ptr;

	va_start(ptr, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			formats(ptr, str[i]);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			i++;
		}
	}
	va_end(ptr);
}

int	main(void)
{
	char	*c;
	void	*d;
	int	a;
	
	a = 12351234;
	c = ft_strdup("world");
	d = &a;

	ft_printf(1, "hello %s %p %i %d \n", c, d, a, a);
	printf("hello %s %p %d %i", c, d, a, a);
}

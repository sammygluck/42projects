/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 10:57:17 by sgluck            #+#    #+#             */
/*   Updated: 2023/02/01 18:42:19 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"
#include <stdio.h>

void	formats(va_list args, char c, int *retn)
{
	if (c == 'c')
		character(va_arg(args, int), retn);
	if (c == 's')
		string(va_arg(args, char *), retn);
	if (c == 'p')
		pointer(va_arg(args, void *), retn);
	if (c == 'i' || c == 'd')
		decimal(va_arg(args, int), retn);
	if (c == 'u')
		u_nbr(va_arg(args, unsigned int), retn);
	if (c == 'x' || c == 'X')
		ft_hex(va_arg(args, int), c, retn);
	if (c == '%')
		ft_putchar('%', retn);
}

int	ft_printf(int n, char *str, ...)
{
	int		i;
	va_list	ptr;
	int	ret_value;
	int 	*retn;

	re_value = 0;
	retn = &ret_value;

	va_start(ptr, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			formats(ptr, str[i], retn);
			i++;
		}
		else
		{
			ft_putchar(str[i], retn);
			i++;
		}
	}
	va_end(ptr);
	return (ret_value);
}

int	main(void)
{
	char	*c;
	void	*d;
	int	a;
	char	b;

	a = 31;
	b = 'h';
	c = ft_strdup("world");
	d = &a;
	ft_printf(1, "hello %s %p %x %X %% \n", c, d, b, b);
	printf("hello %s %p %x %X %%", c, d, b, b);
}

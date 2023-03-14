/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:37:13 by sgluck            #+#    #+#             */
/*   Updated: 2023/01/22 17:01:47 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length(int nb)
{
	int	l;

	l = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		l++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		l++;
	}
	return (l);
}

static char	*exception(int n)
{
	char	*str;

	if (n == -2147483648)
	{
		str = (char *)malloc(12 * sizeof(char));
		if (!str)
			return (NULL);
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	else
	{
		str = (char *)malloc(2 * sizeof(char));
		if (!str)
			return (NULL);
		ft_strlcpy(str, "0", 2);
		return (str);
	}
}

char	*ft_itoa(int n)
{
	int			len;
	int			sign;
	char		*result;

	sign = 1;
	if (n == -2147483648 || n == 0)
		return (exception(n));
	len = length(n);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (n < 0)
		sign = -1;
	result[len] = '\0';
	while (len--)
	{
		result[len] = (n % 10) * sign + '0';
		n /= 10;
	}
	if (sign == -1)
		result[0] = '-';
	return (result);
}
/*
#include <stdio.h>
int	main(void)
{
	int	a;

	a = -2147483648;
	printf("%s\n", ft_itoa(a));
}*/

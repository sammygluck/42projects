/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:08:44 by sgluck            #+#    #+#             */
/*   Updated: 2023/02/01 16:24:27 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long int	number;
	int					i;
	int					sign;

	i = 0;
	number = 0;
	sign = 1;
	while ((str[i] > 8 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + str[i] - '0';
		if (number > (unsigned)LONG_MAX && sign == -1)
			return (0);
		if (number > (unsigned)LONG_MAX && sign == 1)
			return (-1);
		i++;
	}
	return ((int)number * sign);
}

/*#include <stdio.h>
int	main(void)
{
	printf("%d", ft_atoi("\010 9"));
}*/

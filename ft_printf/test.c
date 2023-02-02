/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:40:45 by sgluck            #+#    #+#             */
/*   Updated: 2023/02/02 11:38:59 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_putnbr_fd(int n, int fd, int *retn)
{
	char	nbr;

	if (n == -2147483648)
	{
		write(fd, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		*retn += 1;
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd, retn);
		n = n % 10;
	}
	nbr = n + '0';
	write(fd, &nbr, 1);
	*retn += 1;
	return (*retn);
}

int	main(void)
{
	int	retn;

	retn = 0;
	printf("\n%i", ft_putnbr_fd(-12345, 1, &retn));
	return (0);
}

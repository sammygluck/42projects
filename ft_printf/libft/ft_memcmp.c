/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:05:48 by sgluck            #+#    #+#             */
/*   Updated: 2023/01/25 16:14:40 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		a;

	i = 0;
	a = 0;
	while (i < n && !a)
	{
		a = *(const unsigned char *)(s1 + i) - *(const unsigned char *)(s2 + i);
		i++;
	}
	return (a);
}

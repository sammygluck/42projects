/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:55:14 by sgluck            #+#    #+#             */
/*   Updated: 2023/01/17 18:58:58 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		a;

	i = 0;
	a = 0;
	while (!a && s1[i] && s2[i] && i < n)
	{
		a = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	if (!a && (s1[i] == '\0' || s2[i] == '\0') && i < n)
		a = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (a);
}

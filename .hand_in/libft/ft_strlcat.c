/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:55:46 by sgluck            #+#    #+#             */
/*   Updated: 2023/01/25 19:09:57 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	bytes;
	size_t	i;

	if (!dst && !src)
		return (0);
	if (!dstsize)
		return (ft_strlen(src));
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	if (dstsize > (srclen + dstlen))
		dstsize = srclen + dstlen + 1;
	bytes = dstsize - dstlen - 1;
	i = 0;
	while (i < bytes)
	{
		*(char *)(dst + dstlen + i) = *(char *)(src + i);
		i++;
	}
	*(char *)(dst + dstlen + i) = '\0';
	return (srclen + dstlen);
}

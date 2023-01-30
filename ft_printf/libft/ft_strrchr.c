/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:52:39 by sgluck            #+#    #+#             */
/*   Updated: 2023/01/17 18:17:52 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	int	end;

	end = ft_strlen(str);
	while (0 <= end)
	{
		if (str[end] == (char) c)
			return ((char *)(str + end));
		end--;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:44:35 by sgluck            #+#    #+#             */
/*   Updated: 2023/01/22 16:59:42 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	joined = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		joined[i] = s2[j];
		j++;
		i++;
	}
	joined[i] = '\0';
	return (joined);
}

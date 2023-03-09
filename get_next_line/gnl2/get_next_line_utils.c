/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:27:15 by sgluck            #+#    #+#             */
/*   Updated: 2023/02/26 17:01:42 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *middle, char *buffer)
{
	char	*new;
	int		i;
	int		j;

	if (!buffer)
		return (NULL);
	if (!middle)
	{
		middle = malloc(1);
		if (!middle)
			return (NULL);
		middle[0] = 0;
	}
	new = malloc(ft_strlen(middle) + ft_strlen(buffer) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (middle[i])
	{
		new[i] = middle[i];
		i++;
	}
	j = 0;
	while (buffer[j])
	{
		new[i] = buffer[j];
		i++;
		j++;
	}
	new[i] = 0;
	return (new);
}

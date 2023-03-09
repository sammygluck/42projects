/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:22:36 by sgluck            #+#    #+#             */
/*   Updated: 2023/03/01 17:58:20 by sgluck           ###   ########.fr       */
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

int	check_newline(char *stock)
{
	int	i;

	if (!stock)
		return (0);
	i = 0;
	while (stock[i])
	{
		if (stock[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *stock, char *buffer)
{
	char	*new;
	int		i;
	int		j;

	if (!stock)
	{
		stock = malloc(1);
		stock[0] = '\0';
	}
	new = malloc(ft_strlen(stock) + ft_strlen(buffer) + 1);
	if (!new)
	{	
		free(stock);
		return (NULL);
	}
	i = -1;
	while (stock[++i])
		new[i] = stock[i];
	j = 0;
	while (buffer[j])
		new[i++] = buffer[j++];
	new[i] = '\0';
	free(stock);
	return (new);
}

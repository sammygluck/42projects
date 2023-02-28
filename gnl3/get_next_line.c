/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:22:24 by sgluck            #+#    #+#             */
/*   Updated: 2023/02/28 17:41:34 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*clean(char *stock)
{
	char	*cleaned;
	int		i;
	int		j;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (stock[i] == '\n')
		i++;
	cleaned = malloc(ft_strlen(stock) - i + 1);
	if (!cleaned)
	{
		free(stock);
		return (NULL);
	}
	if (stock[i - 1] == '\0')
	{
		cleaned[0] = '\0';
		free (stock);
		return (cleaned);
	}
	j = 0;
	while (stock[i])
	{
		cleaned[j] = stock[i];
		i++;
		j++;
	}
	cleaned[j] = '\0';
	free(stock);
	return (cleaned);
}

char	*extract(char *stock)
{
	char	*extracted;
	int		i;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (stock[i] == '\n')
		i++;
	extracted = malloc(i + 1);
	if (!extracted)
		return (NULL);
	i = 0;
	while (stock[i] && stock[i] != '\n')
	{
		extracted[i] = stock[i];
		i++;
	}
	if (stock[i] == '\n')
	{
		extracted[i] = stock[i];
		i++;
	}
	extracted[i] = '\0';
	return (extracted);
}

char	*reader(int fd, char *stock)
{
	char	*buffer;
	int		read_ch;

	read_ch = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!check_newline(stock) && read_ch > 0)
	{
		read_ch = read(fd, buffer, BUFFER_SIZE);
		if (read_ch <= 0)
		{
			free(stock);
			free(buffer);
			return (NULL);
		}
		buffer[BUFFER_SIZE] = '\0';
		stock = ft_strjoin(stock, buffer);
	}
	free(buffer);
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*next_line;

	stock = reader(fd, stock);
	if (!stock)
	{
		return (NULL);
	}
	next_line = extract(stock);
	if (!next_line)
	{
		free(stock);
		return (NULL);
	}
	stock = clean(stock);
	if (!stock)
	{
		free(next_line);
		return (NULL);
	}
	return (next_line);
}

int	main(void)
{
	int		fd;
	char	*next_line;

	fd = open("text.txt", O_RDONLY);
	while ((next_line = get_next_line(fd)) != NULL)
	{
		printf("%s", next_line);
		free(next_line);
	}
	if (next_line)
		free(next_line);
}

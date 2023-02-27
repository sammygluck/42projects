/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:22:24 by sgluck            #+#    #+#             */
/*   Updated: 2023/02/27 19:10:05 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

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
			free(buffer);
			return (NULL);
		}
		buffer[BUFFER_SIZE] = '\0';
		stock = ft_strjoin(stock, buffer);
	}
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char	*next_line;
	
	stock = reader(fd, stock);
	if (!stock)
	{
		free (stock);
		return (NULL);
	}
	next_line = extract(stock);

}

int	main(void)
{
	int	fd;

	fd = open("file_name", O_RDONLY);
	get_next_line(fd);

}

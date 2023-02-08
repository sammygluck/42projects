/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:11:44 by sgluck            #+#    #+#             */
/*   Updated: 2023/02/08 17:49:13 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *buffer, char *middle)
{
	int		i;
	int		j;
	char	*new_string;

	new_string = (char *)malloc(ft_strlen(buffer) + ft_strlen(middle) + 1);
	if (!new_string)
		return (NULL);
	i = 0;
	j = 0;
	while (middle[i])
	{
		new_string[i] = middle[i];
		i++;
	}
	while (buffer[j])
	{
		new_string[i] = buffer[j];
		i++;
		j++;
	}
	new_string[i] = 0;
	return (new_string);
}

int	check_newline(char *middle)
{
	int	i;

	i = 0;
	while (middle[i])
	{
		if (middle[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strcpy(char *next_line, char *middle)
{
	int	i;

	i = 0;
	while (middle[0] != '\n')
	{
		next_line[i] = *middle++;
		i++;
	}
	next_line[i++] = '\n';
	next_line[i] = 0;
	middle++;
	return (middle);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	static char	*middle;
	char	*next_line;
	
	if (!middle)
		middle = malloc(BUFFER_SIZE);
	read(fd, middle, BUFFER_SIZE);
	while (!check_newline(middle))
	{
		buffer = malloc(BUFFER_SIZE);
		read(fd, buffer, BUFFER_SIZE);
		middle = ft_strjoin(buffer, middle);
	}
	next_line = malloc(ft_strlen(middle) + 1);
	middle = ft_strcpy(next_line, middle);
	printf("This is middle %s \n", middle);
	return (next_line);
}

int	main(void)
{
	int		fd;
	char	*buffer;

	fd = open("plan.txt", O_RDONLY);
	printf("This is the fd: %i \n", fd);
	printf("This is the BUFFER_SIZE: %i \n", BUFFER_SIZE);
	buffer = get_next_line(fd);
	printf("This is the returned buffer: %s", buffer);
	buffer = get_next_line(fd);
	printf("This is the returned buffer: %s", buffer);
	free(buffer);
	close(fd);
	return (0);
}

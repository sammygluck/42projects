/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:27:01 by sgluck            #+#    #+#             */
/*   Updated: 2023/02/26 16:50:15 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*middle;
	char		*buffer;
	char		*next_line;
	int			read_ch;
	
	if (fd == -1 || fd == 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	read_ch = read(fd, buffer, BUFFER_SIZE);
	if (read_ch)
	{
		next_line = ft_strjoin(middle, buffer);
		free(buffer);
		return (next_line);
	}
	else
	{
		free(buffer);
		return (NULL);
	}

}

int	main(void)
{
	char	*next_line;
	int		fd;

	fd = open("my_file.txt", O_RDONLY);
	//printf("%i\n", fd);
	while ((next_line = get_next_line(fd)) > 0)
	{
		printf("%s\n", next_line);
		free(next_line);
	}
	return (0);

}

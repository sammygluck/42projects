/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:11:44 by sgluck            #+#    #+#             */
/*   Updated: 2023/02/07 17:23:06 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	char	*buffer;

	buffer = malloc(BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	return (buffer);
	
}

int	main(void)
{
	int	fd;
	char	*buffer;

	fd = open("plan.txt", O_RDONLY);
	printf("This is the fd: %i \n", fd);
	printf("This is the BUFFER_SIZE: %i \n", BUFFER_SIZE);
	buffer = get_next_line(fd);
	printf("This is the returned buffer: %s", buffer);
	free(buffer);
	close(fd);
    return 0;
}


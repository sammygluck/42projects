/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:05:18 by sgluck            #+#    #+#             */
/*   Updated: 2023/03/15 18:20:19 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	count_numbers(char *string)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!string)
		return (0);
	while (string[i])
	{
		if (string[i] == 32)
			count++;
		i++;
	}
	count++;
	return (count);
}

char	*ft_strtok(char *str, char delim)
{
	char		*token;
	static char	*start;

	if (str != NULL)
		start = str;
	if (start == NULL || *start == '\0')
		return (NULL);
	while (*start == delim)
		start++;
	token = start;
	while (*start != '\0')
	{
		if (*start == delim)
		{
			*start = '\0';
			start++;
			break ;
		}
		start++;
	}
	return (token);
}

int	main(int argc, char **argv)
{
	int		count;
	char	*stack1;

	if (argc < 2)
		printf("USAGE: %s <\" string of numbers \">\n", argv[0]);
	count = count_numbers(argv[1]);
	stack1 = ft_strtok(argv[1], ' ');
	while (stack1)
	{
		printf("%s\n", stack1);
		stack1 = ft_strtok(NULL, ' ');
	}		
	return (0);
}

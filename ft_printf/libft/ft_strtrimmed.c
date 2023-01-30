/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:20:59 by sgluck            #+#    #+#             */
/*   Updated: 2023/01/22 16:59:13 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_chr(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static	int	ft_str_len(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		start;
	int		end;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_str_chr(set, s1[start]))
		start++;
	end = ft_str_len(s1) - 1;
	while (s1[end] && ft_str_chr(set, s1[end]))
		end--;
	new = (char *)malloc(end - start + 1 * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (i < (end - start - 1))
	{
		new[i] = s1[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

/*int	main(void)
{
	char str[] = "\tHello my name is SG \n";
	char set[] = "\t\n";
	printf("%s\n", str);
	printf("%s\n", ft_strtrim(str, set));
}*/

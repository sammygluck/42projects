/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:21:08 by sgluck            #+#    #+#             */
/*   Updated: 2023/01/22 17:21:15 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_wordcount(char const *str, char sep)
{
	int	i;
	int	count;

	if (str == 0 || str[0] == 0)
		return (0);
	i = 1;
	count = 0;
	if (str[0] != sep)
		count++;
	while (str[i] != '\0')
	{
		if (str[i] != sep && str[i - 1] == sep)
			count++;
		i++;
	}
	return (count);
}

static int	ft_next_word_count(char const *str, char sep, int i)
{
	int	count;

	count = 0;
	while (str[i] == sep && str[i] != '\0')
		i++;
	while (str[i] != sep && str[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}

static char	**ft_free(char **str_tab, int i)
{
	int	j;

	j = 0;
	while (j < i && str_tab[j] != 0)
	{
		free(str_tab[j]);
		j++;
	}
	free(str_tab);
	return (0);
}

char	**cpy(char **tab_str, char const *str, char charset)
{
	int	s;
	int	i;
	int	j;

	s = 0;
	i = -1;
	while (++i < ft_wordcount(str, charset))
	{
		j = 0;
		tab_str[i] = malloc(ft_next_word_count(str, charset, s) + 1);
		if (!tab_str[i])
			return (ft_free(tab_str, i));
		while (str[s] != '\0' && str[s] == charset)
			s++;
		while (str[s] != '\0' && str[s] != charset)
			tab_str[i][j++] = str[s++];
		tab_str[i][j] = '\0';
	}
	tab_str[i] = 0;
	return (tab_str);
}

char	**ft_split(char const *str, char charset)
{
	int		len;
	char	**tab_str;

	if (str == 0)
		return (0);
	len = ft_wordcount(str, charset);
	tab_str = (char **)malloc(sizeof(char *) * (len + 1));
	if (tab_str == NULL)
		return (NULL);
	return (cpy(tab_str, str, charset));
}

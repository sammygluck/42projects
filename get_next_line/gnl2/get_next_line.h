/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:21:32 by sgluck            #+#    #+#             */
/*   Updated: 2023/02/26 16:08:09 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str);
char	*ft_strjoin(char * buffer, char *middle);
int	check_newline(char *middle);
char	*ft_strcpy(char *next_line, char *middle);
char	*get_next_line(int fd);


#endif

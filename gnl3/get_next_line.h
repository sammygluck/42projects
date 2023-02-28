/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:33:59 by sgluck            #+#    #+#             */
/*   Updated: 2023/02/28 16:23:02 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*reader(int fd, char *stock);
char	*extract(char *stock);
char	*clean(char *stock);
char	*ft_strjoin(char *stock, char *buffer);
int		check_newline(char *stock);
int		ft_strlen(char *str);

#endif 

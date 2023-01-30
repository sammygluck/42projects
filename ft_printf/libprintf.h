/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:56:15 by sgluck            #+#    #+#             */
/*   Updated: 2023/01/30 16:48:38 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

void	formats(va_list args, char c);
void	ft_printf(int n, char *str, ...);
void	character(char c);
void	string(char *str);
void	pointer(void *ptr);
void	print_hex(size_t nbr);
void	decimal(int n);

#endif

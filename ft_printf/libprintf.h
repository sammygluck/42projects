/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:56:15 by sgluck            #+#    #+#             */
/*   Updated: 2023/02/01 18:39:02 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

void	formats(va_list args, char c, int *retn);
void	ft_printf(int n, char *str, ...);
void	character(char c, int *retn);
void	string(char *str, int *retn);
void	pointer(void *ptr, int *retn);
void	print_uhex(size_t nbr, int *retn);
void	print_hex(size_t nbr, int *retn);
void	ft_hex(int nbr, char c, int *retn);
void	decimal(int n, int *retn);
void	u_nbr(unsigned int nbr, int *retn);
void	ft_putchar(char c, int *retn);
void	ft_putstr(char *s, int *retn);
void	ft_putnbr(int n, int *retn);

#endif

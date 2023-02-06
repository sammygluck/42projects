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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

void	formats(va_list args, char c, int *retn);
int	ft_printf(const char *str, ...);
void	character(char c, int *retn);
void	string(char *str, int *retn);
void	pointer(void *ptr, int *retn);
void	print_pointer(unsigned long nbr, int *retn);
void	print_uhex(unsigned int nbr, int *retn);
void	print_hex(unsigned int nbr, int *retn);
void	ft_hex(unsigned int nbr, char c, int *retn);
void	decimal(int n, int *retn);
void	u_nbr(unsigned int nbr, int *retn);
void	ft_putchar(char c, int *retn);
void	ft_putstr(char *s, int *retn);
void	ft_putnbr(int n, int *retn);

#endif
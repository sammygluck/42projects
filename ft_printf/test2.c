/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:30:47 by sgluck            #+#    #+#             */
/*   Updated: 2023/02/06 15:30:50 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ft_printf.h>
#include <limits.h>

int	main(void)
{
	ft_printf("%i\n", ft_printf("%p %p \n", LONG_MIN, LONG_MAX));
	printf("%i\n", printf("%p %p \n", LONG_MIN, LONG_MAX));
}

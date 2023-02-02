/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:18:11 by sgluck            #+#    #+#             */
/*   Updated: 2023/02/02 11:42:37 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"

void	ft_putchar(char c, int *ret)
{
	write(1, &c, 1);
	*ret += 1;
}

/*int	main(void)
{
	ft_putchr_fd('a', 1);
}*/

#include <stdio.h>
#include <ft_printf.h>
#include <limits.h>

int	main(void)
{
	ft_printf("%i\n", ft_printf("%p %p \n", LONG_MIN, LONG_MAX));
	printf("%i\n", printf("%p %p \n", LONG_MIN, LONG_MAX));
}

#include <stdio.h>
#include <unistd.h>


void	ft_putchar(char c, int *ret)
{
	write(1, &c, 1);
	*ret += 1;
}

void	ft_putstr(char *s, int *retn)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], retn);
		i++;
	}
}

int	ft_putnbr(int n, int *retn)
{
	char	nbr;

	if (n == -2147483648)
	{
		write(1, "-2", 2);
		*retn += 2;
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-', retn);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, retn);
		n = n % 10;
	}
	nbr = n + '0';
	ft_putchar(nbr, retn);
	return (*retn);
}

int	main(void)
{
	int	retn;

	retn = 0;
	printf("\n%i", ft_putnbr(-12345, &retn));
	return (0);
}

#include "ft_printf.h"

static void	printout(long nb)
{
	if (nb > 9)
		printout(nb / 10);
	ft_putchar_fd((nb % 10) + '0', 1);
}

int	print_int(int n)
{
	long	nb;
	int		len;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		len++;
		nb = -nb;
	}
	printout(nb);
	while (nb > 9)
	{
		nb /= 10;
		len++;
	}
	len++;
	return (len);
}


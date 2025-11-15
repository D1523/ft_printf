#include "ft_printf.h"

static int	hex_len(unsigned int n)
{
	int	len;

	len = 1;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static void	put_hex(unsigned int n, int asc)
{
	if (n >= 16)
		put_hex(n / 16, asc);
	if ((n % 16) < 10)
		ft_putchar_fd((n % 16) + '0', 1);
	else
		ft_putchar_fd((n % 16) + asc, 1);
}

int	print_hex(unsigned int value, int asc)
{
	if (value == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	put_hex(value, asc);
	return (hex_len(value));
}



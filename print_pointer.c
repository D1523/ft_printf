#include "ft_printf.h"

static int	ptr_hex_len(unsigned long n)
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

static void	put_ptr_hex(unsigned long n, int asc)
{
	if (n >= 16)
		put_ptr_hex(n / 16, asc);
	if ((n % 16) < 10)
		ft_putchar_fd((n % 16) + '0', 1);
	else
		ft_putchar_fd((n % 16) + asc, 1);
}

int	print_pointer(unsigned long value, int asc)
{
	int	len;

	len = 0;
	ft_putstr_fd("0x", 1);
	len += 2;
	if (value == 0)
	{
		ft_putchar_fd('0', 1);
		return (len + 1);
	}
	put_ptr_hex(value, asc);
	len += ptr_hex_len(value);
	return (len);
}



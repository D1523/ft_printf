#include "ft_printf.h"

static void	printout(unsigned int nb)
{
	if (nb > 9)
		printout(nb / 10);
	ft_putchar_fd((nb % 10) + '0', 1);
}

int	print_unsigned(unsigned int nb)
{
	unsigned int	i;
	unsigned int	tmp;

	printout(nb);
	tmp = nb;
	i = 1;
	while (tmp > 9)
	{
		tmp = tmp / 10;
		i++;
	}
	return (i);
}

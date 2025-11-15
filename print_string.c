#include "ft_printf.h"

int	print_string(char *s)
{
	unsigned int	i;

	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	i = 0;
	while (s[i])
		i++;
	ft_putstr_fd(s, 1);
	return (i);
}



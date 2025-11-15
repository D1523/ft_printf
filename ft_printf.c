#include "ft_printf.h"

static int	check_type(const char *input, va_list *args)
{
	if (*input == 'c')
		return (print_char(va_arg(*args, int)));
	else if (*input == 's')
		return (print_string(va_arg(*args, char *)));
	else if (*input == 'p')
		return (print_pointer(va_arg(*args, unsigned long), 87));
	else if (*input == 'd' || *input == 'i')
		return (print_int(va_arg(*args, int)));
	else if (*input == 'u')
		return (print_unsigned(va_arg(*args, unsigned int)));
	else if (*input == 'x')
		return (print_hex(va_arg(*args, unsigned int), 87));
	else if (*input == 'X')
		return (print_hex(va_arg(*args, unsigned int), 55));
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, input);
	while (*input != '\0')
	{
		if (*input == '%')
		{
			input++;
			if (ft_strchr("cspdiuxX", *input))
				i += check_type(input, &args);
			else if (*input == '%')
				i += print_char('%');
		}
		else
			i += print_char(*input);
		if (*input != '\0')
			input++;
	}
	va_end(args);
	return (i);
}

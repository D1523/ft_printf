/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erfiliz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:06:32 by erfiliz           #+#    #+#             */
/*   Updated: 2025/11/15 16:00:00 by erfiliz        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

int		ft_printf(const char *input, ...);
int		print_pointer(unsigned long value, int asc);
int		print_unsigned(unsigned int nb);
int		print_string(char *s);
int		print_int(int n);
int		print_char(char c);
int		print_hex(unsigned int value, int asc);

/* utils (libft'siz kullanmak için) */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);

#endif


#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

static void	sep(const char *title)
{
	printf("\n========== %s ==========\n", title);
}

/*
 * Her testte aynı format iki kez çağrılıyor:
 * önce printf, sonra ft_printf, sonra length karşılaştırması yazdırılıyor.
 */

int	main(void)
{
	int		x;
	int		a;
	int		b;
	char	*null_str = NULL;

	x = 42;

	/* Temel test: tüm zorunlu formatlar */
	sep("BASIC FORMATS");
	a = printf("ORIG: %c %s %p %d %i %u %x %X %%\n",
			'A', "Hello", (void *)&x, -42, 123, 3000000000u,
			3735928559u, 3735928559u);
	b = ft_printf("MINE: %c %s %p %d %i %u %x %X %%\n",
			'A', "Hello", (void *)&x, -42, 123, 3000000000u,
			3735928559u, 3735928559u);
	printf("len printf: %d\nlen ft_printf: %d\n", a, b);

	/* NULL string */
	sep("NULL STRING");
	a = printf("ORIG: [%s]\n", null_str);
	b = ft_printf("MINE: [%s]\n", null_str);
	printf("len printf: %d\nlen ft_printf: %d\n", a, b);

	/* Sıfır değerler */
	sep("ZERO VALUES");
	a = printf("ORIG: d=%d i=%i u=%u x=%x X=%X p=%p\n",
			0, 0, 0u, 0u, 0u, (void *)0);
	b = ft_printf("MINE: d=%d i=%i u=%u x=%x X=%X p=%p\n",
			0, 0, 0u, 0u, 0u, (void *)0);
	printf("len printf: %d\nlen ft_printf: %d\n", a, b);

	/* Negatif sayılar ve INT_MIN */
	sep("NEGATIVE NUMBERS");
	a = printf("ORIG: -1=%d, -42=%i, INT_MIN=%d\n", -1, -42, INT_MIN);
	b = ft_printf("MINE: -1=%d, -42=%i, INT_MIN=%d\n", -1, -42, INT_MIN);
	printf("len printf: %d\nlen ft_printf: %d\n", a, b);

	/* UINT_MAX ve büyük unsigned */
	sep("UNSIGNED & UINT_MAX");
	a = printf("ORIG: u=%u, UINT_MAX=%u\n", 3000000000u, UINT_MAX);
	b = ft_printf("MINE: u=%u, UINT_MAX=%u\n", 3000000000u, UINT_MAX);
	printf("len printf: %d\nlen ft_printf: %d\n", a, b);

	/* Hex edge case’ler */
	sep("HEX VALUES");
	a = printf("ORIG: x=%x X=%X, UINT_MAX=%x/%X\n", 0u, 0u, UINT_MAX, UINT_MAX);
	b = ft_printf("MINE: x=%x X=%X, UINT_MAX=%x/%X\n", 0u, 0u, UINT_MAX, UINT_MAX);
	printf("len printf: %d\nlen ft_printf: %d\n", a, b);

	/* Pointer testleri */
	sep("POINTERS");
	a = printf("ORIG: &x=%p, NULL=%p\n", (void *)&x, (void *)0);
	b = ft_printf("MINE: &x=%p, NULL=%p\n", (void *)&x, (void *)0);
	printf("len printf: %d\nlen ft_printf: %d\n", a, b);

	/* Karışık format testi */
	sep("MIXED COMPLEX");
	a = printf("ORIG: str=%s, c=%c, d=%d, u=%u, x=%x, p=%p, %% done\n",
			"Test", 'Z', -12345, 987654321u, 0xabcdef, (void *)&a);
	b = ft_printf("MINE: str=%s, c=%c, d=%d, u=%u, x=%x, p=%p, %% done\n",
			"Test", 'Z', -12345, 987654321u, 0xabcdef, (void *)&a);
	printf("len printf: %d\nlen ft_printf: %d\n", a, b);

	return (0);
}

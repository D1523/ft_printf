#include "ft_printf.h"

size_t ft_strlen(const char *s)
{
    size_t i = 0;
    while (s && s[i]) i++;
    return i;
}

int ft_putchr(int c)
{
    return (int)write(1, &c, 1);
}

int ft_putstr(const char *s)
{
    if (!s) return (int)write(1, "(null)", 6);
    return (int)write(1, s, ft_strlen(s));
}

static int putnbr_recursive(long n)
{
    char d;
    int  count = 0;

    if (n > 9) count += putnbr_recursive(n / 10);
    d = '0' + (char)(n % 10);
    count += (int)write(1, &d, 1);
    return count;
}

int ft_putnbr(int n)
{
    long ln = n;
    int  count = 0;

    if (ln < 0)
    {
        count += (int)write(1, "-", 1);
        ln = -ln;
    }
    count += putnbr_recursive(ln);
    return count;
}

static int putunbr_recursive(unsigned int n)
{
    char d;
    int  count = 0;

    if (n > 9) count += putunbr_recursive(n / 10);
    d = '0' + (char)(n % 10);
    count += (int)write(1, &d, 1);
    return count;
}

int ft_putunbr(unsigned int n)
{
    return putunbr_recursive(n);
}

static int puthex_recursive(unsigned long n, const char *base)
{
    int count = 0;
    if (n >= 16) count += puthex_recursive(n / 16, base);
    count += (int)write(1, &base[n % 16], 1);
    return count;
}

int ft_puthex(unsigned long n, int uppercase)
{
    const char *base = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
    return puthex_recursive(n, base);
}

int ft_putptr(void *p)
{
    int count = 0;
    unsigned long addr = (unsigned long)p;

    count += (int)write(1, "0x", 2);
    if (addr == 0)
        count += (int)write(1, "0", 1); // bazı kampüslerde "(nil)" tercih edilir
    else
        count += ft_puthex(addr, 0);
    return count;
}

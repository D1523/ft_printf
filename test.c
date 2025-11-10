#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int a = -42;
    unsigned int u = 4294967295u;
    void *p = &a;

    ft_printf("ft: Hello %s | %c | %d %i | %u | %x %X | %p | %%\n",
              "world", 'A', a, 123, u, 48879, 48879, p);

    printf(   "og: Hello %s | %c | %d %i | %u | %x %X | %p | %%\n",
              "world", 'A', a, 123, u, 48879, 48879, p);
    return 0;
}

#include "libft.h"

void    *ft_memset(void *b, int c, size_t len)
{
    char    *tmp;

    tmp = b;
    while (len--)
        *tmp++ = c;
    return (b);
}

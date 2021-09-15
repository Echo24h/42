#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t n)
{
    const unsigned char *tmp;

    tmp = s;
    while (n--)
    {
        if (*tmp == (unsigned char)c)
            return ((void *)tmp);
        tmp++;
    }
    return (NULL);
}

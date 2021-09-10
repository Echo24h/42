#include <stdio.h>

void    *ft_memset(void *s, int c, size_t n)
{
    size_t  i;

    if (!s)
        return (s);
    i = 0;
    while (i < n)
        ((unsigned char *)s)[i++] = (unsigned char)c;
    return (s);
}

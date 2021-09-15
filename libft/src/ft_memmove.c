#include "libft.h"

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    char        *d;
    const char  *s;

    if (!dst && !src)
        return (NULL);
    d = dst;
    s = src;
    if (d < s)
        while (len--)
            *d++ = *s++;
    else
    {
        d = d + len - 1;
        s = s + len - 1;
        while (len--)
            *d-- = *s--;
    }
    return (dst);
}

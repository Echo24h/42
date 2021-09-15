#include "libft.h"

void    *ft_memcpy(void *dst, const void *src, size_t n)
{
    char        *tmp_dst;
    const char  *tmp_src;

    if (!dst && !src)
        return (NULL);
    tmp_dst = dst;
    tmp_src = src;
    while (n--)
        *(tmp_dst++) = *(tmp_src++);
    return (dst);
}

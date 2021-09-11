#include <stdio.h>
#include <string.h>

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    char        *tmp_dest;
    const char  *tmp_src;

    while (n--)
        *(tmp_dest++) = *(tmp_src++);
    return (dest);
}

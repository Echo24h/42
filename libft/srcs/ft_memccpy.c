#include <stdio.h>

void *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
    size_t  i;

    if (!dest || !src)
        return (NULL);
    i = 0;
    while (i < n) {
        ((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
        if (((unsigned char *)dest)[i] == (unsigned char)c)
            return (&((unsigned char *)dest)[i + 1]);
        i++;
    }
    return (NULL);
}

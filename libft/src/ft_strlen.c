#include "libft.h"

size_t  ft_strlen(const char *s)
{
    size_t  res;

    if (!s)
        return (0);
    res = 0;
    while (*(s++))
        res++;
    return (res);
}

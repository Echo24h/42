#include "libft.h"

size_t	ft_strlcat(char * restrict dst, const char * restrict src, size_t dstsize)
{
	size_t	len_dst;
	size_t	i;

	len_dst = ft_strlen(dst);
	if (len_dst > dstsize)
		return (dstsize + ft_strlen(src));
	i = 0;
	while ((int)i < (int)dstsize - (int)len_dst - 1 && src[i] && len_dst + i < dstsize)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + ft_strlen(src));
}

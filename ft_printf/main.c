#include "ft_printf.h"
#include "libft.h"

int	main()
{
	int		x;
	int		y;
	int		z;
	char	*s1;
	char	*s2;

	//x = printf("%d\n", 22);
	//printf("printf:%d\n\n", x);

	x = ft_printf("%#-0+   -- +56789034.512d\n", 55);
	printf("ft_printf: %d\n", x);
	return (0);
}
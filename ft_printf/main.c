#include "ft_printf.h"
#include "libft.h"

int	main()
{
	int		x;
	int		y;
	int		z;
	char	*s1 = "";
	char	s2[] = "|%s|\n";

	//printf("%s", ft_str);
	printf("\n\n=== my test ===\n\n");

	x = printf(s2, s1);
	printf("printf:%d\n\n", x);

	printf("\n\n");
	x = ft_printf(s2, s1);
	printf("ft_printf: %d\n", x);
	return (0);
}
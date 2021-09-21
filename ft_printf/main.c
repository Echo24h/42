#include "ft_printf.h"
#include "libft.h"
#include "limits.h"

int	main()
{
	int		x;
	int		y = -1;
	unsigned int	z = 1234;
	void	*ptr = ft_strdup("lol");
	void	*ptr2 = ft_strdup("lol");
	void	*ptr3 = ft_strdup("lol");
	char	*s1;
	char	s2[] = "|% #X|\n";

	printf("\n\n");
	printf("printf\n\n");

	printf("\n\n=== my test ===\n\n");

	x = printf(s2, y);
	printf("ft_printf: %d\n\n", x);

	x = ft_printf(s2, y);
	printf("ft_printf: %d\n", x);
	//printf("%u", z);
	return (0);
}
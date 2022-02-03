#include "libft.h"

void	print_strs(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
		ft_printf("%s\n", strs[i++]);
}

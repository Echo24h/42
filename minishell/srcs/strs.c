#include "libft.h"

void	free_strs(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

char	**copy_strs(char **strs)
{
	char	**new;
	int		i;

	if (!strs)
		return (NULL);
	i = 0;
	while (strs[i])
		i++;
	new = malloc(sizeof(char *) * (i + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (strs[i])
	{
		new[i] = ft_strdup(strs[i]);
		if (!new[i])
			return (NULL);
		i++;
	}
	new[i] = NULL;
	return (new);
}

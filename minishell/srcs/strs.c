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

int	strs_len(char **strs)
{
	int	i;

	if (!strs)
		return (0);
	i = 0;
	while (strs[i])
		i++;
	return (i);
}

char	**strs_append(char **strs, const char *str)
{
	int		i;
	char	**new;

	new = malloc(sizeof(char *) * (strs_len(strs) + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (strs && strs[i])
	{
		new[i] = ft_strdup(strs[i]);
		if (!new[i])
			return (NULL);
		i++;
	}
	new[i] = ft_strdup(str);
	if (!new[i])
		return (NULL);
	new[i + 1] = NULL; 
	free_strs(strs);
	return (new);
}

#include "minishell.h"

char	*index_str(const char *str, int index)
{
	char	*new_str;
	char	*str_index;

	if (!str)
		return (NULL);
	str_index = ft_itoa(index);
	if (!str_index)
		return (NULL);
	new_str = ft_strjoin(str, str_index);
	free(str_index);
	return (new_str);
}

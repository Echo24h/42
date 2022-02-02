#include "minishell.h"
#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	if (!s1 && !s2)
		return (0);
	if (s1 || s2)
		return (1);
	while (*s1 && *s2 && *s1 != *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	my_strncpy(char *dst, char *src, int n)
{
	int	i;

	if (!dst || !src || n <= 0)
		return ;
	i = 0;
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';	
}

void	exit_error(char *msg, int code)
{
	ft_printf("Error: %s\n", msg);
	exit(code);
}

// delete len char at index start of str and rearrange the string
char	*trunc_str(char *str, int start, int len)
{
	int		i;
	char	*new;

	new = malloc(ft_strlen(str) - len + 1);
	if (!new)
		exit_error("malloc() failed", 1);
	my_strncpy(new, str, start);
	i = 0;
	while (str[start + len + i])
	{
		new[start + i] = str[start + len + i];
		i++;
	}
	new[start + i] = '\0';
	free(str);
	return (new);
}

// insert src in dst at index n
void	insert_str(char **dst, char *src, size_t n)
{
	int		i;
	int		j;
	char	*new;

	new = malloc(ft_strlen(*dst) + ft_strlen(src)); // omitted +1 for \0 because of $ that we need to soustract
	if (!new)
		exit_error("malloc() failed", 1);
	my_strncpy(new, *dst, n);
	i = 0;
	while (src[i])
	{
		new[n + i] = src[i];
		i++;
	}
	while ((*dst)[n])
	{
		new[n + i] = (*dst)[n + 1];
		n++;
	}
	free(*dst);
	*dst = new;
}

char	*get_var_name(char *line)
{
	int		i;
	char	*var_name;

	i = 0;
	while (line[i] && ft_isalnum(line[i]))
		i++;
	var_name = malloc(i + 1);
	if (!var_name)
		exit_error("malloc() failed", 1);
	my_strncpy(var_name, line, i);
	return (var_name);
}

char	*get_var_value(t_envvar *envvar, char *var_name)
{
	char	*var_value;
	int		i;

	var_value = ft_strdup("");
	if (!var_value)
		exit_error("malloc() failed", 1);
	i = 0;
	while (envvar[i].name)
	{
		if (!ft_strcmp(envvar[i].name, var_name))
		{
			free(var_value);
			var_value = ft_strdup(envvar[i].value);
			if (!var_value)
				exit_error("malloc() failed", 1);
			break ;
		}
		i++;
	}
	return (var_value);
}

void	expand(char **line, t_envvar *envvar)
{
	int	i;
	int	j;
	char	*var_name;
	char	*var_value;

	i = 0;
	while ((*line)[i])
	{
		if ((*line)[i] == '$')
		{
			if ((*line)[i + 1] == '?')
				; // expand to the exit status of the most recently executed foreground pipeline ; incr i
			else if (ft_isalnum((*line)[i + 1]))
			{
				// proceed to expand env var value ; which is "" if var doesn't exist
				var_name = get_var_name(&(*line)[i + 1]);
				*line = trunc_str(*line, i + 1, ft_strlen(var_name));
				var_value = get_var_value(envvar, var_name);
				insert_str(line, var_value, i);
				i += ft_strlen(var_value) - 1;
				free(var_name);
				free(var_value);
			}
			else if ((*line)[i + 1] == '$')
				; // expand to the process pid (not necessary?) ; incr i
			else
				i++;
		}
		else if ((*line)[i++] == '\'')
			while ((*line)[i] && (*line)[i] != '\'')
				i++;
	}
}
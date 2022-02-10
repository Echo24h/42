#include "minishell.h"
#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (-1);
	if (!s2)
		return (1);
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	my_strncpy(char *dst, const char *src, int n)
{
	int	i;

	if (!dst || !src || n < 0)
		return ;
	i = 0;
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';	
}

/*
	description :
		delete len char at index start of str and rearrange the string
*/
char	*get_str_truncated(const char *str, int start, int len)
{
	int		i;
	char	*new;

	new = malloc(ft_strlen(str) - len + 1);
	if (!new)
		return (NULL);
	my_strncpy(new, str, start);
	i = 0;
	while (str[start + len + i])
	{
		new[start + i] = str[start + len + i];
		i++;
	}
	new[start + i] = '\0';
	return (new);
}

char	*trunc_str(char *str, int start, int len)
{
	int		i;
	char	*new;

	new = malloc(ft_strlen(str) - len + 1);
	if (!new)
		return (NULL);
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

/*
	description :
		insert src in dst at index n
*/
char	*str_insert(char *dst, const char *src, size_t n)
{
	int		i;
	int		j;
	char	*new;

	new = malloc(ft_strlen(dst) + ft_strlen(src));
	if (!new)
		return (NULL);
	my_strncpy(new, dst, n);
	i = 0;
	while (src[i])
	{
		new[n + i] = src[i];
		i++;
	}
	while (dst[n])
	{
		new[n + i] = dst[n + 1];
		n++;
	}
	free(dst);
	return (new);
}

char	*get_ev_name(char *ev)
{
	int		i;
	char	*ev_name;

	if (ft_isdigit(ev[0]))
	{
		ev_name = ft_calloc(2, 1);
		if (!ev_name)
			exit_error(strerror(errno), EXIT_FAILURE);
		ev_name[0] = ev[0];
		return (ev_name);
	}
	i = 0;
	while (ev[i] && (ft_isalnum(ev[i]) || ev[i] == '_'))
		i++;
	ev_name = malloc(i + 1);
	if (!ev_name)
		exit_error(strerror(errno), EXIT_FAILURE);
	my_strncpy(ev_name, ev, i);
	return (ev_name);
}

char	*get_ev_value(char **local_env, char *ev_name)
{
	char	*ev_value;
	char	*tmp;
	int		i;

	i = 0;
	while (local_env[i])
	{
		tmp = get_ev_name(local_env[i]);
		if (!ft_strcmp(tmp, ev_name))
		{
			ev_value = get_str_truncated(local_env[i], 0, ft_strlen(ev_name) + 1);
			if (!ev_value)
				exit_error(strerror(errno), EXIT_FAILURE);
			free(tmp);
			return (ev_value);
		}
		free(tmp);
		i++;
	}
	ev_value = ft_strdup("");
	if (!ev_value)
		exit_error(strerror(errno), EXIT_FAILURE);
	return (ev_value);
}

/*
	to do :
		- handle $?

	description :
		replace '$NAME' in the line by it's value retrivied
		from process local environnement variables
*/
void	expand_ev(char **line, char **local_env)
{
	int		i;
	char	*ev_name;
	char	*ev_value;

	i = 0;
	while ((*line)[i])
	{
		if ((*line)[i] == '$')
		{
			if ((*line)[i + 1] == '?')
				; // expand to the exit status of the most recently executed foreground pipeline ; incr i
			else if (ft_isalnum((*line)[i + 1]) || (*line)[i + 1] == '_')
			{
				ev_name = get_ev_name(&(*line)[i + 1]);
				*line = trunc_str(*line, i + 1, ft_strlen(ev_name));
				if (!*line)
					exit_error(strerror(errno), EXIT_FAILURE);
				ev_value = get_ev_value(local_env, ev_name);
				*line = str_insert(*line, ev_value, i);
				if (!line)
					exit_error(strerror(errno), EXIT_FAILURE);
				i += ft_strlen(ev_value);
				free(ev_value);
				free(ev_name);
			}
			else
				i++;
		}
		else if ((*line)[i++] == '\'')
			while ((*line)[i] && (*line)[i] != '\'')
				i++;
	}
}
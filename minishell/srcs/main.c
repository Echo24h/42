#include "minishell.h"
#include "libft.h"

# define PROMPT "minishell> "

// not protected ; env var should be set correctly
void	extract_name_and_value(char *str, t_envvar *ev)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '=')
		i++;
	ev->name = malloc(i + 1);
	if (!ev->name)
		exit_error("malloc() failed", 1);
	my_strncpy(ev->name, str, i);
	i++;
	ev->value = malloc(ft_strlen(&str[i]) + 1);
	if (!ev->value)
		exit_error("malloc() failed", 1);
	my_strncpy(ev->value, &str[i], ft_strlen(&str[i]));
}

t_envvar	*parse_env(char **env)
{
	t_envvar	*ev;
	int	i;

	i = 0;
	while (env[i])
		i++;
	ev = malloc(sizeof(t_envvar) * (i + 1));
	if (!ev)
		exit_error("malloc() failed", 1);
	i = 0;
	while (env[i])
	{
		extract_name_and_value(env[i], &ev[i]);
		i++;
	}
	ev[i].name = NULL;
	return (ev);
}

void	free_envvar(t_envvar *ev)
{
	int	i;

	i = 0;
	while (ev[i].name)
	{
		free(ev[i].name);
		free(ev[i].value);
		i++;
	}
	free(ev);
}

void	print_envvar(t_envvar *ev)
{
	int	i;

	i = 0;
	while (ev[i].name)
	{
		printf("%s=%s\n", ev[i].name, ev[i].value);
		i++;
	}
}

int	main(int ac, char **av, char **env)
{
	char	*line;
	int		i;
	t_envvar	*ev;

	ev = parse_env(env);
	line = readline(PROMPT);
	while (line)
	{
		printf("before expand: %s\n", line);
		expand(&line, ev);
		printf("after expand: %s\n", line);
		free(line);
		line = readline(PROMPT);
	}
	free_envvar(ev);
	return (0);
}


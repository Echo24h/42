#include "minishell.h"
#include "libft.h"

# define PROMPT "minishell> "

// not protected ; env var should be set correctly
void	extract_name_and_value(char *str, t_envvar *var)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '=')
		i++;
	var->name = malloc(i + 1);
	if (!var->name)
		exit_error("malloc() failed", 1);
	my_strncpy(var->name, str, i);
	i++;
	var->value = malloc(ft_strlen(&str[i]) + 1);
	if (!var->value)
		exit_error("malloc() failed", 1);
	my_strncpy(var->value, &str[i], ft_strlen(&str[i]));
}

// need implement function to free envvar
t_envvar	*parse_env(char **env)
{
	t_envvar	*envvar;
	int	i;

	i = 0;
	while (env[i])
		i++;
	envvar = malloc(sizeof(t_envvar) * (i + 1));
	if (!envvar)
		exit_error("malloc() failed", 1);
	i = 0;
	while (env[i])
	{
		extract_name_and_value(env[i], &envvar[i]);
		i++;
	}
	envvar[i].name = NULL;
	return (envvar);
}

void	print_envvar(t_envvar *envvar)
{
	int	i;

	i = 0;
	while (envvar[i].name)
	{
		printf("%s=%s\n", envvar[i].name, envvar[i].value);
		i++;
	}
}

int	main(int ac, char **av, char **env)
{
	char	*line;
	int		i;
	t_envvar	*envvar;

	envvar = parse_env(env);
	line = readline(PROMPT);
	while (line)
	{
		printf("before expand: %s\n", line);
		expand(&line, envvar);
		printf("after expand: %s\n", line);
		free(line);
		line = readline(PROMPT);
	}

	//system("leaks minishell");
	return (0);
}


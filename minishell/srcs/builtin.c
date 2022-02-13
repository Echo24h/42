#include "minishell.h"

int	is_in_env(char **env, char *ev_name)
{
	int		i;
	char	*tmp;

	if (!env)
		return (0);
	while (env[i])
	{
		tmp = get_ev_name(env[i]); // !!!
		if (!ft_strcmp(tmp, ev_name))
		{
			free(tmp);
			return (1);
		}
		free(tmp);
		i++;
	}
	return (0);
}

/*
	to do:
		- handle errors properly
*/
int	builtin_env(char **local_env, char **args)
{
	if (strs_len(args) > 1)
	{
		print_error("env command doesn't take arguments");
		return (EXIT_FAILURE);
	}
	print_strs(local_env);
	return (EXIT_SUCCESS);
}

static int	check_ev_name(char *arg)
{
	int	i;

	if (!ft_isalpha(arg[0]) && arg[0] != '_')
		return (0);
	i = 1;
	while (arg[i] && arg[i] != '=')
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return (0);
		i++;
	}
	if (arg[i] != '=')
		return (0);	
	return (1);
}

/*
	to do:
		- handle errors properly
*/
int	builtin_export(char **local_env, char **args)
{
	int		i;
	char	*new_ev_name;
	int		ret;

	ret = 0;
	i = 1;
	while (args[i])
	{
		if (!check_ev_name(args[i]))
		{
			print_error("Invalid env. variable name");
			ret = 1;
		}
		else
		{
			new_ev_name = get_ev_name(args[i]);
			if (!is_in_env(local_env, new_ev_name))
			{
				local_env = strs_append(local_env, args[i]);
				if (!local_env)
				{
					print_error("Cannot allocate memory");
					return (EXIT_FAILURE);
				}
			}
			else
			{
				print_error("Env. variable already exists");
				ret = 1;
			}
			free(new_ev_name);
			i++;
		}
	}
	return (ret);
}
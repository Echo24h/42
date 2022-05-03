#include "minishell.h"

static int	is_valid_input(char *arg)
{
	int	i;

	if (ft_isdigit(arg[0]) || !arg[0])
		return (0);
	i = 0;
	while (arg[i] && arg[i] != '=')
	{
		if (i == 0 && arg[i] == '_')
			i++;
		else
		{
			if (!ft_isalnum(arg[i]))
				return (0);
			i++;
		}
	}
	return (1);
}

int	ev_has_value(char *ev)
{
	while (*ev && *ev != '=')
		ev++;
	if (*ev != '=')
		return (0);
	return (1);
}

void	export_ev(char *ev, char ***env, int mode)
{
	int		i;
	char	*ev_name;
	char	*tmp;

	ev_name = get_ev_name(ev);
	i = 0;
	while ((*env)[i])
	{
		tmp = get_ev_name((*env)[i]);
		if (!my_strcmp(ev_name, tmp))
		{
			free(ev_name);
			free(tmp);
			if (!ev_has_value(ev))
				return ;
			tmp = (*env)[i];
			(*env)[i] = ft_strdup(ev);
			free(tmp);
			return ;
		}
		free(tmp);
		i++;
	}
	free(ev_name);
	if (mode == TO_LOCAL_ENV && !ev_has_value(ev))
		return ;
	*env = strs_append(*env, ev);
}

int	builtin_export(char **args, t_var *var)
{
	int	ret;
	int	i;

	if (!args[1])
	{
		i = 0;
		while (var->local_export[i])
		{
			ft_putstr_fd("declare -x ", STDOUT_FILENO);
			ft_putendl_fd(var->local_export[i], STDOUT_FILENO);
			i++;
		}
		return (0);
	}
	i = 1;
	ret = 0;
	while (args[i])
	{
		if (!is_valid_input(args[i]))
		{
			print_error(ft_strjoin("export: ", args[i]), "not a valid identifier");
			ret = 1;
		}
		else
		{
			export_ev(args[i], &var->local_env, TO_LOCAL_ENV);
			export_ev(args[i], &var->local_export, TO_LOCAL_EXPORT);
		}
		i++;
	}
	return (ret);
}
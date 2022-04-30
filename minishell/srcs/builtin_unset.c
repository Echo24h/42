#include "minishell.h"

static int	is_valid_input(char *arg)
{
	if (!*arg || ft_isdigit(*arg))
		return (0);
	if (*arg == '_')
		arg++;
	while (*arg && ft_isalnum(*arg))
		arg++;
	if (*arg)
		return (0);
	return (1);
}

void	unset_ev(char *ev_name, char ***env)
{
	char	*tmp;
	int		i;

	i = 0;
	while ((*env)[i])
	{
		tmp = get_ev_name((*env)[i]);
		if (!my_strcmp(ev_name, tmp))
		{
			*env = strs_del_index(*env, i);
			free(tmp);
			break ;
		}
		free(tmp);
		i++;
	}
}

int	builtin_unset(char **args, t_var *var)
{
	int	ret;
	int	i;

	if (!args[1])
		return (0);
	i = 0;
	ret = 0;
	while (args[i])
	{
		if (!is_valid_input(args[i]))
		{
			print_error(ft_strjoin("unset: ", args[i]), "not a valid identifier");
			ret = 1;
		}
		else
		{
			unset_ev(args[i], &var->local_export);
			unset_ev(args[i], &var->local_env);
		}
		i++;
	}
	return (ret);
}
#include "minishell.h"

static void	update_ev(t_var *var, char *old_pwd)
{
	char	*curr_pwd;
	char	*ev;

	ev = ft_strjoin("OLDPWD=", old_pwd);
	export_ev(ev, &var->local_env, TO_LOCAL_ENV);
	export_ev(ev, &var->local_export, TO_LOCAL_EXPORT);
	free(ev);
	curr_pwd = getcwd(NULL, 0);
	ev = ft_strjoin("PWD=", curr_pwd);
	export_ev(ev, &var->local_env, TO_LOCAL_ENV);
	export_ev(ev, &var->local_export, TO_LOCAL_EXPORT);
	free(curr_pwd);
	free(ev);
}

static int	change_dir(char *path, t_var *var)
{
	char	*old_pwd;

	old_pwd = getcwd(NULL, 0);
	if (chdir(path) == -1)
	{
		print_error(ft_strjoin("cd: ", path), strerror(errno));
		free(old_pwd);
		return (1);
	}
	update_ev(var, old_pwd);
	free(old_pwd);
	return (0);
}

int	builtin_cd(char **args, t_var *var)
{
	int		ret;
	char	*ev_value;

	if (!args[1])
	{
		ev_value = get_ev_value("HOME", var->local_env);
		ret = change_dir(ev_value, var);
	}
	else if (!my_strcmp(args[1], "-"))
	{
		ev_value = get_ev_value("OLDPWD", var->local_env);
		ret = change_dir(ev_value, var);
		ft_putendl_fd(ev_value, STDOUT_FILENO);
	}
	else
		return (change_dir(args[1], var));
	free(ev_value);
	return (ret);
}

#include "minishell.h"

char	*get_path(char *cmd, char **env)
{
	char	**paths;
	char	*path;
	char	*tmp;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (error_null("PATH must be set"));
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK) == 0)
			break ;
		free(path);
		path = NULL;
		i++;
	}
	if (!paths[i])
		print_error("command not found");
	free_strs(paths);
	return (path);
}

char	*get_cmd_path(char *cmd, char **env)
{
	char	*path;

	if (ft_strchr(cmd, '/') == NULL)
	{
		path = get_path(cmd, env);
		if (!path)
			return (NULL);
	}
	else
	{
		path = ft_strdup(cmd);
		if (access(path, F_OK) == -1)
		{
			free(path);
			return (error_null("file doesn't exist"));
		}
	}
	return (path);
}

void	task(char *path, t_cmd *cmd, char **env)
{
	if (execve(path, cmd->args, env) == -1)
		print_error(strerror(errno));
	exit(1);
}

int	exec_cmd(t_cmd *cmd, char **env)
{
	pid_t	pid;
	char	*path;
	int		ret;

	path = get_cmd_path(cmd->args[0], env);
	if (!path)
		return (0);
	printf("%s\n", path);
	pid = fork();
	if (pid == 0)
		task(path, cmd, env);
	waitpid(pid, &ret, 0);
	free(path);
	if (ret)
		return (0);
	return (1);
}

int	exec_cmds(t_list *cmds, char **env)
{
	int	fd[2];

	if (pipe(fd) == -1)
		return (error(strerror(errno), 0));
	
	while (cmds->next)
		; // redirect cmd stdout to stdin and exec cmd
	// exec last cmd
	return (1);
}
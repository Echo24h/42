/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:33:48 by jbettini          #+#    #+#             */
/*   Updated: 2022/04/07 01:09:41 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_var(t_var *var)
{
	free_strs(var->local_env);
}

int	main(int ac, char **av, char **env)
{
	t_var	var;
	char	*cmd_line;
	t_list	*cmds;
	int		fd;

	/*char *line = get_next_line_hd(STDIN_FILENO);
	printf("line: |%s|", line);
	exit(0);*/
	(void)ac;
	(void)av;
	var.exit_status = 0;
	var.local_env = copy_strs(env);
	set_sig(SIGQUIT, SIG_IGN);
	var.fd_stdin = dup(STDIN_FILENO);
	var.fd_stdout = dup(STDOUT_FILENO);
	while (1)
	{
		set_tty();
		set_sig(SIGINT, &sigint_handler);
		dup2(var.fd_stdin, STDIN_FILENO);
		dup2(var.fd_stdout, STDOUT_FILENO);
		var.nb_chld = 0;
		cmd_line = readline(PROMPT);
		if (!cmd_line) // EOF (^D) sent to readline
		{
			ft_putstr_fd("exit\n", STDOUT_FILENO);
			reset_tty();
			free_var(&var);
			close(var.fd_stdin);
			close(var.fd_stdout);
			exit(var.exit_status);
		}
		if (my_strcmp(cmd_line, ""))
			add_history(cmd_line);
		cmds = parse(cmd_line);
		free(cmd_line);
		//ft_lstiter(cmds, &print_cmd);
		exec_cmds(cmds, &var);
		wait_chld(&var);
		ft_lstclear(&cmds, &free_cmd);
	}
	return (0);
}

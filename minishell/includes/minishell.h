/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:51:20 by jbettini          #+#    #+#             */
/*   Updated: 2022/04/07 01:17:18 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <termios.h>
# include "libft.h"
# include "cmds.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>

# define PROMPT		"\033[1;32mminishell$> \033[0m"
# define QUOTE		39
# define DQUOTE		34
# define BACKSLASH	92

typedef struct s_global
{
	long long	g_exit_status;
	long long	g_check_hd;
}	t_global;

typedef struct s_cpt
{
	int	i;
	int	j;
	int	k;
	int	ret;
	int	equ;
}	t_cpt;

t_global	g_set;

enum	e_err
{
	CMD_NOT_FOUND = 127,
	FILE_NOT_FOUND = 1
};

enum	e_err_cmd
{
	CTRL_C = -1,
	SUCCESS,
	BUILD_ERROR,
	BF_ERROR,
	OP_ERROR,
	DUP_ERROR,
	OUT_ERROR,
	EXPAND_ERROR,
	PERM_ERROR,
	CMD_ERROR = 127
};

enum	e_mod
{
	IN_ENV,
	OUT_OF_ENV,
	IN_PIPE,
	LAST_PIPE_BLOCK,
	IN_MAIN,
	IN_CHILD,
	SET,
	DESTROY_SET
};

enum	e_redir_type
{
	WORD,
	PIPE,
	REDIR_L,
	REDIR_LL,
	REDIR_R,
	REDIR_RR
};

typedef struct s_token
{
	int		type;
	char	*val;
}	t_token;

typedef struct s_env
{
	t_list	*envp;
	t_list	*ex_env;
	char	**nbtfke;
	char	**path;
	char	*cmd_path;
	int		oldstdin;
	int		oldstdout;
	int		out_check;
	int		child;
	int		last_pid;
}		t_env;

typedef struct	s_var
{
	char	**local_env;
	int		exit_status;
	int		fd_stdin;
	int		fd_stdout;
	int		nb_chld;
}	t_var;

//		index_str;
char	*index_str(const char *str, int index);

//		redirect.c
int	redirect_stdin(t_list *redir_in);
int	redirect_stdout(t_list *redir_out);

//		heredoc.c
int	handle_hd(t_list *redir_in);

//		exec_cmds.c
void	exec_cmds(t_list *cmds, t_var *var);

//		wait_chld.c
void	wait_chld(t_var *var);

//		dev.c
void	print_cmd(void *ptr);
void	print_redir(void *ptr);
void	print_tokens(t_list *tokens);

//		error.c
void	print_error(char *cmd, const char *msg);
void	exit_error(char *cmd, const char *msg, int code);
int		error(char *cmd, const char *msg, int code);
void	*error_null(char *cmd, const char *msg);
void	error_manag(int ret);

//		expand_ev.c
void	expand_word(char **word, char **env);
char	**expand_args(char **args, char **env);
int		redir_expanded_is_valid(char *word_expanded);
int		expand_redir(t_list *redirs, char **env);
//int		expand_ev(t_list *cmds, t_env *env);
int		expand_ev(t_cmd *cmd, t_env *env);

//		expand_utils.c
char	*get_ev_name(char *str);
char	*get_ev_value(char *ev_name, char **env);
void	rearrange_word(char **word, int *i, char **env);
void	delete_quotes(char **word);

//		free.c
void	free_token(void *ptr);
void	free_redir(void *ptr);
void	free_cmd(void *ptr);

//		ft_strtok.c
char	**ft_strtok(char *str, char *delim);

//		get_cmds.c
t_list	*get_cmds(t_list *tokens);

//		get_tokens.c
t_list	*get_tokens(char *line);
int		get_len_word(char *line);

//		main.c
t_env	*env_manag(char **env, t_env *to_free, int mod);
void	wait_this_fk_process(t_env *env);
int		minishell(t_env *env_set);
int		ft_exit(char **args, int print_exit, t_env *env_set);
int		main(int ac, char **av, char **env);

//		parse.c
t_list	*parse(char *line);
char	*parse_cmd(char **path, char **cmd);
void	print_strs(char **strs);
void	init_cpt(t_cpt *cpt);

// 		signals.c                                       
void	sigint_handler(int signum);
void	sig_hd_handler(int signum);
void	set_sig(int signum, void (*handler)(int));

//		strs.c
void	free_strs(char **strs);
char	**copy_strs(char **strs);
int		strs_len(char **strs);
char	**strs_append(char **strs, const char *str);
char	**strs_join(char **strs1, char **strs2);

//		tty.c
void	set_tty(void);
void	reset_tty(void);

//		utils_0.c.c
char	*str_insert(char *dst, const char *src, size_t n);
char	*get_str_truncated(const char *str, int start, int len);
char	*trunc_str(char *str, int start, int len);
int		get_token_type(t_token *tok);
char	*get_token_value(t_token *tok);

//		utils_1.c
int		is_symbol(char c);
int		is_whitespace(char c);
void	skip_whitespace(char **line);
void	my_strncpy(char *dst, const char *src, int n);
int		my_strcmp(char *s1, char *s2);

#endif

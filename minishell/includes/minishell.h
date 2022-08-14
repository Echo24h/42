/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <ydanset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:51:20 by jbettini          #+#    #+#             */
/*   Updated: 2022/08/14 13:32:47 by ydanset          ###   ########.fr       */
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
# include <limits.h>

/*
	echo test f2 salut
	> f0 ; > ydanset
	&1>
*/

# define PROMPT		"\033[1;32mminishell$> \033[0m"

# define TO_LOCAL_EXPORT 1
# define TO_LOCAL_ENV 2

enum	e_err
{
	CMD_NOT_FOUND = 127
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

typedef struct	s_var
{
	char			**local_env;
	char			**local_export;
	int				exit_status;
	int				fd_stdin;
	int				fd_stdout;
	int				nb_chld;
	int				last_chld_pid;
	int				is_simple_builtin_cmd;
	struct termios	usr_tty_config;
	int				exit_minishell;
}	t_var;

typedef struct	s_global
{
	int	in_hd;
	int	sigint_in_hd;
}	t_global;

t_global	g;

//		builtins
int	builtin_pwd(void);
int	builtin_env(t_var *var);
int	builtin_exit(char **args, t_var *var);
int	builtin_export(char **args, t_var *var);
int	builtin_unset(char **args, t_var *var);
int	builtin_cd(char **args, t_var *var);
int	builtin_echo(char **args);
void	export_ev(char *ev, char ***env, int mode);

//		get_next_line_hd.c
char	*get_next_line_hd(int fd);

//		index_str.c
char	*index_str(const char *str, int index);

//		redirect.c
int	redirect(t_list *redirs, t_var *var);

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
void	print_strs(char **strs);

//		error.c
void	print_error(char *cmd, const char *msg);
void	exit_error(char *cmd, const char *msg, int code);
int		error(char *cmd, const char *msg, int code);
void	*error_null(char *cmd, const char *msg);

//		expand.c
char	**expand_args(char **args, t_var *var);
int		expand_redir(t_redir *redir, t_var *var);
void	expand_word(char **word, t_var *var);

//		expand_utils.c
char	*get_ev_name(char *str);
char	*get_ev_value(char *ev_name, char **env);
void	rearrange_word(char **word, int *i, t_var *var);
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

//		parse.c
t_list	*parse(char *line);

// 		signals.c                                       
void	sigint_handler(int signum);
void	set_sig(int signum, void (*handler)(int));

//		strs.c
void	free_strs(char **strs);
char	**copy_strs(char **strs);
int		strs_len(char **strs);
char	**strs_append(char **strs, const char *str);
char	**strs_join(char **strs1, char **strs2);
char	**strs_del_index(char **strs, int index);

//		tty.c
void	tty_hide_ctrl(void);
void	tty_show_ctrl(void);
void	save_usr_tty_config(t_var *var);
void	reset_usr_tty_config(t_var *var);

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

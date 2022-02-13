#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include "libft.h"
# include "cmds.h"

# define WORD 0
# define PIPE 1
# define REDIR_L 2
# define REDIR_LL 3
# define REDIR_R 4
# define REDIR_RR 5

typedef struct s_token
{
	int		type;
	char	*val;
}	t_token;

// expand 
void	expand_ev(char **line, char **env);

// parse
t_list	*parse(char *line);

// get_tokens
t_list	*get_tokens(char *line);

// get_cmds
t_list	*get_cmds(t_list *tokens);

// utils
int		is_symbol(char c);
int		is_whitespace(char c);
void	skip_whitespace(char **line);
int		my_strcmp(char *s1, char *s2);
void	my_strncpy(char *dst, const char *src, int n);
char	*str_insert(char *dst, const char *src, size_t n);
char	*trunc_str(char *str, int start, int len);
char	*get_str_truncated(const char *str, int start, int len);

// free
void	free_token(void *token);
void	free_cmd(void *ptr);

// strs
char	**copy_strs(char **strs);
void	free_strs(char **strs);
int		strs_len(char **strs);
char	*strs_join(char **strs1, char **strs2);
char	**strs_append(char **strs, const char *str);
char	*strs_chr(char **strs, char *s);
void	print_strs(char **strs);

// error
void	exit_error(char *msg, int code);
int 	error(char *msg, int code);
void	print_error(char *msg);

// dev
void	print_cmd(void *ptr);
void	print_tokens(t_list *tokens);
void	print_redir(void *ptr);

#endif
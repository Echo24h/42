#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <curses.h>
# include <term.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_envvar
{
	char	*name;
	char	*value;
}	t_envvar;

// expand 
void	expand(char **line, t_envvar *envvar);
void	insert_str(char **dst, char *src, size_t n);
char	*trunc_str(char *str, int start, int len);
void	my_strncpy(char *dst, char *src, int n);
void	exit_error(char *msg, int code);

#endif
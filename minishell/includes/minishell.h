#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <curses.h>
# include <term.h>
# include <readline/readline.h>
# include <readline/history.h>

// expand 
void	expand(char **line, char **env);
int		insert_str(char **dst, char *src, size_t n);
char	*trunc_str(const char *str, int start, int len);
char	*trunc_and_free_str(char *str, int start, int len);
void	my_strncpy(char *dst, const char *src, int n);

// strs
char	**copy_strs(char **strs);
void	free_strs(char **strs);

// error
void	exit_error(char *msg, int code);
int		error(char *msg, int code);

// dev
void	print_strs(char **strs);

#endif
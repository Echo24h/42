#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <curses.h>
# include <term.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_cap
{
	char	*clean;
	char	*font_color;
	char	*bg_color;
	char	*bold;
	char	*reset;
	char	*underline;
	char	*cursor;
}	t_cap;

#endif
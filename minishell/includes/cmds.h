#ifndef CMDS_H
# define CMDS_H

# include "libft.h"

typedef struct	s_redir
{
	int		type; // "<" or "<<" or ">" or ">>"
	char	*filename;
}	t_redir;

typedef struct	s_cmd
{
	char	**args; // args[0] = command
	t_list	*redir_in; // '<' and '<<' ; ordered from first seen to last seen
	t_list	*redir_out; // '>' and '>>' ; ordered from first seen to last seen
	// 'redir_in/out->content' will be a pointer on a 't_redir' structure
}	t_cmd;

/*
	. your execution fct will receive a 't_list *cmds' variable

	. 'cmds->content' will be a pointer on a 't_cmd' structure

	. between each 'cmds' elements we assume there is a pipe
*/

#endif

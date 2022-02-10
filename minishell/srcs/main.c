#include "minishell.h"
#include "libft.h"
#include "cmds.h"

# define PROMPT "minishell> "

int	is_in_env(char **env, char *ev_name)
{
	int		i;
	char	*tmp;

	if (!env)
		return (0);
	while (env[i])
	{
		tmp = get_ev_name(env[i]); // !!!
		if (!ft_strcmp(tmp, ev_name))
		{
			free(tmp);
			return (1);
		}
		free(tmp);
		i++;
	}
	return (0);
}

/*
	to do:
		- handle errors properly
*/
int	builtin_env(char **local_env, char **args)
{
	if (strs_len(args) > 1)
	{
		print_error("env command doesn't take arguments");
		return (EXIT_FAILURE);
	}
	print_strs(local_env);
	return (EXIT_SUCCESS);
}

static int	check_ev_name(char *arg)
{
	int	i;

	if (!ft_isalpha(arg[0]) && arg[0] != '_')
		return (0);
	i = 1;
	while (arg[i] && arg[i] != '=')
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return (0);
		i++;
	}
	if (arg[i] != '=')
		return (0);	
	return (1);
}

/*
	to do:
		- handle errors properly
*/
int	builtin_export(char **local_env, char **args)
{
	int		i;
	char	*new_ev_name;
	int		ret;

	ret = 0;
	i = 1;
	while (args[i])
	{
		if (!check_ev_name(args[i]))
		{
			print_error("Invalid env. variable name");
			ret = 1;
		}
		else
		{
			new_ev_name = get_ev_name(args[i]);
			if (!is_in_env(local_env, new_ev_name))
			{
				local_env = strs_append(local_env, args[i]);
				if (!local_env)
				{
					print_error(strerror(errno));
					return (EXIT_FAILURE);
				}
			}
			else
			{
				print_error("Env. variable already exists");
				ret = 1;
			}
			free(new_ev_name);
			i++;
		}
	}
	return (ret);
}

int	is_symbol(char c)
{
	if (c == '<' || c == '>' || c == '|')
		return (1);
	return (0);
}

int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	skip_whitespace(char **line)
{
	while (is_whitespace(**line))
		(*line)++;
}

int	get_len_word(char *line)
{
	int		len_word;
	char	quote;

	len_word = 0;
	while (*line && !is_whitespace(*line) && !is_symbol(*line))
	{
		if (*line == '"' || *line == '\'')
		{
			quote = *line;
			line++;
			while (*line && *line != quote)
			{
				len_word++;
				line++;
			}
			if (!*line)
				return (-1);
			line++;
		}
		else
		{
			len_word++;
			line++;
		}
	}
	return (len_word);
}

char	*extract_word(char **line)
{
	char	*word;
	char	quote;
	int		i;

	i = get_len_word(*line); 
	if (i == - 1)
		return (NULL);
	word = malloc(i + 1);
	if (!word)
		exit_error(strerror(errno), EXIT_FAILURE);
	i = 0;
	while (**line && !is_whitespace(**line) && !is_symbol(**line))
	{
		if (**line == '"' || **line == '\'')
		{
			quote = **line;
			*line += 1;
			while (**line && **line != quote)
				word[i++] = *((*line)++);
			*line += 1;
		}
		else
			word[i++] = *((*line)++);
	}
	word[i] = '\0';
	return (word);
}

t_token	*get_next_token(char **line)
{
	t_token	*tok;

	tok = malloc(sizeof(t_token) * 1);
	if (!tok)
		exit_error(strerror(errno), EXIT_FAILURE);
	tok->val = NULL;
	if (**line == '|')
		tok->type = PIPE;
	else if (**line == '<' && *(*line + 1) == '<')
	{
		tok->type = REDIR_LL;
		if (*(*line + 2) == '<')
			; // syntax error near unexpected token `<'
	}
	else if (**line == '<')
		tok->type = REDIR_L;
	else if (**line == '>' && *(*line + 1) == '>')
	{
		tok->type = REDIR_RR;
		if (*(*line + 2) == '>')
			; // syntax error near unexpected token `>'
	}
	else if (**line == '>')
		tok->type = REDIR_R;
	else
	{
		tok->type = WORD;
		tok->val = extract_word(line);
		if (!tok->val)
			; // error: unclosed quote
		return (tok);
	}
	if ((**line == '<' && *(*line + 1) == '<')
		|| (**line == '>' && *(*line + 1) == '>'))
		*line += 2;
	else
		*line += 1;
	return (tok);
}

t_list	*get_tokens(char *line)
{
	t_list	*tokens;
	t_list	*new;
	t_token	*tok;

	tokens = NULL;
	skip_whitespace(&line);
	while (*line)
	{
		tok = get_next_token(&line);
		new = ft_lstnew(tok);
		if (!new)
			exit_error(strerror(errno), EXIT_FAILURE);
		ft_lstadd_back(&tokens, new);
		skip_whitespace(&line);
	}
	return (tokens);
}

void	set_redir(t_cmd *cmd, t_list **tokens)
{
	t_token	*tok;
	t_list	*new;
	t_redir	*redir;

	tok = (*tokens)->content;
	redir = malloc(sizeof(t_redir) * 1);
	if (!redir)
		exit_error(strerror(errno), EXIT_FAILURE);
	redir->type = tok->type;
	*tokens = (*tokens)->next;
	if (!*tokens)
		; // error: missing filename (or keyword for heredoc?)
	tok = (*tokens)->content;
	if (tok->type != WORD)
		; // error: missing filename (or keyword for heredoc?)
	redir->filename = ft_strdup(tok->val);
	if (!redir->filename)
		exit_error(strerror(errno), EXIT_FAILURE);
	new = ft_lstnew(redir);
	if (!new)
		exit_error(strerror(errno), EXIT_FAILURE);
	if (redir->type == REDIR_LL || redir->type == REDIR_L)
		ft_lstadd_back(&cmd->redir_in, new);
	else
		ft_lstadd_back(&cmd->redir_out, new);
}

void	init_cmd(t_cmd **cmd)
{
	*cmd = malloc(sizeof(t_cmd) * 1);
	if (!*cmd)
		exit_error(strerror(errno), EXIT_FAILURE);
	(*cmd)->args = NULL;
	(*cmd)->redir_in = NULL;
	(*cmd)->redir_out = NULL;
}

t_cmd	*get_next_cmd(t_list **tokens)
{
	t_cmd	*cmd;
	t_token	*tok;

	if (!*tokens)
		return (NULL);
	init_cmd(&cmd);
	tok = (*tokens)->content;
	while (*tokens && tok->type != PIPE)
	{
		if (tok->type == WORD)
		{
			cmd->args = strs_append(cmd->args, tok->val);
			if (cmd->args)
				exit_error(strerror(errno), EXIT_FAILURE);
		}
		else
			set_redir(cmd, tokens);
		*tokens = (*tokens)->next;
		if (*tokens)
			tok = (*tokens)->content;
	}
	if (*tokens)
	{
		// we reach a pipe
		*tokens = (*tokens)->next;
	}
	return (cmd);
}

t_list	*get_cmds(t_list *tokens)
{
	t_list	*cmds;
	t_list	*new;
	t_cmd	*cmd;

	cmds = NULL;
	while (tokens)
	{
		cmd = get_next_cmd(&tokens);
		new = ft_lstnew(cmd);
		if (!new)
			exit_error(strerror(errno), EXIT_FAILURE);
		ft_lstadd_back(&cmds, new);
	}
	return (cmds);
}

void	free_token(void *token)
{
	t_token	*tok;

	tok = token;
	free(tok->val);
	free(tok);
}

/*
	to do :
		- make a custom prompt
		- handle errors

	must ensure that :
		- env variables must not start by a digit
		- env variables consist of alpha, numeric and/or '_' characters
		- quotes are closed, handle that in parsing
*/
int	main(int ac, char **av, char **env)
{
	char	*line;
	char	**local_env;
	t_list	*tokens;

	local_env = copy_strs(env);
	if (!local_env)
		exit_error(strerror(errno), EXIT_FAILURE);
	line = readline(PROMPT);
	while (line)
	{
		expand_ev(&line, local_env);
		ft_printf("%s\n", line);
		tokens = get_tokens(line);
		print_tokens(tokens);
		get_cmds(tokens);
		ft_lstclear(&tokens, &free_token);
		free(line);
		line = readline(PROMPT);
	}
	free_strs(local_env);
	return (0);
}


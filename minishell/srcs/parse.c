/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:26:44 by ydanset           #+#    #+#             */
/*   Updated: 2022/04/03 21:49:09 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*parse(char *line)
{
	t_list	*tokens;
	t_list	*cmds;

	tokens = get_tokens(line);
	if (!tokens)
		return (NULL);
	//print_tokens(tokens);
	cmds = get_cmds(tokens);
	ft_lstclear(&tokens, &free_token);
	return (cmds);
}

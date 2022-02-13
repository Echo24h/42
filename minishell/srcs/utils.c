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

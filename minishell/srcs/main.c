#include "minishell.h"

# define PROMPT "minishell> "

int	ft_putchar(int x)
{
	unsigned char	c;

	c = x;
	return (write(1, &c, 1));
}

int	on_error(char *msg, int code)
{
	printf("Error: %s\n", msg);
	return (code);
}

void	parse_line(char *line)
{
	return ;
}

int	init_term(void)
{
	int		n;
	char	*term_type;

	term_type = getenv("TERM");
	if (!term_type)
		return (on_error("TERM must be set (see 'env')", 0));
	n = tgetent(NULL, term_type);
	if (n == -1)
		return (on_error("Could not access to the termcap database", 0));
	if (!n)
		return (on_error("Terminal type is not defined in termcap database (or have too few informations)", 0));
	return (1);
}

void	init_cap(t_cap *cap)
{
	cap->clean = tgetstr("cl", NULL);
	cap->font_color = tgetstr("AF", NULL);
	cap->bg_color = tgetstr("AB", NULL);
	cap->reset = tgetstr("me", NULL);
	cap->bold = tgetstr("md", NULL);
	cap->underline = tgetstr("us", NULL);
	cap->cursor = tgetstr("cm", NULL);
}

void	print_term_dim(int nb_col, int nb_row)
{
	printf("DIM : %d %d\n", nb_col, nb_row);
}

int	main(int ac, char **av)
{
	char	*line;
	int		nb_col;
	int		nb_row;
	t_cap	cap;
	
	if (!init_term())
		return (EXIT_FAILURE);

	nb_col = tgetnum("co");
	nb_row = tgetnum("li");
	print_term_dim(nb_col, nb_row);

	init_cap(&cap);

	tputs(cap.clean, 1, &ft_putchar);

	tputs(tparm(cap.font_color, COLOR_GREEN), 1, &ft_putchar);
	tputs(tparm(cap.bg_color, COLOR_YELLOW), 1, &ft_putchar);
	tputs(cap.bold, 1, &ft_putchar);

	printf("Writing in green on yellow bitch\n");

	tputs(tgoto(cap.cursor, nb_col / 2, nb_row / 2), 1, &ft_putchar);

	printf(":D\n");

	tputs(cap.reset, 1, &ft_putchar);
	
	tputs(cap.bold, 1, &ft_putchar);
	line = readline(PROMPT);
	tputs(cap.reset, 1, &ft_putchar);
	while (line)
	{
		tputs(cap.underline, 1, &ft_putchar);
		printf("%s\n", line);
		tputs(cap.reset, 1, &ft_putchar);

		parse_line(line);
		free(line);

		tputs(cap.bold, 1, &ft_putchar);
		line = readline(PROMPT);
		tputs(cap.reset, 1, &ft_putchar);
	}
	system("leaks minishell");
	return (EXIT_SUCCESS);
}

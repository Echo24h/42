#include "libft.h"

void	print_error(char *msg)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	exit_error(char *msg, int code)
{
	print_error(msg);
	exit(code);
}

int	return_error(char *msg, int code)
{
	print_error(msg);
	return (code);
}

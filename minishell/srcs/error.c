/*
	to do :
		- write errors on stderr
*/

#include "libft.h"

void	exit_error(char *msg, int code)
{
	ft_printf("Error: %s\n", msg);
	exit(code);
}

int	error(char *msg, int code)
{
	ft_printf("Error: %s\n", msg);
	return (code);
}
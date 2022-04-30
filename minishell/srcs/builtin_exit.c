#include "minishell.h"

static unsigned long long	ft_atoull(char *nbr)
{
	unsigned long long	res;

	res = 0;
	while (ft_isdigit(*nbr))
		res = res * 10 + ((int)*(nbr++) - 48);
	return (res);
}

static long long	ft_atoll(char *nbr)
{
	long long	res;
	int			neg;
	
	neg = 0;
	if (*nbr == '-')
	{
		neg = 1;
		nbr++;
	}
	res = 0;
	while (ft_isdigit(*nbr))
		res = res * 10 - ((int)*(nbr++) - 48);
	if (neg)
		return (res);
	return (-res);
}

static int	is_valid_nbr(char *nbr)
{
	int					neg;
	unsigned long long	n;

	neg = 0;
	if (*nbr == '-')
	{
		neg = 1;
		nbr++;
	}
	if (ft_strlen(nbr) > 19)
		return (0);
	n = ft_atoull(nbr);
	if ((neg && n > (unsigned long long)LONG_MAX + 1) || (!neg && n > LONG_MAX))
		return (0);
	return (1);
}

int	builtin_exit(char **args, t_var *var)
{
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	var->exit_minishell = 1;
	if (strs_len(args) == 1)
		return (0);
	if (!is_number(args[1]) || !is_valid_nbr(args[1]))
	{
		print_error(ft_strjoin("exit: ", args[1]), "numeric argument required");
		return (255);
	}
	if (strs_len(args) > 2)
	{
		var->exit_minishell = 0;
		print_error(ft_strdup("exit"), "too many arguments");
		return (1);
	}
	return (ft_atoll(args[1]) % 256);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <ydanset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:55:44 by ydanset           #+#    #+#             */
/*   Updated: 2021/12/17 17:55:44 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	set_buff(char *buff, unsigned int c)
{
	int	n;

	n = 8;
	while (n--)
	{
		buff[n] = c % 2 + 48;
		c /= 2;
	}
}

static int	parse(int ac, char **av, pid_t *server_pid)
{
	if (ac != 3)
		return (0);
	if (!is_number(av[1]))
		return (0);
	*server_pid = ft_atoi(av[1]);
	if ((int)*server_pid < 0)
		return (0);
	return (1);
}

static void	send_bit(pid_t server_pid, char *client_message)
{
	static char		*msg = NULL;
	static pid_t	pid = 0;
	static int		i = 0;
	static char		buff[8];

	if (!msg)
		msg = ft_strdup(client_message);
	if (!msg)
		exit(EXIT_FAILURE);
	if (!pid)
		pid = server_pid;
	if (i % 8 == 0)
		set_buff(buff, msg[i / 8]);
	i++;
	if (buff[(i - 1) % 8] == '0')
	{
		if (kill(pid, SIGUSR1) == -1)
			exit_and_free(EXIT_FAILURE, msg);
	}
	else if (kill(pid, SIGUSR2) == -1)
		exit_and_free(EXIT_FAILURE, msg);
}

static void	sigusr_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("The data has been sent successfully!\n");
		exit(EXIT_SUCCESS);
	}
	else
		send_bit(0, 0);
}

int	main(int ac, char **av)
{
	pid_t				server_pid;
	struct sigaction	setup_sigusr1;
	struct sigaction	setup_sigusr2;
	sigset_t			block_mask;

	if (!parse(ac, av, &server_pid))
		return (EXIT_FAILURE);
	if (sigemptyset(&block_mask) == -1
		|| sigaddset(&block_mask, SIGUSR1) == -1
		|| sigaddset(&block_mask, SIGUSR2) == -1)
		return (EXIT_FAILURE);
	setup_sigusr1.sa_handler = &sigusr_handler;
	setup_sigusr1.sa_mask = block_mask;
	setup_sigusr1.sa_flags = 0;
	setup_sigusr2.sa_handler = &sigusr_handler;
	setup_sigusr2.sa_mask = block_mask;
	setup_sigusr2.sa_flags = 0;
	if (sigaction(SIGUSR1, &setup_sigusr1, NULL) == -1
		|| sigaction(SIGUSR2, &setup_sigusr2, NULL) == -1)
		return (EXIT_FAILURE);
	send_bit(server_pid, av[2]);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}

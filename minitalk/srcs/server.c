/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <ydanset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:55:48 by ydanset           #+#    #+#             */
/*   Updated: 2021/12/17 18:14:09 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	read_byte(char *byte)
{
	unsigned int	c;
	int				n;

	c = 0;
	n = 8;
	while (n--)
		c += (byte[n] - '0') * (1 << (7 - n));
	return (c);
}

static char	*ft_append_char_to_str(char *str, char c)
{
	int		i;
	char	*res;

	res = ft_calloc(ft_strlen(str) + 2, 1);
	if (!res)
	{
		free(str);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (str && str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = c;
	free(str);
	return (res);
}

static int	addto_byte(char bit, pid_t client_pid)
{
	static int		i = 0;
	static char		byte[8];
	static char		*msg = NULL;
	unsigned char	c;

	byte[i++] = bit;
	if (i > 7)
	{
		i = 0;
		c = read_byte(byte);
		msg = ft_append_char_to_str(msg, c);
		if (c == '\0')
		{
			write(1, msg, ft_strlen(msg));
			free(msg);
			msg = NULL;
			kill(client_pid, SIGUSR1);
			return (0);
		}
	}
	return (1);
}

static void	sigusr_handler(int signum, siginfo_t *info, void *context)
{
	static pid_t	client_pid = 0;

	(void)context;
	if (!client_pid && !info->si_pid)
		ft_printf("Error : failed to load client PID.\n");
	else if (!client_pid)
		client_pid = info->si_pid;
	if (signum == SIGUSR1)
	{
		if (!addto_byte('0', client_pid))
			client_pid = 0;
	}
	else if (!addto_byte('1', client_pid))
		client_pid = 0;
	if (client_pid)
		kill(client_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	setup_sigusr1;
	struct sigaction	setup_sigusr2;
	sigset_t			block_mask;

	ft_printf("PID : %d\n", (int)getpid());
	if (sigemptyset(&block_mask) == -1
		|| sigaddset(&block_mask, SIGUSR1) == -1
		|| sigaddset(&block_mask, SIGUSR2) == -1)
		return (EXIT_FAILURE);
	setup_sigusr1.sa_sigaction = &sigusr_handler;
	setup_sigusr1.sa_mask = block_mask;
	setup_sigusr1.sa_flags = SA_SIGINFO;
	setup_sigusr2.sa_sigaction = &sigusr_handler;
	setup_sigusr2.sa_mask = block_mask;
	setup_sigusr2.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &setup_sigusr1, NULL) == -1
		|| sigaction(SIGUSR2, &setup_sigusr2, NULL) == -1)
		return (EXIT_FAILURE);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}

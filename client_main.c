/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:09:12 by takhayas          #+#    #+#             */
/*   Updated: 2025/11/03 01:44:12 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_is_get_signal;

void	ack_handler(int signo, siginfo_t *info, void *context)
{
	(void)signo;
	(void)context;
	(void)info;
	g_is_get_signal = 1;
}

int	send_char_as_bit(pid_t pid, char c)
{
	int	send_bits;
	int	is_kill_error;

	send_bits = 0;
	while (send_bits < 8)
	{
		g_is_get_signal = 0;
		if ((c & (1 << send_bits)) != 0)
			is_kill_error = kill(pid, SIGUSR2);
		else
			is_kill_error = kill(pid, SIGUSR1);
		if (is_kill_error == -1)
			return (1);
		while (g_is_get_signal == 0)
			usleep(10);
		usleep(30);
		send_bits++;
	}
	return (0);
}

int	pid_parser(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	set_sigaction_client(struct sigaction *sa)
{
	sa->sa_flags = SA_SIGINFO;
	sa->sa_sigaction = ack_handler;
	sigemptyset(&sa->sa_mask);
	sigaddset(&sa->sa_mask, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa_client;
	pid_t				server_pid;
	int					i;

	if (argc != 3 || pid_parser(argv[1]))
		return (1);
	server_pid = (pid_t) ft_atoi(argv[1]);
	if (server_pid <= 0)
		return (1);
	set_sigaction_client(&sa_client);
	if (sigaction(SIGUSR1, &sa_client, NULL) == -1)
		return (1);
	i = 0;
	while (argv[2][i])
	{
		if (send_char_as_bit(server_pid, argv[2][i]))
			return (1);
		i++;
	}
	if (send_char_as_bit(server_pid, '\0'))
		return (1);
	return (0);
}

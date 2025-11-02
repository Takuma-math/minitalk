/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:37:48 by takhayas          #+#    #+#             */
/*   Updated: 2025/11/02 22:15:37 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	reset_server(pid_t *pid, int *bit_count, char *c, siginfo_t *info)
{
	*pid = info->si_pid;
	*bit_count = 0;
	*c = 0;
}

void	signal_handler(int signo, siginfo_t *info, void *context)
{
	static pid_t	current_client_pid;
	static int		bit_counter;
	static char		current_char;

	(void)context;
	if (current_client_pid != info->si_pid)
		reset_server(&current_client_pid, &bit_counter, &current_char, info);
	if (signo == SIGUSR2)
		current_char = current_char | (1 << bit_counter);
	bit_counter++;
	if (bit_counter == 8)
	{
		if (current_char == '\0')
			write (1, "\n", 1);
		else
			write (1, &current_char, 1);
		bit_counter = 0;
		current_char = 0;
	}
	return ;
}

void	set_sigaction(struct sigaction *sa)
{
	sa->sa_flags = SA_SIGINFO;
	sa->sa_sigaction = signal_handler;
	sigemptyset(&sa->sa_mask);
	sigaddset(&sa->sa_mask, SIGUSR1);
	sigaddset(&sa->sa_mask, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("%d\n", getpid());
	set_sigaction(&sa);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (1);
	while (1)
		pause();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:37:48 by takhayas          #+#    #+#             */
/*   Updated: 2025/10/27 21:23:44 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signo)
{
	static int	bit_counter;
	static char	current_char;

	if (signo == SIGUSR2)
		current_char = current_char | (1 << bit_counter);
	bit_counter++;
	if (bit_counter == 8)
	{
		if (current_char == '\0')
			write (1, "\n", 1);
		else
			write (1, &current_char, 1);
	}
	bit_counter = 0;
	current_char = 0;
	return ;
}

void	set_sigaction(struct sigaction *sa)
{
	sa->sa_handler = signal_handler;
	sigemptyset(&sa->sa_mask);
	sigaddset(&sa->sa_mask, SIGUSR1);
	sigaddset(&sa->sa_mask, SIGUSR2);
	sa->sa_flags = 0;
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("%d\n", getpid());
	set_sigaction(&sa);
}

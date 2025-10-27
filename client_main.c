/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:09:12 by takhayas          #+#    #+#             */
/*   Updated: 2025/10/27 15:43:26 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signo)
{
	static int	bit_counter;
	static char	current_char;

	if (signo == SIGUSR2)
		current_char = current_char | 1 << bit_counter;
	bit_counter++;
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	return (0);
}

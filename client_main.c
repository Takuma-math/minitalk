/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:09:12 by takhayas          #+#    #+#             */
/*   Updated: 2025/11/01 23:36:45 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
int send_char_as_bit(pid_t pid, char c)
{
	int	send_bits;
	int	is_kill_error;

	send_bits = 0;
	while (send_bits < 8)
	{
		if ((c & (1 << send_bits))!= 0)
		{
			is_kill_error = kill(pid, SIGUSR2);
			usleep(100);
		}

		else
		{
			is_kill_error = kill(pid, SIGUSR1);
			usleep(100);
		}
		if (is_kill_error == -1)
			return (1);
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
int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*string_to_send;
	int		i;

	if (argc != 3 || pid_parser(argv[1]))
		return (1);
	server_pid = (pid_t) ft_atoi(argv[1]);
	if (server_pid <= 0)
		return (1);
	string_to_send = argv[2];
	i = 0;
	while (string_to_send[i])
	{
		if (send_char_as_bit(server_pid, string_to_send[i]))
			return (1);
		i++;
	}
	if (send_char_as_bit(server_pid, '\0'))
        return (1);
	return (0);
}

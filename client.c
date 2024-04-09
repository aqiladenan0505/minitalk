/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:13:34 by aadenan           #+#    #+#             */
/*   Updated: 2024/03/18 16:23:07 by aadenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(pid_t server_pid, char *str)
{
	int				num_bits;
	unsigned char	current_byte;

	while (*str != '\0')
	{
		current_byte = *str;
		num_bits = 8;
		while (num_bits > 0)
		{
			if (current_byte & (1 << 7))
			{
				if (kill(server_pid, SIGUSR1) == -1)
					write(2, "SIGUSR1 Client Error", 20);
			}
			else
			{
				if (kill(server_pid, SIGUSR2) == -1)
					write(2, "SIGUSR2 Client Error", 20);
			}
			usleep(350);
			current_byte <<= 1;
			num_bits--;
		}
		str++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;

	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		send_bits(server_pid, argv[2]);
	}
	else
	{
		write(2, "Invalid arguments\n", 18);
		return (1);
	}
	return (0);
}

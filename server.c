/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:36:11 by aadenan           #+#    #+#             */
/*   Updated: 2023/12/29 17:58:40 by aadenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

struct	s_globaldata
{
	int				bit_position;
	int				data_ready;
	unsigned char	buffer;
};

struct s_globaldata	g_data = {-1, 0, 0};

void	handle_signal(int signum, siginfo_t *info, void *ucontent)
{
	(void)info;
	(void)ucontent;
	if (g_data.bit_position < 0)
		g_data.bit_position = 7;
	if (signum == SIGUSR1)
		g_data.buffer |= (1 << g_data.bit_position);
	else if (signum == SIGUSR2)
		g_data.buffer &= ~(1 << g_data.bit_position);
	g_data.bit_position--;
	if (g_data.bit_position < 0)
		g_data.data_ready = 1;
}

void	config_signals(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		write(2, "SIGUSR1 signal handler\n", 23);
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(2, "SIGUSR2 signal handler\n", 23);
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("SERVER PID = %d\n", pid);
	config_signals();
	while (1)
	{
		if (g_data.data_ready == 1)
		{
			write(1, &g_data.buffer, 1);
			g_data.buffer = 0;
			g_data.bit_position = -1;
			g_data.data_ready = 0;
		}
		usleep(10000);
	}
	return (0);
}

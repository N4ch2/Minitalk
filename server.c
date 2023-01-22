/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joramire <joramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:13:42 by joramire          #+#    #+#             */
/*   Updated: 2023/01/22 20:09:38 by joramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	sig_handler(int sigtype, siginfo_t *info, ucontext_t *uap)
{
	ucontext_t	*uc;
	static int	c = 0;
	static int	recieved_bits = 0;
	static int	current_pid = 0;

	uc = (ucontext_t *)uap;
	if (info->si_pid != current_pid)
	{
		ft_printf("\nNew message from PID: %d\n", info ->si_pid);
		current_pid = info ->si_pid;
	}
	if (sigtype == SIGUSR1)
	{
		c = c | (1 << (recieved_bits % 8));
	}
	recieved_bits++;
	if ((recieved_bits % 8) == 0 && recieved_bits > 0)
	{
		ft_printf("%c", c);
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	signals;

	if (argc != 1)
	{
		ft_printf("Error: this program dont take parameters \n");
	}
	else
	{
		signals.sa_sigaction = (void *)sig_handler;
		sigemptyset(&signals.sa_mask);
		signals.sa_flags = SA_RESTART | SA_SIGINFO;
		sigaction(SIGUSR1, &signals, NULL);
		sigaction(SIGUSR2, &signals, NULL);
		ft_printf("%s PID: %d\n", argv[0] + 2, getpid());
		while (argc == 1)
		{
			pause();
		}
	}
	return (0);
}

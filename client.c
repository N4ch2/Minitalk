/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:05:05 by joramire          #+#    #+#             */
/*   Updated: 2023/01/24 17:45:31 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include "Printf/ft_printf.h"

int	pass = 0;

void	sig_handler(int sigtype)
{
	int		aux;

	aux = sigtype;
	pass = 1;
}

void	ft_send_bytes(int c, int server_pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		pass = 0;
		if ((c & (1 << bit)) != 0)
		{
			kill(server_pid, SIGUSR1);
		}
		else
		{
			kill(server_pid, SIGUSR2);
		}
		bit++;
		while (pass == 0)
		{
			usleep(1);	
		}
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	signals;
	int					i;

	if (argc != 3)
	{
		ft_printf("Error: number of arguments incorrect\n");
		return (1);
	}
	else
	{
		signals.sa_handler = sig_handler;
		sigemptyset(&signals.sa_mask);
		signals.sa_flags = 0;
		sigaction(SIGUSR1, &signals, NULL);
		i = 0;
		while (argv[1][i] != '\0')
		{
			ft_send_bytes(argv[1][i], ft_atoi(argv[2]));
			i++;
		}
	}
	return (0);
}

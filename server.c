/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:43:08 by marai             #+#    #+#             */
/*   Updated: 2023/03/24 01:05:02 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <sys/types.h>

//global variable
int	g_bitsum;

//signalhandler
void	signal_handler(int signum)
{
	static int	degit;

	g_bitsum <<= 1;
	if (signum == SIGUSR2)
		g_bitsum += 1;
	if (7 <= degit)
	{
		write(1, &g_bitsum, 1);
		g_bitsum = 0;
		degit = 0;
	}
	else
		degit++;
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	printf("%d\n", pid);
	while (1)
		;
}

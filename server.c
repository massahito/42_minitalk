/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:43:08 by marai             #+#    #+#             */
/*   Updated: 2023/03/29 11:36:49 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <sys/types.h>

//global variable
volatile sig_atomic_t	g_bitsum;

//signalhandler

void	signal_handler(int signum)
{
	if (signum == SIGUSR2)
		g_bitsum = 2;
	else if (signum == SIGUSR1)
		g_bitsum = 1;
	else
		g_bitsum = 0;
}

static void	calc_bit(void)
{
	static int	digit;
	static int	bitsum;

	if(g_bitsum != 1 && g_bitsum != 2)
		return ;
	bitsum <<= 1;
	if (g_bitsum == 2)
		bitsum |= 1;
	if (7 <= digit)
	{
		write(1, &bitsum, 1);
		bitsum = 0;
		digit = 0;
	}
	else
		digit++;
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	if (sigemptyset(&sa.sa_mask) != 0)
	{
		ft_printf("sigempty error\n");
		exit(1);
	}
	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_printf("%d\n", pid);
	while (1)
	{
		pause();
		calc_bit();
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Marai <MasaDevs@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:43:17 by marai             #+#    #+#             */
/*   Updated: 2023/03/22 16:40:48 by Marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <sys/types.h>

pid_t	check_error(int argc, char *argv[]);
int		send_char_bit(pid_t pid, char *argv[], int index);

int	main(int argc, char *argv[])
{
	pid_t	pid;
	ssize_t	i;

	pid = check_error(argc, argv);
	if (pid < 0)
		return (-1);
	i = 0;
	while (argv[2][i] != '\0')
	{
		if (send_char_bit(pid, argv, i) == -1)
			return (-1);
		i++;
	}
}

pid_t	check_error(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("Incorrect the number of arguments\n");
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 1)
	{
		ft_printf("Invalid process id\n");
		return (-1);
	}
	return (pid);
}

int	send_char_bit(pid_t pid, char *argv[], int index)
{
	int	j;
	int	chr;
	int	result;

	j = 7;
	chr = argv[2][index];
	while (0 <= j)
	{
		if ((chr >> j) & 1)
			result = kill(pid, SIGUSR2);
		else
			result = kill(pid, SIGUSR1);
		if (result == -1)
		{
			ft_printf("Can't send the messege\nPlease check the pid.\n");
			return (-1);
		}
		usleep(300);
		j--;
	}
	return (1);
}

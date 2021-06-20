/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:58:08 by abello-r          #+#    #+#             */
/*   Updated: 2021/06/20 18:01:26 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./srcs/Libft/libft.h"
#include <signal.h>

static int	send_bin(pid_t pid, char c)
{
	int	bit;

	bit = 7;
	while (--bit > -1)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
	}
	return (0);
}

static int	ftp_server(pid_t pid_num, char *str)
{
	int	i;

	i = 0;
	while (str[i] >= ' ' && str[i] <= '~')
	{
		if (send_bin(pid_num, str[i]))
			return (1);
		++i;
	}
	i = 0;
	while (i < 7)
	{
		kill(pid_num, SIGUSR1);
		usleep(1000);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid_num;

	if (argc < 3)
	{
		write(STDOUT_FILENO, "Introduce un PID y una cadena\n", 31);
		return (1);
	}
	else if (argc == 3)
	{
		pid_num = ft_atoi(argv[1]);
		if (pid_num == 0)
			return (1);
		if (pid_num)
			ftp_server(pid_num, argv[2]);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:58:11 by abello-r          #+#    #+#             */
/*   Updated: 2021/06/24 18:34:03 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./srcs/Libft/libft.h"
#include <signal.h>
#include <math.h>

int	g_foo = 1;

static void	print_pid(void)
{
	pid_t	pid_num;

	pid_num = getpid();
	if (pid_num == 0)
		return ;
	write(STDOUT_FILENO, "\nPID [", 6);
	ft_putnbr_fd(pid_num, 1);
	write(STDOUT_FILENO, "]\n\n", 3);
}

static void	reception(int sig)
{
	static size_t	i;
	static int		bit;
	static char		buf[1002];

	if (--bit == -1)
	{
		bit = 6;
		++i;
	}
	buf[i] &= ~(1 << 7);
	if (sig == SIGUSR1)
		buf[i] |= (1 << bit);
	else if (sig == SIGUSR2)
		buf[i] &= ~(1 << bit);
	if (i == 1001 || buf[i] == 127)
	{
		buf[i] = 0;
		write(STDOUT_FILENO, buf, i + 1);
		ft_memset(buf, '\0', 1001);
		i = 0;
		bit = 0;
	}
}

static void	close_server(int sig)
{
	write(STDOUT_FILENO, "\nServidor apagado.\n", 19);
	sig = 2;
	g_foo = 0;
}

int	main(int argc, char **argv)
{
	argv = NULL;
	if (argc != 1)
	{
		write(STDERR_FILENO, "Ejecuta solo el ./server sin parámetros.\n", 42);
		return (1);
	}
	else
	{
		print_pid();
		signal(SIGUSR1, reception);
		signal(SIGUSR2, reception);
		signal(SIGINT, close_server);
		while (g_foo)
		{
		}
	}
	return (0);
}

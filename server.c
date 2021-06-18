/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:58:11 by abello-r          #+#    #+#             */
/*   Updated: 2021/06/18 12:43:29 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "talk.h"

int	g_foo = 1;

void	print_pid(void)
{
	pid_t pid_num;

	pid_num = getpid();
	if (pid_num == 0)
		return ;
	write(STDOUT_FILENO, "\nPID [", 6); 
	ft_putnbr_fd(pid_num, 1);
	write(STDOUT_FILENO, "]\n\n", 3);
}

static void	reception(int sig)
{
	//char *bin_letter;

	/*if (i == 9)
	{
		
	}*/
	if (sig == 30) // RECIBO COMO SEÑAL ' 1 '
	{
		write(1, "1", 1);
		//bin_letter[i] = '1';
		//i++;
	}
	else if (sig == 31) // RECIBO COMO SEÑAL ' 0 '
	{
		write(1, "0", 1);
		//bin_letter[i] = '0';
		//i++;
	}
	fflush(stdout);
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
		write(STDERR_FILENO, "Ejecuta solo el ./server sin agregar parámetros.\n", 50);
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
			usleep(1000);
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:56:35 by abello-r          #+#    #+#             */
/*   Updated: 2021/05/27 21:44:41 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	i;
	long	sign;
	long	nb;

	nb = 0;
	sign = 1;
	i = 0;
	while ((str[i] == '\n' || str[i] == '\t' || str[i] == ' ' )
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - '0');
	nb = nb * sign;
	if (nb > 2147483647 || nb < -2147483647)
	{
		printf("\e[1;31m""Error\n");
		exit(EXIT_FAILURE);
	}
	return (nb);
}

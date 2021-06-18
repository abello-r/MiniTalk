/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:36:51 by abello-r          #+#    #+#             */
/*   Updated: 2021/06/16 16:55:37 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "talk.h"

void	opt(int color)
{
	if (color & AZUL)
		printf("AZUL\n");
	if (color & ROJO)
		printf("ROJO\n");
	if (color & VERDE)
		printf("VERDE\n");
	if (color & AMARILLO)
		printf("AMARILLO\n");
	if (color & MORADO)
		printf("MORADO\n");
	if (color & BLANCO)
		printf("BLANCO\n");
	if (color & NEGRO)
		printf("NEGRO\n");
	if (color & GRIS)
		printf("GRIS\n");
}

int main (void)
{
	opt((BLANCO | AZUL | VERDE));
	return (0);
}
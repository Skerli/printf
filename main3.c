/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:45:09 by cskipjac          #+#    #+#             */
/*   Updated: 2021/11/12 22:06:35 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fX(void *n, t_s s)
{
	int	j;

	j = 0;
	if (*((unsigned int *)&n) != 0 && s.shar == 1)
	{
		j = 2;
		write(1, "0X", 2);
	}
	return (xeks("0123456789ABCDEF", *((unsigned int *)&n), 0) + j);
}

int	fx(void *n, t_s s)
{
	int	j;

	j = 0;
	if (*((unsigned int *)&n) != 0 && s.shar == 1)
	{
		j = 2;
		write(1, "0x", 2);
	}
	return (xeks("0123456789abcdef", *((unsigned int *)&n), 0));
}

int	xeks(char *base, unsigned int n, int i)
{
	if (n > 15)
		i = xeks(base, n / 16, i);
	i += fpc(base[n % 16]);
	return (i);
}


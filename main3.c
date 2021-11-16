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

int	fX(void *n)
{
	return (xeks("0123456789ABCDEF", *((unsigned int *)&n), 0));
}

int	fx(void *n)
{
	return (xeks("0123456789abcdef", *((unsigned int *)&n), 0));
}

int	xeks(char *base, unsigned int n, int i)
{
	if (n > 15)
		i = xeks(base, n / 16, i);
	i += fpc(base[n % 16]);
	return (i);
}

int	fu(void *n)
{
	return (fu_plus(*((unsigned int *)&n), 0));
}

int	fu_plus(unsigned int n, int i)
{
	if (n >= 10)
		i = fd_plus(n / 10, i);
	i += fpc((n % 10) + 48);
	return (i);
}

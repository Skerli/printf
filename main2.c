/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:06:47 by cskipjac          #+#    #+#             */
/*   Updated: 2021/11/12 18:36:29 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fpc(int	a)
{
	write(1, &a, 1);
	return (1);
}

int	fc(void	*c)
{
	char	*a;

	a = (char *)c;
	write(1, &a, 1);
	return (1);
}

int	fd(void *n)
{
	return (fd_plus(*((int *)&n), 0));
}

int	fd_plus(int n, int i)
{
	if (n == -2147483648)
	{
		fpc('-');
		fpc('2');
		fd_plus(147483648, i);
		return (11);
	}
	if (n < 0)
	{
		fpc('-');
		n = -n;
		i++;
	}
	if (n >= 10)
		i = fd_plus(n / 10, i);
	i = i + fpc((n % 10) + 48);
	return (i);
}

int	fs(void *s)
{
	int		i;
	char	*str;

	i = -1;
	str = (char *)s;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[++i])
		write(1, &(str[i]), 1);
	return (i);
}

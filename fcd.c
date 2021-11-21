/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:12:57 by cskipjac          #+#    #+#             */
/*   Updated: 2021/11/18 17:59:37 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fc(void	*c, t_s s)
{
	char	*a;
	int		q;

	q = 1;
	a = (char *)c;
	if (s.weight > 1 && s.minus == 0 && s.nul == 0)
		space_null(s, 1, ' ', 1);
	if (s.weight > 1 && s.minus == 0 && s.nul == 1)
		space_null(s, 1, '0', 3);
	write(1, &a, 1);
	if (s.weight > 1 && s.minus == 1)
		space_null(s, 1, ' ', 1);
	if (s.weight > q)
		q = s.weight;
	return (q);
}

int	fd_len(int n, int i)
{
	if (n == -2147483648)
	{
		fd_len(147483648, i);
		return (11);
	}
	if (n < 0)
	{
		n = -n;
		i++;
	}
	if (n >= 10)
		i = fd_len(n / 10, i);
	i++;
	return (i);
}

int	fd_plus(int n, int i)
{
	if (n == -2147483648)
	{
		write(1, "2", 1);
		fd_plus(147483648, i);
		return (11);
	}
	if (n < 0)
	{
		n = -n;
		i++;
	}
	if (n >= 10)
		i = fd_plus(n / 10, i);
	i += fpc((n % 10) + 48);
	return (i);
}

int	fd(void *n, t_s s)
{
	int	q;
	int	qa;

	if (*((int *)&n) < 0)
		s.dm = 1;
	q = fd_len(*((int *)&n), 0);
	if ((s.plus == 1 || s.space == 1) && s.dm == 0)
		s.jd = 1;
	qa = q + s.jd;
	if (q < s.accuracy)
		qa = s.accuracy + s.jd + s.dm;
	if (s.weight > qa && s.weight != 0 && s.minus == 0 && s.nul == 1)
		s = space_nulld(s, qa, '0', 1);
	if (s.weight > qa && s.weight != 0 && s.minus == 0 && s.nul == 0)
		space_nulld(s, qa, ' ', 1);
	space_nulld(s, q, '0', 0);
	fd_plus(*((int *)&n), 0);
	if (s.weight > q && s.weight != 0 && s.minus == 1 && s.accuracy < s.weight)
		space_nulld(s, qa, ' ', 1);
	if (s.weight > qa)
		qa = s.weight;
	if (qa > s.weight && s.accuracy == q && *((int *)&n) < 0)
		qa++;
	return (qa);
}

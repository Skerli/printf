/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:01:11 by cskipjac          #+#    #+#             */
/*   Updated: 2021/11/17 14:01:11 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_s	space_nullX(t_s s, int q, char c, int k)
{
	int		i;

	i = 0;
	if (s.plus == 2 && c == '0')
	{
		write(1, "0X", 2);
		s.plus--;
	}
	if (k == 1 || k == 3)
	{
		if (s.term == 1 && k != 3)
			c = ' ';
		i = s.weight - q;
	}
	if (k == 0)
		i = s.accuracy - q;
	while (i-- > 0)
		fpc(c);
	return (s);
}

t_s	space_null(t_s s, int q, char c, int k)
{
	int		i;

	i = 0;
	if (s.plus == 2 && c == '0')
	{
		write(1, "0x", 2);
		s.plus--;
	}
	if (k == 1 || k == 3)
	{
		if (s.term == 1 && k != 3)
			c = ' ';
		i = s.weight - q;
	}
	if (k == 0)
		i = s.accuracy - q;
	while (i-- > 0)
		fpc(c);
	return (s);
}

int	fpc(int	a)
{
	return (write(1, &a, 1));
}

t_s	minus(t_s s, char c)
{
	if (c == '0' && s.dm == 1)
	{
		write(1, "-", 1);
		s.dm--;
	}
	return (s);
}

t_s	space_nulld(t_s s, int q, char c, int k)
{
	int		i;

	i = 0;
	if (k == 0)
		i = s.accuracy - q + s.dm;
	if (s.space == 1 && c == '0' && s.plus == 0 && s.dm == 0)
	{
		write(1, " ", 1);
		s.space--;
	}
	if (s.plus == 1 && c == '0' && s.dm == 0)
	{
		write(1, "+", 1);
		s.plus--;
	}
	s = minus(s, c);
	if (k == 1 || k == 3)
	{
		if (s.term == 1 && k != 3)
			c = ' ';
		i = s.weight - q;
	}
	while (i-- > 0)
		fpc(c);
	return (s);
}

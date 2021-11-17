/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fxX.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:45:09 by cskipjac          #+#    #+#             */
/*   Updated: 2021/11/17 18:46:42 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	xeks_len(unsigned int n, int i)
{
	if (n > 15)
		i = xeks_len(n / 16, i);
	i++;
	return (i);
}

int	fX(void *n, t_s s)
{
	int	q;
	int	qa;

	s.plus = 0;
	q = xeks_len(*((unsigned int *)&n), 0);
	if (*((unsigned int *)&n) != 0 && s.shar == 1)
		s.plus = 2;
	qa = q + s.plus;
	if (q < s.accuracy)
		qa = s.accuracy + s.plus;
	if (s.weight > qa && s.weight != 0 && s.minus == 0 && s.nul == 1)
		s = space_nullX(s, qa, '0', 1);
	if (s.weight > qa && s.weight != 0 && s.minus == 0 && s.nul == 0)
		space_nullX(s, qa, ' ', 1);
	space_nullX(s, q, '0', 0);
	xeks("0123456789ABCDEF", *((unsigned int *)&n), 0);
	if (s.weight > q && s.weight != 0 && s.minus == 1 && s.accuracy < s.weight)
		space_nullX(s, qa, ' ', 1);
	if (s.weight > qa)
		qa = s.weight;
	return (qa);
}

int	fx(void *n, t_s s)
{
	int	q;
	int	qa;

	s.plus = 0;
	q = xeks_len(*((unsigned int *)&n), 0);
	if (*((unsigned int *)&n) != 0 && s.shar == 1)
		s.plus = 2;
	qa = q + s.plus;
	if (q < s.accuracy)
		qa = s.accuracy + s.plus;
	if (s.weight > qa && s.weight != 0 && s.minus == 0 && s.nul == 1)
		s = space_null(s, qa, '0', 1);
	if (s.weight > qa && s.weight != 0 && s.minus == 0 && s.nul == 0)
		space_null(s, qa, ' ', 1);
	space_null(s, q, '0', 0);
	xeks("0123456789abcdef", *((unsigned int *)&n), 0);
	if (s.weight > q && s.weight != 0 && s.minus == 1 && s.accuracy < s.weight)
		space_null(s, qa, ' ', 1);
	if (s.weight > qa)
		qa = s.weight;
	return (qa);
}

int	xeks(char *base, unsigned int n, int i)
{
	if (n > 15)
		i = xeks(base, n / 16, i);
	i += fpc(base[n % 16]);
	return (i);
}

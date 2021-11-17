/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:02:35 by cskipjac          #+#    #+#             */
/*   Updated: 2021/11/17 14:02:35 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fp_len(long unsigned int n, int len)
{
	if (n == 0 && len == 0)
		return (1);
	if (n == 0)
		return (len);
	n = n / 16;
	if (len == 18)
		return (len);
	len += 1;
	len = fp_len(n, len);
	return (len);
}

int	fp_plus(long unsigned int n, int len)
{
	char	*x;
	char	e;

	x = "0123456789abcdef";
	if (n == 0 && len == 0)
		return (write(1, "0", 1));
	if (n == 0)
		return (len);
	e = x[n % 16];
	n = n / 16;
	if (len == 18)
		return (len);
	len += 1;
	len = fp_plus(n, len);
	write(1, &e, 1);
	return (len);
}

int	fp(void *n, t_s s)
{
	int	q;
	int	qa;

	s.plus = 2;
	q = fp_len(*((long unsigned int *)&n), 0);
	qa = q + 2;
	if (s.weight > qa && s.weight != 0 && s.minus == 0 && s.nul == 0)
		space_null(s, qa, ' ', 1);
	space_null(s, q, '0', 0);
	fp_plus(*((long unsigned int *)&n), 0);
	if (s.weight > q && s.weight != 0 && s.minus == 1 && s.accuracy < s.weight)
		space_null(s, qa, ' ', 1);
	if (s.weight > qa)
		qa = s.weight;
	return (qa);
}

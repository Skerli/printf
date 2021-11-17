/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fu.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:02:21 by cskipjac          #+#    #+#             */
/*   Updated: 2021/11/17 14:02:21 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fu_len(unsigned int n, int i)
{
	if (n >= 10)
		i = fu_len(n / 10, i);
	i++;
	return (i);
}

int	fu_plus(unsigned int n, int i)
{
	if (n >= 10)
		i = fu_plus(n / 10, i);
	i += fpc((n % 10) + 48);
	return (i);
}

int	fu(void *n, t_s s)
{
	int		qa;
	int		q;
	int		z;

	q = 0;
	q = fu_len(*((unsigned int *)&n), 0);
	qa = q;
	if (q < s.accuracy)
		qa = s.accuracy;
	if (s.weight > qa && s.weight != 0 && s.minus == 0 && s.nul == 1)
		space_null(s, qa, '0', 1);
	if (s.weight > qa && s.weight != 0 && s.minus == 0 && s.nul == 0)
		space_null(s, qa, ' ', 1);
	space_null(s, q, '0', 0);
	z = fu_plus(*((unsigned int *)&n), 0);
	if (s.weight > q && s.weight != 0 && s.minus == 1 && s.accuracy < s.weight)
		space_null(s, qa, ' ', 1);
	if (s.weight > z)
		z = s.weight;
	if (s.accuracy > z)
		z = s.accuracy;
	return (z);
}

int	fs_len(char *str)
{
	int	q;

	q = 0;
	while (str[q])
		q++;
	return (q);
}

int	fs(void *st, t_s s)
{
	int		i;
	int		q;
	char	*str;

	i = -1;
	q = 0;
	str = (char *)st;
	if (!str)
		str = "(null)";
	q = fs_len(str);
	if (s.weight > q && s.minus == 0 && s.nul == 0)
		space_null(s, q, ' ', 1);
	if (s.weight > q && s.minus == 0 && s.nul == 1)
		space_null(s, q, '0', 3);
	while (str[++i])
		fpc(str[i]);
	if (s.weight > q && s.minus == 1)
		space_null(s, q, ' ', 1);
	if (s.weight > q)
		q = s.weight;
	return (q);
}

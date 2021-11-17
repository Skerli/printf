/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:22:57 by cskipjac          #+#    #+#             */
/*   Updated: 2021/11/15 18:55:41 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_s	null_flags(t_s s, int k, const char *str)
{
	if (k == 0)
	{
		s.i++;
		s.minus = 0;
		s.nul = 0;
		s.plus = 0;
		s.shar = 0;
		s.space = 0;
		s.term = 0;
		s.weight = 0;
		s.accuracy = 0;
	}
	if (k == 1 && str[s.i] == '%')
		s.i++;
	return (s);
}

t_s	flags(t_s s, const char *str)
{
	s = null_flags(s, 0, str);
	while (str[s.i] == '-' || str[s.i] == '+' || str[s.i] == '#' ||
			str[s.i] == '0' || str[s.i] == ' ')
	{
		if (str[s.i] == '-')
			s.minus = 1;
		if (str[s.i] == '0')
			s.nul = 1;
		if (str[s.i] == '+')
			s.plus = 1;
		if (str[s.i] == '#')
			s.shar = 1;
		if (str[s.i] == ' ')
			s.space = 1;
		s.i++;
	}
	while (str[s.i] >= '0' && str[s.i] <= '9')
		s.weight = (s.weight * 10) + (str[s.i++] - '0');
	if (str[s.i++] == '.')
		s.term = 1;
	while (str[s.i] >= '0' && str[s.i] <= '9')
		s.accuracy = (s.accuracy * 10) + (str[s.i++] - '0');
	return (null_flags(s, 1, str));
}

int	poisk(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
	{
		if (base[i] == c)
			return (i);
	}
	return (-1);
}

int	printf_plus(va_list ptr, t_s s, const char *str)
{
	static	int		(*op[8])(void *, t_s) = {&fc, &fs, &fd, &fd, &fu, &fx, &fX, &fp};

	while (str[++s.i])
	{
		if (str[s.i] == '%' && str[s.i + 1])
		{
			if (str[s.i + 1] == '%')
			{
				s.j += fpc('%');
				s.i++;
				continue ;
			}
			s = flags(s, str);
			s.j += op[poisk(str[s.i], "csdiuxXp")](va_arg(ptr, void *), s);
		}
		else
			s.j += fpc(str[s.i]);
	}
	return (s.j);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	va_list		ptr;
	t_s			s;

	if (!str)
		return (-1);
	i = 0;
	va_start(ptr, str);
	s.i = -1;
	s.j = 0;
	i = printf_plus(ptr, s, str);
	va_end(ptr);
	return (i);
}

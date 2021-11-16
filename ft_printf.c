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

int	fp(void *n)
{
	write(1, "0x", 2);
	return (fp_plus(*((long unsigned int *)&n), 0) + 2);
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

int	printf_plus(int i, va_list ptr, int j, const char *str)
{
	static	int		(*op[8])(void *) = {&fc, &fs, &fd, &fd, &fu, &fx, &fX, &fp};
	t_s				s;

	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1] && str[i + 1])
		{
			if (str[i + 1] == '%')
			{
				j += fpc('%');
				i++;
				continue ;
			}
			j = j + op[poisk(str[++i], "csdiuxXp")](va_arg(ptr, void *));
		}
		else
			j = j + fpc(str[i]);
	}
	return (j);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	va_list		ptr;
	int			j;

	if (!str)
		return (-1);
	va_start(ptr, str);
	i = -1;
	j = 0;
	va_end(ptr);
	return (printf_plus(i, ptr, j, str));
}

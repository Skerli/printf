/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:26:45 by cskipjac          #+#    #+#             */
/*   Updated: 2021/11/15 16:28:49 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
/*int	p(int a, int b)
{
	return (a + b);
}

int	p1(int a, int b)
{
	return (a - b);
}

int	p2(int a, int b)
{
	return (a * b);
}

int	p3(int a, int b)
{
	return (a - b);
}

int	p4(int a, int b)
{
	return (a - b);
}

void	ft_do_operation(int a, int b, char operator,  char *operators)
{
	static	int	(*operations[5])(int, int) = {&p, &p1, &p2, &p3, &p4};
	int			result;
	int			index;

	result = 0;
	index = 0;
	while (index < 5)
	{
		if (operator == operators[index])
		{
			result = (operations[index])(a, b);
			break ;
		}
		index++;
	}
	printf("%d", result);
}


void	f(void *str)
{
	char	*s;
	int		i;

	s = (char *)str;
	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
}

void	f2(void *c1)
{
	int	*p;

	p = (int *)c1;
	write(1, &p, 1);
}

void	a(int q, ...)
{
	va_list	p;
	char	*s;

	va_start(p, q);
	f2(va_arg(p, void *));
	va_end(p);
}

void	z1(int a)
{
	write(1, &a, 1);
}

void	z(void *a)
{
	int	*z;

	z = (int *)a;
	z1(*z);
}
*/
int	main(void)
{
	//ft_do_operation(3, 2, '+', "+-/*c");
	//printf("\n%d\n%i\n%u", 123, 123, 123);
	//fd(11);
	//fs("abcd");
	//printf("%x", -3324234);
	//xeks("0123456789abcdef", 100);
	printf("\treturn = %d\n", printf("%s\t%d\t%x\t%X", "fdfsf", -544541, 334534, 0));
	printf("\treturn = %d\n", ft_printf("%s\t%d\t%x\t%X", "fdfsf", -544541, 334534, 0));
	return (0);
}

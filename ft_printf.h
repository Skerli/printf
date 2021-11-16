/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:27:22 by cskipjac          #+#    #+#             */
/*   Updated: 2021/11/15 18:54:18 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
int		fp(void *n);
int		fp_plus(long unsigned int num, int len);
int		ft_printf(const char *str, ...);
int		printf_plus(int i, va_list ptr, int j, const char *str);
int		poisk(char c, char *base);
int		fc(void	*c);
int		fs(void *s);
int		fpc(int	a);
int		fd(void *a);
int		fd_plus(int n, int i);
int		fX(void *n);
int		fx(void *n);
int		xeks(char *base, unsigned int n, int i);
int		fu(void *n);
int		fu_plus(unsigned int n, int i);

typedef struct s_s
{
	int	plus;
	int	space;
	int	minus;
	int	nul;
	int	shar;
	int	weight;
}	t_s;
#endif
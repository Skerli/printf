/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:27:22 by cskipjac          #+#    #+#             */
/*   Updated: 2021/11/17 20:57:43 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_s
{
	int	j;
	int	i;
	int	plus;
	int	space;
	int	term;
	int	minus;
	int	nul;
	int	shar;
	int	weight;
	int	accuracy;
	int	dm;
}	t_s;

t_s		space_null(t_s s, int q, char c, int k);
int		ft_printf(const char *str, ...);
int		printf_plus(va_list ptr, t_s s, const char *str);
t_s		flags(t_s s, const char *str);
t_s		null_flags(t_s s, int k, const char *str);
int		poisk(char c, char *base);
int		fp(void *n, t_s s);
int		fp_plus(long unsigned int num, int len);
int		fp_len(long unsigned int num, int len);
int		fc(void	*c, t_s s);
int		fs(void *st, t_s s);
int		fs_len(char *str);
int		fpc(int	a);
int		fd(void *a, t_s s);
t_s		space_nulld(t_s s, int q, char c, int k);
int		fd_plus(int n, int i);
int		fd_len(int n, int i);
t_s		minus(t_s s, char c);
int		fX(void *n, t_s s);
int		fx(void *n, t_s s);
int		xeks(char *base, unsigned int n, int i);
int		xeks_len(unsigned int n, int i);
t_s		space_nullX(t_s s, int q, char c, int k);
int		fu(void *n, t_s s);
int		fu_len(unsigned int n, int i);
int		fu_plus(unsigned int n, int i);

#endif
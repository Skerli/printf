
#include "ft_printf.h"

int	fu_len(unsigned int n, int i)
{
	if (n >= 10)
		i = fu_len(n / 10, i);
	i++;
	return (i);
}

int	fu_plus(unsigned int n, int i, t_s s)
{
	if (n >= 10)
		i = fu_plus(n / 10, i, s);
	i += fpc((n % 10) + 48);
	return (i);
}

int	fu(void *n, t_s s)
{
	int	q;
	int	z;

	q = 0;
	q = fu_len(*((unsigned int *)&n), 0);
	if (s.weight > q && s.weight != 0 && s.minus == 0)
		space_null(s, q);
	z = fu_plus(*((unsigned int *)&n), 0, s);
	if (s.weight > q && s.weight != 0 && s.minus == 1)
		space_null(s, q);
	if (s.weight > z)
		return (s.weight);
	return (z);
}

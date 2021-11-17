
#include "ft_printf.h"


int	fp(void *n, t_s s)
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
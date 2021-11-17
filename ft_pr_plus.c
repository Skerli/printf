
#include "ft_printf.h"

void	space_null(t_s s, int q)
{
	int		i;
	char	c;

	i = s.weight - q;
	c = ' ';
	while (i != 0)
	{
		fpc(c);
		i--;
	}
}
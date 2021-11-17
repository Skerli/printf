#include "ft_printf.h"

int	main(void)
{
	int	a;

	a = 45454;
	printf("\treturn = %d\n", printf("|%#15.8X|%.3d|%10.8u|%10s|%25p|",
			5554, -11, 7866, NULL, &a));
	printf("\treturn = %d\n", ft_printf("|%#15.8X|%.3d|%10.8u|%10s|%25p|",
			5554, -11, 7866, NULL, &a));
	return (0);
}

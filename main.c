
#include "ft_printf.h"

int	main(void)
{
	//ft_do_operation(3, 2, '+', "+-/*c");
	//printf("\n%d\n%i\n%u", 123, 123, 123);
	//fd(11);
	//fs("abcd");
	//printf("%x", -3324234);
	//xeks("0123456789abcdef", 100);
	printf("\treturn = %d\n", printf("|%d|%i|%-6.8u|", 3423, -0, 7866));
	printf("\treturn = %d\n", ft_printf("|%d|%i|%-6u|", 3423, -0, 7866));
	return (0);
}

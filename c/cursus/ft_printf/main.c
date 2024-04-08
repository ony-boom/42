#include <stdio.h>
#include "includes/ft_printf.h"

int	main(void)
{
	int	me;
	int	them;
	me = ft_printf("%032d\n", -2147483648);
	them = printf("%032d\n", -2147483648);
	printf("Mine %d, theirs %d\n", me, them);
}

#include <stdio.h>
#include "includes/ft_printf.h"

int	main(void)
{
	int	me;
	int	them;
	me = ft_printf("%-20.18d\n", -214748364);
	them = printf("%-20.18d\n", -214748364);
	printf("Mine %d, theirs %d\n", me, them);
}

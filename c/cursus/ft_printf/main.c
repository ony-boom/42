#include <stdio.h>
#include "includes/ft_printf.h"

int	main(void)
{
	int	me;
	int	them;
	me = ft_printf("[%2u]\n", 1);
	them = printf("[%2u]\n", 1);
	printf("Mine %d, theirs %d\n", me, them);
}

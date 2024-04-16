#include <stdio.h>
#include "includes/ft_printf.h"

int	main(void)
{
	int	me;
	int	them;
	me = ft_printf("[%#8.4x]\n", 10);
	them = printf("[%#8.4x]\n", 10);
	printf("Mine %d, theirs %d\n", me, them);
}
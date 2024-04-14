#include <stdio.h>
#include "includes/ft_printf.h"

int	main(void)
{
	int	me;
	int	them;
	me = ft_printf("[%-.d]\n", 0);
	them = printf("[%-.d]\n", 0);
	printf("Mine %d, theirs %d\n", me, them);
}

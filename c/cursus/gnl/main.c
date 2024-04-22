#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	char	*line1;
	char	*line2;
	char	*line3;

	char *line4;
	// char *line5;
	fd = open("test.txt", O_RDONLY);
	line1 = get_next_line(fd);
	printf("line1: %s\n", line1);
	line2 = get_next_line(fd);
	printf("line2: %s\n", line2);
	close(fd);
	line3 = get_next_line(fd);
	printf("line3: %s\n", line3);
	fd = open("test.txt", O_RDONLY);
	line4 = get_next_line(fd);
	printf("line4: %s\n", line4);
	// line5 = get_next_line(fd);
	// printf("line5: %s\n", line5);
	free(line1);
	free(line2);
	free(line3);
	free(line4);
	// free(line5);
}

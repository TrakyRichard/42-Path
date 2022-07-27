#include "../get_next_line.h"

#include "fcntl.h"
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	char *filename = "tests/files/test.txt";
	fd1 = open(filename, O_WRONLY);
	fd2 = open("tests/files/test2.txt", O_RDONLY);
	fd3 = open("tests/files/test3.txt", O_RDONLY);
	fd4 = open("tests/files/41_with_nl", O_RDONLY);
	i = 1;

	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s \n", i, line);
		free(line);
		line = get_next_line(fd2);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s \n", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}

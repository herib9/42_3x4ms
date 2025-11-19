#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#include "gnl.h"

char	*gnl(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	pos = 0;
	static int	leido = 0;
	char		*line;
	int 		i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0 || !(line = malloc(10000)))
		return (NULL);
	while (1)
	{
		if (pos >= leido)
		{
			if ((leido = read(fd, buffer, BUFFER_SIZE)) <= 0)
				break;
			pos = 0;
		}
		line[i++] = buffer[pos++];
		if (line[i - 1] == '\n')
			break;
	}
	line[i] = '\0';
	if (i == 0)
		return (free(line), NULL);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;	
	
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}

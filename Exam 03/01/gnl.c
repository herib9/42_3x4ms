#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	int	i = 0;
	int	leido;
	char c;
	char *str;

	if (!(str = malloc(100000)))
		return (NULL);
	while ((leido = read(fd, &c, 1)) > 0)
	{
		str[i++] = c;
		if (c == '\n')
			break;
	}
	str[i] = '\0';
	if (i == 0 || leido < 0)
	{
		free(str);
		return (NULL);
	}
	return (str);
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

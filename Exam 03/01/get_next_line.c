#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	static int	pos;
	static int	r = 0;
	char		*line;
	int			i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(10000);
	if (!line)
		return (NULL);
	while (1)
	{
		if (pos >= r)
		{
			r = read(fd, buf, BUFFER_SIZE);
			pos = 0;
			if (r <= 0)
			{
				//pos = 0;
				//r = 0;
				break;
			}
		}
		if (i >= 9999)
		{
			line[i++] = '\n';
			break;
		}
		line[i++] = buf[pos++];
		if (line[i - 1] == '\n')
			break;
	}
	line[i] = '\0';
	if (i == 0)
		return (free(line), NULL);
	return (line);
}

/*int	main(void)
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
}*/


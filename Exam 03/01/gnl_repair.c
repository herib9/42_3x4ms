#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

//		:%s/size_t/int

char	*ft_strchr(char *s, int c)
{
	int	i = 0;
	while (s[i] && s[i] != c)	//s[i] &&
		i++;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, int n)
{
	while (n-- > 0)								//cambiar --n por n--
		((char *)dest[n]) = ((char *)src[n]); 	//borrar - 1
	return (dest);
}

int	ft_strlen(char *s)
{
	int	ret = 0;
	while (s && *s)					//añadir s &&
	{
		s++;
		ret++;
	}
	return (ret);
}

int	str_append_mem(char **s1, char *s2, int size2)
{
	int	size1 = *s1 ? ft_strlen(*s1) : 0;
	char	*tmp = malloc(size2 + size1 + 1);
	if (!tmp)
		return (0);
	ft_memcpy(tmp, *s1, size1);
	ft_memcpy(tmp + size1, s2, size2);
	tmp [size1 + size2] = 0;
	free(*s1);
	*s1 = tmp;
	return (1);
}

int	str_append_str(char **s1, char *s2)
{
	return (str_append_mem(s1, s2, ft_strlen(s2)));
}

void	*ft_memmove(void *dest, const void *src, int n)
{
	if (dest < src)
		return (ft_memcpy(dest, src, n));		//puede aparecer memmove en vez de memcpy 
	else if (dest == src)
		return (dest);
	int j = ft_strlen((char *)src);				//crear int j cambiando = de i, borramos - 1
	int	i = 0;									//i = 0
	while (i < j)								//i < j      ?¿? i <= j
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;									//cambiar i-- por i++
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	b[BUFFER_SIZE + 1] = "";
	char	*ret = NULL;
	char	*tmp = ft_strchr(b, '\n');
	while (!tmp)
	{
		if (!str_append_str(&ret, b))
			return (NULL);
		int	read_ret = read(fd, b, BUFFER_SIZE);
		if (read_ret == -1)
			return (NULL);
		b[read_ret] = 0;
		if (read_ret == 0)				//AÑADIR TODO ESTE IF
		{
			if(*ret)
				return (ret);
			free(ret);
			return(NULL);
		}
		tmp = ft_strchr(b, '\n');	//copiar de arriba
	}
	if (!str_append_mem(&ret, b, tmp - b + 1))
	{
		free(ret);
		return (NULL);
	}
	ft_memmove(b, tmp + 1, ft_strlen(tmp + 1));		//añadir esta linea
	return (ret);
}

#include <stdio.h>
#include <fcntl.h>
int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *line;

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}

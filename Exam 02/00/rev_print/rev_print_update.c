char	*rev_print(char *s)
{
	int	i = 0;
	int	len = 0;
	int	temp;
	
	while (s[len])
		len++;
	len--;
	while (i < len)
	{
		temp = s[i];
		s[i] = s[len];
		s[len] = temp;
		i++;
		len--;
	}
	return (s);
}

int main(void)
{
	rev_print("rainbow dash");
	write(1, "\n", 1);
	rev_print("Ponies are awesome");
	write(1, "\n", 1);
	rev_print("");
	write(1, "\n", 1);
	return (0);
}

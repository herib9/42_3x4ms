#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int	match_space(FILE *f)
{
	int space;
	space = fgetc(f);
	while (space != EOF)
	{
		if (!isspace(space))
		{
			ungetc(space, f);
			return (0);
		}
		space = fgetc(f);
	}
	if (ferror(f))
		return (-1);
	return (0);
}

int	match_char(FILE *f, char c)
{
	int char_read;
	char_read = fgetc(f);
	if (char_read == EOF)
	{
		if (ferror(f))
			return (-1);
		return (0);
	}
	if (char_read == c)
		return (1);
	else
	{
		ungetc(char_read, f);
		return (0);
	}
}

int	scan_char(FILE *f, va_list ap)
{
	char *character;
	int c;

	c = fgetc(f);
	if (c == EOF)
	{
		if (ferror(f))
			return (-1);
		return (0);
	}
	character = va_arg(ap, char *);
	*character = (char)c;
	return (1);
}

int	scan_int(FILE *f, va_list ap)
{
	int n;
	int num = 0;
	int sign = 1;
	int digint_readed = 0;
	int *final_value;

	n = fgetc(f); // tomamos el valor para poder revisar condiciones

	if (n == EOF) // revisamos que no sea el final de la entrada
	{
		if (ferror(f))
			return (-1);
		return (0);
	}

	if (n == '+' || n == '-') // verificamos si hay algun + o -
	{
		if (n == '-')
			sign = -1; // si es asi con el - cambiamos el signo
	}
	ungetc(n, f); // devolvemos lo que leimos para no PERDER ningun caracter
	n = fgetc(f); // volvemos a leer la salida

	while (n != EOF)
	{
		if (isdigit(n)) // si es un digito
		{
			num = (n * 10) + (n - '0'); // ingresamos el numero
			digint_readed++;
		}
		else
		{
			ungetc(n, f); // si no es un digito devolvemos lo leido
			break ;
		}
	}

	if (ferror(f)) // si hay un error devolvemos el -1
		return (-1);
	if (digint_readed == 0) // si no hubo ningun caracter leido devolvemos 0
		return (0);

	final_value = va_arg(ap, int *);
	*final_value = num * sign;

	return (1);
}

int scan_string(FILE *f, va_list ap)
{
	int	character_readed = 0;
	char c;
	char *str;

	c = fgetc(f); // leemos el caracter desde la entrada
	if (c == EOF) // si devuelve EOF | verificamos si es por "error" o "final del lectura" 
	{
		if (ferror(f))
			return (-1);
		return (0);
	}
	str = va_arg(ap, char *); // obtenemos el puntero donde guardaremos lo leido
	while (c != EOF)
	{
		if (isspace(c)) // verificamos que no sea un espacio | si lo es cortamos el bucle
		{
			ungetc(c, f);
			break ;
		}
		*str = c; // agregamos el caracter
		str++; // sumamos la posicion
		character_readed++; // sumamos el contador de caracteres leidos
		c = fgetc(f); // volvemos a leer
	}
	if (ferror(f)) // verificamos si hubo un error
		return (-1);
	if (character_readed == 0) // verificamos si hubo lectura
		return (0);
	*str = '\0'; // agregamos el nulo
    return (1);
}

int	match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
		case 'c':
			return scan_char(f, ap);
		case 'd':
			match_space(f);
			return scan_int(f, ap);
		case 's':
			match_space(f);
			return scan_string(f, ap);
		case EOF:
			return -1;
		default:
			return -1;
	}
}

int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int i = 0;
	int nconv = 0;
	int c = fgetc(f);
	if (c == EOF)
		return EOF;
	ungetc(c, f);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (match_conv(f, &format, ap) != 1)
				break;
			else
				nconv++;
		}
		else if (isspace(format[i]))
		{
			if (match_space(f) == -1)
				break;
		}
		else if (match_char(f, format[i]) != 1)
			break;
		i++;
	}
	
	if (ferror(f))
		return EOF;
	return nconv;
}

int ft_scanf(const char *format, ...)
{
	int ret;
	va_list ap;
	va_start(ap, format);
	ret = ft_vfscanf(stdin, format, ap);
	va_end(ap);
	return (ret);
}

int main(void)
{
	char str[100];

	ft_scanf("%s\n", str);
	return (0);
}

/*Assignment name  : ft_scanf
Expected files   : ft_scanf.c
Allowed functions: fgetc, ungetc, ferror, feof, isspace, isdigit, stdin, va_start, 
va_arg, va_copy, va_end
--------------------------------------------------------------------------------

Escribe una función llamada `ft_scanf` que imite a la función real scanf con las siguientes restricciones:

- Solo gestionará las siguientes conversiones: s, d y c
- No es necesario gestionar las opciones *, m y '
- No es necesario gestionar el ancho máximo del campo
- No es necesario gestionar los caracteres modificadores de tipos (h, hh, l, etc.)
- No tienes que manejar las conversiones que comienzan con %n$.

Tu función debe declararse de la siguiente manera:

int ft_scanf(const char *, ... );

En este directorio encontrarás un archivo que contiene parte del código que necesitarás,
solo tienes que completarlo.

Para probar tu programa, compara tus resultados con el scanf real.

Pista: es posible que tengas que leer el manual de scanf.

#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int match_space(FILE *f)
{
        // You may insert code here
    return (0);
}

int match_char(FILE *f, char c)
{
        // You may insert code here
    return (0);
}

int scan_char(FILE *f, va_list ap)
{
        // You may insert code here
    return (0);
}

int scan_int(FILE *f, va_list ap)
{
        // You may insert code here
    return (0);
}

int scan_string(FILE *f, va_list ap)
{
        // You may insert code here
    return (0);
}

int	match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
		case 'c':
			return scan_char(f, ap);
		case 'd':
			match_space(f);
			return scan_int(f, ap);
		case 's':
			match_space(f);
			return scan_string(f, ap);
		case EOF:
			return -1;
		default:
			return -1;
	}
}

int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int nconv = 0;

	int c = fgetc(f);
	if (c == EOF)
		return EOF;
	ungetc(c, f);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (match_conv(f, &format, ap) != 1)
				break;
			else
				nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				break;
		}
		else if (match_char(f, *format) != 1)
			break;
		format++;
	}
	
	if (ferror(f))
		return EOF;
	return nconv;
}

int ft_scanf(const char *format, ...)
{
	// ...
	int ret = ft_vfscanf(stdin, format, ap);
	// ...
	return ret;
}*/
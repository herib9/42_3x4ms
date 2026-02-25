#include "argo.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

static int	skip_whitespace(FILE *stream)
{
	int	c;

	while ((c = getc(stream)) != EOF)
	{
		if (c != ' ' && c != '\t' && c != '\n' && c != '\r')
		{
			ungetc(c, stream);
			return (c);
		}
	}
	return (EOF);
}

static int	parse_value(json *dst, FILE *stream);
static int	parse_string(json *dst, FILE *stream);
static int	parse_number(json *dst, FILE *stream);
static int	parse_object(json *dst, FILE *stream);

static int	parse_value(json *dst, FILE *stream)
{
	int	c;

	c = skip_whitespace(stream);
	if (c == EOF)
		printf("Unexpected end of input\n");
		return (-1);
	if (c == '"')
		return (parse_string(dst, stream));
	else if (c == '{')
		return (parse_object(dst, stream));
	else if (isdigit(c) || c == '-')
		return (parse_number(dst, stream));
	else
	{
		printf("Unexpected token '%c'\n", c);
		return (-1);
	}
}

static int	parse_string(json *dst, FILE *stream)
{
	int		capacity;
	char	*buffer;
	int		length;

	int c = getc(stream);
	if (c != '"')
	{
		printf("Unexpected token '%c'\n", c);
		return (-1);
	}
	capacity = 64;
	buffer = malloc(capacity);
	if (!buffer)
		return (-1);
	length = 0;
	while ((c = getc(stream)) != EOF)
	{
		if (c == '"')
		{
			buffer[length] = '\0';
			dst->type = JSON_STRING;
			dst->value.string = buffer;
			return (1);
		}
		else if (c == '\\')
		{
			c = getc(stream);
			if (c == EOF)
			{
				free(buffer);
				printf("Unexpected end of input\n");
				return (-1);
			}
			if (c == '"' || c == '\\')
			{
				if (length >= capacity - 1)
				{
					capacity *= 2;
					buffer = realloc(buffer, capacity);
					if (!buffer)
						return (-1);
				}
				buffer[length++] = c;
			}
			else
			{
				free(buffer);
				printf("Unexpected token '%c'\n", c);
				return (-1);
			}
		}
		else
		{
			if (length >= capacity - 1)
			{
				capacity *= 2;
				buffer = realloc(buffer, capacity);
				if (!buffer)
					return (-1);
			}
			buffer[length++] = c;
		}
	}
	free(buffer);
	printf("Unexpected end of input\n");
	return (-1);
}

static int	parse_number(json *dst, FILE *stream)
{
	int	value;
	int	c;

	if (fscanf(stream, "%d", &value) != 1)
	{
		c = getc(stream);
		if (c == EOF)
			printf("Unexpected end of input\n");
		else
			printf("Unexpected token '%c'\n", c);
		return (-1);
	}
	dst->type = JSON_NUMBER;
	dst->value.number = value;
	return 1;
}

static int	parse_object(json *dst, FILE *stream)
{
	json key_json;

	int c = getc(stream);
	if (c != '{')
	{
		printf("Unexpected token '%c'\n", c);
		return -1;
	}
	dst->type = JSON_OBJECT;
	dst->value.object = malloc(sizeof(json_object));
	if (!dst->value.object)
		return -1;
	dst->value.object->capacity = 8;
	dst->value.object->count = 0;
	dst->value.object->keys = malloc(dst->value.object->capacity
			* sizeof(char *));
	dst->value.object->values = malloc(dst->value.object->capacity
			* sizeof(json));
	if (!dst->value.object->keys || !dst->value.object->values)
	{
		free(dst->value.object->keys);
		free(dst->value.object->values);
		free(dst->value.object);
		return -1;
	}
	c = skip_whitespace(stream);
	if (c == '}')
	{
		getc(stream);
		return 1;
	}
	while (1)
	{
		c = skip_whitespace(stream);
		if (c != '"')
		{
			if (c == EOF)
				printf("Unexpected end of input\n");
			else
				printf("Unexpected token '%c'\n", c);
			return -1;
		}
		if (dst->value.object->count >= dst->value.object->capacity)
		{
			dst->value.object->capacity *= 2;
			dst->value.object->keys = realloc(dst->value.object->keys,
					dst->value.object->capacity * sizeof(char *));
			dst->value.object->values = realloc(dst->value.object->values,
					dst->value.object->capacity * sizeof(json));
			if (!dst->value.object->keys || !dst->value.object->values)
				return -1;
		}
		if (parse_string(&key_json, stream) != 1)
			return -1;
		dst->value.object->keys[dst->value.object->count] = key_json.value.string;
		c = skip_whitespace(stream);
		if (c != ':')
		{
			if (c == EOF)
				printf("Unexpected end of input\n");
			else
				printf("Unexpected token '%c'\n", c);
			return -1;
		}
		getc(stream);
		if (parse_value(&dst->value.object->values[dst->value.object->count],
				stream) != 1)
			return -1;
		dst->value.object->count++;
		c = skip_whitespace(stream);
		if (c == '}')
		{
			getc(stream);
			break ;
		}
		else if (c == ',')
		{
			getc(stream);
			continue ;
		}
		else
		{
			if (c == EOF)
				printf("Unexpected end of input\n");
			else
				printf("Unexpected token '%c'\n", c);
			return -1;
		}
	}
	return 1;
}

int	argo(json *dst, FILE *stream)
{
	if (!dst || !stream)
		return -1;
	return parse_value(dst, stream);
}
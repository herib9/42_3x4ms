#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

#endif

/*Assignment name : broken_GNL
Expected files  : get_next_line.c get_next_line.h
Allowed functions : read, free, malloc
--------------------------------------------------------------------------------
Repara la función «get_next_line» en el archivo get_next_line.c, cuyo prototipo debe ser:
char *get_next_line(int fd);

Es posible que también tengas que reparar otras funciones.

Descripción de la función «get_next_line»:

Tu función debe devolver una línea que se haya leído del descriptor de archivo
pasado como parámetro.

Una «línea que se ha leído» se define como una sucesión de 0 a n caracteres
que termina con «\n» (código ASCII 0x0a) o con Fin de archivo (EOF).

La línea debe devolverse incluyendo el «\n» si hay uno al final
de la línea que se ha leído.

Cuando llegue al EOF, debe almacenar el búfer actual en un char * y
devolverlo. Si el búfer está vacío, debe devolver NULL.

En caso de error, devuelva NULL.

Si no devuelve NULL, el puntero debe poder liberarse.

Su programa se compilará con el indicador -D BUFFER_SIZE=xx, que debe
utilizarse como tamaño del búfer para las llamadas de lectura en sus funciones.

Su función debe estar libre de fugas de memoria.

Cuando llegue al EOF, su función no debe mantener ninguna memoria asignada con
malloc, excepto la línea que se ha devuelto.

Llamar a su función get_next_line en un bucle le permitirá leer
el texto disponible en un descriptor de archivo línea por línea hasta el final del
texto, independientemente del tamaño del texto o de cualquiera de sus líneas.

Asegúrese de que su función se comporta correctamente al leer desde un archivo, desde la
salida estándar, desde una redirección, etc.

No se realizará ninguna llamada a otra función en el descriptor de archivo entre dos llamadas
a get_next_line.

Por último, consideramos que get_next_line tiene un comportamiento indefinido al leer
desde un archivo binario.
--------------------------------------------------------------------------------*/

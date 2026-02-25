#include <stdlib.h>
#include <unistd.h>


int ft_popen(const char *file, char *const argv[], char type)
{
	int fd[2];
	int pid;

	if(!file || !argv ||(type != 'r' && type != 'w'))
		return -1;

	if(pipe(fd) == -1)
		return -1;

	pid = fork();
	if (pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		return -1;
	}

	if(pid == 0)
	{
		if(type == 'r')
		{
			if(dup2(fd[1], STDOUT_FILENO) == -1)
				exit(1);
		}
		else
		{
			if(dup2(fd[0], STDIN_FILENO) == -1)
				exit(1);
		}
		close(fd[0]);
		close(fd[1]);
		execvp(file, argv);
		exit (1);
	}
	
	if(type == 'r')
	{
		close(fd[1]);
		return(fd[0]);
	}
	else
	{
		close(fd[0]);
		return(fd[1]);
	}
}

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int     fd;
    char    buffer[256];
    int     bytes_leidos;

    // =========================================
    // PRUEBA 1: modo 'r' (leer lo que produce un programa)
    // Vamos a ejecutar "ls -l" y leer su salida
    // =========================================
    printf("=== PRUEBA MODO 'r' (ejecutamos 'ls -l') ===\n");

    char *argv_ls[] = {"ls", "-l", NULL};
    fd = ft_popen("ls", argv_ls, 'r');

    if (fd == -1)
    {
        printf("Error al abrir el pipe\n");
        return (1);
    }

    // Leemos lo que nos manda el programa hijo por el tubo
    while ((bytes_leidos = read(fd, buffer, sizeof(buffer) - 1)) > 0)
    {
        buffer[bytes_leidos] = '\0';
        printf("%s", buffer);
    }
    close(fd);

    // =========================================
    // PRUEBA 2: modo 'w' (escribirle a un programa)
    // Vamos a ejecutar "cat" y mandarle texto
    // "cat" simplemente repite lo que recibe
    // =========================================
    printf("\n=== PRUEBA MODO 'w' (ejecutamos 'cat', le mandamos texto) ===\n");

    char *argv_cat[] = {"cat", NULL};
    fd = ft_popen("cat", argv_cat, 'w');

    if (fd == -1)
    {
        printf("Error al abrir el pipe\n");
        return (1);
    }

    // Escribimos en el tubo, cat lo recibe y lo imprime en pantalla
    char *mensaje = "Hola, esto lo escribimos nosotros y cat lo repite!\n";
    write(fd, mensaje, 50);
    close(fd);

    // Pequeña pausa para que cat tenga tiempo de imprimir
    sleep(1);

    printf("\n=== FIN DE LAS PRUEBAS ===\n");
    return (0);
}

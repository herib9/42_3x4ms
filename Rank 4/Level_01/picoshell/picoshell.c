#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int    picoshell(char **cmds[])
{
	int pid;
	int fd[2];
	int prev_fd = -1;
	int i = 0;

	while(cmds[i])
	{
		if(cmds[i + 1] && pipe(fd) == -1)
			return 1;
		
		pid = fork();
		if(pid == -1)
			return 1;

		if(pid == 0)
		{
			if(prev_fd != -1)
			{
				dup2(prev_fd, STDIN_FILENO);
				close(prev_fd);
			}

			if(cmds[i + 1])
			{
				close(fd[0]);
				dup2(fd[1], STDOUT_FILENO);
				close(fd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		else
		{
			if(prev_fd != -1)
				close(prev_fd);

			if(cmds[i + 1])
			{
				close(fd[1]);
				prev_fd = fd[0];
			}
			else
			{
				close(fd[0]);
				close(fd[1]);
			}
		}
		i++;
		wait(&pid);
	}

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    // =========================================
    // PRUEBA 1: equivale a escribir en terminal:
    // ls | grep .c
    // (lista archivos y filtra los que tienen ".c")
    // =========================================
    printf("=== PRUEBA 1: ls | grep .c ===\n");

    char *cmd1[] = {"ls", NULL};
    char *cmd2[] = {"grep", ".c", NULL};
    char **prueba1[] = {cmd1, cmd2, NULL};

    picoshell(prueba1);

    // =========================================
    // PRUEBA 2: equivale a escribir en terminal:
    // ls | grep .c | wc -l
    // (lista archivos, filtra los ".c" y cuenta cuántos hay)
    // =========================================
    printf("\n=== PRUEBA 2: ls | grep .c | wc -l ===\n");

    char *cmd3[] = {"ls", NULL};
    char *cmd4[] = {"grep", ".c", NULL};
    char *cmd5[] = {"wc", "-l", NULL};
    char **prueba2[] = {cmd3, cmd4, cmd5, NULL};

    picoshell(prueba2);

    // =========================================
    // PRUEBA 3: equivale a escribir en terminal:
    // echo "Hola mundo" | wc -w
    // (escribe "Hola mundo" y cuenta las palabras)
    // =========================================
    printf("\n=== PRUEBA 3: echo 'Hola mundo' | wc -w ===\n");
    printf("(deberia salir 2, porque 'Hola mundo' tiene 2 palabras)\n");

    char *cmd6[] = {"echo", "Hola mundo", NULL};
    char *cmd7[] = {"wc", "-w", NULL};
    char **prueba3[] = {cmd6, cmd7, NULL};

    picoshell(prueba3);

    printf("\n=== FIN DE LAS PRUEBAS ===\n");
    return 0;
}

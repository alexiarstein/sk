// a semantic process id killer
// Author: Alexia Steinberg
// LICENSE: GNU GPL 3.0 (See license for more information)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Uso: sk <nombre del proceso>\n");
		return 1;
	}

	char *nombre_proc = argv[1];
	
	char command[100];
	snprintf(command, 100, "pidof %s", nombre_proc);
	FILE *pidof_output = popen(command, "r");
	if (pidof_output == NULL)
	{
		printf("Error al ejecutar el comando pidof d\n");
		return 1;
	}

	
	int process_id;
	if (fscanf(pidof_output, "%d", &process_id) != 1)
	{
		printf("No se puede parsear el PID\n");
		return 1;
	}

	pclose(pidof_output);


	if (kill(process_id, SIGKILL) != 0)
	{ 
		printf("Error al intentar hacer un kill a la ID %d\n", process_id);
		return 1;
	}
	printf("Proceso terminado con exito %d\n", process_id);
	return 0;
}

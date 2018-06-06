#include <stdio.h>
#include "strings_functions.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <errno.h>
#include <memory.h>

int main(void)
{
	int		fd;
	int		i;
	int		file;
	char	**line;

	i = 1;
	line = NULL;
	line = malloc(sizeof(char *));
	*line = NULL;
/*
	//
	 // Tests avec un seul fichier
	 //
//	fd = open("./tests_persos/sans_nl.txt", O_RDONLY);
//	fd = open("./tests_persos/un_caractere_avec_nl.txt", O_RDONLY);
//	fd = open("./tests_persos/test1.txt", O_RDONLY);
	fd = open("./tests_persos/6_caracteres.txt", O_RDONLY);
//	fd = open("./tests_persos/3_caracteres.txt", O_RDONLY);

	if (fd != -1)
	{
		while 	((get_next_line(fd, line) > 0) && *line)
		{
			printf("Ligne %d : %s\n", i, *line);
			i++;
		}
	}
	else
		printf("%s\n", strerror(errno));
*/

	file = 0;
	if((fd = open("./tests_persos/3_caracteres.txt", O_RDONLY)) != -1)
		if (get_next_line(fd, line) > 0)
		{
			file++;
			i = 1;
			printf("Fichier %d, Ligne %d : %s\n", file, i, *line);
		}
	if((fd = open("./tests_persos/6_caracteres.txt", O_RDONLY)) != -1)
		if (get_next_line(fd, line) > 0)
		{
			file++;
			i = 1;
			printf("Fichier %d, Ligne %d : %s\n", file, i, *line);
		}
//*/
	free(*line);
	free(line);
	return (0);
}
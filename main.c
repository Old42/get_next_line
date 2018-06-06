#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <errno.h>
#include <memory.h>
#include <stdlib.h>
#include <zconf.h>

int main(void)
{
	/*
	int		fd;
	int		i;
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
	fd = open("./tests_persos/test1.txt", O_RDONLY);
//	fd = open("./tests_persos/6_caracteres.txt", O_RDONLY);
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
/
	int		file;

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
*/

	//TEST 04 TEST_RETURN_VALUES
	char    *line;
	int             out;
	int             p[2];
	int             fd;
	int             gnl_ret;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abc\n\n", 5);
	close(p[1]);
	dup2(out, fd);

	/* Read abc and new line */
	if (((gnl_ret = get_next_line(p[0], &line))) > 0)
	{
		printf("Read abc and new line : %s\n", line);
	}

	/* Read new line */
	if (((gnl_ret = get_next_line(p[0], &line))) > 0)
	{
		printf("Read new line : %s\n", line);
	}

	/* Read again, but meet EOF */
	if (((gnl_ret = get_next_line(p[0], &line))) > 0)
	{
		printf("Read new line : %s\n", line);
	}
	/* Let's do it once again */
	if (((gnl_ret = get_next_line(p[0], &line))) > 0)
	{
		printf("Read new line : %s\n", line);
	}

	free((void *)*line);
	free(line);
	return (0);
}
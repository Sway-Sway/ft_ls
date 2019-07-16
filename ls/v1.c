#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int		main(int ac, char **av)
{
	DIR *dir;
	struct	dirent	*sd;

	dir = opendir(av[1]);

	if(dir == NULL)
	{
		printf("Error! Unable to open directory.\n");
		exit(1);
	}
	while((sd=readdir(dir)) != NULL)
	{
		printf("%s\n", sd->d_name);
	}
	closedir(dir);
	return (0);
}

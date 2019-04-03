#include <sys/dir.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	/*Declaration des variables requises (man opendir, man dir)*/
	DIR *dir;
	struct dirent *name;

	/*Gestion d'erreurs. stat renvoie NULL en cas d'errreur*/
	if (argc != 2 || !(dir = opendir(argv[1])))
		return (0);

	while ((name = readdir(dir)))
		printf("%s\n", name->d_name);
	closedir(dir);
}

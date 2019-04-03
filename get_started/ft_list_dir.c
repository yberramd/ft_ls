#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	/*Declaration des variables requises (man opendir, man dir)*/
	void *dir;
	struct stat file_info;

	/*Gestion d'erreurs. stat renvoie NULL en cas d'errreur*/
	if (argc != 2 || !stat(argv[1], &file_info))
		return (0);

	printf("%d\n", file_info.st_mode);
}

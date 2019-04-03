#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdio.h>

void print_stat(struct stat *file_info)
{
	printf("\033[0;35m");
	printf("st_dev : [%d]\n", file_info->st_dev);
	printf("st_mode : [%d]\n", file_info->st_mode);
	printf("st_nlink : [%d]\n", file_info->st_nlink);
	printf("st_ino : [%llu]\n", file_info->st_ino);
	printf("st_uid : [%d]\n", file_info->st_uid);
	printf("st_gid : [%d]\n", file_info->st_gid);
	printf("st_rdev : [%d]\n", file_info->st_rdev);
	printf("st_atimespec : [%lld.%.9ld]\n",	
		(long long)file_info->st_atimespec.tv_sec,
		file_info->st_atimespec.tv_nsec);
	printf("st_mtimespec : [%lld.%.9ld]\n",
		(long long)file_info->st_mtimespec.tv_sec,
		file_info->st_mtimespec.tv_nsec);
	printf("st_ctimespec : [%lld.%.9ld]\n",	
		(long long)file_info->st_ctimespec.tv_sec,
		file_info->st_ctimespec.tv_nsec);
	printf("st_birthtimespec : [%lld.%.9ld]\n",	
		(long long)file_info->st_birthtimespec.tv_sec,
		file_info->st_birthtimespec.tv_nsec);
	printf("st_size : [%lld]\n", file_info->st_size);
	printf("st_blocks : [%lld]\n", file_info->st_blocks);
	printf("st_blksize : [%d]\n", file_info->st_blksize);
	printf("st_flags : [%d]\n", file_info->st_flags);
	printf("st_gen : [%d]\n", file_info->st_gen);
	printf("st_lspare : [%d]\n", file_info->st_lspare);
	printf("st_qspare : {%lld,%lld}\n\n", 
		file_info->st_qspare[0], file_info->st_qspare[1]);
	printf("\033[0m");
}

char *file_mode(char *str, int st_mode)
{
	str[0] = st_mode & S_IFDIR ? 'd' : '-';
	str[1] = st_mode & S_IRUSR ? 'r' : '-';
	str[2] = st_mode & S_IWUSR ? 'w' : '-';
	str[3] = st_mode & S_IXUSR ? 'x' : '-';
	str[4] = st_mode & S_IRGRP ? 'r' : '-';
	str[5] = st_mode & S_IWGRP ? 'w' : '-';
	str[6] = st_mode & S_IXGRP ? 'x' : '-';
	str[7] = st_mode & S_IROTH ? 'r' : '-';
	str[8] = st_mode & S_IWOTH ? 'w' : '-';
	str[9] = st_mode & S_IXOTH ? 'x' : '-';
	return (str);
}
int main(int argc, char **argv)
{
	/*Declaration des variables requises (man 2 stat)*/
	struct stat file_info;

	/*Autres variables*/
	char modes[10] = "----------";
	/*Gestion d'erreurs. stat renvoie NULL en cas d'errreur*/
	if (argc != 2 || stat(argv[1], &file_info))
		return (0);
	print_stat(&file_info);

	printf("\033[0;32m");
	printf("Nom: %s\n", argv[1]); 
	printf("Type: \n"); //TODO
	printf("Modes: %.10s\n", file_mode(modes, file_info.st_mode)); //TODO
	printf("Nombre de liens: %d\n", file_info.st_nlink);
	printf("Proprietaire: %s\n", getpwuid(file_info.st_uid)->pw_name);
	printf("Groupe: %s\n", getgrgid(file_info.st_gid)->gr_name);
	printf("Taille: %lld octets\n", file_info.st_size);
	printf("Date de derniere modification: %.12s\n\n\n", 
			&ctime(&file_info.st_mtimespec.tv_sec)[4]);
	printf("%d", S_IFMT);
	printf("\033[0m");
}

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <grp.h>
#include <stdlib.h>
#include <pwd.h>
#include <time.h>
#include <string.h>

#define BUFFER_SIZE 50

/**
 * @brief 
 * function that shows all the details ls -l would display on a file or directory
 * @param ref 
 * @param statut 
 */
void print_stat(const char * ref, struct stat *statut){
	struct passwd * pw;
	struct group *gr;
	char type;
}

int main(int argc, char * argv[]){

char *file = argv[1];
char * grs;

long long size; 
    mode_t    mode;     /* Protection */
    nlink_t   nlink;    /* Nb liens matériels */
    uid_t     uid;      /* UID propriétaire */
    gid_t     gid;      /* GID propriétaire */
	time_t 	date_time;

struct stat *info = malloc(sizeof(struct stat)); //allocates memory for stat structure.

struct filedetails {
	char * file_mode;
	int file_nlink;
	int file_uid;
	int file_gid;
	long long file_size;
	char * file_modif_date;
	char * file_name;
};

errno = 0; 

if(stat(file, info) == 0)
	{	
	    size = info->st_size;
	    nlink = info->st_nlink;
	    //uid = info->st_uid;
	    //gid = info->st_gid;
	    mode = info->st_mode;
		
		// getting the mtime
		struct timespec modifytime;
		modifytime = info->st_mtim;
		timespec_get(&modifytime, TIME_UTC);
		char mtime[ BUFFER_SIZE ];
		strftime( mtime, BUFFER_SIZE, "%d %b %H:%M", gmtime( &modifytime.tv_sec ) );

		// On affiche la date de modification (mtime)
		printf( "modification time: %s UTC\n", mtime);

	    printf("Size of \"%s\" is %lld.\n", file, size);
	
		// extracting file_owner uid
	   struct passwd *pwd;
	   pwd = getpwuid(info->st_uid);
	   if(pwd == NULL){
			perror("getpwuid");
	   }else{
			printf("file proprietary : %s\n", pwd->pw_name);
	   }

		
		// extracting owner_group_id gid
		struct group *gr;
		gr = getgrgid(info->st_gid);
		if(gr != NULL){
			printf("the user group is %s\n", gr->gr_name);
		}else {
			perror("getgrgid");
		}

		// extracting the n_link
		 printf("nlink of \"%s\" is %ld.\n", file, nlink);

		// extracting the mode
		printf("%c", S_ISDIR(info->st_mode)? 'd' : '-');
		printf("%c", info->st_mode & S_IRUSR ? 'r' : '-');
		printf("%c", info->st_mode & S_IWUSR ? 'w' : '-');
		printf("%c", (info->st_mode & S_IXUSR) ? 'x' : '-');
		
		printf("%c", info->st_mode & S_IRGRP ? 'r' : '-');
		printf("%c", info->st_mode & S_IWGRP ? 'w' : '-');
		printf("%c", info->st_mode & S_IXGRP ? 'x' : '-');
		printf("%c", info->st_mode & S_IROTH ? 'r' : '-');
		printf("%c", info->st_mode & S_IWOTH ? 'w' : '-');
		printf("%c", info->st_mode & S_IXOTH ? 'x' : '-');
		printf("\n");
	}
else
	{
	    perror(file);    //if stat fails, print a diagnostic.
	}
	
//printf("%s %ld %s %s %lld %s %s %s", mode, nlink, uid, gid, size, date_time, file);
	

return 0;
}

// man 2 stat
// man 3 getpwuid
// man 3 getgrgid
// 	strftime
// gcc -o mon_pro mon_prog.c -Wall
// ouvrir le repertoire avec Opendir

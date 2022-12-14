#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
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

	struct filedetails {
		char * file_mode;
		int file_nlink;
		char* file_uid;
		char * file_gid;
		long long file_size;
		char * file_modif_date;
		char * file_name;
	};

	errno = 0; 
	struct filedetails filedata;
	// filedata.file_name = ref;

	if(stat(ref, statut) == 0)
		{	
			// getting the mtime
			struct timespec modifytime;
			modifytime = statut->st_mtim;
			timespec_get(&modifytime, TIME_UTC);
			char mtime[ BUFFER_SIZE ];
			if(strftime( mtime, BUFFER_SIZE, "%b %d %H:%M", gmtime( &modifytime.tv_sec )) == -1){
				perror("date and time not captured strftime");
			}
			
			filedata.file_modif_date = mtime;

			filedata.file_size = statut->st_size;

		// extracting file_owner uid
		struct passwd *pwd;
		pwd = getpwuid(statut->st_uid);
		if(pwd == NULL){
				perror("getpwuid");
		}else{
				filedata.file_uid = pwd->pw_name;
		}

			// extracting owner_group_id gid
			struct group *gr;
			gr = getgrgid(statut->st_gid);
			if(gr != NULL){
				filedata.file_gid = gr->gr_name;
			}else {
				perror("getgrgid");
			}

			// extracting the n_link
			filedata.file_nlink = statut->st_nlink;

			// extracting the mode
			char mode[11];

			sprintf(mode, "%c%c%c%c%c%c%c%c%c%c", 

				S_ISDIR(statut->st_mode)? 'd' : '-',
				// user rights
				statut->st_mode & S_IRUSR ? 'r' : '-',
				statut->st_mode & S_IWUSR ? 'w' : '-',
				statut->st_mode & S_IXUSR ? 'x' : '-',
				// group rights
				statut->st_mode & S_IRGRP ? 'r' : '-',
				statut->st_mode & S_IWGRP ? 'w' : '-',
				statut->st_mode & S_IXGRP ? 'x' : '-',
				// others 
				statut->st_mode & S_IROTH ? 'r' : '-',
				statut->st_mode & S_IWOTH ? 'w' : '-',
				statut->st_mode & S_IXOTH ? 'x' : '-'
			);
				filedata.file_mode = mode;
		}
		else
		{
			perror(ref);    //if stat fails, print a diagnostic.
		}
		
	printf("%s %d %s %s %lld %s %s\n", filedata.file_mode, filedata.file_nlink, filedata.file_uid, filedata.file_gid, filedata.file_size, filedata.file_modif_date, ref);
		

}

/**
 * @brief list directory content iteratively
 * 
 * @param nameDir 
 */
void ls_dir(char*nameDir){
 
  DIR*dir=opendir(nameDir);
  struct dirent* d;
 
  if(dir){
    while( (d=readdir(dir)) ){
	  printf("%s\n",d->d_name);
    }
    closedir(dir);
  }
}

int main(int argc, char * argv[]){

char *file = argv[1];
struct stat *statut = malloc(sizeof(struct stat));

print_stat(file, statut);

return 0;
}

// man 2 stat
// man 3 getpwuid
// man 3 getgrgid
// 	strftime
// gcc -o mon_pro mon_prog.c -Wall
// ouvrir le repertoire avec Opendir

#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>



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

    printf("reading path\n");
    char * path = argv[1];
    
    ls_dir(path);
    printf("program ends\n");
}
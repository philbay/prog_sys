#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>



void ls_dir(char*dir_name){
 
  DIR*dir=opendir(dir_name);
  if(dir == NULL){
    return;
  }

    struct dirent* dir_entry;
    dir_entry = readdir(dir);
    while(dir_entry != NULL){
        //if(dir_entry->d_type == DT_REG)
        printf("%s\n", dir_entry->d_name);
        dir_entry = readdir(dir);
    }
     closedir(dir);
}

int main(int argc, char * argv[]){

    printf("reading path\n");
    char * path = argv[1];

    ls_dir(path);
    printf("program ends\n");
}
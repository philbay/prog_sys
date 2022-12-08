#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

#define BUFFER_SIZE 100

void ls_dir(char*dir_name){
 
  DIR*dir=opendir(dir_name);
  if(dir == NULL){
    return;
  }
    struct dirent* dir_entry;
    dir_entry = readdir(dir);
    while(dir_entry != NULL){
        
        printf("%s %s\n", dir_name, dir_entry->d_name);
        if(dir_entry->d_type == DT_DIR && strcmp(dir_entry->d_name, ".")!= 0 
        && dir_entry->d_type != DT_LNK && strcmp(dir_entry->d_name, "..")!= 0){
            char path[BUFFER_SIZE] = {0};
            strcat(path, dir_name);
            strcat(path, "/");
            strcat(path, dir_entry->d_name);
            ls_dir(path);
        }
        dir_entry = readdir(dir);
    }
     closedir(dir);
}

int main(int argc, char * argv[]){

    printf("***reading path***\n");
    char * path = argv[1];

    ls_dir(path);
    printf("***program ends***\n");
}
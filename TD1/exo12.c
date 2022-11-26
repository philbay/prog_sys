#include <sys/syscall.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

void pr_pathconf(char *path, int name, char * message){

    printf("%s", message);
    long limit_val = pathconf(path, name);

    if(limit_val == -1){
        perror("erreur");
        printf("errno %d\n", errno);
        exit(1);
    }


  
}

int main(){
    char * chemin;
    chemin = (char*)malloc(256*sizeof(char));
    printf("%s", chemin);
    // scanf("%s", chemin);
    fgets(chemin, 255, stdin);
    chemin[strlen(chemin)-1] = '\0';
    pr_pathconf(chemin, _PC_LINK_MAX,"nombre max de liens associes: ");
    
    free(chemin);
    return 0;
}
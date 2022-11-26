#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){

	extern char **environ;
	
	printf("%s\n", argv);
	int i = 0;
	while(environ[i] != NULL)
	{
	// printf("%s \n",  environ[i]);
	i++;
}
return 0;
}

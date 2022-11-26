#include <stdlib.h>
#include <stdio.h>

int main(){

	extern char **environ;
	
	int i = 0;
	while(environ[i] != NULL)
	{
	printf("%s \n",  environ[i]);
	i++;
}
return 0;
}

#include <unistd.h>
#include <stdio.h>
int main()
{
	int j;
	j = sysconf(_SC_VERSION);
	printf("from Exo4: _SC_VERSION=%i\n", j);

return 0;
}

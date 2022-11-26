#include <sys/syscall.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
/* Exercices 8 ~ 11
    Numero |  Sorties
    ----------------------
        0  | Entree
        1  | Sortie Standard
        2  | sortie err
*/

int main()
{
    // write(3, "hello\n", 6);
    if (syscall(SYS_write, 2, "hello\n", 6) == -1)
    {
        perror("erreur");
        printf("errno %d\n", errno);
        exit(1);
    }
}
// Exercice 4
#include <stdio.h>

void main(int argc, char *argv)
{
    printf("hello, world");
    // printf("%s", argv[1]);
    // content_nlines(2, argv[1]);
}

char *content_nlines(int n, char *filename)
{
    FILE *file;
    char ch;
    int nlines = 0;

    if ((file = fopen(filename, "w+")) != -1)
    {
        while (ch = fgetc(file) != EOF)
        {
            if (ch == '\n')
            {
                nlines++;
                printf("%d", nlines);
            }
        }
    }
    else
    {
        perror("file corrupted or not found");
    }
    return "hello";
}

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void ordinaCrescente(int argc, char *argv[])
{
    char *tmp[1];
    for (int i = 3; i < argc; i++)
    {
        for (int k = 3; k < argc - 1; k++)
            if (strcmp(argv[k], argv[k + 1]) < 0)
            {
                tmp[0] = argv[k];
                argv[k] = argv[k + 1];
                argv[k + 1] = tmp[0];
            }
    }
}

void ordinaDecrescente(int argc, char *argv[])
{
    char *tmp[1];
    for (int i = 3; i < argc - 1; i++)
    {
        for (int k = 3; k < argc - 2; k++)
            if (strcmp(argv[k], argv[k + 1]) > 0)
            {
                tmp[0] = argv[k];
                argv[k] = argv[k + 1];
                argv[k + 1] = tmp[0];
            }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        printf("errore negli argomenti inseriti\n");
        return -1;
    }

    if (strcmp(argv[2], "--asc"))
        ordinaCrescente(argc, argv);
    else if (strcmp(argv[2], "--desc"))
        ordinaDecrescente(argc, argv);
    else
    {
        printf("errore flag di ordinamento");
        return -1;
    }
    
    int fd = open(argv[1], O_WRONLY | O_CREAT);

    for (int i = 3; i < argc; i++)
    {
        printf("%s\n", argv[i]);
        write(fd, argv[i], strlen(argv[i]));
        write(fd, "\n", strlen("\n"));
    }
    close(fd);
    return 0;
}
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/fcntl.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int pid;
    pid = fork();
    if(pid == 0)
    {
        printf("La stringa maiuscolo è :");

        for(int i = 0; i<strlen(argv[1]); i++)
        {
            printf("%c", toupper(argv[1][i]));
        }
        
        printf("\n");
        exit(0);
    }
    else
    {
        wait(&pid);
    }

    printf("Il mio figlio è terminato\n");
    return 0;
}
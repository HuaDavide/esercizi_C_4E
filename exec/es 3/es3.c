#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("errore negli argomenti inseriti\n");
        return -1;
    }

    int pid;

    for (int i = 0; i < argc; i++)
    {
        pid = fork();
        if (pid == 0)
        {
            execl("/usr/bin/rm", "rm", argv[i], NULL);
            printf("errore nella chiamata di execl\n");
            return -1;
        }
        else
        {
            wait(&pid);
        }
    }

    return 0;
}
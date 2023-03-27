#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> //libreria che contiene flag di open
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Errore inserimento parametri\n");
        exit(0);
    }

    int p1p2[2], pid;

    pipe(p1p2);
    pid = fork();

    if (pid == 0)
    {
        close(p1p2[0]);
        close(1);
        dup(p1p2[1]);
        close(p1p2[1]);

        execl("/use/bin/cat", "cat", argv[1], NULL);
        return -1;
    }
    pid = fork();

    if (pid == 0)
    {
        close(p1p2[1]);
        close(0);
        dup(p1p2[0]);
        close(p1p2[0]);
        execl("/usr/bin/grep", "grep", argv[2], argv[1], NULL);
        return -1;
    }

    close(p1p2[1]);
    close(p1p2[0]);
    
    return 0;
}
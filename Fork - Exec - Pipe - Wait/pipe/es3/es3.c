#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> //libreria che contiene flag di open
#include <string.h>

int main(int argc, char *argv[])
{
    int p1p2[2];
    char estensione[10];
    char est[11] = {"."};
    printf("Inserisci l'estensione che vuoi cercare : ");
    scanf("%s", estensione);
    pipe(p1p2);
    int pid = fork();
    if (pid == 0)
    {
        close(p1p2[0]);
        close(1);
        dup(p1p2[1]);
        close(p1p2[1]);

        execl("/usr/bin/ls", "ls", NULL);
        return -1;
    }

    pid = fork();

    if (pid == 0)
    {
        close(p1p2[1]);
        close(0);
        dup(p1p2[0]);
        close(p1p2[0]);

        execl("/usr/bin/grep", "grep", strcat(est, estensione), NULL);
        return -1;
    }

    close(p1p2[0]);
    close(p1p2[1]);

    return 0;
}
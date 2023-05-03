#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> //libreria che contiene flag di open
#include <string.h>
#include <wait.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Errore inserimento parametri\n");
        exit(0);
    }

    int pid, p1p2[2];
    pipe(p1p2);
    char stringa[100];

    printf("Inserisci la parola che vuoi cercare:\n");
    scanf("%s", stringa);

    pid = fork();
    if (pid == 0)
    {
        close(p1p2[0]);
        close(1);
        dup(p1p2[1]);
        close(p1p2[1]);
    
        execl("/usr/bin/cat", "cat", argv[1], (char *)0);
        return -1;
    }

    pid = fork();

    if (pid == 0)
    {
        close(p1p2[1]);
        close(0);
        dup(p1p2[0]);
        close(p1p2[0]);

        close(1);

        remove("result");
        int fd = open("result", O_WRONLY | O_CREAT, 0777);

        execl("/usr/bin/grep", "grep", stringa, (char *)0);
        return -1;
    }

    wait(&pid);
    close(p1p2[1]);
    close(p1p2[0]);

    return 0;
}

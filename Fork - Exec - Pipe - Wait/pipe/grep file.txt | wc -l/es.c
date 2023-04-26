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

    int pid, p1p2[2], p2p0[2];
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
        printf("%s", stringa);
        execl("/usr/bin/grep", "grep", stringa, argv[1], (char *)0);
        return -1;
    }

    pipe(p2p0);
    pid = fork();

    if (pid == 0)
    {
        close(p1p2[1]);
        close(0);
        dup(p1p2[0]);
        close(p1p2[0]);

        close(p2p0[0]);
        close(1);
        dup(p2p0[1]);
        close(p2p0[1]);

        execl("/usr/bin/wc", "wc", "-l", (char *)0);
        return -1;
    }

    wait(&pid);
    close(p1p2[1]);
    close(p1p2[0]);
    close(p2p0[1]);

    int nRead = 0;
    int fd = open("ris", O_WRONLY);

    while (nRead = read(p2p0[0], stringa, strlen(stringa)) > 0)
    {
        write(fd, stringa, nRead);
    }

    close(p2p0[0]);

    return 0;
}

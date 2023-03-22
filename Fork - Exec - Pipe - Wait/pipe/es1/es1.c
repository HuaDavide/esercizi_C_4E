#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> //libreria che contiene flag di open
#include <string.h>
int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Errore inserimento parametri");
        exit(0);
    }

    int p1p2[2], p2p0[2], pid;
    char stringa[50], str[100];

    pipe(p1p2);
    pid = fork();
    if(pid == 0)
    {
        close(p1p2[0]);
        close(1);
        dup(p1p2[1]);
        close(p1p2[1]);

        execl("/use/bin/cat", "cat", argv[1], NULL);
        return -1;
    }


    printf("Inserisci la stringa da ricercare: ");
    scanf("%s", stringa);

    pipe(p2p0);
    pid = fork();

    if(pid == 0)
    {
        close(0);
        dup(p1p2[0]);
        close(p1p2[0]);
        close(p2p0[0]);
        close(1);
        dup(p2p0[1]);
        close(p2p0[1]);

        execl("/usr/bin/grep", "grep", stringa, NULL);
        return -1;
    }

    close(p1p2[1]);
    close(p1p2[0]);

    int fd = open("risultato.txt", O_WRONLY | O_CREAT, 0644);
    int nRead;
    while(nRead = read(p2p0[0], stringa, strlen(stringa) > 0))
    {
        write(fd, stringa, nRead);
    }

    close(p2p0[1]);
    close(p2p0[0]);
    return 0;

}
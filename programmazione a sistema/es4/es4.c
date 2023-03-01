#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("errore nei parametri inseriti.\n");
        return -1;
    }

    char stringa[100], contatore[100];
    int p1p2[2], p2p0[2], totale = 0, pid;

    while(1)
    {
        printf("Inserisci la stringa da cercare: ");
        scanf("%s", stringa);

        if(strcmp(stringa, "fine"))
        {
            printf("\n\nIn tutti sono stati trovati trovati %d stringhe\n", totale);
            exit(1);
        }

        pipe(p1p2);
        pid = fork();

        if(pid == 0)
        {
            close(p1p2[0]);
            close(1);
            dup(p1p2[1]);
            close(p1p2[1]);

            execl("/usr/bin/grep", "grep", "-ow", stringa, argv[1], NULL);
            return -1;
        }

        pipe(p2p0);
        pid = fork();
        if(pid == 0)
        {
            close(p1p2[1]);
            close(0);
            dup(p1p2[0]);
            close(p1p2[0]);
        }


    }
}
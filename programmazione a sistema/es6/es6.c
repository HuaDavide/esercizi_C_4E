#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("errore nei parametri inseriti\n");
        return -1;
    }

    char strimporto[1], *conversione, stringa[100];
    int pid, p1p2[2], p2p0[2];
    double totale = 0;

    pipe(p1p2);
    pid = fork();
    if (pid == 0)
    {
        close(p1p2[0]);
        close(1);
        dup(p1p2[1]);
        close(p1p2[1]);
        execl("/usr/bin/cat", "cat", argv[1], NULL);
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

        execl("/usr/bin/awk", "awk", "{print $3}", NULL);
        return -1;
    }

    close(p1p2[0]);
    close(p1p2[1]);
    close(p2p0[1]);

    while (read(p2p0[0], strimporto, 1) > 0)
    {
        strncat(stringa, strimporto, sizeof(strimporto));
        if (strimporto[0] == '\n')
        {
            totale += strtod(stringa, &conversione);
            stringa[0] = '\0';
        }
    }
    
    close(p2p0[0]);
    printf("L'importo totale: %lf\n", totale);
    return 0;
}
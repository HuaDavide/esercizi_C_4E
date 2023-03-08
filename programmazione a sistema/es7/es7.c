#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Argomenti inseriti errati");
        exit(0);
    }

    int p1p2[2], p2p3[2], p3p0[2], pid;
    double totale = 0;
    char stringa, tempo[100], *conversione;

    pipe(p1p2);
    pid = fork();
    if (pid == 0)
    {
        close(p1p2[0]);
        close(1);
        dup(p1p2[1]);
        close(p1p2[1]);

        execl("/usr/bin/traceroute", "traceroute", argv[1], NULL);
        return -1;
    }

    pipe(p2p3);
    pid = fork();

    if (pid == 0)
    {
        close(p1p2[1]);
        close(0);
        dup(p1p2[0]);
        close(p1p2[0]);

        close(p2p3[0]);
        close(1);
        dup(p2p3[1]);
        close(p2p3[1]);

        execl("/usr/bin/awk", "awk", "{print $4}", NULL);
        return -1;
    }

    close(p1p2[0]);
    close(p1p2[1]);
    pipe(p3p0);
    pid = fork();

    if (pid == 0)
    {
        close(p2p3[1]);
        close(0);
        dup(p2p3[0]);
        close(p2p3[0]);

        close(p3p0[0]);
        close(1);
        dup(p3p0[1]);
        close(p3p0[1]);

        execl("/usr/bin/tail", "tail", "-n", "+2", NULL);
    }

    close(p2p3[0]);
    close(p2p3[1]);
    close(p3p0[1]);

    while (read(p3p0[0], &stringa, 1) > 0)
    {

        strncat(tempo, &stringa, sizeof(stringa));

        if (stringa == '\n')
        {   
            totale += strtod(tempo, &conversione);
            tempo[0] = '\0';
        }
    }

    close(p3p0[0]);
    printf("Tempo totale impiegato = %.3lf\n", totale);
    return 0;
}
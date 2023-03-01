#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/fcntl.h>
#include <ctype.h>
#define NRFIGLI 4

int main(int argc, char *argv[])
{
    int pid, status, x;
    pid = fork();
    if (pid == 0)
    {
        printf("Sono il processo figlio con pid %d", getpid());
        printf(" il mio papi ha pid %d\n", getppid());
        exit(0);
    }

    printf("Sono il processo padre con pid %d\n", getpid());
    printf("Il pid del figlio corrente e' %d\n", pid);
    printf("L'exit di mio figlio (%d) e' %d\n\n", wait(&status), status);
    return 0;
}
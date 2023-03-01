#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <wait.h>

int main(int argc, char *argv[])
{
    int p1p2[2], p2p0[2], pid;

    pipe(p1p2);
    pipe(p2p0);

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

    wait(&pid);

    pid = fork();

    if (pid == 0)
    {
        close(p1p2[0]);
        close(p2p0[0]);
        close(0);
        dup(p1p2[0]);
        close(p1p2[0]);
        close(1);
        dup(p2p0[1]);
        close(p2p0[1]);
        execl("/usr/bin/wc", "wc", 0, NULL);
        return -1;
    }

    close(p1p2[0]);
    close(p1p2[1]);
    close(p2p0[1]);
    close(0);
    dup(p2p0[0]);
    close(p2p0[0]);
    close(1);
    open("wc.txt", O_WRONLY);
    char stringa[100];
    read(0, stringa, strlen(stringa));
    write(1, stringa, strlen(stringa));
    return 0;
}
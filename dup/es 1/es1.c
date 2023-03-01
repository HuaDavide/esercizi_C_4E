#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
int main(int argc, char *argv[])
{
    int pid;

    int p1p2[2];
    pipe(p1p2);

    pid = fork();

    if (pid == 0)
    {

        close(1);
        dup(p1p2[1]);
        close(p1p2[0]);
        close(p1p2[1]);
        execl("/usr/bin/cat", "cat", argv[1], NULL);
    }


    wait(&pid);
    pid = fork();
    if (pid == 0)
    {
        close(0);
        dup(p1p2[0]);
        close(p1p2[0]);
        close(p1p2[1]);
        execl("/usr/bin/more", "more", 0, NULL);
    }

    wait(&pid);
    return 0;
}
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <wait.h>
int main(int argc, char *argv[])
{
    int p1p0[2];
    pipe(p1p0);
    int pid = fork();
    if(pid == 0)
    {
        close(p1p0[0]);
        char stringa[strlen(argv[1])];
        for(int i = 0; i<strlen(argv[1]);i++)
            stringa[i] += toupper(argv[1][i]);
        
        write(p1p0[1], stringa, strlen(stringa));
        exit(0);
    }

    wait(&pid);
    close(p1p0[1]);
    char stringa[2];
    read(p1p0[0], stringa, strlen(stringa));
    printf("stringa maiuscolo: %s\n", stringa);
    return 0;
}
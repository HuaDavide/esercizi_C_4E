#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("errore negli argomenti inseriti\n");
        return -1;
    }

    execl("/usr/bin/cat", "cat", argv[1], NULL);
    printf("errore nella chiamata di execl");
    return -1;
}
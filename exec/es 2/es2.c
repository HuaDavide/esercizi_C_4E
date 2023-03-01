#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("errore negli argomenti inseriti\n");
        return -1;
    }
    
    execl("/usr/bin/cp", "cp", argv[1], argv[2], NULL);
    printf("errore nella chiamata di execl\n");
    return -1;
}
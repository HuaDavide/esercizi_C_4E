#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int num;
    printf("%d", getpid());
    scanf("%d", &num);
    close(0);
    sleep(120);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n;
    
    printf("Inserisci il valore del numero N: ");
    scanf("%d", &n);
    
    for(int i = 0 ; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i+j == n)
            {
                printf("\n%d + %d", i,j);
            }
        }
    }

    printf("\n");
    return 0;
}
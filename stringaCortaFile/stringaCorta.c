#include <stdio.h>
#include <string.h>
#define DIM 100

int stringaCorta(char stringa[], char str[])
{
    
}

int main()
{
    FILE *f1, *f2, *f3;
    char stringa1[DIM], stringa2[DIM], corta[DIM];

    f1 = fopen("FILE1.txt", "r");
    f2 = fopen("FILE2.txt", "r");
    f3 = fopen("risultato.txt", "w");

    if(f1 == NULL || f2 == NULL || f3== NULL)
    {
        printf("errore apritura file");
        return -1;
    }

    while(!feof(f1))
    {

    }
}
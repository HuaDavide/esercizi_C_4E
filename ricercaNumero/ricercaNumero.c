#include <stdio.h>

int ricerca(int n, char *argv[], int argc)
{
    for(int i = 1; i<argc;i++)
    {
        if(atoi(argv[i]) == n)
            return i;
    }
    
    return -1;
}

int main(int argc, char *argv[])
{
    int numero;

    printf("Inserisci un numero:");
    scanf("%d", &numero);

    int posizione = ricerca(numero, argv, argc);

    if(posizione >= 0)
    {
        printf("posizione= %d \n", posizione);
    }
    else
    {
        printf("numero non presente");
    }

    return 0;
}


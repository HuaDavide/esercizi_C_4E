#include <stdio.h>
int Max(int numeri[], int N)
{
    int Max = numeri[0];

    for (int i = 1; i < N; i++)
    {
        if (numeri[i] > Max)
        {
            Max = numeri[i];
        }
    }

    return Max;
}

int Min(int numeri[], int N)
{
    int Min = numeri[0];

    for (int i = 1; i < N; i++)
    {
        if (numeri[i] < Min)
        {
            Min = numeri[i];
        }
    }

    return Min;
}

int main()
{
    int N;

    printf("Quanti numeri vuoi inserire? ");
    scanf("%d", &N);

    int numeri[N];

    for (int i = 0; i < N; i++)
    {
        printf("Inserisci il %d numero: ", i + 1);
        scanf("%d", &numeri[i]);
    }

    printf("\nIl numero massimo dei numeri inseriti è: %d", Max(numeri, N));
    printf("\nIl numero minimo dei numeri inseriti è: %d\n", Min(numeri, N));
    
    return 0;
}


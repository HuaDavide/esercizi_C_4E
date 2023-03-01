#include <stdio.h>
#include <stdlib.h>

void inserisci(int numeri[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("array[%d] = ", i);
        scanf("%d", &numeri[i]);
    }
}

void stampa(int numeri[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", numeri[i]);
    }
}

void inverti(int numeri[], int n)
{
    int numero, lung = n - 1;

    for (int i = 0; i < n / 2; i++)
    {
        numero = numeri[i];
        numeri[i] = numeri[lung];
        numeri[lung] = numero;
        lung--;
    }
}

int somma(int numeri[], int n)
{
    int somma = 0;

    for (int i = 0; i < n; i++)
    {
        somma += numeri[i];
    }

    return somma;
}

void pari(int numeri[], int pari[], int n, int *nPari)
{
    int numero;

    for (int i = 0; i < n; i++)
    {
        numero = numeri[i] % 2;

        if (numero == 0)
        {
            pari[*nPari] = numeri[i];
            (*nPari)++;
        }
    }
}

void dispari(int numeri[], int dispari[], int n, int *nDispari)
{
    int numero;

    for (int i = 0; i < n; i++)
    {
        numero = numeri[i] % 2;

        if (numero == 1)
        {
            dispari[*nDispari] = numeri[i];
            (*nDispari)++;
        }
    }
}

int ricerca(int numeri[], int n, int numero)
{
    for (int i = 0; i < n; i++)
    {
        if (numeri[i] == numero)
            return i;
    }

    return -1;
}

void elimina(int numeri[], int *n, int posizione)
{
    (*n)--;

    for (int i = posizione; i < *n; i++)
    {
        numeri[i] = numeri[i + 1];
    }
}

void alterna(int numeri[], int n)
{
    int appoggio;
    for (int i = 0; i < n - 1; i = i + 2)
    {
        appoggio = numeri[i];
        numeri[i] = numeri[i + 1];
        numeri[i + 1] = appoggio;
    }
}

void ordina(int numeri[], int n)
{
    int appoggio;
    int scambio = 1;
    for (int i = 0; i < n && scambio; i++)
    {
        scambio = 0;
        for (int i = 0; i < n; i++)
        {
            if (numeri[i] > numeri[i + 1])
            {
                appoggio = numeri[i];
                numeri[i] = numeri[i + 1];
                numeri[i + 1] = appoggio;
                scambio = 1;
            }
        }
    }
}

void menu()
{
    printf("\n\n====Menu====\n");
    printf("1)stampa\n");
    printf("2)inverti\n");
    printf("3)somma e media\n");
    printf("4)stampa pari\n");
    printf("5)stampa dispari\n");
    printf("6)ricerca\n");
    printf("7)elimina\n");
    printf("8)alterna\n");
    printf("9)ordina\n");
    printf("10)esci\n");
}

int main()
{
    int indice, numero, posizione, scelta, indPari = 0, indDispari = 0;
    double media, som;

    printf("Inserisci la lunghezza dell'array: ");
    scanf("%d", &indice);

    int numeri[indice], nPari[indice], nDispari[indice];

    inserisci(numeri, indice);

    do
    {

        do
        {

            menu();
            printf("scegli l'opzione: ");
            scanf("%d", &scelta);

            system("clear");

            if (!(scelta >= 1 && scelta <= 10))
            {
                printf("\nL'opzione errata");
            }

        } while (!(scelta >= 1 && scelta <= 10));

        switch (scelta)
        {
        case 1:
            printf("Contenuto array: ");
            stampa(numeri, indice);
            break;

        case 2:
            inverti(numeri, indice);
            printf("L'array invertita: ");
            stampa(numeri, indice);
            break;

        case 3:
            som = somma(numeri, indice);
            printf("La somma dei contenuti: %f\n", som);

            media = som / indice;
            printf("La media dei contenuti: %f", media);
            break;

        case 4:
            pari(numeri, nPari, indice, &indPari);
            printf("Numeri pari: ");
            stampa(nPari, indPari);
            indPari = 0;
            break;

        case 5:
            dispari(numeri, nDispari, indice, &indDispari);
            printf("Numeri dispari: ");
            stampa(nDispari, indDispari);
            indDispari = 0;
            break;

        case 6:
            printf("Inserisci il numero da ricercare: ");
            scanf("%d", &numero);

            posizione = ricerca(numeri, indice, numero);
            if (posizione != -1)
            {
                printf("Il numero si trova nella posizione %d", posizione);
            }
            else
            {
                printf("\nIl numero non esiste");
            }
            break;

        case 7:
            printf("Inserisci il numero da eliminare: ");
            scanf("%d", &numero);
            posizione = ricerca(numeri, indice, numero);

            if (posizione != -1)
            {
                printf("numero eliminato");
                elimina(numeri, &indice, posizione);
            }
            else
            {
                printf("\nIl numero non esiste");
            }
            break;

        case 8:
            printf("L'array alternata: ");
            alterna(numeri, indice);
            stampa(numeri, indice);
            break;

        case 9:
            printf("L'array ordinato crescentemente: ");
            ordina(numeri, indice);
            stampa(numeri, indice);
            break;

        default:
            printf("programma terminata\n");
            break;
        }

    } while (scelta != 10);

    return 0;
}
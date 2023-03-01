#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int numeroVocali(char stringa[])
{
    bool seVocale;
    int nVocali = 0;
    for (int i = 0; i < strlen(stringa); i++)
    {
        seVocale = (stringa[i] == 'a' || stringa[i] == 'e' || stringa[i] == 'i' || stringa[i] == 'o' || stringa[i] == 'u' || stringa[i] == 'A' || stringa[i] == 'E' || stringa[i] == 'I' || stringa[i] == 'O' || stringa[i] == 'U');
        if (seVocale)
        {
            nVocali++;
        }
    }

    return nVocali;
}

int numeroConsonanti(char stringa[])
{
    bool seConsonante;
    int nConsonanti = 0;
    for (int i = 0; i < strlen(stringa); i++)
    {
        seConsonante = ((stringa[i] >= 65 && stringa[i] <= 90) || (stringa[i] >= 97 && stringa[i] <= 122)) && !(stringa[i] == 'a' || stringa[i] == 'e' || stringa[i] == 'i' || stringa[i] == 'o' || stringa[i] == 'u' || stringa[i] == 'A' || stringa[i] == 'E' || stringa[i] == 'I' || stringa[i] == 'O' || stringa[i] == 'U');
        if (seConsonante)
        {
            nConsonanti++;
        }
    }

    return nConsonanti;
}

int main()
{
    FILE *f1, *f2;
    char stringa[100];
    int nVocali = 0, nConsonanti = 0, nStringhe = 0;
    int i;

    f1 = fopen("FILE.txt", "r");

    if (f1 == NULL)
    {
        printf("Errore apertura del file!\n");
        return -1;
    }

    while (!feof(f1))
    {
        fscanf(f1, "%s", stringa);

        nVocali += numeroVocali(stringa);
        nConsonanti += numeroConsonanti(stringa);
        nStringhe++;
    }
    fclose(f1);

    f2 = fopen("RISULTATO.txt", "w");
    fprintf(f2, "Numero vocali = %d\nNumero consonanti = %d\nNumero stringhe = %d", nVocali, nConsonanti, nStringhe);
    fclose(f2);

    return 0;
}
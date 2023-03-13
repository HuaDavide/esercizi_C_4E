#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int verificaLettere(char stringa[])
{
    for (int i = 0; i < strlen(stringa); i++)
    {
        if (!((stringa[i] >= 65 && stringa[i] <= 90) || (stringa[i] >= 97 && stringa[i] <= 122)))
        {
            return -1;
        }
    }

    return 1;
}

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

int numeroLettera(char stringa[], char lettera)
{
    int nLettera = 0;
    for (int i = 0; i < strlen(stringa); i++)
    {
        if (stringa[i] == lettera)
        {
            nLettera++;
        }
    }

    return nLettera;
}

void stringaPariDispari(char stringa[], char stringaPari[], char stringaDispari[])
{
    int indPari = 0, indDispari = 0;

    for (int i = 0; i < strlen(stringa); i++)
    {
        if ((i % 2) == 1)
        {
            stringaPari[indPari++] = stringa[i];
        }
        else
        {
            stringaDispari[indDispari++] = stringa[i];
        }
    }
}

int doppie(char stringa[])
{
    for (int i = 1; i < strlen(stringa); i++)
    {
        if (stringa[i] == stringa[i - 1])
            return 1;
    }

    return 0;
}

void lettereAmb(char stringaMAX[], char stringaMIN[], int min, int max, char lettere[])
{
    int cLettera = 0;
    bool esistente;

    for (int i = 0; i < min; i++)
    {
        if (((stringaMIN[i] >= 65 && stringaMIN[i] <= 90) || (stringaMIN[i] >= 97 && stringaMIN[i] <= 122)))
        {
            for (int j = 0; j < max; j++)
            {
                if (((stringaMAX[j] >= 65 && stringaMAX[j] <= 90) || (stringaMAX[j] >= 97 && stringaMAX[j] <= 122)))
                {

                    if (stringaMIN[i] == stringaMAX[j])
                    {
                        esistente = false;

                        for (int k = 0; i < cLettera; i++)
                        {
                            if (lettere[k] == stringaMIN[i])
                            {
                                esistente = true;
                            }
                        }

                        if (!esistente)
                        {
                            lettere[cLettera++] = stringaMIN[i];
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    char stringa1[100], stringaPari[50], stringaDispari[50], stringa2[100], lettereAmbedue[100];
    int nVocali, nConsonanti, nLettera, nVocali2, nConsonanti2;
    char car;

    printf("Inserisci la stringa: ");
    scanf("%s", stringa1);

    if (verificaLettere(stringa1) == -1)
    {
        printf("\nLa stringa non contiene solo lettere\n");
    }
    else
    {
        printf("\nLa stringa contiene solo lettere\n");
    }

    nVocali = numeroVocali(stringa1);
    printf("La stringa contiene %d vocali\n", nVocali);

    nConsonanti = numeroConsonanti(stringa1);

    printf("La stringa contiene %d consonanti\n", nConsonanti);

    printf("\nInserisci una lettera per verificare quante volte è presente nella stringa: ");
    scanf("%s", &car);

    nLettera = numeroLettera(stringa1, car);
    if (nLettera != 0)
    {
        printf("La lettera è presente %d volte\n", nLettera);
    }
    else
    {
        printf("La lettera non è presente\n");
    }

    stringaPariDispari(stringa1, stringaPari, stringaDispari);

    printf("\nLa stringa composta dalle lettere nel posto pari: %s", stringaPari);

    printf("\nLa stringa composta dalle lettere nel posto dispari: %s\n", stringaDispari);

    if (doppie(stringa1))
    {
        printf("\nLa stringa contiene le doppie\n");
    }
    else
    {
        printf("\nLa stringa non contiene doppie\n");
    }

    printf("\nInserisci la seconda stringa: ");
    scanf("%s", stringa2);

    if (strlen(stringa1) > strlen(stringa2))
    {
        printf("\nLa prima stringa è più lungo del secondo");
        lettereAmb(stringa2, stringa1, strlen(stringa2), strlen(stringa1), lettereAmbedue);
    }
    else if (strlen(stringa1) < strlen(stringa2))
    {
        printf("\nLa prima stringa è più corta del secondo");
        lettereAmb(stringa1, stringa2, strlen(stringa1), strlen(stringa2), lettereAmbedue);
    }
    else
    {
        printf("\nLe due stringhe sono lunghe uguali");
        lettereAmb(stringa1, stringa2, strlen(stringa1), strlen(stringa2), lettereAmbedue);
    }

    printf("\nLe lettere ambedue sono: %s\n", lettereAmbedue);
    nVocali2 = numeroVocali(stringa2);
    nConsonanti2 = numeroConsonanti(stringa2);

    if (nVocali2 > nVocali)
    {
        printf("\nLa seconda stringa ha più vocali");
    }
    else if (nVocali > nVocali2)
    {
        printf("\nLa prima stringa ha più vocali");
    }
    else
        printf("\nLe due stringhe hanno numero di vocali uguali");

    if (nConsonanti2 > nConsonanti)
    {
        printf("\nLa seconda stringa ha più consonanti");
    }
    else if (nConsonanti > nConsonanti2)
    {
        printf("\nLa prima stringa ha più consonanti");
    }
    else
        printf("\nLe due stringhe hanno numero di consonanti uguali\n");

    return 0;
}

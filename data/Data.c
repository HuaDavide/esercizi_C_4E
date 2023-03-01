#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2 || strlen(argv[1]) != 8 )
    {
        printf("valore errato\n");
        return -1;
    }

    char giorno[2], mese[2], anno[4];
    int intGiorno, intMese, intAnno, indice;

    for (int i = 0; i < 2; i++)
    {
        giorno[indice++] = argv[1][i];
    }

    intGiorno = atoi(giorno);

    if (!(intGiorno >= 1 && intGiorno <= 31))
    {
        printf("giono errato\n");
        return -1;
    }

    indice = 0;

    for (int i = 2; i < 4; i++)
    {
        mese[indice] = argv[1][i];
        indice++;
    }

    intMese = atoi(mese);

    if (!(intMese >= 1 && intMese <= 12))
    {
        printf("mese errato\n");
        return -1;
    }

    indice = 0;

    for (int i = 4; i < 8; i++)
    {
        anno[indice] = argv[1][i];
        indice++;
    }
    intAnno = atoi(anno);

    if (!(intAnno < 2022) && !(intAnno > 0))
    {
        printf("anno errato\n");
        return -1;
    }

    if (intAnno < 10)
    {
        if (intGiorno < 10 && intMese < 10)
        {
            printf("0%d/0%d/000%d \n", intGiorno, intMese, intAnno);
        }
        else if (intGiorno < 10)
        {
            printf("0%d/%d/000%d \n", intGiorno, intMese, intAnno);
        }
        else if (intMese < 10)
        {
            printf("%d/0%d/000%d \n", intGiorno, intMese, intAnno);
        }
    }
    else if (intAnno < 100)
    {
        if (intGiorno < 10 && intMese < 10)
        {
            printf("0%d/0%d/00%d \n", intGiorno, intMese, intAnno);
        }
        else if (intGiorno < 10)
        {
            printf("0%d/%d/00%d \n", intGiorno, intMese, intAnno);
        }
        else if (intMese < 10)
        {
            printf("%d/0%d/00%d \n", intGiorno, intMese, intAnno);
        }
    }
    else if (intAnno < 1000)
    {
        if (intGiorno < 10 && intMese < 10)
        {
            printf("0%d/0%d/0%d \n", intGiorno, intMese, intAnno);
        }
        else if (intGiorno < 10)
        {
            printf("0%d/%d/0%d \n", intGiorno, intMese, intAnno);
        }
        else if (intMese < 10)
        {
            printf("%d/0%d/0%d \n", intGiorno, intMese, intAnno);
        }
    }
    else
    {
        if (intGiorno < 10 && intMese < 10)
        {
            printf("0%d/0%d/%d \n", intGiorno, intMese, intAnno);
        }
        else if (intGiorno < 10)
        {
            printf("0%d/%d/%d \n", intGiorno, intMese, intAnno);
        }
        else if (intMese < 10)
        {
            printf("%d/0%d/%d \n", intGiorno, intMese, intAnno);
        }
    }

    return 0;
}
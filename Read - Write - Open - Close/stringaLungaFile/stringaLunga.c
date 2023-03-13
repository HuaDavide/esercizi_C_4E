#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f1, *f2;
    char stringa[100], stringaPrecedente[100];
    int volta = 0;
    f1 = fopen("FILE.txt", "r");
    f2 = fopen("risultato.txt", "w");

    if(f1 == NULL || f2 == NULL)
    {
        printf("errore apertura file");
        return -1;
    }

    while(!feof(f1))
    {
        fscanf(f1, "%s", stringaPrecedente);

        if(strlen(stringaPrecedente) > strlen(stringa) && volta)
        {
            for(int i = 0; i < strlen(stringaPrecedente); i++)
            {
                stringa[i] = stringaPrecedente[i];
            }
        }
        else
            volta++;
    }

    fprintf(f2, "La stringa più lunga è: %s", stringa);
    printf("La stringa più lunga è: %s\n", stringa);
    fclose(f1);
    fclose(f2);
}
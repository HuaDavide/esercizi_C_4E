#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE *f1,*f2,*f3;
    char stringa[100], stringa2[100];
    int trovato, cont = 0;

    f1 = fopen("FILE1.txt", "r");
    f2 = fopen("FILE2.txt", "r");
    f3 = fopen("risultato.txt", "w");

    if(f1 == NULL || f2 == NULL || f3 == NULL)
    {
        printf("errore apertura file");
        return -1;
    }

    while(!feof(f1))
    {
        fscanf(f1, "%s", stringa);
        rewind(f2); //riposiziona il puntatore del file all'inizio
        trovato = 0;

        while(!feof(f2) && !trovato)
        {
            fscanf(f2, "%s", stringa2);
            if((strcmp(stringa, stringa2) == 0 && !trovato))
            {
                cont++;
                printf("Ho trovato %s!\n", stringa2);
                trovato = 1;
            }
        }
    }

    fprintf(f3, "Le stringhe ripetute sono: %d", cont);
    printf("Le stringhe ripetute sono: %d\n", cont);
    fclose(f1);
    fclose(f2);
    fclose(f3);

}
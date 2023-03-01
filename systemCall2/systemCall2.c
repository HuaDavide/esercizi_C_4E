#include <stdio.h>

int main()
{
    FILE *f1;
    int ris1 = 7, ris2 = 5, ris3 = 2;

    f1 = fopen("risultati.dat", "w");
    fprintf(f1, "%d %d", ris1, ris2);
    printf("valori aggiunti nel file\n");
    fclose(f1);

    f1 = fopen("risultati.dat", "a");
    fprintf(f1, " %d", ris3);
    return 0;
}
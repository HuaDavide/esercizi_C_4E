#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int lato;
    
    if (argc == 2)
        lato = atoi(argv[1]);
    else
    {
        printf("Errore accaduto\n");
        return -1;
    }

    for (int i = 0; i < lato; i++)
    {
        if (i == 0 || i == lato - 1)
        {
            for (int j = 0; j < lato; j++)
            {
                printf("*");
            }
        }
        else
        {
            for (int k = 0; k < lato; k++)
            {
                if (k == 0 || k == lato - 1)
                    printf("*");
                else
                    printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}

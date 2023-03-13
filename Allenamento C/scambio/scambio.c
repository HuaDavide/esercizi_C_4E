#include <stdio.h>

void scambia(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int main()
{
    int a = 10;
    int b = 20;

    scambia(&a, &b);

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return 0;
}
#include <stdio.h>

void main()
{
    void inv(int x[], int n);
    int i, a[10] = {3,7,9,11,0,6,7,5,4,2};
    printf("The original array:\n");
    for(i = 0; i < 10; i++)
        printf("%d,", a[i]);
    printf("\n");
    inv(a, 10);
    printf("The array has been inverted:\n");
    for(i = 0; i < 10; i++)
        printf("%d,", a[i]);
    printf("\n");
}

void inv(int x[], int n)
{
    int tmp, i, j, m = (n - 1)/2;
    for(i = 0; i <= m; i++)
    {
        j = n - 1 - i;
        tmp = x[i];
        x[i] = x[j];
        x[j] = tmp;
    }
    return;
}
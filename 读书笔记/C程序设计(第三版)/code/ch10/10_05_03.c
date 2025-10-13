#include <stdio.h>

void main()
{
    int a[10];
    int i, *p;
    for(i = 0; i < 10; i++)
        scanf("%d", &a[i]);
    printf("\n");
    for(p = a; p < (a+10); p++)
        printf("%d\n", *p);
}
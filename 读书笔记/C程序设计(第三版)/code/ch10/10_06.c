#include <stdio.h>

void main()
{
    int *p, i, a[10];
    p = a;
    for(i = 0; i < 10; i++)
        scanf("%d", p++);
    printf("\n");
    //p = a;//放开这句就对了
    for(i = 0; i < 10; i++,p++)//再次使用p之前没有把p的指向复位
        printf("%d\n", *p);
}
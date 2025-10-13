#include <stdio.h>

void main()
{
    void swap(int*, int*);
    int a, b;
    int * pointer_1, * pointer_2;
    scanf("%d, %d", &a, &b);
    pointer_1 = &a;
    pointer_2 = &b;
    if(a < b) swap(pointer_1, pointer_2);
    printf("\na = %d, b = %d\n", a, b);
}

void swap(int *p1, int *p2)
{
    int tmp;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
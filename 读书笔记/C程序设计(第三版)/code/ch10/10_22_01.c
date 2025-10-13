#include <stdio.h>

void main()
{
    int max(int, int);
    int a, b, c;
    scanf("%d,%d", &a, &b);
    c = max(a, b);
    printf("a = %d, b = %d, max = %d\n", a, b, c);
}

int max(int x, int y)
{
    int z;
    if(x > y)z = x;
    else z = y;
    return (z);
}
#include <stdio.h>

void main()
{
    int max(int, int);
    extern A, B;
    printf("%d\n", max(A, B));
}

int A = 13, B = -8;

int max(int x, int y)
{
    int z;
    z = z > y ? x : y;
    return (z);
}
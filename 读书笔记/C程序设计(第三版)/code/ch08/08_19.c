#include <stdio.h>

void main()
{
    long fac(long);
    long i, n;
    scanf("%ld", &n);
    for(i = 1; i <= n; i++)
        printf("%ld != %ld\n", i, fac(i));
}

long fac(long n)
{
    register long i, f = 1; /* 定义寄存器变量，如果n的值大，能节约许多执行时间 */
    for(i = 1; i <= n; i++)
        f = f * i;
    return (f);
}
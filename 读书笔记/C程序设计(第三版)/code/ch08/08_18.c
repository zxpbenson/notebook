#include <stdio.h>

void main()
{
    int fac(int n);
    int i;
    for(i = 1; i <= 5; i++)
        printf("%d != %d\n", i, fac(i));
}

int fac(int n)
{
    static int f = 1; /* 编译时初始化，变量只被引用而不改变值 */
    f = f * n;
    return (f);
}
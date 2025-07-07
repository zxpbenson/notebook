#include <stdio.h>

void main()
{
    int f(int);
    int a = 2, i;
    for(i = 0; i < 3; i++)
        printf("%d", f(a));
}

int f(int a)
{
    auto int b = 0;
    static int c = 3; /* f函数调用结束时此变量所占用的内存单元不释放并保留当前值 */
    b = b + 1;
    c = c + 1;
    return (a + b + c);
}
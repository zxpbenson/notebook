#include <stdio.h>

void main()
{
    int f(int a, int b); /* 函数声明 */
    int i = 2, p;
    p = f(i, ++i); /* 函数调用 */
    printf("%d\n", p);
}

int f(int a, int b)
{
    int c;
    if(a > b)c = 1;
    else if(a == b)c = 0;
    else c = -1;
    return (c);
}
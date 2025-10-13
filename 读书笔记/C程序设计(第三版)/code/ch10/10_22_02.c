#include <stdio.h>

void main()
{
    int max(int, int);
    int (*p)(int, int);//定义指向函数的指针变量，该函数有两个整型参数，函数值为整型。
    int a, b, c;
    p = max;//给函数指针变量赋值不需要&
    scanf("%d,%d", &a, &b);
    c = (*p)(a, b);
    printf("a = %d, b = %d, max = %d\n", a, b, c);
}

int max(int x, int y)
{
    int z;
    if(x > y)z = x;
    else z = y;
    return (z);
}
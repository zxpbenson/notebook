#include <stdio.h>

int a = 3, b = 5; /* a、b为外部变量 */

void main()
{
    int max(int a, int b); /* 本行为函数声明，a、b为形参名 */
    int a = 8; /* a为局部变量 */
    printf("%d\n", max(a, b));
}

int max(int a, int b) /* a、b为形参局部变量，作用域整个max函数 */
{
    int c;
    c = a > b ? a : b;
    return (c);
}
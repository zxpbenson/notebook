#include <stdio.h>

void main()
{
    float add(float x, float y); /* 对被调用函数 add 的声明 */
    float a, b, c;
    scanf("%f, %f", &a, &b);
    c = add(a, b);
    printf("sum is %f\n", c);
}

float add(float x, float y) /* 函数首部 */
{
    float z; /* 函数体 */
    z = x + y;
    return (z);
}
#include <stdio.h>

void main()
{
    unsigned a;
    int b = -1;
    a = b;
    printf("%u\n", a);//输出无符号数用%u，预期结果65535
}
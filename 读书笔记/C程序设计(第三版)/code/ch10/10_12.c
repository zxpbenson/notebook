#include <stdio.h>

void main()
{
    int a[3][4] = {1,3,5,7,9,11,13,15,17,19,21,23};
    int (*p)[4], i, j;
    p = a;
    scanf("i=%d,j=%d", &i, &j);//注意应输入“i=1,j=2”以与scanf函数中指定的字符串相对应
    printf("a[%d,%d]=%d\n", i, j, *(*(p+i)+j));
}
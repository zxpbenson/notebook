#include <stdio.h>

void main()
{
    int max(int, int);
    extern int A, B;// 没有类型（不推荐） 这是 合法的旧式 C 写法（早期 C 允许变量声明时不写类型，默认是 int），但在现代 C 标准（C99 及之后）中，这是不被推荐的写法，有些编译器在默认严格模式下会报错。
    printf("%d\n", max(A, B));
}

int A = 13, B = -8;

int max(int x, int y)
{
    int z;
    z = x > y ? x : y;
    return (z);
}
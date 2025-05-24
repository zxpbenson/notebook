extern A; /* 声明A为一个已经定义的外部变量，不必在为它分配内存 */

int power(int n)
{
    int i, y = 1;
    for(i = 1; i <= n; i++)
        y *= A;
    return (y);
}
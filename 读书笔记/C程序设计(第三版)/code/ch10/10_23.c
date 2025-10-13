#include <stdio.h>

void main()
{
    int max(int, int);//function decleration
    int min(int, int);//function decleration
    int add(int, int);//function decleration
    int process(int, int, int (*fun)(int, int));//function decleration
    int a, b;
    printf("enter a and b:");
    scanf("%d,%d", &a, &b);
    printf("max=");
    process(a, b, max);
    printf("min=");
    process(a, b, min);
    printf("sub=");
    process(a, b, sum);    
}

int max(int x, int y)
{
    int z;
    if(x>y)z=x;
    else z=y;
    return (z);
}

int min(int x, int y)
{
    int z;
    if(x<y)z=x;
    else z=y;
    return (z);
}

int sum(int x, int y)
{
    int z;
    z=x+y;
    return (z);
}

void process(int x, int y, int(* fun)(int, int))
{
    int result;
    result = (*fun)(x, y);
    printf("result=%d\n", result);
}
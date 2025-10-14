#include<stdio.h>

void main() 
{
    unsigned a, b, c;
    int n;
    scanf("a=%o,n=%d", &a, &n);
    b = a<<(16-n);
    c = a>>n;
    c = c|b;
    printf("%o\n%o", a, c);
}
#include <stdio.h>

void main()
{
  int i , a[10];
  for(i = 0; i <= 9; i++)
    a[i] = i;
  for(i = 9; i >= 0; i--)
    printf("%d", a[i]);//9 8 7 6 5 4 3 2 1 0
  printf("\n");
}
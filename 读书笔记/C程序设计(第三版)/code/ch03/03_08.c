#include <stdio.h>

void main() 
{
  float x;
  int i;
  x = 3.6;
  i = (int)x;
  printf("x=%f, i=%d\n", x, i);// x=3.6000000, i=3 
  //此例验证了 x类型仍是float，值不变
}
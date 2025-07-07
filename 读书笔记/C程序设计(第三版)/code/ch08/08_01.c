# include <stdio.h>

void main()
{
  void printstar(); /* 声明 printstar 函数 */
  void print_message(); /* 声明 print_message 函数 */
  printstar(); /* 调用 printstar 函数 */
  print_message(); /* 调用 print_message 函数 */
  printstar(); /* 调用 printstar 函数 */
}

void printstar() /* 定义 printstar 函数 */
{
  printf("* * * * * * * * * * * *\n");
}


void print_message() /* 定义 print_message 函数 */
{
  printf(" How do you do! \n");
}
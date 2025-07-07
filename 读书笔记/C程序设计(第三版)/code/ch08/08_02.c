# include<stdio.h>

void main()
{
	int max(int x, int y); /* 声明 max(int) 函数 */
	int a,b,c;
	scanf("%d, %d", &a, &b);
	c=max(a, b); /* 这里的 a,b 是实参 */
	printf("Max is %d", c);
}

int max(int x, int y) /* 定义 max(int) 函数， x，y是形参 */
{
	int z;
	z = x > y ? x : y;
	return (z);
}
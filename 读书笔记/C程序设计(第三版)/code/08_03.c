# include<stdio.h>

void main()
{
	int max(float x, float y); /* 声明 max(int) 函数 */
	float a, b;
	int c;
	scanf("%f, %f", &a, &b);
	c=max(a, b); /* 这里的 a,b 是实参 */
	printf("Max is %d", c);
}

int max(float x, float y) /* 定义 max(float, float) 函数， x，y是形参 */
{
	float z; /* z是实型变量 */
	z = x > y ? x : y;
	return (z);
}
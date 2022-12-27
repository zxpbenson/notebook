# include <stdio.h>
void main() {
	int a,b;
	a = 32767;
	b = a + 1;

	printf("sizeof(a) = %d\n", sizeof(a));
	printf("sizeof a = %d\n", sizeof a);
	printf("sizeof(int) = %d\n", sizeof(int));
	//printf("sizeof int = %d\n", sizeof int);//这个语法不允许

	printf("a = %d, b = %d\n", a, b);//a = 32767, b = 32768

	a = 2147483647;
	b = a + 1;

	printf("a = %d, b = %d\n", a, b);//a = 2147483647, b = -2147483648
}
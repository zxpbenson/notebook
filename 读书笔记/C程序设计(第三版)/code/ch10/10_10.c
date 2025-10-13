#include <stdio.h>
#define FORMAT "%d, %d\n"

void main()
{
    int a[3][4] = {1,3,5,7,9,11,13,15,17,19,21,23};
    printf(FORMAT, a, *a);
    printf(FORMAT, a[0], *(a+0));
    printf(FORMAT, &a[0], &a[0][0]);
    printf(FORMAT, a[1], a+1);
    printf(FORMAT, &a[1][0], *(a+1)+0);
    printf(FORMAT, a[2], *(a+2));
    printf(FORMAT, &a[2], a+2);
    printf(FORMAT, a[1][0], *(*(a+1)+0));
}
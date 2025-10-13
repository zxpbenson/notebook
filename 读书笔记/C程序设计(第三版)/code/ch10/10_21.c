#include <stdio.h>

void main()
{
    char *a = "I love China!";
    int i;
    printf("The sixth character is %c\n", a[5]);
    for(i=0; a[i]!='\0'; i++)
        printf("%c", a[i]);
    printf("\n");
}
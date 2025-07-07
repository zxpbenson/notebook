#include <stdio.h>
#define LETTER 1

void main()
{
    char str[20] = "C Language", c;
    int i;
    i = 0;
    while((c = str[i]) != '\0')
    {
        i++;
        #if LETTER
            if(c >= 'a' && c <= 'z')
                c = c - 32;
        #else
            if(c >= 'A' && c <= 'Z')
                c = c + 32;
        #endif
        printf("%c", c);
    }
    printf("\n");
}
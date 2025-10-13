#include <stdio.h>

void main()
{
    void copy_string(char *from, char *to);
    char *a = "I am a teacher.";
    char *b = "You are a student.";
    printf("string a =%s\nstring b = %s\n", a, b);
    printf("copy string a to string b:\n");
    copy_string(a, b);
    printf("\n string a = %s\nstring b = %s\n", a, b);
}

void copy_string(char *from, char *to) 
{
    for(; *from != '\0'; from++, to++)
        *to=*from;
    *to = '\0';
}
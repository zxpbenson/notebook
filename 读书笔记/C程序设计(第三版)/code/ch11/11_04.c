#include <stdio.h>

struct student
{
    int num;
    char name[20];
    char sex;
    int age;
    char addr[30];
};

struct student stu[] = {
    {10101, "Li Lin", 'M', "103 Beijing Road"},
    {10102, "Zhang Fun", 'M', "130 Shanghai Road"},
    {10103, "Wang Min", 'F', "1010 Zhongshan Road"}
};

void main()
{
    struct student *p;
    printf("no. Name sex age\n");
    for(p = stu; p < stu+3; p++)
        printf("%5d %-20s %2c %4d\n", p->num, p->name, p->sex, p->age);
}